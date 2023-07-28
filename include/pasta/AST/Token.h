/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <iterator>
#include <memory>
#include <optional>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace pasta {

class AST;
class ASTImpl;
class Attr;
class CXXBaseSpecifier;
class DefineMacroDirective;
class Designator;
class FileToken;
class FileTokenRange;
class Macro;
class MacroSubstitution;
class MacroToken;
class PrintedTokenRange;
class PrintedTokenRangeImpl;
class TemplateArgument;
class TemplateParameterList;
class TokenIterator;
class TokenPrinterContext;
class TokenImpl;
class TokenRange;

// X-macro for repeated operations on TokenRole values
#define ROLES \
  ROLE(Invalid) \
  ROLE(BeginOfFileMarker) \
  ROLE(FileToken) \
  ROLE(EndOfFileMarker) \
  ROLE(BeginOfMacroExpansionMarker) \
  ROLE(InitialMacroUseToken) \
  ROLE(IntermediateMacroExpansionToken) \
  ROLE(FinalMacroExpansionToken) \
  ROLE(EndOfMacroExpansionMarker) \
  ROLE(EndOfInternalMacroEventMarker) \

enum class TokenKind : unsigned short;
enum class TokenRole : unsigned char {
  #define ROLE(role) k ## role ,
  ROLES
  #undef ROLE
};

// Vector of all token roles for iteration.
extern std::vector<TokenRole> TokenRoles;

// Returns the name of the specified TokenRole as a string.
std::string TokenRoleName(const TokenRole role);

bool IsIdentifierTokenKind(TokenKind) noexcept;
const char *KeywordSpellingOrNull(TokenKind) noexcept;

// Represents a token that has been pre-processed and parsed.
class Token {
 private:
  std::shared_ptr<ASTImpl> ast;
  const TokenImpl *impl;

 public:
  ~Token(void);

  Token(const Token &) = default;
  Token(Token &&) noexcept = default;
  Token &operator=(const Token &) = default;
  Token &operator=(Token &&) noexcept = default;

  inline const void *RawToken(void) const noexcept {
    return impl;
  }

  // Find the token from which this token was derived.
  std::optional<Token> DerivedLocation(void) const;

  // Follow this token's derived token list and accumulate results along the
  // way. The result vector's first element is this token, and the last element
  // is the first token this token was derived from.
  std::vector<Token> DerivationChain(void) const;

  // Location of the token in a file.
  std::optional<FileToken> FileLocation(void) const;

  // Location of the token in a macro expansion.
  std::optional<MacroToken> MacroLocation(void) const;

  // `#define` associated with the name of this token. This doesn't
  // necessarily mean that this token is actually expanded as the macro,
  // just that it could be referring to it at the point of use. An example
  // of where this can seem misleading is:
  //
  //      #define FOO() ...
  //      #define not_FOO
  //      #define BAR(x) not_ ## x
  //
  //      BAR(FOO)
  //
  // Here, `FOO` in the parameter to `BAR` refers to the macro `FOO`, but it
  // actually ends up being concatenated with `not_`, becoming a different
  // macro, `not_FOO`, which expands to nothing.
  std::optional<DefineMacroDirective> AssociatedMacro(void) const;

  // Returns true if we can follow the token's derived location chain to a token
  // expanded under the given macro.
  bool IsDerivedFromMacro(const Macro &macro) const noexcept;

  // Return the data associated with this token.
  std::string_view Data(void) const;

  // Index of this token in the AST's token list.
  uint64_t Index(void) const;

  // Kind of this token.
  TokenKind Kind(void) const noexcept;

  // Return the role of this token.
  TokenRole Role(void) const noexcept;

  // Return the printable kind of this token.
  const char *KindName(void) const noexcept;

  inline operator bool(void) const noexcept {
    return !!impl;
  }

  inline uint64_t Hash(void) const noexcept {
    return std::hash<const TokenImpl *>{}(impl);
  }

  inline bool operator==(const Token &that) const noexcept {
    return impl == that.impl;
  }

  inline bool operator<(const Token &that) const noexcept {
    return impl < that.impl;
  }

  // Returns the first final expansion or file token in the AST after this
  // token.
  std::optional<Token> NextFinalExpansionOrFileToken(void) const noexcept;

  // Returns the first final expansion or file token in the AST before this
  // token.
  std::optional<Token> PrevFinalExpansionOrFileToken(void) const noexcept;

 private:
  friend class AST;
  friend class ASTImpl;
  friend class CXXBaseSpecifier;
  friend class MacroToken;
  friend class TokenContext;
  friend class TokenIterator;
  friend class TokenPrinterContext;
  friend class TokenRange;

  Token(void) = delete;

