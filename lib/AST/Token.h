/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/Token.h>

#include <cstdint>
#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/TokenKinds.h>
#pragma clang diagnostic pop

namespace clang {
class ASTContext;
class SourceManager;
class LangOptions;
class Token;
} // namespace clang

namespace pasta {

class ASTImpl;
class Token;
class PrintedTokenRangeImpl;

// Backing implementation of a token.
class TokenImpl {
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

  std::string_view Data(const ASTImpl &ast) const noexcept;
  std::string_view Data(const PrintedTokenRangeImpl &range) const noexcept;

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
                     const clang::LangOptions &lang_opts,
                     const clang::Token &tok, std::string *out);

// Try to lex the data at `loc` into the token `*out`.
bool TryLexRawToken(clang::SourceManager &source_manager,
                    const clang::LangOptions &lang_opts,
                    clang::SourceLocation loc, clang::Token *out);

// Try to lex the data at `loc` into the token `*out`.
bool TryLexRawToken(clang::ASTContext &ast_context,
                    clang::SourceLocation loc, clang::Token *out);

} // namespace pasta
