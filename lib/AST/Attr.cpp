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
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#include <clang/AST/Attr.h>
#include <clang/Frontend/CompilerInstance.h>
#pragma clang diagnostic pop

#include <pasta/AST/Attr.h>
#include <stdexcept>
#include "AST.h"
#include "Builder.h"

#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \
    std::optional<class derived> derived::From(const class base &that) { \
      if (auto attr_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.base)) { \
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
      kind = that.kind; \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      class derived new_that(std::forward<class derived>(that)); \
      ast = std::move(new_that.ast); \
      u.Attr = new_that.u.Attr; \
      kind = new_that.kind; \
      return *this; \
    }

namespace pasta {

namespace {
// Return the PASTA `AttrKind` for a Clang `Attr`.
static AttrKind KindOfAttr(const clang::Attr *attr) {
  switch (attr->getKind()) {
#define PASTA_ATTR_CASE(a) \
    case clang::attr::Kind::a: \
      return AttrKind::k ## a;

    PASTA_FOR_EACH_ATTR_IMPL(PASTA_ATTR_CASE, PASTA_IGNORE_ABSTRACT)
#undef PASTA_ATTR_CASE
    default: break;
  }
  throw std::runtime_error("The unreachable has been reached");
}

static const std::string_view kAttrNames[] = {
#define PASTA_ATTR_KIND_NAME(name) #name ,
PASTA_FOR_EACH_ATTR_IMPL(PASTA_ATTR_KIND_NAME, PASTA_IGNORE_ABSTRACT)
#undef PASTA_ATTR_KIND_NAME
};
}  // namespace

std::string_view Attr::KindName(void) const noexcept {
  return kAttrNames[static_cast<unsigned>(kind)];
}

::pasta::TokenRange Attr::Tokens(void) const noexcept {
  return ast->TokenRangeFrom(u.Attr->getRange());
}

Attr::Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)    : Attr(std::move(ast_), attr_, KindOfAttr(attr_)) {}

