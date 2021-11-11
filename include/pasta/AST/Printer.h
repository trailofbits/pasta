/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>
#include <string_view>

namespace clang {
class ASTContext;
class Decl;
class Stmt;
class Type;
class PrintingPolicy;
namespace tok {
enum TokenKind : unsigned short;
}  // namespace tok
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
class Decl;
class Type;

class PrintedTokenIterator;
class PrintedTokenImpl;
class PrintedTokenRange;
class PrintedTokenRangeImpl;

// The context associated with a printed token. This represents a path from
// the decl/stmt/type that led to the printing of this token, back to the root
// printing request.
struct PrintedTokenContext {
 public:
  const PrintedTokenContext * const parent;

  // The decl associated with the token
  const clang::Decl * const decl;

  // The stmt associated with the token
  const clang::Stmt * const stmt;

  // The types associated with the token
  const clang::Type * const type;

  // Traverse up the chain.
  static std::shared_ptr<const PrintedTokenContext> Parent(
      std::shared_ptr<const PrintedTokenContext> curr);

 private:
  friend class PrintedTokenRangeImpl;

  PrintedTokenContext(void) = delete;

  inline PrintedTokenContext(const PrintedTokenContext *parent_,
                             const clang::Stmt *stmt_)
      : parent(parent_),
        decl(nullptr),
        stmt(stmt_),
        type(nullptr) {}

  inline PrintedTokenContext(const PrintedTokenContext *parent_,
                             const clang::Decl *decl_)
      : parent(parent_),
        decl(decl_),
        stmt(nullptr),
        type(nullptr) {}

  inline PrintedTokenContext(const PrintedTokenContext *parent_,
                             const clang::Type *type_)
      : parent(parent_),
        decl(nullptr),
        stmt(nullptr),
        type(type_) {}
};

class PrintedToken {
 public:
  ~PrintedToken(void);

  PrintedToken(const PrintedToken &) = default;
  PrintedToken(PrintedToken &&) noexcept = default;
  PrintedToken &operator=(const PrintedToken &) = default;
  PrintedToken &operator=(PrintedToken &&) noexcept = default;

  // A pointer to the raw context.
  std::shared_ptr<const PrintedTokenContext> RawContext(void) const;

  // Return the data associated with this token.
  std::string_view Data(void) const;

  // Kind of this token.
  clang::tok::TokenKind Kind(void) const;

  // Number of leading new lines (before any indentation spaces).
  unsigned NumLeadingNewLines(void) const;

  // Number of leading spaces (after any leading new lines).
  unsigned NumleadingSpaces(void) const;

  // Return the index of this token in its token range.
  unsigned Index(void) const;

  inline operator bool(void) const noexcept {
    return !!impl;
  }

 private:
  friend class AST;
  friend class ASTImpl;
  friend class PrintedTokenIterator;
  friend class PrintedTokenRange;

  PrintedToken(void) = delete;

  inline explicit PrintedToken(std::shared_ptr<PrintedTokenRangeImpl> range_)
      : range(std::move(range_)),
        impl(nullptr) {}

  inline explicit PrintedToken(std::shared_ptr<PrintedTokenRangeImpl> range_, PrintedTokenImpl *impl_)
      : range(std::move(range_)),
        impl(impl_) {}

  std::shared_ptr<PrintedTokenRangeImpl> range;
  PrintedTokenImpl *impl;
};

class PrintedTokenIterator {
 public:
  typedef PrintedToken value_type;
  typedef ptrdiff_t difference_type;
  typedef const PrintedToken *pointer;
  typedef const PrintedToken &reference;
  typedef std::random_access_iterator_tag iterator_category;

  PrintedTokenIterator(const PrintedTokenIterator &) = default;
  PrintedTokenIterator(PrintedTokenIterator &&) noexcept = default;
  PrintedTokenIterator &operator=(const PrintedTokenIterator &) = default;
  PrintedTokenIterator &operator=(PrintedTokenIterator &&) noexcept = default;

