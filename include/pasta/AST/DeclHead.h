/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>

#include "Forward.h"

namespace clang {
class CXXBaseSpecifier;
class TemplateParameterList;
}  // namespace clang
namespace pasta {

class ASTImpl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class Decl;
class DecompositionDecl;
class EnumDecl;
class Expr;
class ImplicitParamDecl;
class NamedDecl;
class OMPCapturedExprDecl;
class ParmVarDecl;
class PrintedTokenRange;
class RecordDecl;
class Token;
class VarTemplatePartialSpecializationDecl;

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
  // Range of the tokens for the specific.
  ::pasta::TokenRange TokenRange(void) const noexcept;

  // Token of the the base type name. Doesn't include the qualifiers.
  ::pasta::Token BaseTypeToken(void) const noexcept;

  // Is this a virtual base (using virtual inheritance)?
  bool IsVirtual(void) const noexcept;

  // Kind of the base type. This is either `TagTypeKind::kStruct` or
  // `TagTypeKind::kClass`.
  TagTypeKind BaseKind(void) const noexcept;

  // Is this specifier a pack expansion?
  bool IsPackExpansion(void) const noexcept;

  // Returns `true` if the constructors from the base class are explicitly
  // inherited in the derived class with a `using` declaration.
  bool ConstructorsAreInherited(void) const noexcept;

  // For a pack expansion, determine the location of the ellipsis.
  std::optional<Token> Ellipsis(void) const noexcept;

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
#endif  // PASTA_IN_BOOTSTRAP
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
  ::pasta::TokenRange TokenRange(void) const noexcept;

  std::vector<::pasta::NamedDecl> Parameters(void) const noexcept;

#endif  // PASTA_IN_BOOTSTRAP
};

}  // namespace pasta
