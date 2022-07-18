/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/TypeManual.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Type.h>
#pragma clang diagnostic pop

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/Util/Compiler.h>

#include "AST.h"
#include "Builder.h"

#ifndef PASTA_IN_BOOTSTRAP
namespace pasta {
namespace {

#define EXC_PTR reinterpret_cast<const clang::FunctionProtoType::ExceptionSpecInfo *>(data.get())

std::shared_ptr<void> GetExcSpec(const clang::FunctionProtoType *type) {
  return std::make_shared<clang::FunctionProtoType::ExceptionSpecInfo>(
      type->getExceptionSpecInfo());
}

}  // namnespace

ExceptionSpecification::~ExceptionSpecification(void) {}

ExceptionSpecification::ExceptionSpecification(const FunctionProtoType &type)
    : data(GetExcSpec(type.RawType())),
      ast(type.ast) {}


// Return the kind of this exception specification.
ExceptionSpecificationType ExceptionSpecification::Kind(void) const {
  return static_cast<ExceptionSpecificationType>(EXC_PTR->Type);
}

// Return the list of explicitly-specified exceptions.
std::vector<Type> ExceptionSpecification::Exceptions(void) const {
  std::vector<Type> ret;
  for (clang::QualType type : EXC_PTR->Exceptions) {
    ret.emplace_back(TypeBuilder::Build(ast, type));
  }
  return ret;
}

// The expression inside of `noexcept`, if this is a computed `noexcept`
// specification.
std::optional<Expr> ExceptionSpecification::NoExceptExpression(void) const {
  if (const clang::Expr *expr = EXC_PTR->NoexceptExpr) {
    return StmtBuilder::Create<::pasta::Expr>(ast, expr);
  } else {
    return std::nullopt;
  }
}

// If this is an unevaluated or uninstantiated `noexcept` then this is the
// function whose exception specification this is.
std::optional<FunctionDecl> ExceptionSpecification::SourceFunction(void) {
  if (const clang::FunctionDecl *decl = EXC_PTR->SourceDecl) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl);
  } else {
    return std::nullopt;
  }
}

// If this is an unevaluated or uninstantiated `noexcept` then this is the
// function template whose exception specification this is.
std::optional<FunctionDecl> ExceptionSpecification::SourceTemplate(void) {
  if (const clang::FunctionDecl *decl = EXC_PTR->SourceTemplate) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl);
  } else {
    return std::nullopt;
  }
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
