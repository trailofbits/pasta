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

struct FileTokenImpl {
  inline FileTokenImpl(const char *data_, unsigned line_, unsigned column_,
                       unsigned kind_)
      : data(data_),
        line(line_),
        column(static_cast<uint16_t>(column_)),
        kind(static_cast<uint16_t>(kind_)) {}
  const char *data;
  unsigned line;
  uint16_t column;
  uint16_t kind;
};

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

  // NOTE(pag): The rest of the stuff related to `tokens` is all filled in
  //            by the `ParsedFileTracker` of `CompileJob::Run`.

  // Lock on mutating `tokens`.
  std::mutex tokens_lock;
  bool has_tokens{false};

  // This points into `data`. A token is bound by `token_data[i]` and
  // `token_data[i + 1]`.
  std::vector<FileTokenImpl> tokens;
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
