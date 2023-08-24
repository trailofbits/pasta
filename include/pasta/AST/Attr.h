/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#ifndef PASTA_IN_BOOTSTRAP
#include <variant>
#include <vector>
#include <pasta/Util/Compiler.h>

#include "AttrManual.h"

#define PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(base) \
    friend class AST; \
    friend class ASTImpl; \
    friend class Decl; \
    friend class Stmt; \
    friend class DeclBuilder; \
    friend class AttrBuilder; \
    friend class AttrVisitor; \
    friend class PrintedTokenRange; \
    base(void) = delete; \
    explicit base( \
        std::shared_ptr<ASTImpl> ast_, \
        const ::clang::Attr *attr_); \
   public: \
    inline const clang::base *RawAttr(void) const noexcept { \
      return u.base; \
    }

namespace pasta {

class AST;
class ASTImpl;
class AttrBuilder;
class Decl;
class Decl;
class PrintedTokenRange;
class Stmt;

class AttrVisitor {
 public:
  virtual ~AttrVisitor(void);
  void Accept(const Attr &);
  virtual void VisitAttr(const Attr &);
  virtual void VisitBuiltinAliasAttr(const BuiltinAliasAttr &);
  virtual void VisitCalledOnceAttr(const CalledOnceAttr &);
  virtual void VisitIFuncAttr(const IFuncAttr &);
  virtual void VisitInheritableAttr(const InheritableAttr &);
  virtual void VisitInheritableParamAttr(const InheritableParamAttr &);
  virtual void VisitInitPriorityAttr(const InitPriorityAttr &);
  virtual void VisitInitSegAttr(const InitSegAttr &);
  virtual void VisitIntelOclBiccAttr(const IntelOclBiccAttr &);
  virtual void VisitInternalLinkageAttr(const InternalLinkageAttr &);
  virtual void VisitLTOVisibilityPublicAttr(const LTOVisibilityPublicAttr &);
  virtual void VisitLayoutVersionAttr(const LayoutVersionAttr &);
  virtual void VisitLeafAttr(const LeafAttr &);
  virtual void VisitLifetimeBoundAttr(const LifetimeBoundAttr &);
  virtual void VisitLoaderUninitializedAttr(const LoaderUninitializedAttr &);
  virtual void VisitLockReturnedAttr(const LockReturnedAttr &);
  virtual void VisitLocksExcludedAttr(const LocksExcludedAttr &);
  virtual void VisitLoopHintAttr(const LoopHintAttr &);
  virtual void VisitM68kInterruptAttr(const M68kInterruptAttr &);
  virtual void VisitMIGServerRoutineAttr(const MIGServerRoutineAttr &);
  virtual void VisitMSABIAttr(const MSABIAttr &);
  virtual void VisitMSAllocatorAttr(const MSAllocatorAttr &);
  virtual void VisitMSInheritanceAttr(const MSInheritanceAttr &);
  virtual void VisitMSNoVTableAttr(const MSNoVTableAttr &);
  virtual void VisitMSP430InterruptAttr(const MSP430InterruptAttr &);
  virtual void VisitMSStructAttr(const MSStructAttr &);
  virtual void VisitMSVtorDispAttr(const MSVtorDispAttr &);
  virtual void VisitMaxFieldAlignmentAttr(const MaxFieldAlignmentAttr &);
  virtual void VisitMayAliasAttr(const MayAliasAttr &);
  virtual void VisitMaybeUndefAttr(const MaybeUndefAttr &);
  virtual void VisitMicroMipsAttr(const MicroMipsAttr &);
  virtual void VisitMinSizeAttr(const MinSizeAttr &);
  virtual void VisitMinVectorWidthAttr(const MinVectorWidthAttr &);
  virtual void VisitMips16Attr(const Mips16Attr &);
  virtual void VisitMipsInterruptAttr(const MipsInterruptAttr &);
  virtual void VisitMipsLongCallAttr(const MipsLongCallAttr &);
  virtual void VisitMipsShortCallAttr(const MipsShortCallAttr &);
  virtual void VisitModeAttr(const ModeAttr &);
  virtual void VisitNSConsumedAttr(const NSConsumedAttr &);
  virtual void VisitNSConsumesSelfAttr(const NSConsumesSelfAttr &);
  virtual void VisitNSErrorDomainAttr(const NSErrorDomainAttr &);
  virtual void VisitNSReturnsAutoreleasedAttr(const NSReturnsAutoreleasedAttr &);
  virtual void VisitNSReturnsNotRetainedAttr(const NSReturnsNotRetainedAttr &);
  virtual void VisitNSReturnsRetainedAttr(const NSReturnsRetainedAttr &);
  virtual void VisitNakedAttr(const NakedAttr &);
  virtual void VisitNoAliasAttr(const NoAliasAttr &);
  virtual void VisitNoBuiltinAttr(const NoBuiltinAttr &);
  virtual void VisitNoCommonAttr(const NoCommonAttr &);
  virtual void VisitNoDebugAttr(const NoDebugAttr &);
  virtual void VisitNoDestroyAttr(const NoDestroyAttr &);
  virtual void VisitNoDuplicateAttr(const NoDuplicateAttr &);
  virtual void VisitNoEscapeAttr(const NoEscapeAttr &);
  virtual void VisitNoInstrumentFunctionAttr(const NoInstrumentFunctionAttr &);
  virtual void VisitNoMicroMipsAttr(const NoMicroMipsAttr &);
  virtual void VisitNoMips16Attr(const NoMips16Attr &);
  virtual void VisitNoProfileFunctionAttr(const NoProfileFunctionAttr &);
  virtual void VisitNoRandomizeLayoutAttr(const NoRandomizeLayoutAttr &);
  virtual void VisitNoReturnAttr(const NoReturnAttr &);
  virtual void VisitNoSanitizeAttr(const NoSanitizeAttr &);
  virtual void VisitNoSpeculativeLoadHardeningAttr(const NoSpeculativeLoadHardeningAttr &);
  virtual void VisitNoSplitStackAttr(const NoSplitStackAttr &);
  virtual void VisitNoStackProtectorAttr(const NoStackProtectorAttr &);
  virtual void VisitNoThreadSafetyAnalysisAttr(const NoThreadSafetyAnalysisAttr &);
  virtual void VisitNoThrowAttr(const NoThrowAttr &);
  virtual void VisitNoUniqueAddressAttr(const NoUniqueAddressAttr &);
  virtual void VisitNoUwtableAttr(const NoUwtableAttr &);
  virtual void VisitNonNullAttr(const NonNullAttr &);
  virtual void VisitNotTailCalledAttr(const NotTailCalledAttr &);
  virtual void VisitOMPAllocateDeclAttr(const OMPAllocateDeclAttr &);
  virtual void VisitOMPCaptureKindAttr(const OMPCaptureKindAttr &);
  virtual void VisitOMPCaptureNoInitAttr(const OMPCaptureNoInitAttr &);
  virtual void VisitOMPDeclareSimdDeclAttr(const OMPDeclareSimdDeclAttr &);
  virtual void VisitOMPDeclareTargetDeclAttr(const OMPDeclareTargetDeclAttr &);
  virtual void VisitOMPDeclareVariantAttr(const OMPDeclareVariantAttr &);
  virtual void VisitOMPReferencedVarAttr(const OMPReferencedVarAttr &);
  virtual void VisitOMPThreadPrivateDeclAttr(const OMPThreadPrivateDeclAttr &);
  virtual void VisitOSConsumedAttr(const OSConsumedAttr &);
  virtual void VisitOSConsumesThisAttr(const OSConsumesThisAttr &);
  virtual void VisitOSReturnsNotRetainedAttr(const OSReturnsNotRetainedAttr &);
  virtual void VisitOSReturnsRetainedAttr(const OSReturnsRetainedAttr &);
  virtual void VisitOSReturnsRetainedOnNonZeroAttr(const OSReturnsRetainedOnNonZeroAttr &);
  virtual void VisitOSReturnsRetainedOnZeroAttr(const OSReturnsRetainedOnZeroAttr &);
  virtual void VisitObjCBoxableAttr(const ObjCBoxableAttr &);
  virtual void VisitObjCBridgeAttr(const ObjCBridgeAttr &);
  virtual void VisitObjCBridgeMutableAttr(const ObjCBridgeMutableAttr &);
  virtual void VisitObjCBridgeRelatedAttr(const ObjCBridgeRelatedAttr &);
  virtual void VisitObjCClassStubAttr(const ObjCClassStubAttr &);
  virtual void VisitObjCDesignatedInitializerAttr(const ObjCDesignatedInitializerAttr &);
  virtual void VisitObjCDirectAttr(const ObjCDirectAttr &);
  virtual void VisitObjCDirectMembersAttr(const ObjCDirectMembersAttr &);
  virtual void VisitObjCExceptionAttr(const ObjCExceptionAttr &);
  virtual void VisitObjCExplicitProtocolImplAttr(const ObjCExplicitProtocolImplAttr &);
  virtual void VisitObjCExternallyRetainedAttr(const ObjCExternallyRetainedAttr &);
  virtual void VisitObjCIndependentClassAttr(const ObjCIndependentClassAttr &);
  virtual void VisitObjCMethodFamilyAttr(const ObjCMethodFamilyAttr &);
  virtual void VisitObjCNSObjectAttr(const ObjCNSObjectAttr &);
  virtual void VisitObjCNonLazyClassAttr(const ObjCNonLazyClassAttr &);
  virtual void VisitObjCNonRuntimeProtocolAttr(const ObjCNonRuntimeProtocolAttr &);
  virtual void VisitObjCOwnershipAttr(const ObjCOwnershipAttr &);
  virtual void VisitObjCPreciseLifetimeAttr(const ObjCPreciseLifetimeAttr &);
  virtual void VisitObjCRequiresPropertyDefsAttr(const ObjCRequiresPropertyDefsAttr &);
  virtual void VisitObjCRequiresSuperAttr(const ObjCRequiresSuperAttr &);
  virtual void VisitObjCReturnsInnerPointerAttr(const ObjCReturnsInnerPointerAttr &);
  virtual void VisitObjCRootClassAttr(const ObjCRootClassAttr &);
  virtual void VisitObjCRuntimeNameAttr(const ObjCRuntimeNameAttr &);
  virtual void VisitObjCRuntimeVisibleAttr(const ObjCRuntimeVisibleAttr &);
  virtual void VisitObjCSubclassingRestrictedAttr(const ObjCSubclassingRestrictedAttr &);
  virtual void VisitOpenCLAccessAttr(const OpenCLAccessAttr &);
  virtual void VisitOpenCLIntelReqdSubGroupSizeAttr(const OpenCLIntelReqdSubGroupSizeAttr &);
  virtual void VisitOpenCLKernelAttr(const OpenCLKernelAttr &);
  virtual void VisitOptimizeNoneAttr(const OptimizeNoneAttr &);
  virtual void VisitOverloadableAttr(const OverloadableAttr &);
  virtual void VisitOverrideAttr(const OverrideAttr &);
  virtual void VisitOwnerAttr(const OwnerAttr &);
  virtual void VisitOwnershipAttr(const OwnershipAttr &);
  virtual void VisitPackedAttr(const PackedAttr &);
  virtual void VisitParamTypestateAttr(const ParamTypestateAttr &);
  virtual void VisitParameterABIAttr(const ParameterABIAttr &);
  virtual void VisitPascalAttr(const PascalAttr &);
  virtual void VisitPassObjectSizeAttr(const PassObjectSizeAttr &);
  virtual void VisitPatchableFunctionEntryAttr(const PatchableFunctionEntryAttr &);
  virtual void VisitPcsAttr(const PcsAttr &);
  virtual void VisitPointerAttr(const PointerAttr &);
  virtual void VisitPragmaClangBSSSectionAttr(const PragmaClangBSSSectionAttr &);
  virtual void VisitPragmaClangDataSectionAttr(const PragmaClangDataSectionAttr &);
  virtual void VisitPragmaClangRelroSectionAttr(const PragmaClangRelroSectionAttr &);
  virtual void VisitPragmaClangRodataSectionAttr(const PragmaClangRodataSectionAttr &);
  virtual void VisitPragmaClangTextSectionAttr(const PragmaClangTextSectionAttr &);
  virtual void VisitPreferredNameAttr(const PreferredNameAttr &);
  virtual void VisitPreserveAllAttr(const PreserveAllAttr &);
  virtual void VisitPreserveMostAttr(const PreserveMostAttr &);
  virtual void VisitPtGuardedByAttr(const PtGuardedByAttr &);
  virtual void VisitPtGuardedVarAttr(const PtGuardedVarAttr &);
  virtual void VisitPureAttr(const PureAttr &);
  virtual void VisitRISCVInterruptAttr(const RISCVInterruptAttr &);
  virtual void VisitRandomizeLayoutAttr(const RandomizeLayoutAttr &);
  virtual void VisitReadOnlyPlacementAttr(const ReadOnlyPlacementAttr &);
  virtual void VisitRegCallAttr(const RegCallAttr &);
  virtual void VisitReinitializesAttr(const ReinitializesAttr &);
  virtual void VisitReleaseCapabilityAttr(const ReleaseCapabilityAttr &);
  virtual void VisitReleaseHandleAttr(const ReleaseHandleAttr &);
  virtual void VisitRenderScriptKernelAttr(const RenderScriptKernelAttr &);
  virtual void VisitReqdWorkGroupSizeAttr(const ReqdWorkGroupSizeAttr &);
  virtual void VisitRequiresCapabilityAttr(const RequiresCapabilityAttr &);
  virtual void VisitRestrictAttr(const RestrictAttr &);
  virtual void VisitRetainAttr(const RetainAttr &);
  virtual void VisitReturnTypestateAttr(const ReturnTypestateAttr &);
  virtual void VisitReturnsNonNullAttr(const ReturnsNonNullAttr &);
  virtual void VisitReturnsTwiceAttr(const ReturnsTwiceAttr &);
  virtual void VisitSYCLKernelAttr(const SYCLKernelAttr &);
  virtual void VisitSYCLSpecialClassAttr(const SYCLSpecialClassAttr &);
  virtual void VisitScopedLockableAttr(const ScopedLockableAttr &);
  virtual void VisitSectionAttr(const SectionAttr &);
  virtual void VisitSelectAnyAttr(const SelectAnyAttr &);
  virtual void VisitSentinelAttr(const SentinelAttr &);
  virtual void VisitSetTypestateAttr(const SetTypestateAttr &);
  virtual void VisitSharedTrylockFunctionAttr(const SharedTrylockFunctionAttr &);
  virtual void VisitSpeculativeLoadHardeningAttr(const SpeculativeLoadHardeningAttr &);
  virtual void VisitStandaloneDebugAttr(const StandaloneDebugAttr &);
  virtual void VisitStdCallAttr(const StdCallAttr &);
  virtual void VisitStmtAttr(const StmtAttr &);
  virtual void VisitStrictFPAttr(const StrictFPAttr &);
  virtual void VisitStrictGuardStackCheckAttr(const StrictGuardStackCheckAttr &);
  virtual void VisitSuppressAttr(const SuppressAttr &);
  virtual void VisitSwiftAsyncAttr(const SwiftAsyncAttr &);
  virtual void VisitSwiftAsyncCallAttr(const SwiftAsyncCallAttr &);
  virtual void VisitSwiftAsyncContextAttr(const SwiftAsyncContextAttr &);
  virtual void VisitSwiftAsyncErrorAttr(const SwiftAsyncErrorAttr &);
  virtual void VisitSwiftAsyncNameAttr(const SwiftAsyncNameAttr &);
  virtual void VisitSwiftAttrAttr(const SwiftAttrAttr &);
  virtual void VisitSwiftBridgeAttr(const SwiftBridgeAttr &);
  virtual void VisitSwiftBridgedTypedefAttr(const SwiftBridgedTypedefAttr &);
  virtual void VisitSwiftCallAttr(const SwiftCallAttr &);
  virtual void VisitSwiftContextAttr(const SwiftContextAttr &);
  virtual void VisitSwiftErrorAttr(const SwiftErrorAttr &);
  virtual void VisitSwiftErrorResultAttr(const SwiftErrorResultAttr &);
  virtual void VisitSwiftIndirectResultAttr(const SwiftIndirectResultAttr &);
  virtual void VisitSwiftNameAttr(const SwiftNameAttr &);
  virtual void VisitSwiftNewTypeAttr(const SwiftNewTypeAttr &);
  virtual void VisitSwiftObjCMembersAttr(const SwiftObjCMembersAttr &);
  virtual void VisitSwiftPrivateAttr(const SwiftPrivateAttr &);
  virtual void VisitSysVABIAttr(const SysVABIAttr &);
  virtual void VisitTLSModelAttr(const TLSModelAttr &);
  virtual void VisitTargetAttr(const TargetAttr &);
  virtual void VisitTargetClonesAttr(const TargetClonesAttr &);
  virtual void VisitTargetVersionAttr(const TargetVersionAttr &);
  virtual void VisitTestTypestateAttr(const TestTypestateAttr &);
  virtual void VisitThisCallAttr(const ThisCallAttr &);
  virtual void VisitThreadAttr(const ThreadAttr &);
  virtual void VisitTransparentUnionAttr(const TransparentUnionAttr &);
  virtual void VisitTrivialABIAttr(const TrivialABIAttr &);
  virtual void VisitTryAcquireCapabilityAttr(const TryAcquireCapabilityAttr &);
  virtual void VisitTypeAttr(const TypeAttr &);
  virtual void VisitTypeNonNullAttr(const TypeNonNullAttr &);
  virtual void VisitTypeNullUnspecifiedAttr(const TypeNullUnspecifiedAttr &);
  virtual void VisitTypeNullableAttr(const TypeNullableAttr &);
  virtual void VisitTypeNullableResultAttr(const TypeNullableResultAttr &);
  virtual void VisitTypeTagForDatatypeAttr(const TypeTagForDatatypeAttr &);
  virtual void VisitTypeVisibilityAttr(const TypeVisibilityAttr &);
  virtual void VisitUPtrAttr(const UPtrAttr &);
  virtual void VisitUnavailableAttr(const UnavailableAttr &);
  virtual void VisitUninitializedAttr(const UninitializedAttr &);
  virtual void VisitUnlikelyAttr(const UnlikelyAttr &);
  virtual void VisitUnusedAttr(const UnusedAttr &);
  virtual void VisitUseHandleAttr(const UseHandleAttr &);
  virtual void VisitUsedAttr(const UsedAttr &);
  virtual void VisitUsingIfExistsAttr(const UsingIfExistsAttr &);
  virtual void VisitUuidAttr(const UuidAttr &);
  virtual void VisitVecReturnAttr(const VecReturnAttr &);
  virtual void VisitVecTypeHintAttr(const VecTypeHintAttr &);
  virtual void VisitVectorCallAttr(const VectorCallAttr &);
  virtual void VisitVisibilityAttr(const VisibilityAttr &);
  virtual void VisitWarnUnusedAttr(const WarnUnusedAttr &);
  virtual void VisitWarnUnusedResultAttr(const WarnUnusedResultAttr &);
  virtual void VisitWeakAttr(const WeakAttr &);
  virtual void VisitWeakImportAttr(const WeakImportAttr &);
  virtual void VisitWeakRefAttr(const WeakRefAttr &);
  virtual void VisitWebAssemblyExportNameAttr(const WebAssemblyExportNameAttr &);
  virtual void VisitWebAssemblyImportModuleAttr(const WebAssemblyImportModuleAttr &);
  virtual void VisitWebAssemblyImportNameAttr(const WebAssemblyImportNameAttr &);
  virtual void VisitWorkGroupSizeHintAttr(const WorkGroupSizeHintAttr &);
  virtual void VisitX86ForceAlignArgPointerAttr(const X86ForceAlignArgPointerAttr &);
  virtual void VisitXRayInstrumentAttr(const XRayInstrumentAttr &);
  virtual void VisitXRayLogArgsAttr(const XRayLogArgsAttr &);
  virtual void VisitZeroCallUsedRegsAttr(const ZeroCallUsedRegsAttr &);
  virtual void VisitAArch64SVEPcsAttr(const AArch64SVEPcsAttr &);
  virtual void VisitAArch64VectorPcsAttr(const AArch64VectorPcsAttr &);
  virtual void VisitAMDGPUFlatWorkGroupSizeAttr(const AMDGPUFlatWorkGroupSizeAttr &);
  virtual void VisitAMDGPUKernelCallAttr(const AMDGPUKernelCallAttr &);
  virtual void VisitAMDGPUNumSGPRAttr(const AMDGPUNumSGPRAttr &);
  virtual void VisitAMDGPUNumVGPRAttr(const AMDGPUNumVGPRAttr &);
  virtual void VisitAMDGPUWavesPerEUAttr(const AMDGPUWavesPerEUAttr &);
  virtual void VisitARMInterruptAttr(const ARMInterruptAttr &);
  virtual void VisitAVRInterruptAttr(const AVRInterruptAttr &);
  virtual void VisitAVRSignalAttr(const AVRSignalAttr &);
  virtual void VisitAbiTagAttr(const AbiTagAttr &);
  virtual void VisitAcquireCapabilityAttr(const AcquireCapabilityAttr &);
  virtual void VisitAcquireHandleAttr(const AcquireHandleAttr &);
  virtual void VisitAcquiredAfterAttr(const AcquiredAfterAttr &);
  virtual void VisitAcquiredBeforeAttr(const AcquiredBeforeAttr &);
  virtual void VisitAddressSpaceAttr(const AddressSpaceAttr &);
  virtual void VisitAliasAttr(const AliasAttr &);
  virtual void VisitAlignMac68kAttr(const AlignMac68kAttr &);
  virtual void VisitAlignNaturalAttr(const AlignNaturalAttr &);
  virtual void VisitAlignValueAttr(const AlignValueAttr &);
  virtual void VisitAlignedAttr(const AlignedAttr &);
  virtual void VisitAllocAlignAttr(const AllocAlignAttr &);
  virtual void VisitAllocSizeAttr(const AllocSizeAttr &);
  virtual void VisitAlwaysDestroyAttr(const AlwaysDestroyAttr &);
  virtual void VisitAnalyzerNoReturnAttr(const AnalyzerNoReturnAttr &);
  virtual void VisitAnnotateAttr(const AnnotateAttr &);
  virtual void VisitAnnotateTypeAttr(const AnnotateTypeAttr &);
  virtual void VisitAnyX86InterruptAttr(const AnyX86InterruptAttr &);
  virtual void VisitAnyX86NoCallerSavedRegistersAttr(const AnyX86NoCallerSavedRegistersAttr &);
  virtual void VisitAnyX86NoCfCheckAttr(const AnyX86NoCfCheckAttr &);
  virtual void VisitArcWeakrefUnavailableAttr(const ArcWeakrefUnavailableAttr &);
  virtual void VisitArgumentWithTypeTagAttr(const ArgumentWithTypeTagAttr &);
  virtual void VisitArmBuiltinAliasAttr(const ArmBuiltinAliasAttr &);
  virtual void VisitArmMveStrictPolymorphismAttr(const ArmMveStrictPolymorphismAttr &);
  virtual void VisitArtificialAttr(const ArtificialAttr &);
  virtual void VisitAsmLabelAttr(const AsmLabelAttr &);
  virtual void VisitAssertCapabilityAttr(const AssertCapabilityAttr &);
  virtual void VisitAssertExclusiveLockAttr(const AssertExclusiveLockAttr &);
  virtual void VisitAssertSharedLockAttr(const AssertSharedLockAttr &);
  virtual void VisitAssumeAlignedAttr(const AssumeAlignedAttr &);
  virtual void VisitAssumptionAttr(const AssumptionAttr &);
  virtual void VisitAvailabilityAttr(const AvailabilityAttr &);
  virtual void VisitBPFPreserveAccessIndexAttr(const BPFPreserveAccessIndexAttr &);
  virtual void VisitBTFDeclTagAttr(const BTFDeclTagAttr &);
  virtual void VisitBTFTypeTagAttr(const BTFTypeTagAttr &);
  virtual void VisitBlocksAttr(const BlocksAttr &);
  virtual void VisitBuiltinAttr(const BuiltinAttr &);
  virtual void VisitC11NoReturnAttr(const C11NoReturnAttr &);
  virtual void VisitCDeclAttr(const CDeclAttr &);
  virtual void VisitCFAuditedTransferAttr(const CFAuditedTransferAttr &);
  virtual void VisitCFConsumedAttr(const CFConsumedAttr &);
  virtual void VisitCFGuardAttr(const CFGuardAttr &);
  virtual void VisitCFICanonicalJumpTableAttr(const CFICanonicalJumpTableAttr &);
  virtual void VisitCFReturnsNotRetainedAttr(const CFReturnsNotRetainedAttr &);
  virtual void VisitCFReturnsRetainedAttr(const CFReturnsRetainedAttr &);
  virtual void VisitCFUnknownTransferAttr(const CFUnknownTransferAttr &);
  virtual void VisitCPUDispatchAttr(const CPUDispatchAttr &);
  virtual void VisitCPUSpecificAttr(const CPUSpecificAttr &);
  virtual void VisitCUDAConstantAttr(const CUDAConstantAttr &);
  virtual void VisitCUDADeviceAttr(const CUDADeviceAttr &);
  virtual void VisitCUDADeviceBuiltinSurfaceTypeAttr(const CUDADeviceBuiltinSurfaceTypeAttr &);
  virtual void VisitCUDADeviceBuiltinTextureTypeAttr(const CUDADeviceBuiltinTextureTypeAttr &);
  virtual void VisitCUDAGlobalAttr(const CUDAGlobalAttr &);
  virtual void VisitCUDAHostAttr(const CUDAHostAttr &);
  virtual void VisitCUDAInvalidTargetAttr(const CUDAInvalidTargetAttr &);
  virtual void VisitCUDALaunchBoundsAttr(const CUDALaunchBoundsAttr &);
  virtual void VisitCUDASharedAttr(const CUDASharedAttr &);
  virtual void VisitCXX11NoReturnAttr(const CXX11NoReturnAttr &);
  virtual void VisitCallableWhenAttr(const CallableWhenAttr &);
  virtual void VisitCallbackAttr(const CallbackAttr &);
  virtual void VisitCapabilityAttr(const CapabilityAttr &);
  virtual void VisitCapturedRecordAttr(const CapturedRecordAttr &);
  virtual void VisitCarriesDependencyAttr(const CarriesDependencyAttr &);
  virtual void VisitCleanupAttr(const CleanupAttr &);
  virtual void VisitCmseNSCallAttr(const CmseNSCallAttr &);
  virtual void VisitCmseNSEntryAttr(const CmseNSEntryAttr &);
  virtual void VisitCodeSegAttr(const CodeSegAttr &);
  virtual void VisitColdAttr(const ColdAttr &);
  virtual void VisitCommonAttr(const CommonAttr &);
  virtual void VisitConstAttr(const ConstAttr &);
  virtual void VisitConstInitAttr(const ConstInitAttr &);
  virtual void VisitConstructorAttr(const ConstructorAttr &);
  virtual void VisitConsumableAttr(const ConsumableAttr &);
  virtual void VisitConsumableAutoCastAttr(const ConsumableAutoCastAttr &);
  virtual void VisitConsumableSetOnReadAttr(const ConsumableSetOnReadAttr &);
  virtual void VisitConvergentAttr(const ConvergentAttr &);
  virtual void VisitDLLExportAttr(const DLLExportAttr &);
  virtual void VisitDLLExportStaticLocalAttr(const DLLExportStaticLocalAttr &);
  virtual void VisitDLLImportAttr(const DLLImportAttr &);
  virtual void VisitDLLImportStaticLocalAttr(const DLLImportStaticLocalAttr &);
  virtual void VisitDeclOrStmtAttr(const DeclOrStmtAttr &);
  virtual void VisitDeprecatedAttr(const DeprecatedAttr &);
  virtual void VisitDestructorAttr(const DestructorAttr &);
  virtual void VisitDiagnoseAsBuiltinAttr(const DiagnoseAsBuiltinAttr &);
  virtual void VisitDiagnoseIfAttr(const DiagnoseIfAttr &);
  virtual void VisitDisableSanitizerInstrumentationAttr(const DisableSanitizerInstrumentationAttr &);
  virtual void VisitDisableTailCallsAttr(const DisableTailCallsAttr &);
  virtual void VisitEmptyBasesAttr(const EmptyBasesAttr &);
  virtual void VisitEnableIfAttr(const EnableIfAttr &);
  virtual void VisitEnforceTCBAttr(const EnforceTCBAttr &);
  virtual void VisitEnforceTCBLeafAttr(const EnforceTCBLeafAttr &);
  virtual void VisitEnumExtensibilityAttr(const EnumExtensibilityAttr &);
  virtual void VisitErrorAttr(const ErrorAttr &);
  virtual void VisitExcludeFromExplicitInstantiationAttr(const ExcludeFromExplicitInstantiationAttr &);
  virtual void VisitExclusiveTrylockFunctionAttr(const ExclusiveTrylockFunctionAttr &);
  virtual void VisitExternalSourceSymbolAttr(const ExternalSourceSymbolAttr &);
  virtual void VisitFallThroughAttr(const FallThroughAttr &);
  virtual void VisitFastCallAttr(const FastCallAttr &);
  virtual void VisitFinalAttr(const FinalAttr &);
  virtual void VisitFlagEnumAttr(const FlagEnumAttr &);
  virtual void VisitFlattenAttr(const FlattenAttr &);
  virtual void VisitFormatArgAttr(const FormatArgAttr &);
  virtual void VisitFormatAttr(const FormatAttr &);
  virtual void VisitFunctionReturnThunksAttr(const FunctionReturnThunksAttr &);
  virtual void VisitGNUInlineAttr(const GNUInlineAttr &);
  virtual void VisitGuardedByAttr(const GuardedByAttr &);
  virtual void VisitGuardedVarAttr(const GuardedVarAttr &);
  virtual void VisitHIPManagedAttr(const HIPManagedAttr &);
  virtual void VisitHLSLAnnotationAttr(const HLSLAnnotationAttr &);
  virtual void VisitHLSLGroupSharedAddressSpaceAttr(const HLSLGroupSharedAddressSpaceAttr &);
  virtual void VisitHLSLNumThreadsAttr(const HLSLNumThreadsAttr &);
  virtual void VisitHLSLResourceAttr(const HLSLResourceAttr &);
  virtual void VisitHLSLResourceBindingAttr(const HLSLResourceBindingAttr &);
  virtual void VisitHLSLSV_DispatchThreadIDAttr(const HLSLSV_DispatchThreadIDAttr &);
  virtual void VisitHLSLSV_GroupIndexAttr(const HLSLSV_GroupIndexAttr &);
  virtual void VisitHLSLShaderAttr(const HLSLShaderAttr &);
  virtual void VisitHotAttr(const HotAttr &);
  virtual void VisitIBActionAttr(const IBActionAttr &);
  virtual void VisitIBOutletAttr(const IBOutletAttr &);
  virtual void VisitIBOutletCollectionAttr(const IBOutletCollectionAttr &);
  virtual void VisitLikelyAttr(const LikelyAttr &);
  virtual void VisitMustTailAttr(const MustTailAttr &);
  virtual void VisitNoDerefAttr(const NoDerefAttr &);
  virtual void VisitNoInlineAttr(const NoInlineAttr &);
  virtual void VisitNoMergeAttr(const NoMergeAttr &);
  virtual void VisitObjCGCAttr(const ObjCGCAttr &);
  virtual void VisitObjCInertUnsafeUnretainedAttr(const ObjCInertUnsafeUnretainedAttr &);
  virtual void VisitObjCKindOfAttr(const ObjCKindOfAttr &);
  virtual void VisitOpenCLConstantAddressSpaceAttr(const OpenCLConstantAddressSpaceAttr &);
  virtual void VisitOpenCLGenericAddressSpaceAttr(const OpenCLGenericAddressSpaceAttr &);
  virtual void VisitOpenCLGlobalAddressSpaceAttr(const OpenCLGlobalAddressSpaceAttr &);
  virtual void VisitOpenCLGlobalDeviceAddressSpaceAttr(const OpenCLGlobalDeviceAddressSpaceAttr &);
  virtual void VisitOpenCLGlobalHostAddressSpaceAttr(const OpenCLGlobalHostAddressSpaceAttr &);
  virtual void VisitOpenCLLocalAddressSpaceAttr(const OpenCLLocalAddressSpaceAttr &);
  virtual void VisitOpenCLPrivateAddressSpaceAttr(const OpenCLPrivateAddressSpaceAttr &);
  virtual void VisitOpenCLUnrollHintAttr(const OpenCLUnrollHintAttr &);
  virtual void VisitPtr32Attr(const Ptr32Attr &);
  virtual void VisitPtr64Attr(const Ptr64Attr &);
  virtual void VisitSPtrAttr(const SPtrAttr &);
  virtual void VisitAlwaysInlineAttr(const AlwaysInlineAttr &);
};

// Wraps an attribute.
class Attr {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AArch64SVEPcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AArch64VectorPcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AMDGPUKernelCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AMDGPUNumSGPRAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AMDGPUNumVGPRAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AMDGPUWavesPerEUAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ARMInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AVRInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AVRSignalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AbiTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AcquireCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AcquireHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AcquiredAfterAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AcquiredBeforeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AlignMac68kAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AlignNaturalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AlignValueAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AlignedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AllocAlignAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AllocSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AlwaysDestroyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AlwaysInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AnalyzerNoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AnnotateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AnnotateTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AnyX86InterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AnyX86NoCallerSavedRegistersAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AnyX86NoCfCheckAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ArcWeakrefUnavailableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ArgumentWithTypeTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ArmBuiltinAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ArmMveStrictPolymorphismAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ArtificialAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AsmLabelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AssertCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AssertExclusiveLockAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AssertSharedLockAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AssumeAlignedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AssumptionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AvailabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, BPFPreserveAccessIndexAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, BTFDeclTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, BTFTypeTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, BlocksAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, BuiltinAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, BuiltinAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, C11NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFAuditedTransferAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFGuardAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFICanonicalJumpTableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFReturnsNotRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFReturnsRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CFUnknownTransferAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CPUDispatchAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CPUSpecificAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDAConstantAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDADeviceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDADeviceBuiltinSurfaceTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDADeviceBuiltinTextureTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDAGlobalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDAHostAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDAInvalidTargetAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDALaunchBoundsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CUDASharedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CXX11NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CallableWhenAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CallbackAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CalledOnceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CapturedRecordAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CarriesDependencyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CleanupAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CmseNSCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CmseNSEntryAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CodeSegAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ColdAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, CommonAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConstAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConstInitAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConstructorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConsumableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConsumableAutoCastAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConsumableSetOnReadAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ConvergentAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DLLExportAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DLLExportStaticLocalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DLLImportAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DLLImportStaticLocalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DeclOrStmtAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DeprecatedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DestructorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DiagnoseAsBuiltinAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DiagnoseIfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DisableSanitizerInstrumentationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, DisableTailCallsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, EmptyBasesAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, EnableIfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, EnforceTCBAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, EnforceTCBLeafAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, EnumExtensibilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ErrorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ExcludeFromExplicitInstantiationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ExclusiveTrylockFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ExternalSourceSymbolAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FallThroughAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FastCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FinalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FlagEnumAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FlattenAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FormatArgAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FormatAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, FunctionReturnThunksAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, GNUInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, GuardedByAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, GuardedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HIPManagedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLAnnotationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLGroupSharedAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLNumThreadsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLResourceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLResourceBindingAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLSV_DispatchThreadIDAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLSV_GroupIndexAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HLSLShaderAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HotAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, IBActionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, IBOutletAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, IBOutletCollectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, IFuncAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, InheritableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, InheritableParamAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, InitPriorityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, InitSegAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, IntelOclBiccAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, InternalLinkageAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LTOVisibilityPublicAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LayoutVersionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LeafAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LifetimeBoundAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LikelyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LoaderUninitializedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LockReturnedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LocksExcludedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, LoopHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, M68kInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MIGServerRoutineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSAllocatorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSInheritanceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSNoVTableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSP430InterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSStructAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MSVtorDispAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MaxFieldAlignmentAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MayAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MaybeUndefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MicroMipsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MinSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MinVectorWidthAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, Mips16Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MipsInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MipsLongCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MipsShortCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ModeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, MustTailAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NSConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NSConsumesSelfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NSErrorDomainAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NSReturnsAutoreleasedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NSReturnsNotRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NSReturnsRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NakedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoBuiltinAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoCommonAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoDebugAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoDerefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoDestroyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoDuplicateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoEscapeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoInstrumentFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoMergeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoMicroMipsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoMips16Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoProfileFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoRandomizeLayoutAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoSanitizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoSpeculativeLoadHardeningAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoSplitStackAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoStackProtectorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoThrowAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoUniqueAddressAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoUwtableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NotTailCalledAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPAllocateDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPCaptureKindAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPCaptureNoInitAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPDeclareSimdDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPDeclareTargetDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPDeclareVariantAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPReferencedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OMPThreadPrivateDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OSConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OSConsumesThisAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OSReturnsNotRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OSReturnsRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OSReturnsRetainedOnNonZeroAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OSReturnsRetainedOnZeroAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCBoxableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCBridgeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCBridgeMutableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCBridgeRelatedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCClassStubAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCDesignatedInitializerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCDirectAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCDirectMembersAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCExceptionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCExplicitProtocolImplAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCExternallyRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCGCAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCIndependentClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCInertUnsafeUnretainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCKindOfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCMethodFamilyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCNSObjectAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCNonLazyClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCNonRuntimeProtocolAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCOwnershipAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCPreciseLifetimeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCRequiresPropertyDefsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCRequiresSuperAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCReturnsInnerPointerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCRootClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCRuntimeNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCRuntimeVisibleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ObjCSubclassingRestrictedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLAccessAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLConstantAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLGenericAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLGlobalAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLGlobalDeviceAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLGlobalHostAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLIntelReqdSubGroupSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLKernelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLLocalAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLPrivateAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OpenCLUnrollHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OptimizeNoneAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OverloadableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OverrideAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OwnerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, OwnershipAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PackedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ParamTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ParameterABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PascalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PassObjectSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PatchableFunctionEntryAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PointerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PragmaClangBSSSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PragmaClangDataSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PragmaClangRelroSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PragmaClangRodataSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PragmaClangTextSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PreferredNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PreserveAllAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PreserveMostAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PtGuardedByAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PtGuardedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, Ptr32Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, Ptr64Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, PureAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RISCVInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RandomizeLayoutAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReadOnlyPlacementAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RegCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReinitializesAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReleaseCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReleaseHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RenderScriptKernelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReqdWorkGroupSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RequiresCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RestrictAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, RetainAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReturnTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReturnsNonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ReturnsTwiceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SPtrAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SYCLKernelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SYCLSpecialClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ScopedLockableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SelectAnyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SentinelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SetTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SharedTrylockFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SpeculativeLoadHardeningAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, StandaloneDebugAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, StdCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, StmtAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, StrictFPAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, StrictGuardStackCheckAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SuppressAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftAsyncAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftAsyncCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftAsyncContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftAsyncErrorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftAsyncNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftAttrAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftBridgeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftBridgedTypedefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftErrorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftErrorResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftIndirectResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftNewTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftObjCMembersAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SwiftPrivateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, SysVABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TLSModelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TargetAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TargetClonesAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TargetVersionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TestTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ThisCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ThreadAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TransparentUnionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TrivialABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TryAcquireCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeNonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeNullUnspecifiedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeNullableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeNullableResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeTagForDatatypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, TypeVisibilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UPtrAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UnavailableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UninitializedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UnlikelyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UnusedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UseHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UsedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UsingIfExistsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, UuidAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, VecReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, VecTypeHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, VectorCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, VisibilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WarnUnusedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WarnUnusedResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WeakAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WeakImportAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WeakRefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WebAssemblyExportNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WebAssemblyImportModuleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WebAssemblyImportNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, WorkGroupSizeHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, X86ForceAlignArgPointerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, XRayInstrumentAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, XRayLogArgsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, ZeroCallUsedRegsAttr)
  ::pasta::Token Token(void) const;
  std::string_view Spelling(void) const;
  uint32_t SpellingListIndex(void) const;
  bool IsImplicit(void) const;
  bool IsInherited(void) const;
  bool IsLateParsed(void) const;
  bool IsPackExpansion(void) const;
  inline ::pasta::AttrKind Kind(void) const noexcept {
    return kind;
  }