  inline explicit Token(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        impl(nullptr) {}

  inline explicit Token(std::shared_ptr<ASTImpl> ast_, const TokenImpl *impl_)
      : ast(std::move(ast_)),
        impl(impl_) {}
};

// A bi-directional, random-access iterator over tokens.
class TokenIterator {
 private:
  Token token;

 public:
  typedef Token value_type;
  typedef ptrdiff_t difference_type;
  typedef const Token *pointer;
  typedef const Token &reference;
  typedef std::random_access_iterator_tag iterator_category;

  TokenIterator(const TokenIterator &) = default;
  TokenIterator(TokenIterator &&) noexcept = default;
  TokenIterator &operator=(const TokenIterator &) = default;
  TokenIterator &operator=(TokenIterator &&) noexcept = default;

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token &operator*(void) const & noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token *operator->(void) const & noexcept {
    return &token;
  }

  TokenIterator &operator++(void) noexcept;
  TokenIterator operator++(int) noexcept;
  TokenIterator &operator--(void) noexcept;
  TokenIterator operator--(int) noexcept;
  TokenIterator operator+(size_t offset) const noexcept;
  TokenIterator operator-(size_t offset) const noexcept;
  TokenIterator &operator+=(size_t offset) noexcept;
  TokenIterator &operator-=(size_t offset) noexcept;
  Token operator[](size_t offset) const noexcept;
  ptrdiff_t operator-(const TokenIterator &that) const noexcept;

  inline bool operator!=(const TokenIterator &that) const noexcept {
    return token.impl != that.token.impl;
  }

  inline bool operator==(const TokenIterator &that) const noexcept {
    return token.impl == that.token.impl;
  }

  inline bool operator<=(const TokenIterator &that) const noexcept {
    return token.impl <= that.token.impl;
  }

  inline bool operator>=(const TokenIterator &that) const noexcept {
    return token.impl >= that.token.impl;
  }

  inline bool operator<(const TokenIterator &that) const noexcept {
    return token.impl < that.token.impl;
  }

  inline bool operator>(const TokenIterator &that) const noexcept {
    return token.impl > that.token.impl;
  }

 private:
  friend class TokenRange;

  TokenIterator(void) = delete;

  inline explicit TokenIterator(const std::shared_ptr<ASTImpl> &ast_,
                                const TokenImpl *it_)
      : token(ast_, it_) {}
};

// Range of tokens.
class TokenRange {
 private:
  std::shared_ptr<ASTImpl> ast;
  const TokenImpl *first;
  const TokenImpl *after_last;

 public:
  TokenRange(const TokenRange &) = default;
  TokenRange(TokenRange &&) noexcept = default;
  TokenRange &operator=(const TokenRange &) = default;
  TokenRange &operator=(TokenRange &&) noexcept = default;

  inline TokenIterator begin(void) const noexcept {
    return TokenIterator(ast, first);
  }

  inline TokenIterator end(void) const noexcept {
    return TokenIterator(ast, after_last);
  }

  // Tries to create a TokenRange from the given beginning and ending tokens.
  // Fails if the tokens don't belong to the same AST, or if the beginning token
  // comes after the ending token.
  static std::optional<TokenRange> From(Token begin, Token end);

  inline size_t size(void) const noexcept {
    return Size();
  }

  inline bool empty(void) const noexcept {
    return !Size();
  }

  // If this range is not empty, returns the first token. Otherwise returns
  // std::nullopt.
  std::optional<Token> Front(void) const noexcept;

  // If this range is not empty, returns the last token. Otherwise returns
  // std::nullopt.
  std::optional<Token> Back(void) const noexcept;

  // Number of tokens in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<Token> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  Token operator[](size_t index) const;

  // Returns the list of macros that align with this token range, in the order
  // of most-nested to least. The optional heuristic determines whether or not
  // to try and match macro expansions that contain semicolons.
  std::vector<MacroSubstitution>
  AlignedSubstitutions(bool heuristic) noexcept;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }

 private:
  friend class AST;
  friend class ASTImpl;
  friend class CXXBaseSpecifier;
  friend class DeclPrinter;
  friend class PrintedTokenRange;
  friend class Token;

  TokenRange(void) = delete;

  inline explicit TokenRange(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        first(nullptr),
        after_last(nullptr) {}

  inline explicit TokenRange(std::shared_ptr<ASTImpl> ast_,
                             const TokenImpl *begin_, const TokenImpl *end_)
      : ast(std::move(ast_)),
        first(begin_),
        after_last(end_) {}
};

}  // namespace pasta
namespace std {

template <>
struct hash<::pasta::Token> {
  uintptr_t operator()(const ::pasta::Token &tok) const noexcept {
    return tok.Hash();
  }
};

}  // namespace std
