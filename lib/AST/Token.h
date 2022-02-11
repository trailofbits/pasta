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
#include <clang/AST/Decl.h>
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
class PrintedTokenImpl;
class PrintedTokenRangeImpl;

using OpaqueSourceLoc = uint32_t;
using TokenContextIndex = uint32_t;
static constexpr TokenContextIndex kInvalidTokenContextIndex = ~0u;

inline static const clang::Decl *Canonicalize(const clang::Decl *decl) {
  return decl->getCanonicalDecl();
}

template <typename T>
inline static const T *Canonicalize(const T *other) {
  return other;
}

// Backing data for a token context.
class TokenContextImpl {
 public:
  const void *data;
  TokenContextIndex parent_index;
  uint16_t depth;
  TokenContextKind kind;

  // Return the common ancestor between two contexts. This focuses on the data
  // itself, so if there are two distinct contexts sharing the same data, or
  // aliasing the same data, the context associated with the second token is
  // returned.
  static const TokenContextImpl *CommonAncestor(
      const TokenContextImpl *a, const TokenContextImpl *b,
      const std::vector<TokenContextImpl> &contexts);

  // Return the common ancestor between two tokens. This focuses on the data
  // itself, so if there are two distinct contexts sharing the same data, or
  // aliasing the same data, the context associated with the second token is
  // returned.
  static const TokenContextImpl *CommonAncestor(
      TokenImpl *a, TokenImpl *b,
      const std::vector<TokenContextImpl> &contexts);

  const TokenContextImpl *Parent(
      const std::vector<TokenContextImpl> &contexts) const;

  const TokenContextImpl *Aliasee(
      const std::vector<TokenContextImpl> &contexts) const;

  const char *KindName(
      const std::vector<TokenContextImpl> &contexts) const;

  inline TokenContextImpl(const void *data_,
                          TokenContextIndex parent_index_,
                          unsigned parent_depth,
                          TokenContextKind kind_)
      : data(data_),
        parent_index(parent_index_),
        depth(static_cast<uint16_t>(parent_depth)),
        kind(kind_) {}

#define PASTA_DEFINE_TOKEN_CONTEXT_CONSTRUCTOR(cls) \
    inline TokenContextImpl(TokenContextIndex parent_index_, \
                            uint16_t parent_depth, \
                            const clang::cls *data_) \
        : TokenContextImpl(Canonicalize(data_), parent_index_, \
                           parent_depth + 1u, TokenContextKind::k ## cls) {}
  PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_DEFINE_TOKEN_CONTEXT_CONSTRUCTOR)
#undef PASTA_DEFINE_TOKEN_CONTEXT_CONSTRUCTOR

  inline TokenContextImpl(TokenContextIndex parent_index_,
                          uint16_t parent_depth,
                          const char *data_)
      : TokenContextImpl(data_, parent_index_,
                         parent_depth + 1u, TokenContextKind::kString) {}

  inline TokenContextImpl(TokenContextIndex parent_index_,
                          uint16_t parent_depth,
                          TokenContextIndex aliasee_)
      : TokenContextImpl(reinterpret_cast<const void *>(aliasee_),
                         parent_index_, parent_depth + 1u,
                         TokenContextKind::kAlias) {}

  // Special context that we place at the end of a vector.
  inline TokenContextImpl(ASTImpl &ast)
      : TokenContextImpl(reinterpret_cast<const void *>(&ast),
                         kInvalidTokenContextIndex,
                         std::numeric_limits<uint16_t>::max(),
                         TokenContextKind::kInvalid) {}
};

using TokenKindBase = std::underlying_type_t<clang::tok::TokenKind>;

// Backing implementation of a token.
class TokenImpl {
 public:
  static constexpr OpaqueSourceLoc kInvalidSourceLocation = 0u;

  static constexpr uint32_t kTokenSizeMask = ((1u << 20) - 1u);

  inline TokenImpl(OpaqueSourceLoc opaque_source_loc_, int32_t data_offset_,
                   uint32_t data_len_, clang::tok::TokenKind kind_,
                   TokenRole role_, TokenContextIndex token_context_index_=kInvalidTokenContextIndex)
      : opaque_source_loc(opaque_source_loc_),
        context_index(token_context_index_),
        data_offset(data_offset_),
        data_len(static_cast<uint32_t>(data_len_ & kTokenSizeMask)),
        kind(static_cast<TokenKindBase>(kind_)),
        role(static_cast<TokenKindBase>(role_)) {}

  // Return the source location of this token.
  inline clang::SourceLocation Location(void) const {
    return clang::SourceLocation::getFromRawEncoding(opaque_source_loc);
  }

  std::string_view Data(const ASTImpl &ast) const noexcept;
  std::string_view Data(const PrintedTokenRangeImpl &range) const noexcept;

  inline TokenRole Role(void) const noexcept {
    return static_cast<TokenRole>(role);
  }

  inline clang::tok::TokenKind Kind(void) const noexcept {
    return static_cast<clang::tok::TokenKind>(kind);
  }

  // The raw encoding of the source location of the token.
  OpaqueSourceLoc opaque_source_loc{kInvalidSourceLocation};

  // Index of the token context in either `ASTImpl::contexts` or
  // `PrintedTokenRangeImpl::contexts`.
  TokenContextIndex context_index{kInvalidTokenContextIndex};

  // Offset and length of this token's data. If `data_offset` is positive, then
  // the data is located in `ast->preprocessed_code`, otherwise it's located in
  // `ast->backup_code`.
  int32_t data_offset{0u};

  // The Linux kernel has some *massive* comments, e.g. comments in
  // `tools/include/uapi/linux/bpf.h`.
  uint32_t data_len:20;

  // The original token kind.
  TokenKindBase kind:9;
  TokenKindBase role:7;
} __attribute__((packed));

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
