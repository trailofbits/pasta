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
#include "Forward.h"

#define PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(base) \
    friend class AST; \
    friend class ASTImpl; \
    friend class AttrBuilder; \
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

class Attr {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Attr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AArch64VectorPcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, GNUInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, GuardedByAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, GuardedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, HIPManagedAttr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoSanitizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoSpeculativeLoadHardeningAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoSplitStackAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoStackProtectorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoThrowAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(Attr, NoUniqueAddressAttr)
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
  // Clone: (clang::Attr *)
  ::pasta::AttrKind Kind(void) const noexcept;
  ::pasta::Token Token(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  uint32_t SpellingListIndex(void) const noexcept;
  bool IsImplicit(void) const noexcept;
  bool IsInherited(void) const noexcept;
  bool IsLateParsed(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
  std::string_view KindName(void) const noexcept;

  ::pasta::TokenRange Tokens(void) const noexcept;

  inline bool operator==(const Attr &that) const noexcept {
    return u.opaque == that.u.opaque;
  }
  static std::optional<::pasta::Attr> From(const TokenContext &);

  inline Attr(std::shared_ptr<ASTImpl> ast_, const clang::Attr *Attr_)
      : ast(std::move(ast_)) {
    assert(ast.get() != nullptr);
    u.Attr = Attr_;
  }

 protected:
  friend class TokenContext;

  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::AArch64VectorPcsAttr *AArch64VectorPcsAttr;
    const ::clang::AMDGPUFlatWorkGroupSizeAttr *AMDGPUFlatWorkGroupSizeAttr;
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
    const ::clang::GNUInlineAttr *GNUInlineAttr;
    const ::clang::GuardedByAttr *GuardedByAttr;
    const ::clang::GuardedVarAttr *GuardedVarAttr;
    const ::clang::HIPManagedAttr *HIPManagedAttr;
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
    const ::clang::NoReturnAttr *NoReturnAttr;
    const ::clang::NoSanitizeAttr *NoSanitizeAttr;
    const ::clang::NoSpeculativeLoadHardeningAttr *NoSpeculativeLoadHardeningAttr;
    const ::clang::NoSplitStackAttr *NoSplitStackAttr;
    const ::clang::NoStackProtectorAttr *NoStackProtectorAttr;
    const ::clang::NoThreadSafetyAnalysisAttr *NoThreadSafetyAnalysisAttr;
    const ::clang::NoThrowAttr *NoThrowAttr;
    const ::clang::NoUniqueAddressAttr *NoUniqueAddressAttr;
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
    const void *opaque;
  } u;
};

class BuiltinAliasAttr : public Attr {
 private:
  using Attr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinAliasAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, BuiltinAliasAttr)
  // Clone: (clang::BuiltinAliasAttr *)
  // BuiltinName: (clang::IdentifierInfo *)
  enum BuiltinAliasAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CalledOnceAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::IFuncAttr *)
  std::string_view Resolver(void) const noexcept;
  uint32_t ResolverLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, GNUInlineAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, GuardedByAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, GuardedVarAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, HIPManagedAttr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoReturnAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoSanitizeAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoSpeculativeLoadHardeningAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoSplitStackAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoStackProtectorAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoThrowAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
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
  bool ShouldInheritEvenIfAlreadyPresent(void) const noexcept;
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
  // Clone: (clang::InitPriorityAttr *)
  uint32_t Priority(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::InitSegAttr *)
  std::string_view Section(void) const noexcept;
  uint32_t SectionLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::IntelOclBiccAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::InternalLinkageAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LTOVisibilityPublicAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LayoutVersionAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t Version(void) const noexcept;
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
  // Clone: (clang::LeafAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LifetimeBoundAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LoaderUninitializedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LockReturnedAttr *)
  ::pasta::Expr Argument(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LocksExcludedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LoopHintAttr *)
  // DiagnosticName: (std::string)
  enum LoopHintAttrOptionType Option(void) const noexcept;
  enum LoopHintAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  enum LoopHintAttrLoopHintState State(void) const noexcept;
  ::pasta::Expr Value(void) const noexcept;
  // ValueString: (std::string)
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
  // Clone: (clang::M68kInterruptAttr *)
  uint32_t Number(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MIGServerRoutineAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSABIAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSAllocatorAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSInheritanceAttr *)
  bool BestCase(void) const noexcept;
  enum MSInheritanceModel InheritanceModel(void) const noexcept;
  enum MSInheritanceAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSNoVTableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSP430InterruptAttr *)
  uint32_t Number(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSStructAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MSVtorDispAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t Vdm(void) const noexcept;
  enum MSVtorDispMode VtorDispMode(void) const noexcept;
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
  // Clone: (clang::MaxFieldAlignmentAttr *)
  uint32_t Alignment(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MayAliasAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(MayAliasAttr)
};

static_assert(sizeof(Attr) == sizeof(MayAliasAttr));

class MicroMipsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MicroMipsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, MicroMipsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, MicroMipsAttr)
  // Clone: (clang::MicroMipsAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MinSizeAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MinVectorWidthAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t VectorWidth(void) const noexcept;
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
  // Clone: (clang::Mips16Attr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MipsInterruptAttr *)
  enum MipsInterruptAttrInterruptType Interrupt(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MipsLongCallAttr *)
  enum MipsLongCallAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MipsShortCallAttr *)
  enum MipsShortCallAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ModeAttr *)
  // Mode: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NSConsumedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NSConsumesSelfAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NSErrorDomainAttr *)
  ::pasta::VarDecl ErrorDomain(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NSReturnsAutoreleasedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NSReturnsNotRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NSReturnsRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NakedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoAliasAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoBuiltinAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoCommonAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoDebugAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoDestroyAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoDuplicateAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoEscapeAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoEscapeAttr)
};