  std::string_view KindName(void) const noexcept;

  ::pasta::TokenRange Tokens(void) const noexcept;

  inline bool operator==(const Attr &that) const noexcept {
    return u.opaque == that.u.opaque;
  }
  static std::optional<::pasta::Attr> From(const TokenContext &);

 protected:
  friend class TokenContext;

  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::AArch64SVEPcsAttr *AArch64SVEPcsAttr;
    const ::clang::AArch64VectorPcsAttr *AArch64VectorPcsAttr;
    const ::clang::AMDGPUFlatWorkGroupSizeAttr *AMDGPUFlatWorkGroupSizeAttr;
    const ::clang::AMDGPUKernelCallAttr *AMDGPUKernelCallAttr;
    const ::clang::AMDGPUNumSGPRAttr *AMDGPUNumSGPRAttr;
    const ::clang::AMDGPUNumVGPRAttr *AMDGPUNumVGPRAttr;
    const ::clang::AMDGPUWavesPerEUAttr *AMDGPUWavesPerEUAttr;
    const ::clang::ARMInterruptAttr *ARMInterruptAttr;
    const ::clang::AVRInterruptAttr *AVRInterruptAttr;
    const ::clang::AVRSignalAttr *AVRSignalAttr;
    const ::clang::AbiTagAttr *AbiTagAttr;
    const ::clang::AcquireCapabilityAttr *AcquireCapabilityAttr;
    const ::clang::AcquireHandleAttr *AcquireHandleAttr;
    const ::clang::AcquiredAfterAttr *AcquiredAfterAttr;
    const ::clang::AcquiredBeforeAttr *AcquiredBeforeAttr;
    const ::clang::AddressSpaceAttr *AddressSpaceAttr;
    const ::clang::AliasAttr *AliasAttr;
    const ::clang::AlignMac68kAttr *AlignMac68kAttr;
    const ::clang::AlignNaturalAttr *AlignNaturalAttr;
    const ::clang::AlignValueAttr *AlignValueAttr;
    const ::clang::AlignedAttr *AlignedAttr;
    const ::clang::AllocAlignAttr *AllocAlignAttr;
    const ::clang::AllocSizeAttr *AllocSizeAttr;
    const ::clang::AlwaysDestroyAttr *AlwaysDestroyAttr;
    const ::clang::AlwaysInlineAttr *AlwaysInlineAttr;
    const ::clang::AnalyzerNoReturnAttr *AnalyzerNoReturnAttr;
    const ::clang::AnnotateAttr *AnnotateAttr;
    const ::clang::AnnotateTypeAttr *AnnotateTypeAttr;
    const ::clang::AnyX86InterruptAttr *AnyX86InterruptAttr;
    const ::clang::AnyX86NoCallerSavedRegistersAttr *AnyX86NoCallerSavedRegistersAttr;
    const ::clang::AnyX86NoCfCheckAttr *AnyX86NoCfCheckAttr;
    const ::clang::ArcWeakrefUnavailableAttr *ArcWeakrefUnavailableAttr;
    const ::clang::ArgumentWithTypeTagAttr *ArgumentWithTypeTagAttr;
    const ::clang::ArmBuiltinAliasAttr *ArmBuiltinAliasAttr;
    const ::clang::ArmMveStrictPolymorphismAttr *ArmMveStrictPolymorphismAttr;
    const ::clang::ArtificialAttr *ArtificialAttr;
    const ::clang::AsmLabelAttr *AsmLabelAttr;
    const ::clang::AssertCapabilityAttr *AssertCapabilityAttr;
    const ::clang::AssertExclusiveLockAttr *AssertExclusiveLockAttr;
    const ::clang::AssertSharedLockAttr *AssertSharedLockAttr;
    const ::clang::AssumeAlignedAttr *AssumeAlignedAttr;
    const ::clang::AssumptionAttr *AssumptionAttr;
    const ::clang::Attr *Attr;
    const ::clang::AvailabilityAttr *AvailabilityAttr;
    const ::clang::BPFPreserveAccessIndexAttr *BPFPreserveAccessIndexAttr;
    const ::clang::BTFDeclTagAttr *BTFDeclTagAttr;
    const ::clang::BTFTypeTagAttr *BTFTypeTagAttr;
    const ::clang::BlocksAttr *BlocksAttr;
    const ::clang::BuiltinAliasAttr *BuiltinAliasAttr;
    const ::clang::BuiltinAttr *BuiltinAttr;
    const ::clang::C11NoReturnAttr *C11NoReturnAttr;
    const ::clang::CDeclAttr *CDeclAttr;
    const ::clang::CFAuditedTransferAttr *CFAuditedTransferAttr;
    const ::clang::CFConsumedAttr *CFConsumedAttr;
    const ::clang::CFGuardAttr *CFGuardAttr;
    const ::clang::CFICanonicalJumpTableAttr *CFICanonicalJumpTableAttr;
    const ::clang::CFReturnsNotRetainedAttr *CFReturnsNotRetainedAttr;
    const ::clang::CFReturnsRetainedAttr *CFReturnsRetainedAttr;
    const ::clang::CFUnknownTransferAttr *CFUnknownTransferAttr;
    const ::clang::CPUDispatchAttr *CPUDispatchAttr;
    const ::clang::CPUSpecificAttr *CPUSpecificAttr;
    const ::clang::CUDAConstantAttr *CUDAConstantAttr;
    const ::clang::CUDADeviceAttr *CUDADeviceAttr;
    const ::clang::CUDADeviceBuiltinSurfaceTypeAttr *CUDADeviceBuiltinSurfaceTypeAttr;
    const ::clang::CUDADeviceBuiltinTextureTypeAttr *CUDADeviceBuiltinTextureTypeAttr;
    const ::clang::CUDAGlobalAttr *CUDAGlobalAttr;
    const ::clang::CUDAHostAttr *CUDAHostAttr;
    const ::clang::CUDAInvalidTargetAttr *CUDAInvalidTargetAttr;
    const ::clang::CUDALaunchBoundsAttr *CUDALaunchBoundsAttr;
    const ::clang::CUDASharedAttr *CUDASharedAttr;
    const ::clang::CXX11NoReturnAttr *CXX11NoReturnAttr;
    const ::clang::CallableWhenAttr *CallableWhenAttr;
    const ::clang::CallbackAttr *CallbackAttr;
    const ::clang::CalledOnceAttr *CalledOnceAttr;
    const ::clang::CapabilityAttr *CapabilityAttr;
    const ::clang::CapturedRecordAttr *CapturedRecordAttr;
    const ::clang::CarriesDependencyAttr *CarriesDependencyAttr;
    const ::clang::CleanupAttr *CleanupAttr;
    const ::clang::CmseNSCallAttr *CmseNSCallAttr;
    const ::clang::CmseNSEntryAttr *CmseNSEntryAttr;
    const ::clang::CodeSegAttr *CodeSegAttr;
    const ::clang::ColdAttr *ColdAttr;
    const ::clang::CommonAttr *CommonAttr;
    const ::clang::ConstAttr *ConstAttr;
    const ::clang::ConstInitAttr *ConstInitAttr;
    const ::clang::ConstructorAttr *ConstructorAttr;
    const ::clang::ConsumableAttr *ConsumableAttr;
    const ::clang::ConsumableAutoCastAttr *ConsumableAutoCastAttr;
    const ::clang::ConsumableSetOnReadAttr *ConsumableSetOnReadAttr;
    const ::clang::ConvergentAttr *ConvergentAttr;
    const ::clang::DLLExportAttr *DLLExportAttr;
    const ::clang::DLLExportStaticLocalAttr *DLLExportStaticLocalAttr;
    const ::clang::DLLImportAttr *DLLImportAttr;
    const ::clang::DLLImportStaticLocalAttr *DLLImportStaticLocalAttr;
    const ::clang::DeclOrStmtAttr *DeclOrStmtAttr;
    const ::clang::DeprecatedAttr *DeprecatedAttr;
    const ::clang::DestructorAttr *DestructorAttr;
    const ::clang::DiagnoseAsBuiltinAttr *DiagnoseAsBuiltinAttr;
    const ::clang::DiagnoseIfAttr *DiagnoseIfAttr;
    const ::clang::DisableSanitizerInstrumentationAttr *DisableSanitizerInstrumentationAttr;
    const ::clang::DisableTailCallsAttr *DisableTailCallsAttr;
    const ::clang::EmptyBasesAttr *EmptyBasesAttr;
    const ::clang::EnableIfAttr *EnableIfAttr;
    const ::clang::EnforceTCBAttr *EnforceTCBAttr;
    const ::clang::EnforceTCBLeafAttr *EnforceTCBLeafAttr;
    const ::clang::EnumExtensibilityAttr *EnumExtensibilityAttr;
    const ::clang::ErrorAttr *ErrorAttr;
    const ::clang::ExcludeFromExplicitInstantiationAttr *ExcludeFromExplicitInstantiationAttr;
    const ::clang::ExclusiveTrylockFunctionAttr *ExclusiveTrylockFunctionAttr;
    const ::clang::ExternalSourceSymbolAttr *ExternalSourceSymbolAttr;
    const ::clang::FallThroughAttr *FallThroughAttr;
    const ::clang::FastCallAttr *FastCallAttr;
    const ::clang::FinalAttr *FinalAttr;
    const ::clang::FlagEnumAttr *FlagEnumAttr;
    const ::clang::FlattenAttr *FlattenAttr;
    const ::clang::FormatArgAttr *FormatArgAttr;
    const ::clang::FormatAttr *FormatAttr;
    const ::clang::FunctionReturnThunksAttr *FunctionReturnThunksAttr;
    const ::clang::GNUInlineAttr *GNUInlineAttr;
    const ::clang::GuardedByAttr *GuardedByAttr;
    const ::clang::GuardedVarAttr *GuardedVarAttr;
    const ::clang::HIPManagedAttr *HIPManagedAttr;
    const ::clang::HLSLAnnotationAttr *HLSLAnnotationAttr;
    const ::clang::HLSLGroupSharedAddressSpaceAttr *HLSLGroupSharedAddressSpaceAttr;
    const ::clang::HLSLNumThreadsAttr *HLSLNumThreadsAttr;
    const ::clang::HLSLResourceAttr *HLSLResourceAttr;
    const ::clang::HLSLResourceBindingAttr *HLSLResourceBindingAttr;
    const ::clang::HLSLSV_DispatchThreadIDAttr *HLSLSV_DispatchThreadIDAttr;
    const ::clang::HLSLSV_GroupIndexAttr *HLSLSV_GroupIndexAttr;
    const ::clang::HLSLShaderAttr *HLSLShaderAttr;
    const ::clang::HotAttr *HotAttr;
    const ::clang::IBActionAttr *IBActionAttr;
    const ::clang::IBOutletAttr *IBOutletAttr;
    const ::clang::IBOutletCollectionAttr *IBOutletCollectionAttr;
    const ::clang::IFuncAttr *IFuncAttr;
    const ::clang::InheritableAttr *InheritableAttr;
    const ::clang::InheritableParamAttr *InheritableParamAttr;
    const ::clang::InitPriorityAttr *InitPriorityAttr;
    const ::clang::InitSegAttr *InitSegAttr;
    const ::clang::IntelOclBiccAttr *IntelOclBiccAttr;
    const ::clang::InternalLinkageAttr *InternalLinkageAttr;
    const ::clang::LTOVisibilityPublicAttr *LTOVisibilityPublicAttr;
    const ::clang::LayoutVersionAttr *LayoutVersionAttr;
    const ::clang::LeafAttr *LeafAttr;
    const ::clang::LifetimeBoundAttr *LifetimeBoundAttr;
    const ::clang::LikelyAttr *LikelyAttr;
    const ::clang::LoaderUninitializedAttr *LoaderUninitializedAttr;
    const ::clang::LockReturnedAttr *LockReturnedAttr;
    const ::clang::LocksExcludedAttr *LocksExcludedAttr;
    const ::clang::LoopHintAttr *LoopHintAttr;
    const ::clang::M68kInterruptAttr *M68kInterruptAttr;
    const ::clang::MIGServerRoutineAttr *MIGServerRoutineAttr;
    const ::clang::MSABIAttr *MSABIAttr;
    const ::clang::MSAllocatorAttr *MSAllocatorAttr;
    const ::clang::MSInheritanceAttr *MSInheritanceAttr;
    const ::clang::MSNoVTableAttr *MSNoVTableAttr;
    const ::clang::MSP430InterruptAttr *MSP430InterruptAttr;
    const ::clang::MSStructAttr *MSStructAttr;
    const ::clang::MSVtorDispAttr *MSVtorDispAttr;
    const ::clang::MaxFieldAlignmentAttr *MaxFieldAlignmentAttr;
    const ::clang::MayAliasAttr *MayAliasAttr;
    const ::clang::MaybeUndefAttr *MaybeUndefAttr;
    const ::clang::MicroMipsAttr *MicroMipsAttr;
    const ::clang::MinSizeAttr *MinSizeAttr;
    const ::clang::MinVectorWidthAttr *MinVectorWidthAttr;
    const ::clang::Mips16Attr *Mips16Attr;
    const ::clang::MipsInterruptAttr *MipsInterruptAttr;
    const ::clang::MipsLongCallAttr *MipsLongCallAttr;
    const ::clang::MipsShortCallAttr *MipsShortCallAttr;
    const ::clang::ModeAttr *ModeAttr;
    const ::clang::MustTailAttr *MustTailAttr;
    const ::clang::NSConsumedAttr *NSConsumedAttr;
    const ::clang::NSConsumesSelfAttr *NSConsumesSelfAttr;
    const ::clang::NSErrorDomainAttr *NSErrorDomainAttr;
    const ::clang::NSReturnsAutoreleasedAttr *NSReturnsAutoreleasedAttr;
    const ::clang::NSReturnsNotRetainedAttr *NSReturnsNotRetainedAttr;
    const ::clang::NSReturnsRetainedAttr *NSReturnsRetainedAttr;
    const ::clang::NakedAttr *NakedAttr;
    const ::clang::NoAliasAttr *NoAliasAttr;
    const ::clang::NoBuiltinAttr *NoBuiltinAttr;
    const ::clang::NoCommonAttr *NoCommonAttr;
    const ::clang::NoDebugAttr *NoDebugAttr;
    const ::clang::NoDerefAttr *NoDerefAttr;
    const ::clang::NoDestroyAttr *NoDestroyAttr;
    const ::clang::NoDuplicateAttr *NoDuplicateAttr;
    const ::clang::NoEscapeAttr *NoEscapeAttr;
    const ::clang::NoInlineAttr *NoInlineAttr;
    const ::clang::NoInstrumentFunctionAttr *NoInstrumentFunctionAttr;
    const ::clang::NoMergeAttr *NoMergeAttr;
    const ::clang::NoMicroMipsAttr *NoMicroMipsAttr;
    const ::clang::NoMips16Attr *NoMips16Attr;
    const ::clang::NoProfileFunctionAttr *NoProfileFunctionAttr;
    const ::clang::NoRandomizeLayoutAttr *NoRandomizeLayoutAttr;
    const ::clang::NoReturnAttr *NoReturnAttr;
    const ::clang::NoSanitizeAttr *NoSanitizeAttr;
    const ::clang::NoSpeculativeLoadHardeningAttr *NoSpeculativeLoadHardeningAttr;
    const ::clang::NoSplitStackAttr *NoSplitStackAttr;
    const ::clang::NoStackProtectorAttr *NoStackProtectorAttr;
    const ::clang::NoThreadSafetyAnalysisAttr *NoThreadSafetyAnalysisAttr;
    const ::clang::NoThrowAttr *NoThrowAttr;
    const ::clang::NoUniqueAddressAttr *NoUniqueAddressAttr;
    const ::clang::NoUwtableAttr *NoUwtableAttr;
    const ::clang::NonNullAttr *NonNullAttr;
    const ::clang::NotTailCalledAttr *NotTailCalledAttr;
    const ::clang::OMPAllocateDeclAttr *OMPAllocateDeclAttr;
    const ::clang::OMPCaptureKindAttr *OMPCaptureKindAttr;
    const ::clang::OMPCaptureNoInitAttr *OMPCaptureNoInitAttr;
    const ::clang::OMPDeclareSimdDeclAttr *OMPDeclareSimdDeclAttr;
    const ::clang::OMPDeclareTargetDeclAttr *OMPDeclareTargetDeclAttr;
    const ::clang::OMPDeclareVariantAttr *OMPDeclareVariantAttr;
    const ::clang::OMPReferencedVarAttr *OMPReferencedVarAttr;
    const ::clang::OMPThreadPrivateDeclAttr *OMPThreadPrivateDeclAttr;
    const ::clang::OSConsumedAttr *OSConsumedAttr;
    const ::clang::OSConsumesThisAttr *OSConsumesThisAttr;
    const ::clang::OSReturnsNotRetainedAttr *OSReturnsNotRetainedAttr;
    const ::clang::OSReturnsRetainedAttr *OSReturnsRetainedAttr;
    const ::clang::OSReturnsRetainedOnNonZeroAttr *OSReturnsRetainedOnNonZeroAttr;
    const ::clang::OSReturnsRetainedOnZeroAttr *OSReturnsRetainedOnZeroAttr;
    const ::clang::ObjCBoxableAttr *ObjCBoxableAttr;
    const ::clang::ObjCBridgeAttr *ObjCBridgeAttr;
    const ::clang::ObjCBridgeMutableAttr *ObjCBridgeMutableAttr;
    const ::clang::ObjCBridgeRelatedAttr *ObjCBridgeRelatedAttr;
    const ::clang::ObjCClassStubAttr *ObjCClassStubAttr;
    const ::clang::ObjCDesignatedInitializerAttr *ObjCDesignatedInitializerAttr;
    const ::clang::ObjCDirectAttr *ObjCDirectAttr;
    const ::clang::ObjCDirectMembersAttr *ObjCDirectMembersAttr;
    const ::clang::ObjCExceptionAttr *ObjCExceptionAttr;
    const ::clang::ObjCExplicitProtocolImplAttr *ObjCExplicitProtocolImplAttr;
    const ::clang::ObjCExternallyRetainedAttr *ObjCExternallyRetainedAttr;
    const ::clang::ObjCGCAttr *ObjCGCAttr;
    const ::clang::ObjCIndependentClassAttr *ObjCIndependentClassAttr;
    const ::clang::ObjCInertUnsafeUnretainedAttr *ObjCInertUnsafeUnretainedAttr;
    const ::clang::ObjCKindOfAttr *ObjCKindOfAttr;
    const ::clang::ObjCMethodFamilyAttr *ObjCMethodFamilyAttr;
    const ::clang::ObjCNSObjectAttr *ObjCNSObjectAttr;
    const ::clang::ObjCNonLazyClassAttr *ObjCNonLazyClassAttr;
    const ::clang::ObjCNonRuntimeProtocolAttr *ObjCNonRuntimeProtocolAttr;
    const ::clang::ObjCOwnershipAttr *ObjCOwnershipAttr;
    const ::clang::ObjCPreciseLifetimeAttr *ObjCPreciseLifetimeAttr;
    const ::clang::ObjCRequiresPropertyDefsAttr *ObjCRequiresPropertyDefsAttr;
    const ::clang::ObjCRequiresSuperAttr *ObjCRequiresSuperAttr;
    const ::clang::ObjCReturnsInnerPointerAttr *ObjCReturnsInnerPointerAttr;
    const ::clang::ObjCRootClassAttr *ObjCRootClassAttr;
    const ::clang::ObjCRuntimeNameAttr *ObjCRuntimeNameAttr;
    const ::clang::ObjCRuntimeVisibleAttr *ObjCRuntimeVisibleAttr;
    const ::clang::ObjCSubclassingRestrictedAttr *ObjCSubclassingRestrictedAttr;
    const ::clang::OpenCLAccessAttr *OpenCLAccessAttr;
    const ::clang::OpenCLConstantAddressSpaceAttr *OpenCLConstantAddressSpaceAttr;
    const ::clang::OpenCLGenericAddressSpaceAttr *OpenCLGenericAddressSpaceAttr;
    const ::clang::OpenCLGlobalAddressSpaceAttr *OpenCLGlobalAddressSpaceAttr;
    const ::clang::OpenCLGlobalDeviceAddressSpaceAttr *OpenCLGlobalDeviceAddressSpaceAttr;
    const ::clang::OpenCLGlobalHostAddressSpaceAttr *OpenCLGlobalHostAddressSpaceAttr;
    const ::clang::OpenCLIntelReqdSubGroupSizeAttr *OpenCLIntelReqdSubGroupSizeAttr;
    const ::clang::OpenCLKernelAttr *OpenCLKernelAttr;
    const ::clang::OpenCLLocalAddressSpaceAttr *OpenCLLocalAddressSpaceAttr;
    const ::clang::OpenCLPrivateAddressSpaceAttr *OpenCLPrivateAddressSpaceAttr;
    const ::clang::OpenCLUnrollHintAttr *OpenCLUnrollHintAttr;
    const ::clang::OptimizeNoneAttr *OptimizeNoneAttr;
    const ::clang::OverloadableAttr *OverloadableAttr;
    const ::clang::OverrideAttr *OverrideAttr;
    const ::clang::OwnerAttr *OwnerAttr;
    const ::clang::OwnershipAttr *OwnershipAttr;
    const ::clang::PackedAttr *PackedAttr;
    const ::clang::ParamTypestateAttr *ParamTypestateAttr;
    const ::clang::ParameterABIAttr *ParameterABIAttr;
    const ::clang::PascalAttr *PascalAttr;
    const ::clang::PassObjectSizeAttr *PassObjectSizeAttr;
    const ::clang::PatchableFunctionEntryAttr *PatchableFunctionEntryAttr;
    const ::clang::PcsAttr *PcsAttr;
    const ::clang::PointerAttr *PointerAttr;
    const ::clang::PragmaClangBSSSectionAttr *PragmaClangBSSSectionAttr;
    const ::clang::PragmaClangDataSectionAttr *PragmaClangDataSectionAttr;
    const ::clang::PragmaClangRelroSectionAttr *PragmaClangRelroSectionAttr;
    const ::clang::PragmaClangRodataSectionAttr *PragmaClangRodataSectionAttr;
    const ::clang::PragmaClangTextSectionAttr *PragmaClangTextSectionAttr;
    const ::clang::PreferredNameAttr *PreferredNameAttr;
    const ::clang::PreserveAllAttr *PreserveAllAttr;
    const ::clang::PreserveMostAttr *PreserveMostAttr;
    const ::clang::PtGuardedByAttr *PtGuardedByAttr;
    const ::clang::PtGuardedVarAttr *PtGuardedVarAttr;
    const ::clang::Ptr32Attr *Ptr32Attr;
    const ::clang::Ptr64Attr *Ptr64Attr;
    const ::clang::PureAttr *PureAttr;
    const ::clang::RISCVInterruptAttr *RISCVInterruptAttr;
    const ::clang::RandomizeLayoutAttr *RandomizeLayoutAttr;
    const ::clang::ReadOnlyPlacementAttr *ReadOnlyPlacementAttr;
    const ::clang::RegCallAttr *RegCallAttr;
    const ::clang::ReinitializesAttr *ReinitializesAttr;
    const ::clang::ReleaseCapabilityAttr *ReleaseCapabilityAttr;
    const ::clang::ReleaseHandleAttr *ReleaseHandleAttr;
    const ::clang::RenderScriptKernelAttr *RenderScriptKernelAttr;
    const ::clang::ReqdWorkGroupSizeAttr *ReqdWorkGroupSizeAttr;
    const ::clang::RequiresCapabilityAttr *RequiresCapabilityAttr;
    const ::clang::RestrictAttr *RestrictAttr;
    const ::clang::RetainAttr *RetainAttr;
    const ::clang::ReturnTypestateAttr *ReturnTypestateAttr;
    const ::clang::ReturnsNonNullAttr *ReturnsNonNullAttr;
    const ::clang::ReturnsTwiceAttr *ReturnsTwiceAttr;
    const ::clang::SPtrAttr *SPtrAttr;
    const ::clang::SYCLKernelAttr *SYCLKernelAttr;
    const ::clang::SYCLSpecialClassAttr *SYCLSpecialClassAttr;
    const ::clang::ScopedLockableAttr *ScopedLockableAttr;
    const ::clang::SectionAttr *SectionAttr;
    const ::clang::SelectAnyAttr *SelectAnyAttr;
    const ::clang::SentinelAttr *SentinelAttr;
    const ::clang::SetTypestateAttr *SetTypestateAttr;
    const ::clang::SharedTrylockFunctionAttr *SharedTrylockFunctionAttr;
    const ::clang::SpeculativeLoadHardeningAttr *SpeculativeLoadHardeningAttr;
    const ::clang::StandaloneDebugAttr *StandaloneDebugAttr;
    const ::clang::StdCallAttr *StdCallAttr;
    const ::clang::StmtAttr *StmtAttr;
    const ::clang::StrictFPAttr *StrictFPAttr;
    const ::clang::StrictGuardStackCheckAttr *StrictGuardStackCheckAttr;
    const ::clang::SuppressAttr *SuppressAttr;
    const ::clang::SwiftAsyncAttr *SwiftAsyncAttr;
    const ::clang::SwiftAsyncCallAttr *SwiftAsyncCallAttr;
    const ::clang::SwiftAsyncContextAttr *SwiftAsyncContextAttr;
    const ::clang::SwiftAsyncErrorAttr *SwiftAsyncErrorAttr;
    const ::clang::SwiftAsyncNameAttr *SwiftAsyncNameAttr;
    const ::clang::SwiftAttrAttr *SwiftAttrAttr;
    const ::clang::SwiftBridgeAttr *SwiftBridgeAttr;
    const ::clang::SwiftBridgedTypedefAttr *SwiftBridgedTypedefAttr;
    const ::clang::SwiftCallAttr *SwiftCallAttr;
    const ::clang::SwiftContextAttr *SwiftContextAttr;
    const ::clang::SwiftErrorAttr *SwiftErrorAttr;
    const ::clang::SwiftErrorResultAttr *SwiftErrorResultAttr;
    const ::clang::SwiftIndirectResultAttr *SwiftIndirectResultAttr;
    const ::clang::SwiftNameAttr *SwiftNameAttr;
    const ::clang::SwiftNewTypeAttr *SwiftNewTypeAttr;
    const ::clang::SwiftObjCMembersAttr *SwiftObjCMembersAttr;
    const ::clang::SwiftPrivateAttr *SwiftPrivateAttr;
    const ::clang::SysVABIAttr *SysVABIAttr;
    const ::clang::TLSModelAttr *TLSModelAttr;
    const ::clang::TargetAttr *TargetAttr;
    const ::clang::TargetClonesAttr *TargetClonesAttr;
    const ::clang::TargetVersionAttr *TargetVersionAttr;
    const ::clang::TestTypestateAttr *TestTypestateAttr;
    const ::clang::ThisCallAttr *ThisCallAttr;
    const ::clang::ThreadAttr *ThreadAttr;
    const ::clang::TransparentUnionAttr *TransparentUnionAttr;
    const ::clang::TrivialABIAttr *TrivialABIAttr;
    const ::clang::TryAcquireCapabilityAttr *TryAcquireCapabilityAttr;
    const ::clang::TypeAttr *TypeAttr;
    const ::clang::TypeNonNullAttr *TypeNonNullAttr;
    const ::clang::TypeNullUnspecifiedAttr *TypeNullUnspecifiedAttr;
    const ::clang::TypeNullableAttr *TypeNullableAttr;
    const ::clang::TypeNullableResultAttr *TypeNullableResultAttr;
    const ::clang::TypeTagForDatatypeAttr *TypeTagForDatatypeAttr;
    const ::clang::TypeVisibilityAttr *TypeVisibilityAttr;
    const ::clang::UPtrAttr *UPtrAttr;
    const ::clang::UnavailableAttr *UnavailableAttr;
    const ::clang::UninitializedAttr *UninitializedAttr;
    const ::clang::UnlikelyAttr *UnlikelyAttr;
    const ::clang::UnusedAttr *UnusedAttr;
    const ::clang::UseHandleAttr *UseHandleAttr;
    const ::clang::UsedAttr *UsedAttr;
    const ::clang::UsingIfExistsAttr *UsingIfExistsAttr;
    const ::clang::UuidAttr *UuidAttr;
    const ::clang::VecReturnAttr *VecReturnAttr;
    const ::clang::VecTypeHintAttr *VecTypeHintAttr;
    const ::clang::VectorCallAttr *VectorCallAttr;
    const ::clang::VisibilityAttr *VisibilityAttr;
    const ::clang::WarnUnusedAttr *WarnUnusedAttr;
    const ::clang::WarnUnusedResultAttr *WarnUnusedResultAttr;
    const ::clang::WeakAttr *WeakAttr;
    const ::clang::WeakImportAttr *WeakImportAttr;
    const ::clang::WeakRefAttr *WeakRefAttr;
    const ::clang::WebAssemblyExportNameAttr *WebAssemblyExportNameAttr;
    const ::clang::WebAssemblyImportModuleAttr *WebAssemblyImportModuleAttr;
    const ::clang::WebAssemblyImportNameAttr *WebAssemblyImportNameAttr;
    const ::clang::WorkGroupSizeHintAttr *WorkGroupSizeHintAttr;
    const ::clang::X86ForceAlignArgPointerAttr *X86ForceAlignArgPointerAttr;
    const ::clang::XRayInstrumentAttr *XRayInstrumentAttr;
    const ::clang::XRayLogArgsAttr *XRayLogArgsAttr;
    const ::clang::ZeroCallUsedRegsAttr *ZeroCallUsedRegsAttr;
    const void *opaque;
  } u;
  AttrKind kind;

  inline Attr(std::shared_ptr<ASTImpl> ast_, const clang::Attr *attr_,
              AttrKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    assert(ast.get() != nullptr);
    u.Attr = attr_;
  }

 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(Attr)
};

class BuiltinAliasAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BuiltinAliasAttr)
  // BuiltinName: (clang::IdentifierInfo *)
  enum BuiltinAliasAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(BuiltinAliasAttr)
};

static_assert(sizeof(Attr) == sizeof(BuiltinAliasAttr));

class CalledOnceAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CalledOnceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CalledOnceAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CalledOnceAttr)
};

static_assert(sizeof(Attr) == sizeof(CalledOnceAttr));

class IFuncAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IFuncAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, IFuncAttr)
  std::string_view Resolver(void) const;
  uint32_t ResolverLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(IFuncAttr)
};

static_assert(sizeof(Attr) == sizeof(IFuncAttr));

class InheritableAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InheritableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, InheritableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AArch64SVEPcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AMDGPUKernelCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AMDGPUNumSGPRAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AMDGPUNumVGPRAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AMDGPUWavesPerEUAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ARMInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AVRInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AVRSignalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AcquireCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AcquireHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AcquiredAfterAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AcquiredBeforeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AlignMac68kAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AlignNaturalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AlignedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AllocAlignAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AllocSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AlwaysDestroyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AlwaysInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AnalyzerNoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AnnotateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AnyX86InterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AnyX86NoCallerSavedRegistersAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AnyX86NoCfCheckAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ArcWeakrefUnavailableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ArgumentWithTypeTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ArmBuiltinAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ArtificialAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AsmLabelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AssertCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AssertExclusiveLockAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AssertSharedLockAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AssumeAlignedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AssumptionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AvailabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, BPFPreserveAccessIndexAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, BTFDeclTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, BlocksAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, BuiltinAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, C11NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFAuditedTransferAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFGuardAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFICanonicalJumpTableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFReturnsNotRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFReturnsRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CFUnknownTransferAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CPUDispatchAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CPUSpecificAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDAConstantAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDADeviceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDADeviceBuiltinSurfaceTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDADeviceBuiltinTextureTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDAGlobalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDAHostAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDAInvalidTargetAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDALaunchBoundsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CUDASharedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CXX11NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CallableWhenAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CallbackAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CapturedRecordAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CarriesDependencyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CleanupAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CmseNSEntryAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CodeSegAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ColdAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, CommonAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConstAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConstInitAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConstructorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConsumableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConsumableAutoCastAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConsumableSetOnReadAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ConvergentAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DLLExportAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DLLExportStaticLocalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DLLImportAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DLLImportStaticLocalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DeclOrStmtAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DeprecatedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DestructorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DiagnoseAsBuiltinAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DiagnoseIfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DisableSanitizerInstrumentationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, DisableTailCallsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, EmptyBasesAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, EnableIfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, EnforceTCBAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, EnforceTCBLeafAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, EnumExtensibilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ErrorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ExcludeFromExplicitInstantiationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ExclusiveTrylockFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ExternalSourceSymbolAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FastCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FinalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FlagEnumAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FlattenAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FormatArgAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FormatAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, FunctionReturnThunksAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, GNUInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, GuardedByAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, GuardedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HIPManagedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLAnnotationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLNumThreadsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLResourceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLResourceBindingAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLSV_DispatchThreadIDAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLSV_GroupIndexAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HLSLShaderAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HotAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, IBActionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, IBOutletAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, IBOutletCollectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, InheritableParamAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, InitPriorityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, IntelOclBiccAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, InternalLinkageAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, LTOVisibilityPublicAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, LayoutVersionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, LeafAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, LifetimeBoundAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, LockReturnedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, LocksExcludedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, M68kInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MIGServerRoutineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSAllocatorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSInheritanceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSNoVTableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSP430InterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSStructAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MSVtorDispAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MaxFieldAlignmentAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MayAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MaybeUndefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MicroMipsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MinSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MinVectorWidthAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, Mips16Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MipsInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MipsLongCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, MipsShortCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NSConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NSConsumesSelfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NSErrorDomainAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NSReturnsAutoreleasedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NSReturnsNotRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NSReturnsRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NakedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoAliasAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoCommonAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoDebugAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoDestroyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoDuplicateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoInstrumentFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoMergeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoMicroMipsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoMips16Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoProfileFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoRandomizeLayoutAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoSanitizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoSpeculativeLoadHardeningAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoSplitStackAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoStackProtectorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoThrowAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoUwtableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NotTailCalledAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OMPAllocateDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OMPCaptureNoInitAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OMPDeclareTargetDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OMPDeclareVariantAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OMPThreadPrivateDeclAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OSConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OSConsumesThisAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OSReturnsNotRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OSReturnsRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OSReturnsRetainedOnNonZeroAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OSReturnsRetainedOnZeroAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCBridgeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCBridgeMutableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCBridgeRelatedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCExceptionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCExplicitProtocolImplAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCExternallyRetainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCIndependentClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCMethodFamilyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCNSObjectAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCOwnershipAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCPreciseLifetimeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCRequiresPropertyDefsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCRequiresSuperAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCReturnsInnerPointerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCRootClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ObjCSubclassingRestrictedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OpenCLIntelReqdSubGroupSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OpenCLKernelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OptimizeNoneAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OverrideAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OwnerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, OwnershipAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PackedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ParamTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ParameterABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PascalAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PassObjectSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PatchableFunctionEntryAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PointerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PragmaClangBSSSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PragmaClangDataSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PragmaClangRelroSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PragmaClangRodataSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PragmaClangTextSectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PreferredNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PreserveAllAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PreserveMostAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PtGuardedByAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PtGuardedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, PureAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, RISCVInterruptAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, RandomizeLayoutAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReadOnlyPlacementAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, RegCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReinitializesAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReleaseCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReleaseHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReqdWorkGroupSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, RequiresCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, RestrictAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, RetainAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReturnTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReturnsNonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ReturnsTwiceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SYCLKernelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SYCLSpecialClassAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ScopedLockableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SectionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SelectAnyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SentinelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SetTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SharedTrylockFunctionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SpeculativeLoadHardeningAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, StandaloneDebugAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, StdCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, StrictFPAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, StrictGuardStackCheckAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncErrorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftAttrAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftBridgeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftBridgedTypedefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftErrorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftErrorResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftIndirectResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftNewTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SwiftPrivateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, SysVABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TLSModelAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TargetAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TargetClonesAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TargetVersionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TestTypestateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ThisCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TransparentUnionAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TrivialABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TryAcquireCapabilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TypeTagForDatatypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, TypeVisibilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UnavailableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UninitializedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UnusedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UseHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UsedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UsingIfExistsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, UuidAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, VecReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, VecTypeHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, VectorCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, VisibilityAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WarnUnusedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WarnUnusedResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WeakAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WeakImportAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WeakRefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WebAssemblyExportNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WebAssemblyImportModuleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WebAssemblyImportNameAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, WorkGroupSizeHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, X86ForceAlignArgPointerAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, XRayInstrumentAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, XRayLogArgsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, ZeroCallUsedRegsAttr)
  bool ShouldInheritEvenIfAlreadyPresent(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(InheritableAttr)
};

