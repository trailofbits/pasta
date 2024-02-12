/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Forward.h>

#include <cstdint>
#include <deque>
#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Decl.h>
#include <clang/AST/Expr.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/TokenKinds.h>
#pragma GCC diagnostic pop

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

using OpaqueSourceLoc = clang::SourceLocation::UIntTy;
using TokenContextIndex = uint32_t;
using DerivedTokenIndex = uint32_t;
using TokenDataOffset = int32_t;
using TokenDataIndex = uint32_t;
static constexpr DerivedTokenIndex kInvalidDerivedTokenIndex = ~0u;
static constexpr TokenContextIndex kInvalidTokenContextIndex = ~0u;
static constexpr TokenContextIndex kASTTokenContextIndex = 0u;
static constexpr TokenContextIndex kTranslationUnitTokenContextIndex = 1u;

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
  const void *data{nullptr};
  TokenContextIndex parent_index{kInvalidTokenContextIndex};
  uint16_t depth{0};
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
      PrintedTokenImpl *a, PrintedTokenImpl *b,
      const std::vector<TokenContextImpl> &contexts);

  const TokenContextImpl *Parent(
      const std::vector<TokenContextImpl> &contexts) const;

  const TokenContextImpl *Aliasee(
      const std::vector<TokenContextImpl> &contexts) const;

  const char *KindName(
      const std::vector<TokenContextImpl> &contexts) const;

  inline TokenContextImpl(const void *data_, TokenContextIndex parent_index_,
                          unsigned depth_, TokenContextKind kind_)
      : data(data_),
        parent_index(parent_index_),
        depth(static_cast<uint16_t>(depth_)),
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

  inline TokenContextImpl(TokenContextIndex parent_index_,
                          uint16_t parent_depth,
                          const clang::DesignatedInitExpr::Designator *data_)
      : TokenContextImpl(Canonicalize(data_), parent_index_,
                         parent_depth + 1u, TokenContextKind::kDesignator) {}

  // Special context that we place at the end of a vector.
  inline TokenContextImpl(ASTImpl &ast)
      : TokenContextImpl(reinterpret_cast<const void *>(&ast),
                         kInvalidTokenContextIndex,
                         0u,
                         TokenContextKind::kAST) {}
};

using TokenKindBase = std::underlying_type_t<clang::tok::TokenKind>;

// Backing implementation of a token.
class TokenImpl {
 public:
  static constexpr OpaqueSourceLoc kInvalidSourceLocation = 0u;

  static constexpr uint32_t kTokenSizeMask = ((1u << 20) - 1u);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
  inline TokenImpl(
      OpaqueSourceLoc opaque_source_loc_, int32_t data_offset_,
      uint32_t data_len_, clang::tok::TokenKind kind_, TokenRole role_,
      TokenContextIndex token_context_index_=kInvalidTokenContextIndex)
      : opaque_source_loc(opaque_source_loc_),
        context_index(token_context_index_),
        data_offset(data_offset_),
        data_len(static_cast<uint32_t>(data_len_ & kTokenSizeMask)),
        kind(static_cast<TokenKindBase>(kind_)),
        role(static_cast<TokenKindBase>(role_)),
        is_macro_name(0),
        is_in_pragma_directive(0) {}
#pragma GCC diagnostic pop

  // Return the source location of this token.
  inline clang::SourceLocation Location(void) const {
    return clang::SourceLocation::getFromRawEncoding(opaque_source_loc);
  }

  std::string_view Data(const ASTImpl &ast) const noexcept;
  std::string_view Data(const PrintedTokenRangeImpl &range) const noexcept;

  inline TokenRole Role(void) const noexcept {
    return static_cast<TokenRole>(role);
  }

  inline bool IsParsed(void) const noexcept {
    switch (Role()) {
      case TokenRole::kInvalid:
      case TokenRole::kBeginOfFileMarker:
      case TokenRole::kEndOfFileMarker:
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
      case TokenRole::kEndOfInternalMacroEventMarker:
        return false;

      case TokenRole::kFinalMacroExpansionToken:
      case TokenRole::kFileToken:
        // Clang supports the following:
        //
        //    #pragma attribute push(__attribute__((....)), apply_to = (...))
        //    ...
        //
        // In this case, we don't want to let the locations of any of these
        // attributes influence the locations of the declarations enclosed by
        // this pragma.
        //
        // Although pragmas are indeed parsed, we "hide" their tokens from the
        // ASTs via some the `PatchedMacroTracker`: when a pragma directive is
        // finished, we inject a zero-length marker token, and also render the
        // full, macro-expanded directive into `ASTImpl::preprocessed_code`.
        // These pragmas are visible to Clang's Sema, but not to our parsed
        // token list.
        return !is_in_pragma_directive && data_len;
    }
  }

  inline bool HasMacroRole(void) const noexcept {
    switch (Role()) {
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
      case TokenRole::kFinalMacroExpansionToken:
      case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kEndOfInternalMacroEventMarker:
        return true;
      default:
        return false;
    }
  }

  inline clang::tok::TokenKind Kind(void) const noexcept {
    return static_cast<clang::tok::TokenKind>(kind);
  }

  // Return the context of this token, or `nullptr`.
  const TokenContextImpl *Context(
      const ASTImpl &ast,
      const std::vector<TokenContextImpl> &contexts) const noexcept;