static_assert(sizeof(Attr) == sizeof(NoEscapeAttr));

class NoInlineAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoInlineAttr)
  // Clone: (clang::NoInlineAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoInlineAttr)
};

static_assert(sizeof(Attr) == sizeof(NoInlineAttr));

class NoInstrumentFunctionAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoInstrumentFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoInstrumentFunctionAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoInstrumentFunctionAttr)
  // Clone: (clang::NoInstrumentFunctionAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoMicroMipsAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoMips16Attr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoProfileFunctionAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoProfileFunctionAttr)
};

static_assert(sizeof(Attr) == sizeof(NoProfileFunctionAttr));

class NoReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoReturnAttr)
  // Clone: (clang::NoReturnAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoSanitizeAttr *)
  // Mask: (clang::SanitizerMask)
  std::string_view Spelling(void) const noexcept;
  bool HasCoverage(void) const noexcept;
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
  // Clone: (clang::NoSpeculativeLoadHardeningAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoSplitStackAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoStackProtectorAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoThreadSafetyAnalysisAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoThrowAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoUniqueAddressAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoUniqueAddressAttr)
};

static_assert(sizeof(Attr) == sizeof(NoUniqueAddressAttr));

class NonNullAttr : public InheritableParamAttr {
 private:
  using InheritableParamAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NonNullAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableParamAttr, NonNullAttr)
  // Arguments: (llvm::iterator_range<clang::ParamIdx *>)
  // Clone: (clang::NonNullAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NotTailCalledAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OMPAllocateDeclAttr *)
  ::pasta::Expr Alignment(void) const noexcept;
  ::pasta::Expr Allocator(void) const noexcept;
  enum OMPAllocateDeclAttrAllocatorTypeTy AllocatorType(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OMPCaptureKindAttr *)
  // CaptureKind: (llvm::omp::Clause)
  uint32_t CaptureKindValue(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OMPCaptureNoInitAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OMPDeclareSimdDeclAttr *)
  enum OMPDeclareSimdDeclAttrBranchStateTy BranchState(void) const noexcept;
  ::pasta::Expr Simdlen(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OMPDeclareTargetDeclAttr *)
  enum OMPDeclareTargetDeclAttrDevTypeTy DevType(void) const noexcept;
  bool Indirect(void) const noexcept;
  ::pasta::Expr IndirectExpression(void) const noexcept;
  uint32_t Level(void) const noexcept;
  enum OMPDeclareTargetDeclAttrMapTypeTy MapType(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // AppendArguments: (llvm::iterator_range<clang::OMPDeclareVariantAttr::InteropType *>)
  // Clone: (clang::OMPDeclareVariantAttr *)
  std::string_view Spelling(void) const noexcept;
  // TraitInfos: (clang::OMPTraitInfo *)
  ::pasta::Expr VariantFuncReference(void) const noexcept;
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
  // Clone: (clang::OMPReferencedVarAttr *)
  ::pasta::Expr Reference(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OMPThreadPrivateDeclAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OSConsumedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OSConsumesThisAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OSReturnsNotRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OSReturnsRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OSReturnsRetainedOnNonZeroAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OSReturnsRetainedOnZeroAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCBoxableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCBridgeAttr *)
  // BridgedType: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCBridgeMutableAttr *)
  // BridgedType: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCBridgeRelatedAttr *)
  // ClassMethod: (clang::IdentifierInfo *)
  // InstanceMethod: (clang::IdentifierInfo *)
  // RelatedClass: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCClassStubAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCDesignatedInitializerAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCDirectAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCDirectMembersAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCExceptionAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCExplicitProtocolImplAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCExternallyRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCIndependentClassAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCMethodFamilyAttr *)
  enum ObjCMethodFamilyAttrFamilyKind Family(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCNSObjectAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCNonLazyClassAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCNonRuntimeProtocolAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCOwnershipAttr *)
  // Kind: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCPreciseLifetimeAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCRequiresPropertyDefsAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCRequiresSuperAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCReturnsInnerPointerAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCRootClassAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCRuntimeNameAttr *)
  std::string_view MetadataName(void) const noexcept;
  uint32_t MetadataNameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCRuntimeVisibleAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCSubclassingRestrictedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLAccessAttr *)
  enum OpenCLAccessAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsReadOnly(void) const noexcept;
  bool IsReadWrite(void) const noexcept;
  bool IsWriteOnly(void) const noexcept;
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
  // Clone: (clang::OpenCLIntelReqdSubGroupSizeAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t SubGroupSize(void) const noexcept;
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
  // Clone: (clang::OpenCLKernelAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OptimizeNoneAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OverloadableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OverrideAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OwnerAttr *)
  ::pasta::Type DerefType(void) const noexcept;
  ::pasta::Type DerefTypeToken(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OwnershipAttr *)
  // Module: (clang::IdentifierInfo *)
  enum OwnershipAttrOwnershipKind OwnKind(void) const noexcept;
  enum OwnershipAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsHolds(void) const noexcept;
  bool IsReturns(void) const noexcept;
  bool IsTakes(void) const noexcept;
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
  // Clone: (clang::PackedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ParamTypestateAttr *)
  enum ParamTypestateAttrConsumedState ParameterState(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  enum ParameterABI ABI(void) const noexcept;
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
  // Clone: (clang::PascalAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PassObjectSizeAttr *)
  enum PassObjectSizeAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  // Type: (int)
  bool IsDynamic(void) const noexcept;
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
  // Clone: (clang::PatchableFunctionEntryAttr *)
  uint32_t Count(void) const noexcept;
  // Offset: (int)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PcsAttr *)
  enum PcsAttrPCSType PCS(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PointerAttr *)
  ::pasta::Type DerefType(void) const noexcept;
  ::pasta::Type DerefTypeToken(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PragmaClangBSSSectionAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PragmaClangDataSectionAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PragmaClangRelroSectionAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PragmaClangRodataSectionAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PragmaClangTextSectionAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PreferredNameAttr *)
  std::string_view Spelling(void) const noexcept;
  ::pasta::Type TypedefType(void) const noexcept;
  ::pasta::Type TypedefTypeToken(void) const noexcept;
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
  // Clone: (clang::PreserveAllAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PreserveMostAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PtGuardedByAttr *)
  ::pasta::Expr Argument(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PtGuardedVarAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::PureAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::RISCVInterruptAttr *)
  enum RISCVInterruptAttrInterruptType Interrupt(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(RISCVInterruptAttr)
};

static_assert(sizeof(Attr) == sizeof(RISCVInterruptAttr));

class RegCallAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RegCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, RegCallAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, RegCallAttr)
  // Clone: (clang::RegCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ReinitializesAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ReleaseCapabilityAttr *)
  enum ReleaseCapabilityAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsGeneric(void) const noexcept;
  bool IsShared(void) const noexcept;
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
  // Clone: (clang::ReleaseHandleAttr *)
  std::string_view HandleType(void) const noexcept;
  uint32_t HandleTypeLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::RenderScriptKernelAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ReqdWorkGroupSizeAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t XDim(void) const noexcept;
  uint32_t YDim(void) const noexcept;
  uint32_t ZDim(void) const noexcept;
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
  // Clone: (clang::RequiresCapabilityAttr *)
  enum RequiresCapabilityAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsShared(void) const noexcept;
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
  // Clone: (clang::RestrictAttr *)
  enum RestrictAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::RetainAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ReturnTypestateAttr *)
  std::string_view Spelling(void) const noexcept;
  enum ReturnTypestateAttrConsumedState State(void) const noexcept;
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
  // Clone: (clang::ReturnsNonNullAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ReturnsTwiceAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SYCLKernelAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SYCLSpecialClassAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ScopedLockableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SectionAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  enum SectionAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SelectAnyAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SentinelAttr *)
  // NullPos: (int)
  // Sentinel: (int)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SetTypestateAttr *)
  enum SetTypestateAttrConsumedState NewState(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SharedTrylockFunctionAttr *)
  std::string_view Spelling(void) const noexcept;
  ::pasta::Expr SuccessValue(void) const noexcept;
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
  // Clone: (clang::SpeculativeLoadHardeningAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::StandaloneDebugAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::StdCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::StrictFPAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(StrictFPAttr)
};

