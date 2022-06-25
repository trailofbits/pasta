/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>

#include "Forward.h"

namespace clang {
class CXXBaseSpecifier;
class TemplateArgument;
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
  inline const void *RawCXXBaseSpecifier(void) const noexcept {
    return spec;
  }

  // Range of the tokens for the specific.
  ::pasta::TokenRange Tokens(void) const noexcept;

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
  std::optional<Token> EllipsisToken(void) const noexcept;

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

class Designator {
 private:
  std::shared_ptr<ASTImpl> ast;

  // NOTE(kumarak): This is a placeholder for `clang::DesignatedInitExpr::Designator`.
  //                We can't forward declare `DesignatedInitExpr::Designator`
  const void *spec;
  
  Designator(void) = delete;
  
 public:
  inline Designator(std::shared_ptr<ASTImpl> ast_, const void *spec_)
      : ast(std::move(ast_)), spec(spec_) {}

#ifndef PASTA_IN_BOOTSTRAP
  // Is this a field designator?
  bool IsFieldDesignator(void) const noexcept;

  // Is this an array designator?
  bool IsArrayDesignator(void) const noexcept;

  // Is this an array range designator?
  bool IsArrayRangeDesignator(void) const noexcept;

  // Returns the FieldDecl for the designator. It is only
  // valid when Designator is of type field.
  std::optional<::pasta::FieldDecl> Field(void) const noexcept;

  // Returns the TokenRange for the designator.
  ::pasta::TokenRange Tokens(void) const noexcept;

  // Returns the Token for dot location. It is only valid on
  // field designators.
  ::pasta::Token DotLoc(void) const noexcept;

  // Returns the Field token for the designator. It is only
  // valid for field designators.
  ::pasta::Token FieldLoc(void) const noexcept;

  // Returns the LBracket token. It will be only valid
  // on an array or array-range designators.
  ::pasta::Token LBracketLoc(void) const noexcept;

  // Returns the token for RBracket location. It will be only valid
  // on an array or array-range designators.
  ::pasta::Token RBracketLoc(void) const noexcept;

  // Returns the token for Ellipsis location. It will be only valid
  // on an array-range designators.
  ::pasta::Token EllipsisLoc(void) const noexcept;

  // Returns the index of first designator expression.
  // TODO(kumarak) : It is valid only for array and array range designators
  //                 Should it return signed to avoid return index as 0 if
  //                 the designator type is Field
  unsigned FirstExprIndex(void) const noexcept;
#endif
};

class TemplateArgument {
 private:
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
  inline const void *RawTemplateArgument(void) const noexcept {
    return arg;
  }

  // Return the kind of the stored template argument.
  TemplateArgumentKind Kind(void) const noexcept;

  // Determine whether this template argument has no value.
  inline bool IsNull(void) const noexcept {
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
  std::optional<ValueDecl> AsDeclaration(void) const noexcept;

  // Retrieve the type for a type template argument.
  std::optional<Type> AsType(void) const noexcept;

  std::optional<Type> ParameterTypeForDeclaration(void) const noexcept;

  std::optional<Type> NullPointerType(void) const noexcept;

  // TODO(pag): Others methods.
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

}  // namespace pasta
