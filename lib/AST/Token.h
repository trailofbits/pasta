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
#include <tuple>
#include <variant>
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
class PrintedTokenRange;
class PrintedTokenRangeImpl;

using OpaqueSourceLoc = clang::SourceLocation::UIntTy;
using SignedOpaqueSourceLoc = clang::SourceLocation::IntTy;
using TokenContextIndex = uint32_t;
using DerivedTokenIndex = uint32_t;
using TokenDataOffset = int32_t;
using TokenDataIndex = uint32_t;
static constexpr DerivedTokenIndex kInvalidDerivedTokenIndex = ~0u;
static constexpr TokenContextIndex kInvalidTokenContextIndex = ~0u;
static constexpr TokenContextIndex kASTTokenContextIndex = 0u;
static constexpr TokenContextIndex kTranslationUnitTokenContextIndex = 1u;

class MacroNodeImpl;
class MacroTokenImpl;
using Node = std::variant<std::monostate, MacroNodeImpl *, MacroTokenImpl *>;
using NodeList = std::vector<Node>;

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
      // case TokenRole::kBeginOfMacroExpansionMarker:
      // case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
      case TokenRole::kEmptyOrSpecialMacroToken:
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
      // case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
      case TokenRole::kFinalMacroExpansionToken:
      // case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kEmptyOrSpecialMacroToken:
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
void SkipLeadingWhitespace(std::string &tok_data);

