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

static constexpr auto kAnyExecutable = std::filesystem::perms::owner_exec |
                                       std::filesystem::perms::group_exec |
                                       std::filesystem::perms::others_exec;

// Try to parse out the installation directory of this version of GCC.
static void ParseGCCInstalledDir(FileSystemView &fs, CompilerImpl &info,
                                 llvm::StringRef line) {
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

  auto status = fs.Stat(fs.ParsePath(guess));
  if (status.Succeeded() && status->IsDirectory()) {
    info.install_dir = std::move(status->real_path);
  }
}

// Try to parse the resource directory out of the compiler's output. This
// only really works for Clang-based compilers.
static void ParseClangResourceDir(FileSystemView &fs, CompilerImpl &info,
                                  llvm::StringRef line) {
  const auto pos = line.find("-resource-dir");
  if (std::string::npos == pos) {
    return;
  }

  ArgumentVector vec(line.substr(pos));
  if (2 > vec.Size()) {
    return;
  }

  auto status = fs.Stat(fs.ParsePath(vec[1]));
  if (status.Succeeded() && status->IsDirectory()) {
    if (fs.IsResourceDir(status->real_path)) {
      info.resource_dir = std::move(status->real_path);
    }
  }
}

// Try to parse the system root directory out of the compiler's output. This
// only really works for Clang-based compilers.
static void ParseClangSysroot(FileSystemView &fs, CompilerImpl &info,
                              llvm::StringRef line) {
  const auto pos = line.find("-isysroot");
  if (std::string::npos == pos) {
    return;
  }

  ArgumentVector vec(line.substr(pos));
  if (2 > vec.Size()) {
    return;
  }

  auto status = fs.Stat(fs.ParsePath(vec[1]));
  if (status.Succeeded() && status->IsDirectory()) {
    info.sysroot_dir = std::move(status->real_path);
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
static void ParseOutputInto(FileSystemView &fs, std::stringstream &ss,
                            CompilerImpl &info) {

  enum State {
    kUnknown,
    kInUserIncludeList,
    kInSystemIncludeList,
  } state = kUnknown;

  for (std::string line_; std::getline(ss, line_);) {
    llvm::StringRef line(line_);

    ParseClangResourceDir(fs, info, line);
    ParseClangSysroot(fs, info, line);

    if (line.startswith("InstalledDir: ")) {
      auto maybe_status = fs.Stat(fs.ParsePath(line.substr(14).str()));
      if (maybe_status.Succeeded() && maybe_status->IsDirectory()) {
        info.install_dir = std::move(maybe_status->real_path);
      }

    } else if (line.startswith("Configured with: ")) {
      ParseGCCInstalledDir(fs, info, line);

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

      auto status = fs.Stat(fs.ParsePath(line.substr(1).str()));
      if (status.Failed() || !status->IsDirectory()) {

        // Silently ignore non-existant directories.
        continue;
      }

      if (is_framework && kUnknown != state) {
        info.frameworks.emplace_back(std::move(status->real_path),
                                     IncludePathLocation::kAbsolute);
      } else if (kInUserIncludeList == state) {
        info.user_includes.emplace_back(std::move(status->real_path),
                                        IncludePathLocation::kAbsolute);
      } else if (kInSystemIncludeList == state) {
        info.system_includes.emplace_back(std::move(status->real_path),
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
static bool ScanForResourceDir(FileSystemView &fs, CompilerImpl &info,
                               std::filesystem::path path) {
  for (;;) {
    auto parent_path = path.parent_path();
    if (parent_path == path) {
      break;
    }
    path = std::move(parent_path);
    if (fs.IsResourceDir(path)) {
      info.resource_dir = std::move(path);
      return true;
    }
  }
  return false;
}

// Try to derive the resource directory from the include paths of the compiler.
static bool DeriveResourceDirs(FileSystemView &fs, CompilerImpl &info) {
  for (const auto &entry : info.system_includes) {
    std::filesystem::path path;
    if (entry.second == IncludePathLocation::kAbsolute) {
      path = entry.first;
    } else {
      path = info.sysroot_dir;
      path /= entry.first;
    }

    if (ScanForResourceDir(fs, info, path)) {
      return true;
    }
  }
  return false;
}

// Extract the relative component of a `include_path`, assuming it is an
// absolute path that beings with `sysroot_dir`.
std::filesystem::path ExtractRelativeComponent(
    FileSystemView &fs,
    std::filesystem::path sysroot_dir,
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

  if (auto maybe_path = fs.RootDirectory(include_path);
      maybe_path.Succeeded()) {
    auto path = maybe_path.TakeValue();
    for (; include_path_it != include_path_it_end; ++include_path_it) {
      path /= *include_path_it;
    }
    return path;
  }

  return {};
}

// Try to compute the "real" system root directory.
static void FindSystemRootRelPaths(
    FileSystemView &fs, std::vector<IncludePath> &orig,
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

    if (!found) {
      auto include_dir = fs.Stat(orig_entry.first);
      if (include_dir.Succeeded() && include_dir->IsDirectory()) {
        sysroot_rel_paths.emplace_back(std::move(include_dir->real_path));
      }
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
static void RelativizePaths(FileSystemView &fs,
                            std::filesystem::path sysroot_dir,
                            std::vector<IncludePath> &orig,
                            const std::vector<IncludePath> &sysroot_rel) {
  const auto sysroot_path_str = sysroot_dir.generic_string();

  for (IncludePath &orig_entry : orig) {

    // Sometimes things are sysroot relative, even though they pretend not
    // to be. At least this is the case with AppleClang.
    std::filesystem::path path = orig_entry.first;

    auto extracted_path = ExtractRelativeComponent(fs, sysroot_dir,
                                                   orig_entry.first);
    const auto extracted_path_str = extracted_path.generic_string();

    if (path.generic_string() != extracted_path_str &&
        extracted_path_str != sysroot_path_str) {
      orig_entry.first = std::move(extracted_path);
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
  std::filesystem::path path;
  const char *version_info = nullptr;
  const char *version_info_fake_sysroot = nullptr;
  auto name = CompilerName::kUnknown;
  switch (lang) {
    case TargetLanguage::kC:
      name = kHostCCompiler;
      path = kHostCCompilerPath;
      version_info = kHostCVersionInfo;
      version_info_fake_sysroot = kHostCVersionInfoFakeSysroot;
      break;
    case TargetLanguage::kCXX:
      name = kHostCxxCompiler;
      path = kHostCxxCompilerPath;
      version_info = kHostCxxVersionInfo;
      version_info_fake_sysroot = kHostCxxVersionInfoFakeSysroot;
      break;
  }

  if (path.empty() || !version_info || name == CompilerName::kUnknown) {
    return kErrUnrecognizedCompiler;
  }

  auto host_fs = FileSystem::CreateNative();
  auto maybe_cwd = host_fs->CurrentWorkingDirectory();
  if (maybe_cwd.Failed()) {
    return maybe_cwd.TakeError().message();
  }

  auto cwd = maybe_cwd.TakeValue();
  auto maybe_compiler = Create(
      std::move(host_fs), path.lexically_normal(), std::move(cwd),
      name, lang, version_info, version_info_fake_sysroot);
  if (maybe_compiler.Failed()) {
    return maybe_compiler.TakeError();
  } else {
    return std::move(*maybe_compiler);
  }
}

// Create a compiler from a version string.
//
// NOTE(pag): The `working_dir` is the directory in which the compiler
//            invocation was made.
Result<Compiler, std::string>
Compiler::Create(std::shared_ptr<class FileSystem> fs_,
                 std::filesystem::path compiler_path,
                 std::filesystem::path working_dir,
                 CompilerName name, enum TargetLanguage lang,
                 std::string_view version_info,
                 std::string_view version_info_fake_sysroot) {
  std::stringstream err;

  // Fix it up, just in case.
  if (CompilerName::kClang == name &&
      strstr(version_info.data(), "Apple clang version") ==
          version_info.data()) {
    name = CompilerName::kAppleClang;
  }

  FileSystemView fs(fs_);
  auto ec = fs.PushWorkingDirectory(working_dir);
  if (ec) {
    err << "Error with working directory '" << working_dir.generic_string()
        << "': " << ec.message();
    return err.str();
  }

  // Get the status of the compiler executable.
  auto maybe_status = fs.Stat(compiler_path);
  if (maybe_status.Failed()) {
    err << "Error with compiler path '" << compiler_path.generic_string()
        << "': " << maybe_status.TakeError().message();
    return err.str();
  }

  // Make sure the compiler path is executable.
  if (maybe_status->type != std::filesystem::file_type::regular ||
      (maybe_status->permissions & kAnyExecutable) ==
          std::filesystem::perms::none) {
    err << "Compiler path '" << maybe_status->real_path.generic_string()
        << "' is not a file or is not executable (type "
        << static_cast<int>(maybe_status->type) << "; perms "
        << static_cast<unsigned>(maybe_status->permissions) << ")";
      return err.str();
  }

  working_dir = fs.CurrentWorkingDirectory();
  compiler_path = std::move(maybe_status->real_path);

  std::shared_ptr<CompilerImpl> impl(std::make_shared<CompilerImpl>(
      fs_, compiler_path, name, lang));

  std::stringstream ss;
  ss << version_info;
  ParseOutputInto(fs, ss, *impl);

  // Give the installation directory a sensible default if missing.
  if (impl->install_dir.empty() && !impl->compiler_exe.empty()) {
    impl->compiler_exe.parent_path().swap(impl->install_dir);
  }

  // If the sysroot looks relative, then assume it's relative to the
  // installation directory, and compute an absolute path.
  if (!impl->sysroot_dir.empty() && !impl->install_dir.empty()) {
    auto maybe_sysroot_path = fs.Stat(impl->install_dir / impl->sysroot_dir);
    if (maybe_sysroot_path.Succeeded() && maybe_sysroot_path->IsDirectory()) {
      impl->sysroot_dir = std::move(maybe_sysroot_path->real_path);
    }
  }

  // Still empty? Take the root directory of the compiler path, and failing
  // that, the root directory of the working directory.
  if (impl->sysroot_dir.empty()) {
    auto maybe_sysroot = fs.RootDirectory(compiler_path);
    if (maybe_sysroot.Succeeded()) {
      maybe_sysroot.TakeValue().swap(impl->sysroot_dir);
    }
  }

  // Still empty? Take the root directory of the current working directory.
  if (impl->sysroot_dir.empty()) {
    std::filesystem::path empty;
    auto maybe_sysroot = fs.RootDirectory(empty);
    if (maybe_sysroot.Succeeded()) {
      maybe_sysroot.TakeValue().swap(impl->sysroot_dir);
    }
  }

  if (impl->sysroot_dir.empty()) {
    err << "Unable to infer system root directory for compiler '"
        << compiler_path.generic_string() << "'";
    return err.str();
  }

  // We might have version information with a fake or different system
  // root directory specified. This is to let us discover which paths
  // are absolute and which ones are sysroot-relative.
  if (!version_info_fake_sysroot.empty()) {

    CompilerImpl fake_sysroot_impl(
        fs_, impl->compiler_exe, impl->compiler_name, impl->target_lang);
    std::stringstream ss2;
    ss2 << version_info_fake_sysroot;
    ParseOutputInto(fs, ss2, fake_sysroot_impl);

    // If we've got "fake" system root-relative versions to compare against
    // then we might be able to do a better job of finding the 'true' system
    // root directory.
    std::filesystem::path sysroot_dir(impl->sysroot_dir);
    std::vector<std::filesystem::path> sysroot_rel_paths;
    FindSystemRootRelPaths(
        fs, impl->system_includes, fake_sysroot_impl.system_includes,
        sysroot_rel_paths);
    FindSystemRootRelPaths(
        fs, impl->user_includes, fake_sysroot_impl.user_includes,
        sysroot_rel_paths);

    FindRealSystemRoot(sysroot_dir, sysroot_rel_paths).swap(impl->sysroot_dir);

    // Relative the paths w.r.t. the true system root directory.
    RelativizePaths(fs, sysroot_dir, impl->system_includes,
                    fake_sysroot_impl.system_includes);
    RelativizePaths(fs, sysroot_dir, impl->user_includes,
                    fake_sysroot_impl.user_includes);
    RelativizePaths(fs, sysroot_dir, impl->frameworks,
                    fake_sysroot_impl.frameworks);
  }

  if (impl->resource_dir.empty() && !DeriveResourceDirs(fs, *impl)) {
    err << "Unable to infer resource directory for compiler '"
        << compiler_path.generic_string() << "'";
    return err.str();
  }

  return Compiler(std::move(impl));
}

}  // namespace pasta
