/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>

#include "Forward.h"

namespace llvm {
class APSInt;
}  // namespace llvm
namespace clang {
class CXXBaseSpecifier;
class CXXCtorInitializer;
class TemplateArgument;
class TemplateParameterList;
}  // namespace clang
namespace pasta {

class ASTImpl;
class Attr;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class Decl;
class DecompositionDecl;
class Designator;
class EnumDecl;
class Expr;
class ImplicitParamDecl;
class NamedDecl;
class OMPCapturedExprDecl;
class ParmVarDecl;
class PrintedTokenRange;
class RecordDecl;
class Token;
class TokenContext;
class VarTemplatePartialSpecializationDecl;

enum class TemplateArgumentKind : unsigned int;

enum class DeclCategory : unsigned int {
  kUnknown,
  kLocalVariable,
  kGlobalVariable,
  kParameterVariable,
  kFunction,
  kInstanceMethod,
  kInstanceMember,
  kClassMethod,
  kClassMember,
  kThis,
  kClass,
  kStructure,
  kUnion,
  kConcept,
  kInterface,
  kEnumeration,
  kEnumerator,
  kNamespace,
  kTypeAlias,
  kTemplateTypeParameter,
  kTemplateValueParameter,
  kLabel,
};

class CXXBaseSpecifier {
 private:
  std::shared_ptr<ASTImpl> ast;
  const clang::CXXBaseSpecifier *spec;

  friend class CXXRecordDecl;

 public:
  inline CXXBaseSpecifier(std::shared_ptr<ASTImpl> ast_,
                          const clang::CXXBaseSpecifier &spec_)
      : ast(std::move(ast_)),
        spec(&spec_) {}

  inline CXXBaseSpecifier(std::shared_ptr<ASTImpl> ast_,
                          const clang::CXXBaseSpecifier *spec_)
      : ast(std::move(ast_)),
        spec(spec_) {}

#ifndef PASTA_IN_BOOTSTRAP
  static std::optional<CXXBaseSpecifier> From(const TokenContext &) noexcept;

  inline const void *RawCXXBaseSpecifier(void) const noexcept {
    return spec;
  }

  // Range of the tokens for the specific.
  ::pasta::TokenRange Tokens(void) const noexcept;

  // Token of the the base type name. Doesn't include the qualifiers.
  ::pasta::Token BaseTypeToken(void) const noexcept;

  // For a pack expansion, determine the location of the ellipsis.
  std::optional<Token> EllipsisToken(void) const noexcept;

  // Is this a virtual base (using virtual inheritance)?
  bool IsVirtual(void) const noexcept;

  // Is this specifier a pack expansion?
  bool IsPackExpansion(void) const noexcept;

  // Returns `true` if the constructors from the base class are explicitly
  // inherited in the derived class with a `using` declaration.
  bool ConstructorsAreInherited(void) const noexcept;

  // Kind of the base type. This is either `TagTypeKind::kStruct` or
  // `TagTypeKind::kClass`.
  TagTypeKind BaseKind(void) const noexcept;

  // Returns the access specifier for this base specifier.
  //
  // This is the actual base specifier as used for semantic analysis, so
  // the result can never be `AccessSpecifier::kNone`. To retrieve the access
  // specifier as written in the source code, use `LexicalAccessSpecifier`.
  ::pasta::AccessSpecifier SemanticAccessSpecifier(void) const noexcept;

  // Retrieves the access specifier as written in the source code
  // (which may mean that no access specifier was explicitly written).
  //
  // Use `SemanticAccessSpecifier` to retrieve the access specifier for use in
  // semantic analysis.
  ::pasta::AccessSpecifier LexicalAccessSpecifier(void) const noexcept;

  // Retrieves the type of the base class.
  //
  // This type will always be an unqualified class type.
  //
  // NOTE(pag): This might not be a struct/class type, but could be a typedef
  //            to a struct/class type.
  ::pasta::Type BaseType(void) const noexcept;

  // Returns the base class, if known. It might not be known if the base type
  // is dependent / not deduced.
  std::optional<::pasta::CXXRecordDecl> BaseClass(void) const noexcept;
#endif  // PASTA_IN_BOOTSTRAP
};

class TemplateArgument {
 private:
  friend class AST;

  std::shared_ptr<ASTImpl> ast;
  const clang::TemplateArgument *arg;

 public:
  inline TemplateArgument(std::shared_ptr<ASTImpl> ast_,
                          const clang::TemplateArgument &arg_)
      : ast(std::move(ast_)),
        arg(&arg_) {}

  inline TemplateArgument(std::shared_ptr<ASTImpl> ast_,
                          const clang::TemplateArgument *arg_)
      : ast(std::move(ast_)),
        arg(arg_) {}

#ifndef PASTA_IN_BOOTSTRAP
  static std::optional<TemplateArgument> From(const TokenContext &) noexcept;

  inline const void *RawTemplateArgument(void) const noexcept {
    return arg;
  }

  // Return the kind of the stored template argument.
  TemplateArgumentKind Kind(void) const noexcept;

  // Determine whether this template argument has no value.
  //
  // NOTE(pag): This corresponds to `clang::TemplateArgument::isNull`.
  inline bool IsEmpty(void) const noexcept {
    return Kind() == TemplateArgumentKind::kEmpty;
  }

  // TODO(pag): Implement `getDependence` and `TemplateArgumentDependence`.

  // Whether this template argument is dependent on a template
  // parameter such that its result can change from one instantiation to
  // another.
  bool IsDependent(void) const noexcept;

  // Whether this template argument is dependent on a template parameter.
  bool IsInstantiationDependent(void) const noexcept;

