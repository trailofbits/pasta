/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>

#include "Forward.h"

namespace clang {
class CXXBaseSpecifier;
}  // namespace clang
namespace pasta {

class ASTImpl;
class PrintedTokenRange;
class CXXRecordDecl;

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
#endif
};

}  // namespace pasta
