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
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
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

void TypeVisitor::VisitQualifiedType(const QualifiedType &type) {
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
PASTA_DEFINE_DERIVED_OPERATORS(Type, QualifiedType)
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
bool Type::AcceptsObjCTypeParameters(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.acceptsObjCTypeParams();
  return val;
}

bool Type::CanDecayToPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.canDecayToPointerType();
  return val;
}

bool Type::CanHaveNullability(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.canHaveNullability();
  return val;
}

bool Type::ContainsErrors(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.containsErrors();
  return val;
}

bool Type::ContainsUnexpandedParameterPack(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.containsUnexpandedParameterPack();
  return val;
}

std::optional<::pasta::Type> Type::ArrayElementTypeNoTypeQualified(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getArrayElementTypeNoTypeQual();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
}

std::optional<::pasta::CXXRecordDecl> Type::AsCXXRecordDeclaration(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsCXXRecordDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

std::optional<::pasta::ComplexType> Type::AsComplexIntegerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsComplexIntegerType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ComplexType>(ast, val);
  }
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCInterfacePointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCInterfacePointerType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
}

std::optional<::pasta::ObjCObjectType> Type::AsObjCInterfaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCInterfaceType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCQualifiedClassType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCQualifiedClassType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCQualifiedIdType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCQualifiedIdType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
}

std::optional<::pasta::ObjCObjectType> Type::AsObjCQualifiedInterfaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsObjCQualifiedInterfaceType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
}

std::optional<::pasta::BuiltinType> Type::AsPlaceholderType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsPlaceholderType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::BuiltinType>(ast, val);
  }
}

std::optional<::pasta::RecordDecl> Type::AsRecordDeclaration(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsRecordDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
}

std::optional<::pasta::RecordType> Type::AsStructureType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsStructureType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::RecordType>(ast, val);
  }
}

std::optional<::pasta::TagDecl> Type::AsTagDeclaration(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsTagDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
}

std::optional<::pasta::RecordType> Type::AsUnionType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getAsUnionType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::RecordType>(ast, val);
  }
}

::pasta::Type Type::CanonicalTypeInternal(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getCanonicalTypeInternal();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: Type::CanonicalTypeUnqualified
std::optional<::pasta::AutoType> Type::ContainedAutoType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getContainedAutoType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::AutoType>(ast, val);
  }
}

std::optional<::pasta::DeducedType> Type::ContainedDeducedType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getContainedDeducedType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::DeducedType>(ast, val);
  }
}

// 0: Type::Dependence
enum Linkage Type::Linkage(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getLinkage();
  return static_cast<::pasta::Linkage>(val);
}

// 0: Type::LinkageAndVisibility
::pasta::Type Type::LocallyUnqualifiedSingleStepDesugaredType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getLocallyUnqualifiedSingleStepDesugaredType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::NullabilityKind> Type::Nullability(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getNullability();
  if (val.has_value()) {
    return static_cast<::pasta::NullabilityKind>(val.value());
  } else {
    return std::nullopt;
  }
}

// 0: Type::ObjCARCImplicitLifetime
// 1: Type::ObjCSubstitutions
std::optional<::pasta::CXXRecordDecl> Type::PointeeCXXRecordDeclaration(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getPointeeCXXRecordDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

std::optional<::pasta::Type> Type::PointeeOrArrayElementType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getPointeeOrArrayElementType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
}

std::optional<::pasta::Type> Type::PointeeType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getPointeeType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Type> Type::RVVElementType(void) const {
  auto &self = *(u.Type);
  if (!self.isRVVVLSBuiltinType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getRVVEltType(ast->ci->getASTContext());
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::optional<enum TypeScalarTypeKind> Type::ScalarTypeKind(void) const {
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
}

std::optional<::pasta::Type> Type::SveElementType(void) const {
  auto &self = *(u.Type);
  if (!self.isRVVVLSBuiltinType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getSveEltType(ast->ci->getASTContext());
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::UnqualifiedDesugaredType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getUnqualifiedDesugaredType();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  throw std::runtime_error("Type::UnqualifiedDesugaredType can return nullptr!");
}

enum Visibility Type::Visibility(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::Visibility>(val);
}

// 1: Type::HasAttribute
bool Type::HasAutoForTrailingReturnType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasAutoForTrailingReturnType();
  return val;
}

bool Type::HasFloatingRepresentation(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasFloatingRepresentation();
  return val;
}

bool Type::HasIntegerRepresentation(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasIntegerRepresentation();
  return val;
}

bool Type::HasObjCPointerRepresentation(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasObjCPointerRepresentation();
  return val;
}

bool Type::HasPointerRepresentation(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasPointerRepresentation();
  return val;
}

bool Type::HasSignedIntegerRepresentation(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasSignedIntegerRepresentation();
  return val;
}

bool Type::HasSizedVLAType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasSizedVLAType();
  return val;
}

bool Type::HasUnnamedOrLocalType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasUnnamedOrLocalType();
  return val;
}

bool Type::HasUnsignedIntegerRepresentation(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.hasUnsignedIntegerRepresentation();
  return val;
}

std::optional<bool> Type::IsAggregateType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (auto klass = self.getAsCXXRecordDecl()) {
    if (!klass->getDefinition()) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.isAggregateType();
  return val;
}

bool Type::IsAlignValueT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAlignValT();
  return val;
}

bool Type::IsAnyCharacterType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAnyCharacterType();
  return val;
}

bool Type::IsAnyComplexType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAnyComplexType();
  return val;
}

bool Type::IsAnyPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAnyPointerType();
  return val;
}

bool Type::IsArithmeticType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isArithmeticType();
  return val;
}

bool Type::IsArrayType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isArrayType();
  return val;
}

bool Type::IsAtomicType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isAtomicType();
  return val;
}

bool Type::IsBFloat16Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBFloat16Type();
  return val;
}

bool Type::IsBitIntType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBitIntType();
  return val;
}

bool Type::IsBlockCompatibleObjCPointerType(void) const {
  auto &self = *(u.Type);
  decltype(auto) val = self.isBlockCompatibleObjCPointerType(ast->ci->getASTContext());
  return val;
}

bool Type::IsBlockPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBlockPointerType();
  return val;
}

bool Type::IsBooleanType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBooleanType();
  return val;
}

bool Type::IsBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isBuiltinType();
  return val;
}

bool Type::IsCARCBridgableType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCARCBridgableType();
  return val;
}

bool Type::IsCUDADeviceBuiltinSurfaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCUDADeviceBuiltinSurfaceType();
  return val;
}

bool Type::IsCUDADeviceBuiltinTextureType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCUDADeviceBuiltinTextureType();
  return val;
}

bool Type::IsCanonicalUnqualified(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCanonicalUnqualified();
  return val;
}

bool Type::IsChar16Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isChar16Type();
  return val;
}

bool Type::IsChar32Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isChar32Type();
  return val;
}

bool Type::IsChar8Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isChar8Type();
  return val;
}

bool Type::IsCharacterType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCharType();
  return val;
}

bool Type::IsClassType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isClassType();
  return val;
}

bool Type::IsClkEventT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isClkEventT();
  return val;
}

bool Type::IsComplexIntegerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isComplexIntegerType();
  return val;
}

bool Type::IsComplexType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isComplexType();
  return val;
}

bool Type::IsCompoundType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isCompoundType();
  return val;
}

bool Type::IsConstantArrayType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isConstantArrayType();
  return val;
}

bool Type::IsConstantMatrixType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isConstantMatrixType();
  return val;
}

std::optional<bool> Type::IsConstantSizeType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (self.isIncompleteType() || self.isDependentType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isConstantSizeType();
  return val;
}

bool Type::IsDecltypeType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDecltypeType();
  return val;
}

bool Type::IsDependentAddressSpaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDependentAddressSpaceType();
  return val;
}

bool Type::IsDependentSizedArrayType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDependentSizedArrayType();
  return val;
}

bool Type::IsDependentType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isDependentType();
  return val;
}

bool Type::IsElaboratedTypeSpecifier(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isElaboratedTypeSpecifier();
  return val;
}

bool Type::IsEnumeralType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isEnumeralType();
  return val;
}

bool Type::IsEventT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isEventT();
  return val;
}

bool Type::IsExtVectorBooleanType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isExtVectorBoolType();
  return val;
}

bool Type::IsExtVectorType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isExtVectorType();
  return val;
}

bool Type::IsFixedPointOrIntegerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFixedPointOrIntegerType();
  return val;
}

bool Type::IsFixedPointType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFixedPointType();
  return val;
}

bool Type::IsFloat128Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFloat128Type();
  return val;
}

bool Type::IsFloat16Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFloat16Type();
  return val;
}

