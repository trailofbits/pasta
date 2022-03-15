/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/DeclHead.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclTemplate.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Builder.h"

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP

// Range of the tokens for the specific.
::pasta::TokenRange CXXBaseSpecifier::TokenRange(void) const noexcept {
  auto range = spec->getSourceRange();
  auto begin = ast->RawTokenAt(range.getBegin());
  auto end = ast->RawTokenAt(range.getEnd());
  if (begin && end && begin <= end) {
    return pasta::TokenRange(ast, begin, &(end[1]));
  } else {
    return pasta::TokenRange(ast);
  }
}

// Token of the the base type name. Doesn't include the qualifiers.
::pasta::Token CXXBaseSpecifier::BaseTypeToken(void) const noexcept {
  return ast->TokenAt(spec->getBaseTypeLoc());
}

// Is this a virtual base (using virtual inheritance)?
bool CXXBaseSpecifier::IsVirtual(void) const noexcept {
  return spec->isVirtual();
}

// Kind of the base type. This is either `TagTypeKind::kStruct` or
// `TagTypeKind::kClass`.
TagTypeKind CXXBaseSpecifier::BaseKind(void) const noexcept {
  if (spec->isBaseOfClass()) {
    return TagTypeKind::kClass;
  } else {
    return TagTypeKind::kStruct;
  }
}

// Is this specifier a pack expansion?
bool CXXBaseSpecifier::IsPackExpansion(void) const noexcept {
  return spec->isPackExpansion();
}

// Returns `true` if the constructors from the base class are explicitly
// inherited in the derived class with a `using` declaration.
bool CXXBaseSpecifier::ConstructorsAreInherited(void) const noexcept {
  return spec->getInheritConstructors();
}

// For a pack expansion, determine the location of the ellipsis.
std::optional<Token> CXXBaseSpecifier::Ellipsis(void) const noexcept {
  if (auto tok = ast->RawTokenAt(spec->getEllipsisLoc())) {
    return Token(ast, tok);
  } else {
    return std::nullopt;
  }
}

// Returns the access specifier for this base specifier.
//
// This is the actual base specifier as used for semantic analysis, so
// the result can never be `AccessSpecifier::kNone`. To retrieve the access
// specifier as written in the source code, use `LexicalAccessSpecifier`.
::pasta::AccessSpecifier
CXXBaseSpecifier::SemanticAccessSpecifier(void) const noexcept {
  return static_cast<::pasta::AccessSpecifier>(spec->getAccessSpecifier());
}

// Retrieves the access specifier as written in the source code
// (which may mean that no access specifier was explicitly written).
//
// Use `SemanticAccessSpecifier` to retrieve the access specifier for use in
// semantic analysis.
::pasta::AccessSpecifier
CXXBaseSpecifier::LexicalAccessSpecifier(void) const noexcept {
  return static_cast<::pasta::AccessSpecifier>(
      spec->getAccessSpecifierAsWritten());
}

// Retrieves the type of the base class.
//
// This type will always be an unqualified class type.
::pasta::Type CXXBaseSpecifier::BaseType(void) const noexcept {

  // NOTE(pag): `spec->getType()` can sometimes crash when computing the
  //            unqualified base type.
  auto tsi = spec->getTypeSourceInfo();
  return TypeBuilder::Build(ast, tsi->getType()).UnqualifiedType();
}

// Return the kind of the stored template argument.
TemplateArgumentKind TemplateArgument::Kind(void) const noexcept {
  return static_cast<TemplateArgumentKind>(arg->getKind());
}

// Whether this template argument is dependent on a template
// parameter such that its result can change from one instantiation to
// another.
bool TemplateArgument::IsDependent(void) const noexcept {
  return arg->isDependent();
}

// Whether this template argument is dependent on a template parameter.
bool TemplateArgument::IsInstantiationDependent(void) const noexcept {
  return arg->isInstantiationDependent();
}

// Whether this template argument contains an unexpanded parameter pack.
bool TemplateArgument::ContainsUnexpandedParameterPack(void) const noexcept {
  return arg->containsUnexpandedParameterPack();
}

// Determine whether this template argument is a pack expansion.
bool TemplateArgument::IsPackExpansion(void) const noexcept {
  return arg->isPackExpansion();
}

// Retrieve the declaration for a declaration non-type template argument.
std::optional<ValueDecl> TemplateArgument::AsDeclaration(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kDeclaration) {
    return DeclBuilder::Create<pasta::ValueDecl>(ast, arg->getAsDecl());
  } else {
    return std::nullopt;
  }
}

// Retrieve the type for a type template argument.
std::optional<Type> TemplateArgument::AsType(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kType) {
    return TypeBuilder::Build(ast, arg->getAsType());
  } else {
    return std::nullopt;
  }
}

std::optional<Type>
TemplateArgument::ParameterTypeForDeclaration(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kDeclaration) {
    return TypeBuilder::Build(ast, arg->getParamTypeForDecl());
  } else {
    return std::nullopt;
  }
}

std::optional<Type> TemplateArgument::NullPointerType(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kNullPointer) {
    return TypeBuilder::Build(ast, arg->getNullPtrType());
  } else {
    return std::nullopt;
  }
}

// Total number of parameters.
unsigned TemplateParameterList::NumParameters(void) const noexcept {
  return params->size();
}

// Minimum number of required parameters needed to be explicitly specified
// by arguments when specializing this template.
unsigned TemplateParameterList::NumRequiredParameters(void) const noexcept {
  return params->getMinRequiredArguments();
}

// Get the depth of this template parameter list in the set of
// template parameter lists.
//
// The first template parameter list in a declaration will have depth `0`,
// the second template parameter list will have depth `1`, etc.
unsigned TemplateParameterList::Depth(void) const noexcept {
  return params->getDepth();
}

// Returns `true` if this parameter list contains an unexpanded template
// parameter pack.
bool TemplateParameterList::HasUnexpandedParameterPack(void) const noexcept {
  return params->containsUnexpandedParameterPack();
}

// Returns `true` if this parameter list contains a parameter pack.
bool TemplateParameterList::HasParameterPack(void) const noexcept {
  return params->hasParameterPack();
}

// The constraint-expression of the associated requires-clause.
std::optional<::pasta::Expr>
TemplateParameterList::RequiresClause(void) const noexcept {
  if (auto expr = params->getRequiresClause()) {
    return StmtBuilder::Create<::pasta::Expr>(ast, expr);
  } else {
    return std::nullopt;
  }
}

::pasta::Token TemplateParameterList::TemplateKeywordToken(void) const noexcept {
  return ast->TokenAt(params->getTemplateLoc());
}

::pasta::Token TemplateParameterList::LeftAngleToken(void) const noexcept {
  return ast->TokenAt(params->getLAngleLoc());
}

::pasta::Token TemplateParameterList::RightAngleToken(void) const noexcept {
  return ast->TokenAt(params->getRAngleLoc());
}

::pasta::TokenRange TemplateParameterList::TokenRange(void) const noexcept {
  return ast->TokenRangeFrom(params->getSourceRange());
}

std::vector<::pasta::NamedDecl>
TemplateParameterList::Parameters(void) const noexcept {
  std::vector<::pasta::NamedDecl> ret;
  for (clang::NamedDecl *param : *params) {
    ret.emplace_back(DeclBuilder::Create<pasta::NamedDecl>(ast, param));
  }
  return ret;
}

#endif  // PASTA_IN_BOOTSTRAP

}  // namespace pasta
