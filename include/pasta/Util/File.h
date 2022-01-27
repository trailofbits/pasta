/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <cstdint>
#include <iterator>
#include <memory>
#include <optional>
#include <string_view>
#include <system_error>

#include "Result.h"
#include "StdFileSystem.h"

namespace clang {
namespace tok {
enum TokenKind : unsigned short;
}  // namespace tok
}  // namspace clang
namespace pasta {

class AST;
class ASTImpl;
class File;
class FileImpl;
class FileManager;
class FileManagerImpl;
class FileTokenIterator;
class FileFileTokenRange;
class ParsedFileTracker;
struct Stat;
struct FileTokenImpl;

// A file token is a token, lexed from a file, but which is not directly
// associated with a specific parse or AST. Instead, AST tokens and macro
// expansion tokens can be associated with file tokens.
class FileToken {
 private:
  friend class File;
  friend class FileImpl;
  friend class FileTokenIterator;
  friend class FileTokenRange;

  FileToken(void) = delete;

  std::shared_ptr<FileImpl> file;
  const FileTokenImpl *impl;

  inline FileToken(std::shared_ptr<FileImpl> file_, const FileTokenImpl *impl_)
      : file(std::move(file_)),
        impl(impl_) {}

 public:
  ~FileToken(void);

  // Kind of this token.
  clang::tok::TokenKind Kind(void) const noexcept;

  int PreProcessorKeywordKind(void) const noexcept;
  int ObjectiveCAtKeywordKind(void) const noexcept;

  // Kind of this token.
  const char *KindName(void) const noexcept;

  // Return the line number associated with this token.
  unsigned Line(void) const noexcept;

  // Return the column number associated with this token.
  unsigned Column(void) const noexcept;

  // Return the data associated with this token.
  std::string_view Data(void) const noexcept;

  // Index of this token within its file.
  uint64_t Index(void) const noexcept;

  inline bool operator<(const FileToken &that) const noexcept {
    return file == that.file && impl < that.impl;
  }

  inline bool operator<=(const FileToken &that) const noexcept {
    return file == that.file && impl <= that.impl;
  }

  inline bool operator>(const FileToken &that) const noexcept {
    return file == that.file && impl > that.impl;
  }

  inline bool operator>=(const FileToken &that) const noexcept {
    return file == that.file && impl >= that.impl;
  }

  inline bool operator==(const FileToken &that) const noexcept {
    return file == that.file && impl == that.impl;
  }

  inline bool operator!=(const FileToken &that) const noexcept {
    return file != that.file || impl != that.impl;
  }
};

// A bi-directional, random-access iterator over tokens.
class FileTokenIterator {
 public:
  typedef FileToken value_type;
  typedef ptrdiff_t difference_type;
  typedef const FileToken *pointer;
  typedef const FileToken &reference;
  typedef std::random_access_iterator_tag iterator_category;

  FileTokenIterator(const FileTokenIterator &) = default;
  FileTokenIterator(FileTokenIterator &&) noexcept = default;
  FileTokenIterator &operator=(const FileTokenIterator &) = default;
  FileTokenIterator &operator=(FileTokenIterator &&) noexcept = default;

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const FileToken &operator*(void) const noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const FileToken *operator->(void) const noexcept {
    return &token;
  }

  FileTokenIterator &operator++(void) noexcept;
  FileTokenIterator operator++(int) noexcept;
  FileTokenIterator &operator--(void) noexcept;
  FileTokenIterator operator--(int) noexcept;
  FileTokenIterator operator+(size_t offset) const noexcept;
  FileTokenIterator operator-(size_t offset) const noexcept;
  FileTokenIterator &operator+=(size_t offset) noexcept;
  FileTokenIterator &operator-=(size_t offset) noexcept;
  FileToken operator[](size_t offset) const noexcept;
  ptrdiff_t operator-(const FileTokenIterator &that) const noexcept;

  inline bool operator!=(const FileTokenIterator &that) const noexcept {
    return token != that.token;
  }

  inline bool operator==(const FileTokenIterator &that) const noexcept {
    return token == that.token;
  }

  inline bool operator<=(const FileTokenIterator &that) const noexcept {
    return token <= that.token;
  }

  inline bool operator>=(const FileTokenIterator &that) const noexcept {
    return token >= that.token;
  }

  inline bool operator<(const FileTokenIterator &that) const noexcept {
    return token < that.token;
  }

  inline bool operator>(const FileTokenIterator &that) const noexcept {
    return token > that.token;
  }

 private:
  friend class FileTokenRange;

  FileTokenIterator(void) = delete;

  inline explicit FileTokenIterator(const std::shared_ptr<FileImpl> &file_,
                                    const FileTokenImpl *impl_)
      : token(file_, impl_) {}

  FileToken token;
};

// Range of file tokens.
class FileTokenRange {
 public:
  FileTokenRange(const FileTokenRange &) = default;
  FileTokenRange(FileTokenRange &&) noexcept = default;
  FileTokenRange &operator=(const FileTokenRange &) = default;
  FileTokenRange &operator=(FileTokenRange &&) noexcept = default;

  inline FileTokenIterator begin(void) const noexcept {
    return FileTokenIterator(file, first);
  }

  inline FileTokenIterator end(void) const noexcept {
    return FileTokenIterator(file, after_last);
  }

  inline size_t size(void) const noexcept {
    return Size();
  }

  // Number of tokens in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<FileToken> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  FileToken operator[](size_t index) const;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }

 private:
  friend class File;
  friend class FileImpl;

  FileTokenRange(void) = delete;

  inline explicit FileTokenRange(std::shared_ptr<FileImpl> file_)
      : file(std::move(file_)),
        first(nullptr),
        after_last(nullptr) {}

  inline explicit FileTokenRange(std::shared_ptr<FileImpl> file_,
                                 const FileTokenImpl *begin_,
                                 const FileTokenImpl *end_)
      : file(std::move(file_)),
        first(begin_),
        after_last(end_) {}

  std::shared_ptr<FileImpl> file;
  const FileTokenImpl *first;
  const FileTokenImpl *after_last;
};

// Represents an open file.
class File {
 private:
  friend class AST;
  friend class ASTImpl;
  friend class FileManager;
  friend class FileManagerImpl;
  friend class ParsedFileTracker;

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

  // Did we parse this file as part of trying to make an AST?
  bool WasParsed(void) const noexcept;

  // Returns the status of this file.
  const ::pasta::Stat &Stat(void) const noexcept;

  // Return a range of file tokens.
  FileTokenRange Tokens(void) const noexcept;

  // Return a token at a specific file offset.
  std::optional<FileToken> TokenAtOffset(unsigned offset) const noexcept;

  inline bool operator==(const File &that) const noexcept {
    return impl == that.impl;
  }

  inline bool operator!=(const File &that) const noexcept {
    return impl != that.impl;
  }

  inline uint64_t HashCode(void) const noexcept {
    return std::hash<void *>{}(impl.get());
  }
};

}  // namespace pasta
namespace std {
template <>
struct hash<::pasta::File> {
 public:
  inline uint64_t operator()(const ::pasta::File &file) const noexcept {
    return file.HashCode();
  }
};
}  // namespace std
