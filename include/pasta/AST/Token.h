/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <iterator>
#include <memory>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>

#define PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(pp) \
    pp(Stmt) \
    pp(Decl) \
    pp(Type) \
    pp(TemplateParameterList) \
    pp(TemplateArgument) \
    pp(TypeConstraint) \
    pp(Attr)

namespace clang {

#define PASTA_FORWARD_DECLARE_CLASS(cls) class cls;
PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_FORWARD_DECLARE_CLASS)
#undef PASTA_FORWARD_DECLARE_CLASS

namespace tok {
enum TokenKind : unsigned short;
}  // namespace tok
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
class FileToken;
class FileTokenRange;
class PrintedTokenRangeImpl;
class TokenContextImpl;
class TokenIterator;
class TokenPrinterContext;
class TokenImpl;
class TokenRange;

enum class TokenRole : std::underlying_type_t<clang::tok::TokenKind> {
  kInvalid,

  kBeginOfFileMarker,
  kFileToken,
  kEndOfFileMarker,

  kBeginOfMacroExpansionMarker,
  kMacroExpansionToken,
  kEndOfMacroExpansionMarker,

  // An invented token from the pretty-printer.
  kPrintedToken,
};

enum class TokenContextKind : unsigned char {
  kInvalid,
#define PASTA_DECLARE_TOKEN_CONTEXT_KIND(cls) k ## cls ,
  PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_DECLARE_TOKEN_CONTEXT_KIND)
#undef PASTA_DECLARE_TOKEN_CONTEXT_KIND

  // This is some metadata of some fixed kind.
  kString,

  // This is an alias to another token kind higher up in the stack.
  kAlias
};

// The context associated with a printed token. This represents a path from
// the decl/stmt/type that led to the printing of this token, back to the root
// printing request.
class TokenContext {
 private:
  const TokenContextImpl *impl;
  std::shared_ptr<const std::vector<TokenContextImpl>> contexts;

 public:
  // Return the index of this token context.
  uint32_t Index(void) const;

  // String representation of this token context kind.
  const char *KindName(void) const;

  // Return the kind of this context.
  TokenContextKind Kind(void) const;

  // Return the data of this context.
  const void *Data(void) const;

  // Return the parent context.
  std::optional<TokenContext> Parent(void) const;

  // Return the context aliased by this context.
  std::optional<TokenContext> Aliasee(void) const;

  // Try to update this context to point to its parent.
  bool TryUpdateToParent(void);

  // Try to update this context to point to its aliasee.
  bool TryUpdateToAliasee(void);

  inline uint64_t Hash(void) const noexcept {
    return std::hash<const TokenContextImpl *>{}(impl);
  }

  inline bool operator==(const TokenContext &that) const noexcept {
    return impl == that.impl;
  }

  inline bool operator<(const TokenContext &that) const noexcept {
    return impl < that.impl;
  }

 private:
  friend class Decl;
  friend class PrintedToken;
  friend class Stmt;
  friend class Token;
  friend class Type;

  TokenContext(void) = delete;

  inline explicit TokenContext(
      const TokenContextImpl *impl_,
      std::shared_ptr<const std::vector<TokenContextImpl>> contexts_)
      : impl(impl_),
        contexts(std::move(contexts_)) {}
};

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

  // Location of the token in a file.
  std::optional<FileToken> FileLocation(void) const;

  // Return the data associated with this token.
  std::string_view Data(void) const;

  // Index of this token in the AST's token list.
  uint64_t Index(void) const;

  // Kind of this token.
  clang::tok::TokenKind Kind(void) const noexcept;

  // Return the role of this token.
  TokenRole Role(void) const noexcept;

  // Return the printable kind of this token.
  const char *KindName(void) const noexcept;

  inline operator bool(void) const noexcept {
    return !!impl;
  }

  // If this token is a macro expansion token, or is the beginning or ending of
  // a macro expansion range, then return the entire range of file tokens which
  // led to this macro expansion. Otherwise, return an empty range.
  FileTokenRange MacroUseTokens(void) const noexcept;

  // If this token is a macro expansion token, or is the beginning or ending of
  // a macro expansion range, then return the entire range. Otherwise, this will
  // return an empty range.
  TokenRange MacroExpandedTokens(void) const noexcept;

  // Return this token's context, or a null context.
  std::optional<TokenContext> Context(void) const noexcept;

  inline uint64_t Hash(void) const noexcept {
    return std::hash<const TokenImpl *>{}(impl);
  }

  inline bool operator==(const Token &that) const noexcept {
    return impl == that.impl;
  }

  inline bool operator<(const Token &that) const noexcept {
    return impl < that.impl;
  }

 private:
  friend class AST;
  friend class ASTImpl;
  friend class TokenIterator;
  friend class TokenPrinterContext;
  friend class TokenRange;
  friend class Token;

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
  inline const Token &operator*(void) const noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token *operator->(void) const noexcept {
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

  inline size_t size(void) const noexcept {
    return Size();
  }

  // Number of tokens in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<Token> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  Token operator[](size_t index) const;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }

 private:
  friend class AST;
  friend class ASTImpl;
  friend class DeclPrinter;
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

template <>
struct hash<::pasta::TokenContext> {
  uintptr_t operator()(const ::pasta::TokenContext &ctx) const noexcept {
    return ctx.Hash();
  }
};

}  // namespace std
