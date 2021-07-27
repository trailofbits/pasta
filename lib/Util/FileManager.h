/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/FileManager.h>

#include <mutex>
#include <string>
#include <unordered_map>

#include <pasta/Util/File.h>

namespace pasta {

// Implementation of a backing file.
class FileImpl final {
 public:
  FileImpl(const std::shared_ptr<FileManagerImpl> &owner_, Stat stat_);

  const std::weak_ptr<FileManagerImpl> owner;

  // Stat on this file.
  const Stat stat;

  // Have we tried to get data yet?
  bool has_data{false};
  std::error_code data_ec;

  // All data read for the file.
  std::string data;

  // Lock on mutating `data`.
  std::mutex data_lock;
};

// Backing implementation of a file manager.
class FileManagerImpl final
    : public std::enable_shared_from_this<FileManagerImpl> {
 public:

  // File system that is used for directory listings, traversals, etc.
  std::shared_ptr<FileSystem> file_system;

  // Mapping of `path.generic_string()` to open files.
  std::unordered_map<std::string, std::unique_ptr<FileImpl>> open_files;

  // Guards access to `open_files`.
  std::mutex open_files_lock;

  inline FileManagerImpl(std::shared_ptr<FileSystem> file_system_)
      : file_system(std::move(file_system_)) {}
};

}  // namespace pasta
