/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#include <cstdint>
#include <llvm/ADT/APSInt.h>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "Token.h"

#define PASTA_IGNORE_ABSTRACT(...)

namespace clang {
class AbstractConditionalOperator;
class AccessSpecDecl;
class AddrLabelExpr;
class AdjustedType;
class ArrayInitIndexExpr;
class ArrayInitLoopExpr;
class ArraySubscriptExpr;
class ArrayType;
class ArrayTypeTraitExpr;
class AsTypeExpr;
class AsmStmt;
class AtomicExpr;
class AtomicType;
class AttributedStmt;
class AttributedType;
class AutoType;
class BaseUsingDecl;
class BinaryConditionalOperator;
class BinaryOperator;
class BindingDecl;
class BlockDecl;
class BlockExpr;
class BlockPointerType;
class BreakStmt;
class BuiltinBitCastExpr;
class BuiltinTemplateDecl;
class BuiltinType;
class CStyleCastExpr;
class CUDAKernelCallExpr;
class CXXAddrspaceCastExpr;
class CXXBindTemporaryExpr;
class CXXBoolLiteralExpr;
class CXXCatchStmt;
class CXXConstCastExpr;
class CXXConstructExpr;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDefaultArgExpr;
class CXXDefaultInitExpr;
class CXXDeleteExpr;
class CXXDependentScopeMemberExpr;
class CXXDestructorDecl;
class CXXDynamicCastExpr;
class CXXFoldExpr;
class CXXForRangeStmt;
class CXXFunctionalCastExpr;
class CXXInheritedCtorInitExpr;
class CXXMemberCallExpr;
class CXXMethodDecl;
class CXXNamedCastExpr;
class CXXNewExpr;
class CXXNoexceptExpr;
class CXXNullPtrLiteralExpr;
class CXXOperatorCallExpr;
class CXXPseudoDestructorExpr;
class CXXRecordDecl;
class CXXReinterpretCastExpr;
class CXXRewrittenBinaryOperator;
class CXXScalarValueInitExpr;
class CXXStaticCastExpr;
class CXXStdInitializerListExpr;
class CXXTemporaryObjectExpr;
class CXXThisExpr;
class CXXThrowExpr;
class CXXTryStmt;
class CXXTypeidExpr;
class CXXUnresolvedConstructExpr;
class CXXUuidofExpr;
class CallExpr;
class CapturedDecl;
class CapturedStmt;
class CaseStmt;
class CastExpr;
class CharacterLiteral;
class ChooseExpr;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class CoawaitExpr;
class ComplexType;
class CompoundAssignOperator;
class CompoundLiteralExpr;
class CompoundStmt;
class ConceptDecl;
class ConceptSpecializationExpr;
class ConditionalOperator;
class ConstantArrayType;
class ConstantExpr;
class ConstantMatrixType;
class ConstructorUsingShadowDecl;
class ContinueStmt;
class ConvertVectorExpr;
class CoreturnStmt;
class CoroutineBodyStmt;
class CoroutineSuspendExpr;
class CoyieldExpr;
class DecayedType;
class Decl;
class DeclContext;
class DeclRefExpr;
class DeclStmt;
class DeclaratorDecl;
class DecltypeType;
class DecompositionDecl;
class DeducedTemplateSpecializationType;
class DeducedType;
class DefaultStmt;
class DependentAddressSpaceType;
class DependentCoawaitExpr;
class DependentExtIntType;
class DependentNameType;
class DependentScopeDeclRefExpr;
class DependentSizedArrayType;
class DependentSizedExtVectorType;
class DependentSizedMatrixType;
class DependentTemplateSpecializationType;
class DependentVectorType;
class DesignatedInitExpr;
class DesignatedInitUpdateExpr;
class DoStmt;
class ElaboratedType;
class EmptyDecl;
class EnumConstantDecl;
class EnumDecl;
class EnumType;
class ExplicitCastExpr;
class ExportDecl;
class Expr;
class ExprWithCleanups;
class ExpressionTraitExpr;
class ExtIntType;
class ExtVectorElementExpr;
class ExtVectorType;
class ExternCContextDecl;
class FieldDecl;
class FileScopeAsmDecl;
class FixedPointLiteral;
class FloatingLiteral;
class ForStmt;
class FriendDecl;
class FriendTemplateDecl;
class FullExpr;
class FunctionDecl;
class FunctionNoProtoType;
class FunctionParmPackExpr;
class FunctionProtoType;
class FunctionTemplateDecl;
class FunctionTemplateSpecializationInfo;
class FunctionType;
class GCCAsmStmt;
class GNUNullExpr;
class GenericSelectionExpr;
class GotoStmt;
class IfStmt;
class ImaginaryLiteral;
class ImplicitCastExpr;
class ImplicitParamDecl;
class ImplicitValueInitExpr;
class ImportDecl;
class IncompleteArrayType;
class IndirectFieldDecl;
class IndirectGotoStmt;
class InitListExpr;
class InjectedClassNameType;
class IntegerLiteral;
class LValueReferenceType;
class LabelDecl;
class LabelStmt;
class LambdaExpr;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class MSAsmStmt;
class MSDependentExistsStmt;
class MSGuidDecl;
class MSPropertyDecl;
class MSPropertyRefExpr;
class MSPropertySubscriptExpr;
class MacroQualifiedType;
class MaterializeTemporaryExpr;
class MatrixSubscriptExpr;
class MatrixType;
class MemberExpr;
class MemberPointerType;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NoInitExpr;
class NonTypeTemplateParmDecl;
class NullStmt;
class OMPAllocateDecl;
class OMPArraySectionExpr;
class OMPArrayShapingExpr;
class OMPAtomicDirective;
class OMPBarrierDirective;
class OMPCancelDirective;
class OMPCancellationPointDirective;
class OMPCanonicalLoop;
class OMPCapturedExprDecl;
class OMPCriticalDirective;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPDepobjDirective;
class OMPDispatchDirective;
class OMPDistributeDirective;
class OMPDistributeParallelForDirective;
class OMPDistributeParallelForSimdDirective;
class OMPDistributeSimdDirective;
class OMPExecutableDirective;
class OMPFlushDirective;
class OMPForDirective;
class OMPForSimdDirective;
class OMPInteropDirective;
class OMPIteratorExpr;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedDirective;
class OMPMasterDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPOrderedDirective;
class OMPParallelDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelMasterDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPParallelSectionsDirective;
class OMPRequiresDecl;
class OMPScanDirective;
class OMPSectionDirective;
class OMPSectionsDirective;
class OMPSimdDirective;
class OMPSingleDirective;
class OMPTargetDataDirective;
class OMPTargetDirective;
class OMPTargetEnterDataDirective;
class OMPTargetExitDataDirective;
class OMPTargetParallelDirective;
class OMPTargetParallelForDirective;
class OMPTargetParallelForSimdDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetUpdateDirective;
class OMPTaskDirective;
class OMPTaskLoopDirective;
class OMPTaskLoopSimdDirective;
class OMPTaskgroupDirective;
class OMPTaskwaitDirective;
class OMPTaskyieldDirective;
class OMPTeamsDirective;
class OMPTeamsDistributeDirective;
class OMPTeamsDistributeParallelForDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class OMPTeamsDistributeSimdDirective;
class OMPThreadPrivateDecl;
class OMPTileDirective;
class OMPUnrollDirective;
class ObjCArrayLiteral;
class ObjCAtCatchStmt;
class ObjCAtDefsFieldDecl;
class ObjCAtFinallyStmt;
class ObjCAtSynchronizedStmt;
class ObjCAtThrowStmt;
class ObjCAtTryStmt;
class ObjCAutoreleasePoolStmt;
class ObjCAvailabilityCheckExpr;
class ObjCBoolLiteralExpr;
class ObjCBoxedExpr;
class ObjCBridgedCastExpr;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCDictionaryLiteral;
class ObjCEncodeExpr;
class ObjCForCollectionStmt;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCIndirectCopyRestoreExpr;
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCIsaExpr;
class ObjCIvarDecl;
class ObjCIvarRefExpr;
class ObjCMessageExpr;
class ObjCMethodDecl;
class ObjCObjectPointerType;
class ObjCObjectType;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCPropertyRefExpr;
class ObjCProtocolDecl;
class ObjCProtocolExpr;
class ObjCSelectorExpr;
class ObjCStringLiteral;
class ObjCSubscriptRefExpr;
class ObjCTypeParamDecl;
class ObjCTypeParamType;
class OffsetOfExpr;
class OpaqueValueExpr;
class OverloadExpr;
class PackExpansionExpr;
class PackExpansionType;
class ParenExpr;
class ParenListExpr;
class ParenType;
class ParmVarDecl;
class PipeType;
class PointerType;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class PredefinedExpr;
class PseudoObjectExpr;
class QualType;
class RValueReferenceType;
class RecordDecl;
class RecordType;
class RecoveryExpr;
class RedeclarableTemplateDecl;
class ReferenceType;
class RequiresExpr;
class RequiresExprBodyDecl;
class ReturnStmt;
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHLeaveStmt;
class SEHTryStmt;
class SYCLUniqueStableNameExpr;
class ShuffleVectorExpr;
class SizeOfPackExpr;
class SourceLocExpr;
class StaticAssertDecl;
class Stmt;
class StmtExpr;
class StringLiteral;
class SubstNonTypeTemplateParmExpr;
class SubstNonTypeTemplateParmPackExpr;
class SubstTemplateTypeParmPackType;
class SubstTemplateTypeParmType;
class SwitchCase;
class SwitchStmt;
class TagDecl;
class TagType;
class TemplateArgument;
class TemplateDecl;
class TemplateParamObjectDecl;
class TemplateSpecializationType;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TemplateTypeParmType;
class TranslationUnitDecl;
class Type;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypeOfExprType;
class TypeOfType;
class TypeSourceInfo;
class TypeTraitExpr;
class TypeWithKeyword;
class TypedefDecl;
class TypedefNameDecl;
class TypedefType;
class TypoExpr;
class UnaryExprOrTypeTraitExpr;
class UnaryOperator;
class UnaryTransformType;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class UnresolvedUsingIfExistsDecl;
class UnresolvedUsingType;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UserDefinedLiteral;
class UsingDecl;
class UsingDirectiveDecl;
class UsingEnumDecl;
class UsingPackDecl;
class UsingShadowDecl;
class VAArgExpr;
class ValueDecl;
class ValueStmt;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
class VariableArrayType;
class VectorType;
class WhileStmt;
#ifndef PASTA_IN_DECL_CPP
using OMPDeclarativeDirectiveDecl = Decl;
using OMPDeclarativeDirectiveValueDecl = ValueDecl;
#endif  // PASTA_IN_DECL_CPP
}  // namespace clang
namespace pasta {
class AST;
class ASTImpl;
class DeclBuilder;
class TypeBuilder;

#define PASTA_FOR_EACH_DECL_IMPL(m, a) \
    m(AccessSpec) \
    m(BaseUsing) \
    m(Binding) \
    m(Block) \
    m(BuiltinTemplate) \
    m(CXXConstructor) \
    m(CXXConversion) \
    m(CXXDeductionGuide) \
    m(CXXDestructor) \
    m(CXXMethod) \
    m(CXXRecord) \
    m(Captured) \
    m(ClassScopeFunctionSpecialization) \
    m(ClassTemplate) \
    m(ClassTemplatePartialSpecialization) \
    m(ClassTemplateSpecialization) \
    m(Concept) \
    m(ConstructorUsingShadow) \
    a(Decl) \
    m(Declarator) \
    m(Decomposition) \
    m(Empty) \
    m(EnumConstant) \
    m(Enum) \
    m(Export) \
    m(ExternCContext) \
    m(Field) \
    m(FileScopeAsm) \
    m(Friend) \
    m(FriendTemplate) \
    m(Function) \
    m(FunctionTemplate) \
    m(ImplicitParam) \
    m(Import) \
    m(IndirectField) \
    m(Label) \
    m(LifetimeExtendedTemporary) \
    m(LinkageSpec) \
    m(MSGuid) \
    m(MSProperty) \
    m(Named) \
    m(NamespaceAlias) \
    m(Namespace) \
    m(NonTypeTemplateParm) \
    m(OMPAllocate) \
    m(OMPCapturedExpr) \
    m(OMPDeclareMapper) \
    m(OMPDeclareReduction) \
    m(OMPRequires) \
    m(OMPThreadPrivate) \
    m(ObjCAtDefsField) \
    m(ObjCCategory) \
    m(ObjCCategoryImpl) \
    m(ObjCCompatibleAlias) \
    m(ObjCContainer) \
    m(ObjCImpl) \
    m(ObjCImplementation) \
    m(ObjCInterface) \
    m(ObjCIvar) \
    m(ObjCMethod) \
    m(ObjCProperty) \
    m(ObjCPropertyImpl) \
    m(ObjCProtocol) \
    m(ObjCTypeParam) \
    m(ParmVar) \
    m(PragmaComment) \
    m(PragmaDetectMismatch) \
    m(Record) \
    m(RedeclarableTemplate) \
    m(RequiresExprBody) \
    m(StaticAssert) \
    m(Tag) \
    m(Template) \
    m(TemplateParamObject) \
    m(TemplateTemplateParm) \
    m(TemplateTypeParm) \
    m(TranslationUnit) \
    m(TypeAlias) \
    m(TypeAliasTemplate) \
    m(Type) \
    m(Typedef) \
    m(TypedefName) \
    m(UnresolvedUsingIfExists) \
    m(UnresolvedUsingTypename) \
    m(UnresolvedUsingValue) \
    m(Using) \
    m(UsingDirective) \
    m(UsingEnum) \
    m(UsingPack) \
    m(UsingShadow) \
    m(Value) \
    m(Var) \
    m(VarTemplate) \
    m(VarTemplatePartialSpecialization) \
    m(VarTemplateSpecialization) \
    a(OMPDeclarativeDirective) \
    a(OMPDeclarativeDirectiveValue)

#define PASTA_FOR_EACH_STMT_IMPL(s, d, e, o, l, a) \
    a(AbstractConditionalOperator) \
    e(AddrLabelExpr) \
    e(ArrayInitIndexExpr) \
    e(ArrayInitLoopExpr) \
    e(ArraySubscriptExpr) \
    e(ArrayTypeTraitExpr) \
    e(AsTypeExpr) \
    a(AsmStmt) \
    e(AtomicExpr) \
    s(AttributedStmt) \
    o(BinaryConditionalOperator) \
    o(BinaryOperator) \
    e(BlockExpr) \
    s(BreakStmt) \
    e(BuiltinBitCastExpr) \
    e(CStyleCastExpr) \
    e(CUDAKernelCallExpr) \
    e(CXXAddrspaceCastExpr) \
    e(CXXBindTemporaryExpr) \
    e(CXXBoolLiteralExpr) \
    s(CXXCatchStmt) \
    e(CXXConstCastExpr) \
    e(CXXConstructExpr) \
    e(CXXDefaultArgExpr) \
    e(CXXDefaultInitExpr) \
    e(CXXDeleteExpr) \
    e(CXXDependentScopeMemberExpr) \
    e(CXXDynamicCastExpr) \
    e(CXXFoldExpr) \
    s(CXXForRangeStmt) \
    e(CXXFunctionalCastExpr) \
    e(CXXInheritedCtorInitExpr) \
    e(CXXMemberCallExpr) \
    a(CXXNamedCastExpr) \
    e(CXXNewExpr) \
    e(CXXNoexceptExpr) \
    e(CXXNullPtrLiteralExpr) \
    e(CXXOperatorCallExpr) \
    e(CXXPseudoDestructorExpr) \
    e(CXXReinterpretCastExpr) \
    o(CXXRewrittenBinaryOperator) \
    e(CXXScalarValueInitExpr) \
    e(CXXStaticCastExpr) \
    e(CXXStdInitializerListExpr) \
    e(CXXTemporaryObjectExpr) \
    e(CXXThisExpr) \
    e(CXXThrowExpr) \
    s(CXXTryStmt) \
    e(CXXTypeidExpr) \
    e(CXXUnresolvedConstructExpr) \
    e(CXXUuidofExpr) \
    e(CallExpr) \
    s(CapturedStmt) \
    s(CaseStmt) \
    a(CastExpr) \
    l(CharacterLiteral) \
    e(ChooseExpr) \
    e(CoawaitExpr) \
    o(CompoundAssignOperator) \
    e(CompoundLiteralExpr) \
    s(CompoundStmt) \
    e(ConceptSpecializationExpr) \
    o(ConditionalOperator) \
    e(ConstantExpr) \
    s(ContinueStmt) \
    e(ConvertVectorExpr) \
    s(CoreturnStmt) \
    s(CoroutineBodyStmt) \
    a(CoroutineSuspendExpr) \
    e(CoyieldExpr) \
    e(DeclRefExpr) \
    s(DeclStmt) \
    s(DefaultStmt) \
    e(DependentCoawaitExpr) \
    e(DependentScopeDeclRefExpr) \
    e(DesignatedInitExpr) \
    e(DesignatedInitUpdateExpr) \
    s(DoStmt) \
    a(ExplicitCastExpr) \
    a(Expr) \
    e(ExprWithCleanups) \
    e(ExpressionTraitExpr) \
    e(ExtVectorElementExpr) \
    l(FixedPointLiteral) \
    l(FloatingLiteral) \
    s(ForStmt) \
    a(FullExpr) \
    e(FunctionParmPackExpr) \
    s(GCCAsmStmt) \
    e(GNUNullExpr) \
    e(GenericSelectionExpr) \
    s(GotoStmt) \
    s(IfStmt) \
    l(ImaginaryLiteral) \
    e(ImplicitCastExpr) \
    e(ImplicitValueInitExpr) \
    s(IndirectGotoStmt) \
    e(InitListExpr) \
    l(IntegerLiteral) \
    s(LabelStmt) \
    e(LambdaExpr) \
    s(MSAsmStmt) \
    s(MSDependentExistsStmt) \
    e(MSPropertyRefExpr) \
    e(MSPropertySubscriptExpr) \
    e(MaterializeTemporaryExpr) \
    e(MatrixSubscriptExpr) \
    e(MemberExpr) \
    e(NoInitExpr) \
    s(NullStmt) \
    e(OMPArraySectionExpr) \
    e(OMPArrayShapingExpr) \
    d(OMPAtomicDirective) \
    d(OMPBarrierDirective) \
    d(OMPCancelDirective) \
    d(OMPCancellationPointDirective) \
    s(OMPCanonicalLoop) \
    d(OMPCriticalDirective) \
    d(OMPDepobjDirective) \
    d(OMPDispatchDirective) \
    d(OMPDistributeDirective) \
    d(OMPDistributeParallelForDirective) \
    d(OMPDistributeParallelForSimdDirective) \
    d(OMPDistributeSimdDirective) \
    a(OMPExecutableDirective) \
    d(OMPFlushDirective) \
    d(OMPForDirective) \
    d(OMPForSimdDirective) \
    d(OMPInteropDirective) \
    e(OMPIteratorExpr) \
    a(OMPLoopBasedDirective) \
    a(OMPLoopDirective) \
    d(OMPMaskedDirective) \
    d(OMPMasterDirective) \
    d(OMPMasterTaskLoopDirective) \
    d(OMPMasterTaskLoopSimdDirective) \
    d(OMPOrderedDirective) \
    d(OMPParallelDirective) \
    d(OMPParallelForDirective) \
    d(OMPParallelForSimdDirective) \
    d(OMPParallelMasterDirective) \
    d(OMPParallelMasterTaskLoopDirective) \
    d(OMPParallelMasterTaskLoopSimdDirective) \
    d(OMPParallelSectionsDirective) \
    d(OMPScanDirective) \
    d(OMPSectionDirective) \
    d(OMPSectionsDirective) \
    d(OMPSimdDirective) \
    d(OMPSingleDirective) \
    d(OMPTargetDataDirective) \
    d(OMPTargetDirective) \
    d(OMPTargetEnterDataDirective) \
    d(OMPTargetExitDataDirective) \
    d(OMPTargetParallelDirective) \
    d(OMPTargetParallelForDirective) \
    d(OMPTargetParallelForSimdDirective) \
    d(OMPTargetSimdDirective) \
    d(OMPTargetTeamsDirective) \
    d(OMPTargetTeamsDistributeDirective) \
    d(OMPTargetTeamsDistributeParallelForDirective) \
    d(OMPTargetTeamsDistributeParallelForSimdDirective) \
    d(OMPTargetTeamsDistributeSimdDirective) \
    d(OMPTargetUpdateDirective) \
    d(OMPTaskDirective) \
    d(OMPTaskLoopDirective) \
    d(OMPTaskLoopSimdDirective) \
    d(OMPTaskgroupDirective) \
    d(OMPTaskwaitDirective) \
    d(OMPTaskyieldDirective) \
    d(OMPTeamsDirective) \
    d(OMPTeamsDistributeDirective) \
    d(OMPTeamsDistributeParallelForDirective) \
    d(OMPTeamsDistributeParallelForSimdDirective) \
    d(OMPTeamsDistributeSimdDirective) \
    d(OMPTileDirective) \
    d(OMPUnrollDirective) \
    l(ObjCArrayLiteral) \
    s(ObjCAtCatchStmt) \
    s(ObjCAtFinallyStmt) \
    s(ObjCAtSynchronizedStmt) \
    s(ObjCAtThrowStmt) \
    s(ObjCAtTryStmt) \
    s(ObjCAutoreleasePoolStmt) \
    e(ObjCAvailabilityCheckExpr) \
    e(ObjCBoolLiteralExpr) \
    e(ObjCBoxedExpr) \
    e(ObjCBridgedCastExpr) \
    l(ObjCDictionaryLiteral) \
    e(ObjCEncodeExpr) \
    s(ObjCForCollectionStmt) \
    e(ObjCIndirectCopyRestoreExpr) \
    e(ObjCIsaExpr) \
    e(ObjCIvarRefExpr) \
    e(ObjCMessageExpr) \
    e(ObjCPropertyRefExpr) \
    e(ObjCProtocolExpr) \
    e(ObjCSelectorExpr) \
    l(ObjCStringLiteral) \
    e(ObjCSubscriptRefExpr) \
    e(OffsetOfExpr) \
    e(OpaqueValueExpr) \
    a(OverloadExpr) \
    e(PackExpansionExpr) \
    e(ParenExpr) \
    e(ParenListExpr) \
    e(PredefinedExpr) \
    e(PseudoObjectExpr) \
    e(RecoveryExpr) \
    e(RequiresExpr) \
    s(ReturnStmt) \
    s(SEHExceptStmt) \
    s(SEHFinallyStmt) \
    s(SEHLeaveStmt) \
    s(SEHTryStmt) \
    e(SYCLUniqueStableNameExpr) \
    e(ShuffleVectorExpr) \
    e(SizeOfPackExpr) \
    e(SourceLocExpr) \
    a(Stmt) \
    e(StmtExpr) \
    l(StringLiteral) \
    e(SubstNonTypeTemplateParmExpr) \
    e(SubstNonTypeTemplateParmPackExpr) \
    a(SwitchCase) \
    s(SwitchStmt) \
    e(TypeTraitExpr) \
    e(TypoExpr) \
    e(UnaryExprOrTypeTraitExpr) \
    o(UnaryOperator) \
    e(UnresolvedLookupExpr) \
    e(UnresolvedMemberExpr) \
    l(UserDefinedLiteral) \
    e(VAArgExpr) \
    a(ValueStmt) \
    s(WhileStmt)

#define PASTA_FOR_EACH_TYPE_IMPL(m, a) \
    m(Adjusted) \
    m(Array) \
    m(Atomic) \
    m(Attributed) \
    m(Auto) \
    m(BlockPointer) \
    m(Builtin) \
    m(Complex) \
    m(ConstantArray) \
    m(ConstantMatrix) \
    m(Decayed) \
    m(Decltype) \
    m(DeducedTemplateSpecialization) \
    m(Deduced) \
    m(DependentAddressSpace) \
    m(DependentExtInt) \
    m(DependentName) \
    m(DependentSizedArray) \
    m(DependentSizedExtVector) \
    m(DependentSizedMatrix) \
    m(DependentTemplateSpecialization) \
    m(DependentVector) \
    m(Elaborated) \
    m(Enum) \
    m(ExtInt) \
    m(ExtVector) \
    m(FunctionNoProto) \
    m(FunctionProto) \
    m(Function) \
    m(IncompleteArray) \
    m(InjectedClassName) \
    m(LValueReference) \
    m(MacroQualified) \
    m(Matrix) \
    m(MemberPointer) \
    m(ObjCInterface) \
    m(ObjCObjectPointer) \
    m(ObjCObject) \
    m(ObjCTypeParam) \
    m(PackExpansion) \
    m(Paren) \
    m(Pipe) \
    m(Pointer) \
    m(RValueReference) \
    m(Record) \
    m(Reference) \
    m(SubstTemplateTypeParmPack) \
    m(SubstTemplateTypeParm) \
    m(Tag) \
    m(TemplateSpecialization) \
    m(TemplateTypeParm) \
    a(Type) \
    m(TypeOfExpr) \
    m(TypeOf) \
    m(Typedef) \
    m(UnaryTransform) \
    m(UnresolvedUsing) \
    m(VariableArray) \
    m(Vector) \
    m(TypeWithKey)

enum class DeclKind : unsigned {
#define PASTA_DECLARE_DECL_KIND(name) k ## name ,
  PASTA_FOR_EACH_DECL_IMPL(PASTA_DECLARE_DECL_KIND, PASTA_IGNORE_ABSTRACT)
#undef PASTA_DECLARE_DECL_KIND
};

enum class ArrayTypeArraySizeModifier : unsigned int {
  kNormal = 0,
  kStatic = 1,
  kStar = 2,
};

enum class AtomicExprAtomicOp : unsigned int {
  kC11AtomicInitializer = 0,
  kC11AtomicLoad = 1,
  kC11AtomicStore = 2,
  kC11AtomicExchange = 3,
  kC11AtomicCompareExchangeStrong = 4,
  kC11AtomicCompareExchangeWeak = 5,
  kC11AtomicFetchAdd = 6,
  kC11AtomicFetchSub = 7,
  kC11AtomicFetchAnd = 8,
  kC11AtomicFetchOr = 9,
  kC11AtomicFetchXor = 10,
  kC11AtomicFetchMax = 11,
  kC11AtomicFetchMin = 12,
  kAtomicLoad = 13,
  kAtomicLoadN = 14,
  kAtomicStore = 15,
  kAtomicStoreN = 16,
  kAtomicExchange = 17,
  kAtomicExchangeN = 18,
  kAtomicCompareExchange = 19,
  kAtomicCompareExchangeN = 20,
  kAtomicFetchAdd = 21,
  kAtomicFetchSub = 22,
  kAtomicFetchAnd = 23,
  kAtomicFetchOr = 24,
  kAtomicFetchXor = 25,
  kAtomicFetchNand = 26,
  kAtomicAddFetch = 27,
  kAtomicSubFetch = 28,
  kAtomicAndFetch = 29,
  kAtomicOrFetch = 30,
  kAtomicXorFetch = 31,
  kAtomicMaxFetch = 32,
  kAtomicMinFetch = 33,
  kAtomicNandFetch = 34,
  kOpenclAtomicInitializer = 35,
  kOpenclAtomicLoad = 36,
  kOpenclAtomicStore = 37,
  kOpenclAtomicExchange = 38,
  kOpenclAtomicCompareExchangeStrong = 39,
  kOpenclAtomicCompareExchangeWeak = 40,
  kOpenclAtomicFetchAdd = 41,
  kOpenclAtomicFetchSub = 42,
  kOpenclAtomicFetchAnd = 43,
  kOpenclAtomicFetchOr = 44,
  kOpenclAtomicFetchXor = 45,
  kOpenclAtomicFetchMin = 46,
  kOpenclAtomicFetchMax = 47,
  kAtomicFetchMin = 48,
  kAtomicFetchMax = 49,
};

enum class BuiltinTypeKind : unsigned int {
  kOCLImage1dRO = 0,
  kOCLImage1dArrayRO = 1,
  kOCLImage1dBufferRO = 2,
  kOCLImage2dRO = 3,
  kOCLImage2dArrayRO = 4,
  kOCLImage2dDepthRO = 5,
  kOCLImage2dArrayDepthRO = 6,
  kOCLImage2dMSAARO = 7,
  kOCLImage2dArrayMSAARO = 8,
  kOCLImage2dMSAADepthRO = 9,
  kOCLImage2dArrayMSAADepthRO = 10,
  kOCLImage3dRO = 11,
  kOCLImage1dWO = 12,
  kOCLImage1dArrayWO = 13,
  kOCLImage1dBufferWO = 14,
  kOCLImage2dWO = 15,
  kOCLImage2dArrayWO = 16,
  kOCLImage2dDepthWO = 17,
  kOCLImage2dArrayDepthWO = 18,
  kOCLImage2dMSAAWO = 19,
  kOCLImage2dArrayMSAAWO = 20,
  kOCLImage2dMSAADepthWO = 21,
  kOCLImage2dArrayMSAADepthWO = 22,
  kOCLImage3dWO = 23,
  kOCLImage1dRW = 24,
  kOCLImage1dArrayRW = 25,
  kOCLImage1dBufferRW = 26,
  kOCLImage2dRW = 27,
  kOCLImage2dArrayRW = 28,
  kOCLImage2dDepthRW = 29,
  kOCLImage2dArrayDepthRW = 30,
  kOCLImage2dMSAARW = 31,
  kOCLImage2dArrayMSAARW = 32,
  kOCLImage2dMSAADepthRW = 33,
  kOCLImage2dArrayMSAADepthRW = 34,
  kOCLImage3dRW = 35,
  kOCLIntelSubgroupAVCMcePayload = 36,
  kOCLIntelSubgroupAVCImePayload = 37,
  kOCLIntelSubgroupAVCRefPayload = 38,
  kOCLIntelSubgroupAVCSicPayload = 39,
  kOCLIntelSubgroupAVCMceResult = 40,
  kOCLIntelSubgroupAVCImeResult = 41,
  kOCLIntelSubgroupAVCRefResult = 42,
  kOCLIntelSubgroupAVCSicResult = 43,
  kOCLIntelSubgroupAVCImeResultSingleReferenceStreamout = 44,
  kOCLIntelSubgroupAVCImeResultDualReferenceStreamout = 45,
  kOCLIntelSubgroupAVCImeSingleReferenceStreamin = 46,
  kOCLIntelSubgroupAVCImeDualReferenceStreamin = 47,
  kSveInt8 = 48,
  kSveInt16 = 49,
  kSveInt32 = 50,
  kSveInt64 = 51,
  kSveUint8 = 52,
  kSveUint16 = 53,
  kSveUint32 = 54,
  kSveUint64 = 55,
  kSveFloat16 = 56,
  kSveFloat32 = 57,
  kSveFloat64 = 58,
  kSveBFloat16 = 59,
  kSveInt8x2 = 60,
  kSveInt16x2 = 61,
  kSveInt32x2 = 62,
  kSveInt64x2 = 63,
  kSveUint8x2 = 64,
  kSveUint16x2 = 65,
  kSveUint32x2 = 66,
  kSveUint64x2 = 67,
  kSveFloat16x2 = 68,
  kSveFloat32x2 = 69,
  kSveFloat64x2 = 70,
  kSveBFloat16x2 = 71,
  kSveInt8x3 = 72,
  kSveInt16x3 = 73,
  kSveInt32x3 = 74,
  kSveInt64x3 = 75,
  kSveUint8x3 = 76,
  kSveUint16x3 = 77,
  kSveUint32x3 = 78,
  kSveUint64x3 = 79,
  kSveFloat16x3 = 80,
  kSveFloat32x3 = 81,
  kSveFloat64x3 = 82,
  kSveBFloat16x3 = 83,
  kSveInt8x4 = 84,
  kSveInt16x4 = 85,
  kSveInt32x4 = 86,
  kSveInt64x4 = 87,
  kSveUint8x4 = 88,
  kSveUint16x4 = 89,
  kSveUint32x4 = 90,
  kSveUint64x4 = 91,
  kSveFloat16x4 = 92,
  kSveFloat32x4 = 93,
  kSveFloat64x4 = 94,
  kSveBFloat16x4 = 95,
  kSveBoolean = 96,
  kVectorQuad = 97,
  kVectorPair = 98,
  kRvvInt8mf8 = 99,
  kRvvInt8mf4 = 100,
  kRvvInt8mf2 = 101,
  kRvvInt8m1 = 102,
  kRvvInt8m2 = 103,
  kRvvInt8m4 = 104,
  kRvvInt8m8 = 105,
  kRvvUint8mf8 = 106,
  kRvvUint8mf4 = 107,
  kRvvUint8mf2 = 108,
  kRvvUint8m1 = 109,
  kRvvUint8m2 = 110,
  kRvvUint8m4 = 111,
  kRvvUint8m8 = 112,
  kRvvInt16mf4 = 113,
  kRvvInt16mf2 = 114,
  kRvvInt16m1 = 115,
  kRvvInt16m2 = 116,
  kRvvInt16m4 = 117,
  kRvvInt16m8 = 118,
  kRvvUint16mf4 = 119,
  kRvvUint16mf2 = 120,
  kRvvUint16m1 = 121,
  kRvvUint16m2 = 122,
  kRvvUint16m4 = 123,
  kRvvUint16m8 = 124,
  kRvvInt32mf2 = 125,
  kRvvInt32m1 = 126,
  kRvvInt32m2 = 127,
  kRvvInt32m4 = 128,
  kRvvInt32m8 = 129,
  kRvvUint32mf2 = 130,
  kRvvUint32m1 = 131,
  kRvvUint32m2 = 132,
  kRvvUint32m4 = 133,
  kRvvUint32m8 = 134,
  kRvvInt64m1 = 135,
  kRvvInt64m2 = 136,
  kRvvInt64m4 = 137,
  kRvvInt64m8 = 138,
  kRvvUint64m1 = 139,
  kRvvUint64m2 = 140,
  kRvvUint64m4 = 141,
  kRvvUint64m8 = 142,
  kRvvFloat16mf4 = 143,
  kRvvFloat16mf2 = 144,
  kRvvFloat16m1 = 145,
  kRvvFloat16m2 = 146,
  kRvvFloat16m4 = 147,
  kRvvFloat16m8 = 148,
  kRvvFloat32mf2 = 149,
  kRvvFloat32m1 = 150,
  kRvvFloat32m2 = 151,
  kRvvFloat32m4 = 152,
  kRvvFloat32m8 = 153,
  kRvvFloat64m1 = 154,
  kRvvFloat64m2 = 155,
  kRvvFloat64m4 = 156,
  kRvvFloat64m8 = 157,
  kRvvBool1 = 158,
  kRvvBool2 = 159,
  kRvvBool4 = 160,
  kRvvBool8 = 161,
  kRvvBool16 = 162,
  kRvvBool32 = 163,
  kRvvBool64 = 164,
  kVoid = 165,
  kBoolean = 166,
  kCharacterU = 167,
  kUChar = 168,
  kWCharU = 169,
  kChar8 = 170,
  kChar16 = 171,
  kChar32 = 172,
  kUShort = 173,
  kUInt = 174,
  kULong = 175,
  kULongLong = 176,
  kUInt128 = 177,
  kCharacterS = 178,
  kSChar = 179,
  kWCharS = 180,
  kShort = 181,
  kInt = 182,
  kLong = 183,
  kLongLong = 184,
  kInt128 = 185,
  kShortAccum = 186,
  kAccum = 187,
  kLongAccum = 188,
  kUShortAccum = 189,
  kUAccum = 190,
  kULongAccum = 191,
  kShortFract = 192,
  kFract = 193,
  kLongFract = 194,
  kUShortFract = 195,
  kUFract = 196,
  kULongFract = 197,
  kSatShortAccum = 198,
  kSatAccum = 199,
  kSatLongAccum = 200,
  kSatUShortAccum = 201,
  kSatUAccum = 202,
  kSatULongAccum = 203,
  kSatShortFract = 204,
  kSatFract = 205,
  kSatLongFract = 206,
  kSatUShortFract = 207,
  kSatUFract = 208,
  kSatULongFract = 209,
  kHalf = 210,
  kFloat = 211,
  kDouble = 212,
  kLongDouble = 213,
  kFloat16 = 214,
  kBFloat16 = 215,
  kFloat128 = 216,
  kNullPointer = 217,
  kObjCId = 218,
  kObjCClass = 219,
  kObjCSel = 220,
  kOCLSampler = 221,
  kOCLEvent = 222,
  kOCLClkEvent = 223,
  kOCLQueue = 224,
  kOCLReserveID = 225,
  kDependent = 226,
  kOverload = 227,
  kBoundMember = 228,
  kPseudoObject = 229,
  kUnknownAny = 230,
  kBuiltinFn = 231,
  kARCUnbridgedCast = 232,
  kIncompleteMatrixIndex = 233,
  kOMPArraySection = 234,
  kOMPArrayShaping = 235,
  kOMPIterator = 236,
};

enum class CXXConstructExprConstructionKind : unsigned int {
  kComplete = 0,
  kNonVirtualBase = 1,
  kVirtualBase = 2,
  kDelegating = 3,
};

enum class CXXNewExprInitializationStyle : unsigned int {
  kNoInitializer = 0,
  kCallInitializer = 1,
  kListInitializer = 2,
};

enum class CallExprADLCallKind : bool {
  kNotADL = 0,
  kUsesADL = 1,
};

enum class CapturedStmtVariableCaptureKind : unsigned int {
  kThis = 0,
  kByReference = 1,
  kByCopy = 2,
  kVLAType = 3,
};

enum class CharacterLiteralCharacterKind : unsigned int {
  kAscii = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class ConstantExprResultStorageKind : unsigned int {
  kNone = 0,
  kInt64 = 1,
  kAPValue = 2,
};

enum class DeclFriendObjectKind : unsigned int {
  kNone = 0,
  kDeclared = 1,
  kUndeclared = 2,
};

enum class DeclIdentifierNamespace : unsigned int {
  kLabel = 1,
  kTag = 2,
  kType = 4,
  kMember = 8,
  kNamespace = 16,
  kOrdinary = 32,
  kObjCProtocol = 64,
  kOrdinaryFriend = 128,
  kTagFriend = 256,
  kUsing = 512,
  kNonMemberOperator = 1024,
  kLocalExtern = 2048,
  kOMPReduction = 4096,
  kOMPMapper = 8192,
};

enum class DeclModuleOwnershipKind : unsigned int {
  kUnowned = 0,
  kVisible = 1,
  kVisibleWhenImported = 2,
  kModulePrivate = 3,
};

enum class DeclObjCDeclQualifier : unsigned int {
  kNone = 0,
  kIn = 1,
  kInout = 2,
  kOut = 4,
  kBycopy = 8,
  kByref = 16,
  kOneway = 32,
  kCSNullability = 64,
};

enum class ExprConstantExprKind : int {
  kNormal = 0,
  kNonClassTemplateArgument = 1,
  kClassTemplateArgument = 2,
  kImmediateInvocation = 3,
};

enum class ExprLValueClassification : unsigned int {
  kValid = 0,
  kNotObjectType = 1,
  kIncompleteVoidType = 2,
  kDuplicateVectorComponents = 3,
  kInvalidExpression = 4,
  kInvalidMessageExpression = 5,
  kMemberFunction = 6,
  kSubObjCPropertySetting = 7,
  kClassTemporary = 8,
  kArrayTemporary = 9,
};

enum class ExprNullPointerConstantKind : unsigned int {
  kNotNull = 0,
  kZeroExpression = 1,
  kZeroLiteral = 2,
  kCXX11Nullptr = 3,
  kGNUNull = 4,
};

enum class ExprNullPointerConstantValueDependence : unsigned int {
  kNeverValueDependent = 0,
  kValueDependentIsNull = 1,
  kValueDependentIsNotNull = 2,
};

enum class ExprSideEffectsKind : unsigned int {
  kNoSideEffects = 0,
  kAllowUndefinedBehavior = 1,
  kAllowSideEffects = 2,
};

enum class ExprisModifiableLvalueResult : unsigned int {
  kValid = 0,
  kNotObjectType = 1,
  kIncompleteVoidType = 2,
  kDuplicateVectorComponents = 3,
  kInvalidExpression = 4,
  kLValueCast = 5,
  kIncompleteType = 6,
  kConstQualified = 7,
  kConstQualifiedField = 8,
  kConstAddrSpace = 9,
  kArrayType = 10,
  kNoSetterProperty = 11,
  kMemberFunction = 12,
  kSubObjCPropertySetting = 13,
  kInvalidMessageExpression = 14,
  kClassTemporary = 15,
  kArrayTemporary = 16,
};

enum class FunctionDeclTemplatedKind : unsigned int {
  kNonTemplate = 0,
  kFunctionTemplate = 1,
  kMemberSpecialization = 2,
  kFunctionTemplateSpecialization = 3,
  kDependentFunctionTemplateSpecialization = 4,
};

enum class ImplicitCastExprOnStack_t : unsigned int {
  kOnStack = 0,
};

enum class ImplicitParamDeclImplicitParamKind : unsigned int {
  kObjCSelf = 0,
  kObjCCmd = 1,
  kCXXThis = 2,
  kCXXVTT = 3,
  kCapturedContext = 4,
  kOther = 5,
};

enum class LinkageSpecDeclLanguageIDs : unsigned int {
  kC = 1,
  kCxx = 2,
};

enum class NamedDeclExplicitVisibilityKind : unsigned int {
  kVisibilityForType = 0,
  kVisibilityForValue = 1,
};

enum class OMPDeclareReductionDeclInitKind : unsigned int {
  kCallInitializer = 0,
  kDirectInitializer = 1,
  kCopyInitializer = 2,
};

enum class ObjCIvarDeclAccessControl : unsigned int {
  kNone = 0,
  kPrivate = 1,
  kProtected = 2,
  kPublic = 3,
  kPackage = 4,
};

enum class ObjCMessageExprReceiverKind : unsigned int {
  kClass = 0,
  kInstance = 1,
  kSuperClass = 2,
  kSuperInstance = 3,
};

enum class ObjCMethodDeclImplementationControl : unsigned int {
  kNone = 0,
  kRequired = 1,
  kOptional = 2,
};

enum class ObjCPropertyDeclPropertyControl : unsigned int {
  kNone = 0,
  kRequired = 1,
  kOptional = 2,
};

enum class ObjCPropertyDeclSetterKind : unsigned int {
  kAssign = 0,
  kRetain = 1,
  kCopy = 2,
  kWeak = 3,
};

enum class ObjCPropertyImplDeclKind : unsigned int {
  kSynthesize = 0,
  kDynamic = 1,
};

enum class PredefinedExprIdentKind : unsigned int {
  kFunc = 0,
  kFunction = 1,
  kLFunction = 2,
  kFuncDName = 3,
  kFuncSig = 4,
  kLFuncSig = 5,
  kPrettyFunction = 6,
  kPrettyFunctionNoVirtual = 7,
};

enum class QualTypeDestructionKind : unsigned int {
  kNone = 0,
  kCxxDestructor = 1,
  kObjcStrongLifetime = 2,
  kObjcWeakLifetime = 3,
  kNontrivialCStruct = 4,
};

enum class QualTypePrimitiveCopyKind : unsigned int {
  kTrivial = 0,
  kVolatileTrivial = 1,
  kARCStrong = 2,
  kARCWeak = 3,
  kStruct = 4,
};

enum class QualTypePrimitiveDefaultInitializeKind : unsigned int {
  kTrivial = 0,
  kARCStrong = 1,
  kARCWeak = 2,
  kStruct = 3,
};

enum class RecordDeclArgPassingKind : unsigned int {
  kCanPassInRegs = 0,
  kCannotPassInRegs = 1,
  kCanNeverPassInRegs = 2,
};

enum class SourceLocExprIdentKind : unsigned int {
  kFunction = 0,
  kFile = 1,
  kLine = 2,
  kColumn = 3,
};

enum class StmtLikelihood : int {
  kUnlikely = -1,
  kNone = 0,
  kLikely = 1,
};

enum class StmtStmtClass : unsigned int {
  kGCCAsmStatementClass = 1,
  kMSAssemblyStatementClass = 2,
  kBreakStatementClass = 3,
  kCXXCatchStatementClass = 4,
  kCXXForRangeStatementClass = 5,
  kCXXTryStatementClass = 6,
  kCapturedStatementClass = 7,
  kCompoundStatementClass = 8,
  kContinueStatementClass = 9,
  kCoreturnStatementClass = 10,
  kCoroutineBodyStatementClass = 11,
  kDeclarationStatementClass = 12,
  kDoStatementClass = 13,
  kForStatementClass = 14,
  kGotoStatementClass = 15,
  kIfStatementClass = 16,
  kIndirectGotoStatementClass = 17,
  kMSDependentExistsStatementClass = 18,
  kNullStatementClass = 19,
  kOMPCanonicalLoopClass = 20,
  kOMPAtomicDirectiveClass = 21,
  kOMPBarrierDirectiveClass = 22,
  kOMPCancelDirectiveClass = 23,
  kOMPCancellationPointDirectiveClass = 24,
  kOMPCriticalDirectiveClass = 25,
  kOMPDepobjDirectiveClass = 26,
  kOMPDispatchDirectiveClass = 27,
  kOMPFlushDirectiveClass = 28,
  kOMPInteropDirectiveClass = 29,
  kOMPDistributeDirectiveClass = 30,
  kOMPDistributeParallelForDirectiveClass = 31,
  kOMPDistributeParallelForSimdDirectiveClass = 32,
  kOMPDistributeSimdDirectiveClass = 33,
  kOMPForDirectiveClass = 34,
  kOMPForSimdDirectiveClass = 35,
  kOMPMasterTaskLoopDirectiveClass = 36,
  kOMPMasterTaskLoopSimdDirectiveClass = 37,
  kOMPParallelForDirectiveClass = 38,
  kOMPParallelForSimdDirectiveClass = 39,
  kOMPParallelMasterTaskLoopDirectiveClass = 40,
  kOMPParallelMasterTaskLoopSimdDirectiveClass = 41,
  kOMPSimdDirectiveClass = 42,
  kOMPTargetParallelForSimdDirectiveClass = 43,
  kOMPTargetSimdDirectiveClass = 44,
  kOMPTargetTeamsDistributeDirectiveClass = 45,
  kOMPTargetTeamsDistributeParallelForDirectiveClass = 46,
  kOMPTargetTeamsDistributeParallelForSimdDirectiveClass = 47,
  kOMPTargetTeamsDistributeSimdDirectiveClass = 48,
  kOMPTaskLoopDirectiveClass = 49,
  kOMPTaskLoopSimdDirectiveClass = 50,
  kOMPTeamsDistributeDirectiveClass = 51,
  kOMPTeamsDistributeParallelForDirectiveClass = 52,
  kOMPTeamsDistributeParallelForSimdDirectiveClass = 53,
  kOMPTeamsDistributeSimdDirectiveClass = 54,
  kOMPTileDirectiveClass = 55,
  kOMPUnrollDirectiveClass = 56,
  kOMPMaskedDirectiveClass = 57,
  kOMPMasterDirectiveClass = 58,
  kOMPOrderedDirectiveClass = 59,
  kOMPParallelDirectiveClass = 60,
  kOMPParallelMasterDirectiveClass = 61,
  kOMPParallelSectionsDirectiveClass = 62,
  kOMPScanDirectiveClass = 63,
  kOMPSectionDirectiveClass = 64,
  kOMPSectionsDirectiveClass = 65,
  kOMPSingleDirectiveClass = 66,
  kOMPTargetDataDirectiveClass = 67,
  kOMPTargetDirectiveClass = 68,
  kOMPTargetEnterDataDirectiveClass = 69,
  kOMPTargetExitDataDirectiveClass = 70,
  kOMPTargetParallelDirectiveClass = 71,
  kOMPTargetParallelForDirectiveClass = 72,
  kOMPTargetTeamsDirectiveClass = 73,
  kOMPTargetUpdateDirectiveClass = 74,
  kOMPTaskDirectiveClass = 75,
  kOMPTaskgroupDirectiveClass = 76,
  kOMPTaskwaitDirectiveClass = 77,
  kOMPTaskyieldDirectiveClass = 78,
  kOMPTeamsDirectiveClass = 79,
  kObjCAtCatchStatementClass = 80,
  kObjCAtFinallyStatementClass = 81,
  kObjCAtSynchronizedStatementClass = 82,
  kObjCAtThrowStatementClass = 83,
  kObjCAtTryStatementClass = 84,
  kObjCAutoreleasePoolStatementClass = 85,
  kObjCForCollectionStatementClass = 86,
  kReturnStatementClass = 87,
  kSEHExceptStatementClass = 88,
  kSEHFinallyStatementClass = 89,
  kSEHLeaveStatementClass = 90,
  kSEHTryStatementClass = 91,
  kCaseStatementClass = 92,
  kDefaultStatementClass = 93,
  kSwitchStatementClass = 94,
  kAttributedStatementClass = 95,
  kBinaryConditionalOperatorClass = 96,
  kConditionalOperatorClass = 97,
  kAddrLabelExpressionClass = 98,
  kArrayInitializerIndexExpressionClass = 99,
  kArrayInitializerLoopExpressionClass = 100,
  kArraySubscriptExpressionClass = 101,
  kArrayTypeTraitExpressionClass = 102,
  kAsTypeExpressionClass = 103,
  kAtomicExpressionClass = 104,
  kBinaryOperatorClass = 105,
  kCompoundAssignOperatorClass = 106,
  kBlockExpressionClass = 107,
  kCXXBindTemporaryExpressionClass = 108,
  kCXXBoolLiteralExpressionClass = 109,
  kCXXConstructExpressionClass = 110,
  kCXXTemporaryObjectExpressionClass = 111,
  kCXXDefaultArgumentExpressionClass = 112,
  kCXXDefaultInitializerExpressionClass = 113,
  kCXXDeleteExpressionClass = 114,
  kCXXDependentScopeMemberExpressionClass = 115,
  kCXXFoldExpressionClass = 116,
  kCXXInheritedConstructorInitializerExpressionClass = 117,
  kCXXNewExpressionClass = 118,
  kCXXNoexceptExpressionClass = 119,
  kCXXNullPointerLiteralExpressionClass = 120,
  kCXXPseudoDestructorExpressionClass = 121,
  kCXXRewrittenBinaryOperatorClass = 122,
  kCXXScalarValueInitializerExpressionClass = 123,
  kCXXStdInitializerListExpressionClass = 124,
  kCXXThisExpressionClass = 125,
  kCXXThrowExpressionClass = 126,
  kCXXTypeidExpressionClass = 127,
  kCXXUnresolvedConstructExpressionClass = 128,
  kCXXUuidofExpressionClass = 129,
  kCallExpressionClass = 130,
  kCUDAKernelCallExpressionClass = 131,
  kCXXMemberCallExpressionClass = 132,
  kCXXOperatorCallExpressionClass = 133,
  kUserDefinedLiteralClass = 134,
  kBuiltinBitCastExpressionClass = 135,
  kCStyleCastExpressionClass = 136,
  kCXXFunctionalCastExpressionClass = 137,
  kCXXAddrspaceCastExpressionClass = 138,
  kCXXConstCastExpressionClass = 139,
  kCXXDynamicCastExpressionClass = 140,
  kCXXReinterpretCastExpressionClass = 141,
  kCXXStaticCastExpressionClass = 142,
  kObjCBridgedCastExpressionClass = 143,
  kImplicitCastExpressionClass = 144,
  kCharacterLiteralClass = 145,
  kChooseExpressionClass = 146,
  kCompoundLiteralExpressionClass = 147,
  kConceptSpecializationExpressionClass = 148,
  kConvertVectorExpressionClass = 149,
  kCoawaitExpressionClass = 150,
  kCoyieldExpressionClass = 151,
  kDeclarationReferenceExpressionClass = 152,
  kDependentCoawaitExpressionClass = 153,
  kDependentScopeDeclarationReferenceExpressionClass = 154,
  kDesignatedInitializerExpressionClass = 155,
  kDesignatedInitializerUpdateExpressionClass = 156,
  kExpressionTraitExpressionClass = 157,
  kExtVectorElementExpressionClass = 158,
  kFixedPointLiteralClass = 159,
  kFloatingLiteralClass = 160,
  kConstantExpressionClass = 161,
  kExpressionWithCleanupsClass = 162,
  kFunctionParmPackExpressionClass = 163,
  kGNUNullExpressionClass = 164,
  kGenericSelectionExpressionClass = 165,
  kImaginaryLiteralClass = 166,
  kImplicitValueInitializerExpressionClass = 167,
  kInitializerListExpressionClass = 168,
  kIntegerLiteralClass = 169,
  kLambdaExpressionClass = 170,
  kMSPropertyReferenceExpressionClass = 171,
  kMSPropertySubscriptExpressionClass = 172,
  kMaterializeTemporaryExpressionClass = 173,
  kMatrixSubscriptExpressionClass = 174,
  kMemberExpressionClass = 175,
  kNoInitializerExpressionClass = 176,
  kOMPArraySectionExpressionClass = 177,
  kOMPArrayShapingExpressionClass = 178,
  kOMPIteratorExpressionClass = 179,
  kObjCArrayLiteralClass = 180,
  kObjCAvailabilityCheckExpressionClass = 181,
  kObjCBoolLiteralExpressionClass = 182,
  kObjCBoxedExpressionClass = 183,
  kObjCDictionaryLiteralClass = 184,
  kObjCEncodeExpressionClass = 185,
  kObjCIndirectCopyRestoreExpressionClass = 186,
  kObjCIsaExpressionClass = 187,
  kObjCIvarReferenceExpressionClass = 188,
  kObjCMessageExpressionClass = 189,
  kObjCPropertyReferenceExpressionClass = 190,
  kObjCProtocolExpressionClass = 191,
  kObjCSelectorExpressionClass = 192,
  kObjCStringLiteralClass = 193,
  kObjCSubscriptReferenceExpressionClass = 194,
  kOffsetOfExpressionClass = 195,
  kOpaqueValueExpressionClass = 196,
  kUnresolvedLookupExpressionClass = 197,
  kUnresolvedMemberExpressionClass = 198,
  kPackExpansionExpressionClass = 199,
  kParenthesisExpressionClass = 200,
  kParenthesisListExpressionClass = 201,
  kPredefinedExpressionClass = 202,
  kPseudoObjectExpressionClass = 203,
  kRecoveryExpressionClass = 204,
  kRequiresExpressionClass = 205,
  kSYCLUniqueStableNameExpressionClass = 206,
  kShuffleVectorExpressionClass = 207,
  kSizeOfPackExpressionClass = 208,
  kSourceTokenExpressionClass = 209,
  kStatementExpressionClass = 210,
  kStringLiteralClass = 211,
  kSubstNonTypeTemplateParmExpressionClass = 212,
  kSubstNonTypeTemplateParmPackExpressionClass = 213,
  kTypeTraitExpressionClass = 214,
  kTypoExpressionClass = 215,
  kUnaryExpressionOrTypeTraitExpressionClass = 216,
  kUnaryOperatorClass = 217,
  kVAArgumentExpressionClass = 218,
  kLabelStatementClass = 219,
  kWhileStatementClass = 220,
};

enum class StringLiteralStringKind : unsigned int {
  kAscii = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class TemplateArgumentArgKind : unsigned int {
  kNull = 0,
  kType = 1,
  kDeclaration = 2,
  kNullPointer = 3,
  kIntegral = 4,
  kTemplate = 5,
  kTemplateExpansion = 6,
  kExpression = 7,
  kPack = 8,
};

enum class TypeScalarTypeKind : unsigned int {
  kCPointer = 0,
  kBlockPointer = 1,
  kObjCObjectPointer = 2,
  kMemberPointer = 3,
  kBoolean = 4,
  kIntegral = 5,
  kFloating = 6,
  kIntegralComplex = 7,
  kFloatingComplex = 8,
  kFixedPoint = 9,
};

enum class TypeTypeClass : unsigned int {
  kAdjusted = 0,
  kDecayed = 1,
  kConstantArray = 2,
  kDependentSizedArray = 3,
  kIncompleteArray = 4,
  kVariableArray = 5,
  kAtomic = 6,
  kAttributed = 7,
  kBlockPointer = 8,
  kBuiltin = 9,
  kComplex = 10,
  kDecltype = 11,
  kAuto = 12,
  kDeducedTemplateSpecialization = 13,
  kDependentAddressSpace = 14,
  kDependentExtInt = 15,
  kDependentName = 16,
  kDependentSizedExtVector = 17,
  kDependentTemplateSpecialization = 18,
  kDependentVector = 19,
  kElaborated = 20,
  kExtInt = 21,
  kFunctionNoProto = 22,
  kFunctionProto = 23,
  kInjectedClassName = 24,
  kMacroQualified = 25,
  kConstantMatrix = 26,
  kDependentSizedMatrix = 27,
  kMemberPointer = 28,
  kObjCObjectPointer = 29,
  kObjCObject = 30,
  kObjCInterface = 31,
  kObjCTypeParam = 32,
  kPackExpansion = 33,
  kParenthesis = 34,
  kPipe = 35,
  kPointer = 36,
  kLValueReference = 37,
  kRValueReference = 38,
  kSubstTemplateTypeParmPack = 39,
  kSubstTemplateTypeParm = 40,
  kEnum = 41,
  kRecord = 42,
  kTemplateSpecialization = 43,
  kTemplateTypeParm = 44,
  kTypeOfExpression = 45,
  kTypeOf = 46,
  kTypedef = 47,
  kUnaryTransform = 48,
  kUnresolvedUsing = 49,
  kVector = 50,
  kExtVector = 51,
};

enum class UnaryTransformTypeUTTKind : unsigned int {
  kEnumUnderlyingType = 0,
};

enum class UserDefinedLiteralLiteralOperatorKind : unsigned int {
  kRaw = 0,
  kTemplate = 1,
  kInteger = 2,
  kFloating = 3,
  kString = 4,
  kCharacter = 5,
};

enum class VarDeclDefinitionKind : unsigned int {
  kDeclarationOnly = 0,
  kTentativeDefinition = 1,
  kDefinition = 2,
};

enum class VarDeclInitializationStyle : unsigned int {
  kCInit = 0,
  kCallInitializer = 1,
  kListInitializer = 2,
};

enum class VarDeclTLSKind : unsigned int {
  kNone = 0,
  kStatic = 1,
  kDynamic = 2,
};

enum class VectorTypeVectorKind : unsigned int {
  kGenericVector = 0,
  kAltiVecVector = 1,
  kAltiVecPixel = 2,
  kAltiVecBoolean = 3,
  kNeonVector = 4,
  kNeonPolyVector = 5,
  kSveFixedLengthDataVector = 6,
  kSveFixedLengthPredicateVector = 7,
};

enum class ADLCallKind : bool {
  kNotADL = 0,
  kUsesADL = 1,
};

enum class ASTDumpOutputFormat : unsigned int {
  kDefault = 0,
  kJSON = 1,
};

enum class AccessControl : unsigned int {
  kNone = 0,
  kPrivate = 1,
  kProtected = 2,
  kPublic = 3,
  kPackage = 4,
};

enum class AccessSpecifier : unsigned int {
  kPublic = 0,
  kProtected = 1,
  kPrivate = 2,
  kNone = 3,
};

enum class AddrSpaceMapMangling : unsigned int {
  kTarget = 0,
  kOn = 1,
  kOff = 2,
};

enum class AllocatorTypeTy : unsigned int {
  kOMPNullMemoryAlloc = 0,
  kOMPDefaultMemoryAlloc = 1,
  kOMPLargeCapMemoryAlloc = 2,
  kOMPConstMemoryAlloc = 3,
  kOMPHighBWMemoryAlloc = 4,
  kOMPLowLatMemoryAlloc = 5,
  kOMPCGroupMemoryAlloc = 6,
  kOMPPTeamMemoryAlloc = 7,
  kOMPThreadMemoryAlloc = 8,
  kOMPUserDefinedMemoryAlloc = 9,
};

enum class AltivecSrcCompatKind : int {
  kMixed = 0,
  kGCC = 1,
  kXL = 2,
  kDefault = 0,
};

enum class ArgKind : unsigned int {
  kNull = 0,
  kType = 1,
  kDeclaration = 2,
  kNullPointer = 3,
  kIntegral = 4,
  kTemplate = 5,
  kTemplateExpansion = 6,
  kExpression = 7,
  kPack = 8,
};

enum class ArgPassingKind : unsigned int {
  kCanPassInRegs = 0,
  kCannotPassInRegs = 1,
  kCanNeverPassInRegs = 2,
};

enum class ArgumentKind : unsigned int {
  kStdString = 0,
  kCString = 1,
  kSint = 2,
  kUint = 3,
  kTokenkind = 4,
  kIdentifierinfo = 5,
  kAddrspace = 6,
  kQualified = 7,
  kQualtype = 8,
  kDeclarationname = 9,
  kNameddecl = 10,
  kNestednamespec = 11,
  kDeclcontext = 12,
  kQualtypePair = 13,
  kAttribute = 14,
};

enum class ArraySizeModifier : unsigned int {
  kNormal = 0,
  kStatic = 1,
  kStar = 2,
};

enum class ArrayTypeTrait : unsigned int {
  kArrayRank = 0,
  kArrayExtent = 1,
};

enum class AtomicOp : unsigned int {
  kC11AtomicInitializer = 0,
  kC11AtomicLoad = 1,
  kC11AtomicStore = 2,
  kC11AtomicExchange = 3,
  kC11AtomicCompareExchangeStrong = 4,
  kC11AtomicCompareExchangeWeak = 5,
  kC11AtomicFetchAdd = 6,
  kC11AtomicFetchSub = 7,
  kC11AtomicFetchAnd = 8,
  kC11AtomicFetchOr = 9,
  kC11AtomicFetchXor = 10,
  kC11AtomicFetchMax = 11,
  kC11AtomicFetchMin = 12,
  kAtomicLoad = 13,
  kAtomicLoadN = 14,
  kAtomicStore = 15,
  kAtomicStoreN = 16,
  kAtomicExchange = 17,
  kAtomicExchangeN = 18,
  kAtomicCompareExchange = 19,
  kAtomicCompareExchangeN = 20,
  kAtomicFetchAdd = 21,
  kAtomicFetchSub = 22,
  kAtomicFetchAnd = 23,
  kAtomicFetchOr = 24,
  kAtomicFetchXor = 25,
  kAtomicFetchNand = 26,
  kAtomicAddFetch = 27,
  kAtomicSubFetch = 28,
  kAtomicAndFetch = 29,
  kAtomicOrFetch = 30,
  kAtomicXorFetch = 31,
  kAtomicMaxFetch = 32,
  kAtomicMinFetch = 33,
  kAtomicNandFetch = 34,
  kOpenclAtomicInitializer = 35,
  kOpenclAtomicLoad = 36,
  kOpenclAtomicStore = 37,
  kOpenclAtomicExchange = 38,
  kOpenclAtomicCompareExchangeStrong = 39,
  kOpenclAtomicCompareExchangeWeak = 40,
  kOpenclAtomicFetchAdd = 41,
  kOpenclAtomicFetchSub = 42,
  kOpenclAtomicFetchAnd = 43,
  kOpenclAtomicFetchOr = 44,
  kOpenclAtomicFetchXor = 45,
  kOpenclAtomicFetchMin = 46,
  kOpenclAtomicFetchMax = 47,
  kAtomicFetchMin = 48,
  kAtomicFetchMax = 49,
};

enum class AtomicScopeModelKind : int {
  kNone = 0,
  kOpenCL = 1,
};

enum class AttributeKind : unsigned int {
  kAddressSpace = 0,
  kArmMveStrictPolymorphism = 1,
  kCmseNSCall = 2,
  kNoDeref = 3,
  kObjCGC = 4,
  kObjCInertUnsafeUnretained = 5,
  kObjCKindOf = 6,
  kOpenCLConstantAddressSpace = 7,
  kOpenCLGenericAddressSpace = 8,
  kOpenCLGlobalAddressSpace = 9,
  kOpenCLGlobalDeviceAddressSpace = 10,
  kOpenCLGlobalHostAddressSpace = 11,
  kOpenCLLocalAddressSpace = 12,
  kOpenCLPrivateAddressSpace = 13,
  kPtr32 = 14,
  kPtr64 = 15,
  kSPtr = 16,
  kTypeNonNull = 17,
  kTypeNullUnspecified = 18,
  kTypeNullable = 19,
  kTypeNullableResult = 20,
  kUPtr = 21,
  kFallThrough = 22,
  kLikely = 23,
  kMustTail = 24,
  kOpenCLUnrollHint = 25,
  kSuppress = 26,
  kUnlikely = 27,
  kNoMerge = 28,
  kAArch64VectorPcs = 29,
  kAcquireHandle = 30,
  kAnyX86NoCfCheck = 31,
  kCDecl = 32,
  kFastCall = 33,
  kIntelOclBicc = 34,
  kLifetimeBound = 35,
  kMSABI = 36,
  kNSReturnsRetained = 37,
  kObjCOwnership = 38,
  kPascal = 39,
  kPcs = 40,
  kPreserveAll = 41,
  kPreserveMost = 42,
  kRegCall = 43,
  kStdCall = 44,
  kSwiftAsyncCall = 45,
  kSwiftCall = 46,
  kSysVABI = 47,
  kThisCall = 48,
  kVectorCall = 49,
  kSwiftAsyncContext = 50,
  kSwiftContext = 51,
  kSwiftErrorResult = 52,
  kSwiftIndirectResult = 53,
  kAnnotate = 54,
  kCFConsumed = 55,
  kCarriesDependency = 56,
  kNSConsumed = 57,
  kNonNull = 58,
  kOSConsumed = 59,
  kPassObjectSize = 60,
  kReleaseHandle = 61,
  kUseHandle = 62,
  kAMDGPUFlatWorkGroupSize = 63,
  kAMDGPUNumSGPR = 64,
  kAMDGPUNumVGPR = 65,
  kAMDGPUWavesPerEU = 66,
  kARMInterrupt = 67,
  kAVRInterrupt = 68,
  kAVRSignal = 69,
  kAcquireCapability = 70,
  kAcquiredAfter = 71,
  kAcquiredBefore = 72,
  kAlignMac68k = 73,
  kAlignNatural = 74,
  kAligned = 75,
  kAllocAlign = 76,
  kAllocSize = 77,
  kAlwaysDestroy = 78,
  kAlwaysInline = 79,
  kAnalyzerNoReturn = 80,
  kAnyX86Interrupt = 81,
  kAnyX86NoCallerSavedRegisters = 82,
  kArcWeakrefUnavailable = 83,
  kArgumentWithTypeTag = 84,
  kArmBuiltinAlias = 85,
  kArtificial = 86,
  kAssemblyLabel = 87,
  kAssertCapability = 88,
  kAssertExclusiveLock = 89,
  kAssertSharedLock = 90,
  kAssumeAligned = 91,
  kAssumption = 92,
  kAvailability = 93,
  kBPFPreserveAccessIndex = 94,
  kBlocks = 95,
  kBuiltin = 96,
  kC11NoReturn = 97,
  kCFAuditedTransfer = 98,
  kCFGuard = 99,
  kCFICanonicalJumpTable = 100,
  kCFReturnsNotRetained = 101,
  kCFReturnsRetained = 102,
  kCFUnknownTransfer = 103,
  kCPUDispatch = 104,
  kCPUSpecific = 105,
  kCUDAConstant = 106,
  kCUDADevice = 107,
  kCUDADeviceBuiltinSurfaceType = 108,
  kCUDADeviceBuiltinTextureType = 109,
  kCUDAGlobal = 110,
  kCUDAHost = 111,
  kCUDAInvalidTarget = 112,
  kCUDALaunchBounds = 113,
  kCUDAShared = 114,
  kCXX11NoReturn = 115,
  kCallableWhen = 116,
  kCallback = 117,
  kCapability = 118,
  kCapturedRecord = 119,
  kCleanup = 120,
  kCmseNSEntry = 121,
  kCodeSeg = 122,
  kCold = 123,
  kCommon = 124,
  kConst = 125,
  kConstInitializer = 126,
  kConstructor = 127,
  kConsumable = 128,
  kConsumableAutoCast = 129,
  kConsumableSetOnRead = 130,
  kConvergent = 131,
  kDLLExport = 132,
  kDLLExportStaticLocal = 133,
  kDLLImport = 134,
  kDLLImportStaticLocal = 135,
  kDeprecated = 136,
  kDestructor = 137,
  kDiagnoseIf = 138,
  kDisableTailCalls = 139,
  kEmptyBases = 140,
  kEnableIf = 141,
  kEnforceTCB = 142,
  kEnforceTCBLeaf = 143,
  kEnumExtensibility = 144,
  kExcludeFromExplicitInstantiation = 145,
  kExclusiveTrylockFunction = 146,
  kExternalSourceSymbol = 147,
  kFinal = 148,
  kFlagEnum = 149,
  kFlatten = 150,
  kFormat = 151,
  kFormatArgument = 152,
  kGNUInline = 153,
  kGuardedBy = 154,
  kGuardedVariable = 155,
  kHIPManaged = 156,
  kHot = 157,
  kIBAction = 158,
  kIBOutlet = 159,
  kIBOutletCollection = 160,
  kInitializerPriority = 161,
  kInternalLinkage = 162,
  kLTOVisibilityPublic = 163,
  kLayoutVersion = 164,
  kLeaf = 165,
  kLockReturned = 166,
  kLocksExcluded = 167,
  kM68kInterrupt = 168,
  kMIGServerRoutine = 169,
  kMSAllocator = 170,
  kMSInheritance = 171,
  kMSNoVTable = 172,
  kMSP430Interrupt = 173,
  kMSStruct = 174,
  kMSVtorDisp = 175,
  kMaxFieldAlignment = 176,
  kMayAlias = 177,
  kMicroMips = 178,
  kMinSize = 179,
  kMinVectorWidth = 180,
  kMips16 = 181,
  kMipsInterrupt = 182,
  kMipsLongCall = 183,
  kMipsShortCall = 184,
  kNSConsumesSelf = 185,
  kNSErrorDomain = 186,
  kNSReturnsAutoreleased = 187,
  kNSReturnsNotRetained = 188,
  kNaked = 189,
  kNoAlias = 190,
  kNoCommon = 191,
  kNoDebug = 192,
  kNoDestroy = 193,
  kNoDuplicate = 194,
  kNoInline = 195,
  kNoInstrumentFunction = 196,
  kNoMicroMips = 197,
  kNoMips16 = 198,
  kNoProfileFunction = 199,
  kNoReturn = 200,
  kNoSanitize = 201,
  kNoSpeculativeLoadHardening = 202,
  kNoSplitStack = 203,
  kNoStackProtector = 204,
  kNoThreadSafetyAnalysis = 205,
  kNoThrow = 206,
  kNoUniqueAddress = 207,
  kNotTailCalled = 208,
  kOMPAllocateDeclaration = 209,
  kOMPCaptureNoInitializer = 210,
  kOMPDeclareTargetDeclaration = 211,
  kOMPDeclareVariant = 212,
  kOMPThreadPrivateDeclaration = 213,
  kOSConsumesThis = 214,
  kOSReturnsNotRetained = 215,
  kOSReturnsRetained = 216,
  kOSReturnsRetainedOnNonZero = 217,
  kOSReturnsRetainedOnZero = 218,
  kObjCBridge = 219,
  kObjCBridgeMutable = 220,
  kObjCBridgeRelated = 221,
  kObjCException = 222,
  kObjCExplicitProtocolImplementation = 223,
  kObjCExternallyRetained = 224,
  kObjCIndependentClass = 225,
  kObjCMethodFamily = 226,
  kObjCNSObject = 227,
  kObjCPreciseLifetime = 228,
  kObjCRequiresPropertyDefinitions = 229,
  kObjCRequiresSuper = 230,
  kObjCReturnsInnerPointer = 231,
  kObjCRootClass = 232,
  kObjCSubclassingRestricted = 233,
  kOpenCLIntelReqdSubGroupSize = 234,
  kOpenCLKernel = 235,
  kOptimizeNone = 236,
  kOverride = 237,
  kOwner = 238,
  kOwnership = 239,
  kPacked = 240,
  kParamTypestate = 241,
  kPatchableFunctionEntry = 242,
  kPointer = 243,
  kPragmaClangBSSSection = 244,
  kPragmaClangDataSection = 245,
  kPragmaClangRelroSection = 246,
  kPragmaClangRodataSection = 247,
  kPragmaClangTextSection = 248,
  kPreferredName = 249,
  kPtGuardedBy = 250,
  kPtGuardedVariable = 251,
  kPure = 252,
  kRISCVInterrupt = 253,
  kReinitializes = 254,
  kReleaseCapability = 255,
  kReqdWorkGroupSize = 256,
  kRequiresCapability = 257,
  kRestrict = 258,
  kRetain = 259,
  kReturnTypestate = 260,
  kReturnsNonNull = 261,
  kReturnsTwice = 262,
  kSYCLKernel = 263,
  kScopedLockable = 264,
  kSection = 265,
  kSelectAny = 266,
  kSentinel = 267,
  kSetTypestate = 268,
  kSharedTrylockFunction = 269,
  kSpeculativeLoadHardening = 270,
  kStandaloneDebug = 271,
  kStrictFP = 272,
  kSwiftAsync = 273,
  kSwiftAsyncError = 274,
  kSwiftAsyncName = 275,
  kSwiftAttribute = 276,
  kSwiftBridge = 277,
  kSwiftBridgedTypedef = 278,
  kSwiftError = 279,
  kSwiftName = 280,
  kSwiftNewType = 281,
  kSwiftPrivate = 282,
  kTLSModel = 283,
  kTarget = 284,
  kTestTypestate = 285,
  kTransparentUnion = 286,
  kTrivialABI = 287,
  kTryAcquireCapability = 288,
  kTypeTagForDatatype = 289,
  kTypeVisibility = 290,
  kUnavailable = 291,
  kUninitialized = 292,
  kUnused = 293,
  kUsed = 294,
  kUsingIfExists = 295,
  kUuid = 296,
  kVecReturn = 297,
  kVecTypeHint = 298,
  kVisibility = 299,
  kWarnUnused = 300,
  kWarnUnusedResult = 301,
  kWeak = 302,
  kWeakImport = 303,
  kWeakReference = 304,
  kWebAssemblyExportName = 305,
  kWebAssemblyImportModule = 306,
  kWebAssemblyImportName = 307,
  kWorkGroupSizeHint = 308,
  kX86ForceAlignArgumentPointer = 309,
  kXRayInstrument = 310,
  kXRayLogArguments = 311,
  kAbiTag = 312,
  kAlias = 313,
  kAlignValue = 314,
  kBuiltinAlias = 315,
  kCalledOnce = 316,
  kIFunc = 317,
  kInitializerSeg = 318,
  kLoaderUninitialized = 319,
  kLoopHint = 320,
  kMode = 321,
  kNoBuiltin = 322,
  kNoEscape = 323,
  kOMPCaptureKind = 324,
  kOMPDeclareSimdDeclaration = 325,
  kOMPReferencedVariable = 326,
  kObjCBoxable = 327,
  kObjCClassStub = 328,
  kObjCDesignatedInitializer = 329,
  kObjCDirect = 330,
  kObjCDirectMembers = 331,
  kObjCNonLazyClass = 332,
  kObjCNonRuntimeProtocol = 333,
  kObjCRuntimeName = 334,
  kObjCRuntimeVisible = 335,
  kOpenCLAccess = 336,
  kOverloadable = 337,
  kRenderScriptKernel = 338,
  kSwiftObjCMembers = 339,
  kThread = 340,
};

enum class AutoTypeKeyword : int {
  kAuto = 0,
  kDecltypeAuto = 1,
  kGNUAutoType = 2,
};

enum class AvailabilityResult : unsigned int {
  kAvailable = 0,
  kNotYetIntroduced = 1,
  kDeprecated = 2,
  kUnavailable = 3,
};

enum class BinaryOperatorKind : unsigned int {
  kPointerMemoryD = 0,
  kPointerMemoryI = 1,
  kMul = 2,
  kDiv = 3,
  kRem = 4,
  kAdd = 5,
  kSub = 6,
  kShl = 7,
  kShr = 8,
  kCmp = 9,
  kLT = 10,
  kGT = 11,
  kLE = 12,
  kGE = 13,
  kEQ = 14,
  kNE = 15,
  kAnd = 16,
  kXor = 17,
  kOr = 18,
  kLAnd = 19,
  kLOr = 20,
  kAssign = 21,
  kMulAssign = 22,
  kDivAssign = 23,
  kRemAssign = 24,
  kAddAssign = 25,
  kSubAssign = 26,
  kShlAssign = 27,
  kShrAssign = 28,
  kAndAssign = 29,
  kXorAssign = 30,
  kOrAssign = 31,
  kComma = 32,
};

enum class Bits : unsigned char {
  kNone = 0,
  kUnexpandedPack = 1,
  kInstantiation = 2,
  kType = 4,
  kValue = 8,
  kDependent = 12,
  kError = 16,
  kVariablyModified = 32,
  kSyntactic = 19,
};

enum class BlockType : unsigned int {
  kByReference = 0,
};

enum class BranchStateTy : unsigned int {
  kUndefined = 0,
  kInbranch = 1,
  kNotinbranch = 2,
};

enum class CallingConv : unsigned int {
  kC = 0,
  kX86StdCall = 1,
  kX86FastCall = 2,
  kX86ThisCall = 3,
  kX86VectorCall = 4,
  kX86Pascal = 5,
  kWin64 = 6,
  kX8664SysV = 7,
  kX86RegCall = 8,
  kAAPCS = 9,
  kAAPCSVFP = 10,
  kIntelOclBicc = 11,
  kSpirFunction = 12,
  kOpenCLKernel = 13,
  kSwift = 14,
  kSwiftAsync = 15,
  kPreserveMost = 16,
  kPreserveAll = 17,
  kAArch64VectorCall = 18,
};

enum class CanThrowResult : unsigned int {
  kCannot = 0,
  kDependent = 1,
  kCan = 2,
};

enum class CapturedRegionKind : unsigned int {
  kDefault = 0,
  kObjCAtFinally = 1,
  kOpenMP = 2,
};

enum class CastKind : unsigned int {
  kDependent = 0,
  kBitCast = 1,
  kLValueBitCast = 2,
  kLValueToRValueBitCast = 3,
  kLValueToRValue = 4,
  kNoOperation = 5,
  kBaseToDerived = 6,
  kDerivedToBase = 7,
  kUncheckedDerivedToBase = 8,
  kDynamic = 9,
  kToUnion = 10,
  kArrayToPointerDecay = 11,
  kFunctionToPointerDecay = 12,
  kNullToPointer = 13,
  kNullToMemberPointer = 14,
  kBaseToDerivedMemberPointer = 15,
  kDerivedToBaseMemberPointer = 16,
  kMemberPointerToBoolean = 17,
  kReinterpretMemberPointer = 18,
  kUserDefinedConversion = 19,
  kConstructorConversion = 20,
  kIntegralToPointer = 21,
  kPointerToIntegral = 22,
  kPointerToBoolean = 23,
  kToVoid = 24,
  kMatrixCast = 25,
  kVectorSplat = 26,
  kIntegralCast = 27,
  kIntegralToBoolean = 28,
  kIntegralToFloating = 29,
  kFloatingToFixedPoint = 30,
  kFixedPointToFloating = 31,
  kFixedPointCast = 32,
  kFixedPointToIntegral = 33,
  kIntegralToFixedPoint = 34,
  kFixedPointToBoolean = 35,
  kFloatingToIntegral = 36,
  kFloatingToBoolean = 37,
  kBooleanToSignedIntegral = 38,
  kFloatingCast = 39,
  kCPointerToObjCPointerCast = 40,
  kBlockPointerToObjCPointerCast = 41,
  kAnyPointerToBlockPointerCast = 42,
  kObjCObjectLValueCast = 43,
  kFloatingRealToComplex = 44,
  kFloatingComplexToReal = 45,
  kFloatingComplexToBoolean = 46,
  kFloatingComplexCast = 47,
  kFloatingComplexToIntegralComplex = 48,
  kIntegralRealToComplex = 49,
  kIntegralComplexToReal = 50,
  kIntegralComplexToBoolean = 51,
  kIntegralComplexCast = 52,
  kIntegralComplexToFloatingComplex = 53,
  kARCProduceObject = 54,
  kARCConsumeObject = 55,
  kARCReclaimReturnedObject = 56,
  kARCExtendBlockObject = 57,
  kAtomicToNonAtomic = 58,
  kNonAtomicToAtomic = 59,
  kCopyAndAutoreleaseBlockObject = 60,
  kBuiltinFnToFnPointer = 61,
  kZeroToOCLOpaqueType = 62,
  kAddressSpaceConversion = 63,
  kIntToOCLSampler = 64,
};

enum class CharacterKind : unsigned int {
  kAscii = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class ClangABI : int {
  kVer38 = 0,
  kVer4 = 1,
  kVer6 = 2,
  kVer7 = 3,
  kVer9 = 4,
  kVer11 = 5,
  kVer12 = 6,
  kLatest = 7,
};

enum class CommentKind : unsigned int {
  kInvalid = 0,
  kOrdinaryBCPL = 1,
  kOrdinaryC = 2,
  kBCPLSlash = 3,
  kBCPLExcl = 4,
  kJavaDoc = 5,
  kQt = 6,
  kMerged = 7,
};

enum class ComparisonCategoryResult : unsigned char {
  kEqual = 0,
  kEquivalent = 1,
  kLess = 2,
  kGreater = 3,
  kUnordered = 4,
};

enum class ComparisonCategoryType : unsigned char {
  kPartialOrdering = 0,
  kWeakOrdering = 1,
  kStrongOrdering = 2,
};

enum class CompilingModuleKind : unsigned int {
  kNone = 0,
  kModuleMap = 1,
  kHeaderModule = 2,
  kModuleInterface = 3,
};

enum class ConstantExprKind : int {
  kNormal = 0,
  kNonClassTemplateArgument = 1,
  kClassTemplateArgument = 2,
  kImmediateInvocation = 3,
};

enum class ConstexprSpecKind : int {
  kUnspecified = 0,
  kConstexpr = 1,
  kConsteval = 2,
  kConstinit = 3,
};

enum class ConstructionKind : unsigned int {
  kComplete = 0,
  kNonVirtualBase = 1,
  kVirtualBase = 2,
  kDelegating = 3,
};

enum class ConsumedState : unsigned int {
  kUnknown = 0,
  kConsumed = 1,
  kUnconsumed = 2,
};

enum class ConventionKind : unsigned int {
  kNone = 0,
  kNonNullError = 1,
  kZeroArgument = 2,
  kNonZeroArgument = 3,
};

enum class CoreFoundationABI : int {
  kUnspecified = 0,
  kStandalone = 1,
  kObjectiveC = 2,
  kSwift = 3,
  kSwift50 = 4,
  kSwift42 = 5,
  kSwift41 = 6,
};

enum class DefaultArgKind : unsigned int {
  kNone = 0,
  kUnparsed = 1,
  kUninstantiated = 2,
  kNormal = 3,
};

enum class DefaultCallingConvention : unsigned int {
  kNone = 0,
  kCDecl = 1,
  kFastCall = 2,
  kStdCall = 3,
  kVectorCall = 4,
  kRegCall = 5,
};

enum class DefinitionKind : unsigned int {
  kDeclarationOnly = 0,
  kTentativeDefinition = 1,
  kDefinition = 2,
};

enum class DestructionKind : unsigned int {
  kNone = 0,
  kCxxDestructor = 1,
  kObjcStrongLifetime = 2,
  kObjcWeakLifetime = 3,
  kNontrivialCStruct = 4,
};

enum class DevTypeTy : unsigned int {
  kHost = 0,
  kNoHost = 1,
  kAny = 2,
};

enum class DiagnosticLevelMask : unsigned int {
  kNone = 0,
  kNote = 1,
  kRemark = 2,
  kWarning = 4,
  kError = 8,
  kAll = 15,
};

enum class DiagnosticType : unsigned int {
  kError = 0,
  kWarning = 1,
};

enum class ElaboratedTypeKeyword : unsigned int {
  kStruct = 0,
  kInterface = 1,
  kUnion = 2,
  kClass = 3,
  kEnum = 4,
  kTypename = 5,
  kNone = 6,
};

enum class EmbedBitcodeKind : unsigned int {
  kEmbedOff = 0,
  kEmbedAll = 1,
  kEmbedBitcode = 2,
  kEmbedMarker = 3,
};

enum class ExceptionHandlingKind : int {
  kNone = 0,
  kSjLj = 1,
  kWinEH = 2,
  kDwarfCFI = 3,
  kWasm = 4,
};

enum class ExceptionSpecificationType : unsigned int {
  kNone = 0,
  kDynamicNone = 1,
  kDynamic = 2,
  kMSAny = 3,
  kNoThrow = 4,
  kBasicNoexcept = 5,
  kDependentNoexcept = 6,
  kNoexceptFalse = 7,
  kNoexceptTrue = 8,
  kUnevaluated = 9,
  kUninstantiated = 10,
  kUnparsed = 11,
};

enum class ExplicitSpecKind : unsigned int {
  kResolvedFalse = 0,
  kResolvedTrue = 1,
  kUnresolved = 2,
};

enum class ExplicitVisibilityKind : unsigned int {
  kVisibilityForType = 0,
  kVisibilityForValue = 1,
};

enum class ExprDependence : unsigned char {
  kUnexpandedPack = 1,
  kInstantiation = 2,
  kType = 4,
  kValue = 8,
  kError = 16,
  kNone = 0,
  kAll = 31,
  kTypeValue = 12,
  kTypeInstantiation = 6,
  kValueInstantiation = 10,
  kTypeValueInstantiation = 14,
  kErrorDependent = 26,
};

enum class ExprObjectKind : unsigned int {
  kOrdinary = 0,
  kBitField = 1,
  kVectorComponent = 2,
  kObjCProperty = 3,
  kObjCSubscript = 4,
  kMatrixComponent = 5,
};

enum class ExprOffsets : int {
  kAllocator = 0,
  kAllocatorTraits = 1,
  kTotal = 2,
};

enum class ExprValueKind : unsigned int {
  kPRValue = 0,
  kLValue = 1,
  kXValue = 2,
};

enum class ExpressionTrait : unsigned int {
  kIsLValueExpression = 0,
  kIsRValueExpression = 1,
};

enum class ExtKind : unsigned int {
  kAlways = 0,
  kNever = 1,
  kReplyHazy = 2,
};

enum class ExtendArgsKind : int {
  kExtendTo32 = 0,
  kExtendTo64 = 1,
};

enum class FPExceptionModeKind : unsigned int {
  kIgnore = 0,
  kMayTrap = 1,
  kStrict = 2,
};

enum class FPModeKind : unsigned int {
  kOff = 0,
  kOn = 1,
  kFast = 2,
  kFastHonorPragmas = 3,
};

enum class FamilyKind : unsigned int {
  kNone = 0,
  kAlloc = 1,
  kCopy = 2,
  kInitializer = 3,
  kMutableCopy = 4,
  kNew = 5,
};

enum class FiniteLoopsKind : unsigned int {
  kLanguage = 0,
  kAlways = 1,
  kNever = 2,
};

enum class FramePointerKind : int {
  kNone = 0,
  kNonLeaf = 1,
  kAll = 2,
};

enum class FriendObjectKind : unsigned int {
  kNone = 0,
  kDeclared = 1,
  kUndeclared = 2,
};

enum class GC : unsigned int {
  kGCNone = 0,
  kWeak = 1,
  kStrong = 2,
};

enum class GCMode : unsigned int {
  kNonGC = 0,
  kGCOnly = 1,
  kHybridGC = 2,
};

enum class GVALinkage : unsigned int {
  kInternal = 0,
  kAvailableExternally = 1,
  kDiscardableODR = 2,
  kStrongExternal = 3,
  kStrongODR = 4,
};

enum class GetBuiltinTypeError : unsigned int {
  kNone = 0,
  kMissingType = 1,
  kMissingStdio = 2,
  kMissing = 3,
  kMissingUcontext = 4,
};

enum class GuardArg : unsigned int {
  kNocf = 0,
};

enum class ID : unsigned int {
  kWorkGroup = 1,
  kDevice = 2,
  kAllSVMDevices = 3,
  kSubGroup = 4,
};

enum class IdentKind : unsigned int {
  kFunc = 0,
  kFunction = 1,
  kLFunction = 2,
  kFuncDName = 3,
  kFuncSig = 4,
  kLFuncSig = 5,
  kPrettyFunction = 6,
  kPrettyFunctionNoVirtual = 7,
};

enum class IdentifierInfoFlag : unsigned int {
  kZeroArgument = 1,
  kOneArgument = 2,
  kMultiArgument = 7,
  kArgumentFlags = 7,
};

enum class IdentifierNamespace : unsigned int {
  kLabel = 1,
  kTag = 2,
  kType = 4,
  kMember = 8,
  kNamespace = 16,
  kOrdinary = 32,
  kObjCProtocol = 64,
  kOrdinaryFriend = 128,
  kTagFriend = 256,
  kUsing = 512,
  kNonMemberOperator = 1024,
  kLocalExtern = 2048,
  kOMPReduction = 4096,
  kOMPMapper = 8192,
};

enum class ImbueAttribute : int {
  kNONE = 0,
  kALWAYS = 1,
  kNEVER = 2,
  kALWAYSARG1 = 3,
};

enum class ImplementationControl : unsigned int {
  kNone = 0,
  kRequired = 1,
  kOptional = 2,
};

enum class ImplicitParamKind : unsigned int {
  kObjCSelf = 0,
  kObjCCmd = 1,
  kCXXThis = 2,
  kCXXVTT = 3,
  kCapturedContext = 4,
  kOther = 5,
};

enum class ImplicitReason : unsigned int {
  kNone = 0,
  kARCForbiddenType = 1,
  kForbiddenWeak = 2,
  kARCForbiddenConversion = 3,
  kARCInitReturnsUnrelated = 4,
  kARCFieldWithOwnership = 5,
};

enum class InClassInitStyle : unsigned int {
  kNoInitializer = 0,
  kCopyInitializer = 1,
  kListInitializer = 2,
};

enum class InheritedDesignatedInitializersState : unsigned int {
  kUnknown = 0,
  kInherited = 1,
  kNotInherited = 2,
};

enum class InitKind : unsigned int {
  kCallInitializer = 0,
  kDirectInitializer = 1,
  kCopyInitializer = 2,
};

enum class InitStorageKind : unsigned int {
  kNoInitializer = 0,
  kInClassCopyInitializer = 1,
  kInClassListInitializer = 2,
  kCapturedVLAType = 3,
};

enum class InitializationStyle : unsigned int {
  kCInit = 0,
  kCallInitializer = 1,
  kListInitializer = 2,
};

enum class InlineVariableDefinitionKind : int {
  kNone = 0,
  kWeak = 1,
  kWeakUnknown = 2,
  kStrong = 3,
};

enum class InliningMethod : unsigned int {
  kNormalInlining = 0,
  kOnlyHintInlining = 1,
  kOnlyAlwaysInlining = 2,
};

enum class InterruptType : unsigned int {
  kIRQ = 0,
  kFIQ = 1,
  kSWI = 2,
  kABORT = 3,
  kUNDEF = 4,
  kGeneric = 5,
};

enum class Kinds : unsigned int {
  kLValue = 0,
  kXValue = 1,
  kFunction = 2,
  kVoid = 3,
  kAddressableVoid = 4,
  kDuplicateVectorComponents = 5,
  kMemberFunction = 6,
  kSubObjCPropertySetting = 7,
  kClassTemporary = 8,
  kArrayTemporary = 9,
  kObjCMessageRValue = 10,
  kPRValue = 11,
};

enum class LValueClassification : unsigned int {
  kValid = 0,
  kNotObjectType = 1,
  kIncompleteVoidType = 2,
  kDuplicateVectorComponents = 3,
  kInvalidExpression = 4,
  kInvalidMessageExpression = 5,
  kMemberFunction = 6,
  kSubObjCPropertySetting = 7,
  kClassTemporary = 8,
  kArrayTemporary = 9,
};

enum class LambdaCaptureDefault : unsigned int {
  kNone = 0,
  kByCopy = 1,
  kByReference = 2,
};

enum class LambdaCaptureKind : unsigned int {
  kThis = 0,
  kStarThis = 1,
  kByCopy = 2,
  kByReference = 3,
  kVLAType = 4,
};

enum class LangAS : unsigned int {
  kDefault = 0,
  kOpenclGlobal = 1,
  kOpenclLocal = 2,
  kOpenclConstant = 3,
  kOpenclPrivate = 4,
  kOpenclGeneric = 5,
  kOpenclGlobalDevice = 6,
  kOpenclGlobalHost = 7,
  kCudaDevice = 8,
  kCudaConstant = 9,
  kCudaShared = 10,
  kSyclGlobal = 11,
  kSyclGlobalDevice = 12,
  kSyclGlobalHost = 13,
  kSyclLocal = 14,
  kSyclPrivate = 15,
  kPtr32Sptr = 16,
  kPtr32Uptr = 17,
  kPtr64 = 18,
};

enum class LangFeatures : unsigned int {
  kLineComment = 1,
  kC99 = 2,
  kC11 = 4,
  kC17 = 8,
  kC2x = 16,
  kCPlusPlus = 32,
  kCPlusPlus11 = 64,
  kCPlusPlus14 = 128,
  kCPlusPlus17 = 256,
  kCPlusPlus20 = 512,
  kCPlusPlus2b = 1024,
  kDigraphs = 2048,
  kGNUMode = 4096,
  kHexFloat = 8192,
  kImplicitInt = 16384,
  kOpenCL = 32768,
};

enum class Language : unsigned char {
  kUnknown = 0,
  kAssembly = 1,
  kLLVMIR = 2,
  kC = 3,
  kCXX = 4,
  kObjC = 5,
  kObjCXX = 6,
  kOpenCL = 7,
  kOpenCLCXX = 8,
  kCUDA = 9,
  kRenderScript = 10,
  kHIP = 11,
};

enum class LanguageIDs : unsigned int {
  kC = 1,
  kCxx = 2,
};

enum class LanguageLinkage : unsigned int {
  kCLanguageLinkage = 0,
  kCXXLanguageLinkage = 1,
  kNoLanguageLinkage = 2,
};

enum class LaxVectorConversionKind : int {
  kNone = 0,
  kInteger = 1,
  kAll = 2,
};

enum class Level : unsigned int {
  kIgnored = 0,
  kNote = 1,
  kRemark = 2,
  kWarning = 3,
  kError = 4,
  kFatal = 5,
};

enum class Likelihood : int {
  kUnlikely = -1,
  kNone = 0,
  kLikely = 1,
};

enum class Linkage : unsigned char {
  kNoLinkage = 0,
  kInternalLinkage = 1,
  kUniqueExternalLinkage = 2,
  kVisibleNoLinkage = 3,
  kModuleInternalLinkage = 4,
  kModuleLinkage = 5,
  kExternalLinkage = 6,
};

enum class LiteralOperatorKind : unsigned int {
  kRaw = 0,
  kTemplate = 1,
  kInteger = 2,
  kFloating = 3,
  kString = 4,
  kCharacter = 5,
};

enum class LoopHintState : unsigned int {
  kEnable = 0,
  kDisable = 1,
  kNumeric = 2,
  kFixedWidth = 3,
  kScalableWidth = 4,
  kAssumeSafety = 5,
  kFull = 6,
};

enum class MSInheritanceModel : int {
  kSingle = 0,
  kMultiple = 1,
  kVirtual = 2,
  kUnspecified = 3,
};

enum class MSVCMajorVersion : unsigned int {
  kMSVC2010 = 1600,
  kMSVC2012 = 1700,
  kMSVC2013 = 1800,
  kMSVC2015 = 1900,
  kMSVC2017 = 1910,
  kMSVC20175 = 1912,
  kMSVC20177 = 1914,
  kMSVC2019 = 1920,
  kMSVC20198 = 1928,
};

enum class MSVtorDispMode : int {
  kNever = 0,
  kForVirtualBaseOverride = 1,
  kForVFTable = 2,
};

enum class MapTypeTy : unsigned int {
  kTo = 0,
  kLink = 1,
};

enum class MethodRefFlags : unsigned int {
  kMethodReferenceNone = 0,
  kMethodReferenceGetter = 1,
  kMethodReferenceSetter = 2,
};

enum class ModifiableType : unsigned int {
  kUntested = 0,
  kModifiable = 1,
  kRValue = 2,
  kFunction = 3,
  kLValueCast = 4,
  kNoSetterProperty = 5,
  kConstQualified = 6,
  kConstQualifiedField = 7,
  kConstAddrSpace = 8,
  kArrayType = 9,
  kIncompleteType = 10,
};

enum class ModuleOwnershipKind : unsigned int {
  kUnowned = 0,
  kVisible = 1,
  kVisibleWhenImported = 2,
  kModulePrivate = 3,
};

enum class MultiVersionKind : int {
  kNone = 0,
  kTarget = 1,
  kCPUSpecific = 2,
  kCPUDispatch = 3,
};

enum class NameKind : unsigned int {
  kTemplate = 0,
  kOverloadedTemplate = 1,
  kAssumedTemplate = 2,
  kQualifiedTemplate = 3,
  kDependentTemplate = 4,
  kSubstTemplateTemplateParm = 5,
  kSubstTemplateTemplateParmPack = 6,
};

enum class NeedExtraManglingDecl_t : unsigned int {
  kNeedExtraManglingDeclaration = 0,
};

enum class NestedNameSpecifierDependence : unsigned char {
  kUnexpandedPack = 1,
  kInstantiation = 2,
  kDependent = 4,
  kError = 8,
  kNone = 0,
  kDependentInstantiation = 6,
  kAll = 15,
};

enum class NewtypeKind : unsigned int {
  kStruct = 0,
  kEnum = 1,
};

enum class NonOdrUseReason : unsigned int {
  kNone = 0,
  kUnevaluated = 1,
  kConstant = 2,
  kDiscarded = 3,
};

enum class Nonce_ObjCInterface : unsigned int {
  kObjCInterface = 0,
};

enum class NullPointerConstantKind : unsigned int {
  kNotNull = 0,
  kZeroExpression = 1,
  kZeroLiteral = 2,
  kCXX11Nullptr = 3,
  kGNUNull = 4,
};

enum class NullPointerConstantValueDependence : unsigned int {
  kNeverValueDependent = 0,
  kValueDependentIsNull = 1,
  kValueDependentIsNotNull = 2,
};

enum class NullabilityKind : unsigned char {
  kNonNull = 0,
  kNullable = 1,
  kUnspecified = 2,
  kNullableResult = 3,
};

enum class ObjCBridgeCastKind : unsigned int {
  kBridge = 0,
  kBridgeTransfer = 1,
  kBridgeRetained = 2,
};

enum class ObjCDeclQualifier : unsigned int {
  kNone = 0,
  kIn = 1,
  kInout = 2,
  kOut = 4,
  kBycopy = 8,
  kByref = 16,
  kOneway = 32,
  kCSNullability = 64,
};

enum class ObjCDispatchMethodKind : unsigned int {
  kLegacy = 0,
  kNonLegacy = 1,
  kMixed = 2,
};

enum class ObjCInstanceTypeFamily : unsigned int {
  kNone = 0,
  kArray = 1,
  kDictionary = 2,
  kSingleton = 3,
  kInitializer = 4,
  kReturnsSelf = 5,
};

enum class ObjCKeywordKind : unsigned int {
  kNotKeyword = 0,
  kClass = 1,
  kCompatibilityAlias = 2,
  kDefinitions = 3,
  kEncode = 4,
  kObjcEnd = 5,
  kImplementation = 6,
  kInterface = 7,
  kPrivate = 8,
  kProtected = 9,
  kProtocol = 10,
  kPublic = 11,
  kSelector = 12,
  kThrow = 13,
  kTry = 14,
  kCatch = 15,
  kFinally = 16,
  kSynchronized = 17,
  kAutoreleasepool = 18,
  kProperty = 19,
  kPackage = 20,
  kRequired = 21,
  kOptional = 22,
  kSynthesize = 23,
  kDynamic = 24,
  kImport = 25,
  kAvailable = 26,
};

enum class ObjCLifetime : unsigned int {
  kNone = 0,
  kExplicitNone = 1,
  kStrong = 2,
  kWeak = 3,
  kAutoreleasing = 4,
};

enum class ObjCMethodFamily : unsigned int {
  kNone = 0,
  kAlloc = 1,
  kCopy = 2,
  kInitializer = 3,
  kMutableCopy = 4,
  kNew = 5,
  kAutorelease = 6,
  kDealloc = 7,
  kFinalize = 8,
  kRelease = 9,
  kRetain = 10,
  kRetainCount = 11,
  kSelf = 12,
  kInitialize = 13,
  kPerformSelector = 14,
};

enum class ObjCPropertyQueryKind : unsigned char {
  kQueryUnknown = 0,
  kQueryInstance = 1,
  kQueryClass = 2,
};

enum class ObjCStringFormatFamily : unsigned int {
  kNone = 0,
  kNSString = 1,
  kCFString = 2,
};

enum class ObjCSubstitutionContext : int {
  kOrdinary = 0,
  kResult = 1,
  kParameter = 2,
  kProperty = 3,
  kSuperclass = 4,
};

enum class ObjCTypeParamVariance : unsigned char {
  kInvariant = 0,
  kCovariant = 1,
  kContravariant = 2,
};

enum class OnOffSwitch : unsigned int {
  kON = 0,
  kOFF = 1,
  kDEFAULT = 2,
};

enum class OnStackType : unsigned int {
  kOnStack = 0,
};

enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned int {
  kSeqCst = 0,
  kAcqRel = 1,
  kRelaxed = 2,
  kUnknown = 3,
};

enum class OpenMPDefaultmapClauseKind : unsigned int {
  kScalar = 0,
  kAggregate = 1,
  kPointer = 2,
  kUnknown = 3,
};

enum class OpenMPDefaultmapClauseModifier : unsigned int {
  kUnknown = 3,
  kAlloc = 4,
  kTo = 5,
  kFrom = 6,
  kTofrom = 7,
  kNone = 9,
  kDefault = 10,
  kPresent = 11,
};

enum class OpenMPDependClauseKind : unsigned int {
  kIn = 0,
  kOut = 1,
  kInout = 2,
  kMutexinoutset = 3,
  kDepobj = 4,
  kSource = 5,
  kSink = 6,
  kUnknown = 7,
};

enum class OpenMPDeviceClauseModifier : unsigned int {
  kAncestor = 0,
  kDeviceNum = 1,
  kUnknown = 2,
};

enum class OpenMPDeviceType : unsigned int {
  kHost = 0,
  kNohost = 1,
  kAny = 2,
  kUnknown = 3,
};

enum class OpenMPDistScheduleClauseKind : unsigned int {
  kStatic = 0,
  kUnknown = 1,
};

enum class OpenMPLastprivateModifier : unsigned int {
  kConditional = 0,
  kUnknown = 1,
};

enum class OpenMPLinearClauseKind : unsigned int {
  kVal = 0,
  kReference = 1,
  kUval = 2,
  kUnknown = 3,
};

enum class OpenMPMapClauseKind : unsigned int {
  kAlloc = 0,
  kTo = 1,
  kFrom = 2,
  kTofrom = 3,
  kDelete = 4,
  kRelease = 5,
  kUnknown = 6,
};

enum class OpenMPMapModifierKind : unsigned int {
  kUnknown = 6,
  kAlways = 7,
  kClose = 8,
  kMapper = 9,
  kPresent = 10,
};

enum class OpenMPMotionModifierKind : unsigned int {
  kMOTIONMODIFIERMapper = 0,
  kMOTIONMODIFIERPresent = 1,
  kMOTIONMODIFIERUnknown = 2,
};

enum class OpenMPOrderClauseKind : unsigned int {
  kConcurrent = 0,
  kUnknown = 1,
};

enum class OpenMPReductionClauseModifier : unsigned int {
  kDefault = 0,
  kInscan = 1,
  kTask = 2,
  kUnknown = 3,
};

enum class OpenMPScheduleClauseKind : unsigned int {
  kStatic = 0,
  kDynamic = 1,
  kGuided = 2,
  kAuto = 3,
  kRuntime = 4,
  kUnknown = 5,
};

enum class OpenMPScheduleClauseModifier : unsigned int {
  kUnknown = 5,
  kMonotonic = 6,
  kNonmonotonic = 7,
  kSimd = 8,
};

enum class OptionType : unsigned int {
  kVectorize = 0,
  kVectorizeWidth = 1,
  kInterleave = 2,
  kInterleaveCount = 3,
  kUnroll = 4,
  kUnrollCount = 5,
  kUnrollAndJam = 6,
  kUnrollAndJamCount = 7,
  kPipelineDisabled = 8,
  kPipelineInitiationInterval = 9,
  kDistribute = 10,
  kVectorizePredicate = 11,
};

enum class OverloadedOperatorKind : int {
  kNone = 0,
  kNew = 1,
  kDelete = 2,
  kArrayNew = 3,
  kArrayDelete = 4,
  kPlus = 5,
  kMinus = 6,
  kStar = 7,
  kSlash = 8,
  kPercent = 9,
  kCaret = 10,
  kAmp = 11,
  kPipe = 12,
  kTilde = 13,
  kExclaim = 14,
  kEqual = 15,
  kLess = 16,
  kGreater = 17,
  kPlusEqual = 18,
  kMinusEqual = 19,
  kStarEqual = 20,
  kSlashEqual = 21,
  kPercentEqual = 22,
  kCaretEqual = 23,
  kAmpEqual = 24,
  kPipeEqual = 25,
  kLessLess = 26,
  kGreaterGreater = 27,
  kLessLessEqual = 28,
  kGreaterGreaterEqual = 29,
  kEqualEqual = 30,
  kExclaimEqual = 31,
  kLessEqual = 32,
  kGreaterEqual = 33,
  kSpaceship = 34,
  kAmpAmp = 35,
  kPipePipe = 36,
  kPlusPlus = 37,
  kMinusMinus = 38,
  kComma = 39,
  kArrowStar = 40,
  kArrow = 41,
  kCall = 42,
  kSubscript = 43,
  kConditional = 44,
  kCoawait = 45,
};

enum class OverloadsShown : unsigned int {
  kAll = 0,
  kBest = 1,
};

enum class OwnershipKind : unsigned int {
  kHolds = 0,
  kReturns = 1,
  kTakes = 2,
};

enum class PCSType : unsigned int {
  kAAPCS = 0,
  kVFP = 1,
};

enum class PPKeywordKind : unsigned int {
  kNotKeyword = 0,
  kIf = 1,
  kIfdef = 2,
  kIfndef = 3,
  kElif = 4,
  kElifdef = 5,
  kElifndef = 6,
  kElse = 7,
  kEndif = 8,
  kDefined = 9,
  kInclude = 10,
  k__IncludeMacros = 11,
  kDefine = 12,
  kUndef = 13,
  kLine = 14,
  kError = 15,
  kPragma = 16,
  kImport = 17,
  kIncludeNext = 18,
  kWarning = 19,
  kIdentifier = 20,
  kSccs = 21,
  kAssert = 22,
  kUnassert = 23,
  k__PublicMacro = 24,
  k__PrivateMacro = 25,
};

enum class ParameterABI : int {
  kOrdinary = 0,
  kSwiftIndirectResult = 1,
  kSwiftErrorResult = 2,
  kSwiftContext = 3,
  kSwiftAsyncContext = 4,
};

enum class ParenLocsOffsets : int {
  kLParen = 0,
  kRParen = 1,
  kTotal = 2,
};

enum class PragmaFloatControlKind : unsigned int {
  kUnknown = 0,
  kPrecise = 1,
  kNoPrecise = 2,
  kExcept = 3,
  kNoExcept = 4,
  kPush = 5,
  kPop = 6,
};

enum class PragmaMSCommentKind : unsigned int {
  kUnknown = 0,
  kLinker = 1,
  kLib = 2,
  kCompiler = 3,
  kExeString = 4,
  kUser = 5,
};

enum class PragmaMSPointersToMembersKind : unsigned int {
  kBestCase = 0,
  kFullGeneralitySingleInheritance = 1,
  kFullGeneralityMultipleInheritance = 2,
  kFullGeneralityVirtualInheritance = 3,
};

enum class PragmaMSStructKind : unsigned int {
  kOFF = 0,
  kON = 1,
};

enum class PragmaSectionFlag : unsigned int {
  kNone = 0,
  kRead = 1,
  kWrite = 2,
  kExecute = 4,
  kImplicit = 8,
  kZeroInitializer = 16,
  kInvalid = 2147483648,
};

enum class PrimitiveCopyKind : unsigned int {
  kTrivial = 0,
  kVolatileTrivial = 1,
  kARCStrong = 2,
  kARCWeak = 3,
  kStruct = 4,
};

enum class PrimitiveDefaultInitializeKind : unsigned int {
  kTrivial = 0,
  kARCStrong = 1,
  kARCWeak = 2,
  kStruct = 3,
};

enum class ProfileInstrKind : unsigned int {
  kProfileNone = 0,
  kProfileClangInstr = 1,
  kProfileIRInstr = 2,
  kProfileCSIRInstr = 3,
};

enum class PropertyControl : unsigned int {
  kNone = 0,
  kRequired = 1,
  kOptional = 2,
};

enum class RangeExprOffset : int {
  kBegin = 0,
  kEnd = 1,
  kStep = 2,
  kTotal = 3,
};

enum class RangeLocOffset : int {
  kAssignToken = 0,
  kSecondColonToken = 2,
  kTotal = 3,
};

enum class ReceiverKind : unsigned int {
  kClass = 0,
  kInstance = 1,
  kSuperClass = 2,
  kSuperInstance = 3,
};

enum class RefQualifierKind : unsigned int {
  kNone = 0,
  kLValue = 1,
  kRValue = 2,
};

enum class RemarkKind : unsigned int {
  kMissing = 0,
  kEnabled = 1,
  kEnabledEverything = 2,
  kDisabled = 3,
  kDisabledEverything = 4,
  kWithPattern = 5,
};

enum class ReservedIdentifierStatus : int {
  kNotReserved = 0,
  kStartsWithUnderscoreAtGlobalScope = 1,
  kStartsWithDoubleUnderscore = 2,
  kStartsWithUnderscoreFollowedByCapitalLetter = 3,
  kContainsDoubleUnderscore = 4,
};

enum class ResultStorageKind : unsigned int {
  kNone = 0,
  kInt64 = 1,
  kAPValue = 2,
};

enum class SFINAEResponse : unsigned int {
  kSubstitutionFailure = 0,
  kSuppress = 1,
  kReport = 2,
  kAccessControl = 3,
};

enum class SYCLMajorVersion : unsigned int {
  kNone = 0,
  k2017 = 1,
  k2020 = 2,
  kDefault = 2,
};

enum class SanitizerOrdinal : unsigned long long {
  kAddress = 0,
  kPointerCompare = 1,
  kPointerSubtract = 2,
  kKernelAddress = 3,
  kHWAddress = 4,
  kKernelHWAddress = 5,
  kMemoryTag = 6,
  kMemory = 7,
  kKernelMemory = 8,
  kFuzzer = 9,
  kFuzzerNoLink = 10,
  kThread = 11,
  kLeak = 12,
  kAlignment = 13,
  kArrayBounds = 14,
  kBoolean = 15,
  kBuiltin = 16,
  kEnum = 17,
  kFloatCastOverflow = 18,
  kFloatDivideByZero = 19,
  kFunction = 20,
  kIntegerDivideByZero = 21,
  kNonnullAttribute = 22,
  kNull = 23,
  kNullabilityArgument = 24,
  kNullabilityAssign = 25,
  kNullabilityReturn = 26,
  kNullabilityGroup = 27,
  kObjectSize = 28,
  kPointerOverflow = 29,
  kReturn = 30,
  kReturnsNonnullAttribute = 31,
  kShiftBase = 32,
  kShiftExponent = 33,
  kShiftGroup = 34,
  kSignedIntegerOverflow = 35,
  kUnreachable = 36,
  kVLABound = 37,
  kVptr = 38,
  kUnsignedIntegerOverflow = 39,
  kUnsignedShiftBase = 40,
  kDataFlow = 41,
  kCFICastStrict = 42,
  kCFIDerivedCast = 43,
  kCFIICall = 44,
  kCFIMFCall = 45,
  kCFIUnrelatedCast = 46,
  kCFINVCall = 47,
  kCFIVCall = 48,
  kCFIGroup = 49,
  kSafeStack = 50,
  kShadowCallStack = 51,
  kUndefinedGroup = 52,
  kUndefinedTrapGroup = 53,
  kImplicitUnsignedIntegerTruncation = 54,
  kImplicitSignedIntegerTruncation = 55,
  kImplicitIntegerTruncationGroup = 56,
  kImplicitIntegerSignChange = 57,
  kImplicitIntegerArithmeticValueChangeGroup = 58,
  kObjCCast = 59,
  kImplicitConversionGroup = 60,
  kIntegerGroup = 61,
  kLocalBounds = 62,
  kBoundsGroup = 63,
  kScudo = 64,
  kAllGroup = 65,
  kCount = 66,
};

enum class ScalarTypeKind : unsigned int {
  kCPointer = 0,
  kBlockPointer = 1,
  kObjCObjectPointer = 2,
  kMemberPointer = 3,
  kBoolean = 4,
  kIntegral = 5,
  kFloating = 6,
  kIntegralComplex = 7,
  kFloatingComplex = 8,
  kFixedPoint = 9,
};

enum class SelectorLocationsKind : unsigned int {
  kNonStandard = 0,
  kStandardNoSpace = 1,
  kStandardWithSpace = 2,
};

enum class SetterKind : unsigned int {
  kAssign = 0,
  kRetain = 1,
  kCopy = 2,
  kWeak = 3,
};

enum class SideEffectsKind : unsigned int {
  kNoSideEffects = 0,
  kAllowUndefinedBehavior = 1,
  kAllowSideEffects = 2,
};

enum class SignReturnAddressKeyKind : int {
  kAKey = 0,
  kBKey = 1,
};

enum class SignReturnAddressScopeKind : int {
  kNone = 0,
  kNonLeaf = 1,
  kAll = 2,
};

enum class SignedOverflowBehaviorTy : unsigned int {
  kUndefined = 0,
  kDefined = 1,
  kTrapping = 2,
};

enum class SpecialMemberFlags : unsigned int {
  kDefaultConstructor = 1,
  kCopyConstructor = 2,
  kMoveConstructor = 4,
  kCopyAssignment = 8,
  kMoveAssignment = 16,
  kDestructor = 32,
  kAll = 63,
};

enum class SpecifierKind : unsigned int {
  kIdentifier = 0,
  kNamespace = 1,
  kNamespaceAlias = 2,
  kTypeSpec = 3,
  kTypeSpecWithTemplate = 4,
  kGlobal = 5,
  kSuper = 6,
};

enum class Spelling : unsigned int {
  kGNUAarch64VectorPcs = 0,
  kCXX11ClangAarch64VectorPcs = 1,
  kC2xClangAarch64VectorPcs = 2,
  kSpellingNotCalculated = 15,
};

enum class StackProtectorMode : unsigned int {
  kOff = 0,
  kOn = 1,
  kStrong = 2,
  kReq = 3,
};

enum class StmtKind : unsigned int {
  kGCCAsmStmt = 1,
  kMSAsmStmt = 2,
  kBreakStmt = 3,
  kCXXCatchStmt = 4,
  kCXXForRangeStmt = 5,
  kCXXTryStmt = 6,
  kCapturedStmt = 7,
  kCompoundStmt = 8,
  kContinueStmt = 9,
  kCoreturnStmt = 10,
  kCoroutineBodyStmt = 11,
  kDeclStmt = 12,
  kDoStmt = 13,
  kForStmt = 14,
  kGotoStmt = 15,
  kIfStmt = 16,
  kIndirectGotoStmt = 17,
  kMSDependentExistsStmt = 18,
  kNullStmt = 19,
  kOMPCanonicalLoop = 20,
  kOMPAtomicDirective = 21,
  kOMPBarrierDirective = 22,
  kOMPCancelDirective = 23,
  kOMPCancellationPointDirective = 24,
  kOMPCriticalDirective = 25,
  kOMPDepobjDirective = 26,
  kOMPDispatchDirective = 27,
  kOMPFlushDirective = 28,
  kOMPInteropDirective = 29,
  kOMPDistributeDirective = 30,
  kOMPDistributeParallelForDirective = 31,
  kOMPDistributeParallelForSimdDirective = 32,
  kOMPDistributeSimdDirective = 33,
  kOMPForDirective = 34,
  kOMPForSimdDirective = 35,
  kOMPMasterTaskLoopDirective = 36,
  kOMPMasterTaskLoopSimdDirective = 37,
  kOMPParallelForDirective = 38,
  kOMPParallelForSimdDirective = 39,
  kOMPParallelMasterTaskLoopDirective = 40,
  kOMPParallelMasterTaskLoopSimdDirective = 41,
  kOMPSimdDirective = 42,
  kOMPTargetParallelForSimdDirective = 43,
  kOMPTargetSimdDirective = 44,
  kOMPTargetTeamsDistributeDirective = 45,
  kOMPTargetTeamsDistributeParallelForDirective = 46,
  kOMPTargetTeamsDistributeParallelForSimdDirective = 47,
  kOMPTargetTeamsDistributeSimdDirective = 48,
  kOMPTaskLoopDirective = 49,
  kOMPTaskLoopSimdDirective = 50,
  kOMPTeamsDistributeDirective = 51,
  kOMPTeamsDistributeParallelForDirective = 52,
  kOMPTeamsDistributeParallelForSimdDirective = 53,
  kOMPTeamsDistributeSimdDirective = 54,
  kOMPTileDirective = 55,
  kOMPUnrollDirective = 56,
  kOMPMaskedDirective = 57,
  kOMPMasterDirective = 58,
  kOMPOrderedDirective = 59,
  kOMPParallelDirective = 60,
  kOMPParallelMasterDirective = 61,
  kOMPParallelSectionsDirective = 62,
  kOMPScanDirective = 63,
  kOMPSectionDirective = 64,
  kOMPSectionsDirective = 65,
  kOMPSingleDirective = 66,
  kOMPTargetDataDirective = 67,
  kOMPTargetDirective = 68,
  kOMPTargetEnterDataDirective = 69,
  kOMPTargetExitDataDirective = 70,
  kOMPTargetParallelDirective = 71,
  kOMPTargetParallelForDirective = 72,
  kOMPTargetTeamsDirective = 73,
  kOMPTargetUpdateDirective = 74,
  kOMPTaskDirective = 75,
  kOMPTaskgroupDirective = 76,
  kOMPTaskwaitDirective = 77,
  kOMPTaskyieldDirective = 78,
  kOMPTeamsDirective = 79,
  kObjCAtCatchStmt = 80,
  kObjCAtFinallyStmt = 81,
  kObjCAtSynchronizedStmt = 82,
  kObjCAtThrowStmt = 83,
  kObjCAtTryStmt = 84,
  kObjCAutoreleasePoolStmt = 85,
  kObjCForCollectionStmt = 86,
  kReturnStmt = 87,
  kSEHExceptStmt = 88,
  kSEHFinallyStmt = 89,
  kSEHLeaveStmt = 90,
  kSEHTryStmt = 91,
  kCaseStmt = 92,
  kDefaultStmt = 93,
  kSwitchStmt = 94,
  kAttributedStmt = 95,
  kBinaryConditionalOperator = 96,
  kConditionalOperator = 97,
  kAddrLabelExpr = 98,
  kArrayInitIndexExpr = 99,
  kArrayInitLoopExpr = 100,
  kArraySubscriptExpr = 101,
  kArrayTypeTraitExpr = 102,
  kAsTypeExpr = 103,
  kAtomicExpr = 104,
  kBinaryOperator = 105,
  kCompoundAssignOperator = 106,
  kBlockExpr = 107,
  kCXXBindTemporaryExpr = 108,
  kCXXBoolLiteralExpr = 109,
  kCXXConstructExpr = 110,
  kCXXTemporaryObjectExpr = 111,
  kCXXDefaultArgExpr = 112,
  kCXXDefaultInitExpr = 113,
  kCXXDeleteExpr = 114,
  kCXXDependentScopeMemberExpr = 115,
  kCXXFoldExpr = 116,
  kCXXInheritedCtorInitExpr = 117,
  kCXXNewExpr = 118,
  kCXXNoexceptExpr = 119,
  kCXXNullPtrLiteralExpr = 120,
  kCXXPseudoDestructorExpr = 121,
  kCXXRewrittenBinaryOperator = 122,
  kCXXScalarValueInitExpr = 123,
  kCXXStdInitializerListExpr = 124,
  kCXXThisExpr = 125,
  kCXXThrowExpr = 126,
  kCXXTypeidExpr = 127,
  kCXXUnresolvedConstructExpr = 128,
  kCXXUuidofExpr = 129,
  kCallExpr = 130,
  kCUDAKernelCallExpr = 131,
  kCXXMemberCallExpr = 132,
  kCXXOperatorCallExpr = 133,
  kUserDefinedLiteral = 134,
  kBuiltinBitCastExpr = 135,
  kCStyleCastExpr = 136,
  kCXXFunctionalCastExpr = 137,
  kCXXAddrspaceCastExpr = 138,
  kCXXConstCastExpr = 139,
  kCXXDynamicCastExpr = 140,
  kCXXReinterpretCastExpr = 141,
  kCXXStaticCastExpr = 142,
  kObjCBridgedCastExpr = 143,
  kImplicitCastExpr = 144,
  kCharacterLiteral = 145,
  kChooseExpr = 146,
  kCompoundLiteralExpr = 147,
  kConceptSpecializationExpr = 148,
  kConvertVectorExpr = 149,
  kCoawaitExpr = 150,
  kCoyieldExpr = 151,
  kDeclRefExpr = 152,
  kDependentCoawaitExpr = 153,
  kDependentScopeDeclRefExpr = 154,
  kDesignatedInitExpr = 155,
  kDesignatedInitUpdateExpr = 156,
  kExpressionTraitExpr = 157,
  kExtVectorElementExpr = 158,
  kFixedPointLiteral = 159,
  kFloatingLiteral = 160,
  kConstantExpr = 161,
  kExprWithCleanups = 162,
  kFunctionParmPackExpr = 163,
  kGNUNullExpr = 164,
  kGenericSelectionExpr = 165,
  kImaginaryLiteral = 166,
  kImplicitValueInitExpr = 167,
  kInitListExpr = 168,
  kIntegerLiteral = 169,
  kLambdaExpr = 170,
  kMSPropertyRefExpr = 171,
  kMSPropertySubscriptExpr = 172,
  kMaterializeTemporaryExpr = 173,
  kMatrixSubscriptExpr = 174,
  kMemberExpr = 175,
  kNoInitExpr = 176,
  kOMPArraySectionExpr = 177,
  kOMPArrayShapingExpr = 178,
  kOMPIteratorExpr = 179,
  kObjCArrayLiteral = 180,
  kObjCAvailabilityCheckExpr = 181,
  kObjCBoolLiteralExpr = 182,
  kObjCBoxedExpr = 183,
  kObjCDictionaryLiteral = 184,
  kObjCEncodeExpr = 185,
  kObjCIndirectCopyRestoreExpr = 186,
  kObjCIsaExpr = 187,
  kObjCIvarRefExpr = 188,
  kObjCMessageExpr = 189,
  kObjCPropertyRefExpr = 190,
  kObjCProtocolExpr = 191,
  kObjCSelectorExpr = 192,
  kObjCStringLiteral = 193,
  kObjCSubscriptRefExpr = 194,
  kOffsetOfExpr = 195,
  kOpaqueValueExpr = 196,
  kUnresolvedLookupExpr = 197,
  kUnresolvedMemberExpr = 198,
  kPackExpansionExpr = 199,
  kParenExpr = 200,
  kParenListExpr = 201,
  kPredefinedExpr = 202,
  kPseudoObjectExpr = 203,
  kRecoveryExpr = 204,
  kRequiresExpr = 205,
  kSYCLUniqueStableNameExpr = 206,
  kShuffleVectorExpr = 207,
  kSizeOfPackExpr = 208,
  kSourceLocExpr = 209,
  kStmtExpr = 210,
  kStringLiteral = 211,
  kSubstNonTypeTemplateParmExpr = 212,
  kSubstNonTypeTemplateParmPackExpr = 213,
  kTypeTraitExpr = 214,
  kTypoExpr = 215,
  kUnaryExprOrTypeTraitExpr = 216,
  kUnaryOperator = 217,
  kVAArgExpr = 218,
  kLabelStmt = 219,
  kWhileStmt = 220,
};

enum class StorageClass : unsigned int {
  kNone = 0,
  kExtern = 1,
  kStatic = 2,
  kPrivateExtern = 3,
  kAuto = 4,
  kRegister = 5,
};

enum class StorageDuration : unsigned int {
  kFullExpression = 0,
  kAutomatic = 1,
  kThread = 2,
  kStatic = 3,
  kDynamic = 4,
};

enum class StoredNameKind : unsigned int {
  kStoredIdentifier = 0,
  kStoredObjCZeroArgumentSelector = 1,
  kStoredObjCOneArgumentSelector = 2,
  kStoredCXXConstructorName = 3,
  kStoredCXXDestructorName = 4,
  kStoredCXXConversionFunctionName = 5,
  kStoredCXXOperatorName = 6,
  kStoredDeclarationNameExtra = 7,
  kPointerMask = 7,
  kUncommonNameKindOffset = 8,
};

enum class StoredSpecifierKind : unsigned int {
  kStoredIdentifier = 0,
  kStoredDeclaration = 1,
  kStoredTypeSpec = 2,
  kStoredTypeSpecWithTemplate = 3,
};

enum class StringKind : unsigned int {
  kAscii = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class StructReturnConventionKind : unsigned int {
  kDefault = 0,
  kOnStack = 1,
  kInRegs = 2,
};

enum class SubExpr : unsigned int {
  kCallee = 0,
  kLHS = 1,
  kRHS = 2,
  kCount = 3,
};

enum class SubStmt : unsigned int {
  kBody = 0,
  kPromise = 1,
  kInitializerSuspend = 2,
  kFinalSuspend = 3,
  kOnException = 4,
  kOnFallthrough = 5,
  kAllocate = 6,
  kDeallocate = 7,
  kReturnValue = 8,
  kResultDeclaration = 9,
  kReturnStatement = 10,
  kReturnStatementOnAllocFailure = 11,
};

enum class SyncScope : int {
  kOpenCLWorkGroup = 0,
  kOpenCLDevice = 1,
  kOpenCLAllSVMDevices = 2,
  kOpenCLSubGroup = 3,
};

enum class Syntax : unsigned int {
  kGNU = 0,
  kCXX11 = 1,
  kC2x = 2,
  kDeclspec = 3,
  kMicrosoft = 4,
  kKeyword = 5,
  kPragma = 6,
  kContextSensitiveKeyword = 7,
};

enum class TLSKind : unsigned int {
  kNone = 0,
  kStatic = 1,
  kDynamic = 2,
};

enum class TLSModel : unsigned int {
  kGeneralDynamicTLSModel = 0,
  kLocalDynamicTLSModel = 1,
  kInitialExecTLSModel = 2,
  kLocalExecTLSModel = 3,
};

enum class TQ : unsigned int {
  kConst = 1,
  kRestrict = 2,
  kVolatile = 4,
  kCVRMask = 7,
};

enum class TagTypeKind : unsigned int {
  kStruct = 0,
  kInterface = 1,
  kUnion = 2,
  kClass = 3,
  kEnum = 4,
};

enum class TailPaddingUseRules : unsigned int {
  kAlwaysUseTailPadding = 0,
  kUseTailPaddingUnlessPOD03 = 1,
  kUseTailPaddingUnlessPOD11 = 2,
};

enum class TemplateArgumentDependence : unsigned char {
  kUnexpandedPack = 1,
  kInstantiation = 2,
  kDependent = 4,
  kError = 8,
  kNone = 0,
  kDependentInstantiation = 6,
  kAll = 15,
};

enum class TemplateNameDependence : unsigned char {
  kUnexpandedPack = 1,
  kInstantiation = 2,
  kDependent = 4,
  kError = 8,
  kNone = 0,
  kDependentInstantiation = 6,
  kAll = 15,
};

enum class TemplateSpecializationKind : unsigned int {
  kUndeclared = 0,
  kImplicitInstantiation = 1,
  kExplicitSpecialization = 2,
  kExplicitInstantiationDeclaration = 3,
  kExplicitInstantiationDefinition = 4,
};

enum class TemplatedKind : unsigned int {
  kNonTemplate = 0,
  kFunctionTemplate = 1,
  kMemberSpecialization = 2,
  kFunctionTemplateSpecialization = 3,
  kDependentFunctionTemplateSpecialization = 4,
};

enum class TextDiagnosticFormat : unsigned int {
  kClang = 0,
  kMSVC = 1,
  kVi = 2,
};

enum class ThreadModelKind : int {
  kPOSIX = 0,
  kSingle = 1,
};

enum class ThreadStorageClassSpecifier : unsigned int {
  kUnspecified = 0,
  k__Thread = 1,
  kThreadLocal = 2,
  k_ThreadLocal = 3,
};

enum class TokenKind : unsigned short {
  kUnknown = 0,
  kEndOfFile = 1,
  kEndOfDirective = 2,
  kCodeCompletion = 3,
  kComment = 4,
  kIdentifier = 5,
  kRawIdentifier = 6,
  kNumericConstant = 7,
  kCharacterConstant = 8,
  kWideCharacterConstant = 9,
  kUtf8CharacterConstant = 10,
  kUtf16CharacterConstant = 11,
  kUtf32CharacterConstant = 12,
  kStringLiteral = 13,
  kWideStringLiteral = 14,
  kHeaderName = 15,
  kUtf8StringLiteral = 16,
  kUtf16StringLiteral = 17,
  kUtf32StringLiteral = 18,
  kLSquare = 19,
  kRSquare = 20,
  kLParenthesis = 21,
  kRParenthesis = 22,
  kLBrace = 23,
  kRBrace = 24,
  kPeriod = 25,
  kEllipsis = 26,
  kAmp = 27,
  kAmpAmp = 28,
  kAmpEqual = 29,
  kStar = 30,
  kStarEqual = 31,
  kPlus = 32,
  kPlusPlus = 33,
  kPlusEqual = 34,
  kMinus = 35,
  kArrow = 36,
  kMinusMinus = 37,
  kMinusEqual = 38,
  kTilde = 39,
  kExclaim = 40,
  kExclaimEqual = 41,
  kSlash = 42,
  kSlashEqual = 43,
  kPercent = 44,
  kPercentEqual = 45,
  kLess = 46,
  kLessLess = 47,
  kLessEqual = 48,
  kLessLessEqual = 49,
  kSpaceship = 50,
  kGreater = 51,
  kGreaterGreater = 52,
  kGreaterEqual = 53,
  kGreaterGreaterEqual = 54,
  kCaret = 55,
  kCaretEqual = 56,
  kPipe = 57,
  kPipePipe = 58,
  kPipeEqual = 59,
  kQuestion = 60,
  kColon = 61,
  kSemi = 62,
  kEqual = 63,
  kEqualEqual = 64,
  kComma = 65,
  kHash = 66,
  kHashHash = 67,
  kHashat = 68,
  kPeriodStar = 69,
  kArrowStar = 70,
  kColonColon = 71,
  kAt = 72,
  kLessLessLess = 73,
  kGreaterGreaterGreater = 74,
  kCaretcaret = 75,
  kKeywordAuto = 76,
  kKeywordBreak = 77,
  kKeywordCase = 78,
  kKeywordCharacter = 79,
  kKeywordConst = 80,
  kKeywordContinue = 81,
  kKeywordDefault = 82,
  kKeywordDo = 83,
  kKeywordDouble = 84,
  kKeywordElse = 85,
  kKeywordEnum = 86,
  kKeywordExtern = 87,
  kKeywordFloat = 88,
  kKeywordFor = 89,
  kKeywordGoto = 90,
  kKeywordIf = 91,
  kKeywordInline = 92,
  kKeywordInt = 93,
  kKeyword_ExtInt = 94,
  kKeywordLong = 95,
  kKeywordRegister = 96,
  kKeywordRestrict = 97,
  kKeywordReturn = 98,
  kKeywordShort = 99,
  kKeywordSigned = 100,
  kKeywordSizeof = 101,
  kKeywordStatic = 102,
  kKeywordStruct = 103,
  kKeywordSwitch = 104,
  kKeywordTypedef = 105,
  kKeywordUnion = 106,
  kKeywordUnsigned = 107,
  kKeywordVoid = 108,
  kKeywordVolatile = 109,
  kKeywordWhile = 110,
  kKeyword_Alignas = 111,
  kKeyword_Alignof = 112,
  kKeyword_Atomic = 113,
  kKeyword_Boolean = 114,
  kKeyword_Complex = 115,
  kKeyword_Generic = 116,
  kKeyword_Imaginary = 117,
  kKeyword_Noreturn = 118,
  kKeyword_StaticAssert = 119,
  kKeyword_ThreadLocal = 120,
  kKeyword__Func__ = 121,
  kKeyword__ObjcYes = 122,
  kKeyword__ObjcNo = 123,
  kKeywordAssembly = 124,
  kKeywordBoolean = 125,
  kKeywordCatch = 126,
  kKeywordClass = 127,
  kKeywordConstCast = 128,
  kKeywordDelete = 129,
  kKeywordDynamicCast = 130,
  kKeywordExplicit = 131,
  kKeywordExport = 132,
  kKeywordFalse = 133,
  kKeywordFriend = 134,
  kKeywordMutable = 135,
  kKeywordNamespace = 136,
  kKeywordNew = 137,
  kKeywordOperator = 138,
  kKeywordPrivate = 139,
  kKeywordProtected = 140,
  kKeywordPublic = 141,
  kKeywordReinterpretCast = 142,
  kKeywordStaticCast = 143,
  kKeywordTemplate = 144,
  kKeywordThis = 145,
  kKeywordThrow = 146,
  kKeywordTrue = 147,
  kKeywordTry = 148,
  kKeywordTypename = 149,
  kKeywordTypeid = 150,
  kKeywordUsing = 151,
  kKeywordVirtual = 152,
  kKeywordWcharT = 153,
  kKeywordAlignas = 154,
  kKeywordAlignof = 155,
  kKeywordChar16T = 156,
  kKeywordChar32T = 157,
  kKeywordConstexpr = 158,
  kKeywordDecltype = 159,
  kKeywordNoexcept = 160,
  kKeywordNullptr = 161,
  kKeywordStaticAssert = 162,
  kKeywordThreadLocal = 163,
  kKeywordConcept = 164,
  kKeywordRequires = 165,
  kKeywordCoAwait = 166,
  kKeywordCoReturn = 167,
  kKeywordCoYield = 168,
  kKeywordModule = 169,
  kKeywordImport = 170,
  kKeywordConsteval = 171,
  kKeywordConstinit = 172,
  kKeywordChar8T = 173,
  kKeyword_Float16 = 174,
  kKeyword_Accum = 175,
  kKeyword_Fract = 176,
  kKeyword_Sat = 177,
  kKeyword_Decimal32 = 178,
  kKeyword_Decimal64 = 179,
  kKeyword_Decimal128 = 180,
  kKeyword__Null = 181,
  kKeyword__Alignof = 182,
  kKeyword__Attribute = 183,
  kKeyword__BuiltinChooseExpression = 184,
  kKeyword__BuiltinOffsetof = 185,
  kKeyword__BuiltinFILE = 186,
  kKeyword__BuiltinFUNCTION = 187,
  kKeyword__BuiltinLINE = 188,
  kKeyword__BuiltinCOLUMN = 189,
  kKeyword__BuiltinTypesCompatibleP = 190,
  kKeyword__BuiltinVaArgument = 191,
  kKeyword__Extension__ = 192,
  kKeyword__Float128 = 193,
  kKeyword__Imag = 194,
  kKeyword__Int128 = 195,
  kKeyword__Label__ = 196,
  kKeyword__Real = 197,
  kKeyword__Thread = 198,
  kKeyword__FUNCTION__ = 199,
  kKeyword__PRETTYFUNCTION__ = 200,
  kKeyword__AutoType = 201,
  kKeywordTypeof = 202,
  kKeyword__FUNCDNAME__ = 203,
  kKeyword__FUNCSIG__ = 204,
  kKeywordLFUNCTION__ = 205,
  kKeywordLFUNCSIG__ = 206,
  kKeyword__IsInterfaceClass = 207,
  kKeyword__IsSealed = 208,
  kKeyword__IsDestructible = 209,
  kKeyword__IsTriviallyDestructible = 210,
  kKeyword__IsNothrowDestructible = 211,
  kKeyword__IsNothrowAssignable = 212,
  kKeyword__IsConstructible = 213,
  kKeyword__IsNothrowConstructible = 214,
  kKeyword__IsAssignable = 215,
  kKeyword__HasNothrowMoveAssign = 216,
  kKeyword__HasTrivialMoveAssign = 217,
  kKeyword__HasTrivialMoveConstructor = 218,
  kKeyword__HasNothrowAssign = 219,
  kKeyword__HasNothrowCopy = 220,
  kKeyword__HasNothrowConstructor = 221,
  kKeyword__HasTrivialAssign = 222,
  kKeyword__HasTrivialCopy = 223,
  kKeyword__HasTrivialConstructor = 224,
  kKeyword__HasTrivialDestructor = 225,
  kKeyword__HasVirtualDestructor = 226,
  kKeyword__IsAbstract = 227,
  kKeyword__IsAggregate = 228,
  kKeyword__IsBaseOf = 229,
  kKeyword__IsClass = 230,
  kKeyword__IsConvertibleTo = 231,
  kKeyword__IsEmpty = 232,
  kKeyword__IsEnum = 233,
  kKeyword__IsFinal = 234,
  kKeyword__IsLiteral = 235,
  kKeyword__IsPod = 236,
  kKeyword__IsPolymorphic = 237,
  kKeyword__IsStandardLayout = 238,
  kKeyword__IsTrivial = 239,
  kKeyword__IsTriviallyAssignable = 240,
  kKeyword__IsTriviallyConstructible = 241,
  kKeyword__IsTriviallyCopyable = 242,
  kKeyword__IsUnion = 243,
  kKeyword__HasUniqueObjectRepresentations = 244,
  kKeyword__UnderlyingType = 245,
  kKeyword__ReferenceBindsToTemporary = 246,
  kKeyword__IsLvalueExpression = 247,
  kKeyword__IsRvalueExpression = 248,
  kKeyword__IsArithmetic = 249,
  kKeyword__IsFloatingPoint = 250,
  kKeyword__IsIntegral = 251,
  kKeyword__IsCompleteType = 252,
  kKeyword__IsVoid = 253,
  kKeyword__IsArray = 254,
  kKeyword__IsFunction = 255,
  kKeyword__IsReference = 256,
  kKeyword__IsLvalueReference = 257,
  kKeyword__IsRvalueReference = 258,
  kKeyword__IsFundamental = 259,
  kKeyword__IsObject = 260,
  kKeyword__IsScalar = 261,
  kKeyword__IsCompound = 262,
  kKeyword__IsPointer = 263,
  kKeyword__IsMemberObjectPointer = 264,
  kKeyword__IsMemberFunctionPointer = 265,
  kKeyword__IsMemberPointer = 266,
  kKeyword__IsConst = 267,
  kKeyword__IsVolatile = 268,
  kKeyword__IsSigned = 269,
  kKeyword__IsUnsigned = 270,
  kKeyword__IsSame = 271,
  kKeyword__IsConvertible = 272,
  kKeyword__ArrayRank = 273,
  kKeyword__ArrayExtent = 274,
  kKeyword__PrivateExtern__ = 275,
  kKeyword__ModulePrivate__ = 276,
  kKeyword__Declspec = 277,
  kKeyword__Cdecl = 278,
  kKeyword__Stdcall = 279,
  kKeyword__Fastcall = 280,
  kKeyword__Thiscall = 281,
  kKeyword__Regcall = 282,
  kKeyword__Vectorcall = 283,
  kKeyword__Forceinline = 284,
  kKeyword__Unaligned = 285,
  kKeyword__Super = 286,
  kKeyword__Global = 287,
  kKeyword__Local = 288,
  kKeyword__Constant = 289,
  kKeyword__Private = 290,
  kKeyword__Generic = 291,
  kKeyword__Kernel = 292,
  kKeyword__ReadOnly = 293,
  kKeyword__WriteOnly = 294,
  kKeyword__ReadWrite = 295,
  kKeyword__BuiltinAstype = 296,
  kKeywordVecStep = 297,
  kKeywordImage1dT = 298,
  kKeywordImage1dArrayT = 299,
  kKeywordImage1dBufferT = 300,
  kKeywordImage2dT = 301,
  kKeywordImage2dArrayT = 302,
  kKeywordImage2dDepthT = 303,
  kKeywordImage2dArrayDepthT = 304,
  kKeywordImage2dMsaaT = 305,
  kKeywordImage2dArrayMsaaT = 306,
  kKeywordImage2dMsaaDepthT = 307,
  kKeywordImage2dArrayMsaaDepthT = 308,
  kKeywordImage3dT = 309,
  kKeywordPipe = 310,
  kKeywordAddrspaceCast = 311,
  kKeyword__BuiltinOmpRequiredSimdAlign = 312,
  kKeyword__Pascal = 313,
  kKeyword__Vector = 314,
  kKeyword__Pixel = 315,
  kKeyword__Boolean = 316,
  kKeyword__Bf16 = 317,
  kKeywordHalf = 318,
  kKeyword__Bridge = 319,
  kKeyword__BridgeTransfer = 320,
  kKeyword__BridgeRetained = 321,
  kKeyword__BridgeRetain = 322,
  kKeyword__Covariant = 323,
  kKeyword__Contravariant = 324,
  kKeyword__Kindof = 325,
  kKeyword_Nonnull = 326,
  kKeyword_Nullable = 327,
  kKeyword_NullableResult = 328,
  kKeyword_NullUnspecified = 329,
  kKeyword__Ptr64 = 330,
  kKeyword__Ptr32 = 331,
  kKeyword__Sptr = 332,
  kKeyword__Uptr = 333,
  kKeyword__W64 = 334,
  kKeyword__Uuidof = 335,
  kKeyword__Try = 336,
  kKeyword__Finally = 337,
  kKeyword__Leave = 338,
  kKeyword__Int64 = 339,
  kKeyword__IfExists = 340,
  kKeyword__IfNotExists = 341,
  kKeyword__SingleInheritance = 342,
  kKeyword__MultipleInheritance = 343,
  kKeyword__VirtualInheritance = 344,
  kKeyword__Interface = 345,
  kKeyword__BuiltinConvertvector = 346,
  kKeyword__BuiltinBitCast = 347,
  kKeyword__BuiltinAvailable = 348,
  kKeyword__BuiltinSyclUniqueStableName = 349,
  kKeyword__UnknownAnytype = 350,
  kAnnotCxxscope = 351,
  kAnnotTypename = 352,
  kAnnotTemplateId = 353,
  kAnnotNonType = 354,
  kAnnotNonTypeUndeclared = 355,
  kAnnotNonTypeDependent = 356,
  kAnnotOverload = 357,
  kAnnotPrimaryExpression = 358,
  kAnnotDecltype = 359,
  kAnnotPragmaUnused = 360,
  kAnnotPragmaVis = 361,
  kAnnotPragmaPack = 362,
  kAnnotPragmaParserCrash = 363,
  kAnnotPragmaCaptured = 364,
  kAnnotPragmaDump = 365,
  kAnnotPragmaMsstruct = 366,
  kAnnotPragmaAlign = 367,
  kAnnotPragmaWeak = 368,
  kAnnotPragmaWeakalias = 369,
  kAnnotPragmaRedefineExtname = 370,
  kAnnotPragmaFpContract = 371,
  kAnnotPragmaFenvAccess = 372,
  kAnnotPragmaFenvRound = 373,
  kAnnotPragmaFloatControl = 374,
  kAnnotPragmaMsPointersToMembers = 375,
  kAnnotPragmaMsVtordisp = 376,
  kAnnotPragmaMsPragma = 377,
  kAnnotPragmaOpenclExtension = 378,
  kAnnotAttributeOpenmp = 379,
  kAnnotPragmaOpenmp = 380,
  kAnnotPragmaOpenmpEnd = 381,
  kAnnotPragmaLoopHint = 382,
  kAnnotPragmaFp = 383,
  kAnnotPragmaAttribute = 384,
  kAnnotModuleInclude = 385,
  kAnnotModuleBegin = 386,
  kAnnotModuleEnd = 387,
  kAnnotHeaderUnit = 388,
};

enum class TrailingAllocKind : unsigned int {
  kTAKInheritsConstructor = 1,
  kTAKHasTailExplicit = 2,
};

enum class TranslationUnitKind : unsigned int {
  kComplete = 0,
  kPrefix = 1,
  kModule = 2,
  kIncremental = 3,
};

enum class TrivialAutoVarInitKind : int {
  kUninitialized = 0,
  kZero = 1,
  kPattern = 2,
};

enum class TypeKind : unsigned int {
  kAdjusted = 0,
  kDecayed = 1,
  kConstantArray = 2,
  kDependentSizedArray = 3,
  kIncompleteArray = 4,
  kVariableArray = 5,
  kAtomic = 6,
  kAttributed = 7,
  kBlockPointer = 8,
  kBuiltin = 9,
  kComplex = 10,
  kDecltype = 11,
  kAuto = 12,
  kDeducedTemplateSpecialization = 13,
  kDependentAddressSpace = 14,
  kDependentExtInt = 15,
  kDependentName = 16,
  kDependentSizedExtVector = 17,
  kDependentTemplateSpecialization = 18,
  kDependentVector = 19,
  kElaborated = 20,
  kExtInt = 21,
  kFunctionNoProto = 22,
  kFunctionProto = 23,
  kInjectedClassName = 24,
  kMacroQualified = 25,
  kConstantMatrix = 26,
  kDependentSizedMatrix = 27,
  kMemberPointer = 28,
  kObjCObjectPointer = 29,
  kObjCObject = 30,
  kObjCInterface = 31,
  kObjCTypeParam = 32,
  kPackExpansion = 33,
  kParen = 34,
  kPipe = 35,
  kPointer = 36,
  kLValueReference = 37,
  kRValueReference = 38,
  kSubstTemplateTypeParmPack = 39,
  kSubstTemplateTypeParm = 40,
  kEnum = 41,
  kRecord = 42,
  kTemplateSpecialization = 43,
  kTemplateTypeParm = 44,
  kTypeOfExpr = 45,
  kTypeOf = 46,
  kTypedef = 47,
  kUnaryTransform = 48,
  kUnresolvedUsing = 49,
  kVector = 50,
  kExtVector = 51,
};

enum class TypeDependence : unsigned char {
  kUnexpandedPack = 1,
  kInstantiation = 2,
  kDependent = 4,
  kVariablyModified = 8,
  kError = 16,
  kNone = 0,
  kAll = 31,
  kDependentInstantiation = 6,
};

enum class TypeLocClass : unsigned int {
  kAdjusted = 0,
  kDecayed = 1,
  kConstantArray = 2,
  kDependentSizedArray = 3,
  kIncompleteArray = 4,
  kVariableArray = 5,
  kAtomic = 6,
  kAttributed = 7,
  kBlockPointer = 8,
  kBuiltin = 9,
  kComplex = 10,
  kDecltype = 11,
  kAuto = 12,
  kDeducedTemplateSpecialization = 13,
  kDependentAddressSpace = 14,
  kDependentExtInt = 15,
  kDependentName = 16,
  kDependentSizedExtVector = 17,
  kDependentTemplateSpecialization = 18,
  kDependentVector = 19,
  kElaborated = 20,
  kExtInt = 21,
  kFunctionNoProto = 22,
  kFunctionProto = 23,
  kInjectedClassName = 24,
  kMacroQualified = 25,
  kConstantMatrix = 26,
  kDependentSizedMatrix = 27,
  kMemberPointer = 28,
  kObjCObjectPointer = 29,
  kObjCObject = 30,
  kObjCInterface = 31,
  kObjCTypeParam = 32,
  kPackExpansion = 33,
  kParenthesis = 34,
  kPipe = 35,
  kPointer = 36,
  kLValueReference = 37,
  kRValueReference = 38,
  kSubstTemplateTypeParmPack = 39,
  kSubstTemplateTypeParm = 40,
  kEnum = 41,
  kRecord = 42,
  kTemplateSpecialization = 43,
  kTemplateTypeParm = 44,
  kTypeOfExpression = 45,
  kTypeOf = 46,
  kTypedef = 47,
  kUnaryTransform = 48,
  kUnresolvedUsing = 49,
  kVector = 50,
  kExtVector = 51,
  kQualified = 52,
};

enum class TypeSpecifierSign : int {
  kUnspecified = 0,
  kSigned = 1,
  kUnsigned = 2,
};

enum class TypeSpecifierType : unsigned int {
  kUnspecified = 0,
  kVoid = 1,
  kCharacter = 2,
  kWchar = 3,
  kChar8 = 4,
  kChar16 = 5,
  kChar32 = 6,
  kInt = 7,
  kInt128 = 8,
  kExtint = 9,
  kHalf = 10,
  kFloat16 = 11,
  kAccum = 12,
  kFract = 13,
  kBFloat16 = 14,
  kFloat = 15,
  kDouble = 16,
  kFloat128 = 17,
  kBoolean = 18,
  kDecimal32 = 19,
  kDecimal64 = 20,
  kDecimal128 = 21,
  kEnum = 22,
  kUnion = 23,
  kStruct = 24,
  kClass = 25,
  kInterface = 26,
  kTypename = 27,
  kTypeofType = 28,
  kTypeofExpression = 29,
  kDecltype = 30,
  kUnderlyingType = 31,
  kAuto = 32,
  kDecltypeAuto = 33,
  kAutoType = 34,
  kUnknownAnytype = 35,
  kAtomic = 36,
  kImage1dT = 37,
  kImage1dArrayT = 38,
  kImage1dBufferT = 39,
  kImage2dT = 40,
  kImage2dArrayT = 41,
  kImage2dDepthT = 42,
  kImage2dArrayDepthT = 43,
  kImage2dMsaaT = 44,
  kImage2dArrayMsaaT = 45,
  kImage2dMsaaDepthT = 46,
  kImage2dArrayMsaaDepthT = 47,
  kImage3dT = 48,
  kError = 49,
};

enum class TypeSpecifierWidth : int {
  kUnspecified = 0,
  kShort = 1,
  kLong = 2,
  kLongLong = 3,
};

enum class TypeSpecifiersPipe : int {
  kUnspecified = 0,
  kPipe = 1,
};

enum class TypeTrait : unsigned int {
  kIsInterfaceClass = 0,
  kIsSealed = 1,
  kIsDestructible = 2,
  kIsTriviallyDestructible = 3,
  kIsNothrowDestructible = 4,
  kHasNothrowMoveAssign = 5,
  kHasTrivialMoveAssign = 6,
  kHasTrivialMoveConstructor = 7,
  kHasNothrowAssign = 8,
  kHasNothrowCopy = 9,
  kHasNothrowConstructor = 10,
  kHasTrivialAssign = 11,
  kHasTrivialCopy = 12,
  kHasTrivialDefaultConstructor = 13,
  kHasTrivialDestructor = 14,
  kHasVirtualDestructor = 15,
  kIsAbstract = 16,
  kIsAggregate = 17,
  kIsClass = 18,
  kIsEmpty = 19,
  kIsEnum = 20,
  kIsFinal = 21,
  kIsLiteral = 22,
  kIsPOD = 23,
  kIsPolymorphic = 24,
  kIsStandardLayout = 25,
  kIsTrivial = 26,
  kIsTriviallyCopyable = 27,
  kIsUnion = 28,
  kHasUniqueObjectRepresentations = 29,
  kIsArithmetic = 30,
  kIsFloatingPoint = 31,
  kIsIntegral = 32,
  kIsCompleteType = 33,
  kIsVoid = 34,
  kIsArray = 35,
  kIsFunction = 36,
  kIsReference = 37,
  kIsLvalueReference = 38,
  kIsRvalueReference = 39,
  kIsFundamental = 40,
  kIsObject = 41,
  kIsScalar = 42,
  kIsCompound = 43,
  kIsPointer = 44,
  kIsMemberObjectPointer = 45,
  kIsMemberFunctionPointer = 46,
  kIsMemberPointer = 47,
  kIsConst = 48,
  kIsVolatile = 49,
  kIsSigned = 50,
  kIsUnsigned = 51,
  kTypeCompatible = 52,
  kIsNothrowAssignable = 53,
  kIsAssignable = 54,
  kIsBaseOf = 55,
  kIsConvertibleTo = 56,
  kIsTriviallyAssignable = 57,
  kReferenceBindsToTemporary = 58,
  kIsSame = 59,
  kIsConvertible = 60,
  kIsConstructible = 61,
  kIsNothrowConstructible = 62,
  kIsTriviallyConstructible = 63,
};

enum class UTTKind : unsigned int {
  kEnumUnderlyingType = 0,
};

enum class UnaryExprOrTypeTrait : unsigned int {
  kSizeOf = 0,
  kAlignOf = 1,
  kPreferredAlignOf = 2,
  kVecStep = 3,
  kOpenMPRequiredSimdAlign = 4,
};

enum class UnaryOperatorKind : unsigned int {
  kPostIncrement = 0,
  kPostDec = 1,
  kPreIncrement = 2,
  kPreDec = 3,
  kAddrOf = 4,
  kDeref = 5,
  kPlus = 6,
  kMinus = 7,
  kNot = 8,
  kLNot = 9,
  kReal = 10,
  kImag = 11,
  kExtension = 12,
  kCoawait = 13,
};

enum class APValueKind : unsigned int {
  kNone = 0,
  kIndeterminate = 1,
  kInt = 2,
  kFloat = 3,
  kFixedPoint = 4,
  kComplexInt = 5,
  kComplexFloat = 6,
  kLValue = 7,
  kVector = 8,
  kArray = 9,
  kStruct = 10,
  kUnion = 11,
  kMemberPointer = 12,
  kAddrLabelDiff = 13,
};

enum class VariableCaptureKind : unsigned int {
  kThis = 0,
  kByReference = 1,
  kByCopy = 2,
  kVLAType = 3,
};

enum class VectorKind : unsigned int {
  kGenericVector = 0,
  kAltiVecVector = 1,
  kAltiVecPixel = 2,
  kAltiVecBoolean = 3,
  kNeonVector = 4,
  kNeonPolyVector = 5,
  kSveFixedLengthDataVector = 6,
  kSveFixedLengthPredicateVector = 7,
};

enum class VectorLibrary : unsigned int {
  kNoLibrary = 0,
  kAccelerate = 1,
  kLIBMVEC = 2,
  kMASSV = 3,
  kSVML = 4,
  kDarwinLibsystemM = 5,
};

enum class Visibility : unsigned int {
  kHiddenVisibility = 0,
  kProtectedVisibility = 1,
  kDefaultVisibility = 2,
};

enum class VisibilityType : unsigned int {
  kDefault = 0,
  kHidden = 1,
  kProtected = 2,
};

enum class IsModifiableLvalueResult : unsigned int {
  kValid = 0,
  kNotObjectType = 1,
  kIncompleteVoidType = 2,
  kDuplicateVectorComponents = 3,
  kInvalidExpression = 4,
  kLValueCast = 5,
  kIncompleteType = 6,
  kConstQualified = 7,
  kConstQualifiedField = 8,
  kConstAddrSpace = 9,
  kArrayType = 10,
  kNoSetterProperty = 11,
  kMemberFunction = 12,
  kSubObjCPropertySetting = 13,
  kInvalidMessageExpression = 14,
  kClassTemporary = 15,
  kArrayTemporary = 16,
};

#define PASTA_FOR_EACH_STMT_KIND(m) \
    m(GCCAsmStmt) \
    m(MSAsmStmt) \
    m(BreakStmt) \
    m(CXXCatchStmt) \
    m(CXXForRangeStmt) \
    m(CXXTryStmt) \
    m(CapturedStmt) \
    m(CompoundStmt) \
    m(ContinueStmt) \
    m(CoreturnStmt) \
    m(CoroutineBodyStmt) \
    m(DeclStmt) \
    m(DoStmt) \
    m(ForStmt) \
    m(GotoStmt) \
    m(IfStmt) \
    m(IndirectGotoStmt) \
    m(MSDependentExistsStmt) \
    m(NullStmt) \
    m(OMPCanonicalLoop) \
    m(OMPAtomicDirective) \
    m(OMPBarrierDirective) \
    m(OMPCancelDirective) \
    m(OMPCancellationPointDirective) \
    m(OMPCriticalDirective) \
    m(OMPDepobjDirective) \
    m(OMPDispatchDirective) \
    m(OMPFlushDirective) \
    m(OMPInteropDirective) \
    m(OMPDistributeDirective) \
    m(OMPDistributeParallelForDirective) \
    m(OMPDistributeParallelForSimdDirective) \
    m(OMPDistributeSimdDirective) \
    m(OMPForDirective) \
    m(OMPForSimdDirective) \
    m(OMPMasterTaskLoopDirective) \
    m(OMPMasterTaskLoopSimdDirective) \
    m(OMPParallelForDirective) \
    m(OMPParallelForSimdDirective) \
    m(OMPParallelMasterTaskLoopDirective) \
    m(OMPParallelMasterTaskLoopSimdDirective) \
    m(OMPSimdDirective) \
    m(OMPTargetParallelForSimdDirective) \
    m(OMPTargetSimdDirective) \
    m(OMPTargetTeamsDistributeDirective) \
    m(OMPTargetTeamsDistributeParallelForDirective) \
    m(OMPTargetTeamsDistributeParallelForSimdDirective) \
    m(OMPTargetTeamsDistributeSimdDirective) \
    m(OMPTaskLoopDirective) \
    m(OMPTaskLoopSimdDirective) \
    m(OMPTeamsDistributeDirective) \
    m(OMPTeamsDistributeParallelForDirective) \
    m(OMPTeamsDistributeParallelForSimdDirective) \
    m(OMPTeamsDistributeSimdDirective) \
    m(OMPTileDirective) \
    m(OMPUnrollDirective) \
    m(OMPMaskedDirective) \
    m(OMPMasterDirective) \
    m(OMPOrderedDirective) \
    m(OMPParallelDirective) \
    m(OMPParallelMasterDirective) \
    m(OMPParallelSectionsDirective) \
    m(OMPScanDirective) \
    m(OMPSectionDirective) \
    m(OMPSectionsDirective) \
    m(OMPSingleDirective) \
    m(OMPTargetDataDirective) \
    m(OMPTargetDirective) \
    m(OMPTargetEnterDataDirective) \
    m(OMPTargetExitDataDirective) \
    m(OMPTargetParallelDirective) \
    m(OMPTargetParallelForDirective) \
    m(OMPTargetTeamsDirective) \
    m(OMPTargetUpdateDirective) \
    m(OMPTaskDirective) \
    m(OMPTaskgroupDirective) \
    m(OMPTaskwaitDirective) \
    m(OMPTaskyieldDirective) \
    m(OMPTeamsDirective) \
    m(ObjCAtCatchStmt) \
    m(ObjCAtFinallyStmt) \
    m(ObjCAtSynchronizedStmt) \
    m(ObjCAtThrowStmt) \
    m(ObjCAtTryStmt) \
    m(ObjCAutoreleasePoolStmt) \
    m(ObjCForCollectionStmt) \
    m(ReturnStmt) \
    m(SEHExceptStmt) \
    m(SEHFinallyStmt) \
    m(SEHLeaveStmt) \
    m(SEHTryStmt) \
    m(CaseStmt) \
    m(DefaultStmt) \
    m(SwitchStmt) \
    m(AttributedStmt) \
    m(BinaryConditionalOperator) \
    m(ConditionalOperator) \
    m(AddrLabelExpr) \
    m(ArrayInitIndexExpr) \
    m(ArrayInitLoopExpr) \
    m(ArraySubscriptExpr) \
    m(ArrayTypeTraitExpr) \
    m(AsTypeExpr) \
    m(AtomicExpr) \
    m(BinaryOperator) \
    m(CompoundAssignOperator) \
    m(BlockExpr) \
    m(CXXBindTemporaryExpr) \
    m(CXXBoolLiteralExpr) \
    m(CXXConstructExpr) \
    m(CXXTemporaryObjectExpr) \
    m(CXXDefaultArgExpr) \
    m(CXXDefaultInitExpr) \
    m(CXXDeleteExpr) \
    m(CXXDependentScopeMemberExpr) \
    m(CXXFoldExpr) \
    m(CXXInheritedCtorInitExpr) \
    m(CXXNewExpr) \
    m(CXXNoexceptExpr) \
    m(CXXNullPtrLiteralExpr) \
    m(CXXPseudoDestructorExpr) \
    m(CXXRewrittenBinaryOperator) \
    m(CXXScalarValueInitExpr) \
    m(CXXStdInitializerListExpr) \
    m(CXXThisExpr) \
    m(CXXThrowExpr) \
    m(CXXTypeidExpr) \
    m(CXXUnresolvedConstructExpr) \
    m(CXXUuidofExpr) \
    m(CallExpr) \
    m(CUDAKernelCallExpr) \
    m(CXXMemberCallExpr) \
    m(CXXOperatorCallExpr) \
    m(UserDefinedLiteral) \
    m(BuiltinBitCastExpr) \
    m(CStyleCastExpr) \
    m(CXXFunctionalCastExpr) \
    m(CXXAddrspaceCastExpr) \
    m(CXXConstCastExpr) \
    m(CXXDynamicCastExpr) \
    m(CXXReinterpretCastExpr) \
    m(CXXStaticCastExpr) \
    m(ObjCBridgedCastExpr) \
    m(ImplicitCastExpr) \
    m(CharacterLiteral) \
    m(ChooseExpr) \
    m(CompoundLiteralExpr) \
    m(ConceptSpecializationExpr) \
    m(ConvertVectorExpr) \
    m(CoawaitExpr) \
    m(CoyieldExpr) \
    m(DeclRefExpr) \
    m(DependentCoawaitExpr) \
    m(DependentScopeDeclRefExpr) \
    m(DesignatedInitExpr) \
    m(DesignatedInitUpdateExpr) \
    m(ExpressionTraitExpr) \
    m(ExtVectorElementExpr) \
    m(FixedPointLiteral) \
    m(FloatingLiteral) \
    m(ConstantExpr) \
    m(ExprWithCleanups) \
    m(FunctionParmPackExpr) \
    m(GNUNullExpr) \
    m(GenericSelectionExpr) \
    m(ImaginaryLiteral) \
    m(ImplicitValueInitExpr) \
    m(InitListExpr) \
    m(IntegerLiteral) \
    m(LambdaExpr) \
    m(MSPropertyRefExpr) \
    m(MSPropertySubscriptExpr) \
    m(MaterializeTemporaryExpr) \
    m(MatrixSubscriptExpr) \
    m(MemberExpr) \
    m(NoInitExpr) \
    m(OMPArraySectionExpr) \
    m(OMPArrayShapingExpr) \
    m(OMPIteratorExpr) \
    m(ObjCArrayLiteral) \
    m(ObjCAvailabilityCheckExpr) \
    m(ObjCBoolLiteralExpr) \
    m(ObjCBoxedExpr) \
    m(ObjCDictionaryLiteral) \
    m(ObjCEncodeExpr) \
    m(ObjCIndirectCopyRestoreExpr) \
    m(ObjCIsaExpr) \
    m(ObjCIvarRefExpr) \
    m(ObjCMessageExpr) \
    m(ObjCPropertyRefExpr) \
    m(ObjCProtocolExpr) \
    m(ObjCSelectorExpr) \
    m(ObjCStringLiteral) \
    m(ObjCSubscriptRefExpr) \
    m(OffsetOfExpr) \
    m(OpaqueValueExpr) \
    m(UnresolvedLookupExpr) \
    m(UnresolvedMemberExpr) \
    m(PackExpansionExpr) \
    m(ParenExpr) \
    m(ParenListExpr) \
    m(PredefinedExpr) \
    m(PseudoObjectExpr) \
    m(RecoveryExpr) \
    m(RequiresExpr) \
    m(SYCLUniqueStableNameExpr) \
    m(ShuffleVectorExpr) \
    m(SizeOfPackExpr) \
    m(SourceLocExpr) \
    m(StmtExpr) \
    m(StringLiteral) \
    m(SubstNonTypeTemplateParmExpr) \
    m(SubstNonTypeTemplateParmPackExpr) \
    m(TypeTraitExpr) \
    m(TypoExpr) \
    m(UnaryExprOrTypeTraitExpr) \
    m(UnaryOperator) \
    m(VAArgExpr) \
    m(LabelStmt) \
    m(WhileStmt)

#define PASTA_FOR_EACH_TYPE_KIND(m) \
    m(Adjusted) \
    m(Decayed) \
    m(ConstantArray) \
    m(DependentSizedArray) \
    m(IncompleteArray) \
    m(VariableArray) \
    m(Atomic) \
    m(Attributed) \
    m(BlockPointer) \
    m(Builtin) \
    m(Complex) \
    m(Decltype) \
    m(Auto) \
    m(DeducedTemplateSpecialization) \
    m(DependentAddressSpace) \
    m(DependentExtInt) \
    m(DependentName) \
    m(DependentSizedExtVector) \
    m(DependentTemplateSpecialization) \
    m(DependentVector) \
    m(Elaborated) \
    m(ExtInt) \
    m(FunctionNoProto) \
    m(FunctionProto) \
    m(InjectedClassName) \
    m(MacroQualified) \
    m(ConstantMatrix) \
    m(DependentSizedMatrix) \
    m(MemberPointer) \
    m(ObjCObjectPointer) \
    m(ObjCObject) \
    m(ObjCInterface) \
    m(ObjCTypeParam) \
    m(PackExpansion) \
    m(Paren) \
    m(Pipe) \
    m(Pointer) \
    m(LValueReference) \
    m(RValueReference) \
    m(SubstTemplateTypeParmPack) \
    m(SubstTemplateTypeParm) \
    m(Enum) \
    m(Record) \
    m(TemplateSpecialization) \
    m(TemplateTypeParm) \
    m(TypeOfExpr) \
    m(TypeOf) \
    m(Typedef) \
    m(UnaryTransform) \
    m(UnresolvedUsing) \
    m(Vector) \
    m(ExtVector)

class AbstractConditionalOperator;
class AccessSpecDecl;
class AddrLabelExpr;
class AdjustedType;
class ArrayInitIndexExpr;
class ArrayInitLoopExpr;
class ArraySubscriptExpr;
class ArrayType;
class ArrayTypeTraitExpr;
class AsTypeExpr;
class AsmStmt;
class AtomicExpr;
class AtomicType;
class AttributedStmt;
class AttributedType;
class AutoType;
class BaseUsingDecl;
class BinaryConditionalOperator;
class BinaryOperator;
class BindingDecl;
class BlockDecl;
class BlockExpr;
class BlockPointerType;
class BreakStmt;
class BuiltinBitCastExpr;
class BuiltinTemplateDecl;
class BuiltinType;
class CStyleCastExpr;
class CUDAKernelCallExpr;
class CXXAddrspaceCastExpr;
class CXXBindTemporaryExpr;
class CXXBoolLiteralExpr;
class CXXCatchStmt;
class CXXConstCastExpr;
class CXXConstructExpr;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDefaultArgExpr;
class CXXDefaultInitExpr;
class CXXDeleteExpr;
class CXXDependentScopeMemberExpr;
class CXXDestructorDecl;
class CXXDynamicCastExpr;
class CXXFoldExpr;
class CXXForRangeStmt;
class CXXFunctionalCastExpr;
class CXXInheritedCtorInitExpr;
class CXXMemberCallExpr;
class CXXMethodDecl;
class CXXNamedCastExpr;
class CXXNewExpr;
class CXXNoexceptExpr;
class CXXNullPtrLiteralExpr;
class CXXOperatorCallExpr;
class CXXPseudoDestructorExpr;
class CXXRecordDecl;
class CXXReinterpretCastExpr;
class CXXRewrittenBinaryOperator;
class CXXScalarValueInitExpr;
class CXXStaticCastExpr;
class CXXStdInitializerListExpr;
class CXXTemporaryObjectExpr;
class CXXThisExpr;
class CXXThrowExpr;
class CXXTryStmt;
class CXXTypeidExpr;
class CXXUnresolvedConstructExpr;
class CXXUuidofExpr;
class CallExpr;
class CapturedDecl;
class CapturedStmt;
class CaseStmt;
class CastExpr;
class CharacterLiteral;
class ChooseExpr;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class CoawaitExpr;
class ComplexType;
class CompoundAssignOperator;
class CompoundLiteralExpr;
class CompoundStmt;
class ConceptDecl;
class ConceptSpecializationExpr;
class ConditionalOperator;
class ConstantArrayType;
class ConstantExpr;
class ConstantMatrixType;
class ConstructorUsingShadowDecl;
class ContinueStmt;
class ConvertVectorExpr;
class CoreturnStmt;
class CoroutineBodyStmt;
class CoroutineSuspendExpr;
class CoyieldExpr;
class DecayedType;
class Decl;
class DeclContext;
class DeclRefExpr;
class DeclStmt;
class DeclaratorDecl;
class DecltypeType;
class DecompositionDecl;
class DeducedTemplateSpecializationType;
class DeducedType;
class DefaultStmt;
class DependentAddressSpaceType;
class DependentCoawaitExpr;
class DependentExtIntType;
class DependentNameType;
class DependentScopeDeclRefExpr;
class DependentSizedArrayType;
class DependentSizedExtVectorType;
class DependentSizedMatrixType;
class DependentTemplateSpecializationType;
class DependentVectorType;
class DesignatedInitExpr;
class DesignatedInitUpdateExpr;
class DoStmt;
class ElaboratedType;
class EmptyDecl;
class EnumConstantDecl;
class EnumDecl;
class EnumType;
class ExplicitCastExpr;
class ExportDecl;
class Expr;
class ExprWithCleanups;
class ExpressionTraitExpr;
class ExtIntType;
class ExtVectorElementExpr;
class ExtVectorType;
class ExternCContextDecl;
class FieldDecl;
class FileScopeAsmDecl;
class FixedPointLiteral;
class FloatingLiteral;
class ForStmt;
class FriendDecl;
class FriendTemplateDecl;
class FullExpr;
class FunctionDecl;
class FunctionNoProtoType;
class FunctionParmPackExpr;
class FunctionProtoType;
class FunctionTemplateDecl;
class FunctionTemplateSpecializationInfo;
class FunctionType;
class GCCAsmStmt;
class GNUNullExpr;
class GenericSelectionExpr;
class GotoStmt;
class IfStmt;
class ImaginaryLiteral;
class ImplicitCastExpr;
class ImplicitParamDecl;
class ImplicitValueInitExpr;
class ImportDecl;
class IncompleteArrayType;
class IndirectFieldDecl;
class IndirectGotoStmt;
class InitListExpr;
class InjectedClassNameType;
class IntegerLiteral;
class LValueReferenceType;
class LabelDecl;
class LabelStmt;
class LambdaExpr;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class MSAsmStmt;
class MSDependentExistsStmt;
class MSGuidDecl;
class MSPropertyDecl;
class MSPropertyRefExpr;
class MSPropertySubscriptExpr;
class MacroQualifiedType;
class MaterializeTemporaryExpr;
class MatrixSubscriptExpr;
class MatrixType;
class MemberExpr;
class MemberPointerType;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NoInitExpr;
class NonTypeTemplateParmDecl;
class NullStmt;
class OMPAllocateDecl;
class OMPArraySectionExpr;
class OMPArrayShapingExpr;
class OMPAtomicDirective;
class OMPBarrierDirective;
class OMPCancelDirective;
class OMPCancellationPointDirective;
class OMPCanonicalLoop;
class OMPCapturedExprDecl;
class OMPCriticalDirective;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPDepobjDirective;
class OMPDispatchDirective;
class OMPDistributeDirective;
class OMPDistributeParallelForDirective;
class OMPDistributeParallelForSimdDirective;
class OMPDistributeSimdDirective;
class OMPExecutableDirective;
class OMPFlushDirective;
class OMPForDirective;
class OMPForSimdDirective;
class OMPInteropDirective;
class OMPIteratorExpr;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedDirective;
class OMPMasterDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPOrderedDirective;
class OMPParallelDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelMasterDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPParallelSectionsDirective;
class OMPRequiresDecl;
class OMPScanDirective;
class OMPSectionDirective;
class OMPSectionsDirective;
class OMPSimdDirective;
class OMPSingleDirective;
class OMPTargetDataDirective;
class OMPTargetDirective;
class OMPTargetEnterDataDirective;
class OMPTargetExitDataDirective;
class OMPTargetParallelDirective;
class OMPTargetParallelForDirective;
class OMPTargetParallelForSimdDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetUpdateDirective;
class OMPTaskDirective;
class OMPTaskLoopDirective;
class OMPTaskLoopSimdDirective;
class OMPTaskgroupDirective;
class OMPTaskwaitDirective;
class OMPTaskyieldDirective;
class OMPTeamsDirective;
class OMPTeamsDistributeDirective;
class OMPTeamsDistributeParallelForDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class OMPTeamsDistributeSimdDirective;
class OMPThreadPrivateDecl;
class OMPTileDirective;
class OMPUnrollDirective;
class ObjCArrayLiteral;
class ObjCAtCatchStmt;
class ObjCAtDefsFieldDecl;
class ObjCAtFinallyStmt;
class ObjCAtSynchronizedStmt;
class ObjCAtThrowStmt;
class ObjCAtTryStmt;
class ObjCAutoreleasePoolStmt;
class ObjCAvailabilityCheckExpr;
class ObjCBoolLiteralExpr;
class ObjCBoxedExpr;
class ObjCBridgedCastExpr;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCDictionaryLiteral;
class ObjCEncodeExpr;
class ObjCForCollectionStmt;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCIndirectCopyRestoreExpr;
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCIsaExpr;
class ObjCIvarDecl;
class ObjCIvarRefExpr;
class ObjCMessageExpr;
class ObjCMethodDecl;
class ObjCObjectPointerType;
class ObjCObjectType;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCPropertyRefExpr;
class ObjCProtocolDecl;
class ObjCProtocolExpr;
class ObjCSelectorExpr;
class ObjCStringLiteral;
class ObjCSubscriptRefExpr;
class ObjCTypeParamDecl;
class ObjCTypeParamType;
class OffsetOfExpr;
class OpaqueValueExpr;
class OverloadExpr;
class PackExpansionExpr;
class PackExpansionType;
class ParenExpr;
class ParenListExpr;
class ParenType;
class ParmVarDecl;
class PipeType;
class PointerType;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class PredefinedExpr;
class PseudoObjectExpr;
class QualType;
class RValueReferenceType;
class RecordDecl;
class RecordType;
class RecoveryExpr;
class RedeclarableTemplateDecl;
class ReferenceType;
class RequiresExpr;
class RequiresExprBodyDecl;
class ReturnStmt;
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHLeaveStmt;
class SEHTryStmt;
class SYCLUniqueStableNameExpr;
class ShuffleVectorExpr;
class SizeOfPackExpr;
class SourceLocExpr;
class StaticAssertDecl;
class Stmt;
class StmtExpr;
class StringLiteral;
class SubstNonTypeTemplateParmExpr;
class SubstNonTypeTemplateParmPackExpr;
class SubstTemplateTypeParmPackType;
class SubstTemplateTypeParmType;
class SwitchCase;
class SwitchStmt;
class TagDecl;
class TagType;
class TemplateArgument;
class TemplateDecl;
class TemplateParamObjectDecl;
class TemplateSpecializationType;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TemplateTypeParmType;
class TranslationUnitDecl;
class Type;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypeOfExprType;
class TypeOfType;
class TypeSourceInfo;
class TypeTraitExpr;
class TypeWithKeyword;
class TypedefDecl;
class TypedefNameDecl;
class TypedefType;
class TypoExpr;
class UnaryExprOrTypeTraitExpr;
class UnaryOperator;
class UnaryTransformType;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class UnresolvedUsingIfExistsDecl;
class UnresolvedUsingType;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UserDefinedLiteral;
class UsingDecl;
class UsingDirectiveDecl;
class UsingEnumDecl;
class UsingPackDecl;
class UsingShadowDecl;
class VAArgExpr;
class ValueDecl;
class ValueStmt;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
class VariableArrayType;
class VectorType;
class WhileStmt;
class OMPDeclarativeDirectiveDecl;
class OMPDeclarativeDirectiveValueDecl;
}  // namespace pasta
