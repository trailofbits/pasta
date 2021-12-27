/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <iterator>
#include <memory>
#include <optional>
#include <string_view>

namespace clang {
namespace tok {
enum TokenKind : unsigned short;
}  // namespace tok
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
class FileToken;
class TokenIterator;
class TokenPrinterContext;
class TokenImpl;
class TokenRange;

// Represents a token that has been pre-processed and parsed.
class Token {
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
  clang::tok::TokenKind Kind(void) const;

  inline operator bool(void) const noexcept {
    return !!impl;
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

  inline explicit Token(std::shared_ptr<ASTImpl> ast_, TokenImpl *impl_)
      : ast(std::move(ast_)),
        impl(impl_) {}

  std::shared_ptr<ASTImpl> ast;
  TokenImpl *impl;
};

// A bi-directional, random-access iterator over tokens.
class TokenIterator {
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
  const Token &operator*(void) const noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  const Token *operator->(void) const noexcept {
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
                                TokenImpl *it_)
      : token(ast_, it_) {}

  Token token;
};

// Range of tokens.
class TokenRange {
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

  TokenRange(void) = delete;

  inline explicit TokenRange(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        first(nullptr),
        after_last(nullptr) {}

  inline explicit TokenRange(std::shared_ptr<ASTImpl> ast_,
                             TokenImpl *begin_, TokenImpl *end_)
      : ast(std::move(ast_)),
        first(begin_),
        after_last(end_) {}

  std::shared_ptr<ASTImpl> ast;
  TokenImpl *first;
  TokenImpl *after_last;
};

}  // namespace pasta
