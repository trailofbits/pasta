/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#define PASTA_IN_TYPE_CPP
#ifndef PASTA_IN_BOOTSTRAP
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclFriend.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/Frontend/CompilerInstance.h>
#pragma clang diagnostic pop

#include <pasta/AST/Decl.h>
#include <pasta/AST/Type.h>
#include "AST.h"
#include "Builder.h"

#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \
    std::optional<class derived> derived::From(const class base &that) { \
      assert(that.ast.get() != nullptr); \
      if (auto type_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.Type)) { \
        return TypeBuilder::Create<class derived>(that.ast, type_ptr, that.qualifiers); \
      } else { \
        return std::nullopt; \
      } \
    }

#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, that.u.base, that.kind, that.qualifiers) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), that.u.base, that.kind, that.qualifiers) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.Type = that.u.Type; \
      kind = that.kind; \
      qualifiers = that.qualifiers; \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      class derived new_that(std::forward<class derived>(that)); \
      ast = std::move(new_that.ast); \
      u.Type = new_that.u.Type; \
      kind = new_that.kind; \
      qualifiers = new_that.qualifiers; \
      return *this; \
    }

namespace pasta {

TypeVisitor::~TypeVisitor(void) {}

void TypeVisitor::Accept(const Type &type) {
  switch (type.Kind()) {
#define PASTA_VISIT_TYPE(name) \
    case TypeKind::k ## name: \
      Visit ## name ## Type(reinterpret_cast<const name ## Type &>(type)); \
      break;

    PASTA_FOR_EACH_TYPE_KIND(PASTA_VISIT_TYPE)
#undef PASTA_VISIT_TYPE
  }
}

void TypeVisitor::VisitType(const Type &type) {
  (void) type;
}

void TypeVisitor::VisitTypeOfExprType(const TypeOfExprType &type) {
  VisitType(type);
}

void TypeVisitor::VisitTypeOfType(const TypeOfType &type) {
  VisitType(type);
}

void TypeVisitor::VisitTypedefType(const TypedefType &type) {
  VisitType(type);
}

void TypeVisitor::VisitUnaryTransformType(const UnaryTransformType &type) {
  VisitType(type);
}

void TypeVisitor::VisitUnresolvedUsingType(const UnresolvedUsingType &type) {
  VisitType(type);
}

void TypeVisitor::VisitUsingType(const UsingType &type) {
  VisitType(type);
}

void TypeVisitor::VisitVectorType(const VectorType &type) {
  VisitType(type);
}

void TypeVisitor::VisitTypeWithKeyword(const TypeWithKeyword &type) {
  VisitType(type);
}

void TypeVisitor::VisitAdjustedType(const AdjustedType &type) {
  VisitType(type);
}

void TypeVisitor::VisitArrayType(const ArrayType &type) {
  VisitType(type);
}

void TypeVisitor::VisitAtomicType(const AtomicType &type) {
  VisitType(type);
}

void TypeVisitor::VisitAttributedType(const AttributedType &type) {
  VisitType(type);
}

void TypeVisitor::VisitBTFTagAttributedType(const BTFTagAttributedType &type) {
  VisitType(type);
}

void TypeVisitor::VisitBitIntType(const BitIntType &type) {
  VisitType(type);
}

void TypeVisitor::VisitBlockPointerType(const BlockPointerType &type) {
  VisitType(type);
}

void TypeVisitor::VisitBuiltinType(const BuiltinType &type) {
  VisitType(type);
}

void TypeVisitor::VisitComplexType(const ComplexType &type) {
  VisitType(type);
}

void TypeVisitor::VisitConstantArrayType(const ConstantArrayType &type) {
  VisitArrayType(type);
}

void TypeVisitor::VisitDecayedType(const DecayedType &type) {
  VisitAdjustedType(type);
}

void TypeVisitor::VisitDecltypeType(const DecltypeType &type) {
  VisitType(type);
}

void TypeVisitor::VisitDeducedType(const DeducedType &type) {
  VisitType(type);
}

void TypeVisitor::VisitDependentAddressSpaceType(const DependentAddressSpaceType &type) {
  VisitType(type);
}

void TypeVisitor::VisitDependentBitIntType(const DependentBitIntType &type) {
  VisitType(type);
}

void TypeVisitor::VisitDependentNameType(const DependentNameType &type) {
  VisitTypeWithKeyword(type);
}

void TypeVisitor::VisitDependentSizedArrayType(const DependentSizedArrayType &type) {
  VisitArrayType(type);
}

void TypeVisitor::VisitDependentSizedExtVectorType(const DependentSizedExtVectorType &type) {
  VisitType(type);
}

void TypeVisitor::VisitDependentTemplateSpecializationType(const DependentTemplateSpecializationType &type) {
  VisitTypeWithKeyword(type);
}

void TypeVisitor::VisitDependentVectorType(const DependentVectorType &type) {
  VisitType(type);
}

void TypeVisitor::VisitElaboratedType(const ElaboratedType &type) {
  VisitTypeWithKeyword(type);
}

void TypeVisitor::VisitExtVectorType(const ExtVectorType &type) {
  VisitVectorType(type);
}

void TypeVisitor::VisitFunctionType(const FunctionType &type) {
  VisitType(type);
}

void TypeVisitor::VisitIncompleteArrayType(const IncompleteArrayType &type) {
  VisitArrayType(type);
}

void TypeVisitor::VisitInjectedClassNameType(const InjectedClassNameType &type) {
  VisitType(type);
}

void TypeVisitor::VisitMacroQualifiedType(const MacroQualifiedType &type) {
  VisitType(type);
}

void TypeVisitor::VisitMatrixType(const MatrixType &type) {
  VisitType(type);
}

void TypeVisitor::VisitMemberPointerType(const MemberPointerType &type) {
  VisitType(type);
}

void TypeVisitor::VisitObjCObjectPointerType(const ObjCObjectPointerType &type) {
  VisitType(type);
}

void TypeVisitor::VisitObjCObjectType(const ObjCObjectType &type) {
  VisitType(type);
}

void TypeVisitor::VisitObjCTypeParamType(const ObjCTypeParamType &type) {
  VisitType(type);
}

void TypeVisitor::VisitPackExpansionType(const PackExpansionType &type) {
  VisitType(type);
}

void TypeVisitor::VisitParenType(const ParenType &type) {
  VisitType(type);
}

void TypeVisitor::VisitPipeType(const PipeType &type) {
  VisitType(type);
}

void TypeVisitor::VisitPointerType(const PointerType &type) {
  VisitType(type);
}

void TypeVisitor::VisitReferenceType(const ReferenceType &type) {
  VisitType(type);
}

void TypeVisitor::VisitSubstTemplateTypeParmPackType(const SubstTemplateTypeParmPackType &type) {
  VisitType(type);
}

void TypeVisitor::VisitSubstTemplateTypeParmType(const SubstTemplateTypeParmType &type) {
  VisitType(type);
}

void TypeVisitor::VisitTagType(const TagType &type) {
  VisitType(type);
}

void TypeVisitor::VisitTemplateSpecializationType(const TemplateSpecializationType &type) {
  VisitType(type);
}

void TypeVisitor::VisitTemplateTypeParmType(const TemplateTypeParmType &type) {
  VisitType(type);
}

void TypeVisitor::VisitVariableArrayType(const VariableArrayType &type) {
  VisitArrayType(type);
}

void TypeVisitor::VisitAutoType(const AutoType &type) {
  VisitDeducedType(type);
}

void TypeVisitor::VisitConstantMatrixType(const ConstantMatrixType &type) {
  VisitMatrixType(type);
}

void TypeVisitor::VisitDeducedTemplateSpecializationType(const DeducedTemplateSpecializationType &type) {
  VisitDeducedType(type);
}

void TypeVisitor::VisitDependentSizedMatrixType(const DependentSizedMatrixType &type) {
  VisitMatrixType(type);
}

void TypeVisitor::VisitEnumType(const EnumType &type) {
  VisitTagType(type);
}

void TypeVisitor::VisitFunctionNoProtoType(const FunctionNoProtoType &type) {
  VisitFunctionType(type);
}

void TypeVisitor::VisitFunctionProtoType(const FunctionProtoType &type) {
  VisitFunctionType(type);
}

void TypeVisitor::VisitLValueReferenceType(const LValueReferenceType &type) {
  VisitReferenceType(type);
}

void TypeVisitor::VisitObjCInterfaceType(const ObjCInterfaceType &type) {
  VisitObjCObjectType(type);
}

void TypeVisitor::VisitRValueReferenceType(const RValueReferenceType &type) {
  VisitReferenceType(type);
}

void TypeVisitor::VisitRecordType(const RecordType &type) {
  VisitTagType(type);
}

PASTA_DEFINE_DERIVED_OPERATORS(Type, AdjustedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, AtomicType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, AttributedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, AutoType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, BTFTagAttributedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, BitIntType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, BlockPointerType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, BuiltinType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ComplexType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ConstantArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ConstantMatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DecayedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DecltypeType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DeducedTemplateSpecializationType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DeducedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentAddressSpaceType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentBitIntType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentNameType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentSizedArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentSizedExtVectorType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentSizedMatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentTemplateSpecializationType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentVectorType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ElaboratedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, EnumType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ExtVectorType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, FunctionNoProtoType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, FunctionProtoType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, FunctionType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, IncompleteArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, InjectedClassNameType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, LValueReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, MacroQualifiedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, MatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, MemberPointerType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ObjCInterfaceType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ObjCObjectPointerType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ObjCObjectType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ObjCTypeParamType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, PackExpansionType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ParenType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, PipeType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, PointerType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, RValueReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, RecordType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, SubstTemplateTypeParmPackType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, SubstTemplateTypeParmType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TagType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TemplateSpecializationType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TemplateTypeParmType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TypeOfExprType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TypeOfType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TypeWithKeyword)
PASTA_DEFINE_DERIVED_OPERATORS(Type, TypedefType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, UnaryTransformType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, UnresolvedUsingType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, UsingType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, VariableArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, VectorType)
bool Type::AcceptsObjCTypeParameters(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.acceptsObjCTypeParams();
  return val;
  __builtin_unreachable();
}

bool Type::CanDecayToPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.canDecayToPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::CanHaveNullability(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.canHaveNullability();
  return val;
  __builtin_unreachable();
}

bool Type::ContainsErrors(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.containsErrors();
  return val;
  __builtin_unreachable();
}

bool Type::ContainsUnexpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.containsUnexpandedParameterPack();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::Type> Type::ArrayElementTypeNoTypeQualified(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getArrayElementTypeNoTypeQual();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> Type::AsCXXRecordDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsCXXRecordDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ComplexType> Type::AsComplexIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsComplexIntegerType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ComplexType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCInterfacePointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCInterfacePointerType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ObjCObjectType> Type::AsObjCInterfaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCInterfaceType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCQualifiedClassType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCQualifiedClassType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCQualifiedIdType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCQualifiedIdType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ObjCObjectType> Type::AsObjCQualifiedInterfaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCQualifiedInterfaceType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::BuiltinType> Type::AsPlaceholderType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsPlaceholderType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::BuiltinType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::RecordDecl> Type::AsRecordDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsRecordDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::RecordType> Type::AsStructureType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsStructureType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::RecordType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::TagDecl> Type::AsTagDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsTagDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::RecordType> Type::AsUnionType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsUnionType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::RecordType>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Type Type::CanonicalTypeInternal(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getCanonicalTypeInternal();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: Type::CanonicalTypeUnqualified
std::optional<::pasta::AutoType> Type::ContainedAutoType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getContainedAutoType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::AutoType>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::DeducedType> Type::ContainedDeducedType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getContainedDeducedType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::DeducedType>(ast, val);
  }
  __builtin_unreachable();
}

// 0: Type::Dependence
enum Linkage Type::Linkage(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getLinkage();
  return static_cast<::pasta::Linkage>(val);
  __builtin_unreachable();
}

// 0: Type::LinkageAndVisibility
::pasta::Type Type::LocallyUnqualifiedSingleStepDesugaredType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getLocallyUnqualifiedSingleStepDesugaredType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::NullabilityKind> Type::Nullability(void) const noexcept {
  auto &self = *(u.Type);
  decltype(auto) val = self.getNullability(ast->ci->getASTContext());
  if (val.hasValue()) {
    return static_cast<::pasta::NullabilityKind>(val.getValue());
  } else {
    return std::nullopt;
  }
  __builtin_unreachable();
}

// 0: Type::ObjCARCImplicitLifetime
// 1: Type::ObjCSubstitutions
std::optional<::pasta::CXXRecordDecl> Type::PointeeCXXRecordDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getPointeeCXXRecordDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Type> Type::PointeeOrArrayElementType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getPointeeOrArrayElementType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Type> Type::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getPointeeType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<enum TypeScalarTypeKind> Type::ScalarTypeKind(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (!self.isScalarType()) {
    return std::nullopt;
  } else {
    const clang::Type *t = self.getCanonicalTypeInternal().getTypePtr();
    if (const clang::EnumType *et = clang::dyn_cast<clang::EnumType>(t)) {
      if (!et->getDecl()->isComplete()) {
        return std::nullopt;
      }
    }
  }
  decltype(auto) val = self.getScalarTypeKind();
  return static_cast<::pasta::TypeScalarTypeKind>(val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> Type::SveElementType(void) const noexcept {
  auto &self = *(u.Type);
  if (!self.isVLSTBuiltinType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getSveEltType(ast->ci->getASTContext());
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TypeKind Type::Kind(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getTypeClass();
  return static_cast<enum ::pasta::TypeKind>(val);
  __builtin_unreachable();
}

std::string_view Type::KindName(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getTypeClassName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Type::KindName can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type Type::UnqualifiedDesugaredType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getUnqualifiedDesugaredType();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "Type::UnqualifiedDesugaredType can return nullptr!");
  __builtin_unreachable();
}

enum Visibility Type::Visibility(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::Visibility>(val);
  __builtin_unreachable();
}

// 1: Type::HasAttribute
bool Type::HasAutoForTrailingReturnType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasAutoForTrailingReturnType();
  return val;
  __builtin_unreachable();
}

bool Type::HasFloatingRepresentation(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasFloatingRepresentation();
  return val;
  __builtin_unreachable();
}

bool Type::HasIntegerRepresentation(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasIntegerRepresentation();
  return val;
  __builtin_unreachable();
}

bool Type::HasObjCPointerRepresentation(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasObjCPointerRepresentation();
  return val;
  __builtin_unreachable();
}

bool Type::HasPointerRepresentation(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasPointerRepresentation();
  return val;
  __builtin_unreachable();
}

bool Type::HasSignedIntegerRepresentation(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasSignedIntegerRepresentation();
  return val;
  __builtin_unreachable();
}

bool Type::HasSizedVLAType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasSizedVLAType();
  return val;
  __builtin_unreachable();
}

bool Type::HasUnnamedOrLocalType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasUnnamedOrLocalType();
  return val;
  __builtin_unreachable();
}

bool Type::HasUnsignedIntegerRepresentation(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasUnsignedIntegerRepresentation();
  return val;
  __builtin_unreachable();
}

std::optional<bool> Type::IsAggregateType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (auto klass = self.getAsCXXRecordDecl()) {
    if (!klass->getDefinition()) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.isAggregateType();
  return val;
  __builtin_unreachable();
}

bool Type::IsAlignValueT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAlignValT();
  return val;
  __builtin_unreachable();
}

