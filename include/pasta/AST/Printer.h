/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>
#include <pasta/Util/Result.h>
#include <string_view>
#include <utility>
#include <vector>

#define PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(pp) \
    pp(Stmt) \
    pp(Decl) \
    pp(Type) \
    pp(Attr) \
    pp(CXXBaseSpecifier) \
    pp(Designator) \
    pp(CXXCtorInitializer) \
    pp(TemplateParameterList) \
    pp(TemplateArgument) \
    pp(TypeConstraint)

namespace clang {
class ASTContext;
class Decl;
class QualType;
class Stmt;
class TemplateArgument;
class TemplateParameterList;
class Type;
struct PrintingPolicy;

#define PASTA_FORWARD_DECLARE_CLASS(cls) class cls;
PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_FORWARD_DECLARE_CLASS)
#undef PASTA_FORWARD_DECLARE_CLASS

}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class Decl;
class FunctionDecl;
class FunctionTemplateDecl;
class PrintedTokenIterator;
class PrintedTokenImpl;
class PrintedTokenRange;
class PrintedTokenRangeImpl;
class Stmt;
class TagDecl;
class TemplateDecl;
class TokenContextImpl;
class Type;
class Token;
class TokenRange;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;

enum class TokenKind : unsigned short;

enum class TokenContextKind : unsigned char {
  kInvalid,
#define PASTA_DECLARE_TOKEN_CONTEXT_KIND(cls) k ## cls ,
  PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_DECLARE_TOKEN_CONTEXT_KIND)
#undef PASTA_DECLARE_TOKEN_CONTEXT_KIND

  // This is some metadata of some fixed kind.
  kString,

  // This is an alias to another token kind higher up in the stack.
  kAlias,

  // This is an AST marker node. These are the main roots of all parsed
  // token ranges.
  kAST,
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
  friend class Attr;
  friend class Decl;
  friend class CXXBaseSpecifier;
  friend class CXXCtorInitializer;
  friend class Designator;
  friend class PrintedToken;
  friend class Stmt;
  friend class TemplateArgument;
  friend class TemplateParameterList;
  friend class Token;
  friend class Type;

  TokenContext(void) = delete;

  inline explicit TokenContext(
      const TokenContextImpl *impl_,
      std::shared_ptr<const std::vector<TokenContextImpl>> contexts_)
      : impl(impl_),
        contexts(std::move(contexts_)) {}
};

class PrintedToken {
 public:
  ~PrintedToken(void);

  PrintedToken(const PrintedToken &) = default;
  PrintedToken(PrintedToken &&) noexcept = default;
  PrintedToken &operator=(const PrintedToken &) = default;
  PrintedToken &operator=(PrintedToken &&) noexcept = default;

  // Return the data associated with this token.
  std::string_view Data(void) const;

  // Kind of this token.
  TokenKind Kind(void) const;

  // Find the parsed token from which this printed token was derived.
  std::optional<Token> DerivedLocation(void) const;

  // Return the index of this token in its token range.
  unsigned Index(void) const;

  // Return this token's context, or a null context.
  std::optional<TokenContext> Context(void) const noexcept;

  inline operator bool(void) const noexcept {
    return !!impl;
  }

  // Return a pointer to the underlying data. Suitable for hashing.
  inline const void *RawToken(void) const noexcept {
    return impl;
  }

  inline uint64_t Hash(void) const noexcept {
    return std::hash<const void *>{}(RawToken());
  }

  inline bool operator==(const PrintedToken &that) const noexcept {
    return impl == that.impl;
  }

