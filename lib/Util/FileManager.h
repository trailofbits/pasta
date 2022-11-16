/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/FileManager.h>

#include <mutex>
#include <string>
#include <unordered_map>

#include <pasta/Util/File.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/TokenKinds.h>
#pragma GCC diagnostic pop

namespace pasta {

static_assert(
    static_cast<unsigned>(clang::tok::TokenKind::NUM_TOKENS) <= (1u << 9u));

struct FileTokenImpl {
  inline FileTokenImpl(uint32_t data_offset_, uint32_t data_len_,
                       uint32_t line_, unsigned column_,
                       clang::tok::TokenKind kind_)
      : data_offset(data_offset_),
        data_len(data_len_),
        line(line_),
        column(static_cast<uint16_t>(column_)) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
    kind.extended.kind = static_cast<uint16_t>(kind_);
#pragma GCC diagnostic pop
  }
  uint32_t data_offset;
  uint32_t data_len;
  uint32_t line;
  uint16_t column;

  inline clang::tok::TokenKind Kind(void) const noexcept {
    return static_cast<clang::tok::TokenKind>(kind.extended.kind);
  }

  union {
    uint16_t flat{0};
    struct {
      uint16_t kind:9;
      uint16_t is_pp_kw:1;
      uint16_t is_objc_kw:1;
      uint16_t alt_kind:5;
    } extended;
  } __attribute__((packed)) kind;
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
