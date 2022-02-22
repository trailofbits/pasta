/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/DeclManual.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/DeclCXX.h>
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

/// Retrieves the access specifier as written in the source code
/// (which may mean that no access specifier was explicitly written).
///
/// Use `SemanticAccessSpecifier` to retrieve the access specifier for use in
/// semantic analysis.
::pasta::AccessSpecifier
CXXBaseSpecifier::LexicalAccessSpecifier(void) const noexcept {
  return static_cast<::pasta::AccessSpecifier>(
      spec->getAccessSpecifierAsWritten());
}

// Retrieves the type of the base class.
//
// This type will always be an unqualified class type.
::pasta::Type CXXBaseSpecifier::BaseType(void) const noexcept {
  return TypeBuilder::Build(ast, spec->getType());
}

#endif  // PASTA_IN_BOOTSTRAP

}  // namespace pasta
