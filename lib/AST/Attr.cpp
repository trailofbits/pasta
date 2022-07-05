/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#define PASTA_IN_ATTR_CPP
#ifndef PASTA_IN_BOOTSTRAP
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#include <clang/Frontend/CompilerInstance.h>
#pragma clang diagnostic pop

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include "AST.h"
#include "Builder.h"

#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \
    std::optional<class derived> derived::From(const class base &that) { \
      if (auto attr_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.Attr)) { \
        return AttrBuilder::Create<class derived>(that.ast, attr_ptr); \
      } else { \
        return std::nullopt; \
      } \
    }

#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, that.u.Attr) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), that.u.Attr) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.Attr = that.u.Attr; \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      class derived new_that(std::forward<class derived>(that)); \
      ast = std::move(new_that.ast); \
      u.Attr = new_that.u.Attr; \
      return *this; \
    }

namespace pasta {


// Return the KindName of the Clang's `Attr`
std::string_view Attr::KindName(void) const noexcept {
  switch (u.Attr->getKind()) {
#define ATTR(X) \
    case clang::attr::Kind::X: \
      return #X;
#include "clang/Basic/AttrList.inc"
  }
  __builtin_unreachable();
}

::pasta::TokenRange Attr::Tokens(void) const noexcept {
  return ast->TokenRangeFrom(u.Attr->getRange());
}

PASTA_DEFINE_DERIVED_OPERATORS(Attr, AArch64VectorPcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AMDGPUNumSGPRAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AMDGPUNumVGPRAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AMDGPUWavesPerEUAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ARMInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AVRInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AVRSignalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AbiTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AcquireCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AcquireHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AcquiredAfterAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AcquiredBeforeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AlignMac68kAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AlignNaturalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AlignValueAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AlignedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AllocAlignAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AllocSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AlwaysDestroyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AlwaysInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AnalyzerNoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AnnotateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AnyX86InterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AnyX86NoCallerSavedRegistersAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AnyX86NoCfCheckAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ArcWeakrefUnavailableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ArgumentWithTypeTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ArmBuiltinAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ArmMveStrictPolymorphismAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ArtificialAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AsmLabelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AssertCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AssertExclusiveLockAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AssertSharedLockAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AssumeAlignedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AssumptionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AvailabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, BPFPreserveAccessIndexAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, BTFDeclTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, BTFTypeTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, BlocksAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, BuiltinAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, BuiltinAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, C11NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFAuditedTransferAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFGuardAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFICanonicalJumpTableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFReturnsNotRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFReturnsRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CFUnknownTransferAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CPUDispatchAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CPUSpecificAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDAConstantAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDADeviceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDADeviceBuiltinSurfaceTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDADeviceBuiltinTextureTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDAGlobalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDAHostAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDAInvalidTargetAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDALaunchBoundsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CUDASharedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CXX11NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CallableWhenAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CallbackAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CalledOnceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CapturedRecordAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CarriesDependencyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CleanupAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CmseNSCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CmseNSEntryAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CodeSegAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ColdAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, CommonAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConstAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConstInitAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConstructorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConsumableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConsumableAutoCastAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConsumableSetOnReadAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ConvergentAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DLLExportAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DLLExportStaticLocalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DLLImportAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DLLImportStaticLocalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DeclOrStmtAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DeprecatedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DestructorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DiagnoseAsBuiltinAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DiagnoseIfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DisableSanitizerInstrumentationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, DisableTailCallsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, EmptyBasesAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, EnableIfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, EnforceTCBAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, EnforceTCBLeafAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, EnumExtensibilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ErrorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ExcludeFromExplicitInstantiationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ExclusiveTrylockFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ExternalSourceSymbolAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FallThroughAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FastCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FinalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FlagEnumAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FlattenAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FormatArgAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FormatAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, GNUInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, GuardedByAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, GuardedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HIPManagedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HotAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, IBActionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, IBOutletAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, IBOutletCollectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, IFuncAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, InheritableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, InheritableParamAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, InitPriorityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, InitSegAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, IntelOclBiccAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, InternalLinkageAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LTOVisibilityPublicAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LayoutVersionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LeafAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LifetimeBoundAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LikelyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LoaderUninitializedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LockReturnedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LocksExcludedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, LoopHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, M68kInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MIGServerRoutineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSAllocatorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSInheritanceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSNoVTableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSP430InterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSStructAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MSVtorDispAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MaxFieldAlignmentAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MayAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MicroMipsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MinSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MinVectorWidthAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, Mips16Attr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MipsInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MipsLongCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MipsShortCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ModeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MustTailAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NSConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NSConsumesSelfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NSErrorDomainAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NSReturnsAutoreleasedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NSReturnsNotRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NSReturnsRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NakedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoBuiltinAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoCommonAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoDebugAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoDerefAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoDestroyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoDuplicateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoEscapeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoInstrumentFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoMergeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoMicroMipsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoMips16Attr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoProfileFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoSanitizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoSpeculativeLoadHardeningAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoSplitStackAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoStackProtectorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoThrowAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoUniqueAddressAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NotTailCalledAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPAllocateDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPCaptureKindAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPCaptureNoInitAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPDeclareSimdDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPDeclareTargetDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPDeclareVariantAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPReferencedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OMPThreadPrivateDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OSConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OSConsumesThisAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OSReturnsNotRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OSReturnsRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OSReturnsRetainedOnNonZeroAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OSReturnsRetainedOnZeroAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCBoxableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCBridgeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCBridgeMutableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCBridgeRelatedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCClassStubAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCDesignatedInitializerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCDirectAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCDirectMembersAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCExceptionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCExplicitProtocolImplAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCExternallyRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCGCAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCIndependentClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCInertUnsafeUnretainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCKindOfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCMethodFamilyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCNSObjectAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCNonLazyClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCNonRuntimeProtocolAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCOwnershipAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCPreciseLifetimeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCRequiresPropertyDefsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCRequiresSuperAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCReturnsInnerPointerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCRootClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCRuntimeNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCRuntimeVisibleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ObjCSubclassingRestrictedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLAccessAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLConstantAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLGenericAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLGlobalAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLGlobalDeviceAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLGlobalHostAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLIntelReqdSubGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLKernelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLLocalAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLPrivateAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OpenCLUnrollHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OptimizeNoneAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OverloadableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OverrideAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OwnerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, OwnershipAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PackedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ParamTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ParameterABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PascalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PassObjectSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PatchableFunctionEntryAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PointerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PragmaClangBSSSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PragmaClangDataSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PragmaClangRelroSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PragmaClangRodataSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PragmaClangTextSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PreferredNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PreserveAllAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PreserveMostAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PtGuardedByAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PtGuardedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, Ptr32Attr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, Ptr64Attr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, PureAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RISCVInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RegCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReinitializesAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReleaseCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReleaseHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RenderScriptKernelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReqdWorkGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RequiresCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RestrictAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RetainAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReturnTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReturnsNonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReturnsTwiceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SPtrAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SYCLKernelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SYCLSpecialClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ScopedLockableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SelectAnyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SentinelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SetTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SharedTrylockFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SpeculativeLoadHardeningAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, StandaloneDebugAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, StdCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, StmtAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, StrictFPAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SuppressAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftAsyncAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftAsyncCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftAsyncContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftAsyncErrorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftAsyncNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftAttrAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftBridgeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftBridgedTypedefAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftErrorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftErrorResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftIndirectResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftNewTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftObjCMembersAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SwiftPrivateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, SysVABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TLSModelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TargetAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TargetClonesAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TestTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ThisCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ThreadAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TransparentUnionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TrivialABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TryAcquireCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeNonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeNullUnspecifiedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeNullableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeNullableResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeTagForDatatypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TypeVisibilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UPtrAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UnavailableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UninitializedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UnlikelyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UnusedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UseHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UsedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UsingIfExistsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, UuidAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, VecReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, VecTypeHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, VectorCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, VisibilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WarnUnusedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WarnUnusedResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WeakAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WeakImportAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WeakRefAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WebAssemblyExportNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WebAssemblyImportModuleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WebAssemblyImportNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, WorkGroupSizeHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, X86ForceAlignArgPointerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, XRayInstrumentAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, XRayLogArgsAttr)
// 1: Attr::Clone
::pasta::AttrKind Attr::Kind(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::AttrKind>(val);
  __builtin_unreachable();
}

::pasta::Token Attr::Token(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::string_view Attr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Attr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t Attr::SpellingListIndex(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getSpellingListIndex();
  return val;
  __builtin_unreachable();
}

bool Attr::IsImplicit(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isImplicit();
  return val;
  __builtin_unreachable();
}

bool Attr::IsInherited(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isInherited();
  return val;
  __builtin_unreachable();
}

bool Attr::IsLateParsed(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isLateParsed();
  return val;
  __builtin_unreachable();
}

bool Attr::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isPackExpansion();
  return val;
  __builtin_unreachable();
}

BuiltinAliasAttr::BuiltinAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BuiltinAliasAttr)
// 1: BuiltinAliasAttr::Clone
// 0: BuiltinAliasAttr::BuiltinName
enum BuiltinAliasAttrSpelling BuiltinAliasAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinAliasAttr *>(u.BuiltinAliasAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::BuiltinAliasAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view BuiltinAliasAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinAliasAttr *>(u.BuiltinAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BuiltinAliasAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CalledOnceAttr::CalledOnceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CalledOnceAttr)
// 1: CalledOnceAttr::Clone
std::string_view CalledOnceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CalledOnceAttr *>(u.CalledOnceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CalledOnceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

IFuncAttr::IFuncAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IFuncAttr)
// 1: IFuncAttr::Clone
std::string_view IFuncAttr::Resolver(void) const noexcept {
  auto &self = *const_cast<clang::IFuncAttr *>(u.IFuncAttr);
  decltype(auto) val = self.getResolver();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t IFuncAttr::ResolverLength(void) const noexcept {
  auto &self = *const_cast<clang::IFuncAttr *>(u.IFuncAttr);
  decltype(auto) val = self.getResolverLength();
  return val;
  __builtin_unreachable();
}

std::string_view IFuncAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::IFuncAttr *>(u.IFuncAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IFuncAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

InheritableAttr::InheritableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InheritableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AMDGPUNumSGPRAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AMDGPUNumVGPRAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AMDGPUWavesPerEUAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ARMInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AVRInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AVRSignalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AcquireCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AcquireHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AcquiredAfterAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AcquiredBeforeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AlignMac68kAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AlignNaturalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AlignedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AllocAlignAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AllocSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AlwaysDestroyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AlwaysInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AnalyzerNoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AnnotateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AnyX86InterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AnyX86NoCallerSavedRegistersAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AnyX86NoCfCheckAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ArcWeakrefUnavailableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ArgumentWithTypeTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ArmBuiltinAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ArtificialAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AsmLabelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AssertCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AssertExclusiveLockAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AssertSharedLockAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AssumeAlignedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AssumptionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AvailabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, BPFPreserveAccessIndexAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, BTFDeclTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, BlocksAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, BuiltinAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, C11NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFAuditedTransferAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFGuardAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFICanonicalJumpTableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFReturnsNotRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFReturnsRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CFUnknownTransferAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CPUDispatchAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CPUSpecificAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDAConstantAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDADeviceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDADeviceBuiltinSurfaceTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDADeviceBuiltinTextureTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDAGlobalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDAHostAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDAInvalidTargetAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDALaunchBoundsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CUDASharedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CXX11NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CallableWhenAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CallbackAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CapturedRecordAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CarriesDependencyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CleanupAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CmseNSEntryAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CodeSegAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ColdAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, CommonAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConstAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConstInitAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConstructorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConsumableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConsumableAutoCastAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConsumableSetOnReadAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ConvergentAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DLLExportAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DLLExportStaticLocalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DLLImportAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DLLImportStaticLocalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DeclOrStmtAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DeprecatedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DestructorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DiagnoseAsBuiltinAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DiagnoseIfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DisableSanitizerInstrumentationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, DisableTailCallsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, EmptyBasesAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, EnableIfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, EnforceTCBAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, EnforceTCBLeafAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, EnumExtensibilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ErrorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ExcludeFromExplicitInstantiationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ExclusiveTrylockFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ExternalSourceSymbolAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FastCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FinalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FlagEnumAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FlattenAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FormatArgAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FormatAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, GNUInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, GuardedByAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, GuardedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HIPManagedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HotAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, IBActionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, IBOutletAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, IBOutletCollectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, InheritableParamAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, InitPriorityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, IntelOclBiccAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, InternalLinkageAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, LTOVisibilityPublicAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, LayoutVersionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, LeafAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, LifetimeBoundAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, LockReturnedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, LocksExcludedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, M68kInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MIGServerRoutineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSAllocatorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSInheritanceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSNoVTableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSP430InterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSStructAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MSVtorDispAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MaxFieldAlignmentAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MayAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MicroMipsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MinSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MinVectorWidthAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, Mips16Attr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MipsInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MipsLongCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MipsShortCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NSConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NSConsumesSelfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NSErrorDomainAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NSReturnsAutoreleasedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NSReturnsNotRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NSReturnsRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NakedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoAliasAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoCommonAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoDebugAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoDestroyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoDuplicateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoInstrumentFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoMergeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoMicroMipsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoMips16Attr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoProfileFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoSanitizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoSpeculativeLoadHardeningAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoSplitStackAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoStackProtectorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoThrowAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NotTailCalledAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OMPAllocateDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OMPCaptureNoInitAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OMPDeclareTargetDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OMPDeclareVariantAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OMPThreadPrivateDeclAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OSConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OSConsumesThisAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OSReturnsNotRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OSReturnsRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OSReturnsRetainedOnNonZeroAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OSReturnsRetainedOnZeroAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCBridgeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCBridgeMutableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCBridgeRelatedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCExceptionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCExplicitProtocolImplAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCExternallyRetainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCIndependentClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCMethodFamilyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCNSObjectAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCOwnershipAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCPreciseLifetimeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCRequiresPropertyDefsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCRequiresSuperAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCReturnsInnerPointerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCRootClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ObjCSubclassingRestrictedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OpenCLIntelReqdSubGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OpenCLKernelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OptimizeNoneAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OverrideAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OwnerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, OwnershipAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PackedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ParamTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ParameterABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PascalAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PassObjectSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PatchableFunctionEntryAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PointerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PragmaClangBSSSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PragmaClangDataSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PragmaClangRelroSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PragmaClangRodataSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PragmaClangTextSectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PreferredNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PreserveAllAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PreserveMostAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PtGuardedByAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PtGuardedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, PureAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, RISCVInterruptAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, RegCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReinitializesAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReleaseCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReleaseHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReqdWorkGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, RequiresCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, RestrictAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, RetainAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReturnTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReturnsNonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReturnsTwiceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SYCLKernelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SYCLSpecialClassAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ScopedLockableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SectionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SelectAnyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SentinelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SetTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SharedTrylockFunctionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SpeculativeLoadHardeningAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, StandaloneDebugAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, StdCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, StrictFPAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncErrorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftAsyncNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftAttrAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftBridgeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftBridgedTypedefAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftErrorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftErrorResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftIndirectResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftNewTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SwiftPrivateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, SysVABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TLSModelAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TargetAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TargetClonesAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TestTypestateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ThisCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TransparentUnionAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TrivialABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TryAcquireCapabilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TypeTagForDatatypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TypeVisibilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UnavailableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UninitializedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UnusedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UseHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UsedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UsingIfExistsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, UuidAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, VecReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, VecTypeHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, VectorCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, VisibilityAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WarnUnusedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WarnUnusedResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WeakAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WeakImportAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WeakRefAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WebAssemblyExportNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WebAssemblyImportModuleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WebAssemblyImportNameAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, WorkGroupSizeHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, X86ForceAlignArgPointerAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, XRayInstrumentAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, XRayLogArgsAttr)
bool InheritableAttr::ShouldInheritEvenIfAlreadyPresent(void) const noexcept {
  auto &self = *const_cast<clang::InheritableAttr *>(u.InheritableAttr);
  decltype(auto) val = self.shouldInheritEvenIfAlreadyPresent();
  return val;
  __builtin_unreachable();
}

InheritableParamAttr::InheritableParamAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InheritableParamAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, InheritableParamAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, AnnotateAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, CFConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, CarriesDependencyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, NSConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, NonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, OSConsumedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, ParameterABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, PassObjectSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, ReleaseHandleAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, SwiftAsyncContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, SwiftContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, SwiftErrorResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, SwiftIndirectResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableParamAttr, UseHandleAttr)
InitPriorityAttr::InitPriorityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InitPriorityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, InitPriorityAttr)
// 1: InitPriorityAttr::Clone
uint32_t InitPriorityAttr::Priority(void) const noexcept {
  auto &self = *const_cast<clang::InitPriorityAttr *>(u.InitPriorityAttr);
  decltype(auto) val = self.getPriority();
  return val;
  __builtin_unreachable();
}

std::string_view InitPriorityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::InitPriorityAttr *>(u.InitPriorityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "InitPriorityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

InitSegAttr::InitSegAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InitSegAttr)
// 1: InitSegAttr::Clone
std::string_view InitSegAttr::Section(void) const noexcept {
  auto &self = *const_cast<clang::InitSegAttr *>(u.InitSegAttr);
  decltype(auto) val = self.getSection();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t InitSegAttr::SectionLength(void) const noexcept {
  auto &self = *const_cast<clang::InitSegAttr *>(u.InitSegAttr);
  decltype(auto) val = self.getSectionLength();
  return val;
  __builtin_unreachable();
}

std::string_view InitSegAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::InitSegAttr *>(u.InitSegAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "InitSegAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

IntelOclBiccAttr::IntelOclBiccAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IntelOclBiccAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IntelOclBiccAttr)
// 1: IntelOclBiccAttr::Clone
std::string_view IntelOclBiccAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::IntelOclBiccAttr *>(u.IntelOclBiccAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IntelOclBiccAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

InternalLinkageAttr::InternalLinkageAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InternalLinkageAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, InternalLinkageAttr)
// 1: InternalLinkageAttr::Clone
std::string_view InternalLinkageAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::InternalLinkageAttr *>(u.InternalLinkageAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "InternalLinkageAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LTOVisibilityPublicAttr::LTOVisibilityPublicAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LTOVisibilityPublicAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LTOVisibilityPublicAttr)
// 1: LTOVisibilityPublicAttr::Clone
std::string_view LTOVisibilityPublicAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LTOVisibilityPublicAttr *>(u.LTOVisibilityPublicAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LTOVisibilityPublicAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LayoutVersionAttr::LayoutVersionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LayoutVersionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LayoutVersionAttr)
// 1: LayoutVersionAttr::Clone
std::string_view LayoutVersionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LayoutVersionAttr *>(u.LayoutVersionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LayoutVersionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t LayoutVersionAttr::Version(void) const noexcept {
  auto &self = *const_cast<clang::LayoutVersionAttr *>(u.LayoutVersionAttr);
  decltype(auto) val = self.getVersion();
  return val;
  __builtin_unreachable();
}

LeafAttr::LeafAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LeafAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LeafAttr)
// 1: LeafAttr::Clone
std::string_view LeafAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LeafAttr *>(u.LeafAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LeafAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LifetimeBoundAttr::LifetimeBoundAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LifetimeBoundAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LifetimeBoundAttr)
// 1: LifetimeBoundAttr::Clone
std::string_view LifetimeBoundAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeBoundAttr *>(u.LifetimeBoundAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LifetimeBoundAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LoaderUninitializedAttr::LoaderUninitializedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LoaderUninitializedAttr)
// 1: LoaderUninitializedAttr::Clone
std::string_view LoaderUninitializedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LoaderUninitializedAttr *>(u.LoaderUninitializedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LoaderUninitializedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LockReturnedAttr::LockReturnedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LockReturnedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LockReturnedAttr)
// 1: LockReturnedAttr::Clone
::pasta::Expr LockReturnedAttr::Argument(void) const noexcept {
  auto &self = *const_cast<clang::LockReturnedAttr *>(u.LockReturnedAttr);
  decltype(auto) val = self.getArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "LockReturnedAttr::Argument can return nullptr!");
  __builtin_unreachable();
}

std::string_view LockReturnedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LockReturnedAttr *>(u.LockReturnedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LockReturnedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LocksExcludedAttr::LocksExcludedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LocksExcludedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LocksExcludedAttr)
// 0: LocksExcludedAttr::Arguments
// 0: LocksExcludedAttr::
// 0: LocksExcludedAttr::
// 0: LocksExcludedAttr::
// 1: LocksExcludedAttr::Clone
std::string_view LocksExcludedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LocksExcludedAttr *>(u.LocksExcludedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LocksExcludedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LoopHintAttr::LoopHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LoopHintAttr)
// 1: LoopHintAttr::Clone
// 1: LoopHintAttr::DiagnosticName
enum LoopHintAttrOptionType LoopHintAttr::Option(void) const noexcept {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getOption();
  return static_cast<::pasta::LoopHintAttrOptionType>(val);
  __builtin_unreachable();
}

enum LoopHintAttrSpelling LoopHintAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::LoopHintAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view LoopHintAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LoopHintAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

enum LoopHintAttrLoopHintState LoopHintAttr::State(void) const noexcept {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getState();
  return static_cast<::pasta::LoopHintAttrLoopHintState>(val);
  __builtin_unreachable();
}

::pasta::Expr LoopHintAttr::Value(void) const noexcept {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "LoopHintAttr::Value can return nullptr!");
  __builtin_unreachable();
}