  const PrintedToken &operator*(void) const noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  const PrintedToken *operator->(void) const noexcept {
    return &token;
  }

  PrintedTokenIterator &operator++(void) noexcept;
  PrintedTokenIterator operator++(int) noexcept;
  PrintedTokenIterator &operator--(void) noexcept;
  PrintedTokenIterator operator--(int) noexcept;
  PrintedTokenIterator operator+(size_t offset) const noexcept;
  PrintedTokenIterator operator-(size_t offset) const noexcept;
  PrintedTokenIterator &operator+=(size_t offset) noexcept;
  PrintedTokenIterator &operator-=(size_t offset) noexcept;
  PrintedToken operator[](size_t offset) const noexcept;
  ptrdiff_t operator-(const PrintedTokenIterator &that) const noexcept;

  inline bool operator!=(const PrintedTokenIterator &that) const noexcept {
    return token.impl != that.token.impl;
  }

  inline bool operator==(const PrintedTokenIterator &that) const noexcept {
    return token.impl == that.token.impl;
  }

  inline bool operator<=(const PrintedTokenIterator &that) const noexcept {
    return token.impl <= that.token.impl;
  }

  inline bool operator>=(const PrintedTokenIterator &that) const noexcept {
    return token.impl >= that.token.impl;
  }

  inline bool operator<(const PrintedTokenIterator &that) const noexcept {
    return token.impl < that.token.impl;
  }

  inline bool operator>(const PrintedTokenIterator &that) const noexcept {
    return token.impl > that.token.impl;
  }

 private:
  friend class PrintedTokenRange;

  PrintedTokenIterator(void) = delete;

  inline explicit PrintedTokenIterator(
      std::shared_ptr<PrintedTokenRangeImpl> range_, PrintedTokenImpl *it_)
      : token(std::move(range_), it_) {}

  PrintedToken token;
};

class PrintedTokenRangeImpl;
class PrintedTokenRange {
 public:
  PrintedTokenRange(const PrintedTokenRange &) = default;
  PrintedTokenRange(PrintedTokenRange &&) noexcept = default;
  PrintedTokenRange &operator=(const PrintedTokenRange &) = default;
  PrintedTokenRange &operator=(PrintedTokenRange &&) noexcept = default;

  // Raw interfaces for when we're not using a PASTA AST, but when we want
  // the power of its token printer.
  static PrintedTokenRange Create(clang::ASTContext &context_,
                                  const clang::PrintingPolicy &policy_,
                                  clang::Stmt *stmt_);
  static PrintedTokenRange Create(clang::ASTContext &context_,
                                  const clang::PrintingPolicy &policy_,
                                  clang::Decl *decl_);

  // More typical APIs when we've got PASTA ASTs.
  static PrintedTokenRange Create(const Decl &decl_);

  inline PrintedTokenIterator begin(void) const noexcept {
    return PrintedTokenIterator(impl, first);
  }

  inline PrintedTokenIterator end(void) const noexcept {
    return PrintedTokenIterator(impl, after_last);
  }

  inline size_t size(void) const noexcept {
    return Size();
  }

  inline bool empty(void) const noexcept {
    return !Size();
  }

  // Number of tokens in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<PrintedToken> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  PrintedToken operator[](size_t index) const;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }

 private:
  friend class AST;
  friend class ASTImpl;
  friend class DeclPrinter;

  PrintedTokenRange(void) = delete;

  inline explicit PrintedTokenRange(
      std::shared_ptr<PrintedTokenRangeImpl> impl_)
      : impl(std::move(impl_)),
        first(nullptr),
        after_last(nullptr) {}

  inline explicit PrintedTokenRange(
      std::shared_ptr<PrintedTokenRangeImpl> impl_,
      PrintedTokenImpl *begin_, PrintedTokenImpl *end_)
      : impl(std::move(impl_)),
        first(begin_),
        after_last(end_) {}

  std::shared_ptr<PrintedTokenRangeImpl> impl;
  PrintedTokenImpl *first;
  PrintedTokenImpl *after_last;
};

} // namespace pasta
