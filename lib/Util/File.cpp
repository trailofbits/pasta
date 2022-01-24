/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/Util/File.h>

#include <algorithm>

#include "FileManager.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/TokenKinds.h>
#pragma clang diagnostic pop

namespace pasta {

FileImpl::FileImpl(const std::shared_ptr<FileManagerImpl> &owner_, Stat stat_)
    : owner(owner_),
      stat(std::move(stat_)) {}

FileToken::~FileToken(void) {}

File::~File(void) {}

// Return the file containing a given file token.
File File::Containing(const FileToken &tok) {
  return File(tok.file);
}

// Return the path of this file.
std::filesystem::path File::Path(void) const noexcept {
  return impl->stat.full_path;
}

// Return the contents of this file.
Result<std::string_view, std::error_code> File::Data(void) const noexcept {
  std::unique_lock<std::mutex> locker(impl->data_lock);
  if (impl->has_data) {
    if (impl->data_ec) {
      return impl->data_ec;
    } else {
      return std::string_view(impl->data.data(), impl->data.size());
    }
  }

  impl->has_data = true;

  auto fm = impl->owner.lock();
  auto maybe_file = fm->file_system->ReadFile(impl->stat);
  if (maybe_file.Succeeded()) {
    maybe_file.TakeValue().swap(impl->data);
    return std::string_view(impl->data.data(), impl->data.size());
  } else {
    impl->data_ec = maybe_file.TakeError();
    return impl->data_ec;
  }
}

// Do we have cached data associated with this file?
bool File::WasParsed(void) const noexcept {
  std::unique_lock<std::mutex> locker(impl->tokens_lock);
  return impl->has_tokens;
}

// Returns the status of this file.
const ::pasta::Stat &File::Stat(void) const noexcept {
  return impl->stat;
}

// Return a range of file tokens.
FileTokenRange File::Tokens(void) const noexcept {
  std::unique_lock<std::mutex> locker(impl->tokens_lock);
  if (1u >= impl->tokens.size()) {
    return FileTokenRange(impl);

  // NOTE(pag): The last token in the range exists to provide the ending
  //            pointer for the data of the "true" last token.
  } else {
    auto begin = impl->tokens.data();
    return FileTokenRange(impl, begin, &(begin[impl->tokens.size() - 1]));
  }
}

// Return a token at a specific file offset.
std::optional<FileToken> File::TokenAtOffset(unsigned offset) const noexcept {

  const char *data_ptr = nullptr;
  {
    std::unique_lock<std::mutex> locker(impl->data_lock);
    if (offset >= impl->data.size()) {
      return std::nullopt;
    }

    data_ptr = &(impl->data[offset]);
  }

  FileTokenImpl fake_tok(data_ptr, 0, 0, 0);

  {
    std::unique_lock<std::mutex> locker(impl->tokens_lock);
    auto tokens = impl->tokens.data();
    auto end_tokens = &(impl->tokens[impl->tokens.size()]);
    auto ret = std::lower_bound(
        tokens, end_tokens, fake_tok,
        [] (const FileTokenImpl &a, const FileTokenImpl &b) {
          return a.data < b.data;
        });

    if (tokens <= ret && ret < end_tokens) {
      return FileToken(impl, ret);
    }
  }

  return std::nullopt;
}

// Kind of this token.
unsigned FileToken::Kind(void) const noexcept {
  return impl ? impl->kind : clang::tok::unknown;
}

// Kind of this token.
const char *FileToken::KindName(void) const noexcept {
  if (impl) {
    return clang::tok::getTokenName(static_cast<clang::tok::TokenKind>(impl->kind));
  } else {
    return clang::tok::getTokenName(clang::tok::unknown);
  }
}

// Return the line number associated with this token.
unsigned FileToken::Line(void) const noexcept {
  return impl ? impl->line : 0u;
}

// Return the column number associated with this token.
unsigned FileToken::Column(void) const noexcept {
  return impl ? impl->column : 0u;
}

// Return the data associated with this token.
std::string_view FileToken::Data(void) const noexcept {
  if (impl) {
    const FileTokenImpl *next_impl = &(impl[1]);
    return std::string_view(
        impl->data, static_cast<size_t>(next_impl->data - impl->data));
  } else {
    return {};
  }
}

// Index of this token within its file.
//
// NOTE(pag): In theory it should be safe to access `file->tokens` without
//            acquiring `file->tokens_lock` as we must have already gotten
//            the tokens to have this token.
uint64_t FileToken::Index(void) const noexcept {
  if (impl) {
    return static_cast<size_t>(impl - file->tokens.data());
  } else {
    return std::numeric_limits<uint64_t>::max();
  }
}

// Prefix increment operator.
FileTokenIterator &FileTokenIterator::operator++(void) noexcept {
  ++token.impl;
  return *this;
}

// Postfix increment operator.
FileTokenIterator FileTokenIterator::operator++(int) noexcept {
  auto ret = *this;
  ++token.impl;
  return ret;
}

// Prefix decrement operator.
FileTokenIterator &FileTokenIterator::operator--(void) noexcept {
  --token.impl;
  return *this;
}

// Postfix decrement operator.
FileTokenIterator FileTokenIterator::operator--(int) noexcept {
  auto ret = *this;
  --token.impl;
  return ret;
}

FileTokenIterator FileTokenIterator::operator-(size_t offset) const noexcept {
  return FileTokenIterator(token.file, token.impl - offset);
}

FileTokenIterator& FileTokenIterator::operator+=(size_t offset) noexcept {
  token.impl += offset;
  return *this;
}

FileTokenIterator &FileTokenIterator::operator-=(size_t offset) noexcept {
  token.impl -= offset;
  return *this;
}

FileToken FileTokenIterator::operator[](size_t offset) const noexcept {
  return FileToken(token.file, &(token.impl[offset]));
}

ptrdiff_t FileTokenIterator::operator-(
    const FileTokenIterator &that) const noexcept {
  return token.impl - token.impl;
}

// Number of tokens in this range.
size_t FileTokenRange::Size(void) const noexcept {
  return static_cast<size_t>(after_last - first);
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<FileToken> FileTokenRange::At(size_t index) const noexcept {
  auto size = static_cast<size_t>(after_last - first);
  if (index < size) {
    return FileToken(file, &(first[index]));
  } else {
    return std::nullopt;
  }
}

// Unsafe indexed access into the token range.
FileToken FileTokenRange::operator[](size_t index) const {
  return FileToken(file, &(first[index]));
}

}  // namespace pasta
