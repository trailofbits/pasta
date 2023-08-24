/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>

#include "Forward.h"

namespace clang {
class Type;
class QualType;
using QualifiedType = Type;
}  // namespace clang
#ifndef PASTA_IN_BOOTSTRAP
namespace pasta {

class AST;
class ASTImpl;

// An explicit exception specification on a function prototype.
class ExceptionSpecification {
 private:
  std::shared_ptr<void> data;
  std::shared_ptr<ASTImpl> ast;

  ExceptionSpecification(void) = delete;

 public:
  ~ExceptionSpecification(void);
  explicit ExceptionSpecification(const FunctionProtoType &type);

  ExceptionSpecification(const ExceptionSpecification &) = default;
  ExceptionSpecification(ExceptionSpecification &&) noexcept = default;

  ExceptionSpecification &operator=(const ExceptionSpecification &) = default;
  ExceptionSpecification &operator=(ExceptionSpecification &&) noexcept = default;

  // Return the kind of this exception specification.
  ExceptionSpecificationType Kind(void) const;

  // Return the list of explicitly-specified exceptions.
  std::vector<Type> Exceptions(void) const;

  // The expression inside of `noexcept`, if this is a computed `noexcept`
  // specification.
  std::optional<Expr> NoExceptExpression(void) const;

  // If this is an unevaluated or uninstantiated `noexcept` then this is the
  // function whose exception specification this is.
  std::optional<FunctionDecl> SourceFunction(void);

  // If this is an unevaluated or uninstantiated `noexcept` then this is the
  // function template whose exception specification this is.
  std::optional<FunctionDecl> SourceTemplate(void);
};

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