// 1: LoopHintAttr::ValueString
M68kInterruptAttr::M68kInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, M68kInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, M68kInterruptAttr)
// 1: M68kInterruptAttr::Clone
uint32_t M68kInterruptAttr::Number(void) const noexcept {
  auto &self = *const_cast<clang::M68kInterruptAttr *>(u.M68kInterruptAttr);
  decltype(auto) val = self.getNumber();
  return val;
  __builtin_unreachable();
}

std::string_view M68kInterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::M68kInterruptAttr *>(u.M68kInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "M68kInterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MIGServerRoutineAttr::MIGServerRoutineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MIGServerRoutineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MIGServerRoutineAttr)
// 1: MIGServerRoutineAttr::Clone
std::string_view MIGServerRoutineAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MIGServerRoutineAttr *>(u.MIGServerRoutineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MIGServerRoutineAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSABIAttr::MSABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSABIAttr)
// 1: MSABIAttr::Clone
std::string_view MSABIAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSABIAttr *>(u.MSABIAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSABIAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSAllocatorAttr::MSAllocatorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSAllocatorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSAllocatorAttr)
// 1: MSAllocatorAttr::Clone
std::string_view MSAllocatorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSAllocatorAttr *>(u.MSAllocatorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSAllocatorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSInheritanceAttr::MSInheritanceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSInheritanceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSInheritanceAttr)
// 1: MSInheritanceAttr::Clone
bool MSInheritanceAttr::BestCase(void) const noexcept {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getBestCase();
  return val;
  __builtin_unreachable();
}

enum MSInheritanceModel MSInheritanceAttr::InheritanceModel(void) const noexcept {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
  __builtin_unreachable();
}

enum MSInheritanceAttrSpelling MSInheritanceAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::MSInheritanceAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view MSInheritanceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSInheritanceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSNoVTableAttr::MSNoVTableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSNoVTableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSNoVTableAttr)
// 1: MSNoVTableAttr::Clone
std::string_view MSNoVTableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSNoVTableAttr *>(u.MSNoVTableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSNoVTableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSP430InterruptAttr::MSP430InterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSP430InterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSP430InterruptAttr)
// 1: MSP430InterruptAttr::Clone
uint32_t MSP430InterruptAttr::Number(void) const noexcept {
  auto &self = *const_cast<clang::MSP430InterruptAttr *>(u.MSP430InterruptAttr);
  decltype(auto) val = self.getNumber();
  return val;
  __builtin_unreachable();
}

std::string_view MSP430InterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSP430InterruptAttr *>(u.MSP430InterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSP430InterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSStructAttr::MSStructAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSStructAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSStructAttr)
// 1: MSStructAttr::Clone
std::string_view MSStructAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSStructAttr *>(u.MSStructAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSStructAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MSVtorDispAttr::MSVtorDispAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSVtorDispAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSVtorDispAttr)
// 1: MSVtorDispAttr::Clone
std::string_view MSVtorDispAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MSVtorDispAttr *>(u.MSVtorDispAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSVtorDispAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t MSVtorDispAttr::Vdm(void) const noexcept {
  auto &self = *const_cast<clang::MSVtorDispAttr *>(u.MSVtorDispAttr);
  decltype(auto) val = self.getVdm();
  return val;
  __builtin_unreachable();
}

enum MSVtorDispMode MSVtorDispAttr::VtorDispMode(void) const noexcept {
  auto &self = *const_cast<clang::MSVtorDispAttr *>(u.MSVtorDispAttr);
  decltype(auto) val = self.getVtorDispMode();
  return static_cast<::pasta::MSVtorDispMode>(val);
  __builtin_unreachable();
}

MaxFieldAlignmentAttr::MaxFieldAlignmentAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MaxFieldAlignmentAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MaxFieldAlignmentAttr)
// 1: MaxFieldAlignmentAttr::Clone
uint32_t MaxFieldAlignmentAttr::Alignment(void) const noexcept {
  auto &self = *const_cast<clang::MaxFieldAlignmentAttr *>(u.MaxFieldAlignmentAttr);
  decltype(auto) val = self.getAlignment();
  return val;
  __builtin_unreachable();
}

std::string_view MaxFieldAlignmentAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MaxFieldAlignmentAttr *>(u.MaxFieldAlignmentAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MaxFieldAlignmentAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MayAliasAttr::MayAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MayAliasAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MayAliasAttr)
// 1: MayAliasAttr::Clone
std::string_view MayAliasAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MayAliasAttr *>(u.MayAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MayAliasAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MicroMipsAttr::MicroMipsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MicroMipsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MicroMipsAttr)
// 1: MicroMipsAttr::Clone
std::string_view MicroMipsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MicroMipsAttr *>(u.MicroMipsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MicroMipsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MinSizeAttr::MinSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MinSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MinSizeAttr)
// 1: MinSizeAttr::Clone
std::string_view MinSizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MinSizeAttr *>(u.MinSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MinSizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MinVectorWidthAttr::MinVectorWidthAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MinVectorWidthAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MinVectorWidthAttr)
// 1: MinVectorWidthAttr::Clone
std::string_view MinVectorWidthAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MinVectorWidthAttr *>(u.MinVectorWidthAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MinVectorWidthAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t MinVectorWidthAttr::VectorWidth(void) const noexcept {
  auto &self = *const_cast<clang::MinVectorWidthAttr *>(u.MinVectorWidthAttr);
  decltype(auto) val = self.getVectorWidth();
  return val;
  __builtin_unreachable();
}

Mips16Attr::Mips16Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, Mips16Attr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, Mips16Attr)
// 1: Mips16Attr::Clone
std::string_view Mips16Attr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::Mips16Attr *>(u.Mips16Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Mips16Attr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MipsInterruptAttr::MipsInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MipsInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MipsInterruptAttr)
// 1: MipsInterruptAttr::Clone
enum MipsInterruptAttrInterruptType MipsInterruptAttr::Interrupt(void) const noexcept {
  auto &self = *const_cast<clang::MipsInterruptAttr *>(u.MipsInterruptAttr);
  decltype(auto) val = self.getInterrupt();
  return static_cast<::pasta::MipsInterruptAttrInterruptType>(val);
  __builtin_unreachable();
}

