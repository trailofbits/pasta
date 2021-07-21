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
//
// NOTE(pag): Some of the parsed include paths are sysroot-relative, others
//            are not. Unfortunately, we can't figure out easily which is which
//            (e.g. sometimes Clang version info tells us in another way, but
//            not GCC does not).
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
        info.frameworks.emplace_back(std::move(path_str),
                                     IncludePathLocation::kAbsolute);
      } else if (kInUserIncludeList == state) {
        info.user_includes.emplace_back(std::move(path_str),
                                        IncludePathLocation::kAbsolute);
      } else if (kInSystemIncludeList == state) {
        info.system_includes.emplace_back(std::move(path_str),
                                          IncludePathLocation::kAbsolute);
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
  for (const auto &entry : info.system_includes) {
    std::filesystem::path path;
    if (entry.second == IncludePathLocation::kAbsolute) {
      path = entry.first;
    } else {
      path = info.sysroot_dir;
      path /= entry.first;
    }

    if (ScanForResourceDir(info, path)) {
      return true;
    }
  }
  return false;
}

// Extract the relative component of a `include_path`, assuming it is an
// absolute path that beings with `sysroot_dir`.
std::filesystem::path ExtractRelativeComponent(std::filesystem::path sysroot_dir,
                                               std::filesystem::path include_path) {
  if (std::distance(include_path.begin(), include_path.end()) <
      std::distance(sysroot_dir.begin(), sysroot_dir.end())) {
    return include_path;
  }

  auto sysroot_it = sysroot_dir.begin();
  auto sysroot_it_end = sysroot_dir.end();

  auto include_path_it = include_path.begin();
  auto include_path_it_end = include_path.end();

  for (; sysroot_it != sysroot_it_end && include_path_it != include_path_it_end;
       ++sysroot_it, ++include_path_it) {
    if (*sysroot_it != *include_path_it) {
      return include_path;
    }
  }

  auto path = include_path.root_directory();
  for (; include_path_it != include_path_it_end; ++include_path_it) {
    path /= *include_path_it;
  }

  return path;
}

// Try to compute the "real" system root directory.
static void FindSystemRootRelPaths(
    std::vector<IncludePath> &orig,
    const std::vector<IncludePath> &sysroot_rel,
    std::vector<std::filesystem::path> &sysroot_rel_paths) {

  for (auto &orig_entry : orig) {
    auto found = false;
    for (const auto &sysroot_entry : sysroot_rel) {
      if (orig_entry.first == sysroot_entry.first) {
        found = true;
        break;
      }
    }

    std::filesystem::path include_dir(orig_entry.first);
    if (!found && std::filesystem::is_directory(include_dir)) {
      sysroot_rel_paths.emplace_back(CanonicalPath(include_dir));
    }
  }
}

// Try to compute the "real" system root directory.
static std::filesystem::path FindRealSystemRoot(
    std::filesystem::path &sysroot_dir,
    const std::vector<std::filesystem::path> &sysroot_rel_paths) {

  // TODO(pag): Do a better job.
  if (1u >= sysroot_rel_paths.size()) {
    return sysroot_dir;
  }

  std::vector<std::pair<std::filesystem::path::iterator,
                        std::filesystem::path::iterator>> path_iterators;

  // TODO(pag): Adding this makes it end up finding the common stem between
  //            the existing sysroot dir and all the relative paths. But really,
  //            this will probably be the existing sysroot dir, so it all ends
  //            up being a bit useless, but I originally made this code to solve
  //            a real problem, but I don't remember why or how the code
  //            (absent the next line) actually solved that problem.
  path_iterators.emplace_back(sysroot_dir.begin(), sysroot_dir.end());

  for (auto &path : sysroot_rel_paths) {
    if (path.empty()) {
      return sysroot_dir;
    }

    path_iterators.emplace_back(path.begin(), path.end());
  }

  // Go find the common pieces of all of the path parts. This steps through
  // each of the iterators one path part at a time until one of the iterators
  // runs out or one of the path parts disagrees.
  std::filesystem::path new_sysroot_dir;
  for (auto done = false; !done ;) {

    std::filesystem::path part;
    auto has_part = false;

    for (auto &range : path_iterators) {
      if (range.first == range.second) {
        done = true;
        break;

      } else if (has_part) {
        if (part != *(range.first)) {
          done = true;
        }
        ++range.first;

      } else {
        part = *(range.first);
        has_part = true;
        ++range.first;
      }
    }

    if (!done) {
      new_sysroot_dir /= part;
    }
  }

  if (new_sysroot_dir.empty()) {
    return sysroot_dir;
  }

  return new_sysroot_dir;
}

// Find all paths in `orig` that aren't in `sysroot_rel`. The missing paths
// are marked as being relative to an `-isysroot`.
static void RelativizePaths(std::filesystem::path sysroot_dir,
                            std::vector<IncludePath> &orig,
                            const std::vector<IncludePath> &sysroot_rel) {
  const auto sysroot_path = sysroot_dir.string();

  for (IncludePath &orig_entry : orig) {

    // Sometimes things are sysroot relative, even though they pretend not
    // to be. At least this is the case with AppleClang.
    std::filesystem::path path = orig_entry.first;
    std::string extracted_path =
        ExtractRelativeComponent(sysroot_dir, orig_entry.first).string();

    if (path.string() != extracted_path && extracted_path != sysroot_path) {
      extracted_path.swap(orig_entry.first);
      orig_entry.second = IncludePathLocation::kSysrootRelative;
      continue;
    }

    // Go look for this path in `sysroot_rel`. If we can't find it then it
    // means it is likely to be relative to `-isysroot`.
    auto found = false;
    for (const auto &sysroot_entry : sysroot_rel) {
      if (orig_entry.first == sysroot_entry.first) {
        found = true;
        break;
      }
    }

    if (!found) {
      orig_entry.second = IncludePathLocation::kSysrootRelative;
    }
  }
}