static_assert(sizeof(Attr) == sizeof(StrictFPAttr));

class SuppressAttr : public StmtAttr {
 private:
  using StmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SuppressAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, SuppressAttr)
  PASTA_DECLARE_BASE_OPERATORS(StmtAttr, SuppressAttr)
  // Clone: (clang::SuppressAttr *)
  // DiagnosticIdentifiers: (llvm::iterator_range<llvm::StringRef *>)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftAsyncAttr *)
  // CompletionHandlerIndex: (clang::ParamIdx)
  enum SwiftAsyncAttrKind Kind(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftAsyncCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftAsyncContextAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftAsyncErrorAttr *)
  enum SwiftAsyncErrorAttrConventionKind Convention(void) const noexcept;
  uint32_t HandlerParameterIndex(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftAsyncNameAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftAttrAttr *)
  std::string_view Attribute(void) const noexcept;
  uint32_t AttributeLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftBridgeAttr *)
  std::string_view Spelling(void) const noexcept;
  std::string_view SwiftType(void) const noexcept;
  uint32_t SwiftTypeLength(void) const noexcept;
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
  // Clone: (clang::SwiftBridgedTypedefAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftContextAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftErrorAttr *)
  enum SwiftErrorAttrConventionKind Convention(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftErrorResultAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftIndirectResultAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftNameAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftNewTypeAttr *)
  enum SwiftNewTypeAttrNewtypeKind NewtypeKind(void) const noexcept;
  enum SwiftNewTypeAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftObjCMembersAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SwiftPrivateAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SysVABIAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TLSModelAttr *)
  std::string_view Model(void) const noexcept;
  uint32_t ModelLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TargetAttr *)
  std::string_view Architecture(void) const noexcept;
  std::string_view FeaturesString(void) const noexcept;
  uint32_t FeaturesStringLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsDefaultVersion(void) const noexcept;
  // Parse: (clang::ParsedTargetAttr)
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
  // Clone: (clang::TargetClonesAttr *)
  // FeaturesStrings: (llvm::iterator_range<llvm::StringRef *>)
  // FeatureString: (llvm::StringRef)
  // MangledIndex: (unsigned int)
  std::string_view Spelling(void) const noexcept;
  // IsFirstOfVersion: (bool)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(TargetClonesAttr)
};

