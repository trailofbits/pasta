/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <pasta/Util/File.h>

#include <algorithm>
#include <pasta/AST/Forward.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wfloat-conversion"
#include <clang/Lex/HeaderMapTypes.h>
#include <llvm/Support/JSON.h>
#pragma clang diagnostic pop

#include <llvm/Support/xxhash.h>

#include "FileManager.h"

namespace pasta {
namespace {

static const std::string_view kPPKeywordSpelling[] = {
#define PPKEYWORD(X) #X,
#include "clang/Basic/TokenKinds.def"
};


static const std::string_view kObjCKeywordSpelling[] = {
#define OBJC_AT_KEYWORD(X) #X,
#include "clang/Basic/TokenKinds.def"
};

// Strip Byte Offset Marker character from the string if it exists.
static inline void RemoveBOM(std::string &value) {
  if (HasBOM(value.c_str(), value.size())) {
    value.erase(0, 3);
  }
}

// Strip carriage returns from the string.
static inline void RemoveCarriageReturns(std::string &value) {
  auto it = std::remove(value.begin(), value.end(), '\r');
  value.erase(it, value.end());
}

static bool IsPowerOfTwo(uint32_t x) {
    return (x & (x - 1u)) == 0u;
}

static bool IsHeaderMapHeader(const clang::HMapHeader &header,
                              const std::string &data) {
  if (header.Reserved != 0u) {
    return false;
  }

  if (!IsPowerOfTwo(header.NumBuckets)) {
    return false;
  }

  auto needed_size = sizeof(clang::HMapHeader) +
                     sizeof(clang::HMapBucket) * header.NumBuckets;

  return data.size() >= needed_size;
}

} // namespace

// Check if string has Byte-offset marker
bool HasBOM(const char *value, size_t size) {
  if (3 > size) {
    return false;
  }

  return ((value[0] & 0xff) == 0xef) &&
         ((value[1] & 0xff) == 0xbb) &&
         ((value[2] & 0xff) == 0xbf);
}

// Sanitize a string for PASTA's use. A lot of code in PASTA relies on the file
// being formatted as UTF-8.
void SanitizeString(std::string &data) {
  if (!llvm::json::isUTF8(data)) {
    llvm::json::fixUTF8(data).swap(data);
  }
  RemoveBOM(data);
  RemoveCarriageReturns(data);
}

// Check if this looks like a headermap file. If so, don't convert to UTF-8.
bool IsHeaderMap(const std::string &data) {
  if (data.size() <= sizeof(clang::HMapHeader)) {
    return false;
  }

  clang::HMapHeader header = {};
  memcpy(&header, data.data(), sizeof(header));

  // Sniff it to see if it's a headermap by checking the magic number and
  // version.
  if (header.Magic == clang::HMAP_HeaderMagicNumber &&
      header.Version == clang::HMAP_HeaderVersion) {
    return IsHeaderMapHeader(header, data);
  }

  header.Magic = __builtin_bswap32(header.Magic);
  header.Version = __builtin_bswap16(header.Version);

  if (header.Magic == clang::HMAP_HeaderMagicNumber &&
      header.Version == clang::HMAP_HeaderVersion) {

    header.Reserved = __builtin_bswap16(header.Reserved);
    header.StringsOffset = __builtin_bswap32(header.StringsOffset);
    header.NumEntries = __builtin_bswap32(header.NumEntries);
    header.NumBuckets = __builtin_bswap32(header.NumBuckets);
    header.MaxValueLength = __builtin_bswap32(header.MaxValueLength);
    return IsHeaderMapHeader(header, data);
  }

  return false;
}

FileImpl::FileImpl(const std::shared_ptr<FileManagerImpl> &owner_, Stat stat_)
    : owner(owner_),
      stat(std::move(stat_)) {}

FileToken::~FileToken(void) {}

File::~File(void) {}

// Return the file containing a given file token.
File File::Containing(const FileToken &tok) {
  return File(tok.file);
}

// Return the file containing a given file token.
std::optional<File> File::Containing(const std::optional<FileToken> &tok) {
  if (!tok) {
    return std::nullopt;
  } else {
    return File(tok->file);
  }
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
      assert(!impl->data.empty());
      assert(impl->data.back() == '\0');
      return std::string_view(impl->data.data(), impl->data.size() - 1u);
    }
  }

  impl->has_data = true;

  auto fm = impl->owner.lock();
  auto maybe_file = fm->file_system->ReadFile(impl->stat);
  if (!maybe_file.Succeeded()) {
    impl->data_ec = maybe_file.TakeError();
    return impl->data_ec;
  }
  maybe_file.TakeValue().swap(impl->data);

  if (!IsHeaderMap(impl->data)) {
    SanitizeString(impl->data);
  }

  // NOTE(pag): We use this extra trailing NUL to help us with location
  //            offsets for EOF tokens.
  //
  // NOTE(pag): Header map buffers also need to be NUL-terminated.
  impl->data.push_back('\0');

  // NOTE(pag): We use the data hash to help us maintain semi-determinstic
  //            `__COUNTER__` values across files.
  impl->data_hash = llvm::xxHash64(impl->data);

  return std::string_view(impl->data.data(), impl->data.size() - 1u);
}

