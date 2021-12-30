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

using TokenContextIndex = uint32_t;
static constexpr TokenContextIndex kInvalidTokenContextIndex = ~0u;

// Backing data for a token context.
class TokenContextImpl {
 public:
  const void * const data;
  const TokenContextIndex parent_index;
  const TokenContextKind kind;

#define PASTA_DEFINE_TOKEN_CONTEXT_CONSTRUCTOR(cls) \
    inline TokenContextImpl(uint32_t parent_index_, const clang::cls *data_) \
        : data(data_), \
          parent_index(parent_index_), \
          kind(TokenContextKind::k ## cls) {}
  PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_DEFINE_TOKEN_CONTEXT_CONSTRUCTOR)
#undef PASTA_DEFINE_TOKEN_CONTEXT_CONSTRUCTOR

  inline TokenContextImpl(uint32_t parent_index_, const char *data_)
      : data(data_),
        parent_index(parent_index_),
        kind(TokenContextKind::kString) {}
};

// Backing implementation of a token.
class TokenImpl {
 public:
  static constexpr uint32_t kInvalidSourceLocation = 0u;

  inline TokenImpl(uint32_t opaque_source_loc_, int32_t data_offset_,
                   uint16_t data_len_, clang::tok::TokenKind kind_,
                   uint32_t token_context_index_=kInvalidTokenContextIndex)
      : opaque_source_loc(opaque_source_loc_),
        context_index(token_context_index_),
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
  uint32_t opaque_source_loc{kInvalidSourceLocation};

  // Index of the token context in either `ASTImpl::contexts` or
  // `PrintedTokenRangeImpl::contexts`.
  TokenContextIndex context_index{kInvalidTokenContextIndex};

  // Offset and length of this token's data. If `data_offset` is positive, then
  // the data is located in `ast->preprocessed_code`, otherwise it's located in
  // `ast->backup_code`.
  int32_t data_offset{0u};
  uint16_t data_len{0u};

  // The original token kind.
  clang::tok::TokenKind kind{clang::tok::unknown};
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
