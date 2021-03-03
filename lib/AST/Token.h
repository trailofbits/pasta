/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/Token.h>

#include <cstdint>
#include <string>
#include <string_view>

namespace clang {
class SourceManager;
class LangOptions;
class Token;
} // namespace clang

namespace pasta {

class Token;
class ASTImpl;

// Backing implementation of a token.
struct TokenImpl {
 public:
  inline TokenImpl(uint32_t opaque_source_loc_, int32_t data_offset_,
                   uint16_t data_len_, clang::tok::TokenKind kind_)
      : opaque_source_loc(opaque_source_loc_),
        data_offset(data_offset_),
        data_len(data_len_),
        kind(kind_) {}

  // Return the source location of this token.
  inline clang::SourceLocation Location(void) const {
    return clang::SourceLocation::getFromRawEncoding(opaque_source_loc);
  }

  // The raw encoding of the source location of the token.
  uint32_t opaque_source_loc;

  // Offset and length of this token's data. If `data_offset` is positive, then
  // the data is located in `ast->preprocessed_code`, otherwise it's located in
  // `ast->backup_code`.
  int32_t data_offset;
  uint16_t data_len;

  // The original token kind.
  clang::tok::TokenKind kind;
};

// Read the data of the token into the passed in string pointer
bool TryReadRawToken(clang::SourceManager &source_manager,
                     clang::LangOptions &lang_opts,
                     const clang::Token &tok, std::string *out);

} // namespace pasta
