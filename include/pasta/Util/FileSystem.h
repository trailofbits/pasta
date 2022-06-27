/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>
#include <cstdint>
#include <string>
#include <vector>

#include "StdFileSystem.h"
#include "Result.h"

namespace pasta {

enum class PathKind : signed char {
  kUnix = '/',
  kWindows = '\\'
};

enum class FileType : signed char {
  kNone = static_cast<int8_t>(std::filesystem::file_type::none),
  kNotFound = static_cast<int8_t>(std::filesystem::file_type::not_found),
  kRegular = static_cast<int8_t>(std::filesystem::file_type::regular),
  kDirectory = static_cast<int8_t>(std::filesystem::file_type::directory),
  kSymbolicLink = static_cast<int8_t>(std::filesystem::file_type::symlink),
  kBlock = static_cast<int8_t>(std::filesystem::file_type::block),
  kCharacter = static_cast<int8_t>(std::filesystem::file_type::character),
  kFirstInFirstOut = static_cast<int8_t>(std::filesystem::file_type::fifo),
  kSocket = static_cast<int8_t>(std::filesystem::file_type::socket),
  kKnknown = static_cast<int8_t>(std::filesystem::file_type::unknown),
};

// Stat information about a file.
struct Stat {
  // The full path which was the subject of this stat query.
  std::filesystem::path full_path;

  // The full path of the final file, after following symlinks.
  std::filesystem::path real_path;

  // The type of the file.
  std::filesystem::file_type type;

  // Permissions on the file.
  std::filesystem::perms permissions;

  // Size of the file. Only valid for regular files.
  std::optional<std::uintmax_t> size;

  inline std::filesystem::path FullPath(void) const noexcept {
    return full_path;
  }

  inline std::filesystem::path RealPath(void) const noexcept {
    return real_path;
  }

  inline FileType Type(void) const noexcept {
    return static_cast<FileType>(type);
  }

  inline unsigned Permissions(void) const noexcept {
    return static_cast<unsigned>(permissions);
  }

  inline bool IsSymbolicLink(void) const noexcept {
    return type == std::filesystem::file_type::symlink;
  }

  inline bool IsRegularFile(void) const noexcept {
    return type == std::filesystem::file_type::regular;
  }

  inline bool IsDirectory(void) const noexcept {
    return type == std::filesystem::file_type::directory;
  }
};

// Virtual interface to a file system.
class FileSystem : public std::enable_shared_from_this<FileSystem> {
 public:
  virtual ~FileSystem(void);

  // Create a native file system.
  static std::shared_ptr<FileSystem> CreateNative(void);

  // Parse a string into a file system path.
  std::filesystem::path ParsePath(std::string path,
                                  std::filesystem::path cwd,
                                  ::pasta::PathKind kind);

  // Returns `true` if `path` looks like a resource directory for a compiler.
  bool IsResourceDir(std::filesystem::path path, std::filesystem::path cwd);

  // Tells us what kind of file system path to use.
  virtual ::pasta::PathKind PathKind(void) const = 0;

  // Checks if a file exists. By default this is implemented with `Stat`.
  virtual bool FileExists(std::filesystem::path path,
                          std::filesystem::path cwd);

  // Try to read the contents of a file.
  virtual Result<std::string, std::error_code> ReadFile(
      std::filesystem::path path, std::filesystem::path cwd);

  // Try to read the contents of a file, given the result of a `Stat` call.
  virtual Result<std::string, std::error_code> ReadFile(::pasta::Stat) = 0;

  // Return the root directory of `path`, possibly within the context of `cwd`.
  virtual Result<std::filesystem::path, std::error_code>
  RootDirectory(std::filesystem::path path, std::filesystem::path cwd) = 0;

  // Return the current working directory of the process.
  virtual Result<std::filesystem::path, std::error_code>
  CurrentWorkingDirectory(void) = 0;

  // Get information about a file path.
  virtual Result<::pasta::Stat, std::error_code>
  Stat(std::filesystem::path path, std::filesystem::path cwd) = 0;