static_assert(sizeof(Attr) == sizeof(TargetClonesAttr));

class TestTypestateAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TestTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, TestTypestateAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, TestTypestateAttr)
  // Clone: (clang::TestTypestateAttr *)
  std::string_view Spelling(void) const noexcept;
  enum TestTypestateAttrConsumedState TestState(void) const noexcept;
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
  // Clone: (clang::ThisCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ThreadAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TransparentUnionAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TrivialABIAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TryAcquireCapabilityAttr *)
  enum TryAcquireCapabilityAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  ::pasta::Expr SuccessValue(void) const noexcept;
  bool IsShared(void) const noexcept;
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
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, BTFTypeTagAttr)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeAttr, CmseNSCallAttr)
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
  // Clone: (clang::TypeNonNullAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TypeNullUnspecifiedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TypeNullableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TypeNullableResultAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TypeTagForDatatypeAttr *)
  // ArgumentKind: (clang::IdentifierInfo *)
  bool LayoutCompatible(void) const noexcept;
  ::pasta::Type MatchingCType(void) const noexcept;
  ::pasta::Type MatchingCTypeToken(void) const noexcept;
  bool MustBeNull(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::TypeVisibilityAttr *)
  std::string_view Spelling(void) const noexcept;
  enum TypeVisibilityAttrVisibilityType Visibility(void) const noexcept;
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
  // Clone: (clang::UPtrAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UnavailableAttr *)
  enum UnavailableAttrImplicitReason ImplicitReason(void) const noexcept;
  std::string_view Message(void) const noexcept;
  uint32_t MessageLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UninitializedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UnlikelyAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UnusedAttr *)
  enum UnusedAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UseHandleAttr *)
  std::string_view HandleType(void) const noexcept;
  uint32_t HandleTypeLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UsedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UsingIfExistsAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::UuidAttr *)
  std::string_view Guid(void) const noexcept;
  ::pasta::MSGuidDecl GuidDeclaration(void) const noexcept;
  uint32_t GuidLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::VecReturnAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::VecTypeHintAttr *)
  std::string_view Spelling(void) const noexcept;
  ::pasta::Type TypeHint(void) const noexcept;
  ::pasta::Type TypeHintToken(void) const noexcept;
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
  // Clone: (clang::VectorCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::VisibilityAttr *)
  std::string_view Spelling(void) const noexcept;
  enum VisibilityAttrVisibilityType Visibility(void) const noexcept;
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
  // Clone: (clang::WarnUnusedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  bool IsCXX11NoDiscard(void) const noexcept;
  // Clone: (clang::WarnUnusedResultAttr *)
  std::string_view Message(void) const noexcept;
  uint32_t MessageLength(void) const noexcept;
  enum WarnUnusedResultAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WeakAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WeakImportAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WeakRefAttr *)
  std::string_view Aliasee(void) const noexcept;
  uint32_t AliaseeLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WebAssemblyExportNameAttr *)
  std::string_view ExportName(void) const noexcept;
  uint32_t ExportNameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WebAssemblyImportModuleAttr *)
  std::string_view ImportModule(void) const noexcept;
  uint32_t ImportModuleLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WebAssemblyImportNameAttr *)
  std::string_view ImportName(void) const noexcept;
  uint32_t ImportNameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::WorkGroupSizeHintAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t XDim(void) const noexcept;
  uint32_t YDim(void) const noexcept;
  uint32_t ZDim(void) const noexcept;
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
  // Clone: (clang::X86ForceAlignArgPointerAttr *)
  std::string_view Spelling(void) const noexcept;
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
  bool AlwaysXRayInstrument(void) const noexcept;
  // Clone: (clang::XRayInstrumentAttr *)
  enum XRayInstrumentAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool NeverXRayInstrument(void) const noexcept;
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
  // Clone: (clang::XRayLogArgsAttr *)
  uint32_t ArgumentCount(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(XRayLogArgsAttr)
};