bool Type::IsAnyCharacterType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAnyCharacterType();
  return val;
  __builtin_unreachable();
}

bool Type::IsAnyComplexType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAnyComplexType();
  return val;
  __builtin_unreachable();
}

bool Type::IsAnyPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAnyPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsArithmeticType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isArithmeticType();
  return val;
  __builtin_unreachable();
}

bool Type::IsArrayType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isArrayType();
  return val;
  __builtin_unreachable();
}

bool Type::IsAtomicType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAtomicType();
  return val;
  __builtin_unreachable();
}

bool Type::IsBFloat16Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBFloat16Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsBitIntType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBitIntType();
  return val;
  __builtin_unreachable();
}

bool Type::IsBlockCompatibleObjCPointerType(void) const noexcept {
  auto &self = *(u.Type);
  decltype(auto) val = self.isBlockCompatibleObjCPointerType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsBlockPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBlockPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsBooleanType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBooleanType();
  return val;
  __builtin_unreachable();
}

bool Type::IsBuiltinType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBuiltinType();
  return val;
  __builtin_unreachable();
}

bool Type::IsCARCBridgableType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCARCBridgableType();
  return val;
  __builtin_unreachable();
}

bool Type::IsCUDADeviceBuiltinSurfaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCUDADeviceBuiltinSurfaceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsCUDADeviceBuiltinTextureType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCUDADeviceBuiltinTextureType();
  return val;
  __builtin_unreachable();
}

bool Type::IsCanonicalUnqualified(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCanonicalUnqualified();
  return val;
  __builtin_unreachable();
}

bool Type::IsChar16Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isChar16Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsChar32Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isChar32Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsChar8Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isChar8Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsCharacterType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCharType();
  return val;
  __builtin_unreachable();
}

bool Type::IsClassType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isClassType();
  return val;
  __builtin_unreachable();
}

