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
using TokenDataOffset = uint32_t;
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

static constexpr uint32_t kTokenSizeMask = ((1u << 20) - 1u);
static constexpr OpaqueSourceLoc kInvalidSourceLocation = 0u;

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

class ParsedTokenIterator;

class ParsedTokenStorage {
 protected:
  friend class AST;
  friend class ASTImpl;
  friend class ParsedTokenIterator;
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

  void AppendLeadingWhitespace(const clang::Token &tok);

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

  inline void SetRole(DerivedTokenIndex offset, TokenRole role_) {
    role[offset] = role_;
  }

  inline void SetLocation(DerivedTokenIndex offset, BitPackedLocation loc_) {
    location[offset] = loc_;
  }

  std::optional<DerivedTokenIndex> DataOffsetToTokenIndex(
      unsigned offset) const;

  void AppendSplitTokens(BitPackedLocation loc, TokenKind kind_,
                         bool is_in_pragma);
  void AppendFileToken(std::string_view data, const clang::Token &tok);
  void AppendMacroToken(const clang::Token &tok);
  void AppendInternalToken(std::string_view tok_data,
                           clang::SourceLocation loc,
                           TokenRole role_,
                           bool is_in_pragma=false);

  // Append a marker token to the parsed token list.
  void AppendMarkerToken(clang::SourceLocation loc, TokenRole role);

  // Try to split the token at offset `offset`.
  void SplitToken(DerivedTokenIndex offset);

  void Finalize(void);
};

class MacroTokenStorage : public ParsedTokenStorage {
 private:
  friend class ASTImpl;
  friend class MacroToken;
  friend class ParsedTokenStorage;
  friend class Token;
  
  // Offset in `ASTImpl::root_macro_node.tokens` where this token is located.
  std::vector<DerivedTokenIndex> macro_token_offset;

  // State used during the lexing phase to keep track of whether or not we're
  // inside of an expansion.
  bool next_is_begin_expansion{false};
  std::optional<DerivedTokenIndex> last_expansion_begin_offset;

  // If a token is associated with a macro, then we can find that associated
  // macro node here.
  std::unordered_map<DerivedTokenIndex, Node> macro_definition;

  // Opaque source location of the last macro use token.
  std::optional<clang::SourceLocation> last_use_loc;

  // State used when fixing up token provenance.
  using TokenProvenanceMap = std::unordered_map<OpaqueSourceLoc,
                                                BitPackedLocation>;

  TokenProvenanceMap file_token_refs;
  TokenProvenanceMap macro_token_refs;

  // Hidden methods.
  using ParsedTokenStorage::AppendFileToken;
  using ParsedTokenStorage::AppendMacroToken;
  using ParsedTokenStorage::AppendSplitTokens;
  using ParsedTokenStorage::Finalize;

  void FixupTokenProvenance(
      DerivedTokenIndex tok_index, DerivedTokenIndex min_derived_index,
      bool can_be_derived, int depth, clang::SourceLocation loc);

 public:
  inline MacroTokenStorage(ASTImpl *ast_)
      : ParsedTokenStorage(ast_) {
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

class ParsedTokenIterator {
 private:
  const ParsedTokenStorage *storage;
  DerivedTokenIndex upper_bound{0u};  // Inclusive.
  DerivedTokenIndex offset{0u};

  ParsedTokenIterator(void) = delete;

 public:
  ParsedTokenIterator(ParsedTokenIterator &&) noexcept = default;
  ParsedTokenIterator(const ParsedTokenIterator &) = default;

  ParsedTokenIterator &operator=(ParsedTokenIterator &&) noexcept = default;
  ParsedTokenIterator &operator=(const ParsedTokenIterator &) = default;

  inline ParsedTokenIterator(const ParsedTokenStorage *storage_,
                             DerivedTokenIndex upper_bound_,
                             DerivedTokenIndex offset_)
      : storage(storage_),
        upper_bound(upper_bound_),
        offset(offset_) {}

  inline ParsedTokenIterator(const ParsedTokenStorage *storage_,
                             DerivedTokenIndex offset_)
      : ParsedTokenIterator(storage_, storage_->size() - 1u, offset_) {}

  bool Next(DerivedTokenIndex inclusive_upper_bound);
  bool Previous(DerivedTokenIndex inclusive_lower_bound);

  inline bool Next(void) {
    return Next(upper_bound);
  }

  inline bool Previous(void) {
    return Previous(0u);
  }

  inline bool Next(const ParsedTokenIterator &upper) {
    assert(storage == upper.storage);
    return Next(upper.offset);
  }

  inline bool Previous(const ParsedTokenIterator &lower) {
    assert(storage == lower.storage);
    return Previous(lower.offset);
  }

  ParsedTokenIterator WithOffset(DerivedTokenIndex new_offset) const noexcept;

  inline DerivedTokenIndex Offset(void) const noexcept {
    return offset;
  }

  inline std::string_view Data(void) const noexcept {
    return storage->Data(offset);
  }

  inline bool IsValid(void) const noexcept {
    return !!upper_bound;
  }

  inline operator bool(void) const noexcept {
    return !!upper_bound;
  }

  inline bool operator<(const ParsedTokenIterator &that) const noexcept {
    return storage == that.storage && offset < that.offset;
  }

  inline bool operator<=(const ParsedTokenIterator &that) const noexcept {
    return storage == that.storage && offset <= that.offset;
  }

  inline bool operator>(const ParsedTokenIterator &that) const noexcept {
    return storage == that.storage && offset > that.offset;
  }

  inline bool operator>=(const ParsedTokenIterator &that) const noexcept {
    return storage == that.storage && offset >= that.offset;
  }

  inline bool IsInPragmaDirective(void) const noexcept {
    return storage->IsInPragmaDirective(offset);
  }

  inline bool InInclusiveBounds(
      const ParsedTokenIterator &lower_inclusive,
      const ParsedTokenIterator &upper_inclusive) const {
    return lower_inclusive.storage == storage &&
           upper_inclusive.storage == storage &&
           lower_inclusive.offset <= offset &&
           upper_inclusive.offset >= offset &&
           upper_bound;
  }

  inline bool InInclusiveBoundsFast(
      const ParsedTokenIterator &lower_inclusive,
      const ParsedTokenIterator &upper_inclusive) const {
    return lower_inclusive.offset <= offset &&
           upper_inclusive.offset >= offset;
  }

  inline bool IsParsed(void) const noexcept {
    switch (Role()) {
      case TokenRole::kInvalid:
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kEmptyOrSpecialMacroToken:
        return false;
      default:
        return true;
    }
  }

  inline TokenKind Kind(void) const noexcept {
    return storage->Kind(offset);
  }

  inline TokenRole Role(void) const noexcept {
    return storage->Role(offset);
  }

  inline bool operator==(const ParsedTokenIterator &that) const noexcept {
    return storage == that.storage && offset == that.offset;
  }
};

} // namespace pasta
