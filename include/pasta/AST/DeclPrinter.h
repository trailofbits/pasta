
#pragma once

#include <memory>
#include <optional>
#include <string_view>
#include <vector>

#include "Decl.h"
#include "Token.h"
#include "Type.h"

namespace clang {
class ASTContext;
}  // namespace clang


namespace pasta {

class ASTImpl;
class Decl;
class Type;

class FatTokenIterator;
struct FatTokenImpl;
class FatTokenRange;

class DeclPrinterImpl;
class StmtPrinterImpl;

class FatToken {
 public:
  ~FatToken(void);

  FatToken(const FatToken &) = default;
  FatToken(FatToken &&) noexcept = default;
  FatToken &operator=(const FatToken &) = default;
  FatToken &operator=(FatToken &&) noexcept = default;

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
  friend class FatTokenIterator;
  friend class FatTokenRange;

  FatToken(void) = delete;

  inline explicit FatToken(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        impl(nullptr) {}

  inline explicit FatToken(std::shared_ptr<ASTImpl> ast_, FatTokenImpl *impl_)
      : ast(std::move(ast_)),
        impl(impl_) {}

  std::shared_ptr<ASTImpl> ast;
  FatTokenImpl *impl;
};

class FatTokenIterator {
 public:
  typedef FatToken value_type;
  typedef ptrdiff_t difference_type;
  typedef const FatToken *pointer;
  typedef const FatToken &reference;
  typedef std::random_access_iterator_tag iterator_category;

  FatTokenIterator(const FatTokenIterator &) = default;
  FatTokenIterator(FatTokenIterator &&) noexcept = default;
  FatTokenIterator &operator=(const FatTokenIterator &) = default;
  FatTokenIterator &operator=(FatTokenIterator &&) noexcept = default;

  const FatToken &operator*(void) const noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  const FatToken *operator->(void) const noexcept {
    return &token;
  }

  FatTokenIterator &operator++(void) noexcept;
  FatTokenIterator operator++(int) noexcept;
  FatTokenIterator &operator--(void) noexcept;
  FatTokenIterator operator--(int) noexcept;
  FatTokenIterator operator+(size_t offset) const noexcept;
  FatTokenIterator operator-(size_t offset) const noexcept;
  FatTokenIterator &operator+=(size_t offset) noexcept;
  FatTokenIterator &operator-=(size_t offset) noexcept;
  FatToken operator[](size_t offset) const noexcept;
  ptrdiff_t operator-(const FatTokenIterator &that) const noexcept;

  inline bool operator!=(const FatTokenIterator &that) const noexcept {
    return token.impl != that.token.impl;
  }

  inline bool operator==(const FatTokenIterator &that) const noexcept {
    return token.impl == that.token.impl;
  }

  inline bool operator<=(const FatTokenIterator &that) const noexcept {
    return token.impl <= that.token.impl;
  }

  inline bool operator>=(const FatTokenIterator &that) const noexcept {
    return token.impl >= that.token.impl;
  }

  inline bool operator<(const FatTokenIterator &that) const noexcept {
    return token.impl < that.token.impl;
  }

  inline bool operator>(const FatTokenIterator &that) const noexcept {
    return token.impl > that.token.impl;
  }

 private:
  friend class FatTokenRange;

  FatTokenIterator(void) = delete;

  inline explicit FatTokenIterator(const std::shared_ptr<ASTImpl> &ast_,
                                FatTokenImpl *it_)
      : token(ast_, it_) {}

  FatToken token;
};

// Range of tokens.
class FatTokenRange {
 public:
  FatTokenRange(const FatTokenRange &) = default;
  FatTokenRange(FatTokenRange &&) noexcept = default;
  FatTokenRange &operator=(const FatTokenRange &) = default;
  FatTokenRange &operator=(FatTokenRange &&) noexcept = default;

  inline FatTokenIterator begin(void) const noexcept {
    return FatTokenIterator(ast, first);
  }

  inline FatTokenIterator end(void) const noexcept {
    return FatTokenIterator(ast, after_last);
  }

  inline size_t size(void) const noexcept {
    return Size();
  }

  // Number of tokens in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<FatToken> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  FatToken operator[](size_t index) const;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }

 private:
  friend class AST;
  friend class ASTImpl;
  friend class DeclPrinter;

  FatTokenRange(void) = delete;

  inline explicit FatTokenRange(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        first(nullptr),
        after_last(nullptr) {}

  inline explicit FatTokenRange(std::shared_ptr<ASTImpl> ast_,
                                FatTokenImpl *begin_, FatTokenImpl *end_)
      : ast(std::move(ast_)),
        first(begin_),
        after_last(end_) {}

  std::shared_ptr<ASTImpl> ast;
  FatTokenImpl *first;
  FatTokenImpl *after_last;
};

class DeclPrinter {
 public:
  explicit DeclPrinter(AST &ast_, const pasta::Decl &decl_);

  ~DeclPrinter(void);

  FatTokenRange Tokens(void);

 private:
  friend class DeclPrinterImpl;

  AST &ast;
  std::shared_ptr<DeclPrinterImpl> impl;
};

class StmtPrinter {
 public:
  explicit StmtPrinter(AST &ast_, const pasta::Stmt &stmt_);

  ~StmtPrinter();

  FatTokenRange Tokens(void);

 private:
  friend class StmtPrinterImpl;

  AST &ast;
  std::shared_ptr<StmtPrinterImpl> impl;
};

} // namespace pasta