bool Type::IsClkEventT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isClkEventT();
  return val;
  __builtin_unreachable();
}

bool Type::IsComplexIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isComplexIntegerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsComplexType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isComplexType();
  return val;
  __builtin_unreachable();
}

bool Type::IsCompoundType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCompoundType();
  return val;
  __builtin_unreachable();
}

bool Type::IsConstantArrayType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isConstantArrayType();
  return val;
  __builtin_unreachable();
}

bool Type::IsConstantMatrixType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isConstantMatrixType();
  return val;
  __builtin_unreachable();
}

std::optional<bool> Type::IsConstantSizeType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (self.isIncompleteType() || self.isDependentType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isConstantSizeType();
  return val;
  __builtin_unreachable();
}

bool Type::IsDecltypeType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDecltypeType();
  return val;
  __builtin_unreachable();
}

bool Type::IsDependentAddressSpaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDependentAddressSpaceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsDependentSizedArrayType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDependentSizedArrayType();
  return val;
  __builtin_unreachable();
}

bool Type::IsDependentType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDependentType();
  return val;
  __builtin_unreachable();
}

bool Type::IsElaboratedTypeSpecifier(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isElaboratedTypeSpecifier();
  return val;
  __builtin_unreachable();
}

bool Type::IsEnumeralType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isEnumeralType();
  return val;
  __builtin_unreachable();
}

bool Type::IsEventT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isEventT();
  return val;
  __builtin_unreachable();
}

bool Type::IsExtVectorBooleanType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isExtVectorBoolType();
  return val;
  __builtin_unreachable();
}

bool Type::IsExtVectorType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isExtVectorType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFixedPointOrIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFixedPointOrIntegerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFixedPointType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFixedPointType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFloat128Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFloat128Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsFloat16Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFloat16Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsFloatingType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFloatingType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFromAST(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFromAST();
  return val;
  __builtin_unreachable();
}

bool Type::IsFunctionNoProtoType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionNoProtoType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFunctionPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFunctionProtoType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionProtoType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFunctionReferenceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionReferenceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFunctionType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionType();
  return val;
  __builtin_unreachable();
}

bool Type::IsFundamentalType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFundamentalType();
  return val;
  __builtin_unreachable();
}

bool Type::IsHalfType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isHalfType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIbm128Type(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIbm128Type();
  return val;
  __builtin_unreachable();
}

bool Type::IsImageType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isImageType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIncompleteArrayType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIncompleteArrayType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIncompleteOrObjectType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIncompleteOrObjectType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIncompleteType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIncompleteType();
  return val;
  __builtin_unreachable();
}

bool Type::IsInstantiationDependentType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isInstantiationDependentType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIntegerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIntegralOrEnumerationType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIntegralOrEnumerationType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIntegralOrUnscopedEnumerationType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIntegralOrUnscopedEnumerationType();
  return val;
  __builtin_unreachable();
}

bool Type::IsIntegralType(void) const noexcept {
  auto &self = *(u.Type);
  decltype(auto) val = self.isIntegralType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsInterfaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isInterfaceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsLValueReferenceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isLValueReferenceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsLinkageValid(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isLinkageValid();
  return val;
  __builtin_unreachable();
}

std::optional<bool> Type::IsLiteralType(void) const noexcept {
  auto &self = *(u.Type);
  if (self.isDependentType()) {
    return false;
  } else {
    auto &c = ast->ci->getASTContext();
    if (c.getLangOpts().CPlusPlus14 && self.isVoidType()) {
      return true;
    } else if (self.isVariableArrayType()) {
      return false;
    } else if (!self.getBaseElementTypeUnsafe()) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.isLiteralType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsMatrixType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMatrixType();
  return val;
  __builtin_unreachable();
}

bool Type::IsMemberDataPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMemberDataPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsMemberFunctionPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMemberFunctionPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsMemberPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMemberPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsNonOverloadPlaceholderType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isNonOverloadPlaceholderType();
  return val;
  __builtin_unreachable();
}

bool Type::IsNothrowT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isNothrowT();
  return val;
  __builtin_unreachable();
}

bool Type::IsNullPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isNullPtrType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLExtOpaqueType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLExtOpaqueType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dArrayROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dArrayROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dArrayRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dArrayRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dArrayWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dArrayWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dBufferROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dBufferROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dBufferRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dBufferRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dBufferWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dBufferWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage1dWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayDepthROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayDepthROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayDepthRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayDepthRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayDepthWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayDepthWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayMSAADepthROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAADepthROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayMSAADepthRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAADepthRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayMSAADepthWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAADepthWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayMSAAROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAAROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayMSAARWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAARWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayMSAAWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAAWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dArrayWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dDepthROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dDepthROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dDepthRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dDepthRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dDepthWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dDepthWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dMSAADepthROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAADepthROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dMSAADepthRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAADepthRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dMSAADepthWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAADepthWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dMSAAROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAAROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dMSAARWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAARWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dMSAAWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAAWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage2dWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage3dROType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage3dROType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage3dRWType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage3dRWType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLImage3dWOType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage3dWOType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCImeDualReferenceStreaminType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeDualRefStreaminType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCImePayloadType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImePayloadType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeResultDualRefStreamoutType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeResultSingleRefStreamoutType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCImeResultType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeResultType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeSingleRefStreaminType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCMcePayloadType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCMcePayloadType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCMceResultType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCMceResultType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCRefPayloadType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCRefPayloadType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCRefResultType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCRefResultType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCSicPayloadType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCSicPayloadType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCSicResultType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCSicResultType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOCLIntelSubgroupAVCType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCARCBridgableType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCARCBridgableType();
  return val;
  __builtin_unreachable();
}

std::optional<bool> Type::IsObjCARCImplicitlyUnretainedType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (!self.isObjCLifetimeType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isObjCARCImplicitlyUnretainedType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCBoxableRecordType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCBoxableRecordType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCBuiltinType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCBuiltinType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCClassOrClassKindOfType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCClassOrClassKindOfType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCClassType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCClassType();
  return val;
  __builtin_unreachable();
}

// 2: IsObjCIdOrObjectKindOfType
bool Type::IsObjCIdType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCIdType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCIndependentClassType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCIndependentClassType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCIndirectLifetimeType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCIndirectLifetimeType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCInertUnsafeUnretainedType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCInertUnsafeUnretainedType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCLifetimeType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCLifetimeType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCNSObjectType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCNSObjectType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCObjectOrInterfaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCObjectOrInterfaceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCObjectPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCObjectPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCObjectType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCObjectType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCQualifiedClassType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCQualifiedClassType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCQualifiedIdType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCQualifiedIdType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCQualifiedInterfaceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCQualifiedInterfaceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCRetainableType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCRetainableType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCSelType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCSelType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjectPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjectPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjectType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjectType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOpenCLSpecificType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOpenCLSpecificType();
  return val;
  __builtin_unreachable();
}

bool Type::IsOverloadableType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOverloadableType();
  return val;
  __builtin_unreachable();
}

bool Type::IsPipeType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPipeType();
  return val;
  __builtin_unreachable();
}

bool Type::IsPlaceholderType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPlaceholderType();
  return val;
  __builtin_unreachable();
}

bool Type::IsPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsPromotableIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPromotableIntegerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsQueueT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isQueueT();
  return val;
  __builtin_unreachable();
}

bool Type::IsRValueReferenceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRValueReferenceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsRealFloatingType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRealFloatingType();
  return val;
  __builtin_unreachable();
}

bool Type::IsRealType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRealType();
  return val;
  __builtin_unreachable();
}

bool Type::IsRecordType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRecordType();
  return val;
  __builtin_unreachable();
}

bool Type::IsReferenceType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isReferenceType();
  return val;
  __builtin_unreachable();
}

bool Type::IsReserveIDT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isReserveIDT();
  return val;
  __builtin_unreachable();
}

bool Type::IsSamplerT(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSamplerT();
  return val;
  __builtin_unreachable();
}

bool Type::IsSaturatedFixedPointType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSaturatedFixedPointType();
  return val;
  __builtin_unreachable();
}

bool Type::IsScalarType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isScalarType();
  return val;
  __builtin_unreachable();
}

bool Type::IsScopedEnumeralType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isScopedEnumeralType();
  return val;
  __builtin_unreachable();
}

bool Type::IsSignedFixedPointType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSignedFixedPointType();
  return val;
  __builtin_unreachable();
}

bool Type::IsSignedIntegerOrEnumerationType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSignedIntegerOrEnumerationType();
  return val;
  __builtin_unreachable();
}

bool Type::IsSignedIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSignedIntegerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsSizelessBuiltinType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSizelessBuiltinType();
  return val;
  __builtin_unreachable();
}

bool Type::IsSizelessType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSizelessType();
  return val;
  __builtin_unreachable();
}