  // Whether this template argument contains an unexpanded parameter pack.
  bool ContainsUnexpandedParameterPack(void) const noexcept;

  // Determine whether this template argument is a pack expansion.
  bool IsPackExpansion(void) const noexcept;

  // Retrieve the declaration for a declaration non-type template argument.
  std::optional<ValueDecl> Declaration(void) const noexcept;

  // Retrieve the type for a type template argument.
  std::optional<::pasta::Type> Type(void) const noexcept;

  std::optional<::pasta::Type> ParameterTypeForDeclaration(void) const noexcept;

  std::optional<::pasta::Type> NullPointerType(void) const noexcept;

  // Retrieve the expression for an expression template argument.
  std::optional<::pasta::Expr> Expression(void) const noexcept;

  // Retrieve the number value for an integral template argument if it fits in
  // 64 bits.
  std::optional<llvm::APSInt> Integral(void) const noexcept;

  // Return the template arguments in this pack, or an empty vector if this
  // isn't a pack.
  std::vector<TemplateArgument> PackArguments(void) const noexcept;
#endif
};

class TemplateParameterList {
 private:
  std::shared_ptr<ASTImpl> ast;
  const clang::TemplateParameterList *params;

  friend class ClassTemplatePartialSpecializationDecl;
  friend class ClassTemplateSpecializationDecl;
  friend class CXXConstructorDecl;
  friend class CXXConversionDecl;
  friend class CXXDestructorDecl;
  friend class CXXMethodDecl;
  friend class CXXRecordDecl;
  friend class Decl;
  friend class DecompositionDecl;
  friend class EnumDecl;
  friend class ImplicitParamDecl;
  friend class OMPCapturedExprDecl;
  friend class ParmVarDecl;
  friend class RecordDecl;
  friend class VarTemplatePartialSpecializationDecl;

 public:
  inline TemplateParameterList(std::shared_ptr<ASTImpl> ast_,
                               const clang::TemplateParameterList &params_)
      : ast(std::move(ast_)),
        params(&params_) {}

  inline TemplateParameterList(std::shared_ptr<ASTImpl> ast_,
                               const clang::TemplateParameterList *params_)
      : ast(std::move(ast_)),
        params(params_) {}

#ifndef PASTA_IN_BOOTSTRAP
  static std::optional<TemplateParameterList> From(
      const TokenContext &) noexcept;

  inline const void *RawTemplateParameterList(void) const noexcept {
    return params;
  }

  // Total number of parameters.
  unsigned NumParameters(void) const noexcept;

  // Minimum number of required parameters needed to be explicitly specified
  // by arguments when specializing this template.
  unsigned NumRequiredParameters(void) const noexcept;

  // Get the depth of this template parameter list in the set of
  // template parameter lists.
  //
  // The first template parameter list in a declaration will have depth `0`,
  // the second template parameter list will have depth `1`, etc.
  unsigned Depth(void) const noexcept;

  // Returns `true` if this parameter list contains an unexpanded template
  // parameter pack.
  bool HasUnexpandedParameterPack(void) const noexcept;

  // Returns `true` if this parameter list contains a parameter pack.
  bool HasParameterPack(void) const noexcept;

  // The constraint-expression of the associated requires-clause.
  std::optional<::pasta::Expr> RequiresClause(void) const noexcept;

  ::pasta::Token TemplateKeywordToken(void) const noexcept;
  ::pasta::Token LeftAngleToken(void) const noexcept;
  ::pasta::Token RightAngleToken(void) const noexcept;
  ::pasta::TokenRange Tokens(void) const noexcept;

  std::vector<::pasta::NamedDecl> Parameters(void) const noexcept;

#endif  // PASTA_IN_BOOTSTRAP
};

class CXXCtorInitializer {
 private:
  std::shared_ptr<ASTImpl> ast;
  const clang::CXXCtorInitializer *initializer;

 public:
  inline CXXCtorInitializer(std::shared_ptr<ASTImpl> ast_,
                            const clang::CXXCtorInitializer &initializer_)
      : ast(std::move(ast_)),
        initializer(&initializer_) {}

  inline CXXCtorInitializer(std::shared_ptr<ASTImpl> ast_,
                            const clang::CXXCtorInitializer *initializer_)
      : ast(std::move(ast_)),
        initializer(initializer_) {}

#ifndef PASTA_IN_BOOTSTRAP
  static std::optional<CXXCtorInitializer> From(
      const TokenContext &) noexcept;

  inline const void *RawCXXCtorInitializer(void) const noexcept {
    return initializer;
  }

  bool IsBaseInitializer(void) const noexcept;
  bool IsMemberInitializer(void) const noexcept;
  bool IsAnyMemberInitializer(void) const noexcept;
  bool IsIndirectMemberInitializer(void) const noexcept;
  bool IsInClassMemberInitializer(void) const noexcept;
  bool IsDelegatingInitializer(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
  std::optional<bool> IsBaseVirtual(void) const noexcept;

  std::optional<::pasta::FieldDecl> Member(void) const noexcept;
  std::optional<::pasta::FieldDecl> AnyMember(void) const noexcept;
  std::optional<::pasta::IndirectFieldDecl> IndirectMember(void) const noexcept;
  std::optional<::pasta::Stmt> Initializer(void) const noexcept;

  ::pasta::Token EllipsisToken(void) const noexcept;
  ::pasta::Token MemberToken(void) const noexcept;
  ::pasta::Token LeftAngleToken(void) const noexcept;
  ::pasta::Token RightAngleToken(void) const noexcept;
  ::pasta::TokenRange Tokens(void) const noexcept;

#endif  // PASTA_IN_BOOTSTRAP
};

}  // namespace pasta
