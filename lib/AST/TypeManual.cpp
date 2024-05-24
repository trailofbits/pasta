/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/TypeManual.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#include <clang/AST/Type.h>
#include <clang/Frontend/CompilerInstance.h>
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

static std::shared_ptr<void> GetExcSpec(const clang::FunctionProtoType *type) {
  return std::make_shared<clang::FunctionProtoType::ExceptionSpecInfo>(
      type->getExceptionSpecInfo());
}

static bool IsSizedType(clang::QualType self) {
  if (self.isNull()) {
    return false;
  }

  clang::NamedDecl *nd = nullptr;
  auto tp = self.getTypePtr();
  if (tp->isIncompleteType(&nd) || tp->isDependentType() ||
      tp->isUndeducedType() || tp->isUndeducedAutoType()) {
    return false;
  }

  if (auto bt = clang::dyn_cast<clang::BuiltinType>(tp)) {
    switch (bt->getKind()) {
      default:
        return true;
#define BUILTIN_TYPE(...)
#define PLACEHOLDER_TYPE(kind, ty) case clang::BuiltinType::kind: return false;
#include <clang/AST/BuiltinTypes.def>
    }
  } else if (auto dt = clang::dyn_cast<clang::DeducedType>(tp)) {
    if (dt->getDeducedType().isNull()) {
      return false;
    }
  }
  return true;
}

}  // namespace

::pasta::TypeKind Type::Kind(void) const {
  if (qualifiers) {
    return TypeKind::kQualified;
  }
#ifndef NDEBUG
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getTypeClass();
  assert(kind == static_cast<enum ::pasta::TypeKind>(val));
#endif
  return kind;
}

std::string_view Type::KindName(void) const {
  if (qualifiers) {
    return "QualifiedType";
  }

  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getTypeClassName();
  if (val) {
    return std::string_view(val);
  }

  assert(false && "Type::KindName can return nullptr!");
  return std::string_view("");
}

clang::QualType Type::RawQualType(void) const noexcept {
  if (!ast || !u.Type) {
    assert(false);
    return {};
  }

  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  return ast_ctx.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
}

::pasta::Type Type::DesugaredType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getDesugaredType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::CanonicalType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getCanonicalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<uint64_t> Type::SizeInBits(void) const noexcept {
  auto self = RawQualType();
  if (!IsSizedType(self)) {
    return std::nullopt;
  }

  auto &ast_ctx = ast->ci->getASTContext();
  return ast_ctx.getTypeSize(self);
}

std::optional<uint64_t> Type::Alignment(void) const noexcept {
  auto self = RawQualType();
  if (!IsSizedType(self)) {
    return std::nullopt;
  }

  auto &ast_ctx = ast->ci->getASTContext();
  if (auto ret = ast_ctx.getTypeAlignIfKnown(self)) {
    return ret / 8u;
  }

  return std::nullopt;
}

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
  }
  return std::nullopt;
}

// If this is an unevaluated or uninstantiated `noexcept` then this is the
// function whose exception specification this is.
std::optional<FunctionDecl> ExceptionSpecification::SourceFunction(void) {
  if (const clang::FunctionDecl *decl = EXC_PTR->SourceDecl) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl);
  }
  return std::nullopt;
}

// If this is an unevaluated or uninstantiated `noexcept` then this is the
// function template whose exception specification this is.
std::optional<FunctionDecl> ExceptionSpecification::SourceTemplate(void) {
  if (const clang::FunctionDecl *decl = EXC_PTR->SourceTemplate) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl);
  }
  return std::nullopt;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