  // List out the files in a directory.
  virtual Result<std::vector<std::filesystem::path>, std::error_code>
  ListDirectory(std::filesystem::path path,
                std::filesystem::path cwd);

  // List out the files in a directory.
  virtual Result<std::vector<std::filesystem::path>, std::error_code>
  ListDirectory(::pasta::Stat stat) = 0;
};

// Represents a view into the current file system. A file system view maintains
// its own stack of working directories that is independent of the process-wide
// current working directory; however, it does try to initialize its internal
// stack with the `FileSystem`-provided CWD.
class FileSystemView {
 private:
  FileSystemView(void) = delete;

  std::shared_ptr<FileSystem> impl;
  std::vector<std::filesystem::path> cwd;

 public:
  explicit FileSystemView(std::shared_ptr<FileSystem> impl_);

  // Return the file system associated with this view.
  inline std::shared_ptr<::pasta::FileSystem> UnderlyingFileSystem(void) const {
    return impl;
  }

  // Return the current working directory of the process.
  std::filesystem::path CurrentWorkingDirectory(void) const;

  // Return the root directory of `path`, possibly within the context of
  // `CurrentWorkingDirectory()`.
  Result<std::filesystem::path, std::error_code>
  inline RootDirectory(std::filesystem::path path) const {
    return impl->RootDirectory(std::move(path), CurrentWorkingDirectory());
  }

  // Parse a path string into a path object.
  inline std::filesystem::path ParsePath(std::string path) const {
    return impl->ParsePath(
        std::move(path), CurrentWorkingDirectory(), impl->PathKind());
  }

  // Parse a path string into a path object.
  inline std::filesystem::path ParsePath(std::string path,
                                         std::string cwd) const {
    const auto pk = impl->PathKind();
    if (cwd.empty()) {
      return impl->ParsePath(std::move(path), CurrentWorkingDirectory(), pk);
    } else {
      return impl->ParsePath(
          std::move(path),
          impl->ParsePath(std::move(cwd), CurrentWorkingDirectory(), pk),
          pk);
    }
  }

  // Returns `true` if `path` looks like a resource directory for a compiler.
  inline bool IsResourceDir(std::filesystem::path path) const {
    return impl->IsResourceDir(std::move(path), CurrentWorkingDirectory());
  }

  // Get information about a file path.
  inline Result<::pasta::Stat, std::error_code>
  Stat(std::filesystem::path path) const {
    return impl->Stat(std::move(path), CurrentWorkingDirectory());
  }

  // Try to read the contents of a file.
  inline Result<std::string, std::error_code> ReadFile(
      std::filesystem::path path) const {
    return impl->ReadFile(std::move(path), CurrentWorkingDirectory());
  }

  // Try to read the contents of a file, given the result of a `Stat` call.
  inline Result<std::string, std::error_code> ReadFile(
      ::pasta::Stat stat) const {
    return impl->ReadFile(std::move(stat));
  }

  // List out the files in a directory.
  inline Result<std::vector<std::filesystem::path>, std::error_code>
  ListDirectory(std::filesystem::path path) const {
    return impl->ListDirectory(std::move(path), CurrentWorkingDirectory());
  }

  // List out the files in a directory.
  inline Result<std::vector<std::filesystem::path>, std::error_code>
  ListDirectory(::pasta::Stat stat) const {
    return impl->ListDirectory(std::move(stat));
  }

  // Change the current working directory.
  std::error_code PushWorkingDirectory(std::filesystem::path path);

  inline void PopWorkingDirectory(void) {
    cwd.pop_back();
  }
};

// An RAII wrapper around a `FileSystemView` that lets us push/pop a current
// working directory for some lexical scope.
class InWorkingDirectory {
 private:
  FileSystemView &view;

 public:
  inline InWorkingDirectory(FileSystemView &view_, std::filesystem::path path)
      : view(view_) {
    view.PushWorkingDirectory(std::move(path));
  }

  inline ~InWorkingDirectory(void) {
    view.PopWorkingDirectory();
  }
};

}  // namespace pasta