static const std::string kErrUnrecognizedCompiler{
    "Unrecognized host compiler"};

}  // namespace

// Create a "host" compiler instance, i.e. a compiler instance based on the
// compiler used to compile this library.
Result<Compiler, std::string>
Compiler::CreateHostCompiler(enum TargetLanguage lang) {
  const char *path = nullptr;
  const char *version_info = nullptr;
  const char *version_info_fake_sysroot = nullptr;
  switch (lang) {
    case TargetLanguage::kC:
      path = kHostCCompilerPath;
      version_info = kHostCVersionInfo;
      version_info_fake_sysroot = kHostCVersionInfoFakeSysroot;
      break;
    case TargetLanguage::kCXX:
      path = kHostCxxCompilerPath;
      version_info = kHostCxxVersionInfo;
      version_info_fake_sysroot = kHostCxxVersionInfoFakeSysroot;
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
  auto maybe_compiler = Create(name, lang, path, version_info,
                               version_info_fake_sysroot, kHostWorkingDir);
  if (maybe_compiler.Failed()) {
    return maybe_compiler.TakeError();
  } else {
    return std::move(*maybe_compiler);
  }
#else
  return kErrUnrecognizedCompiler;
#endif
}

// Create a compiler from a version string.
//
// NOTE(pag): The `working_dir` is the directory in which the compiler
//            invocation was made.
Result<Compiler, std::string>
Compiler::Create(CompilerName name, enum TargetLanguage lang,
                 std::string_view compiler_path_, std::string_view version_info,
                 std::string_view version_info_fake_sysroot,
                 std::string_view compiler_working_dir) {
  std::stringstream err;

  // Fix it up, just in case.
  if (CompilerName::kClang == name &&
      strstr(version_info.data(), "Apple clang version") ==
          version_info.data()) {
    name = CompilerName::kAppleClang;
  }

  std::filesystem::path working_dir(compiler_working_dir);
  if (!std::filesystem::is_directory(working_dir)) {
    err << "Invalid working directory for compiler invocation: "
        << compiler_working_dir;
    return err.str();
  }

  std::filesystem::path compiler_path = AbsolutePath(
      compiler_path_, working_dir);
  if (!std::filesystem::exists(compiler_path)) {
    err << "Invalid compiler path: " << compiler_path_;
    return err.str();
  }

  std::shared_ptr<CompilerImpl> impl(std::make_shared<CompilerImpl>(
      name, lang, CanonicalPath(compiler_path).string()));

  std::stringstream ss;
  ss << version_info;
  ParseOutputInto(ss, *impl, working_dir);

  // Give the installation directory a sensible default if missing.
  if (impl->install_dir.empty() && !impl->compiler_exe.empty()) {
    std::filesystem::path compiler_exe_path(impl->compiler_exe);
    compiler_exe_path.parent_path().string().swap(impl->install_dir);
  }

  // If the sysroot looks relative, then assume it's relative to the
  // installation directory, and compute an absolute path.
  if (!impl->sysroot_dir.empty() && !impl->install_dir.empty()) {
    std::filesystem::path install_path(impl->install_dir);
    std::filesystem::path sysroot_path(impl->sysroot_dir);
    if (sysroot_path.is_relative()) {
      const auto new_sysroot_path =
          CanonicalPath(AbsolutePath(install_path / sysroot_path, working_dir));
      new_sysroot_path.string().swap(impl->sysroot_dir);
    }
  }

  // Still empty? Take the root directory of the compiler path, and failing
  // that, the root directory of the working directory.
  if (impl->sysroot_dir.empty()) {
    compiler_path.root_directory().string().swap(impl->sysroot_dir);
  }
  if (impl->sysroot_dir.empty()) {
    working_dir.root_directory().string().swap(impl->sysroot_dir);
  }

  // We might have version information with a fake or different system
  // root directory specified. This is to let us discover which paths
  // are absolute and which ones are sysroot-relative.
  if (!version_info_fake_sysroot.empty()) {

    CompilerImpl fake_sysroot_impl(
        impl->compiler_name, impl->target_lang, impl->compiler_exe);
    std::stringstream ss2;
    ss2 << version_info_fake_sysroot;
    ParseOutputInto(ss2, fake_sysroot_impl, working_dir);

    // If we've got "fake" system root-relative versions to compare against
    // then we might be able to do a better job of finding the 'true' system
    // root directory.
    std::filesystem::path sysroot_dir(impl->sysroot_dir);
    std::vector<std::filesystem::path> sysroot_rel_paths;
    FindSystemRootRelPaths(
        impl->system_includes, fake_sysroot_impl.system_includes,
        sysroot_rel_paths);
    FindSystemRootRelPaths(
        impl->user_includes, fake_sysroot_impl.user_includes,
        sysroot_rel_paths);

    sysroot_dir = FindRealSystemRoot(sysroot_dir, sysroot_rel_paths);
    sysroot_dir.string().swap(impl->sysroot_dir);

    // Relative the paths w.r.t. the true system root directory.
    RelativizePaths(sysroot_dir, impl->system_includes,
                    fake_sysroot_impl.system_includes);
    RelativizePaths(sysroot_dir, impl->user_includes,
                    fake_sysroot_impl.user_includes);
    RelativizePaths(sysroot_dir, impl->frameworks,
                    fake_sysroot_impl.frameworks);
  }

  if (impl->resource_dir.empty() && !DeriveResourceDirs(*impl)) {
    err << "Unable to infer resource directory for compiler '"
        << compiler_path_ << "'";
    return err.str();
  }

  return Compiler(std::move(impl));
}

}  // namespace pasta
