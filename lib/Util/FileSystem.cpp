/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Util/FileSystem.h>

#include <algorithm>
#include <cassert>
#include <cerrno>
#include <string_view>

#include <fstream>
#include <streambuf>

#include <pasta/Util/Error.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wfloat-conversion"
#include <llvm/Support/JSON.h>
#pragma clang diagnostic pop

#include "FileManager.h"

namespace pasta {
namespace {

static constexpr int kMaxFollowSymlinks = 10;

#if defined(__CYGWIN__)
#  error "Handle Cygwin"
#endif

#if defined(_WIN32) || defined(_MSC_VER)
static constexpr auto kNativePathKind = ::pasta::PathKind::kWindows;
#else
static constexpr auto kNativePathKind =::pasta::PathKind::kUnix;
#endif

static const std::error_code kErrNoSuchFileOrDirectory =
    std::make_error_code(std::errc::no_such_file_or_directory);

static const std::error_code kErrTooManySymbolicLinkLevels =
    std::make_error_code(std::errc::too_many_symbolic_link_levels);

static const std::error_code kErrNotRecoverable =
    std::make_error_code(std::errc::state_not_recoverable);

static const std::error_code kErrNotADirectory =
    std::make_error_code(std::errc::not_a_directory);

static const std::error_code kErrNotSupported =
    std::make_error_code(std::errc::operation_not_supported);

static const std::error_code kErrIOError =
    std::make_error_code(std::errc::io_error);

static const std::error_code kErrNotPermitted =
    std::make_error_code(std::errc::operation_not_permitted);

static constexpr auto kAnyRead =
    std::filesystem::perms::group_read |
    std::filesystem::perms::others_read |
    std::filesystem::perms::owner_read;

// Implementation of a native file system.
class NativeFileSystem final : public FileSystem {
 public:
  virtual ~NativeFileSystem(void) = default;

  // Tells us what kind of file system path to use.
  ::pasta::PathKind PathKind(void) const final;

  // Try to read the contents of a file.
  Result<std::string, std::error_code> ReadFile(::pasta::Stat stat) final;

  // Return the root directory of `path`, possibly within the context of `cwd`.
  Result<std::filesystem::path, std::error_code>
  RootDirectory(std::filesystem::path path, std::filesystem::path cwd) final;

  // Return the current working directory of the process.
  Result<std::filesystem::path, std::error_code>
  CurrentWorkingDirectory(void) final;

  // Get information about a file path.
  Result<::pasta::Stat, std::error_code>
  Stat(std::filesystem::path path, std::filesystem::path cwd) final;