static_assert(sizeof(Attr) == sizeof(InheritableAttr));

class InheritableParamAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InheritableParamAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, InheritableParamAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, InheritableParamAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, AnnotateAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, CFConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, CarriesDependencyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, NSConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, NonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, OSConsumedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, ParameterABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, PassObjectSizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, ReleaseHandleAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, SwiftAsyncContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, SwiftContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, SwiftErrorResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, SwiftIndirectResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableParamAttr, UseHandleAttr)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(InheritableParamAttr)
};

static_assert(sizeof(Attr) == sizeof(InheritableParamAttr));

class InitPriorityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InitPriorityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, InitPriorityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, InitPriorityAttr)
  uint32_t Priority(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(InitPriorityAttr)
};

static_assert(sizeof(Attr) == sizeof(InitPriorityAttr));

class InitSegAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InitSegAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, InitSegAttr)
  std::string_view Section(void) const;
  uint32_t SectionLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(InitSegAttr)
};

static_assert(sizeof(Attr) == sizeof(InitSegAttr));

class IntelOclBiccAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IntelOclBiccAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, IntelOclBiccAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, IntelOclBiccAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(IntelOclBiccAttr)
};

static_assert(sizeof(Attr) == sizeof(IntelOclBiccAttr));

class InternalLinkageAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InternalLinkageAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, InternalLinkageAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, InternalLinkageAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(InternalLinkageAttr)
};

static_assert(sizeof(Attr) == sizeof(InternalLinkageAttr));

class LTOVisibilityPublicAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LTOVisibilityPublicAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LTOVisibilityPublicAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, LTOVisibilityPublicAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LTOVisibilityPublicAttr)
};

static_assert(sizeof(Attr) == sizeof(LTOVisibilityPublicAttr));

class LayoutVersionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LayoutVersionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LayoutVersionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, LayoutVersionAttr)
  std::string_view Spelling(void) const;
  uint32_t Version(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LayoutVersionAttr)
};

static_assert(sizeof(Attr) == sizeof(LayoutVersionAttr));

class LeafAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LeafAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LeafAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, LeafAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LeafAttr)
};

static_assert(sizeof(Attr) == sizeof(LeafAttr));

class LifetimeBoundAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LifetimeBoundAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LifetimeBoundAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, LifetimeBoundAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LifetimeBoundAttr)
};

static_assert(sizeof(Attr) == sizeof(LifetimeBoundAttr));

class LoaderUninitializedAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LoaderUninitializedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LoaderUninitializedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LoaderUninitializedAttr)
};

static_assert(sizeof(Attr) == sizeof(LoaderUninitializedAttr));

class LockReturnedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LockReturnedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LockReturnedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, LockReturnedAttr)
  ::pasta::Expr Argument(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LockReturnedAttr)
};

static_assert(sizeof(Attr) == sizeof(LockReturnedAttr));

class LocksExcludedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LocksExcludedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LocksExcludedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, LocksExcludedAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LocksExcludedAttr)
};

static_assert(sizeof(Attr) == sizeof(LocksExcludedAttr));

class LoopHintAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LoopHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LoopHintAttr)
  // DiagnosticName: (std::basic_string<char, std::char_traits<char>, std::allocator<char>>)
  enum LoopHintAttrOptionType Option(void) const;
  enum LoopHintAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  enum LoopHintAttrLoopHintState State(void) const;
  std::optional<::pasta::Expr> Value(void) const;
  // ValueString: (std::basic_string<char, std::char_traits<char>, std::allocator<char>>)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LoopHintAttr)
};

static_assert(sizeof(Attr) == sizeof(LoopHintAttr));

class M68kInterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(M68kInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, M68kInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, M68kInterruptAttr)
  uint32_t Number(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(M68kInterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(M68kInterruptAttr));

class MIGServerRoutineAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MIGServerRoutineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MIGServerRoutineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MIGServerRoutineAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MIGServerRoutineAttr)
};

static_assert(sizeof(Attr) == sizeof(MIGServerRoutineAttr));

class MSABIAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSABIAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSABIAttr)
};

static_assert(sizeof(Attr) == sizeof(MSABIAttr));

class MSAllocatorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSAllocatorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSAllocatorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSAllocatorAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSAllocatorAttr)
};

static_assert(sizeof(Attr) == sizeof(MSAllocatorAttr));

class MSInheritanceAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSInheritanceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSInheritanceAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSInheritanceAttr)
  bool BestCase(void) const;
  enum MSInheritanceModel InheritanceModel(void) const;
  enum MSInheritanceAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSInheritanceAttr)
};

static_assert(sizeof(Attr) == sizeof(MSInheritanceAttr));

class MSNoVTableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSNoVTableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSNoVTableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSNoVTableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSNoVTableAttr)
};

static_assert(sizeof(Attr) == sizeof(MSNoVTableAttr));

class MSP430InterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSP430InterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSP430InterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSP430InterruptAttr)
  uint32_t Number(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSP430InterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(MSP430InterruptAttr));

class MSStructAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSStructAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSStructAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSStructAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSStructAttr)
};

static_assert(sizeof(Attr) == sizeof(MSStructAttr));

class MSVtorDispAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSVtorDispAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MSVtorDispAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MSVtorDispAttr)
  std::string_view Spelling(void) const;
  uint32_t Vdm(void) const;
  enum MSVtorDispMode VtorDispMode(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MSVtorDispAttr)
};

static_assert(sizeof(Attr) == sizeof(MSVtorDispAttr));

class MaxFieldAlignmentAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MaxFieldAlignmentAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MaxFieldAlignmentAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MaxFieldAlignmentAttr)
  uint32_t Alignment(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MaxFieldAlignmentAttr)
};

static_assert(sizeof(Attr) == sizeof(MaxFieldAlignmentAttr));

class MayAliasAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MayAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MayAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MayAliasAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MayAliasAttr)
};

static_assert(sizeof(Attr) == sizeof(MayAliasAttr));

class MaybeUndefAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MaybeUndefAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MaybeUndefAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MaybeUndefAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MaybeUndefAttr)
};

static_assert(sizeof(Attr) == sizeof(MaybeUndefAttr));

class MicroMipsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MicroMipsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MicroMipsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MicroMipsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MicroMipsAttr)
};

static_assert(sizeof(Attr) == sizeof(MicroMipsAttr));

class MinSizeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MinSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MinSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MinSizeAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MinSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(MinSizeAttr));

class MinVectorWidthAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MinVectorWidthAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MinVectorWidthAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MinVectorWidthAttr)
  std::string_view Spelling(void) const;
  uint32_t VectorWidth(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MinVectorWidthAttr)
};

static_assert(sizeof(Attr) == sizeof(MinVectorWidthAttr));

class Mips16Attr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Mips16Attr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, Mips16Attr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, Mips16Attr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(Mips16Attr)
};

static_assert(sizeof(Attr) == sizeof(Mips16Attr));

class MipsInterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MipsInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MipsInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MipsInterruptAttr)
  enum MipsInterruptAttrInterruptType Interrupt(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MipsInterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(MipsInterruptAttr));

class MipsLongCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MipsLongCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MipsLongCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MipsLongCallAttr)
  enum MipsLongCallAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MipsLongCallAttr)
};

static_assert(sizeof(Attr) == sizeof(MipsLongCallAttr));

class MipsShortCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MipsShortCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MipsShortCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MipsShortCallAttr)
  enum MipsShortCallAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MipsShortCallAttr)
};

static_assert(sizeof(Attr) == sizeof(MipsShortCallAttr));

class ModeAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ModeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ModeAttr)
  // Mode: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ModeAttr)
};

static_assert(sizeof(Attr) == sizeof(ModeAttr));

class NSConsumedAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NSConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NSConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NSConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, NSConsumedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NSConsumedAttr)
};

static_assert(sizeof(Attr) == sizeof(NSConsumedAttr));

class NSConsumesSelfAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NSConsumesSelfAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NSConsumesSelfAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NSConsumesSelfAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NSConsumesSelfAttr)
};

static_assert(sizeof(Attr) == sizeof(NSConsumesSelfAttr));

class NSErrorDomainAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NSErrorDomainAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NSErrorDomainAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NSErrorDomainAttr)
  ::pasta::VarDecl ErrorDomain(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NSErrorDomainAttr)
};

static_assert(sizeof(Attr) == sizeof(NSErrorDomainAttr));

class NSReturnsAutoreleasedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NSReturnsAutoreleasedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NSReturnsAutoreleasedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NSReturnsAutoreleasedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NSReturnsAutoreleasedAttr)
};

static_assert(sizeof(Attr) == sizeof(NSReturnsAutoreleasedAttr));

class NSReturnsNotRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NSReturnsNotRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NSReturnsNotRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NSReturnsNotRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NSReturnsNotRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(NSReturnsNotRetainedAttr));

class NSReturnsRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NSReturnsRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NSReturnsRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NSReturnsRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NSReturnsRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(NSReturnsRetainedAttr));

class NakedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NakedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NakedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NakedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NakedAttr)
};

static_assert(sizeof(Attr) == sizeof(NakedAttr));

class NoAliasAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoAliasAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoAliasAttr)
};

static_assert(sizeof(Attr) == sizeof(NoAliasAttr));

class NoBuiltinAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoBuiltinAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoBuiltinAttr)
  // BuiltinNames: (llvm::iterator_range<llvm::StringRef *>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoBuiltinAttr)
};

static_assert(sizeof(Attr) == sizeof(NoBuiltinAttr));

class NoCommonAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoCommonAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoCommonAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoCommonAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoCommonAttr)
};

static_assert(sizeof(Attr) == sizeof(NoCommonAttr));

class NoDebugAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoDebugAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoDebugAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoDebugAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoDebugAttr)
};

static_assert(sizeof(Attr) == sizeof(NoDebugAttr));

class NoDestroyAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoDestroyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoDestroyAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoDestroyAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoDestroyAttr)
};

static_assert(sizeof(Attr) == sizeof(NoDestroyAttr));

class NoDuplicateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoDuplicateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoDuplicateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoDuplicateAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoDuplicateAttr)
};

static_assert(sizeof(Attr) == sizeof(NoDuplicateAttr));

class NoEscapeAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoEscapeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoEscapeAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoEscapeAttr)
};

static_assert(sizeof(Attr) == sizeof(NoEscapeAttr));

class NoInstrumentFunctionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoInstrumentFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoInstrumentFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoInstrumentFunctionAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoInstrumentFunctionAttr)
};

static_assert(sizeof(Attr) == sizeof(NoInstrumentFunctionAttr));

class NoMicroMipsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoMicroMipsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoMicroMipsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoMicroMipsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoMicroMipsAttr)
};

static_assert(sizeof(Attr) == sizeof(NoMicroMipsAttr));

class NoMips16Attr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoMips16Attr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoMips16Attr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoMips16Attr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoMips16Attr)
};

static_assert(sizeof(Attr) == sizeof(NoMips16Attr));

class NoProfileFunctionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoProfileFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoProfileFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoProfileFunctionAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoProfileFunctionAttr)
};

static_assert(sizeof(Attr) == sizeof(NoProfileFunctionAttr));

class NoRandomizeLayoutAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoRandomizeLayoutAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoRandomizeLayoutAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoRandomizeLayoutAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoRandomizeLayoutAttr)
};

static_assert(sizeof(Attr) == sizeof(NoRandomizeLayoutAttr));

class NoReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoReturnAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoReturnAttr)
};

static_assert(sizeof(Attr) == sizeof(NoReturnAttr));

class NoSanitizeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoSanitizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoSanitizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoSanitizeAttr)
  // Mask: (clang::SanitizerMask)
  std::string_view Spelling(void) const;
  bool HasCoverage(void) const;
  // Sanitizers: (llvm::iterator_range<llvm::StringRef *>)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoSanitizeAttr)
};

static_assert(sizeof(Attr) == sizeof(NoSanitizeAttr));

class NoSpeculativeLoadHardeningAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoSpeculativeLoadHardeningAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoSpeculativeLoadHardeningAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoSpeculativeLoadHardeningAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoSpeculativeLoadHardeningAttr)
};

static_assert(sizeof(Attr) == sizeof(NoSpeculativeLoadHardeningAttr));

class NoSplitStackAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoSplitStackAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoSplitStackAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoSplitStackAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoSplitStackAttr)
};

static_assert(sizeof(Attr) == sizeof(NoSplitStackAttr));

class NoStackProtectorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoStackProtectorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoStackProtectorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoStackProtectorAttr)
  enum NoStackProtectorAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoStackProtectorAttr)
};

static_assert(sizeof(Attr) == sizeof(NoStackProtectorAttr));

class NoThreadSafetyAnalysisAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoThreadSafetyAnalysisAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoThreadSafetyAnalysisAttr)
};

static_assert(sizeof(Attr) == sizeof(NoThreadSafetyAnalysisAttr));

class NoThrowAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoThrowAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoThrowAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoThrowAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoThrowAttr)
};

static_assert(sizeof(Attr) == sizeof(NoThrowAttr));

class NoUniqueAddressAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoUniqueAddressAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoUniqueAddressAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoUniqueAddressAttr)
};

static_assert(sizeof(Attr) == sizeof(NoUniqueAddressAttr));

class NoUwtableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoUwtableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoUwtableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoUwtableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoUwtableAttr)
};

static_assert(sizeof(Attr) == sizeof(NoUwtableAttr));

class NonNullAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, NonNullAttr)
  // Arguments: (llvm::iterator_range<clang::ParamIdx *>)
  std::string_view Spelling(void) const;
  // IsNonNull: (bool)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NonNullAttr)
};

static_assert(sizeof(Attr) == sizeof(NonNullAttr));

class NotTailCalledAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NotTailCalledAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NotTailCalledAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NotTailCalledAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NotTailCalledAttr)
};

static_assert(sizeof(Attr) == sizeof(NotTailCalledAttr));

class OMPAllocateDeclAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPAllocateDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPAllocateDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OMPAllocateDeclAttr)
  ::pasta::Expr Alignment(void) const;
  ::pasta::Expr Allocator(void) const;
  enum OMPAllocateDeclAttrAllocatorTypeTy AllocatorType(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPAllocateDeclAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPAllocateDeclAttr));

class OMPCaptureKindAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCaptureKindAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPCaptureKindAttr)
  // CaptureKind: (llvm::omp::Clause)
  uint32_t CaptureKindValue(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPCaptureKindAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPCaptureKindAttr));

class OMPCaptureNoInitAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCaptureNoInitAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPCaptureNoInitAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OMPCaptureNoInitAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPCaptureNoInitAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPCaptureNoInitAttr));

class OMPDeclareSimdDeclAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareSimdDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPDeclareSimdDeclAttr)
  // Aligneds: (llvm::iterator_range<clang::Expr **>)
  // Alignments: (llvm::iterator_range<clang::Expr **>)
  enum OMPDeclareSimdDeclAttrBranchStateTy BranchState(void) const;
  ::pasta::Expr Simdlen(void) const;
  std::string_view Spelling(void) const;
  // Linears: (llvm::iterator_range<clang::Expr **>)
  // Modifiers: (llvm::iterator_range<unsigned int *>)
  // Steps: (llvm::iterator_range<clang::Expr **>)
  // Uniforms: (llvm::iterator_range<clang::Expr **>)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPDeclareSimdDeclAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPDeclareSimdDeclAttr));

class OMPDeclareTargetDeclAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareTargetDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPDeclareTargetDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OMPDeclareTargetDeclAttr)
  enum OMPDeclareTargetDeclAttrDevTypeTy DevType(void) const;
  bool Indirect(void) const;
  ::pasta::Expr IndirectExpression(void) const;
  uint32_t Level(void) const;
  enum OMPDeclareTargetDeclAttrMapTypeTy MapType(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPDeclareTargetDeclAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPDeclareTargetDeclAttr));

class OMPDeclareVariantAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareVariantAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPDeclareVariantAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OMPDeclareVariantAttr)
  // AdjustArgumentsNeedDevicePointer: (llvm::iterator_range<clang::Expr **>)
  // AdjustArgumentsNothing: (llvm::iterator_range<clang::Expr **>)
  // AppendArguments: (llvm::iterator_range<clang::OMPInteropInfo *>)
  std::string_view Spelling(void) const;
  // TraitInfos: (clang::OMPTraitInfo *)
  ::pasta::Expr VariantFuncReference(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPDeclareVariantAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPDeclareVariantAttr));

class OMPReferencedVarAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPReferencedVarAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPReferencedVarAttr)
  ::pasta::Expr Reference(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPReferencedVarAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPReferencedVarAttr));

class OMPThreadPrivateDeclAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPThreadPrivateDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OMPThreadPrivateDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OMPThreadPrivateDeclAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OMPThreadPrivateDeclAttr)
};

static_assert(sizeof(Attr) == sizeof(OMPThreadPrivateDeclAttr));

class OSConsumedAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OSConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OSConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OSConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, OSConsumedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OSConsumedAttr)
};

static_assert(sizeof(Attr) == sizeof(OSConsumedAttr));

class OSConsumesThisAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OSConsumesThisAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OSConsumesThisAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OSConsumesThisAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OSConsumesThisAttr)
};

static_assert(sizeof(Attr) == sizeof(OSConsumesThisAttr));

class OSReturnsNotRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OSReturnsNotRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OSReturnsNotRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OSReturnsNotRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OSReturnsNotRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(OSReturnsNotRetainedAttr));

class OSReturnsRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OSReturnsRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OSReturnsRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OSReturnsRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(OSReturnsRetainedAttr));

class OSReturnsRetainedOnNonZeroAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OSReturnsRetainedOnNonZeroAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OSReturnsRetainedOnNonZeroAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedOnNonZeroAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OSReturnsRetainedOnNonZeroAttr)
};

static_assert(sizeof(Attr) == sizeof(OSReturnsRetainedOnNonZeroAttr));

class OSReturnsRetainedOnZeroAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OSReturnsRetainedOnZeroAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OSReturnsRetainedOnZeroAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedOnZeroAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OSReturnsRetainedOnZeroAttr)
};

static_assert(sizeof(Attr) == sizeof(OSReturnsRetainedOnZeroAttr));

class ObjCBoxableAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBoxableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCBoxableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCBoxableAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCBoxableAttr));

class ObjCBridgeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBridgeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCBridgeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCBridgeAttr)
  // BridgedType: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCBridgeAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCBridgeAttr));

class ObjCBridgeMutableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBridgeMutableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCBridgeMutableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCBridgeMutableAttr)
  // BridgedType: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCBridgeMutableAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCBridgeMutableAttr));

class ObjCBridgeRelatedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBridgeRelatedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCBridgeRelatedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCBridgeRelatedAttr)
  // ClassMethod: (clang::IdentifierInfo *)
  // InstanceMethod: (clang::IdentifierInfo *)
  // RelatedClass: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCBridgeRelatedAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCBridgeRelatedAttr));

class ObjCClassStubAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCClassStubAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCClassStubAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCClassStubAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCClassStubAttr));

class ObjCDesignatedInitializerAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCDesignatedInitializerAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCDesignatedInitializerAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCDesignatedInitializerAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCDesignatedInitializerAttr));

class ObjCDirectAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCDirectAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCDirectAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCDirectAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCDirectAttr));

class ObjCDirectMembersAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCDirectMembersAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCDirectMembersAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCDirectMembersAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCDirectMembersAttr));

class ObjCExceptionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCExceptionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCExceptionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCExceptionAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCExceptionAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCExceptionAttr));

class ObjCExplicitProtocolImplAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCExplicitProtocolImplAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCExplicitProtocolImplAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCExplicitProtocolImplAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCExplicitProtocolImplAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCExplicitProtocolImplAttr));

class ObjCExternallyRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCExternallyRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCExternallyRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCExternallyRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCExternallyRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCExternallyRetainedAttr));

class ObjCIndependentClassAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCIndependentClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCIndependentClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCIndependentClassAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCIndependentClassAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCIndependentClassAttr));

class ObjCMethodFamilyAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCMethodFamilyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCMethodFamilyAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCMethodFamilyAttr)
  enum ObjCMethodFamilyAttrFamilyKind Family(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCMethodFamilyAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCMethodFamilyAttr));

class ObjCNSObjectAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCNSObjectAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCNSObjectAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCNSObjectAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCNSObjectAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCNSObjectAttr));

class ObjCNonLazyClassAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCNonLazyClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCNonLazyClassAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCNonLazyClassAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCNonLazyClassAttr));

class ObjCNonRuntimeProtocolAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCNonRuntimeProtocolAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCNonRuntimeProtocolAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCNonRuntimeProtocolAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCNonRuntimeProtocolAttr));

class ObjCOwnershipAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCOwnershipAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCOwnershipAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCOwnershipAttr)
  // Kind: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCOwnershipAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCOwnershipAttr));

class ObjCPreciseLifetimeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPreciseLifetimeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCPreciseLifetimeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCPreciseLifetimeAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCPreciseLifetimeAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCPreciseLifetimeAttr));

class ObjCRequiresPropertyDefsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCRequiresPropertyDefsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCRequiresPropertyDefsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCRequiresPropertyDefsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCRequiresPropertyDefsAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCRequiresPropertyDefsAttr));

class ObjCRequiresSuperAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCRequiresSuperAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCRequiresSuperAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCRequiresSuperAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCRequiresSuperAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCRequiresSuperAttr));

class ObjCReturnsInnerPointerAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCReturnsInnerPointerAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCReturnsInnerPointerAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCReturnsInnerPointerAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCReturnsInnerPointerAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCReturnsInnerPointerAttr));

class ObjCRootClassAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCRootClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCRootClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCRootClassAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCRootClassAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCRootClassAttr));

class ObjCRuntimeNameAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCRuntimeNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCRuntimeNameAttr)
  std::string_view MetadataName(void) const;
  uint32_t MetadataNameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCRuntimeNameAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCRuntimeNameAttr));

class ObjCRuntimeVisibleAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCRuntimeVisibleAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCRuntimeVisibleAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCRuntimeVisibleAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCRuntimeVisibleAttr));

class ObjCSubclassingRestrictedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCSubclassingRestrictedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCSubclassingRestrictedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ObjCSubclassingRestrictedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCSubclassingRestrictedAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCSubclassingRestrictedAttr));

class OpenCLAccessAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLAccessAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLAccessAttr)
  enum OpenCLAccessAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsReadOnly(void) const;
  bool IsReadWrite(void) const;
  bool IsWriteOnly(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLAccessAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLAccessAttr));

class OpenCLIntelReqdSubGroupSizeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLIntelReqdSubGroupSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLIntelReqdSubGroupSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OpenCLIntelReqdSubGroupSizeAttr)
  std::string_view Spelling(void) const;
  uint32_t SubGroupSize(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLIntelReqdSubGroupSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLIntelReqdSubGroupSizeAttr));

class OpenCLKernelAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLKernelAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLKernelAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OpenCLKernelAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLKernelAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLKernelAttr));

class OptimizeNoneAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OptimizeNoneAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OptimizeNoneAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OptimizeNoneAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OptimizeNoneAttr)
};

static_assert(sizeof(Attr) == sizeof(OptimizeNoneAttr));

class OverloadableAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OverloadableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OverloadableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OverloadableAttr)
};

static_assert(sizeof(Attr) == sizeof(OverloadableAttr));

class OverrideAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OverrideAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OverrideAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OverrideAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OverrideAttr)
};

static_assert(sizeof(Attr) == sizeof(OverrideAttr));

class OwnerAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OwnerAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OwnerAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OwnerAttr)
  ::pasta::Type DerefType(void) const;
  ::pasta::Type DerefTypeToken(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OwnerAttr)
};

static_assert(sizeof(Attr) == sizeof(OwnerAttr));

class OwnershipAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OwnershipAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OwnershipAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, OwnershipAttr)
  // Arguments: (llvm::iterator_range<clang::ParamIdx *>)
  // Module: (clang::IdentifierInfo *)
  enum OwnershipAttrOwnershipKind OwnKind(void) const;
  enum OwnershipAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsHolds(void) const;
  bool IsReturns(void) const;
  bool IsTakes(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OwnershipAttr)
};

static_assert(sizeof(Attr) == sizeof(OwnershipAttr));

class PackedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PackedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PackedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PackedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PackedAttr)
};

static_assert(sizeof(Attr) == sizeof(PackedAttr));

class ParamTypestateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParamTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ParamTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ParamTypestateAttr)
  enum ParamTypestateAttrConsumedState ParameterState(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ParamTypestateAttr)
};

static_assert(sizeof(Attr) == sizeof(ParamTypestateAttr));

class ParameterABIAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParameterABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ParameterABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ParameterABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, ParameterABIAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(ParameterABIAttr, SwiftAsyncContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(ParameterABIAttr, SwiftContextAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(ParameterABIAttr, SwiftErrorResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(ParameterABIAttr, SwiftIndirectResultAttr)
  ::pasta::ParameterABI ABI(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ParameterABIAttr)
};

static_assert(sizeof(Attr) == sizeof(ParameterABIAttr));

class PascalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PascalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PascalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PascalAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PascalAttr)
};

static_assert(sizeof(Attr) == sizeof(PascalAttr));

class PassObjectSizeAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PassObjectSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PassObjectSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PassObjectSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, PassObjectSizeAttr)
  enum PassObjectSizeAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  // Type: (int)
  bool IsDynamic(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PassObjectSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(PassObjectSizeAttr));

class PatchableFunctionEntryAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PatchableFunctionEntryAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PatchableFunctionEntryAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PatchableFunctionEntryAttr)
  uint32_t Count(void) const;
  // Offset: (int)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PatchableFunctionEntryAttr)
};

static_assert(sizeof(Attr) == sizeof(PatchableFunctionEntryAttr));

class PcsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PcsAttr)
  enum PcsAttrPCSType PCS(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PcsAttr)
};

static_assert(sizeof(Attr) == sizeof(PcsAttr));

class PointerAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PointerAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PointerAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PointerAttr)
  ::pasta::Type DerefType(void) const;
  ::pasta::Type DerefTypeToken(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PointerAttr)
};

static_assert(sizeof(Attr) == sizeof(PointerAttr));

class PragmaClangBSSSectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaClangBSSSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PragmaClangBSSSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PragmaClangBSSSectionAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PragmaClangBSSSectionAttr)
};

static_assert(sizeof(Attr) == sizeof(PragmaClangBSSSectionAttr));

class PragmaClangDataSectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaClangDataSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PragmaClangDataSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PragmaClangDataSectionAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PragmaClangDataSectionAttr)
};

static_assert(sizeof(Attr) == sizeof(PragmaClangDataSectionAttr));

class PragmaClangRelroSectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaClangRelroSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PragmaClangRelroSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PragmaClangRelroSectionAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PragmaClangRelroSectionAttr)
};

static_assert(sizeof(Attr) == sizeof(PragmaClangRelroSectionAttr));

class PragmaClangRodataSectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaClangRodataSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PragmaClangRodataSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PragmaClangRodataSectionAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PragmaClangRodataSectionAttr)
};

static_assert(sizeof(Attr) == sizeof(PragmaClangRodataSectionAttr));

class PragmaClangTextSectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaClangTextSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PragmaClangTextSectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PragmaClangTextSectionAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PragmaClangTextSectionAttr)
};

static_assert(sizeof(Attr) == sizeof(PragmaClangTextSectionAttr));

class PreferredNameAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PreferredNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PreferredNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PreferredNameAttr)
  std::string_view Spelling(void) const;
  ::pasta::Type TypedefType(void) const;
  ::pasta::Type TypedefTypeToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PreferredNameAttr)
};

static_assert(sizeof(Attr) == sizeof(PreferredNameAttr));

class PreserveAllAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PreserveAllAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PreserveAllAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PreserveAllAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PreserveAllAttr)
};

static_assert(sizeof(Attr) == sizeof(PreserveAllAttr));

class PreserveMostAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PreserveMostAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PreserveMostAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PreserveMostAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PreserveMostAttr)
};

static_assert(sizeof(Attr) == sizeof(PreserveMostAttr));

class PtGuardedByAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PtGuardedByAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PtGuardedByAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PtGuardedByAttr)
  ::pasta::Expr Argument(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PtGuardedByAttr)
};

static_assert(sizeof(Attr) == sizeof(PtGuardedByAttr));

class PtGuardedVarAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PtGuardedVarAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PtGuardedVarAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PtGuardedVarAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PtGuardedVarAttr)
};

static_assert(sizeof(Attr) == sizeof(PtGuardedVarAttr));

class PureAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PureAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, PureAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, PureAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(PureAttr)
};

static_assert(sizeof(Attr) == sizeof(PureAttr));

class RISCVInterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RISCVInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RISCVInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RISCVInterruptAttr)
  enum RISCVInterruptAttrInterruptType Interrupt(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RISCVInterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(RISCVInterruptAttr));

class RandomizeLayoutAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RandomizeLayoutAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RandomizeLayoutAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RandomizeLayoutAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RandomizeLayoutAttr)
};

static_assert(sizeof(Attr) == sizeof(RandomizeLayoutAttr));

class ReadOnlyPlacementAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReadOnlyPlacementAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReadOnlyPlacementAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReadOnlyPlacementAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReadOnlyPlacementAttr)
};

static_assert(sizeof(Attr) == sizeof(ReadOnlyPlacementAttr));

class RegCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RegCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RegCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RegCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RegCallAttr)
};

static_assert(sizeof(Attr) == sizeof(RegCallAttr));

class ReinitializesAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReinitializesAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReinitializesAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReinitializesAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReinitializesAttr)
};

static_assert(sizeof(Attr) == sizeof(ReinitializesAttr));

class ReleaseCapabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReleaseCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReleaseCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReleaseCapabilityAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  enum ReleaseCapabilityAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsGeneric(void) const;
  bool IsShared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReleaseCapabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(ReleaseCapabilityAttr));

class ReleaseHandleAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReleaseHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReleaseHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReleaseHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, ReleaseHandleAttr)
  std::string_view HandleType(void) const;
  uint32_t HandleTypeLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReleaseHandleAttr)
};

static_assert(sizeof(Attr) == sizeof(ReleaseHandleAttr));

class RenderScriptKernelAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RenderScriptKernelAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RenderScriptKernelAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RenderScriptKernelAttr)
};

static_assert(sizeof(Attr) == sizeof(RenderScriptKernelAttr));

class ReqdWorkGroupSizeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReqdWorkGroupSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReqdWorkGroupSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReqdWorkGroupSizeAttr)
  std::string_view Spelling(void) const;
  uint32_t XDim(void) const;
  uint32_t YDim(void) const;
  uint32_t ZDim(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReqdWorkGroupSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(ReqdWorkGroupSizeAttr));

class RequiresCapabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RequiresCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RequiresCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RequiresCapabilityAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  enum RequiresCapabilityAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsShared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RequiresCapabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(RequiresCapabilityAttr));

class RestrictAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RestrictAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RestrictAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RestrictAttr)
  enum RestrictAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RestrictAttr)
};

static_assert(sizeof(Attr) == sizeof(RestrictAttr));

class RetainAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RetainAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RetainAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RetainAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RetainAttr)
};

static_assert(sizeof(Attr) == sizeof(RetainAttr));

class ReturnTypestateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReturnTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReturnTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReturnTypestateAttr)
  std::string_view Spelling(void) const;
  enum ReturnTypestateAttrConsumedState State(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReturnTypestateAttr)
};

static_assert(sizeof(Attr) == sizeof(ReturnTypestateAttr));

class ReturnsNonNullAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReturnsNonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReturnsNonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReturnsNonNullAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReturnsNonNullAttr)
};

static_assert(sizeof(Attr) == sizeof(ReturnsNonNullAttr));

class ReturnsTwiceAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReturnsTwiceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ReturnsTwiceAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ReturnsTwiceAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ReturnsTwiceAttr)
};

static_assert(sizeof(Attr) == sizeof(ReturnsTwiceAttr));

class SYCLKernelAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SYCLKernelAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SYCLKernelAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SYCLKernelAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SYCLKernelAttr)
};

static_assert(sizeof(Attr) == sizeof(SYCLKernelAttr));

class SYCLSpecialClassAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SYCLSpecialClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SYCLSpecialClassAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SYCLSpecialClassAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SYCLSpecialClassAttr)
};

static_assert(sizeof(Attr) == sizeof(SYCLSpecialClassAttr));

class ScopedLockableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ScopedLockableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ScopedLockableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ScopedLockableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ScopedLockableAttr)
};

static_assert(sizeof(Attr) == sizeof(ScopedLockableAttr));

class SectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SectionAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  enum SectionAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SectionAttr)
};

static_assert(sizeof(Attr) == sizeof(SectionAttr));

class SelectAnyAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SelectAnyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SelectAnyAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SelectAnyAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SelectAnyAttr)
};

static_assert(sizeof(Attr) == sizeof(SelectAnyAttr));

class SentinelAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SentinelAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SentinelAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SentinelAttr)
  // NullPos: (int)
  // Sentinel: (int)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SentinelAttr)
};

static_assert(sizeof(Attr) == sizeof(SentinelAttr));

class SetTypestateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SetTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SetTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SetTypestateAttr)
  enum SetTypestateAttrConsumedState NewState(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SetTypestateAttr)
};

static_assert(sizeof(Attr) == sizeof(SetTypestateAttr));

class SharedTrylockFunctionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SharedTrylockFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SharedTrylockFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SharedTrylockFunctionAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
  ::pasta::Expr SuccessValue(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SharedTrylockFunctionAttr)
};

static_assert(sizeof(Attr) == sizeof(SharedTrylockFunctionAttr));

class SpeculativeLoadHardeningAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SpeculativeLoadHardeningAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SpeculativeLoadHardeningAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SpeculativeLoadHardeningAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SpeculativeLoadHardeningAttr)
};

static_assert(sizeof(Attr) == sizeof(SpeculativeLoadHardeningAttr));

class StandaloneDebugAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StandaloneDebugAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, StandaloneDebugAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, StandaloneDebugAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(StandaloneDebugAttr)
};

static_assert(sizeof(Attr) == sizeof(StandaloneDebugAttr));

class StdCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StdCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, StdCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, StdCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(StdCallAttr)
};

static_assert(sizeof(Attr) == sizeof(StdCallAttr));

class StmtAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StmtAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, StmtAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(StmtAttr, FallThroughAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(StmtAttr, LikelyAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(StmtAttr, MustTailAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(StmtAttr, OpenCLUnrollHintAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(StmtAttr, SuppressAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(StmtAttr, UnlikelyAttr)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(StmtAttr)
};

static_assert(sizeof(Attr) == sizeof(StmtAttr));

class StrictFPAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StrictFPAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, StrictFPAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, StrictFPAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(StrictFPAttr)
};

static_assert(sizeof(Attr) == sizeof(StrictFPAttr));

class StrictGuardStackCheckAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StrictGuardStackCheckAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, StrictGuardStackCheckAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, StrictGuardStackCheckAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(StrictGuardStackCheckAttr)
};

static_assert(sizeof(Attr) == sizeof(StrictGuardStackCheckAttr));

class SuppressAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SuppressAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SuppressAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, SuppressAttr)
  // DiagnosticIdentifiers: (llvm::iterator_range<llvm::StringRef *>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SuppressAttr)
};

static_assert(sizeof(Attr) == sizeof(SuppressAttr));

class SwiftAsyncAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftAsyncAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftAsyncAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftAsyncAttr)
  // CompletionHandlerIndex: (clang::ParamIdx)
  enum SwiftAsyncAttrKind AttributeKind(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftAsyncAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftAsyncAttr));

class SwiftAsyncCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftAsyncCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftAsyncCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftAsyncCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftAsyncCallAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftAsyncCallAttr));

class SwiftAsyncContextAttr : public ParameterABIAttr {
 private:
  using ParameterABIAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftAsyncContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftAsyncContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftAsyncContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, SwiftAsyncContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(ParameterABIAttr, SwiftAsyncContextAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftAsyncContextAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftAsyncContextAttr));

class SwiftAsyncErrorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftAsyncErrorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftAsyncErrorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftAsyncErrorAttr)
  enum SwiftAsyncErrorAttrConventionKind Convention(void) const;
  uint32_t HandlerParameterIndex(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftAsyncErrorAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftAsyncErrorAttr));

class SwiftAsyncNameAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftAsyncNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftAsyncNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftAsyncNameAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftAsyncNameAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftAsyncNameAttr));

class SwiftAttrAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftAttrAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftAttrAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftAttrAttr)
  std::string_view Attribute(void) const;
  uint32_t AttributeLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftAttrAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftAttrAttr));

class SwiftBridgeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftBridgeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftBridgeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftBridgeAttr)
  std::string_view Spelling(void) const;
  std::string_view SwiftType(void) const;
  uint32_t SwiftTypeLength(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftBridgeAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftBridgeAttr));

class SwiftBridgedTypedefAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftBridgedTypedefAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftBridgedTypedefAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftBridgedTypedefAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftBridgedTypedefAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftBridgedTypedefAttr));

class SwiftCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftCallAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftCallAttr));

class SwiftContextAttr : public ParameterABIAttr {
 private:
  using ParameterABIAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, SwiftContextAttr)
  PASTA_DECLARE_BASE_OPERATORS(ParameterABIAttr, SwiftContextAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftContextAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftContextAttr));

class SwiftErrorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftErrorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftErrorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftErrorAttr)
  enum SwiftErrorAttrConventionKind Convention(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftErrorAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftErrorAttr));

class SwiftErrorResultAttr : public ParameterABIAttr {
 private:
  using ParameterABIAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftErrorResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftErrorResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftErrorResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, SwiftErrorResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(ParameterABIAttr, SwiftErrorResultAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftErrorResultAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftErrorResultAttr));

class SwiftIndirectResultAttr : public ParameterABIAttr {
 private:
  using ParameterABIAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftIndirectResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftIndirectResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftIndirectResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, SwiftIndirectResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(ParameterABIAttr, SwiftIndirectResultAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftIndirectResultAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftIndirectResultAttr));

class SwiftNameAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftNameAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftNameAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftNameAttr));

class SwiftNewTypeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftNewTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftNewTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftNewTypeAttr)
  enum SwiftNewTypeAttrNewtypeKind NewtypeKind(void) const;
  enum SwiftNewTypeAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftNewTypeAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftNewTypeAttr));

class SwiftObjCMembersAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftObjCMembersAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftObjCMembersAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftObjCMembersAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftObjCMembersAttr));

class SwiftPrivateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwiftPrivateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SwiftPrivateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SwiftPrivateAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SwiftPrivateAttr)
};

static_assert(sizeof(Attr) == sizeof(SwiftPrivateAttr));

class SysVABIAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SysVABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SysVABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, SysVABIAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SysVABIAttr)
};

static_assert(sizeof(Attr) == sizeof(SysVABIAttr));

class TLSModelAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TLSModelAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TLSModelAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TLSModelAttr)
  std::string_view Model(void) const;
  uint32_t ModelLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TLSModelAttr)
};

static_assert(sizeof(Attr) == sizeof(TLSModelAttr));

class TargetAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TargetAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TargetAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TargetAttr)
  std::string_view Architecture(void) const;
  std::string_view FeaturesString(void) const;
  uint32_t FeaturesStringLength(void) const;
  std::string_view Spelling(void) const;
  bool IsDefaultVersion(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TargetAttr)
};

static_assert(sizeof(Attr) == sizeof(TargetAttr));

class TargetClonesAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TargetClonesAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TargetClonesAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TargetClonesAttr)
  // FeaturesStrings: (llvm::iterator_range<llvm::StringRef *>)
  // FeatureString: (llvm::StringRef)
  // MangledIndex: (unsigned int)
  std::string_view Spelling(void) const;
  // IsFirstOfVersion: (bool)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TargetClonesAttr)
};

static_assert(sizeof(Attr) == sizeof(TargetClonesAttr));

class TargetVersionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TargetVersionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TargetVersionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TargetVersionAttr)
  std::string_view Name(void) const;
  std::string_view NamesString(void) const;
  uint32_t NamesStringLength(void) const;
  std::string_view Spelling(void) const;
  bool IsDefaultVersion(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TargetVersionAttr)
};

static_assert(sizeof(Attr) == sizeof(TargetVersionAttr));

class TestTypestateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TestTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TestTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TestTypestateAttr)
  std::string_view Spelling(void) const;
  enum TestTypestateAttrConsumedState TestState(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TestTypestateAttr)
};

static_assert(sizeof(Attr) == sizeof(TestTypestateAttr));

class ThisCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ThisCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ThisCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ThisCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ThisCallAttr)
};

static_assert(sizeof(Attr) == sizeof(ThisCallAttr));

class ThreadAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ThreadAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ThreadAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ThreadAttr)
};

static_assert(sizeof(Attr) == sizeof(ThreadAttr));

class TransparentUnionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TransparentUnionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TransparentUnionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TransparentUnionAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TransparentUnionAttr)
};

static_assert(sizeof(Attr) == sizeof(TransparentUnionAttr));

class TrivialABIAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TrivialABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TrivialABIAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TrivialABIAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TrivialABIAttr)
};

static_assert(sizeof(Attr) == sizeof(TrivialABIAttr));

class TryAcquireCapabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TryAcquireCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TryAcquireCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TryAcquireCapabilityAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  enum TryAcquireCapabilityAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  ::pasta::Expr SuccessValue(void) const;
  bool IsShared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TryAcquireCapabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(TryAcquireCapabilityAttr));

class TypeAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, AddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, AnnotateTypeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, BTFTypeTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, CmseNSCallAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, HLSLGroupSharedAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, NoDerefAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, ObjCGCAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, ObjCInertUnsafeUnretainedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, ObjCKindOfAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLConstantAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLGenericAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLGlobalAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLGlobalDeviceAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLGlobalHostAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLLocalAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, OpenCLPrivateAddressSpaceAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, Ptr32Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, Ptr64Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, SPtrAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, TypeNonNullAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, TypeNullUnspecifiedAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, TypeNullableAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, TypeNullableResultAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, UPtrAttr)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeAttr));

class TypeNonNullAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeNonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeNonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, TypeNonNullAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeNonNullAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeNonNullAttr));

class TypeNullUnspecifiedAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeNullUnspecifiedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeNullUnspecifiedAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, TypeNullUnspecifiedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeNullUnspecifiedAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeNullUnspecifiedAttr));

class TypeNullableAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeNullableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeNullableAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, TypeNullableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeNullableAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeNullableAttr));

class TypeNullableResultAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeNullableResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeNullableResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, TypeNullableResultAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeNullableResultAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeNullableResultAttr));

class TypeTagForDatatypeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeTagForDatatypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeTagForDatatypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TypeTagForDatatypeAttr)
  // ArgumentKind: (clang::IdentifierInfo *)
  bool LayoutCompatible(void) const;
  ::pasta::Type MatchingCType(void) const;
  ::pasta::Type MatchingCTypeToken(void) const;
  bool MustBeNull(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeTagForDatatypeAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeTagForDatatypeAttr));

class TypeVisibilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeVisibilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TypeVisibilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TypeVisibilityAttr)
  std::string_view Spelling(void) const;
  enum TypeVisibilityAttrVisibilityType Visibility(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TypeVisibilityAttr)
};

static_assert(sizeof(Attr) == sizeof(TypeVisibilityAttr));

class UPtrAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UPtrAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UPtrAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, UPtrAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UPtrAttr)
};

static_assert(sizeof(Attr) == sizeof(UPtrAttr));

class UnavailableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnavailableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UnavailableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UnavailableAttr)
  enum UnavailableAttrImplicitReason ImplicitReason(void) const;
  std::string_view Message(void) const;
  uint32_t MessageLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UnavailableAttr)
};

static_assert(sizeof(Attr) == sizeof(UnavailableAttr));

class UninitializedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UninitializedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UninitializedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UninitializedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UninitializedAttr)
};

static_assert(sizeof(Attr) == sizeof(UninitializedAttr));

class UnlikelyAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnlikelyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UnlikelyAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, UnlikelyAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UnlikelyAttr)
};

static_assert(sizeof(Attr) == sizeof(UnlikelyAttr));

class UnusedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnusedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UnusedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UnusedAttr)
  enum UnusedAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UnusedAttr)
};

static_assert(sizeof(Attr) == sizeof(UnusedAttr));

class UseHandleAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UseHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UseHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UseHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, UseHandleAttr)
  std::string_view HandleType(void) const;
  uint32_t HandleTypeLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UseHandleAttr)
};

static_assert(sizeof(Attr) == sizeof(UseHandleAttr));

class UsedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UsedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UsedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UsedAttr)
};

static_assert(sizeof(Attr) == sizeof(UsedAttr));

class UsingIfExistsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingIfExistsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UsingIfExistsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UsingIfExistsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UsingIfExistsAttr)
};

static_assert(sizeof(Attr) == sizeof(UsingIfExistsAttr));

class UuidAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UuidAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, UuidAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, UuidAttr)
  std::string_view Guid(void) const;
  ::pasta::MSGuidDecl GuidDeclaration(void) const;
  uint32_t GuidLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(UuidAttr)
};

static_assert(sizeof(Attr) == sizeof(UuidAttr));

class VecReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VecReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, VecReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, VecReturnAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(VecReturnAttr)
};

static_assert(sizeof(Attr) == sizeof(VecReturnAttr));

class VecTypeHintAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VecTypeHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, VecTypeHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, VecTypeHintAttr)
  std::string_view Spelling(void) const;
  ::pasta::Type TypeHint(void) const;
  ::pasta::Type TypeHintToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(VecTypeHintAttr)
};

static_assert(sizeof(Attr) == sizeof(VecTypeHintAttr));

class VectorCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VectorCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, VectorCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, VectorCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(VectorCallAttr)
};

static_assert(sizeof(Attr) == sizeof(VectorCallAttr));

class VisibilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VisibilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, VisibilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, VisibilityAttr)
  std::string_view Spelling(void) const;
  enum VisibilityAttrVisibilityType Visibility(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(VisibilityAttr)
};