// 1: Type::IsSpecificBuiltinType
// 1: Type::IsSpecificPlaceholderType
bool Type::IsSpecifierType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSpecifierType();
  return val;
  __builtin_unreachable();
}

std::optional<bool> Type::IsStandardLayoutType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (self.isDependentType()) {
    return false;
  } else if (!self.getBaseElementTypeUnsafe()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isStandardLayoutType();
  return val;
  __builtin_unreachable();
}

bool Type::IsStdByteType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isStdByteType();
  return val;
  __builtin_unreachable();
}

std::optional<bool> Type::IsStructuralType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (auto klass = self.getAsCXXRecordDecl()) {
    if (!klass->getDefinition()) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.isStructuralType();
  return val;
  __builtin_unreachable();
}

bool Type::IsStructureOrClassType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isStructureOrClassType();
  return val;
  __builtin_unreachable();
}

bool Type::IsStructureType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isStructureType();
  return val;
  __builtin_unreachable();
}

bool Type::IsTemplateTypeParmType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isTemplateTypeParmType();
  return val;
  __builtin_unreachable();
}

bool Type::IsTypedefNameType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isTypedefNameType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUndeducedAutoType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUndeducedAutoType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUndeducedType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUndeducedType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUnionType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnionType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUnsaturatedFixedPointType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsaturatedFixedPointType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUnscopedEnumerationType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnscopedEnumerationType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUnsignedFixedPointType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsignedFixedPointType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUnsignedIntegerOrEnumerationType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsignedIntegerOrEnumerationType();
  return val;
  __builtin_unreachable();
}

bool Type::IsUnsignedIntegerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsignedIntegerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsVLSTBuiltinType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVLSTBuiltinType();
  return val;
  __builtin_unreachable();
}

bool Type::IsVariableArrayType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVariableArrayType();
  return val;
  __builtin_unreachable();
}

bool Type::IsVariablyModifiedType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVariablyModifiedType();
  return val;
  __builtin_unreachable();
}

bool Type::IsVectorType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVectorType();
  return val;
  __builtin_unreachable();
}

bool Type::IsVisibilityExplicit(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVisibilityExplicit();
  return val;
  __builtin_unreachable();
}

bool Type::IsVoidPointerType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVoidPointerType();
  return val;
  __builtin_unreachable();
}

bool Type::IsVoidType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVoidType();
  return val;
  __builtin_unreachable();
}

bool Type::IsWideCharacterType(void) const noexcept {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isWideCharType();
  return val;
  __builtin_unreachable();
}

::pasta::Type Type::IgnoreParentheses(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.IgnoreParens();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

enum LangAS Type::AddressSpace(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getAddressSpace();
  return static_cast<::pasta::LangAS>(val);
  __builtin_unreachable();
}

// 0: Type::
::pasta::Type Type::AtomicUnqualifiedType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getAtomicUnqualifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: Type::BaseTypeIdentifier
uint32_t Type::CVRQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getCVRQualifiers();
  return val;
  __builtin_unreachable();
}

::pasta::Type Type::CanonicalType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getCanonicalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type Type::DesugaredType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getDesugaredType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

uint32_t Type::LocalCVRQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getLocalCVRQualifiers();
  return val;
  __builtin_unreachable();
}

uint32_t Type::LocalFastQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getLocalFastQualifiers();
  return val;
  __builtin_unreachable();
}

// 0: Type::LocalQualifiers
::pasta::Type Type::LocalUnqualifiedType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getLocalUnqualifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type Type::NonLValueExpressionType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getNonLValueExprType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type Type::NonPackExpansionType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getNonPackExpansionType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type Type::NonReferenceType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getNonReferenceType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: Type::ObjCGCAttr
// 0: Type::ObjCLifetime
// 0: Type::Qualifiers
::pasta::Type Type::SingleStepDesugaredType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.getSingleStepDesugaredType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: Type::SplitDesugaredType
// 0: Type::SplitUnqualifiedType
// 0: Type::
// 0: Type::
// 0: Type::
bool Type::HasAddressSpace(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasAddressSpace();
  return val;
  __builtin_unreachable();
}

bool Type::HasLocalNonFastQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasLocalNonFastQualifiers();
  return val;
  __builtin_unreachable();
}

bool Type::HasLocalQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasLocalQualifiers();
  return val;
  __builtin_unreachable();
}

bool Type::HasNonTrivialObjCLifetime(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasNonTrivialObjCLifetime();
  return val;
  __builtin_unreachable();
}

bool Type::HasNonTrivialToPrimitiveCopyCUnion(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
  __builtin_unreachable();
}

bool Type::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
  __builtin_unreachable();
}

bool Type::HasNonTrivialToPrimitiveDestructCUnion(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
  __builtin_unreachable();
}

bool Type::HasQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasQualifiers();
  return val;
  __builtin_unreachable();
}

bool Type::HasStrongOrWeakObjCLifetime(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.hasStrongOrWeakObjCLifetime();
  return val;
  __builtin_unreachable();
}

// 1: Type::IsAddressSpaceOverlapping
// 1: Type::IsAtLeastAsQualifiedAs
bool Type::IsCForbiddenLValueType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isCForbiddenLValueType();
  return val;
  __builtin_unreachable();
}

bool Type::IsCXX11PODType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isCXX11PODType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsCXX98PODType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isCXX98PODType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsCanonical(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isCanonical();
  return val;
  __builtin_unreachable();
}

bool Type::IsCanonicalAsParameter(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isCanonicalAsParam();
  return val;
  __builtin_unreachable();
}

bool Type::IsConstQualified(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isConstQualified();
  return val;
  __builtin_unreachable();
}