  // List out the files in a directory.
  Result<std::vector<std::filesystem::path>, std::error_code>
  ListDirectory(::pasta::Stat stat) final;
};

// Tells us what kind of file system path to use.
::pasta::PathKind NativeFileSystem::PathKind(void) const {
  return kNativePathKind;
}

// Make `path` absolute if it's not already.
std::filesystem::path FullPath(std::filesystem::path path,
                               std::filesystem::path working_dir,
                               ::pasta::PathKind kind) {
  if (path.empty()) {
    assert(working_dir.is_absolute());
    return working_dir.lexically_normal();
  }

  if (path.is_absolute()) {
    return path.lexically_normal();
  }

  assert(working_dir.is_absolute());
  auto full_path = (working_dir / path).lexically_normal();
  assert(full_path.is_absolute());
  return full_path;
}

// Try to read the contents of a file.
Result<std::string, std::error_code> NativeFileSystem::ReadFile(
    ::pasta::Stat stat) {

  if ((kAnyRead & stat.permissions) == std::filesystem::perms::none) {
    return kErrNotPermitted;
  }

  std::string ret;
  if (stat.size.has_value()) {
    ret.reserve(stat.size.value());
  }

  ClearLastError();

  std::ifstream f(stat.real_path.generic_string(),
                  std::ios_base::in | std::ios_base::binary);

  if (f.fail()) {
    auto ret = GetLastError();
    if (!ret) {
      ret = kErrNotSupported;
    }
    return ret;
  }


  ret.assign((std::istreambuf_iterator<char>(f)),
              std::istreambuf_iterator<char>());

  // Force the `ifstream` to synchronize its `eofbit`.
  (void) f.get();

  if (!f.eof()) {
    auto ret = GetLastError();
    if (!ret) {
      ret = kErrNotSupported;
    }
    return ret;
  }

  f.close();

  // A lot of code in PASTA relies on the file being formatted as UTF-8.
  if (!llvm::json::isUTF8(ret)) {
    ret = llvm::json::fixUTF8(ret);
  }

  // strip Byte-Offset Marker from UTF8
  skipBOM(ret);
  return ret;
}

// Return the root directory of `path`, possibly within the context of `cwd`.
Result<std::filesystem::path, std::error_code>
NativeFileSystem::RootDirectory(std::filesystem::path path,
                                std::filesystem::path cwd) try {
  auto root_path = FullPath(std::move(path),
                  std::move(cwd),
                  kNativePathKind).root_directory();

  std::error_code ec;
  if (std::filesystem::is_directory(root_path, ec)) {
    return root_path;
  } else if (ec) {
    return ec;
  } else {
    return kErrNotADirectory;
  }

} catch (std::filesystem::filesystem_error &fse) {
  return fse.code();

} catch (...) {
  return kErrNotRecoverable;
}

// Return the current working directory of the process.
Result<std::filesystem::path, std::error_code>
NativeFileSystem::CurrentWorkingDirectory(void) try {
  std::error_code ec;
  auto native = std::filesystem::current_path(ec);
  if (ec) {
    return ec;
  } else {
    std::filesystem::path ret(
        native, std::filesystem::path::format::generic_format);
    return ret;
  }

} catch (std::filesystem::filesystem_error &fse) {
  return fse.code();

} catch (...) {
  return kErrNotRecoverable;
}

// Get information about a file path.
Result<::pasta::Stat, std::error_code>
NativeFileSystem::Stat(std::filesystem::path path,
                       std::filesystem::path cwd) try {
  std::error_code ec;
  path = FullPath(std::move(path), std::move(cwd), kNativePathKind);
  auto stat = std::filesystem::status(path, ec);
  if (ec) {
    return ec;
  } else if (!std::filesystem::status_known(stat)) {
    return kErrNoSuchFileOrDirectory;
  }

  auto abs_path = path;
  for (auto num_followed = 0;
       stat.type() == std::filesystem::file_type::symlink;
       ++num_followed) {

    if (num_followed >= kMaxFollowSymlinks) {
      return kErrTooManySymbolicLinkLevels;
    }

    abs_path = std::filesystem::canonical(abs_path, ec);
    if (ec) {
      return ec;
    }

    stat = std::filesystem::status(abs_path, ec);
    if (ec) {
      return ec;
    } else if (!std::filesystem::status_known(stat)) {
      return kErrNoSuchFileOrDirectory;
    }
  }

  ::pasta::Stat ret;
  ret.full_path = std::move(path);
  ret.real_path = abs_path.lexically_normal();
  ret.permissions = stat.permissions();
  ret.type = stat.type();

  if (std::filesystem::file_type::regular == ret.type) {
    ret.size = std::filesystem::file_size(ret.real_path, ec);
    if (ec) {
      return ec;
    }
  }
  return ret;

} catch (std::filesystem::filesystem_error &fse) {
  return fse.code();

} catch (...) {
  return kErrNotRecoverable;
}

// List out the files in a directory.
Result<std::vector<std::filesystem::path>, std::error_code>
NativeFileSystem::ListDirectory(::pasta::Stat stat) try {
  std::error_code ec;
  if (stat.type != std::filesystem::file_type::directory) {
    return kErrNotADirectory;
  }

  const std::filesystem::directory_options options =
      std::filesystem::directory_options::follow_directory_symlink |
      std::filesystem::directory_options::skip_permission_denied;

  std::filesystem::directory_iterator it(stat.full_path, options, ec);
  if (ec) {
    return ec;
  }

  std::vector<std::filesystem::path> ret;

  for (const std::filesystem::directory_iterator it_end; it != it_end; ++it) {
    const std::filesystem::directory_entry &curr = *it;
    ret.emplace_back(FullPath(curr.path(), stat.full_path, kNativePathKind));
  }

  return ret;

} catch (std::filesystem::filesystem_error &fse) {
  return fse.code();

} catch (...) {
  return kErrNotRecoverable;
}

}  // namespace

FileSystem::~FileSystem(void) {}

// Create a native file system.
std::shared_ptr<::pasta::FileSystem> FileSystem::CreateNative(void) {
  return std::make_shared<NativeFileSystem>();
}

// Returns `true` if `path` looks like a resource directory for a compiler.
bool FileSystem::IsResourceDir(std::filesystem::path path,
                               std::filesystem::path cwd) try {
  auto maybe_status = Stat(path / "include" / "stdarg.h", cwd);
  return maybe_status.Succeeded() &&
         maybe_status->type == std::filesystem::file_type::regular;

} catch (std::filesystem::filesystem_error &fse) {
  return false;

} catch (...) {
  return false;
}

// Parse a string into a file system path.
std::filesystem::path FileSystem::ParsePath(std::string path,
                                            std::filesystem::path cwd,
                                            ::pasta::PathKind kind) {
  if (path.empty() || path == ".") {
    return cwd.lexically_normal();
  }

  bool is_absolute = false;

  // Normalize Windows paths to look like UNIX paths.
  if (kind == ::pasta::PathKind::kWindows) {
    std::replace(path.begin(), path.end(), '/', '\\');
    assert(path.front() != '/');
  } else {
    if (path.front() == '/') {
      is_absolute = true;
    }
  }

  std::vector<std::string_view> parts;
  const char *buff = &(path.front());
  const char *prev_buff = buff;
  const char * const buff_end = &(path.back()) + 1u;

  // Cases:
  //
  //    /               a/             /a/
  //    ^ buff           ^ buff          ^ buff
  //    ^ prev_buff     ^ prev_buff     ^ prev_buff
  auto add_path_part = [&] (void) {
    if (buff <= buff_end && prev_buff < buff) {
      parts.emplace_back(prev_buff, static_cast<size_t>(buff - prev_buff));
    }
    prev_buff = &(buff[1]);
  };

  for (; buff < buff_end && buff[0]; ++buff) {
    if (buff[0] == '/') {
      add_path_part();
    }
  }
  add_path_part();

  if (parts.empty()) {
    if (is_absolute) {
      return cwd.root_path();
    } else {
      return cwd;
    }
  }

  std::string root_path = cwd.root_name().generic_string();

  if (kind == ::pasta::PathKind::kWindows) {

    // Figure out if it looks like an absolute path. We use a path part
    // ending with a colon to signal that it's a drive.
    if (parts.front().back() == ':') {
      is_absolute = true;

    // Force it to be absolute.
    } else if (is_absolute && !root_path.empty()) {
      std::string_view root_name(root_path.data(), root_path.size());
      parts.insert(parts.begin(), root_name);
    }
  }

  // Build up the path.
  std::filesystem::path base_path;
  if (!is_absolute) {
    base_path = cwd;

  // TODO(pag): What should the root path be on Windows?
  } else if (cwd.empty()) {
    base_path = "/";

  } else {
    base_path = cwd.root_path();
  }

  for (auto part : parts) {
    base_path /= part;
  }

  return base_path.lexically_normal();
}

// Checks if a file exists. By default this is implemented with `Stat`.
bool FileSystem::FileExists(std::filesystem::path path,
                            std::filesystem::path cwd) {
  auto maybe_stat = this->Stat(std::move(path), std::move(cwd));
  if (maybe_stat.Succeeded()) {
    return maybe_stat->type != std::filesystem::file_type::not_found;
  } else {
    return false;
  }
}

// Try to read the contents of a file.
Result<std::string, std::error_code> FileSystem::ReadFile(
      std::filesystem::path path, std::filesystem::path cwd) {
  auto stat = this->Stat(std::move(path), std::move(cwd));
  if (stat.Succeeded()) {
    return this->ReadFile(stat.TakeValue());
  } else {
    return stat.TakeError();
  }
}

// List out the files in a directory.
Result<std::vector<std::filesystem::path>, std::error_code>
FileSystem::ListDirectory(std::filesystem::path path,
                          std::filesystem::path cwd) {
  auto stat = this->Stat(std::move(path), std::move(cwd));
  if (stat.Succeeded()) {
    return this->ListDirectory(stat.TakeValue());
  } else {
    return stat.TakeError();
  }
}

FileSystemView::FileSystemView(std::shared_ptr<::pasta::FileSystem> impl_)
    : impl(std::move(impl_)) {
  auto maybe_cwd = impl->CurrentWorkingDirectory();
  if (maybe_cwd.Succeeded()) {
    cwd.emplace_back(maybe_cwd.TakeValue());
  }
}

std::error_code FileSystemView::PushWorkingDirectory(
    std::filesystem::path path) {
  auto maybe_status = impl->Stat(std::move(path), CurrentWorkingDirectory());
  if (!maybe_status.Succeeded()) {
    return maybe_status.TakeError();

  } else if (maybe_status->type != std::filesystem::file_type::directory) {
    return kErrNotADirectory;

  } else {
    cwd.emplace_back(std::move(maybe_status->real_path));
    return {};
  }
}

// Return the current working directory of the process.
std::filesystem::path FileSystemView::CurrentWorkingDirectory(void) const {
  if (cwd.empty()) {
    return {};
  } else {
    return cwd.back();
  }
}

}  // namespace pasta