static_assert(sizeof(Attr) == sizeof(XRayLogArgsAttr));

class AArch64VectorPcsAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AArch64VectorPcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AArch64VectorPcsAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
  // Clone: (clang::AArch64VectorPcsAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AMDGPUFlatWorkGroupSizeAttr *)
  ::pasta::Expr Max(void) const noexcept;
  ::pasta::Expr Min(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AMDGPUFlatWorkGroupSizeAttr)
};

static_assert(sizeof(Attr) == sizeof(AMDGPUFlatWorkGroupSizeAttr));

class AMDGPUNumSGPRAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AMDGPUNumSGPRAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AMDGPUNumSGPRAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AMDGPUNumSGPRAttr)
  // Clone: (clang::AMDGPUNumSGPRAttr *)
  uint32_t NumSGPR(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AMDGPUNumVGPRAttr *)
  uint32_t NumVGPR(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AMDGPUWavesPerEUAttr *)
  ::pasta::Expr Max(void) const noexcept;
  ::pasta::Expr Min(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ARMInterruptAttr *)
  enum ARMInterruptAttrInterruptType Interrupt(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AVRInterruptAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AVRSignalAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AbiTagAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AcquireCapabilityAttr *)
  enum AcquireCapabilityAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsShared(void) const noexcept;
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
  // Clone: (clang::AcquireHandleAttr *)
  std::string_view HandleType(void) const noexcept;
  uint32_t HandleTypeLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AcquiredAfterAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AcquiredBeforeAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AddressSpaceAttr *)
  // AddressSpace: (int)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AliasAttr *)
  std::string_view Aliasee(void) const noexcept;
  uint32_t AliaseeLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AlignMac68kAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AlignNaturalAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AlignValueAttr *)
  ::pasta::Expr Alignment(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AlignedAttr *)
  uint32_t Alignment(void) const noexcept;
  ::pasta::Expr AlignmentExpression(void) const noexcept;
  ::pasta::Type AlignmentType(void) const noexcept;
  enum AlignedAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsAlignas(void) const noexcept;
  bool IsAlignmentDependent(void) const noexcept;
  bool IsAlignmentErrorDependent(void) const noexcept;
  bool IsAlignmentExpression(void) const noexcept;
  bool IsC11(void) const noexcept;
  bool IsDeclspec(void) const noexcept;
  bool IsGNU(void) const noexcept;
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
  // Clone: (clang::AllocAlignAttr *)
  // ParameterIndex: (clang::ParamIdx)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AllocSizeAttr *)
  // ElemSizeParameter: (clang::ParamIdx)
  // NumElemsParameter: (clang::ParamIdx)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AlwaysDestroyAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlwaysDestroyAttr)
};

