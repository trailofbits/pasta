/*
 * Copyright (c) 2021 Trail of Bits, Inc.
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
      if (auto type_ptr = clang::dyn_cast<clang::derived>(that.u.base)) { \
        return TypeBuilder::Create<class derived>(that.ast, type_ptr); \
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
      if (this != &that) { \
        ast = std::move(that.ast); \
        u.Type = that.u.Type; \
        kind = that.kind; \
        qualifiers = that.qualifiers; \
      } \
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

void TypeVisitor::VisitDependentExtIntType(const DependentExtIntType &type) {
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

void TypeVisitor::VisitExtIntType(const ExtIntType &type) {
  VisitType(type);
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
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentExtIntType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentNameType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentSizedArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentSizedExtVectorType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentSizedMatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentTemplateSpecializationType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, DependentVectorType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ElaboratedType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, EnumType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, ExtIntType)
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
PASTA_DEFINE_DERIVED_OPERATORS(Type, VariableArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(Type, VectorType)
bool Type::AcceptsObjCTypeParams(void) const {
  auto &self = *(u.Type);
  auto val = self.acceptsObjCTypeParams();
  return val;
}

bool Type::CanDecayToPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.canDecayToPointerType();
  return val;
}

bool Type::CanHaveNullability(void) const {
  auto &self = *(u.Type);
  auto val = self.canHaveNullability();
  return val;
}

std::optional<::pasta::ArrayType> Type::CastAsArrayTypeUnsafe(void) const {
  auto &self = *(u.Type);
  auto val = self.castAsArrayTypeUnsafe();
  if (val) {
    return TypeBuilder::Create<::pasta::ArrayType>(ast, val);
  }
  return std::nullopt;
}

bool Type::ContainsErrors(void) const {
  auto &self = *(u.Type);
  auto val = self.containsErrors();
  return val;
}

bool Type::ContainsUnexpandedParameterPack(void) const {
  auto &self = *(u.Type);
  auto val = self.containsUnexpandedParameterPack();
  return val;
}

::pasta::Type Type::ArrayElementTypeNoTypeQual(void) const {
  auto &self = *(u.Type);
  auto val = self.getArrayElementTypeNoTypeQual();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "Type::ArrayElementTypeNoTypeQual can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::ArrayType> Type::AsArrayTypeUnsafe(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsArrayTypeUnsafe();
  if (val) {
    return TypeBuilder::Create<::pasta::ArrayType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::CXXRecordDecl> Type::AsCXXRecordDecl(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsCXXRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ComplexType> Type::AsComplexIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsComplexIntegerType();
  if (val) {
    return TypeBuilder::Create<::pasta::ComplexType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCInterfacePointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsObjCInterfacePointerType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ObjCObjectType> Type::AsObjCInterfaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsObjCInterfaceType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCQualifiedClassType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsObjCQualifiedClassType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ObjCObjectPointerType> Type::AsObjCQualifiedIdType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsObjCQualifiedIdType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ObjCObjectType> Type::AsObjCQualifiedInterfaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsObjCQualifiedInterfaceType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::BuiltinType> Type::AsPlaceholderType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsPlaceholderType();
  if (val) {
    return TypeBuilder::Create<::pasta::BuiltinType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::RecordDecl> Type::AsRecordDecl(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::RecordType> Type::AsStructureType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsStructureType();
  if (val) {
    return TypeBuilder::Create<::pasta::RecordType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::TagDecl> Type::AsTagDecl(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsTagDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::RecordType> Type::AsUnionType(void) const {
  auto &self = *(u.Type);
  auto val = self.getAsUnionType();
  if (val) {
    return TypeBuilder::Create<::pasta::RecordType>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::Type> Type::BaseElementTypeUnsafe(void) const {
  auto &self = *(u.Type);
  auto val = self.getBaseElementTypeUnsafe();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  return std::nullopt;
}

::pasta::Type Type::CanonicalTypeInternal(void) const {
  auto &self = *(u.Type);
  auto val = self.getCanonicalTypeInternal();
  return TypeBuilder::Build(ast, val);
}

// 0: Type::CanonicalTypeUnqualified
::pasta::AutoType Type::ContainedAutoType(void) const {
  auto &self = *(u.Type);
  auto val = self.getContainedAutoType();
  if (val) {
    return TypeBuilder::Create<::pasta::AutoType>(ast, val);
  }
  assert(false && "Type::ContainedAutoType can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeducedType Type::ContainedDeducedType(void) const {
  auto &self = *(u.Type);
  auto val = self.getContainedDeducedType();
  if (val) {
    return TypeBuilder::Create<::pasta::DeducedType>(ast, val);
  }
  assert(false && "Type::ContainedDeducedType can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeDependence Type::Dependence(void) const {
  auto &self = *(u.Type);
  auto val = self.getDependence();
  return static_cast<::pasta::TypeDependence>(val);
}

enum Linkage Type::Linkage(void) const {
  auto &self = *(u.Type);
  auto val = self.getLinkage();
  return static_cast<::pasta::Linkage>(static_cast<unsigned char>(val));
}

// 0: Type::LinkageAndVisibility
::pasta::Type Type::LocallyUnqualifiedSingleStepDesugaredType(void) const {
  auto &self = *(u.Type);
  auto val = self.getLocallyUnqualifiedSingleStepDesugaredType();
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::NullabilityKind> Type::Nullability(void) const {
  auto &self = *(u.Type);
  auto val = self.getNullability(ast->ci->getASTContext());
  if (val.hasValue()) {
    return static_cast<::pasta::NullabilityKind>(val.getValue());
  } else {
    return std::nullopt;
  }
}

::pasta::ObjCLifetime Type::ObjCARCImplicitLifetime(void) const {
  auto &self = *(u.Type);
  auto val = self.getObjCARCImplicitLifetime();
  return static_cast<::pasta::ObjCLifetime>(val);
}

// 1: Type::ObjCSubstitutions
std::optional<::pasta::CXXRecordDecl> Type::PointeeCXXRecordDecl(void) const {
  auto &self = *(u.Type);
  auto val = self.getPointeeCXXRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  return std::nullopt;
}

::pasta::Type Type::PointeeOrArrayElementType(void) const {
  auto &self = *(u.Type);
  auto val = self.getPointeeOrArrayElementType();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "Type::PointeeOrArrayElementType can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type Type::PointeeType(void) const {
  auto &self = *(u.Type);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

::pasta::ScalarTypeKind Type::ScalarTypeKind(void) const {
  auto &self = *(u.Type);
  auto val = self.getScalarTypeKind();
  return static_cast<::pasta::ScalarTypeKind>(val);
}

::pasta::Type Type::SveEltType(void) const {
  auto &self = *(u.Type);
  auto val = self.getSveEltType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

::pasta::TypeKind Type::Kind(void) const {
  auto &self = *(u.Type);
  auto val = self.getTypeClass();
  return static_cast<::pasta::TypeKind>(val);
}

std::string_view Type::KindName(void) const {
  auto &self = *(u.Type);
  auto val = self.getTypeClassName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Type::KindName can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type Type::UnqualifiedDesugaredType(void) const {
  auto &self = *(u.Type);
  auto val = self.getUnqualifiedDesugaredType();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "Type::UnqualifiedDesugaredType can return nullptr!");
  __builtin_unreachable();
}

enum Visibility Type::Visibility(void) const {
  auto &self = *(u.Type);
  auto val = self.getVisibility();
  return static_cast<::pasta::Visibility>(static_cast<unsigned int>(val));
}

// 1: Type::HasAttr
bool Type::HasAutoForTrailingReturnType(void) const {
  auto &self = *(u.Type);
  auto val = self.hasAutoForTrailingReturnType();
  return val;
}

bool Type::HasFloatingRepresentation(void) const {
  auto &self = *(u.Type);
  auto val = self.hasFloatingRepresentation();
  return val;
}

bool Type::HasIntegerRepresentation(void) const {
  auto &self = *(u.Type);
  auto val = self.hasIntegerRepresentation();
  return val;
}

bool Type::HasObjCPointerRepresentation(void) const {
  auto &self = *(u.Type);
  auto val = self.hasObjCPointerRepresentation();
  return val;
}

bool Type::HasPointerRepresentation(void) const {
  auto &self = *(u.Type);
  auto val = self.hasPointerRepresentation();
  return val;
}

bool Type::HasSignedIntegerRepresentation(void) const {
  auto &self = *(u.Type);
  auto val = self.hasSignedIntegerRepresentation();
  return val;
}

bool Type::HasSizedVLAType(void) const {
  auto &self = *(u.Type);
  auto val = self.hasSizedVLAType();
  return val;
}

bool Type::HasUnnamedOrLocalType(void) const {
  auto &self = *(u.Type);
  auto val = self.hasUnnamedOrLocalType();
  return val;
}

bool Type::HasUnsignedIntegerRepresentation(void) const {
  auto &self = *(u.Type);
  auto val = self.hasUnsignedIntegerRepresentation();
  return val;
}

bool Type::IsAggregateType(void) const {
  auto &self = *(u.Type);
  auto val = self.isAggregateType();
  return val;
}

bool Type::IsAlignValT(void) const {
  auto &self = *(u.Type);
  auto val = self.isAlignValT();
  return val;
}

bool Type::IsAnyCharacterType(void) const {
  auto &self = *(u.Type);
  auto val = self.isAnyCharacterType();
  return val;
}

bool Type::IsAnyComplexType(void) const {
  auto &self = *(u.Type);
  auto val = self.isAnyComplexType();
  return val;
}

bool Type::IsAnyPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isAnyPointerType();
  return val;
}

bool Type::IsArithmeticType(void) const {
  auto &self = *(u.Type);
  auto val = self.isArithmeticType();
  return val;
}

bool Type::IsArrayType(void) const {
  auto &self = *(u.Type);
  auto val = self.isArrayType();
  return val;
}

bool Type::IsAtomicType(void) const {
  auto &self = *(u.Type);
  auto val = self.isAtomicType();
  return val;
}

bool Type::IsBFloat16Type(void) const {
  auto &self = *(u.Type);
  auto val = self.isBFloat16Type();
  return val;
}

bool Type::IsBlockCompatibleObjCPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isBlockCompatibleObjCPointerType(ast->ci->getASTContext());
  return val;
}

bool Type::IsBlockPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isBlockPointerType();
  return val;
}

bool Type::IsBooleanType(void) const {
  auto &self = *(u.Type);
  auto val = self.isBooleanType();
  return val;
}

bool Type::IsBuiltinType(void) const {
  auto &self = *(u.Type);
  auto val = self.isBuiltinType();
  return val;
}

bool Type::IsCARCBridgableType(void) const {
  auto &self = *(u.Type);
  auto val = self.isCARCBridgableType();
  return val;
}

bool Type::IsCUDADeviceBuiltinSurfaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isCUDADeviceBuiltinSurfaceType();
  return val;
}

bool Type::IsCUDADeviceBuiltinTextureType(void) const {
  auto &self = *(u.Type);
  auto val = self.isCUDADeviceBuiltinTextureType();
  return val;
}

bool Type::IsCanonicalUnqualified(void) const {
  auto &self = *(u.Type);
  auto val = self.isCanonicalUnqualified();
  return val;
}

bool Type::IsChar16Type(void) const {
  auto &self = *(u.Type);
  auto val = self.isChar16Type();
  return val;
}

bool Type::IsChar32Type(void) const {
  auto &self = *(u.Type);
  auto val = self.isChar32Type();
  return val;
}

bool Type::IsChar8Type(void) const {
  auto &self = *(u.Type);
  auto val = self.isChar8Type();
  return val;
}

bool Type::IsCharType(void) const {
  auto &self = *(u.Type);
  auto val = self.isCharType();
  return val;
}

bool Type::IsClassType(void) const {
  auto &self = *(u.Type);
  auto val = self.isClassType();
  return val;
}

bool Type::IsClkEventT(void) const {
  auto &self = *(u.Type);
  auto val = self.isClkEventT();
  return val;
}

bool Type::IsComplexIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isComplexIntegerType();
  return val;
}

bool Type::IsComplexType(void) const {
  auto &self = *(u.Type);
  auto val = self.isComplexType();
  return val;
}

bool Type::IsCompoundType(void) const {
  auto &self = *(u.Type);
  auto val = self.isCompoundType();
  return val;
}

bool Type::IsConstantArrayType(void) const {
  auto &self = *(u.Type);
  auto val = self.isConstantArrayType();
  return val;
}

bool Type::IsConstantMatrixType(void) const {
  auto &self = *(u.Type);
  auto val = self.isConstantMatrixType();
  return val;
}

bool Type::IsConstantSizeType(void) const {
  auto &self = *(u.Type);
  auto val = self.isConstantSizeType();
  return val;
}

bool Type::IsDecltypeType(void) const {
  auto &self = *(u.Type);
  auto val = self.isDecltypeType();
  return val;
}

bool Type::IsDependentAddressSpaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isDependentAddressSpaceType();
  return val;
}

bool Type::IsDependentSizedArrayType(void) const {
  auto &self = *(u.Type);
  auto val = self.isDependentSizedArrayType();
  return val;
}

bool Type::IsDependentType(void) const {
  auto &self = *(u.Type);
  auto val = self.isDependentType();
  return val;
}

bool Type::IsElaboratedTypeSpecifier(void) const {
  auto &self = *(u.Type);
  auto val = self.isElaboratedTypeSpecifier();
  return val;
}

bool Type::IsEnumeralType(void) const {
  auto &self = *(u.Type);
  auto val = self.isEnumeralType();
  return val;
}

bool Type::IsEventT(void) const {
  auto &self = *(u.Type);
  auto val = self.isEventT();
  return val;
}

bool Type::IsExtIntType(void) const {
  auto &self = *(u.Type);
  auto val = self.isExtIntType();
  return val;
}

bool Type::IsExtVectorType(void) const {
  auto &self = *(u.Type);
  auto val = self.isExtVectorType();
  return val;
}

bool Type::IsFixedPointOrIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFixedPointOrIntegerType();
  return val;
}

bool Type::IsFixedPointType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFixedPointType();
  return val;
}

bool Type::IsFloat128Type(void) const {
  auto &self = *(u.Type);
  auto val = self.isFloat128Type();
  return val;
}

bool Type::IsFloat16Type(void) const {
  auto &self = *(u.Type);
  auto val = self.isFloat16Type();
  return val;
}

bool Type::IsFloatingType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFloatingType();
  return val;
}

bool Type::IsFromAST(void) const {
  auto &self = *(u.Type);
  auto val = self.isFromAST();
  return val;
}

bool Type::IsFunctionNoProtoType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFunctionNoProtoType();
  return val;
}

bool Type::IsFunctionPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFunctionPointerType();
  return val;
}

bool Type::IsFunctionProtoType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFunctionProtoType();
  return val;
}

bool Type::IsFunctionReferenceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFunctionReferenceType();
  return val;
}

bool Type::IsFunctionType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFunctionType();
  return val;
}

bool Type::IsFundamentalType(void) const {
  auto &self = *(u.Type);
  auto val = self.isFundamentalType();
  return val;
}

bool Type::IsHalfType(void) const {
  auto &self = *(u.Type);
  auto val = self.isHalfType();
  return val;
}

bool Type::IsImageType(void) const {
  auto &self = *(u.Type);
  auto val = self.isImageType();
  return val;
}

bool Type::IsIncompleteArrayType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIncompleteArrayType();
  return val;
}

bool Type::IsIncompleteOrObjectType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIncompleteOrObjectType();
  return val;
}

bool Type::IsIncompleteType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIncompleteType();
  return val;
}

bool Type::IsInstantiationDependentType(void) const {
  auto &self = *(u.Type);
  auto val = self.isInstantiationDependentType();
  return val;
}

bool Type::IsIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIntegerType();
  return val;
}

bool Type::IsIntegralOrEnumerationType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIntegralOrEnumerationType();
  return val;
}

bool Type::IsIntegralOrUnscopedEnumerationType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIntegralOrUnscopedEnumerationType();
  return val;
}

bool Type::IsIntegralType(void) const {
  auto &self = *(u.Type);
  auto val = self.isIntegralType(ast->ci->getASTContext());
  return val;
}

bool Type::IsInterfaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isInterfaceType();
  return val;
}

bool Type::IsLValueReferenceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isLValueReferenceType();
  return val;
}

bool Type::IsLinkageValid(void) const {
  auto &self = *(u.Type);
  auto val = self.isLinkageValid();
  return val;
}

bool Type::IsLiteralType(void) const {
  auto &self = *(u.Type);
  auto val = self.isLiteralType(ast->ci->getASTContext());
  return val;
}

bool Type::IsMatrixType(void) const {
  auto &self = *(u.Type);
  auto val = self.isMatrixType();
  return val;
}

bool Type::IsMemberDataPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isMemberDataPointerType();
  return val;
}

bool Type::IsMemberFunctionPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isMemberFunctionPointerType();
  return val;
}

bool Type::IsMemberPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isMemberPointerType();
  return val;
}

bool Type::IsNonOverloadPlaceholderType(void) const {
  auto &self = *(u.Type);
  auto val = self.isNonOverloadPlaceholderType();
  return val;
}

bool Type::IsNothrowT(void) const {
  auto &self = *(u.Type);
  auto val = self.isNothrowT();
  return val;
}

bool Type::IsNullPtrType(void) const {
  auto &self = *(u.Type);
  auto val = self.isNullPtrType();
  return val;
}

bool Type::IsOCLExtOpaqueType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLExtOpaqueType();
  return val;
}

bool Type::IsOCLImage1dArrayROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dArrayROType();
  return val;
}

bool Type::IsOCLImage1dArrayRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dArrayRWType();
  return val;
}

bool Type::IsOCLImage1dArrayWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dArrayWOType();
  return val;
}

bool Type::IsOCLImage1dBufferROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dBufferROType();
  return val;
}

bool Type::IsOCLImage1dBufferRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dBufferRWType();
  return val;
}

bool Type::IsOCLImage1dBufferWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dBufferWOType();
  return val;
}

bool Type::IsOCLImage1dROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dROType();
  return val;
}

bool Type::IsOCLImage1dRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dRWType();
  return val;
}

bool Type::IsOCLImage1dWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage1dWOType();
  return val;
}

bool Type::IsOCLImage2dArrayDepthROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayDepthROType();
  return val;
}

bool Type::IsOCLImage2dArrayDepthRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayDepthRWType();
  return val;
}

bool Type::IsOCLImage2dArrayDepthWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayDepthWOType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAADepthROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayMSAADepthROType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAADepthRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayMSAADepthRWType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAADepthWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayMSAADepthWOType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAAROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayMSAAROType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAARWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayMSAARWType();
  return val;
}

bool Type::IsOCLImage2dArrayMSAAWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayMSAAWOType();
  return val;
}

bool Type::IsOCLImage2dArrayROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayROType();
  return val;
}

bool Type::IsOCLImage2dArrayRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayRWType();
  return val;
}

bool Type::IsOCLImage2dArrayWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dArrayWOType();
  return val;
}

bool Type::IsOCLImage2dDepthROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dDepthROType();
  return val;
}

bool Type::IsOCLImage2dDepthRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dDepthRWType();
  return val;
}

bool Type::IsOCLImage2dDepthWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dDepthWOType();
  return val;
}

bool Type::IsOCLImage2dMSAADepthROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dMSAADepthROType();
  return val;
}

bool Type::IsOCLImage2dMSAADepthRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dMSAADepthRWType();
  return val;
}

bool Type::IsOCLImage2dMSAADepthWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dMSAADepthWOType();
  return val;
}

bool Type::IsOCLImage2dMSAAROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dMSAAROType();
  return val;
}

bool Type::IsOCLImage2dMSAARWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dMSAARWType();
  return val;
}

bool Type::IsOCLImage2dMSAAWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dMSAAWOType();
  return val;
}

bool Type::IsOCLImage2dROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dROType();
  return val;
}

bool Type::IsOCLImage2dRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dRWType();
  return val;
}

bool Type::IsOCLImage2dWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage2dWOType();
  return val;
}

bool Type::IsOCLImage3dROType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage3dROType();
  return val;
}

bool Type::IsOCLImage3dRWType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage3dRWType();
  return val;
}

bool Type::IsOCLImage3dWOType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLImage3dWOType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeDualRefStreaminType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCImeDualRefStreaminType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImePayloadType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCImePayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeResultDualRefStreamoutType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCImeResultDualRefStreamoutType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeResultSingleRefStreamoutType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCImeResultSingleRefStreamoutType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeResultType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCImeResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCImeSingleRefStreaminType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCImeSingleRefStreaminType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCMcePayloadType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCMcePayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCMceResultType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCMceResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCRefPayloadType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCRefPayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCRefResultType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCRefResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCSicPayloadType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCSicPayloadType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCSicResultType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCSicResultType();
  return val;
}

bool Type::IsOCLIntelSubgroupAVCType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOCLIntelSubgroupAVCType();
  return val;
}

bool Type::IsObjCARCBridgableType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCARCBridgableType();
  return val;
}

bool Type::IsObjCARCImplicitlyUnretainedType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCARCImplicitlyUnretainedType();
  return val;
}

bool Type::IsObjCBoxableRecordType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCBoxableRecordType();
  return val;
}

bool Type::IsObjCBuiltinType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCBuiltinType();
  return val;
}

bool Type::IsObjCClassOrClassKindOfType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCClassOrClassKindOfType();
  return val;
}

bool Type::IsObjCClassType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCClassType();
  return val;
}

// 2: IsObjCIdOrObjectKindOfType
bool Type::IsObjCIdType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCIdType();
  return val;
}

bool Type::IsObjCIndependentClassType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCIndependentClassType();
  return val;
}

bool Type::IsObjCIndirectLifetimeType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCIndirectLifetimeType();
  return val;
}

bool Type::IsObjCInertUnsafeUnretainedType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCInertUnsafeUnretainedType();
  return val;
}

bool Type::IsObjCLifetimeType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCLifetimeType();
  return val;
}

bool Type::IsObjCNSObjectType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCNSObjectType();
  return val;
}

bool Type::IsObjCObjectOrInterfaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCObjectOrInterfaceType();
  return val;
}

bool Type::IsObjCObjectPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCObjectPointerType();
  return val;
}

bool Type::IsObjCObjectType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCObjectType();
  return val;
}

bool Type::IsObjCQualifiedClassType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCQualifiedClassType();
  return val;
}

bool Type::IsObjCQualifiedIdType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCQualifiedIdType();
  return val;
}

bool Type::IsObjCQualifiedInterfaceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCQualifiedInterfaceType();
  return val;
}

bool Type::IsObjCRetainableType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCRetainableType();
  return val;
}

bool Type::IsObjCSelType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjCSelType();
  return val;
}

bool Type::IsObjectPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjectPointerType();
  return val;
}

bool Type::IsObjectType(void) const {
  auto &self = *(u.Type);
  auto val = self.isObjectType();
  return val;
}

bool Type::IsOpenCLSpecificType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOpenCLSpecificType();
  return val;
}

bool Type::IsOverloadableType(void) const {
  auto &self = *(u.Type);
  auto val = self.isOverloadableType();
  return val;
}

bool Type::IsPipeType(void) const {
  auto &self = *(u.Type);
  auto val = self.isPipeType();
  return val;
}

bool Type::IsPlaceholderType(void) const {
  auto &self = *(u.Type);
  auto val = self.isPlaceholderType();
  return val;
}

bool Type::IsPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isPointerType();
  return val;
}

bool Type::IsPromotableIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isPromotableIntegerType();
  return val;
}

bool Type::IsQueueT(void) const {
  auto &self = *(u.Type);
  auto val = self.isQueueT();
  return val;
}

bool Type::IsRValueReferenceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isRValueReferenceType();
  return val;
}

bool Type::IsRealFloatingType(void) const {
  auto &self = *(u.Type);
  auto val = self.isRealFloatingType();
  return val;
}

bool Type::IsRealType(void) const {
  auto &self = *(u.Type);
  auto val = self.isRealType();
  return val;
}

bool Type::IsRecordType(void) const {
  auto &self = *(u.Type);
  auto val = self.isRecordType();
  return val;
}

bool Type::IsReferenceType(void) const {
  auto &self = *(u.Type);
  auto val = self.isReferenceType();
  return val;
}

bool Type::IsReserveIDT(void) const {
  auto &self = *(u.Type);
  auto val = self.isReserveIDT();
  return val;
}

bool Type::IsSamplerT(void) const {
  auto &self = *(u.Type);
  auto val = self.isSamplerT();
  return val;
}

bool Type::IsSaturatedFixedPointType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSaturatedFixedPointType();
  return val;
}

bool Type::IsScalarType(void) const {
  auto &self = *(u.Type);
  auto val = self.isScalarType();
  return val;
}

bool Type::IsScopedEnumeralType(void) const {
  auto &self = *(u.Type);
  auto val = self.isScopedEnumeralType();
  return val;
}

bool Type::IsSignedFixedPointType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSignedFixedPointType();
  return val;
}

bool Type::IsSignedIntegerOrEnumerationType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSignedIntegerOrEnumerationType();
  return val;
}

bool Type::IsSignedIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSignedIntegerType();
  return val;
}

bool Type::IsSizelessBuiltinType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSizelessBuiltinType();
  return val;
}

bool Type::IsSizelessType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSizelessType();
  return val;
}

// 1: Type::IsSpecificBuiltinType
// 1: Type::IsSpecificPlaceholderType
bool Type::IsSpecifierType(void) const {
  auto &self = *(u.Type);
  auto val = self.isSpecifierType();
  return val;
}

bool Type::IsStandardLayoutType(void) const {
  auto &self = *(u.Type);
  auto val = self.isStandardLayoutType();
  return val;
}

bool Type::IsStdByteType(void) const {
  auto &self = *(u.Type);
  auto val = self.isStdByteType();
  return val;
}

bool Type::IsStructuralType(void) const {
  auto &self = *(u.Type);
  auto val = self.isStructuralType();
  return val;
}

bool Type::IsStructureOrClassType(void) const {
  auto &self = *(u.Type);
  auto val = self.isStructureOrClassType();
  return val;
}

bool Type::IsStructureType(void) const {
  auto &self = *(u.Type);
  auto val = self.isStructureType();
  return val;
}

bool Type::IsTemplateTypeParmType(void) const {
  auto &self = *(u.Type);
  auto val = self.isTemplateTypeParmType();
  return val;
}

bool Type::IsTypedefNameType(void) const {
  auto &self = *(u.Type);
  auto val = self.isTypedefNameType();
  return val;
}

bool Type::IsUndeducedAutoType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUndeducedAutoType();
  return val;
}

bool Type::IsUndeducedType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUndeducedType();
  return val;
}

bool Type::IsUnionType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUnionType();
  return val;
}

bool Type::IsUnsaturatedFixedPointType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUnsaturatedFixedPointType();
  return val;
}

bool Type::IsUnscopedEnumerationType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUnscopedEnumerationType();
  return val;
}

bool Type::IsUnsignedFixedPointType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUnsignedFixedPointType();
  return val;
}

bool Type::IsUnsignedIntegerOrEnumerationType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUnsignedIntegerOrEnumerationType();
  return val;
}

bool Type::IsUnsignedIntegerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isUnsignedIntegerType();
  return val;
}

bool Type::IsVLSTBuiltinType(void) const {
  auto &self = *(u.Type);
  auto val = self.isVLSTBuiltinType();
  return val;
}

bool Type::IsVariableArrayType(void) const {
  auto &self = *(u.Type);
  auto val = self.isVariableArrayType();
  return val;
}

bool Type::IsVariablyModifiedType(void) const {
  auto &self = *(u.Type);
  auto val = self.isVariablyModifiedType();
  return val;
}

bool Type::IsVectorType(void) const {
  auto &self = *(u.Type);
  auto val = self.isVectorType();
  return val;
}

bool Type::IsVisibilityExplicit(void) const {
  auto &self = *(u.Type);
  auto val = self.isVisibilityExplicit();
  return val;
}

bool Type::IsVoidPointerType(void) const {
  auto &self = *(u.Type);
  auto val = self.isVoidPointerType();
  return val;
}

bool Type::IsVoidType(void) const {
  auto &self = *(u.Type);
  auto val = self.isVoidType();
  return val;
}

bool Type::IsWideCharType(void) const {
  auto &self = *(u.Type);
  auto val = self.isWideCharType();
  return val;
}

::pasta::Type Type::IgnoreParens(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.IgnoreParens();
  return TypeBuilder::Build(ast, val);
}

enum LangAS Type::AddressSpace(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getAddressSpace();
  return static_cast<::pasta::LangAS>(static_cast<unsigned int>(val));
}

// 0: Type::
::pasta::Type Type::AtomicUnqualifiedType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getAtomicUnqualifiedType();
  return TypeBuilder::Build(ast, val);
}

// 0: Type::BaseTypeIdentifier
uint32_t Type::CVRQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getCVRQualifiers();
  return val;
}

::pasta::Type Type::CanonicalType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getCanonicalType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::DesugaredType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getDesugaredType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

uint32_t Type::LocalCVRQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getLocalCVRQualifiers();
  return val;
}

uint32_t Type::LocalFastQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getLocalFastQualifiers();
  return val;
}

// 0: Type::LocalQualifiers
::pasta::Type Type::LocalUnqualifiedType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getLocalUnqualifiedType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::NonLValueExprType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getNonLValueExprType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::NonPackExpansionType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getNonPackExpansionType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::NonReferenceType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getNonReferenceType();
  return TypeBuilder::Build(ast, val);
}

// 0: Type::ObjCGCAttr
::pasta::ObjCLifetime Type::ObjCLifetime(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getObjCLifetime();
  return static_cast<::pasta::ObjCLifetime>(val);
}

// 0: Type::Qualifiers
::pasta::Type Type::SingleStepDesugaredType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.getSingleStepDesugaredType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

// 0: Type::SplitDesugaredType
// 0: Type::SplitUnqualifiedType
// 0: Type::
// 0: Type::
// 0: Type::
bool Type::HasAddressSpace(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasAddressSpace();
  return val;
}

bool Type::HasLocalNonFastQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasLocalNonFastQualifiers();
  return val;
}

bool Type::HasLocalQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasLocalQualifiers();
  return val;
}

bool Type::HasNonTrivialObjCLifetime(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasNonTrivialObjCLifetime();
  return val;
}

bool Type::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
}

bool Type::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
}

bool Type::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
}

bool Type::HasQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasQualifiers();
  return val;
}

bool Type::HasStrongOrWeakObjCLifetime(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.hasStrongOrWeakObjCLifetime();
  return val;
}

// 1: Type::IsAddressSpaceOverlapping
// 1: Type::IsAtLeastAsQualifiedAs
bool Type::IsCForbiddenLValueType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isCForbiddenLValueType();
  return val;
}

bool Type::IsCXX11PODType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isCXX11PODType(ast->ci->getASTContext());
  return val;
}

bool Type::IsCXX98PODType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isCXX98PODType(ast->ci->getASTContext());
  return val;
}

bool Type::IsCanonical(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isCanonical();
  return val;
}

bool Type::IsCanonicalAsParam(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isCanonicalAsParam();
  return val;
}

bool Type::IsConstQualified(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isConstQualified();
  return val;
}

bool Type::IsConstant(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isConstant(ast->ci->getASTContext());
  return val;
}

// 0: Type::IsDestructedType
bool Type::IsLocalConstQualified(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isLocalConstQualified();
  return val;
}

bool Type::IsLocalRestrictQualified(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isLocalRestrictQualified();
  return val;
}

bool Type::IsLocalVolatileQualified(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isLocalVolatileQualified();
  return val;
}

// 1: Type::IsMoreQualifiedThan
::pasta::PrimitiveCopyKind Type::IsNonTrivialToPrimitiveCopy(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isNonTrivialToPrimitiveCopy();
  return static_cast<::pasta::PrimitiveCopyKind>(val);
}

::pasta::PrimitiveDefaultInitializeKind Type::IsNonTrivialToPrimitiveDefaultInitialize(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isNonTrivialToPrimitiveDefaultInitialize();
  return static_cast<::pasta::PrimitiveDefaultInitializeKind>(val);
}

::pasta::PrimitiveCopyKind Type::IsNonTrivialToPrimitiveDestructiveMove(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isNonTrivialToPrimitiveDestructiveMove();
  return static_cast<::pasta::PrimitiveCopyKind>(val);
}

bool Type::IsNonWeakInMRRWithObjCWeak(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isNonWeakInMRRWithObjCWeak(ast->ci->getASTContext());
  return val;
}

bool Type::IsNull(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isNull();
  return val;
}

bool Type::IsObjCGCStrong(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isObjCGCStrong();
  return val;
}

bool Type::IsObjCGCWeak(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isObjCGCWeak();
  return val;
}

bool Type::IsPODType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isPODType(ast->ci->getASTContext());
  return val;
}

bool Type::IsRestrictQualified(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isRestrictQualified();
  return val;
}

bool Type::IsTrivialType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isTrivialType(ast->ci->getASTContext());
  return val;
}

bool Type::IsTriviallyCopyableType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isTriviallyCopyableType(ast->ci->getASTContext());
  return val;
}

bool Type::IsVolatileQualified(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.isVolatileQualified();
  return val;
}

bool Type::MayBeDynamicClass(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.mayBeDynamicClass();
  return val;
}

bool Type::MayBeNotDynamicClass(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.mayBeNotDynamicClass();
  return val;
}

// 0: Type::Split
// 1: Type::Stream
::pasta::Type Type::StripObjCKindOfType(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.stripObjCKindOfType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

// 3: QualType::SubstObjCMemberType
// 3: QualType::SubstObjCTypeArgs
// 1: Type::WithCVRQualifiers
::pasta::Type Type::WithConst(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.withConst();
  return TypeBuilder::Build(ast, val);
}

// 1: Type::WithExactLocalFastQualifiers
// 1: Type::WithFastQualifiers
::pasta::Type Type::WithRestrict(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.withRestrict();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::WithVolatile(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.withVolatile();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type Type::WithoutLocalFastQualifiers(void) const {
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
  auto val = self.withoutLocalFastQualifiers();
  return TypeBuilder::Build(ast, val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypeOfExprType)
::pasta::Type TypeOfExprType::Desugar(void) const {
  auto &self = *(u.TypeOfExprType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr TypeOfExprType::UnderlyingExpr(void) const {
  auto &self = *(u.TypeOfExprType);
  auto val = self.getUnderlyingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "TypeOfExprType::UnderlyingExpr can return nullptr!");
  __builtin_unreachable();
}

bool TypeOfExprType::IsSugared(void) const {
  auto &self = *(u.TypeOfExprType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypeOfType)
::pasta::Type TypeOfType::Desugar(void) const {
  auto &self = *(u.TypeOfType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type TypeOfType::UnderlyingType(void) const {
  auto &self = *(u.TypeOfType);
  auto val = self.getUnderlyingType();
  return TypeBuilder::Build(ast, val);
}

bool TypeOfType::IsSugared(void) const {
  auto &self = *(u.TypeOfType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TypedefType)
::pasta::Type TypedefType::Desugar(void) const {
  auto &self = *(u.TypedefType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::TypedefNameDecl TypedefType::Decl(void) const {
  auto &self = *(u.TypedefType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TypedefType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool TypedefType::IsSugared(void) const {
  auto &self = *(u.TypedefType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, UnaryTransformType)
::pasta::Type UnaryTransformType::Desugar(void) const {
  auto &self = *(u.UnaryTransformType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type UnaryTransformType::BaseType(void) const {
  auto &self = *(u.UnaryTransformType);
  auto val = self.getBaseType();
  return TypeBuilder::Build(ast, val);
}

::pasta::UTTKind UnaryTransformType::UTTKind(void) const {
  auto &self = *(u.UnaryTransformType);
  auto val = self.getUTTKind();
  return static_cast<::pasta::UTTKind>(val);
}

::pasta::Type UnaryTransformType::UnderlyingType(void) const {
  auto &self = *(u.UnaryTransformType);
  auto val = self.getUnderlyingType();
  return TypeBuilder::Build(ast, val);
}

bool UnaryTransformType::IsSugared(void) const {
  auto &self = *(u.UnaryTransformType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, UnresolvedUsingType)
::pasta::Type UnresolvedUsingType::Desugar(void) const {
  auto &self = *(u.UnresolvedUsingType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingType::Decl(void) const {
  auto &self = *(u.UnresolvedUsingType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool UnresolvedUsingType::IsSugared(void) const {
  auto &self = *(u.UnresolvedUsingType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, VectorType)
PASTA_DEFINE_DERIVED_OPERATORS(VectorType, ExtVectorType)
::pasta::Type VectorType::Desugar(void) const {
  auto &self = *(u.VectorType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type VectorType::ElementType(void) const {
  auto &self = *(u.VectorType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

uint32_t VectorType::NumElements(void) const {
  auto &self = *(u.VectorType);
  auto val = self.getNumElements();
  return val;
}

::pasta::VectorKind VectorType::VectorKind(void) const {
  auto &self = *(u.VectorType);
  auto val = self.getVectorKind();
  return static_cast<::pasta::VectorKind>(val);
}

bool VectorType::IsSugared(void) const {
  auto &self = *(u.VectorType);
  auto val = self.isSugared();
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
  auto &self = *(u.TypeWithKeyword);
  auto val = self.getKeyword();
  return static_cast<::pasta::ElaboratedTypeKeyword>(static_cast<unsigned int>(val));
}

PASTA_DEFINE_BASE_OPERATORS(Type, AdjustedType)
PASTA_DEFINE_DERIVED_OPERATORS(AdjustedType, DecayedType)
::pasta::Type AdjustedType::Desugar(void) const {
  auto &self = *(u.AdjustedType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type AdjustedType::ResolvedType(void) const {
  auto &self = *(u.AdjustedType);
  auto val = self.getAdjustedType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type AdjustedType::OriginalType(void) const {
  auto &self = *(u.AdjustedType);
  auto val = self.getOriginalType();
  return TypeBuilder::Build(ast, val);
}

bool AdjustedType::IsSugared(void) const {
  auto &self = *(u.AdjustedType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, ConstantArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, DependentSizedArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, IncompleteArrayType)
PASTA_DEFINE_DERIVED_OPERATORS(ArrayType, VariableArrayType)
::pasta::Type ArrayType::ElementType(void) const {
  auto &self = *(u.ArrayType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

uint32_t ArrayType::IndexTypeCVRQualifiers(void) const {
  auto &self = *(u.ArrayType);
  auto val = self.getIndexTypeCVRQualifiers();
  return val;
}

// 0: ArrayType::IndexTypeQualifiers
::pasta::ArraySizeModifier ArrayType::SizeModifier(void) const {
  auto &self = *(u.ArrayType);
  auto val = self.getSizeModifier();
  return static_cast<::pasta::ArraySizeModifier>(val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, AtomicType)
::pasta::Type AtomicType::Desugar(void) const {
  auto &self = *(u.AtomicType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type AtomicType::ValueType(void) const {
  auto &self = *(u.AtomicType);
  auto val = self.getValueType();
  return TypeBuilder::Build(ast, val);
}

bool AtomicType::IsSugared(void) const {
  auto &self = *(u.AtomicType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, AttributedType)
::pasta::Type AttributedType::Desugar(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::AttributeKind AttributedType::AttributeKind(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.getAttrKind();
  return static_cast<::pasta::AttributeKind>(val);
}

::pasta::Type AttributedType::EquivalentType(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.getEquivalentType();
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::NullabilityKind> AttributedType::ImmediateNullability(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.getImmediateNullability();
  if (val.hasValue()) {
    return static_cast<::pasta::NullabilityKind>(val.getValue());
  } else {
    return std::nullopt;
  }
}

::pasta::Type AttributedType::ModifiedType(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.getModifiedType();
  return TypeBuilder::Build(ast, val);
}

bool AttributedType::IsCallingConv(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.isCallingConv();
  return val;
}

bool AttributedType::IsMSTypeSpec(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.isMSTypeSpec();
  return val;
}

bool AttributedType::IsQualifier(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.isQualifier();
  return val;
}

bool AttributedType::IsSugared(void) const {
  auto &self = *(u.AttributedType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, BlockPointerType)
::pasta::Type BlockPointerType::Desugar(void) const {
  auto &self = *(u.BlockPointerType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type BlockPointerType::PointeeType(void) const {
  auto &self = *(u.BlockPointerType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

bool BlockPointerType::IsSugared(void) const {
  auto &self = *(u.BlockPointerType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, BuiltinType)
::pasta::Type BuiltinType::Desugar(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: BuiltinType::
// 1: BuiltinType::Name
// 1: BuiltinType::NameAsCString
bool BuiltinType::IsFloatingPoint(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isFloatingPoint();
  return val;
}

bool BuiltinType::IsInteger(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isInteger();
  return val;
}

bool BuiltinType::IsNonOverloadPlaceholderType(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isNonOverloadPlaceholderType();
  return val;
}

bool BuiltinType::IsPlaceholderType(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isPlaceholderType();
  return val;
}

bool BuiltinType::IsSignedInteger(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isSignedInteger();
  return val;
}

bool BuiltinType::IsSugared(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isSugared();
  return val;
}

bool BuiltinType::IsUnsignedInteger(void) const {
  auto &self = *(u.BuiltinType);
  auto val = self.isUnsignedInteger();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ComplexType)
::pasta::Type ComplexType::Desugar(void) const {
  auto &self = *(u.ComplexType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ComplexType::ElementType(void) const {
  auto &self = *(u.ComplexType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

bool ComplexType::IsSugared(void) const {
  auto &self = *(u.ComplexType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, ConstantArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, ConstantArrayType)
::pasta::Type ConstantArrayType::Desugar(void) const {
  auto &self = *(u.ConstantArrayType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: ConstantArrayType::Size
::pasta::Expr ConstantArrayType::SizeExpr(void) const {
  auto &self = *(u.ConstantArrayType);
  auto val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConstantArrayType::SizeExpr can return nullptr!");
  __builtin_unreachable();
}

bool ConstantArrayType::IsSugared(void) const {
  auto &self = *(u.ConstantArrayType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(AdjustedType, DecayedType)
PASTA_DEFINE_BASE_OPERATORS(Type, DecayedType)
::pasta::Type DecayedType::ResolvedType(void) const {
  auto &self = *(u.DecayedType);
  auto val = self.getDecayedType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type DecayedType::PointeeType(void) const {
  auto &self = *(u.DecayedType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, DecltypeType)
::pasta::Type DecltypeType::Desugar(void) const {
  auto &self = *(u.DecltypeType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DecltypeType::UnderlyingExpr(void) const {
  auto &self = *(u.DecltypeType);
  auto val = self.getUnderlyingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DecltypeType::UnderlyingExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type DecltypeType::UnderlyingType(void) const {
  auto &self = *(u.DecltypeType);
  auto val = self.getUnderlyingType();
  return TypeBuilder::Build(ast, val);
}

bool DecltypeType::IsSugared(void) const {
  auto &self = *(u.DecltypeType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DeducedType)
PASTA_DEFINE_DERIVED_OPERATORS(DeducedType, AutoType)
PASTA_DEFINE_DERIVED_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
::pasta::Type DeducedType::Desugar(void) const {
  auto &self = *(u.DeducedType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type DeducedType::ResolvedType(void) const {
  auto &self = *(u.DeducedType);
  auto val = self.getDeducedType();
  return TypeBuilder::Build(ast, val);
}

bool DeducedType::IsDeduced(void) const {
  auto &self = *(u.DeducedType);
  auto val = self.isDeduced();
  return val;
}

bool DeducedType::IsSugared(void) const {
  auto &self = *(u.DeducedType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentAddressSpaceType)
::pasta::Type DependentAddressSpaceType::Desugar(void) const {
  auto &self = *(u.DependentAddressSpaceType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentAddressSpaceType::AddrSpaceExpr(void) const {
  auto &self = *(u.DependentAddressSpaceType);
  auto val = self.getAddrSpaceExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentAddressSpaceType::AddrSpaceExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DependentAddressSpaceType::AttributeToken(void) const {
  auto &self = *(u.DependentAddressSpaceType);
  auto val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Type DependentAddressSpaceType::PointeeType(void) const {
  auto &self = *(u.DependentAddressSpaceType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

bool DependentAddressSpaceType::IsSugared(void) const {
  auto &self = *(u.DependentAddressSpaceType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentExtIntType)
::pasta::Type DependentExtIntType::Desugar(void) const {
  auto &self = *(u.DependentExtIntType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentExtIntType::NumBitsExpr(void) const {
  auto &self = *(u.DependentExtIntType);
  auto val = self.getNumBitsExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentExtIntType::NumBitsExpr can return nullptr!");
  __builtin_unreachable();
}

bool DependentExtIntType::IsSigned(void) const {
  auto &self = *(u.DependentExtIntType);
  auto val = self.isSigned();
  return val;
}

bool DependentExtIntType::IsSugared(void) const {
  auto &self = *(u.DependentExtIntType);
  auto val = self.isSugared();
  return val;
}

bool DependentExtIntType::IsUnsigned(void) const {
  auto &self = *(u.DependentExtIntType);
  auto val = self.isUnsigned();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentNameType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, DependentNameType)
::pasta::Type DependentNameType::Desugar(void) const {
  auto &self = *(u.DependentNameType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: DependentNameType::Identifier
// 0: DependentNameType::Qualifier
bool DependentNameType::IsSugared(void) const {
  auto &self = *(u.DependentNameType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, DependentSizedArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedArrayType)
::pasta::Type DependentSizedArrayType::Desugar(void) const {
  auto &self = *(u.DependentSizedArrayType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange DependentSizedArrayType::BracketsRange(void) const {
  auto &self = *(u.DependentSizedArrayType);
  auto val = self.getBracketsRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token DependentSizedArrayType::LBracketToken(void) const {
  auto &self = *(u.DependentSizedArrayType);
  auto val = self.getLBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentSizedArrayType::RBracketToken(void) const {
  auto &self = *(u.DependentSizedArrayType);
  auto val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DependentSizedArrayType::SizeExpr(void) const {
  auto &self = *(u.DependentSizedArrayType);
  auto val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedArrayType::SizeExpr can return nullptr!");
  __builtin_unreachable();
}

bool DependentSizedArrayType::IsSugared(void) const {
  auto &self = *(u.DependentSizedArrayType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedExtVectorType)
::pasta::Type DependentSizedExtVectorType::Desugar(void) const {
  auto &self = *(u.DependentSizedExtVectorType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token DependentSizedExtVectorType::AttributeToken(void) const {
  auto &self = *(u.DependentSizedExtVectorType);
  auto val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Type DependentSizedExtVectorType::ElementType(void) const {
  auto &self = *(u.DependentSizedExtVectorType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentSizedExtVectorType::SizeExpr(void) const {
  auto &self = *(u.DependentSizedExtVectorType);
  auto val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedExtVectorType::SizeExpr can return nullptr!");
  __builtin_unreachable();
}

bool DependentSizedExtVectorType::IsSugared(void) const {
  auto &self = *(u.DependentSizedExtVectorType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, DependentTemplateSpecializationType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, DependentTemplateSpecializationType)
// 0: DependentTemplateSpecializationType::Begin
::pasta::Type DependentTemplateSpecializationType::Desugar(void) const {
  auto &self = *(u.DependentTemplateSpecializationType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: DependentTemplateSpecializationType::End
// 1: DependentTemplateSpecializationType::Arg
// 0: DependentTemplateSpecializationType::Args
// 0: DependentTemplateSpecializationType::Identifier
uint32_t DependentTemplateSpecializationType::NumArgs(void) const {
  auto &self = *(u.DependentTemplateSpecializationType);
  auto val = self.getNumArgs();
  return val;
}

// 0: DependentTemplateSpecializationType::Qualifier
bool DependentTemplateSpecializationType::IsSugared(void) const {
  auto &self = *(u.DependentTemplateSpecializationType);
  auto val = self.isSugared();
  return val;
}

// 0: DependentTemplateSpecializationType::Template_arguments
PASTA_DEFINE_BASE_OPERATORS(Type, DependentVectorType)
::pasta::Type DependentVectorType::Desugar(void) const {
  auto &self = *(u.DependentVectorType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token DependentVectorType::AttributeToken(void) const {
  auto &self = *(u.DependentVectorType);
  auto val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Type DependentVectorType::ElementType(void) const {
  auto &self = *(u.DependentVectorType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentVectorType::SizeExpr(void) const {
  auto &self = *(u.DependentVectorType);
  auto val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentVectorType::SizeExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::VectorKind DependentVectorType::VectorKind(void) const {
  auto &self = *(u.DependentVectorType);
  auto val = self.getVectorKind();
  return static_cast<::pasta::VectorKind>(val);
}

bool DependentVectorType::IsSugared(void) const {
  auto &self = *(u.DependentVectorType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ElaboratedType)
PASTA_DEFINE_BASE_OPERATORS(TypeWithKeyword, ElaboratedType)
::pasta::Type ElaboratedType::Desugar(void) const {
  auto &self = *(u.ElaboratedType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ElaboratedType::NamedType(void) const {
  auto &self = *(u.ElaboratedType);
  auto val = self.getNamedType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TagDecl ElaboratedType::OwnedTagDecl(void) const {
  auto &self = *(u.ElaboratedType);
  auto val = self.getOwnedTagDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "ElaboratedType::OwnedTagDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ElaboratedType::Qualifier
bool ElaboratedType::IsSugared(void) const {
  auto &self = *(u.ElaboratedType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ExtIntType)
::pasta::Type ExtIntType::Desugar(void) const {
  auto &self = *(u.ExtIntType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

uint32_t ExtIntType::NumBits(void) const {
  auto &self = *(u.ExtIntType);
  auto val = self.getNumBits();
  return val;
}

bool ExtIntType::IsSigned(void) const {
  auto &self = *(u.ExtIntType);
  auto val = self.isSigned();
  return val;
}

bool ExtIntType::IsSugared(void) const {
  auto &self = *(u.ExtIntType);
  auto val = self.isSugared();
  return val;
}

bool ExtIntType::IsUnsigned(void) const {
  auto &self = *(u.ExtIntType);
  auto val = self.isUnsigned();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ExtVectorType)
PASTA_DEFINE_BASE_OPERATORS(VectorType, ExtVectorType)
::pasta::Type ExtVectorType::Desugar(void) const {
  auto &self = *(u.ExtVectorType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 2: IsAccessorWithinNumElements
bool ExtVectorType::IsSugared(void) const {
  auto &self = *(u.ExtVectorType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, FunctionType)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionType, FunctionNoProtoType)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionType, FunctionProtoType)
enum CallingConv FunctionType::CallConv(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getCallConv();
  return static_cast<::pasta::CallingConv>(static_cast<unsigned int>(val));
}

::pasta::Type FunctionType::CallResultType(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getCallResultType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

bool FunctionType::CmseNSCallAttr(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getCmseNSCallAttr();
  return val;
}

// 0: FunctionType::ExtInfo
bool FunctionType::HasRegParm(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getHasRegParm();
  return val;
}

bool FunctionType::NoReturnAttr(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getNoReturnAttr();
  return val;
}

uint32_t FunctionType::RegParmType(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getRegParmType();
  return val;
}

::pasta::Type FunctionType::ReturnType(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.getReturnType();
  return TypeBuilder::Build(ast, val);
}

bool FunctionType::IsConst(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.isConst();
  return val;
}

bool FunctionType::IsRestrict(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.isRestrict();
  return val;
}

bool FunctionType::IsVolatile(void) const {
  auto &self = *(u.FunctionType);
  auto val = self.isVolatile();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, IncompleteArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, IncompleteArrayType)
::pasta::Type IncompleteArrayType::Desugar(void) const {
  auto &self = *(u.IncompleteArrayType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

bool IncompleteArrayType::IsSugared(void) const {
  auto &self = *(u.IncompleteArrayType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, InjectedClassNameType)
::pasta::Type InjectedClassNameType::Desugar(void) const {
  auto &self = *(u.InjectedClassNameType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::CXXRecordDecl InjectedClassNameType::Decl(void) const {
  auto &self = *(u.InjectedClassNameType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "InjectedClassNameType::Decl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type InjectedClassNameType::InjectedSpecializationType(void) const {
  auto &self = *(u.InjectedClassNameType);
  auto val = self.getInjectedSpecializationType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TemplateSpecializationType InjectedClassNameType::InjectedTST(void) const {
  auto &self = *(u.InjectedClassNameType);
  auto val = self.getInjectedTST();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateSpecializationType>(ast, val);
  }
  assert(false && "InjectedClassNameType::InjectedTST can return nullptr!");
  __builtin_unreachable();
}

// 0: InjectedClassNameType::TemplateName
bool InjectedClassNameType::IsSugared(void) const {
  auto &self = *(u.InjectedClassNameType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, MacroQualifiedType)
::pasta::Type MacroQualifiedType::Desugar(void) const {
  auto &self = *(u.MacroQualifiedType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: MacroQualifiedType::MacroIdentifier
::pasta::Type MacroQualifiedType::ModifiedType(void) const {
  auto &self = *(u.MacroQualifiedType);
  auto val = self.getModifiedType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type MacroQualifiedType::UnderlyingType(void) const {
  auto &self = *(u.MacroQualifiedType);
  auto val = self.getUnderlyingType();
  return TypeBuilder::Build(ast, val);
}

bool MacroQualifiedType::IsSugared(void) const {
  auto &self = *(u.MacroQualifiedType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, MatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(MatrixType, ConstantMatrixType)
PASTA_DEFINE_DERIVED_OPERATORS(MatrixType, DependentSizedMatrixType)
::pasta::Type MatrixType::Desugar(void) const {
  auto &self = *(u.MatrixType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type MatrixType::ElementType(void) const {
  auto &self = *(u.MatrixType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

bool MatrixType::IsSugared(void) const {
  auto &self = *(u.MatrixType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, MemberPointerType)
::pasta::Type MemberPointerType::Desugar(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type MemberPointerType::Class(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.getClass();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "MemberPointerType::Class can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl MemberPointerType::MostRecentCXXRecordDecl(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.getMostRecentCXXRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "MemberPointerType::MostRecentCXXRecordDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type MemberPointerType::PointeeType(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

bool MemberPointerType::IsMemberDataPointer(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.isMemberDataPointer();
  return val;
}

bool MemberPointerType::IsMemberFunctionPointer(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.isMemberFunctionPointer();
  return val;
}

bool MemberPointerType::IsSugared(void) const {
  auto &self = *(u.MemberPointerType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCObjectPointerType)
::pasta::Type ObjCObjectPointerType::Desugar(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCInterfaceDecl ObjCObjectPointerType::InterfaceDecl(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getInterfaceDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::InterfaceDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCInterfaceType ObjCObjectPointerType::InterfaceType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getInterfaceType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCInterfaceType>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::InterfaceType can return nullptr!");
  __builtin_unreachable();
}

uint32_t ObjCObjectPointerType::NumProtocols(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getNumProtocols();
  return val;
}

::pasta::ObjCObjectType ObjCObjectPointerType::ObjectType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getObjectType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::ObjectType can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type ObjCObjectPointerType::PointeeType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

// 1: ObjCObjectPointerType::Protocol
::pasta::Type ObjCObjectPointerType::SuperClassType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getSuperClassType();
  return TypeBuilder::Build(ast, val);
}

std::vector<::pasta::Type> ObjCObjectPointerType::TypeArgs(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getTypeArgs();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

std::vector<::pasta::Type> ObjCObjectPointerType::TypeArgsAsWritten(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.getTypeArgsAsWritten();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

bool ObjCObjectPointerType::IsKindOfType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isKindOfType();
  return val;
}

bool ObjCObjectPointerType::IsObjCClassType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isObjCClassType();
  return val;
}

bool ObjCObjectPointerType::IsObjCIdOrClassType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isObjCIdOrClassType();
  return val;
}

bool ObjCObjectPointerType::IsObjCIdType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isObjCIdType();
  return val;
}

bool ObjCObjectPointerType::IsObjCQualifiedClassType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isObjCQualifiedClassType();
  return val;
}

bool ObjCObjectPointerType::IsObjCQualifiedIdType(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isObjCQualifiedIdType();
  return val;
}

bool ObjCObjectPointerType::IsSpecialized(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isSpecialized();
  return val;
}

bool ObjCObjectPointerType::IsSpecializedAsWritten(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isSpecializedAsWritten();
  return val;
}

bool ObjCObjectPointerType::IsSugared(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isSugared();
  return val;
}

bool ObjCObjectPointerType::IsUnspecialized(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isUnspecialized();
  return val;
}

bool ObjCObjectPointerType::IsUnspecializedAsWritten(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.isUnspecializedAsWritten();
  return val;
}

// 0: ObjCObjectPointerType::
// 0: ObjCObjectPointerType::
// 0: ObjCObjectPointerType::
std::vector<::pasta::ObjCProtocolDecl> ObjCObjectPointerType::Quals(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.quals();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::ObjCObjectPointerType ObjCObjectPointerType::StripObjCKindOfTypeAndQuals(void) const {
  auto &self = *(u.ObjCObjectPointerType);
  auto val = self.stripObjCKindOfTypeAndQuals(ast->ci->getASTContext());
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectPointerType>(ast, val);
  }
  assert(false && "ObjCObjectPointerType::StripObjCKindOfTypeAndQuals can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::ObjCProtocolDecl> ObjCObjectPointerType::Protocols(void) const {
  auto convert_elem = [&] (clang::ObjCProtocolDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ObjCProtocolDecl> ret;
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
  auto &self = *(u.ObjCObjectType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ObjCObjectType::BaseType(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.getBaseType();
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCInterfaceDecl ObjCObjectType::Interface(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.getInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCObjectType::Interface can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type ObjCObjectType::SuperClassType(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.getSuperClassType();
  return TypeBuilder::Build(ast, val);
}

std::vector<::pasta::Type> ObjCObjectType::TypeArgs(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.getTypeArgs();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

std::vector<::pasta::Type> ObjCObjectType::TypeArgsAsWritten(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.getTypeArgsAsWritten();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

bool ObjCObjectType::IsKindOfType(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isKindOfType();
  return val;
}

bool ObjCObjectType::IsKindOfTypeAsWritten(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isKindOfTypeAsWritten();
  return val;
}

bool ObjCObjectType::IsObjCClass(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCClass();
  return val;
}

bool ObjCObjectType::IsObjCId(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCId();
  return val;
}

bool ObjCObjectType::IsObjCQualifiedClass(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCQualifiedClass();
  return val;
}

bool ObjCObjectType::IsObjCQualifiedId(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCQualifiedId();
  return val;
}

bool ObjCObjectType::IsObjCUnqualifiedClass(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCUnqualifiedClass();
  return val;
}

bool ObjCObjectType::IsObjCUnqualifiedId(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCUnqualifiedId();
  return val;
}

bool ObjCObjectType::IsObjCUnqualifiedIdOrClass(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isObjCUnqualifiedIdOrClass();
  return val;
}

bool ObjCObjectType::IsSpecialized(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isSpecialized();
  return val;
}

bool ObjCObjectType::IsSpecializedAsWritten(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isSpecializedAsWritten();
  return val;
}

bool ObjCObjectType::IsSugared(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isSugared();
  return val;
}

bool ObjCObjectType::IsUnspecialized(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isUnspecialized();
  return val;
}

bool ObjCObjectType::IsUnspecializedAsWritten(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.isUnspecializedAsWritten();
  return val;
}

::pasta::Type ObjCObjectType::StripObjCKindOfTypeAndQuals(void) const {
  auto &self = *(u.ObjCObjectType);
  auto val = self.stripObjCKindOfTypeAndQuals(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

PASTA_DEFINE_BASE_OPERATORS(Type, ObjCTypeParamType)
::pasta::Type ObjCTypeParamType::Desugar(void) const {
  auto &self = *(u.ObjCTypeParamType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCTypeParamDecl ObjCTypeParamType::Decl(void) const {
  auto &self = *(u.ObjCTypeParamType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCTypeParamDecl>(ast, val);
  }
  assert(false && "ObjCTypeParamType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool ObjCTypeParamType::IsSugared(void) const {
  auto &self = *(u.ObjCTypeParamType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, PackExpansionType)
::pasta::Type PackExpansionType::Desugar(void) const {
  auto &self = *(u.PackExpansionType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

std::optional<unsigned> PackExpansionType::NumExpansions(void) const {
  auto &self = *(u.PackExpansionType);
  auto val = self.getNumExpansions();
  if (val.hasValue()) {
    return val.getValue();
  } else {
    return std::nullopt;
  }
}

::pasta::Type PackExpansionType::Pattern(void) const {
  auto &self = *(u.PackExpansionType);
  auto val = self.getPattern();
  return TypeBuilder::Build(ast, val);
}

bool PackExpansionType::IsSugared(void) const {
  auto &self = *(u.PackExpansionType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ParenType)
::pasta::Type ParenType::Desugar(void) const {
  auto &self = *(u.ParenType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ParenType::InnerType(void) const {
  auto &self = *(u.ParenType);
  auto val = self.getInnerType();
  return TypeBuilder::Build(ast, val);
}

bool ParenType::IsSugared(void) const {
  auto &self = *(u.ParenType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, PipeType)
::pasta::Type PipeType::Desugar(void) const {
  auto &self = *(u.PipeType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type PipeType::ElementType(void) const {
  auto &self = *(u.PipeType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

bool PipeType::IsReadOnly(void) const {
  auto &self = *(u.PipeType);
  auto val = self.isReadOnly();
  return val;
}

bool PipeType::IsSugared(void) const {
  auto &self = *(u.PipeType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, PointerType)
::pasta::Type PointerType::Desugar(void) const {
  auto &self = *(u.PointerType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type PointerType::PointeeType(void) const {
  auto &self = *(u.PointerType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

bool PointerType::IsSugared(void) const {
  auto &self = *(u.PointerType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, ReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(ReferenceType, LValueReferenceType)
PASTA_DEFINE_DERIVED_OPERATORS(ReferenceType, RValueReferenceType)
::pasta::Type ReferenceType::PointeeType(void) const {
  auto &self = *(u.ReferenceType);
  auto val = self.getPointeeType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ReferenceType::PointeeTypeAsWritten(void) const {
  auto &self = *(u.ReferenceType);
  auto val = self.getPointeeTypeAsWritten();
  return TypeBuilder::Build(ast, val);
}

bool ReferenceType::IsInnerRef(void) const {
  auto &self = *(u.ReferenceType);
  auto val = self.isInnerRef();
  return val;
}

bool ReferenceType::IsSpelledAsLValue(void) const {
  auto &self = *(u.ReferenceType);
  auto val = self.isSpelledAsLValue();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, SubstTemplateTypeParmPackType)
::pasta::Type SubstTemplateTypeParmPackType::Desugar(void) const {
  auto &self = *(u.SubstTemplateTypeParmPackType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: SubstTemplateTypeParmPackType::ArgumentPack
// 0: SubstTemplateTypeParmPackType::Identifier
uint32_t SubstTemplateTypeParmPackType::NumArgs(void) const {
  auto &self = *(u.SubstTemplateTypeParmPackType);
  auto val = self.getNumArgs();
  return val;
}

::pasta::TemplateTypeParmType SubstTemplateTypeParmPackType::ReplacedParameter(void) const {
  auto &self = *(u.SubstTemplateTypeParmPackType);
  auto val = self.getReplacedParameter();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateTypeParmType>(ast, val);
  }
  assert(false && "SubstTemplateTypeParmPackType::ReplacedParameter can return nullptr!");
  __builtin_unreachable();
}

bool SubstTemplateTypeParmPackType::IsSugared(void) const {
  auto &self = *(u.SubstTemplateTypeParmPackType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, SubstTemplateTypeParmType)
::pasta::Type SubstTemplateTypeParmType::Desugar(void) const {
  auto &self = *(u.SubstTemplateTypeParmType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::TemplateTypeParmType SubstTemplateTypeParmType::ReplacedParameter(void) const {
  auto &self = *(u.SubstTemplateTypeParmType);
  auto val = self.getReplacedParameter();
  if (val) {
    return TypeBuilder::Create<::pasta::TemplateTypeParmType>(ast, val);
  }
  assert(false && "SubstTemplateTypeParmType::ReplacedParameter can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type SubstTemplateTypeParmType::ReplacementType(void) const {
  auto &self = *(u.SubstTemplateTypeParmType);
  auto val = self.getReplacementType();
  return TypeBuilder::Build(ast, val);
}

bool SubstTemplateTypeParmType::IsSugared(void) const {
  auto &self = *(u.SubstTemplateTypeParmType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TagType)
PASTA_DEFINE_DERIVED_OPERATORS(TagType, EnumType)
PASTA_DEFINE_DERIVED_OPERATORS(TagType, RecordType)
::pasta::TagDecl TagType::Decl(void) const {
  auto &self = *(u.TagType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TagType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool TagType::IsBeingDefined(void) const {
  auto &self = *(u.TagType);
  auto val = self.isBeingDefined();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(Type, TemplateSpecializationType)
// 0: TemplateSpecializationType::Begin
::pasta::Type TemplateSpecializationType::Desugar(void) const {
  auto &self = *(u.TemplateSpecializationType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: TemplateSpecializationType::End
::pasta::Type TemplateSpecializationType::AliasedType(void) const {
  auto &self = *(u.TemplateSpecializationType);
  auto val = self.getAliasedType();
  return TypeBuilder::Build(ast, val);
}

// 1: TemplateSpecializationType::Arg
// 0: TemplateSpecializationType::Args
uint32_t TemplateSpecializationType::NumArgs(void) const {
  auto &self = *(u.TemplateSpecializationType);
  auto val = self.getNumArgs();
  return val;
}

// 0: TemplateSpecializationType::TemplateName
bool TemplateSpecializationType::IsCurrentInstantiation(void) const {
  auto &self = *(u.TemplateSpecializationType);
  auto val = self.isCurrentInstantiation();
  return val;
}

bool TemplateSpecializationType::IsSugared(void) const {
  auto &self = *(u.TemplateSpecializationType);
  auto val = self.isSugared();
  return val;
}

bool TemplateSpecializationType::IsTypeAlias(void) const {
  auto &self = *(u.TemplateSpecializationType);
  auto val = self.isTypeAlias();
  return val;
}

// 0: TemplateSpecializationType::Template_arguments
PASTA_DEFINE_BASE_OPERATORS(Type, TemplateTypeParmType)
::pasta::Type TemplateTypeParmType::Desugar(void) const {
  auto &self = *(u.TemplateTypeParmType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::TemplateTypeParmDecl TemplateTypeParmType::Decl(void) const {
  auto &self = *(u.TemplateTypeParmType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateTypeParmDecl>(ast, val);
  }
  assert(false && "TemplateTypeParmType::Decl can return nullptr!");
  __builtin_unreachable();
}

uint32_t TemplateTypeParmType::Depth(void) const {
  auto &self = *(u.TemplateTypeParmType);
  auto val = self.getDepth();
  return val;
}

// 0: TemplateTypeParmType::Identifier
uint32_t TemplateTypeParmType::Index(void) const {
  auto &self = *(u.TemplateTypeParmType);
  auto val = self.getIndex();
  return val;
}

bool TemplateTypeParmType::IsParameterPack(void) const {
  auto &self = *(u.TemplateTypeParmType);
  auto val = self.isParameterPack();
  return val;
}

bool TemplateTypeParmType::IsSugared(void) const {
  auto &self = *(u.TemplateTypeParmType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ArrayType, VariableArrayType)
PASTA_DEFINE_BASE_OPERATORS(Type, VariableArrayType)
::pasta::Type VariableArrayType::Desugar(void) const {
  auto &self = *(u.VariableArrayType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange VariableArrayType::BracketsRange(void) const {
  auto &self = *(u.VariableArrayType);
  auto val = self.getBracketsRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token VariableArrayType::LBracketToken(void) const {
  auto &self = *(u.VariableArrayType);
  auto val = self.getLBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Token VariableArrayType::RBracketToken(void) const {
  auto &self = *(u.VariableArrayType);
  auto val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr VariableArrayType::SizeExpr(void) const {
  auto &self = *(u.VariableArrayType);
  auto val = self.getSizeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "VariableArrayType::SizeExpr can return nullptr!");
  __builtin_unreachable();
}

bool VariableArrayType::IsSugared(void) const {
  auto &self = *(u.VariableArrayType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(DeducedType, AutoType)
PASTA_DEFINE_BASE_OPERATORS(Type, AutoType)
// 1: AutoType::Arg
// 0: AutoType::Args
enum AutoTypeKeyword AutoType::Keyword(void) const {
  auto &self = *(u.AutoType);
  auto val = self.getKeyword();
  return static_cast<::pasta::AutoTypeKeyword>(static_cast<int>(val));
}

uint32_t AutoType::NumArgs(void) const {
  auto &self = *(u.AutoType);
  auto val = self.getNumArgs();
  return val;
}

// 0: AutoType::TypeConstraintArguments
::pasta::ConceptDecl AutoType::TypeConstraintConcept(void) const {
  auto &self = *(u.AutoType);
  auto val = self.getTypeConstraintConcept();
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
  assert(false && "AutoType::TypeConstraintConcept can return nullptr!");
  __builtin_unreachable();
}

bool AutoType::IsConstrained(void) const {
  auto &self = *(u.AutoType);
  auto val = self.isConstrained();
  return val;
}

bool AutoType::IsDecltypeAuto(void) const {
  auto &self = *(u.AutoType);
  auto val = self.isDecltypeAuto();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(MatrixType, ConstantMatrixType)
PASTA_DEFINE_BASE_OPERATORS(Type, ConstantMatrixType)
uint32_t ConstantMatrixType::NumColumns(void) const {
  auto &self = *(u.ConstantMatrixType);
  auto val = self.getNumColumns();
  return val;
}

uint32_t ConstantMatrixType::NumElementsFlattened(void) const {
  auto &self = *(u.ConstantMatrixType);
  auto val = self.getNumElementsFlattened();
  return val;
}

uint32_t ConstantMatrixType::NumRows(void) const {
  auto &self = *(u.ConstantMatrixType);
  auto val = self.getNumRows();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
PASTA_DEFINE_BASE_OPERATORS(Type, DeducedTemplateSpecializationType)
// 0: DeducedTemplateSpecializationType::TemplateName
PASTA_DEFINE_BASE_OPERATORS(MatrixType, DependentSizedMatrixType)
PASTA_DEFINE_BASE_OPERATORS(Type, DependentSizedMatrixType)
::pasta::Type DependentSizedMatrixType::Desugar(void) const {
  auto &self = *(u.DependentSizedMatrixType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token DependentSizedMatrixType::AttributeToken(void) const {
  auto &self = *(u.DependentSizedMatrixType);
  auto val = self.getAttributeLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DependentSizedMatrixType::ColumnExpr(void) const {
  auto &self = *(u.DependentSizedMatrixType);
  auto val = self.getColumnExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedMatrixType::ColumnExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type DependentSizedMatrixType::ElementType(void) const {
  auto &self = *(u.DependentSizedMatrixType);
  auto val = self.getElementType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr DependentSizedMatrixType::RowExpr(void) const {
  auto &self = *(u.DependentSizedMatrixType);
  auto val = self.getRowExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentSizedMatrixType::RowExpr can return nullptr!");
  __builtin_unreachable();
}

bool DependentSizedMatrixType::IsSugared(void) const {
  auto &self = *(u.DependentSizedMatrixType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(TagType, EnumType)
PASTA_DEFINE_BASE_OPERATORS(Type, EnumType)
::pasta::Type EnumType::Desugar(void) const {
  auto &self = *(u.EnumType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::EnumDecl EnumType::Decl(void) const {
  auto &self = *(u.EnumType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool EnumType::IsSugared(void) const {
  auto &self = *(u.EnumType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(FunctionType, FunctionNoProtoType)
PASTA_DEFINE_BASE_OPERATORS(Type, FunctionNoProtoType)
::pasta::Type FunctionNoProtoType::Desugar(void) const {
  auto &self = *(u.FunctionNoProtoType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

bool FunctionNoProtoType::IsSugared(void) const {
  auto &self = *(u.FunctionNoProtoType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(FunctionType, FunctionProtoType)
PASTA_DEFINE_BASE_OPERATORS(Type, FunctionProtoType)
enum CanThrowResult FunctionProtoType::CanThrow(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.canThrow();
  return static_cast<::pasta::CanThrowResult>(static_cast<unsigned int>(val));
}

::pasta::Type FunctionProtoType::Desugar(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

// 0: FunctionProtoType::
// 0: FunctionProtoType::
std::vector<::pasta::Type> FunctionProtoType::Exceptions(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.exceptions();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

::pasta::Token FunctionProtoType::EllipsisToken(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::FunctionDecl FunctionProtoType::ExceptionSpecDecl(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getExceptionSpecDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionProtoType::ExceptionSpecDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: FunctionProtoType::ExceptionSpecInfo
::pasta::FunctionDecl FunctionProtoType::ExceptionSpecTemplate(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getExceptionSpecTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionProtoType::ExceptionSpecTemplate can return nullptr!");
  __builtin_unreachable();
}

enum ExceptionSpecificationType FunctionProtoType::ExceptionSpecType(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(static_cast<unsigned int>(val));
}

// 1: FunctionProtoType::ExceptionType
// 1: FunctionProtoType::ExtParameterInfo
// 0: FunctionProtoType::ExtParameterInfos
// 0: FunctionProtoType::ExtParameterInfosOrNull
// 0: FunctionProtoType::ExtProtoInfo
// 0: FunctionProtoType::MethodQuals
::pasta::Expr FunctionProtoType::NoexceptExpr(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getNoexceptExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "FunctionProtoType::NoexceptExpr can return nullptr!");
  __builtin_unreachable();
}

uint32_t FunctionProtoType::NumExceptions(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getNumExceptions();
  return val;
}

uint32_t FunctionProtoType::NumParams(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getNumParams();
  return val;
}

// 1: FunctionProtoType::ParamType
std::vector<::pasta::Type> FunctionProtoType::ParamTypes(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getParamTypes();
  std::vector<::pasta::Type> ret;
  for (auto qual_type : val) {
    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));
  }
  return ret;
}

// 1: FunctionProtoType::ParameterABI
enum RefQualifierKind FunctionProtoType::RefQualifier(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(static_cast<unsigned int>(val));
}

bool FunctionProtoType::HasDependentExceptionSpec(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasDependentExceptionSpec();
  return val;
}

bool FunctionProtoType::HasDynamicExceptionSpec(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasDynamicExceptionSpec();
  return val;
}

bool FunctionProtoType::HasExceptionSpec(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasExceptionSpec();
  return val;
}

bool FunctionProtoType::HasExtParameterInfos(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasExtParameterInfos();
  return val;
}

bool FunctionProtoType::HasInstantiationDependentExceptionSpec(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasInstantiationDependentExceptionSpec();
  return val;
}

bool FunctionProtoType::HasNoexceptExceptionSpec(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasNoexceptExceptionSpec();
  return val;
}

bool FunctionProtoType::HasTrailingReturn(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.hasTrailingReturn();
  return val;
}

bool FunctionProtoType::IsNothrow(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.isNothrow();
  return val;
}

// 1: FunctionProtoType::IsParamConsumed
bool FunctionProtoType::IsSugared(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.isSugared();
  return val;
}

bool FunctionProtoType::IsTemplateVariadic(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.isTemplateVariadic();
  return val;
}

bool FunctionProtoType::IsVariadic(void) const {
  auto &self = *(u.FunctionProtoType);
  auto val = self.isVariadic();
  return val;
}

// 0: FunctionProtoType::
// 0: FunctionProtoType::
// 0: FunctionProtoType::Param_types
std::vector<::pasta::Type> FunctionProtoType::ExceptionTypes(void) const {
  auto convert_elem = [&] (clang::QualType val) {
    return TypeBuilder::Build(ast, val);
  };
  std::vector<::pasta::Type> ret;
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
  auto &self = *(u.LValueReferenceType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

bool LValueReferenceType::IsSugared(void) const {
  auto &self = *(u.LValueReferenceType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ObjCObjectType, ObjCInterfaceType)
PASTA_DEFINE_BASE_OPERATORS(Type, ObjCInterfaceType)
::pasta::Type ObjCInterfaceType::Desugar(void) const {
  auto &self = *(u.ObjCInterfaceType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::ObjCInterfaceDecl ObjCInterfaceType::Decl(void) const {
  auto &self = *(u.ObjCInterfaceType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool ObjCInterfaceType::IsSugared(void) const {
  auto &self = *(u.ObjCInterfaceType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(ReferenceType, RValueReferenceType)
PASTA_DEFINE_BASE_OPERATORS(Type, RValueReferenceType)
::pasta::Type RValueReferenceType::Desugar(void) const {
  auto &self = *(u.RValueReferenceType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

bool RValueReferenceType::IsSugared(void) const {
  auto &self = *(u.RValueReferenceType);
  auto val = self.isSugared();
  return val;
}

PASTA_DEFINE_BASE_OPERATORS(TagType, RecordType)
PASTA_DEFINE_BASE_OPERATORS(Type, RecordType)
::pasta::Type RecordType::Desugar(void) const {
  auto &self = *(u.RecordType);
  auto val = self.desugar();
  return TypeBuilder::Build(ast, val);
}

::pasta::RecordDecl RecordType::Decl(void) const {
  auto &self = *(u.RecordType);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordType::Decl can return nullptr!");
  __builtin_unreachable();
}

bool RecordType::HasConstFields(void) const {
  auto &self = *(u.RecordType);
  auto val = self.hasConstFields();
  return val;
}

bool RecordType::IsSugared(void) const {
  auto &self = *(u.RecordType);
  auto val = self.isSugared();
  return val;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
