/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#include <cstdint>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/ADT/APSInt.h>
#pragma GCC diagnostic pop
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "Token.h"

#define PASTA_IGNORE_ABSTRACT(...)

namespace clang {
class ExceptionSpecification;
class AArch64SVEPcsAttr;
class AArch64VectorPcsAttr;
class AMDGPUFlatWorkGroupSizeAttr;
class AMDGPUKernelCallAttr;
class AMDGPUNumSGPRAttr;
class AMDGPUNumVGPRAttr;
class AMDGPUWavesPerEUAttr;
class ARMInterruptAttr;
class AVRInterruptAttr;
class AVRSignalAttr;
class AbiTagAttr;
class AbstractConditionalOperator;
class AccessSpecDecl;
class AcquireCapabilityAttr;
class AcquireHandleAttr;
class AcquiredAfterAttr;
class AcquiredBeforeAttr;
class AddrLabelExpr;
class AddressSpaceAttr;
class AdjustedType;
class AliasAttr;
class AlignMac68kAttr;
class AlignNaturalAttr;
class AlignValueAttr;
class AlignedAttr;
class AllocAlignAttr;
class AllocSizeAttr;
class AlwaysDestroyAttr;
class AlwaysInlineAttr;
class AnalyzerNoReturnAttr;
class AnnotateAttr;
class AnnotateTypeAttr;
class AnyX86InterruptAttr;
class AnyX86NoCallerSavedRegistersAttr;
class AnyX86NoCfCheckAttr;
class ArcWeakrefUnavailableAttr;
class ArgumentWithTypeTagAttr;
class ArmBuiltinAliasAttr;
class ArmMveStrictPolymorphismAttr;
class ArrayInitIndexExpr;
class ArrayInitLoopExpr;
class ArraySubscriptExpr;
class ArrayType;
class ArrayTypeTraitExpr;
class ArtificialAttr;
class AsTypeExpr;
class AsmLabelAttr;
class AsmStmt;
class AssertCapabilityAttr;
class AssertExclusiveLockAttr;
class AssertSharedLockAttr;
class AssumeAlignedAttr;
class AssumptionAttr;
class AtomicExpr;
class AtomicType;
class Attr;
class AttributedStmt;
class AttributedType;
class AutoType;
class AvailabilityAttr;
class BPFPreserveAccessIndexAttr;
class BTFDeclTagAttr;
class BTFTagAttributedType;
class BTFTypeTagAttr;
class BaseUsingDecl;
class BinaryConditionalOperator;
class BinaryOperator;
class BindingDecl;
class BitIntType;
class BlockDecl;
class BlockExpr;
class BlockPointerType;
class BlocksAttr;
class BreakStmt;
class BuiltinAliasAttr;
class BuiltinAttr;
class BuiltinBitCastExpr;
class BuiltinTemplateDecl;
class BuiltinType;
class C11NoReturnAttr;
class CDeclAttr;
class CFAuditedTransferAttr;
class CFConsumedAttr;
class CFGuardAttr;
class CFICanonicalJumpTableAttr;
class CFReturnsNotRetainedAttr;
class CFReturnsRetainedAttr;
class CFUnknownTransferAttr;
class CPUDispatchAttr;
class CPUSpecificAttr;
class CStyleCastExpr;
class CUDAConstantAttr;
class CUDADeviceAttr;
class CUDADeviceBuiltinSurfaceTypeAttr;
class CUDADeviceBuiltinTextureTypeAttr;
class CUDAGlobalAttr;
class CUDAHostAttr;
class CUDAInvalidTargetAttr;
class CUDAKernelCallExpr;
class CUDALaunchBoundsAttr;
class CUDASharedAttr;
class CXX11NoReturnAttr;
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
class CallableWhenAttr;
class CallbackAttr;
class CalledOnceAttr;
class CapabilityAttr;
class CapturedDecl;
class CapturedRecordAttr;
class CapturedStmt;
class CarriesDependencyAttr;
class CaseStmt;
class CastExpr;
class CharacterLiteral;
class ChooseExpr;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class CleanupAttr;
class CmseNSCallAttr;
class CmseNSEntryAttr;
class CoawaitExpr;
class CodeSegAttr;
class ColdAttr;
class CommonAttr;
class ComplexType;
class CompoundAssignOperator;
class CompoundLiteralExpr;
class CompoundStmt;
class ConceptDecl;
class ConceptSpecializationExpr;
class ConditionalOperator;
class ConstAttr;
class ConstInitAttr;
class ConstantArrayType;
class ConstantExpr;
class ConstantMatrixType;
class ConstructorAttr;
class ConstructorUsingShadowDecl;
class ConsumableAttr;
class ConsumableAutoCastAttr;
class ConsumableSetOnReadAttr;
class ContinueStmt;
class ConvergentAttr;
class ConvertVectorExpr;
class CoreturnStmt;
class CoroutineBodyStmt;
class CoroutineSuspendExpr;
class CoyieldExpr;
class DLLExportAttr;
class DLLExportStaticLocalAttr;
class DLLImportAttr;
class DLLImportStaticLocalAttr;
class DecayedType;
class Decl;
class DeclContext;
class DeclOrStmtAttr;
class DeclRefExpr;
class DeclStmt;
class DeclaratorDecl;
class DecltypeType;
class DecompositionDecl;
class DeducedTemplateSpecializationType;
class DeducedType;
class DefaultStmt;
class DependentAddressSpaceType;
class DependentBitIntType;
class DependentCoawaitExpr;
class DependentNameType;
class DependentScopeDeclRefExpr;
class DependentSizedArrayType;
class DependentSizedExtVectorType;
class DependentSizedMatrixType;
class DependentTemplateSpecializationType;
class DependentVectorType;
class DeprecatedAttr;
class DesignatedInitExpr;
class DesignatedInitUpdateExpr;
class DestructorAttr;
class DiagnoseAsBuiltinAttr;
class DiagnoseIfAttr;
class DisableSanitizerInstrumentationAttr;
class DisableTailCallsAttr;
class DoStmt;
class ElaboratedType;
class EmptyBasesAttr;
class EmptyDecl;
class EnableIfAttr;
class EnforceTCBAttr;
class EnforceTCBLeafAttr;
class EnumConstantDecl;
class EnumDecl;
class EnumExtensibilityAttr;
class EnumType;
class ErrorAttr;
class ExcludeFromExplicitInstantiationAttr;
class ExclusiveTrylockFunctionAttr;
class ExplicitCastExpr;
class ExportDecl;
class Expr;
class ExprWithCleanups;
class ExpressionTraitExpr;
class ExtVectorElementExpr;
class ExtVectorType;
class ExternCContextDecl;
class ExternalSourceSymbolAttr;
class FallThroughAttr;
class FastCallAttr;
class FieldDecl;
class FileScopeAsmDecl;
class FinalAttr;
class FixedPointLiteral;
class FlagEnumAttr;
class FlattenAttr;
class FloatingLiteral;
class ForStmt;
class FormatArgAttr;
class FormatAttr;
class FriendDecl;
class FriendTemplateDecl;
class FullExpr;
class FunctionDecl;
class FunctionNoProtoType;
class FunctionParmPackExpr;
class FunctionProtoType;
class FunctionReturnThunksAttr;
class FunctionTemplateDecl;
class FunctionTemplateSpecializationInfo;
class FunctionType;
class GCCAsmStmt;
class GNUInlineAttr;
class GNUNullExpr;
class GenericSelectionExpr;
class GotoStmt;
class GuardedByAttr;
class GuardedVarAttr;
class HIPManagedAttr;
class HLSLNumThreadsAttr;
class HLSLSV_GroupIndexAttr;
class HLSLShaderAttr;
class HotAttr;
class IBActionAttr;
class IBOutletAttr;
class IBOutletCollectionAttr;
class IFuncAttr;
class IfStmt;
class ImaginaryLiteral;
class ImplicitCastExpr;
class ImplicitParamDecl;
class ImplicitValueInitExpr;
class ImportDecl;
class IncompleteArrayType;
class IndirectFieldDecl;
class IndirectGotoStmt;
class InheritableAttr;
class InheritableParamAttr;
class InitListExpr;
class InitPriorityAttr;
class InitSegAttr;
class InjectedClassNameType;
class IntegerLiteral;
class IntelOclBiccAttr;
class InternalLinkageAttr;
class LTOVisibilityPublicAttr;
class LValueReferenceType;
class LabelDecl;
class LabelStmt;
class LambdaExpr;
class LayoutVersionAttr;
class LeafAttr;
class LifetimeBoundAttr;
class LifetimeExtendedTemporaryDecl;
class LikelyAttr;
class LinkageSpecDecl;
class LoaderUninitializedAttr;
class LockReturnedAttr;
class LocksExcludedAttr;
class LoopHintAttr;
class M68kInterruptAttr;
class MIGServerRoutineAttr;
class MSABIAttr;
class MSAllocatorAttr;
class MSAsmStmt;
class MSDependentExistsStmt;
class MSGuidDecl;
class MSInheritanceAttr;
class MSNoVTableAttr;
class MSP430InterruptAttr;
class MSPropertyDecl;
class MSPropertyRefExpr;
class MSPropertySubscriptExpr;
class MSStructAttr;
class MSVtorDispAttr;
class MacroQualifiedType;
class MaterializeTemporaryExpr;
class MatrixSubscriptExpr;
class MatrixType;
class MaxFieldAlignmentAttr;
class MayAliasAttr;
class MemberExpr;
class MemberPointerType;
class MicroMipsAttr;
class MinSizeAttr;
class MinVectorWidthAttr;
class Mips16Attr;
class MipsInterruptAttr;
class MipsLongCallAttr;
class MipsShortCallAttr;
class ModeAttr;
class MustTailAttr;
class NSConsumedAttr;
class NSConsumesSelfAttr;
class NSErrorDomainAttr;
class NSReturnsAutoreleasedAttr;
class NSReturnsNotRetainedAttr;
class NSReturnsRetainedAttr;
class NakedAttr;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NoAliasAttr;
class NoBuiltinAttr;
class NoCommonAttr;
class NoDebugAttr;
class NoDerefAttr;
class NoDestroyAttr;
class NoDuplicateAttr;
class NoEscapeAttr;
class NoInitExpr;
class NoInlineAttr;
class NoInstrumentFunctionAttr;
class NoMergeAttr;
class NoMicroMipsAttr;
class NoMips16Attr;
class NoProfileFunctionAttr;
class NoRandomizeLayoutAttr;
class NoReturnAttr;
class NoSanitizeAttr;
class NoSpeculativeLoadHardeningAttr;
class NoSplitStackAttr;
class NoStackProtectorAttr;
class NoThreadSafetyAnalysisAttr;
class NoThrowAttr;
class NoUniqueAddressAttr;
class NonNullAttr;
class NonTypeTemplateParmDecl;
class NotTailCalledAttr;
class NullStmt;
class OMPAllocateDecl;
class OMPAllocateDeclAttr;
class OMPArraySectionExpr;
class OMPArrayShapingExpr;
class OMPAtomicDirective;
class OMPBarrierDirective;
class OMPCancelDirective;
class OMPCancellationPointDirective;
class OMPCanonicalLoop;
class OMPCaptureKindAttr;
class OMPCaptureNoInitAttr;
class OMPCapturedExprDecl;
class OMPCriticalDirective;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPDeclareSimdDeclAttr;
class OMPDeclareTargetDeclAttr;
class OMPDeclareVariantAttr;
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
class OMPGenericLoopDirective;
class OMPInteropDirective;
class OMPIteratorExpr;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPLoopTransformationDirective;
class OMPMaskedDirective;
class OMPMaskedTaskLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class OMPMasterDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPMetaDirective;
class OMPOrderedDirective;
class OMPParallelDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelGenericLoopDirective;
class OMPParallelMaskedDirective;
class OMPParallelMaskedTaskLoopDirective;
class OMPParallelMaskedTaskLoopSimdDirective;
class OMPParallelMasterDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPParallelSectionsDirective;
class OMPReferencedVarAttr;
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
class OMPTargetParallelGenericLoopDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetTeamsGenericLoopDirective;
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
class OMPTeamsGenericLoopDirective;
class OMPThreadPrivateDecl;
class OMPThreadPrivateDeclAttr;
class OMPTileDirective;
class OMPUnrollDirective;
class OSConsumedAttr;
class OSConsumesThisAttr;
class OSReturnsNotRetainedAttr;
class OSReturnsRetainedAttr;
class OSReturnsRetainedOnNonZeroAttr;
class OSReturnsRetainedOnZeroAttr;
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
class ObjCBoxableAttr;
class ObjCBoxedExpr;
class ObjCBridgeAttr;
class ObjCBridgeMutableAttr;
class ObjCBridgeRelatedAttr;
class ObjCBridgedCastExpr;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCClassStubAttr;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCDesignatedInitializerAttr;
class ObjCDictionaryLiteral;
class ObjCDirectAttr;
class ObjCDirectMembersAttr;
class ObjCEncodeExpr;
class ObjCExceptionAttr;
class ObjCExplicitProtocolImplAttr;
class ObjCExternallyRetainedAttr;
class ObjCForCollectionStmt;
class ObjCGCAttr;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCIndependentClassAttr;
class ObjCIndirectCopyRestoreExpr;
class ObjCInertUnsafeUnretainedAttr;
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCIsaExpr;
class ObjCIvarDecl;
class ObjCIvarRefExpr;
class ObjCKindOfAttr;
class ObjCMessageExpr;
class ObjCMethodDecl;
class ObjCMethodFamilyAttr;
class ObjCNSObjectAttr;
class ObjCNonLazyClassAttr;
class ObjCNonRuntimeProtocolAttr;
class ObjCObjectPointerType;
class ObjCObjectType;
class ObjCOwnershipAttr;
class ObjCPreciseLifetimeAttr;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCPropertyRefExpr;
class ObjCProtocolDecl;
class ObjCProtocolExpr;
class ObjCRequiresPropertyDefsAttr;
class ObjCRequiresSuperAttr;
class ObjCReturnsInnerPointerAttr;
class ObjCRootClassAttr;
class ObjCRuntimeNameAttr;
class ObjCRuntimeVisibleAttr;
class ObjCSelectorExpr;
class ObjCStringLiteral;
class ObjCSubclassingRestrictedAttr;
class ObjCSubscriptRefExpr;
class ObjCTypeParamDecl;
class ObjCTypeParamType;
class OffsetOfExpr;
class OpaqueValueExpr;
class OpenCLAccessAttr;
class OpenCLConstantAddressSpaceAttr;
class OpenCLGenericAddressSpaceAttr;
class OpenCLGlobalAddressSpaceAttr;
class OpenCLGlobalDeviceAddressSpaceAttr;
class OpenCLGlobalHostAddressSpaceAttr;
class OpenCLIntelReqdSubGroupSizeAttr;
class OpenCLKernelAttr;
class OpenCLLocalAddressSpaceAttr;
class OpenCLPrivateAddressSpaceAttr;
class OpenCLUnrollHintAttr;
class OptimizeNoneAttr;
class OverloadExpr;
class OverloadableAttr;
class OverrideAttr;
class OwnerAttr;
class OwnershipAttr;
class PackExpansionExpr;
class PackExpansionType;
class PackedAttr;
class ParamTypestateAttr;
class ParameterABIAttr;
class ParenExpr;
class ParenListExpr;
class ParenType;
class ParmVarDecl;
class PascalAttr;
class PassObjectSizeAttr;
class PatchableFunctionEntryAttr;
class PcsAttr;
class PipeType;
class PointerAttr;
class PointerType;
class PragmaClangBSSSectionAttr;
class PragmaClangDataSectionAttr;
class PragmaClangRelroSectionAttr;
class PragmaClangRodataSectionAttr;
class PragmaClangTextSectionAttr;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class PredefinedExpr;
class PreferredNameAttr;
class PreserveAllAttr;
class PreserveMostAttr;
class PseudoObjectExpr;
class PtGuardedByAttr;
class PtGuardedVarAttr;
class Ptr32Attr;
class Ptr64Attr;
class PureAttr;
class RISCVInterruptAttr;
class RValueReferenceType;
class RandomizeLayoutAttr;
class RecordDecl;
class RecordType;
class RecoveryExpr;
class RedeclarableTemplateDecl;
class ReferenceType;
class RegCallAttr;
class ReinitializesAttr;
class ReleaseCapabilityAttr;
class ReleaseHandleAttr;
class RenderScriptKernelAttr;
class ReqdWorkGroupSizeAttr;
class RequiresCapabilityAttr;
class RequiresExpr;
class RequiresExprBodyDecl;
class RestrictAttr;
class RetainAttr;
class ReturnStmt;
class ReturnTypestateAttr;
class ReturnsNonNullAttr;
class ReturnsTwiceAttr;
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHLeaveStmt;
class SEHTryStmt;
class SPtrAttr;
class SYCLKernelAttr;
class SYCLSpecialClassAttr;
class SYCLUniqueStableNameExpr;
class ScopedLockableAttr;
class SectionAttr;
class SelectAnyAttr;
class SentinelAttr;
class SetTypestateAttr;
class SharedTrylockFunctionAttr;
class ShuffleVectorExpr;
class SizeOfPackExpr;
class SourceLocExpr;
class SpeculativeLoadHardeningAttr;
class StandaloneDebugAttr;
class StaticAssertDecl;
class StdCallAttr;
class Stmt;
class StmtAttr;
class StmtExpr;
class StrictFPAttr;
class StringLiteral;
class SubstNonTypeTemplateParmExpr;
class SubstNonTypeTemplateParmPackExpr;
class SubstTemplateTypeParmPackType;
class SubstTemplateTypeParmType;
class SuppressAttr;
class SwiftAsyncAttr;
class SwiftAsyncCallAttr;
class SwiftAsyncContextAttr;
class SwiftAsyncErrorAttr;
class SwiftAsyncNameAttr;
class SwiftAttrAttr;
class SwiftBridgeAttr;
class SwiftBridgedTypedefAttr;
class SwiftCallAttr;
class SwiftContextAttr;
class SwiftErrorAttr;
class SwiftErrorResultAttr;
class SwiftIndirectResultAttr;
class SwiftNameAttr;
class SwiftNewTypeAttr;
class SwiftObjCMembersAttr;
class SwiftPrivateAttr;
class SwitchCase;
class SwitchStmt;
class SysVABIAttr;
class TLSModelAttr;
class TagDecl;
class TagType;
class TargetAttr;
class TargetClonesAttr;
class TemplateArgument;
class TemplateDecl;
class TemplateParamObjectDecl;
class TemplateSpecializationType;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TemplateTypeParmType;
class TestTypestateAttr;
class ThisCallAttr;
class ThreadAttr;
class TranslationUnitDecl;
class TransparentUnionAttr;
class TrivialABIAttr;
class TryAcquireCapabilityAttr;
class Type;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeAttr;
class TypeDecl;
class TypeNonNullAttr;
class TypeNullUnspecifiedAttr;
class TypeNullableAttr;
class TypeNullableResultAttr;
class TypeOfExprType;
class TypeOfType;
class TypeSourceInfo;
class TypeTagForDatatypeAttr;
class TypeTraitExpr;
class TypeVisibilityAttr;
class TypeWithKeyword;
class TypedefDecl;
class TypedefNameDecl;
class TypedefType;
class TypoExpr;
class UPtrAttr;
class UnaryExprOrTypeTraitExpr;
class UnaryOperator;
class UnaryTransformType;
class UnavailableAttr;
class UninitializedAttr;
class UnlikelyAttr;
class UnnamedGlobalConstantDecl;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class UnresolvedUsingIfExistsDecl;
class UnresolvedUsingType;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UnusedAttr;
class UseHandleAttr;
class UsedAttr;
class UserDefinedLiteral;
class UsingDecl;
class UsingDirectiveDecl;
class UsingEnumDecl;
class UsingIfExistsAttr;
class UsingPackDecl;
class UsingShadowDecl;
class UsingType;
class UuidAttr;
class VAArgExpr;
class ValueDecl;
class ValueStmt;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
class VariableArrayType;
class VecReturnAttr;
class VecTypeHintAttr;
class VectorCallAttr;
class VectorType;
class VisibilityAttr;
class WarnUnusedAttr;
class WarnUnusedResultAttr;
class WeakAttr;
class WeakImportAttr;
class WeakRefAttr;
class WebAssemblyExportNameAttr;
class WebAssemblyImportModuleAttr;
class WebAssemblyImportNameAttr;
class WhileStmt;
class WorkGroupSizeHintAttr;
class X86ForceAlignArgPointerAttr;
class XRayInstrumentAttr;
class XRayLogArgsAttr;
class ZeroCallUsedRegsAttr;
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
    a(OMPDeclarativeDirectiveDecl) \
    a(OMPDeclarativeDirectiveValueDecl) \
    m(AccessSpec) \
    a(BaseUsingDecl) \
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
    a(DeclaratorDecl) \
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
    a(NamedDecl) \
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
    a(ObjCContainerDecl) \
    a(ObjCImplDecl) \
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
    a(RedeclarableTemplateDecl) \
    m(RequiresExprBody) \
    m(StaticAssert) \
    a(TagDecl) \
    a(TemplateDecl) \
    m(TemplateParamObject) \
    m(TemplateTemplateParm) \
    m(TemplateTypeParm) \
    m(TranslationUnit) \
    m(TypeAlias) \
    m(TypeAliasTemplate) \
    a(TypeDecl) \
    m(Typedef) \
    a(TypedefNameDecl) \
    m(UnnamedGlobalConstant) \
    m(UnresolvedUsingIfExists) \
    m(UnresolvedUsingTypename) \
    m(UnresolvedUsingValue) \
    m(Using) \
    m(UsingDirective) \
    m(UsingEnum) \
    m(UsingPack) \
    m(UsingShadow) \
    a(ValueDecl) \
    m(Var) \
    m(VarTemplate) \
    m(VarTemplatePartialSpecialization) \
    m(VarTemplateSpecialization)

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
    d(OMPGenericLoopDirective) \
    d(OMPInteropDirective) \
    e(OMPIteratorExpr) \
    a(OMPLoopBasedDirective) \
    a(OMPLoopDirective) \
    a(OMPLoopTransformationDirective) \
    d(OMPMaskedDirective) \
    d(OMPMaskedTaskLoopDirective) \
    d(OMPMaskedTaskLoopSimdDirective) \
    d(OMPMasterDirective) \
    d(OMPMasterTaskLoopDirective) \
    d(OMPMasterTaskLoopSimdDirective) \
    d(OMPMetaDirective) \
    d(OMPOrderedDirective) \
    d(OMPParallelDirective) \
    d(OMPParallelForDirective) \
    d(OMPParallelForSimdDirective) \
    d(OMPParallelGenericLoopDirective) \
    d(OMPParallelMaskedDirective) \
    d(OMPParallelMaskedTaskLoopDirective) \
    d(OMPParallelMaskedTaskLoopSimdDirective) \
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
    d(OMPTargetParallelGenericLoopDirective) \
    d(OMPTargetSimdDirective) \
    d(OMPTargetTeamsDirective) \
    d(OMPTargetTeamsDistributeDirective) \
    d(OMPTargetTeamsDistributeParallelForDirective) \
    d(OMPTargetTeamsDistributeParallelForSimdDirective) \
    d(OMPTargetTeamsDistributeSimdDirective) \
    d(OMPTargetTeamsGenericLoopDirective) \
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
    d(OMPTeamsGenericLoopDirective) \
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
    a(ArrayType) \
    m(Atomic) \
    m(Attributed) \
    m(Auto) \
    m(BTFTagAttributed) \
    m(BitInt) \
    m(BlockPointer) \
    m(Builtin) \
    m(Complex) \
    m(ConstantArray) \
    m(ConstantMatrix) \
    m(Decayed) \
    m(Decltype) \
    m(DeducedTemplateSpecialization) \
    a(DeducedType) \
    m(DependentAddressSpace) \
    m(DependentBitInt) \
    m(DependentName) \
    m(DependentSizedArray) \
    m(DependentSizedExtVector) \
    m(DependentSizedMatrix) \
    m(DependentTemplateSpecialization) \
    m(DependentVector) \
    m(Elaborated) \
    m(Enum) \
    m(ExtVector) \
    m(FunctionNoProto) \
    m(FunctionProto) \
    a(FunctionType) \
    m(IncompleteArray) \
    m(InjectedClassName) \
    m(LValueReference) \
    m(MacroQualified) \
    a(MatrixType) \
    m(MemberPointer) \
    m(ObjCInterface) \
    m(ObjCObjectPointer) \
    m(ObjCObject) \
    m(ObjCTypeParam) \
    m(PackExpansion) \
    m(Paren) \
    m(Pipe) \
    m(Pointer) \
    a(QualifiedType) \
    m(RValueReference) \
    m(Record) \
    a(ReferenceType) \
    m(SubstTemplateTypeParmPack) \
    m(SubstTemplateTypeParm) \
    a(TagType) \
    m(TemplateSpecialization) \
    m(TemplateTypeParm) \
    a(Type) \
    m(TypeOfExpr) \
    m(TypeOf) \
    m(Typedef) \
    m(UnaryTransform) \
    m(UnresolvedUsing) \
    m(Using) \
    m(VariableArray) \
    m(Vector) \
    a(TypeWithKeyword) \
    m(Qualified)

#define PASTA_FOR_EACH_ATTR_IMPL(m, a) \
    m(AArch64SVEPcs) \
    m(AArch64VectorPcs) \
    m(AMDGPUFlatWorkGroupSize) \
    m(AMDGPUKernelCall) \
    m(AMDGPUNumSGPR) \
    m(AMDGPUNumVGPR) \
    m(AMDGPUWavesPerEU) \
    m(ARMInterrupt) \
    m(AVRInterrupt) \
    m(AVRSignal) \
    m(AbiTag) \
    m(AcquireCapability) \
    m(AcquireHandle) \
    m(AcquiredAfter) \
    m(AcquiredBefore) \
    m(AddressSpace) \
    m(Alias) \
    m(AlignMac68k) \
    m(AlignNatural) \
    m(AlignValue) \
    m(Aligned) \
    m(AllocAlign) \
    m(AllocSize) \
    m(AlwaysDestroy) \
    m(AlwaysInline) \
    m(AnalyzerNoReturn) \
    m(Annotate) \
    m(AnnotateType) \
    m(AnyX86Interrupt) \
    m(AnyX86NoCallerSavedRegisters) \
    m(AnyX86NoCfCheck) \
    m(ArcWeakrefUnavailable) \
    m(ArgumentWithTypeTag) \
    m(ArmBuiltinAlias) \
    m(ArmMveStrictPolymorphism) \
    m(Artificial) \
    m(AsmLabel) \
    m(AssertCapability) \
    m(AssertExclusiveLock) \
    m(AssertSharedLock) \
    m(AssumeAligned) \
    m(Assumption) \
    a(Attr) \
    m(Availability) \
    m(BPFPreserveAccessIndex) \
    m(BTFDeclTag) \
    m(BTFTypeTag) \
    m(Blocks) \
    m(BuiltinAlias) \
    m(Builtin) \
    m(C11NoReturn) \
    m(CDecl) \
    m(CFAuditedTransfer) \
    m(CFConsumed) \
    m(CFGuard) \
    m(CFICanonicalJumpTable) \
    m(CFReturnsNotRetained) \
    m(CFReturnsRetained) \
    m(CFUnknownTransfer) \
    m(CPUDispatch) \
    m(CPUSpecific) \
    m(CUDAConstant) \
    m(CUDADevice) \
    m(CUDADeviceBuiltinSurfaceType) \
    m(CUDADeviceBuiltinTextureType) \
    m(CUDAGlobal) \
    m(CUDAHost) \
    m(CUDAInvalidTarget) \
    m(CUDALaunchBounds) \
    m(CUDAShared) \
    m(CXX11NoReturn) \
    m(CallableWhen) \
    m(Callback) \
    m(CalledOnce) \
    m(Capability) \
    m(CapturedRecord) \
    m(CarriesDependency) \
    m(Cleanup) \
    m(CmseNSCall) \
    m(CmseNSEntry) \
    m(CodeSeg) \
    m(Cold) \
    m(Common) \
    m(Const) \
    m(ConstInit) \
    m(Constructor) \
    m(Consumable) \
    m(ConsumableAutoCast) \
    m(ConsumableSetOnRead) \
    m(Convergent) \
    m(DLLExport) \
    m(DLLExportStaticLocal) \
    m(DLLImport) \
    m(DLLImportStaticLocal) \
    a(DeclOrStmtAttr) \
    m(Deprecated) \
    m(Destructor) \
    m(DiagnoseAsBuiltin) \
    m(DiagnoseIf) \
    m(DisableSanitizerInstrumentation) \
    m(DisableTailCalls) \
    m(EmptyBases) \
    m(EnableIf) \
    m(EnforceTCB) \
    m(EnforceTCBLeaf) \
    m(EnumExtensibility) \
    m(Error) \
    m(ExcludeFromExplicitInstantiation) \
    m(ExclusiveTrylockFunction) \
    m(ExternalSourceSymbol) \
    m(FallThrough) \
    m(FastCall) \
    m(Final) \
    m(FlagEnum) \
    m(Flatten) \
    m(FormatArg) \
    m(Format) \
    m(FunctionReturnThunks) \
    m(GNUInline) \
    m(GuardedBy) \
    m(GuardedVar) \
    m(HIPManaged) \
    m(HLSLNumThreads) \
    m(HLSLSV_GroupIndex) \
    m(HLSLShader) \
    m(Hot) \
    m(IBAction) \
    m(IBOutlet) \
    m(IBOutletCollection) \
    m(IFunc) \
    a(InheritableAttr) \
    a(InheritableParamAttr) \
    m(InitPriority) \
    m(InitSeg) \
    m(IntelOclBicc) \
    m(InternalLinkage) \
    m(LTOVisibilityPublic) \
    m(LayoutVersion) \
    m(Leaf) \
    m(LifetimeBound) \
    m(Likely) \
    m(LoaderUninitialized) \
    m(LockReturned) \
    m(LocksExcluded) \
    m(LoopHint) \
    m(M68kInterrupt) \
    m(MIGServerRoutine) \
    m(MSABI) \
    m(MSAllocator) \
    m(MSInheritance) \
    m(MSNoVTable) \
    m(MSP430Interrupt) \
    m(MSStruct) \
    m(MSVtorDisp) \
    m(MaxFieldAlignment) \
    m(MayAlias) \
    m(MicroMips) \
    m(MinSize) \
    m(MinVectorWidth) \
    m(Mips16) \
    m(MipsInterrupt) \
    m(MipsLongCall) \
    m(MipsShortCall) \
    m(Mode) \
    m(MustTail) \
    m(NSConsumed) \
    m(NSConsumesSelf) \
    m(NSErrorDomain) \
    m(NSReturnsAutoreleased) \
    m(NSReturnsNotRetained) \
    m(NSReturnsRetained) \
    m(Naked) \
    m(NoAlias) \
    m(NoBuiltin) \
    m(NoCommon) \
    m(NoDebug) \
    m(NoDeref) \
    m(NoDestroy) \
    m(NoDuplicate) \
    m(NoEscape) \
    m(NoInline) \
    m(NoInstrumentFunction) \
    m(NoMerge) \
    m(NoMicroMips) \
    m(NoMips16) \
    m(NoProfileFunction) \
    m(NoRandomizeLayout) \
    m(NoReturn) \
    m(NoSanitize) \
    m(NoSpeculativeLoadHardening) \
    m(NoSplitStack) \
    m(NoStackProtector) \
    m(NoThreadSafetyAnalysis) \
    m(NoThrow) \
    m(NoUniqueAddress) \
    m(NonNull) \
    m(NotTailCalled) \
    m(OMPAllocateDecl) \
    m(OMPCaptureKind) \
    m(OMPCaptureNoInit) \
    m(OMPDeclareSimdDecl) \
    m(OMPDeclareTargetDecl) \
    m(OMPDeclareVariant) \
    m(OMPReferencedVar) \
    m(OMPThreadPrivateDecl) \
    m(OSConsumed) \
    m(OSConsumesThis) \
    m(OSReturnsNotRetained) \
    m(OSReturnsRetained) \
    m(OSReturnsRetainedOnNonZero) \
    m(OSReturnsRetainedOnZero) \
    m(ObjCBoxable) \
    m(ObjCBridge) \
    m(ObjCBridgeMutable) \
    m(ObjCBridgeRelated) \
    m(ObjCClassStub) \
    m(ObjCDesignatedInitializer) \
    m(ObjCDirect) \
    m(ObjCDirectMembers) \
    m(ObjCException) \
    m(ObjCExplicitProtocolImpl) \
    m(ObjCExternallyRetained) \
    m(ObjCGC) \
    m(ObjCIndependentClass) \
    m(ObjCInertUnsafeUnretained) \
    m(ObjCKindOf) \
    m(ObjCMethodFamily) \
    m(ObjCNSObject) \
    m(ObjCNonLazyClass) \
    m(ObjCNonRuntimeProtocol) \
    m(ObjCOwnership) \
    m(ObjCPreciseLifetime) \
    m(ObjCRequiresPropertyDefs) \
    m(ObjCRequiresSuper) \
    m(ObjCReturnsInnerPointer) \
    m(ObjCRootClass) \
    m(ObjCRuntimeName) \
    m(ObjCRuntimeVisible) \
    m(ObjCSubclassingRestricted) \
    m(OpenCLAccess) \
    m(OpenCLConstantAddressSpace) \
    m(OpenCLGenericAddressSpace) \
    m(OpenCLGlobalAddressSpace) \
    m(OpenCLGlobalDeviceAddressSpace) \
    m(OpenCLGlobalHostAddressSpace) \
    m(OpenCLIntelReqdSubGroupSize) \
    m(OpenCLKernel) \
    m(OpenCLLocalAddressSpace) \
    m(OpenCLPrivateAddressSpace) \
    m(OpenCLUnrollHint) \
    m(OptimizeNone) \
    m(Overloadable) \
    m(Override) \
    m(Owner) \
    m(Ownership) \
    m(Packed) \
    m(ParamTypestate) \
    a(ParameterABIAttr) \
    m(Pascal) \
    m(PassObjectSize) \
    m(PatchableFunctionEntry) \
    m(Pcs) \
    m(Pointer) \
    m(PragmaClangBSSSection) \
    m(PragmaClangDataSection) \
    m(PragmaClangRelroSection) \
    m(PragmaClangRodataSection) \
    m(PragmaClangTextSection) \
    m(PreferredName) \
    m(PreserveAll) \
    m(PreserveMost) \
    m(PtGuardedBy) \
    m(PtGuardedVar) \
    m(Ptr32) \
    m(Ptr64) \
    m(Pure) \
    m(RISCVInterrupt) \
    m(RandomizeLayout) \
    m(RegCall) \
    m(Reinitializes) \
    m(ReleaseCapability) \
    m(ReleaseHandle) \
    m(RenderScriptKernel) \
    m(ReqdWorkGroupSize) \
    m(RequiresCapability) \
    m(Restrict) \
    m(Retain) \
    m(ReturnTypestate) \
    m(ReturnsNonNull) \
    m(ReturnsTwice) \
    m(SPtr) \
    m(SYCLKernel) \
    m(SYCLSpecialClass) \
    m(ScopedLockable) \
    m(Section) \
    m(SelectAny) \
    m(Sentinel) \
    m(SetTypestate) \
    m(SharedTrylockFunction) \
    m(SpeculativeLoadHardening) \
    m(StandaloneDebug) \
    m(StdCall) \
    a(StmtAttr) \
    m(StrictFP) \
    m(Suppress) \
    m(SwiftAsync) \
    m(SwiftAsyncCall) \
    m(SwiftAsyncContext) \
    m(SwiftAsyncError) \
    m(SwiftAsyncName) \
    m(SwiftAttr) \
    m(SwiftBridge) \
    m(SwiftBridgedTypedef) \
    m(SwiftCall) \
    m(SwiftContext) \
    m(SwiftError) \
    m(SwiftErrorResult) \
    m(SwiftIndirectResult) \
    m(SwiftName) \
    m(SwiftNewType) \
    m(SwiftObjCMembers) \
    m(SwiftPrivate) \
    m(SysVABI) \
    m(TLSModel) \
    m(Target) \
    m(TargetClones) \
    m(TestTypestate) \
    m(ThisCall) \
    m(Thread) \
    m(TransparentUnion) \
    m(TrivialABI) \
    m(TryAcquireCapability) \
    a(TypeAttr) \
    m(TypeNonNull) \
    m(TypeNullUnspecified) \
    m(TypeNullable) \
    m(TypeNullableResult) \
    m(TypeTagForDatatype) \
    m(TypeVisibility) \
    m(UPtr) \
    m(Unavailable) \
    m(Uninitialized) \
    m(Unlikely) \
    m(Unused) \
    m(UseHandle) \
    m(Used) \
    m(UsingIfExists) \
    m(Uuid) \
    m(VecReturn) \
    m(VecTypeHint) \
    m(VectorCall) \
    m(Visibility) \
    m(WarnUnused) \
    m(WarnUnusedResult) \
    m(Weak) \
    m(WeakImport) \
    m(WeakRef) \
    m(WebAssemblyExportName) \
    m(WebAssemblyImportModule) \
    m(WebAssemblyImportName) \
    m(WorkGroupSizeHint) \
    m(X86ForceAlignArgPointer) \
    m(XRayInstrument) \
    m(XRayLogArgs) \
    m(ZeroCallUsedRegs)

enum class DeclKind : unsigned int {
#define PASTA_DECLARE_DECL_KIND(name) k ## name ,
  PASTA_FOR_EACH_DECL_IMPL(PASTA_DECLARE_DECL_KIND, PASTA_IGNORE_ABSTRACT)
#undef PASTA_DECLARE_DECL_KIND
};

enum class AttrKind : unsigned int {
#define PASTA_DECLARE_ATTR_KIND(name) k ## name ,
  PASTA_FOR_EACH_ATTR_IMPL(PASTA_DECLARE_ATTR_KIND, PASTA_IGNORE_ABSTRACT)
#undef PASTA_DECLARE_DECL_KIND
};

enum class AArch64SVEPcsAttrSpelling : unsigned int {
  kGNUAarch64SvePcs = 0,
  kCXX11ClangAarch64SvePcs = 1,
  kC2xClangAarch64SvePcs = 2,
  kSpellingNotCalculated = 15,
};

enum class AArch64VectorPcsAttrSpelling : unsigned int {
  kGNUAarch64VectorPcs = 0,
  kCXX11ClangAarch64VectorPcs = 1,
  kC2xClangAarch64VectorPcs = 2,
  kSpellingNotCalculated = 15,
};

enum class AMDGPUFlatWorkGroupSizeAttrSpelling : unsigned int {
  kGNUAmdgpuFlatWorkGroupSize = 0,
  kCXX11ClangAmdgpuFlatWorkGroupSize = 1,
  kSpellingNotCalculated = 15,
};

enum class AMDGPUKernelCallAttrSpelling : unsigned int {
  kGNUAmdgpuKernel = 0,
  kCXX11ClangAmdgpuKernel = 1,
  kC2xClangAmdgpuKernel = 2,
  kSpellingNotCalculated = 15,
};

enum class AMDGPUNumSGPRAttrSpelling : unsigned int {
  kGNUAmdgpuNumSgpr = 0,
  kCXX11ClangAmdgpuNumSgpr = 1,
  kSpellingNotCalculated = 15,
};

enum class AMDGPUNumVGPRAttrSpelling : unsigned int {
  kGNUAmdgpuNumVgpr = 0,
  kCXX11ClangAmdgpuNumVgpr = 1,
  kSpellingNotCalculated = 15,
};

enum class AMDGPUWavesPerEUAttrSpelling : unsigned int {
  kGNUAmdgpuWavesPerEu = 0,
  kCXX11ClangAmdgpuWavesPerEu = 1,
  kSpellingNotCalculated = 15,
};

enum class ARMInterruptAttrInterruptType : unsigned int {
  kIRQ = 0,
  kFIQ = 1,
  kSWI = 2,
  kABORT = 3,
  kUNDEF = 4,
  kGeneric = 5,
};

enum class ARMInterruptAttrSpelling : unsigned int {
  kGNUInterrupt = 0,
  kCXX11GnuInterrupt = 1,
  kC2xGnuInterrupt = 2,
  kSpellingNotCalculated = 15,
};

enum class AVRInterruptAttrSpelling : unsigned int {
  kGNUInterrupt = 0,
  kCXX11GnuInterrupt = 1,
  kC2xGnuInterrupt = 2,
  kSpellingNotCalculated = 15,
};

enum class AVRSignalAttrSpelling : unsigned int {
  kGNUSignal = 0,
  kCXX11GnuSignal = 1,
  kC2xGnuSignal = 2,
  kSpellingNotCalculated = 15,
};

enum class AbiTagAttrSpelling : unsigned int {
  kGNUAbiTag = 0,
  kCXX11GnuAbiTag = 1,
  kSpellingNotCalculated = 15,
};

enum class AcquireCapabilityAttrSpelling : unsigned int {
  kGNUAcquireCapability = 0,
  kCXX11ClangAcquireCapability = 1,
  kGNUAcquireSharedCapability = 2,
  kCXX11ClangAcquireSharedCapability = 3,
  kGNUExclusiveLockFunction = 4,
  kGNUSharedLockFunction = 5,
  kSpellingNotCalculated = 15,
};

enum class AcquireHandleAttrSpelling : unsigned int {
  kGNUAcquireHandle = 0,
  kCXX11ClangAcquireHandle = 1,
  kC2xClangAcquireHandle = 2,
  kSpellingNotCalculated = 15,
};

enum class AddressSpaceAttrSpelling : unsigned int {
  kGNUAddressSpace = 0,
  kCXX11ClangAddressSpace = 1,
  kC2xClangAddressSpace = 2,
  kSpellingNotCalculated = 15,
};

enum class AliasAttrSpelling : unsigned int {
  kGNUAlias = 0,
  kCXX11GnuAlias = 1,
  kC2xGnuAlias = 2,
  kSpellingNotCalculated = 15,
};

enum class AlignedAttrSpelling : unsigned int {
  kGNUAligned = 0,
  kCXX11GnuAligned = 1,
  kC2xGnuAligned = 2,
  kDeclspecAlign = 3,
  kKeywordAlignas = 4,
  kKeyword_Alignas = 5,
  kSpellingNotCalculated = 15,
};

enum class AllocAlignAttrSpelling : unsigned int {
  kGNUAllocAlign = 0,
  kCXX11GnuAllocAlign = 1,
  kC2xGnuAllocAlign = 2,
  kSpellingNotCalculated = 15,
};

enum class AllocSizeAttrSpelling : unsigned int {
  kGNUAllocSize = 0,
  kCXX11GnuAllocSize = 1,
  kC2xGnuAllocSize = 2,
  kSpellingNotCalculated = 15,
};

enum class AlwaysDestroyAttrSpelling : unsigned int {
  kGNUAlwaysDestroy = 0,
  kCXX11ClangAlwaysDestroy = 1,
  kSpellingNotCalculated = 15,
};

enum class AlwaysInlineAttrSpelling : unsigned int {
  kGNUAlwaysInline = 0,
  kCXX11GnuAlwaysInline = 1,
  kC2xGnuAlwaysInline = 2,
  kCXX11ClangAlwaysInline = 3,
  kC2xClangAlwaysInline = 4,
  kKeywordForceinline = 5,
  kSpellingNotCalculated = 15,
};

enum class AnnotateAttrSpelling : unsigned int {
  kGNUAnnotate = 0,
  kCXX11ClangAnnotate = 1,
  kC2xClangAnnotate = 2,
  kSpellingNotCalculated = 15,
};

enum class AnnotateTypeAttrSpelling : unsigned int {
  kCXX11ClangAnnotateType = 0,
  kC2xClangAnnotateType = 1,
  kSpellingNotCalculated = 15,
};

enum class AnyX86InterruptAttrSpelling : unsigned int {
  kGNUInterrupt = 0,
  kCXX11GnuInterrupt = 1,
  kC2xGnuInterrupt = 2,
  kSpellingNotCalculated = 15,
};

enum class AnyX86NoCallerSavedRegistersAttrSpelling : unsigned int {
  kGNUNoCallerSavedRegisters = 0,
  kCXX11GnuNoCallerSavedRegisters = 1,
  kC2xGnuNoCallerSavedRegisters = 2,
  kSpellingNotCalculated = 15,
};

enum class AnyX86NoCfCheckAttrSpelling : unsigned int {
  kGNUNocfCheck = 0,
  kCXX11GnuNocfCheck = 1,
  kC2xGnuNocfCheck = 2,
  kSpellingNotCalculated = 15,
};

enum class ArcWeakrefUnavailableAttrSpelling : unsigned int {
  kGNUObjcArcWeakReferenceUnavailable = 0,
  kCXX11ClangObjcArcWeakReferenceUnavailable = 1,
  kC2xClangObjcArcWeakReferenceUnavailable = 2,
  kSpellingNotCalculated = 15,
};

enum class ArgumentWithTypeTagAttrSpelling : unsigned int {
  kGNUArgumentWithTypeTag = 0,
  kCXX11ClangArgumentWithTypeTag = 1,
  kC2xClangArgumentWithTypeTag = 2,
  kGNUPointerWithTypeTag = 3,
  kCXX11ClangPointerWithTypeTag = 4,
  kC2xClangPointerWithTypeTag = 5,
  kSpellingNotCalculated = 15,
};

enum class ArmBuiltinAliasAttrSpelling : unsigned int {
  kGNUClangArmBuiltinAlias = 0,
  kCXX11ClangClangArmBuiltinAlias = 1,
  kC2xClangClangArmBuiltinAlias = 2,
  kSpellingNotCalculated = 15,
};

enum class ArmMveStrictPolymorphismAttrSpelling : unsigned int {
  kGNUClangArmMveStrictPolymorphism = 0,
  kCXX11ClangClangArmMveStrictPolymorphism = 1,
  kC2xClangClangArmMveStrictPolymorphism = 2,
  kSpellingNotCalculated = 15,
};

enum class ArrayTypeArraySizeModifier : unsigned int {
  kNormal = 0,
  kStatic = 1,
  kStar = 2,
};

enum class ArtificialAttrSpelling : unsigned int {
  kGNUArtificial = 0,
  kCXX11GnuArtificial = 1,
  kC2xGnuArtificial = 2,
  kSpellingNotCalculated = 15,
};

enum class AsmLabelAttrSpelling : unsigned int {
  kKeywordAssembly = 0,
  kSpellingNotCalculated = 15,
};

enum class AssertCapabilityAttrSpelling : unsigned int {
  kGNUAssertCapability = 0,
  kCXX11ClangAssertCapability = 1,
  kGNUAssertSharedCapability = 2,
  kCXX11ClangAssertSharedCapability = 3,
  kSpellingNotCalculated = 15,
};

enum class AssumeAlignedAttrSpelling : unsigned int {
  kGNUAssumeAligned = 0,
  kCXX11GnuAssumeAligned = 1,
  kC2xGnuAssumeAligned = 2,
  kSpellingNotCalculated = 15,
};

enum class AssumptionAttrSpelling : unsigned int {
  kGNUAssume = 0,
  kCXX11ClangAssume = 1,
  kC2xClangAssume = 2,
  kSpellingNotCalculated = 15,
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
  kC11AtomicFetchNand = 11,
  kC11AtomicFetchMax = 12,
  kC11AtomicFetchMin = 13,
  kAtomicLoad = 14,
  kAtomicLoadN = 15,
  kAtomicStore = 16,
  kAtomicStoreN = 17,
  kAtomicExchange = 18,
  kAtomicExchangeN = 19,
  kAtomicCompareExchange = 20,
  kAtomicCompareExchangeN = 21,
  kAtomicFetchAdd = 22,
  kAtomicFetchSub = 23,
  kAtomicFetchAnd = 24,
  kAtomicFetchOr = 25,
  kAtomicFetchXor = 26,
  kAtomicFetchNand = 27,
  kAtomicAddFetch = 28,
  kAtomicSubFetch = 29,
  kAtomicAndFetch = 30,
  kAtomicOrFetch = 31,
  kAtomicXorFetch = 32,
  kAtomicMaxFetch = 33,
  kAtomicMinFetch = 34,
  kAtomicNandFetch = 35,
  kOpenclAtomicInitializer = 36,
  kOpenclAtomicLoad = 37,
  kOpenclAtomicStore = 38,
  kOpenclAtomicExchange = 39,
  kOpenclAtomicCompareExchangeStrong = 40,
  kOpenclAtomicCompareExchangeWeak = 41,
  kOpenclAtomicFetchAdd = 42,
  kOpenclAtomicFetchSub = 43,
  kOpenclAtomicFetchAnd = 44,
  kOpenclAtomicFetchOr = 45,
  kOpenclAtomicFetchXor = 46,
  kOpenclAtomicFetchMin = 47,
  kOpenclAtomicFetchMax = 48,
  kAtomicFetchMin = 49,
  kAtomicFetchMax = 50,
  kHipAtomicLoad = 51,
  kHipAtomicStore = 52,
  kHipAtomicCompareExchangeWeak = 53,
  kHipAtomicCompareExchangeStrong = 54,
  kHipAtomicExchange = 55,
  kHipAtomicFetchAdd = 56,
  kHipAtomicFetchAnd = 57,
  kHipAtomicFetchOr = 58,
  kHipAtomicFetchXor = 59,
  kHipAtomicFetchMin = 60,
  kHipAtomicFetchMax = 61,
};

enum class AvailabilityAttrSpelling : unsigned int {
  kGNUAvailability = 0,
  kCXX11ClangAvailability = 1,
  kC2xClangAvailability = 2,
  kSpellingNotCalculated = 15,
};

enum class BPFPreserveAccessIndexAttrSpelling : unsigned int {
  kGNUPreserveAccessIndex = 0,
  kCXX11ClangPreserveAccessIndex = 1,
  kC2xClangPreserveAccessIndex = 2,
  kSpellingNotCalculated = 15,
};

enum class BTFDeclTagAttrSpelling : unsigned int {
  kGNUBtfDeclarationTag = 0,
  kCXX11ClangBtfDeclarationTag = 1,
  kC2xClangBtfDeclarationTag = 2,
  kSpellingNotCalculated = 15,
};

enum class BTFTypeTagAttrSpelling : unsigned int {
  kGNUBtfTypeTag = 0,
  kCXX11ClangBtfTypeTag = 1,
  kC2xClangBtfTypeTag = 2,
  kSpellingNotCalculated = 15,
};

enum class BlocksAttrBlockType : unsigned int {
  kByReference = 0,
};

enum class BlocksAttrSpelling : unsigned int {
  kGNUBlocks = 0,
  kCXX11ClangBlocks = 1,
  kC2xClangBlocks = 2,
  kSpellingNotCalculated = 15,
};

enum class BuiltinAliasAttrSpelling : unsigned int {
  kCXX11ClangBuiltinAlias = 0,
  kC2xClangBuiltinAlias = 1,
  kGNUClangBuiltinAlias = 2,
  kSpellingNotCalculated = 15,
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
  kIbm128 = 217,
  kNullPointer = 218,
  kObjCId = 219,
  kObjCClass = 220,
  kObjCSel = 221,
  kOCLSampler = 222,
  kOCLEvent = 223,
  kOCLClkEvent = 224,
  kOCLQueue = 225,
  kOCLReserveID = 226,
  kDependent = 227,
  kOverload = 228,
  kBoundMember = 229,
  kPseudoObject = 230,
  kUnknownAny = 231,
  kBuiltinFn = 232,
  kARCUnbridgedCast = 233,
  kIncompleteMatrixIndex = 234,
  kOMPArraySection = 235,
  kOMPArrayShaping = 236,
  kOMPIterator = 237,
};

enum class CDeclAttrSpelling : unsigned int {
  kGNUCdecl = 0,
  kCXX11GnuCdecl = 1,
  kC2xGnuCdecl = 2,
  kKeywordCdecl = 3,
  kSpellingNotCalculated = 15,
};

enum class CFAuditedTransferAttrSpelling : unsigned int {
  kGNUCfAuditedTransfer = 0,
  kCXX11ClangCfAuditedTransfer = 1,
  kC2xClangCfAuditedTransfer = 2,
  kSpellingNotCalculated = 15,
};

enum class CFConsumedAttrSpelling : unsigned int {
  kGNUCfConsumed = 0,
  kCXX11ClangCfConsumed = 1,
  kC2xClangCfConsumed = 2,
  kSpellingNotCalculated = 15,
};

enum class CFGuardAttrGuardArg : unsigned int {
  kNocf = 0,
};

enum class CFICanonicalJumpTableAttrSpelling : unsigned int {
  kGNUCfiCanonicalJumpTable = 0,
  kCXX11ClangCfiCanonicalJumpTable = 1,
  kC2xClangCfiCanonicalJumpTable = 2,
  kSpellingNotCalculated = 15,
};

enum class CFReturnsNotRetainedAttrSpelling : unsigned int {
  kGNUCfReturnsNotRetained = 0,
  kCXX11ClangCfReturnsNotRetained = 1,
  kC2xClangCfReturnsNotRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class CFReturnsRetainedAttrSpelling : unsigned int {
  kGNUCfReturnsRetained = 0,
  kCXX11ClangCfReturnsRetained = 1,
  kC2xClangCfReturnsRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class CFUnknownTransferAttrSpelling : unsigned int {
  kGNUCfUnknownTransfer = 0,
  kCXX11ClangCfUnknownTransfer = 1,
  kC2xClangCfUnknownTransfer = 2,
  kSpellingNotCalculated = 15,
};

enum class CPUDispatchAttrSpelling : unsigned int {
  kGNUCpuDispatch = 0,
  kCXX11ClangCpuDispatch = 1,
  kC2xClangCpuDispatch = 2,
  kDeclspecCpuDispatch = 3,
  kSpellingNotCalculated = 15,
};

enum class CPUSpecificAttrSpelling : unsigned int {
  kGNUCpuSpecific = 0,
  kCXX11ClangCpuSpecific = 1,
  kC2xClangCpuSpecific = 2,
  kDeclspecCpuSpecific = 3,
  kSpellingNotCalculated = 15,
};

enum class CUDAConstantAttrSpelling : unsigned int {
  kGNUConstant = 0,
  kDeclspecConstant = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDADeviceAttrSpelling : unsigned int {
  kGNUDevice = 0,
  kDeclspecDevice = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDADeviceBuiltinSurfaceTypeAttrSpelling : unsigned int {
  kGNUDeviceBuiltinSurfaceType = 0,
  kDeclspecDeviceBuiltinSurfaceType = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDADeviceBuiltinTextureTypeAttrSpelling : unsigned int {
  kGNUDeviceBuiltinTextureType = 0,
  kDeclspecDeviceBuiltinTextureType = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDAGlobalAttrSpelling : unsigned int {
  kGNUGlobal = 0,
  kDeclspecGlobal = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDAHostAttrSpelling : unsigned int {
  kGNUHost = 0,
  kDeclspecHost = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDALaunchBoundsAttrSpelling : unsigned int {
  kGNULaunchBounds = 0,
  kDeclspecLaunchBounds = 1,
  kSpellingNotCalculated = 15,
};

enum class CUDASharedAttrSpelling : unsigned int {
  kGNUShared = 0,
  kDeclspecShared = 1,
  kSpellingNotCalculated = 15,
};

enum class CXX11NoReturnAttrSpelling : unsigned int {
  kCXX11Noreturn = 0,
  kC2xnoreturn = 1,
  kC2xNoreturn = 2,
  kSpellingNotCalculated = 15,
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

enum class CXXRecordDeclLambdaDependencyKind : unsigned int {
  kUnknown = 0,
  kAlwaysDependent = 1,
  kNeverDependent = 2,
};

enum class CallExprADLCallKind : bool {
  kNotADL = 0,
  kUsesADL = 1,
};

enum class CallableWhenAttrConsumedState : unsigned int {
  kUnknown = 0,
  kConsumed = 1,
  kUnconsumed = 2,
};

enum class CallableWhenAttrSpelling : unsigned int {
  kGNUCallableWhen = 0,
  kCXX11ClangCallableWhen = 1,
  kSpellingNotCalculated = 15,
};

enum class CallbackAttrSpelling : unsigned int {
  kGNUCallback = 0,
  kCXX11ClangCallback = 1,
  kC2xClangCallback = 2,
  kSpellingNotCalculated = 15,
};

enum class CalledOnceAttrSpelling : unsigned int {
  kGNUCalledOnce = 0,
  kCXX11ClangCalledOnce = 1,
  kC2xClangCalledOnce = 2,
  kSpellingNotCalculated = 15,
};

enum class CapabilityAttrSpelling : unsigned int {
  kGNUCapability = 0,
  kCXX11ClangCapability = 1,
  kGNUSharedCapability = 2,
  kCXX11ClangSharedCapability = 3,
  kSpellingNotCalculated = 15,
};

enum class CapturedStmtVariableCaptureKind : unsigned int {
  kThis = 0,
  kByReference = 1,
  kByCopy = 2,
  kVLAType = 3,
};

enum class CarriesDependencyAttrSpelling : unsigned int {
  kGNUCarriesDependency = 0,
  kCXX11CarriesDependency = 1,
  kSpellingNotCalculated = 15,
};

enum class CharacterLiteralCharacterKind : unsigned int {
  kAscii = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class CleanupAttrSpelling : unsigned int {
  kGNUCleanup = 0,
  kCXX11GnuCleanup = 1,
  kC2xGnuCleanup = 2,
  kSpellingNotCalculated = 15,
};

enum class ColdAttrSpelling : unsigned int {
  kGNUCold = 0,
  kCXX11GnuCold = 1,
  kC2xGnuCold = 2,
  kSpellingNotCalculated = 15,
};

enum class CommonAttrSpelling : unsigned int {
  kGNUCommon = 0,
  kCXX11GnuCommon = 1,
  kC2xGnuCommon = 2,
  kSpellingNotCalculated = 15,
};

enum class ConstAttrSpelling : unsigned int {
  kGNUConst = 0,
  kCXX11GnuConst = 1,
  kC2xGnuConst = 2,
  kSpellingNotCalculated = 15,
};

enum class ConstInitAttrSpelling : unsigned int {
  kKeywordConstinit = 0,
  kGNURequireConstantInitialization = 1,
  kCXX11ClangRequireConstantInitialization = 2,
  kSpellingNotCalculated = 15,
};

enum class ConstantExprResultStorageKind : unsigned int {
  kNone = 0,
  kInt64 = 1,
  kAPValue = 2,
};

enum class ConstructorAttrSpelling : unsigned int {
  kGNUConstructor = 0,
  kCXX11GnuConstructor = 1,
  kC2xGnuConstructor = 2,
  kSpellingNotCalculated = 15,
};

enum class ConsumableAttrConsumedState : unsigned int {
  kUnknown = 0,
  kConsumed = 1,
  kUnconsumed = 2,
};

enum class ConsumableAttrSpelling : unsigned int {
  kGNUConsumable = 0,
  kCXX11ClangConsumable = 1,
  kSpellingNotCalculated = 15,
};

enum class ConsumableAutoCastAttrSpelling : unsigned int {
  kGNUConsumableAutoCastState = 0,
  kCXX11ClangConsumableAutoCastState = 1,
  kSpellingNotCalculated = 15,
};

enum class ConsumableSetOnReadAttrSpelling : unsigned int {
  kGNUConsumableStateOnRead = 0,
  kCXX11ClangConsumableStateOnRead = 1,
  kSpellingNotCalculated = 15,
};

enum class ConvergentAttrSpelling : unsigned int {
  kGNUConvergent = 0,
  kCXX11ClangConvergent = 1,
  kC2xClangConvergent = 2,
  kSpellingNotCalculated = 15,
};

enum class DLLExportAttrSpelling : unsigned int {
  kDeclspecDllexport = 0,
  kGNUDllexport = 1,
  kCXX11GnuDllexport = 2,
  kC2xGnuDllexport = 3,
  kSpellingNotCalculated = 15,
};

enum class DLLImportAttrSpelling : unsigned int {
  kDeclspecDllimport = 0,
  kGNUDllimport = 1,
  kCXX11GnuDllimport = 2,
  kC2xGnuDllimport = 3,
  kSpellingNotCalculated = 15,
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
  kReachableWhenImported = 3,
  kModulePrivate = 4,
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

enum class DeprecatedAttrSpelling : unsigned int {
  kGNUDeprecated = 0,
  kCXX11GnuDeprecated = 1,
  kC2xGnuDeprecated = 2,
  kDeclspecDeprecated = 3,
  kCXX11Deprecated = 4,
  kC2xDeprecated = 5,
  kSpellingNotCalculated = 15,
};

enum class DestructorAttrSpelling : unsigned int {
  kGNUDestructor = 0,
  kCXX11GnuDestructor = 1,
  kC2xGnuDestructor = 2,
  kSpellingNotCalculated = 15,
};

enum class DiagnoseAsBuiltinAttrSpelling : unsigned int {
  kGNUDiagnoseAsBuiltin = 0,
  kCXX11ClangDiagnoseAsBuiltin = 1,
  kC2xClangDiagnoseAsBuiltin = 2,
  kSpellingNotCalculated = 15,
};

enum class DiagnoseIfAttrDiagnosticType : unsigned int {
  kError = 0,
  kWarning = 1,
};

enum class DisableSanitizerInstrumentationAttrSpelling : unsigned int {
  kGNUDisableSanitizerInstrumentation = 0,
  kCXX11ClangDisableSanitizerInstrumentation = 1,
  kC2xClangDisableSanitizerInstrumentation = 2,
  kSpellingNotCalculated = 15,
};

enum class DisableTailCallsAttrSpelling : unsigned int {
  kGNUDisableTailCalls = 0,
  kCXX11ClangDisableTailCalls = 1,
  kC2xClangDisableTailCalls = 2,
  kSpellingNotCalculated = 15,
};

enum class EnforceTCBAttrSpelling : unsigned int {
  kGNUEnforceTcb = 0,
  kCXX11ClangEnforceTcb = 1,
  kC2xClangEnforceTcb = 2,
  kSpellingNotCalculated = 15,
};

enum class EnforceTCBLeafAttrSpelling : unsigned int {
  kGNUEnforceTcbLeaf = 0,
  kCXX11ClangEnforceTcbLeaf = 1,
  kC2xClangEnforceTcbLeaf = 2,
  kSpellingNotCalculated = 15,
};

enum class EnumExtensibilityAttrKind : unsigned int {
  kClosed = 0,
  kOpen = 1,
};

enum class EnumExtensibilityAttrSpelling : unsigned int {
  kGNUEnumExtensibility = 0,
  kCXX11ClangEnumExtensibility = 1,
  kC2xClangEnumExtensibility = 2,
  kSpellingNotCalculated = 15,
};

enum class ErrorAttrSpelling : unsigned int {
  kGNUError = 0,
  kCXX11GnuError = 1,
  kC2xGnuError = 2,
  kGNUWarning = 3,
  kCXX11GnuWarning = 4,
  kC2xGnuWarning = 5,
  kSpellingNotCalculated = 15,
};

enum class ExcludeFromExplicitInstantiationAttrSpelling : unsigned int {
  kGNUExcludeFromExplicitInstantiation = 0,
  kCXX11ClangExcludeFromExplicitInstantiation = 1,
  kC2xClangExcludeFromExplicitInstantiation = 2,
  kSpellingNotCalculated = 15,
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
  kConstAddressSpace = 9,
  kArrayType = 10,
  kNoSetterProperty = 11,
  kMemberFunction = 12,
  kSubObjCPropertySetting = 13,
  kInvalidMessageExpression = 14,
  kClassTemporary = 15,
  kArrayTemporary = 16,
};

enum class ExternalSourceSymbolAttrSpelling : unsigned int {
  kGNUExternalSourceSymbol = 0,
  kCXX11ClangExternalSourceSymbol = 1,
  kC2xClangExternalSourceSymbol = 2,
  kSpellingNotCalculated = 15,
};

enum class FallThroughAttrSpelling : unsigned int {
  kCXX11Fallthrough = 0,
  kC2xFallthrough = 1,
  kCXX11ClangFallthrough = 2,
  kGNUFallthrough = 3,
  kCXX11GnuFallthrough = 4,
  kC2xGnuFallthrough = 5,
  kSpellingNotCalculated = 15,
};

enum class FastCallAttrSpelling : unsigned int {
  kGNUFastcall = 0,
  kCXX11GnuFastcall = 1,
  kC2xGnuFastcall = 2,
  kKeywordFastcall = 3,
  kSpellingNotCalculated = 15,
};

enum class FinalAttrSpelling : unsigned int {
  kKeywordFinal = 0,
  kKeywordSealed = 1,
  kSpellingNotCalculated = 15,
};

enum class FlagEnumAttrSpelling : unsigned int {
  kGNUFlagEnum = 0,
  kCXX11ClangFlagEnum = 1,
  kC2xClangFlagEnum = 2,
  kSpellingNotCalculated = 15,
};

enum class FlattenAttrSpelling : unsigned int {
  kGNUFlatten = 0,
  kCXX11GnuFlatten = 1,
  kC2xGnuFlatten = 2,
  kSpellingNotCalculated = 15,
};

enum class FormatArgAttrSpelling : unsigned int {
  kGNUFormatArgument = 0,
  kCXX11GnuFormatArgument = 1,
  kC2xGnuFormatArgument = 2,
  kSpellingNotCalculated = 15,
};

enum class FormatAttrSpelling : unsigned int {
  kGNUFormat = 0,
  kCXX11GnuFormat = 1,
  kC2xGnuFormat = 2,
  kSpellingNotCalculated = 15,
};

enum class FunctionDeclTemplatedKind : unsigned int {
  kNonTemplate = 0,
  kFunctionTemplate = 1,
  kMemberSpecialization = 2,
  kFunctionTemplateSpecialization = 3,
  kDependentFunctionTemplateSpecialization = 4,
  kDependentNonTemplate = 5,
};

enum class FunctionReturnThunksAttrKind : unsigned int {
  kKeep = 0,
  kExtern = 1,
};

enum class FunctionReturnThunksAttrSpelling : unsigned int {
  kGNUFunctionReturn = 0,
  kCXX11GnuFunctionReturn = 1,
  kC2xGnuFunctionReturn = 2,
  kSpellingNotCalculated = 15,
};

enum class GNUInlineAttrSpelling : unsigned int {
  kGNUGnuInline = 0,
  kCXX11GnuGnuInline = 1,
  kC2xGnuGnuInline = 2,
  kSpellingNotCalculated = 15,
};

enum class GuardedVarAttrSpelling : unsigned int {
  kGNUGuardedVariable = 0,
  kCXX11ClangGuardedVariable = 1,
  kSpellingNotCalculated = 15,
};

enum class HIPManagedAttrSpelling : unsigned int {
  kGNUManaged = 0,
  kDeclspecManaged = 1,
  kSpellingNotCalculated = 15,
};

enum class HLSLShaderAttrShaderType : unsigned int {
  kPixel = 0,
  kVertex = 1,
  kGeometry = 2,
  kHull = 3,
  kDomain = 4,
  kCompute = 5,
  kRayGeneration = 6,
  kIntersection = 7,
  kAnyHit = 8,
  kClosestHit = 9,
  kMiss = 10,
  kCallable = 11,
  kMesh = 12,
  kAmplification = 13,
};

enum class HotAttrSpelling : unsigned int {
  kGNUHot = 0,
  kCXX11GnuHot = 1,
  kC2xGnuHot = 2,
  kSpellingNotCalculated = 15,
};

enum class IBActionAttrSpelling : unsigned int {
  kGNUIbaction = 0,
  kCXX11ClangIbaction = 1,
  kC2xClangIbaction = 2,
  kSpellingNotCalculated = 15,
};

enum class IBOutletAttrSpelling : unsigned int {
  kGNUIboutlet = 0,
  kCXX11ClangIboutlet = 1,
  kC2xClangIboutlet = 2,
  kSpellingNotCalculated = 15,
};

enum class IBOutletCollectionAttrSpelling : unsigned int {
  kGNUIboutletcollection = 0,
  kCXX11ClangIboutletcollection = 1,
  kC2xClangIboutletcollection = 2,
  kSpellingNotCalculated = 15,
};

enum class IFuncAttrSpelling : unsigned int {
  kGNUIfunc = 0,
  kCXX11GnuIfunc = 1,
  kC2xGnuIfunc = 2,
  kSpellingNotCalculated = 15,
};

enum class ImplicitCastExprOnStack : unsigned int {
  kOnStack = 0,
};

enum class ImplicitParamDeclImplicitParamKind : unsigned int {
  kObjCSelf = 0,
  kObjCCmd = 1,
  kCXXThis = 2,
  kCXXVTT = 3,
  kCapturedContext = 4,
  kThreadPrivateVariable = 5,
  kOther = 6,
};

enum class InitPriorityAttrSpelling : unsigned int {
  kGNUInitializerPriority = 0,
  kCXX11GnuInitializerPriority = 1,
  kSpellingNotCalculated = 15,
};

enum class IntelOclBiccAttrSpelling : unsigned int {
  kGNUIntelOclBicc = 0,
  kCXX11ClangIntelOclBicc = 1,
  kSpellingNotCalculated = 15,
};

enum class InternalLinkageAttrSpelling : unsigned int {
  kGNUInternalLinkage = 0,
  kCXX11ClangInternalLinkage = 1,
  kC2xClangInternalLinkage = 2,
  kSpellingNotCalculated = 15,
};

enum class LTOVisibilityPublicAttrSpelling : unsigned int {
  kGNULtoVisibilityPublic = 0,
  kCXX11ClangLtoVisibilityPublic = 1,
  kC2xClangLtoVisibilityPublic = 2,
  kSpellingNotCalculated = 15,
};

enum class LeafAttrSpelling : unsigned int {
  kGNULeaf = 0,
  kCXX11GnuLeaf = 1,
  kC2xGnuLeaf = 2,
  kSpellingNotCalculated = 15,
};

enum class LifetimeBoundAttrSpelling : unsigned int {
  kGNULifetimebound = 0,
  kCXX11ClangLifetimebound = 1,
  kSpellingNotCalculated = 15,
};

enum class LikelyAttrSpelling : unsigned int {
  kCXX11Likely = 0,
  kC2xClangLikely = 1,
  kSpellingNotCalculated = 15,
};

enum class LinkageSpecDeclLanguageIDs : unsigned int {
  kC = 1,
  kCxx = 2,
};

enum class LoaderUninitializedAttrSpelling : unsigned int {
  kGNULoaderUninitialized = 0,
  kCXX11ClangLoaderUninitialized = 1,
  kC2xClangLoaderUninitialized = 2,
  kSpellingNotCalculated = 15,
};

enum class LoopHintAttrLoopHintState : unsigned int {
  kEnable = 0,
  kDisable = 1,
  kNumeric = 2,
  kFixedWidth = 3,
  kScalableWidth = 4,
  kAssumeSafety = 5,
  kFull = 6,
};

enum class LoopHintAttrOptionType : unsigned int {
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

enum class LoopHintAttrSpelling : unsigned int {
  kPragmaClangLoop = 0,
  kPragmaUnroll = 1,
  kPragmaNounroll = 2,
  kPragmaUnrollAndJam = 3,
  kPragmaNounrollAndJam = 4,
  kSpellingNotCalculated = 15,
};

enum class MIGServerRoutineAttrSpelling : unsigned int {
  kGNUMigServerRoutine = 0,
  kCXX11ClangMigServerRoutine = 1,
  kC2xClangMigServerRoutine = 2,
  kSpellingNotCalculated = 15,
};

enum class MSABIAttrSpelling : unsigned int {
  kGNUMsAbi = 0,
  kCXX11GnuMsAbi = 1,
  kC2xGnuMsAbi = 2,
  kSpellingNotCalculated = 15,
};

enum class MSInheritanceAttrSpelling : unsigned int {
  kKeywordSingleInheritance = 0,
  kKeywordMultipleInheritance = 1,
  kKeywordVirtualInheritance = 2,
  kKeywordUnspecifiedInheritance = 3,
  kSpellingNotCalculated = 15,
};

enum class MSP430InterruptAttrSpelling : unsigned int {
  kGNUInterrupt = 0,
  kCXX11GnuInterrupt = 1,
  kC2xGnuInterrupt = 2,
  kSpellingNotCalculated = 15,
};

enum class MSStructAttrSpelling : unsigned int {
  kGNUMsStruct = 0,
  kCXX11GnuMsStruct = 1,
  kC2xGnuMsStruct = 2,
  kSpellingNotCalculated = 15,
};

enum class MayAliasAttrSpelling : unsigned int {
  kGNUMayAlias = 0,
  kCXX11GnuMayAlias = 1,
  kC2xGnuMayAlias = 2,
  kSpellingNotCalculated = 15,
};

enum class MicroMipsAttrSpelling : unsigned int {
  kGNUMicromips = 0,
  kCXX11GnuMicromips = 1,
  kC2xGnuMicromips = 2,
  kSpellingNotCalculated = 15,
};

enum class MinSizeAttrSpelling : unsigned int {
  kGNUMinsize = 0,
  kCXX11ClangMinsize = 1,
  kC2xClangMinsize = 2,
  kSpellingNotCalculated = 15,
};

enum class MinVectorWidthAttrSpelling : unsigned int {
  kGNUMinVectorWidth = 0,
  kCXX11ClangMinVectorWidth = 1,
  kC2xClangMinVectorWidth = 2,
  kSpellingNotCalculated = 15,
};

enum class Mips16AttrSpelling : unsigned int {
  kGNUMips16 = 0,
  kCXX11GnuMips16 = 1,
  kC2xGnuMips16 = 2,
  kSpellingNotCalculated = 15,
};

enum class MipsInterruptAttrInterruptType : unsigned int {
  kSw0 = 0,
  kSw1 = 1,
  kHw0 = 2,
  kHw1 = 3,
  kHw2 = 4,
  kHw3 = 5,
  kHw4 = 6,
  kHw5 = 7,
  kEic = 8,
};

enum class MipsInterruptAttrSpelling : unsigned int {
  kGNUInterrupt = 0,
  kCXX11GnuInterrupt = 1,
  kC2xGnuInterrupt = 2,
  kSpellingNotCalculated = 15,
};

enum class MipsLongCallAttrSpelling : unsigned int {
  kGNULongCall = 0,
  kCXX11GnuLongCall = 1,
  kC2xGnuLongCall = 2,
  kGNUFar = 3,
  kCXX11GnuFar = 4,
  kC2xGnuFar = 5,
  kSpellingNotCalculated = 15,
};

enum class MipsShortCallAttrSpelling : unsigned int {
  kGNUShortCall = 0,
  kCXX11GnuShortCall = 1,
  kC2xGnuShortCall = 2,
  kGNUNear = 3,
  kCXX11GnuNear = 4,
  kC2xGnuNear = 5,
  kSpellingNotCalculated = 15,
};

enum class ModeAttrSpelling : unsigned int {
  kGNUMode = 0,
  kCXX11GnuMode = 1,
  kC2xGnuMode = 2,
  kSpellingNotCalculated = 15,
};

enum class MustTailAttrSpelling : unsigned int {
  kGNUMusttail = 0,
  kCXX11ClangMusttail = 1,
  kC2xClangMusttail = 2,
  kSpellingNotCalculated = 15,
};

enum class NSConsumedAttrSpelling : unsigned int {
  kGNUNsConsumed = 0,
  kCXX11ClangNsConsumed = 1,
  kC2xClangNsConsumed = 2,
  kSpellingNotCalculated = 15,
};

enum class NSConsumesSelfAttrSpelling : unsigned int {
  kGNUNsConsumesSelf = 0,
  kCXX11ClangNsConsumesSelf = 1,
  kC2xClangNsConsumesSelf = 2,
  kSpellingNotCalculated = 15,
};

enum class NSReturnsAutoreleasedAttrSpelling : unsigned int {
  kGNUNsReturnsAutoreleased = 0,
  kCXX11ClangNsReturnsAutoreleased = 1,
  kC2xClangNsReturnsAutoreleased = 2,
  kSpellingNotCalculated = 15,
};

enum class NSReturnsNotRetainedAttrSpelling : unsigned int {
  kGNUNsReturnsNotRetained = 0,
  kCXX11ClangNsReturnsNotRetained = 1,
  kC2xClangNsReturnsNotRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class NSReturnsRetainedAttrSpelling : unsigned int {
  kGNUNsReturnsRetained = 0,
  kCXX11ClangNsReturnsRetained = 1,
  kC2xClangNsReturnsRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class NakedAttrSpelling : unsigned int {
  kGNUNaked = 0,
  kCXX11GnuNaked = 1,
  kC2xGnuNaked = 2,
  kDeclspecNaked = 3,
  kSpellingNotCalculated = 15,
};

enum class NamedDeclExplicitVisibilityKind : unsigned int {
  kVisibilityForType = 0,
  kVisibilityForValue = 1,
};

enum class NoBuiltinAttrSpelling : unsigned int {
  kGNUNoBuiltin = 0,
  kCXX11ClangNoBuiltin = 1,
  kC2xClangNoBuiltin = 2,
  kSpellingNotCalculated = 15,
};

enum class NoCommonAttrSpelling : unsigned int {
  kGNUNocommon = 0,
  kCXX11GnuNocommon = 1,
  kC2xGnuNocommon = 2,
  kSpellingNotCalculated = 15,
};

enum class NoDebugAttrSpelling : unsigned int {
  kGNUNodebug = 0,
  kCXX11GnuNodebug = 1,
  kC2xGnuNodebug = 2,
  kSpellingNotCalculated = 15,
};

enum class NoDerefAttrSpelling : unsigned int {
  kGNUNoderef = 0,
  kCXX11ClangNoderef = 1,
  kC2xClangNoderef = 2,
  kSpellingNotCalculated = 15,
};

enum class NoDestroyAttrSpelling : unsigned int {
  kGNUNoDestroy = 0,
  kCXX11ClangNoDestroy = 1,
  kSpellingNotCalculated = 15,
};

enum class NoDuplicateAttrSpelling : unsigned int {
  kGNUNoduplicate = 0,
  kCXX11ClangNoduplicate = 1,
  kC2xClangNoduplicate = 2,
  kSpellingNotCalculated = 15,
};

enum class NoEscapeAttrSpelling : unsigned int {
  kGNUNoescape = 0,
  kCXX11ClangNoescape = 1,
  kC2xClangNoescape = 2,
  kSpellingNotCalculated = 15,
};

enum class NoInlineAttrSpelling : unsigned int {
  kKeywordNoinline = 0,
  kGNUNoinline = 1,
  kCXX11GnuNoinline = 2,
  kC2xGnuNoinline = 3,
  kCXX11ClangNoinline = 4,
  kC2xClangNoinline = 5,
  kDeclspecNoinline = 6,
  kSpellingNotCalculated = 15,
};

enum class NoInstrumentFunctionAttrSpelling : unsigned int {
  kGNUNoInstrumentFunction = 0,
  kCXX11GnuNoInstrumentFunction = 1,
  kC2xGnuNoInstrumentFunction = 2,
  kSpellingNotCalculated = 15,
};

enum class NoMergeAttrSpelling : unsigned int {
  kGNUNomerge = 0,
  kCXX11ClangNomerge = 1,
  kC2xClangNomerge = 2,
  kSpellingNotCalculated = 15,
};

enum class NoMicroMipsAttrSpelling : unsigned int {
  kGNUNomicromips = 0,
  kCXX11GnuNomicromips = 1,
  kC2xGnuNomicromips = 2,
  kSpellingNotCalculated = 15,
};

enum class NoMips16AttrSpelling : unsigned int {
  kGNUNomips16 = 0,
  kCXX11GnuNomips16 = 1,
  kC2xGnuNomips16 = 2,
  kSpellingNotCalculated = 15,
};

enum class NoProfileFunctionAttrSpelling : unsigned int {
  kGNUNoProfileInstrumentFunction = 0,
  kCXX11GnuNoProfileInstrumentFunction = 1,
  kC2xGnuNoProfileInstrumentFunction = 2,
  kSpellingNotCalculated = 15,
};

enum class NoRandomizeLayoutAttrSpelling : unsigned int {
  kGNUNoRandomizeLayout = 0,
  kCXX11GnuNoRandomizeLayout = 1,
  kC2xGnuNoRandomizeLayout = 2,
  kSpellingNotCalculated = 15,
};

enum class NoReturnAttrSpelling : unsigned int {
  kGNUNoreturn = 0,
  kCXX11GnuNoreturn = 1,
  kC2xGnuNoreturn = 2,
  kDeclspecNoreturn = 3,
  kSpellingNotCalculated = 15,
};

enum class NoSanitizeAttrSpelling : unsigned int {
  kGNUNoSanitize = 0,
  kCXX11ClangNoSanitize = 1,
  kC2xClangNoSanitize = 2,
  kSpellingNotCalculated = 15,
};

enum class NoSpeculativeLoadHardeningAttrSpelling : unsigned int {
  kGNUNoSpeculativeLoadHardening = 0,
  kCXX11ClangNoSpeculativeLoadHardening = 1,
  kC2xClangNoSpeculativeLoadHardening = 2,
  kSpellingNotCalculated = 15,
};

enum class NoSplitStackAttrSpelling : unsigned int {
  kGNUNoSplitStack = 0,
  kCXX11GnuNoSplitStack = 1,
  kC2xGnuNoSplitStack = 2,
  kSpellingNotCalculated = 15,
};

enum class NoStackProtectorAttrSpelling : unsigned int {
  kGNUNoStackProtector = 0,
  kCXX11ClangNoStackProtector = 1,
  kC2xClangNoStackProtector = 2,
  kSpellingNotCalculated = 15,
};

enum class NoThreadSafetyAnalysisAttrSpelling : unsigned int {
  kGNUNoThreadSafetyAnalysis = 0,
  kCXX11ClangNoThreadSafetyAnalysis = 1,
  kC2xClangNoThreadSafetyAnalysis = 2,
  kSpellingNotCalculated = 15,
};

enum class NoThrowAttrSpelling : unsigned int {
  kGNUNothrow = 0,
  kCXX11GnuNothrow = 1,
  kC2xGnuNothrow = 2,
  kDeclspecNothrow = 3,
  kSpellingNotCalculated = 15,
};

enum class NonNullAttrSpelling : unsigned int {
  kGNUNonnull = 0,
  kCXX11GnuNonnull = 1,
  kC2xGnuNonnull = 2,
  kSpellingNotCalculated = 15,
};

enum class NotTailCalledAttrSpelling : unsigned int {
  kGNUNotTailCalled = 0,
  kCXX11ClangNotTailCalled = 1,
  kC2xClangNotTailCalled = 2,
  kSpellingNotCalculated = 15,
};

enum class OMPAllocateDeclAttrAllocatorTypeTy : unsigned int {
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

enum class OMPDeclareReductionDeclInitKind : unsigned int {
  kCallInitializer = 0,
  kDirectInitializer = 1,
  kCopyInitializer = 2,
};

enum class OMPDeclareSimdDeclAttrBranchStateTy : unsigned int {
  kUndefined = 0,
  kInbranch = 1,
  kNotinbranch = 2,
};

enum class OMPDeclareTargetDeclAttrDevTypeTy : unsigned int {
  kHost = 0,
  kNoHost = 1,
  kAny = 2,
};

enum class OMPDeclareTargetDeclAttrMapTypeTy : unsigned int {
  kTo = 0,
  kLink = 1,
};

enum class OMPDeclareVariantAttrInteropType : unsigned int {
  kTarget = 0,
  kTargetSync = 1,
  kTargetTargetSync = 2,
};

enum class OSConsumedAttrSpelling : unsigned int {
  kGNUOsConsumed = 0,
  kCXX11ClangOsConsumed = 1,
  kC2xClangOsConsumed = 2,
  kSpellingNotCalculated = 15,
};

enum class OSConsumesThisAttrSpelling : unsigned int {
  kGNUOsConsumesThis = 0,
  kCXX11ClangOsConsumesThis = 1,
  kC2xClangOsConsumesThis = 2,
  kSpellingNotCalculated = 15,
};

enum class OSReturnsNotRetainedAttrSpelling : unsigned int {
  kGNUOsReturnsNotRetained = 0,
  kCXX11ClangOsReturnsNotRetained = 1,
  kC2xClangOsReturnsNotRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class OSReturnsRetainedAttrSpelling : unsigned int {
  kGNUOsReturnsRetained = 0,
  kCXX11ClangOsReturnsRetained = 1,
  kC2xClangOsReturnsRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class OSReturnsRetainedOnNonZeroAttrSpelling : unsigned int {
  kGNUOsReturnsRetainedOnNonZero = 0,
  kCXX11ClangOsReturnsRetainedOnNonZero = 1,
  kC2xClangOsReturnsRetainedOnNonZero = 2,
  kSpellingNotCalculated = 15,
};

enum class OSReturnsRetainedOnZeroAttrSpelling : unsigned int {
  kGNUOsReturnsRetainedOnZero = 0,
  kCXX11ClangOsReturnsRetainedOnZero = 1,
  kC2xClangOsReturnsRetainedOnZero = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCBoxableAttrSpelling : unsigned int {
  kGNUObjcBoxable = 0,
  kCXX11ClangObjcBoxable = 1,
  kC2xClangObjcBoxable = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCBridgeAttrSpelling : unsigned int {
  kGNUObjcBridge = 0,
  kCXX11ClangObjcBridge = 1,
  kC2xClangObjcBridge = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCBridgeMutableAttrSpelling : unsigned int {
  kGNUObjcBridgeMutable = 0,
  kCXX11ClangObjcBridgeMutable = 1,
  kC2xClangObjcBridgeMutable = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCBridgeRelatedAttrSpelling : unsigned int {
  kGNUObjcBridgeRelated = 0,
  kCXX11ClangObjcBridgeRelated = 1,
  kC2xClangObjcBridgeRelated = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCClassStubAttrSpelling : unsigned int {
  kGNUObjcClassStub = 0,
  kCXX11ClangObjcClassStub = 1,
  kC2xClangObjcClassStub = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCDesignatedInitializerAttrSpelling : unsigned int {
  kGNUObjcDesignatedInitializer = 0,
  kCXX11ClangObjcDesignatedInitializer = 1,
  kC2xClangObjcDesignatedInitializer = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCDirectAttrSpelling : unsigned int {
  kGNUObjcDirect = 0,
  kCXX11ClangObjcDirect = 1,
  kC2xClangObjcDirect = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCDirectMembersAttrSpelling : unsigned int {
  kGNUObjcDirectMembers = 0,
  kCXX11ClangObjcDirectMembers = 1,
  kC2xClangObjcDirectMembers = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCExceptionAttrSpelling : unsigned int {
  kGNUObjcException = 0,
  kCXX11ClangObjcException = 1,
  kC2xClangObjcException = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCExplicitProtocolImplAttrSpelling : unsigned int {
  kGNUObjcProtocolRequiresExplicitImplementation = 0,
  kCXX11ClangObjcProtocolRequiresExplicitImplementation = 1,
  kC2xClangObjcProtocolRequiresExplicitImplementation = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCExternallyRetainedAttrSpelling : unsigned int {
  kGNUObjcExternallyRetained = 0,
  kCXX11ClangObjcExternallyRetained = 1,
  kC2xClangObjcExternallyRetained = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCGCAttrSpelling : unsigned int {
  kGNUObjcGc = 0,
  kCXX11ClangObjcGc = 1,
  kC2xClangObjcGc = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCIndependentClassAttrSpelling : unsigned int {
  kGNUObjcIndependentClass = 0,
  kCXX11ClangObjcIndependentClass = 1,
  kC2xClangObjcIndependentClass = 2,
  kSpellingNotCalculated = 15,
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

enum class ObjCMethodFamilyAttrFamilyKind : unsigned int {
  kNone = 0,
  kAlloc = 1,
  kCopy = 2,
  kInitializer = 3,
  kMutableCopy = 4,
  kNew = 5,
};

enum class ObjCMethodFamilyAttrSpelling : unsigned int {
  kGNUObjcMethodFamily = 0,
  kCXX11ClangObjcMethodFamily = 1,
  kC2xClangObjcMethodFamily = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCNSObjectAttrSpelling : unsigned int {
  kGNUNSObject = 0,
  kCXX11ClangNSObject = 1,
  kC2xClangNSObject = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCNonLazyClassAttrSpelling : unsigned int {
  kGNUObjcNonlazyClass = 0,
  kCXX11ClangObjcNonlazyClass = 1,
  kC2xClangObjcNonlazyClass = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCNonRuntimeProtocolAttrSpelling : unsigned int {
  kGNUObjcNonRuntimeProtocol = 0,
  kCXX11ClangObjcNonRuntimeProtocol = 1,
  kC2xClangObjcNonRuntimeProtocol = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCOwnershipAttrSpelling : unsigned int {
  kGNUObjcOwnership = 0,
  kCXX11ClangObjcOwnership = 1,
  kC2xClangObjcOwnership = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCPreciseLifetimeAttrSpelling : unsigned int {
  kGNUObjcPreciseLifetime = 0,
  kCXX11ClangObjcPreciseLifetime = 1,
  kC2xClangObjcPreciseLifetime = 2,
  kSpellingNotCalculated = 15,
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

enum class ObjCRequiresPropertyDefsAttrSpelling : unsigned int {
  kGNUObjcRequiresPropertyDefinitions = 0,
  kCXX11ClangObjcRequiresPropertyDefinitions = 1,
  kC2xClangObjcRequiresPropertyDefinitions = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCRequiresSuperAttrSpelling : unsigned int {
  kGNUObjcRequiresSuper = 0,
  kCXX11ClangObjcRequiresSuper = 1,
  kC2xClangObjcRequiresSuper = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCReturnsInnerPointerAttrSpelling : unsigned int {
  kGNUObjcReturnsInnerPointer = 0,
  kCXX11ClangObjcReturnsInnerPointer = 1,
  kC2xClangObjcReturnsInnerPointer = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCRootClassAttrSpelling : unsigned int {
  kGNUObjcRootClass = 0,
  kCXX11ClangObjcRootClass = 1,
  kC2xClangObjcRootClass = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCRuntimeNameAttrSpelling : unsigned int {
  kGNUObjcRuntimeName = 0,
  kCXX11ClangObjcRuntimeName = 1,
  kC2xClangObjcRuntimeName = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCRuntimeVisibleAttrSpelling : unsigned int {
  kGNUObjcRuntimeVisible = 0,
  kCXX11ClangObjcRuntimeVisible = 1,
  kC2xClangObjcRuntimeVisible = 2,
  kSpellingNotCalculated = 15,
};

enum class ObjCSubclassingRestrictedAttrSpelling : unsigned int {
  kGNUObjcSubclassingRestricted = 0,
  kCXX11ClangObjcSubclassingRestricted = 1,
  kC2xClangObjcSubclassingRestricted = 2,
  kSpellingNotCalculated = 15,
};

enum class OpenCLAccessAttrSpelling : unsigned int {
  kKeywordReadOnly = 0,
  kKeywordWriteOnly = 2,
  kKeywordReadWrite = 4,
  kSpellingNotCalculated = 15,
};

enum class OpenCLConstantAddressSpaceAttrSpelling : unsigned int {
  kKeywordConstant = 0,
  kGNUOpenclConstant = 2,
  kCXX11ClangOpenclConstant = 3,
  kC2xClangOpenclConstant = 4,
  kSpellingNotCalculated = 15,
};

enum class OpenCLGenericAddressSpaceAttrSpelling : unsigned int {
  kKeywordGeneric = 0,
  kGNUOpenclGeneric = 2,
  kCXX11ClangOpenclGeneric = 3,
  kC2xClangOpenclGeneric = 4,
  kSpellingNotCalculated = 15,
};

enum class OpenCLGlobalAddressSpaceAttrSpelling : unsigned int {
  kKeywordGlobal = 0,
  kGNUOpenclGlobal = 2,
  kCXX11ClangOpenclGlobal = 3,
  kC2xClangOpenclGlobal = 4,
  kSpellingNotCalculated = 15,
};

enum class OpenCLGlobalDeviceAddressSpaceAttrSpelling : unsigned int {
  kGNUOpenclGlobalDevice = 0,
  kCXX11ClangOpenclGlobalDevice = 1,
  kC2xClangOpenclGlobalDevice = 2,
  kSpellingNotCalculated = 15,
};

enum class OpenCLGlobalHostAddressSpaceAttrSpelling : unsigned int {
  kGNUOpenclGlobalHost = 0,
  kCXX11ClangOpenclGlobalHost = 1,
  kC2xClangOpenclGlobalHost = 2,
  kSpellingNotCalculated = 15,
};

enum class OpenCLKernelAttrSpelling : unsigned int {
  kKeywordKernel = 0,
  kSpellingNotCalculated = 15,
};

enum class OpenCLLocalAddressSpaceAttrSpelling : unsigned int {
  kKeywordLocal = 0,
  kGNUOpenclLocal = 2,
  kCXX11ClangOpenclLocal = 3,
  kC2xClangOpenclLocal = 4,
  kSpellingNotCalculated = 15,
};

enum class OpenCLPrivateAddressSpaceAttrSpelling : unsigned int {
  kKeywordPrivate = 0,
  kGNUOpenclPrivate = 2,
  kCXX11ClangOpenclPrivate = 3,
  kC2xClangOpenclPrivate = 4,
  kSpellingNotCalculated = 15,
};

enum class OptimizeNoneAttrSpelling : unsigned int {
  kGNUOptnone = 0,
  kCXX11ClangOptnone = 1,
  kC2xClangOptnone = 2,
  kSpellingNotCalculated = 15,
};

enum class OverloadableAttrSpelling : unsigned int {
  kGNUOverloadable = 0,
  kCXX11ClangOverloadable = 1,
  kC2xClangOverloadable = 2,
  kSpellingNotCalculated = 15,
};

enum class OwnershipAttrOwnershipKind : unsigned int {
  kHolds = 0,
  kReturns = 1,
  kTakes = 2,
};

enum class OwnershipAttrSpelling : unsigned int {
  kGNUOwnershipHolds = 0,
  kCXX11ClangOwnershipHolds = 1,
  kC2xClangOwnershipHolds = 2,
  kGNUOwnershipReturns = 3,
  kCXX11ClangOwnershipReturns = 4,
  kC2xClangOwnershipReturns = 5,
  kGNUOwnershipTakes = 6,
  kCXX11ClangOwnershipTakes = 7,
  kC2xClangOwnershipTakes = 8,
  kSpellingNotCalculated = 15,
};

enum class PackedAttrSpelling : unsigned int {
  kGNUPacked = 0,
  kCXX11GnuPacked = 1,
  kC2xGnuPacked = 2,
  kSpellingNotCalculated = 15,
};

enum class ParamTypestateAttrConsumedState : unsigned int {
  kUnknown = 0,
  kConsumed = 1,
  kUnconsumed = 2,
};

enum class ParamTypestateAttrSpelling : unsigned int {
  kGNUParameterTypestate = 0,
  kCXX11ClangParameterTypestate = 1,
  kSpellingNotCalculated = 15,
};

enum class PascalAttrSpelling : unsigned int {
  kGNUPascal = 0,
  kCXX11ClangPascal = 1,
  kC2xClangPascal = 2,
  kKeywordPascal = 3,
  kSpellingNotCalculated = 15,
};

enum class PassObjectSizeAttrSpelling : unsigned int {
  kGNUPassObjectSize = 0,
  kCXX11ClangPassObjectSize = 1,
  kC2xClangPassObjectSize = 2,
  kGNUPassDynamicObjectSize = 3,
  kCXX11ClangPassDynamicObjectSize = 4,
  kC2xClangPassDynamicObjectSize = 5,
  kSpellingNotCalculated = 15,
};

enum class PatchableFunctionEntryAttrSpelling : unsigned int {
  kGNUPatchableFunctionEntry = 0,
  kCXX11GnuPatchableFunctionEntry = 1,
  kC2xGnuPatchableFunctionEntry = 2,
  kSpellingNotCalculated = 15,
};

enum class PcsAttrPCSType : unsigned int {
  kAAPCS = 0,
  kVFP = 1,
};

enum class PcsAttrSpelling : unsigned int {
  kGNUPcs = 0,
  kCXX11GnuPcs = 1,
  kC2xGnuPcs = 2,
  kSpellingNotCalculated = 15,
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

enum class PreferredNameAttrSpelling : unsigned int {
  kGNUPreferredName = 0,
  kCXX11ClangPreferredName = 1,
  kSpellingNotCalculated = 15,
};

enum class PreserveAllAttrSpelling : unsigned int {
  kGNUPreserveAll = 0,
  kCXX11ClangPreserveAll = 1,
  kC2xClangPreserveAll = 2,
  kSpellingNotCalculated = 15,
};

enum class PreserveMostAttrSpelling : unsigned int {
  kGNUPreserveMost = 0,
  kCXX11ClangPreserveMost = 1,
  kC2xClangPreserveMost = 2,
  kSpellingNotCalculated = 15,
};

enum class PtGuardedVarAttrSpelling : unsigned int {
  kGNUPtGuardedVariable = 0,
  kCXX11ClangPtGuardedVariable = 1,
  kSpellingNotCalculated = 15,
};

enum class PureAttrSpelling : unsigned int {
  kGNUPure = 0,
  kCXX11GnuPure = 1,
  kC2xGnuPure = 2,
  kSpellingNotCalculated = 15,
};

enum class QualifiedTypeDestructionKind : unsigned int {
  kNone = 0,
  kCxxDestructor = 1,
  kObjcStrongLifetime = 2,
  kObjcWeakLifetime = 3,
  kNontrivialCStruct = 4,
};

enum class QualifiedTypePrimitiveCopyKind : unsigned int {
  kTrivial = 0,
  kVolatileTrivial = 1,
  kARCStrong = 2,
  kARCWeak = 3,
  kStruct = 4,
};

enum class QualifiedTypePrimitiveDefaultInitializeKind : unsigned int {
  kTrivial = 0,
  kARCStrong = 1,
  kARCWeak = 2,
  kStruct = 3,
};

enum class RISCVInterruptAttrInterruptType : unsigned int {
  kUser = 0,
  kSupervisor = 1,
  kMachine = 2,
};

enum class RISCVInterruptAttrSpelling : unsigned int {
  kGNUInterrupt = 0,
  kCXX11GnuInterrupt = 1,
  kC2xGnuInterrupt = 2,
  kSpellingNotCalculated = 15,
};

enum class RandomizeLayoutAttrSpelling : unsigned int {
  kGNURandomizeLayout = 0,
  kCXX11GnuRandomizeLayout = 1,
  kC2xGnuRandomizeLayout = 2,
  kSpellingNotCalculated = 15,
};

enum class RecordDeclArgPassingKind : unsigned int {
  kCanPassInRegs = 0,
  kCannotPassInRegs = 1,
  kCanNeverPassInRegs = 2,
};

enum class RegCallAttrSpelling : unsigned int {
  kGNURegcall = 0,
  kCXX11GnuRegcall = 1,
  kC2xGnuRegcall = 2,
  kKeywordRegcall = 3,
  kSpellingNotCalculated = 15,
};

enum class ReinitializesAttrSpelling : unsigned int {
  kGNUReinitializes = 0,
  kCXX11ClangReinitializes = 1,
  kSpellingNotCalculated = 15,
};

enum class ReleaseCapabilityAttrSpelling : unsigned int {
  kGNUReleaseCapability = 0,
  kCXX11ClangReleaseCapability = 1,
  kGNUReleaseSharedCapability = 2,
  kCXX11ClangReleaseSharedCapability = 3,
  kGNUReleaseGenericCapability = 4,
  kCXX11ClangReleaseGenericCapability = 5,
  kGNUUnlockFunction = 6,
  kCXX11ClangUnlockFunction = 7,
  kSpellingNotCalculated = 15,
};

enum class ReleaseHandleAttrSpelling : unsigned int {
  kGNUReleaseHandle = 0,
  kCXX11ClangReleaseHandle = 1,
  kC2xClangReleaseHandle = 2,
  kSpellingNotCalculated = 15,
};

enum class RequiresCapabilityAttrSpelling : unsigned int {
  kGNURequiresCapability = 0,
  kCXX11ClangRequiresCapability = 1,
  kGNUExclusiveLocksRequired = 2,
  kCXX11ClangExclusiveLocksRequired = 3,
  kGNURequiresSharedCapability = 4,
  kCXX11ClangRequiresSharedCapability = 5,
  kGNUSharedLocksRequired = 6,
  kCXX11ClangSharedLocksRequired = 7,
  kSpellingNotCalculated = 15,
};

enum class RestrictAttrSpelling : unsigned int {
  kDeclspecRestrict = 0,
  kGNUMalloc = 1,
  kCXX11GnuMalloc = 2,
  kC2xGnuMalloc = 3,
  kSpellingNotCalculated = 15,
};

enum class RetainAttrSpelling : unsigned int {
  kGNURetain = 0,
  kCXX11GnuRetain = 1,
  kC2xGnuRetain = 2,
  kSpellingNotCalculated = 15,
};

enum class ReturnTypestateAttrConsumedState : unsigned int {
  kUnknown = 0,
  kConsumed = 1,
  kUnconsumed = 2,
};

enum class ReturnTypestateAttrSpelling : unsigned int {
  kGNUReturnTypestate = 0,
  kCXX11ClangReturnTypestate = 1,
  kSpellingNotCalculated = 15,
};

enum class ReturnsNonNullAttrSpelling : unsigned int {
  kGNUReturnsNonnull = 0,
  kCXX11GnuReturnsNonnull = 1,
  kC2xGnuReturnsNonnull = 2,
  kSpellingNotCalculated = 15,
};

enum class ReturnsTwiceAttrSpelling : unsigned int {
  kGNUReturnsTwice = 0,
  kCXX11GnuReturnsTwice = 1,
  kC2xGnuReturnsTwice = 2,
  kSpellingNotCalculated = 15,
};

enum class SYCLKernelAttrSpelling : unsigned int {
  kGNUSyclKernel = 0,
  kCXX11ClangSyclKernel = 1,
  kC2xClangSyclKernel = 2,
  kSpellingNotCalculated = 15,
};

enum class SYCLSpecialClassAttrSpelling : unsigned int {
  kGNUSyclSpecialClass = 0,
  kCXX11ClangSyclSpecialClass = 1,
  kC2xClangSyclSpecialClass = 2,
  kSpellingNotCalculated = 15,
};

enum class ScopedLockableAttrSpelling : unsigned int {
  kGNUScopedLockable = 0,
  kCXX11ClangScopedLockable = 1,
  kSpellingNotCalculated = 15,
};

enum class SectionAttrSpelling : unsigned int {
  kGNUSection = 0,
  kCXX11GnuSection = 1,
  kC2xGnuSection = 2,
  kDeclspecAllocate = 3,
  kSpellingNotCalculated = 15,
};

enum class SelectAnyAttrSpelling : unsigned int {
  kDeclspecSelectany = 0,
  kGNUSelectany = 1,
  kCXX11GnuSelectany = 2,
  kC2xGnuSelectany = 3,
  kSpellingNotCalculated = 15,
};

enum class SentinelAttrSpelling : unsigned int {
  kGNUSentinel = 0,
  kCXX11GnuSentinel = 1,
  kC2xGnuSentinel = 2,
  kSpellingNotCalculated = 15,
};

enum class SetTypestateAttrConsumedState : unsigned int {
  kUnknown = 0,
  kConsumed = 1,
  kUnconsumed = 2,
};

enum class SetTypestateAttrSpelling : unsigned int {
  kGNUTypestate = 0,
  kCXX11ClangTypestate = 1,
  kSpellingNotCalculated = 15,
};

enum class SourceLocExprIdentKind : unsigned int {
  kFunction = 0,
  kFile = 1,
  kLine = 2,
  kColumn = 3,
  kSourceTokenStruct = 4,
};

enum class SpeculativeLoadHardeningAttrSpelling : unsigned int {
  kGNUSpeculativeLoadHardening = 0,
  kCXX11ClangSpeculativeLoadHardening = 1,
  kC2xClangSpeculativeLoadHardening = 2,
  kSpellingNotCalculated = 15,
};

enum class StandaloneDebugAttrSpelling : unsigned int {
  kGNUStandaloneDebug = 0,
  kCXX11ClangStandaloneDebug = 1,
  kSpellingNotCalculated = 15,
};

enum class StdCallAttrSpelling : unsigned int {
  kGNUStdcall = 0,
  kCXX11GnuStdcall = 1,
  kC2xGnuStdcall = 2,
  kKeywordStdcall = 3,
  kSpellingNotCalculated = 15,
};

enum class StmtLikelihood : int {
  kUnlikely = -1,
  kNone = 0,
  kLikely = 1,
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
  kOMPGenericLoopDirective = 36,
  kOMPMaskedTaskLoopDirective = 37,
  kOMPMaskedTaskLoopSimdDirective = 38,
  kOMPMasterTaskLoopDirective = 39,
  kOMPMasterTaskLoopSimdDirective = 40,
  kOMPParallelForDirective = 41,
  kOMPParallelForSimdDirective = 42,
  kOMPParallelGenericLoopDirective = 43,
  kOMPParallelMaskedTaskLoopDirective = 44,
  kOMPParallelMaskedTaskLoopSimdDirective = 45,
  kOMPParallelMasterTaskLoopDirective = 46,
  kOMPParallelMasterTaskLoopSimdDirective = 47,
  kOMPSimdDirective = 48,
  kOMPTargetParallelForSimdDirective = 49,
  kOMPTargetParallelGenericLoopDirective = 50,
  kOMPTargetSimdDirective = 51,
  kOMPTargetTeamsDistributeDirective = 52,
  kOMPTargetTeamsDistributeParallelForDirective = 53,
  kOMPTargetTeamsDistributeParallelForSimdDirective = 54,
  kOMPTargetTeamsDistributeSimdDirective = 55,
  kOMPTargetTeamsGenericLoopDirective = 56,
  kOMPTaskLoopDirective = 57,
  kOMPTaskLoopSimdDirective = 58,
  kOMPTeamsDistributeDirective = 59,
  kOMPTeamsDistributeParallelForDirective = 60,
  kOMPTeamsDistributeParallelForSimdDirective = 61,
  kOMPTeamsDistributeSimdDirective = 62,
  kOMPTeamsGenericLoopDirective = 63,
  kOMPTileDirective = 64,
  kOMPUnrollDirective = 65,
  kOMPMaskedDirective = 66,
  kOMPMasterDirective = 67,
  kOMPMetaDirective = 68,
  kOMPOrderedDirective = 69,
  kOMPParallelDirective = 70,
  kOMPParallelMaskedDirective = 71,
  kOMPParallelMasterDirective = 72,
  kOMPParallelSectionsDirective = 73,
  kOMPScanDirective = 74,
  kOMPSectionDirective = 75,
  kOMPSectionsDirective = 76,
  kOMPSingleDirective = 77,
  kOMPTargetDataDirective = 78,
  kOMPTargetDirective = 79,
  kOMPTargetEnterDataDirective = 80,
  kOMPTargetExitDataDirective = 81,
  kOMPTargetParallelDirective = 82,
  kOMPTargetParallelForDirective = 83,
  kOMPTargetTeamsDirective = 84,
  kOMPTargetUpdateDirective = 85,
  kOMPTaskDirective = 86,
  kOMPTaskgroupDirective = 87,
  kOMPTaskwaitDirective = 88,
  kOMPTaskyieldDirective = 89,
  kOMPTeamsDirective = 90,
  kObjCAtCatchStmt = 91,
  kObjCAtFinallyStmt = 92,
  kObjCAtSynchronizedStmt = 93,
  kObjCAtThrowStmt = 94,
  kObjCAtTryStmt = 95,
  kObjCAutoreleasePoolStmt = 96,
  kObjCForCollectionStmt = 97,
  kReturnStmt = 98,
  kSEHExceptStmt = 99,
  kSEHFinallyStmt = 100,
  kSEHLeaveStmt = 101,
  kSEHTryStmt = 102,
  kCaseStmt = 103,
  kDefaultStmt = 104,
  kSwitchStmt = 105,
  kAttributedStmt = 106,
  kBinaryConditionalOperator = 107,
  kConditionalOperator = 108,
  kAddrLabelExpr = 109,
  kArrayInitIndexExpr = 110,
  kArrayInitLoopExpr = 111,
  kArraySubscriptExpr = 112,
  kArrayTypeTraitExpr = 113,
  kAsTypeExpr = 114,
  kAtomicExpr = 115,
  kBinaryOperator = 116,
  kCompoundAssignOperator = 117,
  kBlockExpr = 118,
  kCXXBindTemporaryExpr = 119,
  kCXXBoolLiteralExpr = 120,
  kCXXConstructExpr = 121,
  kCXXTemporaryObjectExpr = 122,
  kCXXDefaultArgExpr = 123,
  kCXXDefaultInitExpr = 124,
  kCXXDeleteExpr = 125,
  kCXXDependentScopeMemberExpr = 126,
  kCXXFoldExpr = 127,
  kCXXInheritedCtorInitExpr = 128,
  kCXXNewExpr = 129,
  kCXXNoexceptExpr = 130,
  kCXXNullPtrLiteralExpr = 131,
  kCXXPseudoDestructorExpr = 132,
  kCXXRewrittenBinaryOperator = 133,
  kCXXScalarValueInitExpr = 134,
  kCXXStdInitializerListExpr = 135,
  kCXXThisExpr = 136,
  kCXXThrowExpr = 137,
  kCXXTypeidExpr = 138,
  kCXXUnresolvedConstructExpr = 139,
  kCXXUuidofExpr = 140,
  kCallExpr = 141,
  kCUDAKernelCallExpr = 142,
  kCXXMemberCallExpr = 143,
  kCXXOperatorCallExpr = 144,
  kUserDefinedLiteral = 145,
  kBuiltinBitCastExpr = 146,
  kCStyleCastExpr = 147,
  kCXXFunctionalCastExpr = 148,
  kCXXAddrspaceCastExpr = 149,
  kCXXConstCastExpr = 150,
  kCXXDynamicCastExpr = 151,
  kCXXReinterpretCastExpr = 152,
  kCXXStaticCastExpr = 153,
  kObjCBridgedCastExpr = 154,
  kImplicitCastExpr = 155,
  kCharacterLiteral = 156,
  kChooseExpr = 157,
  kCompoundLiteralExpr = 158,
  kConceptSpecializationExpr = 159,
  kConvertVectorExpr = 160,
  kCoawaitExpr = 161,
  kCoyieldExpr = 162,
  kDeclRefExpr = 163,
  kDependentCoawaitExpr = 164,
  kDependentScopeDeclRefExpr = 165,
  kDesignatedInitExpr = 166,
  kDesignatedInitUpdateExpr = 167,
  kExpressionTraitExpr = 168,
  kExtVectorElementExpr = 169,
  kFixedPointLiteral = 170,
  kFloatingLiteral = 171,
  kConstantExpr = 172,
  kExprWithCleanups = 173,
  kFunctionParmPackExpr = 174,
  kGNUNullExpr = 175,
  kGenericSelectionExpr = 176,
  kImaginaryLiteral = 177,
  kImplicitValueInitExpr = 178,
  kInitListExpr = 179,
  kIntegerLiteral = 180,
  kLambdaExpr = 181,
  kMSPropertyRefExpr = 182,
  kMSPropertySubscriptExpr = 183,
  kMaterializeTemporaryExpr = 184,
  kMatrixSubscriptExpr = 185,
  kMemberExpr = 186,
  kNoInitExpr = 187,
  kOMPArraySectionExpr = 188,
  kOMPArrayShapingExpr = 189,
  kOMPIteratorExpr = 190,
  kObjCArrayLiteral = 191,
  kObjCAvailabilityCheckExpr = 192,
  kObjCBoolLiteralExpr = 193,
  kObjCBoxedExpr = 194,
  kObjCDictionaryLiteral = 195,
  kObjCEncodeExpr = 196,
  kObjCIndirectCopyRestoreExpr = 197,
  kObjCIsaExpr = 198,
  kObjCIvarRefExpr = 199,
  kObjCMessageExpr = 200,
  kObjCPropertyRefExpr = 201,
  kObjCProtocolExpr = 202,
  kObjCSelectorExpr = 203,
  kObjCStringLiteral = 204,
  kObjCSubscriptRefExpr = 205,
  kOffsetOfExpr = 206,
  kOpaqueValueExpr = 207,
  kUnresolvedLookupExpr = 208,
  kUnresolvedMemberExpr = 209,
  kPackExpansionExpr = 210,
  kParenExpr = 211,
  kParenListExpr = 212,
  kPredefinedExpr = 213,
  kPseudoObjectExpr = 214,
  kRecoveryExpr = 215,
  kRequiresExpr = 216,
  kSYCLUniqueStableNameExpr = 217,
  kShuffleVectorExpr = 218,
  kSizeOfPackExpr = 219,
  kSourceLocExpr = 220,
  kStmtExpr = 221,
  kStringLiteral = 222,
  kSubstNonTypeTemplateParmExpr = 223,
  kSubstNonTypeTemplateParmPackExpr = 224,
  kTypeTraitExpr = 225,
  kTypoExpr = 226,
  kUnaryExprOrTypeTraitExpr = 227,
  kUnaryOperator = 228,
  kVAArgExpr = 229,
  kLabelStmt = 230,
  kWhileStmt = 231,
};

enum class StringLiteralStringKind : unsigned int {
  kOrdinary = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class SwiftAsyncAttrKind : unsigned int {
  kNone = 0,
  kSwiftPrivate = 1,
  kNotSwiftPrivate = 2,
};

enum class SwiftAsyncAttrSpelling : unsigned int {
  kGNUSwiftAsync = 0,
  kCXX11ClangSwiftAsync = 1,
  kC2xClangSwiftAsync = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftAsyncCallAttrSpelling : unsigned int {
  kGNUSwiftasynccall = 0,
  kCXX11ClangSwiftasynccall = 1,
  kC2xClangSwiftasynccall = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftAsyncContextAttrSpelling : unsigned int {
  kGNUSwiftAsyncContext = 0,
  kCXX11ClangSwiftAsyncContext = 1,
  kC2xClangSwiftAsyncContext = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftAsyncErrorAttrConventionKind : unsigned int {
  kNone = 0,
  kNonNullError = 1,
  kZeroArgument = 2,
  kNonZeroArgument = 3,
};

enum class SwiftAsyncErrorAttrSpelling : unsigned int {
  kGNUSwiftAsyncError = 0,
  kCXX11ClangSwiftAsyncError = 1,
  kC2xClangSwiftAsyncError = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftCallAttrSpelling : unsigned int {
  kGNUSwiftcall = 0,
  kCXX11ClangSwiftcall = 1,
  kC2xClangSwiftcall = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftContextAttrSpelling : unsigned int {
  kGNUSwiftContext = 0,
  kCXX11ClangSwiftContext = 1,
  kC2xClangSwiftContext = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftErrorAttrConventionKind : unsigned int {
  kNone = 0,
  kNonNullError = 1,
  kNullResult = 2,
  kZeroResult = 3,
  kNonZeroResult = 4,
};

enum class SwiftErrorResultAttrSpelling : unsigned int {
  kGNUSwiftErrorResult = 0,
  kCXX11ClangSwiftErrorResult = 1,
  kC2xClangSwiftErrorResult = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftIndirectResultAttrSpelling : unsigned int {
  kGNUSwiftIndirectResult = 0,
  kCXX11ClangSwiftIndirectResult = 1,
  kC2xClangSwiftIndirectResult = 2,
  kSpellingNotCalculated = 15,
};

enum class SwiftNewTypeAttrNewtypeKind : unsigned int {
  kStruct = 0,
  kEnum = 1,
};

enum class SwiftNewTypeAttrSpelling : unsigned int {
  kGNUSwiftNewtype = 0,
  kGNUSwiftWrapper = 1,
  kSpellingNotCalculated = 15,
};

enum class SysVABIAttrSpelling : unsigned int {
  kGNUSysvAbi = 0,
  kCXX11GnuSysvAbi = 1,
  kC2xGnuSysvAbi = 2,
  kSpellingNotCalculated = 15,
};

enum class TLSModelAttrSpelling : unsigned int {
  kGNUTlsModel = 0,
  kCXX11GnuTlsModel = 1,
  kC2xGnuTlsModel = 2,
  kSpellingNotCalculated = 15,
};

enum class TargetAttrSpelling : unsigned int {
  kGNUTarget = 0,
  kCXX11GnuTarget = 1,
  kC2xGnuTarget = 2,
  kSpellingNotCalculated = 15,
};

enum class TargetClonesAttrSpelling : unsigned int {
  kGNUTargetClones = 0,
  kCXX11GnuTargetClones = 1,
  kC2xGnuTargetClones = 2,
  kSpellingNotCalculated = 15,
};

enum class TemplateArgumentKind : unsigned int {
  kEmpty = 0,
  kType = 1,
  kDeclaration = 2,
  kNullPointer = 3,
  kIntegral = 4,
  kTemplate = 5,
  kTemplateExpansion = 6,
  kExpression = 7,
  kPack = 8,
};

enum class TestTypestateAttrConsumedState : unsigned int {
  kConsumed = 0,
  kUnconsumed = 1,
};

enum class TestTypestateAttrSpelling : unsigned int {
  kGNUTestTypestate = 0,
  kCXX11ClangTestTypestate = 1,
  kSpellingNotCalculated = 15,
};

enum class ThisCallAttrSpelling : unsigned int {
  kGNUThiscall = 0,
  kCXX11GnuThiscall = 1,
  kC2xGnuThiscall = 2,
  kKeywordThiscall = 3,
  kSpellingNotCalculated = 15,
};

enum class TransparentUnionAttrSpelling : unsigned int {
  kGNUTransparentUnion = 0,
  kCXX11GnuTransparentUnion = 1,
  kC2xGnuTransparentUnion = 2,
  kSpellingNotCalculated = 15,
};

enum class TrivialABIAttrSpelling : unsigned int {
  kGNUTrivialAbi = 0,
  kCXX11ClangTrivialAbi = 1,
  kSpellingNotCalculated = 15,
};

enum class TryAcquireCapabilityAttrSpelling : unsigned int {
  kGNUTryAcquireCapability = 0,
  kCXX11ClangTryAcquireCapability = 1,
  kGNUTryAcquireSharedCapability = 2,
  kCXX11ClangTryAcquireSharedCapability = 3,
  kSpellingNotCalculated = 15,
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

enum class TypeKind : unsigned int {
  kAdjusted = 0,
  kDecayed = 1,
  kConstantArray = 2,
  kDependentSizedArray = 3,
  kIncompleteArray = 4,
  kVariableArray = 5,
  kAtomic = 6,
  kAttributed = 7,
  kBTFTagAttributed = 8,
  kBitInt = 9,
  kBlockPointer = 10,
  kBuiltin = 11,
  kComplex = 12,
  kDecltype = 13,
  kAuto = 14,
  kDeducedTemplateSpecialization = 15,
  kDependentAddressSpace = 16,
  kDependentBitInt = 17,
  kDependentName = 18,
  kDependentSizedExtVector = 19,
  kDependentTemplateSpecialization = 20,
  kDependentVector = 21,
  kElaborated = 22,
  kFunctionNoProto = 23,
  kFunctionProto = 24,
  kInjectedClassName = 25,
  kMacroQualified = 26,
  kConstantMatrix = 27,
  kDependentSizedMatrix = 28,
  kMemberPointer = 29,
  kObjCObjectPointer = 30,
  kObjCObject = 31,
  kObjCInterface = 32,
  kObjCTypeParam = 33,
  kPackExpansion = 34,
  kParen = 35,
  kPipe = 36,
  kPointer = 37,
  kLValueReference = 38,
  kRValueReference = 39,
  kSubstTemplateTypeParmPack = 40,
  kSubstTemplateTypeParm = 41,
  kEnum = 42,
  kRecord = 43,
  kTemplateSpecialization = 44,
  kTemplateTypeParm = 45,
  kTypeOfExpr = 46,
  kTypeOf = 47,
  kTypedef = 48,
  kUnaryTransform = 49,
  kUnresolvedUsing = 50,
  kUsing = 51,
  kVector = 52,
  kExtVector = 53,
  kQualified  // Manually added.
};

enum class TypeTagForDatatypeAttrSpelling : unsigned int {
  kGNUTypeTagForDatatype = 0,
  kCXX11ClangTypeTagForDatatype = 1,
  kC2xClangTypeTagForDatatype = 2,
  kSpellingNotCalculated = 15,
};

enum class TypeVisibilityAttrSpelling : unsigned int {
  kGNUTypeVisibility = 0,
  kCXX11ClangTypeVisibility = 1,
  kC2xClangTypeVisibility = 2,
  kSpellingNotCalculated = 15,
};

enum class TypeVisibilityAttrVisibilityType : unsigned int {
  kDefault = 0,
  kHidden = 1,
  kProtected = 2,
};

enum class UnaryTransformTypeUTTKind : unsigned int {
  kEnumUnderlyingType = 0,
};

enum class UnavailableAttrImplicitReason : unsigned int {
  kNone = 0,
  kARCForbiddenType = 1,
  kForbiddenWeak = 2,
  kARCForbiddenConversion = 3,
  kARCInitReturnsUnrelated = 4,
  kARCFieldWithOwnership = 5,
};

enum class UnavailableAttrSpelling : unsigned int {
  kGNUUnavailable = 0,
  kCXX11ClangUnavailable = 1,
  kC2xClangUnavailable = 2,
  kSpellingNotCalculated = 15,
};

enum class UninitializedAttrSpelling : unsigned int {
  kGNUUninitialized = 0,
  kCXX11ClangUninitialized = 1,
  kSpellingNotCalculated = 15,
};

enum class UnlikelyAttrSpelling : unsigned int {
  kCXX11Unlikely = 0,
  kC2xClangUnlikely = 1,
  kSpellingNotCalculated = 15,
};

enum class UnusedAttrSpelling : unsigned int {
  kCXX11MaybeUnused = 0,
  kGNUUnused = 1,
  kCXX11GnuUnused = 2,
  kC2xGnuUnused = 3,
  kC2xMaybeUnused = 4,
  kSpellingNotCalculated = 15,
};

enum class UseHandleAttrSpelling : unsigned int {
  kGNUUseHandle = 0,
  kCXX11ClangUseHandle = 1,
  kC2xClangUseHandle = 2,
  kSpellingNotCalculated = 15,
};

enum class UsedAttrSpelling : unsigned int {
  kGNUUsed = 0,
  kCXX11GnuUsed = 1,
  kC2xGnuUsed = 2,
  kSpellingNotCalculated = 15,
};

enum class UserDefinedLiteralLiteralOperatorKind : unsigned int {
  kRaw = 0,
  kTemplate = 1,
  kInteger = 2,
  kFloating = 3,
  kString = 4,
  kCharacter = 5,
};

enum class UsingIfExistsAttrSpelling : unsigned int {
  kGNUUsingIfExists = 0,
  kCXX11ClangUsingIfExists = 1,
  kSpellingNotCalculated = 15,
};

enum class UuidAttrSpelling : unsigned int {
  kDeclspecUuid = 0,
  kMicrosoftUuid = 1,
  kSpellingNotCalculated = 15,
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

enum class VecReturnAttrSpelling : unsigned int {
  kGNUVecreturn = 0,
  kCXX11ClangVecreturn = 1,
  kSpellingNotCalculated = 15,
};

enum class VectorCallAttrSpelling : unsigned int {
  kGNUVectorcall = 0,
  kCXX11ClangVectorcall = 1,
  kC2xClangVectorcall = 2,
  kKeywordVectorcall = 3,
  kSpellingNotCalculated = 15,
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

enum class VisibilityAttrSpelling : unsigned int {
  kGNUVisibility = 0,
  kCXX11GnuVisibility = 1,
  kC2xGnuVisibility = 2,
  kSpellingNotCalculated = 15,
};

enum class VisibilityAttrVisibilityType : unsigned int {
  kDefault = 0,
  kHidden = 1,
  kProtected = 2,
};

enum class WarnUnusedAttrSpelling : unsigned int {
  kGNUWarnUnused = 0,
  kCXX11GnuWarnUnused = 1,
  kC2xGnuWarnUnused = 2,
  kSpellingNotCalculated = 15,
};

enum class WarnUnusedResultAttrSpelling : unsigned int {
  kCXX11Nodiscard = 0,
  kC2xNodiscard = 1,
  kCXX11ClangWarnUnusedResult = 2,
  kGNUWarnUnusedResult = 3,
  kCXX11GnuWarnUnusedResult = 4,
  kC2xGnuWarnUnusedResult = 5,
  kSpellingNotCalculated = 15,
};

enum class WeakAttrSpelling : unsigned int {
  kGNUWeak = 0,
  kCXX11GnuWeak = 1,
  kC2xGnuWeak = 2,
  kSpellingNotCalculated = 15,
};

enum class WeakImportAttrSpelling : unsigned int {
  kGNUWeakImport = 0,
  kCXX11ClangWeakImport = 1,
  kC2xClangWeakImport = 2,
  kSpellingNotCalculated = 15,
};

enum class WeakRefAttrSpelling : unsigned int {
  kGNUWeakref = 0,
  kCXX11GnuWeakref = 1,
  kC2xGnuWeakref = 2,
  kSpellingNotCalculated = 15,
};

enum class WebAssemblyExportNameAttrSpelling : unsigned int {
  kGNUExportName = 0,
  kCXX11ClangExportName = 1,
  kC2xClangExportName = 2,
  kSpellingNotCalculated = 15,
};

enum class WebAssemblyImportModuleAttrSpelling : unsigned int {
  kGNUImportModule = 0,
  kCXX11ClangImportModule = 1,
  kC2xClangImportModule = 2,
  kSpellingNotCalculated = 15,
};

enum class WebAssemblyImportNameAttrSpelling : unsigned int {
  kGNUImportName = 0,
  kCXX11ClangImportName = 1,
  kC2xClangImportName = 2,
  kSpellingNotCalculated = 15,
};

enum class X86ForceAlignArgPointerAttrSpelling : unsigned int {
  kGNUForceAlignArgumentPointer = 0,
  kCXX11GnuForceAlignArgumentPointer = 1,
  kC2xGnuForceAlignArgumentPointer = 2,
  kSpellingNotCalculated = 15,
};

enum class XRayInstrumentAttrSpelling : unsigned int {
  kGNUXrayAlwaysInstrument = 0,
  kCXX11ClangXrayAlwaysInstrument = 1,
  kC2xClangXrayAlwaysInstrument = 2,
  kGNUXrayNeverInstrument = 3,
  kCXX11ClangXrayNeverInstrument = 4,
  kC2xClangXrayNeverInstrument = 5,
  kSpellingNotCalculated = 15,
};

enum class XRayLogArgsAttrSpelling : unsigned int {
  kGNUXrayLogArguments = 0,
  kCXX11ClangXrayLogArguments = 1,
  kC2xClangXrayLogArguments = 2,
  kSpellingNotCalculated = 15,
};

enum class ZeroCallUsedRegsAttrSpelling : unsigned int {
  kGNUZeroCallUsedRegs = 0,
  kCXX11GnuZeroCallUsedRegs = 1,
  kC2xGnuZeroCallUsedRegs = 2,
  kSpellingNotCalculated = 15,
};

enum class ZeroCallUsedRegsAttrZeroCallUsedRegsKind : unsigned int {
  kSkip = 0,
  kUsedGPRArg = 1,
  kUsedGPR = 2,
  kUsedArgument = 3,
  kUsed = 4,
  kAllGPRArg = 5,
  kAllGPR = 6,
  kAllArgument = 7,
  kAll = 8,
};

enum class ASTDumpOutputFormat : unsigned int {
  kDefault = 0,
  kJSON = 1,
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

enum class AlignRequirementKind : int {
  kNone = 0,
  kRequiredByTypedef = 1,
  kRequiredByRecord = 2,
  kRequiredByEnum = 3,
};

enum class AltivecSrcCompatKind : int {
  kMixed = 0,
  kGCC = 1,
  kXL = 2,
  kDefault = 0,
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

enum class ArrayTypeTrait : unsigned int {
  kArrayRank = 0,
  kArrayExtent = 1,
};

enum class AtomicScopeModelKind : int {
  kNone = 0,
  kOpenCL = 1,
  kHIP = 2,
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
  kSemantic = 62,
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
  kAArch64SVEPCS = 19,
  kAMDGPUKernelCall = 20,
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

enum class ClangABI : int {
  kVer38 = 0,
  kVer4 = 1,
  kVer6 = 2,
  kVer7 = 3,
  kVer9 = 4,
  kVer11 = 5,
  kVer12 = 6,
  kVer14 = 7,
  kLatest = 8,
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
  kHeaderUnit = 3,
  kModuleInterface = 4,
};

enum class ConstexprSpecKind : int {
  kUnspecified = 0,
  kConstexpr = 1,
  kConsteval = 2,
  kConstinit = 3,
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

enum class DataPositionTy : unsigned long {
  kPOSX = 0,
  kPOSV = 1,
  kPOSE = 2,
  kPOSUpdateExpression = 3,
  kPOSD = 4,
  kPOSCondition = 5,
  kPOSR = 6,
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

enum class DefaultVisiblityExportMapping : int {
  kNone = 0,
  kExplicit = 1,
  kAll = 2,
};

enum class DiagnosticLevelMask : unsigned int {
  kNone = 0,
  kNote = 1,
  kRemark = 2,
  kWarning = 4,
  kError = 8,
  kAll = 15,
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

enum class EscapeChar : int {
  kSingle = 1,
  kDouble = 2,
  kSingleAndDouble = 3,
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

enum class FPEvalMethodKind : int {
  kFEMIndeterminable = -1,
  kFEMSource = 0,
  kFEMDouble = 1,
  kFEMExtended = 2,
  kFEMUnsetOnCommandLine = 3,
};

enum class FPExceptionModeKind : unsigned int {
  kIgnore = 0,
  kMayTrap = 1,
  kStrict = 2,
  kDefault = 3,
};

enum class FPModeKind : unsigned int {
  kOff = 0,
  kOn = 1,
  kFast = 2,
  kFastHonorPragmas = 3,
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

enum class GPUDefaultStreamKind : int {
  kLegacy = 0,
  kPerThread = 1,
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

enum class HLSLLangStd : unsigned int {
  kHLSLUnset = 0,
  kHLSL2015 = 2015,
  kHLSL2016 = 2016,
  kHLSL2017 = 2017,
  kHLSL2018 = 2018,
  kHLSL2021 = 2021,
  kHLSL202x = 2029,
};

enum class ID : unsigned int {
  kWorkGroup = 1,
  kDevice = 2,
  kAllSVMDevices = 3,
  kSubGroup = 4,
};

enum class IdentifierInfoFlag : unsigned int {
  kZeroArgument = 1,
  kOneArgument = 2,
  kMultiArgument = 7,
  kArgumentFlags = 7,
};

enum class IfStatementKind : unsigned int {
  kOrdinary = 0,
  kConstexpr = 1,
  kConstevalNonNegated = 2,
  kConstevalNegated = 3,
};

enum class ImbueAttribute : int {
  kNONE = 0,
  kALWAYS = 1,
  kNEVER = 2,
  kALWAYSARG1 = 3,
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

enum class InitStorageKind : unsigned int {
  kNoInitializer = 0,
  kInClassCopyInitializer = 1,
  kInClassListInitializer = 2,
  kCapturedVLAType = 3,
};

enum class InlineAsmDialectKind : unsigned int {
  kIADATT = 0,
  kIADIntel = 1,
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
  kOpenCL = 16384,
  kHLSL = 32768,
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
  kHLSL = 12,
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

enum class Linkage : unsigned char {
  kNoLinkage = 0,
  kInternalLinkage = 1,
  kUniqueExternalLinkage = 2,
  kVisibleNoLinkage = 3,
  kModuleInternalLinkage = 4,
  kModuleLinkage = 5,
  kExternalLinkage = 6,
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
  kMSVC20195 = 1925,
  kMSVC20198 = 1928,
};

enum class MSVtorDispMode : int {
  kNever = 0,
  kForVirtualBaseOverride = 1,
  kForVFTable = 2,
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
  kConstAddressSpace = 8,
  kArrayType = 9,
  kIncompleteType = 10,
};

enum class MultiVersionKind : int {
  kNone = 0,
  kTarget = 1,
  kCPUSpecific = 2,
  kCPUDispatch = 3,
  kTargetClones = 4,
};

enum class NameKind : unsigned int {
  kTemplate = 0,
  kOverloadedTemplate = 1,
  kAssumedTemplate = 2,
  kQualifiedTemplate = 3,
  kDependentTemplate = 4,
  kSubstTemplateTemplateParm = 5,
  kSubstTemplateTemplateParmPack = 6,
  kUsingTemplate = 7,
};

enum class NeedExtraManglingDecl : unsigned int {
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

enum class NonOdrUseReason : unsigned int {
  kNone = 0,
  kUnevaluated = 1,
  kConstant = 2,
  kDiscarded = 3,
};

enum class NonceObjCInterface : unsigned int {
  kObjCInterface = 0,
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

enum class OpenMPAdjustArgsOpKind : unsigned int {
  kADJUSTARGSNothing = 0,
  kADJUSTARGSNeedDevicePointer = 1,
  kADJUSTARGSUnknown = 2,
};

enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned int {
  kSeqCst = 0,
  kAcqRel = 1,
  kRelaxed = 2,
  kUnknown = 3,
};

enum class OpenMPBindClauseKind : unsigned int {
  kBINDTeams = 0,
  kBINDParallel = 1,
  kBINDThread = 2,
  kBINDUnknown = 3,
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
  kInoutset = 7,
  kOutallmemory = 8,
  kInoutallmemory = 9,
  kUnknown = 10,
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
  kValue = 0,
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
  kOmpxHold = 11,
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
  kLParenToken = 0,
  kRParenToken = 1,
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

enum class ProfileInstrKind : unsigned int {
  kProfileNone = 0,
  kProfileClangInstr = 1,
  kProfileIRInstr = 2,
  kProfileCSIRInstr = 3,
};

enum class Qualified : int {
  kNone = 0,
  kAsWritten = 1,
  kFully = 2,
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
  kStartsWithUnderscoreAndIsExternC = 2,
  kStartsWithDoubleUnderscore = 3,
  kStartsWithUnderscoreFollowedByCapitalLetter = 4,
  kContainsDoubleUnderscore = 5,
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
  kMemtagStack = 6,
  kMemtagHeap = 7,
  kMemtagGlobals = 8,
  kMemoryTagGroup = 9,
  kMemory = 10,
  kKernelMemory = 11,
  kFuzzer = 12,
  kFuzzerNoLink = 13,
  kThread = 14,
  kLeak = 15,
  kAlignment = 16,
  kArrayBounds = 17,
  kBoolean = 18,
  kBuiltin = 19,
  kEnum = 20,
  kFloatCastOverflow = 21,
  kFloatDivideByZero = 22,
  kFunction = 23,
  kIntegerDivideByZero = 24,
  kNonnullAttribute = 25,
  kNull = 26,
  kNullabilityArgument = 27,
  kNullabilityAssign = 28,
  kNullabilityReturn = 29,
  kNullabilityGroup = 30,
  kObjectSize = 31,
  kPointerOverflow = 32,
  kReturn = 33,
  kReturnsNonnullAttribute = 34,
  kShiftBase = 35,
  kShiftExponent = 36,
  kShiftGroup = 37,
  kSignedIntegerOverflow = 38,
  kUnreachable = 39,
  kVLABound = 40,
  kVptr = 41,
  kUnsignedIntegerOverflow = 42,
  kUnsignedShiftBase = 43,
  kDataFlow = 44,
  kCFICastStrict = 45,
  kCFIDerivedCast = 46,
  kCFIICall = 47,
  kCFIMFCall = 48,
  kCFIUnrelatedCast = 49,
  kCFINVCall = 50,
  kCFIVCall = 51,
  kCFIGroup = 52,
  kSafeStack = 53,
  kShadowCallStack = 54,
  kUndefinedGroup = 55,
  kUndefinedTrapGroup = 56,
  kImplicitUnsignedIntegerTruncation = 57,
  kImplicitSignedIntegerTruncation = 58,
  kImplicitIntegerTruncationGroup = 59,
  kImplicitIntegerSignChange = 60,
  kImplicitIntegerArithmeticValueChangeGroup = 61,
  kObjCCast = 62,
  kImplicitConversionGroup = 63,
  kIntegerGroup = 64,
  kLocalBounds = 65,
  kBoundsGroup = 66,
  kScudo = 67,
  kAllGroup = 68,
  kCount = 69,
};

enum class SelectorLocationsKind : unsigned int {
  kNonStandard = 0,
  kStandardNoSpace = 1,
  kStandardWithSpace = 2,
};

enum class ShaderStage : int {
  kPixel = 0,
  kVertex = 1,
  kGeometry = 2,
  kHull = 3,
  kDomain = 4,
  kCompute = 5,
  kLibrary = 6,
  kRayGeneration = 7,
  kIntersection = 8,
  kAnyHit = 9,
  kClosestHit = 10,
  kMiss = 11,
  kCallable = 12,
  kMesh = 13,
  kAmplification = 14,
  kInvalid = 15,
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

enum class StackProtectorMode : unsigned int {
  kOff = 0,
  kOn = 1,
  kStrong = 2,
  kReq = 3,
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
  kReturnStatement = 9,
  kReturnStatementOnAllocFailure = 10,
};

enum class SwiftAsyncFramePointerKind : int {
  kAuto = 0,
  kAlways = 1,
  kNever = 2,
  kDefault = 1,
};

enum class SyncScope : int {
  kHIPSingleThread = 0,
  kHIPWavefront = 1,
  kHIPWorkgroup = 2,
  kHIPAgent = 3,
  kHIPSystem = 4,
  kOpenCLWorkGroup = 5,
  kOpenCLDevice = 6,
  kOpenCLAllSVMDevices = 7,
  kOpenCLSubGroup = 8,
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
  kHLSLSemantic = 8,
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

enum class TextDiagnosticFormat : unsigned int {
  kClang = 0,
  kMSVC = 1,
  kVi = 2,
  kSARIF = 3,
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
  kLBraceToken = 23,
  kRBraceToken = 24,
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
  kKeyword_BitInt = 95,
  kKeywordLong = 96,
  kKeywordRegister = 97,
  kKeywordRestrict = 98,
  kKeywordReturn = 99,
  kKeywordShort = 100,
  kKeywordSigned = 101,
  kKeywordSizeof = 102,
  kKeywordStatic = 103,
  kKeywordStruct = 104,
  kKeywordSwitch = 105,
  kKeywordTypedef = 106,
  kKeywordUnion = 107,
  kKeywordUnsigned = 108,
  kKeywordVoid = 109,
  kKeywordVolatile = 110,
  kKeywordWhile = 111,
  kKeyword_Alignas = 112,
  kKeyword_Alignof = 113,
  kKeyword_Atomic = 114,
  kKeyword_Boolean = 115,
  kKeyword_Complex = 116,
  kKeyword_Generic = 117,
  kKeyword_Imaginary = 118,
  kKeyword_Noreturn = 119,
  kKeyword_StaticAssert = 120,
  kKeyword_ThreadLocal = 121,
  kKeyword__Func__ = 122,
  kKeyword__ObjcYes = 123,
  kKeyword__ObjcNo = 124,
  kKeywordAssembly = 125,
  kKeywordBoolean = 126,
  kKeywordCatch = 127,
  kKeywordClass = 128,
  kKeywordConstCast = 129,
  kKeywordDelete = 130,
  kKeywordDynamicCast = 131,
  kKeywordExplicit = 132,
  kKeywordExport = 133,
  kKeywordFalse = 134,
  kKeywordFriend = 135,
  kKeywordMutable = 136,
  kKeywordNamespace = 137,
  kKeywordNew = 138,
  kKeywordOperator = 139,
  kKeywordPrivate = 140,
  kKeywordProtected = 141,
  kKeywordPublic = 142,
  kKeywordReinterpretCast = 143,
  kKeywordStaticCast = 144,
  kKeywordTemplate = 145,
  kKeywordThis = 146,
  kKeywordThrow = 147,
  kKeywordTrue = 148,
  kKeywordTry = 149,
  kKeywordTypename = 150,
  kKeywordTypeid = 151,
  kKeywordUsing = 152,
  kKeywordVirtual = 153,
  kKeywordWcharT = 154,
  kKeywordAlignas = 155,
  kKeywordAlignof = 156,
  kKeywordChar16T = 157,
  kKeywordChar32T = 158,
  kKeywordConstexpr = 159,
  kKeywordDecltype = 160,
  kKeywordNoexcept = 161,
  kKeywordNullptr = 162,
  kKeywordStaticAssert = 163,
  kKeywordThreadLocal = 164,
  kKeywordConcept = 165,
  kKeywordRequires = 166,
  kKeywordCoAwait = 167,
  kKeywordCoReturn = 168,
  kKeywordCoYield = 169,
  kKeywordModule = 170,
  kKeywordImport = 171,
  kKeywordConsteval = 172,
  kKeywordConstinit = 173,
  kKeywordChar8T = 174,
  kKeyword_Float16 = 175,
  kKeyword_Accum = 176,
  kKeyword_Fract = 177,
  kKeyword_Sat = 178,
  kKeyword_Decimal32 = 179,
  kKeyword_Decimal64 = 180,
  kKeyword_Decimal128 = 181,
  kKeyword__Null = 182,
  kKeyword__Alignof = 183,
  kKeyword__Attribute = 184,
  kKeyword__BuiltinChooseExpression = 185,
  kKeyword__BuiltinOffsetof = 186,
  kKeyword__BuiltinFILE = 187,
  kKeyword__BuiltinFUNCTION = 188,
  kKeyword__BuiltinLINE = 189,
  kKeyword__BuiltinCOLUMN = 190,
  kKeyword__BuiltinSourceToken = 191,
  kKeyword__BuiltinTypesCompatibleP = 192,
  kKeyword__BuiltinVaArgument = 193,
  kKeyword__Extension__ = 194,
  kKeyword__Float128 = 195,
  kKeyword__Ibm128 = 196,
  kKeyword__Imag = 197,
  kKeyword__Int128 = 198,
  kKeyword__Label__ = 199,
  kKeyword__Real = 200,
  kKeyword__Thread = 201,
  kKeyword__FUNCTION__ = 202,
  kKeyword__PRETTYFUNCTION__ = 203,
  kKeyword__AutoType = 204,
  kKeywordTypeof = 205,
  kKeyword__FUNCDNAME__ = 206,
  kKeyword__FUNCSIG__ = 207,
  kKeywordLFUNCTION__ = 208,
  kKeywordLFUNCSIG__ = 209,
  kKeyword__IsInterfaceClass = 210,
  kKeyword__IsSealed = 211,
  kKeyword__IsDestructible = 212,
  kKeyword__IsTriviallyDestructible = 213,
  kKeyword__IsNothrowDestructible = 214,
  kKeyword__IsNothrowAssignable = 215,
  kKeyword__IsConstructible = 216,
  kKeyword__IsNothrowConstructible = 217,
  kKeyword__IsAssignable = 218,
  kKeyword__HasNothrowMoveAssign = 219,
  kKeyword__HasTrivialMoveAssign = 220,
  kKeyword__HasTrivialMoveConstructor = 221,
  kKeyword__HasNothrowAssign = 222,
  kKeyword__HasNothrowCopy = 223,
  kKeyword__HasNothrowConstructor = 224,
  kKeyword__HasTrivialAssign = 225,
  kKeyword__HasTrivialCopy = 226,
  kKeyword__HasTrivialConstructor = 227,
  kKeyword__HasTrivialDestructor = 228,
  kKeyword__HasVirtualDestructor = 229,
  kKeyword__IsAbstract = 230,
  kKeyword__IsAggregate = 231,
  kKeyword__IsBaseOf = 232,
  kKeyword__IsClass = 233,
  kKeyword__IsConvertibleTo = 234,
  kKeyword__IsEmpty = 235,
  kKeyword__IsEnum = 236,
  kKeyword__IsFinal = 237,
  kKeyword__IsLiteral = 238,
  kKeyword__IsPod = 239,
  kKeyword__IsPolymorphic = 240,
  kKeyword__IsStandardLayout = 241,
  kKeyword__IsTrivial = 242,
  kKeyword__IsTriviallyAssignable = 243,
  kKeyword__IsTriviallyConstructible = 244,
  kKeyword__IsTriviallyCopyable = 245,
  kKeyword__IsUnion = 246,
  kKeyword__HasUniqueObjectRepresentations = 247,
  kKeyword__UnderlyingType = 248,
  kKeyword__IsTriviallyRelocatable = 249,
  kKeyword__ReferenceBindsToTemporary = 250,
  kKeyword__IsLvalueExpression = 251,
  kKeyword__IsRvalueExpression = 252,
  kKeyword__IsArithmetic = 253,
  kKeyword__IsFloatingPoint = 254,
  kKeyword__IsIntegral = 255,
  kKeyword__IsCompleteType = 256,
  kKeyword__IsVoid = 257,
  kKeyword__IsArray = 258,
  kKeyword__IsFunction = 259,
  kKeyword__IsReference = 260,
  kKeyword__IsLvalueReference = 261,
  kKeyword__IsRvalueReference = 262,
  kKeyword__IsFundamental = 263,
  kKeyword__IsObject = 264,
  kKeyword__IsScalar = 265,
  kKeyword__IsCompound = 266,
  kKeyword__IsPointer = 267,
  kKeyword__IsMemberObjectPointer = 268,
  kKeyword__IsMemberFunctionPointer = 269,
  kKeyword__IsMemberPointer = 270,
  kKeyword__IsConst = 271,
  kKeyword__IsVolatile = 272,
  kKeyword__IsSigned = 273,
  kKeyword__IsUnsigned = 274,
  kKeyword__IsSame = 275,
  kKeyword__IsConvertible = 276,
  kKeyword__ArrayRank = 277,
  kKeyword__ArrayExtent = 278,
  kKeyword__PrivateExtern__ = 279,
  kKeyword__ModulePrivate__ = 280,
  kKeyword__Declspec = 281,
  kKeyword__Cdecl = 282,
  kKeyword__Stdcall = 283,
  kKeyword__Fastcall = 284,
  kKeyword__Thiscall = 285,
  kKeyword__Regcall = 286,
  kKeyword__Vectorcall = 287,
  kKeyword__Forceinline = 288,
  kKeyword__Unaligned = 289,
  kKeyword__Super = 290,
  kKeyword__Global = 291,
  kKeyword__Local = 292,
  kKeyword__Constant = 293,
  kKeyword__Private = 294,
  kKeyword__Generic = 295,
  kKeyword__Kernel = 296,
  kKeyword__ReadOnly = 297,
  kKeyword__WriteOnly = 298,
  kKeyword__ReadWrite = 299,
  kKeyword__BuiltinAstype = 300,
  kKeywordVecStep = 301,
  kKeywordImage1dT = 302,
  kKeywordImage1dArrayT = 303,
  kKeywordImage1dBufferT = 304,
  kKeywordImage2dT = 305,
  kKeywordImage2dArrayT = 306,
  kKeywordImage2dDepthT = 307,
  kKeywordImage2dArrayDepthT = 308,
  kKeywordImage2dMsaaT = 309,
  kKeywordImage2dArrayMsaaT = 310,
  kKeywordImage2dMsaaDepthT = 311,
  kKeywordImage2dArrayMsaaDepthT = 312,
  kKeywordImage3dT = 313,
  kKeywordPipe = 314,
  kKeywordAddrspaceCast = 315,
  kKeyword__Noinline__ = 316,
  kKeyword__BuiltinOmpRequiredSimdAlign = 317,
  kKeyword__Pascal = 318,
  kKeyword__Vector = 319,
  kKeyword__Pixel = 320,
  kKeyword__Boolean = 321,
  kKeyword__Bf16 = 322,
  kKeywordHalf = 323,
  kKeyword__Bridge = 324,
  kKeyword__BridgeTransfer = 325,
  kKeyword__BridgeRetained = 326,
  kKeyword__BridgeRetain = 327,
  kKeyword__Covariant = 328,
  kKeyword__Contravariant = 329,
  kKeyword__Kindof = 330,
  kKeyword_Nonnull = 331,
  kKeyword_Nullable = 332,
  kKeyword_NullableResult = 333,
  kKeyword_NullUnspecified = 334,
  kKeyword__Ptr64 = 335,
  kKeyword__Ptr32 = 336,
  kKeyword__Sptr = 337,
  kKeyword__Uptr = 338,
  kKeyword__W64 = 339,
  kKeyword__Uuidof = 340,
  kKeyword__Try = 341,
  kKeyword__Finally = 342,
  kKeyword__Leave = 343,
  kKeyword__Int64 = 344,
  kKeyword__IfExists = 345,
  kKeyword__IfNotExists = 346,
  kKeyword__SingleInheritance = 347,
  kKeyword__MultipleInheritance = 348,
  kKeyword__VirtualInheritance = 349,
  kKeyword__Interface = 350,
  kKeyword__BuiltinConvertvector = 351,
  kKeyword__BuiltinBitCast = 352,
  kKeyword__BuiltinAvailable = 353,
  kKeyword__BuiltinSyclUniqueStableName = 354,
  kKeyword__UnknownAnytype = 355,
  kAnnotCxxscope = 356,
  kAnnotTypename = 357,
  kAnnotTemplateId = 358,
  kAnnotNonType = 359,
  kAnnotNonTypeUndeclared = 360,
  kAnnotNonTypeDependent = 361,
  kAnnotOverload = 362,
  kAnnotPrimaryExpression = 363,
  kAnnotDecltype = 364,
  kAnnotPragmaUnused = 365,
  kAnnotPragmaVis = 366,
  kAnnotPragmaPack = 367,
  kAnnotPragmaParserCrash = 368,
  kAnnotPragmaCaptured = 369,
  kAnnotPragmaDump = 370,
  kAnnotPragmaMsstruct = 371,
  kAnnotPragmaAlign = 372,
  kAnnotPragmaWeak = 373,
  kAnnotPragmaWeakalias = 374,
  kAnnotPragmaRedefineExtname = 375,
  kAnnotPragmaFpContract = 376,
  kAnnotPragmaFenvAccess = 377,
  kAnnotPragmaFenvAccessMs = 378,
  kAnnotPragmaFenvRound = 379,
  kAnnotPragmaFloatControl = 380,
  kAnnotPragmaMsPointersToMembers = 381,
  kAnnotPragmaMsVtordisp = 382,
  kAnnotPragmaMsPragma = 383,
  kAnnotPragmaOpenclExtension = 384,
  kAnnotAttributeOpenmp = 385,
  kAnnotPragmaOpenmp = 386,
  kAnnotPragmaOpenmpEnd = 387,
  kAnnotPragmaLoopHint = 388,
  kAnnotPragmaFp = 389,
  kAnnotPragmaAttribute = 390,
  kAnnotPragmaRiscv = 391,
  kAnnotModuleInclude = 392,
  kAnnotModuleBegin = 393,
  kAnnotModuleEnd = 394,
  kAnnotHeaderUnit = 395,
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
  kBTFTagAttributed = 8,
  kBitInt = 9,
  kBlockPointer = 10,
  kBuiltin = 11,
  kComplex = 12,
  kDecltype = 13,
  kAuto = 14,
  kDeducedTemplateSpecialization = 15,
  kDependentAddressSpace = 16,
  kDependentBitInt = 17,
  kDependentName = 18,
  kDependentSizedExtVector = 19,
  kDependentTemplateSpecialization = 20,
  kDependentVector = 21,
  kElaborated = 22,
  kFunctionNoProto = 23,
  kFunctionProto = 24,
  kInjectedClassName = 25,
  kMacroQualified = 26,
  kConstantMatrix = 27,
  kDependentSizedMatrix = 28,
  kMemberPointer = 29,
  kObjCObjectPointer = 30,
  kObjCObject = 31,
  kObjCInterface = 32,
  kObjCTypeParameter = 33,
  kPackExpansion = 34,
  kParenthesis = 35,
  kPipe = 36,
  kPointer = 37,
  kLValueReference = 38,
  kRValueReference = 39,
  kSubstTemplateTypeParmPack = 40,
  kSubstTemplateTypeParm = 41,
  kEnum = 42,
  kRecord = 43,
  kTemplateSpecialization = 44,
  kTemplateTypeParm = 45,
  kTypeOfExpression = 46,
  kTypeOf = 47,
  kTypedef = 48,
  kUnaryTransform = 49,
  kUnresolvedUsing = 50,
  kUsing = 51,
  kVector = 52,
  kExtVector = 53,
  kQualified = 54,
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
  kBitint = 9,
  kHalf = 10,
  kFloat16 = 11,
  kAccum = 12,
  kFract = 13,
  kBFloat16 = 14,
  kFloat = 15,
  kDouble = 16,
  kFloat128 = 17,
  kIbm128 = 18,
  kBoolean = 19,
  kDecimal32 = 20,
  kDecimal64 = 21,
  kDecimal128 = 22,
  kEnum = 23,
  kUnion = 24,
  kStruct = 25,
  kClass = 26,
  kInterface = 27,
  kTypename = 28,
  kTypeofType = 29,
  kTypeofExpression = 30,
  kDecltype = 31,
  kUnderlyingType = 32,
  kAuto = 33,
  kDecltypeAuto = 34,
  kAutoType = 35,
  kUnknownAnytype = 36,
  kAtomic = 37,
  kImage1dT = 38,
  kImage1dArrayT = 39,
  kImage1dBufferT = 40,
  kImage2dT = 41,
  kImage2dArrayT = 42,
  kImage2dDepthT = 43,
  kImage2dArrayDepthT = 44,
  kImage2dMsaaT = 45,
  kImage2dArrayMsaaT = 46,
  kImage2dMsaaDepthT = 47,
  kImage2dArrayMsaaDepthT = 48,
  kImage3dT = 49,
  kError = 50,
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
  kIsTriviallyRelocatable = 30,
  kIsArithmetic = 31,
  kIsFloatingPoint = 32,
  kIsIntegral = 33,
  kIsCompleteType = 34,
  kIsVoid = 35,
  kIsArray = 36,
  kIsFunction = 37,
  kIsReference = 38,
  kIsLvalueReference = 39,
  kIsRvalueReference = 40,
  kIsFundamental = 41,
  kIsObject = 42,
  kIsScalar = 43,
  kIsCompound = 44,
  kIsPointer = 45,
  kIsMemberObjectPointer = 46,
  kIsMemberFunctionPointer = 47,
  kIsMemberPointer = 48,
  kIsConst = 49,
  kIsVolatile = 50,
  kIsSigned = 51,
  kIsUnsigned = 52,
  kTypeCompatible = 53,
  kIsNothrowAssignable = 54,
  kIsAssignable = 55,
  kIsBaseOf = 56,
  kIsConvertibleTo = 57,
  kIsTriviallyAssignable = 58,
  kReferenceBindsToTemporary = 59,
  kIsSame = 60,
  kIsConvertible = 61,
  kIsConstructible = 62,
  kIsNothrowConstructible = 63,
  kIsTriviallyConstructible = 64,
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
  kAddressOf = 4,
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
  kAddressLabelDiff = 13,
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
    m(OMPGenericLoopDirective) \
    m(OMPMaskedTaskLoopDirective) \
    m(OMPMaskedTaskLoopSimdDirective) \
    m(OMPMasterTaskLoopDirective) \
    m(OMPMasterTaskLoopSimdDirective) \
    m(OMPParallelForDirective) \
    m(OMPParallelForSimdDirective) \
    m(OMPParallelGenericLoopDirective) \
    m(OMPParallelMaskedTaskLoopDirective) \
    m(OMPParallelMaskedTaskLoopSimdDirective) \
    m(OMPParallelMasterTaskLoopDirective) \
    m(OMPParallelMasterTaskLoopSimdDirective) \
    m(OMPSimdDirective) \
    m(OMPTargetParallelForSimdDirective) \
    m(OMPTargetParallelGenericLoopDirective) \
    m(OMPTargetSimdDirective) \
    m(OMPTargetTeamsDistributeDirective) \
    m(OMPTargetTeamsDistributeParallelForDirective) \
    m(OMPTargetTeamsDistributeParallelForSimdDirective) \
    m(OMPTargetTeamsDistributeSimdDirective) \
    m(OMPTargetTeamsGenericLoopDirective) \
    m(OMPTaskLoopDirective) \
    m(OMPTaskLoopSimdDirective) \
    m(OMPTeamsDistributeDirective) \
    m(OMPTeamsDistributeParallelForDirective) \
    m(OMPTeamsDistributeParallelForSimdDirective) \
    m(OMPTeamsDistributeSimdDirective) \
    m(OMPTeamsGenericLoopDirective) \
    m(OMPTileDirective) \
    m(OMPUnrollDirective) \
    m(OMPMaskedDirective) \
    m(OMPMasterDirective) \
    m(OMPMetaDirective) \
    m(OMPOrderedDirective) \
    m(OMPParallelDirective) \
    m(OMPParallelMaskedDirective) \
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
    PASTA_FOR_EACH_TYPE_IMPL(m, PASTA_IGNORE_ABSTRACT)

#define PASTA_FOR_EACH_ATTR_KIND(m) \
    PASTA_FOR_EACH_ATTR_IMPL(m, PASTA_IGNORE_ABSTRACT)

class OMPDeclarativeDirectiveDecl;
class OMPDeclarativeDirectiveValueDecl;
class ExceptionSpecification;
class AArch64SVEPcsAttr;
class AArch64VectorPcsAttr;
class AMDGPUFlatWorkGroupSizeAttr;
class AMDGPUKernelCallAttr;
class AMDGPUNumSGPRAttr;
class AMDGPUNumVGPRAttr;
class AMDGPUWavesPerEUAttr;
class ARMInterruptAttr;
class AVRInterruptAttr;
class AVRSignalAttr;
class AbiTagAttr;
class AbstractConditionalOperator;
class AccessSpecDecl;
class AcquireCapabilityAttr;
class AcquireHandleAttr;
class AcquiredAfterAttr;
class AcquiredBeforeAttr;
class AddrLabelExpr;
class AddressSpaceAttr;
class AdjustedType;
class AliasAttr;
class AlignMac68kAttr;
class AlignNaturalAttr;
class AlignValueAttr;
class AlignedAttr;
class AllocAlignAttr;
class AllocSizeAttr;
class AlwaysDestroyAttr;
class AlwaysInlineAttr;
class AnalyzerNoReturnAttr;
class AnnotateAttr;
class AnnotateTypeAttr;
class AnyX86InterruptAttr;
class AnyX86NoCallerSavedRegistersAttr;
class AnyX86NoCfCheckAttr;
class ArcWeakrefUnavailableAttr;
class ArgumentWithTypeTagAttr;
class ArmBuiltinAliasAttr;
class ArmMveStrictPolymorphismAttr;
class ArrayInitIndexExpr;
class ArrayInitLoopExpr;
class ArraySubscriptExpr;
class ArrayType;
class ArrayTypeTraitExpr;
class ArtificialAttr;
class AsTypeExpr;
class AsmLabelAttr;
class AsmStmt;
class AssertCapabilityAttr;
class AssertExclusiveLockAttr;
class AssertSharedLockAttr;
class AssumeAlignedAttr;
class AssumptionAttr;
class AtomicExpr;
class AtomicType;
class Attr;
class AttributedStmt;
class AttributedType;
class AutoType;
class AvailabilityAttr;
class BPFPreserveAccessIndexAttr;
class BTFDeclTagAttr;
class BTFTagAttributedType;
class BTFTypeTagAttr;
class BaseUsingDecl;
class BinaryConditionalOperator;
class BinaryOperator;
class BindingDecl;
class BitIntType;
class BlockDecl;
class BlockExpr;
class BlockPointerType;
class BlocksAttr;
class BreakStmt;
class BuiltinAliasAttr;
class BuiltinAttr;
class BuiltinBitCastExpr;
class BuiltinTemplateDecl;
class BuiltinType;
class C11NoReturnAttr;
class CDeclAttr;
class CFAuditedTransferAttr;
class CFConsumedAttr;
class CFGuardAttr;
class CFICanonicalJumpTableAttr;
class CFReturnsNotRetainedAttr;
class CFReturnsRetainedAttr;
class CFUnknownTransferAttr;
class CPUDispatchAttr;
class CPUSpecificAttr;
class CStyleCastExpr;
class CUDAConstantAttr;
class CUDADeviceAttr;
class CUDADeviceBuiltinSurfaceTypeAttr;
class CUDADeviceBuiltinTextureTypeAttr;
class CUDAGlobalAttr;
class CUDAHostAttr;
class CUDAInvalidTargetAttr;
class CUDAKernelCallExpr;
class CUDALaunchBoundsAttr;
class CUDASharedAttr;
class CXX11NoReturnAttr;
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
class CallableWhenAttr;
class CallbackAttr;
class CalledOnceAttr;
class CapabilityAttr;
class CapturedDecl;
class CapturedRecordAttr;
class CapturedStmt;
class CarriesDependencyAttr;
class CaseStmt;
class CastExpr;
class CharacterLiteral;
class ChooseExpr;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class CleanupAttr;
class CmseNSCallAttr;
class CmseNSEntryAttr;
class CoawaitExpr;
class CodeSegAttr;
class ColdAttr;
class CommonAttr;
class ComplexType;
class CompoundAssignOperator;
class CompoundLiteralExpr;
class CompoundStmt;
class ConceptDecl;
class ConceptSpecializationExpr;
class ConditionalOperator;
class ConstAttr;
class ConstInitAttr;
class ConstantArrayType;
class ConstantExpr;
class ConstantMatrixType;
class ConstructorAttr;
class ConstructorUsingShadowDecl;
class ConsumableAttr;
class ConsumableAutoCastAttr;
class ConsumableSetOnReadAttr;
class ContinueStmt;
class ConvergentAttr;
class ConvertVectorExpr;
class CoreturnStmt;
class CoroutineBodyStmt;
class CoroutineSuspendExpr;
class CoyieldExpr;
class DLLExportAttr;
class DLLExportStaticLocalAttr;
class DLLImportAttr;
class DLLImportStaticLocalAttr;
class DecayedType;
class Decl;
class DeclContext;
class DeclOrStmtAttr;
class DeclRefExpr;
class DeclStmt;
class DeclaratorDecl;
class DecltypeType;
class DecompositionDecl;
class DeducedTemplateSpecializationType;
class DeducedType;
class DefaultStmt;
class DependentAddressSpaceType;
class DependentBitIntType;
class DependentCoawaitExpr;
class DependentNameType;
class DependentScopeDeclRefExpr;
class DependentSizedArrayType;
class DependentSizedExtVectorType;
class DependentSizedMatrixType;
class DependentTemplateSpecializationType;
class DependentVectorType;
class DeprecatedAttr;
class DesignatedInitExpr;
class DesignatedInitUpdateExpr;
class DestructorAttr;
class DiagnoseAsBuiltinAttr;
class DiagnoseIfAttr;
class DisableSanitizerInstrumentationAttr;
class DisableTailCallsAttr;
class DoStmt;
class ElaboratedType;
class EmptyBasesAttr;
class EmptyDecl;
class EnableIfAttr;
class EnforceTCBAttr;
class EnforceTCBLeafAttr;
class EnumConstantDecl;
class EnumDecl;
class EnumExtensibilityAttr;
class EnumType;
class ErrorAttr;
class ExcludeFromExplicitInstantiationAttr;
class ExclusiveTrylockFunctionAttr;
class ExplicitCastExpr;
class ExportDecl;
class Expr;
class ExprWithCleanups;
class ExpressionTraitExpr;
class ExtVectorElementExpr;
class ExtVectorType;
class ExternCContextDecl;
class ExternalSourceSymbolAttr;
class FallThroughAttr;
class FastCallAttr;
class FieldDecl;
class FileScopeAsmDecl;
class FinalAttr;
class FixedPointLiteral;
class FlagEnumAttr;
class FlattenAttr;
class FloatingLiteral;
class ForStmt;
class FormatArgAttr;
class FormatAttr;
class FriendDecl;
class FriendTemplateDecl;
class FullExpr;
class FunctionDecl;
class FunctionNoProtoType;
class FunctionParmPackExpr;
class FunctionProtoType;
class FunctionReturnThunksAttr;
class FunctionTemplateDecl;
class FunctionTemplateSpecializationInfo;
class FunctionType;
class GCCAsmStmt;
class GNUInlineAttr;
class GNUNullExpr;
class GenericSelectionExpr;
class GotoStmt;
class GuardedByAttr;
class GuardedVarAttr;
class HIPManagedAttr;
class HLSLNumThreadsAttr;
class HLSLSV_GroupIndexAttr;
class HLSLShaderAttr;
class HotAttr;
class IBActionAttr;
class IBOutletAttr;
class IBOutletCollectionAttr;
class IFuncAttr;
class IfStmt;
class ImaginaryLiteral;
class ImplicitCastExpr;
class ImplicitParamDecl;
class ImplicitValueInitExpr;
class ImportDecl;
class IncompleteArrayType;
class IndirectFieldDecl;
class IndirectGotoStmt;
class InheritableAttr;
class InheritableParamAttr;
class InitListExpr;
class InitPriorityAttr;
class InitSegAttr;
class InjectedClassNameType;
class IntegerLiteral;
class IntelOclBiccAttr;
class InternalLinkageAttr;
class LTOVisibilityPublicAttr;
class LValueReferenceType;
class LabelDecl;
class LabelStmt;
class LambdaExpr;
class LayoutVersionAttr;
class LeafAttr;
class LifetimeBoundAttr;
class LifetimeExtendedTemporaryDecl;
class LikelyAttr;
class LinkageSpecDecl;
class LoaderUninitializedAttr;
class LockReturnedAttr;
class LocksExcludedAttr;
class LoopHintAttr;
class M68kInterruptAttr;
class MIGServerRoutineAttr;
class MSABIAttr;
class MSAllocatorAttr;
class MSAsmStmt;
class MSDependentExistsStmt;
class MSGuidDecl;
class MSInheritanceAttr;
class MSNoVTableAttr;
class MSP430InterruptAttr;
class MSPropertyDecl;
class MSPropertyRefExpr;
class MSPropertySubscriptExpr;
class MSStructAttr;
class MSVtorDispAttr;
class MacroQualifiedType;
class MaterializeTemporaryExpr;
class MatrixSubscriptExpr;
class MatrixType;
class MaxFieldAlignmentAttr;
class MayAliasAttr;
class MemberExpr;
class MemberPointerType;
class MicroMipsAttr;
class MinSizeAttr;
class MinVectorWidthAttr;
class Mips16Attr;
class MipsInterruptAttr;
class MipsLongCallAttr;
class MipsShortCallAttr;
class ModeAttr;
class MustTailAttr;
class NSConsumedAttr;
class NSConsumesSelfAttr;
class NSErrorDomainAttr;
class NSReturnsAutoreleasedAttr;
class NSReturnsNotRetainedAttr;
class NSReturnsRetainedAttr;
class NakedAttr;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NoAliasAttr;
class NoBuiltinAttr;
class NoCommonAttr;
class NoDebugAttr;
class NoDerefAttr;
class NoDestroyAttr;
class NoDuplicateAttr;
class NoEscapeAttr;
class NoInitExpr;
class NoInlineAttr;
class NoInstrumentFunctionAttr;
class NoMergeAttr;
class NoMicroMipsAttr;
class NoMips16Attr;
class NoProfileFunctionAttr;
class NoRandomizeLayoutAttr;
class NoReturnAttr;
class NoSanitizeAttr;
class NoSpeculativeLoadHardeningAttr;
class NoSplitStackAttr;
class NoStackProtectorAttr;
class NoThreadSafetyAnalysisAttr;
class NoThrowAttr;
class NoUniqueAddressAttr;
class NonNullAttr;
class NonTypeTemplateParmDecl;
class NotTailCalledAttr;
class NullStmt;
class OMPAllocateDecl;
class OMPAllocateDeclAttr;
class OMPArraySectionExpr;
class OMPArrayShapingExpr;
class OMPAtomicDirective;
class OMPBarrierDirective;
class OMPCancelDirective;
class OMPCancellationPointDirective;
class OMPCanonicalLoop;
class OMPCaptureKindAttr;
class OMPCaptureNoInitAttr;
class OMPCapturedExprDecl;
class OMPCriticalDirective;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPDeclareSimdDeclAttr;
class OMPDeclareTargetDeclAttr;
class OMPDeclareVariantAttr;
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
class OMPGenericLoopDirective;
class OMPInteropDirective;
class OMPIteratorExpr;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPLoopTransformationDirective;
class OMPMaskedDirective;
class OMPMaskedTaskLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class OMPMasterDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPMetaDirective;
class OMPOrderedDirective;
class OMPParallelDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelGenericLoopDirective;
class OMPParallelMaskedDirective;
class OMPParallelMaskedTaskLoopDirective;
class OMPParallelMaskedTaskLoopSimdDirective;
class OMPParallelMasterDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPParallelSectionsDirective;
class OMPReferencedVarAttr;
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
class OMPTargetParallelGenericLoopDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetTeamsGenericLoopDirective;
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
class OMPTeamsGenericLoopDirective;
class OMPThreadPrivateDecl;
class OMPThreadPrivateDeclAttr;
class OMPTileDirective;
class OMPUnrollDirective;
class OSConsumedAttr;
class OSConsumesThisAttr;
class OSReturnsNotRetainedAttr;
class OSReturnsRetainedAttr;
class OSReturnsRetainedOnNonZeroAttr;
class OSReturnsRetainedOnZeroAttr;
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
class ObjCBoxableAttr;
class ObjCBoxedExpr;
class ObjCBridgeAttr;
class ObjCBridgeMutableAttr;
class ObjCBridgeRelatedAttr;
class ObjCBridgedCastExpr;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCClassStubAttr;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCDesignatedInitializerAttr;
class ObjCDictionaryLiteral;
class ObjCDirectAttr;
class ObjCDirectMembersAttr;
class ObjCEncodeExpr;
class ObjCExceptionAttr;
class ObjCExplicitProtocolImplAttr;
class ObjCExternallyRetainedAttr;
class ObjCForCollectionStmt;
class ObjCGCAttr;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCIndependentClassAttr;
class ObjCIndirectCopyRestoreExpr;
class ObjCInertUnsafeUnretainedAttr;
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCIsaExpr;
class ObjCIvarDecl;
class ObjCIvarRefExpr;
class ObjCKindOfAttr;
class ObjCMessageExpr;
class ObjCMethodDecl;
class ObjCMethodFamilyAttr;
class ObjCNSObjectAttr;
class ObjCNonLazyClassAttr;
class ObjCNonRuntimeProtocolAttr;
class ObjCObjectPointerType;
class ObjCObjectType;
class ObjCOwnershipAttr;
class ObjCPreciseLifetimeAttr;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCPropertyRefExpr;
class ObjCProtocolDecl;
class ObjCProtocolExpr;
class ObjCRequiresPropertyDefsAttr;
class ObjCRequiresSuperAttr;
class ObjCReturnsInnerPointerAttr;
class ObjCRootClassAttr;
class ObjCRuntimeNameAttr;
class ObjCRuntimeVisibleAttr;
class ObjCSelectorExpr;
class ObjCStringLiteral;
class ObjCSubclassingRestrictedAttr;
class ObjCSubscriptRefExpr;
class ObjCTypeParamDecl;
class ObjCTypeParamType;
class OffsetOfExpr;
class OpaqueValueExpr;
class OpenCLAccessAttr;
class OpenCLConstantAddressSpaceAttr;
class OpenCLGenericAddressSpaceAttr;
class OpenCLGlobalAddressSpaceAttr;
class OpenCLGlobalDeviceAddressSpaceAttr;
class OpenCLGlobalHostAddressSpaceAttr;
class OpenCLIntelReqdSubGroupSizeAttr;
class OpenCLKernelAttr;
class OpenCLLocalAddressSpaceAttr;
class OpenCLPrivateAddressSpaceAttr;
class OpenCLUnrollHintAttr;
class OptimizeNoneAttr;
class OverloadExpr;
class OverloadableAttr;
class OverrideAttr;
class OwnerAttr;
class OwnershipAttr;
class PackExpansionExpr;
class PackExpansionType;
class PackedAttr;
class ParamTypestateAttr;
class ParameterABIAttr;
class ParenExpr;
class ParenListExpr;
class ParenType;
class ParmVarDecl;
class PascalAttr;
class PassObjectSizeAttr;
class PatchableFunctionEntryAttr;
class PcsAttr;
class PipeType;
class PointerAttr;
class PointerType;
class PragmaClangBSSSectionAttr;
class PragmaClangDataSectionAttr;
class PragmaClangRelroSectionAttr;
class PragmaClangRodataSectionAttr;
class PragmaClangTextSectionAttr;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class PredefinedExpr;
class PreferredNameAttr;
class PreserveAllAttr;
class PreserveMostAttr;
class PseudoObjectExpr;
class PtGuardedByAttr;
class PtGuardedVarAttr;
class Ptr32Attr;
class Ptr64Attr;
class PureAttr;
class QualifiedType;
class RISCVInterruptAttr;
class RValueReferenceType;
class RandomizeLayoutAttr;
class RecordDecl;
class RecordType;
class RecoveryExpr;
class RedeclarableTemplateDecl;
class ReferenceType;
class RegCallAttr;
class ReinitializesAttr;
class ReleaseCapabilityAttr;
class ReleaseHandleAttr;
class RenderScriptKernelAttr;
class ReqdWorkGroupSizeAttr;
class RequiresCapabilityAttr;
class RequiresExpr;
class RequiresExprBodyDecl;
class RestrictAttr;
class RetainAttr;
class ReturnStmt;
class ReturnTypestateAttr;
class ReturnsNonNullAttr;
class ReturnsTwiceAttr;
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHLeaveStmt;
class SEHTryStmt;
class SPtrAttr;
class SYCLKernelAttr;
class SYCLSpecialClassAttr;
class SYCLUniqueStableNameExpr;
class ScopedLockableAttr;
class SectionAttr;
class SelectAnyAttr;
class SentinelAttr;
class SetTypestateAttr;
class SharedTrylockFunctionAttr;
class ShuffleVectorExpr;
class SizeOfPackExpr;
class SourceLocExpr;
class SpeculativeLoadHardeningAttr;
class StandaloneDebugAttr;
class StaticAssertDecl;
class StdCallAttr;
class Stmt;
class StmtAttr;
class StmtExpr;
class StrictFPAttr;
class StringLiteral;
class SubstNonTypeTemplateParmExpr;
class SubstNonTypeTemplateParmPackExpr;
class SubstTemplateTypeParmPackType;
class SubstTemplateTypeParmType;
class SuppressAttr;
class SwiftAsyncAttr;
class SwiftAsyncCallAttr;
class SwiftAsyncContextAttr;
class SwiftAsyncErrorAttr;
class SwiftAsyncNameAttr;
class SwiftAttrAttr;
class SwiftBridgeAttr;
class SwiftBridgedTypedefAttr;
class SwiftCallAttr;
class SwiftContextAttr;
class SwiftErrorAttr;
class SwiftErrorResultAttr;
class SwiftIndirectResultAttr;
class SwiftNameAttr;
class SwiftNewTypeAttr;
class SwiftObjCMembersAttr;
class SwiftPrivateAttr;
class SwitchCase;
class SwitchStmt;
class SysVABIAttr;
class TLSModelAttr;
class TagDecl;
class TagType;
class TargetAttr;
class TargetClonesAttr;
class TemplateArgument;
class TemplateDecl;
class TemplateParamObjectDecl;
class TemplateSpecializationType;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TemplateTypeParmType;
class TestTypestateAttr;
class ThisCallAttr;
class ThreadAttr;
class TranslationUnitDecl;
class TransparentUnionAttr;
class TrivialABIAttr;
class TryAcquireCapabilityAttr;
class Type;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeAttr;
class TypeDecl;
class TypeNonNullAttr;
class TypeNullUnspecifiedAttr;
class TypeNullableAttr;
class TypeNullableResultAttr;
class TypeOfExprType;
class TypeOfType;
class TypeSourceInfo;
class TypeTagForDatatypeAttr;
class TypeTraitExpr;
class TypeVisibilityAttr;
class TypeWithKeyword;
class TypedefDecl;
class TypedefNameDecl;
class TypedefType;
class TypoExpr;
class UPtrAttr;
class UnaryExprOrTypeTraitExpr;
class UnaryOperator;
class UnaryTransformType;
class UnavailableAttr;
class UninitializedAttr;
class UnlikelyAttr;
class UnnamedGlobalConstantDecl;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class UnresolvedUsingIfExistsDecl;
class UnresolvedUsingType;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UnusedAttr;
class UseHandleAttr;
class UsedAttr;
class UserDefinedLiteral;
class UsingDecl;
class UsingDirectiveDecl;
class UsingEnumDecl;
class UsingIfExistsAttr;
class UsingPackDecl;
class UsingShadowDecl;
class UsingType;
class UuidAttr;
class VAArgExpr;
class ValueDecl;
class ValueStmt;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
class VariableArrayType;
class VecReturnAttr;
class VecTypeHintAttr;
class VectorCallAttr;
class VectorType;
class VisibilityAttr;
class WarnUnusedAttr;
class WarnUnusedResultAttr;
class WeakAttr;
class WeakImportAttr;
class WeakRefAttr;
class WebAssemblyExportNameAttr;
class WebAssemblyImportModuleAttr;
class WebAssemblyImportNameAttr;
class WhileStmt;
class WorkGroupSizeHintAttr;
class X86ForceAlignArgPointerAttr;
class XRayInstrumentAttr;
class XRayLogArgsAttr;
class ZeroCallUsedRegsAttr;
}  // namespace pasta
