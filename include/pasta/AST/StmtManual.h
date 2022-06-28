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

  inline const void *RawDesignator(void) const noexcept {
    return spec;
  }

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
  ::pasta::Token DotToken(void) const noexcept;

  // Returns the Field token for the designator. It is only
  // valid for field designators.
  ::pasta::Token FieldToken(void) const noexcept;

  // Returns the l-bracket token. It will be only valid
  // on an array or array-range designators.
  ::pasta::Token LeftBracketToken(void) const noexcept;

  // Returns the token for r-bracket location. It will be only valid
  // on an array or array-range designators.
  ::pasta::Token RightBracketToken(void) const noexcept;

  // Returns the token for Ellipsis location. It will be only valid
  // on an array-range designators.
  ::pasta::Token EllipsisToken(void) const noexcept;

  // Returns the index of first designator expression.
  std::optional<unsigned> FirstExpressionIndex(void) const noexcept;
#endif
};

}  // namespace pasta