std::string_view MipsInterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MipsInterruptAttr *>(u.MipsInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MipsInterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MipsLongCallAttr::MipsLongCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MipsLongCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MipsLongCallAttr)
// 1: MipsLongCallAttr::Clone
enum MipsLongCallAttrSpelling MipsLongCallAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::MipsLongCallAttr *>(u.MipsLongCallAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::MipsLongCallAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view MipsLongCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MipsLongCallAttr *>(u.MipsLongCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MipsLongCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MipsShortCallAttr::MipsShortCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MipsShortCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MipsShortCallAttr)
// 1: MipsShortCallAttr::Clone
enum MipsShortCallAttrSpelling MipsShortCallAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::MipsShortCallAttr *>(u.MipsShortCallAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::MipsShortCallAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view MipsShortCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MipsShortCallAttr *>(u.MipsShortCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MipsShortCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ModeAttr::ModeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ModeAttr)
// 1: ModeAttr::Clone
// 0: ModeAttr::Mode
std::string_view ModeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ModeAttr *>(u.ModeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ModeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NSConsumedAttr::NSConsumedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, NSConsumedAttr)
// 1: NSConsumedAttr::Clone
std::string_view NSConsumedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NSConsumedAttr *>(u.NSConsumedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSConsumedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NSConsumesSelfAttr::NSConsumesSelfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSConsumesSelfAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSConsumesSelfAttr)
// 1: NSConsumesSelfAttr::Clone
std::string_view NSConsumesSelfAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NSConsumesSelfAttr *>(u.NSConsumesSelfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSConsumesSelfAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NSErrorDomainAttr::NSErrorDomainAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSErrorDomainAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSErrorDomainAttr)
// 1: NSErrorDomainAttr::Clone
::pasta::VarDecl NSErrorDomainAttr::ErrorDomain(void) const noexcept {
  auto &self = *const_cast<clang::NSErrorDomainAttr *>(u.NSErrorDomainAttr);
  decltype(auto) val = self.getErrorDomain();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "NSErrorDomainAttr::ErrorDomain can return nullptr!");
  __builtin_unreachable();
}

std::string_view NSErrorDomainAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NSErrorDomainAttr *>(u.NSErrorDomainAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSErrorDomainAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NSReturnsAutoreleasedAttr::NSReturnsAutoreleasedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSReturnsAutoreleasedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSReturnsAutoreleasedAttr)
// 1: NSReturnsAutoreleasedAttr::Clone
std::string_view NSReturnsAutoreleasedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NSReturnsAutoreleasedAttr *>(u.NSReturnsAutoreleasedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSReturnsAutoreleasedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NSReturnsNotRetainedAttr::NSReturnsNotRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSReturnsNotRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSReturnsNotRetainedAttr)
// 1: NSReturnsNotRetainedAttr::Clone
std::string_view NSReturnsNotRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NSReturnsNotRetainedAttr *>(u.NSReturnsNotRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSReturnsNotRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NSReturnsRetainedAttr::NSReturnsRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSReturnsRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSReturnsRetainedAttr)
// 1: NSReturnsRetainedAttr::Clone
std::string_view NSReturnsRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NSReturnsRetainedAttr *>(u.NSReturnsRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSReturnsRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NakedAttr::NakedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NakedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NakedAttr)
// 1: NakedAttr::Clone
std::string_view NakedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NakedAttr *>(u.NakedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NakedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoAliasAttr::NoAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoAliasAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoAliasAttr)
// 1: NoAliasAttr::Clone
std::string_view NoAliasAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoAliasAttr *>(u.NoAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoAliasAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoBuiltinAttr::NoBuiltinAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoBuiltinAttr)
// 0: NoBuiltinAttr::BuiltinNames
// 0: NoBuiltinAttr::
// 0: NoBuiltinAttr::
// 0: NoBuiltinAttr::
// 1: NoBuiltinAttr::Clone
std::string_view NoBuiltinAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoBuiltinAttr *>(u.NoBuiltinAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoBuiltinAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoCommonAttr::NoCommonAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoCommonAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoCommonAttr)
// 1: NoCommonAttr::Clone
std::string_view NoCommonAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoCommonAttr *>(u.NoCommonAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoCommonAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoDebugAttr::NoDebugAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDebugAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoDebugAttr)
// 1: NoDebugAttr::Clone
std::string_view NoDebugAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoDebugAttr *>(u.NoDebugAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDebugAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoDestroyAttr::NoDestroyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDestroyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoDestroyAttr)
// 1: NoDestroyAttr::Clone
std::string_view NoDestroyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoDestroyAttr *>(u.NoDestroyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDestroyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoDuplicateAttr::NoDuplicateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDuplicateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoDuplicateAttr)
// 1: NoDuplicateAttr::Clone
std::string_view NoDuplicateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoDuplicateAttr *>(u.NoDuplicateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDuplicateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoEscapeAttr::NoEscapeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoEscapeAttr)
// 1: NoEscapeAttr::Clone
std::string_view NoEscapeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoEscapeAttr *>(u.NoEscapeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoEscapeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoInlineAttr::NoInlineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoInlineAttr)
// 1: NoInlineAttr::Clone
std::string_view NoInlineAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoInlineAttr *>(u.NoInlineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoInlineAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoInstrumentFunctionAttr::NoInstrumentFunctionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoInstrumentFunctionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoInstrumentFunctionAttr)
// 1: NoInstrumentFunctionAttr::Clone
std::string_view NoInstrumentFunctionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoInstrumentFunctionAttr *>(u.NoInstrumentFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoInstrumentFunctionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoMicroMipsAttr::NoMicroMipsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoMicroMipsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoMicroMipsAttr)
// 1: NoMicroMipsAttr::Clone
std::string_view NoMicroMipsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoMicroMipsAttr *>(u.NoMicroMipsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoMicroMipsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoMips16Attr::NoMips16Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoMips16Attr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoMips16Attr)
// 1: NoMips16Attr::Clone
std::string_view NoMips16Attr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoMips16Attr *>(u.NoMips16Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoMips16Attr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoProfileFunctionAttr::NoProfileFunctionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoProfileFunctionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoProfileFunctionAttr)
// 1: NoProfileFunctionAttr::Clone
std::string_view NoProfileFunctionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoProfileFunctionAttr *>(u.NoProfileFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoProfileFunctionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoReturnAttr::NoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoReturnAttr)
// 1: NoReturnAttr::Clone
std::string_view NoReturnAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoReturnAttr *>(u.NoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoReturnAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoSanitizeAttr::NoSanitizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoSanitizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoSanitizeAttr)
// 1: NoSanitizeAttr::Clone
// 0: NoSanitizeAttr::Mask
std::string_view NoSanitizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoSanitizeAttr *>(u.NoSanitizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoSanitizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool NoSanitizeAttr::HasCoverage(void) const noexcept {
  auto &self = *const_cast<clang::NoSanitizeAttr *>(u.NoSanitizeAttr);
  decltype(auto) val = self.hasCoverage();
  return val;
  __builtin_unreachable();
}

// 0: NoSanitizeAttr::Sanitizers
// 0: NoSanitizeAttr::
// 0: NoSanitizeAttr::
// 0: NoSanitizeAttr::
NoSpeculativeLoadHardeningAttr::NoSpeculativeLoadHardeningAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoSpeculativeLoadHardeningAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoSpeculativeLoadHardeningAttr)
// 1: NoSpeculativeLoadHardeningAttr::Clone
std::string_view NoSpeculativeLoadHardeningAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoSpeculativeLoadHardeningAttr *>(u.NoSpeculativeLoadHardeningAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoSpeculativeLoadHardeningAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoSplitStackAttr::NoSplitStackAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoSplitStackAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoSplitStackAttr)
// 1: NoSplitStackAttr::Clone
std::string_view NoSplitStackAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoSplitStackAttr *>(u.NoSplitStackAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoSplitStackAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoStackProtectorAttr::NoStackProtectorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoStackProtectorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoStackProtectorAttr)
// 1: NoStackProtectorAttr::Clone
std::string_view NoStackProtectorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoStackProtectorAttr *>(u.NoStackProtectorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoStackProtectorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoThreadSafetyAnalysisAttr::NoThreadSafetyAnalysisAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
// 1: NoThreadSafetyAnalysisAttr::Clone
std::string_view NoThreadSafetyAnalysisAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoThreadSafetyAnalysisAttr *>(u.NoThreadSafetyAnalysisAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoThreadSafetyAnalysisAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoThrowAttr::NoThrowAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoThrowAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoThrowAttr)
// 1: NoThrowAttr::Clone
std::string_view NoThrowAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoThrowAttr *>(u.NoThrowAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoThrowAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoUniqueAddressAttr::NoUniqueAddressAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoUniqueAddressAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
// 1: NoUniqueAddressAttr::Clone
std::string_view NoUniqueAddressAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoUniqueAddressAttr *>(u.NoUniqueAddressAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoUniqueAddressAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NonNullAttr::NonNullAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NonNullAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NonNullAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, NonNullAttr)
// 0: NonNullAttr::Arguments
// 0: NonNullAttr::
// 0: NonNullAttr::
// 0: NonNullAttr::
// 1: NonNullAttr::Clone
std::string_view NonNullAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NonNullAttr *>(u.NonNullAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NonNullAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 1: NonNullAttr::IsNonNull
NotTailCalledAttr::NotTailCalledAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NotTailCalledAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NotTailCalledAttr)
// 1: NotTailCalledAttr::Clone
std::string_view NotTailCalledAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NotTailCalledAttr *>(u.NotTailCalledAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NotTailCalledAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OMPAllocateDeclAttr::OMPAllocateDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPAllocateDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPAllocateDeclAttr)
// 1: OMPAllocateDeclAttr::Clone
::pasta::Expr OMPAllocateDeclAttr::Alignment(void) const noexcept {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getAlignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAllocateDeclAttr::Alignment can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPAllocateDeclAttr::Allocator(void) const noexcept {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getAllocator();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAllocateDeclAttr::Allocator can return nullptr!");
  __builtin_unreachable();
}

enum OMPAllocateDeclAttrAllocatorTypeTy OMPAllocateDeclAttr::AllocatorType(void) const noexcept {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getAllocatorType();
  return static_cast<::pasta::OMPAllocateDeclAttrAllocatorTypeTy>(val);
  __builtin_unreachable();
}

std::string_view OMPAllocateDeclAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPAllocateDeclAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OMPCaptureKindAttr::OMPCaptureKindAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPCaptureKindAttr)
// 1: OMPCaptureKindAttr::Clone
// 0: OMPCaptureKindAttr::CaptureKind
uint32_t OMPCaptureKindAttr::CaptureKindValue(void) const noexcept {
  auto &self = *const_cast<clang::OMPCaptureKindAttr *>(u.OMPCaptureKindAttr);
  decltype(auto) val = self.getCaptureKindVal();
  return val;
  __builtin_unreachable();
}

std::string_view OMPCaptureKindAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPCaptureKindAttr *>(u.OMPCaptureKindAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPCaptureKindAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OMPCaptureNoInitAttr::OMPCaptureNoInitAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPCaptureNoInitAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPCaptureNoInitAttr)
// 1: OMPCaptureNoInitAttr::Clone
std::string_view OMPCaptureNoInitAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPCaptureNoInitAttr *>(u.OMPCaptureNoInitAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPCaptureNoInitAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OMPDeclareSimdDeclAttr::OMPDeclareSimdDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPDeclareSimdDeclAttr)
// 0: OMPDeclareSimdDeclAttr::Aligneds
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::Alignments
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 1: OMPDeclareSimdDeclAttr::Clone
enum OMPDeclareSimdDeclAttrBranchStateTy OMPDeclareSimdDeclAttr::BranchState(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareSimdDeclAttr *>(u.OMPDeclareSimdDeclAttr);
  decltype(auto) val = self.getBranchState();
  return static_cast<::pasta::OMPDeclareSimdDeclAttrBranchStateTy>(val);
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareSimdDeclAttr::Simdlen(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareSimdDeclAttr *>(u.OMPDeclareSimdDeclAttr);
  decltype(auto) val = self.getSimdlen();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareSimdDeclAttr::Simdlen can return nullptr!");
  __builtin_unreachable();
}

std::string_view OMPDeclareSimdDeclAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareSimdDeclAttr *>(u.OMPDeclareSimdDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPDeclareSimdDeclAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 0: OMPDeclareSimdDeclAttr::Linears
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::Modifiers
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::Steps
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::Uniforms
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
// 0: OMPDeclareSimdDeclAttr::
OMPDeclareTargetDeclAttr::OMPDeclareTargetDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPDeclareTargetDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPDeclareTargetDeclAttr)
// 1: OMPDeclareTargetDeclAttr::Clone
enum OMPDeclareTargetDeclAttrDevTypeTy OMPDeclareTargetDeclAttr::DevType(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getDevType();
  return static_cast<::pasta::OMPDeclareTargetDeclAttrDevTypeTy>(val);
  __builtin_unreachable();
}

bool OMPDeclareTargetDeclAttr::Indirect(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getIndirect();
  return val;
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareTargetDeclAttr::IndirectExpression(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getIndirectExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareTargetDeclAttr::IndirectExpression can return nullptr!");
  __builtin_unreachable();
}

uint32_t OMPDeclareTargetDeclAttr::Level(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getLevel();
  return val;
  __builtin_unreachable();
}

enum OMPDeclareTargetDeclAttrMapTypeTy OMPDeclareTargetDeclAttr::MapType(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getMapType();
  return static_cast<::pasta::OMPDeclareTargetDeclAttrMapTypeTy>(val);
  __builtin_unreachable();
}

std::string_view OMPDeclareTargetDeclAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPDeclareTargetDeclAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OMPDeclareVariantAttr::OMPDeclareVariantAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPDeclareVariantAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPDeclareVariantAttr)
// 0: OMPDeclareVariantAttr::AdjustArgumentsNeedDevicePointer
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::AdjustArgumentsNothing
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::AppendArguments
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::
// 0: OMPDeclareVariantAttr::
// 1: OMPDeclareVariantAttr::Clone
std::string_view OMPDeclareVariantAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareVariantAttr *>(u.OMPDeclareVariantAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPDeclareVariantAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 0: OMPDeclareVariantAttr::TraitInfos
::pasta::Expr OMPDeclareVariantAttr::VariantFuncReference(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareVariantAttr *>(u.OMPDeclareVariantAttr);
  decltype(auto) val = self.getVariantFuncRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareVariantAttr::VariantFuncReference can return nullptr!");
  __builtin_unreachable();
}

OMPReferencedVarAttr::OMPReferencedVarAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPReferencedVarAttr)
// 1: OMPReferencedVarAttr::Clone
::pasta::Expr OMPReferencedVarAttr::Reference(void) const noexcept {
  auto &self = *const_cast<clang::OMPReferencedVarAttr *>(u.OMPReferencedVarAttr);
  decltype(auto) val = self.getRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPReferencedVarAttr::Reference can return nullptr!");
  __builtin_unreachable();
}

std::string_view OMPReferencedVarAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPReferencedVarAttr *>(u.OMPReferencedVarAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPReferencedVarAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OMPThreadPrivateDeclAttr::OMPThreadPrivateDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPThreadPrivateDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPThreadPrivateDeclAttr)
// 1: OMPThreadPrivateDeclAttr::Clone
std::string_view OMPThreadPrivateDeclAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OMPThreadPrivateDeclAttr *>(u.OMPThreadPrivateDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPThreadPrivateDeclAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OSConsumedAttr::OSConsumedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, OSConsumedAttr)
// 1: OSConsumedAttr::Clone
std::string_view OSConsumedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OSConsumedAttr *>(u.OSConsumedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSConsumedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OSConsumesThisAttr::OSConsumesThisAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSConsumesThisAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSConsumesThisAttr)
// 1: OSConsumesThisAttr::Clone
std::string_view OSConsumesThisAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OSConsumesThisAttr *>(u.OSConsumesThisAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSConsumesThisAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OSReturnsNotRetainedAttr::OSReturnsNotRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsNotRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsNotRetainedAttr)
// 1: OSReturnsNotRetainedAttr::Clone
std::string_view OSReturnsNotRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OSReturnsNotRetainedAttr *>(u.OSReturnsNotRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsNotRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OSReturnsRetainedAttr::OSReturnsRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedAttr)
// 1: OSReturnsRetainedAttr::Clone
std::string_view OSReturnsRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OSReturnsRetainedAttr *>(u.OSReturnsRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OSReturnsRetainedOnNonZeroAttr::OSReturnsRetainedOnNonZeroAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsRetainedOnNonZeroAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedOnNonZeroAttr)
// 1: OSReturnsRetainedOnNonZeroAttr::Clone
std::string_view OSReturnsRetainedOnNonZeroAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OSReturnsRetainedOnNonZeroAttr *>(u.OSReturnsRetainedOnNonZeroAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsRetainedOnNonZeroAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OSReturnsRetainedOnZeroAttr::OSReturnsRetainedOnZeroAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsRetainedOnZeroAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedOnZeroAttr)
// 1: OSReturnsRetainedOnZeroAttr::Clone
std::string_view OSReturnsRetainedOnZeroAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OSReturnsRetainedOnZeroAttr *>(u.OSReturnsRetainedOnZeroAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsRetainedOnZeroAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCBoxableAttr::ObjCBoxableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBoxableAttr)
// 1: ObjCBoxableAttr::Clone
std::string_view ObjCBoxableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCBoxableAttr *>(u.ObjCBoxableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBoxableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCBridgeAttr::ObjCBridgeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBridgeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCBridgeAttr)
// 1: ObjCBridgeAttr::Clone
// 0: ObjCBridgeAttr::BridgedType
std::string_view ObjCBridgeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCBridgeAttr *>(u.ObjCBridgeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBridgeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCBridgeMutableAttr::ObjCBridgeMutableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBridgeMutableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCBridgeMutableAttr)
// 1: ObjCBridgeMutableAttr::Clone
// 0: ObjCBridgeMutableAttr::BridgedType
std::string_view ObjCBridgeMutableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCBridgeMutableAttr *>(u.ObjCBridgeMutableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBridgeMutableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCBridgeRelatedAttr::ObjCBridgeRelatedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBridgeRelatedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCBridgeRelatedAttr)
// 1: ObjCBridgeRelatedAttr::Clone
// 0: ObjCBridgeRelatedAttr::ClassMethod
// 0: ObjCBridgeRelatedAttr::InstanceMethod
// 0: ObjCBridgeRelatedAttr::RelatedClass
std::string_view ObjCBridgeRelatedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCBridgeRelatedAttr *>(u.ObjCBridgeRelatedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBridgeRelatedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCClassStubAttr::ObjCClassStubAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCClassStubAttr)
// 1: ObjCClassStubAttr::Clone
std::string_view ObjCClassStubAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCClassStubAttr *>(u.ObjCClassStubAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCClassStubAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCDesignatedInitializerAttr::ObjCDesignatedInitializerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCDesignatedInitializerAttr)
// 1: ObjCDesignatedInitializerAttr::Clone
std::string_view ObjCDesignatedInitializerAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCDesignatedInitializerAttr *>(u.ObjCDesignatedInitializerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCDesignatedInitializerAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCDirectAttr::ObjCDirectAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCDirectAttr)
// 1: ObjCDirectAttr::Clone
std::string_view ObjCDirectAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCDirectAttr *>(u.ObjCDirectAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCDirectAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCDirectMembersAttr::ObjCDirectMembersAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCDirectMembersAttr)
// 1: ObjCDirectMembersAttr::Clone
std::string_view ObjCDirectMembersAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCDirectMembersAttr *>(u.ObjCDirectMembersAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCDirectMembersAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCExceptionAttr::ObjCExceptionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCExceptionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCExceptionAttr)
// 1: ObjCExceptionAttr::Clone
std::string_view ObjCExceptionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCExceptionAttr *>(u.ObjCExceptionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCExceptionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCExplicitProtocolImplAttr::ObjCExplicitProtocolImplAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCExplicitProtocolImplAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCExplicitProtocolImplAttr)
// 1: ObjCExplicitProtocolImplAttr::Clone
std::string_view ObjCExplicitProtocolImplAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCExplicitProtocolImplAttr *>(u.ObjCExplicitProtocolImplAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCExplicitProtocolImplAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCExternallyRetainedAttr::ObjCExternallyRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCExternallyRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCExternallyRetainedAttr)
// 1: ObjCExternallyRetainedAttr::Clone
std::string_view ObjCExternallyRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCExternallyRetainedAttr *>(u.ObjCExternallyRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCExternallyRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCIndependentClassAttr::ObjCIndependentClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCIndependentClassAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCIndependentClassAttr)
// 1: ObjCIndependentClassAttr::Clone
std::string_view ObjCIndependentClassAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIndependentClassAttr *>(u.ObjCIndependentClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCIndependentClassAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCMethodFamilyAttr::ObjCMethodFamilyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCMethodFamilyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCMethodFamilyAttr)
// 1: ObjCMethodFamilyAttr::Clone
enum ObjCMethodFamilyAttrFamilyKind ObjCMethodFamilyAttr::Family(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodFamilyAttr *>(u.ObjCMethodFamilyAttr);
  decltype(auto) val = self.getFamily();
  return static_cast<::pasta::ObjCMethodFamilyAttrFamilyKind>(val);
  __builtin_unreachable();
}

std::string_view ObjCMethodFamilyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodFamilyAttr *>(u.ObjCMethodFamilyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCMethodFamilyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCNSObjectAttr::ObjCNSObjectAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCNSObjectAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCNSObjectAttr)
// 1: ObjCNSObjectAttr::Clone
std::string_view ObjCNSObjectAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCNSObjectAttr *>(u.ObjCNSObjectAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCNSObjectAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCNonLazyClassAttr::ObjCNonLazyClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCNonLazyClassAttr)
// 1: ObjCNonLazyClassAttr::Clone
std::string_view ObjCNonLazyClassAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCNonLazyClassAttr *>(u.ObjCNonLazyClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCNonLazyClassAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCNonRuntimeProtocolAttr::ObjCNonRuntimeProtocolAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCNonRuntimeProtocolAttr)
// 1: ObjCNonRuntimeProtocolAttr::Clone
std::string_view ObjCNonRuntimeProtocolAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCNonRuntimeProtocolAttr *>(u.ObjCNonRuntimeProtocolAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCNonRuntimeProtocolAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCOwnershipAttr::ObjCOwnershipAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCOwnershipAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCOwnershipAttr)
// 1: ObjCOwnershipAttr::Clone
// 0: ObjCOwnershipAttr::Kind
std::string_view ObjCOwnershipAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCOwnershipAttr *>(u.ObjCOwnershipAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCOwnershipAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCPreciseLifetimeAttr::ObjCPreciseLifetimeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCPreciseLifetimeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCPreciseLifetimeAttr)
// 1: ObjCPreciseLifetimeAttr::Clone
std::string_view ObjCPreciseLifetimeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPreciseLifetimeAttr *>(u.ObjCPreciseLifetimeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCPreciseLifetimeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCRequiresPropertyDefsAttr::ObjCRequiresPropertyDefsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRequiresPropertyDefsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCRequiresPropertyDefsAttr)
// 1: ObjCRequiresPropertyDefsAttr::Clone
std::string_view ObjCRequiresPropertyDefsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRequiresPropertyDefsAttr *>(u.ObjCRequiresPropertyDefsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRequiresPropertyDefsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCRequiresSuperAttr::ObjCRequiresSuperAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRequiresSuperAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCRequiresSuperAttr)
// 1: ObjCRequiresSuperAttr::Clone
std::string_view ObjCRequiresSuperAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRequiresSuperAttr *>(u.ObjCRequiresSuperAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRequiresSuperAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCReturnsInnerPointerAttr::ObjCReturnsInnerPointerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCReturnsInnerPointerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCReturnsInnerPointerAttr)
// 1: ObjCReturnsInnerPointerAttr::Clone
std::string_view ObjCReturnsInnerPointerAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCReturnsInnerPointerAttr *>(u.ObjCReturnsInnerPointerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCReturnsInnerPointerAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCRootClassAttr::ObjCRootClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRootClassAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCRootClassAttr)
// 1: ObjCRootClassAttr::Clone
std::string_view ObjCRootClassAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRootClassAttr *>(u.ObjCRootClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRootClassAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCRuntimeNameAttr::ObjCRuntimeNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRuntimeNameAttr)
// 1: ObjCRuntimeNameAttr::Clone
std::string_view ObjCRuntimeNameAttr::MetadataName(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRuntimeNameAttr *>(u.ObjCRuntimeNameAttr);
  decltype(auto) val = self.getMetadataName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t ObjCRuntimeNameAttr::MetadataNameLength(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRuntimeNameAttr *>(u.ObjCRuntimeNameAttr);
  decltype(auto) val = self.getMetadataNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view ObjCRuntimeNameAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRuntimeNameAttr *>(u.ObjCRuntimeNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRuntimeNameAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCRuntimeVisibleAttr::ObjCRuntimeVisibleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRuntimeVisibleAttr)
// 1: ObjCRuntimeVisibleAttr::Clone
std::string_view ObjCRuntimeVisibleAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCRuntimeVisibleAttr *>(u.ObjCRuntimeVisibleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRuntimeVisibleAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCSubclassingRestrictedAttr::ObjCSubclassingRestrictedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCSubclassingRestrictedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCSubclassingRestrictedAttr)
// 1: ObjCSubclassingRestrictedAttr::Clone
std::string_view ObjCSubclassingRestrictedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCSubclassingRestrictedAttr *>(u.ObjCSubclassingRestrictedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCSubclassingRestrictedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLAccessAttr::OpenCLAccessAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLAccessAttr)
// 1: OpenCLAccessAttr::Clone
enum OpenCLAccessAttrSpelling OpenCLAccessAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLAccessAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OpenCLAccessAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLAccessAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool OpenCLAccessAttr::IsReadOnly(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.isReadOnly();
  return val;
  __builtin_unreachable();
}

bool OpenCLAccessAttr::IsReadWrite(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.isReadWrite();
  return val;
  __builtin_unreachable();
}

bool OpenCLAccessAttr::IsWriteOnly(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.isWriteOnly();
  return val;
  __builtin_unreachable();
}

OpenCLIntelReqdSubGroupSizeAttr::OpenCLIntelReqdSubGroupSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLIntelReqdSubGroupSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OpenCLIntelReqdSubGroupSizeAttr)
// 1: OpenCLIntelReqdSubGroupSizeAttr::Clone
std::string_view OpenCLIntelReqdSubGroupSizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLIntelReqdSubGroupSizeAttr *>(u.OpenCLIntelReqdSubGroupSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLIntelReqdSubGroupSizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t OpenCLIntelReqdSubGroupSizeAttr::SubGroupSize(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLIntelReqdSubGroupSizeAttr *>(u.OpenCLIntelReqdSubGroupSizeAttr);
  decltype(auto) val = self.getSubGroupSize();
  return val;
  __builtin_unreachable();
}

OpenCLKernelAttr::OpenCLKernelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLKernelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OpenCLKernelAttr)
// 1: OpenCLKernelAttr::Clone
std::string_view OpenCLKernelAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLKernelAttr *>(u.OpenCLKernelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLKernelAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OptimizeNoneAttr::OptimizeNoneAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OptimizeNoneAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OptimizeNoneAttr)
// 1: OptimizeNoneAttr::Clone
std::string_view OptimizeNoneAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OptimizeNoneAttr *>(u.OptimizeNoneAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OptimizeNoneAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OverloadableAttr::OverloadableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OverloadableAttr)
// 1: OverloadableAttr::Clone
std::string_view OverloadableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OverloadableAttr *>(u.OverloadableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OverloadableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OverrideAttr::OverrideAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OverrideAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OverrideAttr)
// 1: OverrideAttr::Clone
std::string_view OverrideAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OverrideAttr *>(u.OverrideAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OverrideAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OwnerAttr::OwnerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OwnerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OwnerAttr)
// 1: OwnerAttr::Clone
::pasta::Type OwnerAttr::DerefType(void) const noexcept {
  auto &self = *const_cast<clang::OwnerAttr *>(u.OwnerAttr);
  decltype(auto) val = self.getDerefType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type OwnerAttr::DerefTypeToken(void) const noexcept {
  auto &self = *const_cast<clang::OwnerAttr *>(u.OwnerAttr);
  decltype(auto) val = self.getDerefTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "OwnerAttr::DerefTypeToken can return nullptr!");
  __builtin_unreachable();
}

std::string_view OwnerAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OwnerAttr *>(u.OwnerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OwnerAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OwnershipAttr::OwnershipAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OwnershipAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OwnershipAttr)
// 0: OwnershipAttr::Arguments
// 0: OwnershipAttr::
// 0: OwnershipAttr::
// 0: OwnershipAttr::
// 1: OwnershipAttr::Clone
// 0: OwnershipAttr::Module
enum OwnershipAttrOwnershipKind OwnershipAttr::OwnKind(void) const noexcept {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.getOwnKind();
  return static_cast<::pasta::OwnershipAttrOwnershipKind>(val);
  __builtin_unreachable();
}

enum OwnershipAttrSpelling OwnershipAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OwnershipAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OwnershipAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OwnershipAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool OwnershipAttr::IsHolds(void) const noexcept {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.isHolds();
  return val;
  __builtin_unreachable();
}

bool OwnershipAttr::IsReturns(void) const noexcept {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.isReturns();
  return val;
  __builtin_unreachable();
}

bool OwnershipAttr::IsTakes(void) const noexcept {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.isTakes();
  return val;
  __builtin_unreachable();
}

PackedAttr::PackedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PackedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PackedAttr)
// 1: PackedAttr::Clone
std::string_view PackedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PackedAttr *>(u.PackedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PackedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ParamTypestateAttr::ParamTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ParamTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ParamTypestateAttr)
// 1: ParamTypestateAttr::Clone
enum ParamTypestateAttrConsumedState ParamTypestateAttr::ParameterState(void) const noexcept {
  auto &self = *const_cast<clang::ParamTypestateAttr *>(u.ParamTypestateAttr);
  decltype(auto) val = self.getParamState();
  return static_cast<::pasta::ParamTypestateAttrConsumedState>(val);
  __builtin_unreachable();
}

std::string_view ParamTypestateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ParamTypestateAttr *>(u.ParamTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ParamTypestateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ParameterABIAttr::ParameterABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ParameterABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ParameterABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, ParameterABIAttr)
PASTA_DEFINE_DERIVED_OPERATORS(ParameterABIAttr, SwiftAsyncContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(ParameterABIAttr, SwiftContextAttr)
PASTA_DEFINE_DERIVED_OPERATORS(ParameterABIAttr, SwiftErrorResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(ParameterABIAttr, SwiftIndirectResultAttr)
enum ParameterABI ParameterABIAttr::ABI(void) const noexcept {
  auto &self = *const_cast<clang::ParameterABIAttr *>(u.ParameterABIAttr);
  decltype(auto) val = self.getABI();
  return static_cast<::pasta::ParameterABI>(val);
  __builtin_unreachable();
}

PascalAttr::PascalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PascalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PascalAttr)
// 1: PascalAttr::Clone
std::string_view PascalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PascalAttr *>(u.PascalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PascalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PassObjectSizeAttr::PassObjectSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PassObjectSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PassObjectSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, PassObjectSizeAttr)
// 1: PassObjectSizeAttr::Clone
enum PassObjectSizeAttrSpelling PassObjectSizeAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::PassObjectSizeAttr *>(u.PassObjectSizeAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::PassObjectSizeAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view PassObjectSizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PassObjectSizeAttr *>(u.PassObjectSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PassObjectSizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 0: PassObjectSizeAttr::Type
bool PassObjectSizeAttr::IsDynamic(void) const noexcept {
  auto &self = *const_cast<clang::PassObjectSizeAttr *>(u.PassObjectSizeAttr);
  decltype(auto) val = self.isDynamic();
  return val;
  __builtin_unreachable();
}

PatchableFunctionEntryAttr::PatchableFunctionEntryAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PatchableFunctionEntryAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PatchableFunctionEntryAttr)
// 1: PatchableFunctionEntryAttr::Clone
uint32_t PatchableFunctionEntryAttr::Count(void) const noexcept {
  auto &self = *const_cast<clang::PatchableFunctionEntryAttr *>(u.PatchableFunctionEntryAttr);
  decltype(auto) val = self.getCount();
  return val;
  __builtin_unreachable();
}

// 0: PatchableFunctionEntryAttr::Offset
std::string_view PatchableFunctionEntryAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PatchableFunctionEntryAttr *>(u.PatchableFunctionEntryAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PatchableFunctionEntryAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PcsAttr::PcsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PcsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PcsAttr)
// 1: PcsAttr::Clone
enum PcsAttrPCSType PcsAttr::PCS(void) const noexcept {
  auto &self = *const_cast<clang::PcsAttr *>(u.PcsAttr);
  decltype(auto) val = self.getPCS();
  return static_cast<::pasta::PcsAttrPCSType>(val);
  __builtin_unreachable();
}

std::string_view PcsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PcsAttr *>(u.PcsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PcsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PointerAttr::PointerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PointerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PointerAttr)
// 1: PointerAttr::Clone
::pasta::Type PointerAttr::DerefType(void) const noexcept {
  auto &self = *const_cast<clang::PointerAttr *>(u.PointerAttr);
  decltype(auto) val = self.getDerefType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type PointerAttr::DerefTypeToken(void) const noexcept {
  auto &self = *const_cast<clang::PointerAttr *>(u.PointerAttr);
  decltype(auto) val = self.getDerefTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "PointerAttr::DerefTypeToken can return nullptr!");
  __builtin_unreachable();
}

std::string_view PointerAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PointerAttr *>(u.PointerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PointerAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PragmaClangBSSSectionAttr::PragmaClangBSSSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangBSSSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangBSSSectionAttr)
// 1: PragmaClangBSSSectionAttr::Clone
std::string_view PragmaClangBSSSectionAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangBSSSectionAttr *>(u.PragmaClangBSSSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t PragmaClangBSSSectionAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangBSSSectionAttr *>(u.PragmaClangBSSSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view PragmaClangBSSSectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangBSSSectionAttr *>(u.PragmaClangBSSSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangBSSSectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PragmaClangDataSectionAttr::PragmaClangDataSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangDataSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangDataSectionAttr)
// 1: PragmaClangDataSectionAttr::Clone
std::string_view PragmaClangDataSectionAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangDataSectionAttr *>(u.PragmaClangDataSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t PragmaClangDataSectionAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangDataSectionAttr *>(u.PragmaClangDataSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view PragmaClangDataSectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangDataSectionAttr *>(u.PragmaClangDataSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangDataSectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PragmaClangRelroSectionAttr::PragmaClangRelroSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangRelroSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangRelroSectionAttr)
// 1: PragmaClangRelroSectionAttr::Clone
std::string_view PragmaClangRelroSectionAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangRelroSectionAttr *>(u.PragmaClangRelroSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t PragmaClangRelroSectionAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangRelroSectionAttr *>(u.PragmaClangRelroSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view PragmaClangRelroSectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangRelroSectionAttr *>(u.PragmaClangRelroSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangRelroSectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PragmaClangRodataSectionAttr::PragmaClangRodataSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangRodataSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangRodataSectionAttr)
// 1: PragmaClangRodataSectionAttr::Clone
std::string_view PragmaClangRodataSectionAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangRodataSectionAttr *>(u.PragmaClangRodataSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t PragmaClangRodataSectionAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangRodataSectionAttr *>(u.PragmaClangRodataSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view PragmaClangRodataSectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangRodataSectionAttr *>(u.PragmaClangRodataSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangRodataSectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PragmaClangTextSectionAttr::PragmaClangTextSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangTextSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangTextSectionAttr)
// 1: PragmaClangTextSectionAttr::Clone
std::string_view PragmaClangTextSectionAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangTextSectionAttr *>(u.PragmaClangTextSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t PragmaClangTextSectionAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangTextSectionAttr *>(u.PragmaClangTextSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view PragmaClangTextSectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PragmaClangTextSectionAttr *>(u.PragmaClangTextSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangTextSectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PreferredNameAttr::PreferredNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PreferredNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PreferredNameAttr)
// 1: PreferredNameAttr::Clone
std::string_view PreferredNameAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PreferredNameAttr *>(u.PreferredNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PreferredNameAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type PreferredNameAttr::TypedefType(void) const noexcept {
  auto &self = *const_cast<clang::PreferredNameAttr *>(u.PreferredNameAttr);
  decltype(auto) val = self.getTypedefType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type PreferredNameAttr::TypedefTypeToken(void) const noexcept {
  auto &self = *const_cast<clang::PreferredNameAttr *>(u.PreferredNameAttr);
  decltype(auto) val = self.getTypedefTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "PreferredNameAttr::TypedefTypeToken can return nullptr!");
  __builtin_unreachable();
}

PreserveAllAttr::PreserveAllAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PreserveAllAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PreserveAllAttr)
// 1: PreserveAllAttr::Clone
std::string_view PreserveAllAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PreserveAllAttr *>(u.PreserveAllAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PreserveAllAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PreserveMostAttr::PreserveMostAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PreserveMostAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PreserveMostAttr)
// 1: PreserveMostAttr::Clone
std::string_view PreserveMostAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PreserveMostAttr *>(u.PreserveMostAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PreserveMostAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PtGuardedByAttr::PtGuardedByAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PtGuardedByAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PtGuardedByAttr)
// 1: PtGuardedByAttr::Clone
::pasta::Expr PtGuardedByAttr::Argument(void) const noexcept {
  auto &self = *const_cast<clang::PtGuardedByAttr *>(u.PtGuardedByAttr);
  decltype(auto) val = self.getArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "PtGuardedByAttr::Argument can return nullptr!");
  __builtin_unreachable();
}

std::string_view PtGuardedByAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PtGuardedByAttr *>(u.PtGuardedByAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PtGuardedByAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PtGuardedVarAttr::PtGuardedVarAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PtGuardedVarAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PtGuardedVarAttr)
// 1: PtGuardedVarAttr::Clone
std::string_view PtGuardedVarAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PtGuardedVarAttr *>(u.PtGuardedVarAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PtGuardedVarAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

PureAttr::PureAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PureAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PureAttr)
// 1: PureAttr::Clone
std::string_view PureAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::PureAttr *>(u.PureAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PureAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

RISCVInterruptAttr::RISCVInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RISCVInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RISCVInterruptAttr)
// 1: RISCVInterruptAttr::Clone
enum RISCVInterruptAttrInterruptType RISCVInterruptAttr::Interrupt(void) const noexcept {
  auto &self = *const_cast<clang::RISCVInterruptAttr *>(u.RISCVInterruptAttr);
  decltype(auto) val = self.getInterrupt();
  return static_cast<::pasta::RISCVInterruptAttrInterruptType>(val);
  __builtin_unreachable();
}

std::string_view RISCVInterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::RISCVInterruptAttr *>(u.RISCVInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RISCVInterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

RegCallAttr::RegCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RegCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RegCallAttr)
// 1: RegCallAttr::Clone
std::string_view RegCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::RegCallAttr *>(u.RegCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RegCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ReinitializesAttr::ReinitializesAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReinitializesAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReinitializesAttr)
// 1: ReinitializesAttr::Clone
std::string_view ReinitializesAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReinitializesAttr *>(u.ReinitializesAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReinitializesAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ReleaseCapabilityAttr::ReleaseCapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReleaseCapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReleaseCapabilityAttr)
// 0: ReleaseCapabilityAttr::Arguments
// 0: ReleaseCapabilityAttr::
// 0: ReleaseCapabilityAttr::
// 0: ReleaseCapabilityAttr::
// 1: ReleaseCapabilityAttr::Clone
enum ReleaseCapabilityAttrSpelling ReleaseCapabilityAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ReleaseCapabilityAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view ReleaseCapabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReleaseCapabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool ReleaseCapabilityAttr::IsGeneric(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.isGeneric();
  return val;
  __builtin_unreachable();
}

bool ReleaseCapabilityAttr::IsShared(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  __builtin_unreachable();
}

ReleaseHandleAttr::ReleaseHandleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReleaseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReleaseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, ReleaseHandleAttr)
// 1: ReleaseHandleAttr::Clone
std::string_view ReleaseHandleAttr::HandleType(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseHandleAttr *>(u.ReleaseHandleAttr);
  decltype(auto) val = self.getHandleType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t ReleaseHandleAttr::HandleTypeLength(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseHandleAttr *>(u.ReleaseHandleAttr);
  decltype(auto) val = self.getHandleTypeLength();
  return val;
  __builtin_unreachable();
}

std::string_view ReleaseHandleAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReleaseHandleAttr *>(u.ReleaseHandleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReleaseHandleAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

RenderScriptKernelAttr::RenderScriptKernelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RenderScriptKernelAttr)
// 1: RenderScriptKernelAttr::Clone
std::string_view RenderScriptKernelAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::RenderScriptKernelAttr *>(u.RenderScriptKernelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RenderScriptKernelAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ReqdWorkGroupSizeAttr::ReqdWorkGroupSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReqdWorkGroupSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReqdWorkGroupSizeAttr)
// 1: ReqdWorkGroupSizeAttr::Clone
std::string_view ReqdWorkGroupSizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReqdWorkGroupSizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t ReqdWorkGroupSizeAttr::XDim(void) const noexcept {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getXDim();
  return val;
  __builtin_unreachable();
}

uint32_t ReqdWorkGroupSizeAttr::YDim(void) const noexcept {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getYDim();
  return val;
  __builtin_unreachable();
}

uint32_t ReqdWorkGroupSizeAttr::ZDim(void) const noexcept {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getZDim();
  return val;
  __builtin_unreachable();
}

RequiresCapabilityAttr::RequiresCapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RequiresCapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RequiresCapabilityAttr)
// 0: RequiresCapabilityAttr::Arguments
// 0: RequiresCapabilityAttr::
// 0: RequiresCapabilityAttr::
// 0: RequiresCapabilityAttr::
// 1: RequiresCapabilityAttr::Clone
enum RequiresCapabilityAttrSpelling RequiresCapabilityAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::RequiresCapabilityAttr *>(u.RequiresCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::RequiresCapabilityAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view RequiresCapabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::RequiresCapabilityAttr *>(u.RequiresCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RequiresCapabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool RequiresCapabilityAttr::IsShared(void) const noexcept {
  auto &self = *const_cast<clang::RequiresCapabilityAttr *>(u.RequiresCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  __builtin_unreachable();
}

RestrictAttr::RestrictAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RestrictAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RestrictAttr)
// 1: RestrictAttr::Clone
enum RestrictAttrSpelling RestrictAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::RestrictAttr *>(u.RestrictAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::RestrictAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view RestrictAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::RestrictAttr *>(u.RestrictAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RestrictAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

RetainAttr::RetainAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RetainAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RetainAttr)
// 1: RetainAttr::Clone
std::string_view RetainAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::RetainAttr *>(u.RetainAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RetainAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ReturnTypestateAttr::ReturnTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReturnTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReturnTypestateAttr)
// 1: ReturnTypestateAttr::Clone
std::string_view ReturnTypestateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReturnTypestateAttr *>(u.ReturnTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReturnTypestateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

enum ReturnTypestateAttrConsumedState ReturnTypestateAttr::State(void) const noexcept {
  auto &self = *const_cast<clang::ReturnTypestateAttr *>(u.ReturnTypestateAttr);
  decltype(auto) val = self.getState();
  return static_cast<::pasta::ReturnTypestateAttrConsumedState>(val);
  __builtin_unreachable();
}

ReturnsNonNullAttr::ReturnsNonNullAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReturnsNonNullAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReturnsNonNullAttr)
// 1: ReturnsNonNullAttr::Clone
std::string_view ReturnsNonNullAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReturnsNonNullAttr *>(u.ReturnsNonNullAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReturnsNonNullAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ReturnsTwiceAttr::ReturnsTwiceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReturnsTwiceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReturnsTwiceAttr)
// 1: ReturnsTwiceAttr::Clone
std::string_view ReturnsTwiceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ReturnsTwiceAttr *>(u.ReturnsTwiceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReturnsTwiceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SYCLKernelAttr::SYCLKernelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SYCLKernelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SYCLKernelAttr)
// 1: SYCLKernelAttr::Clone
std::string_view SYCLKernelAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SYCLKernelAttr *>(u.SYCLKernelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SYCLKernelAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SYCLSpecialClassAttr::SYCLSpecialClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SYCLSpecialClassAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SYCLSpecialClassAttr)
// 1: SYCLSpecialClassAttr::Clone
std::string_view SYCLSpecialClassAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SYCLSpecialClassAttr *>(u.SYCLSpecialClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SYCLSpecialClassAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ScopedLockableAttr::ScopedLockableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ScopedLockableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ScopedLockableAttr)
// 1: ScopedLockableAttr::Clone
std::string_view ScopedLockableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ScopedLockableAttr *>(u.ScopedLockableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ScopedLockableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SectionAttr::SectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SectionAttr)
// 1: SectionAttr::Clone
std::string_view SectionAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t SectionAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

enum SectionAttrSpelling SectionAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::SectionAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view SectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SelectAnyAttr::SelectAnyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SelectAnyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SelectAnyAttr)
// 1: SelectAnyAttr::Clone
std::string_view SelectAnyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SelectAnyAttr *>(u.SelectAnyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SelectAnyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SentinelAttr::SentinelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SentinelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SentinelAttr)
// 1: SentinelAttr::Clone
// 0: SentinelAttr::NullPos
// 0: SentinelAttr::Sentinel
std::string_view SentinelAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SentinelAttr *>(u.SentinelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SentinelAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SetTypestateAttr::SetTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SetTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SetTypestateAttr)
// 1: SetTypestateAttr::Clone
enum SetTypestateAttrConsumedState SetTypestateAttr::NewState(void) const noexcept {
  auto &self = *const_cast<clang::SetTypestateAttr *>(u.SetTypestateAttr);
  decltype(auto) val = self.getNewState();
  return static_cast<::pasta::SetTypestateAttrConsumedState>(val);
  __builtin_unreachable();
}

std::string_view SetTypestateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SetTypestateAttr *>(u.SetTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SetTypestateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SharedTrylockFunctionAttr::SharedTrylockFunctionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SharedTrylockFunctionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SharedTrylockFunctionAttr)
// 0: SharedTrylockFunctionAttr::Arguments
// 0: SharedTrylockFunctionAttr::
// 0: SharedTrylockFunctionAttr::
// 0: SharedTrylockFunctionAttr::
// 1: SharedTrylockFunctionAttr::Clone
std::string_view SharedTrylockFunctionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SharedTrylockFunctionAttr *>(u.SharedTrylockFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SharedTrylockFunctionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr SharedTrylockFunctionAttr::SuccessValue(void) const noexcept {
  auto &self = *const_cast<clang::SharedTrylockFunctionAttr *>(u.SharedTrylockFunctionAttr);
  decltype(auto) val = self.getSuccessValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "SharedTrylockFunctionAttr::SuccessValue can return nullptr!");
  __builtin_unreachable();
}

SpeculativeLoadHardeningAttr::SpeculativeLoadHardeningAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SpeculativeLoadHardeningAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SpeculativeLoadHardeningAttr)
// 1: SpeculativeLoadHardeningAttr::Clone
std::string_view SpeculativeLoadHardeningAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SpeculativeLoadHardeningAttr *>(u.SpeculativeLoadHardeningAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SpeculativeLoadHardeningAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

StandaloneDebugAttr::StandaloneDebugAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StandaloneDebugAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, StandaloneDebugAttr)
// 1: StandaloneDebugAttr::Clone
std::string_view StandaloneDebugAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::StandaloneDebugAttr *>(u.StandaloneDebugAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StandaloneDebugAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

StdCallAttr::StdCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StdCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, StdCallAttr)
// 1: StdCallAttr::Clone
std::string_view StdCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::StdCallAttr *>(u.StdCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StdCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

StmtAttr::StmtAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StmtAttr)
PASTA_DEFINE_DERIVED_OPERATORS(StmtAttr, FallThroughAttr)
PASTA_DEFINE_DERIVED_OPERATORS(StmtAttr, LikelyAttr)
PASTA_DEFINE_DERIVED_OPERATORS(StmtAttr, MustTailAttr)
PASTA_DEFINE_DERIVED_OPERATORS(StmtAttr, OpenCLUnrollHintAttr)
PASTA_DEFINE_DERIVED_OPERATORS(StmtAttr, SuppressAttr)
PASTA_DEFINE_DERIVED_OPERATORS(StmtAttr, UnlikelyAttr)
StrictFPAttr::StrictFPAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StrictFPAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, StrictFPAttr)
// 1: StrictFPAttr::Clone
std::string_view StrictFPAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::StrictFPAttr *>(u.StrictFPAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StrictFPAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SuppressAttr::SuppressAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SuppressAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, SuppressAttr)
// 1: SuppressAttr::Clone
// 0: SuppressAttr::DiagnosticIdentifiers
// 0: SuppressAttr::
// 0: SuppressAttr::
// 0: SuppressAttr::
std::string_view SuppressAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SuppressAttr *>(u.SuppressAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SuppressAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftAsyncAttr::SwiftAsyncAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncAttr)
// 1: SwiftAsyncAttr::Clone
// 0: SwiftAsyncAttr::CompletionHandlerIndex
enum SwiftAsyncAttrKind SwiftAsyncAttr::Kind(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncAttr *>(u.SwiftAsyncAttr);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::SwiftAsyncAttrKind>(val);
  __builtin_unreachable();
}

std::string_view SwiftAsyncAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncAttr *>(u.SwiftAsyncAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftAsyncCallAttr::SwiftAsyncCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncCallAttr)
// 1: SwiftAsyncCallAttr::Clone
std::string_view SwiftAsyncCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncCallAttr *>(u.SwiftAsyncCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftAsyncContextAttr::SwiftAsyncContextAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : ParameterABIAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncContextAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncContextAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, SwiftAsyncContextAttr)
PASTA_DEFINE_BASE_OPERATORS(ParameterABIAttr, SwiftAsyncContextAttr)
// 1: SwiftAsyncContextAttr::Clone
std::string_view SwiftAsyncContextAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncContextAttr *>(u.SwiftAsyncContextAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncContextAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftAsyncErrorAttr::SwiftAsyncErrorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncErrorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncErrorAttr)
// 1: SwiftAsyncErrorAttr::Clone
enum SwiftAsyncErrorAttrConventionKind SwiftAsyncErrorAttr::Convention(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncErrorAttr *>(u.SwiftAsyncErrorAttr);
  decltype(auto) val = self.getConvention();
  return static_cast<::pasta::SwiftAsyncErrorAttrConventionKind>(val);
  __builtin_unreachable();
}

uint32_t SwiftAsyncErrorAttr::HandlerParameterIndex(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncErrorAttr *>(u.SwiftAsyncErrorAttr);
  decltype(auto) val = self.getHandlerParamIdx();
  return val;
  __builtin_unreachable();
}

std::string_view SwiftAsyncErrorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncErrorAttr *>(u.SwiftAsyncErrorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncErrorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftAsyncNameAttr::SwiftAsyncNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncNameAttr)
// 1: SwiftAsyncNameAttr::Clone
std::string_view SwiftAsyncNameAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncNameAttr *>(u.SwiftAsyncNameAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t SwiftAsyncNameAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncNameAttr *>(u.SwiftAsyncNameAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view SwiftAsyncNameAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAsyncNameAttr *>(u.SwiftAsyncNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncNameAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftAttrAttr::SwiftAttrAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAttrAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAttrAttr)
// 1: SwiftAttrAttr::Clone
std::string_view SwiftAttrAttr::Attribute(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAttrAttr *>(u.SwiftAttrAttr);
  decltype(auto) val = self.getAttribute();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t SwiftAttrAttr::AttributeLength(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAttrAttr *>(u.SwiftAttrAttr);
  decltype(auto) val = self.getAttributeLength();
  return val;
  __builtin_unreachable();
}

std::string_view SwiftAttrAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftAttrAttr *>(u.SwiftAttrAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAttrAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftBridgeAttr::SwiftBridgeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftBridgeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftBridgeAttr)
// 1: SwiftBridgeAttr::Clone
std::string_view SwiftBridgeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftBridgeAttr *>(u.SwiftBridgeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftBridgeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

std::string_view SwiftBridgeAttr::SwiftType(void) const noexcept {
  auto &self = *const_cast<clang::SwiftBridgeAttr *>(u.SwiftBridgeAttr);
  decltype(auto) val = self.getSwiftType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t SwiftBridgeAttr::SwiftTypeLength(void) const noexcept {
  auto &self = *const_cast<clang::SwiftBridgeAttr *>(u.SwiftBridgeAttr);
  decltype(auto) val = self.getSwiftTypeLength();
  return val;
  __builtin_unreachable();
}

SwiftBridgedTypedefAttr::SwiftBridgedTypedefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftBridgedTypedefAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftBridgedTypedefAttr)
// 1: SwiftBridgedTypedefAttr::Clone
std::string_view SwiftBridgedTypedefAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftBridgedTypedefAttr *>(u.SwiftBridgedTypedefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftBridgedTypedefAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftCallAttr::SwiftCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftCallAttr)
// 1: SwiftCallAttr::Clone
std::string_view SwiftCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftCallAttr *>(u.SwiftCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftContextAttr::SwiftContextAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : ParameterABIAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftContextAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftContextAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, SwiftContextAttr)
PASTA_DEFINE_BASE_OPERATORS(ParameterABIAttr, SwiftContextAttr)
// 1: SwiftContextAttr::Clone
std::string_view SwiftContextAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftContextAttr *>(u.SwiftContextAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftContextAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftErrorAttr::SwiftErrorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftErrorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftErrorAttr)
// 1: SwiftErrorAttr::Clone
enum SwiftErrorAttrConventionKind SwiftErrorAttr::Convention(void) const noexcept {
  auto &self = *const_cast<clang::SwiftErrorAttr *>(u.SwiftErrorAttr);
  decltype(auto) val = self.getConvention();
  return static_cast<::pasta::SwiftErrorAttrConventionKind>(val);
  __builtin_unreachable();
}

std::string_view SwiftErrorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftErrorAttr *>(u.SwiftErrorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftErrorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftErrorResultAttr::SwiftErrorResultAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : ParameterABIAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftErrorResultAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftErrorResultAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, SwiftErrorResultAttr)
PASTA_DEFINE_BASE_OPERATORS(ParameterABIAttr, SwiftErrorResultAttr)
// 1: SwiftErrorResultAttr::Clone
std::string_view SwiftErrorResultAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftErrorResultAttr *>(u.SwiftErrorResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftErrorResultAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftIndirectResultAttr::SwiftIndirectResultAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : ParameterABIAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftIndirectResultAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftIndirectResultAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, SwiftIndirectResultAttr)
PASTA_DEFINE_BASE_OPERATORS(ParameterABIAttr, SwiftIndirectResultAttr)
// 1: SwiftIndirectResultAttr::Clone
std::string_view SwiftIndirectResultAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftIndirectResultAttr *>(u.SwiftIndirectResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftIndirectResultAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftNameAttr::SwiftNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftNameAttr)
// 1: SwiftNameAttr::Clone
std::string_view SwiftNameAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::SwiftNameAttr *>(u.SwiftNameAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t SwiftNameAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::SwiftNameAttr *>(u.SwiftNameAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view SwiftNameAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftNameAttr *>(u.SwiftNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftNameAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftNewTypeAttr::SwiftNewTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftNewTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftNewTypeAttr)
// 1: SwiftNewTypeAttr::Clone
enum SwiftNewTypeAttrNewtypeKind SwiftNewTypeAttr::NewtypeKind(void) const noexcept {
  auto &self = *const_cast<clang::SwiftNewTypeAttr *>(u.SwiftNewTypeAttr);
  decltype(auto) val = self.getNewtypeKind();
  return static_cast<::pasta::SwiftNewTypeAttrNewtypeKind>(val);
  __builtin_unreachable();
}

enum SwiftNewTypeAttrSpelling SwiftNewTypeAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftNewTypeAttr *>(u.SwiftNewTypeAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::SwiftNewTypeAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view SwiftNewTypeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftNewTypeAttr *>(u.SwiftNewTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftNewTypeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftObjCMembersAttr::SwiftObjCMembersAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftObjCMembersAttr)
// 1: SwiftObjCMembersAttr::Clone
std::string_view SwiftObjCMembersAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftObjCMembersAttr *>(u.SwiftObjCMembersAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftObjCMembersAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SwiftPrivateAttr::SwiftPrivateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftPrivateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftPrivateAttr)
// 1: SwiftPrivateAttr::Clone
std::string_view SwiftPrivateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SwiftPrivateAttr *>(u.SwiftPrivateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftPrivateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SysVABIAttr::SysVABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SysVABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SysVABIAttr)
// 1: SysVABIAttr::Clone
std::string_view SysVABIAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SysVABIAttr *>(u.SysVABIAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SysVABIAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TLSModelAttr::TLSModelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TLSModelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TLSModelAttr)
// 1: TLSModelAttr::Clone
std::string_view TLSModelAttr::Model(void) const noexcept {
  auto &self = *const_cast<clang::TLSModelAttr *>(u.TLSModelAttr);
  decltype(auto) val = self.getModel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t TLSModelAttr::ModelLength(void) const noexcept {
  auto &self = *const_cast<clang::TLSModelAttr *>(u.TLSModelAttr);
  decltype(auto) val = self.getModelLength();
  return val;
  __builtin_unreachable();
}

std::string_view TLSModelAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TLSModelAttr *>(u.TLSModelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TLSModelAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TargetAttr::TargetAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TargetAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TargetAttr)
// 1: TargetAttr::Clone
std::string_view TargetAttr::Architecture(void) const noexcept {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getArchitecture();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

std::string_view TargetAttr::FeaturesString(void) const noexcept {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getFeaturesStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t TargetAttr::FeaturesStringLength(void) const noexcept {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getFeaturesStrLength();
  return val;
  __builtin_unreachable();
}

std::string_view TargetAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TargetAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool TargetAttr::IsDefaultVersion(void) const noexcept {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.isDefaultVersion();
  return val;
  __builtin_unreachable();
}

// 0: TargetAttr::Parse
TargetClonesAttr::TargetClonesAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TargetClonesAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TargetClonesAttr)
// 1: TargetClonesAttr::Clone
// 0: TargetClonesAttr::FeaturesStrings
// 0: TargetClonesAttr::
// 0: TargetClonesAttr::
// 0: TargetClonesAttr::
// 1: TargetClonesAttr::FeatureString
// 1: TargetClonesAttr::MangledIndex
std::string_view TargetClonesAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TargetClonesAttr *>(u.TargetClonesAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TargetClonesAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 1: TargetClonesAttr::IsFirstOfVersion
TestTypestateAttr::TestTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TestTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TestTypestateAttr)
// 1: TestTypestateAttr::Clone
std::string_view TestTypestateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TestTypestateAttr *>(u.TestTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TestTypestateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

enum TestTypestateAttrConsumedState TestTypestateAttr::TestState(void) const noexcept {
  auto &self = *const_cast<clang::TestTypestateAttr *>(u.TestTypestateAttr);
  decltype(auto) val = self.getTestState();
  return static_cast<::pasta::TestTypestateAttrConsumedState>(val);
  __builtin_unreachable();
}

ThisCallAttr::ThisCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ThisCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ThisCallAttr)
// 1: ThisCallAttr::Clone
std::string_view ThisCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ThisCallAttr *>(u.ThisCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ThisCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ThreadAttr::ThreadAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ThreadAttr)
// 1: ThreadAttr::Clone
std::string_view ThreadAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ThreadAttr *>(u.ThreadAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ThreadAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TransparentUnionAttr::TransparentUnionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TransparentUnionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TransparentUnionAttr)
// 1: TransparentUnionAttr::Clone
std::string_view TransparentUnionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TransparentUnionAttr *>(u.TransparentUnionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TransparentUnionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TrivialABIAttr::TrivialABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TrivialABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TrivialABIAttr)
// 1: TrivialABIAttr::Clone
std::string_view TrivialABIAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TrivialABIAttr *>(u.TrivialABIAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TrivialABIAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TryAcquireCapabilityAttr::TryAcquireCapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TryAcquireCapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TryAcquireCapabilityAttr)
// 0: TryAcquireCapabilityAttr::Arguments
// 0: TryAcquireCapabilityAttr::
// 0: TryAcquireCapabilityAttr::
// 0: TryAcquireCapabilityAttr::
// 1: TryAcquireCapabilityAttr::Clone
enum TryAcquireCapabilityAttrSpelling TryAcquireCapabilityAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::TryAcquireCapabilityAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view TryAcquireCapabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TryAcquireCapabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr TryAcquireCapabilityAttr::SuccessValue(void) const noexcept {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.getSuccessValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "TryAcquireCapabilityAttr::SuccessValue can return nullptr!");
  __builtin_unreachable();
}

bool TryAcquireCapabilityAttr::IsShared(void) const noexcept {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  __builtin_unreachable();
}

TypeAttr::TypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, AddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, BTFTypeTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, CmseNSCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, NoDerefAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, ObjCGCAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, ObjCInertUnsafeUnretainedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, ObjCKindOfAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLConstantAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLGenericAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLGlobalAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLGlobalDeviceAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLGlobalHostAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLLocalAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, OpenCLPrivateAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, Ptr32Attr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, Ptr64Attr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, SPtrAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, TypeNonNullAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, TypeNullUnspecifiedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, TypeNullableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, TypeNullableResultAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, UPtrAttr)
TypeNonNullAttr::TypeNonNullAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNonNullAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNonNullAttr)
// 1: TypeNonNullAttr::Clone
std::string_view TypeNonNullAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TypeNonNullAttr *>(u.TypeNonNullAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNonNullAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TypeNullUnspecifiedAttr::TypeNullUnspecifiedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNullUnspecifiedAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNullUnspecifiedAttr)
// 1: TypeNullUnspecifiedAttr::Clone
std::string_view TypeNullUnspecifiedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TypeNullUnspecifiedAttr *>(u.TypeNullUnspecifiedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNullUnspecifiedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TypeNullableAttr::TypeNullableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNullableAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNullableAttr)
// 1: TypeNullableAttr::Clone
std::string_view TypeNullableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TypeNullableAttr *>(u.TypeNullableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNullableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TypeNullableResultAttr::TypeNullableResultAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNullableResultAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNullableResultAttr)
// 1: TypeNullableResultAttr::Clone
std::string_view TypeNullableResultAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TypeNullableResultAttr *>(u.TypeNullableResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNullableResultAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TypeTagForDatatypeAttr::TypeTagForDatatypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeTagForDatatypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TypeTagForDatatypeAttr)
// 1: TypeTagForDatatypeAttr::Clone
// 0: TypeTagForDatatypeAttr::ArgumentKind
bool TypeTagForDatatypeAttr::LayoutCompatible(void) const noexcept {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getLayoutCompatible();
  return val;
  __builtin_unreachable();
}

::pasta::Type TypeTagForDatatypeAttr::MatchingCType(void) const noexcept {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getMatchingCType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type TypeTagForDatatypeAttr::MatchingCTypeToken(void) const noexcept {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getMatchingCTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "TypeTagForDatatypeAttr::MatchingCTypeToken can return nullptr!");
  __builtin_unreachable();
}

bool TypeTagForDatatypeAttr::MustBeNull(void) const noexcept {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getMustBeNull();
  return val;
  __builtin_unreachable();
}

std::string_view TypeTagForDatatypeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeTagForDatatypeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

TypeVisibilityAttr::TypeVisibilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeVisibilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TypeVisibilityAttr)
// 1: TypeVisibilityAttr::Clone
std::string_view TypeVisibilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::TypeVisibilityAttr *>(u.TypeVisibilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeVisibilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

enum TypeVisibilityAttrVisibilityType TypeVisibilityAttr::Visibility(void) const noexcept {
  auto &self = *const_cast<clang::TypeVisibilityAttr *>(u.TypeVisibilityAttr);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::TypeVisibilityAttrVisibilityType>(val);
  __builtin_unreachable();
}

UPtrAttr::UPtrAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UPtrAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, UPtrAttr)
// 1: UPtrAttr::Clone
std::string_view UPtrAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UPtrAttr *>(u.UPtrAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UPtrAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UnavailableAttr::UnavailableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UnavailableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UnavailableAttr)
// 1: UnavailableAttr::Clone
enum UnavailableAttrImplicitReason UnavailableAttr::ImplicitReason(void) const noexcept {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getImplicitReason();
  return static_cast<::pasta::UnavailableAttrImplicitReason>(val);
  __builtin_unreachable();
}

std::string_view UnavailableAttr::Message(void) const noexcept {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t UnavailableAttr::MessageLength(void) const noexcept {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  __builtin_unreachable();
}

std::string_view UnavailableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UnavailableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UninitializedAttr::UninitializedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UninitializedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UninitializedAttr)
// 1: UninitializedAttr::Clone
std::string_view UninitializedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UninitializedAttr *>(u.UninitializedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UninitializedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UnlikelyAttr::UnlikelyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UnlikelyAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, UnlikelyAttr)
// 1: UnlikelyAttr::Clone
std::string_view UnlikelyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UnlikelyAttr *>(u.UnlikelyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UnlikelyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UnusedAttr::UnusedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UnusedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UnusedAttr)
// 1: UnusedAttr::Clone
enum UnusedAttrSpelling UnusedAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::UnusedAttr *>(u.UnusedAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::UnusedAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view UnusedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UnusedAttr *>(u.UnusedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UnusedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UseHandleAttr::UseHandleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, UseHandleAttr)
// 1: UseHandleAttr::Clone
std::string_view UseHandleAttr::HandleType(void) const noexcept {
  auto &self = *const_cast<clang::UseHandleAttr *>(u.UseHandleAttr);
  decltype(auto) val = self.getHandleType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t UseHandleAttr::HandleTypeLength(void) const noexcept {
  auto &self = *const_cast<clang::UseHandleAttr *>(u.UseHandleAttr);
  decltype(auto) val = self.getHandleTypeLength();
  return val;
  __builtin_unreachable();
}

std::string_view UseHandleAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UseHandleAttr *>(u.UseHandleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UseHandleAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UsedAttr::UsedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UsedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UsedAttr)
// 1: UsedAttr::Clone
std::string_view UsedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UsedAttr *>(u.UsedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UsedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UsingIfExistsAttr::UsingIfExistsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UsingIfExistsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UsingIfExistsAttr)
// 1: UsingIfExistsAttr::Clone
std::string_view UsingIfExistsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UsingIfExistsAttr *>(u.UsingIfExistsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UsingIfExistsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

UuidAttr::UuidAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UuidAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UuidAttr)
// 1: UuidAttr::Clone
std::string_view UuidAttr::Guid(void) const noexcept {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getGuid();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

::pasta::MSGuidDecl UuidAttr::GuidDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getGuidDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::MSGuidDecl>(ast, val);
  }
  assert(false && "UuidAttr::GuidDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t UuidAttr::GuidLength(void) const noexcept {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getGuidLength();
  return val;
  __builtin_unreachable();
}

std::string_view UuidAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UuidAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

VecReturnAttr::VecReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VecReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VecReturnAttr)
// 1: VecReturnAttr::Clone
std::string_view VecReturnAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::VecReturnAttr *>(u.VecReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VecReturnAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

VecTypeHintAttr::VecTypeHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VecTypeHintAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VecTypeHintAttr)
// 1: VecTypeHintAttr::Clone
std::string_view VecTypeHintAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::VecTypeHintAttr *>(u.VecTypeHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VecTypeHintAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type VecTypeHintAttr::TypeHint(void) const noexcept {
  auto &self = *const_cast<clang::VecTypeHintAttr *>(u.VecTypeHintAttr);
  decltype(auto) val = self.getTypeHint();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type VecTypeHintAttr::TypeHintToken(void) const noexcept {
  auto &self = *const_cast<clang::VecTypeHintAttr *>(u.VecTypeHintAttr);
  decltype(auto) val = self.getTypeHintLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "VecTypeHintAttr::TypeHintToken can return nullptr!");
  __builtin_unreachable();
}

VectorCallAttr::VectorCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VectorCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VectorCallAttr)
// 1: VectorCallAttr::Clone
std::string_view VectorCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::VectorCallAttr *>(u.VectorCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VectorCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

VisibilityAttr::VisibilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VisibilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VisibilityAttr)
// 1: VisibilityAttr::Clone
std::string_view VisibilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::VisibilityAttr *>(u.VisibilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VisibilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

enum VisibilityAttrVisibilityType VisibilityAttr::Visibility(void) const noexcept {
  auto &self = *const_cast<clang::VisibilityAttr *>(u.VisibilityAttr);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::VisibilityAttrVisibilityType>(val);
  __builtin_unreachable();
}

WarnUnusedAttr::WarnUnusedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WarnUnusedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WarnUnusedAttr)
// 1: WarnUnusedAttr::Clone
std::string_view WarnUnusedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WarnUnusedAttr *>(u.WarnUnusedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WarnUnusedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WarnUnusedResultAttr::WarnUnusedResultAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WarnUnusedResultAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WarnUnusedResultAttr)
bool WarnUnusedResultAttr::IsCXX11NoDiscard(void) const noexcept {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.IsCXX11NoDiscard();
  return val;
  __builtin_unreachable();
}

// 1: WarnUnusedResultAttr::Clone
std::string_view WarnUnusedResultAttr::Message(void) const noexcept {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t WarnUnusedResultAttr::MessageLength(void) const noexcept {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  __builtin_unreachable();
}

enum WarnUnusedResultAttrSpelling WarnUnusedResultAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::WarnUnusedResultAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view WarnUnusedResultAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WarnUnusedResultAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WeakAttr::WeakAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WeakAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WeakAttr)
// 1: WeakAttr::Clone
std::string_view WeakAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WeakAttr *>(u.WeakAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WeakAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WeakImportAttr::WeakImportAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WeakImportAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WeakImportAttr)
// 1: WeakImportAttr::Clone
std::string_view WeakImportAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WeakImportAttr *>(u.WeakImportAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WeakImportAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WeakRefAttr::WeakRefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WeakRefAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WeakRefAttr)
// 1: WeakRefAttr::Clone
std::string_view WeakRefAttr::Aliasee(void) const noexcept {
  auto &self = *const_cast<clang::WeakRefAttr *>(u.WeakRefAttr);
  decltype(auto) val = self.getAliasee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t WeakRefAttr::AliaseeLength(void) const noexcept {
  auto &self = *const_cast<clang::WeakRefAttr *>(u.WeakRefAttr);
  decltype(auto) val = self.getAliaseeLength();
  return val;
  __builtin_unreachable();
}

std::string_view WeakRefAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WeakRefAttr *>(u.WeakRefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WeakRefAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WebAssemblyExportNameAttr::WebAssemblyExportNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WebAssemblyExportNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WebAssemblyExportNameAttr)
// 1: WebAssemblyExportNameAttr::Clone
std::string_view WebAssemblyExportNameAttr::ExportName(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyExportNameAttr *>(u.WebAssemblyExportNameAttr);
  decltype(auto) val = self.getExportName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t WebAssemblyExportNameAttr::ExportNameLength(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyExportNameAttr *>(u.WebAssemblyExportNameAttr);
  decltype(auto) val = self.getExportNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view WebAssemblyExportNameAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyExportNameAttr *>(u.WebAssemblyExportNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WebAssemblyExportNameAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WebAssemblyImportModuleAttr::WebAssemblyImportModuleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WebAssemblyImportModuleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WebAssemblyImportModuleAttr)
// 1: WebAssemblyImportModuleAttr::Clone
std::string_view WebAssemblyImportModuleAttr::ImportModule(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyImportModuleAttr *>(u.WebAssemblyImportModuleAttr);
  decltype(auto) val = self.getImportModule();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t WebAssemblyImportModuleAttr::ImportModuleLength(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyImportModuleAttr *>(u.WebAssemblyImportModuleAttr);
  decltype(auto) val = self.getImportModuleLength();
  return val;
  __builtin_unreachable();
}

std::string_view WebAssemblyImportModuleAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyImportModuleAttr *>(u.WebAssemblyImportModuleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WebAssemblyImportModuleAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WebAssemblyImportNameAttr::WebAssemblyImportNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WebAssemblyImportNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WebAssemblyImportNameAttr)
// 1: WebAssemblyImportNameAttr::Clone
std::string_view WebAssemblyImportNameAttr::ImportName(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyImportNameAttr *>(u.WebAssemblyImportNameAttr);
  decltype(auto) val = self.getImportName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t WebAssemblyImportNameAttr::ImportNameLength(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyImportNameAttr *>(u.WebAssemblyImportNameAttr);
  decltype(auto) val = self.getImportNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view WebAssemblyImportNameAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WebAssemblyImportNameAttr *>(u.WebAssemblyImportNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WebAssemblyImportNameAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

WorkGroupSizeHintAttr::WorkGroupSizeHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WorkGroupSizeHintAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WorkGroupSizeHintAttr)
// 1: WorkGroupSizeHintAttr::Clone
std::string_view WorkGroupSizeHintAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WorkGroupSizeHintAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t WorkGroupSizeHintAttr::XDim(void) const noexcept {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getXDim();
  return val;
  __builtin_unreachable();
}

uint32_t WorkGroupSizeHintAttr::YDim(void) const noexcept {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getYDim();
  return val;
  __builtin_unreachable();
}

uint32_t WorkGroupSizeHintAttr::ZDim(void) const noexcept {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getZDim();
  return val;
  __builtin_unreachable();
}

X86ForceAlignArgPointerAttr::X86ForceAlignArgPointerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, X86ForceAlignArgPointerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, X86ForceAlignArgPointerAttr)
// 1: X86ForceAlignArgPointerAttr::Clone
std::string_view X86ForceAlignArgPointerAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::X86ForceAlignArgPointerAttr *>(u.X86ForceAlignArgPointerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "X86ForceAlignArgPointerAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

XRayInstrumentAttr::XRayInstrumentAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, XRayInstrumentAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, XRayInstrumentAttr)
bool XRayInstrumentAttr::AlwaysXRayInstrument(void) const noexcept {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.alwaysXRayInstrument();
  return val;
  __builtin_unreachable();
}

// 1: XRayInstrumentAttr::Clone
enum XRayInstrumentAttrSpelling XRayInstrumentAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::XRayInstrumentAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view XRayInstrumentAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "XRayInstrumentAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool XRayInstrumentAttr::NeverXRayInstrument(void) const noexcept {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.neverXRayInstrument();
  return val;
  __builtin_unreachable();
}

XRayLogArgsAttr::XRayLogArgsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, XRayLogArgsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, XRayLogArgsAttr)
// 1: XRayLogArgsAttr::Clone
uint32_t XRayLogArgsAttr::ArgumentCount(void) const noexcept {
  auto &self = *const_cast<clang::XRayLogArgsAttr *>(u.XRayLogArgsAttr);
  decltype(auto) val = self.getArgumentCount();
  return val;
  __builtin_unreachable();
}

std::string_view XRayLogArgsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::XRayLogArgsAttr *>(u.XRayLogArgsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "XRayLogArgsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AArch64VectorPcsAttr::AArch64VectorPcsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AArch64VectorPcsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
// 1: AArch64VectorPcsAttr::Clone
std::string_view AArch64VectorPcsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AArch64VectorPcsAttr *>(u.AArch64VectorPcsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AArch64VectorPcsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AMDGPUFlatWorkGroupSizeAttr::AMDGPUFlatWorkGroupSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
// 1: AMDGPUFlatWorkGroupSizeAttr::Clone
::pasta::Expr AMDGPUFlatWorkGroupSizeAttr::Max(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUFlatWorkGroupSizeAttr *>(u.AMDGPUFlatWorkGroupSizeAttr);
  decltype(auto) val = self.getMax();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUFlatWorkGroupSizeAttr::Max can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AMDGPUFlatWorkGroupSizeAttr::Min(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUFlatWorkGroupSizeAttr *>(u.AMDGPUFlatWorkGroupSizeAttr);
  decltype(auto) val = self.getMin();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUFlatWorkGroupSizeAttr::Min can return nullptr!");
  __builtin_unreachable();
}

std::string_view AMDGPUFlatWorkGroupSizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUFlatWorkGroupSizeAttr *>(u.AMDGPUFlatWorkGroupSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUFlatWorkGroupSizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AMDGPUNumSGPRAttr::AMDGPUNumSGPRAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUNumSGPRAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUNumSGPRAttr)
// 1: AMDGPUNumSGPRAttr::Clone
uint32_t AMDGPUNumSGPRAttr::NumSGPR(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUNumSGPRAttr *>(u.AMDGPUNumSGPRAttr);
  decltype(auto) val = self.getNumSGPR();
  return val;
  __builtin_unreachable();
}

std::string_view AMDGPUNumSGPRAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUNumSGPRAttr *>(u.AMDGPUNumSGPRAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUNumSGPRAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AMDGPUNumVGPRAttr::AMDGPUNumVGPRAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUNumVGPRAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUNumVGPRAttr)
// 1: AMDGPUNumVGPRAttr::Clone
uint32_t AMDGPUNumVGPRAttr::NumVGPR(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUNumVGPRAttr *>(u.AMDGPUNumVGPRAttr);
  decltype(auto) val = self.getNumVGPR();
  return val;
  __builtin_unreachable();
}

std::string_view AMDGPUNumVGPRAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUNumVGPRAttr *>(u.AMDGPUNumVGPRAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUNumVGPRAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AMDGPUWavesPerEUAttr::AMDGPUWavesPerEUAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUWavesPerEUAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUWavesPerEUAttr)
// 1: AMDGPUWavesPerEUAttr::Clone
::pasta::Expr AMDGPUWavesPerEUAttr::Max(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUWavesPerEUAttr *>(u.AMDGPUWavesPerEUAttr);
  decltype(auto) val = self.getMax();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUWavesPerEUAttr::Max can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AMDGPUWavesPerEUAttr::Min(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUWavesPerEUAttr *>(u.AMDGPUWavesPerEUAttr);
  decltype(auto) val = self.getMin();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUWavesPerEUAttr::Min can return nullptr!");
  __builtin_unreachable();
}

std::string_view AMDGPUWavesPerEUAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AMDGPUWavesPerEUAttr *>(u.AMDGPUWavesPerEUAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUWavesPerEUAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ARMInterruptAttr::ARMInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ARMInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ARMInterruptAttr)
// 1: ARMInterruptAttr::Clone
enum ARMInterruptAttrInterruptType ARMInterruptAttr::Interrupt(void) const noexcept {
  auto &self = *const_cast<clang::ARMInterruptAttr *>(u.ARMInterruptAttr);
  decltype(auto) val = self.getInterrupt();
  return static_cast<::pasta::ARMInterruptAttrInterruptType>(val);
  __builtin_unreachable();
}

std::string_view ARMInterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ARMInterruptAttr *>(u.ARMInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ARMInterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AVRInterruptAttr::AVRInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AVRInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AVRInterruptAttr)
// 1: AVRInterruptAttr::Clone
std::string_view AVRInterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AVRInterruptAttr *>(u.AVRInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AVRInterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AVRSignalAttr::AVRSignalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AVRSignalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AVRSignalAttr)
// 1: AVRSignalAttr::Clone
std::string_view AVRSignalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AVRSignalAttr *>(u.AVRSignalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AVRSignalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AbiTagAttr::AbiTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AbiTagAttr)
// 1: AbiTagAttr::Clone
std::string_view AbiTagAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AbiTagAttr *>(u.AbiTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AbiTagAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 0: AbiTagAttr::Tags
// 0: AbiTagAttr::
// 0: AbiTagAttr::
// 0: AbiTagAttr::
AcquireCapabilityAttr::AcquireCapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AcquireCapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AcquireCapabilityAttr)
// 0: AcquireCapabilityAttr::Arguments
// 0: AcquireCapabilityAttr::
// 0: AcquireCapabilityAttr::
// 0: AcquireCapabilityAttr::
// 1: AcquireCapabilityAttr::Clone
enum AcquireCapabilityAttrSpelling AcquireCapabilityAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::AcquireCapabilityAttr *>(u.AcquireCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AcquireCapabilityAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view AcquireCapabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AcquireCapabilityAttr *>(u.AcquireCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquireCapabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool AcquireCapabilityAttr::IsShared(void) const noexcept {
  auto &self = *const_cast<clang::AcquireCapabilityAttr *>(u.AcquireCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  __builtin_unreachable();
}

AcquireHandleAttr::AcquireHandleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AcquireHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AcquireHandleAttr)
// 1: AcquireHandleAttr::Clone
std::string_view AcquireHandleAttr::HandleType(void) const noexcept {
  auto &self = *const_cast<clang::AcquireHandleAttr *>(u.AcquireHandleAttr);
  decltype(auto) val = self.getHandleType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AcquireHandleAttr::HandleTypeLength(void) const noexcept {
  auto &self = *const_cast<clang::AcquireHandleAttr *>(u.AcquireHandleAttr);
  decltype(auto) val = self.getHandleTypeLength();
  return val;
  __builtin_unreachable();
}

std::string_view AcquireHandleAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AcquireHandleAttr *>(u.AcquireHandleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquireHandleAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AcquiredAfterAttr::AcquiredAfterAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AcquiredAfterAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AcquiredAfterAttr)
// 0: AcquiredAfterAttr::Arguments
// 0: AcquiredAfterAttr::
// 0: AcquiredAfterAttr::
// 0: AcquiredAfterAttr::
// 1: AcquiredAfterAttr::Clone
std::string_view AcquiredAfterAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AcquiredAfterAttr *>(u.AcquiredAfterAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquiredAfterAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AcquiredBeforeAttr::AcquiredBeforeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AcquiredBeforeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AcquiredBeforeAttr)
// 0: AcquiredBeforeAttr::Arguments
// 0: AcquiredBeforeAttr::
// 0: AcquiredBeforeAttr::
// 0: AcquiredBeforeAttr::
// 1: AcquiredBeforeAttr::Clone
std::string_view AcquiredBeforeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AcquiredBeforeAttr *>(u.AcquiredBeforeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquiredBeforeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AddressSpaceAttr::AddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, AddressSpaceAttr)
// 1: AddressSpaceAttr::Clone
// 0: AddressSpaceAttr::AddressSpace
std::string_view AddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AddressSpaceAttr *>(u.AddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AliasAttr::AliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AliasAttr)
// 1: AliasAttr::Clone
std::string_view AliasAttr::Aliasee(void) const noexcept {
  auto &self = *const_cast<clang::AliasAttr *>(u.AliasAttr);
  decltype(auto) val = self.getAliasee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AliasAttr::AliaseeLength(void) const noexcept {
  auto &self = *const_cast<clang::AliasAttr *>(u.AliasAttr);
  decltype(auto) val = self.getAliaseeLength();
  return val;
  __builtin_unreachable();
}

std::string_view AliasAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AliasAttr *>(u.AliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AliasAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AlignMac68kAttr::AlignMac68kAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignMac68kAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlignMac68kAttr)
// 1: AlignMac68kAttr::Clone
std::string_view AlignMac68kAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AlignMac68kAttr *>(u.AlignMac68kAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignMac68kAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AlignNaturalAttr::AlignNaturalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignNaturalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlignNaturalAttr)
// 1: AlignNaturalAttr::Clone
std::string_view AlignNaturalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AlignNaturalAttr *>(u.AlignNaturalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignNaturalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AlignValueAttr::AlignValueAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignValueAttr)
// 1: AlignValueAttr::Clone
::pasta::Expr AlignValueAttr::Alignment(void) const noexcept {
  auto &self = *const_cast<clang::AlignValueAttr *>(u.AlignValueAttr);
  decltype(auto) val = self.getAlignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AlignValueAttr::Alignment can return nullptr!");
  __builtin_unreachable();
}

std::string_view AlignValueAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AlignValueAttr *>(u.AlignValueAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignValueAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AlignedAttr::AlignedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlignedAttr)
// 1: AlignedAttr::Clone
uint32_t AlignedAttr::Alignment(void) const noexcept {
  auto &self = *(u.AlignedAttr);
  decltype(auto) val = self.getAlignment(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

::pasta::Expr AlignedAttr::AlignmentExpression(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.getAlignmentExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AlignedAttr::AlignmentExpression can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type AlignedAttr::AlignmentType(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.getAlignmentType();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "AlignedAttr::AlignmentType can return nullptr!");
  __builtin_unreachable();
}

enum AlignedAttrSpelling AlignedAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AlignedAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view AlignedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool AlignedAttr::IsAlignas(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignas();
  return val;
  __builtin_unreachable();
}

bool AlignedAttr::IsAlignmentDependent(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignmentDependent();
  return val;
  __builtin_unreachable();
}

bool AlignedAttr::IsAlignmentErrorDependent(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignmentErrorDependent();
  return val;
  __builtin_unreachable();
}

bool AlignedAttr::IsAlignmentExpression(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignmentExpr();
  return val;
  __builtin_unreachable();
}

bool AlignedAttr::IsC11(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isC11();
  return val;
  __builtin_unreachable();
}

bool AlignedAttr::IsDeclspec(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isDeclspec();
  return val;
  __builtin_unreachable();
}

bool AlignedAttr::IsGNU(void) const noexcept {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isGNU();
  return val;
  __builtin_unreachable();
}

AllocAlignAttr::AllocAlignAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AllocAlignAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AllocAlignAttr)
// 1: AllocAlignAttr::Clone
// 0: AllocAlignAttr::ParameterIndex
std::string_view AllocAlignAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AllocAlignAttr *>(u.AllocAlignAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AllocAlignAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AllocSizeAttr::AllocSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AllocSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AllocSizeAttr)
// 1: AllocSizeAttr::Clone
// 0: AllocSizeAttr::ElemSizeParameter
// 0: AllocSizeAttr::NumElemsParameter
std::string_view AllocSizeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AllocSizeAttr *>(u.AllocSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AllocSizeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AlwaysDestroyAttr::AlwaysDestroyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlwaysDestroyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlwaysDestroyAttr)
// 1: AlwaysDestroyAttr::Clone
std::string_view AlwaysDestroyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AlwaysDestroyAttr *>(u.AlwaysDestroyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlwaysDestroyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AlwaysInlineAttr::AlwaysInlineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlwaysInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlwaysInlineAttr)
// 1: AlwaysInlineAttr::Clone
enum AlwaysInlineAttrSpelling AlwaysInlineAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::AlwaysInlineAttr *>(u.AlwaysInlineAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AlwaysInlineAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view AlwaysInlineAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AlwaysInlineAttr *>(u.AlwaysInlineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlwaysInlineAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AnalyzerNoReturnAttr::AnalyzerNoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnalyzerNoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnalyzerNoReturnAttr)
// 1: AnalyzerNoReturnAttr::Clone
std::string_view AnalyzerNoReturnAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AnalyzerNoReturnAttr *>(u.AnalyzerNoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnalyzerNoReturnAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AnnotateAttr::AnnotateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnnotateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnnotateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, AnnotateAttr)
// 0: AnnotateAttr::Arguments
// 0: AnnotateAttr::
// 0: AnnotateAttr::
// 0: AnnotateAttr::
// 1: AnnotateAttr::Clone
std::string_view AnnotateAttr::Annotation(void) const noexcept {
  auto &self = *const_cast<clang::AnnotateAttr *>(u.AnnotateAttr);
  decltype(auto) val = self.getAnnotation();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AnnotateAttr::AnnotationLength(void) const noexcept {
  auto &self = *const_cast<clang::AnnotateAttr *>(u.AnnotateAttr);
  decltype(auto) val = self.getAnnotationLength();
  return val;
  __builtin_unreachable();
}

std::string_view AnnotateAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AnnotateAttr *>(u.AnnotateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnnotateAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AnyX86InterruptAttr::AnyX86InterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnyX86InterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnyX86InterruptAttr)
// 1: AnyX86InterruptAttr::Clone
std::string_view AnyX86InterruptAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AnyX86InterruptAttr *>(u.AnyX86InterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnyX86InterruptAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AnyX86NoCallerSavedRegistersAttr::AnyX86NoCallerSavedRegistersAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnyX86NoCallerSavedRegistersAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnyX86NoCallerSavedRegistersAttr)
// 1: AnyX86NoCallerSavedRegistersAttr::Clone
std::string_view AnyX86NoCallerSavedRegistersAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AnyX86NoCallerSavedRegistersAttr *>(u.AnyX86NoCallerSavedRegistersAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnyX86NoCallerSavedRegistersAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AnyX86NoCfCheckAttr::AnyX86NoCfCheckAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnyX86NoCfCheckAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnyX86NoCfCheckAttr)
// 1: AnyX86NoCfCheckAttr::Clone
std::string_view AnyX86NoCfCheckAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AnyX86NoCfCheckAttr *>(u.AnyX86NoCfCheckAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnyX86NoCfCheckAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ArcWeakrefUnavailableAttr::ArcWeakrefUnavailableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArcWeakrefUnavailableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ArcWeakrefUnavailableAttr)
// 1: ArcWeakrefUnavailableAttr::Clone
std::string_view ArcWeakrefUnavailableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ArcWeakrefUnavailableAttr *>(u.ArcWeakrefUnavailableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArcWeakrefUnavailableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ArgumentWithTypeTagAttr::ArgumentWithTypeTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArgumentWithTypeTagAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ArgumentWithTypeTagAttr)
// 1: ArgumentWithTypeTagAttr::Clone
// 0: ArgumentWithTypeTagAttr::ArgumentIndex
// 0: ArgumentWithTypeTagAttr::ArgumentKind
bool ArgumentWithTypeTagAttr::IsPointer(void) const noexcept {
  auto &self = *const_cast<clang::ArgumentWithTypeTagAttr *>(u.ArgumentWithTypeTagAttr);
  decltype(auto) val = self.getIsPointer();
  return val;
  __builtin_unreachable();
}

enum ArgumentWithTypeTagAttrSpelling ArgumentWithTypeTagAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::ArgumentWithTypeTagAttr *>(u.ArgumentWithTypeTagAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ArgumentWithTypeTagAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view ArgumentWithTypeTagAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ArgumentWithTypeTagAttr *>(u.ArgumentWithTypeTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArgumentWithTypeTagAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 0: ArgumentWithTypeTagAttr::TypeTagIndex
ArmBuiltinAliasAttr::ArmBuiltinAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArmBuiltinAliasAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ArmBuiltinAliasAttr)
// 1: ArmBuiltinAliasAttr::Clone
// 0: ArmBuiltinAliasAttr::BuiltinName
std::string_view ArmBuiltinAliasAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ArmBuiltinAliasAttr *>(u.ArmBuiltinAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArmBuiltinAliasAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ArmMveStrictPolymorphismAttr::ArmMveStrictPolymorphismAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArmMveStrictPolymorphismAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
// 1: ArmMveStrictPolymorphismAttr::Clone
std::string_view ArmMveStrictPolymorphismAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ArmMveStrictPolymorphismAttr *>(u.ArmMveStrictPolymorphismAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArmMveStrictPolymorphismAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ArtificialAttr::ArtificialAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArtificialAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ArtificialAttr)
// 1: ArtificialAttr::Clone
std::string_view ArtificialAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ArtificialAttr *>(u.ArtificialAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArtificialAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AsmLabelAttr::AsmLabelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AsmLabelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AsmLabelAttr)
// 1: AsmLabelAttr::Clone
bool AsmLabelAttr::IsLiteralLabel(void) const noexcept {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getIsLiteralLabel();
  return val;
  __builtin_unreachable();
}

std::string_view AsmLabelAttr::Label(void) const noexcept {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getLabel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AsmLabelAttr::LabelLength(void) const noexcept {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getLabelLength();
  return val;
  __builtin_unreachable();
}

std::string_view AsmLabelAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AsmLabelAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 1: AsmLabelAttr::IsEquivalent
AssertCapabilityAttr::AssertCapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssertCapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssertCapabilityAttr)
// 0: AssertCapabilityAttr::Arguments
// 0: AssertCapabilityAttr::
// 0: AssertCapabilityAttr::
// 0: AssertCapabilityAttr::
// 1: AssertCapabilityAttr::Clone
enum AssertCapabilityAttrSpelling AssertCapabilityAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::AssertCapabilityAttr *>(u.AssertCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AssertCapabilityAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view AssertCapabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AssertCapabilityAttr *>(u.AssertCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssertCapabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool AssertCapabilityAttr::IsShared(void) const noexcept {
  auto &self = *const_cast<clang::AssertCapabilityAttr *>(u.AssertCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  __builtin_unreachable();
}

AssertExclusiveLockAttr::AssertExclusiveLockAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssertExclusiveLockAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssertExclusiveLockAttr)
// 0: AssertExclusiveLockAttr::Arguments
// 0: AssertExclusiveLockAttr::
// 0: AssertExclusiveLockAttr::
// 0: AssertExclusiveLockAttr::
// 1: AssertExclusiveLockAttr::Clone
std::string_view AssertExclusiveLockAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AssertExclusiveLockAttr *>(u.AssertExclusiveLockAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssertExclusiveLockAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AssertSharedLockAttr::AssertSharedLockAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssertSharedLockAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssertSharedLockAttr)
// 0: AssertSharedLockAttr::Arguments
// 0: AssertSharedLockAttr::
// 0: AssertSharedLockAttr::
// 0: AssertSharedLockAttr::
// 1: AssertSharedLockAttr::Clone
std::string_view AssertSharedLockAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AssertSharedLockAttr *>(u.AssertSharedLockAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssertSharedLockAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AssumeAlignedAttr::AssumeAlignedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssumeAlignedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssumeAlignedAttr)
// 1: AssumeAlignedAttr::Clone
::pasta::Expr AssumeAlignedAttr::Alignment(void) const noexcept {
  auto &self = *const_cast<clang::AssumeAlignedAttr *>(u.AssumeAlignedAttr);
  decltype(auto) val = self.getAlignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AssumeAlignedAttr::Alignment can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AssumeAlignedAttr::Offset(void) const noexcept {
  auto &self = *const_cast<clang::AssumeAlignedAttr *>(u.AssumeAlignedAttr);
  decltype(auto) val = self.getOffset();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AssumeAlignedAttr::Offset can return nullptr!");
  __builtin_unreachable();
}

std::string_view AssumeAlignedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AssumeAlignedAttr *>(u.AssumeAlignedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssumeAlignedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AssumptionAttr::AssumptionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssumptionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssumptionAttr)
// 1: AssumptionAttr::Clone
std::string_view AssumptionAttr::Assumption(void) const noexcept {
  auto &self = *const_cast<clang::AssumptionAttr *>(u.AssumptionAttr);
  decltype(auto) val = self.getAssumption();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AssumptionAttr::AssumptionLength(void) const noexcept {
  auto &self = *const_cast<clang::AssumptionAttr *>(u.AssumptionAttr);
  decltype(auto) val = self.getAssumptionLength();
  return val;
  __builtin_unreachable();
}

std::string_view AssumptionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AssumptionAttr *>(u.AssumptionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssumptionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

AvailabilityAttr::AvailabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AvailabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AvailabilityAttr)
// 1: AvailabilityAttr::Clone
// 0: AvailabilityAttr::Deprecated
// 0: AvailabilityAttr::Introduced
std::string_view AvailabilityAttr::Message(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AvailabilityAttr::MessageLength(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  __builtin_unreachable();
}

// 0: AvailabilityAttr::Obsoleted
// 0: AvailabilityAttr::Platform
// 0: AvailabilityAttr::Priority
std::string_view AvailabilityAttr::Replacement(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getReplacement();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t AvailabilityAttr::ReplacementLength(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getReplacementLength();
  return val;
  __builtin_unreachable();
}

std::string_view AvailabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AvailabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool AvailabilityAttr::Strict(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getStrict();
  return val;
  __builtin_unreachable();
}

bool AvailabilityAttr::Unavailable(void) const noexcept {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getUnavailable();
  return val;
  __builtin_unreachable();
}

BPFPreserveAccessIndexAttr::BPFPreserveAccessIndexAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BPFPreserveAccessIndexAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BPFPreserveAccessIndexAttr)
// 1: BPFPreserveAccessIndexAttr::Clone
std::string_view BPFPreserveAccessIndexAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::BPFPreserveAccessIndexAttr *>(u.BPFPreserveAccessIndexAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BPFPreserveAccessIndexAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

BTFDeclTagAttr::BTFDeclTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BTFDeclTagAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BTFDeclTagAttr)
// 1: BTFDeclTagAttr::Clone
std::string_view BTFDeclTagAttr::BTFDeclTag(void) const noexcept {
  auto &self = *const_cast<clang::BTFDeclTagAttr *>(u.BTFDeclTagAttr);
  decltype(auto) val = self.getBTFDeclTag();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t BTFDeclTagAttr::BTFDeclTagLength(void) const noexcept {
  auto &self = *const_cast<clang::BTFDeclTagAttr *>(u.BTFDeclTagAttr);
  decltype(auto) val = self.getBTFDeclTagLength();
  return val;
  __builtin_unreachable();
}

std::string_view BTFDeclTagAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::BTFDeclTagAttr *>(u.BTFDeclTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BTFDeclTagAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

BTFTypeTagAttr::BTFTypeTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BTFTypeTagAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, BTFTypeTagAttr)
// 1: BTFTypeTagAttr::Clone
std::string_view BTFTypeTagAttr::BTFTypeTag(void) const noexcept {
  auto &self = *const_cast<clang::BTFTypeTagAttr *>(u.BTFTypeTagAttr);
  decltype(auto) val = self.getBTFTypeTag();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t BTFTypeTagAttr::BTFTypeTagLength(void) const noexcept {
  auto &self = *const_cast<clang::BTFTypeTagAttr *>(u.BTFTypeTagAttr);
  decltype(auto) val = self.getBTFTypeTagLength();
  return val;
  __builtin_unreachable();
}

std::string_view BTFTypeTagAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::BTFTypeTagAttr *>(u.BTFTypeTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BTFTypeTagAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

BlocksAttr::BlocksAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BlocksAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BlocksAttr)
// 1: BlocksAttr::Clone
std::string_view BlocksAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::BlocksAttr *>(u.BlocksAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BlocksAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

enum BlocksAttrBlockType BlocksAttr::Type(void) const noexcept {
  auto &self = *const_cast<clang::BlocksAttr *>(u.BlocksAttr);
  decltype(auto) val = self.getType();
  return static_cast<::pasta::BlocksAttrBlockType>(val);
  __builtin_unreachable();
}

BuiltinAttr::BuiltinAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BuiltinAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BuiltinAttr)
// 1: BuiltinAttr::Clone
uint32_t BuiltinAttr::ID(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinAttr *>(u.BuiltinAttr);
  decltype(auto) val = self.getID();
  return val;
  __builtin_unreachable();
}

std::string_view BuiltinAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::BuiltinAttr *>(u.BuiltinAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BuiltinAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

C11NoReturnAttr::C11NoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, C11NoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, C11NoReturnAttr)
// 1: C11NoReturnAttr::Clone
std::string_view C11NoReturnAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::C11NoReturnAttr *>(u.C11NoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "C11NoReturnAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CDeclAttr::CDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CDeclAttr)
// 1: CDeclAttr::Clone
std::string_view CDeclAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CDeclAttr *>(u.CDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CDeclAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFAuditedTransferAttr::CFAuditedTransferAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFAuditedTransferAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFAuditedTransferAttr)
// 1: CFAuditedTransferAttr::Clone
std::string_view CFAuditedTransferAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFAuditedTransferAttr *>(u.CFAuditedTransferAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFAuditedTransferAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFConsumedAttr::CFConsumedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, CFConsumedAttr)
// 1: CFConsumedAttr::Clone
std::string_view CFConsumedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFConsumedAttr *>(u.CFConsumedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFConsumedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFGuardAttr::CFGuardAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFGuardAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFGuardAttr)
// 1: CFGuardAttr::Clone
enum CFGuardAttrGuardArg CFGuardAttr::Guard(void) const noexcept {
  auto &self = *const_cast<clang::CFGuardAttr *>(u.CFGuardAttr);
  decltype(auto) val = self.getGuard();
  return static_cast<::pasta::CFGuardAttrGuardArg>(val);
  __builtin_unreachable();
}

std::string_view CFGuardAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFGuardAttr *>(u.CFGuardAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFGuardAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFICanonicalJumpTableAttr::CFICanonicalJumpTableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFICanonicalJumpTableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFICanonicalJumpTableAttr)
// 1: CFICanonicalJumpTableAttr::Clone
std::string_view CFICanonicalJumpTableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFICanonicalJumpTableAttr *>(u.CFICanonicalJumpTableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFICanonicalJumpTableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFReturnsNotRetainedAttr::CFReturnsNotRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFReturnsNotRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFReturnsNotRetainedAttr)
// 1: CFReturnsNotRetainedAttr::Clone
std::string_view CFReturnsNotRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFReturnsNotRetainedAttr *>(u.CFReturnsNotRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFReturnsNotRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFReturnsRetainedAttr::CFReturnsRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFReturnsRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFReturnsRetainedAttr)
// 1: CFReturnsRetainedAttr::Clone
std::string_view CFReturnsRetainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFReturnsRetainedAttr *>(u.CFReturnsRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFReturnsRetainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CFUnknownTransferAttr::CFUnknownTransferAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFUnknownTransferAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFUnknownTransferAttr)
// 1: CFUnknownTransferAttr::Clone
std::string_view CFUnknownTransferAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CFUnknownTransferAttr *>(u.CFUnknownTransferAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFUnknownTransferAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CPUDispatchAttr::CPUDispatchAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CPUDispatchAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CPUDispatchAttr)
// 1: CPUDispatchAttr::Clone
// 0: CPUDispatchAttr::Cpus
// 0: CPUDispatchAttr::
// 0: CPUDispatchAttr::
// 0: CPUDispatchAttr::
std::string_view CPUDispatchAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CPUDispatchAttr *>(u.CPUDispatchAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CPUDispatchAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CPUSpecificAttr::CPUSpecificAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CPUSpecificAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CPUSpecificAttr)
// 1: CPUSpecificAttr::Clone
// 0: CPUSpecificAttr::Cpus
// 0: CPUSpecificAttr::
// 0: CPUSpecificAttr::
// 0: CPUSpecificAttr::
// 1: CPUSpecificAttr::CPUName
std::string_view CPUSpecificAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CPUSpecificAttr *>(u.CPUSpecificAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CPUSpecificAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDAConstantAttr::CUDAConstantAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAConstantAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAConstantAttr)
// 1: CUDAConstantAttr::Clone
std::string_view CUDAConstantAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDAConstantAttr *>(u.CUDAConstantAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAConstantAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDADeviceAttr::CUDADeviceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDADeviceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDADeviceAttr)
// 1: CUDADeviceAttr::Clone
std::string_view CUDADeviceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDADeviceAttr *>(u.CUDADeviceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDADeviceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDADeviceBuiltinSurfaceTypeAttr::CUDADeviceBuiltinSurfaceTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDADeviceBuiltinSurfaceTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDADeviceBuiltinSurfaceTypeAttr)
// 1: CUDADeviceBuiltinSurfaceTypeAttr::Clone
std::string_view CUDADeviceBuiltinSurfaceTypeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDADeviceBuiltinSurfaceTypeAttr *>(u.CUDADeviceBuiltinSurfaceTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDADeviceBuiltinSurfaceTypeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDADeviceBuiltinTextureTypeAttr::CUDADeviceBuiltinTextureTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDADeviceBuiltinTextureTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDADeviceBuiltinTextureTypeAttr)
// 1: CUDADeviceBuiltinTextureTypeAttr::Clone
std::string_view CUDADeviceBuiltinTextureTypeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDADeviceBuiltinTextureTypeAttr *>(u.CUDADeviceBuiltinTextureTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDADeviceBuiltinTextureTypeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDAGlobalAttr::CUDAGlobalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAGlobalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAGlobalAttr)
// 1: CUDAGlobalAttr::Clone
std::string_view CUDAGlobalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDAGlobalAttr *>(u.CUDAGlobalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAGlobalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDAHostAttr::CUDAHostAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAHostAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAHostAttr)
// 1: CUDAHostAttr::Clone
std::string_view CUDAHostAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDAHostAttr *>(u.CUDAHostAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAHostAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDAInvalidTargetAttr::CUDAInvalidTargetAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAInvalidTargetAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAInvalidTargetAttr)
// 1: CUDAInvalidTargetAttr::Clone
std::string_view CUDAInvalidTargetAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDAInvalidTargetAttr *>(u.CUDAInvalidTargetAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAInvalidTargetAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDALaunchBoundsAttr::CUDALaunchBoundsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDALaunchBoundsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDALaunchBoundsAttr)
// 1: CUDALaunchBoundsAttr::Clone
::pasta::Expr CUDALaunchBoundsAttr::MaxThreads(void) const noexcept {
  auto &self = *const_cast<clang::CUDALaunchBoundsAttr *>(u.CUDALaunchBoundsAttr);
  decltype(auto) val = self.getMaxThreads();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CUDALaunchBoundsAttr::MaxThreads can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CUDALaunchBoundsAttr::MinBlocks(void) const noexcept {
  auto &self = *const_cast<clang::CUDALaunchBoundsAttr *>(u.CUDALaunchBoundsAttr);
  decltype(auto) val = self.getMinBlocks();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CUDALaunchBoundsAttr::MinBlocks can return nullptr!");
  __builtin_unreachable();
}

std::string_view CUDALaunchBoundsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDALaunchBoundsAttr *>(u.CUDALaunchBoundsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDALaunchBoundsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CUDASharedAttr::CUDASharedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDASharedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDASharedAttr)
// 1: CUDASharedAttr::Clone
std::string_view CUDASharedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CUDASharedAttr *>(u.CUDASharedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDASharedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CXX11NoReturnAttr::CXX11NoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CXX11NoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CXX11NoReturnAttr)
// 1: CXX11NoReturnAttr::Clone
std::string_view CXX11NoReturnAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CXX11NoReturnAttr *>(u.CXX11NoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CXX11NoReturnAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CallableWhenAttr::CallableWhenAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CallableWhenAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CallableWhenAttr)
// 0: CallableWhenAttr::CallableStates
// 0: CallableWhenAttr::
// 0: CallableWhenAttr::
// 0: CallableWhenAttr::
// 1: CallableWhenAttr::Clone
std::string_view CallableWhenAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CallableWhenAttr *>(u.CallableWhenAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CallableWhenAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CallbackAttr::CallbackAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CallbackAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CallbackAttr)
// 1: CallbackAttr::Clone
// 0: CallbackAttr::Encoding
// 0: CallbackAttr::
// 0: CallbackAttr::
// 0: CallbackAttr::
std::string_view CallbackAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CallbackAttr *>(u.CallbackAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CallbackAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CapabilityAttr::CapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CapabilityAttr)
// 1: CapabilityAttr::Clone
std::string_view CapabilityAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t CapabilityAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

enum CapabilityAttrSpelling CapabilityAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::CapabilityAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view CapabilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CapabilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool CapabilityAttr::IsShared(void) const noexcept {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  __builtin_unreachable();
}

CapturedRecordAttr::CapturedRecordAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CapturedRecordAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CapturedRecordAttr)
// 1: CapturedRecordAttr::Clone
std::string_view CapturedRecordAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CapturedRecordAttr *>(u.CapturedRecordAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CapturedRecordAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CarriesDependencyAttr::CarriesDependencyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CarriesDependencyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CarriesDependencyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, CarriesDependencyAttr)
// 1: CarriesDependencyAttr::Clone
std::string_view CarriesDependencyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CarriesDependencyAttr *>(u.CarriesDependencyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CarriesDependencyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CleanupAttr::CleanupAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CleanupAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CleanupAttr)
// 1: CleanupAttr::Clone
::pasta::FunctionDecl CleanupAttr::FunctionDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CleanupAttr *>(u.CleanupAttr);
  decltype(auto) val = self.getFunctionDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CleanupAttr::FunctionDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::string_view CleanupAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CleanupAttr *>(u.CleanupAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CleanupAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CmseNSCallAttr::CmseNSCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CmseNSCallAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, CmseNSCallAttr)
// 1: CmseNSCallAttr::Clone
std::string_view CmseNSCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CmseNSCallAttr *>(u.CmseNSCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CmseNSCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CmseNSEntryAttr::CmseNSEntryAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CmseNSEntryAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CmseNSEntryAttr)
// 1: CmseNSEntryAttr::Clone
std::string_view CmseNSEntryAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CmseNSEntryAttr *>(u.CmseNSEntryAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CmseNSEntryAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CodeSegAttr::CodeSegAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CodeSegAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CodeSegAttr)
// 1: CodeSegAttr::Clone
std::string_view CodeSegAttr::Name(void) const noexcept {
  auto &self = *const_cast<clang::CodeSegAttr *>(u.CodeSegAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t CodeSegAttr::NameLength(void) const noexcept {
  auto &self = *const_cast<clang::CodeSegAttr *>(u.CodeSegAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  __builtin_unreachable();
}

std::string_view CodeSegAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CodeSegAttr *>(u.CodeSegAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CodeSegAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ColdAttr::ColdAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ColdAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ColdAttr)
// 1: ColdAttr::Clone
std::string_view ColdAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ColdAttr *>(u.ColdAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ColdAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

CommonAttr::CommonAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CommonAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CommonAttr)
// 1: CommonAttr::Clone
std::string_view CommonAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::CommonAttr *>(u.CommonAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CommonAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ConstAttr::ConstAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConstAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConstAttr)
// 1: ConstAttr::Clone
std::string_view ConstAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConstAttr *>(u.ConstAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConstAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ConstInitAttr::ConstInitAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConstInitAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConstInitAttr)
// 1: ConstInitAttr::Clone
enum ConstInitAttrSpelling ConstInitAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::ConstInitAttr *>(u.ConstInitAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ConstInitAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view ConstInitAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConstInitAttr *>(u.ConstInitAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConstInitAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool ConstInitAttr::IsConstinit(void) const noexcept {
  auto &self = *const_cast<clang::ConstInitAttr *>(u.ConstInitAttr);
  decltype(auto) val = self.isConstinit();
  return val;
  __builtin_unreachable();
}

ConstructorAttr::ConstructorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConstructorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConstructorAttr)
// 1: ConstructorAttr::Clone
// 0: ConstructorAttr::Priority
std::string_view ConstructorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorAttr *>(u.ConstructorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConstructorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ConsumableAttr::ConsumableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConsumableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConsumableAttr)
// 1: ConsumableAttr::Clone
enum ConsumableAttrConsumedState ConsumableAttr::DefaultState(void) const noexcept {
  auto &self = *const_cast<clang::ConsumableAttr *>(u.ConsumableAttr);
  decltype(auto) val = self.getDefaultState();
  return static_cast<::pasta::ConsumableAttrConsumedState>(val);
  __builtin_unreachable();
}

std::string_view ConsumableAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConsumableAttr *>(u.ConsumableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConsumableAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ConsumableAutoCastAttr::ConsumableAutoCastAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConsumableAutoCastAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConsumableAutoCastAttr)
// 1: ConsumableAutoCastAttr::Clone
std::string_view ConsumableAutoCastAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConsumableAutoCastAttr *>(u.ConsumableAutoCastAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConsumableAutoCastAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ConsumableSetOnReadAttr::ConsumableSetOnReadAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConsumableSetOnReadAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConsumableSetOnReadAttr)
// 1: ConsumableSetOnReadAttr::Clone
std::string_view ConsumableSetOnReadAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConsumableSetOnReadAttr *>(u.ConsumableSetOnReadAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConsumableSetOnReadAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ConvergentAttr::ConvergentAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConvergentAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConvergentAttr)
// 1: ConvergentAttr::Clone
std::string_view ConvergentAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ConvergentAttr *>(u.ConvergentAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConvergentAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DLLExportAttr::DLLExportAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLExportAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLExportAttr)
// 1: DLLExportAttr::Clone
std::string_view DLLExportAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DLLExportAttr *>(u.DLLExportAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLExportAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DLLExportStaticLocalAttr::DLLExportStaticLocalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLExportStaticLocalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLExportStaticLocalAttr)
// 1: DLLExportStaticLocalAttr::Clone
std::string_view DLLExportStaticLocalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DLLExportStaticLocalAttr *>(u.DLLExportStaticLocalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLExportStaticLocalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DLLImportAttr::DLLImportAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLImportAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLImportAttr)
// 1: DLLImportAttr::Clone
std::string_view DLLImportAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DLLImportAttr *>(u.DLLImportAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLImportAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DLLImportStaticLocalAttr::DLLImportStaticLocalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLImportStaticLocalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLImportStaticLocalAttr)
// 1: DLLImportStaticLocalAttr::Clone
std::string_view DLLImportStaticLocalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DLLImportStaticLocalAttr *>(u.DLLImportStaticLocalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLImportStaticLocalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DeclOrStmtAttr::DeclOrStmtAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DeclOrStmtAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DeclOrStmtAttr)
PASTA_DEFINE_DERIVED_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
DeprecatedAttr::DeprecatedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DeprecatedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DeprecatedAttr)
// 1: DeprecatedAttr::Clone
std::string_view DeprecatedAttr::Message(void) const noexcept {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t DeprecatedAttr::MessageLength(void) const noexcept {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  __builtin_unreachable();
}

std::string_view DeprecatedAttr::Replacement(void) const noexcept {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getReplacement();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t DeprecatedAttr::ReplacementLength(void) const noexcept {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getReplacementLength();
  return val;
  __builtin_unreachable();
}

std::string_view DeprecatedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DeprecatedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DestructorAttr::DestructorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DestructorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DestructorAttr)
// 1: DestructorAttr::Clone
// 0: DestructorAttr::Priority
std::string_view DestructorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DestructorAttr *>(u.DestructorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DestructorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DiagnoseAsBuiltinAttr::DiagnoseAsBuiltinAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DiagnoseAsBuiltinAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DiagnoseAsBuiltinAttr)
// 0: DiagnoseAsBuiltinAttr::ArgumentIndices
// 0: DiagnoseAsBuiltinAttr::
// 0: DiagnoseAsBuiltinAttr::
// 0: DiagnoseAsBuiltinAttr::
// 1: DiagnoseAsBuiltinAttr::Clone
::pasta::FunctionDecl DiagnoseAsBuiltinAttr::Function(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseAsBuiltinAttr *>(u.DiagnoseAsBuiltinAttr);
  decltype(auto) val = self.getFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "DiagnoseAsBuiltinAttr::Function can return nullptr!");
  __builtin_unreachable();
}

std::string_view DiagnoseAsBuiltinAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseAsBuiltinAttr *>(u.DiagnoseAsBuiltinAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DiagnoseAsBuiltinAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DiagnoseIfAttr::DiagnoseIfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DiagnoseIfAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DiagnoseIfAttr)
// 1: DiagnoseIfAttr::Clone
bool DiagnoseIfAttr::ArgumentDependent(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getArgDependent();
  return val;
  __builtin_unreachable();
}

::pasta::Expr DiagnoseIfAttr::Condition(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DiagnoseIfAttr::Condition can return nullptr!");
  __builtin_unreachable();
}

enum DiagnoseIfAttrDiagnosticType DiagnoseIfAttr::DiagnosticType(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getDiagnosticType();
  return static_cast<::pasta::DiagnoseIfAttrDiagnosticType>(val);
  __builtin_unreachable();
}

std::string_view DiagnoseIfAttr::Message(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t DiagnoseIfAttr::MessageLength(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  __builtin_unreachable();
}

::pasta::NamedDecl DiagnoseIfAttr::Parent(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "DiagnoseIfAttr::Parent can return nullptr!");
  __builtin_unreachable();
}

std::string_view DiagnoseIfAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DiagnoseIfAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool DiagnoseIfAttr::IsError(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.isError();
  return val;
  __builtin_unreachable();
}

bool DiagnoseIfAttr::IsWarning(void) const noexcept {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.isWarning();
  return val;
  __builtin_unreachable();
}

DisableSanitizerInstrumentationAttr::DisableSanitizerInstrumentationAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DisableSanitizerInstrumentationAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DisableSanitizerInstrumentationAttr)
// 1: DisableSanitizerInstrumentationAttr::Clone
std::string_view DisableSanitizerInstrumentationAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DisableSanitizerInstrumentationAttr *>(u.DisableSanitizerInstrumentationAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DisableSanitizerInstrumentationAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

DisableTailCallsAttr::DisableTailCallsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DisableTailCallsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DisableTailCallsAttr)
// 1: DisableTailCallsAttr::Clone
std::string_view DisableTailCallsAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::DisableTailCallsAttr *>(u.DisableTailCallsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DisableTailCallsAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

EmptyBasesAttr::EmptyBasesAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EmptyBasesAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EmptyBasesAttr)
// 1: EmptyBasesAttr::Clone
std::string_view EmptyBasesAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::EmptyBasesAttr *>(u.EmptyBasesAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EmptyBasesAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

EnableIfAttr::EnableIfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnableIfAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnableIfAttr)
// 1: EnableIfAttr::Clone
::pasta::Expr EnableIfAttr::Condition(void) const noexcept {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "EnableIfAttr::Condition can return nullptr!");
  __builtin_unreachable();
}

std::string_view EnableIfAttr::Message(void) const noexcept {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t EnableIfAttr::MessageLength(void) const noexcept {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  __builtin_unreachable();
}

std::string_view EnableIfAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnableIfAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

EnforceTCBAttr::EnforceTCBAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnforceTCBAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnforceTCBAttr)
// 1: EnforceTCBAttr::Clone
std::string_view EnforceTCBAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::EnforceTCBAttr *>(u.EnforceTCBAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnforceTCBAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

std::string_view EnforceTCBAttr::TCBName(void) const noexcept {
  auto &self = *const_cast<clang::EnforceTCBAttr *>(u.EnforceTCBAttr);
  decltype(auto) val = self.getTCBName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t EnforceTCBAttr::TCBNameLength(void) const noexcept {
  auto &self = *const_cast<clang::EnforceTCBAttr *>(u.EnforceTCBAttr);
  decltype(auto) val = self.getTCBNameLength();
  return val;
  __builtin_unreachable();
}

EnforceTCBLeafAttr::EnforceTCBLeafAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnforceTCBLeafAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnforceTCBLeafAttr)
// 1: EnforceTCBLeafAttr::Clone
std::string_view EnforceTCBLeafAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::EnforceTCBLeafAttr *>(u.EnforceTCBLeafAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnforceTCBLeafAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

std::string_view EnforceTCBLeafAttr::TCBName(void) const noexcept {
  auto &self = *const_cast<clang::EnforceTCBLeafAttr *>(u.EnforceTCBLeafAttr);
  decltype(auto) val = self.getTCBName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t EnforceTCBLeafAttr::TCBNameLength(void) const noexcept {
  auto &self = *const_cast<clang::EnforceTCBLeafAttr *>(u.EnforceTCBLeafAttr);
  decltype(auto) val = self.getTCBNameLength();
  return val;
  __builtin_unreachable();
}

EnumExtensibilityAttr::EnumExtensibilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnumExtensibilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnumExtensibilityAttr)
// 1: EnumExtensibilityAttr::Clone
enum EnumExtensibilityAttrKind EnumExtensibilityAttr::Extensibility(void) const noexcept {
  auto &self = *const_cast<clang::EnumExtensibilityAttr *>(u.EnumExtensibilityAttr);
  decltype(auto) val = self.getExtensibility();
  return static_cast<::pasta::EnumExtensibilityAttrKind>(val);
  __builtin_unreachable();
}

std::string_view EnumExtensibilityAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::EnumExtensibilityAttr *>(u.EnumExtensibilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnumExtensibilityAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ErrorAttr::ErrorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ErrorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ErrorAttr)
// 1: ErrorAttr::Clone
enum ErrorAttrSpelling ErrorAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ErrorAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view ErrorAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ErrorAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

std::string_view ErrorAttr::UserDiagnostic(void) const noexcept {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getUserDiagnostic();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t ErrorAttr::UserDiagnosticLength(void) const noexcept {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getUserDiagnosticLength();
  return val;
  __builtin_unreachable();
}

bool ErrorAttr::IsError(void) const noexcept {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.isError();
  return val;
  __builtin_unreachable();
}

bool ErrorAttr::IsWarning(void) const noexcept {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.isWarning();
  return val;
  __builtin_unreachable();
}

ExcludeFromExplicitInstantiationAttr::ExcludeFromExplicitInstantiationAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ExcludeFromExplicitInstantiationAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ExcludeFromExplicitInstantiationAttr)
// 1: ExcludeFromExplicitInstantiationAttr::Clone
std::string_view ExcludeFromExplicitInstantiationAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ExcludeFromExplicitInstantiationAttr *>(u.ExcludeFromExplicitInstantiationAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ExcludeFromExplicitInstantiationAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ExclusiveTrylockFunctionAttr::ExclusiveTrylockFunctionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ExclusiveTrylockFunctionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ExclusiveTrylockFunctionAttr)
// 0: ExclusiveTrylockFunctionAttr::Arguments
// 0: ExclusiveTrylockFunctionAttr::
// 0: ExclusiveTrylockFunctionAttr::
// 0: ExclusiveTrylockFunctionAttr::
// 1: ExclusiveTrylockFunctionAttr::Clone
std::string_view ExclusiveTrylockFunctionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ExclusiveTrylockFunctionAttr *>(u.ExclusiveTrylockFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ExclusiveTrylockFunctionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ExclusiveTrylockFunctionAttr::SuccessValue(void) const noexcept {
  auto &self = *const_cast<clang::ExclusiveTrylockFunctionAttr *>(u.ExclusiveTrylockFunctionAttr);
  decltype(auto) val = self.getSuccessValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ExclusiveTrylockFunctionAttr::SuccessValue can return nullptr!");
  __builtin_unreachable();
}

ExternalSourceSymbolAttr::ExternalSourceSymbolAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ExternalSourceSymbolAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ExternalSourceSymbolAttr)
// 1: ExternalSourceSymbolAttr::Clone
std::string_view ExternalSourceSymbolAttr::DefinedIn(void) const noexcept {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getDefinedIn();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t ExternalSourceSymbolAttr::DefinedInLength(void) const noexcept {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getDefinedInLength();
  return val;
  __builtin_unreachable();
}

bool ExternalSourceSymbolAttr::GeneratedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getGeneratedDeclaration();
  return val;
  __builtin_unreachable();
}

std::string_view ExternalSourceSymbolAttr::Language(void) const noexcept {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getLanguage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t ExternalSourceSymbolAttr::LanguageLength(void) const noexcept {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getLanguageLength();
  return val;
  __builtin_unreachable();
}

std::string_view ExternalSourceSymbolAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ExternalSourceSymbolAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

FallThroughAttr::FallThroughAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FallThroughAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, FallThroughAttr)
// 1: FallThroughAttr::Clone
std::string_view FallThroughAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FallThroughAttr *>(u.FallThroughAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FallThroughAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

FastCallAttr::FastCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FastCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FastCallAttr)
// 1: FastCallAttr::Clone
std::string_view FastCallAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FastCallAttr *>(u.FastCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FastCallAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

FinalAttr::FinalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FinalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FinalAttr)
// 1: FinalAttr::Clone
enum FinalAttrSpelling FinalAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::FinalAttr *>(u.FinalAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::FinalAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view FinalAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FinalAttr *>(u.FinalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FinalAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

bool FinalAttr::IsSpelledAsSealed(void) const noexcept {
  auto &self = *const_cast<clang::FinalAttr *>(u.FinalAttr);
  decltype(auto) val = self.isSpelledAsSealed();
  return val;
  __builtin_unreachable();
}

FlagEnumAttr::FlagEnumAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FlagEnumAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FlagEnumAttr)
// 1: FlagEnumAttr::Clone
std::string_view FlagEnumAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FlagEnumAttr *>(u.FlagEnumAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FlagEnumAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

FlattenAttr::FlattenAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FlattenAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FlattenAttr)
// 1: FlattenAttr::Clone
std::string_view FlattenAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FlattenAttr *>(u.FlattenAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FlattenAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

FormatArgAttr::FormatArgAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FormatArgAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FormatArgAttr)
// 1: FormatArgAttr::Clone
// 0: FormatArgAttr::FormatIndex
std::string_view FormatArgAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FormatArgAttr *>(u.FormatArgAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FormatArgAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

FormatAttr::FormatAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FormatAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FormatAttr)
// 1: FormatAttr::Clone
// 0: FormatAttr::FirstArgument
// 0: FormatAttr::FormatIndex
std::string_view FormatAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::FormatAttr *>(u.FormatAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FormatAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

// 0: FormatAttr::Type
GNUInlineAttr::GNUInlineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, GNUInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, GNUInlineAttr)
// 1: GNUInlineAttr::Clone
std::string_view GNUInlineAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::GNUInlineAttr *>(u.GNUInlineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "GNUInlineAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

GuardedByAttr::GuardedByAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, GuardedByAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, GuardedByAttr)
// 1: GuardedByAttr::Clone
::pasta::Expr GuardedByAttr::Argument(void) const noexcept {
  auto &self = *const_cast<clang::GuardedByAttr *>(u.GuardedByAttr);
  decltype(auto) val = self.getArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "GuardedByAttr::Argument can return nullptr!");
  __builtin_unreachable();
}

std::string_view GuardedByAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::GuardedByAttr *>(u.GuardedByAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "GuardedByAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

GuardedVarAttr::GuardedVarAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, GuardedVarAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, GuardedVarAttr)
// 1: GuardedVarAttr::Clone
std::string_view GuardedVarAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::GuardedVarAttr *>(u.GuardedVarAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "GuardedVarAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

HIPManagedAttr::HIPManagedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HIPManagedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HIPManagedAttr)
// 1: HIPManagedAttr::Clone
std::string_view HIPManagedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::HIPManagedAttr *>(u.HIPManagedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HIPManagedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

HotAttr::HotAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HotAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HotAttr)
// 1: HotAttr::Clone
std::string_view HotAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::HotAttr *>(u.HotAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HotAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

IBActionAttr::IBActionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IBActionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IBActionAttr)
// 1: IBActionAttr::Clone
std::string_view IBActionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::IBActionAttr *>(u.IBActionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IBActionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

IBOutletAttr::IBOutletAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IBOutletAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IBOutletAttr)
// 1: IBOutletAttr::Clone
std::string_view IBOutletAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::IBOutletAttr *>(u.IBOutletAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IBOutletAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

IBOutletCollectionAttr::IBOutletCollectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IBOutletCollectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IBOutletCollectionAttr)
// 1: IBOutletCollectionAttr::Clone
::pasta::Type IBOutletCollectionAttr::Interface(void) const noexcept {
  auto &self = *const_cast<clang::IBOutletCollectionAttr *>(u.IBOutletCollectionAttr);
  decltype(auto) val = self.getInterface();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Type IBOutletCollectionAttr::InterfaceToken(void) const noexcept {
  auto &self = *const_cast<clang::IBOutletCollectionAttr *>(u.IBOutletCollectionAttr);
  decltype(auto) val = self.getInterfaceLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "IBOutletCollectionAttr::InterfaceToken can return nullptr!");
  __builtin_unreachable();
}

std::string_view IBOutletCollectionAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::IBOutletCollectionAttr *>(u.IBOutletCollectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IBOutletCollectionAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

LikelyAttr::LikelyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LikelyAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, LikelyAttr)
// 1: LikelyAttr::Clone
std::string_view LikelyAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::LikelyAttr *>(u.LikelyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LikelyAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

MustTailAttr::MustTailAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MustTailAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, MustTailAttr)
// 1: MustTailAttr::Clone
std::string_view MustTailAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::MustTailAttr *>(u.MustTailAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MustTailAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoDerefAttr::NoDerefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDerefAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, NoDerefAttr)
// 1: NoDerefAttr::Clone
std::string_view NoDerefAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoDerefAttr *>(u.NoDerefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDerefAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

NoMergeAttr::NoMergeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : DeclOrStmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoMergeAttr)
PASTA_DEFINE_BASE_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoMergeAttr)
// 1: NoMergeAttr::Clone
std::string_view NoMergeAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::NoMergeAttr *>(u.NoMergeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoMergeAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCGCAttr::ObjCGCAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCGCAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ObjCGCAttr)
// 1: ObjCGCAttr::Clone
// 0: ObjCGCAttr::Kind
std::string_view ObjCGCAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCGCAttr *>(u.ObjCGCAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCGCAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCInertUnsafeUnretainedAttr::ObjCInertUnsafeUnretainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCInertUnsafeUnretainedAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ObjCInertUnsafeUnretainedAttr)
// 1: ObjCInertUnsafeUnretainedAttr::Clone
std::string_view ObjCInertUnsafeUnretainedAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInertUnsafeUnretainedAttr *>(u.ObjCInertUnsafeUnretainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCInertUnsafeUnretainedAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

ObjCKindOfAttr::ObjCKindOfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCKindOfAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ObjCKindOfAttr)
// 1: ObjCKindOfAttr::Clone
std::string_view ObjCKindOfAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::ObjCKindOfAttr *>(u.ObjCKindOfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCKindOfAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLConstantAddressSpaceAttr::OpenCLConstantAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLConstantAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLConstantAddressSpaceAttr)
// 1: OpenCLConstantAddressSpaceAttr::Clone
enum OpenCLConstantAddressSpaceAttrSpelling OpenCLConstantAddressSpaceAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLConstantAddressSpaceAttr *>(u.OpenCLConstantAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLConstantAddressSpaceAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OpenCLConstantAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLConstantAddressSpaceAttr *>(u.OpenCLConstantAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLConstantAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLGenericAddressSpaceAttr::OpenCLGenericAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGenericAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGenericAddressSpaceAttr)
// 1: OpenCLGenericAddressSpaceAttr::Clone
enum OpenCLGenericAddressSpaceAttrSpelling OpenCLGenericAddressSpaceAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLGenericAddressSpaceAttr *>(u.OpenCLGenericAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLGenericAddressSpaceAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OpenCLGenericAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLGenericAddressSpaceAttr *>(u.OpenCLGenericAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGenericAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLGlobalAddressSpaceAttr::OpenCLGlobalAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGlobalAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGlobalAddressSpaceAttr)
// 1: OpenCLGlobalAddressSpaceAttr::Clone
enum OpenCLGlobalAddressSpaceAttrSpelling OpenCLGlobalAddressSpaceAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLGlobalAddressSpaceAttr *>(u.OpenCLGlobalAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLGlobalAddressSpaceAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OpenCLGlobalAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLGlobalAddressSpaceAttr *>(u.OpenCLGlobalAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGlobalAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLGlobalDeviceAddressSpaceAttr::OpenCLGlobalDeviceAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGlobalDeviceAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGlobalDeviceAddressSpaceAttr)
// 1: OpenCLGlobalDeviceAddressSpaceAttr::Clone
std::string_view OpenCLGlobalDeviceAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLGlobalDeviceAddressSpaceAttr *>(u.OpenCLGlobalDeviceAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGlobalDeviceAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLGlobalHostAddressSpaceAttr::OpenCLGlobalHostAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGlobalHostAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGlobalHostAddressSpaceAttr)
// 1: OpenCLGlobalHostAddressSpaceAttr::Clone
std::string_view OpenCLGlobalHostAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLGlobalHostAddressSpaceAttr *>(u.OpenCLGlobalHostAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGlobalHostAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLLocalAddressSpaceAttr::OpenCLLocalAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLLocalAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLLocalAddressSpaceAttr)
// 1: OpenCLLocalAddressSpaceAttr::Clone
enum OpenCLLocalAddressSpaceAttrSpelling OpenCLLocalAddressSpaceAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLLocalAddressSpaceAttr *>(u.OpenCLLocalAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLLocalAddressSpaceAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OpenCLLocalAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLLocalAddressSpaceAttr *>(u.OpenCLLocalAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLLocalAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLPrivateAddressSpaceAttr::OpenCLPrivateAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLPrivateAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLPrivateAddressSpaceAttr)
// 1: OpenCLPrivateAddressSpaceAttr::Clone
enum OpenCLPrivateAddressSpaceAttrSpelling OpenCLPrivateAddressSpaceAttr::SemanticSpelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLPrivateAddressSpaceAttr *>(u.OpenCLPrivateAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLPrivateAddressSpaceAttrSpelling>(val);
  __builtin_unreachable();
}

std::string_view OpenCLPrivateAddressSpaceAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLPrivateAddressSpaceAttr *>(u.OpenCLPrivateAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLPrivateAddressSpaceAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

OpenCLUnrollHintAttr::OpenCLUnrollHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLUnrollHintAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, OpenCLUnrollHintAttr)
// 1: OpenCLUnrollHintAttr::Clone
std::string_view OpenCLUnrollHintAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLUnrollHintAttr *>(u.OpenCLUnrollHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLUnrollHintAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

uint32_t OpenCLUnrollHintAttr::UnrollHint(void) const noexcept {
  auto &self = *const_cast<clang::OpenCLUnrollHintAttr *>(u.OpenCLUnrollHintAttr);
  decltype(auto) val = self.getUnrollHint();
  return val;
  __builtin_unreachable();
}

Ptr32Attr::Ptr32Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, Ptr32Attr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, Ptr32Attr)
// 1: Ptr32Attr::Clone
std::string_view Ptr32Attr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::Ptr32Attr *>(u.Ptr32Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Ptr32Attr::Spelling can return nullptr!");
  __builtin_unreachable();
}

Ptr64Attr::Ptr64Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, Ptr64Attr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, Ptr64Attr)
// 1: Ptr64Attr::Clone
std::string_view Ptr64Attr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::Ptr64Attr *>(u.Ptr64Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Ptr64Attr::Spelling can return nullptr!");
  __builtin_unreachable();
}

SPtrAttr::SPtrAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SPtrAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, SPtrAttr)
// 1: SPtrAttr::Clone
std::string_view SPtrAttr::Spelling(void) const noexcept {
  auto &self = *const_cast<clang::SPtrAttr *>(u.SPtrAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SPtrAttr::Spelling can return nullptr!");
  __builtin_unreachable();
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