bool Type::IsConstant(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isConstant(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

enum QualTypeDestructionKind Type::IsDestructedType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isDestructedType();
  return static_cast<::pasta::QualTypeDestructionKind>(val);
  __builtin_unreachable();
}

bool Type::IsLocalConstQualified(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isLocalConstQualified();
  return val;
  __builtin_unreachable();
}

bool Type::IsLocalRestrictQualified(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isLocalRestrictQualified();
  return val;
  __builtin_unreachable();
}

bool Type::IsLocalVolatileQualified(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isLocalVolatileQualified();
  return val;
  __builtin_unreachable();
}

// 1: Type::IsMoreQualifiedThan
enum QualTypePrimitiveCopyKind Type::IsNonTrivialToPrimitiveCopy(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isNonTrivialToPrimitiveCopy();
  return static_cast<::pasta::QualTypePrimitiveCopyKind>(val);
  __builtin_unreachable();
}

enum QualTypePrimitiveDefaultInitializeKind Type::IsNonTrivialToPrimitiveDefaultInitialize(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isNonTrivialToPrimitiveDefaultInitialize();
  return static_cast<::pasta::QualTypePrimitiveDefaultInitializeKind>(val);
  __builtin_unreachable();
}

enum QualTypePrimitiveCopyKind Type::IsNonTrivialToPrimitiveDestructiveMove(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isNonTrivialToPrimitiveDestructiveMove();
  return static_cast<::pasta::QualTypePrimitiveCopyKind>(val);
  __builtin_unreachable();
}

bool Type::IsNonWeakInMRRWithObjCWeak(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isNonWeakInMRRWithObjCWeak(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsNull(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isNull();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCGCStrong(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isObjCGCStrong();
  return val;
  __builtin_unreachable();
}

bool Type::IsObjCGCWeak(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isObjCGCWeak();
  return val;
  __builtin_unreachable();
}

bool Type::IsPODType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isPODType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsRestrictQualified(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isRestrictQualified();
  return val;
  __builtin_unreachable();
}

bool Type::IsTrivialType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isTrivialType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsTriviallyCopyableType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isTriviallyCopyableType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsTriviallyRelocatableType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isTriviallyRelocatableType(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool Type::IsVolatileQualified(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.isVolatileQualified();
  return val;
  __builtin_unreachable();
}

bool Type::MayBeDynamicClass(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.mayBeDynamicClass();
  return val;
  __builtin_unreachable();
}

bool Type::MayBeNotDynamicClass(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.mayBeNotDynamicClass();
  return val;
  __builtin_unreachable();
}

// 0: Type::Split
// 1: Type::Stream
::pasta::Type Type::StripObjCKindOfType(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.stripObjCKindOfType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 3: QualType::SubstObjCMemberType
// 3: QualType::SubstObjCTypeArguments
// 1: Type::WithCVRQualifiers
::pasta::Type Type::WithConst(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.withConst();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 1: Type::WithExactLocalFastQualifiers
// 1: Type::WithFastQualifiers
::pasta::Type Type::WithRestrict(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.withRestrict();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type Type::WithVolatile(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.withVolatile();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type Type::WithoutLocalFastQualifiers(void) const noexcept {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  decltype(auto) val = self.withoutLocalFastQualifiers();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypeOfExprType)
::pasta::Type TypeOfExprType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Expr TypeOfExprType::UnderlyingExpression(void) const noexcept {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.getUnderlyingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "TypeOfExprType::UnderlyingExpression can return nullptr!");
  __builtin_unreachable();
}

bool TypeOfExprType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypeOfType)
::pasta::Type TypeOfType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type TypeOfType::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool TypeOfType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypedefType)
::pasta::Type TypedefType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TypedefNameDecl TypedefType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TypedefType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool TypedefType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, UnaryTransformType)
::pasta::Type UnaryTransformType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type UnaryTransformType::BaseType(void) const noexcept {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.getBaseType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

enum UnaryTransformTypeUTTKind UnaryTransformType::UTTKind(void) const noexcept {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.getUTTKind();
  return static_cast<::pasta::UnaryTransformTypeUTTKind>(val);
  __builtin_unreachable();
}

::pasta::Type UnaryTransformType::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool UnaryTransformType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, UnresolvedUsingType)
::pasta::Type UnresolvedUsingType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingType *>(u.UnresolvedUsingType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingType *>(u.UnresolvedUsingType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool UnresolvedUsingType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingType *>(u.UnresolvedUsingType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, UsingType)
::pasta::Type UsingType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::UsingShadowDecl UsingType::FoundDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.getFoundDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingType::FoundDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type UsingType::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool UsingType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, VectorType)
PASTA_DEFINE_DERIVED_OPERATORS(VectorType, ExtVectorType)
::pasta::Type VectorType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type VectorType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

uint32_t VectorType::NumElements(void) const noexcept {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.getNumElements();
  return val;
  __builtin_unreachable();
}

enum VectorTypeVectorKind VectorType::VectorKind(void) const noexcept {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.getVectorKind();
  return static_cast<::pasta::VectorTypeVectorKind>(val);
  __builtin_unreachable();
}

bool VectorType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

std::optional<class TypeWithKeyword> TypeWithKeyword::From(const class Type &that) {
  if (auto type_ptr1 = clang::dyn_cast<clang::DependentNameType>(that.u.Type)) {
    return TypeBuilder::Create<class TypeWithKeyword>(that.ast, type_ptr1);
  } else if (auto type_ptr2 = clang::dyn_cast<clang::DependentTemplateSpecializationType>(that.u.Type)) {
    return TypeBuilder::Create<class TypeWithKeyword>(that.ast, type_ptr2);
  } else if (auto type_ptr3 = clang::dyn_cast<clang::ElaboratedType>(that.u.Type)) {
    return TypeBuilder::Create<class TypeWithKeyword>(that.ast, type_ptr3);
  } else {
    return std::nullopt;
  }
}

PASTA_DEFINE_DERIVED_OPERATORS(TypeWithKeyword, DependentNameType)
PASTA_DEFINE_DERIVED_OPERATORS(TypeWithKeyword, DependentTemplateSpecializationType)
PASTA_DEFINE_DERIVED_OPERATORS(TypeWithKeyword, ElaboratedType)
enum ElaboratedTypeKeyword TypeWithKeyword::Keyword(void) const noexcept {
  auto &self = *const_cast<clang::TypeWithKeyword *>(u.TypeWithKeyword);
  decltype(auto) val = self.getKeyword();
  return static_cast<::pasta::ElaboratedTypeKeyword>(val);
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, AdjustedType)
PASTA_DEFINE_DERIVED_OPERATORS(AdjustedType, DecayedType)
::pasta::Type AdjustedType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type AdjustedType::ResolvedType(void) const noexcept {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.getAdjustedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type AdjustedType::OriginalType(void) const noexcept {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.getOriginalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool AdjustedType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, ConstantArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, DependentSizedArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, IncompleteArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, VariableArrayType)
::pasta::Type ArrayType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::ArrayType *>(u.ArrayType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

uint32_t ArrayType::IndexTypeCVRQualifiers(void) const noexcept {
  auto &self = *const_cast<clang::ArrayType *>(u.ArrayType);
  decltype(auto) val = self.getIndexTypeCVRQualifiers();
  return val;
  __builtin_unreachable();
}

// 0: ArrayType::IndexTypeQualifiers
enum ArrayTypeArraySizeModifier ArrayType::SizeModifier(void) const noexcept {
  auto &self = *const_cast<clang::ArrayType *>(u.ArrayType);
  decltype(auto) val = self.getSizeModifier();
  return static_cast<::pasta::ArrayTypeArraySizeModifier>(val);
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, AtomicType)
::pasta::Type AtomicType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::AtomicType *>(u.AtomicType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type AtomicType::ValueType(void) const noexcept {
  auto &self = *const_cast<clang::AtomicType *>(u.AtomicType);
  decltype(auto) val = self.getValueType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool AtomicType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::AtomicType *>(u.AtomicType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, AttributedType)
::pasta::Type AttributedType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

enum ::pasta::AttrKind AttributedType::AttributeKind(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getAttrKind();
  return static_cast<enum ::pasta::AttrKind>(val);
  __builtin_unreachable();
}

::pasta::Type AttributedType::EquivalentType(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getEquivalentType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::NullabilityKind> AttributedType::ImmediateNullability(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getImmediateNullability();
  if (val.hasValue()) {
    return static_cast<::pasta::NullabilityKind>(val.getValue());
  } else {
    return std::nullopt;
  }
  __builtin_unreachable();
}

::pasta::Type AttributedType::ModifiedType(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getModifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool AttributedType::IsCallingConv(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isCallingConv();
  return val;
  __builtin_unreachable();
}

bool AttributedType::IsMSTypeSpec(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isMSTypeSpec();
  return val;
  __builtin_unreachable();
}

bool AttributedType::IsQualifier(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isQualifier();
  return val;
  __builtin_unreachable();
}

bool AttributedType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, BTFTagAttributedType)
::pasta::Type BTFTagAttributedType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::BTFTypeTagAttr BTFTagAttributedType::Attribute(void) const noexcept {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.getAttr();
  if (val) {
    return AttrBuilder::Create<::pasta::BTFTypeTagAttr>(ast, val);
  }
  assert(false && "BTFTagAttributedType::Attribute can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type BTFTagAttributedType::WrappedType(void) const noexcept {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.getWrappedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool BTFTagAttributedType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, BitIntType)
::pasta::Type BitIntType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

uint32_t BitIntType::NumBits(void) const noexcept {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.getNumBits();
  return val;
  __builtin_unreachable();
}

bool BitIntType::IsSigned(void) const noexcept {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.isSigned();
  return val;
  __builtin_unreachable();
}

bool BitIntType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool BitIntType::IsUnsigned(void) const noexcept {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.isUnsigned();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, BlockPointerType)
::pasta::Type BlockPointerType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::BlockPointerType *>(u.BlockPointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type BlockPointerType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::BlockPointerType *>(u.BlockPointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool BlockPointerType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::BlockPointerType *>(u.BlockPointerType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, BuiltinType)
::pasta::Type BuiltinType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::BuiltinTypeKind BuiltinType::Kind(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::BuiltinTypeKind>(val);
  __builtin_unreachable();
}

// 1: BuiltinType::Name
// 1: BuiltinType::NameAsCString
bool BuiltinType::IsFloatingPoint(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isFloatingPoint();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsInteger(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isInteger();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsNonOverloadPlaceholderType(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isNonOverloadPlaceholderType();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsPlaceholderType(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isPlaceholderType();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsSVEBool(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSVEBool();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsSignedInteger(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSignedInteger();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool BuiltinType::IsUnsignedInteger(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isUnsignedInteger();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ComplexType)
::pasta::Type ComplexType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ComplexType *>(u.ComplexType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type ComplexType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::ComplexType *>(u.ComplexType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool ComplexType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ComplexType *>(u.ComplexType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, ConstantArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, ConstantArrayType)
::pasta::Type ConstantArrayType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

llvm::APInt ConstantArrayType::Size(void) const noexcept {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.getSize();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::Expr> ConstantArrayType::SizeExpression(void) const noexcept {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.getSizeExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

bool ConstantArrayType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(AdjustedType, DecayedType)
PASTA_DEFINE_BASE_OPERATORS(Type, DecayedType)
::pasta::Type DecayedType::ResolvedType(void) const noexcept {
  auto &self = *const_cast<clang::DecayedType *>(u.DecayedType);
  decltype(auto) val = self.getDecayedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type DecayedType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::DecayedType *>(u.DecayedType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DecltypeType)
::pasta::Type DecltypeType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Expr DecltypeType::UnderlyingExpression(void) const noexcept {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.getUnderlyingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DecltypeType::UnderlyingExpression can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type DecltypeType::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool DecltypeType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DeducedType)
PASTA_DEFINE_DERIVED_OPERATORS(DeducedType, AutoType)
PASTA_DEFINE_DERIVED_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
::pasta::Type DeducedType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> DeducedType::ResolvedType(void) const noexcept {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.getDeducedType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool DeducedType::IsDeduced(void) const noexcept {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.isDeduced();
  return val;
  __builtin_unreachable();
}

bool DeducedType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentAddressSpaceType)
::pasta::Type DependentAddressSpaceType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Expr DependentAddressSpaceType::AddressSpaceExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.getAddrSpaceExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentAddressSpaceType::AddressSpaceExpression can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DependentAddressSpaceType::AttributeToken(void) const noexcept {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type DependentAddressSpaceType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool DependentAddressSpaceType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentBitIntType)
::pasta::Type DependentBitIntType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Expr DependentBitIntType::NumBitsExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.getNumBitsExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentBitIntType::NumBitsExpression can return nullptr!");
  __builtin_unreachable();
}

bool DependentBitIntType::IsSigned(void) const noexcept {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.isSigned();
  return val;
  __builtin_unreachable();
}

bool DependentBitIntType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool DependentBitIntType::IsUnsigned(void) const noexcept {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.isUnsigned();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentNameType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, DependentNameType)
::pasta::Type DependentNameType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentNameType *>(u.DependentNameType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: DependentNameType::Identifier
// 0: DependentNameType::Qualifier
bool DependentNameType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentNameType *>(u.DependentNameType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, DependentSizedArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedArrayType)
::pasta::Type DependentSizedArrayType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TokenRange DependentSizedArrayType::BracketsRange(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getBracketsRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

::pasta::Token DependentSizedArrayType::LBracketToken(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getLBracketLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token DependentSizedArrayType::RBracketToken(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Expr DependentSizedArrayType::SizeExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedArrayType::SizeExpression can return nullptr!");
  __builtin_unreachable();
}

bool DependentSizedArrayType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedExtVectorType)
::pasta::Type DependentSizedExtVectorType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Token DependentSizedExtVectorType::AttributeToken(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type DependentSizedExtVectorType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Expr DependentSizedExtVectorType::SizeExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedExtVectorType::SizeExpression can return nullptr!");
  __builtin_unreachable();
}

bool DependentSizedExtVectorType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentTemplateSpecializationType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, DependentTemplateSpecializationType)
// 0: DependentTemplateSpecializationType::
::pasta::Type DependentTemplateSpecializationType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: DependentTemplateSpecializationType::
// 1: DependentTemplateSpecializationType::Argument
// 0: DependentTemplateSpecializationType::Arguments
// 0: DependentTemplateSpecializationType::Identifier
uint32_t DependentTemplateSpecializationType::NumArguments(void) const noexcept {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.getNumArgs();
  return val;
  __builtin_unreachable();
}

// 0: DependentTemplateSpecializationType::Qualifier
bool DependentTemplateSpecializationType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateArgument> DependentTemplateSpecializationType::TemplateArguments(void) const noexcept {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.template_arguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentVectorType)
::pasta::Type DependentVectorType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Token DependentVectorType::AttributeToken(void) const noexcept {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type DependentVectorType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Expr DependentVectorType::SizeExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentVectorType::SizeExpression can return nullptr!");
  __builtin_unreachable();
}

enum VectorTypeVectorKind DependentVectorType::VectorKind(void) const noexcept {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getVectorKind();
  return static_cast<::pasta::VectorTypeVectorKind>(val);
  __builtin_unreachable();
}

bool DependentVectorType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ElaboratedType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, ElaboratedType)
::pasta::Type ElaboratedType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type ElaboratedType::NamedType(void) const noexcept {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.getNamedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::TagDecl> ElaboratedType::OwnedTagDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.getOwnedTagDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  __builtin_unreachable();
}

// 0: ElaboratedType::Qualifier
bool ElaboratedType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ExtVectorType)
PASTA_DEFINE_BASE_OPERATORS(VectorType, ExtVectorType)
::pasta::Type ExtVectorType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ExtVectorType *>(u.ExtVectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 2: IsAccessorWithinNumElements
bool ExtVectorType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ExtVectorType *>(u.ExtVectorType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, FunctionType)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionType, FunctionNoProtoType)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionType, FunctionProtoType)
enum CallingConv FunctionType::CallConv(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getCallConv();
  return static_cast<::pasta::CallingConv>(val);
  __builtin_unreachable();
}

::pasta::Type FunctionType::CallResultType(void) const noexcept {
  auto &self = *(u.FunctionType);
  decltype(auto) val = self.getCallResultType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool FunctionType::CmseNSCallAttribute(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getCmseNSCallAttr();
  return val;
  __builtin_unreachable();
}

// 0: FunctionType::ExtInfo
bool FunctionType::HasRegParm(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getHasRegParm();
  return val;
  __builtin_unreachable();
}

bool FunctionType::NoReturnAttribute(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getNoReturnAttr();
  return val;
  __builtin_unreachable();
}

uint32_t FunctionType::RegParmType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getRegParmType();
  return val;
  __builtin_unreachable();
}

::pasta::Type FunctionType::ReturnType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool FunctionType::IsConst(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.isConst();
  return val;
  __builtin_unreachable();
}

bool FunctionType::IsRestrict(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.isRestrict();
  return val;
  __builtin_unreachable();
}

bool FunctionType::IsVolatile(void) const noexcept {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.isVolatile();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, IncompleteArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, IncompleteArrayType)
::pasta::Type IncompleteArrayType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::IncompleteArrayType *>(u.IncompleteArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool IncompleteArrayType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::IncompleteArrayType *>(u.IncompleteArrayType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, InjectedClassNameType)
::pasta::Type InjectedClassNameType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::CXXRecordDecl InjectedClassNameType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "InjectedClassNameType::Declaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type InjectedClassNameType::InjectedSpecializationType(void) const noexcept {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.getInjectedSpecializationType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TemplateSpecializationType InjectedClassNameType::InjectedTST(void) const noexcept {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.getInjectedTST();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateSpecializationType>(ast, val);
  }
  assert(false && "InjectedClassNameType::InjectedTST can return nullptr!");
  __builtin_unreachable();
}

// 0: InjectedClassNameType::TemplateName
bool InjectedClassNameType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, MacroQualifiedType)
::pasta::Type MacroQualifiedType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: MacroQualifiedType::MacroIdentifier
::pasta::Type MacroQualifiedType::ModifiedType(void) const noexcept {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.getModifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type MacroQualifiedType::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool MacroQualifiedType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, MatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(MatrixType, ConstantMatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(MatrixType, DependentSizedMatrixType)
::pasta::Type MatrixType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::MatrixType *>(u.MatrixType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type MatrixType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::MatrixType *>(u.MatrixType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool MatrixType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::MatrixType *>(u.MatrixType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, MemberPointerType)
::pasta::Type MemberPointerType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type MemberPointerType::Class(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.getClass();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "MemberPointerType::Class can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl MemberPointerType::MostRecentCXXRecordDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.getMostRecentCXXRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "MemberPointerType::MostRecentCXXRecordDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type MemberPointerType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool MemberPointerType::IsMemberDataPointer(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.isMemberDataPointer();
  return val;
  __builtin_unreachable();
}

bool MemberPointerType::IsMemberFunctionPointer(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.isMemberFunctionPointer();
  return val;
  __builtin_unreachable();
}

bool MemberPointerType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCObjectPointerType)
::pasta::Type ObjCObjectPointerType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCObjectPointerType::InterfaceDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getInterfaceDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::InterfaceDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCInterfaceType ObjCObjectPointerType::InterfaceType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getInterfaceType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCInterfaceType>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::InterfaceType can return nullptr!");
  __builtin_unreachable();
}

uint32_t ObjCObjectPointerType::NumProtocols(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getNumProtocols();
  return val;
  __builtin_unreachable();
}

::pasta::ObjCObjectType ObjCObjectPointerType::ObjectType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getObjectType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::ObjectType can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type ObjCObjectPointerType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 1: ObjCObjectPointerType::Protocol
::pasta::Type ObjCObjectPointerType::SuperClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getSuperClassType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::vector<::pasta::Type> ObjCObjectPointerType::TypeArguments(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getTypeArgs();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::Type> ObjCObjectPointerType::TypeArgumentsAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getTypeArgsAsWritten();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsKindOfType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isKindOfType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsObjCClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCClassType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsObjCIdOrClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCIdOrClassType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsObjCIdType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCIdType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsObjCQualifiedClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCQualifiedClassType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsObjCQualifiedIdType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCQualifiedIdType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsSpecialized(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isSpecialized();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsSpecializedAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isSpecializedAsWritten();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsUnspecialized(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isUnspecialized();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectPointerType::IsUnspecializedAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isUnspecializedAsWritten();
  return val;
  __builtin_unreachable();
}

// 0: ObjCObjectPointerType::
// 0: ObjCObjectPointerType::
// 0: ObjCObjectPointerType::
std::vector<::pasta::ObjCProtocolDecl> ObjCObjectPointerType::Qualifiers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.quals();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

::pasta::ObjCObjectPointerType ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers(void) const noexcept {
  auto &self = *(u.ObjCObjectPointerType);
  decltype(auto) val = self.stripObjCKindOfTypeAndQuals(ast->ci->getASTContext());
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers can return nullptr!");
  __builtin_unreachable();
  __builtin_unreachable();
}

std::vector<::pasta::ObjCProtocolDecl> ObjCObjectPointerType::Protocols(void) const noexcept {
  std::vector<::pasta::ObjCProtocolDecl> ret;
  auto convert_elem = [&] (clang::ObjCProtocolDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  auto count = u.ObjCObjectPointerType->getNumProtocols();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCObjectPointerType->getProtocol(i)));
  }
  return ret;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCObjectType)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCObjectType, ObjCInterfaceType)
::pasta::Type ObjCObjectType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type ObjCObjectType::BaseType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getBaseType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCObjectType::Interface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCObjectType::Interface can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::Type> ObjCObjectType::SuperClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getSuperClassType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::vector<::pasta::Type> ObjCObjectType::TypeArguments(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getTypeArgs();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::Type> ObjCObjectType::TypeArgumentsAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getTypeArgsAsWritten();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
  __builtin_unreachable();
}

bool ObjCObjectType::IsKindOfType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isKindOfType();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsKindOfTypeAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isKindOfTypeAsWritten();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCClass();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCId(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCId();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCQualifiedClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCQualifiedClass();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCQualifiedId(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCQualifiedId();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCUnqualifiedClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCUnqualifiedClass();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCUnqualifiedId(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCUnqualifiedId();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsObjCUnqualifiedIdOrClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCUnqualifiedIdOrClass();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsSpecialized(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isSpecialized();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsSpecializedAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isSpecializedAsWritten();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsUnspecialized(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isUnspecialized();
  return val;
  __builtin_unreachable();
}

bool ObjCObjectType::IsUnspecializedAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isUnspecializedAsWritten();
  return val;
  __builtin_unreachable();
}

::pasta::Type ObjCObjectType::StripObjCKindOfTypeAndQualifiers(void) const noexcept {
  auto &self = *(u.ObjCObjectType);
  decltype(auto) val = self.stripObjCKindOfTypeAndQuals(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCTypeParamType)
::pasta::Type ObjCTypeParamType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamType *>(u.ObjCTypeParamType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::ObjCTypeParamDecl ObjCTypeParamType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamType *>(u.ObjCTypeParamType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCTypeParamDecl>(ast, val);
  }
  assert(false && "ObjCTypeParamType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool ObjCTypeParamType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamType *>(u.ObjCTypeParamType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, PackExpansionType)
::pasta::Type PackExpansionType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<unsigned> PackExpansionType::NumExpansions(void) const noexcept {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.getNumExpansions();
  if (val.hasValue()) {
    return val.getValue();
  } else {
    return std::nullopt;
  }
  __builtin_unreachable();
}

::pasta::Type PackExpansionType::Pattern(void) const noexcept {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.getPattern();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool PackExpansionType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ParenType)
::pasta::Type ParenType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ParenType *>(u.ParenType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type ParenType::InnerType(void) const noexcept {
  auto &self = *const_cast<clang::ParenType *>(u.ParenType);
  decltype(auto) val = self.getInnerType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool ParenType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ParenType *>(u.ParenType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, PipeType)
::pasta::Type PipeType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type PipeType::ElementType(void) const noexcept {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool PipeType::IsReadOnly(void) const noexcept {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.isReadOnly();
  return val;
  __builtin_unreachable();
}

bool PipeType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, PointerType)
::pasta::Type PointerType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::PointerType *>(u.PointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type PointerType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::PointerType *>(u.PointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool PointerType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::PointerType *>(u.PointerType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, ReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(ReferenceType, LValueReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(ReferenceType, RValueReferenceType)
::pasta::Type ReferenceType::PointeeType(void) const noexcept {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type ReferenceType::PointeeTypeAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.getPointeeTypeAsWritten();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool ReferenceType::IsInnerReference(void) const noexcept {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.isInnerRef();
  return val;
  __builtin_unreachable();
}

bool ReferenceType::IsSpelledAsLValue(void) const noexcept {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.isSpelledAsLValue();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, SubstTemplateTypeParmPackType)
::pasta::Type SubstTemplateTypeParmPackType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: SubstTemplateTypeParmPackType::ArgumentPack
// 0: SubstTemplateTypeParmPackType::Identifier
uint32_t SubstTemplateTypeParmPackType::NumArguments(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getNumArgs();
  return val;
  __builtin_unreachable();
}

::pasta::TemplateTypeParmType SubstTemplateTypeParmPackType::ReplacedParameter(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getReplacedParameter();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateTypeParmType>(ast, val);
  }
  assert(false && "SubstTemplateTypeParmPackType::ReplacedParameter can return nullptr!");
  __builtin_unreachable();
}

bool SubstTemplateTypeParmPackType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, SubstTemplateTypeParmType)
::pasta::Type SubstTemplateTypeParmType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TemplateTypeParmType SubstTemplateTypeParmType::ReplacedParameter(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getReplacedParameter();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateTypeParmType>(ast, val);
  }
  assert(false && "SubstTemplateTypeParmType::ReplacedParameter can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type SubstTemplateTypeParmType::ReplacementType(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getReplacementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool SubstTemplateTypeParmType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, TagType)
PASTA_DEFINE_DERIVED_OPERATORS(TagType, EnumType)
PASTA_DEFINE_DERIVED_OPERATORS(TagType, RecordType)
::pasta::TagDecl TagType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::TagType *>(u.TagType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TagType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool TagType::IsBeingDefined(void) const noexcept {
  auto &self = *const_cast<clang::TagType *>(u.TagType);
  decltype(auto) val = self.isBeingDefined();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, TemplateSpecializationType)
// 0: TemplateSpecializationType::
::pasta::Type TemplateSpecializationType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: TemplateSpecializationType::
std::optional<::pasta::Type> TemplateSpecializationType::AliasedType(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  if (!self.isTypeAlias()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getAliasedType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 1: TemplateSpecializationType::Argument
// 0: TemplateSpecializationType::Arguments
uint32_t TemplateSpecializationType::NumArguments(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.getNumArgs();
  return val;
  __builtin_unreachable();
}

// 0: TemplateSpecializationType::TemplateName
bool TemplateSpecializationType::IsCurrentInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.isCurrentInstantiation();
  return val;
  __builtin_unreachable();
}

bool TemplateSpecializationType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool TemplateSpecializationType::IsTypeAlias(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.isTypeAlias();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateArgument> TemplateSpecializationType::TemplateArguments(void) const noexcept {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.template_arguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(Type, TemplateTypeParmType)
::pasta::Type TemplateTypeParmType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::TemplateTypeParmDecl> TemplateTypeParmType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.getDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateTypeParmDecl>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t TemplateTypeParmType::Depth(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.getDepth();
  return val;
  __builtin_unreachable();
}

// 0: TemplateTypeParmType::Identifier
uint32_t TemplateTypeParmType::Index(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.getIndex();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmType::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.isParameterPack();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, VariableArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, VariableArrayType)
::pasta::Type VariableArrayType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TokenRange VariableArrayType::BracketsRange(void) const noexcept {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getBracketsRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

::pasta::Token VariableArrayType::LBracketToken(void) const noexcept {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getLBracketLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token VariableArrayType::RBracketToken(void) const noexcept {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Expr VariableArrayType::SizeExpression(void) const noexcept {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "VariableArrayType::SizeExpression can return nullptr!");
  __builtin_unreachable();
}

bool VariableArrayType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(DeducedType, AutoType)
PASTA_DEFINE_BASE_OPERATORS(Type, AutoType)
// 1: AutoType::Argument
// 0: AutoType::Arguments
enum AutoTypeKeyword AutoType::Keyword(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getKeyword();
  return static_cast<::pasta::AutoTypeKeyword>(val);
  __builtin_unreachable();
}

uint32_t AutoType::NumArguments(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getNumArgs();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateArgument> AutoType::TypeConstraintArguments(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getTypeConstraintArguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

std::optional<::pasta::ConceptDecl> AutoType::TypeConstraintConcept(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getTypeConstraintConcept();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
  __builtin_unreachable();
}

bool AutoType::IsConstrained(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.isConstrained();
  return val;
  __builtin_unreachable();
}

bool AutoType::IsDecltypeAuto(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.isDecltypeAuto();
  return val;
  __builtin_unreachable();
}

bool AutoType::IsGNUAutoType(void) const noexcept {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.isGNUAutoType();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(MatrixType, ConstantMatrixType)
PASTA_DEFINE_BASE_OPERATORS(Type, ConstantMatrixType)
uint32_t ConstantMatrixType::NumColumns(void) const noexcept {
  auto &self = *const_cast<clang::ConstantMatrixType *>(u.ConstantMatrixType);
  decltype(auto) val = self.getNumColumns();
  return val;
  __builtin_unreachable();
}

uint32_t ConstantMatrixType::NumElementsFlattened(void) const noexcept {
  auto &self = *const_cast<clang::ConstantMatrixType *>(u.ConstantMatrixType);
  decltype(auto) val = self.getNumElementsFlattened();
  return val;
  __builtin_unreachable();
}

uint32_t ConstantMatrixType::NumRows(void) const noexcept {
  auto &self = *const_cast<clang::ConstantMatrixType *>(u.ConstantMatrixType);
  decltype(auto) val = self.getNumRows();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
PASTA_DEFINE_BASE_OPERATORS(Type, DeducedTemplateSpecializationType)
// 0: DeducedTemplateSpecializationType::TemplateName
PASTA_DEFINE_BASE_OPERATORS(MatrixType, DependentSizedMatrixType)
PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedMatrixType)
::pasta::Token DependentSizedMatrixType::AttributeToken(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedMatrixType *>(u.DependentSizedMatrixType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Expr DependentSizedMatrixType::ColumnExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedMatrixType *>(u.DependentSizedMatrixType);
  decltype(auto) val = self.getColumnExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedMatrixType::ColumnExpression can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr DependentSizedMatrixType::RowExpression(void) const noexcept {
  auto &self = *const_cast<clang::DependentSizedMatrixType *>(u.DependentSizedMatrixType);
  decltype(auto) val = self.getRowExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedMatrixType::RowExpression can return nullptr!");
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(TagType, EnumType)
PASTA_DEFINE_BASE_OPERATORS(Type, EnumType)
::pasta::Type EnumType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::EnumType *>(u.EnumType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::EnumDecl EnumType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::EnumType *>(u.EnumType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool EnumType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::EnumType *>(u.EnumType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(FunctionType, FunctionNoProtoType)
PASTA_DEFINE_BASE_OPERATORS(Type, FunctionNoProtoType)
::pasta::Type FunctionNoProtoType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::FunctionNoProtoType *>(u.FunctionNoProtoType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool FunctionNoProtoType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::FunctionNoProtoType *>(u.FunctionNoProtoType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(FunctionType, FunctionProtoType)
PASTA_DEFINE_BASE_OPERATORS(Type, FunctionProtoType)
std::optional<enum CanThrowResult> FunctionProtoType::CanThrow(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  switch (self.getExceptionSpecType()) {
    case clang::EST_Unparsed:
    case clang::EST_Unevaluated:
    case clang::EST_Uninstantiated:
      return std::nullopt;
    default: break;
  }
  decltype(auto) val = self.canThrow();
  return static_cast<::pasta::CanThrowResult>(val);
  __builtin_unreachable();
}

::pasta::Type FunctionProtoType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: FunctionProtoType::
// 0: FunctionProtoType::
std::vector<::pasta::Type> FunctionProtoType::Exceptions(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.exceptions();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
  __builtin_unreachable();
}

::pasta::Token FunctionProtoType::EllipsisToken(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::FunctionDecl> FunctionProtoType::ExceptionSpecDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getExceptionSpecDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

// 0: FunctionProtoType::ExceptionSpecInfo
std::optional<::pasta::FunctionDecl> FunctionProtoType::ExceptionSpecTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getExceptionSpecTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

enum ExceptionSpecificationType FunctionProtoType::ExceptionSpecType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(val);
  __builtin_unreachable();
}

// 1: FunctionProtoType::ExceptionType
// 1: FunctionProtoType::ExtParameterInfo
// 0: FunctionProtoType::ExtParameterInfos
// 0: FunctionProtoType::ExtParameterInfosOrNull
// 0: FunctionProtoType::ExtProtoInfo
// 0: FunctionProtoType::MethodQualifiers
std::optional<::pasta::Expr> FunctionProtoType::NoexceptExpression(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getNoexceptExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t FunctionProtoType::NumExceptions(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getNumExceptions();
  return val;
  __builtin_unreachable();
}

uint32_t FunctionProtoType::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getNumParams();
  return val;
  __builtin_unreachable();
}

// 1: FunctionProtoType::ParameterType
std::vector<::pasta::Type> FunctionProtoType::ParameterTypes(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getParamTypes();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
  __builtin_unreachable();
}

// 1: FunctionProtoType::ParameterABI
enum RefQualifierKind FunctionProtoType::ReferenceQualifier(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(val);
  __builtin_unreachable();
}

bool FunctionProtoType::HasDependentExceptionSpec(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasDependentExceptionSpec();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::HasDynamicExceptionSpec(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasDynamicExceptionSpec();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::HasExceptionSpec(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasExceptionSpec();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::HasExtParameterInfos(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasExtParameterInfos();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::HasInstantiationDependentExceptionSpec(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasInstantiationDependentExceptionSpec();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::HasNoexceptExceptionSpec(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasNoexceptExceptionSpec();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::HasTrailingReturn(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasTrailingReturn();
  return val;
  __builtin_unreachable();
}

std::optional<bool> FunctionProtoType::IsNothrow(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  switch (self.getExceptionSpecType()) {
    case clang::EST_Unparsed:
    case clang::EST_Unevaluated:
    case clang::EST_Uninstantiated:
      return std::nullopt;
    default: break;
  }
  decltype(auto) val = self.isNothrow();
  return val;
  __builtin_unreachable();
}

// 1: FunctionProtoType::IsParameterConsumed
bool FunctionProtoType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::IsTemplateVariadic(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.isTemplateVariadic();
  return val;
  __builtin_unreachable();
}

bool FunctionProtoType::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.isVariadic();
  return val;
  __builtin_unreachable();
}

// 0: FunctionProtoType::
// 0: FunctionProtoType::
// 0: FunctionProtoType::ParameterTypes
std::vector<::pasta::Type> FunctionProtoType::ExceptionTypes(void) const noexcept {
  std::vector<::pasta::Type> ret;
  auto convert_elem = [&] (clang::QualType val) {
    return TypeBuilder::Build(ast, val);
  };
  auto count = u.FunctionProtoType->getNumExceptions();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FunctionProtoType->getExceptionType(i)));
  }
  return ret;
}

PASTA_DEFINE_BASE_OPERATORS(ReferenceType, LValueReferenceType)
PASTA_DEFINE_BASE_OPERATORS(Type, LValueReferenceType)
::pasta::Type LValueReferenceType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::LValueReferenceType *>(u.LValueReferenceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool LValueReferenceType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::LValueReferenceType *>(u.LValueReferenceType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(ObjCObjectType, ObjCInterfaceType)
PASTA_DEFINE_BASE_OPERATORS(Type, ObjCInterfaceType)
::pasta::Type ObjCInterfaceType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceType *>(u.ObjCInterfaceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCInterfaceType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceType *>(u.ObjCInterfaceType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool ObjCInterfaceType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceType *>(u.ObjCInterfaceType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(ReferenceType, RValueReferenceType)
PASTA_DEFINE_BASE_OPERATORS(Type, RValueReferenceType)
::pasta::Type RValueReferenceType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::RValueReferenceType *>(u.RValueReferenceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool RValueReferenceType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::RValueReferenceType *>(u.RValueReferenceType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

PASTA_DEFINE_BASE_OPERATORS(TagType, RecordType)
PASTA_DEFINE_BASE_OPERATORS(Type, RecordType)
::pasta::Type RecordType::Desugar(void) const noexcept {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::RecordDecl RecordType::Declaration(void) const noexcept {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordType::Declaration can return nullptr!");
  __builtin_unreachable();
}

bool RecordType::HasConstFields(void) const noexcept {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.hasConstFields();
  return val;
  __builtin_unreachable();
}

bool RecordType::IsSugared(void) const noexcept {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.isSugared();
  return val;
  __builtin_unreachable();
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
