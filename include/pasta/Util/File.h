/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <cstdint>
#include <memory>
#include <string_view>
#include <system_error>

#include "Result.h"
#include "StdFileSystem.h"

namespace pasta {

class AST;
class ASTImpl;
class File;
class FileImpl;
class FileManager;
class FileManagerImpl;
struct Stat;

// A file token is a token, lexed from a file, but which is not directly
// associated with a specific parse or AST. Instead, AST tokens and macro
// expansion tokens can be associated with file tokens.
class FileToken {
 private:
  friend class File;

  FileToken(void) = delete;

  std::shared_ptr<FileImpl> impl;
  uint64_t index;

 public:
  ~FileToken(void);

  // Return the line number associated with this token.
  unsigned Line(void) const noexcept;

  // Return the column number associated with this token.
  unsigned Column(void) const noexcept;

  // Return the data associated with this token.
  std::string_view Data(void) const noexcept;

  // Index of this token within its file.
  inline uint64_t Index(void) const noexcept {
    return index;
  }

  inline bool operator==(const FileToken &that) const noexcept {
    return impl == that.impl && index == that.index;
  }

  inline bool operator!=(const FileToken &that) const noexcept {
    return impl != that.impl || index != that.index;
  }
};

// Represents an open file.
class File {
 private:
  friend class AST;
  friend class ASTImpl;
  friend class FileManager;
  friend class FileManagerImpl;

  File(void) = delete;

  std::shared_ptr<FileImpl> impl;

  inline File(std::shared_ptr<FileImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  ~File(void);

  // Return the file containing a given file token.
  static File Containing(const FileToken &tok);

  // Return the path of this file from within its file system.
  std::filesystem::path Path(void) const noexcept;

  // Return the contents of this file.
  Result<std::string_view, std::error_code> Data(void) const noexcept;

  // Do we have cached data associated with this file?
  bool HasCachedData(void) const noexcept;

  // Returns the status of this file.
  const ::pasta::Stat &Stat(void) const noexcept;

  // Unique ID of this file.
  uint64_t Id(void) const noexcept;

  inline bool operator==(const File &that) const noexcept {
    return impl == that.impl;
  }

  inline bool operator!=(const File &that) const noexcept {
    return impl != that.impl;
  }
};

}  // namespace pasta
