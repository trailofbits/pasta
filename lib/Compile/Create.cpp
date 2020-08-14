/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Error.h>
#pragma clang diagnostic pop

#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>

#include <cassert>
#include <cstring>
#include <sstream>
#include <system_error>

#include "Compiler.h"
#include "Host.h"

namespace pasta {
namespace {

// Try to parse out the installation directory of this version of GCC.
static void ParseGCCInstalledDir(CompilerImpl &info, llvm::StringRef line,
                                 std::filesystem::path working_dir) {
  const auto pos = line.find("--prefix");
  if (std::string::npos == pos) {
    return;
  }

  ArgumentVector vec(line.substr(pos));
  std::string guess;
  if (std::string::npos != line.find("--prefix=", pos)) {
    guess = &(vec[0][9]);
  } else if (2 <= vec.Size()) {
    guess = vec[1];
  } else {
    return;
  }

  auto path = AbsolutePath(guess, working_dir);

  std::error_code ec;
  std::filesystem::canonical(path, ec);
  if (ec || !std::filesystem::is_directory(path)) {
    return;
  }

  CanonicalPath(path).string().swap(info.install_dir);
}

// Try to parse the resource directory out of the compiler's output. This
// only really works for Clang-based compilers.
static void ParseClangResourceDir(CompilerImpl &info, llvm::StringRef line,
                                  std::filesystem::path working_dir) {
  const auto pos = line.find("-resource-dir");
  if (std::string::npos == pos) {
    return;
  }

  ArgumentVector vec(line.substr(pos));
  if (2 > vec.Size()) {
    return;
  }

  auto path = AbsolutePath(vec[1], working_dir);
  if (IsResourceDir(path)) {
    CanonicalPath(path).string().swap(info.resource_dir);
  }
}

// Try to parse the system root directory out of the compiler's output. This
// only really works for Clang-based compilers.
static void ParseClangSysroot(CompilerImpl &info, llvm::StringRef line,
                              std::filesystem::path working_dir) {
  const auto pos = line.find("-isysroot");
  if (std::string::npos == pos) {
    return;
  }

  ArgumentVector vec(line.substr(pos));
  if (2 > vec.Size()) {
    return;
  }

  auto path = AbsolutePath(vec[1], working_dir);
  if (std::filesystem::is_directory(path)) {
    CanonicalPath(path).string().swap(info.sysroot_dir);
  }
}

// Roughly, the info we want to parse comes in the following form:
//
//    #include "..." search starts here:
//    #include <...> search starts here:
//     /usr/local/Cellar/gcc/8.1.0/lib/gcc/8/gcc/..
//     /usr/local/include
//     /usr/local/Cellar/gcc/8.1.0/include
//     /usr/local/Cellar/gcc/8.1.0/lib/gcc/8/gcc/...
//     /usr/include
//     /System/Library/Frameworks (framework directory)
//     /Library/Frameworks (framework directory)
//    End of search list.
static void ParseOutputInto(std::stringstream &ss, CompilerImpl &info,
                            std::filesystem::path working_dir) {

  enum State {
    kUnknown,
    kInUserIncludeList,
    kInSystemIncludeList,
  } state = kUnknown;

  for (std::string line_; std::getline(ss, line_);) {
    llvm::StringRef line(line_);

    ParseClangResourceDir(info, line, working_dir);
    ParseClangSysroot(info, line, working_dir);

    if (line.startswith("InstalledDir: ")) {
      auto path = AbsolutePath(line.substr(14).str(), working_dir);
      if (std::filesystem::is_directory(path)) {
        CanonicalPath(path).string().swap(info.install_dir);
      }

    } else if (line.startswith("Configured with: ")) {
      ParseGCCInstalledDir(info, line, working_dir);

    } else if (line.startswith("#include \"...\"")) {
      state = kInUserIncludeList;

    } else if (line.startswith("#include <...>")) {
      state = kInSystemIncludeList;

    // TODO(pag): Handle absolute paths on Windows.
    } else if (line.startswith(" /")) {
      if (kUnknown == state) {
        continue;
      }

      bool is_framework = false;
      if (line.endswith(" (framework directory)")) {
        line = line.substr(0, line.size() - 22);
        is_framework = true;
      }

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
#  error "Add compiler info resolution support for Windows"
#endif

      auto path = AbsolutePath(line.substr(1).str(), working_dir);

      if (!std::filesystem::is_directory(path)) {

        // Silently ignore non-existant directories.
        continue;
      }

      auto path_str = CanonicalPath(path).string();

      if (is_framework && kUnknown != state) {
        info.frameworks.emplace_back(std::move(path_str));
      } else if (kInUserIncludeList == state) {
        info.user_includes.emplace_back(std::move(path_str));
      } else if (kInSystemIncludeList == state) {
        info.system_includes.emplace_back(std::move(path_str));
      }

    } else if (line.startswith("End of search list")) {
      state = kUnknown;
    }
  }
}

// Try to scan up the directory hierarchy of an include path and find the
// compiler's resource directory. The resource directory usually looks something
// like this:
//
//  /Library/Developer/CommandLineTools/usr/lib/clang/<version number>
//
// Often times, multiple resource directories are present, and so getting the
// right version number can bit tricky absent other info. We assume that the
// right version is whichever appears in the compiler command-line.
static bool ScanForResourceDir(CompilerImpl &info, std::filesystem::path path) {
  for (;;) {
    auto parent_path = path.parent_path();
    if (parent_path == path) {
      break;
    }
    path = parent_path;
    auto base_name = path.filename();
    if (IsResourceDir(path)) {
      CanonicalPath(path).string().swap(info.resource_dir);
      return true;
    }
  }
  return false;
}

// Try to derive the resource directory from the include paths of the compiler.
static bool DeriveResourceDirs(CompilerImpl &info) {
  for (auto path : info.system_includes) {
    if (ScanForResourceDir(info, path)) {
      return true;
    }
  }
  return false;
}

}  // namespace

// Create a "host" compiler instance, i.e. a compiler instance based on the
// compiler used to compile this library.
llvm::Expected<Compiler> Compiler::CreateHostCompiler(TargetLanguage lang) {
  const char *path = nullptr;
  const char *version_info = nullptr;
  switch (lang) {
    case TargetLanguage::kC:
      path = kHostCCompilerPath;
      version_info = kHostCVersionInfo;
      break;
    case TargetLanguage::kCXX:
      path = kHostCxxCompilerPath;
      version_info = kHostCxxVersionInfo;
      break;
  }
  assert(path && version_info);

#define FOUND_HOST_COMPILER
#if defined(__clang__)
  auto name = CompilerName::kClang;
#  if defined(__APPLE__)
  if (strstr(version_info, "Apple clang version") == version_info) {
    name = CompilerName::kAppleClang;
  }
#  elif defined(_WIN32) || defined(_MSC_VER)
  name = CompilerName::kClangCL;
#  endif
#elif defined(__GNUC__) || defined(__GNUG__)
#  if defined(_WIN32) || defined(_MSC_VER) || defined(__CYGWIN__)
  const auto name = CompilerName::kMinGW;
#  else
  const auto name = CompilerName::kGNU;
#  endif
#elif defined(_WIN32) || defined(_MSC_VER)
  const auto name = CompilerName::kCL;
#else
#  undef FOUND_HOST_COMPILER
#endif

#ifdef FOUND_HOST_COMPILER
  return Create(name, lang, path, version_info, kHostWorkingDir);
#else
  return llvm::createStringError(
      std::make_error_code(std::errc::function_not_supported),
      "Unrecognized host compiler");
#endif
}

// Create a compiler from a version string.
//
// NOTE(pag): The `working_dir` is the directory in which the compiler
//            invocation was made.
llvm::Expected<Compiler>
Compiler::Create(CompilerName name, TargetLanguage lang,
                 std::string_view compiler_path_, std::string_view version_info,
                 std::string_view compiler_working_dir) {

  // Fix it up, just in case.
  if (CompilerName::kClang == name &&
      strstr(version_info.data(), "Apple clang version") ==
          version_info.data()) {
    name = CompilerName::kAppleClang;
  }

  std::filesystem::path working_dir(compiler_working_dir);
  if (!std::filesystem::is_directory(working_dir)) {
    return llvm::createStringError(
        std::make_error_code(std::errc::not_a_directory),
        "Invalid working directory for compiler invocation: %s",
        compiler_working_dir.data());
  }

  auto compiler_path = AbsolutePath(compiler_path_, working_dir);
  if (!std::filesystem::exists(compiler_path)) {
    return llvm::createStringError(
        std::make_error_code(std::errc::executable_format_error),
        "Invalid compiler path: %s", compiler_path_.data());
  }

  std::unique_ptr<CompilerImpl> impl(
      new CompilerImpl(name, lang, CanonicalPath(compiler_path).string()));

  std::stringstream ss;
  ss << version_info;
  ParseOutputInto(ss, *impl, working_dir);

  if (impl->resource_dir.empty() && !DeriveResourceDirs(*impl)) {
    return llvm::createStringError(
        std::make_error_code(std::errc::not_a_directory),
        "Unable to infer resource directory");
  }

  return Compiler(impl.release());
}

}  // namespace pasta