static_assert(sizeof(Attr) == sizeof(VisibilityAttr));

class WarnUnusedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WarnUnusedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WarnUnusedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WarnUnusedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WarnUnusedAttr)
};

static_assert(sizeof(Attr) == sizeof(WarnUnusedAttr));

class WarnUnusedResultAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WarnUnusedResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WarnUnusedResultAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WarnUnusedResultAttr)
  bool IsCXX11NoDiscard(void) const;
  std::string_view Message(void) const;
  uint32_t MessageLength(void) const;
  enum WarnUnusedResultAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WarnUnusedResultAttr)
};

static_assert(sizeof(Attr) == sizeof(WarnUnusedResultAttr));

class WeakAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WeakAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WeakAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WeakAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WeakAttr)
};

static_assert(sizeof(Attr) == sizeof(WeakAttr));

class WeakImportAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WeakImportAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WeakImportAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WeakImportAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WeakImportAttr)
};

static_assert(sizeof(Attr) == sizeof(WeakImportAttr));

class WeakRefAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WeakRefAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WeakRefAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WeakRefAttr)
  std::string_view Aliasee(void) const;
  uint32_t AliaseeLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WeakRefAttr)
};

static_assert(sizeof(Attr) == sizeof(WeakRefAttr));

class WebAssemblyExportNameAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WebAssemblyExportNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WebAssemblyExportNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WebAssemblyExportNameAttr)
  std::string_view ExportName(void) const;
  uint32_t ExportNameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WebAssemblyExportNameAttr)
};

static_assert(sizeof(Attr) == sizeof(WebAssemblyExportNameAttr));

class WebAssemblyImportModuleAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WebAssemblyImportModuleAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WebAssemblyImportModuleAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WebAssemblyImportModuleAttr)
  std::string_view ImportModule(void) const;
  uint32_t ImportModuleLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WebAssemblyImportModuleAttr)
};

static_assert(sizeof(Attr) == sizeof(WebAssemblyImportModuleAttr));

class WebAssemblyImportNameAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WebAssemblyImportNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WebAssemblyImportNameAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WebAssemblyImportNameAttr)
  std::string_view ImportName(void) const;
  uint32_t ImportNameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WebAssemblyImportNameAttr)
};

static_assert(sizeof(Attr) == sizeof(WebAssemblyImportNameAttr));

class WorkGroupSizeHintAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WorkGroupSizeHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, WorkGroupSizeHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, WorkGroupSizeHintAttr)
  std::string_view Spelling(void) const;
  uint32_t XDim(void) const;
  uint32_t YDim(void) const;
  uint32_t ZDim(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(WorkGroupSizeHintAttr)
};

static_assert(sizeof(Attr) == sizeof(WorkGroupSizeHintAttr));

class X86ForceAlignArgPointerAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(X86ForceAlignArgPointerAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, X86ForceAlignArgPointerAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, X86ForceAlignArgPointerAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(X86ForceAlignArgPointerAttr)
};

static_assert(sizeof(Attr) == sizeof(X86ForceAlignArgPointerAttr));

class XRayInstrumentAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(XRayInstrumentAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, XRayInstrumentAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, XRayInstrumentAttr)
  bool AlwaysXRayInstrument(void) const;
  enum XRayInstrumentAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool NeverXRayInstrument(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(XRayInstrumentAttr)
};

static_assert(sizeof(Attr) == sizeof(XRayInstrumentAttr));

class XRayLogArgsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(XRayLogArgsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, XRayLogArgsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, XRayLogArgsAttr)
  uint32_t ArgumentCount(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(XRayLogArgsAttr)
};

static_assert(sizeof(Attr) == sizeof(XRayLogArgsAttr));

class ZeroCallUsedRegsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ZeroCallUsedRegsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ZeroCallUsedRegsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ZeroCallUsedRegsAttr)
  std::string_view Spelling(void) const;
  enum ZeroCallUsedRegsAttrZeroCallUsedRegsKind ZeroCallUsedRegs(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ZeroCallUsedRegsAttr)
};

static_assert(sizeof(Attr) == sizeof(ZeroCallUsedRegsAttr));

class AArch64SVEPcsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AArch64SVEPcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AArch64SVEPcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AArch64SVEPcsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AArch64SVEPcsAttr)
};

static_assert(sizeof(Attr) == sizeof(AArch64SVEPcsAttr));

class AArch64VectorPcsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AArch64VectorPcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AArch64VectorPcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AArch64VectorPcsAttr)
};

static_assert(sizeof(Attr) == sizeof(AArch64VectorPcsAttr));

class AMDGPUFlatWorkGroupSizeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AMDGPUFlatWorkGroupSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
  ::pasta::Expr Max(void) const;
  ::pasta::Expr Min(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AMDGPUFlatWorkGroupSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(AMDGPUFlatWorkGroupSizeAttr));

class AMDGPUKernelCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AMDGPUKernelCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AMDGPUKernelCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AMDGPUKernelCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AMDGPUKernelCallAttr)
};

static_assert(sizeof(Attr) == sizeof(AMDGPUKernelCallAttr));

class AMDGPUNumSGPRAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AMDGPUNumSGPRAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AMDGPUNumSGPRAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AMDGPUNumSGPRAttr)
  uint32_t NumSGPR(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AMDGPUNumSGPRAttr)
};

static_assert(sizeof(Attr) == sizeof(AMDGPUNumSGPRAttr));

class AMDGPUNumVGPRAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AMDGPUNumVGPRAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AMDGPUNumVGPRAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AMDGPUNumVGPRAttr)
  uint32_t NumVGPR(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AMDGPUNumVGPRAttr)
};

static_assert(sizeof(Attr) == sizeof(AMDGPUNumVGPRAttr));

class AMDGPUWavesPerEUAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AMDGPUWavesPerEUAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AMDGPUWavesPerEUAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AMDGPUWavesPerEUAttr)
  ::pasta::Expr Max(void) const;
  ::pasta::Expr Min(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AMDGPUWavesPerEUAttr)
};

static_assert(sizeof(Attr) == sizeof(AMDGPUWavesPerEUAttr));

class ARMInterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ARMInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ARMInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ARMInterruptAttr)
  enum ARMInterruptAttrInterruptType Interrupt(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ARMInterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(ARMInterruptAttr));

class AVRInterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AVRInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AVRInterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AVRInterruptAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AVRInterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(AVRInterruptAttr));

class AVRSignalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AVRSignalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AVRSignalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AVRSignalAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AVRSignalAttr)
};

static_assert(sizeof(Attr) == sizeof(AVRSignalAttr));

class AbiTagAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AbiTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AbiTagAttr)
  std::string_view Spelling(void) const;
  // Tags: (llvm::iterator_range<llvm::StringRef *>)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AbiTagAttr)
};

static_assert(sizeof(Attr) == sizeof(AbiTagAttr));

class AcquireCapabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AcquireCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AcquireCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AcquireCapabilityAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  enum AcquireCapabilityAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsShared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AcquireCapabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(AcquireCapabilityAttr));

class AcquireHandleAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AcquireHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AcquireHandleAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AcquireHandleAttr)
  std::string_view HandleType(void) const;
  uint32_t HandleTypeLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AcquireHandleAttr)
};

static_assert(sizeof(Attr) == sizeof(AcquireHandleAttr));

class AcquiredAfterAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AcquiredAfterAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AcquiredAfterAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AcquiredAfterAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AcquiredAfterAttr)
};

static_assert(sizeof(Attr) == sizeof(AcquiredAfterAttr));

class AcquiredBeforeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AcquiredBeforeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AcquiredBeforeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AcquiredBeforeAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AcquiredBeforeAttr)
};

static_assert(sizeof(Attr) == sizeof(AcquiredBeforeAttr));

class AddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, AddressSpaceAttr)
  // AddressSpace: (int)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(AddressSpaceAttr));

class AliasAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AliasAttr)
  std::string_view Aliasee(void) const;
  uint32_t AliaseeLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AliasAttr)
};

static_assert(sizeof(Attr) == sizeof(AliasAttr));

class AlignMac68kAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlignMac68kAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlignMac68kAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AlignMac68kAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlignMac68kAttr)
};

static_assert(sizeof(Attr) == sizeof(AlignMac68kAttr));

class AlignNaturalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlignNaturalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlignNaturalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AlignNaturalAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlignNaturalAttr)
};

static_assert(sizeof(Attr) == sizeof(AlignNaturalAttr));

class AlignValueAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlignValueAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlignValueAttr)
  ::pasta::Expr Alignment(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlignValueAttr)
};

static_assert(sizeof(Attr) == sizeof(AlignValueAttr));

class AlignedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlignedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlignedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AlignedAttr)
  uint32_t Alignment(void) const;
  std::optional<::pasta::Expr> AlignmentExpression(void) const;
  std::optional<::pasta::Type> AlignmentType(void) const;
  enum AlignedAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsAlignas(void) const;
  bool IsAlignmentDependent(void) const;
  bool IsAlignmentErrorDependent(void) const;
  bool IsAlignmentExpression(void) const;
  bool IsC11(void) const;
  bool IsDeclspec(void) const;
  bool IsGNU(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlignedAttr)
};

static_assert(sizeof(Attr) == sizeof(AlignedAttr));

class AllocAlignAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AllocAlignAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AllocAlignAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AllocAlignAttr)
  // ParameterIndex: (clang::ParamIdx)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AllocAlignAttr)
};

static_assert(sizeof(Attr) == sizeof(AllocAlignAttr));

class AllocSizeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AllocSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AllocSizeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AllocSizeAttr)
  // ElemSizeParameter: (clang::ParamIdx)
  // NumElemsParameter: (clang::ParamIdx)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AllocSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(AllocSizeAttr));

class AlwaysDestroyAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlwaysDestroyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlwaysDestroyAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AlwaysDestroyAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlwaysDestroyAttr)
};

static_assert(sizeof(Attr) == sizeof(AlwaysDestroyAttr));

class AnalyzerNoReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnalyzerNoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnalyzerNoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnalyzerNoReturnAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnalyzerNoReturnAttr)
};

static_assert(sizeof(Attr) == sizeof(AnalyzerNoReturnAttr));

class AnnotateAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnnotateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnnotateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnnotateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, AnnotateAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  // DelayedArguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Annotation(void) const;
  uint32_t AnnotationLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnnotateAttr)
};

static_assert(sizeof(Attr) == sizeof(AnnotateAttr));

class AnnotateTypeAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnnotateTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnnotateTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, AnnotateTypeAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  // DelayedArguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Annotation(void) const;
  uint32_t AnnotationLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnnotateTypeAttr)
};

static_assert(sizeof(Attr) == sizeof(AnnotateTypeAttr));

class AnyX86InterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnyX86InterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnyX86InterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnyX86InterruptAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnyX86InterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(AnyX86InterruptAttr));

class AnyX86NoCallerSavedRegistersAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnyX86NoCallerSavedRegistersAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnyX86NoCallerSavedRegistersAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnyX86NoCallerSavedRegistersAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnyX86NoCallerSavedRegistersAttr)
};

static_assert(sizeof(Attr) == sizeof(AnyX86NoCallerSavedRegistersAttr));

class AnyX86NoCfCheckAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnyX86NoCfCheckAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnyX86NoCfCheckAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnyX86NoCfCheckAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnyX86NoCfCheckAttr)
};

static_assert(sizeof(Attr) == sizeof(AnyX86NoCfCheckAttr));

class ArcWeakrefUnavailableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArcWeakrefUnavailableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ArcWeakrefUnavailableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ArcWeakrefUnavailableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ArcWeakrefUnavailableAttr)
};

static_assert(sizeof(Attr) == sizeof(ArcWeakrefUnavailableAttr));

class ArgumentWithTypeTagAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArgumentWithTypeTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ArgumentWithTypeTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ArgumentWithTypeTagAttr)
  // ArgumentIndex: (clang::ParamIdx)
  // ArgumentKind: (clang::IdentifierInfo *)
  bool IsPointer(void) const;
  enum ArgumentWithTypeTagAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  // TypeTagIndex: (clang::ParamIdx)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ArgumentWithTypeTagAttr)
};

static_assert(sizeof(Attr) == sizeof(ArgumentWithTypeTagAttr));

class ArmBuiltinAliasAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArmBuiltinAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ArmBuiltinAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ArmBuiltinAliasAttr)
  // BuiltinName: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ArmBuiltinAliasAttr)
};

static_assert(sizeof(Attr) == sizeof(ArmBuiltinAliasAttr));

class ArmMveStrictPolymorphismAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArmMveStrictPolymorphismAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ArmMveStrictPolymorphismAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ArmMveStrictPolymorphismAttr)
};

static_assert(sizeof(Attr) == sizeof(ArmMveStrictPolymorphismAttr));

class ArtificialAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArtificialAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ArtificialAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ArtificialAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ArtificialAttr)
};

static_assert(sizeof(Attr) == sizeof(ArtificialAttr));

class AsmLabelAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AsmLabelAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AsmLabelAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AsmLabelAttr)
  bool IsLiteralLabel(void) const;
  std::string_view Label(void) const;
  uint32_t LabelLength(void) const;
  std::string_view Spelling(void) const;
  // IsEquivalent: (bool)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AsmLabelAttr)
};

static_assert(sizeof(Attr) == sizeof(AsmLabelAttr));

class AssertCapabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AssertCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AssertCapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AssertCapabilityAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  enum AssertCapabilityAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsShared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AssertCapabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(AssertCapabilityAttr));

class AssertExclusiveLockAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AssertExclusiveLockAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AssertExclusiveLockAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AssertExclusiveLockAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AssertExclusiveLockAttr)
};

static_assert(sizeof(Attr) == sizeof(AssertExclusiveLockAttr));

class AssertSharedLockAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AssertSharedLockAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AssertSharedLockAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AssertSharedLockAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AssertSharedLockAttr)
};

static_assert(sizeof(Attr) == sizeof(AssertSharedLockAttr));

class AssumeAlignedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AssumeAlignedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AssumeAlignedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AssumeAlignedAttr)
  ::pasta::Expr Alignment(void) const;
  std::optional<::pasta::Expr> Offset(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AssumeAlignedAttr)
};

static_assert(sizeof(Attr) == sizeof(AssumeAlignedAttr));

class AssumptionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AssumptionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AssumptionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AssumptionAttr)
  std::string_view Assumption(void) const;
  uint32_t AssumptionLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AssumptionAttr)
};

static_assert(sizeof(Attr) == sizeof(AssumptionAttr));

class AvailabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AvailabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AvailabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AvailabilityAttr)
  // Deprecated: (llvm::VersionTuple)
  // Introduced: (llvm::VersionTuple)
  std::string_view Message(void) const;
  uint32_t MessageLength(void) const;
  // Obsoleted: (llvm::VersionTuple)
  // Platform: (clang::IdentifierInfo *)
  // Priority: (int)
  std::string_view Replacement(void) const;
  uint32_t ReplacementLength(void) const;
  std::string_view Spelling(void) const;
  bool Strict(void) const;
  bool Unavailable(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AvailabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(AvailabilityAttr));

class BPFPreserveAccessIndexAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BPFPreserveAccessIndexAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BPFPreserveAccessIndexAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, BPFPreserveAccessIndexAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(BPFPreserveAccessIndexAttr)
};

static_assert(sizeof(Attr) == sizeof(BPFPreserveAccessIndexAttr));

class BTFDeclTagAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BTFDeclTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BTFDeclTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, BTFDeclTagAttr)
  std::string_view BTFDeclTag(void) const;
  uint32_t BTFDeclTagLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(BTFDeclTagAttr)
};

static_assert(sizeof(Attr) == sizeof(BTFDeclTagAttr));

class BTFTypeTagAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BTFTypeTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BTFTypeTagAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, BTFTypeTagAttr)
  std::string_view BTFTypeTag(void) const;
  uint32_t BTFTypeTagLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(BTFTypeTagAttr)
};

static_assert(sizeof(Attr) == sizeof(BTFTypeTagAttr));

class BlocksAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BlocksAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BlocksAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, BlocksAttr)
  std::string_view Spelling(void) const;
  enum BlocksAttrBlockType Type(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(BlocksAttr)
};

static_assert(sizeof(Attr) == sizeof(BlocksAttr));

class BuiltinAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BuiltinAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, BuiltinAttr)
  uint32_t ID(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(BuiltinAttr)
};

static_assert(sizeof(Attr) == sizeof(BuiltinAttr));

class C11NoReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(C11NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, C11NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, C11NoReturnAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(C11NoReturnAttr)
};

static_assert(sizeof(Attr) == sizeof(C11NoReturnAttr));

class CDeclAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CDeclAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CDeclAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CDeclAttr)
};

static_assert(sizeof(Attr) == sizeof(CDeclAttr));

class CFAuditedTransferAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFAuditedTransferAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFAuditedTransferAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFAuditedTransferAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFAuditedTransferAttr)
};

static_assert(sizeof(Attr) == sizeof(CFAuditedTransferAttr));

class CFConsumedAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFConsumedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, CFConsumedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFConsumedAttr)
};

static_assert(sizeof(Attr) == sizeof(CFConsumedAttr));

class CFGuardAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFGuardAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFGuardAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFGuardAttr)
  enum CFGuardAttrGuardArg Guard(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFGuardAttr)
};

static_assert(sizeof(Attr) == sizeof(CFGuardAttr));

class CFICanonicalJumpTableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFICanonicalJumpTableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFICanonicalJumpTableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFICanonicalJumpTableAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFICanonicalJumpTableAttr)
};

static_assert(sizeof(Attr) == sizeof(CFICanonicalJumpTableAttr));

class CFReturnsNotRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFReturnsNotRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFReturnsNotRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFReturnsNotRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFReturnsNotRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(CFReturnsNotRetainedAttr));

class CFReturnsRetainedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFReturnsRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFReturnsRetainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFReturnsRetainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFReturnsRetainedAttr)
};

static_assert(sizeof(Attr) == sizeof(CFReturnsRetainedAttr));

class CFUnknownTransferAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CFUnknownTransferAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CFUnknownTransferAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CFUnknownTransferAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CFUnknownTransferAttr)
};

static_assert(sizeof(Attr) == sizeof(CFUnknownTransferAttr));

class CPUDispatchAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CPUDispatchAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CPUDispatchAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CPUDispatchAttr)
  // Cpus: (llvm::iterator_range<clang::IdentifierInfo **>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CPUDispatchAttr)
};

static_assert(sizeof(Attr) == sizeof(CPUDispatchAttr));

class CPUSpecificAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CPUSpecificAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CPUSpecificAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CPUSpecificAttr)
  // Cpus: (llvm::iterator_range<clang::IdentifierInfo **>)
  // CPUName: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CPUSpecificAttr)
};

static_assert(sizeof(Attr) == sizeof(CPUSpecificAttr));

class CUDAConstantAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDAConstantAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDAConstantAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDAConstantAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDAConstantAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDAConstantAttr));

class CUDADeviceAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDADeviceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDADeviceAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDADeviceAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDADeviceAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDADeviceAttr));

class CUDADeviceBuiltinSurfaceTypeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDADeviceBuiltinSurfaceTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDADeviceBuiltinSurfaceTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDADeviceBuiltinSurfaceTypeAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDADeviceBuiltinSurfaceTypeAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDADeviceBuiltinSurfaceTypeAttr));

class CUDADeviceBuiltinTextureTypeAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDADeviceBuiltinTextureTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDADeviceBuiltinTextureTypeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDADeviceBuiltinTextureTypeAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDADeviceBuiltinTextureTypeAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDADeviceBuiltinTextureTypeAttr));

class CUDAGlobalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDAGlobalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDAGlobalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDAGlobalAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDAGlobalAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDAGlobalAttr));

class CUDAHostAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDAHostAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDAHostAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDAHostAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDAHostAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDAHostAttr));

class CUDAInvalidTargetAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDAInvalidTargetAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDAInvalidTargetAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDAInvalidTargetAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDAInvalidTargetAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDAInvalidTargetAttr));

class CUDALaunchBoundsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDALaunchBoundsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDALaunchBoundsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDALaunchBoundsAttr)
  ::pasta::Expr MaxThreads(void) const;
  ::pasta::Expr MinBlocks(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDALaunchBoundsAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDALaunchBoundsAttr));

class CUDASharedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDASharedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CUDASharedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CUDASharedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CUDASharedAttr)
};

static_assert(sizeof(Attr) == sizeof(CUDASharedAttr));

class CXX11NoReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXX11NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CXX11NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CXX11NoReturnAttr)
  enum CXX11NoReturnAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CXX11NoReturnAttr)
};

static_assert(sizeof(Attr) == sizeof(CXX11NoReturnAttr));

class CallableWhenAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CallableWhenAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CallableWhenAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CallableWhenAttr)
  // CallableStates: (llvm::iterator_range<clang::CallableWhenAttr::ConsumedState *>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CallableWhenAttr)
};

static_assert(sizeof(Attr) == sizeof(CallableWhenAttr));

class CallbackAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CallbackAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CallbackAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CallbackAttr)
  // Encoding: (llvm::iterator_range<int *>)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CallbackAttr)
};

static_assert(sizeof(Attr) == sizeof(CallbackAttr));

class CapabilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CapabilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CapabilityAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  enum CapabilityAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsShared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CapabilityAttr)
};

static_assert(sizeof(Attr) == sizeof(CapabilityAttr));

class CapturedRecordAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CapturedRecordAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CapturedRecordAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CapturedRecordAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CapturedRecordAttr)
};

static_assert(sizeof(Attr) == sizeof(CapturedRecordAttr));

class CarriesDependencyAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CarriesDependencyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CarriesDependencyAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CarriesDependencyAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, CarriesDependencyAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CarriesDependencyAttr)
};

static_assert(sizeof(Attr) == sizeof(CarriesDependencyAttr));

class CleanupAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CleanupAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CleanupAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CleanupAttr)
  ::pasta::FunctionDecl FunctionDeclaration(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CleanupAttr)
};

static_assert(sizeof(Attr) == sizeof(CleanupAttr));

class CmseNSCallAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CmseNSCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CmseNSCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, CmseNSCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CmseNSCallAttr)
};

static_assert(sizeof(Attr) == sizeof(CmseNSCallAttr));

class CmseNSEntryAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CmseNSEntryAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CmseNSEntryAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CmseNSEntryAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CmseNSEntryAttr)
};

static_assert(sizeof(Attr) == sizeof(CmseNSEntryAttr));

class CodeSegAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CodeSegAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CodeSegAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CodeSegAttr)
  std::string_view Name(void) const;
  uint32_t NameLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CodeSegAttr)
};

static_assert(sizeof(Attr) == sizeof(CodeSegAttr));

class ColdAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ColdAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ColdAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ColdAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ColdAttr)
};

static_assert(sizeof(Attr) == sizeof(ColdAttr));

class CommonAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CommonAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, CommonAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, CommonAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(CommonAttr)
};

static_assert(sizeof(Attr) == sizeof(CommonAttr));

class ConstAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConstAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConstAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConstAttr)
};

static_assert(sizeof(Attr) == sizeof(ConstAttr));

class ConstInitAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstInitAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConstInitAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConstInitAttr)
  enum ConstInitAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsConstinit(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConstInitAttr)
};

static_assert(sizeof(Attr) == sizeof(ConstInitAttr));

class ConstructorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstructorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConstructorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConstructorAttr)
  // Priority: (int)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConstructorAttr)
};

static_assert(sizeof(Attr) == sizeof(ConstructorAttr));

class ConsumableAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConsumableAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConsumableAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConsumableAttr)
  enum ConsumableAttrConsumedState DefaultState(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConsumableAttr)
};

static_assert(sizeof(Attr) == sizeof(ConsumableAttr));

class ConsumableAutoCastAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConsumableAutoCastAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConsumableAutoCastAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConsumableAutoCastAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConsumableAutoCastAttr)
};

static_assert(sizeof(Attr) == sizeof(ConsumableAutoCastAttr));

class ConsumableSetOnReadAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConsumableSetOnReadAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConsumableSetOnReadAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConsumableSetOnReadAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConsumableSetOnReadAttr)
};

static_assert(sizeof(Attr) == sizeof(ConsumableSetOnReadAttr));

class ConvergentAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConvergentAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ConvergentAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ConvergentAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ConvergentAttr)
};

static_assert(sizeof(Attr) == sizeof(ConvergentAttr));

class DLLExportAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DLLExportAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DLLExportAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DLLExportAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DLLExportAttr)
};

static_assert(sizeof(Attr) == sizeof(DLLExportAttr));

class DLLExportStaticLocalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DLLExportStaticLocalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DLLExportStaticLocalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DLLExportStaticLocalAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DLLExportStaticLocalAttr)
};

static_assert(sizeof(Attr) == sizeof(DLLExportStaticLocalAttr));

class DLLImportAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DLLImportAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DLLImportAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DLLImportAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DLLImportAttr)
};

static_assert(sizeof(Attr) == sizeof(DLLImportAttr));

class DLLImportStaticLocalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DLLImportStaticLocalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DLLImportStaticLocalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DLLImportStaticLocalAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DLLImportStaticLocalAttr)
};

static_assert(sizeof(Attr) == sizeof(DLLImportStaticLocalAttr));

class DeclOrStmtAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclOrStmtAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DeclOrStmtAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DeclOrStmtAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclOrStmtAttr, AlwaysInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclOrStmtAttr, NoInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DeclOrStmtAttr)
};

static_assert(sizeof(Attr) == sizeof(DeclOrStmtAttr));

class DeprecatedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeprecatedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DeprecatedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DeprecatedAttr)
  std::string_view Message(void) const;
  uint32_t MessageLength(void) const;
  std::string_view Replacement(void) const;
  uint32_t ReplacementLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DeprecatedAttr)
};

static_assert(sizeof(Attr) == sizeof(DeprecatedAttr));

class DestructorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DestructorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DestructorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DestructorAttr)
  // Priority: (int)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DestructorAttr)
};

static_assert(sizeof(Attr) == sizeof(DestructorAttr));

class DiagnoseAsBuiltinAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DiagnoseAsBuiltinAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DiagnoseAsBuiltinAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DiagnoseAsBuiltinAttr)
  // ArgumentIndices: (llvm::iterator_range<unsigned int *>)
  ::pasta::FunctionDecl Function(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DiagnoseAsBuiltinAttr)
};

static_assert(sizeof(Attr) == sizeof(DiagnoseAsBuiltinAttr));

class DiagnoseIfAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DiagnoseIfAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DiagnoseIfAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DiagnoseIfAttr)
  bool ArgumentDependent(void) const;
  ::pasta::Expr Condition(void) const;
  enum DiagnoseIfAttrDiagnosticType DiagnosticType(void) const;
  std::string_view Message(void) const;
  uint32_t MessageLength(void) const;
  ::pasta::NamedDecl Parent(void) const;
  std::string_view Spelling(void) const;
  bool IsError(void) const;
  bool IsWarning(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DiagnoseIfAttr)
};

static_assert(sizeof(Attr) == sizeof(DiagnoseIfAttr));

class DisableSanitizerInstrumentationAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DisableSanitizerInstrumentationAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DisableSanitizerInstrumentationAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DisableSanitizerInstrumentationAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DisableSanitizerInstrumentationAttr)
};

static_assert(sizeof(Attr) == sizeof(DisableSanitizerInstrumentationAttr));

class DisableTailCallsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DisableTailCallsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, DisableTailCallsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, DisableTailCallsAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(DisableTailCallsAttr)
};

static_assert(sizeof(Attr) == sizeof(DisableTailCallsAttr));

class EmptyBasesAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EmptyBasesAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, EmptyBasesAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, EmptyBasesAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(EmptyBasesAttr)
};

static_assert(sizeof(Attr) == sizeof(EmptyBasesAttr));

class EnableIfAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnableIfAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, EnableIfAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, EnableIfAttr)
  ::pasta::Expr Condition(void) const;
  std::string_view Message(void) const;
  uint32_t MessageLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(EnableIfAttr)
};

static_assert(sizeof(Attr) == sizeof(EnableIfAttr));

class EnforceTCBAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnforceTCBAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, EnforceTCBAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, EnforceTCBAttr)
  std::string_view Spelling(void) const;
  std::string_view TCBName(void) const;
  uint32_t TCBNameLength(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(EnforceTCBAttr)
};

static_assert(sizeof(Attr) == sizeof(EnforceTCBAttr));

class EnforceTCBLeafAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnforceTCBLeafAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, EnforceTCBLeafAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, EnforceTCBLeafAttr)
  std::string_view Spelling(void) const;
  std::string_view TCBName(void) const;
  uint32_t TCBNameLength(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(EnforceTCBLeafAttr)
};

static_assert(sizeof(Attr) == sizeof(EnforceTCBLeafAttr));

class EnumExtensibilityAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnumExtensibilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, EnumExtensibilityAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, EnumExtensibilityAttr)
  enum EnumExtensibilityAttrKind Extensibility(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(EnumExtensibilityAttr)
};

static_assert(sizeof(Attr) == sizeof(EnumExtensibilityAttr));

class ErrorAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ErrorAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ErrorAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ErrorAttr)
  enum ErrorAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  std::string_view UserDiagnostic(void) const;
  uint32_t UserDiagnosticLength(void) const;
  bool IsError(void) const;
  bool IsWarning(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ErrorAttr)
};

static_assert(sizeof(Attr) == sizeof(ErrorAttr));

class ExcludeFromExplicitInstantiationAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExcludeFromExplicitInstantiationAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ExcludeFromExplicitInstantiationAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ExcludeFromExplicitInstantiationAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ExcludeFromExplicitInstantiationAttr)
};

static_assert(sizeof(Attr) == sizeof(ExcludeFromExplicitInstantiationAttr));

class ExclusiveTrylockFunctionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExclusiveTrylockFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ExclusiveTrylockFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ExclusiveTrylockFunctionAttr)
  // Arguments: (llvm::iterator_range<clang::Expr **>)
  std::string_view Spelling(void) const;
  ::pasta::Expr SuccessValue(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ExclusiveTrylockFunctionAttr)
};

static_assert(sizeof(Attr) == sizeof(ExclusiveTrylockFunctionAttr));

class ExternalSourceSymbolAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExternalSourceSymbolAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ExternalSourceSymbolAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, ExternalSourceSymbolAttr)
  std::string_view DefinedIn(void) const;
  uint32_t DefinedInLength(void) const;
  bool GeneratedDeclaration(void) const;
  std::string_view Language(void) const;
  uint32_t LanguageLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ExternalSourceSymbolAttr)
};

static_assert(sizeof(Attr) == sizeof(ExternalSourceSymbolAttr));

class FallThroughAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FallThroughAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FallThroughAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, FallThroughAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FallThroughAttr)
};

static_assert(sizeof(Attr) == sizeof(FallThroughAttr));

class FastCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FastCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FastCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FastCallAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FastCallAttr)
};

static_assert(sizeof(Attr) == sizeof(FastCallAttr));

class FinalAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FinalAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FinalAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FinalAttr)
  enum FinalAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsSpelledAsSealed(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FinalAttr)
};

static_assert(sizeof(Attr) == sizeof(FinalAttr));

class FlagEnumAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FlagEnumAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FlagEnumAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FlagEnumAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FlagEnumAttr)
};

static_assert(sizeof(Attr) == sizeof(FlagEnumAttr));

class FlattenAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FlattenAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FlattenAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FlattenAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FlattenAttr)
};

static_assert(sizeof(Attr) == sizeof(FlattenAttr));

class FormatArgAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FormatArgAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FormatArgAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FormatArgAttr)
  // FormatIndex: (clang::ParamIdx)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FormatArgAttr)
};

static_assert(sizeof(Attr) == sizeof(FormatArgAttr));

class FormatAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FormatAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FormatAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FormatAttr)
  // FirstArgument: (int)
  // FormatIndex: (int)
  std::string_view Spelling(void) const;
  // Type: (clang::IdentifierInfo *)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FormatAttr)
};

static_assert(sizeof(Attr) == sizeof(FormatAttr));

class FunctionReturnThunksAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionReturnThunksAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, FunctionReturnThunksAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, FunctionReturnThunksAttr)
  std::string_view Spelling(void) const;
  enum FunctionReturnThunksAttrKind ThunkType(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FunctionReturnThunksAttr)
};

static_assert(sizeof(Attr) == sizeof(FunctionReturnThunksAttr));

class GNUInlineAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GNUInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, GNUInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, GNUInlineAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(GNUInlineAttr)
};

static_assert(sizeof(Attr) == sizeof(GNUInlineAttr));

class GuardedByAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GuardedByAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, GuardedByAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, GuardedByAttr)
  ::pasta::Expr Argument(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(GuardedByAttr)
};

static_assert(sizeof(Attr) == sizeof(GuardedByAttr));

class GuardedVarAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GuardedVarAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, GuardedVarAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, GuardedVarAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(GuardedVarAttr)
};

static_assert(sizeof(Attr) == sizeof(GuardedVarAttr));

class HIPManagedAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HIPManagedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HIPManagedAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HIPManagedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HIPManagedAttr)
};

static_assert(sizeof(Attr) == sizeof(HIPManagedAttr));

class HLSLAnnotationAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLAnnotationAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLAnnotationAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLAnnotationAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(HLSLAnnotationAttr, HLSLSV_DispatchThreadIDAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(HLSLAnnotationAttr, HLSLSV_GroupIndexAttr)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLAnnotationAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLAnnotationAttr));

class HLSLGroupSharedAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLGroupSharedAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLGroupSharedAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, HLSLGroupSharedAddressSpaceAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLGroupSharedAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLGroupSharedAddressSpaceAttr));

class HLSLNumThreadsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLNumThreadsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLNumThreadsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLNumThreadsAttr)
  std::string_view Spelling(void) const;
  // X: (int)
  // Y: (int)
  // Z: (int)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLNumThreadsAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLNumThreadsAttr));

class HLSLResourceAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLResourceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLResourceAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLResourceAttr)
  enum HLSLResourceAttrResourceKind ResourceShape(void) const;
  enum HLSLResourceAttrResourceClass ResourceType(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLResourceAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLResourceAttr));

class HLSLResourceBindingAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLResourceBindingAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLResourceBindingAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLResourceBindingAttr)
  std::string_view Slot(void) const;
  uint32_t SlotLength(void) const;
  std::string_view Space(void) const;
  uint32_t SpaceLength(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLResourceBindingAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLResourceBindingAttr));

class HLSLSV_DispatchThreadIDAttr : public HLSLAnnotationAttr {
 private:
  using HLSLAnnotationAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLSV_DispatchThreadIDAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLSV_DispatchThreadIDAttr)
  PASTA_DECLARE_BASE_OPERATORS(HLSLAnnotationAttr, HLSLSV_DispatchThreadIDAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLSV_DispatchThreadIDAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLSV_DispatchThreadIDAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLSV_DispatchThreadIDAttr));

class HLSLSV_GroupIndexAttr : public HLSLAnnotationAttr {
 private:
  using HLSLAnnotationAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLSV_GroupIndexAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLSV_GroupIndexAttr)
  PASTA_DECLARE_BASE_OPERATORS(HLSLAnnotationAttr, HLSLSV_GroupIndexAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLSV_GroupIndexAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLSV_GroupIndexAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLSV_GroupIndexAttr));

class HLSLShaderAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLShaderAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HLSLShaderAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HLSLShaderAttr)
  std::string_view Spelling(void) const;
  enum HLSLShaderAttrShaderType Type(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HLSLShaderAttr)
};

static_assert(sizeof(Attr) == sizeof(HLSLShaderAttr));

class HotAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HotAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HotAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HotAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HotAttr)
};

static_assert(sizeof(Attr) == sizeof(HotAttr));

class IBActionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IBActionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, IBActionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, IBActionAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(IBActionAttr)
};

static_assert(sizeof(Attr) == sizeof(IBActionAttr));

class IBOutletAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IBOutletAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, IBOutletAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, IBOutletAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(IBOutletAttr)
};

static_assert(sizeof(Attr) == sizeof(IBOutletAttr));

class IBOutletCollectionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IBOutletCollectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, IBOutletCollectionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, IBOutletCollectionAttr)
  ::pasta::Type Interface(void) const;
  ::pasta::Type InterfaceToken(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(IBOutletCollectionAttr)
};

static_assert(sizeof(Attr) == sizeof(IBOutletCollectionAttr));

class LikelyAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LikelyAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, LikelyAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, LikelyAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(LikelyAttr)
};

static_assert(sizeof(Attr) == sizeof(LikelyAttr));

class MustTailAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MustTailAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MustTailAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, MustTailAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MustTailAttr)
};

static_assert(sizeof(Attr) == sizeof(MustTailAttr));

class NoDerefAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoDerefAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoDerefAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, NoDerefAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoDerefAttr)
};

static_assert(sizeof(Attr) == sizeof(NoDerefAttr));

class NoInlineAttr : public DeclOrStmtAttr {
 private:
  using DeclOrStmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(DeclOrStmtAttr, NoInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoInlineAttr)
  std::string_view Spelling(void) const;
  bool IsClangNoInline(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoInlineAttr)
};

static_assert(sizeof(Attr) == sizeof(NoInlineAttr));

class NoMergeAttr : public DeclOrStmtAttr {
 private:
  using DeclOrStmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoMergeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoMergeAttr)
  PASTA_DECLARE_BASE_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoMergeAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoMergeAttr)
};

static_assert(sizeof(Attr) == sizeof(NoMergeAttr));

class ObjCGCAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCGCAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCGCAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, ObjCGCAttr)
  // Kind: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCGCAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCGCAttr));

class ObjCInertUnsafeUnretainedAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCInertUnsafeUnretainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCInertUnsafeUnretainedAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, ObjCInertUnsafeUnretainedAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCInertUnsafeUnretainedAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCInertUnsafeUnretainedAttr));

class ObjCKindOfAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCKindOfAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, ObjCKindOfAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, ObjCKindOfAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(ObjCKindOfAttr)
};

static_assert(sizeof(Attr) == sizeof(ObjCKindOfAttr));

class OpenCLConstantAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLConstantAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLConstantAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLConstantAddressSpaceAttr)
  enum OpenCLConstantAddressSpaceAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLConstantAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLConstantAddressSpaceAttr));

class OpenCLGenericAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLGenericAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLGenericAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLGenericAddressSpaceAttr)
  enum OpenCLGenericAddressSpaceAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLGenericAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLGenericAddressSpaceAttr));

class OpenCLGlobalAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLGlobalAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLGlobalAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLGlobalAddressSpaceAttr)
  enum OpenCLGlobalAddressSpaceAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLGlobalAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLGlobalAddressSpaceAttr));

class OpenCLGlobalDeviceAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLGlobalDeviceAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLGlobalDeviceAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLGlobalDeviceAddressSpaceAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLGlobalDeviceAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLGlobalDeviceAddressSpaceAttr));

class OpenCLGlobalHostAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLGlobalHostAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLGlobalHostAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLGlobalHostAddressSpaceAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLGlobalHostAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLGlobalHostAddressSpaceAttr));

class OpenCLLocalAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLLocalAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLLocalAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLLocalAddressSpaceAttr)
  enum OpenCLLocalAddressSpaceAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLLocalAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLLocalAddressSpaceAttr));

class OpenCLPrivateAddressSpaceAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLPrivateAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLPrivateAddressSpaceAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, OpenCLPrivateAddressSpaceAttr)
  enum OpenCLPrivateAddressSpaceAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLPrivateAddressSpaceAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLPrivateAddressSpaceAttr));

class OpenCLUnrollHintAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpenCLUnrollHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, OpenCLUnrollHintAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, OpenCLUnrollHintAttr)
  std::string_view Spelling(void) const;
  uint32_t UnrollHint(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(OpenCLUnrollHintAttr)
};

static_assert(sizeof(Attr) == sizeof(OpenCLUnrollHintAttr));

class Ptr32Attr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Ptr32Attr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, Ptr32Attr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, Ptr32Attr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(Ptr32Attr)
};

static_assert(sizeof(Attr) == sizeof(Ptr32Attr));

class Ptr64Attr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Ptr64Attr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, Ptr64Attr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, Ptr64Attr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(Ptr64Attr)
};

static_assert(sizeof(Attr) == sizeof(Ptr64Attr));

class SPtrAttr : public TypeAttr {
 private:
  using TypeAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SPtrAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SPtrAttr)
  PASTA_DECLARE_BASE_OPERATORS(TypeAttr, SPtrAttr)
  std::string_view Spelling(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SPtrAttr)
};

static_assert(sizeof(Attr) == sizeof(SPtrAttr));

class AlwaysInlineAttr : public DeclOrStmtAttr {
 private:
  using DeclOrStmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlwaysInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlwaysInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(DeclOrStmtAttr, AlwaysInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AlwaysInlineAttr)
  enum AlwaysInlineAttrSpelling SemanticSpelling(void) const;
  std::string_view Spelling(void) const;
  bool IsClangAlwaysInline(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlwaysInlineAttr)
};

static_assert(sizeof(Attr) == sizeof(AlwaysInlineAttr));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR
#endif  // PASTA_IN_BOOTSTRAP