static_assert(sizeof(Attr) == sizeof(AlwaysDestroyAttr));

class AlwaysInlineAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AlwaysInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AlwaysInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AlwaysInlineAttr)
  // Clone: (clang::AlwaysInlineAttr *)
  enum AlwaysInlineAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AlwaysInlineAttr)
};

static_assert(sizeof(Attr) == sizeof(AlwaysInlineAttr));

class AnalyzerNoReturnAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnalyzerNoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnalyzerNoReturnAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnalyzerNoReturnAttr)
  // Clone: (clang::AnalyzerNoReturnAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AnnotateAttr *)
  std::string_view Annotation(void) const noexcept;
  uint32_t AnnotationLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(AnnotateAttr)
};

static_assert(sizeof(Attr) == sizeof(AnnotateAttr));

class AnyX86InterruptAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AnyX86InterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, AnyX86InterruptAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, AnyX86InterruptAttr)
  // Clone: (clang::AnyX86InterruptAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AnyX86NoCallerSavedRegistersAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AnyX86NoCfCheckAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ArcWeakrefUnavailableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ArgumentWithTypeTagAttr *)
  // ArgumentIndex: (clang::ParamIdx)
  // ArgumentKind: (clang::IdentifierInfo *)
  bool IsPointer(void) const noexcept;
  enum ArgumentWithTypeTagAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ArmBuiltinAliasAttr *)
  // BuiltinName: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ArmMveStrictPolymorphismAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ArtificialAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AsmLabelAttr *)
  bool IsLiteralLabel(void) const noexcept;
  std::string_view Label(void) const noexcept;
  uint32_t LabelLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AssertCapabilityAttr *)
  enum AssertCapabilityAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsShared(void) const noexcept;
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
  // Clone: (clang::AssertExclusiveLockAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AssertSharedLockAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AssumeAlignedAttr *)
  ::pasta::Expr Alignment(void) const noexcept;
  ::pasta::Expr Offset(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AssumptionAttr *)
  std::string_view Assumption(void) const noexcept;
  uint32_t AssumptionLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::AvailabilityAttr *)
  // Deprecated: (llvm::VersionTuple)
  // Introduced: (llvm::VersionTuple)
  std::string_view Message(void) const noexcept;
  uint32_t MessageLength(void) const noexcept;
  // Obsoleted: (llvm::VersionTuple)
  // Platform: (clang::IdentifierInfo *)
  // Priority: (int)
  std::string_view Replacement(void) const noexcept;
  uint32_t ReplacementLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool Strict(void) const noexcept;
  bool Unavailable(void) const noexcept;
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
  // Clone: (clang::BPFPreserveAccessIndexAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::BTFDeclTagAttr *)
  std::string_view BTFDeclTag(void) const noexcept;
  uint32_t BTFDeclTagLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::BTFTypeTagAttr *)
  std::string_view BTFTypeTag(void) const noexcept;
  uint32_t BTFTypeTagLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::BlocksAttr *)
  std::string_view Spelling(void) const noexcept;
  enum BlocksAttrBlockType Type(void) const noexcept;
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
  // Clone: (clang::BuiltinAttr *)
  uint32_t ID(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::C11NoReturnAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CDeclAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFAuditedTransferAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFConsumedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFGuardAttr *)
  enum CFGuardAttrGuardArg Guard(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFICanonicalJumpTableAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFReturnsNotRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFReturnsRetainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CFUnknownTransferAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CPUDispatchAttr *)
  // Cpus: (llvm::iterator_range<clang::IdentifierInfo **>)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CPUSpecificAttr *)
  // Cpus: (llvm::iterator_range<clang::IdentifierInfo **>)
  // CPUName: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDAConstantAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDADeviceAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDADeviceBuiltinSurfaceTypeAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDADeviceBuiltinTextureTypeAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDAGlobalAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDAHostAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDAInvalidTargetAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDALaunchBoundsAttr *)
  ::pasta::Expr MaxThreads(void) const noexcept;
  ::pasta::Expr MinBlocks(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CUDASharedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CXX11NoReturnAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CallableWhenAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CallbackAttr *)
  // Encoding: (llvm::iterator_range<int *>)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CapabilityAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  enum CapabilityAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsShared(void) const noexcept;
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
  // Clone: (clang::CapturedRecordAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CarriesDependencyAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CleanupAttr *)
  ::pasta::FunctionDecl FunctionDeclaration(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CmseNSCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CmseNSEntryAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CodeSegAttr *)
  std::string_view Name(void) const noexcept;
  uint32_t NameLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ColdAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::CommonAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ConstAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ConstInitAttr *)
  enum ConstInitAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsConstinit(void) const noexcept;
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
  // Clone: (clang::ConstructorAttr *)
  // Priority: (int)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ConsumableAttr *)
  enum ConsumableAttrConsumedState DefaultState(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ConsumableAutoCastAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ConsumableSetOnReadAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ConvergentAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DLLExportAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DLLExportStaticLocalAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DLLImportAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DLLImportStaticLocalAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DeprecatedAttr *)
  std::string_view Message(void) const noexcept;
  uint32_t MessageLength(void) const noexcept;
  std::string_view Replacement(void) const noexcept;
  uint32_t ReplacementLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DestructorAttr *)
  // Priority: (int)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DiagnoseAsBuiltinAttr *)
  ::pasta::FunctionDecl Function(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DiagnoseIfAttr *)
  bool ArgumentDependent(void) const noexcept;
  ::pasta::Expr Condition(void) const noexcept;
  enum DiagnoseIfAttrDiagnosticType DiagnosticType(void) const noexcept;
  std::string_view Message(void) const noexcept;
  uint32_t MessageLength(void) const noexcept;
  ::pasta::NamedDecl Parent(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsError(void) const noexcept;
  bool IsWarning(void) const noexcept;
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
  // Clone: (clang::DisableSanitizerInstrumentationAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::DisableTailCallsAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::EmptyBasesAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::EnableIfAttr *)
  ::pasta::Expr Condition(void) const noexcept;
  std::string_view Message(void) const noexcept;
  uint32_t MessageLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::EnforceTCBAttr *)
  std::string_view Spelling(void) const noexcept;
  std::string_view TCBName(void) const noexcept;
  uint32_t TCBNameLength(void) const noexcept;
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
  // Clone: (clang::EnforceTCBLeafAttr *)
  std::string_view Spelling(void) const noexcept;
  std::string_view TCBName(void) const noexcept;
  uint32_t TCBNameLength(void) const noexcept;
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
  // Clone: (clang::EnumExtensibilityAttr *)
  enum EnumExtensibilityAttrKind Extensibility(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ErrorAttr *)
  enum ErrorAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  std::string_view UserDiagnostic(void) const noexcept;
  uint32_t UserDiagnosticLength(void) const noexcept;
  bool IsError(void) const noexcept;
  bool IsWarning(void) const noexcept;
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
  // Clone: (clang::ExcludeFromExplicitInstantiationAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ExclusiveTrylockFunctionAttr *)
  std::string_view Spelling(void) const noexcept;
  ::pasta::Expr SuccessValue(void) const noexcept;
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
  // Clone: (clang::ExternalSourceSymbolAttr *)
  std::string_view DefinedIn(void) const noexcept;
  uint32_t DefinedInLength(void) const noexcept;
  bool GeneratedDeclaration(void) const noexcept;
  std::string_view Language(void) const noexcept;
  uint32_t LanguageLength(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::FallThroughAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::FastCallAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::FinalAttr *)
  enum FinalAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
  bool IsSpelledAsSealed(void) const noexcept;
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
  // Clone: (clang::FlagEnumAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::FlattenAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::FormatArgAttr *)
  // FormatIndex: (clang::ParamIdx)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::FormatAttr *)
  // FirstArgument: (int)
  // FormatIndex: (int)
  std::string_view Spelling(void) const noexcept;
  // Type: (clang::IdentifierInfo *)
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(FormatAttr)
};