  // If this number is positive, then it is the raw encoding of the source
  // location of the token, which references a `FileToken`. If this number is
  // negative, then this token was derived from a prior token in a macro
  // expansion. That prior token is at `ast->tokens[derived_index]`. This
  // process is enacted by `PatchedMacroTracker::FixupDerivedLocations`. If the
  // index points to itself, then it's a macro token that makes it into the
  // final parse (and is thus relevant to token alignment), but that also
  // doesn't have any associated source location, e.g. how `__FILE__` expands to
  // a provenanceless string.
  //
  // NOTE(pag): These locations DO NOT point into `ASTImpl::preprocessed_code`.
  //            These are the *original* source locations, as produced by Clang
  //            when we ran the preprocessor in `PreprocessCode` from `Run.cpp`.
  OpaqueSourceLoc opaque_source_loc{kInvalidSourceLocation};

  DerivedTokenIndex derived_index{kInvalidDerivedTokenIndex};

  // If this is a `PrintedTokenImpl` in a `PrintedTokenRangeImpl`, then this
  // represents the index of the token context in
  // `PrintedTokenRangeImpl::contexts`.
  //
  // If this is a `TokenImpl` in a `ASTImpl`, then this represents the index of
  // a `MacroTokenImpl` in `ASTImpl::root_macro_node.token_nodes`.
  //
  // TODO(pag): Split `PrintedTokenImpl` off into its own thing.
  TokenContextIndex context_index{kInvalidTokenContextIndex};

  // Offset and length of this token's data. If `data_offset` is positive, then
  // the data is located in `ast->preprocessed_code`, otherwise it's located in
  // `ast->backup_code`.
  TokenDataOffset data_offset{0u};

  // The Linux kernel has some *massive* comments, e.g. comments in
  // `tools/include/uapi/linux/bpf.h`.
  uint32_t data_len;

  // The original token kind.
  TokenKindBase kind;

  // The role of this token, e.g. parsed, printed, macro expansion, etc.
  TokenKindBase role:4;

  // Is this token associated with a macro definition? If so, then we have a
  // lookup mechanism in `ASTImpl` to go from the token index to the macro
  // definition.
  TokenKindBase is_macro_name:1;

  // Is this token part of a `#pragma` macro directive region?
  //
  // Clang supports the following:
  //
  //    #pragma attribute push(__attribute__((....)), apply_to = (...))
  //    ...
  //
  // In this case, we don't want to let the locations of any of these
  // attributes influence the locations of the declarations enclosed by
  // this `#pragma`.
  TokenKindBase is_in_pragma_directive:1;
};

void SkipTrailingWhitespace(std::string &tok_data);
void SkipLeadingWhitspace(std::string &tok_data);

// Strip off leading whitespace from a token that has been read.
void SkipLeadingWhitspace(clang::Token &tok, clang::SourceLocation &tok_loc,
                          std::string &tok_data);

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

// Recursively migrate token contexts.
TokenContextIndex MigrateContexts(
    TokenContextIndex id,
    const std::vector<TokenContextImpl> &from_contexts,
    std::vector<TokenContextImpl> &to_contexts,
    std::unordered_multimap<const void *, TokenContextIndex> &data_to_context,
    std::vector<TokenContextIndex> &context_map);


class ParsedTokenStorage {
 private:
  // This is the data that will get parsed by Clang. It includes all tokens that
  // make it through the lexing process.
  std::string data;

  // Ending position of a token.
  std::vector<unsigned> token_offset;

  std::vector<TokenRole> role;

  std::vector<TokenKind> kind;

  // Is this token associated with a macro definition? If so, then we have a
  // lookup mechanism in `ASTImpl` to go from the token index to the macro
  // definition.
  std::vector<bool> is_macro_name;

  // Is this token part of a `#pragma` macro directive region?
  //
  // Clang supports the following:
  //
  //    #pragma attribute push(__attribute__((....)), apply_to = (...))
  //    ...
  //
  // In this case, we don't want to let the locations of any of these
  // attributes influence the locations of the declarations enclosed by
  // this `#pragma`.
  std::vector<bool> is_in_pragma_directive;

 public:
  inline ParsedTokenStorage(void) {
    data.reserve(4096u * 16u);
    data.push_back('\0');
    data.pop_back();
    token_offset.reserve(4096u);
    role.reserve(4096u);
    kind.reserve(4096u);
    is_macro_name.reserve(4096u);
    is_in_pragma_directive.reserve(4096u);
    token_offset.push_back(0u);
  }

  inline std::string_view Data(unsigned offset) const {
    auto begin_offset = token_offset[offset];
    auto end_offset = token_offset[offset + 1u];
    auto raw_data = data.data();
    return std::string_view(&(raw_data[begin_offset]),
                            &(raw_data[end_offset]));
  }

  inline TokenKind Kind(unsigned offset) const {
    return kind[offset];
  }

  inline TokenKind Role(unsigned offset) const {
    return role[offset];
  }

  inline bool IsInPragmaDirective(unsigned offset) const {
    return is_in_pragma_directive[offset];
  }

  // Finish off a token.
  inline void FinishToken(void) {
    token_offset.emplace_back(static_cast<unsigned>(data.size()));
  }
};

class MacroTokenStorage : public ParsedTokenStorage {
 private:
  // Is this token associated with a macro definition? If so, then we have a
  // lookup mechanism in `ASTImpl` to go from the token index to the macro
  // definition.
  std::vector<bool> is_macro_name;

 public:
  inline MacroTokenStorage(void) {
    is_macro_name.reserve(4096u);
  }

  inline bool IsMacroName(unsigned offset) const {
    return is_macro_name[offset];
  }
};

} // namespace pasta