bool Type::IsFloatingType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFloatingType();
  return val;
}

bool Type::IsFromAST(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFromAST();
  return val;
}

bool Type::IsFunctionNoProtoType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionNoProtoType();
  return val;
}

bool Type::IsFunctionPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionPointerType();
  return val;
}

bool Type::IsFunctionProtoType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionProtoType();
  return val;
}

bool Type::IsFunctionReferenceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionReferenceType();
  return val;
}

bool Type::IsFunctionType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFunctionType();
  return val;
}

bool Type::IsFundamentalType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isFundamentalType();
  return val;
}

bool Type::IsHalfType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isHalfType();
  return val;
}

bool Type::IsIbm128Type(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIbm128Type();
  return val;
}

bool Type::IsImageType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isImageType();
  return val;
}

bool Type::IsIncompleteArrayType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIncompleteArrayType();
  return val;
}

bool Type::IsIncompleteOrObjectType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIncompleteOrObjectType();
  return val;
}

bool Type::IsIncompleteType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIncompleteType();
  return val;
}

bool Type::IsInstantiationDependentType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isInstantiationDependentType();
  return val;
}

bool Type::IsIntegerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIntegerType();
  return val;
}

bool Type::IsIntegralOrEnumerationType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIntegralOrEnumerationType();
  return val;
}

bool Type::IsIntegralOrUnscopedEnumerationType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isIntegralOrUnscopedEnumerationType();
  return val;
}

bool Type::IsIntegralType(void) const {
  auto &self = *(u.Type);
  decltype(auto) val = self.isIntegralType(ast->ci->getASTContext());
  return val;
}

bool Type::IsInterfaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isInterfaceType();
  return val;
}

bool Type::IsLValueReferenceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isLValueReferenceType();
  return val;
}

bool Type::IsLinkageValid(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isLinkageValid();
  return val;
}

std::optional<bool> Type::IsLiteralType(void) const {
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
}

bool Type::IsMatrixType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMatrixType();
  return val;
}

bool Type::IsMemberDataPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMemberDataPointerType();
  return val;
}

bool Type::IsMemberFunctionPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMemberFunctionPointerType();
  return val;
}

bool Type::IsMemberPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isMemberPointerType();
  return val;
}

bool Type::IsNonOverloadPlaceholderType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isNonOverloadPlaceholderType();
  return val;
}

bool Type::IsNothrowT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isNothrowT();
  return val;
}

bool Type::IsNullPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isNullPtrType();
  return val;
}

bool Type::IsOCLExtOpaqueType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLExtOpaqueType();
  return val;
}

bool Type::IsOCLImage1dArrayROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dArrayROType();
  return val;
}

bool Type::IsOCLImage1dArrayRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dArrayRWType();
  return val;
}

bool Type::IsOCLImage1dArrayWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dArrayWOType();
  return val;
}

bool Type::IsOCLImage1dBufferROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dBufferROType();
  return val;
}

bool Type::IsOCLImage1dBufferRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dBufferRWType();
  return val;
}

bool Type::IsOCLImage1dBufferWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dBufferWOType();
  return val;
}

bool Type::IsOCLImage1dROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dROType();
  return val;
}

bool Type::IsOCLImage1dRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dRWType();
  return val;
}

bool Type::IsOCLImage1dWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage1dWOType();
  return val;
}

bool Type::IsOCLImage2dArrayDepthROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayDepthROType();
  return val;
}

bool Type::IsOCLImage2dArrayDepthRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayDepthRWType();
  return val;
}

bool Type::IsOCLImage2dArrayDepthWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayDepthWOType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAADepthROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAADepthROType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAADepthRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAADepthRWType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAADepthWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAADepthWOType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAAROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAAROType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAARWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAARWType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAAWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayMSAAWOType();
  return val;
}

bool Type::IsOCLImage2dArrayROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayROType();
  return val;
}

bool Type::IsOCLImage2dArrayRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayRWType();
  return val;
}

bool Type::IsOCLImage2dArrayWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dArrayWOType();
  return val;
}

bool Type::IsOCLImage2dDepthROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dDepthROType();
  return val;
}

bool Type::IsOCLImage2dDepthRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dDepthRWType();
  return val;
}

bool Type::IsOCLImage2dDepthWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dDepthWOType();
  return val;
}

bool Type::IsOCLImage2dMSAADepthROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAADepthROType();
  return val;
}

bool Type::IsOCLImage2dMSAADepthRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAADepthRWType();
  return val;
}

bool Type::IsOCLImage2dMSAADepthWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAADepthWOType();
  return val;
}

bool Type::IsOCLImage2dMSAAROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAAROType();
  return val;
}

bool Type::IsOCLImage2dMSAARWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAARWType();
  return val;
}

bool Type::IsOCLImage2dMSAAWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dMSAAWOType();
  return val;
}

bool Type::IsOCLImage2dROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dROType();
  return val;
}

bool Type::IsOCLImage2dRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dRWType();
  return val;
}

bool Type::IsOCLImage2dWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage2dWOType();
  return val;
}

bool Type::IsOCLImage3dROType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage3dROType();
  return val;
}

bool Type::IsOCLImage3dRWType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage3dRWType();
  return val;
}

bool Type::IsOCLImage3dWOType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLImage3dWOType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeDualReferenceStreaminType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeDualReferenceStreaminType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImePayloadType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImePayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeResultType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCImeSingleReferenceStreaminType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCMcePayloadType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCMcePayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCMceResultType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCMceResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCRefPayloadType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCRefPayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCRefResultType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCRefResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCSicPayloadType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCSicPayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCSicResultType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCSicResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOCLIntelSubgroupAVCType();
  return val;
}

bool Type::IsObjCARCBridgableType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCARCBridgableType();
  return val;
}

std::optional<bool> Type::IsObjCARCImplicitlyUnretainedType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (!self.isObjCLifetimeType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isObjCARCImplicitlyUnretainedType();
  return val;
}

bool Type::IsObjCBoxableRecordType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCBoxableRecordType();
  return val;
}

bool Type::IsObjCBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCBuiltinType();
  return val;
}

bool Type::IsObjCClassOrClassKindOfType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCClassOrClassKindOfType();
  return val;
}

bool Type::IsObjCClassType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCClassType();
  return val;
}

// 2: IsObjCIdOrObjectKindOfType
bool Type::IsObjCIdType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCIdType();
  return val;
}

bool Type::IsObjCIndependentClassType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCIndependentClassType();
  return val;
}

bool Type::IsObjCIndirectLifetimeType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCIndirectLifetimeType();
  return val;
}

bool Type::IsObjCInertUnsafeUnretainedType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCInertUnsafeUnretainedType();
  return val;
}

bool Type::IsObjCLifetimeType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCLifetimeType();
  return val;
}

bool Type::IsObjCNSObjectType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCNSObjectType();
  return val;
}

bool Type::IsObjCObjectOrInterfaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCObjectOrInterfaceType();
  return val;
}

bool Type::IsObjCObjectPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCObjectPointerType();
  return val;
}

bool Type::IsObjCObjectType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCObjectType();
  return val;
}

bool Type::IsObjCQualifiedClassType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCQualifiedClassType();
  return val;
}

bool Type::IsObjCQualifiedIdType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCQualifiedIdType();
  return val;
}

bool Type::IsObjCQualifiedInterfaceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCQualifiedInterfaceType();
  return val;
}

bool Type::IsObjCRetainableType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCRetainableType();
  return val;
}

bool Type::IsObjCSelType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjCSelType();
  return val;
}

bool Type::IsObjectPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjectPointerType();
  return val;
}

bool Type::IsObjectType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isObjectType();
  return val;
}

bool Type::IsOpenCLSpecificType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOpenCLSpecificType();
  return val;
}

bool Type::IsOverloadableType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isOverloadableType();
  return val;
}

bool Type::IsPipeType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPipeType();
  return val;
}

bool Type::IsPlaceholderType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPlaceholderType();
  return val;
}

bool Type::IsPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isPointerType();
  return val;
}

bool Type::IsQueueT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isQueueT();
  return val;
}

bool Type::IsRVVSizelessBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRVVSizelessBuiltinType();
  return val;
}

bool Type::IsRVVVLSBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRVVVLSBuiltinType();
  return val;
}

bool Type::IsRValueReferenceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRValueReferenceType();
  return val;
}

bool Type::IsRealFloatingType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRealFloatingType();
  return val;
}

bool Type::IsRealType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRealType();
  return val;
}

bool Type::IsRecordType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isRecordType();
  return val;
}

