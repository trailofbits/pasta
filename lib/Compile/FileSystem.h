/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/Support/ErrorOr.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Path.h>
#include <llvm/Support/VirtualFileSystem.h>
#pragma clang diagnostic pop

#include <string>
#include <vector>

#include <pasta/Util/File.h>
#include <pasta/Util/FileManager.h>

namespace pasta {

class LLVMFile final : public llvm::vfs::File {
 public:
  virtual ~LLVMFile(void);

  inline LLVMFile(::pasta::File impl_)
      : impl(std::move(impl_)) {}

  // Get the status of the file.
  llvm::ErrorOr<llvm::vfs::Status> status(void) final;

  // Get the name of the file.
  llvm::ErrorOr<std::string> getName(void) final;

  // Get the contents of the file as a `MemoryBuffer`.
  llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>>
  getBuffer(const llvm::Twine &name, int64_t file_size = -1,
            bool requires_null_terminator = true,
            bool is_volatile = false) final;

  /// Closes the file.
  std::error_code close(void) final;

  ::pasta::File impl;
};

class LLVMDirectoryIterator final : public llvm::vfs::detail::DirIterImpl {
 public:
  virtual ~LLVMDirectoryIterator(void);

  inline explicit LLVMDirectoryIterator(std::vector<::pasta::Stat> paths_)
      : paths(std::move(paths_)) {}

  std::error_code increment(void) final;

 private:
  LLVMDirectoryIterator(void) = delete;

  std::vector<::pasta::Stat> paths;
  unsigned index{0};
};

class LLVMFileSystem final : public llvm::vfs::FileSystem {
 private:
  LLVMFileSystem(void) = delete;

  ::pasta::FileManager file_manager;
  ::pasta::FileSystemView file_system;

 public:
  virtual ~LLVMFileSystem(void);

  inline LLVMFileSystem(::pasta::FileManager file_manager_)
      : file_manager(std::move(file_manager_)),
        file_system(file_manager.FileSystem()) {}

  // Get the status of the entry at `path`, if one exists.
  llvm::ErrorOr<llvm::vfs::Status> status(const llvm::Twine &path) final;

  // Get an `LLVMFile` object for the file at `path`, if one exists.
  llvm::ErrorOr<std::unique_ptr<llvm::vfs::File>>
  openFileForRead(const llvm::Twine &path) final;

  // Get a `directory_iterator` for `path`.
  llvm::vfs::directory_iterator dir_begin(
      const llvm::Twine &path, std::error_code &ec) final;

  // Set the current working directory to `path`.
  std::error_code setCurrentWorkingDirectory(const llvm::Twine &path) final;

  // Get the working directory of this file system.
  llvm::ErrorOr<std::string> getCurrentWorkingDirectory(void) const final;

  // Gets real path of `path` e.g. collapse all `.` and `..` patterns, resolve
  // symlinks.
  std::error_code getRealPath(const llvm::Twine &path,
                              llvm::SmallVectorImpl<char> &output) const final;

  // Is the file mounted on a local filesystem?
  std::error_code isLocal(const llvm::Twine &path, bool &result) final;

  // Make `path` an absolute path.
  std::error_code makeAbsolute(llvm::SmallVectorImpl<char> &path) const final;
};

}  // namespace pasta