PASTA_DEFINE_DERIVED_OPERATORS(Attr, AArch64SVEPcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AArch64VectorPcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AMDGPUKernelCallAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, AnnotateTypeAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, FunctionReturnThunksAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, GNUInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, GuardedByAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, GuardedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HIPManagedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLAnnotationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLGroupSharedAddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLNumThreadsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLResourceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLResourceBindingAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLSV_DispatchThreadIDAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLSV_GroupIndexAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, HLSLShaderAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, MaybeUndefAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoRandomizeLayoutAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoSanitizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoSpeculativeLoadHardeningAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoSplitStackAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoStackProtectorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoThrowAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoUniqueAddressAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, NoUwtableAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, RandomizeLayoutAttr)
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ReadOnlyPlacementAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, StrictGuardStackCheckAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, TargetVersionAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Attr, ZeroCallUsedRegsAttr)
// 1: Attr::Clone
::pasta::Token Attr::Token(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view Attr::Spelling(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Attr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t Attr::SpellingListIndex(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.getSpellingListIndex();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool Attr::IsImplicit(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isImplicit();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool Attr::IsInherited(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isInherited();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool Attr::IsLateParsed(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isLateParsed();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool Attr::IsPackExpansion(void) const {
  auto &self = *const_cast<clang::Attr *>(u.Attr);
  decltype(auto) val = self.isPackExpansion();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

BuiltinAliasAttr::BuiltinAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BuiltinAliasAttr)
// 1: BuiltinAliasAttr::Clone
// 0: BuiltinAliasAttr::BuiltinName
enum BuiltinAliasAttrSpelling BuiltinAliasAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::BuiltinAliasAttr *>(u.BuiltinAliasAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::BuiltinAliasAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view BuiltinAliasAttr::Spelling(void) const {
  auto &self = *const_cast<clang::BuiltinAliasAttr *>(u.BuiltinAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BuiltinAliasAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CalledOnceAttr::CalledOnceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CalledOnceAttr)
// 1: CalledOnceAttr::Clone
std::string_view CalledOnceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CalledOnceAttr *>(u.CalledOnceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CalledOnceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

IFuncAttr::IFuncAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IFuncAttr)
// 1: IFuncAttr::Clone
std::string_view IFuncAttr::Resolver(void) const {
  auto &self = *const_cast<clang::IFuncAttr *>(u.IFuncAttr);
  decltype(auto) val = self.getResolver();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t IFuncAttr::ResolverLength(void) const {
  auto &self = *const_cast<clang::IFuncAttr *>(u.IFuncAttr);
  decltype(auto) val = self.getResolverLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view IFuncAttr::Spelling(void) const {
  auto &self = *const_cast<clang::IFuncAttr *>(u.IFuncAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IFuncAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

InheritableAttr::InheritableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InheritableAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AArch64SVEPcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, AMDGPUKernelCallAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, FunctionReturnThunksAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, GNUInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, GuardedByAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, GuardedVarAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HIPManagedAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLAnnotationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLNumThreadsAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLResourceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLResourceBindingAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLSV_DispatchThreadIDAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLSV_GroupIndexAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, HLSLShaderAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, MaybeUndefAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoRandomizeLayoutAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoReturnAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoSanitizeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoSpeculativeLoadHardeningAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoSplitStackAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoStackProtectorAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoThrowAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, NoUwtableAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, RandomizeLayoutAttr)
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ReadOnlyPlacementAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, StrictGuardStackCheckAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, TargetVersionAttr)
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
PASTA_DEFINE_DERIVED_OPERATORS(InheritableAttr, ZeroCallUsedRegsAttr)
bool InheritableAttr::ShouldInheritEvenIfAlreadyPresent(void) const {
  auto &self = *const_cast<clang::InheritableAttr *>(u.InheritableAttr);
  decltype(auto) val = self.shouldInheritEvenIfAlreadyPresent();
  return val;
  throw std::runtime_error("The unreachable has been reached");
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
uint32_t InitPriorityAttr::Priority(void) const {
  auto &self = *const_cast<clang::InitPriorityAttr *>(u.InitPriorityAttr);
  decltype(auto) val = self.getPriority();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view InitPriorityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::InitPriorityAttr *>(u.InitPriorityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "InitPriorityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

InitSegAttr::InitSegAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InitSegAttr)
// 1: InitSegAttr::Clone
std::string_view InitSegAttr::Section(void) const {
  auto &self = *const_cast<clang::InitSegAttr *>(u.InitSegAttr);
  decltype(auto) val = self.getSection();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t InitSegAttr::SectionLength(void) const {
  auto &self = *const_cast<clang::InitSegAttr *>(u.InitSegAttr);
  decltype(auto) val = self.getSectionLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view InitSegAttr::Spelling(void) const {
  auto &self = *const_cast<clang::InitSegAttr *>(u.InitSegAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "InitSegAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

IntelOclBiccAttr::IntelOclBiccAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IntelOclBiccAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IntelOclBiccAttr)
// 1: IntelOclBiccAttr::Clone
std::string_view IntelOclBiccAttr::Spelling(void) const {
  auto &self = *const_cast<clang::IntelOclBiccAttr *>(u.IntelOclBiccAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IntelOclBiccAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

InternalLinkageAttr::InternalLinkageAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, InternalLinkageAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, InternalLinkageAttr)
// 1: InternalLinkageAttr::Clone
std::string_view InternalLinkageAttr::Spelling(void) const {
  auto &self = *const_cast<clang::InternalLinkageAttr *>(u.InternalLinkageAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "InternalLinkageAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LTOVisibilityPublicAttr::LTOVisibilityPublicAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LTOVisibilityPublicAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LTOVisibilityPublicAttr)
// 1: LTOVisibilityPublicAttr::Clone
std::string_view LTOVisibilityPublicAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LTOVisibilityPublicAttr *>(u.LTOVisibilityPublicAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LTOVisibilityPublicAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LayoutVersionAttr::LayoutVersionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LayoutVersionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LayoutVersionAttr)
// 1: LayoutVersionAttr::Clone
std::string_view LayoutVersionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LayoutVersionAttr *>(u.LayoutVersionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LayoutVersionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t LayoutVersionAttr::Version(void) const {
  auto &self = *const_cast<clang::LayoutVersionAttr *>(u.LayoutVersionAttr);
  decltype(auto) val = self.getVersion();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

LeafAttr::LeafAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LeafAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LeafAttr)
// 1: LeafAttr::Clone
std::string_view LeafAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LeafAttr *>(u.LeafAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LeafAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LifetimeBoundAttr::LifetimeBoundAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LifetimeBoundAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LifetimeBoundAttr)
// 1: LifetimeBoundAttr::Clone
std::string_view LifetimeBoundAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LifetimeBoundAttr *>(u.LifetimeBoundAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LifetimeBoundAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LoaderUninitializedAttr::LoaderUninitializedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LoaderUninitializedAttr)
// 1: LoaderUninitializedAttr::Clone
std::string_view LoaderUninitializedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LoaderUninitializedAttr *>(u.LoaderUninitializedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LoaderUninitializedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LockReturnedAttr::LockReturnedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LockReturnedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, LockReturnedAttr)
// 1: LockReturnedAttr::Clone
::pasta::Expr LockReturnedAttr::Argument(void) const {
  auto &self = *const_cast<clang::LockReturnedAttr *>(u.LockReturnedAttr);
  decltype(auto) val = self.getArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "LockReturnedAttr::Argument can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view LockReturnedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LockReturnedAttr *>(u.LockReturnedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LockReturnedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view LocksExcludedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LocksExcludedAttr *>(u.LocksExcludedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LocksExcludedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LoopHintAttr::LoopHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LoopHintAttr)
// 1: LoopHintAttr::Clone
// 1: LoopHintAttr::DiagnosticName
enum LoopHintAttrOptionType LoopHintAttr::Option(void) const {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getOption();
  return static_cast<::pasta::LoopHintAttrOptionType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

enum LoopHintAttrSpelling LoopHintAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::LoopHintAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view LoopHintAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LoopHintAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum LoopHintAttrLoopHintState LoopHintAttr::State(void) const {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getState();
  return static_cast<::pasta::LoopHintAttrLoopHintState>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::optional<::pasta::Expr> LoopHintAttr::Value(void) const {
  auto &self = *const_cast<clang::LoopHintAttr *>(u.LoopHintAttr);
  decltype(auto) val = self.getValue();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("The unreachable has been reached");
}

// 1: LoopHintAttr::ValueString
M68kInterruptAttr::M68kInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, M68kInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, M68kInterruptAttr)
// 1: M68kInterruptAttr::Clone
uint32_t M68kInterruptAttr::Number(void) const {
  auto &self = *const_cast<clang::M68kInterruptAttr *>(u.M68kInterruptAttr);
  decltype(auto) val = self.getNumber();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view M68kInterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::M68kInterruptAttr *>(u.M68kInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "M68kInterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MIGServerRoutineAttr::MIGServerRoutineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MIGServerRoutineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MIGServerRoutineAttr)
// 1: MIGServerRoutineAttr::Clone
std::string_view MIGServerRoutineAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MIGServerRoutineAttr *>(u.MIGServerRoutineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MIGServerRoutineAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSABIAttr::MSABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSABIAttr)
// 1: MSABIAttr::Clone
std::string_view MSABIAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSABIAttr *>(u.MSABIAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSABIAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSAllocatorAttr::MSAllocatorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSAllocatorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSAllocatorAttr)
// 1: MSAllocatorAttr::Clone
std::string_view MSAllocatorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSAllocatorAttr *>(u.MSAllocatorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSAllocatorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSInheritanceAttr::MSInheritanceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSInheritanceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSInheritanceAttr)
// 1: MSInheritanceAttr::Clone
bool MSInheritanceAttr::BestCase(void) const {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getBestCase();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum MSInheritanceModel MSInheritanceAttr::InheritanceModel(void) const {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
  throw std::runtime_error("The unreachable has been reached");
}

enum MSInheritanceAttrSpelling MSInheritanceAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::MSInheritanceAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view MSInheritanceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSInheritanceAttr *>(u.MSInheritanceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSInheritanceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSNoVTableAttr::MSNoVTableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSNoVTableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSNoVTableAttr)
// 1: MSNoVTableAttr::Clone
std::string_view MSNoVTableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSNoVTableAttr *>(u.MSNoVTableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSNoVTableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSP430InterruptAttr::MSP430InterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSP430InterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSP430InterruptAttr)
// 1: MSP430InterruptAttr::Clone
uint32_t MSP430InterruptAttr::Number(void) const {
  auto &self = *const_cast<clang::MSP430InterruptAttr *>(u.MSP430InterruptAttr);
  decltype(auto) val = self.getNumber();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view MSP430InterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSP430InterruptAttr *>(u.MSP430InterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSP430InterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSStructAttr::MSStructAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSStructAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSStructAttr)
// 1: MSStructAttr::Clone
std::string_view MSStructAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSStructAttr *>(u.MSStructAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSStructAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MSVtorDispAttr::MSVtorDispAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MSVtorDispAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MSVtorDispAttr)
// 1: MSVtorDispAttr::Clone
std::string_view MSVtorDispAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MSVtorDispAttr *>(u.MSVtorDispAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MSVtorDispAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t MSVtorDispAttr::Vdm(void) const {
  auto &self = *const_cast<clang::MSVtorDispAttr *>(u.MSVtorDispAttr);
  decltype(auto) val = self.getVdm();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum MSVtorDispMode MSVtorDispAttr::VtorDispMode(void) const {
  auto &self = *const_cast<clang::MSVtorDispAttr *>(u.MSVtorDispAttr);
  decltype(auto) val = self.getVtorDispMode();
  return static_cast<::pasta::MSVtorDispMode>(val);
  throw std::runtime_error("The unreachable has been reached");
}

MaxFieldAlignmentAttr::MaxFieldAlignmentAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MaxFieldAlignmentAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MaxFieldAlignmentAttr)
// 1: MaxFieldAlignmentAttr::Clone
uint32_t MaxFieldAlignmentAttr::Alignment(void) const {
  auto &self = *const_cast<clang::MaxFieldAlignmentAttr *>(u.MaxFieldAlignmentAttr);
  decltype(auto) val = self.getAlignment();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view MaxFieldAlignmentAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MaxFieldAlignmentAttr *>(u.MaxFieldAlignmentAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MaxFieldAlignmentAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MayAliasAttr::MayAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MayAliasAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MayAliasAttr)
// 1: MayAliasAttr::Clone
std::string_view MayAliasAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MayAliasAttr *>(u.MayAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MayAliasAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MaybeUndefAttr::MaybeUndefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MaybeUndefAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MaybeUndefAttr)
// 1: MaybeUndefAttr::Clone
std::string_view MaybeUndefAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MaybeUndefAttr *>(u.MaybeUndefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MaybeUndefAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MicroMipsAttr::MicroMipsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MicroMipsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MicroMipsAttr)
// 1: MicroMipsAttr::Clone
std::string_view MicroMipsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MicroMipsAttr *>(u.MicroMipsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MicroMipsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MinSizeAttr::MinSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MinSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MinSizeAttr)
// 1: MinSizeAttr::Clone
std::string_view MinSizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MinSizeAttr *>(u.MinSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MinSizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MinVectorWidthAttr::MinVectorWidthAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MinVectorWidthAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MinVectorWidthAttr)
// 1: MinVectorWidthAttr::Clone
std::string_view MinVectorWidthAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MinVectorWidthAttr *>(u.MinVectorWidthAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MinVectorWidthAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t MinVectorWidthAttr::VectorWidth(void) const {
  auto &self = *const_cast<clang::MinVectorWidthAttr *>(u.MinVectorWidthAttr);
  decltype(auto) val = self.getVectorWidth();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

Mips16Attr::Mips16Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, Mips16Attr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, Mips16Attr)
// 1: Mips16Attr::Clone
std::string_view Mips16Attr::Spelling(void) const {
  auto &self = *const_cast<clang::Mips16Attr *>(u.Mips16Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Mips16Attr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MipsInterruptAttr::MipsInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MipsInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MipsInterruptAttr)
// 1: MipsInterruptAttr::Clone
enum MipsInterruptAttrInterruptType MipsInterruptAttr::Interrupt(void) const {
  auto &self = *const_cast<clang::MipsInterruptAttr *>(u.MipsInterruptAttr);
  decltype(auto) val = self.getInterrupt();
  return static_cast<::pasta::MipsInterruptAttrInterruptType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view MipsInterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MipsInterruptAttr *>(u.MipsInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MipsInterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MipsLongCallAttr::MipsLongCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MipsLongCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MipsLongCallAttr)
// 1: MipsLongCallAttr::Clone
enum MipsLongCallAttrSpelling MipsLongCallAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::MipsLongCallAttr *>(u.MipsLongCallAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::MipsLongCallAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view MipsLongCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MipsLongCallAttr *>(u.MipsLongCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MipsLongCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MipsShortCallAttr::MipsShortCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MipsShortCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, MipsShortCallAttr)
// 1: MipsShortCallAttr::Clone
enum MipsShortCallAttrSpelling MipsShortCallAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::MipsShortCallAttr *>(u.MipsShortCallAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::MipsShortCallAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view MipsShortCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MipsShortCallAttr *>(u.MipsShortCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MipsShortCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ModeAttr::ModeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ModeAttr)
// 1: ModeAttr::Clone
// 0: ModeAttr::Mode
std::string_view ModeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ModeAttr *>(u.ModeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ModeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NSConsumedAttr::NSConsumedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, NSConsumedAttr)
// 1: NSConsumedAttr::Clone
std::string_view NSConsumedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NSConsumedAttr *>(u.NSConsumedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSConsumedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NSConsumesSelfAttr::NSConsumesSelfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSConsumesSelfAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSConsumesSelfAttr)
// 1: NSConsumesSelfAttr::Clone
std::string_view NSConsumesSelfAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NSConsumesSelfAttr *>(u.NSConsumesSelfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSConsumesSelfAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NSErrorDomainAttr::NSErrorDomainAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSErrorDomainAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSErrorDomainAttr)
// 1: NSErrorDomainAttr::Clone
::pasta::VarDecl NSErrorDomainAttr::ErrorDomain(void) const {
  auto &self = *const_cast<clang::NSErrorDomainAttr *>(u.NSErrorDomainAttr);
  decltype(auto) val = self.getErrorDomain();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "NSErrorDomainAttr::ErrorDomain can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view NSErrorDomainAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NSErrorDomainAttr *>(u.NSErrorDomainAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSErrorDomainAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NSReturnsAutoreleasedAttr::NSReturnsAutoreleasedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSReturnsAutoreleasedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSReturnsAutoreleasedAttr)
// 1: NSReturnsAutoreleasedAttr::Clone
std::string_view NSReturnsAutoreleasedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NSReturnsAutoreleasedAttr *>(u.NSReturnsAutoreleasedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSReturnsAutoreleasedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NSReturnsNotRetainedAttr::NSReturnsNotRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSReturnsNotRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSReturnsNotRetainedAttr)
// 1: NSReturnsNotRetainedAttr::Clone
std::string_view NSReturnsNotRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NSReturnsNotRetainedAttr *>(u.NSReturnsNotRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSReturnsNotRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NSReturnsRetainedAttr::NSReturnsRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NSReturnsRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NSReturnsRetainedAttr)
// 1: NSReturnsRetainedAttr::Clone
std::string_view NSReturnsRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NSReturnsRetainedAttr *>(u.NSReturnsRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NSReturnsRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NakedAttr::NakedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NakedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NakedAttr)
// 1: NakedAttr::Clone
std::string_view NakedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NakedAttr *>(u.NakedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NakedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoAliasAttr::NoAliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoAliasAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoAliasAttr)
// 1: NoAliasAttr::Clone
std::string_view NoAliasAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoAliasAttr *>(u.NoAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoAliasAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view NoBuiltinAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoBuiltinAttr *>(u.NoBuiltinAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoBuiltinAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoCommonAttr::NoCommonAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoCommonAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoCommonAttr)
// 1: NoCommonAttr::Clone
std::string_view NoCommonAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoCommonAttr *>(u.NoCommonAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoCommonAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoDebugAttr::NoDebugAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDebugAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoDebugAttr)
// 1: NoDebugAttr::Clone
std::string_view NoDebugAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoDebugAttr *>(u.NoDebugAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDebugAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoDestroyAttr::NoDestroyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDestroyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoDestroyAttr)
// 1: NoDestroyAttr::Clone
std::string_view NoDestroyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoDestroyAttr *>(u.NoDestroyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDestroyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoDuplicateAttr::NoDuplicateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDuplicateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoDuplicateAttr)
// 1: NoDuplicateAttr::Clone
std::string_view NoDuplicateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoDuplicateAttr *>(u.NoDuplicateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDuplicateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoEscapeAttr::NoEscapeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoEscapeAttr)
// 1: NoEscapeAttr::Clone
std::string_view NoEscapeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoEscapeAttr *>(u.NoEscapeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoEscapeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoInstrumentFunctionAttr::NoInstrumentFunctionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoInstrumentFunctionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoInstrumentFunctionAttr)
// 1: NoInstrumentFunctionAttr::Clone
std::string_view NoInstrumentFunctionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoInstrumentFunctionAttr *>(u.NoInstrumentFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoInstrumentFunctionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoMicroMipsAttr::NoMicroMipsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoMicroMipsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoMicroMipsAttr)
// 1: NoMicroMipsAttr::Clone
std::string_view NoMicroMipsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoMicroMipsAttr *>(u.NoMicroMipsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoMicroMipsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoMips16Attr::NoMips16Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoMips16Attr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoMips16Attr)
// 1: NoMips16Attr::Clone
std::string_view NoMips16Attr::Spelling(void) const {
  auto &self = *const_cast<clang::NoMips16Attr *>(u.NoMips16Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoMips16Attr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoProfileFunctionAttr::NoProfileFunctionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoProfileFunctionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoProfileFunctionAttr)
// 1: NoProfileFunctionAttr::Clone
std::string_view NoProfileFunctionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoProfileFunctionAttr *>(u.NoProfileFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoProfileFunctionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoRandomizeLayoutAttr::NoRandomizeLayoutAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoRandomizeLayoutAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoRandomizeLayoutAttr)
// 1: NoRandomizeLayoutAttr::Clone
std::string_view NoRandomizeLayoutAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoRandomizeLayoutAttr *>(u.NoRandomizeLayoutAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoRandomizeLayoutAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoReturnAttr::NoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoReturnAttr)
// 1: NoReturnAttr::Clone
std::string_view NoReturnAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoReturnAttr *>(u.NoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoReturnAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoSanitizeAttr::NoSanitizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoSanitizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoSanitizeAttr)
// 1: NoSanitizeAttr::Clone
// 0: NoSanitizeAttr::Mask
std::string_view NoSanitizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoSanitizeAttr *>(u.NoSanitizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoSanitizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool NoSanitizeAttr::HasCoverage(void) const {
  auto &self = *const_cast<clang::NoSanitizeAttr *>(u.NoSanitizeAttr);
  decltype(auto) val = self.hasCoverage();
  return val;
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view NoSpeculativeLoadHardeningAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoSpeculativeLoadHardeningAttr *>(u.NoSpeculativeLoadHardeningAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoSpeculativeLoadHardeningAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoSplitStackAttr::NoSplitStackAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoSplitStackAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoSplitStackAttr)
// 1: NoSplitStackAttr::Clone
std::string_view NoSplitStackAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoSplitStackAttr *>(u.NoSplitStackAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoSplitStackAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoStackProtectorAttr::NoStackProtectorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoStackProtectorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoStackProtectorAttr)
// 1: NoStackProtectorAttr::Clone
enum NoStackProtectorAttrSpelling NoStackProtectorAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::NoStackProtectorAttr *>(u.NoStackProtectorAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::NoStackProtectorAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view NoStackProtectorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoStackProtectorAttr *>(u.NoStackProtectorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoStackProtectorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoThreadSafetyAnalysisAttr::NoThreadSafetyAnalysisAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoThreadSafetyAnalysisAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoThreadSafetyAnalysisAttr)
// 1: NoThreadSafetyAnalysisAttr::Clone
std::string_view NoThreadSafetyAnalysisAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoThreadSafetyAnalysisAttr *>(u.NoThreadSafetyAnalysisAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoThreadSafetyAnalysisAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoThrowAttr::NoThrowAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoThrowAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoThrowAttr)
// 1: NoThrowAttr::Clone
std::string_view NoThrowAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoThrowAttr *>(u.NoThrowAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoThrowAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoUniqueAddressAttr::NoUniqueAddressAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoUniqueAddressAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoUniqueAddressAttr)
// 1: NoUniqueAddressAttr::Clone
std::string_view NoUniqueAddressAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoUniqueAddressAttr *>(u.NoUniqueAddressAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoUniqueAddressAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoUwtableAttr::NoUwtableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoUwtableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoUwtableAttr)
// 1: NoUwtableAttr::Clone
std::string_view NoUwtableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoUwtableAttr *>(u.NoUwtableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoUwtableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view NonNullAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NonNullAttr *>(u.NonNullAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NonNullAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

// 1: NonNullAttr::IsNonNull
NotTailCalledAttr::NotTailCalledAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NotTailCalledAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NotTailCalledAttr)
// 1: NotTailCalledAttr::Clone
std::string_view NotTailCalledAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NotTailCalledAttr *>(u.NotTailCalledAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NotTailCalledAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OMPAllocateDeclAttr::OMPAllocateDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPAllocateDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPAllocateDeclAttr)
// 1: OMPAllocateDeclAttr::Clone
::pasta::Expr OMPAllocateDeclAttr::Alignment(void) const {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getAlignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAllocateDeclAttr::Alignment can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr OMPAllocateDeclAttr::Allocator(void) const {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getAllocator();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAllocateDeclAttr::Allocator can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum OMPAllocateDeclAttrAllocatorTypeTy OMPAllocateDeclAttr::AllocatorType(void) const {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getAllocatorType();
  return static_cast<::pasta::OMPAllocateDeclAttrAllocatorTypeTy>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OMPAllocateDeclAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPAllocateDeclAttr *>(u.OMPAllocateDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPAllocateDeclAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OMPCaptureKindAttr::OMPCaptureKindAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPCaptureKindAttr)
// 1: OMPCaptureKindAttr::Clone
// 0: OMPCaptureKindAttr::CaptureKind
uint32_t OMPCaptureKindAttr::CaptureKindValue(void) const {
  auto &self = *const_cast<clang::OMPCaptureKindAttr *>(u.OMPCaptureKindAttr);
  decltype(auto) val = self.getCaptureKindVal();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OMPCaptureKindAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPCaptureKindAttr *>(u.OMPCaptureKindAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPCaptureKindAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OMPCaptureNoInitAttr::OMPCaptureNoInitAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPCaptureNoInitAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPCaptureNoInitAttr)
// 1: OMPCaptureNoInitAttr::Clone
std::string_view OMPCaptureNoInitAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPCaptureNoInitAttr *>(u.OMPCaptureNoInitAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPCaptureNoInitAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum OMPDeclareSimdDeclAttrBranchStateTy OMPDeclareSimdDeclAttr::BranchState(void) const {
  auto &self = *const_cast<clang::OMPDeclareSimdDeclAttr *>(u.OMPDeclareSimdDeclAttr);
  decltype(auto) val = self.getBranchState();
  return static_cast<::pasta::OMPDeclareSimdDeclAttrBranchStateTy>(val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr OMPDeclareSimdDeclAttr::Simdlen(void) const {
  auto &self = *const_cast<clang::OMPDeclareSimdDeclAttr *>(u.OMPDeclareSimdDeclAttr);
  decltype(auto) val = self.getSimdlen();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareSimdDeclAttr::Simdlen can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OMPDeclareSimdDeclAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPDeclareSimdDeclAttr *>(u.OMPDeclareSimdDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPDeclareSimdDeclAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum OMPDeclareTargetDeclAttrDevTypeTy OMPDeclareTargetDeclAttr::DevType(void) const {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getDevType();
  return static_cast<::pasta::OMPDeclareTargetDeclAttrDevTypeTy>(val);
  throw std::runtime_error("The unreachable has been reached");
}

bool OMPDeclareTargetDeclAttr::Indirect(void) const {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getIndirect();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr OMPDeclareTargetDeclAttr::IndirectExpression(void) const {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getIndirectExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareTargetDeclAttr::IndirectExpression can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t OMPDeclareTargetDeclAttr::Level(void) const {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getLevel();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum OMPDeclareTargetDeclAttrMapTypeTy OMPDeclareTargetDeclAttr::MapType(void) const {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getMapType();
  return static_cast<::pasta::OMPDeclareTargetDeclAttrMapTypeTy>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OMPDeclareTargetDeclAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPDeclareTargetDeclAttr *>(u.OMPDeclareTargetDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPDeclareTargetDeclAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view OMPDeclareVariantAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPDeclareVariantAttr *>(u.OMPDeclareVariantAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPDeclareVariantAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

// 0: OMPDeclareVariantAttr::TraitInfos
::pasta::Expr OMPDeclareVariantAttr::VariantFuncReference(void) const {
  auto &self = *const_cast<clang::OMPDeclareVariantAttr *>(u.OMPDeclareVariantAttr);
  decltype(auto) val = self.getVariantFuncRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareVariantAttr::VariantFuncReference can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OMPReferencedVarAttr::OMPReferencedVarAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPReferencedVarAttr)
// 1: OMPReferencedVarAttr::Clone
::pasta::Expr OMPReferencedVarAttr::Reference(void) const {
  auto &self = *const_cast<clang::OMPReferencedVarAttr *>(u.OMPReferencedVarAttr);
  decltype(auto) val = self.getRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPReferencedVarAttr::Reference can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OMPReferencedVarAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPReferencedVarAttr *>(u.OMPReferencedVarAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPReferencedVarAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OMPThreadPrivateDeclAttr::OMPThreadPrivateDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OMPThreadPrivateDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OMPThreadPrivateDeclAttr)
// 1: OMPThreadPrivateDeclAttr::Clone
std::string_view OMPThreadPrivateDeclAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OMPThreadPrivateDeclAttr *>(u.OMPThreadPrivateDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OMPThreadPrivateDeclAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OSConsumedAttr::OSConsumedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, OSConsumedAttr)
// 1: OSConsumedAttr::Clone
std::string_view OSConsumedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OSConsumedAttr *>(u.OSConsumedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSConsumedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OSConsumesThisAttr::OSConsumesThisAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSConsumesThisAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSConsumesThisAttr)
// 1: OSConsumesThisAttr::Clone
std::string_view OSConsumesThisAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OSConsumesThisAttr *>(u.OSConsumesThisAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSConsumesThisAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OSReturnsNotRetainedAttr::OSReturnsNotRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsNotRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsNotRetainedAttr)
// 1: OSReturnsNotRetainedAttr::Clone
std::string_view OSReturnsNotRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OSReturnsNotRetainedAttr *>(u.OSReturnsNotRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsNotRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OSReturnsRetainedAttr::OSReturnsRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedAttr)
// 1: OSReturnsRetainedAttr::Clone
std::string_view OSReturnsRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OSReturnsRetainedAttr *>(u.OSReturnsRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OSReturnsRetainedOnNonZeroAttr::OSReturnsRetainedOnNonZeroAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsRetainedOnNonZeroAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedOnNonZeroAttr)
// 1: OSReturnsRetainedOnNonZeroAttr::Clone
std::string_view OSReturnsRetainedOnNonZeroAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OSReturnsRetainedOnNonZeroAttr *>(u.OSReturnsRetainedOnNonZeroAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsRetainedOnNonZeroAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OSReturnsRetainedOnZeroAttr::OSReturnsRetainedOnZeroAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OSReturnsRetainedOnZeroAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OSReturnsRetainedOnZeroAttr)
// 1: OSReturnsRetainedOnZeroAttr::Clone
std::string_view OSReturnsRetainedOnZeroAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OSReturnsRetainedOnZeroAttr *>(u.OSReturnsRetainedOnZeroAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OSReturnsRetainedOnZeroAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCBoxableAttr::ObjCBoxableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBoxableAttr)
// 1: ObjCBoxableAttr::Clone
std::string_view ObjCBoxableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCBoxableAttr *>(u.ObjCBoxableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBoxableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCBridgeAttr::ObjCBridgeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBridgeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCBridgeAttr)
// 1: ObjCBridgeAttr::Clone
// 0: ObjCBridgeAttr::BridgedType
std::string_view ObjCBridgeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCBridgeAttr *>(u.ObjCBridgeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBridgeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCBridgeMutableAttr::ObjCBridgeMutableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCBridgeMutableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCBridgeMutableAttr)
// 1: ObjCBridgeMutableAttr::Clone
// 0: ObjCBridgeMutableAttr::BridgedType
std::string_view ObjCBridgeMutableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCBridgeMutableAttr *>(u.ObjCBridgeMutableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBridgeMutableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view ObjCBridgeRelatedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCBridgeRelatedAttr *>(u.ObjCBridgeRelatedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCBridgeRelatedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCClassStubAttr::ObjCClassStubAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCClassStubAttr)
// 1: ObjCClassStubAttr::Clone
std::string_view ObjCClassStubAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCClassStubAttr *>(u.ObjCClassStubAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCClassStubAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCDesignatedInitializerAttr::ObjCDesignatedInitializerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCDesignatedInitializerAttr)
// 1: ObjCDesignatedInitializerAttr::Clone
std::string_view ObjCDesignatedInitializerAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCDesignatedInitializerAttr *>(u.ObjCDesignatedInitializerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCDesignatedInitializerAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCDirectAttr::ObjCDirectAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCDirectAttr)
// 1: ObjCDirectAttr::Clone
std::string_view ObjCDirectAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCDirectAttr *>(u.ObjCDirectAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCDirectAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCDirectMembersAttr::ObjCDirectMembersAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCDirectMembersAttr)
// 1: ObjCDirectMembersAttr::Clone
std::string_view ObjCDirectMembersAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCDirectMembersAttr *>(u.ObjCDirectMembersAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCDirectMembersAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCExceptionAttr::ObjCExceptionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCExceptionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCExceptionAttr)
// 1: ObjCExceptionAttr::Clone
std::string_view ObjCExceptionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCExceptionAttr *>(u.ObjCExceptionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCExceptionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCExplicitProtocolImplAttr::ObjCExplicitProtocolImplAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCExplicitProtocolImplAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCExplicitProtocolImplAttr)
// 1: ObjCExplicitProtocolImplAttr::Clone
std::string_view ObjCExplicitProtocolImplAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCExplicitProtocolImplAttr *>(u.ObjCExplicitProtocolImplAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCExplicitProtocolImplAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCExternallyRetainedAttr::ObjCExternallyRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCExternallyRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCExternallyRetainedAttr)
// 1: ObjCExternallyRetainedAttr::Clone
std::string_view ObjCExternallyRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCExternallyRetainedAttr *>(u.ObjCExternallyRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCExternallyRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCIndependentClassAttr::ObjCIndependentClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCIndependentClassAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCIndependentClassAttr)
// 1: ObjCIndependentClassAttr::Clone
std::string_view ObjCIndependentClassAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCIndependentClassAttr *>(u.ObjCIndependentClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCIndependentClassAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCMethodFamilyAttr::ObjCMethodFamilyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCMethodFamilyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCMethodFamilyAttr)
// 1: ObjCMethodFamilyAttr::Clone
enum ObjCMethodFamilyAttrFamilyKind ObjCMethodFamilyAttr::Family(void) const {
  auto &self = *const_cast<clang::ObjCMethodFamilyAttr *>(u.ObjCMethodFamilyAttr);
  decltype(auto) val = self.getFamily();
  return static_cast<::pasta::ObjCMethodFamilyAttrFamilyKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ObjCMethodFamilyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCMethodFamilyAttr *>(u.ObjCMethodFamilyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCMethodFamilyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCNSObjectAttr::ObjCNSObjectAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCNSObjectAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCNSObjectAttr)
// 1: ObjCNSObjectAttr::Clone
std::string_view ObjCNSObjectAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCNSObjectAttr *>(u.ObjCNSObjectAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCNSObjectAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCNonLazyClassAttr::ObjCNonLazyClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCNonLazyClassAttr)
// 1: ObjCNonLazyClassAttr::Clone
std::string_view ObjCNonLazyClassAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCNonLazyClassAttr *>(u.ObjCNonLazyClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCNonLazyClassAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCNonRuntimeProtocolAttr::ObjCNonRuntimeProtocolAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCNonRuntimeProtocolAttr)
// 1: ObjCNonRuntimeProtocolAttr::Clone
std::string_view ObjCNonRuntimeProtocolAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCNonRuntimeProtocolAttr *>(u.ObjCNonRuntimeProtocolAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCNonRuntimeProtocolAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCOwnershipAttr::ObjCOwnershipAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCOwnershipAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCOwnershipAttr)
// 1: ObjCOwnershipAttr::Clone
// 0: ObjCOwnershipAttr::Kind
std::string_view ObjCOwnershipAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCOwnershipAttr *>(u.ObjCOwnershipAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCOwnershipAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCPreciseLifetimeAttr::ObjCPreciseLifetimeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCPreciseLifetimeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCPreciseLifetimeAttr)
// 1: ObjCPreciseLifetimeAttr::Clone
std::string_view ObjCPreciseLifetimeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCPreciseLifetimeAttr *>(u.ObjCPreciseLifetimeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCPreciseLifetimeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCRequiresPropertyDefsAttr::ObjCRequiresPropertyDefsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRequiresPropertyDefsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCRequiresPropertyDefsAttr)
// 1: ObjCRequiresPropertyDefsAttr::Clone
std::string_view ObjCRequiresPropertyDefsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCRequiresPropertyDefsAttr *>(u.ObjCRequiresPropertyDefsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRequiresPropertyDefsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCRequiresSuperAttr::ObjCRequiresSuperAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRequiresSuperAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCRequiresSuperAttr)
// 1: ObjCRequiresSuperAttr::Clone
std::string_view ObjCRequiresSuperAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCRequiresSuperAttr *>(u.ObjCRequiresSuperAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRequiresSuperAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCReturnsInnerPointerAttr::ObjCReturnsInnerPointerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCReturnsInnerPointerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCReturnsInnerPointerAttr)
// 1: ObjCReturnsInnerPointerAttr::Clone
std::string_view ObjCReturnsInnerPointerAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCReturnsInnerPointerAttr *>(u.ObjCReturnsInnerPointerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCReturnsInnerPointerAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCRootClassAttr::ObjCRootClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRootClassAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCRootClassAttr)
// 1: ObjCRootClassAttr::Clone
std::string_view ObjCRootClassAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCRootClassAttr *>(u.ObjCRootClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRootClassAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCRuntimeNameAttr::ObjCRuntimeNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRuntimeNameAttr)
// 1: ObjCRuntimeNameAttr::Clone
std::string_view ObjCRuntimeNameAttr::MetadataName(void) const {
  auto &self = *const_cast<clang::ObjCRuntimeNameAttr *>(u.ObjCRuntimeNameAttr);
  decltype(auto) val = self.getMetadataName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ObjCRuntimeNameAttr::MetadataNameLength(void) const {
  auto &self = *const_cast<clang::ObjCRuntimeNameAttr *>(u.ObjCRuntimeNameAttr);
  decltype(auto) val = self.getMetadataNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ObjCRuntimeNameAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCRuntimeNameAttr *>(u.ObjCRuntimeNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRuntimeNameAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCRuntimeVisibleAttr::ObjCRuntimeVisibleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCRuntimeVisibleAttr)
// 1: ObjCRuntimeVisibleAttr::Clone
std::string_view ObjCRuntimeVisibleAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCRuntimeVisibleAttr *>(u.ObjCRuntimeVisibleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCRuntimeVisibleAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCSubclassingRestrictedAttr::ObjCSubclassingRestrictedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCSubclassingRestrictedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ObjCSubclassingRestrictedAttr)
// 1: ObjCSubclassingRestrictedAttr::Clone
std::string_view ObjCSubclassingRestrictedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCSubclassingRestrictedAttr *>(u.ObjCSubclassingRestrictedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCSubclassingRestrictedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLAccessAttr::OpenCLAccessAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLAccessAttr)
// 1: OpenCLAccessAttr::Clone
enum OpenCLAccessAttrSpelling OpenCLAccessAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLAccessAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OpenCLAccessAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLAccessAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool OpenCLAccessAttr::IsReadOnly(void) const {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.isReadOnly();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool OpenCLAccessAttr::IsReadWrite(void) const {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.isReadWrite();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool OpenCLAccessAttr::IsWriteOnly(void) const {
  auto &self = *const_cast<clang::OpenCLAccessAttr *>(u.OpenCLAccessAttr);
  decltype(auto) val = self.isWriteOnly();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLIntelReqdSubGroupSizeAttr::OpenCLIntelReqdSubGroupSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLIntelReqdSubGroupSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OpenCLIntelReqdSubGroupSizeAttr)
// 1: OpenCLIntelReqdSubGroupSizeAttr::Clone
std::string_view OpenCLIntelReqdSubGroupSizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLIntelReqdSubGroupSizeAttr *>(u.OpenCLIntelReqdSubGroupSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLIntelReqdSubGroupSizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t OpenCLIntelReqdSubGroupSizeAttr::SubGroupSize(void) const {
  auto &self = *const_cast<clang::OpenCLIntelReqdSubGroupSizeAttr *>(u.OpenCLIntelReqdSubGroupSizeAttr);
  decltype(auto) val = self.getSubGroupSize();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLKernelAttr::OpenCLKernelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLKernelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OpenCLKernelAttr)
// 1: OpenCLKernelAttr::Clone
std::string_view OpenCLKernelAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLKernelAttr *>(u.OpenCLKernelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLKernelAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OptimizeNoneAttr::OptimizeNoneAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OptimizeNoneAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OptimizeNoneAttr)
// 1: OptimizeNoneAttr::Clone
std::string_view OptimizeNoneAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OptimizeNoneAttr *>(u.OptimizeNoneAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OptimizeNoneAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OverloadableAttr::OverloadableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OverloadableAttr)
// 1: OverloadableAttr::Clone
std::string_view OverloadableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OverloadableAttr *>(u.OverloadableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OverloadableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OverrideAttr::OverrideAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OverrideAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OverrideAttr)
// 1: OverrideAttr::Clone
std::string_view OverrideAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OverrideAttr *>(u.OverrideAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OverrideAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OwnerAttr::OwnerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OwnerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, OwnerAttr)
// 1: OwnerAttr::Clone
::pasta::Type OwnerAttr::DerefType(void) const {
  auto &self = *const_cast<clang::OwnerAttr *>(u.OwnerAttr);
  decltype(auto) val = self.getDerefType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type OwnerAttr::DerefTypeToken(void) const {
  auto &self = *const_cast<clang::OwnerAttr *>(u.OwnerAttr);
  decltype(auto) val = self.getDerefTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "OwnerAttr::DerefTypeToken can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OwnerAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OwnerAttr *>(u.OwnerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OwnerAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum OwnershipAttrOwnershipKind OwnershipAttr::OwnKind(void) const {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.getOwnKind();
  return static_cast<::pasta::OwnershipAttrOwnershipKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

enum OwnershipAttrSpelling OwnershipAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OwnershipAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OwnershipAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OwnershipAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool OwnershipAttr::IsHolds(void) const {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.isHolds();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool OwnershipAttr::IsReturns(void) const {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.isReturns();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool OwnershipAttr::IsTakes(void) const {
  auto &self = *const_cast<clang::OwnershipAttr *>(u.OwnershipAttr);
  decltype(auto) val = self.isTakes();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

PackedAttr::PackedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PackedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PackedAttr)
// 1: PackedAttr::Clone
std::string_view PackedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PackedAttr *>(u.PackedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PackedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ParamTypestateAttr::ParamTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ParamTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ParamTypestateAttr)
// 1: ParamTypestateAttr::Clone
enum ParamTypestateAttrConsumedState ParamTypestateAttr::ParameterState(void) const {
  auto &self = *const_cast<clang::ParamTypestateAttr *>(u.ParamTypestateAttr);
  decltype(auto) val = self.getParamState();
  return static_cast<::pasta::ParamTypestateAttrConsumedState>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ParamTypestateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ParamTypestateAttr *>(u.ParamTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ParamTypestateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
::pasta::ParameterABI ParameterABIAttr::ABI(void) const {
  auto &self = *const_cast<clang::ParameterABIAttr *>(u.ParameterABIAttr);
  decltype(auto) val = self.getABI();
  return static_cast<enum ::pasta::ParameterABI>(val);
  throw std::runtime_error("The unreachable has been reached");
}

PascalAttr::PascalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PascalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PascalAttr)
// 1: PascalAttr::Clone
std::string_view PascalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PascalAttr *>(u.PascalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PascalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PassObjectSizeAttr::PassObjectSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PassObjectSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PassObjectSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, PassObjectSizeAttr)
// 1: PassObjectSizeAttr::Clone
enum PassObjectSizeAttrSpelling PassObjectSizeAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::PassObjectSizeAttr *>(u.PassObjectSizeAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::PassObjectSizeAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PassObjectSizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PassObjectSizeAttr *>(u.PassObjectSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PassObjectSizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

// 0: PassObjectSizeAttr::Type
bool PassObjectSizeAttr::IsDynamic(void) const {
  auto &self = *const_cast<clang::PassObjectSizeAttr *>(u.PassObjectSizeAttr);
  decltype(auto) val = self.isDynamic();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

PatchableFunctionEntryAttr::PatchableFunctionEntryAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PatchableFunctionEntryAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PatchableFunctionEntryAttr)
// 1: PatchableFunctionEntryAttr::Clone
uint32_t PatchableFunctionEntryAttr::Count(void) const {
  auto &self = *const_cast<clang::PatchableFunctionEntryAttr *>(u.PatchableFunctionEntryAttr);
  decltype(auto) val = self.getCount();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

// 0: PatchableFunctionEntryAttr::Offset
std::string_view PatchableFunctionEntryAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PatchableFunctionEntryAttr *>(u.PatchableFunctionEntryAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PatchableFunctionEntryAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PcsAttr::PcsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PcsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PcsAttr)
// 1: PcsAttr::Clone
enum PcsAttrPCSType PcsAttr::PCS(void) const {
  auto &self = *const_cast<clang::PcsAttr *>(u.PcsAttr);
  decltype(auto) val = self.getPCS();
  return static_cast<::pasta::PcsAttrPCSType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PcsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PcsAttr *>(u.PcsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PcsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PointerAttr::PointerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PointerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PointerAttr)
// 1: PointerAttr::Clone
::pasta::Type PointerAttr::DerefType(void) const {
  auto &self = *const_cast<clang::PointerAttr *>(u.PointerAttr);
  decltype(auto) val = self.getDerefType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type PointerAttr::DerefTypeToken(void) const {
  auto &self = *const_cast<clang::PointerAttr *>(u.PointerAttr);
  decltype(auto) val = self.getDerefTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "PointerAttr::DerefTypeToken can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PointerAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PointerAttr *>(u.PointerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PointerAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PragmaClangBSSSectionAttr::PragmaClangBSSSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangBSSSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangBSSSectionAttr)
// 1: PragmaClangBSSSectionAttr::Clone
std::string_view PragmaClangBSSSectionAttr::Name(void) const {
  auto &self = *const_cast<clang::PragmaClangBSSSectionAttr *>(u.PragmaClangBSSSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t PragmaClangBSSSectionAttr::NameLength(void) const {
  auto &self = *const_cast<clang::PragmaClangBSSSectionAttr *>(u.PragmaClangBSSSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PragmaClangBSSSectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PragmaClangBSSSectionAttr *>(u.PragmaClangBSSSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangBSSSectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PragmaClangDataSectionAttr::PragmaClangDataSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangDataSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangDataSectionAttr)
// 1: PragmaClangDataSectionAttr::Clone
std::string_view PragmaClangDataSectionAttr::Name(void) const {
  auto &self = *const_cast<clang::PragmaClangDataSectionAttr *>(u.PragmaClangDataSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t PragmaClangDataSectionAttr::NameLength(void) const {
  auto &self = *const_cast<clang::PragmaClangDataSectionAttr *>(u.PragmaClangDataSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PragmaClangDataSectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PragmaClangDataSectionAttr *>(u.PragmaClangDataSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangDataSectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PragmaClangRelroSectionAttr::PragmaClangRelroSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangRelroSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangRelroSectionAttr)
// 1: PragmaClangRelroSectionAttr::Clone
std::string_view PragmaClangRelroSectionAttr::Name(void) const {
  auto &self = *const_cast<clang::PragmaClangRelroSectionAttr *>(u.PragmaClangRelroSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t PragmaClangRelroSectionAttr::NameLength(void) const {
  auto &self = *const_cast<clang::PragmaClangRelroSectionAttr *>(u.PragmaClangRelroSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PragmaClangRelroSectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PragmaClangRelroSectionAttr *>(u.PragmaClangRelroSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangRelroSectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PragmaClangRodataSectionAttr::PragmaClangRodataSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangRodataSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangRodataSectionAttr)
// 1: PragmaClangRodataSectionAttr::Clone
std::string_view PragmaClangRodataSectionAttr::Name(void) const {
  auto &self = *const_cast<clang::PragmaClangRodataSectionAttr *>(u.PragmaClangRodataSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t PragmaClangRodataSectionAttr::NameLength(void) const {
  auto &self = *const_cast<clang::PragmaClangRodataSectionAttr *>(u.PragmaClangRodataSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PragmaClangRodataSectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PragmaClangRodataSectionAttr *>(u.PragmaClangRodataSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangRodataSectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PragmaClangTextSectionAttr::PragmaClangTextSectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PragmaClangTextSectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PragmaClangTextSectionAttr)
// 1: PragmaClangTextSectionAttr::Clone
std::string_view PragmaClangTextSectionAttr::Name(void) const {
  auto &self = *const_cast<clang::PragmaClangTextSectionAttr *>(u.PragmaClangTextSectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t PragmaClangTextSectionAttr::NameLength(void) const {
  auto &self = *const_cast<clang::PragmaClangTextSectionAttr *>(u.PragmaClangTextSectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PragmaClangTextSectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PragmaClangTextSectionAttr *>(u.PragmaClangTextSectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PragmaClangTextSectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PreferredNameAttr::PreferredNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PreferredNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PreferredNameAttr)
// 1: PreferredNameAttr::Clone
std::string_view PreferredNameAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PreferredNameAttr *>(u.PreferredNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PreferredNameAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type PreferredNameAttr::TypedefType(void) const {
  auto &self = *const_cast<clang::PreferredNameAttr *>(u.PreferredNameAttr);
  decltype(auto) val = self.getTypedefType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type PreferredNameAttr::TypedefTypeToken(void) const {
  auto &self = *const_cast<clang::PreferredNameAttr *>(u.PreferredNameAttr);
  decltype(auto) val = self.getTypedefTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "PreferredNameAttr::TypedefTypeToken can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PreserveAllAttr::PreserveAllAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PreserveAllAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PreserveAllAttr)
// 1: PreserveAllAttr::Clone
std::string_view PreserveAllAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PreserveAllAttr *>(u.PreserveAllAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PreserveAllAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PreserveMostAttr::PreserveMostAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PreserveMostAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PreserveMostAttr)
// 1: PreserveMostAttr::Clone
std::string_view PreserveMostAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PreserveMostAttr *>(u.PreserveMostAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PreserveMostAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PtGuardedByAttr::PtGuardedByAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PtGuardedByAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PtGuardedByAttr)
// 1: PtGuardedByAttr::Clone
::pasta::Expr PtGuardedByAttr::Argument(void) const {
  auto &self = *const_cast<clang::PtGuardedByAttr *>(u.PtGuardedByAttr);
  decltype(auto) val = self.getArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "PtGuardedByAttr::Argument can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view PtGuardedByAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PtGuardedByAttr *>(u.PtGuardedByAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PtGuardedByAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PtGuardedVarAttr::PtGuardedVarAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PtGuardedVarAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PtGuardedVarAttr)
// 1: PtGuardedVarAttr::Clone
std::string_view PtGuardedVarAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PtGuardedVarAttr *>(u.PtGuardedVarAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PtGuardedVarAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

PureAttr::PureAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, PureAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, PureAttr)
// 1: PureAttr::Clone
std::string_view PureAttr::Spelling(void) const {
  auto &self = *const_cast<clang::PureAttr *>(u.PureAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "PureAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

RISCVInterruptAttr::RISCVInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RISCVInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RISCVInterruptAttr)
// 1: RISCVInterruptAttr::Clone
enum RISCVInterruptAttrInterruptType RISCVInterruptAttr::Interrupt(void) const {
  auto &self = *const_cast<clang::RISCVInterruptAttr *>(u.RISCVInterruptAttr);
  decltype(auto) val = self.getInterrupt();
  return static_cast<::pasta::RISCVInterruptAttrInterruptType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view RISCVInterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RISCVInterruptAttr *>(u.RISCVInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RISCVInterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

RandomizeLayoutAttr::RandomizeLayoutAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RandomizeLayoutAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RandomizeLayoutAttr)
// 1: RandomizeLayoutAttr::Clone
std::string_view RandomizeLayoutAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RandomizeLayoutAttr *>(u.RandomizeLayoutAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RandomizeLayoutAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ReadOnlyPlacementAttr::ReadOnlyPlacementAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReadOnlyPlacementAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReadOnlyPlacementAttr)
// 1: ReadOnlyPlacementAttr::Clone
std::string_view ReadOnlyPlacementAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReadOnlyPlacementAttr *>(u.ReadOnlyPlacementAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReadOnlyPlacementAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

RegCallAttr::RegCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RegCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RegCallAttr)
// 1: RegCallAttr::Clone
std::string_view RegCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RegCallAttr *>(u.RegCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RegCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ReinitializesAttr::ReinitializesAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReinitializesAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReinitializesAttr)
// 1: ReinitializesAttr::Clone
std::string_view ReinitializesAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReinitializesAttr *>(u.ReinitializesAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReinitializesAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum ReleaseCapabilityAttrSpelling ReleaseCapabilityAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ReleaseCapabilityAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ReleaseCapabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReleaseCapabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool ReleaseCapabilityAttr::IsGeneric(void) const {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.isGeneric();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool ReleaseCapabilityAttr::IsShared(void) const {
  auto &self = *const_cast<clang::ReleaseCapabilityAttr *>(u.ReleaseCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

ReleaseHandleAttr::ReleaseHandleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReleaseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReleaseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, ReleaseHandleAttr)
// 1: ReleaseHandleAttr::Clone
std::string_view ReleaseHandleAttr::HandleType(void) const {
  auto &self = *const_cast<clang::ReleaseHandleAttr *>(u.ReleaseHandleAttr);
  decltype(auto) val = self.getHandleType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ReleaseHandleAttr::HandleTypeLength(void) const {
  auto &self = *const_cast<clang::ReleaseHandleAttr *>(u.ReleaseHandleAttr);
  decltype(auto) val = self.getHandleTypeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ReleaseHandleAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReleaseHandleAttr *>(u.ReleaseHandleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReleaseHandleAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

RenderScriptKernelAttr::RenderScriptKernelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RenderScriptKernelAttr)
// 1: RenderScriptKernelAttr::Clone
std::string_view RenderScriptKernelAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RenderScriptKernelAttr *>(u.RenderScriptKernelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RenderScriptKernelAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ReqdWorkGroupSizeAttr::ReqdWorkGroupSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReqdWorkGroupSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReqdWorkGroupSizeAttr)
// 1: ReqdWorkGroupSizeAttr::Clone
std::string_view ReqdWorkGroupSizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReqdWorkGroupSizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ReqdWorkGroupSizeAttr::XDim(void) const {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getXDim();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ReqdWorkGroupSizeAttr::YDim(void) const {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getYDim();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ReqdWorkGroupSizeAttr::ZDim(void) const {
  auto &self = *const_cast<clang::ReqdWorkGroupSizeAttr *>(u.ReqdWorkGroupSizeAttr);
  decltype(auto) val = self.getZDim();
  return val;
  throw std::runtime_error("The unreachable has been reached");
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
enum RequiresCapabilityAttrSpelling RequiresCapabilityAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::RequiresCapabilityAttr *>(u.RequiresCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::RequiresCapabilityAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view RequiresCapabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RequiresCapabilityAttr *>(u.RequiresCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RequiresCapabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool RequiresCapabilityAttr::IsShared(void) const {
  auto &self = *const_cast<clang::RequiresCapabilityAttr *>(u.RequiresCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

RestrictAttr::RestrictAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RestrictAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RestrictAttr)
// 1: RestrictAttr::Clone
enum RestrictAttrSpelling RestrictAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::RestrictAttr *>(u.RestrictAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::RestrictAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view RestrictAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RestrictAttr *>(u.RestrictAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RestrictAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

RetainAttr::RetainAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, RetainAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, RetainAttr)
// 1: RetainAttr::Clone
std::string_view RetainAttr::Spelling(void) const {
  auto &self = *const_cast<clang::RetainAttr *>(u.RetainAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "RetainAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ReturnTypestateAttr::ReturnTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReturnTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReturnTypestateAttr)
// 1: ReturnTypestateAttr::Clone
std::string_view ReturnTypestateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReturnTypestateAttr *>(u.ReturnTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReturnTypestateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum ReturnTypestateAttrConsumedState ReturnTypestateAttr::State(void) const {
  auto &self = *const_cast<clang::ReturnTypestateAttr *>(u.ReturnTypestateAttr);
  decltype(auto) val = self.getState();
  return static_cast<::pasta::ReturnTypestateAttrConsumedState>(val);
  throw std::runtime_error("The unreachable has been reached");
}

ReturnsNonNullAttr::ReturnsNonNullAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReturnsNonNullAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReturnsNonNullAttr)
// 1: ReturnsNonNullAttr::Clone
std::string_view ReturnsNonNullAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReturnsNonNullAttr *>(u.ReturnsNonNullAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReturnsNonNullAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ReturnsTwiceAttr::ReturnsTwiceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ReturnsTwiceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ReturnsTwiceAttr)
// 1: ReturnsTwiceAttr::Clone
std::string_view ReturnsTwiceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ReturnsTwiceAttr *>(u.ReturnsTwiceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ReturnsTwiceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SYCLKernelAttr::SYCLKernelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SYCLKernelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SYCLKernelAttr)
// 1: SYCLKernelAttr::Clone
std::string_view SYCLKernelAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SYCLKernelAttr *>(u.SYCLKernelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SYCLKernelAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SYCLSpecialClassAttr::SYCLSpecialClassAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SYCLSpecialClassAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SYCLSpecialClassAttr)
// 1: SYCLSpecialClassAttr::Clone
std::string_view SYCLSpecialClassAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SYCLSpecialClassAttr *>(u.SYCLSpecialClassAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SYCLSpecialClassAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ScopedLockableAttr::ScopedLockableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ScopedLockableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ScopedLockableAttr)
// 1: ScopedLockableAttr::Clone
std::string_view ScopedLockableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ScopedLockableAttr *>(u.ScopedLockableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ScopedLockableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SectionAttr::SectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SectionAttr)
// 1: SectionAttr::Clone
std::string_view SectionAttr::Name(void) const {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t SectionAttr::NameLength(void) const {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum SectionAttrSpelling SectionAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::SectionAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SectionAttr *>(u.SectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SelectAnyAttr::SelectAnyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SelectAnyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SelectAnyAttr)
// 1: SelectAnyAttr::Clone
std::string_view SelectAnyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SelectAnyAttr *>(u.SelectAnyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SelectAnyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SentinelAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SentinelAttr *>(u.SentinelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SentinelAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SetTypestateAttr::SetTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SetTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SetTypestateAttr)
// 1: SetTypestateAttr::Clone
enum SetTypestateAttrConsumedState SetTypestateAttr::NewState(void) const {
  auto &self = *const_cast<clang::SetTypestateAttr *>(u.SetTypestateAttr);
  decltype(auto) val = self.getNewState();
  return static_cast<::pasta::SetTypestateAttrConsumedState>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SetTypestateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SetTypestateAttr *>(u.SetTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SetTypestateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SharedTrylockFunctionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SharedTrylockFunctionAttr *>(u.SharedTrylockFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SharedTrylockFunctionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr SharedTrylockFunctionAttr::SuccessValue(void) const {
  auto &self = *const_cast<clang::SharedTrylockFunctionAttr *>(u.SharedTrylockFunctionAttr);
  decltype(auto) val = self.getSuccessValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "SharedTrylockFunctionAttr::SuccessValue can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SpeculativeLoadHardeningAttr::SpeculativeLoadHardeningAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SpeculativeLoadHardeningAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SpeculativeLoadHardeningAttr)
// 1: SpeculativeLoadHardeningAttr::Clone
std::string_view SpeculativeLoadHardeningAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SpeculativeLoadHardeningAttr *>(u.SpeculativeLoadHardeningAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SpeculativeLoadHardeningAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

StandaloneDebugAttr::StandaloneDebugAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StandaloneDebugAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, StandaloneDebugAttr)
// 1: StandaloneDebugAttr::Clone
std::string_view StandaloneDebugAttr::Spelling(void) const {
  auto &self = *const_cast<clang::StandaloneDebugAttr *>(u.StandaloneDebugAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StandaloneDebugAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

StdCallAttr::StdCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StdCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, StdCallAttr)
// 1: StdCallAttr::Clone
std::string_view StdCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::StdCallAttr *>(u.StdCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StdCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view StrictFPAttr::Spelling(void) const {
  auto &self = *const_cast<clang::StrictFPAttr *>(u.StrictFPAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StrictFPAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

StrictGuardStackCheckAttr::StrictGuardStackCheckAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, StrictGuardStackCheckAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, StrictGuardStackCheckAttr)
// 1: StrictGuardStackCheckAttr::Clone
std::string_view StrictGuardStackCheckAttr::Spelling(void) const {
  auto &self = *const_cast<clang::StrictGuardStackCheckAttr *>(u.StrictGuardStackCheckAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "StrictGuardStackCheckAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SuppressAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SuppressAttr *>(u.SuppressAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SuppressAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftAsyncAttr::SwiftAsyncAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncAttr)
// 1: SwiftAsyncAttr::Clone
// 0: SwiftAsyncAttr::CompletionHandlerIndex
enum SwiftAsyncAttrKind SwiftAsyncAttr::Kind(void) const {
  auto &self = *const_cast<clang::SwiftAsyncAttr *>(u.SwiftAsyncAttr);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::SwiftAsyncAttrKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftAsyncAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftAsyncAttr *>(u.SwiftAsyncAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftAsyncCallAttr::SwiftAsyncCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncCallAttr)
// 1: SwiftAsyncCallAttr::Clone
std::string_view SwiftAsyncCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftAsyncCallAttr *>(u.SwiftAsyncCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SwiftAsyncContextAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftAsyncContextAttr *>(u.SwiftAsyncContextAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncContextAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftAsyncErrorAttr::SwiftAsyncErrorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncErrorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncErrorAttr)
// 1: SwiftAsyncErrorAttr::Clone
enum SwiftAsyncErrorAttrConventionKind SwiftAsyncErrorAttr::Convention(void) const {
  auto &self = *const_cast<clang::SwiftAsyncErrorAttr *>(u.SwiftAsyncErrorAttr);
  decltype(auto) val = self.getConvention();
  return static_cast<::pasta::SwiftAsyncErrorAttrConventionKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t SwiftAsyncErrorAttr::HandlerParameterIndex(void) const {
  auto &self = *const_cast<clang::SwiftAsyncErrorAttr *>(u.SwiftAsyncErrorAttr);
  decltype(auto) val = self.getHandlerParamIdx();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftAsyncErrorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftAsyncErrorAttr *>(u.SwiftAsyncErrorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncErrorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftAsyncNameAttr::SwiftAsyncNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAsyncNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAsyncNameAttr)
// 1: SwiftAsyncNameAttr::Clone
std::string_view SwiftAsyncNameAttr::Name(void) const {
  auto &self = *const_cast<clang::SwiftAsyncNameAttr *>(u.SwiftAsyncNameAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t SwiftAsyncNameAttr::NameLength(void) const {
  auto &self = *const_cast<clang::SwiftAsyncNameAttr *>(u.SwiftAsyncNameAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftAsyncNameAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftAsyncNameAttr *>(u.SwiftAsyncNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAsyncNameAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftAttrAttr::SwiftAttrAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftAttrAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftAttrAttr)
// 1: SwiftAttrAttr::Clone
std::string_view SwiftAttrAttr::Attribute(void) const {
  auto &self = *const_cast<clang::SwiftAttrAttr *>(u.SwiftAttrAttr);
  decltype(auto) val = self.getAttribute();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t SwiftAttrAttr::AttributeLength(void) const {
  auto &self = *const_cast<clang::SwiftAttrAttr *>(u.SwiftAttrAttr);
  decltype(auto) val = self.getAttributeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftAttrAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftAttrAttr *>(u.SwiftAttrAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftAttrAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftBridgeAttr::SwiftBridgeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftBridgeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftBridgeAttr)
// 1: SwiftBridgeAttr::Clone
std::string_view SwiftBridgeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftBridgeAttr *>(u.SwiftBridgeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftBridgeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftBridgeAttr::SwiftType(void) const {
  auto &self = *const_cast<clang::SwiftBridgeAttr *>(u.SwiftBridgeAttr);
  decltype(auto) val = self.getSwiftType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t SwiftBridgeAttr::SwiftTypeLength(void) const {
  auto &self = *const_cast<clang::SwiftBridgeAttr *>(u.SwiftBridgeAttr);
  decltype(auto) val = self.getSwiftTypeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

SwiftBridgedTypedefAttr::SwiftBridgedTypedefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftBridgedTypedefAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftBridgedTypedefAttr)
// 1: SwiftBridgedTypedefAttr::Clone
std::string_view SwiftBridgedTypedefAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftBridgedTypedefAttr *>(u.SwiftBridgedTypedefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftBridgedTypedefAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftCallAttr::SwiftCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftCallAttr)
// 1: SwiftCallAttr::Clone
std::string_view SwiftCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftCallAttr *>(u.SwiftCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SwiftContextAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftContextAttr *>(u.SwiftContextAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftContextAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftErrorAttr::SwiftErrorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftErrorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftErrorAttr)
// 1: SwiftErrorAttr::Clone
enum SwiftErrorAttrConventionKind SwiftErrorAttr::Convention(void) const {
  auto &self = *const_cast<clang::SwiftErrorAttr *>(u.SwiftErrorAttr);
  decltype(auto) val = self.getConvention();
  return static_cast<::pasta::SwiftErrorAttrConventionKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftErrorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftErrorAttr *>(u.SwiftErrorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftErrorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SwiftErrorResultAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftErrorResultAttr *>(u.SwiftErrorResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftErrorResultAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view SwiftIndirectResultAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftIndirectResultAttr *>(u.SwiftIndirectResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftIndirectResultAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftNameAttr::SwiftNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftNameAttr)
// 1: SwiftNameAttr::Clone
std::string_view SwiftNameAttr::Name(void) const {
  auto &self = *const_cast<clang::SwiftNameAttr *>(u.SwiftNameAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t SwiftNameAttr::NameLength(void) const {
  auto &self = *const_cast<clang::SwiftNameAttr *>(u.SwiftNameAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftNameAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftNameAttr *>(u.SwiftNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftNameAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftNewTypeAttr::SwiftNewTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftNewTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftNewTypeAttr)
// 1: SwiftNewTypeAttr::Clone
enum SwiftNewTypeAttrNewtypeKind SwiftNewTypeAttr::NewtypeKind(void) const {
  auto &self = *const_cast<clang::SwiftNewTypeAttr *>(u.SwiftNewTypeAttr);
  decltype(auto) val = self.getNewtypeKind();
  return static_cast<::pasta::SwiftNewTypeAttrNewtypeKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

enum SwiftNewTypeAttrSpelling SwiftNewTypeAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::SwiftNewTypeAttr *>(u.SwiftNewTypeAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::SwiftNewTypeAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view SwiftNewTypeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftNewTypeAttr *>(u.SwiftNewTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftNewTypeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftObjCMembersAttr::SwiftObjCMembersAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftObjCMembersAttr)
// 1: SwiftObjCMembersAttr::Clone
std::string_view SwiftObjCMembersAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftObjCMembersAttr *>(u.SwiftObjCMembersAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftObjCMembersAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SwiftPrivateAttr::SwiftPrivateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SwiftPrivateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SwiftPrivateAttr)
// 1: SwiftPrivateAttr::Clone
std::string_view SwiftPrivateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SwiftPrivateAttr *>(u.SwiftPrivateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SwiftPrivateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SysVABIAttr::SysVABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SysVABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, SysVABIAttr)
// 1: SysVABIAttr::Clone
std::string_view SysVABIAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SysVABIAttr *>(u.SysVABIAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SysVABIAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TLSModelAttr::TLSModelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TLSModelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TLSModelAttr)
// 1: TLSModelAttr::Clone
std::string_view TLSModelAttr::Model(void) const {
  auto &self = *const_cast<clang::TLSModelAttr *>(u.TLSModelAttr);
  decltype(auto) val = self.getModel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t TLSModelAttr::ModelLength(void) const {
  auto &self = *const_cast<clang::TLSModelAttr *>(u.TLSModelAttr);
  decltype(auto) val = self.getModelLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TLSModelAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TLSModelAttr *>(u.TLSModelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TLSModelAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TargetAttr::TargetAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TargetAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TargetAttr)
// 1: TargetAttr::Clone
std::string_view TargetAttr::Architecture(void) const {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getArchitecture();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TargetAttr::FeaturesString(void) const {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getFeaturesStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t TargetAttr::FeaturesStringLength(void) const {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getFeaturesStrLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TargetAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TargetAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool TargetAttr::IsDefaultVersion(void) const {
  auto &self = *const_cast<clang::TargetAttr *>(u.TargetAttr);
  decltype(auto) val = self.isDefaultVersion();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

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
std::string_view TargetClonesAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TargetClonesAttr *>(u.TargetClonesAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TargetClonesAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

// 1: TargetClonesAttr::IsFirstOfVersion
TargetVersionAttr::TargetVersionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TargetVersionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TargetVersionAttr)
// 1: TargetVersionAttr::Clone
std::string_view TargetVersionAttr::Name(void) const {
  auto &self = *const_cast<clang::TargetVersionAttr *>(u.TargetVersionAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TargetVersionAttr::NamesString(void) const {
  auto &self = *const_cast<clang::TargetVersionAttr *>(u.TargetVersionAttr);
  decltype(auto) val = self.getNamesStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t TargetVersionAttr::NamesStringLength(void) const {
  auto &self = *const_cast<clang::TargetVersionAttr *>(u.TargetVersionAttr);
  decltype(auto) val = self.getNamesStrLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TargetVersionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TargetVersionAttr *>(u.TargetVersionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TargetVersionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool TargetVersionAttr::IsDefaultVersion(void) const {
  auto &self = *const_cast<clang::TargetVersionAttr *>(u.TargetVersionAttr);
  decltype(auto) val = self.isDefaultVersion();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

TestTypestateAttr::TestTypestateAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TestTypestateAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TestTypestateAttr)
// 1: TestTypestateAttr::Clone
std::string_view TestTypestateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TestTypestateAttr *>(u.TestTypestateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TestTypestateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum TestTypestateAttrConsumedState TestTypestateAttr::TestState(void) const {
  auto &self = *const_cast<clang::TestTypestateAttr *>(u.TestTypestateAttr);
  decltype(auto) val = self.getTestState();
  return static_cast<::pasta::TestTypestateAttrConsumedState>(val);
  throw std::runtime_error("The unreachable has been reached");
}

ThisCallAttr::ThisCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ThisCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ThisCallAttr)
// 1: ThisCallAttr::Clone
std::string_view ThisCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ThisCallAttr *>(u.ThisCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ThisCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ThreadAttr::ThreadAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ThreadAttr)
// 1: ThreadAttr::Clone
std::string_view ThreadAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ThreadAttr *>(u.ThreadAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ThreadAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TransparentUnionAttr::TransparentUnionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TransparentUnionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TransparentUnionAttr)
// 1: TransparentUnionAttr::Clone
std::string_view TransparentUnionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TransparentUnionAttr *>(u.TransparentUnionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TransparentUnionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TrivialABIAttr::TrivialABIAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TrivialABIAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TrivialABIAttr)
// 1: TrivialABIAttr::Clone
std::string_view TrivialABIAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TrivialABIAttr *>(u.TrivialABIAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TrivialABIAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum TryAcquireCapabilityAttrSpelling TryAcquireCapabilityAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::TryAcquireCapabilityAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TryAcquireCapabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TryAcquireCapabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr TryAcquireCapabilityAttr::SuccessValue(void) const {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.getSuccessValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "TryAcquireCapabilityAttr::SuccessValue can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool TryAcquireCapabilityAttr::IsShared(void) const {
  auto &self = *const_cast<clang::TryAcquireCapabilityAttr *>(u.TryAcquireCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

TypeAttr::TypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, AddressSpaceAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, AnnotateTypeAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, BTFTypeTagAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, CmseNSCallAttr)
PASTA_DEFINE_DERIVED_OPERATORS(TypeAttr, HLSLGroupSharedAddressSpaceAttr)
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
std::string_view TypeNonNullAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TypeNonNullAttr *>(u.TypeNonNullAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNonNullAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TypeNullUnspecifiedAttr::TypeNullUnspecifiedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNullUnspecifiedAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNullUnspecifiedAttr)
// 1: TypeNullUnspecifiedAttr::Clone
std::string_view TypeNullUnspecifiedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TypeNullUnspecifiedAttr *>(u.TypeNullUnspecifiedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNullUnspecifiedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TypeNullableAttr::TypeNullableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNullableAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNullableAttr)
// 1: TypeNullableAttr::Clone
std::string_view TypeNullableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TypeNullableAttr *>(u.TypeNullableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNullableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TypeNullableResultAttr::TypeNullableResultAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeNullableResultAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, TypeNullableResultAttr)
// 1: TypeNullableResultAttr::Clone
std::string_view TypeNullableResultAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TypeNullableResultAttr *>(u.TypeNullableResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeNullableResultAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TypeTagForDatatypeAttr::TypeTagForDatatypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeTagForDatatypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TypeTagForDatatypeAttr)
// 1: TypeTagForDatatypeAttr::Clone
// 0: TypeTagForDatatypeAttr::ArgumentKind
bool TypeTagForDatatypeAttr::LayoutCompatible(void) const {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getLayoutCompatible();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type TypeTagForDatatypeAttr::MatchingCType(void) const {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getMatchingCType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type TypeTagForDatatypeAttr::MatchingCTypeToken(void) const {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getMatchingCTypeLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "TypeTagForDatatypeAttr::MatchingCTypeToken can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool TypeTagForDatatypeAttr::MustBeNull(void) const {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getMustBeNull();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view TypeTagForDatatypeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TypeTagForDatatypeAttr *>(u.TypeTagForDatatypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeTagForDatatypeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

TypeVisibilityAttr::TypeVisibilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, TypeVisibilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, TypeVisibilityAttr)
// 1: TypeVisibilityAttr::Clone
std::string_view TypeVisibilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::TypeVisibilityAttr *>(u.TypeVisibilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "TypeVisibilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum TypeVisibilityAttrVisibilityType TypeVisibilityAttr::Visibility(void) const {
  auto &self = *const_cast<clang::TypeVisibilityAttr *>(u.TypeVisibilityAttr);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::TypeVisibilityAttrVisibilityType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

UPtrAttr::UPtrAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UPtrAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, UPtrAttr)
// 1: UPtrAttr::Clone
std::string_view UPtrAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UPtrAttr *>(u.UPtrAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UPtrAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UnavailableAttr::UnavailableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UnavailableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UnavailableAttr)
// 1: UnavailableAttr::Clone
enum UnavailableAttrImplicitReason UnavailableAttr::ImplicitReason(void) const {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getImplicitReason();
  return static_cast<::pasta::UnavailableAttrImplicitReason>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view UnavailableAttr::Message(void) const {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t UnavailableAttr::MessageLength(void) const {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view UnavailableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UnavailableAttr *>(u.UnavailableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UnavailableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UninitializedAttr::UninitializedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UninitializedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UninitializedAttr)
// 1: UninitializedAttr::Clone
std::string_view UninitializedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UninitializedAttr *>(u.UninitializedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UninitializedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UnlikelyAttr::UnlikelyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UnlikelyAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, UnlikelyAttr)
// 1: UnlikelyAttr::Clone
std::string_view UnlikelyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UnlikelyAttr *>(u.UnlikelyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UnlikelyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UnusedAttr::UnusedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UnusedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UnusedAttr)
// 1: UnusedAttr::Clone
enum UnusedAttrSpelling UnusedAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::UnusedAttr *>(u.UnusedAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::UnusedAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view UnusedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UnusedAttr *>(u.UnusedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UnusedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UseHandleAttr::UseHandleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UseHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, UseHandleAttr)
// 1: UseHandleAttr::Clone
std::string_view UseHandleAttr::HandleType(void) const {
  auto &self = *const_cast<clang::UseHandleAttr *>(u.UseHandleAttr);
  decltype(auto) val = self.getHandleType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t UseHandleAttr::HandleTypeLength(void) const {
  auto &self = *const_cast<clang::UseHandleAttr *>(u.UseHandleAttr);
  decltype(auto) val = self.getHandleTypeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view UseHandleAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UseHandleAttr *>(u.UseHandleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UseHandleAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UsedAttr::UsedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UsedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UsedAttr)
// 1: UsedAttr::Clone
std::string_view UsedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UsedAttr *>(u.UsedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UsedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UsingIfExistsAttr::UsingIfExistsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UsingIfExistsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UsingIfExistsAttr)
// 1: UsingIfExistsAttr::Clone
std::string_view UsingIfExistsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UsingIfExistsAttr *>(u.UsingIfExistsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UsingIfExistsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

UuidAttr::UuidAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, UuidAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, UuidAttr)
// 1: UuidAttr::Clone
std::string_view UuidAttr::Guid(void) const {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getGuid();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::MSGuidDecl UuidAttr::GuidDeclaration(void) const {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getGuidDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::MSGuidDecl>(ast, val);
  }
  assert(false && "UuidAttr::GuidDeclaration can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t UuidAttr::GuidLength(void) const {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getGuidLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view UuidAttr::Spelling(void) const {
  auto &self = *const_cast<clang::UuidAttr *>(u.UuidAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "UuidAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

VecReturnAttr::VecReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VecReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VecReturnAttr)
// 1: VecReturnAttr::Clone
std::string_view VecReturnAttr::Spelling(void) const {
  auto &self = *const_cast<clang::VecReturnAttr *>(u.VecReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VecReturnAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

VecTypeHintAttr::VecTypeHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VecTypeHintAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VecTypeHintAttr)
// 1: VecTypeHintAttr::Clone
std::string_view VecTypeHintAttr::Spelling(void) const {
  auto &self = *const_cast<clang::VecTypeHintAttr *>(u.VecTypeHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VecTypeHintAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type VecTypeHintAttr::TypeHint(void) const {
  auto &self = *const_cast<clang::VecTypeHintAttr *>(u.VecTypeHintAttr);
  decltype(auto) val = self.getTypeHint();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type VecTypeHintAttr::TypeHintToken(void) const {
  auto &self = *const_cast<clang::VecTypeHintAttr *>(u.VecTypeHintAttr);
  decltype(auto) val = self.getTypeHintLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "VecTypeHintAttr::TypeHintToken can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

VectorCallAttr::VectorCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VectorCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VectorCallAttr)
// 1: VectorCallAttr::Clone
std::string_view VectorCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::VectorCallAttr *>(u.VectorCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VectorCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

VisibilityAttr::VisibilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, VisibilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, VisibilityAttr)
// 1: VisibilityAttr::Clone
std::string_view VisibilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::VisibilityAttr *>(u.VisibilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "VisibilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum VisibilityAttrVisibilityType VisibilityAttr::Visibility(void) const {
  auto &self = *const_cast<clang::VisibilityAttr *>(u.VisibilityAttr);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::VisibilityAttrVisibilityType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

WarnUnusedAttr::WarnUnusedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WarnUnusedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WarnUnusedAttr)
// 1: WarnUnusedAttr::Clone
std::string_view WarnUnusedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WarnUnusedAttr *>(u.WarnUnusedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WarnUnusedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WarnUnusedResultAttr::WarnUnusedResultAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WarnUnusedResultAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WarnUnusedResultAttr)
bool WarnUnusedResultAttr::IsCXX11NoDiscard(void) const {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.IsCXX11NoDiscard();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

// 1: WarnUnusedResultAttr::Clone
std::string_view WarnUnusedResultAttr::Message(void) const {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WarnUnusedResultAttr::MessageLength(void) const {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum WarnUnusedResultAttrSpelling WarnUnusedResultAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::WarnUnusedResultAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view WarnUnusedResultAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WarnUnusedResultAttr *>(u.WarnUnusedResultAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WarnUnusedResultAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WeakAttr::WeakAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WeakAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WeakAttr)
// 1: WeakAttr::Clone
std::string_view WeakAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WeakAttr *>(u.WeakAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WeakAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WeakImportAttr::WeakImportAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WeakImportAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WeakImportAttr)
// 1: WeakImportAttr::Clone
std::string_view WeakImportAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WeakImportAttr *>(u.WeakImportAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WeakImportAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WeakRefAttr::WeakRefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WeakRefAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WeakRefAttr)
// 1: WeakRefAttr::Clone
std::string_view WeakRefAttr::Aliasee(void) const {
  auto &self = *const_cast<clang::WeakRefAttr *>(u.WeakRefAttr);
  decltype(auto) val = self.getAliasee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WeakRefAttr::AliaseeLength(void) const {
  auto &self = *const_cast<clang::WeakRefAttr *>(u.WeakRefAttr);
  decltype(auto) val = self.getAliaseeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view WeakRefAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WeakRefAttr *>(u.WeakRefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WeakRefAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WebAssemblyExportNameAttr::WebAssemblyExportNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WebAssemblyExportNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WebAssemblyExportNameAttr)
// 1: WebAssemblyExportNameAttr::Clone
std::string_view WebAssemblyExportNameAttr::ExportName(void) const {
  auto &self = *const_cast<clang::WebAssemblyExportNameAttr *>(u.WebAssemblyExportNameAttr);
  decltype(auto) val = self.getExportName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WebAssemblyExportNameAttr::ExportNameLength(void) const {
  auto &self = *const_cast<clang::WebAssemblyExportNameAttr *>(u.WebAssemblyExportNameAttr);
  decltype(auto) val = self.getExportNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view WebAssemblyExportNameAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WebAssemblyExportNameAttr *>(u.WebAssemblyExportNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WebAssemblyExportNameAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WebAssemblyImportModuleAttr::WebAssemblyImportModuleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WebAssemblyImportModuleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WebAssemblyImportModuleAttr)
// 1: WebAssemblyImportModuleAttr::Clone
std::string_view WebAssemblyImportModuleAttr::ImportModule(void) const {
  auto &self = *const_cast<clang::WebAssemblyImportModuleAttr *>(u.WebAssemblyImportModuleAttr);
  decltype(auto) val = self.getImportModule();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WebAssemblyImportModuleAttr::ImportModuleLength(void) const {
  auto &self = *const_cast<clang::WebAssemblyImportModuleAttr *>(u.WebAssemblyImportModuleAttr);
  decltype(auto) val = self.getImportModuleLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view WebAssemblyImportModuleAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WebAssemblyImportModuleAttr *>(u.WebAssemblyImportModuleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WebAssemblyImportModuleAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WebAssemblyImportNameAttr::WebAssemblyImportNameAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WebAssemblyImportNameAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WebAssemblyImportNameAttr)
// 1: WebAssemblyImportNameAttr::Clone
std::string_view WebAssemblyImportNameAttr::ImportName(void) const {
  auto &self = *const_cast<clang::WebAssemblyImportNameAttr *>(u.WebAssemblyImportNameAttr);
  decltype(auto) val = self.getImportName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WebAssemblyImportNameAttr::ImportNameLength(void) const {
  auto &self = *const_cast<clang::WebAssemblyImportNameAttr *>(u.WebAssemblyImportNameAttr);
  decltype(auto) val = self.getImportNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view WebAssemblyImportNameAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WebAssemblyImportNameAttr *>(u.WebAssemblyImportNameAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WebAssemblyImportNameAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

WorkGroupSizeHintAttr::WorkGroupSizeHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, WorkGroupSizeHintAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, WorkGroupSizeHintAttr)
// 1: WorkGroupSizeHintAttr::Clone
std::string_view WorkGroupSizeHintAttr::Spelling(void) const {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "WorkGroupSizeHintAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WorkGroupSizeHintAttr::XDim(void) const {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getXDim();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WorkGroupSizeHintAttr::YDim(void) const {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getYDim();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t WorkGroupSizeHintAttr::ZDim(void) const {
  auto &self = *const_cast<clang::WorkGroupSizeHintAttr *>(u.WorkGroupSizeHintAttr);
  decltype(auto) val = self.getZDim();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

X86ForceAlignArgPointerAttr::X86ForceAlignArgPointerAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, X86ForceAlignArgPointerAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, X86ForceAlignArgPointerAttr)
// 1: X86ForceAlignArgPointerAttr::Clone
std::string_view X86ForceAlignArgPointerAttr::Spelling(void) const {
  auto &self = *const_cast<clang::X86ForceAlignArgPointerAttr *>(u.X86ForceAlignArgPointerAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "X86ForceAlignArgPointerAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

XRayInstrumentAttr::XRayInstrumentAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, XRayInstrumentAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, XRayInstrumentAttr)
bool XRayInstrumentAttr::AlwaysXRayInstrument(void) const {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.alwaysXRayInstrument();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

// 1: XRayInstrumentAttr::Clone
enum XRayInstrumentAttrSpelling XRayInstrumentAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::XRayInstrumentAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view XRayInstrumentAttr::Spelling(void) const {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "XRayInstrumentAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool XRayInstrumentAttr::NeverXRayInstrument(void) const {
  auto &self = *const_cast<clang::XRayInstrumentAttr *>(u.XRayInstrumentAttr);
  decltype(auto) val = self.neverXRayInstrument();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

XRayLogArgsAttr::XRayLogArgsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, XRayLogArgsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, XRayLogArgsAttr)
// 1: XRayLogArgsAttr::Clone
uint32_t XRayLogArgsAttr::ArgumentCount(void) const {
  auto &self = *const_cast<clang::XRayLogArgsAttr *>(u.XRayLogArgsAttr);
  decltype(auto) val = self.getArgumentCount();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view XRayLogArgsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::XRayLogArgsAttr *>(u.XRayLogArgsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "XRayLogArgsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ZeroCallUsedRegsAttr::ZeroCallUsedRegsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ZeroCallUsedRegsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ZeroCallUsedRegsAttr)
// 1: ZeroCallUsedRegsAttr::Clone
std::string_view ZeroCallUsedRegsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ZeroCallUsedRegsAttr *>(u.ZeroCallUsedRegsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ZeroCallUsedRegsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum ZeroCallUsedRegsAttrZeroCallUsedRegsKind ZeroCallUsedRegsAttr::ZeroCallUsedRegs(void) const {
  auto &self = *const_cast<clang::ZeroCallUsedRegsAttr *>(u.ZeroCallUsedRegsAttr);
  decltype(auto) val = self.getZeroCallUsedRegs();
  return static_cast<::pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

AArch64SVEPcsAttr::AArch64SVEPcsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AArch64SVEPcsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AArch64SVEPcsAttr)
// 1: AArch64SVEPcsAttr::Clone
std::string_view AArch64SVEPcsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AArch64SVEPcsAttr *>(u.AArch64SVEPcsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AArch64SVEPcsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AArch64VectorPcsAttr::AArch64VectorPcsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AArch64VectorPcsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AArch64VectorPcsAttr)
// 1: AArch64VectorPcsAttr::Clone
std::string_view AArch64VectorPcsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AArch64VectorPcsAttr *>(u.AArch64VectorPcsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AArch64VectorPcsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AMDGPUFlatWorkGroupSizeAttr::AMDGPUFlatWorkGroupSizeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUFlatWorkGroupSizeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUFlatWorkGroupSizeAttr)
// 1: AMDGPUFlatWorkGroupSizeAttr::Clone
::pasta::Expr AMDGPUFlatWorkGroupSizeAttr::Max(void) const {
  auto &self = *const_cast<clang::AMDGPUFlatWorkGroupSizeAttr *>(u.AMDGPUFlatWorkGroupSizeAttr);
  decltype(auto) val = self.getMax();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUFlatWorkGroupSizeAttr::Max can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr AMDGPUFlatWorkGroupSizeAttr::Min(void) const {
  auto &self = *const_cast<clang::AMDGPUFlatWorkGroupSizeAttr *>(u.AMDGPUFlatWorkGroupSizeAttr);
  decltype(auto) val = self.getMin();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUFlatWorkGroupSizeAttr::Min can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AMDGPUFlatWorkGroupSizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AMDGPUFlatWorkGroupSizeAttr *>(u.AMDGPUFlatWorkGroupSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUFlatWorkGroupSizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AMDGPUKernelCallAttr::AMDGPUKernelCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUKernelCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUKernelCallAttr)
// 1: AMDGPUKernelCallAttr::Clone
std::string_view AMDGPUKernelCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AMDGPUKernelCallAttr *>(u.AMDGPUKernelCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUKernelCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AMDGPUNumSGPRAttr::AMDGPUNumSGPRAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUNumSGPRAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUNumSGPRAttr)
// 1: AMDGPUNumSGPRAttr::Clone
uint32_t AMDGPUNumSGPRAttr::NumSGPR(void) const {
  auto &self = *const_cast<clang::AMDGPUNumSGPRAttr *>(u.AMDGPUNumSGPRAttr);
  decltype(auto) val = self.getNumSGPR();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AMDGPUNumSGPRAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AMDGPUNumSGPRAttr *>(u.AMDGPUNumSGPRAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUNumSGPRAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AMDGPUNumVGPRAttr::AMDGPUNumVGPRAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUNumVGPRAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUNumVGPRAttr)
// 1: AMDGPUNumVGPRAttr::Clone
uint32_t AMDGPUNumVGPRAttr::NumVGPR(void) const {
  auto &self = *const_cast<clang::AMDGPUNumVGPRAttr *>(u.AMDGPUNumVGPRAttr);
  decltype(auto) val = self.getNumVGPR();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AMDGPUNumVGPRAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AMDGPUNumVGPRAttr *>(u.AMDGPUNumVGPRAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUNumVGPRAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AMDGPUWavesPerEUAttr::AMDGPUWavesPerEUAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AMDGPUWavesPerEUAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AMDGPUWavesPerEUAttr)
// 1: AMDGPUWavesPerEUAttr::Clone
::pasta::Expr AMDGPUWavesPerEUAttr::Max(void) const {
  auto &self = *const_cast<clang::AMDGPUWavesPerEUAttr *>(u.AMDGPUWavesPerEUAttr);
  decltype(auto) val = self.getMax();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUWavesPerEUAttr::Max can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr AMDGPUWavesPerEUAttr::Min(void) const {
  auto &self = *const_cast<clang::AMDGPUWavesPerEUAttr *>(u.AMDGPUWavesPerEUAttr);
  decltype(auto) val = self.getMin();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AMDGPUWavesPerEUAttr::Min can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AMDGPUWavesPerEUAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AMDGPUWavesPerEUAttr *>(u.AMDGPUWavesPerEUAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AMDGPUWavesPerEUAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ARMInterruptAttr::ARMInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ARMInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ARMInterruptAttr)
// 1: ARMInterruptAttr::Clone
enum ARMInterruptAttrInterruptType ARMInterruptAttr::Interrupt(void) const {
  auto &self = *const_cast<clang::ARMInterruptAttr *>(u.ARMInterruptAttr);
  decltype(auto) val = self.getInterrupt();
  return static_cast<::pasta::ARMInterruptAttrInterruptType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ARMInterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ARMInterruptAttr *>(u.ARMInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ARMInterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AVRInterruptAttr::AVRInterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AVRInterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AVRInterruptAttr)
// 1: AVRInterruptAttr::Clone
std::string_view AVRInterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AVRInterruptAttr *>(u.AVRInterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AVRInterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AVRSignalAttr::AVRSignalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AVRSignalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AVRSignalAttr)
// 1: AVRSignalAttr::Clone
std::string_view AVRSignalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AVRSignalAttr *>(u.AVRSignalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AVRSignalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AbiTagAttr::AbiTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AbiTagAttr)
// 1: AbiTagAttr::Clone
std::string_view AbiTagAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AbiTagAttr *>(u.AbiTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AbiTagAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum AcquireCapabilityAttrSpelling AcquireCapabilityAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::AcquireCapabilityAttr *>(u.AcquireCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AcquireCapabilityAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AcquireCapabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AcquireCapabilityAttr *>(u.AcquireCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquireCapabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool AcquireCapabilityAttr::IsShared(void) const {
  auto &self = *const_cast<clang::AcquireCapabilityAttr *>(u.AcquireCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

AcquireHandleAttr::AcquireHandleAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AcquireHandleAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AcquireHandleAttr)
// 1: AcquireHandleAttr::Clone
std::string_view AcquireHandleAttr::HandleType(void) const {
  auto &self = *const_cast<clang::AcquireHandleAttr *>(u.AcquireHandleAttr);
  decltype(auto) val = self.getHandleType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AcquireHandleAttr::HandleTypeLength(void) const {
  auto &self = *const_cast<clang::AcquireHandleAttr *>(u.AcquireHandleAttr);
  decltype(auto) val = self.getHandleTypeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AcquireHandleAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AcquireHandleAttr *>(u.AcquireHandleAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquireHandleAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view AcquiredAfterAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AcquiredAfterAttr *>(u.AcquiredAfterAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquiredAfterAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view AcquiredBeforeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AcquiredBeforeAttr *>(u.AcquiredBeforeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AcquiredBeforeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AddressSpaceAttr::AddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, AddressSpaceAttr)
// 1: AddressSpaceAttr::Clone
// 0: AddressSpaceAttr::AddressSpace
std::string_view AddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AddressSpaceAttr *>(u.AddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AliasAttr::AliasAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AliasAttr)
// 1: AliasAttr::Clone
std::string_view AliasAttr::Aliasee(void) const {
  auto &self = *const_cast<clang::AliasAttr *>(u.AliasAttr);
  decltype(auto) val = self.getAliasee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AliasAttr::AliaseeLength(void) const {
  auto &self = *const_cast<clang::AliasAttr *>(u.AliasAttr);
  decltype(auto) val = self.getAliaseeLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AliasAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AliasAttr *>(u.AliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AliasAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AlignMac68kAttr::AlignMac68kAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignMac68kAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlignMac68kAttr)
// 1: AlignMac68kAttr::Clone
std::string_view AlignMac68kAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AlignMac68kAttr *>(u.AlignMac68kAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignMac68kAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AlignNaturalAttr::AlignNaturalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignNaturalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlignNaturalAttr)
// 1: AlignNaturalAttr::Clone
std::string_view AlignNaturalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AlignNaturalAttr *>(u.AlignNaturalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignNaturalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AlignValueAttr::AlignValueAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : Attr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignValueAttr)
// 1: AlignValueAttr::Clone
::pasta::Expr AlignValueAttr::Alignment(void) const {
  auto &self = *const_cast<clang::AlignValueAttr *>(u.AlignValueAttr);
  decltype(auto) val = self.getAlignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AlignValueAttr::Alignment can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AlignValueAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AlignValueAttr *>(u.AlignValueAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignValueAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AlignedAttr::AlignedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlignedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlignedAttr)
// 1: AlignedAttr::Clone
uint32_t AlignedAttr::Alignment(void) const {
  auto &self = *(u.AlignedAttr);
  decltype(auto) val = self.getAlignment(ast->ci->getASTContext());
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::optional<::pasta::Expr> AlignedAttr::AlignmentExpression(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  if (!self.isAlignmentExpr()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getAlignmentExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("The unreachable has been reached");
}

std::optional<::pasta::Type> AlignedAttr::AlignmentType(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  if (self.isAlignmentExpr()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getAlignmentType();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("The unreachable has been reached");
}

enum AlignedAttrSpelling AlignedAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AlignedAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AlignedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlignedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsAlignas(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignas();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsAlignmentDependent(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignmentDependent();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsAlignmentErrorDependent(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignmentErrorDependent();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsAlignmentExpression(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isAlignmentExpr();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsC11(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isC11();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsDeclspec(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isDeclspec();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AlignedAttr::IsGNU(void) const {
  auto &self = *const_cast<clang::AlignedAttr *>(u.AlignedAttr);
  decltype(auto) val = self.isGNU();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

AllocAlignAttr::AllocAlignAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AllocAlignAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AllocAlignAttr)
// 1: AllocAlignAttr::Clone
// 0: AllocAlignAttr::ParameterIndex
std::string_view AllocAlignAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AllocAlignAttr *>(u.AllocAlignAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AllocAlignAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view AllocSizeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AllocSizeAttr *>(u.AllocSizeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AllocSizeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AlwaysDestroyAttr::AlwaysDestroyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlwaysDestroyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlwaysDestroyAttr)
// 1: AlwaysDestroyAttr::Clone
std::string_view AlwaysDestroyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AlwaysDestroyAttr *>(u.AlwaysDestroyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlwaysDestroyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AnalyzerNoReturnAttr::AnalyzerNoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnalyzerNoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnalyzerNoReturnAttr)
// 1: AnalyzerNoReturnAttr::Clone
std::string_view AnalyzerNoReturnAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AnalyzerNoReturnAttr *>(u.AnalyzerNoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnalyzerNoReturnAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
// 0: AnnotateAttr::DelayedArguments
// 0: AnnotateAttr::
// 0: AnnotateAttr::
// 0: AnnotateAttr::
std::string_view AnnotateAttr::Annotation(void) const {
  auto &self = *const_cast<clang::AnnotateAttr *>(u.AnnotateAttr);
  decltype(auto) val = self.getAnnotation();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AnnotateAttr::AnnotationLength(void) const {
  auto &self = *const_cast<clang::AnnotateAttr *>(u.AnnotateAttr);
  decltype(auto) val = self.getAnnotationLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AnnotateAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AnnotateAttr *>(u.AnnotateAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnnotateAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AnnotateTypeAttr::AnnotateTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnnotateTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, AnnotateTypeAttr)
// 0: AnnotateTypeAttr::Arguments
// 0: AnnotateTypeAttr::
// 0: AnnotateTypeAttr::
// 0: AnnotateTypeAttr::
// 1: AnnotateTypeAttr::Clone
// 0: AnnotateTypeAttr::DelayedArguments
// 0: AnnotateTypeAttr::
// 0: AnnotateTypeAttr::
// 0: AnnotateTypeAttr::
std::string_view AnnotateTypeAttr::Annotation(void) const {
  auto &self = *const_cast<clang::AnnotateTypeAttr *>(u.AnnotateTypeAttr);
  decltype(auto) val = self.getAnnotation();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AnnotateTypeAttr::AnnotationLength(void) const {
  auto &self = *const_cast<clang::AnnotateTypeAttr *>(u.AnnotateTypeAttr);
  decltype(auto) val = self.getAnnotationLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AnnotateTypeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AnnotateTypeAttr *>(u.AnnotateTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnnotateTypeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AnyX86InterruptAttr::AnyX86InterruptAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnyX86InterruptAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnyX86InterruptAttr)
// 1: AnyX86InterruptAttr::Clone
std::string_view AnyX86InterruptAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AnyX86InterruptAttr *>(u.AnyX86InterruptAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnyX86InterruptAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AnyX86NoCallerSavedRegistersAttr::AnyX86NoCallerSavedRegistersAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnyX86NoCallerSavedRegistersAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnyX86NoCallerSavedRegistersAttr)
// 1: AnyX86NoCallerSavedRegistersAttr::Clone
std::string_view AnyX86NoCallerSavedRegistersAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AnyX86NoCallerSavedRegistersAttr *>(u.AnyX86NoCallerSavedRegistersAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnyX86NoCallerSavedRegistersAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AnyX86NoCfCheckAttr::AnyX86NoCfCheckAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AnyX86NoCfCheckAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AnyX86NoCfCheckAttr)
// 1: AnyX86NoCfCheckAttr::Clone
std::string_view AnyX86NoCfCheckAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AnyX86NoCfCheckAttr *>(u.AnyX86NoCfCheckAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AnyX86NoCfCheckAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ArcWeakrefUnavailableAttr::ArcWeakrefUnavailableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArcWeakrefUnavailableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ArcWeakrefUnavailableAttr)
// 1: ArcWeakrefUnavailableAttr::Clone
std::string_view ArcWeakrefUnavailableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ArcWeakrefUnavailableAttr *>(u.ArcWeakrefUnavailableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArcWeakrefUnavailableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
bool ArgumentWithTypeTagAttr::IsPointer(void) const {
  auto &self = *const_cast<clang::ArgumentWithTypeTagAttr *>(u.ArgumentWithTypeTagAttr);
  decltype(auto) val = self.getIsPointer();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum ArgumentWithTypeTagAttrSpelling ArgumentWithTypeTagAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::ArgumentWithTypeTagAttr *>(u.ArgumentWithTypeTagAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ArgumentWithTypeTagAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ArgumentWithTypeTagAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ArgumentWithTypeTagAttr *>(u.ArgumentWithTypeTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArgumentWithTypeTagAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view ArmBuiltinAliasAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ArmBuiltinAliasAttr *>(u.ArmBuiltinAliasAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArmBuiltinAliasAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ArmMveStrictPolymorphismAttr::ArmMveStrictPolymorphismAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArmMveStrictPolymorphismAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ArmMveStrictPolymorphismAttr)
// 1: ArmMveStrictPolymorphismAttr::Clone
std::string_view ArmMveStrictPolymorphismAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ArmMveStrictPolymorphismAttr *>(u.ArmMveStrictPolymorphismAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArmMveStrictPolymorphismAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ArtificialAttr::ArtificialAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ArtificialAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ArtificialAttr)
// 1: ArtificialAttr::Clone
std::string_view ArtificialAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ArtificialAttr *>(u.ArtificialAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ArtificialAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AsmLabelAttr::AsmLabelAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AsmLabelAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AsmLabelAttr)
// 1: AsmLabelAttr::Clone
bool AsmLabelAttr::IsLiteralLabel(void) const {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getIsLiteralLabel();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AsmLabelAttr::Label(void) const {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getLabel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AsmLabelAttr::LabelLength(void) const {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getLabelLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AsmLabelAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AsmLabelAttr *>(u.AsmLabelAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AsmLabelAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
enum AssertCapabilityAttrSpelling AssertCapabilityAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::AssertCapabilityAttr *>(u.AssertCapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AssertCapabilityAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AssertCapabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AssertCapabilityAttr *>(u.AssertCapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssertCapabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool AssertCapabilityAttr::IsShared(void) const {
  auto &self = *const_cast<clang::AssertCapabilityAttr *>(u.AssertCapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view AssertExclusiveLockAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AssertExclusiveLockAttr *>(u.AssertExclusiveLockAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssertExclusiveLockAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view AssertSharedLockAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AssertSharedLockAttr *>(u.AssertSharedLockAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssertSharedLockAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AssumeAlignedAttr::AssumeAlignedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssumeAlignedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssumeAlignedAttr)
// 1: AssumeAlignedAttr::Clone
::pasta::Expr AssumeAlignedAttr::Alignment(void) const {
  auto &self = *const_cast<clang::AssumeAlignedAttr *>(u.AssumeAlignedAttr);
  decltype(auto) val = self.getAlignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AssumeAlignedAttr::Alignment can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::optional<::pasta::Expr> AssumeAlignedAttr::Offset(void) const {
  auto &self = *const_cast<clang::AssumeAlignedAttr *>(u.AssumeAlignedAttr);
  decltype(auto) val = self.getOffset();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AssumeAlignedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AssumeAlignedAttr *>(u.AssumeAlignedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssumeAlignedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AssumptionAttr::AssumptionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AssumptionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AssumptionAttr)
// 1: AssumptionAttr::Clone
std::string_view AssumptionAttr::Assumption(void) const {
  auto &self = *const_cast<clang::AssumptionAttr *>(u.AssumptionAttr);
  decltype(auto) val = self.getAssumption();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AssumptionAttr::AssumptionLength(void) const {
  auto &self = *const_cast<clang::AssumptionAttr *>(u.AssumptionAttr);
  decltype(auto) val = self.getAssumptionLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AssumptionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AssumptionAttr *>(u.AssumptionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AssumptionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view AvailabilityAttr::Message(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AvailabilityAttr::MessageLength(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

// 0: AvailabilityAttr::Obsoleted
// 0: AvailabilityAttr::Platform
// 0: AvailabilityAttr::Priority
std::string_view AvailabilityAttr::Replacement(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getReplacement();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t AvailabilityAttr::ReplacementLength(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getReplacementLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AvailabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AvailabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool AvailabilityAttr::Strict(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getStrict();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool AvailabilityAttr::Unavailable(void) const {
  auto &self = *const_cast<clang::AvailabilityAttr *>(u.AvailabilityAttr);
  decltype(auto) val = self.getUnavailable();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

BPFPreserveAccessIndexAttr::BPFPreserveAccessIndexAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BPFPreserveAccessIndexAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BPFPreserveAccessIndexAttr)
// 1: BPFPreserveAccessIndexAttr::Clone
std::string_view BPFPreserveAccessIndexAttr::Spelling(void) const {
  auto &self = *const_cast<clang::BPFPreserveAccessIndexAttr *>(u.BPFPreserveAccessIndexAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BPFPreserveAccessIndexAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

BTFDeclTagAttr::BTFDeclTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BTFDeclTagAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BTFDeclTagAttr)
// 1: BTFDeclTagAttr::Clone
std::string_view BTFDeclTagAttr::BTFDeclTag(void) const {
  auto &self = *const_cast<clang::BTFDeclTagAttr *>(u.BTFDeclTagAttr);
  decltype(auto) val = self.getBTFDeclTag();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t BTFDeclTagAttr::BTFDeclTagLength(void) const {
  auto &self = *const_cast<clang::BTFDeclTagAttr *>(u.BTFDeclTagAttr);
  decltype(auto) val = self.getBTFDeclTagLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view BTFDeclTagAttr::Spelling(void) const {
  auto &self = *const_cast<clang::BTFDeclTagAttr *>(u.BTFDeclTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BTFDeclTagAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

BTFTypeTagAttr::BTFTypeTagAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BTFTypeTagAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, BTFTypeTagAttr)
// 1: BTFTypeTagAttr::Clone
std::string_view BTFTypeTagAttr::BTFTypeTag(void) const {
  auto &self = *const_cast<clang::BTFTypeTagAttr *>(u.BTFTypeTagAttr);
  decltype(auto) val = self.getBTFTypeTag();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t BTFTypeTagAttr::BTFTypeTagLength(void) const {
  auto &self = *const_cast<clang::BTFTypeTagAttr *>(u.BTFTypeTagAttr);
  decltype(auto) val = self.getBTFTypeTagLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view BTFTypeTagAttr::Spelling(void) const {
  auto &self = *const_cast<clang::BTFTypeTagAttr *>(u.BTFTypeTagAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BTFTypeTagAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

BlocksAttr::BlocksAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BlocksAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BlocksAttr)
// 1: BlocksAttr::Clone
std::string_view BlocksAttr::Spelling(void) const {
  auto &self = *const_cast<clang::BlocksAttr *>(u.BlocksAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BlocksAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum BlocksAttrBlockType BlocksAttr::Type(void) const {
  auto &self = *const_cast<clang::BlocksAttr *>(u.BlocksAttr);
  decltype(auto) val = self.getType();
  return static_cast<::pasta::BlocksAttrBlockType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

BuiltinAttr::BuiltinAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, BuiltinAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, BuiltinAttr)
// 1: BuiltinAttr::Clone
uint32_t BuiltinAttr::ID(void) const {
  auto &self = *const_cast<clang::BuiltinAttr *>(u.BuiltinAttr);
  decltype(auto) val = self.getID();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view BuiltinAttr::Spelling(void) const {
  auto &self = *const_cast<clang::BuiltinAttr *>(u.BuiltinAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "BuiltinAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

C11NoReturnAttr::C11NoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, C11NoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, C11NoReturnAttr)
// 1: C11NoReturnAttr::Clone
std::string_view C11NoReturnAttr::Spelling(void) const {
  auto &self = *const_cast<clang::C11NoReturnAttr *>(u.C11NoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "C11NoReturnAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CDeclAttr::CDeclAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CDeclAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CDeclAttr)
// 1: CDeclAttr::Clone
std::string_view CDeclAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CDeclAttr *>(u.CDeclAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CDeclAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFAuditedTransferAttr::CFAuditedTransferAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFAuditedTransferAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFAuditedTransferAttr)
// 1: CFAuditedTransferAttr::Clone
std::string_view CFAuditedTransferAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFAuditedTransferAttr *>(u.CFAuditedTransferAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFAuditedTransferAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFConsumedAttr::CFConsumedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFConsumedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, CFConsumedAttr)
// 1: CFConsumedAttr::Clone
std::string_view CFConsumedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFConsumedAttr *>(u.CFConsumedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFConsumedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFGuardAttr::CFGuardAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFGuardAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFGuardAttr)
// 1: CFGuardAttr::Clone
enum CFGuardAttrGuardArg CFGuardAttr::Guard(void) const {
  auto &self = *const_cast<clang::CFGuardAttr *>(u.CFGuardAttr);
  decltype(auto) val = self.getGuard();
  return static_cast<::pasta::CFGuardAttrGuardArg>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view CFGuardAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFGuardAttr *>(u.CFGuardAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFGuardAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFICanonicalJumpTableAttr::CFICanonicalJumpTableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFICanonicalJumpTableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFICanonicalJumpTableAttr)
// 1: CFICanonicalJumpTableAttr::Clone
std::string_view CFICanonicalJumpTableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFICanonicalJumpTableAttr *>(u.CFICanonicalJumpTableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFICanonicalJumpTableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFReturnsNotRetainedAttr::CFReturnsNotRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFReturnsNotRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFReturnsNotRetainedAttr)
// 1: CFReturnsNotRetainedAttr::Clone
std::string_view CFReturnsNotRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFReturnsNotRetainedAttr *>(u.CFReturnsNotRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFReturnsNotRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFReturnsRetainedAttr::CFReturnsRetainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFReturnsRetainedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFReturnsRetainedAttr)
// 1: CFReturnsRetainedAttr::Clone
std::string_view CFReturnsRetainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFReturnsRetainedAttr *>(u.CFReturnsRetainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFReturnsRetainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CFUnknownTransferAttr::CFUnknownTransferAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CFUnknownTransferAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CFUnknownTransferAttr)
// 1: CFUnknownTransferAttr::Clone
std::string_view CFUnknownTransferAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CFUnknownTransferAttr *>(u.CFUnknownTransferAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CFUnknownTransferAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view CPUDispatchAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CPUDispatchAttr *>(u.CPUDispatchAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CPUDispatchAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view CPUSpecificAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CPUSpecificAttr *>(u.CPUSpecificAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CPUSpecificAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDAConstantAttr::CUDAConstantAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAConstantAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAConstantAttr)
// 1: CUDAConstantAttr::Clone
std::string_view CUDAConstantAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDAConstantAttr *>(u.CUDAConstantAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAConstantAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDADeviceAttr::CUDADeviceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDADeviceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDADeviceAttr)
// 1: CUDADeviceAttr::Clone
std::string_view CUDADeviceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDADeviceAttr *>(u.CUDADeviceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDADeviceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDADeviceBuiltinSurfaceTypeAttr::CUDADeviceBuiltinSurfaceTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDADeviceBuiltinSurfaceTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDADeviceBuiltinSurfaceTypeAttr)
// 1: CUDADeviceBuiltinSurfaceTypeAttr::Clone
std::string_view CUDADeviceBuiltinSurfaceTypeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDADeviceBuiltinSurfaceTypeAttr *>(u.CUDADeviceBuiltinSurfaceTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDADeviceBuiltinSurfaceTypeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDADeviceBuiltinTextureTypeAttr::CUDADeviceBuiltinTextureTypeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDADeviceBuiltinTextureTypeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDADeviceBuiltinTextureTypeAttr)
// 1: CUDADeviceBuiltinTextureTypeAttr::Clone
std::string_view CUDADeviceBuiltinTextureTypeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDADeviceBuiltinTextureTypeAttr *>(u.CUDADeviceBuiltinTextureTypeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDADeviceBuiltinTextureTypeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDAGlobalAttr::CUDAGlobalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAGlobalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAGlobalAttr)
// 1: CUDAGlobalAttr::Clone
std::string_view CUDAGlobalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDAGlobalAttr *>(u.CUDAGlobalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAGlobalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDAHostAttr::CUDAHostAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAHostAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAHostAttr)
// 1: CUDAHostAttr::Clone
std::string_view CUDAHostAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDAHostAttr *>(u.CUDAHostAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAHostAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDAInvalidTargetAttr::CUDAInvalidTargetAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDAInvalidTargetAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDAInvalidTargetAttr)
// 1: CUDAInvalidTargetAttr::Clone
std::string_view CUDAInvalidTargetAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDAInvalidTargetAttr *>(u.CUDAInvalidTargetAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDAInvalidTargetAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDALaunchBoundsAttr::CUDALaunchBoundsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDALaunchBoundsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDALaunchBoundsAttr)
// 1: CUDALaunchBoundsAttr::Clone
::pasta::Expr CUDALaunchBoundsAttr::MaxThreads(void) const {
  auto &self = *const_cast<clang::CUDALaunchBoundsAttr *>(u.CUDALaunchBoundsAttr);
  decltype(auto) val = self.getMaxThreads();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CUDALaunchBoundsAttr::MaxThreads can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr CUDALaunchBoundsAttr::MinBlocks(void) const {
  auto &self = *const_cast<clang::CUDALaunchBoundsAttr *>(u.CUDALaunchBoundsAttr);
  decltype(auto) val = self.getMinBlocks();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CUDALaunchBoundsAttr::MinBlocks can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view CUDALaunchBoundsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDALaunchBoundsAttr *>(u.CUDALaunchBoundsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDALaunchBoundsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CUDASharedAttr::CUDASharedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CUDASharedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CUDASharedAttr)
// 1: CUDASharedAttr::Clone
std::string_view CUDASharedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CUDASharedAttr *>(u.CUDASharedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CUDASharedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CXX11NoReturnAttr::CXX11NoReturnAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CXX11NoReturnAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CXX11NoReturnAttr)
// 1: CXX11NoReturnAttr::Clone
enum CXX11NoReturnAttrSpelling CXX11NoReturnAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::CXX11NoReturnAttr *>(u.CXX11NoReturnAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::CXX11NoReturnAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view CXX11NoReturnAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CXX11NoReturnAttr *>(u.CXX11NoReturnAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CXX11NoReturnAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view CallableWhenAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CallableWhenAttr *>(u.CallableWhenAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CallableWhenAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view CallbackAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CallbackAttr *>(u.CallbackAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CallbackAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CapabilityAttr::CapabilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CapabilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CapabilityAttr)
// 1: CapabilityAttr::Clone
std::string_view CapabilityAttr::Name(void) const {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t CapabilityAttr::NameLength(void) const {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

enum CapabilityAttrSpelling CapabilityAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::CapabilityAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view CapabilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CapabilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool CapabilityAttr::IsShared(void) const {
  auto &self = *const_cast<clang::CapabilityAttr *>(u.CapabilityAttr);
  decltype(auto) val = self.isShared();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

CapturedRecordAttr::CapturedRecordAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CapturedRecordAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CapturedRecordAttr)
// 1: CapturedRecordAttr::Clone
std::string_view CapturedRecordAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CapturedRecordAttr *>(u.CapturedRecordAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CapturedRecordAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CarriesDependencyAttr::CarriesDependencyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableParamAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CarriesDependencyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CarriesDependencyAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableParamAttr, CarriesDependencyAttr)
// 1: CarriesDependencyAttr::Clone
std::string_view CarriesDependencyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CarriesDependencyAttr *>(u.CarriesDependencyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CarriesDependencyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CleanupAttr::CleanupAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CleanupAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CleanupAttr)
// 1: CleanupAttr::Clone
::pasta::FunctionDecl CleanupAttr::FunctionDeclaration(void) const {
  auto &self = *const_cast<clang::CleanupAttr *>(u.CleanupAttr);
  decltype(auto) val = self.getFunctionDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CleanupAttr::FunctionDeclaration can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view CleanupAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CleanupAttr *>(u.CleanupAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CleanupAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CmseNSCallAttr::CmseNSCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CmseNSCallAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, CmseNSCallAttr)
// 1: CmseNSCallAttr::Clone
std::string_view CmseNSCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CmseNSCallAttr *>(u.CmseNSCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CmseNSCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CmseNSEntryAttr::CmseNSEntryAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CmseNSEntryAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CmseNSEntryAttr)
// 1: CmseNSEntryAttr::Clone
std::string_view CmseNSEntryAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CmseNSEntryAttr *>(u.CmseNSEntryAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CmseNSEntryAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CodeSegAttr::CodeSegAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CodeSegAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CodeSegAttr)
// 1: CodeSegAttr::Clone
std::string_view CodeSegAttr::Name(void) const {
  auto &self = *const_cast<clang::CodeSegAttr *>(u.CodeSegAttr);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t CodeSegAttr::NameLength(void) const {
  auto &self = *const_cast<clang::CodeSegAttr *>(u.CodeSegAttr);
  decltype(auto) val = self.getNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view CodeSegAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CodeSegAttr *>(u.CodeSegAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CodeSegAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ColdAttr::ColdAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ColdAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ColdAttr)
// 1: ColdAttr::Clone
std::string_view ColdAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ColdAttr *>(u.ColdAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ColdAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

CommonAttr::CommonAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, CommonAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, CommonAttr)
// 1: CommonAttr::Clone
std::string_view CommonAttr::Spelling(void) const {
  auto &self = *const_cast<clang::CommonAttr *>(u.CommonAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CommonAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ConstAttr::ConstAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConstAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConstAttr)
// 1: ConstAttr::Clone
std::string_view ConstAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConstAttr *>(u.ConstAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConstAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ConstInitAttr::ConstInitAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConstInitAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConstInitAttr)
// 1: ConstInitAttr::Clone
enum ConstInitAttrSpelling ConstInitAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::ConstInitAttr *>(u.ConstInitAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ConstInitAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ConstInitAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConstInitAttr *>(u.ConstInitAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConstInitAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool ConstInitAttr::IsConstinit(void) const {
  auto &self = *const_cast<clang::ConstInitAttr *>(u.ConstInitAttr);
  decltype(auto) val = self.isConstinit();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

ConstructorAttr::ConstructorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConstructorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConstructorAttr)
// 1: ConstructorAttr::Clone
// 0: ConstructorAttr::Priority
std::string_view ConstructorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConstructorAttr *>(u.ConstructorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConstructorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ConsumableAttr::ConsumableAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConsumableAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConsumableAttr)
// 1: ConsumableAttr::Clone
enum ConsumableAttrConsumedState ConsumableAttr::DefaultState(void) const {
  auto &self = *const_cast<clang::ConsumableAttr *>(u.ConsumableAttr);
  decltype(auto) val = self.getDefaultState();
  return static_cast<::pasta::ConsumableAttrConsumedState>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ConsumableAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConsumableAttr *>(u.ConsumableAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConsumableAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ConsumableAutoCastAttr::ConsumableAutoCastAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConsumableAutoCastAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConsumableAutoCastAttr)
// 1: ConsumableAutoCastAttr::Clone
std::string_view ConsumableAutoCastAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConsumableAutoCastAttr *>(u.ConsumableAutoCastAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConsumableAutoCastAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ConsumableSetOnReadAttr::ConsumableSetOnReadAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConsumableSetOnReadAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConsumableSetOnReadAttr)
// 1: ConsumableSetOnReadAttr::Clone
std::string_view ConsumableSetOnReadAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConsumableSetOnReadAttr *>(u.ConsumableSetOnReadAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConsumableSetOnReadAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ConvergentAttr::ConvergentAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ConvergentAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ConvergentAttr)
// 1: ConvergentAttr::Clone
std::string_view ConvergentAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ConvergentAttr *>(u.ConvergentAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ConvergentAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DLLExportAttr::DLLExportAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLExportAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLExportAttr)
// 1: DLLExportAttr::Clone
std::string_view DLLExportAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DLLExportAttr *>(u.DLLExportAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLExportAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DLLExportStaticLocalAttr::DLLExportStaticLocalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLExportStaticLocalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLExportStaticLocalAttr)
// 1: DLLExportStaticLocalAttr::Clone
std::string_view DLLExportStaticLocalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DLLExportStaticLocalAttr *>(u.DLLExportStaticLocalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLExportStaticLocalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DLLImportAttr::DLLImportAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLImportAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLImportAttr)
// 1: DLLImportAttr::Clone
std::string_view DLLImportAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DLLImportAttr *>(u.DLLImportAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLImportAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DLLImportStaticLocalAttr::DLLImportStaticLocalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DLLImportStaticLocalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DLLImportStaticLocalAttr)
// 1: DLLImportStaticLocalAttr::Clone
std::string_view DLLImportStaticLocalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DLLImportStaticLocalAttr *>(u.DLLImportStaticLocalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DLLImportStaticLocalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DeclOrStmtAttr::DeclOrStmtAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DeclOrStmtAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DeclOrStmtAttr)
PASTA_DEFINE_DERIVED_OPERATORS(DeclOrStmtAttr, AlwaysInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(DeclOrStmtAttr, NoInlineAttr)
PASTA_DEFINE_DERIVED_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
DeprecatedAttr::DeprecatedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DeprecatedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DeprecatedAttr)
// 1: DeprecatedAttr::Clone
std::string_view DeprecatedAttr::Message(void) const {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t DeprecatedAttr::MessageLength(void) const {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view DeprecatedAttr::Replacement(void) const {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getReplacement();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t DeprecatedAttr::ReplacementLength(void) const {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getReplacementLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view DeprecatedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DeprecatedAttr *>(u.DeprecatedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DeprecatedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DestructorAttr::DestructorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DestructorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DestructorAttr)
// 1: DestructorAttr::Clone
// 0: DestructorAttr::Priority
std::string_view DestructorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DestructorAttr *>(u.DestructorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DestructorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
::pasta::FunctionDecl DiagnoseAsBuiltinAttr::Function(void) const {
  auto &self = *const_cast<clang::DiagnoseAsBuiltinAttr *>(u.DiagnoseAsBuiltinAttr);
  decltype(auto) val = self.getFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "DiagnoseAsBuiltinAttr::Function can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view DiagnoseAsBuiltinAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DiagnoseAsBuiltinAttr *>(u.DiagnoseAsBuiltinAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DiagnoseAsBuiltinAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DiagnoseIfAttr::DiagnoseIfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DiagnoseIfAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DiagnoseIfAttr)
// 1: DiagnoseIfAttr::Clone
bool DiagnoseIfAttr::ArgumentDependent(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getArgDependent();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr DiagnoseIfAttr::Condition(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DiagnoseIfAttr::Condition can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum DiagnoseIfAttrDiagnosticType DiagnoseIfAttr::DiagnosticType(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getDiagnosticType();
  return static_cast<::pasta::DiagnoseIfAttrDiagnosticType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view DiagnoseIfAttr::Message(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t DiagnoseIfAttr::MessageLength(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::NamedDecl DiagnoseIfAttr::Parent(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "DiagnoseIfAttr::Parent can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view DiagnoseIfAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DiagnoseIfAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool DiagnoseIfAttr::IsError(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.isError();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool DiagnoseIfAttr::IsWarning(void) const {
  auto &self = *const_cast<clang::DiagnoseIfAttr *>(u.DiagnoseIfAttr);
  decltype(auto) val = self.isWarning();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

DisableSanitizerInstrumentationAttr::DisableSanitizerInstrumentationAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DisableSanitizerInstrumentationAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DisableSanitizerInstrumentationAttr)
// 1: DisableSanitizerInstrumentationAttr::Clone
std::string_view DisableSanitizerInstrumentationAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DisableSanitizerInstrumentationAttr *>(u.DisableSanitizerInstrumentationAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DisableSanitizerInstrumentationAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

DisableTailCallsAttr::DisableTailCallsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, DisableTailCallsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, DisableTailCallsAttr)
// 1: DisableTailCallsAttr::Clone
std::string_view DisableTailCallsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::DisableTailCallsAttr *>(u.DisableTailCallsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DisableTailCallsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

EmptyBasesAttr::EmptyBasesAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EmptyBasesAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EmptyBasesAttr)
// 1: EmptyBasesAttr::Clone
std::string_view EmptyBasesAttr::Spelling(void) const {
  auto &self = *const_cast<clang::EmptyBasesAttr *>(u.EmptyBasesAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EmptyBasesAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

EnableIfAttr::EnableIfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnableIfAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnableIfAttr)
// 1: EnableIfAttr::Clone
::pasta::Expr EnableIfAttr::Condition(void) const {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "EnableIfAttr::Condition can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view EnableIfAttr::Message(void) const {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getMessage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t EnableIfAttr::MessageLength(void) const {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getMessageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view EnableIfAttr::Spelling(void) const {
  auto &self = *const_cast<clang::EnableIfAttr *>(u.EnableIfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnableIfAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

EnforceTCBAttr::EnforceTCBAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnforceTCBAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnforceTCBAttr)
// 1: EnforceTCBAttr::Clone
std::string_view EnforceTCBAttr::Spelling(void) const {
  auto &self = *const_cast<clang::EnforceTCBAttr *>(u.EnforceTCBAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnforceTCBAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view EnforceTCBAttr::TCBName(void) const {
  auto &self = *const_cast<clang::EnforceTCBAttr *>(u.EnforceTCBAttr);
  decltype(auto) val = self.getTCBName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t EnforceTCBAttr::TCBNameLength(void) const {
  auto &self = *const_cast<clang::EnforceTCBAttr *>(u.EnforceTCBAttr);
  decltype(auto) val = self.getTCBNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

EnforceTCBLeafAttr::EnforceTCBLeafAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnforceTCBLeafAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnforceTCBLeafAttr)
// 1: EnforceTCBLeafAttr::Clone
std::string_view EnforceTCBLeafAttr::Spelling(void) const {
  auto &self = *const_cast<clang::EnforceTCBLeafAttr *>(u.EnforceTCBLeafAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnforceTCBLeafAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view EnforceTCBLeafAttr::TCBName(void) const {
  auto &self = *const_cast<clang::EnforceTCBLeafAttr *>(u.EnforceTCBLeafAttr);
  decltype(auto) val = self.getTCBName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t EnforceTCBLeafAttr::TCBNameLength(void) const {
  auto &self = *const_cast<clang::EnforceTCBLeafAttr *>(u.EnforceTCBLeafAttr);
  decltype(auto) val = self.getTCBNameLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

EnumExtensibilityAttr::EnumExtensibilityAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, EnumExtensibilityAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, EnumExtensibilityAttr)
// 1: EnumExtensibilityAttr::Clone
enum EnumExtensibilityAttrKind EnumExtensibilityAttr::Extensibility(void) const {
  auto &self = *const_cast<clang::EnumExtensibilityAttr *>(u.EnumExtensibilityAttr);
  decltype(auto) val = self.getExtensibility();
  return static_cast<::pasta::EnumExtensibilityAttrKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view EnumExtensibilityAttr::Spelling(void) const {
  auto &self = *const_cast<clang::EnumExtensibilityAttr *>(u.EnumExtensibilityAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "EnumExtensibilityAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ErrorAttr::ErrorAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ErrorAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ErrorAttr)
// 1: ErrorAttr::Clone
enum ErrorAttrSpelling ErrorAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::ErrorAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ErrorAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ErrorAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ErrorAttr::UserDiagnostic(void) const {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getUserDiagnostic();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ErrorAttr::UserDiagnosticLength(void) const {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.getUserDiagnosticLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool ErrorAttr::IsError(void) const {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.isError();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool ErrorAttr::IsWarning(void) const {
  auto &self = *const_cast<clang::ErrorAttr *>(u.ErrorAttr);
  decltype(auto) val = self.isWarning();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

ExcludeFromExplicitInstantiationAttr::ExcludeFromExplicitInstantiationAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ExcludeFromExplicitInstantiationAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ExcludeFromExplicitInstantiationAttr)
// 1: ExcludeFromExplicitInstantiationAttr::Clone
std::string_view ExcludeFromExplicitInstantiationAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ExcludeFromExplicitInstantiationAttr *>(u.ExcludeFromExplicitInstantiationAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ExcludeFromExplicitInstantiationAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view ExclusiveTrylockFunctionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ExclusiveTrylockFunctionAttr *>(u.ExclusiveTrylockFunctionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ExclusiveTrylockFunctionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Expr ExclusiveTrylockFunctionAttr::SuccessValue(void) const {
  auto &self = *const_cast<clang::ExclusiveTrylockFunctionAttr *>(u.ExclusiveTrylockFunctionAttr);
  decltype(auto) val = self.getSuccessValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ExclusiveTrylockFunctionAttr::SuccessValue can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ExternalSourceSymbolAttr::ExternalSourceSymbolAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ExternalSourceSymbolAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, ExternalSourceSymbolAttr)
// 1: ExternalSourceSymbolAttr::Clone
std::string_view ExternalSourceSymbolAttr::DefinedIn(void) const {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getDefinedIn();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ExternalSourceSymbolAttr::DefinedInLength(void) const {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getDefinedInLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

bool ExternalSourceSymbolAttr::GeneratedDeclaration(void) const {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getGeneratedDeclaration();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ExternalSourceSymbolAttr::Language(void) const {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getLanguage();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t ExternalSourceSymbolAttr::LanguageLength(void) const {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getLanguageLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view ExternalSourceSymbolAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ExternalSourceSymbolAttr *>(u.ExternalSourceSymbolAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ExternalSourceSymbolAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

FallThroughAttr::FallThroughAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FallThroughAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, FallThroughAttr)
// 1: FallThroughAttr::Clone
std::string_view FallThroughAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FallThroughAttr *>(u.FallThroughAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FallThroughAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

FastCallAttr::FastCallAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FastCallAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FastCallAttr)
// 1: FastCallAttr::Clone
std::string_view FastCallAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FastCallAttr *>(u.FastCallAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FastCallAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

FinalAttr::FinalAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FinalAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FinalAttr)
// 1: FinalAttr::Clone
enum FinalAttrSpelling FinalAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::FinalAttr *>(u.FinalAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::FinalAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view FinalAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FinalAttr *>(u.FinalAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FinalAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool FinalAttr::IsSpelledAsSealed(void) const {
  auto &self = *const_cast<clang::FinalAttr *>(u.FinalAttr);
  decltype(auto) val = self.isSpelledAsSealed();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

FlagEnumAttr::FlagEnumAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FlagEnumAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FlagEnumAttr)
// 1: FlagEnumAttr::Clone
std::string_view FlagEnumAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FlagEnumAttr *>(u.FlagEnumAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FlagEnumAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

FlattenAttr::FlattenAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FlattenAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FlattenAttr)
// 1: FlattenAttr::Clone
std::string_view FlattenAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FlattenAttr *>(u.FlattenAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FlattenAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

FormatArgAttr::FormatArgAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FormatArgAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FormatArgAttr)
// 1: FormatArgAttr::Clone
// 0: FormatArgAttr::FormatIndex
std::string_view FormatArgAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FormatArgAttr *>(u.FormatArgAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FormatArgAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
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
std::string_view FormatAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FormatAttr *>(u.FormatAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FormatAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

// 0: FormatAttr::Type
FunctionReturnThunksAttr::FunctionReturnThunksAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, FunctionReturnThunksAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, FunctionReturnThunksAttr)
// 1: FunctionReturnThunksAttr::Clone
std::string_view FunctionReturnThunksAttr::Spelling(void) const {
  auto &self = *const_cast<clang::FunctionReturnThunksAttr *>(u.FunctionReturnThunksAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "FunctionReturnThunksAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum FunctionReturnThunksAttrKind FunctionReturnThunksAttr::ThunkType(void) const {
  auto &self = *const_cast<clang::FunctionReturnThunksAttr *>(u.FunctionReturnThunksAttr);
  decltype(auto) val = self.getThunkType();
  return static_cast<::pasta::FunctionReturnThunksAttrKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

GNUInlineAttr::GNUInlineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, GNUInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, GNUInlineAttr)
// 1: GNUInlineAttr::Clone
std::string_view GNUInlineAttr::Spelling(void) const {
  auto &self = *const_cast<clang::GNUInlineAttr *>(u.GNUInlineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "GNUInlineAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

GuardedByAttr::GuardedByAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, GuardedByAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, GuardedByAttr)
// 1: GuardedByAttr::Clone
::pasta::Expr GuardedByAttr::Argument(void) const {
  auto &self = *const_cast<clang::GuardedByAttr *>(u.GuardedByAttr);
  decltype(auto) val = self.getArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "GuardedByAttr::Argument can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view GuardedByAttr::Spelling(void) const {
  auto &self = *const_cast<clang::GuardedByAttr *>(u.GuardedByAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "GuardedByAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

GuardedVarAttr::GuardedVarAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, GuardedVarAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, GuardedVarAttr)
// 1: GuardedVarAttr::Clone
std::string_view GuardedVarAttr::Spelling(void) const {
  auto &self = *const_cast<clang::GuardedVarAttr *>(u.GuardedVarAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "GuardedVarAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HIPManagedAttr::HIPManagedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HIPManagedAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HIPManagedAttr)
// 1: HIPManagedAttr::Clone
std::string_view HIPManagedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HIPManagedAttr *>(u.HIPManagedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HIPManagedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HLSLAnnotationAttr::HLSLAnnotationAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLAnnotationAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLAnnotationAttr)
PASTA_DEFINE_DERIVED_OPERATORS(HLSLAnnotationAttr, HLSLSV_DispatchThreadIDAttr)
PASTA_DEFINE_DERIVED_OPERATORS(HLSLAnnotationAttr, HLSLSV_GroupIndexAttr)
HLSLGroupSharedAddressSpaceAttr::HLSLGroupSharedAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLGroupSharedAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, HLSLGroupSharedAddressSpaceAttr)
// 1: HLSLGroupSharedAddressSpaceAttr::Clone
std::string_view HLSLGroupSharedAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLGroupSharedAddressSpaceAttr *>(u.HLSLGroupSharedAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLGroupSharedAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HLSLNumThreadsAttr::HLSLNumThreadsAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLNumThreadsAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLNumThreadsAttr)
// 1: HLSLNumThreadsAttr::Clone
std::string_view HLSLNumThreadsAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLNumThreadsAttr *>(u.HLSLNumThreadsAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLNumThreadsAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

// 0: HLSLNumThreadsAttr::X
// 0: HLSLNumThreadsAttr::Y
// 0: HLSLNumThreadsAttr::Z
HLSLResourceAttr::HLSLResourceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLResourceAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLResourceAttr)
// 1: HLSLResourceAttr::Clone
enum HLSLResourceAttrResourceKind HLSLResourceAttr::ResourceShape(void) const {
  auto &self = *const_cast<clang::HLSLResourceAttr *>(u.HLSLResourceAttr);
  decltype(auto) val = self.getResourceShape();
  return static_cast<::pasta::HLSLResourceAttrResourceKind>(val);
  throw std::runtime_error("The unreachable has been reached");
}

enum HLSLResourceAttrResourceClass HLSLResourceAttr::ResourceType(void) const {
  auto &self = *const_cast<clang::HLSLResourceAttr *>(u.HLSLResourceAttr);
  decltype(auto) val = self.getResourceType();
  return static_cast<::pasta::HLSLResourceAttrResourceClass>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view HLSLResourceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLResourceAttr *>(u.HLSLResourceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLResourceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HLSLResourceBindingAttr::HLSLResourceBindingAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLResourceBindingAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLResourceBindingAttr)
// 1: HLSLResourceBindingAttr::Clone
std::string_view HLSLResourceBindingAttr::Slot(void) const {
  auto &self = *const_cast<clang::HLSLResourceBindingAttr *>(u.HLSLResourceBindingAttr);
  decltype(auto) val = self.getSlot();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t HLSLResourceBindingAttr::SlotLength(void) const {
  auto &self = *const_cast<clang::HLSLResourceBindingAttr *>(u.HLSLResourceBindingAttr);
  decltype(auto) val = self.getSlotLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view HLSLResourceBindingAttr::Space(void) const {
  auto &self = *const_cast<clang::HLSLResourceBindingAttr *>(u.HLSLResourceBindingAttr);
  decltype(auto) val = self.getSpace();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t HLSLResourceBindingAttr::SpaceLength(void) const {
  auto &self = *const_cast<clang::HLSLResourceBindingAttr *>(u.HLSLResourceBindingAttr);
  decltype(auto) val = self.getSpaceLength();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view HLSLResourceBindingAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLResourceBindingAttr *>(u.HLSLResourceBindingAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLResourceBindingAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HLSLSV_DispatchThreadIDAttr::HLSLSV_DispatchThreadIDAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : HLSLAnnotationAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLSV_DispatchThreadIDAttr)
PASTA_DEFINE_BASE_OPERATORS(HLSLAnnotationAttr, HLSLSV_DispatchThreadIDAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLSV_DispatchThreadIDAttr)
// 1: HLSLSV_DispatchThreadIDAttr::Clone
std::string_view HLSLSV_DispatchThreadIDAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLSV_DispatchThreadIDAttr *>(u.HLSLSV_DispatchThreadIDAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLSV_DispatchThreadIDAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HLSLSV_GroupIndexAttr::HLSLSV_GroupIndexAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : HLSLAnnotationAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLSV_GroupIndexAttr)
PASTA_DEFINE_BASE_OPERATORS(HLSLAnnotationAttr, HLSLSV_GroupIndexAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLSV_GroupIndexAttr)
// 1: HLSLSV_GroupIndexAttr::Clone
std::string_view HLSLSV_GroupIndexAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLSV_GroupIndexAttr *>(u.HLSLSV_GroupIndexAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLSV_GroupIndexAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

HLSLShaderAttr::HLSLShaderAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HLSLShaderAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HLSLShaderAttr)
// 1: HLSLShaderAttr::Clone
std::string_view HLSLShaderAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HLSLShaderAttr *>(u.HLSLShaderAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HLSLShaderAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

enum HLSLShaderAttrShaderType HLSLShaderAttr::Type(void) const {
  auto &self = *const_cast<clang::HLSLShaderAttr *>(u.HLSLShaderAttr);
  decltype(auto) val = self.getType();
  return static_cast<::pasta::HLSLShaderAttrShaderType>(val);
  throw std::runtime_error("The unreachable has been reached");
}

HotAttr::HotAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, HotAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, HotAttr)
// 1: HotAttr::Clone
std::string_view HotAttr::Spelling(void) const {
  auto &self = *const_cast<clang::HotAttr *>(u.HotAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "HotAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

IBActionAttr::IBActionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IBActionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IBActionAttr)
// 1: IBActionAttr::Clone
std::string_view IBActionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::IBActionAttr *>(u.IBActionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IBActionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

IBOutletAttr::IBOutletAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IBOutletAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IBOutletAttr)
// 1: IBOutletAttr::Clone
std::string_view IBOutletAttr::Spelling(void) const {
  auto &self = *const_cast<clang::IBOutletAttr *>(u.IBOutletAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IBOutletAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

IBOutletCollectionAttr::IBOutletCollectionAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : InheritableAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, IBOutletCollectionAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, IBOutletCollectionAttr)
// 1: IBOutletCollectionAttr::Clone
::pasta::Type IBOutletCollectionAttr::Interface(void) const {
  auto &self = *const_cast<clang::IBOutletCollectionAttr *>(u.IBOutletCollectionAttr);
  decltype(auto) val = self.getInterface();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::Type IBOutletCollectionAttr::InterfaceToken(void) const {
  auto &self = *const_cast<clang::IBOutletCollectionAttr *>(u.IBOutletCollectionAttr);
  decltype(auto) val = self.getInterfaceLoc();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "IBOutletCollectionAttr::InterfaceToken can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view IBOutletCollectionAttr::Spelling(void) const {
  auto &self = *const_cast<clang::IBOutletCollectionAttr *>(u.IBOutletCollectionAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "IBOutletCollectionAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

LikelyAttr::LikelyAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, LikelyAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, LikelyAttr)
// 1: LikelyAttr::Clone
std::string_view LikelyAttr::Spelling(void) const {
  auto &self = *const_cast<clang::LikelyAttr *>(u.LikelyAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LikelyAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

MustTailAttr::MustTailAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, MustTailAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, MustTailAttr)
// 1: MustTailAttr::Clone
std::string_view MustTailAttr::Spelling(void) const {
  auto &self = *const_cast<clang::MustTailAttr *>(u.MustTailAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "MustTailAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoDerefAttr::NoDerefAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoDerefAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, NoDerefAttr)
// 1: NoDerefAttr::Clone
std::string_view NoDerefAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoDerefAttr *>(u.NoDerefAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoDerefAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

NoInlineAttr::NoInlineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : DeclOrStmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(DeclOrStmtAttr, NoInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoInlineAttr)
// 1: NoInlineAttr::Clone
std::string_view NoInlineAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoInlineAttr *>(u.NoInlineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoInlineAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool NoInlineAttr::IsClangNoInline(void) const {
  auto &self = *const_cast<clang::NoInlineAttr *>(u.NoInlineAttr);
  decltype(auto) val = self.isClangNoInline();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

NoMergeAttr::NoMergeAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : DeclOrStmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, NoMergeAttr)
PASTA_DEFINE_BASE_OPERATORS(DeclOrStmtAttr, NoMergeAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, NoMergeAttr)
// 1: NoMergeAttr::Clone
std::string_view NoMergeAttr::Spelling(void) const {
  auto &self = *const_cast<clang::NoMergeAttr *>(u.NoMergeAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "NoMergeAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCGCAttr::ObjCGCAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCGCAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ObjCGCAttr)
// 1: ObjCGCAttr::Clone
// 0: ObjCGCAttr::Kind
std::string_view ObjCGCAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCGCAttr *>(u.ObjCGCAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCGCAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCInertUnsafeUnretainedAttr::ObjCInertUnsafeUnretainedAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCInertUnsafeUnretainedAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ObjCInertUnsafeUnretainedAttr)
// 1: ObjCInertUnsafeUnretainedAttr::Clone
std::string_view ObjCInertUnsafeUnretainedAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCInertUnsafeUnretainedAttr *>(u.ObjCInertUnsafeUnretainedAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCInertUnsafeUnretainedAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

ObjCKindOfAttr::ObjCKindOfAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, ObjCKindOfAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, ObjCKindOfAttr)
// 1: ObjCKindOfAttr::Clone
std::string_view ObjCKindOfAttr::Spelling(void) const {
  auto &self = *const_cast<clang::ObjCKindOfAttr *>(u.ObjCKindOfAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "ObjCKindOfAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLConstantAddressSpaceAttr::OpenCLConstantAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLConstantAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLConstantAddressSpaceAttr)
// 1: OpenCLConstantAddressSpaceAttr::Clone
enum OpenCLConstantAddressSpaceAttrSpelling OpenCLConstantAddressSpaceAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OpenCLConstantAddressSpaceAttr *>(u.OpenCLConstantAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLConstantAddressSpaceAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OpenCLConstantAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLConstantAddressSpaceAttr *>(u.OpenCLConstantAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLConstantAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLGenericAddressSpaceAttr::OpenCLGenericAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGenericAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGenericAddressSpaceAttr)
// 1: OpenCLGenericAddressSpaceAttr::Clone
enum OpenCLGenericAddressSpaceAttrSpelling OpenCLGenericAddressSpaceAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OpenCLGenericAddressSpaceAttr *>(u.OpenCLGenericAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLGenericAddressSpaceAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OpenCLGenericAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLGenericAddressSpaceAttr *>(u.OpenCLGenericAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGenericAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLGlobalAddressSpaceAttr::OpenCLGlobalAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGlobalAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGlobalAddressSpaceAttr)
// 1: OpenCLGlobalAddressSpaceAttr::Clone
enum OpenCLGlobalAddressSpaceAttrSpelling OpenCLGlobalAddressSpaceAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OpenCLGlobalAddressSpaceAttr *>(u.OpenCLGlobalAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLGlobalAddressSpaceAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OpenCLGlobalAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLGlobalAddressSpaceAttr *>(u.OpenCLGlobalAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGlobalAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLGlobalDeviceAddressSpaceAttr::OpenCLGlobalDeviceAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGlobalDeviceAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGlobalDeviceAddressSpaceAttr)
// 1: OpenCLGlobalDeviceAddressSpaceAttr::Clone
std::string_view OpenCLGlobalDeviceAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLGlobalDeviceAddressSpaceAttr *>(u.OpenCLGlobalDeviceAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGlobalDeviceAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLGlobalHostAddressSpaceAttr::OpenCLGlobalHostAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLGlobalHostAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLGlobalHostAddressSpaceAttr)
// 1: OpenCLGlobalHostAddressSpaceAttr::Clone
std::string_view OpenCLGlobalHostAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLGlobalHostAddressSpaceAttr *>(u.OpenCLGlobalHostAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLGlobalHostAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLLocalAddressSpaceAttr::OpenCLLocalAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLLocalAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLLocalAddressSpaceAttr)
// 1: OpenCLLocalAddressSpaceAttr::Clone
enum OpenCLLocalAddressSpaceAttrSpelling OpenCLLocalAddressSpaceAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OpenCLLocalAddressSpaceAttr *>(u.OpenCLLocalAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLLocalAddressSpaceAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OpenCLLocalAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLLocalAddressSpaceAttr *>(u.OpenCLLocalAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLLocalAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLPrivateAddressSpaceAttr::OpenCLPrivateAddressSpaceAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLPrivateAddressSpaceAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, OpenCLPrivateAddressSpaceAttr)
// 1: OpenCLPrivateAddressSpaceAttr::Clone
enum OpenCLPrivateAddressSpaceAttrSpelling OpenCLPrivateAddressSpaceAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::OpenCLPrivateAddressSpaceAttr *>(u.OpenCLPrivateAddressSpaceAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::OpenCLPrivateAddressSpaceAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view OpenCLPrivateAddressSpaceAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLPrivateAddressSpaceAttr *>(u.OpenCLPrivateAddressSpaceAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLPrivateAddressSpaceAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

OpenCLUnrollHintAttr::OpenCLUnrollHintAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : StmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, OpenCLUnrollHintAttr)
PASTA_DEFINE_BASE_OPERATORS(StmtAttr, OpenCLUnrollHintAttr)
// 1: OpenCLUnrollHintAttr::Clone
std::string_view OpenCLUnrollHintAttr::Spelling(void) const {
  auto &self = *const_cast<clang::OpenCLUnrollHintAttr *>(u.OpenCLUnrollHintAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "OpenCLUnrollHintAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

uint32_t OpenCLUnrollHintAttr::UnrollHint(void) const {
  auto &self = *const_cast<clang::OpenCLUnrollHintAttr *>(u.OpenCLUnrollHintAttr);
  decltype(auto) val = self.getUnrollHint();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

Ptr32Attr::Ptr32Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, Ptr32Attr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, Ptr32Attr)
// 1: Ptr32Attr::Clone
std::string_view Ptr32Attr::Spelling(void) const {
  auto &self = *const_cast<clang::Ptr32Attr *>(u.Ptr32Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Ptr32Attr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

Ptr64Attr::Ptr64Attr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, Ptr64Attr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, Ptr64Attr)
// 1: Ptr64Attr::Clone
std::string_view Ptr64Attr::Spelling(void) const {
  auto &self = *const_cast<clang::Ptr64Attr *>(u.Ptr64Attr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Ptr64Attr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

SPtrAttr::SPtrAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : TypeAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, SPtrAttr)
PASTA_DEFINE_BASE_OPERATORS(TypeAttr, SPtrAttr)
// 1: SPtrAttr::Clone
std::string_view SPtrAttr::Spelling(void) const {
  auto &self = *const_cast<clang::SPtrAttr *>(u.SPtrAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "SPtrAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

AlwaysInlineAttr::AlwaysInlineAttr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Attr *attr_)
    : DeclOrStmtAttr(std::move(ast_), attr_) {}

PASTA_DEFINE_BASE_OPERATORS(Attr, AlwaysInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(DeclOrStmtAttr, AlwaysInlineAttr)
PASTA_DEFINE_BASE_OPERATORS(InheritableAttr, AlwaysInlineAttr)
// 1: AlwaysInlineAttr::Clone
enum AlwaysInlineAttrSpelling AlwaysInlineAttr::SemanticSpelling(void) const {
  auto &self = *const_cast<clang::AlwaysInlineAttr *>(u.AlwaysInlineAttr);
  decltype(auto) val = self.getSemanticSpelling();
  return static_cast<::pasta::AlwaysInlineAttrSpelling>(val);
  throw std::runtime_error("The unreachable has been reached");
}

std::string_view AlwaysInlineAttr::Spelling(void) const {
  auto &self = *const_cast<clang::AlwaysInlineAttr *>(u.AlwaysInlineAttr);
  decltype(auto) val = self.getSpelling();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "AlwaysInlineAttr::Spelling can return nullptr!");
  throw std::runtime_error("The unreachable has been reached");
}

bool AlwaysInlineAttr::IsClangAlwaysInline(void) const {
  auto &self = *const_cast<clang::AlwaysInlineAttr *>(u.AlwaysInlineAttr);
  decltype(auto) val = self.isClangAlwaysInline();
  return val;
  throw std::runtime_error("The unreachable has been reached");
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