bool Type::IsReferenceType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isReferenceType();
  return val;
}

bool Type::IsReserveIDT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isReserveIDT();
  return val;
}

bool Type::IsSVESizelessBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSVESizelessBuiltinType();
  return val;
}

bool Type::IsSamplerT(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSamplerT();
  return val;
}

bool Type::IsSaturatedFixedPointType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSaturatedFixedPointType();
  return val;
}

bool Type::IsScalarType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isScalarType();
  return val;
}

bool Type::IsScopedEnumeralType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isScopedEnumeralType();
  return val;
}

bool Type::IsSignedFixedPointType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSignedFixedPointType();
  return val;
}

bool Type::IsSignedIntegerOrEnumerationType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSignedIntegerOrEnumerationType();
  return val;
}

bool Type::IsSignedIntegerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSignedIntegerType();
  return val;
}

bool Type::IsSizelessBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSizelessBuiltinType();
  return val;
}

bool Type::IsSizelessType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSizelessType();
  return val;
}

// 1: Type::IsSpecificBuiltinType
// 1: Type::IsSpecificPlaceholderType
bool Type::IsSpecifierType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isSpecifierType();
  return val;
}

std::optional<bool> Type::IsStandardLayoutType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (self.isDependentType()) {
    return false;
  } else if (!self.getBaseElementTypeUnsafe()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isStandardLayoutType();
  return val;
}

bool Type::IsStdByteType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isStdByteType();
  return val;
}

std::optional<bool> Type::IsStructuralType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  if (auto klass = self.getAsCXXRecordDecl()) {
    if (!klass->getDefinition()) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.isStructuralType();
  return val;
}

bool Type::IsStructureOrClassType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isStructureOrClassType();
  return val;
}

bool Type::IsStructureType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isStructureType();
  return val;
}

bool Type::IsTemplateTypeParmType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isTemplateTypeParmType();
  return val;
}

bool Type::IsTypedefNameType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isTypedefNameType();
  return val;
}

bool Type::IsUndeducedAutoType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUndeducedAutoType();
  return val;
}

bool Type::IsUndeducedType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUndeducedType();
  return val;
}

bool Type::IsUnionType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnionType();
  return val;
}

bool Type::IsUnresolvedType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnresolvedType();
  return val;
}

bool Type::IsUnsaturatedFixedPointType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsaturatedFixedPointType();
  return val;
}

bool Type::IsUnscopedEnumerationType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnscopedEnumerationType();
  return val;
}

bool Type::IsUnsignedFixedPointType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsignedFixedPointType();
  return val;
}

bool Type::IsUnsignedIntegerOrEnumerationType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsignedIntegerOrEnumerationType();
  return val;
}

bool Type::IsUnsignedIntegerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isUnsignedIntegerType();
  return val;
}

bool Type::IsVLSTBuiltinType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVLSTBuiltinType();
  return val;
}

bool Type::IsVariableArrayType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVariableArrayType();
  return val;
}

bool Type::IsVariablyModifiedType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVariablyModifiedType();
  return val;
}

bool Type::IsVectorType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVectorType();
  return val;
}

bool Type::IsVisibilityExplicit(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVisibilityExplicit();
  return val;
}

bool Type::IsVoidPointerType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVoidPointerType();
  return val;
}

bool Type::IsVoidType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isVoidType();
  return val;
}

bool Type::IsWebAssemblyExternrefType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isWebAssemblyExternrefType();
  return val;
}

bool Type::IsWebAssemblyTableType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isWebAssemblyTableType();
  return val;
}

bool Type::IsWideCharacterType(void) const {
  auto &self = *const_cast<clang::Type *>(u.Type);
  decltype(auto) val = self.isWideCharType();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypeOfExprType)