static_assert(sizeof(Attr) == sizeof(FormatAttr));

class GNUInlineAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GNUInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, GNUInlineAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, GNUInlineAttr)
  // Clone: (clang::GNUInlineAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::GuardedByAttr *)
  ::pasta::Expr Argument(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::GuardedVarAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::HIPManagedAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(HIPManagedAttr)
};

static_assert(sizeof(Attr) == sizeof(HIPManagedAttr));

class HotAttr : public InheritableAttr {
 private:
  using InheritableAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HotAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, HotAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, HotAttr)
  // Clone: (clang::HotAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::IBActionAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::IBOutletAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::IBOutletCollectionAttr *)
  ::pasta::Type Interface(void) const noexcept;
  ::pasta::Type InterfaceToken(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::LikelyAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::MustTailAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::NoDerefAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(NoDerefAttr)
};

static_assert(sizeof(Attr) == sizeof(NoDerefAttr));

class NoMergeAttr : public DeclOrStmtAttr {
 private:
  using DeclOrStmtAttr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoMergeAttr)
  PASTA_DECLARE_BASE_OPERATORS(Attr, NoMergeAttr)
  PASTA_DECLARE_BASE_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
  PASTA_DECLARE_BASE_OPERATORS(InheritableAttr, NoMergeAttr)
  // Clone: (clang::NoMergeAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCGCAttr *)
  // Kind: (clang::IdentifierInfo *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCInertUnsafeUnretainedAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::ObjCKindOfAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLConstantAddressSpaceAttr *)
  enum OpenCLConstantAddressSpaceAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLGenericAddressSpaceAttr *)
  enum OpenCLGenericAddressSpaceAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLGlobalAddressSpaceAttr *)
  enum OpenCLGlobalAddressSpaceAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLGlobalDeviceAddressSpaceAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLGlobalHostAddressSpaceAttr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLLocalAddressSpaceAttr *)
  enum OpenCLLocalAddressSpaceAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLPrivateAddressSpaceAttr *)
  enum OpenCLPrivateAddressSpaceAttrSpelling SemanticSpelling(void) const noexcept;
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::OpenCLUnrollHintAttr *)
  std::string_view Spelling(void) const noexcept;
  uint32_t UnrollHint(void) const noexcept;
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
  // Clone: (clang::Ptr32Attr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::Ptr64Attr *)
  std::string_view Spelling(void) const noexcept;
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
  // Clone: (clang::SPtrAttr *)
  std::string_view Spelling(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(SPtrAttr)
};

static_assert(sizeof(Attr) == sizeof(SPtrAttr));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR
#endif  // PASTA_IN_BOOTSTRAP