  inline bool operator<(const PrintedToken &that) const noexcept {
    return impl < that.impl;
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

  inline explicit PrintedToken(std::shared_ptr<PrintedTokenRangeImpl> range_,
                               PrintedTokenImpl *impl_)
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

class PrintingPolicy {
 public:
  virtual ~PrintingPolicy(void);

  // Should the default behaviour be to print tag (enum, struct, union, class)
  // bodies or not? The defaults are overwritten based on contextual decisions.
  virtual bool ShouldPrintTagBodies(void) const;

  // Should we print out inherited attributes?
  virtual bool ShouldPrintInheritedAttributes(void) const;

  // Should we print out implicit attributes?
  virtual bool ShouldPrintImplicitAttributes(void) const;

  // E.g. if the size of a type is a constant expression, then should we print
  // it, or just the result value of the expression?
  virtual bool ShouldPrintConstantExpressionsInTypes(void) const;

  // When asked to print an adjusted type, should we print the new type, or
  // the original. The original will likely be more representative of the
  // type as parsed, but the new one will be better for deduplication.
  virtual bool ShouldPrintOriginalTypeOfAdjustedType(void) const;

  // When asked ot print a decayed type, should we print the new type or the
  // original type? The original type will be closer to what is in the actual
  // source code, but the decayed type will more accurately represent the
  // semantics of the type. An example is passing a constant sized array type
  // to a function, which then decays into a pointer.
  virtual bool ShouldPrintOriginalTypeOfDecayedType(void) const;

  virtual bool ShouldPrintTemplate(const TemplateDecl &) const;
  
  virtual bool ShouldPrintTemplate(
      const ClassTemplatePartialSpecializationDecl &) const;
  
  virtual bool ShouldPrintTemplate(
      const VarTemplatePartialSpecializationDecl &) const;
  
  virtual bool ShouldPrintSpecialization(
      const ClassTemplateDecl &, const ClassTemplateSpecializationDecl &) const;
  
  virtual bool ShouldPrintSpecialization(const FunctionTemplateDecl &,
                                         const FunctionDecl &) const;

  virtual bool ShouldPrintSpecialization(
      const VarTemplateDecl &, const VarTemplateSpecializationDecl &) const;
};

class ProxyPrintingPolicy : public PrintingPolicy {
 protected:
  const PrintingPolicy &next;
 public:
  virtual ~ProxyPrintingPolicy(void);

  inline ProxyPrintingPolicy(const PrintingPolicy &next_)
      : next(next_) {}

  bool ShouldPrintTagBodies(void) const override;
  bool ShouldPrintInheritedAttributes(void) const override;
  bool ShouldPrintImplicitAttributes(void) const override;
  bool ShouldPrintConstantExpressionsInTypes(void) const override;
  bool ShouldPrintOriginalTypeOfAdjustedType(void) const override;
  bool ShouldPrintOriginalTypeOfDecayedType(void) const override;

  bool ShouldPrintTemplate(const TemplateDecl &) const override;

  bool ShouldPrintTemplate(
      const ClassTemplatePartialSpecializationDecl &) const override;

  bool ShouldPrintTemplate(
      const VarTemplatePartialSpecializationDecl &) const override;

  bool ShouldPrintSpecialization(
      const ClassTemplateDecl &,
      const ClassTemplateSpecializationDecl &) const override;

  bool ShouldPrintSpecialization(const FunctionTemplateDecl &,
                                 const FunctionDecl &) const override;

  // TODO(pag): ClassScopeFunctionSpecializationDecl
  // TODO(pag): FriendTemplateDecl

  bool ShouldPrintSpecialization(
      const VarTemplateDecl &,
      const VarTemplateSpecializationDecl &) const override;
};

class PrintedTokenRangeImpl;
class PrintedTokenRange {
 public:
  PrintedTokenRange(const PrintedTokenRange &) = default;
  PrintedTokenRange(PrintedTokenRange &&) noexcept = default;
  PrintedTokenRange &operator=(const PrintedTokenRange &) = default;
  PrintedTokenRange &operator=(PrintedTokenRange &&) noexcept = default;

  // Create an empty range.
  static PrintedTokenRange CreateEmpty(const AST &ast_);

  // Raw interfaces for when we're not using a PASTA AST, but when we want
  // the power of its token printer.
  static PrintedTokenRange Create(clang::ASTContext &context_,
                                  const clang::PrintingPolicy &policy_,
                                  clang::Stmt *stmt_);

  static PrintedTokenRange Create(clang::ASTContext &context_,
                                  const clang::PrintingPolicy &policy_,
                                  clang::Decl *decl_);

  static PrintedTokenRange Create(clang::ASTContext &context_,
                                  const clang::PrintingPolicy &policy_,
                                  const clang::QualType &type);

  // More typical APIs when we've got PASTA ASTs.
  static PrintedTokenRange Create(
      const Decl &decl_, const PrintingPolicy &pp_=PrintingPolicy());

  static PrintedTokenRange Create(
      const Stmt &stmt_, const PrintingPolicy &pp_=PrintingPolicy());

  static PrintedTokenRange Create(
      const Type &type_, const PrintingPolicy &pp_=PrintingPolicy());

  // Create a new printed token range by concatenating two printed token ranges
  // together.
  //
  // Returns `std::nullopt` if `a` and/or `b` have corresponding ASTs that don't
  // match.
  static std::optional<PrintedTokenRange>
  Concatenate(const PrintedTokenRange &a, const PrintedTokenRange &b);

  // Align the token locations from `with_locs` with the token contexts from
  // `with_contexts`. Returns a string if an error occured. This provides a
  // mechanism of relating parsedtokens back to AST nodes, when `with_locs` is
  // derived from `Adopt` below.
  //
  // NOTE(pag): Both `with_locs` and `with_contexts` are mutated in-place.
  static std::optional<std::string> Align(PrintedTokenRange &with_locs,
                                          PrintedTokenRange &with_contexts);
  
  // Create a new printed token range from `wants_ws` and `has_ws`, where
  // `wants_ws` and `has_ws` share derived token locations, and we want to
  // import whitespace from `has_ws` into places where it's missing in
  // `wants_ws`, but without chaning `wants_ws`.
  static PrintedTokenRange AdoptWhitespace(const PrintedTokenRange &wants_ws,
                                           const PrintedTokenRange &has_ws);

  // Create a new printed token range, where the token data is taken from `a`.
  // The only token contexts in an adopted range are AST contexts. The only
  // tokens in a printed token range are file tokens and complete macro
  // expansion tokens.
  static PrintedTokenRange Adopt(const TokenRange &a);

  // Create a copy of `a`.
  static PrintedTokenRange Copy(const PrintedTokenRange &a);

  // Dump token provenance information.
  void DumpProvenanceInformation(void);

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

  // Returns `true` if this range contains a specific token.
  inline bool Contains(const PrintedToken &tok) const noexcept {
    return impl == tok.range && first <= tok.impl && tok.impl < after_last;
  }

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first < after_last;
  }

  // Do two ranges match?
  inline bool operator==(const PrintedTokenRange &that) const noexcept {
    return impl == that.impl && first == that.first &&
           after_last == that.after_last;
  }

  std::string_view Data(void) const noexcept;

 private:
  friend class AST;
  friend class ASTImpl;
  friend class DeclPrinter;
  friend class PrintedTokenRangeImpl;

  PrintedTokenRange(void) = delete;

  // Raw interfaces for when we're not using a PASTA AST, but when we want
  // the power of its token printer.
  static PrintedTokenRange Create(const std::shared_ptr<ASTImpl> &,
                                  clang::Stmt *stmt_,
                                  const PrintingPolicy &pp_);

  static PrintedTokenRange Create(const std::shared_ptr<ASTImpl> &,
                                  clang::Decl *decl_,
                                  const PrintingPolicy &pp_);

  static PrintedTokenRange Create(const std::shared_ptr<ASTImpl> &,
                                  const clang::QualType &type,
                                  const PrintingPolicy &pp_);

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
namespace std {

template <>
struct hash<::pasta::TokenContext> {
  uintptr_t operator()(const ::pasta::TokenContext &ctx) const noexcept {
    return ctx.Hash();
  }
};

template <>
struct hash<::pasta::PrintedToken> {
  uintptr_t operator()(const ::pasta::PrintedToken &tok) const noexcept {
    return tok.Hash();
  }
};

}  // namespace std