::pasta::Type TypeOfExprType::Desugar(void) const {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

enum TypeOfKind TypeOfExprType::TypeKind(void) const {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::TypeOfKind>(val);
}

::pasta::Expr TypeOfExprType::UnderlyingExpression(void) const {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.getUnderlyingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("TypeOfExprType::UnderlyingExpression can return nullptr!");
}

bool TypeOfExprType::IsSugared(void) const {
  auto &self = *const_cast<clang::TypeOfExprType *>(u.TypeOfExprType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypeOfType)
::pasta::Type TypeOfType::Desugar(void) const {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

enum TypeOfKind TypeOfType::TypeKind(void) const {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::TypeOfKind>(val);
}

::pasta::Type TypeOfType::UnmodifiedType(void) const {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.getUnmodifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool TypeOfType::IsSugared(void) const {
  auto &self = *const_cast<clang::TypeOfType *>(u.TypeOfType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypedefType)
::pasta::Type TypedefType::Desugar(void) const {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::TypedefNameDecl TypedefType::Declaration(void) const {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  throw std::runtime_error("TypedefType::Declaration can return nullptr!");
}

bool TypedefType::IsSugared(void) const {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool TypedefType::TypeMatchesDeclaration(void) const {
  auto &self = *const_cast<clang::TypedefType *>(u.TypedefType);
  decltype(auto) val = self.typeMatchesDecl();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, UnaryTransformType)
std::optional<::pasta::Type> UnaryTransformType::Desugar(void) const {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.desugar();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Type> UnaryTransformType::BaseType(void) const {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.getBaseType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

enum UnaryTransformTypeUTTKind UnaryTransformType::UTTKind(void) const {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.getUTTKind();
  return static_cast<::pasta::UnaryTransformTypeUTTKind>(val);
}

std::optional<::pasta::Type> UnaryTransformType::UnderlyingType(void) const {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.getUnderlyingType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

bool UnaryTransformType::IsSugared(void) const {
  auto &self = *const_cast<clang::UnaryTransformType *>(u.UnaryTransformType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, UnresolvedUsingType)
::pasta::Type UnresolvedUsingType::Desugar(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingType *>(u.UnresolvedUsingType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingType::Declaration(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingType *>(u.UnresolvedUsingType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  throw std::runtime_error("UnresolvedUsingType::Declaration can return nullptr!");
}

bool UnresolvedUsingType::IsSugared(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingType *>(u.UnresolvedUsingType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, UsingType)
::pasta::Type UsingType::Desugar(void) const {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::UsingShadowDecl UsingType::FoundDeclaration(void) const {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.getFoundDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  throw std::runtime_error("UsingType::FoundDeclaration can return nullptr!");
}

::pasta::Type UsingType::UnderlyingType(void) const {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool UsingType::IsSugared(void) const {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool UsingType::TypeMatchesDeclaration(void) const {
  auto &self = *const_cast<clang::UsingType *>(u.UsingType);
  decltype(auto) val = self.typeMatchesDecl();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, VectorType)
PASTA_DEFINE_DERIVED_OPERATORS(VectorType, ExtVectorType)
::pasta::Type VectorType::Desugar(void) const {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type VectorType::ElementType(void) const {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

uint32_t VectorType::NumElements(void) const {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.getNumElements();
  return val;
}

enum VectorTypeVectorKind VectorType::VectorKind(void) const {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.getVectorKind();
  return static_cast<::pasta::VectorTypeVectorKind>(val);
}

bool VectorType::IsSugared(void) const {
  auto &self = *const_cast<clang::VectorType *>(u.VectorType);
  decltype(auto) val = self.isSugared();
  return val;
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
enum ElaboratedTypeKeyword TypeWithKeyword::Keyword(void) const {
  auto &self = *const_cast<clang::TypeWithKeyword *>(u.TypeWithKeyword);
  decltype(auto) val = self.getKeyword();
  return static_cast<::pasta::ElaboratedTypeKeyword>(val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, AdjustedType)
PASTA_DEFINE_DERIVED_OPERATORS(AdjustedType, DecayedType)
::pasta::Type AdjustedType::Desugar(void) const {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type AdjustedType::ResolvedType(void) const {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.getAdjustedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type AdjustedType::OriginalType(void) const {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.getOriginalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool AdjustedType::IsSugared(void) const {
  auto &self = *const_cast<clang::AdjustedType *>(u.AdjustedType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, ConstantArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, DependentSizedArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, IncompleteArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, VariableArrayType)
::pasta::Type ArrayType::ElementType(void) const {
  auto &self = *const_cast<clang::ArrayType *>(u.ArrayType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

uint32_t ArrayType::IndexTypeCVRQualifiers(void) const {
  auto &self = *const_cast<clang::ArrayType *>(u.ArrayType);
  decltype(auto) val = self.getIndexTypeCVRQualifiers();
  return val;
}

// 0: ArrayType::IndexTypeQualifiers
enum ArrayTypeArraySizeModifier ArrayType::SizeModifier(void) const {
  auto &self = *const_cast<clang::ArrayType *>(u.ArrayType);
  decltype(auto) val = self.getSizeModifier();
  return static_cast<::pasta::ArrayTypeArraySizeModifier>(val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, AtomicType)
::pasta::Type AtomicType::Desugar(void) const {
  auto &self = *const_cast<clang::AtomicType *>(u.AtomicType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type AtomicType::ValueType(void) const {
  auto &self = *const_cast<clang::AtomicType *>(u.AtomicType);
  decltype(auto) val = self.getValueType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool AtomicType::IsSugared(void) const {
  auto &self = *const_cast<clang::AtomicType *>(u.AtomicType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, AttributedType)
::pasta::Type AttributedType::Desugar(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Attr> AttributedType::Attribute(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getAttr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return AttrBuilder::Create<::pasta::Attr>(ast, val);
  }
}

enum ::pasta::AttrKind AttributedType::AttributeKind(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getAttrKind();
  return static_cast<enum ::pasta::AttrKind>(val);
}

::pasta::Type AttributedType::EquivalentType(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getEquivalentType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::NullabilityKind> AttributedType::ImmediateNullability(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getImmediateNullability();
  if (val.has_value()) {
    return static_cast<::pasta::NullabilityKind>(val.value());
  } else {
    return std::nullopt;
  }
}

::pasta::Type AttributedType::ModifiedType(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.getModifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool AttributedType::HasAttribute(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.hasAttr();
  return val;
}

bool AttributedType::IsCallingConv(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isCallingConv();
  return val;
}

bool AttributedType::IsMSTypeSpec(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isMSTypeSpec();
  return val;
}

bool AttributedType::IsQualifier(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isQualifier();
  return val;
}

bool AttributedType::IsSugared(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool AttributedType::IsWebAssemblyFuncrefSpec(void) const {
  auto &self = *const_cast<clang::AttributedType *>(u.AttributedType);
  decltype(auto) val = self.isWebAssemblyFuncrefSpec();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, BTFTagAttributedType)
::pasta::Type BTFTagAttributedType::Desugar(void) const {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::BTFTypeTagAttr BTFTagAttributedType::Attribute(void) const {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.getAttr();
  if (val) {
    return AttrBuilder::Create<::pasta::BTFTypeTagAttr>(ast, val);
  }
  throw std::runtime_error("BTFTagAttributedType::Attribute can return nullptr!");
}

::pasta::Type BTFTagAttributedType::WrappedType(void) const {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.getWrappedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool BTFTagAttributedType::IsSugared(void) const {
  auto &self = *const_cast<clang::BTFTagAttributedType *>(u.BTFTagAttributedType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, BitIntType)
::pasta::Type BitIntType::Desugar(void) const {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

uint32_t BitIntType::NumBits(void) const {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.getNumBits();
  return val;
}

bool BitIntType::IsSigned(void) const {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.isSigned();
  return val;
}

bool BitIntType::IsSugared(void) const {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool BitIntType::IsUnsigned(void) const {
  auto &self = *const_cast<clang::BitIntType *>(u.BitIntType);
  decltype(auto) val = self.isUnsigned();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, BlockPointerType)
::pasta::Type BlockPointerType::Desugar(void) const {
  auto &self = *const_cast<clang::BlockPointerType *>(u.BlockPointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type BlockPointerType::PointeeType(void) const {
  auto &self = *const_cast<clang::BlockPointerType *>(u.BlockPointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool BlockPointerType::IsSugared(void) const {
  auto &self = *const_cast<clang::BlockPointerType *>(u.BlockPointerType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, BuiltinType)
::pasta::Type BuiltinType::Desugar(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::BuiltinTypeKind BuiltinType::BuiltinKind(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::BuiltinTypeKind>(val);
}

// 1: BuiltinType::Name
// 1: BuiltinType::NameAsCString
bool BuiltinType::IsFloatingPoint(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isFloatingPoint();
  return val;
}

bool BuiltinType::IsInteger(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isInteger();
  return val;
}

bool BuiltinType::IsNonOverloadPlaceholderType(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isNonOverloadPlaceholderType();
  return val;
}

bool BuiltinType::IsPlaceholderType(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isPlaceholderType();
  return val;
}

bool BuiltinType::IsSVEBool(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSVEBool();
  return val;
}

bool BuiltinType::IsSVECount(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSVECount();
  return val;
}

bool BuiltinType::IsSignedInteger(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSignedInteger();
  return val;
}

bool BuiltinType::IsSugared(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool BuiltinType::IsUnsignedInteger(void) const {
  auto &self = *const_cast<clang::BuiltinType *>(u.BuiltinType);
  decltype(auto) val = self.isUnsignedInteger();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ComplexType)
::pasta::Type ComplexType::Desugar(void) const {
  auto &self = *const_cast<clang::ComplexType *>(u.ComplexType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ComplexType::ElementType(void) const {
  auto &self = *const_cast<clang::ComplexType *>(u.ComplexType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool ComplexType::IsSugared(void) const {
  auto &self = *const_cast<clang::ComplexType *>(u.ComplexType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, ConstantArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, ConstantArrayType)
::pasta::Type ConstantArrayType::Desugar(void) const {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

llvm::APInt ConstantArrayType::Size(void) const {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.getSize();
  return val;
}

std::optional<::pasta::Expr> ConstantArrayType::SizeExpression(void) const {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.getSizeExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

bool ConstantArrayType::IsSugared(void) const {
  auto &self = *const_cast<clang::ConstantArrayType *>(u.ConstantArrayType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(AdjustedType, DecayedType)
PASTA_DEFINE_BASE_OPERATORS(Type, DecayedType)
::pasta::Type DecayedType::ResolvedType(void) const {
  auto &self = *const_cast<clang::DecayedType *>(u.DecayedType);
  decltype(auto) val = self.getDecayedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type DecayedType::PointeeType(void) const {
  auto &self = *const_cast<clang::DecayedType *>(u.DecayedType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, DecltypeType)
::pasta::Type DecltypeType::Desugar(void) const {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DecltypeType::UnderlyingExpression(void) const {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.getUnderlyingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DecltypeType::UnderlyingExpression can return nullptr!");
}

::pasta::Type DecltypeType::UnderlyingType(void) const {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool DecltypeType::IsSugared(void) const {
  auto &self = *const_cast<clang::DecltypeType *>(u.DecltypeType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DeducedType)
PASTA_DEFINE_DERIVED_OPERATORS(DeducedType, AutoType)
PASTA_DEFINE_DERIVED_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
::pasta::Type DeducedType::Desugar(void) const {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Type> DeducedType::ResolvedType(void) const {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.getDeducedType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

bool DeducedType::IsDeduced(void) const {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.isDeduced();
  return val;
}

bool DeducedType::IsSugared(void) const {
  auto &self = *const_cast<clang::DeducedType *>(u.DeducedType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentAddressSpaceType)
::pasta::Type DependentAddressSpaceType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentAddressSpaceType::AddressSpaceExpression(void) const {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.getAddrSpaceExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentAddressSpaceType::AddressSpaceExpression can return nullptr!");
}

::pasta::Token DependentAddressSpaceType::AttributeToken(void) const {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Type DependentAddressSpaceType::PointeeType(void) const {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool DependentAddressSpaceType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentAddressSpaceType *>(u.DependentAddressSpaceType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentBitIntType)
::pasta::Type DependentBitIntType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentBitIntType::NumBitsExpression(void) const {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.getNumBitsExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentBitIntType::NumBitsExpression can return nullptr!");
}

bool DependentBitIntType::IsSigned(void) const {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.isSigned();
  return val;
}

bool DependentBitIntType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool DependentBitIntType::IsUnsigned(void) const {
  auto &self = *const_cast<clang::DependentBitIntType *>(u.DependentBitIntType);
  decltype(auto) val = self.isUnsigned();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentNameType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, DependentNameType)
::pasta::Type DependentNameType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentNameType *>(u.DependentNameType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: DependentNameType::Identifier
// 0: DependentNameType::Qualifier
bool DependentNameType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentNameType *>(u.DependentNameType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, DependentSizedArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedArrayType)
::pasta::Type DependentSizedArrayType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange DependentSizedArrayType::BracketsRange(void) const {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getBracketsRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token DependentSizedArrayType::LBracketToken(void) const {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getLBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentSizedArrayType::RBracketToken(void) const {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> DependentSizedArrayType::SizeExpression(void) const {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.getSizeExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

bool DependentSizedArrayType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentSizedArrayType *>(u.DependentSizedArrayType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedExtVectorType)
::pasta::Type DependentSizedExtVectorType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Token DependentSizedExtVectorType::AttributeToken(void) const {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Type DependentSizedExtVectorType::ElementType(void) const {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentSizedExtVectorType::SizeExpression(void) const {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentSizedExtVectorType::SizeExpression can return nullptr!");
}

bool DependentSizedExtVectorType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentSizedExtVectorType *>(u.DependentSizedExtVectorType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentTemplateSpecializationType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, DependentTemplateSpecializationType)
::pasta::Type DependentTemplateSpecializationType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: DependentTemplateSpecializationType::Identifier
// 0: DependentTemplateSpecializationType::Qualifier
bool DependentTemplateSpecializationType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.isSugared();
  return val;
}

std::vector<::pasta::TemplateArgument> DependentTemplateSpecializationType::TemplateArguments(void) const {
  auto &self = *const_cast<clang::DependentTemplateSpecializationType *>(u.DependentTemplateSpecializationType);
  decltype(auto) val = self.template_arguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentVectorType)
::pasta::Type DependentVectorType::Desugar(void) const {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Token DependentVectorType::AttributeToken(void) const {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Type DependentVectorType::ElementType(void) const {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentVectorType::SizeExpression(void) const {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentVectorType::SizeExpression can return nullptr!");
}

enum VectorTypeVectorKind DependentVectorType::VectorKind(void) const {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.getVectorKind();
  return static_cast<::pasta::VectorTypeVectorKind>(val);
}

bool DependentVectorType::IsSugared(void) const {
  auto &self = *const_cast<clang::DependentVectorType *>(u.DependentVectorType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ElaboratedType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, ElaboratedType)
::pasta::Type ElaboratedType::Desugar(void) const {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ElaboratedType::NamedType(void) const {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.getNamedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::TagDecl> ElaboratedType::OwnedTagDeclaration(void) const {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.getOwnedTagDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
}

// 0: ElaboratedType::Qualifier
bool ElaboratedType::IsSugared(void) const {
  auto &self = *const_cast<clang::ElaboratedType *>(u.ElaboratedType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ExtVectorType)
PASTA_DEFINE_BASE_OPERATORS(VectorType, ExtVectorType)
::pasta::Type ExtVectorType::Desugar(void) const {
  auto &self = *const_cast<clang::ExtVectorType *>(u.ExtVectorType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 2: IsAccessorWithinNumElements
bool ExtVectorType::IsSugared(void) const {
  auto &self = *const_cast<clang::ExtVectorType *>(u.ExtVectorType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, FunctionType)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionType, FunctionNoProtoType)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionType, FunctionProtoType)
enum CallingConv FunctionType::CallConv(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getCallConv();
  return static_cast<::pasta::CallingConv>(val);
}

::pasta::Type FunctionType::CallResultType(void) const {
  auto &self = *(u.FunctionType);
  decltype(auto) val = self.getCallResultType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool FunctionType::CmseNSCallAttribute(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getCmseNSCallAttr();
  return val;
}

// 0: FunctionType::ExtInfo
bool FunctionType::HasRegParm(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getHasRegParm();
  return val;
}

bool FunctionType::NoReturnAttribute(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getNoReturnAttr();
  return val;
}

uint32_t FunctionType::RegParmType(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getRegParmType();
  return val;
}

::pasta::Type FunctionType::ReturnType(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.getReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool FunctionType::IsConst(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.isConst();
  return val;
}

bool FunctionType::IsRestrict(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.isRestrict();
  return val;
}

bool FunctionType::IsVolatile(void) const {
  auto &self = *const_cast<clang::FunctionType *>(u.FunctionType);
  decltype(auto) val = self.isVolatile();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, IncompleteArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, IncompleteArrayType)
::pasta::Type IncompleteArrayType::Desugar(void) const {
  auto &self = *const_cast<clang::IncompleteArrayType *>(u.IncompleteArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool IncompleteArrayType::IsSugared(void) const {
  auto &self = *const_cast<clang::IncompleteArrayType *>(u.IncompleteArrayType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, InjectedClassNameType)
::pasta::Type InjectedClassNameType::Desugar(void) const {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::CXXRecordDecl InjectedClassNameType::Declaration(void) const {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("InjectedClassNameType::Declaration can return nullptr!");
}

::pasta::Type InjectedClassNameType::InjectedSpecializationType(void) const {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.getInjectedSpecializationType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::TemplateSpecializationType InjectedClassNameType::InjectedTST(void) const {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.getInjectedTST();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateSpecializationType>(ast, val);
  }
  throw std::runtime_error("InjectedClassNameType::InjectedTST can return nullptr!");
}

// 0: InjectedClassNameType::TemplateName
bool InjectedClassNameType::IsSugared(void) const {
  auto &self = *const_cast<clang::InjectedClassNameType *>(u.InjectedClassNameType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, MacroQualifiedType)
::pasta::Type MacroQualifiedType::Desugar(void) const {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: MacroQualifiedType::MacroIdentifier
::pasta::Type MacroQualifiedType::ModifiedType(void) const {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.getModifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type MacroQualifiedType::UnderlyingType(void) const {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool MacroQualifiedType::IsSugared(void) const {
  auto &self = *const_cast<clang::MacroQualifiedType *>(u.MacroQualifiedType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, MatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(MatrixType, ConstantMatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(MatrixType, DependentSizedMatrixType)
::pasta::Type MatrixType::Desugar(void) const {
  auto &self = *const_cast<clang::MatrixType *>(u.MatrixType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type MatrixType::ElementType(void) const {
  auto &self = *const_cast<clang::MatrixType *>(u.MatrixType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool MatrixType::IsSugared(void) const {
  auto &self = *const_cast<clang::MatrixType *>(u.MatrixType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, MemberPointerType)
::pasta::Type MemberPointerType::Desugar(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type MemberPointerType::Class(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.getClass();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  throw std::runtime_error("MemberPointerType::Class can return nullptr!");
}

::pasta::CXXRecordDecl MemberPointerType::MostRecentCXXRecordDeclaration(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.getMostRecentCXXRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("MemberPointerType::MostRecentCXXRecordDeclaration can return nullptr!");
}

::pasta::Type MemberPointerType::PointeeType(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool MemberPointerType::IsMemberDataPointer(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.isMemberDataPointer();
  return val;
}

bool MemberPointerType::IsMemberFunctionPointer(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.isMemberFunctionPointer();
  return val;
}

bool MemberPointerType::IsSugared(void) const {
  auto &self = *const_cast<clang::MemberPointerType *>(u.MemberPointerType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCObjectPointerType)
::pasta::Type ObjCObjectPointerType::Desugar(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCInterfaceDecl ObjCObjectPointerType::InterfaceDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getInterfaceDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCObjectPointerType::InterfaceDeclaration can return nullptr!");
}

::pasta::ObjCInterfaceType ObjCObjectPointerType::InterfaceType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getInterfaceType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCInterfaceType>(ast, val);
  }
  throw std::runtime_error("ObjCObjectPointerType::InterfaceType can return nullptr!");
}

uint32_t ObjCObjectPointerType::NumProtocols(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getNumProtocols();
  return val;
}

::pasta::ObjCObjectType ObjCObjectPointerType::ObjectType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getObjectType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  throw std::runtime_error("ObjCObjectPointerType::ObjectType can return nullptr!");
}

::pasta::Type ObjCObjectPointerType::PointeeType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 1: ObjCObjectPointerType::Protocol
::pasta::Type ObjCObjectPointerType::SuperClassType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getSuperClassType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::vector<::pasta::Type> ObjCObjectPointerType::TypeArguments(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getTypeArgs();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

std::vector<::pasta::Type> ObjCObjectPointerType::TypeArgumentsAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.getTypeArgsAsWritten();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

bool ObjCObjectPointerType::IsKindOfType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isKindOfType();
  return val;
}

bool ObjCObjectPointerType::IsObjCClassType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCClassType();
  return val;
}

bool ObjCObjectPointerType::IsObjCIdOrClassType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCIdOrClassType();
  return val;
}

bool ObjCObjectPointerType::IsObjCIdType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCIdType();
  return val;
}

bool ObjCObjectPointerType::IsObjCQualifiedClassType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCQualifiedClassType();
  return val;
}

bool ObjCObjectPointerType::IsObjCQualifiedIdType(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isObjCQualifiedIdType();
  return val;
}

bool ObjCObjectPointerType::IsSpecialized(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isSpecialized();
  return val;
}

bool ObjCObjectPointerType::IsSpecializedAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isSpecializedAsWritten();
  return val;
}

bool ObjCObjectPointerType::IsSugared(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool ObjCObjectPointerType::IsUnspecialized(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isUnspecialized();
  return val;
}

bool ObjCObjectPointerType::IsUnspecializedAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.isUnspecializedAsWritten();
  return val;
}

// 0: ObjCObjectPointerType::
// 0: ObjCObjectPointerType::
// 0: ObjCObjectPointerType::
std::vector<::pasta::ObjCProtocolDecl> ObjCObjectPointerType::Qualifiers(void) const {
  auto &self = *const_cast<clang::ObjCObjectPointerType *>(u.ObjCObjectPointerType);
  decltype(auto) val = self.quals();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::ObjCObjectPointerType ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  decltype(auto) val = self.stripObjCKindOfTypeAndQuals(ast->ci->getASTContext());
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  throw std::runtime_error("ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers can return nullptr!");
}

std::vector<::pasta::ObjCProtocolDecl> ObjCObjectPointerType::Protocols(void) const {
  std::vector<::pasta::ObjCProtocolDecl> ret;
  auto convert_elem = [&] (clang::ObjCProtocolDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
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
::pasta::Type ObjCObjectType::Desugar(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ObjCObjectType::BaseType(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getBaseType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCInterfaceDecl ObjCObjectType::Interface(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCObjectType::Interface can return nullptr!");
}

std::optional<::pasta::Type> ObjCObjectType::SuperClassType(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getSuperClassType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::vector<::pasta::Type> ObjCObjectType::TypeArguments(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getTypeArgs();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

std::vector<::pasta::Type> ObjCObjectType::TypeArgumentsAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.getTypeArgsAsWritten();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

bool ObjCObjectType::IsKindOfType(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isKindOfType();
  return val;
}

bool ObjCObjectType::IsKindOfTypeAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isKindOfTypeAsWritten();
  return val;
}

bool ObjCObjectType::IsObjCClass(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCClass();
  return val;
}

bool ObjCObjectType::IsObjCId(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCId();
  return val;
}

bool ObjCObjectType::IsObjCQualifiedClass(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCQualifiedClass();
  return val;
}

bool ObjCObjectType::IsObjCQualifiedId(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCQualifiedId();
  return val;
}

bool ObjCObjectType::IsObjCUnqualifiedClass(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCUnqualifiedClass();
  return val;
}

bool ObjCObjectType::IsObjCUnqualifiedId(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCUnqualifiedId();
  return val;
}

bool ObjCObjectType::IsObjCUnqualifiedIdOrClass(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isObjCUnqualifiedIdOrClass();
  return val;
}

bool ObjCObjectType::IsSpecialized(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isSpecialized();
  return val;
}

bool ObjCObjectType::IsSpecializedAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isSpecializedAsWritten();
  return val;
}

bool ObjCObjectType::IsSugared(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool ObjCObjectType::IsUnspecialized(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isUnspecialized();
  return val;
}

bool ObjCObjectType::IsUnspecializedAsWritten(void) const {
  auto &self = *const_cast<clang::ObjCObjectType *>(u.ObjCObjectType);
  decltype(auto) val = self.isUnspecializedAsWritten();
  return val;
}

::pasta::Type ObjCObjectType::StripObjCKindOfTypeAndQualifiers(void) const {
  auto &self = *(u.ObjCObjectType);
  decltype(auto) val = self.stripObjCKindOfTypeAndQuals(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCTypeParamType)
::pasta::Type ObjCTypeParamType::Desugar(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamType *>(u.ObjCTypeParamType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCTypeParamDecl ObjCTypeParamType::Declaration(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamType *>(u.ObjCTypeParamType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCTypeParamDecl>(ast, val);
  }
  throw std::runtime_error("ObjCTypeParamType::Declaration can return nullptr!");
}

bool ObjCTypeParamType::IsSugared(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamType *>(u.ObjCTypeParamType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, PackExpansionType)
::pasta::Type PackExpansionType::Desugar(void) const {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<unsigned> PackExpansionType::NumExpansions(void) const {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.getNumExpansions();
  if (val.has_value()) {
    return val.value();
  } else {
    return std::nullopt;
  }
}

::pasta::Type PackExpansionType::Pattern(void) const {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.getPattern();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool PackExpansionType::IsSugared(void) const {
  auto &self = *const_cast<clang::PackExpansionType *>(u.PackExpansionType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ParenType)
::pasta::Type ParenType::Desugar(void) const {
  auto &self = *const_cast<clang::ParenType *>(u.ParenType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ParenType::InnerType(void) const {
  auto &self = *const_cast<clang::ParenType *>(u.ParenType);
  decltype(auto) val = self.getInnerType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool ParenType::IsSugared(void) const {
  auto &self = *const_cast<clang::ParenType *>(u.ParenType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, PipeType)
::pasta::Type PipeType::Desugar(void) const {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type PipeType::ElementType(void) const {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.getElementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool PipeType::IsReadOnly(void) const {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.isReadOnly();
  return val;
}

bool PipeType::IsSugared(void) const {
  auto &self = *const_cast<clang::PipeType *>(u.PipeType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, PointerType)
::pasta::Type PointerType::Desugar(void) const {
  auto &self = *const_cast<clang::PointerType *>(u.PointerType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type PointerType::PointeeType(void) const {
  auto &self = *const_cast<clang::PointerType *>(u.PointerType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool PointerType::IsSugared(void) const {
  auto &self = *const_cast<clang::PointerType *>(u.PointerType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, QualifiedType)
::pasta::Type QualifiedType::IgnoreParentheses(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.IgnoreParens();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

enum LangAS QualifiedType::AddressSpace(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getAddressSpace();
  return static_cast<::pasta::LangAS>(val);
}

// 0: QualifiedType::
::pasta::Type QualifiedType::AtomicUnqualifiedType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getAtomicUnqualifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: QualifiedType::BaseTypeIdentifier
uint32_t QualifiedType::CVRQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getCVRQualifiers();
  return val;
}

::pasta::Type QualifiedType::CanonicalType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getCanonicalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type QualifiedType::DesugaredType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getDesugaredType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

uint32_t QualifiedType::LocalCVRQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getLocalCVRQualifiers();
  return val;
}

uint32_t QualifiedType::LocalFastQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getLocalFastQualifiers();
  return val;
}

// 0: QualifiedType::LocalQualifiers
::pasta::Type QualifiedType::LocalUnqualifiedType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getLocalUnqualifiedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type QualifiedType::NonLValueExpressionType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getNonLValueExprType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type QualifiedType::NonPackExpansionType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getNonPackExpansionType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type QualifiedType::NonReferenceType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getNonReferenceType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: QualifiedType::ObjCGCAttr
// 0: QualifiedType::ObjCLifetime
// 0: QualifiedType::Qualifiers
::pasta::Type QualifiedType::SingleStepDesugaredType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.getSingleStepDesugaredType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: QualifiedType::SplitDesugaredType
// 0: QualifiedType::SplitUnqualifiedType
// 0: QualifiedType::
// 0: QualifiedType::
// 0: QualifiedType::
bool QualifiedType::HasAddressSpace(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasAddressSpace();
  return val;
}

bool QualifiedType::HasLocalNonFastQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasLocalNonFastQualifiers();
  return val;
}

bool QualifiedType::HasLocalQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasLocalQualifiers();
  return val;
}

bool QualifiedType::HasNonTrivialObjCLifetime(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasNonTrivialObjCLifetime();
  return val;
}

bool QualifiedType::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
}

bool QualifiedType::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
}

bool QualifiedType::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
}

bool QualifiedType::HasQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasQualifiers();
  return val;
}

bool QualifiedType::HasStrongOrWeakObjCLifetime(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.hasStrongOrWeakObjCLifetime();
  return val;
}

// 1: QualifiedType::IsAddressSpaceOverlapping
// 1: QualifiedType::IsAtLeastAsQualifiedAs
bool QualifiedType::IsCForbiddenLValueType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isCForbiddenLValueType();
  return val;
}

bool QualifiedType::IsCXX11PODType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isCXX11PODType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsCXX98PODType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isCXX98PODType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsCanonical(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isCanonical();
  return val;
}

bool QualifiedType::IsCanonicalAsParameter(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isCanonicalAsParam();
  return val;
}

bool QualifiedType::IsConstQualified(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isConstQualified();
  return val;
}

bool QualifiedType::IsConstant(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isConstant(ast->ci->getASTContext());
  return val;
}

// 0: QualifiedType::IsDestructedType
bool QualifiedType::IsLocalConstQualified(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isLocalConstQualified();
  return val;
}

bool QualifiedType::IsLocalRestrictQualified(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isLocalRestrictQualified();
  return val;
}

bool QualifiedType::IsLocalVolatileQualified(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isLocalVolatileQualified();
  return val;
}

// 1: QualifiedType::IsMoreQualifiedThan
// 0: QualifiedType::IsNonTrivialToPrimitiveCopy
// 0: QualifiedType::IsNonTrivialToPrimitiveDefaultInitialize
// 0: QualifiedType::IsNonTrivialToPrimitiveDestructiveMove
bool QualifiedType::IsNonWeakInMRRWithObjCWeak(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isNonWeakInMRRWithObjCWeak(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsNull(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isNull();
  return val;
}

bool QualifiedType::IsObjCGCStrong(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isObjCGCStrong();
  return val;
}

bool QualifiedType::IsObjCGCWeak(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isObjCGCWeak();
  return val;
}

bool QualifiedType::IsPODType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isPODType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsReferenceable(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isReferenceable();
  return val;
}

bool QualifiedType::IsRestrictQualified(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isRestrictQualified();
  return val;
}

bool QualifiedType::IsTrivialType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isTrivialType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsTriviallyCopyableType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isTriviallyCopyableType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsTriviallyEqualityComparableType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isTriviallyEqualityComparableType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsTriviallyRelocatableType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isTriviallyRelocatableType(ast->ci->getASTContext());
  return val;
}

bool QualifiedType::IsVolatileQualified(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isVolatileQualified();
  return val;
}

bool QualifiedType::IsWebAssemblyExternrefType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isWebAssemblyExternrefType();
  return val;
}

bool QualifiedType::IsWebAssemblyFuncrefType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isWebAssemblyFuncrefType();
  return val;
}

bool QualifiedType::IsWebAssemblyReferenceType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.isWebAssemblyReferenceType();
  return val;
}

bool QualifiedType::MayBeDynamicClass(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.mayBeDynamicClass();
  return val;
}

bool QualifiedType::MayBeNotDynamicClass(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.mayBeNotDynamicClass();
  return val;
}

// 0: QualifiedType::Split
// 1: QualifiedType::Stream
::pasta::Type QualifiedType::StripObjCKindOfType(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.stripObjCKindOfType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 3: QualifiedType::SubstObjCMemberType
// 3: QualifiedType::SubstObjCTypeArguments
// 1: QualifiedType::WithCVRQualifiers
::pasta::Type QualifiedType::WithConst(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.withConst();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 1: QualifiedType::WithExactLocalFastQualifiers
// 1: QualifiedType::WithFastQualifiers
::pasta::Type QualifiedType::WithRestrict(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.withRestrict();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type QualifiedType::WithVolatile(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.withVolatile();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type QualifiedType::WithoutLocalFastQualifiers(void) const {
  auto self = RawQualType();
  decltype(auto) val = self.withoutLocalFastQualifiers();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, ReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(ReferenceType, LValueReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(ReferenceType, RValueReferenceType)
::pasta::Type ReferenceType::PointeeType(void) const {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.getPointeeType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ReferenceType::PointeeTypeAsWritten(void) const {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.getPointeeTypeAsWritten();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool ReferenceType::IsInnerReference(void) const {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.isInnerRef();
  return val;
}

bool ReferenceType::IsSpelledAsLValue(void) const {
  auto &self = *const_cast<clang::ReferenceType *>(u.ReferenceType);
  decltype(auto) val = self.isSpelledAsLValue();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, SubstTemplateTypeParmPackType)
::pasta::Type SubstTemplateTypeParmPackType::Desugar(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: SubstTemplateTypeParmPackType::ArgumentPack
::pasta::Decl SubstTemplateTypeParmPackType::AssociatedDeclaration(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getAssociatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  throw std::runtime_error("SubstTemplateTypeParmPackType::AssociatedDeclaration can return nullptr!");
}

bool SubstTemplateTypeParmPackType::Final(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getFinal();
  return val;
}

// 0: SubstTemplateTypeParmPackType::Identifier
uint32_t SubstTemplateTypeParmPackType::Index(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getIndex();
  return val;
}

uint32_t SubstTemplateTypeParmPackType::NumArguments(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getNumArgs();
  return val;
}

::pasta::TemplateTypeParmDecl SubstTemplateTypeParmPackType::ReplacedParameter(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.getReplacedParameter();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateTypeParmDecl>(ast, val);
  }
  throw std::runtime_error("SubstTemplateTypeParmPackType::ReplacedParameter can return nullptr!");
}

bool SubstTemplateTypeParmPackType::IsSugared(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmPackType *>(u.SubstTemplateTypeParmPackType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, SubstTemplateTypeParmType)
::pasta::Type SubstTemplateTypeParmType::Desugar(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Decl SubstTemplateTypeParmType::AssociatedDeclaration(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getAssociatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  throw std::runtime_error("SubstTemplateTypeParmType::AssociatedDeclaration can return nullptr!");
}

uint32_t SubstTemplateTypeParmType::Index(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getIndex();
  return val;
}

std::optional<unsigned> SubstTemplateTypeParmType::PackIndex(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getPackIndex();
  if (val.has_value()) {
    return val.value();
  } else {
    return std::nullopt;
  }
}

::pasta::TemplateTypeParmDecl SubstTemplateTypeParmType::ReplacedParameter(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getReplacedParameter();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateTypeParmDecl>(ast, val);
  }
  throw std::runtime_error("SubstTemplateTypeParmType::ReplacedParameter can return nullptr!");
}

::pasta::Type SubstTemplateTypeParmType::ReplacementType(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.getReplacementType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool SubstTemplateTypeParmType::IsSugared(void) const {
  auto &self = *const_cast<clang::SubstTemplateTypeParmType *>(u.SubstTemplateTypeParmType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TagType)
PASTA_DEFINE_DERIVED_OPERATORS(TagType, EnumType)
PASTA_DEFINE_DERIVED_OPERATORS(TagType, RecordType)
::pasta::TagDecl TagType::Declaration(void) const {
  auto &self = *const_cast<clang::TagType *>(u.TagType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  throw std::runtime_error("TagType::Declaration can return nullptr!");
}

bool TagType::IsBeingDefined(void) const {
  auto &self = *const_cast<clang::TagType *>(u.TagType);
  decltype(auto) val = self.isBeingDefined();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TemplateSpecializationType)
::pasta::Type TemplateSpecializationType::Desugar(void) const {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Type> TemplateSpecializationType::AliasedType(void) const {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  if (!self.isTypeAlias()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getAliasedType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

// 0: TemplateSpecializationType::TemplateName
bool TemplateSpecializationType::IsCurrentInstantiation(void) const {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.isCurrentInstantiation();
  return val;
}

bool TemplateSpecializationType::IsSugared(void) const {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool TemplateSpecializationType::IsTypeAlias(void) const {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.isTypeAlias();
  return val;
}

std::vector<::pasta::TemplateArgument> TemplateSpecializationType::TemplateArguments(void) const {
  auto &self = *const_cast<clang::TemplateSpecializationType *>(u.TemplateSpecializationType);
  decltype(auto) val = self.template_arguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TemplateTypeParmType)
::pasta::Type TemplateTypeParmType::Desugar(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::TemplateTypeParmDecl> TemplateTypeParmType::Declaration(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.getDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateTypeParmDecl>(ast, val);
  }
}

uint32_t TemplateTypeParmType::Depth(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.getDepth();
  return val;
}

// 0: TemplateTypeParmType::Identifier
uint32_t TemplateTypeParmType::Index(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.getIndex();
  return val;
}

bool TemplateTypeParmType::IsParameterPack(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool TemplateTypeParmType::IsSugared(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmType *>(u.TemplateTypeParmType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, VariableArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, VariableArrayType)
::pasta::Type VariableArrayType::Desugar(void) const {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange VariableArrayType::BracketsRange(void) const {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getBracketsRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token VariableArrayType::LBracketToken(void) const {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getLBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Token VariableArrayType::RBracketToken(void) const {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr VariableArrayType::SizeExpression(void) const {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("VariableArrayType::SizeExpression can return nullptr!");
}

bool VariableArrayType::IsSugared(void) const {
  auto &self = *const_cast<clang::VariableArrayType *>(u.VariableArrayType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(DeducedType, AutoType)
PASTA_DEFINE_BASE_OPERATORS(Type, AutoType)
enum AutoTypeKeyword AutoType::Keyword(void) const {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getKeyword();
  return static_cast<::pasta::AutoTypeKeyword>(val);
}

std::vector<::pasta::TemplateArgument> AutoType::TypeConstraintArguments(void) const {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getTypeConstraintArguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
}

std::optional<::pasta::ConceptDecl> AutoType::TypeConstraintConcept(void) const {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.getTypeConstraintConcept();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
}

bool AutoType::IsConstrained(void) const {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.isConstrained();
  return val;
}

bool AutoType::IsDecltypeAuto(void) const {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.isDecltypeAuto();
  return val;
}

bool AutoType::IsGNUAutoType(void) const {
  auto &self = *const_cast<clang::AutoType *>(u.AutoType);
  decltype(auto) val = self.isGNUAutoType();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(MatrixType, ConstantMatrixType)
PASTA_DEFINE_BASE_OPERATORS(Type, ConstantMatrixType)
uint32_t ConstantMatrixType::NumColumns(void) const {
  auto &self = *const_cast<clang::ConstantMatrixType *>(u.ConstantMatrixType);
  decltype(auto) val = self.getNumColumns();
  return val;
}

uint32_t ConstantMatrixType::NumElementsFlattened(void) const {
  auto &self = *const_cast<clang::ConstantMatrixType *>(u.ConstantMatrixType);
  decltype(auto) val = self.getNumElementsFlattened();
  return val;
}

uint32_t ConstantMatrixType::NumRows(void) const {
  auto &self = *const_cast<clang::ConstantMatrixType *>(u.ConstantMatrixType);
  decltype(auto) val = self.getNumRows();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
PASTA_DEFINE_BASE_OPERATORS(Type, DeducedTemplateSpecializationType)
// 0: DeducedTemplateSpecializationType::TemplateName
PASTA_DEFINE_BASE_OPERATORS(MatrixType, DependentSizedMatrixType)
PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedMatrixType)
::pasta::Token DependentSizedMatrixType::AttributeToken(void) const {
  auto &self = *const_cast<clang::DependentSizedMatrixType *>(u.DependentSizedMatrixType);
  decltype(auto) val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DependentSizedMatrixType::ColumnExpression(void) const {
  auto &self = *const_cast<clang::DependentSizedMatrixType *>(u.DependentSizedMatrixType);
  decltype(auto) val = self.getColumnExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentSizedMatrixType::ColumnExpression can return nullptr!");
}

::pasta::Expr DependentSizedMatrixType::RowExpression(void) const {
  auto &self = *const_cast<clang::DependentSizedMatrixType *>(u.DependentSizedMatrixType);
  decltype(auto) val = self.getRowExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentSizedMatrixType::RowExpression can return nullptr!");
}

PASTA_DEFINE_BASE_OPERATORS(TagType, EnumType)
PASTA_DEFINE_BASE_OPERATORS(Type, EnumType)
::pasta::Type EnumType::Desugar(void) const {
  auto &self = *const_cast<clang::EnumType *>(u.EnumType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::EnumDecl EnumType::Declaration(void) const {
  auto &self = *const_cast<clang::EnumType *>(u.EnumType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  throw std::runtime_error("EnumType::Declaration can return nullptr!");
}

bool EnumType::IsSugared(void) const {
  auto &self = *const_cast<clang::EnumType *>(u.EnumType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(FunctionType, FunctionNoProtoType)
PASTA_DEFINE_BASE_OPERATORS(Type, FunctionNoProtoType)
::pasta::Type FunctionNoProtoType::Desugar(void) const {
  auto &self = *const_cast<clang::FunctionNoProtoType *>(u.FunctionNoProtoType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool FunctionNoProtoType::IsSugared(void) const {
  auto &self = *const_cast<clang::FunctionNoProtoType *>(u.FunctionNoProtoType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(FunctionType, FunctionProtoType)
PASTA_DEFINE_BASE_OPERATORS(Type, FunctionProtoType)
std::optional<enum CanThrowResult> FunctionProtoType::CanThrow(void) const {
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
}

::pasta::Type FunctionProtoType::Desugar(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: FunctionProtoType::
// 0: FunctionProtoType::
std::vector<::pasta::Type> FunctionProtoType::Exceptions(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.exceptions();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

::pasta::Token FunctionProtoType::EllipsisToken(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::FunctionDecl> FunctionProtoType::ExceptionSpecDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getExceptionSpecDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

// 0: FunctionProtoType::ExceptionSpecInfo
std::optional<::pasta::FunctionDecl> FunctionProtoType::ExceptionSpecTemplate(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getExceptionSpecTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

enum ExceptionSpecificationType FunctionProtoType::ExceptionSpecType(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(val);
}

// 1: FunctionProtoType::ExceptionType
// 1: FunctionProtoType::ExtParameterInfo
// 0: FunctionProtoType::ExtParameterInfos
// 0: FunctionProtoType::ExtParameterInfosOrNull
// 0: FunctionProtoType::ExtProtoInfo
// 0: FunctionProtoType::MethodQualifiers
std::optional<::pasta::Expr> FunctionProtoType::NoexceptExpression(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getNoexceptExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

uint32_t FunctionProtoType::NumExceptions(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getNumExceptions();
  return val;
}

uint32_t FunctionProtoType::NumParameters(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getNumParams();
  return val;
}

// 1: FunctionProtoType::ParameterType
std::vector<::pasta::Type> FunctionProtoType::ParameterTypes(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getParamTypes();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

// 1: FunctionProtoType::ParameterABI
enum RefQualifierKind FunctionProtoType::ReferenceQualifier(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(val);
}

bool FunctionProtoType::HasDependentExceptionSpec(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasDependentExceptionSpec();
  return val;
}

bool FunctionProtoType::HasDynamicExceptionSpec(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasDynamicExceptionSpec();
  return val;
}

bool FunctionProtoType::HasExceptionSpec(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasExceptionSpec();
  return val;
}

bool FunctionProtoType::HasExtParameterInfos(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasExtParameterInfos();
  return val;
}

bool FunctionProtoType::HasInstantiationDependentExceptionSpec(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasInstantiationDependentExceptionSpec();
  return val;
}

bool FunctionProtoType::HasNoexceptExceptionSpec(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasNoexceptExceptionSpec();
  return val;
}

bool FunctionProtoType::HasTrailingReturn(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.hasTrailingReturn();
  return val;
}

std::optional<bool> FunctionProtoType::IsNothrow(void) const {
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
}

// 1: FunctionProtoType::IsParameterConsumed
bool FunctionProtoType::IsSugared(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.isSugared();
  return val;
}

bool FunctionProtoType::IsTemplateVariadic(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.isTemplateVariadic();
  return val;
}

bool FunctionProtoType::IsVariadic(void) const {
  auto &self = *const_cast<clang::FunctionProtoType *>(u.FunctionProtoType);
  decltype(auto) val = self.isVariadic();
  return val;
}

// 0: FunctionProtoType::
// 0: FunctionProtoType::
std::vector<::pasta::Type> FunctionProtoType::ExceptionTypes(void) const {
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
::pasta::Type LValueReferenceType::Desugar(void) const {
  auto &self = *const_cast<clang::LValueReferenceType *>(u.LValueReferenceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool LValueReferenceType::IsSugared(void) const {
  auto &self = *const_cast<clang::LValueReferenceType *>(u.LValueReferenceType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ObjCObjectType, ObjCInterfaceType)
PASTA_DEFINE_BASE_OPERATORS(Type, ObjCInterfaceType)
::pasta::Type ObjCInterfaceType::Desugar(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceType *>(u.ObjCInterfaceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCInterfaceDecl ObjCInterfaceType::Declaration(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceType *>(u.ObjCInterfaceType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceType::Declaration can return nullptr!");
}

bool ObjCInterfaceType::IsSugared(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceType *>(u.ObjCInterfaceType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ReferenceType, RValueReferenceType)
PASTA_DEFINE_BASE_OPERATORS(Type, RValueReferenceType)
::pasta::Type RValueReferenceType::Desugar(void) const {
  auto &self = *const_cast<clang::RValueReferenceType *>(u.RValueReferenceType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool RValueReferenceType::IsSugared(void) const {
  auto &self = *const_cast<clang::RValueReferenceType *>(u.RValueReferenceType);
  decltype(auto) val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(TagType, RecordType)
PASTA_DEFINE_BASE_OPERATORS(Type, RecordType)
::pasta::Type RecordType::Desugar(void) const {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.desugar();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::RecordDecl RecordType::Declaration(void) const {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  throw std::runtime_error("RecordType::Declaration can return nullptr!");
}

bool RecordType::HasConstFields(void) const {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.hasConstFields();
  return val;
}

bool RecordType::IsSugared(void) const {
  auto &self = *const_cast<clang::RecordType *>(u.RecordType);
  decltype(auto) val = self.isSugared();
  return val;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