// Strip off leading whitespace from a token that has been read.
void SkipLeadingWhitespace(clang::Token &tok, clang::SourceLocation &tok_loc,
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

class MacroTokenStorage;

using BitPackedLocation = uint64_t;
static constexpr BitPackedLocation kInvalidBitPackedLocation = 0u;

class ParsedTokenStorage {
 protected:
  friend class AST;
  friend class ASTImpl;
  friend class PrintedTokenRange;
  friend class PrintedTokenRangeImpl;
  friend class Token;
  friend class TokenRange;

  ASTImpl * const ast;

  // This is the data that will get parsed by Clang. It includes all tokens that
  // make it through the lexing process.
  std::string data;

  // Bit-packed representation. This takes on a few forms:
  //
  //    - `0` is an invalid location.
  //
  //    - `(file_index + 1u, token_index + 1)` where the token can be found at
  //      `ast->parsed_files[file_index][token_index]`.
  //
  //    - `(macro_token_index + 1u, 0u)`, where the token can be found at
  //      offset `macro_token_index - 1u` in `ast->macro_tokens`.
  //      
  //    - `(~0u, raw_source_location)`, where this is a transitory
  //      representation of a macro token's location prior to finishing a
  //      complete macro expansion.
  std::vector<BitPackedLocation> location;

  // Ending position of a token.
  std::vector<unsigned> data_offset;

  // Kind of the `Nth` token.
  std::vector<TokenKind> kind;

  // Role of the `Nth` token.
  std::vector<TokenRole> role;

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

  BitPackedLocation CreateFileLocation(clang::SourceLocation loc);
  BitPackedLocation CreateInitialMacroLocation(clang::SourceLocation loc);
  BitPackedLocation CreateMacroLocation(DerivedTokenIndex offset);

 private:
  // Initialize this storage as an "invalid" storage.
  void InitInvalid(void);

 public:
  virtual ~ParsedTokenStorage(void);

  inline ParsedTokenStorage(ASTImpl *ast_)
      : ast(ast_) {
    data.reserve(4096u * 16u);
    data.push_back('\0');
    data.pop_back();
    location.reserve(4096u);
    data_offset.reserve(4096u);
    role.reserve(4096u);
    kind.reserve(4096u);
    is_in_pragma_directive.reserve(4096u);
    data_offset.push_back(0u);
  }

  std::string_view Data(void) const {
    std::string_view d(data);
    while (!d.empty() && d.back() == '\0') {
      d.remove_suffix(1u);
    }
    return d;
  }

  std::string_view Data(DerivedTokenIndex offset) const;

  inline TokenKind Kind(DerivedTokenIndex offset) const {
    return kind[offset];
  }

  inline TokenRole Role(DerivedTokenIndex offset) const {
    return role[offset];
  }

  inline void MarkTokenAsInPragmaDirective(DerivedTokenIndex offset) {
    is_in_pragma_directive[offset] = true;
  } 

  inline bool IsInPragmaDirective(DerivedTokenIndex offset) const {
    return is_in_pragma_directive[offset];
  }

  // bool IsBeginOfMacroExpansion(
  //     const MacroTokenStorage &macro_tokens, unsigned offset) const;

  // bool IsEndOfMacroExpansion(
  //     const MacroTokenStorage &macro_tokens, unsigned offset) const;

  // Finish off a token.
  inline void FinishToken(void) {
    data_offset.emplace_back(static_cast<DerivedTokenIndex>(data.size()));
  }

  inline DerivedTokenIndex size(void) const {
    return static_cast<DerivedTokenIndex>(role.size());
  }

  inline void SetKind(DerivedTokenIndex offset, TokenKind kind_) {
    kind[offset] = kind_;
  }

  std::optional<DerivedTokenIndex> DataOffsetToTokenIndex(unsigned offset);

  void AppendFileToken(std::string_view data, const clang::Token &tok);
  void AppendMacroToken(MacroTokenStorage &tokens, const clang::Token &tok);
  void AppendInternalToken(std::string_view data, clang::SourceLocation loc);

  // Append a marker token to the parsed token list.
  void AppendMarkerToken(clang::SourceLocation loc, TokenRole role);

  void Finalize(void);
};

class MacroTokenStorage : public ParsedTokenStorage {
 private:
  friend class ASTImpl;
  friend class MacroToken;
  friend class ParsedTokenStorage;
  friend class Token;

  // Does this token represent the start or end of a macro expansion?
  std::vector<bool> is_start_of_macro_expansion;
  std::vector<bool> is_end_of_macro_expansion;
  
  // Offset in `ASTImpl::root_macro_node.tokens` where this token is located.
  std::vector<DerivedTokenIndex> macro_token_offset;

  // State used during the lexing phase to keep track of whether or not we're
  // inside of an expansion.
  bool next_is_begin_expansion{false};
  std::optional<DerivedTokenIndex> last_expansion_begin_offset;

  // If a token is associated with a macro, then we can find that associated
  // macro node here.
  std::unordered_map<DerivedTokenIndex, Node> macro_definition;

  // Find the parsed representation of a token.
  std::unordered_map<DerivedTokenIndex, DerivedTokenIndex> parsed_token_offset;

  // State used when fixing up token provenance.
  using TokenProvenanceMap = std::unordered_map<OpaqueSourceLoc,
                                                BitPackedLocation>;

  TokenProvenanceMap file_token_refs;
  TokenProvenanceMap macro_token_refs;

  // Hidden methods.
  using ParsedTokenStorage::AppendFileToken;
  using ParsedTokenStorage::AppendMacroToken;
  using ParsedTokenStorage::Finalize;

  void FixupTokenProvenance(
      DerivedTokenIndex tok_index, DerivedTokenIndex min_derived_index,
      bool can_be_derived, int depth, clang::SourceLocation loc);

 public:
  inline MacroTokenStorage(ASTImpl *ast_)
      : ParsedTokenStorage(ast_) {
    is_start_of_macro_expansion.reserve(4096u);
    is_end_of_macro_expansion.reserve(4096u);
    macro_token_offset.reserve(4096u);
  }

  virtual ~MacroTokenStorage(void);

  DerivedTokenIndex AppendMacroToken(
      std::string_view data, const clang::Token &tok,
      TokenRole role_, DerivedTokenIndex macro_tok_offset_);

  DerivedTokenIndex CloneMacroToken(
      DerivedTokenIndex offset, DerivedTokenIndex macro_tok_offset_);

  void MarkPreviousTokenAsEndOfExpansion(void);
  void MarkNextTokenAsBeginOfExpansion(void);
  
  const Node *MacroName(DerivedTokenIndex offset) const;
  void MarkAsMacroName(DerivedTokenIndex offset, Node macro);

  clang::SourceLocation OriginalLocation(DerivedTokenIndex offset) const;

  std::optional<DerivedTokenIndex> ParsedTokenOffset(
      DerivedTokenIndex offset) const;

  // // Take the last thing token off of the tracker. 
  // std::tuple<std::string, clang::Token, TokenRole,
  //            DerivedTokenIndex> PopToken(void);

  void Finalize(void);
};

inline static std::optional<std::pair<unsigned, DerivedTokenIndex>>
UnpackFileAndTokenOffset(BitPackedLocation loc) {
  static_assert(sizeof(DerivedTokenIndex) == sizeof(uint32_t));

  auto tok_offset = loc & ~0u;
  auto file_offset = loc >> 32u;
  if (file_offset && tok_offset) {
    assert(file_offset < ~0u);
    return std::pair<unsigned, DerivedTokenIndex>(
        static_cast<unsigned>(file_offset - 1u),
        static_cast<DerivedTokenIndex>(tok_offset - 1u));
  }

  return std::nullopt;
}

inline static constexpr bool IsInvalidOrFileBitPackedLocation(
    BitPackedLocation loc) {
  return !loc || static_cast<uint32_t>(loc);
}

inline static constexpr bool IsMacroTokenOffset(BitPackedLocation loc) {
  return loc && (loc & ~0u) == loc;
}

inline static constexpr DerivedTokenIndex MacroTokenOffset(
    BitPackedLocation loc) {
  return static_cast<DerivedTokenIndex>((loc >> 32u) - 1u);
} 

} // namespace pasta