// Return a hash of the data.
std::optional<uint64_t> File::DataHash(void) const noexcept {
  std::unique_lock<std::mutex> locker(impl->data_lock);
  if (impl->data_ec) {
    return std::nullopt;
  } else {
    return impl->data_hash;
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
  const auto num_toks = impl->tokens.size();
  if (1u >= num_toks) {
    return FileTokenRange(impl);

  // NOTE(pag): The last token in the range exists to provide the ending
  //            pointer for the data of the "true" last token.
  } else {
    auto first = impl->tokens.data();
    auto last = &(first[num_toks - 1u]);
    assert(last->kind.extended.kind == static_cast<uint16_t>(clang::tok::eof));
    return FileTokenRange(impl, first, &(last[1]));
  }
}

// Return the Nth token.
std::optional<FileToken> File::TokenAtIndex(size_t n) const noexcept {
  std::unique_lock<std::mutex> locker(impl->tokens_lock);
  const auto num_toks = impl->tokens.size();
  if (n >= num_toks) {
    return std::nullopt;
  }

  return FileToken(impl, &(impl->tokens[n]));
}

// Return a token at a specific file offset.
std::optional<FileToken> File::TokenAtOffset(size_t offset) const noexcept {

  FileTokenImpl fake_tok(static_cast<unsigned>(offset), 0, 0, 0,
                         clang::tok::unknown);

  {
    std::unique_lock<std::mutex> locker(impl->tokens_lock);
    auto tokens = impl->tokens.data();
    auto end_tokens = &(tokens[impl->tokens.size()]);
    auto ret = std::lower_bound(
        tokens, end_tokens, fake_tok,
        [] (const FileTokenImpl &a, const FileTokenImpl &b) {
          return a.data_offset < b.data_offset;
        });

    if (tokens <= ret && ret < end_tokens) {
      assert(offset == ret->data_offset);
      return FileToken(impl, ret);
    }
  }

  return std::nullopt;
}

TokenKind FileToken::Kind(void) const noexcept {
  if (impl) {
    return static_cast<TokenKind>(impl->Kind());
  } else {
    return TokenKind::kUnknown;
  }
}

PPKeywordKind FileToken::PreProcessorKeywordKind(void) const noexcept {
  if (impl) {
    if (impl->kind.extended.is_pp_kw) {
      return static_cast<PPKeywordKind>(
          impl->kind.extended.alt_kind);
    } else {
      return PPKeywordKind::kNotKeyword;
    }
  } else {
    return PPKeywordKind::kNotKeyword;
  }
}

ObjCKeywordKind FileToken::ObjectiveCAtKeywordKind(void) const noexcept {
  if (impl) {
    if (impl->kind.extended.is_objc_kw) {
      return static_cast<ObjCKeywordKind>(
          impl->kind.extended.alt_kind);
    } else {
      return ObjCKeywordKind::kNotKeyword;
    }
  } else {
    return ObjCKeywordKind::kNotKeyword;
  }
}

// Kind of this token.
const char *FileToken::KindName(void) const noexcept {
  if (impl) {
    return clang::tok::getTokenName(
        static_cast<clang::tok::TokenKind>(impl->kind.extended.kind));
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
    if (impl->kind.extended.is_pp_kw) {
      return kPPKeywordSpelling[impl->kind.extended.alt_kind];

    } else if (impl->kind.extended.is_objc_kw) {
      return kObjCKeywordSpelling[impl->kind.extended.alt_kind];

    } else if (impl->data_len) {
      return std::string_view(file->data).substr(
          impl->data_offset, impl->data_len);

    } else {
      return {};
    }
  } else {
    return {};
  }
}

// The offset in the file of this token's data.
unsigned FileToken::Offset(void) const noexcept {
  return impl->data_offset;
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

bool IsIdentifierTokenKind(TokenKind kind) noexcept {
  return clang::tok::isAnyIdentifier(static_cast<clang::tok::TokenKind>(kind));
}

const char *KeywordSpellingOrNull(TokenKind kind) noexcept {
  return clang::tok::getKeywordSpelling(
      static_cast<clang::tok::TokenKind>(kind));
}

}  // namespace pasta
