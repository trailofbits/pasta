/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "FileManager.h"

namespace pasta {

FileManager::~FileManager(void) {}

FileManager::FileManager(std::shared_ptr<class FileSystem> fs_)
    : impl(std::make_shared<FileManagerImpl>(std::move(fs_))) {}

// Return the file system associated with this file manager.
std::shared_ptr<::pasta::FileSystem> FileManager::FileSystem(void) const {
  return impl->file_system;
}

// Return the file manager containing a file.
FileManager FileManager::Containing(const File &file) {
  return FileManager(file.impl->owner.lock());
}

// Try to open a file.
Result<File, std::error_code> FileManager::OpenFile(Stat stat) const {

  if (stat.type != std::filesystem::file_type::regular) {
    return std::make_error_code(std::errc::operation_not_supported);
  }

  auto file_path = stat.full_path.generic_string();

  std::unique_lock<std::mutex> locker(impl->open_files_lock);
  auto it = impl->open_files.find(file_path);

  FileImpl *ptr = nullptr;

  // We don't yet have this file; go try and read it.
  if (it == impl->open_files.end()) {
    ptr = new FileImpl(impl, std::move(stat));
    it = impl->open_files.try_emplace(
        std::move(file_path), ptr).first;

    // This shouldn't happen.
    if (ptr != it->second.get()) {
      delete ptr;
      ptr = it->second.get();
    }

  // We've got the file.
  } else {
    ptr = it->second.get();
  }

  // Create an return an aliasing shared pointer of the `FileManager`.
  std::shared_ptr<FileImpl> file_impl(impl, ptr);
  return File(std::move(file_impl));
}

}  // namespace pasta
