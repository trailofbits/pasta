/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <nanobind/nanobind.h>

#include <pasta/AST/Forward.h>

namespace pasta {
namespace nb = nanobind;

void RegisterEnums(nb::module_ &m) {
  nb::enum_<pasta::AArch64SVEPcsAttrSpelling>(m, "AArch64SVEPcsAttrSpelling")
    .value("GNU_AARCH64_SVE_PCS", pasta::AArch64SVEPcsAttrSpelling::kGNUAarch64SvePcs)
    .value("CXX11_CLANG_AARCH64_SVE_PCS", pasta::AArch64SVEPcsAttrSpelling::kCXX11ClangAarch64SvePcs)
    .value("C2X_CLANG_AARCH64_SVE_PCS", pasta::AArch64SVEPcsAttrSpelling::kC2xClangAarch64SvePcs)
    .value("SPELLING_NOT_CALCULATED", pasta::AArch64SVEPcsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AArch64VectorPcsAttrSpelling>(m, "AArch64VectorPcsAttrSpelling")
    .value("GNU_AARCH64_VECTOR_PCS", pasta::AArch64VectorPcsAttrSpelling::kGNUAarch64VectorPcs)
    .value("CXX11_CLANG_AARCH64_VECTOR_PCS", pasta::AArch64VectorPcsAttrSpelling::kCXX11ClangAarch64VectorPcs)
    .value("C2X_CLANG_AARCH64_VECTOR_PCS", pasta::AArch64VectorPcsAttrSpelling::kC2xClangAarch64VectorPcs)
    .value("SPELLING_NOT_CALCULATED", pasta::AArch64VectorPcsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AMDGPUFlatWorkGroupSizeAttrSpelling>(m, "AMDGPUFlatWorkGroupSizeAttrSpelling")
    .value("GNU_AMDGPU_FLAT_WORK_GROUP_SIZE", pasta::AMDGPUFlatWorkGroupSizeAttrSpelling::kGNUAmdgpuFlatWorkGroupSize)
    .value("CXX11_CLANG_AMDGPU_FLAT_WORK_GROUP_SIZE", pasta::AMDGPUFlatWorkGroupSizeAttrSpelling::kCXX11ClangAmdgpuFlatWorkGroupSize)
    .value("SPELLING_NOT_CALCULATED", pasta::AMDGPUFlatWorkGroupSizeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AMDGPUKernelCallAttrSpelling>(m, "AMDGPUKernelCallAttrSpelling")
    .value("GNU_AMDGPU_KERNEL", pasta::AMDGPUKernelCallAttrSpelling::kGNUAmdgpuKernel)
    .value("CXX11_CLANG_AMDGPU_KERNEL", pasta::AMDGPUKernelCallAttrSpelling::kCXX11ClangAmdgpuKernel)
    .value("C2X_CLANG_AMDGPU_KERNEL", pasta::AMDGPUKernelCallAttrSpelling::kC2xClangAmdgpuKernel)
    .value("SPELLING_NOT_CALCULATED", pasta::AMDGPUKernelCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AMDGPUNumSGPRAttrSpelling>(m, "AMDGPUNumSGPRAttrSpelling")
    .value("GNU_AMDGPU_NUM_SGPR", pasta::AMDGPUNumSGPRAttrSpelling::kGNUAmdgpuNumSgpr)
    .value("CXX11_CLANG_AMDGPU_NUM_SGPR", pasta::AMDGPUNumSGPRAttrSpelling::kCXX11ClangAmdgpuNumSgpr)
    .value("SPELLING_NOT_CALCULATED", pasta::AMDGPUNumSGPRAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AMDGPUNumVGPRAttrSpelling>(m, "AMDGPUNumVGPRAttrSpelling")
    .value("GNU_AMDGPU_NUM_VGPR", pasta::AMDGPUNumVGPRAttrSpelling::kGNUAmdgpuNumVgpr)
    .value("CXX11_CLANG_AMDGPU_NUM_VGPR", pasta::AMDGPUNumVGPRAttrSpelling::kCXX11ClangAmdgpuNumVgpr)
    .value("SPELLING_NOT_CALCULATED", pasta::AMDGPUNumVGPRAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AMDGPUWavesPerEUAttrSpelling>(m, "AMDGPUWavesPerEUAttrSpelling")
    .value("GNU_AMDGPU_WAVES_PER_EU", pasta::AMDGPUWavesPerEUAttrSpelling::kGNUAmdgpuWavesPerEu)
    .value("CXX11_CLANG_AMDGPU_WAVES_PER_EU", pasta::AMDGPUWavesPerEUAttrSpelling::kCXX11ClangAmdgpuWavesPerEu)
    .value("SPELLING_NOT_CALCULATED", pasta::AMDGPUWavesPerEUAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ARMInterruptAttrInterruptType>(m, "ARMInterruptAttrInterruptType")
    .value("IRQ", pasta::ARMInterruptAttrInterruptType::kIRQ)
    .value("FIQ", pasta::ARMInterruptAttrInterruptType::kFIQ)
    .value("SWI", pasta::ARMInterruptAttrInterruptType::kSWI)
    .value("ABORT", pasta::ARMInterruptAttrInterruptType::kABORT)
    .value("UNDEF", pasta::ARMInterruptAttrInterruptType::kUNDEF)
    .value("GENERIC", pasta::ARMInterruptAttrInterruptType::kGeneric);

  nb::enum_<pasta::ARMInterruptAttrSpelling>(m, "ARMInterruptAttrSpelling")
    .value("GNU_INTERRUPT", pasta::ARMInterruptAttrSpelling::kGNUInterrupt)
    .value("CXX11_GNU_INTERRUPT", pasta::ARMInterruptAttrSpelling::kCXX11GnuInterrupt)
    .value("C2X_GNU_INTERRUPT", pasta::ARMInterruptAttrSpelling::kC2xGnuInterrupt)
    .value("SPELLING_NOT_CALCULATED", pasta::ARMInterruptAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AVRInterruptAttrSpelling>(m, "AVRInterruptAttrSpelling")
    .value("GNU_INTERRUPT", pasta::AVRInterruptAttrSpelling::kGNUInterrupt)
    .value("CXX11_GNU_INTERRUPT", pasta::AVRInterruptAttrSpelling::kCXX11GnuInterrupt)
    .value("C2X_GNU_INTERRUPT", pasta::AVRInterruptAttrSpelling::kC2xGnuInterrupt)
    .value("SPELLING_NOT_CALCULATED", pasta::AVRInterruptAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AVRSignalAttrSpelling>(m, "AVRSignalAttrSpelling")
    .value("GNU_SIGNAL", pasta::AVRSignalAttrSpelling::kGNUSignal)
    .value("CXX11_GNU_SIGNAL", pasta::AVRSignalAttrSpelling::kCXX11GnuSignal)
    .value("C2X_GNU_SIGNAL", pasta::AVRSignalAttrSpelling::kC2xGnuSignal)
    .value("SPELLING_NOT_CALCULATED", pasta::AVRSignalAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AbiTagAttrSpelling>(m, "AbiTagAttrSpelling")
    .value("GNU_ABI_TAG", pasta::AbiTagAttrSpelling::kGNUAbiTag)
    .value("CXX11_GNU_ABI_TAG", pasta::AbiTagAttrSpelling::kCXX11GnuAbiTag)
    .value("SPELLING_NOT_CALCULATED", pasta::AbiTagAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AcquireCapabilityAttrSpelling>(m, "AcquireCapabilityAttrSpelling")
    .value("GNU_ACQUIRE_CAPABILITY", pasta::AcquireCapabilityAttrSpelling::kGNUAcquireCapability)
    .value("CXX11_CLANG_ACQUIRE_CAPABILITY", pasta::AcquireCapabilityAttrSpelling::kCXX11ClangAcquireCapability)
    .value("GNU_ACQUIRE_SHARED_CAPABILITY", pasta::AcquireCapabilityAttrSpelling::kGNUAcquireSharedCapability)
    .value("CXX11_CLANG_ACQUIRE_SHARED_CAPABILITY", pasta::AcquireCapabilityAttrSpelling::kCXX11ClangAcquireSharedCapability)
    .value("GNU_EXCLUSIVE_LOCK_FUNCTION", pasta::AcquireCapabilityAttrSpelling::kGNUExclusiveLockFunction)
    .value("GNU_SHARED_LOCK_FUNCTION", pasta::AcquireCapabilityAttrSpelling::kGNUSharedLockFunction)
    .value("SPELLING_NOT_CALCULATED", pasta::AcquireCapabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AcquireHandleAttrSpelling>(m, "AcquireHandleAttrSpelling")
    .value("GNU_ACQUIRE_HANDLE", pasta::AcquireHandleAttrSpelling::kGNUAcquireHandle)
    .value("CXX11_CLANG_ACQUIRE_HANDLE", pasta::AcquireHandleAttrSpelling::kCXX11ClangAcquireHandle)
    .value("C2X_CLANG_ACQUIRE_HANDLE", pasta::AcquireHandleAttrSpelling::kC2xClangAcquireHandle)
    .value("SPELLING_NOT_CALCULATED", pasta::AcquireHandleAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AddressSpaceAttrSpelling>(m, "AddressSpaceAttrSpelling")
    .value("GNU_ADDRESS_SPACE", pasta::AddressSpaceAttrSpelling::kGNUAddressSpace)
    .value("CXX11_CLANG_ADDRESS_SPACE", pasta::AddressSpaceAttrSpelling::kCXX11ClangAddressSpace)
    .value("C2X_CLANG_ADDRESS_SPACE", pasta::AddressSpaceAttrSpelling::kC2xClangAddressSpace)
    .value("SPELLING_NOT_CALCULATED", pasta::AddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AliasAttrSpelling>(m, "AliasAttrSpelling")
    .value("GNU_ALIAS", pasta::AliasAttrSpelling::kGNUAlias)
    .value("CXX11_GNU_ALIAS", pasta::AliasAttrSpelling::kCXX11GnuAlias)
    .value("C2X_GNU_ALIAS", pasta::AliasAttrSpelling::kC2xGnuAlias)
    .value("SPELLING_NOT_CALCULATED", pasta::AliasAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AlignedAttrSpelling>(m, "AlignedAttrSpelling")
    .value("GNU_ALIGNED", pasta::AlignedAttrSpelling::kGNUAligned)
    .value("CXX11_GNU_ALIGNED", pasta::AlignedAttrSpelling::kCXX11GnuAligned)
    .value("C2X_GNU_ALIGNED", pasta::AlignedAttrSpelling::kC2xGnuAligned)
    .value("DECLSPEC_ALIGN", pasta::AlignedAttrSpelling::kDeclspecAlign)
    .value("KEYWORD_ALIGNAS", pasta::AlignedAttrSpelling::kKeywordAlignas)
    .value("KEYWORD__ALIGNAS", pasta::AlignedAttrSpelling::kKeyword_Alignas)
    .value("SPELLING_NOT_CALCULATED", pasta::AlignedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AllocAlignAttrSpelling>(m, "AllocAlignAttrSpelling")
    .value("GNU_ALLOC_ALIGN", pasta::AllocAlignAttrSpelling::kGNUAllocAlign)
    .value("CXX11_GNU_ALLOC_ALIGN", pasta::AllocAlignAttrSpelling::kCXX11GnuAllocAlign)
    .value("C2X_GNU_ALLOC_ALIGN", pasta::AllocAlignAttrSpelling::kC2xGnuAllocAlign)
    .value("SPELLING_NOT_CALCULATED", pasta::AllocAlignAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AllocSizeAttrSpelling>(m, "AllocSizeAttrSpelling")
    .value("GNU_ALLOC_SIZE", pasta::AllocSizeAttrSpelling::kGNUAllocSize)
    .value("CXX11_GNU_ALLOC_SIZE", pasta::AllocSizeAttrSpelling::kCXX11GnuAllocSize)
    .value("C2X_GNU_ALLOC_SIZE", pasta::AllocSizeAttrSpelling::kC2xGnuAllocSize)
    .value("SPELLING_NOT_CALCULATED", pasta::AllocSizeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AlwaysDestroyAttrSpelling>(m, "AlwaysDestroyAttrSpelling")
    .value("GNU_ALWAYS_DESTROY", pasta::AlwaysDestroyAttrSpelling::kGNUAlwaysDestroy)
    .value("CXX11_CLANG_ALWAYS_DESTROY", pasta::AlwaysDestroyAttrSpelling::kCXX11ClangAlwaysDestroy)
    .value("SPELLING_NOT_CALCULATED", pasta::AlwaysDestroyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AlwaysInlineAttrSpelling>(m, "AlwaysInlineAttrSpelling")
    .value("GNU_ALWAYS_INLINE", pasta::AlwaysInlineAttrSpelling::kGNUAlwaysInline)
    .value("CXX11_GNU_ALWAYS_INLINE", pasta::AlwaysInlineAttrSpelling::kCXX11GnuAlwaysInline)
    .value("C2X_GNU_ALWAYS_INLINE", pasta::AlwaysInlineAttrSpelling::kC2xGnuAlwaysInline)
    .value("CXX11_CLANG_ALWAYS_INLINE", pasta::AlwaysInlineAttrSpelling::kCXX11ClangAlwaysInline)
    .value("C2X_CLANG_ALWAYS_INLINE", pasta::AlwaysInlineAttrSpelling::kC2xClangAlwaysInline)
    .value("KEYWORD_FORCEINLINE", pasta::AlwaysInlineAttrSpelling::kKeywordForceinline)
    .value("SPELLING_NOT_CALCULATED", pasta::AlwaysInlineAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AnnotateAttrSpelling>(m, "AnnotateAttrSpelling")
    .value("GNU_ANNOTATE", pasta::AnnotateAttrSpelling::kGNUAnnotate)
    .value("CXX11_CLANG_ANNOTATE", pasta::AnnotateAttrSpelling::kCXX11ClangAnnotate)
    .value("C2X_CLANG_ANNOTATE", pasta::AnnotateAttrSpelling::kC2xClangAnnotate)
    .value("SPELLING_NOT_CALCULATED", pasta::AnnotateAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AnnotateTypeAttrSpelling>(m, "AnnotateTypeAttrSpelling")
    .value("CXX11_CLANG_ANNOTATE_TYPE", pasta::AnnotateTypeAttrSpelling::kCXX11ClangAnnotateType)
    .value("C2X_CLANG_ANNOTATE_TYPE", pasta::AnnotateTypeAttrSpelling::kC2xClangAnnotateType)
    .value("SPELLING_NOT_CALCULATED", pasta::AnnotateTypeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AnyX86InterruptAttrSpelling>(m, "AnyX86InterruptAttrSpelling")
    .value("GNU_INTERRUPT", pasta::AnyX86InterruptAttrSpelling::kGNUInterrupt)
    .value("CXX11_GNU_INTERRUPT", pasta::AnyX86InterruptAttrSpelling::kCXX11GnuInterrupt)
    .value("C2X_GNU_INTERRUPT", pasta::AnyX86InterruptAttrSpelling::kC2xGnuInterrupt)
    .value("SPELLING_NOT_CALCULATED", pasta::AnyX86InterruptAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AnyX86NoCallerSavedRegistersAttrSpelling>(m, "AnyX86NoCallerSavedRegistersAttrSpelling")
    .value("GNU_NO_CALLER_SAVED_REGISTERS", pasta::AnyX86NoCallerSavedRegistersAttrSpelling::kGNUNoCallerSavedRegisters)
    .value("CXX11_GNU_NO_CALLER_SAVED_REGISTERS", pasta::AnyX86NoCallerSavedRegistersAttrSpelling::kCXX11GnuNoCallerSavedRegisters)
    .value("C2X_GNU_NO_CALLER_SAVED_REGISTERS", pasta::AnyX86NoCallerSavedRegistersAttrSpelling::kC2xGnuNoCallerSavedRegisters)
    .value("SPELLING_NOT_CALCULATED", pasta::AnyX86NoCallerSavedRegistersAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AnyX86NoCfCheckAttrSpelling>(m, "AnyX86NoCfCheckAttrSpelling")
    .value("GNU_NOCF_CHECK", pasta::AnyX86NoCfCheckAttrSpelling::kGNUNocfCheck)
    .value("CXX11_GNU_NOCF_CHECK", pasta::AnyX86NoCfCheckAttrSpelling::kCXX11GnuNocfCheck)
    .value("C2X_GNU_NOCF_CHECK", pasta::AnyX86NoCfCheckAttrSpelling::kC2xGnuNocfCheck)
    .value("SPELLING_NOT_CALCULATED", pasta::AnyX86NoCfCheckAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ArcWeakrefUnavailableAttrSpelling>(m, "ArcWeakrefUnavailableAttrSpelling")
    .value("GNU_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE", pasta::ArcWeakrefUnavailableAttrSpelling::kGNUObjcArcWeakReferenceUnavailable)
    .value("CXX11_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE", pasta::ArcWeakrefUnavailableAttrSpelling::kCXX11ClangObjcArcWeakReferenceUnavailable)
    .value("C2X_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE", pasta::ArcWeakrefUnavailableAttrSpelling::kC2xClangObjcArcWeakReferenceUnavailable)
    .value("SPELLING_NOT_CALCULATED", pasta::ArcWeakrefUnavailableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ArgumentWithTypeTagAttrSpelling>(m, "ArgumentWithTypeTagAttrSpelling")
    .value("GNU_ARGUMENT_WITH_TYPE_TAG", pasta::ArgumentWithTypeTagAttrSpelling::kGNUArgumentWithTypeTag)
    .value("CXX11_CLANG_ARGUMENT_WITH_TYPE_TAG", pasta::ArgumentWithTypeTagAttrSpelling::kCXX11ClangArgumentWithTypeTag)
    .value("C2X_CLANG_ARGUMENT_WITH_TYPE_TAG", pasta::ArgumentWithTypeTagAttrSpelling::kC2xClangArgumentWithTypeTag)
    .value("GNU_POINTER_WITH_TYPE_TAG", pasta::ArgumentWithTypeTagAttrSpelling::kGNUPointerWithTypeTag)
    .value("CXX11_CLANG_POINTER_WITH_TYPE_TAG", pasta::ArgumentWithTypeTagAttrSpelling::kCXX11ClangPointerWithTypeTag)
    .value("C2X_CLANG_POINTER_WITH_TYPE_TAG", pasta::ArgumentWithTypeTagAttrSpelling::kC2xClangPointerWithTypeTag)
    .value("SPELLING_NOT_CALCULATED", pasta::ArgumentWithTypeTagAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ArmBuiltinAliasAttrSpelling>(m, "ArmBuiltinAliasAttrSpelling")
    .value("GNU_CLANG_ARM_BUILTIN_ALIAS", pasta::ArmBuiltinAliasAttrSpelling::kGNUClangArmBuiltinAlias)
    .value("CXX11_CLANG_CLANG_ARM_BUILTIN_ALIAS", pasta::ArmBuiltinAliasAttrSpelling::kCXX11ClangClangArmBuiltinAlias)
    .value("C2X_CLANG_CLANG_ARM_BUILTIN_ALIAS", pasta::ArmBuiltinAliasAttrSpelling::kC2xClangClangArmBuiltinAlias)
    .value("SPELLING_NOT_CALCULATED", pasta::ArmBuiltinAliasAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ArmMveStrictPolymorphismAttrSpelling>(m, "ArmMveStrictPolymorphismAttrSpelling")
    .value("GNU_CLANG_ARM_MVE_STRICT_POLYMORPHISM", pasta::ArmMveStrictPolymorphismAttrSpelling::kGNUClangArmMveStrictPolymorphism)
    .value("CXX11_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM", pasta::ArmMveStrictPolymorphismAttrSpelling::kCXX11ClangClangArmMveStrictPolymorphism)
    .value("C2X_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM", pasta::ArmMveStrictPolymorphismAttrSpelling::kC2xClangClangArmMveStrictPolymorphism)
    .value("SPELLING_NOT_CALCULATED", pasta::ArmMveStrictPolymorphismAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ArrayTypeArraySizeModifier>(m, "ArrayTypeArraySizeModifier")
    .value("NORMAL", pasta::ArrayTypeArraySizeModifier::kNormal)
    .value("STATIC", pasta::ArrayTypeArraySizeModifier::kStatic)
    .value("STAR", pasta::ArrayTypeArraySizeModifier::kStar);

  nb::enum_<pasta::ArtificialAttrSpelling>(m, "ArtificialAttrSpelling")
    .value("GNU_ARTIFICIAL", pasta::ArtificialAttrSpelling::kGNUArtificial)
    .value("CXX11_GNU_ARTIFICIAL", pasta::ArtificialAttrSpelling::kCXX11GnuArtificial)
    .value("C2X_GNU_ARTIFICIAL", pasta::ArtificialAttrSpelling::kC2xGnuArtificial)
    .value("SPELLING_NOT_CALCULATED", pasta::ArtificialAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AsmLabelAttrSpelling>(m, "AsmLabelAttrSpelling")
    .value("KEYWORD_ASSEMBLY", pasta::AsmLabelAttrSpelling::kKeywordAssembly)
    .value("SPELLING_NOT_CALCULATED", pasta::AsmLabelAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AssertCapabilityAttrSpelling>(m, "AssertCapabilityAttrSpelling")
    .value("GNU_ASSERT_CAPABILITY", pasta::AssertCapabilityAttrSpelling::kGNUAssertCapability)
    .value("CXX11_CLANG_ASSERT_CAPABILITY", pasta::AssertCapabilityAttrSpelling::kCXX11ClangAssertCapability)
    .value("GNU_ASSERT_SHARED_CAPABILITY", pasta::AssertCapabilityAttrSpelling::kGNUAssertSharedCapability)
    .value("CXX11_CLANG_ASSERT_SHARED_CAPABILITY", pasta::AssertCapabilityAttrSpelling::kCXX11ClangAssertSharedCapability)
    .value("SPELLING_NOT_CALCULATED", pasta::AssertCapabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AssumeAlignedAttrSpelling>(m, "AssumeAlignedAttrSpelling")
    .value("GNU_ASSUME_ALIGNED", pasta::AssumeAlignedAttrSpelling::kGNUAssumeAligned)
    .value("CXX11_GNU_ASSUME_ALIGNED", pasta::AssumeAlignedAttrSpelling::kCXX11GnuAssumeAligned)
    .value("C2X_GNU_ASSUME_ALIGNED", pasta::AssumeAlignedAttrSpelling::kC2xGnuAssumeAligned)
    .value("SPELLING_NOT_CALCULATED", pasta::AssumeAlignedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AssumptionAttrSpelling>(m, "AssumptionAttrSpelling")
    .value("GNU_ASSUME", pasta::AssumptionAttrSpelling::kGNUAssume)
    .value("CXX11_CLANG_ASSUME", pasta::AssumptionAttrSpelling::kCXX11ClangAssume)
    .value("C2X_CLANG_ASSUME", pasta::AssumptionAttrSpelling::kC2xClangAssume)
    .value("SPELLING_NOT_CALCULATED", pasta::AssumptionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::AtomicExprAtomicOp>(m, "AtomicExprAtomicOp")
    .value("C11_ATOMIC_INITIALIZER", pasta::AtomicExprAtomicOp::kC11AtomicInitializer)
    .value("C11_ATOMIC_LOAD", pasta::AtomicExprAtomicOp::kC11AtomicLoad)
    .value("C11_ATOMIC_STORE", pasta::AtomicExprAtomicOp::kC11AtomicStore)
    .value("C11_ATOMIC_EXCHANGE", pasta::AtomicExprAtomicOp::kC11AtomicExchange)
    .value("C11_ATOMIC_COMPARE_EXCHANGE_STRONG", pasta::AtomicExprAtomicOp::kC11AtomicCompareExchangeStrong)
    .value("C11_ATOMIC_COMPARE_EXCHANGE_WEAK", pasta::AtomicExprAtomicOp::kC11AtomicCompareExchangeWeak)
    .value("C11_ATOMIC_FETCH_ADD", pasta::AtomicExprAtomicOp::kC11AtomicFetchAdd)
    .value("C11_ATOMIC_FETCH_SUB", pasta::AtomicExprAtomicOp::kC11AtomicFetchSub)
    .value("C11_ATOMIC_FETCH_AND", pasta::AtomicExprAtomicOp::kC11AtomicFetchAnd)
    .value("C11_ATOMIC_FETCH_OR", pasta::AtomicExprAtomicOp::kC11AtomicFetchOr)
    .value("C11_ATOMIC_FETCH_XOR", pasta::AtomicExprAtomicOp::kC11AtomicFetchXor)
    .value("C11_ATOMIC_FETCH_NAND", pasta::AtomicExprAtomicOp::kC11AtomicFetchNand)
    .value("C11_ATOMIC_FETCH_MAX", pasta::AtomicExprAtomicOp::kC11AtomicFetchMax)
    .value("C11_ATOMIC_FETCH_MIN", pasta::AtomicExprAtomicOp::kC11AtomicFetchMin)
    .value("ATOMIC_LOAD", pasta::AtomicExprAtomicOp::kAtomicLoad)
    .value("ATOMIC_LOAD_N", pasta::AtomicExprAtomicOp::kAtomicLoadN)
    .value("ATOMIC_STORE", pasta::AtomicExprAtomicOp::kAtomicStore)
    .value("ATOMIC_STORE_N", pasta::AtomicExprAtomicOp::kAtomicStoreN)
    .value("ATOMIC_EXCHANGE", pasta::AtomicExprAtomicOp::kAtomicExchange)
    .value("ATOMIC_EXCHANGE_N", pasta::AtomicExprAtomicOp::kAtomicExchangeN)
    .value("ATOMIC_COMPARE_EXCHANGE", pasta::AtomicExprAtomicOp::kAtomicCompareExchange)
    .value("ATOMIC_COMPARE_EXCHANGE_N", pasta::AtomicExprAtomicOp::kAtomicCompareExchangeN)
    .value("ATOMIC_FETCH_ADD", pasta::AtomicExprAtomicOp::kAtomicFetchAdd)
    .value("ATOMIC_FETCH_SUB", pasta::AtomicExprAtomicOp::kAtomicFetchSub)
    .value("ATOMIC_FETCH_AND", pasta::AtomicExprAtomicOp::kAtomicFetchAnd)
    .value("ATOMIC_FETCH_OR", pasta::AtomicExprAtomicOp::kAtomicFetchOr)
    .value("ATOMIC_FETCH_XOR", pasta::AtomicExprAtomicOp::kAtomicFetchXor)
    .value("ATOMIC_FETCH_NAND", pasta::AtomicExprAtomicOp::kAtomicFetchNand)
    .value("ATOMIC_ADD_FETCH", pasta::AtomicExprAtomicOp::kAtomicAddFetch)
    .value("ATOMIC_SUB_FETCH", pasta::AtomicExprAtomicOp::kAtomicSubFetch)
    .value("ATOMIC_AND_FETCH", pasta::AtomicExprAtomicOp::kAtomicAndFetch)
    .value("ATOMIC_OR_FETCH", pasta::AtomicExprAtomicOp::kAtomicOrFetch)
    .value("ATOMIC_XOR_FETCH", pasta::AtomicExprAtomicOp::kAtomicXorFetch)
    .value("ATOMIC_MAX_FETCH", pasta::AtomicExprAtomicOp::kAtomicMaxFetch)
    .value("ATOMIC_MIN_FETCH", pasta::AtomicExprAtomicOp::kAtomicMinFetch)
    .value("ATOMIC_NAND_FETCH", pasta::AtomicExprAtomicOp::kAtomicNandFetch)
    .value("OPENCL_ATOMIC_INITIALIZER", pasta::AtomicExprAtomicOp::kOpenclAtomicInitializer)
    .value("OPENCL_ATOMIC_LOAD", pasta::AtomicExprAtomicOp::kOpenclAtomicLoad)
    .value("OPENCL_ATOMIC_STORE", pasta::AtomicExprAtomicOp::kOpenclAtomicStore)
    .value("OPENCL_ATOMIC_EXCHANGE", pasta::AtomicExprAtomicOp::kOpenclAtomicExchange)
    .value("OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG", pasta::AtomicExprAtomicOp::kOpenclAtomicCompareExchangeStrong)
    .value("OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK", pasta::AtomicExprAtomicOp::kOpenclAtomicCompareExchangeWeak)
    .value("OPENCL_ATOMIC_FETCH_ADD", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchAdd)
    .value("OPENCL_ATOMIC_FETCH_SUB", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchSub)
    .value("OPENCL_ATOMIC_FETCH_AND", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchAnd)
    .value("OPENCL_ATOMIC_FETCH_OR", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchOr)
    .value("OPENCL_ATOMIC_FETCH_XOR", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchXor)
    .value("OPENCL_ATOMIC_FETCH_MIN", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchMin)
    .value("OPENCL_ATOMIC_FETCH_MAX", pasta::AtomicExprAtomicOp::kOpenclAtomicFetchMax)
    .value("ATOMIC_FETCH_MIN", pasta::AtomicExprAtomicOp::kAtomicFetchMin)
    .value("ATOMIC_FETCH_MAX", pasta::AtomicExprAtomicOp::kAtomicFetchMax)
    .value("HIP_ATOMIC_LOAD", pasta::AtomicExprAtomicOp::kHipAtomicLoad)
    .value("HIP_ATOMIC_STORE", pasta::AtomicExprAtomicOp::kHipAtomicStore)
    .value("HIP_ATOMIC_COMPARE_EXCHANGE_WEAK", pasta::AtomicExprAtomicOp::kHipAtomicCompareExchangeWeak)
    .value("HIP_ATOMIC_COMPARE_EXCHANGE_STRONG", pasta::AtomicExprAtomicOp::kHipAtomicCompareExchangeStrong)
    .value("HIP_ATOMIC_EXCHANGE", pasta::AtomicExprAtomicOp::kHipAtomicExchange)
    .value("HIP_ATOMIC_FETCH_ADD", pasta::AtomicExprAtomicOp::kHipAtomicFetchAdd)
    .value("HIP_ATOMIC_FETCH_AND", pasta::AtomicExprAtomicOp::kHipAtomicFetchAnd)
    .value("HIP_ATOMIC_FETCH_OR", pasta::AtomicExprAtomicOp::kHipAtomicFetchOr)
    .value("HIP_ATOMIC_FETCH_XOR", pasta::AtomicExprAtomicOp::kHipAtomicFetchXor)
    .value("HIP_ATOMIC_FETCH_MIN", pasta::AtomicExprAtomicOp::kHipAtomicFetchMin)
    .value("HIP_ATOMIC_FETCH_MAX", pasta::AtomicExprAtomicOp::kHipAtomicFetchMax);

  nb::enum_<pasta::AvailabilityAttrSpelling>(m, "AvailabilityAttrSpelling")
    .value("GNU_AVAILABILITY", pasta::AvailabilityAttrSpelling::kGNUAvailability)
    .value("CXX11_CLANG_AVAILABILITY", pasta::AvailabilityAttrSpelling::kCXX11ClangAvailability)
    .value("C2X_CLANG_AVAILABILITY", pasta::AvailabilityAttrSpelling::kC2xClangAvailability)
    .value("SPELLING_NOT_CALCULATED", pasta::AvailabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::BPFPreserveAccessIndexAttrSpelling>(m, "BPFPreserveAccessIndexAttrSpelling")
    .value("GNU_PRESERVE_ACCESS_INDEX", pasta::BPFPreserveAccessIndexAttrSpelling::kGNUPreserveAccessIndex)
    .value("CXX11_CLANG_PRESERVE_ACCESS_INDEX", pasta::BPFPreserveAccessIndexAttrSpelling::kCXX11ClangPreserveAccessIndex)
    .value("C2X_CLANG_PRESERVE_ACCESS_INDEX", pasta::BPFPreserveAccessIndexAttrSpelling::kC2xClangPreserveAccessIndex)
    .value("SPELLING_NOT_CALCULATED", pasta::BPFPreserveAccessIndexAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::BTFDeclTagAttrSpelling>(m, "BTFDeclTagAttrSpelling")
    .value("GNU_BTF_DECLARATION_TAG", pasta::BTFDeclTagAttrSpelling::kGNUBtfDeclarationTag)
    .value("CXX11_CLANG_BTF_DECLARATION_TAG", pasta::BTFDeclTagAttrSpelling::kCXX11ClangBtfDeclarationTag)
    .value("C2X_CLANG_BTF_DECLARATION_TAG", pasta::BTFDeclTagAttrSpelling::kC2xClangBtfDeclarationTag)
    .value("SPELLING_NOT_CALCULATED", pasta::BTFDeclTagAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::BTFTypeTagAttrSpelling>(m, "BTFTypeTagAttrSpelling")
    .value("GNU_BTF_TYPE_TAG", pasta::BTFTypeTagAttrSpelling::kGNUBtfTypeTag)
    .value("CXX11_CLANG_BTF_TYPE_TAG", pasta::BTFTypeTagAttrSpelling::kCXX11ClangBtfTypeTag)
    .value("C2X_CLANG_BTF_TYPE_TAG", pasta::BTFTypeTagAttrSpelling::kC2xClangBtfTypeTag)
    .value("SPELLING_NOT_CALCULATED", pasta::BTFTypeTagAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::BlocksAttrBlockType>(m, "BlocksAttrBlockType")
    .value("BY_REFERENCE", pasta::BlocksAttrBlockType::kByReference);

  nb::enum_<pasta::BlocksAttrSpelling>(m, "BlocksAttrSpelling")
    .value("GNU_BLOCKS", pasta::BlocksAttrSpelling::kGNUBlocks)
    .value("CXX11_CLANG_BLOCKS", pasta::BlocksAttrSpelling::kCXX11ClangBlocks)
    .value("C2X_CLANG_BLOCKS", pasta::BlocksAttrSpelling::kC2xClangBlocks)
    .value("SPELLING_NOT_CALCULATED", pasta::BlocksAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::BuiltinAliasAttrSpelling>(m, "BuiltinAliasAttrSpelling")
    .value("CXX11_CLANG_BUILTIN_ALIAS", pasta::BuiltinAliasAttrSpelling::kCXX11ClangBuiltinAlias)
    .value("C2X_CLANG_BUILTIN_ALIAS", pasta::BuiltinAliasAttrSpelling::kC2xClangBuiltinAlias)
    .value("GNU_CLANG_BUILTIN_ALIAS", pasta::BuiltinAliasAttrSpelling::kGNUClangBuiltinAlias)
    .value("SPELLING_NOT_CALCULATED", pasta::BuiltinAliasAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::BuiltinTypeKind>(m, "BuiltinTypeKind")
    .value("OCL_IMAGE_1D_RO", pasta::BuiltinTypeKind::kOCLImage1dRO)
    .value("OCL_IMAGE_1D_ARRAY_RO", pasta::BuiltinTypeKind::kOCLImage1dArrayRO)
    .value("OCL_IMAGE_1D_BUFFER_RO", pasta::BuiltinTypeKind::kOCLImage1dBufferRO)
    .value("OCL_IMAGE_2D_RO", pasta::BuiltinTypeKind::kOCLImage2dRO)
    .value("OCL_IMAGE_2D_ARRAY_RO", pasta::BuiltinTypeKind::kOCLImage2dArrayRO)
    .value("OCL_IMAGE_2D_DEPTH_RO", pasta::BuiltinTypeKind::kOCLImage2dDepthRO)
    .value("OCL_IMAGE_2D_ARRAY_DEPTH_RO", pasta::BuiltinTypeKind::kOCLImage2dArrayDepthRO)
    .value("OCL_IMAGE_2D_MSAARO", pasta::BuiltinTypeKind::kOCLImage2dMSAARO)
    .value("OCL_IMAGE_2D_ARRAY_MSAARO", pasta::BuiltinTypeKind::kOCLImage2dArrayMSAARO)
    .value("OCL_IMAGE_2D_MSAA_DEPTH_RO", pasta::BuiltinTypeKind::kOCLImage2dMSAADepthRO)
    .value("OCL_IMAGE_2D_ARRAY_MSAA_DEPTH_RO", pasta::BuiltinTypeKind::kOCLImage2dArrayMSAADepthRO)
    .value("OCL_IMAGE_3D_RO", pasta::BuiltinTypeKind::kOCLImage3dRO)
    .value("OCL_IMAGE_1D_WO", pasta::BuiltinTypeKind::kOCLImage1dWO)
    .value("OCL_IMAGE_1D_ARRAY_WO", pasta::BuiltinTypeKind::kOCLImage1dArrayWO)
    .value("OCL_IMAGE_1D_BUFFER_WO", pasta::BuiltinTypeKind::kOCLImage1dBufferWO)
    .value("OCL_IMAGE_2D_WO", pasta::BuiltinTypeKind::kOCLImage2dWO)
    .value("OCL_IMAGE_2D_ARRAY_WO", pasta::BuiltinTypeKind::kOCLImage2dArrayWO)
    .value("OCL_IMAGE_2D_DEPTH_WO", pasta::BuiltinTypeKind::kOCLImage2dDepthWO)
    .value("OCL_IMAGE_2D_ARRAY_DEPTH_WO", pasta::BuiltinTypeKind::kOCLImage2dArrayDepthWO)
    .value("OCL_IMAGE_2D_MSAAWO", pasta::BuiltinTypeKind::kOCLImage2dMSAAWO)
    .value("OCL_IMAGE_2D_ARRAY_MSAAWO", pasta::BuiltinTypeKind::kOCLImage2dArrayMSAAWO)
    .value("OCL_IMAGE_2D_MSAA_DEPTH_WO", pasta::BuiltinTypeKind::kOCLImage2dMSAADepthWO)
    .value("OCL_IMAGE_2D_ARRAY_MSAA_DEPTH_WO", pasta::BuiltinTypeKind::kOCLImage2dArrayMSAADepthWO)
    .value("OCL_IMAGE_3D_WO", pasta::BuiltinTypeKind::kOCLImage3dWO)
    .value("OCL_IMAGE_1D_RW", pasta::BuiltinTypeKind::kOCLImage1dRW)
    .value("OCL_IMAGE_1D_ARRAY_RW", pasta::BuiltinTypeKind::kOCLImage1dArrayRW)
    .value("OCL_IMAGE_1D_BUFFER_RW", pasta::BuiltinTypeKind::kOCLImage1dBufferRW)
    .value("OCL_IMAGE_2D_RW", pasta::BuiltinTypeKind::kOCLImage2dRW)
    .value("OCL_IMAGE_2D_ARRAY_RW", pasta::BuiltinTypeKind::kOCLImage2dArrayRW)
    .value("OCL_IMAGE_2D_DEPTH_RW", pasta::BuiltinTypeKind::kOCLImage2dDepthRW)
    .value("OCL_IMAGE_2D_ARRAY_DEPTH_RW", pasta::BuiltinTypeKind::kOCLImage2dArrayDepthRW)
    .value("OCL_IMAGE_2D_MSAARW", pasta::BuiltinTypeKind::kOCLImage2dMSAARW)
    .value("OCL_IMAGE_2D_ARRAY_MSAARW", pasta::BuiltinTypeKind::kOCLImage2dArrayMSAARW)
    .value("OCL_IMAGE_2D_MSAA_DEPTH_RW", pasta::BuiltinTypeKind::kOCLImage2dMSAADepthRW)
    .value("OCL_IMAGE_2D_ARRAY_MSAA_DEPTH_RW", pasta::BuiltinTypeKind::kOCLImage2dArrayMSAADepthRW)
    .value("OCL_IMAGE_3D_RW", pasta::BuiltinTypeKind::kOCLImage3dRW)
    .value("OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCMcePayload)
    .value("OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImePayload)
    .value("OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCRefPayload)
    .value("OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCSicPayload)
    .value("OCL_INTEL_SUBGROUP_AVC_MCE_RESULT", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCMceResult)
    .value("OCL_INTEL_SUBGROUP_AVC_IME_RESULT", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeResult)
    .value("OCL_INTEL_SUBGROUP_AVC_REF_RESULT", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCRefResult)
    .value("OCL_INTEL_SUBGROUP_AVC_SIC_RESULT", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCSicResult)
    .value("OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeResultSingleReferenceStreamout)
    .value("OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeResultDualReferenceStreamout)
    .value("OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeSingleReferenceStreamin)
    .value("OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN", pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeDualReferenceStreamin)
    .value("SVE_INT8", pasta::BuiltinTypeKind::kSveInt8)
    .value("SVE_INT16", pasta::BuiltinTypeKind::kSveInt16)
    .value("SVE_INT32", pasta::BuiltinTypeKind::kSveInt32)
    .value("SVE_INT64", pasta::BuiltinTypeKind::kSveInt64)
    .value("SVE_UINT8", pasta::BuiltinTypeKind::kSveUint8)
    .value("SVE_UINT16", pasta::BuiltinTypeKind::kSveUint16)
    .value("SVE_UINT32", pasta::BuiltinTypeKind::kSveUint32)
    .value("SVE_UINT64", pasta::BuiltinTypeKind::kSveUint64)
    .value("SVE_FLOAT16", pasta::BuiltinTypeKind::kSveFloat16)
    .value("SVE_FLOAT32", pasta::BuiltinTypeKind::kSveFloat32)
    .value("SVE_FLOAT64", pasta::BuiltinTypeKind::kSveFloat64)
    .value("SVE_B_FLOAT16", pasta::BuiltinTypeKind::kSveBFloat16)
    .value("SVE_INT8X2", pasta::BuiltinTypeKind::kSveInt8x2)
    .value("SVE_INT16X2", pasta::BuiltinTypeKind::kSveInt16x2)
    .value("SVE_INT32X2", pasta::BuiltinTypeKind::kSveInt32x2)
    .value("SVE_INT64X2", pasta::BuiltinTypeKind::kSveInt64x2)
    .value("SVE_UINT8X2", pasta::BuiltinTypeKind::kSveUint8x2)
    .value("SVE_UINT16X2", pasta::BuiltinTypeKind::kSveUint16x2)
    .value("SVE_UINT32X2", pasta::BuiltinTypeKind::kSveUint32x2)
    .value("SVE_UINT64X2", pasta::BuiltinTypeKind::kSveUint64x2)
    .value("SVE_FLOAT16X2", pasta::BuiltinTypeKind::kSveFloat16x2)
    .value("SVE_FLOAT32X2", pasta::BuiltinTypeKind::kSveFloat32x2)
    .value("SVE_FLOAT64X2", pasta::BuiltinTypeKind::kSveFloat64x2)
    .value("SVE_B_FLOAT16X2", pasta::BuiltinTypeKind::kSveBFloat16x2)
    .value("SVE_INT8X3", pasta::BuiltinTypeKind::kSveInt8x3)
    .value("SVE_INT16X3", pasta::BuiltinTypeKind::kSveInt16x3)
    .value("SVE_INT32X3", pasta::BuiltinTypeKind::kSveInt32x3)
    .value("SVE_INT64X3", pasta::BuiltinTypeKind::kSveInt64x3)
    .value("SVE_UINT8X3", pasta::BuiltinTypeKind::kSveUint8x3)
    .value("SVE_UINT16X3", pasta::BuiltinTypeKind::kSveUint16x3)
    .value("SVE_UINT32X3", pasta::BuiltinTypeKind::kSveUint32x3)
    .value("SVE_UINT64X3", pasta::BuiltinTypeKind::kSveUint64x3)
    .value("SVE_FLOAT16X3", pasta::BuiltinTypeKind::kSveFloat16x3)
    .value("SVE_FLOAT32X3", pasta::BuiltinTypeKind::kSveFloat32x3)
    .value("SVE_FLOAT64X3", pasta::BuiltinTypeKind::kSveFloat64x3)
    .value("SVE_B_FLOAT16X3", pasta::BuiltinTypeKind::kSveBFloat16x3)
    .value("SVE_INT8X4", pasta::BuiltinTypeKind::kSveInt8x4)
    .value("SVE_INT16X4", pasta::BuiltinTypeKind::kSveInt16x4)
    .value("SVE_INT32X4", pasta::BuiltinTypeKind::kSveInt32x4)
    .value("SVE_INT64X4", pasta::BuiltinTypeKind::kSveInt64x4)
    .value("SVE_UINT8X4", pasta::BuiltinTypeKind::kSveUint8x4)
    .value("SVE_UINT16X4", pasta::BuiltinTypeKind::kSveUint16x4)
    .value("SVE_UINT32X4", pasta::BuiltinTypeKind::kSveUint32x4)
    .value("SVE_UINT64X4", pasta::BuiltinTypeKind::kSveUint64x4)
    .value("SVE_FLOAT16X4", pasta::BuiltinTypeKind::kSveFloat16x4)
    .value("SVE_FLOAT32X4", pasta::BuiltinTypeKind::kSveFloat32x4)
    .value("SVE_FLOAT64X4", pasta::BuiltinTypeKind::kSveFloat64x4)
    .value("SVE_B_FLOAT16X4", pasta::BuiltinTypeKind::kSveBFloat16x4)
    .value("SVE_BOOLEAN", pasta::BuiltinTypeKind::kSveBoolean)
    .value("VECTOR_QUAD", pasta::BuiltinTypeKind::kVectorQuad)
    .value("VECTOR_PAIR", pasta::BuiltinTypeKind::kVectorPair)
    .value("RVV_INT8MF8", pasta::BuiltinTypeKind::kRvvInt8mf8)
    .value("RVV_INT8MF4", pasta::BuiltinTypeKind::kRvvInt8mf4)
    .value("RVV_INT8MF2", pasta::BuiltinTypeKind::kRvvInt8mf2)
    .value("RVV_INT8M1", pasta::BuiltinTypeKind::kRvvInt8m1)
    .value("RVV_INT8M2", pasta::BuiltinTypeKind::kRvvInt8m2)
    .value("RVV_INT8M4", pasta::BuiltinTypeKind::kRvvInt8m4)
    .value("RVV_INT8M8", pasta::BuiltinTypeKind::kRvvInt8m8)
    .value("RVV_UINT8MF8", pasta::BuiltinTypeKind::kRvvUint8mf8)
    .value("RVV_UINT8MF4", pasta::BuiltinTypeKind::kRvvUint8mf4)
    .value("RVV_UINT8MF2", pasta::BuiltinTypeKind::kRvvUint8mf2)
    .value("RVV_UINT8M1", pasta::BuiltinTypeKind::kRvvUint8m1)
    .value("RVV_UINT8M2", pasta::BuiltinTypeKind::kRvvUint8m2)
    .value("RVV_UINT8M4", pasta::BuiltinTypeKind::kRvvUint8m4)
    .value("RVV_UINT8M8", pasta::BuiltinTypeKind::kRvvUint8m8)
    .value("RVV_INT16MF4", pasta::BuiltinTypeKind::kRvvInt16mf4)
    .value("RVV_INT16MF2", pasta::BuiltinTypeKind::kRvvInt16mf2)
    .value("RVV_INT16M1", pasta::BuiltinTypeKind::kRvvInt16m1)
    .value("RVV_INT16M2", pasta::BuiltinTypeKind::kRvvInt16m2)
    .value("RVV_INT16M4", pasta::BuiltinTypeKind::kRvvInt16m4)
    .value("RVV_INT16M8", pasta::BuiltinTypeKind::kRvvInt16m8)
    .value("RVV_UINT16MF4", pasta::BuiltinTypeKind::kRvvUint16mf4)
    .value("RVV_UINT16MF2", pasta::BuiltinTypeKind::kRvvUint16mf2)
    .value("RVV_UINT16M1", pasta::BuiltinTypeKind::kRvvUint16m1)
    .value("RVV_UINT16M2", pasta::BuiltinTypeKind::kRvvUint16m2)
    .value("RVV_UINT16M4", pasta::BuiltinTypeKind::kRvvUint16m4)
    .value("RVV_UINT16M8", pasta::BuiltinTypeKind::kRvvUint16m8)
    .value("RVV_INT32MF2", pasta::BuiltinTypeKind::kRvvInt32mf2)
    .value("RVV_INT32M1", pasta::BuiltinTypeKind::kRvvInt32m1)
    .value("RVV_INT32M2", pasta::BuiltinTypeKind::kRvvInt32m2)
    .value("RVV_INT32M4", pasta::BuiltinTypeKind::kRvvInt32m4)
    .value("RVV_INT32M8", pasta::BuiltinTypeKind::kRvvInt32m8)
    .value("RVV_UINT32MF2", pasta::BuiltinTypeKind::kRvvUint32mf2)
    .value("RVV_UINT32M1", pasta::BuiltinTypeKind::kRvvUint32m1)
    .value("RVV_UINT32M2", pasta::BuiltinTypeKind::kRvvUint32m2)
    .value("RVV_UINT32M4", pasta::BuiltinTypeKind::kRvvUint32m4)
    .value("RVV_UINT32M8", pasta::BuiltinTypeKind::kRvvUint32m8)
    .value("RVV_INT64M1", pasta::BuiltinTypeKind::kRvvInt64m1)
    .value("RVV_INT64M2", pasta::BuiltinTypeKind::kRvvInt64m2)
    .value("RVV_INT64M4", pasta::BuiltinTypeKind::kRvvInt64m4)
    .value("RVV_INT64M8", pasta::BuiltinTypeKind::kRvvInt64m8)
    .value("RVV_UINT64M1", pasta::BuiltinTypeKind::kRvvUint64m1)
    .value("RVV_UINT64M2", pasta::BuiltinTypeKind::kRvvUint64m2)
    .value("RVV_UINT64M4", pasta::BuiltinTypeKind::kRvvUint64m4)
    .value("RVV_UINT64M8", pasta::BuiltinTypeKind::kRvvUint64m8)
    .value("RVV_FLOAT16MF4", pasta::BuiltinTypeKind::kRvvFloat16mf4)
    .value("RVV_FLOAT16MF2", pasta::BuiltinTypeKind::kRvvFloat16mf2)
    .value("RVV_FLOAT16M1", pasta::BuiltinTypeKind::kRvvFloat16m1)
    .value("RVV_FLOAT16M2", pasta::BuiltinTypeKind::kRvvFloat16m2)
    .value("RVV_FLOAT16M4", pasta::BuiltinTypeKind::kRvvFloat16m4)
    .value("RVV_FLOAT16M8", pasta::BuiltinTypeKind::kRvvFloat16m8)
    .value("RVV_FLOAT32MF2", pasta::BuiltinTypeKind::kRvvFloat32mf2)
    .value("RVV_FLOAT32M1", pasta::BuiltinTypeKind::kRvvFloat32m1)
    .value("RVV_FLOAT32M2", pasta::BuiltinTypeKind::kRvvFloat32m2)
    .value("RVV_FLOAT32M4", pasta::BuiltinTypeKind::kRvvFloat32m4)
    .value("RVV_FLOAT32M8", pasta::BuiltinTypeKind::kRvvFloat32m8)
    .value("RVV_FLOAT64M1", pasta::BuiltinTypeKind::kRvvFloat64m1)
    .value("RVV_FLOAT64M2", pasta::BuiltinTypeKind::kRvvFloat64m2)
    .value("RVV_FLOAT64M4", pasta::BuiltinTypeKind::kRvvFloat64m4)
    .value("RVV_FLOAT64M8", pasta::BuiltinTypeKind::kRvvFloat64m8)
    .value("RVV_BOOL1", pasta::BuiltinTypeKind::kRvvBool1)
    .value("RVV_BOOL2", pasta::BuiltinTypeKind::kRvvBool2)
    .value("RVV_BOOL4", pasta::BuiltinTypeKind::kRvvBool4)
    .value("RVV_BOOL8", pasta::BuiltinTypeKind::kRvvBool8)
    .value("RVV_BOOL16", pasta::BuiltinTypeKind::kRvvBool16)
    .value("RVV_BOOL32", pasta::BuiltinTypeKind::kRvvBool32)
    .value("RVV_BOOL64", pasta::BuiltinTypeKind::kRvvBool64)
    .value("VOID", pasta::BuiltinTypeKind::kVoid)
    .value("BOOLEAN", pasta::BuiltinTypeKind::kBoolean)
    .value("CHARACTER_U", pasta::BuiltinTypeKind::kCharacterU)
    .value("U_CHAR", pasta::BuiltinTypeKind::kUChar)
    .value("W_CHAR_U", pasta::BuiltinTypeKind::kWCharU)
    .value("CHAR8", pasta::BuiltinTypeKind::kChar8)
    .value("CHAR16", pasta::BuiltinTypeKind::kChar16)
    .value("CHAR32", pasta::BuiltinTypeKind::kChar32)
    .value("U_SHORT", pasta::BuiltinTypeKind::kUShort)
    .value("U_INT", pasta::BuiltinTypeKind::kUInt)
    .value("U_LONG", pasta::BuiltinTypeKind::kULong)
    .value("U_LONG_LONG", pasta::BuiltinTypeKind::kULongLong)
    .value("U_INT128", pasta::BuiltinTypeKind::kUInt128)
    .value("CHARACTER_S", pasta::BuiltinTypeKind::kCharacterS)
    .value("S_CHAR", pasta::BuiltinTypeKind::kSChar)
    .value("W_CHAR_S", pasta::BuiltinTypeKind::kWCharS)
    .value("SHORT", pasta::BuiltinTypeKind::kShort)
    .value("INT", pasta::BuiltinTypeKind::kInt)
    .value("LONG", pasta::BuiltinTypeKind::kLong)
    .value("LONG_LONG", pasta::BuiltinTypeKind::kLongLong)
    .value("INT128", pasta::BuiltinTypeKind::kInt128)
    .value("SHORT_ACCUM", pasta::BuiltinTypeKind::kShortAccum)
    .value("ACCUM", pasta::BuiltinTypeKind::kAccum)
    .value("LONG_ACCUM", pasta::BuiltinTypeKind::kLongAccum)
    .value("U_SHORT_ACCUM", pasta::BuiltinTypeKind::kUShortAccum)
    .value("U_ACCUM", pasta::BuiltinTypeKind::kUAccum)
    .value("U_LONG_ACCUM", pasta::BuiltinTypeKind::kULongAccum)
    .value("SHORT_FRACT", pasta::BuiltinTypeKind::kShortFract)
    .value("FRACT", pasta::BuiltinTypeKind::kFract)
    .value("LONG_FRACT", pasta::BuiltinTypeKind::kLongFract)
    .value("U_SHORT_FRACT", pasta::BuiltinTypeKind::kUShortFract)
    .value("U_FRACT", pasta::BuiltinTypeKind::kUFract)
    .value("U_LONG_FRACT", pasta::BuiltinTypeKind::kULongFract)
    .value("SAT_SHORT_ACCUM", pasta::BuiltinTypeKind::kSatShortAccum)
    .value("SAT_ACCUM", pasta::BuiltinTypeKind::kSatAccum)
    .value("SAT_LONG_ACCUM", pasta::BuiltinTypeKind::kSatLongAccum)
    .value("SAT_U_SHORT_ACCUM", pasta::BuiltinTypeKind::kSatUShortAccum)
    .value("SAT_U_ACCUM", pasta::BuiltinTypeKind::kSatUAccum)
    .value("SAT_U_LONG_ACCUM", pasta::BuiltinTypeKind::kSatULongAccum)
    .value("SAT_SHORT_FRACT", pasta::BuiltinTypeKind::kSatShortFract)
    .value("SAT_FRACT", pasta::BuiltinTypeKind::kSatFract)
    .value("SAT_LONG_FRACT", pasta::BuiltinTypeKind::kSatLongFract)
    .value("SAT_U_SHORT_FRACT", pasta::BuiltinTypeKind::kSatUShortFract)
    .value("SAT_U_FRACT", pasta::BuiltinTypeKind::kSatUFract)
    .value("SAT_U_LONG_FRACT", pasta::BuiltinTypeKind::kSatULongFract)
    .value("HALF", pasta::BuiltinTypeKind::kHalf)
    .value("FLOAT", pasta::BuiltinTypeKind::kFloat)
    .value("DOUBLE", pasta::BuiltinTypeKind::kDouble)
    .value("LONG_DOUBLE", pasta::BuiltinTypeKind::kLongDouble)
    .value("FLOAT16", pasta::BuiltinTypeKind::kFloat16)
    .value("B_FLOAT16", pasta::BuiltinTypeKind::kBFloat16)
    .value("FLOAT128", pasta::BuiltinTypeKind::kFloat128)
    .value("IBM128", pasta::BuiltinTypeKind::kIbm128)
    .value("NULL_POINTER", pasta::BuiltinTypeKind::kNullPointer)
    .value("OBJ_C_ID", pasta::BuiltinTypeKind::kObjCId)
    .value("OBJ_C_CLASS", pasta::BuiltinTypeKind::kObjCClass)
    .value("OBJ_C_SEL", pasta::BuiltinTypeKind::kObjCSel)
    .value("OCL_SAMPLER", pasta::BuiltinTypeKind::kOCLSampler)
    .value("OCL_EVENT", pasta::BuiltinTypeKind::kOCLEvent)
    .value("OCL_CLK_EVENT", pasta::BuiltinTypeKind::kOCLClkEvent)
    .value("OCL_QUEUE", pasta::BuiltinTypeKind::kOCLQueue)
    .value("OCL_RESERVE_ID", pasta::BuiltinTypeKind::kOCLReserveID)
    .value("DEPENDENT", pasta::BuiltinTypeKind::kDependent)
    .value("OVERLOAD", pasta::BuiltinTypeKind::kOverload)
    .value("BOUND_MEMBER", pasta::BuiltinTypeKind::kBoundMember)
    .value("PSEUDO_OBJECT", pasta::BuiltinTypeKind::kPseudoObject)
    .value("UNKNOWN_ANY", pasta::BuiltinTypeKind::kUnknownAny)
    .value("BUILTIN_FN", pasta::BuiltinTypeKind::kBuiltinFn)
    .value("ARC_UNBRIDGED_CAST", pasta::BuiltinTypeKind::kARCUnbridgedCast)
    .value("INCOMPLETE_MATRIX_INDEX", pasta::BuiltinTypeKind::kIncompleteMatrixIndex)
    .value("OMP_ARRAY_SECTION", pasta::BuiltinTypeKind::kOMPArraySection)
    .value("OMP_ARRAY_SHAPING", pasta::BuiltinTypeKind::kOMPArrayShaping)
    .value("OMP_ITERATOR", pasta::BuiltinTypeKind::kOMPIterator);

  nb::enum_<pasta::CDeclAttrSpelling>(m, "CDeclAttrSpelling")
    .value("GNU_CDECL", pasta::CDeclAttrSpelling::kGNUCdecl)
    .value("CXX11_GNU_CDECL", pasta::CDeclAttrSpelling::kCXX11GnuCdecl)
    .value("C2X_GNU_CDECL", pasta::CDeclAttrSpelling::kC2xGnuCdecl)
    .value("KEYWORD_CDECL", pasta::CDeclAttrSpelling::kKeywordCdecl)
    .value("SPELLING_NOT_CALCULATED", pasta::CDeclAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFAuditedTransferAttrSpelling>(m, "CFAuditedTransferAttrSpelling")
    .value("GNU_CF_AUDITED_TRANSFER", pasta::CFAuditedTransferAttrSpelling::kGNUCfAuditedTransfer)
    .value("CXX11_CLANG_CF_AUDITED_TRANSFER", pasta::CFAuditedTransferAttrSpelling::kCXX11ClangCfAuditedTransfer)
    .value("C2X_CLANG_CF_AUDITED_TRANSFER", pasta::CFAuditedTransferAttrSpelling::kC2xClangCfAuditedTransfer)
    .value("SPELLING_NOT_CALCULATED", pasta::CFAuditedTransferAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFConsumedAttrSpelling>(m, "CFConsumedAttrSpelling")
    .value("GNU_CF_CONSUMED", pasta::CFConsumedAttrSpelling::kGNUCfConsumed)
    .value("CXX11_CLANG_CF_CONSUMED", pasta::CFConsumedAttrSpelling::kCXX11ClangCfConsumed)
    .value("C2X_CLANG_CF_CONSUMED", pasta::CFConsumedAttrSpelling::kC2xClangCfConsumed)
    .value("SPELLING_NOT_CALCULATED", pasta::CFConsumedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFGuardAttrGuardArg>(m, "CFGuardAttrGuardArg")
    .value("NOCF", pasta::CFGuardAttrGuardArg::kNocf);

  nb::enum_<pasta::CFGuardAttrSpelling>(m, "CFGuardAttrSpelling")
    .value("DECLSPEC_GUARD", pasta::CFGuardAttrSpelling::kDeclspecGuard)
    .value("GNU_GUARD", pasta::CFGuardAttrSpelling::kGNUGuard)
    .value("CXX11_CLANG_GUARD", pasta::CFGuardAttrSpelling::kCXX11ClangGuard)
    .value("C2X_CLANG_GUARD", pasta::CFGuardAttrSpelling::kC2xClangGuard)
    .value("SPELLING_NOT_CALCULATED", pasta::CFGuardAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFICanonicalJumpTableAttrSpelling>(m, "CFICanonicalJumpTableAttrSpelling")
    .value("GNU_CFI_CANONICAL_JUMP_TABLE", pasta::CFICanonicalJumpTableAttrSpelling::kGNUCfiCanonicalJumpTable)
    .value("CXX11_CLANG_CFI_CANONICAL_JUMP_TABLE", pasta::CFICanonicalJumpTableAttrSpelling::kCXX11ClangCfiCanonicalJumpTable)
    .value("C2X_CLANG_CFI_CANONICAL_JUMP_TABLE", pasta::CFICanonicalJumpTableAttrSpelling::kC2xClangCfiCanonicalJumpTable)
    .value("SPELLING_NOT_CALCULATED", pasta::CFICanonicalJumpTableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFReturnsNotRetainedAttrSpelling>(m, "CFReturnsNotRetainedAttrSpelling")
    .value("GNU_CF_RETURNS_NOT_RETAINED", pasta::CFReturnsNotRetainedAttrSpelling::kGNUCfReturnsNotRetained)
    .value("CXX11_CLANG_CF_RETURNS_NOT_RETAINED", pasta::CFReturnsNotRetainedAttrSpelling::kCXX11ClangCfReturnsNotRetained)
    .value("C2X_CLANG_CF_RETURNS_NOT_RETAINED", pasta::CFReturnsNotRetainedAttrSpelling::kC2xClangCfReturnsNotRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::CFReturnsNotRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFReturnsRetainedAttrSpelling>(m, "CFReturnsRetainedAttrSpelling")
    .value("GNU_CF_RETURNS_RETAINED", pasta::CFReturnsRetainedAttrSpelling::kGNUCfReturnsRetained)
    .value("CXX11_CLANG_CF_RETURNS_RETAINED", pasta::CFReturnsRetainedAttrSpelling::kCXX11ClangCfReturnsRetained)
    .value("C2X_CLANG_CF_RETURNS_RETAINED", pasta::CFReturnsRetainedAttrSpelling::kC2xClangCfReturnsRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::CFReturnsRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CFUnknownTransferAttrSpelling>(m, "CFUnknownTransferAttrSpelling")
    .value("GNU_CF_UNKNOWN_TRANSFER", pasta::CFUnknownTransferAttrSpelling::kGNUCfUnknownTransfer)
    .value("CXX11_CLANG_CF_UNKNOWN_TRANSFER", pasta::CFUnknownTransferAttrSpelling::kCXX11ClangCfUnknownTransfer)
    .value("C2X_CLANG_CF_UNKNOWN_TRANSFER", pasta::CFUnknownTransferAttrSpelling::kC2xClangCfUnknownTransfer)
    .value("SPELLING_NOT_CALCULATED", pasta::CFUnknownTransferAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CPUDispatchAttrSpelling>(m, "CPUDispatchAttrSpelling")
    .value("GNU_CPU_DISPATCH", pasta::CPUDispatchAttrSpelling::kGNUCpuDispatch)
    .value("CXX11_CLANG_CPU_DISPATCH", pasta::CPUDispatchAttrSpelling::kCXX11ClangCpuDispatch)
    .value("C2X_CLANG_CPU_DISPATCH", pasta::CPUDispatchAttrSpelling::kC2xClangCpuDispatch)
    .value("DECLSPEC_CPU_DISPATCH", pasta::CPUDispatchAttrSpelling::kDeclspecCpuDispatch)
    .value("SPELLING_NOT_CALCULATED", pasta::CPUDispatchAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CPUSpecificAttrSpelling>(m, "CPUSpecificAttrSpelling")
    .value("GNU_CPU_SPECIFIC", pasta::CPUSpecificAttrSpelling::kGNUCpuSpecific)
    .value("CXX11_CLANG_CPU_SPECIFIC", pasta::CPUSpecificAttrSpelling::kCXX11ClangCpuSpecific)
    .value("C2X_CLANG_CPU_SPECIFIC", pasta::CPUSpecificAttrSpelling::kC2xClangCpuSpecific)
    .value("DECLSPEC_CPU_SPECIFIC", pasta::CPUSpecificAttrSpelling::kDeclspecCpuSpecific)
    .value("SPELLING_NOT_CALCULATED", pasta::CPUSpecificAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDAConstantAttrSpelling>(m, "CUDAConstantAttrSpelling")
    .value("GNU_CONSTANT", pasta::CUDAConstantAttrSpelling::kGNUConstant)
    .value("DECLSPEC_CONSTANT", pasta::CUDAConstantAttrSpelling::kDeclspecConstant)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDAConstantAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDADeviceAttrSpelling>(m, "CUDADeviceAttrSpelling")
    .value("GNU_DEVICE", pasta::CUDADeviceAttrSpelling::kGNUDevice)
    .value("DECLSPEC_DEVICE", pasta::CUDADeviceAttrSpelling::kDeclspecDevice)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDADeviceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDADeviceBuiltinSurfaceTypeAttrSpelling>(m, "CUDADeviceBuiltinSurfaceTypeAttrSpelling")
    .value("GNU_DEVICE_BUILTIN_SURFACE_TYPE", pasta::CUDADeviceBuiltinSurfaceTypeAttrSpelling::kGNUDeviceBuiltinSurfaceType)
    .value("DECLSPEC_DEVICE_BUILTIN_SURFACE_TYPE", pasta::CUDADeviceBuiltinSurfaceTypeAttrSpelling::kDeclspecDeviceBuiltinSurfaceType)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDADeviceBuiltinSurfaceTypeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDADeviceBuiltinTextureTypeAttrSpelling>(m, "CUDADeviceBuiltinTextureTypeAttrSpelling")
    .value("GNU_DEVICE_BUILTIN_TEXTURE_TYPE", pasta::CUDADeviceBuiltinTextureTypeAttrSpelling::kGNUDeviceBuiltinTextureType)
    .value("DECLSPEC_DEVICE_BUILTIN_TEXTURE_TYPE", pasta::CUDADeviceBuiltinTextureTypeAttrSpelling::kDeclspecDeviceBuiltinTextureType)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDADeviceBuiltinTextureTypeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDAGlobalAttrSpelling>(m, "CUDAGlobalAttrSpelling")
    .value("GNU_GLOBAL", pasta::CUDAGlobalAttrSpelling::kGNUGlobal)
    .value("DECLSPEC_GLOBAL", pasta::CUDAGlobalAttrSpelling::kDeclspecGlobal)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDAGlobalAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDAHostAttrSpelling>(m, "CUDAHostAttrSpelling")
    .value("GNU_HOST", pasta::CUDAHostAttrSpelling::kGNUHost)
    .value("DECLSPEC_HOST", pasta::CUDAHostAttrSpelling::kDeclspecHost)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDAHostAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDALaunchBoundsAttrSpelling>(m, "CUDALaunchBoundsAttrSpelling")
    .value("GNU_LAUNCH_BOUNDS", pasta::CUDALaunchBoundsAttrSpelling::kGNULaunchBounds)
    .value("DECLSPEC_LAUNCH_BOUNDS", pasta::CUDALaunchBoundsAttrSpelling::kDeclspecLaunchBounds)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDALaunchBoundsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CUDASharedAttrSpelling>(m, "CUDASharedAttrSpelling")
    .value("GNU_SHARED", pasta::CUDASharedAttrSpelling::kGNUShared)
    .value("DECLSPEC_SHARED", pasta::CUDASharedAttrSpelling::kDeclspecShared)
    .value("SPELLING_NOT_CALCULATED", pasta::CUDASharedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CXX11NoReturnAttrSpelling>(m, "CXX11NoReturnAttrSpelling")
    .value("CXX11_NORETURN", pasta::CXX11NoReturnAttrSpelling::kCXX11Noreturn)
    .value("C2XNORETURN", pasta::CXX11NoReturnAttrSpelling::kC2xnoreturn)
    .value("C2X_NORETURN", pasta::CXX11NoReturnAttrSpelling::kC2xNoreturn)
    .value("SPELLING_NOT_CALCULATED", pasta::CXX11NoReturnAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CXXConstructExprConstructionKind>(m, "CXXConstructExprConstructionKind")
    .value("COMPLETE", pasta::CXXConstructExprConstructionKind::kComplete)
    .value("NON_VIRTUAL_BASE", pasta::CXXConstructExprConstructionKind::kNonVirtualBase)
    .value("VIRTUAL_BASE", pasta::CXXConstructExprConstructionKind::kVirtualBase)
    .value("DELEGATING", pasta::CXXConstructExprConstructionKind::kDelegating);

  nb::enum_<pasta::CXXNewExprInitializationStyle>(m, "CXXNewExprInitializationStyle")
    .value("NO_INITIALIZER", pasta::CXXNewExprInitializationStyle::kNoInitializer)
    .value("CALL_INITIALIZER", pasta::CXXNewExprInitializationStyle::kCallInitializer)
    .value("LIST_INITIALIZER", pasta::CXXNewExprInitializationStyle::kListInitializer);

  nb::enum_<pasta::CXXRecordDeclLambdaDependencyKind>(m, "CXXRecordDeclLambdaDependencyKind")
    .value("UNKNOWN", pasta::CXXRecordDeclLambdaDependencyKind::kUnknown)
    .value("ALWAYS_DEPENDENT", pasta::CXXRecordDeclLambdaDependencyKind::kAlwaysDependent)
    .value("NEVER_DEPENDENT", pasta::CXXRecordDeclLambdaDependencyKind::kNeverDependent);

  nb::enum_<pasta::CallExprADLCallKind>(m, "CallExprADLCallKind")
    .value("NOT_ADL", pasta::CallExprADLCallKind::kNotADL)
    .value("USES_ADL", pasta::CallExprADLCallKind::kUsesADL);

  nb::enum_<pasta::CallableWhenAttrConsumedState>(m, "CallableWhenAttrConsumedState")
    .value("UNKNOWN", pasta::CallableWhenAttrConsumedState::kUnknown)
    .value("CONSUMED", pasta::CallableWhenAttrConsumedState::kConsumed)
    .value("UNCONSUMED", pasta::CallableWhenAttrConsumedState::kUnconsumed);

  nb::enum_<pasta::CallableWhenAttrSpelling>(m, "CallableWhenAttrSpelling")
    .value("GNU_CALLABLE_WHEN", pasta::CallableWhenAttrSpelling::kGNUCallableWhen)
    .value("CXX11_CLANG_CALLABLE_WHEN", pasta::CallableWhenAttrSpelling::kCXX11ClangCallableWhen)
    .value("SPELLING_NOT_CALCULATED", pasta::CallableWhenAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CallbackAttrSpelling>(m, "CallbackAttrSpelling")
    .value("GNU_CALLBACK", pasta::CallbackAttrSpelling::kGNUCallback)
    .value("CXX11_CLANG_CALLBACK", pasta::CallbackAttrSpelling::kCXX11ClangCallback)
    .value("C2X_CLANG_CALLBACK", pasta::CallbackAttrSpelling::kC2xClangCallback)
    .value("SPELLING_NOT_CALCULATED", pasta::CallbackAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CalledOnceAttrSpelling>(m, "CalledOnceAttrSpelling")
    .value("GNU_CALLED_ONCE", pasta::CalledOnceAttrSpelling::kGNUCalledOnce)
    .value("CXX11_CLANG_CALLED_ONCE", pasta::CalledOnceAttrSpelling::kCXX11ClangCalledOnce)
    .value("C2X_CLANG_CALLED_ONCE", pasta::CalledOnceAttrSpelling::kC2xClangCalledOnce)
    .value("SPELLING_NOT_CALCULATED", pasta::CalledOnceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CapabilityAttrSpelling>(m, "CapabilityAttrSpelling")
    .value("GNU_CAPABILITY", pasta::CapabilityAttrSpelling::kGNUCapability)
    .value("CXX11_CLANG_CAPABILITY", pasta::CapabilityAttrSpelling::kCXX11ClangCapability)
    .value("GNU_SHARED_CAPABILITY", pasta::CapabilityAttrSpelling::kGNUSharedCapability)
    .value("CXX11_CLANG_SHARED_CAPABILITY", pasta::CapabilityAttrSpelling::kCXX11ClangSharedCapability)
    .value("SPELLING_NOT_CALCULATED", pasta::CapabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CapturedStmtVariableCaptureKind>(m, "CapturedStmtVariableCaptureKind")
    .value("THIS", pasta::CapturedStmtVariableCaptureKind::kThis)
    .value("BY_REFERENCE", pasta::CapturedStmtVariableCaptureKind::kByReference)
    .value("BY_COPY", pasta::CapturedStmtVariableCaptureKind::kByCopy)
    .value("VLA_TYPE", pasta::CapturedStmtVariableCaptureKind::kVLAType);

  nb::enum_<pasta::CarriesDependencyAttrSpelling>(m, "CarriesDependencyAttrSpelling")
    .value("GNU_CARRIES_DEPENDENCY", pasta::CarriesDependencyAttrSpelling::kGNUCarriesDependency)
    .value("CXX11_CARRIES_DEPENDENCY", pasta::CarriesDependencyAttrSpelling::kCXX11CarriesDependency)
    .value("SPELLING_NOT_CALCULATED", pasta::CarriesDependencyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CharacterLiteralCharacterKind>(m, "CharacterLiteralCharacterKind")
    .value("ASCII", pasta::CharacterLiteralCharacterKind::kAscii)
    .value("WIDE", pasta::CharacterLiteralCharacterKind::kWide)
    .value("UTF8", pasta::CharacterLiteralCharacterKind::kUTF8)
    .value("UTF16", pasta::CharacterLiteralCharacterKind::kUTF16)
    .value("UTF32", pasta::CharacterLiteralCharacterKind::kUTF32);

  nb::enum_<pasta::CleanupAttrSpelling>(m, "CleanupAttrSpelling")
    .value("GNU_CLEANUP", pasta::CleanupAttrSpelling::kGNUCleanup)
    .value("CXX11_GNU_CLEANUP", pasta::CleanupAttrSpelling::kCXX11GnuCleanup)
    .value("C2X_GNU_CLEANUP", pasta::CleanupAttrSpelling::kC2xGnuCleanup)
    .value("SPELLING_NOT_CALCULATED", pasta::CleanupAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ColdAttrSpelling>(m, "ColdAttrSpelling")
    .value("GNU_COLD", pasta::ColdAttrSpelling::kGNUCold)
    .value("CXX11_GNU_COLD", pasta::ColdAttrSpelling::kCXX11GnuCold)
    .value("C2X_GNU_COLD", pasta::ColdAttrSpelling::kC2xGnuCold)
    .value("SPELLING_NOT_CALCULATED", pasta::ColdAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::CommonAttrSpelling>(m, "CommonAttrSpelling")
    .value("GNU_COMMON", pasta::CommonAttrSpelling::kGNUCommon)
    .value("CXX11_GNU_COMMON", pasta::CommonAttrSpelling::kCXX11GnuCommon)
    .value("C2X_GNU_COMMON", pasta::CommonAttrSpelling::kC2xGnuCommon)
    .value("SPELLING_NOT_CALCULATED", pasta::CommonAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConstAttrSpelling>(m, "ConstAttrSpelling")
    .value("GNU_CONST", pasta::ConstAttrSpelling::kGNUConst)
    .value("CXX11_GNU_CONST", pasta::ConstAttrSpelling::kCXX11GnuConst)
    .value("C2X_GNU_CONST", pasta::ConstAttrSpelling::kC2xGnuConst)
    .value("SPELLING_NOT_CALCULATED", pasta::ConstAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConstInitAttrSpelling>(m, "ConstInitAttrSpelling")
    .value("KEYWORD_CONSTINIT", pasta::ConstInitAttrSpelling::kKeywordConstinit)
    .value("GNU_REQUIRE_CONSTANT_INITIALIZATION", pasta::ConstInitAttrSpelling::kGNURequireConstantInitialization)
    .value("CXX11_CLANG_REQUIRE_CONSTANT_INITIALIZATION", pasta::ConstInitAttrSpelling::kCXX11ClangRequireConstantInitialization)
    .value("SPELLING_NOT_CALCULATED", pasta::ConstInitAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConstantExprResultStorageKind>(m, "ConstantExprResultStorageKind")
    .value("NONE", pasta::ConstantExprResultStorageKind::kNone)
    .value("INT64", pasta::ConstantExprResultStorageKind::kInt64)
    .value("AP_VALUE", pasta::ConstantExprResultStorageKind::kAPValue);

  nb::enum_<pasta::ConstructorAttrSpelling>(m, "ConstructorAttrSpelling")
    .value("GNU_CONSTRUCTOR", pasta::ConstructorAttrSpelling::kGNUConstructor)
    .value("CXX11_GNU_CONSTRUCTOR", pasta::ConstructorAttrSpelling::kCXX11GnuConstructor)
    .value("C2X_GNU_CONSTRUCTOR", pasta::ConstructorAttrSpelling::kC2xGnuConstructor)
    .value("SPELLING_NOT_CALCULATED", pasta::ConstructorAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConsumableAttrConsumedState>(m, "ConsumableAttrConsumedState")
    .value("UNKNOWN", pasta::ConsumableAttrConsumedState::kUnknown)
    .value("CONSUMED", pasta::ConsumableAttrConsumedState::kConsumed)
    .value("UNCONSUMED", pasta::ConsumableAttrConsumedState::kUnconsumed);

  nb::enum_<pasta::ConsumableAttrSpelling>(m, "ConsumableAttrSpelling")
    .value("GNU_CONSUMABLE", pasta::ConsumableAttrSpelling::kGNUConsumable)
    .value("CXX11_CLANG_CONSUMABLE", pasta::ConsumableAttrSpelling::kCXX11ClangConsumable)
    .value("SPELLING_NOT_CALCULATED", pasta::ConsumableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConsumableAutoCastAttrSpelling>(m, "ConsumableAutoCastAttrSpelling")
    .value("GNU_CONSUMABLE_AUTO_CAST_STATE", pasta::ConsumableAutoCastAttrSpelling::kGNUConsumableAutoCastState)
    .value("CXX11_CLANG_CONSUMABLE_AUTO_CAST_STATE", pasta::ConsumableAutoCastAttrSpelling::kCXX11ClangConsumableAutoCastState)
    .value("SPELLING_NOT_CALCULATED", pasta::ConsumableAutoCastAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConsumableSetOnReadAttrSpelling>(m, "ConsumableSetOnReadAttrSpelling")
    .value("GNU_CONSUMABLE_STATE_ON_READ", pasta::ConsumableSetOnReadAttrSpelling::kGNUConsumableStateOnRead)
    .value("CXX11_CLANG_CONSUMABLE_STATE_ON_READ", pasta::ConsumableSetOnReadAttrSpelling::kCXX11ClangConsumableStateOnRead)
    .value("SPELLING_NOT_CALCULATED", pasta::ConsumableSetOnReadAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ConvergentAttrSpelling>(m, "ConvergentAttrSpelling")
    .value("GNU_CONVERGENT", pasta::ConvergentAttrSpelling::kGNUConvergent)
    .value("CXX11_CLANG_CONVERGENT", pasta::ConvergentAttrSpelling::kCXX11ClangConvergent)
    .value("C2X_CLANG_CONVERGENT", pasta::ConvergentAttrSpelling::kC2xClangConvergent)
    .value("SPELLING_NOT_CALCULATED", pasta::ConvergentAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DLLExportAttrSpelling>(m, "DLLExportAttrSpelling")
    .value("DECLSPEC_DLLEXPORT", pasta::DLLExportAttrSpelling::kDeclspecDllexport)
    .value("GNU_DLLEXPORT", pasta::DLLExportAttrSpelling::kGNUDllexport)
    .value("CXX11_GNU_DLLEXPORT", pasta::DLLExportAttrSpelling::kCXX11GnuDllexport)
    .value("C2X_GNU_DLLEXPORT", pasta::DLLExportAttrSpelling::kC2xGnuDllexport)
    .value("SPELLING_NOT_CALCULATED", pasta::DLLExportAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DLLImportAttrSpelling>(m, "DLLImportAttrSpelling")
    .value("DECLSPEC_DLLIMPORT", pasta::DLLImportAttrSpelling::kDeclspecDllimport)
    .value("GNU_DLLIMPORT", pasta::DLLImportAttrSpelling::kGNUDllimport)
    .value("CXX11_GNU_DLLIMPORT", pasta::DLLImportAttrSpelling::kCXX11GnuDllimport)
    .value("C2X_GNU_DLLIMPORT", pasta::DLLImportAttrSpelling::kC2xGnuDllimport)
    .value("SPELLING_NOT_CALCULATED", pasta::DLLImportAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DeclFriendObjectKind>(m, "DeclFriendObjectKind")
    .value("NONE", pasta::DeclFriendObjectKind::kNone)
    .value("DECLARED", pasta::DeclFriendObjectKind::kDeclared)
    .value("UNDECLARED", pasta::DeclFriendObjectKind::kUndeclared);

  nb::enum_<pasta::DeclIdentifierNamespace>(m, "DeclIdentifierNamespace")
    .value("LABEL", pasta::DeclIdentifierNamespace::kLabel)
    .value("TAG", pasta::DeclIdentifierNamespace::kTag)
    .value("TYPE", pasta::DeclIdentifierNamespace::kType)
    .value("MEMBER", pasta::DeclIdentifierNamespace::kMember)
    .value("NAMESPACE", pasta::DeclIdentifierNamespace::kNamespace)
    .value("ORDINARY", pasta::DeclIdentifierNamespace::kOrdinary)
    .value("OBJ_C_PROTOCOL", pasta::DeclIdentifierNamespace::kObjCProtocol)
    .value("ORDINARY_FRIEND", pasta::DeclIdentifierNamespace::kOrdinaryFriend)
    .value("TAG_FRIEND", pasta::DeclIdentifierNamespace::kTagFriend)
    .value("USING", pasta::DeclIdentifierNamespace::kUsing)
    .value("NON_MEMBER_OPERATOR", pasta::DeclIdentifierNamespace::kNonMemberOperator)
    .value("LOCAL_EXTERN", pasta::DeclIdentifierNamespace::kLocalExtern)
    .value("OMP_REDUCTION", pasta::DeclIdentifierNamespace::kOMPReduction)
    .value("OMP_MAPPER", pasta::DeclIdentifierNamespace::kOMPMapper);

  nb::enum_<pasta::DeclModuleOwnershipKind>(m, "DeclModuleOwnershipKind")
    .value("UNOWNED", pasta::DeclModuleOwnershipKind::kUnowned)
    .value("VISIBLE", pasta::DeclModuleOwnershipKind::kVisible)
    .value("VISIBLE_WHEN_IMPORTED", pasta::DeclModuleOwnershipKind::kVisibleWhenImported)
    .value("REACHABLE_WHEN_IMPORTED", pasta::DeclModuleOwnershipKind::kReachableWhenImported)
    .value("MODULE_PRIVATE", pasta::DeclModuleOwnershipKind::kModulePrivate);

  nb::enum_<pasta::DeclObjCDeclQualifier>(m, "DeclObjCDeclQualifier")
    .value("NONE", pasta::DeclObjCDeclQualifier::kNone)
    .value("IN", pasta::DeclObjCDeclQualifier::kIn)
    .value("INOUT", pasta::DeclObjCDeclQualifier::kInout)
    .value("OUT", pasta::DeclObjCDeclQualifier::kOut)
    .value("BYCOPY", pasta::DeclObjCDeclQualifier::kBycopy)
    .value("BYREF", pasta::DeclObjCDeclQualifier::kByref)
    .value("ONEWAY", pasta::DeclObjCDeclQualifier::kOneway)
    .value("CS_NULLABILITY", pasta::DeclObjCDeclQualifier::kCSNullability);

  nb::enum_<pasta::DeprecatedAttrSpelling>(m, "DeprecatedAttrSpelling")
    .value("GNU_DEPRECATED", pasta::DeprecatedAttrSpelling::kGNUDeprecated)
    .value("CXX11_GNU_DEPRECATED", pasta::DeprecatedAttrSpelling::kCXX11GnuDeprecated)
    .value("C2X_GNU_DEPRECATED", pasta::DeprecatedAttrSpelling::kC2xGnuDeprecated)
    .value("DECLSPEC_DEPRECATED", pasta::DeprecatedAttrSpelling::kDeclspecDeprecated)
    .value("CXX11_DEPRECATED", pasta::DeprecatedAttrSpelling::kCXX11Deprecated)
    .value("C2X_DEPRECATED", pasta::DeprecatedAttrSpelling::kC2xDeprecated)
    .value("SPELLING_NOT_CALCULATED", pasta::DeprecatedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DestructorAttrSpelling>(m, "DestructorAttrSpelling")
    .value("GNU_DESTRUCTOR", pasta::DestructorAttrSpelling::kGNUDestructor)
    .value("CXX11_GNU_DESTRUCTOR", pasta::DestructorAttrSpelling::kCXX11GnuDestructor)
    .value("C2X_GNU_DESTRUCTOR", pasta::DestructorAttrSpelling::kC2xGnuDestructor)
    .value("SPELLING_NOT_CALCULATED", pasta::DestructorAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DiagnoseAsBuiltinAttrSpelling>(m, "DiagnoseAsBuiltinAttrSpelling")
    .value("GNU_DIAGNOSE_AS_BUILTIN", pasta::DiagnoseAsBuiltinAttrSpelling::kGNUDiagnoseAsBuiltin)
    .value("CXX11_CLANG_DIAGNOSE_AS_BUILTIN", pasta::DiagnoseAsBuiltinAttrSpelling::kCXX11ClangDiagnoseAsBuiltin)
    .value("C2X_CLANG_DIAGNOSE_AS_BUILTIN", pasta::DiagnoseAsBuiltinAttrSpelling::kC2xClangDiagnoseAsBuiltin)
    .value("SPELLING_NOT_CALCULATED", pasta::DiagnoseAsBuiltinAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DiagnoseIfAttrDiagnosticType>(m, "DiagnoseIfAttrDiagnosticType")
    .value("ERROR", pasta::DiagnoseIfAttrDiagnosticType::kError)
    .value("WARNING", pasta::DiagnoseIfAttrDiagnosticType::kWarning);

  nb::enum_<pasta::DisableSanitizerInstrumentationAttrSpelling>(m, "DisableSanitizerInstrumentationAttrSpelling")
    .value("GNU_DISABLE_SANITIZER_INSTRUMENTATION", pasta::DisableSanitizerInstrumentationAttrSpelling::kGNUDisableSanitizerInstrumentation)
    .value("CXX11_CLANG_DISABLE_SANITIZER_INSTRUMENTATION", pasta::DisableSanitizerInstrumentationAttrSpelling::kCXX11ClangDisableSanitizerInstrumentation)
    .value("C2X_CLANG_DISABLE_SANITIZER_INSTRUMENTATION", pasta::DisableSanitizerInstrumentationAttrSpelling::kC2xClangDisableSanitizerInstrumentation)
    .value("SPELLING_NOT_CALCULATED", pasta::DisableSanitizerInstrumentationAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::DisableTailCallsAttrSpelling>(m, "DisableTailCallsAttrSpelling")
    .value("GNU_DISABLE_TAIL_CALLS", pasta::DisableTailCallsAttrSpelling::kGNUDisableTailCalls)
    .value("CXX11_CLANG_DISABLE_TAIL_CALLS", pasta::DisableTailCallsAttrSpelling::kCXX11ClangDisableTailCalls)
    .value("C2X_CLANG_DISABLE_TAIL_CALLS", pasta::DisableTailCallsAttrSpelling::kC2xClangDisableTailCalls)
    .value("SPELLING_NOT_CALCULATED", pasta::DisableTailCallsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::EnforceTCBAttrSpelling>(m, "EnforceTCBAttrSpelling")
    .value("GNU_ENFORCE_TCB", pasta::EnforceTCBAttrSpelling::kGNUEnforceTcb)
    .value("CXX11_CLANG_ENFORCE_TCB", pasta::EnforceTCBAttrSpelling::kCXX11ClangEnforceTcb)
    .value("C2X_CLANG_ENFORCE_TCB", pasta::EnforceTCBAttrSpelling::kC2xClangEnforceTcb)
    .value("SPELLING_NOT_CALCULATED", pasta::EnforceTCBAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::EnforceTCBLeafAttrSpelling>(m, "EnforceTCBLeafAttrSpelling")
    .value("GNU_ENFORCE_TCB_LEAF", pasta::EnforceTCBLeafAttrSpelling::kGNUEnforceTcbLeaf)
    .value("CXX11_CLANG_ENFORCE_TCB_LEAF", pasta::EnforceTCBLeafAttrSpelling::kCXX11ClangEnforceTcbLeaf)
    .value("C2X_CLANG_ENFORCE_TCB_LEAF", pasta::EnforceTCBLeafAttrSpelling::kC2xClangEnforceTcbLeaf)
    .value("SPELLING_NOT_CALCULATED", pasta::EnforceTCBLeafAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::EnumExtensibilityAttrKind>(m, "EnumExtensibilityAttrKind")
    .value("CLOSED", pasta::EnumExtensibilityAttrKind::kClosed)
    .value("OPEN", pasta::EnumExtensibilityAttrKind::kOpen);

  nb::enum_<pasta::EnumExtensibilityAttrSpelling>(m, "EnumExtensibilityAttrSpelling")
    .value("GNU_ENUM_EXTENSIBILITY", pasta::EnumExtensibilityAttrSpelling::kGNUEnumExtensibility)
    .value("CXX11_CLANG_ENUM_EXTENSIBILITY", pasta::EnumExtensibilityAttrSpelling::kCXX11ClangEnumExtensibility)
    .value("C2X_CLANG_ENUM_EXTENSIBILITY", pasta::EnumExtensibilityAttrSpelling::kC2xClangEnumExtensibility)
    .value("SPELLING_NOT_CALCULATED", pasta::EnumExtensibilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ErrorAttrSpelling>(m, "ErrorAttrSpelling")
    .value("GNU_ERROR", pasta::ErrorAttrSpelling::kGNUError)
    .value("CXX11_GNU_ERROR", pasta::ErrorAttrSpelling::kCXX11GnuError)
    .value("C2X_GNU_ERROR", pasta::ErrorAttrSpelling::kC2xGnuError)
    .value("GNU_WARNING", pasta::ErrorAttrSpelling::kGNUWarning)
    .value("CXX11_GNU_WARNING", pasta::ErrorAttrSpelling::kCXX11GnuWarning)
    .value("C2X_GNU_WARNING", pasta::ErrorAttrSpelling::kC2xGnuWarning)
    .value("SPELLING_NOT_CALCULATED", pasta::ErrorAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ExcludeFromExplicitInstantiationAttrSpelling>(m, "ExcludeFromExplicitInstantiationAttrSpelling")
    .value("GNU_EXCLUDE_FROM_EXPLICIT_INSTANTIATION", pasta::ExcludeFromExplicitInstantiationAttrSpelling::kGNUExcludeFromExplicitInstantiation)
    .value("CXX11_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION", pasta::ExcludeFromExplicitInstantiationAttrSpelling::kCXX11ClangExcludeFromExplicitInstantiation)
    .value("C2X_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION", pasta::ExcludeFromExplicitInstantiationAttrSpelling::kC2xClangExcludeFromExplicitInstantiation)
    .value("SPELLING_NOT_CALCULATED", pasta::ExcludeFromExplicitInstantiationAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ExprConstantExprKind>(m, "ExprConstantExprKind")
    .value("NORMAL", pasta::ExprConstantExprKind::kNormal)
    .value("NON_CLASS_TEMPLATE_ARGUMENT", pasta::ExprConstantExprKind::kNonClassTemplateArgument)
    .value("CLASS_TEMPLATE_ARGUMENT", pasta::ExprConstantExprKind::kClassTemplateArgument)
    .value("IMMEDIATE_INVOCATION", pasta::ExprConstantExprKind::kImmediateInvocation);

  nb::enum_<pasta::ExprLValueClassification>(m, "ExprLValueClassification")
    .value("VALID", pasta::ExprLValueClassification::kValid)
    .value("NOT_OBJECT_TYPE", pasta::ExprLValueClassification::kNotObjectType)
    .value("INCOMPLETE_VOID_TYPE", pasta::ExprLValueClassification::kIncompleteVoidType)
    .value("DUPLICATE_VECTOR_COMPONENTS", pasta::ExprLValueClassification::kDuplicateVectorComponents)
    .value("INVALID_EXPRESSION", pasta::ExprLValueClassification::kInvalidExpression)
    .value("INVALID_MESSAGE_EXPRESSION", pasta::ExprLValueClassification::kInvalidMessageExpression)
    .value("MEMBER_FUNCTION", pasta::ExprLValueClassification::kMemberFunction)
    .value("SUB_OBJ_C_PROPERTY_SETTING", pasta::ExprLValueClassification::kSubObjCPropertySetting)
    .value("CLASS_TEMPORARY", pasta::ExprLValueClassification::kClassTemporary)
    .value("ARRAY_TEMPORARY", pasta::ExprLValueClassification::kArrayTemporary);

  nb::enum_<pasta::ExprNullPointerConstantKind>(m, "ExprNullPointerConstantKind")
    .value("NOT_NULL", pasta::ExprNullPointerConstantKind::kNotNull)
    .value("ZERO_EXPRESSION", pasta::ExprNullPointerConstantKind::kZeroExpression)
    .value("ZERO_LITERAL", pasta::ExprNullPointerConstantKind::kZeroLiteral)
    .value("CXX11_NULLPTR", pasta::ExprNullPointerConstantKind::kCXX11Nullptr)
    .value("GNU_NULL", pasta::ExprNullPointerConstantKind::kGNUNull);

  nb::enum_<pasta::ExprNullPointerConstantValueDependence>(m, "ExprNullPointerConstantValueDependence")
    .value("NEVER_VALUE_DEPENDENT", pasta::ExprNullPointerConstantValueDependence::kNeverValueDependent)
    .value("VALUE_DEPENDENT_IS_NULL", pasta::ExprNullPointerConstantValueDependence::kValueDependentIsNull)
    .value("VALUE_DEPENDENT_IS_NOT_NULL", pasta::ExprNullPointerConstantValueDependence::kValueDependentIsNotNull);

  nb::enum_<pasta::ExprSideEffectsKind>(m, "ExprSideEffectsKind")
    .value("NO_SIDE_EFFECTS", pasta::ExprSideEffectsKind::kNoSideEffects)
    .value("ALLOW_UNDEFINED_BEHAVIOR", pasta::ExprSideEffectsKind::kAllowUndefinedBehavior)
    .value("ALLOW_SIDE_EFFECTS", pasta::ExprSideEffectsKind::kAllowSideEffects);

  nb::enum_<pasta::ExprisModifiableLvalueResult>(m, "ExprisModifiableLvalueResult")
    .value("VALID", pasta::ExprisModifiableLvalueResult::kValid)
    .value("NOT_OBJECT_TYPE", pasta::ExprisModifiableLvalueResult::kNotObjectType)
    .value("INCOMPLETE_VOID_TYPE", pasta::ExprisModifiableLvalueResult::kIncompleteVoidType)
    .value("DUPLICATE_VECTOR_COMPONENTS", pasta::ExprisModifiableLvalueResult::kDuplicateVectorComponents)
    .value("INVALID_EXPRESSION", pasta::ExprisModifiableLvalueResult::kInvalidExpression)
    .value("L_VALUE_CAST", pasta::ExprisModifiableLvalueResult::kLValueCast)
    .value("INCOMPLETE_TYPE", pasta::ExprisModifiableLvalueResult::kIncompleteType)
    .value("CONST_QUALIFIED", pasta::ExprisModifiableLvalueResult::kConstQualified)
    .value("CONST_QUALIFIED_FIELD", pasta::ExprisModifiableLvalueResult::kConstQualifiedField)
    .value("CONST_ADDRESS_SPACE", pasta::ExprisModifiableLvalueResult::kConstAddressSpace)
    .value("ARRAY_TYPE", pasta::ExprisModifiableLvalueResult::kArrayType)
    .value("NO_SETTER_PROPERTY", pasta::ExprisModifiableLvalueResult::kNoSetterProperty)
    .value("MEMBER_FUNCTION", pasta::ExprisModifiableLvalueResult::kMemberFunction)
    .value("SUB_OBJ_C_PROPERTY_SETTING", pasta::ExprisModifiableLvalueResult::kSubObjCPropertySetting)
    .value("INVALID_MESSAGE_EXPRESSION", pasta::ExprisModifiableLvalueResult::kInvalidMessageExpression)
    .value("CLASS_TEMPORARY", pasta::ExprisModifiableLvalueResult::kClassTemporary)
    .value("ARRAY_TEMPORARY", pasta::ExprisModifiableLvalueResult::kArrayTemporary);

  nb::enum_<pasta::ExternalSourceSymbolAttrSpelling>(m, "ExternalSourceSymbolAttrSpelling")
    .value("GNU_EXTERNAL_SOURCE_SYMBOL", pasta::ExternalSourceSymbolAttrSpelling::kGNUExternalSourceSymbol)
    .value("CXX11_CLANG_EXTERNAL_SOURCE_SYMBOL", pasta::ExternalSourceSymbolAttrSpelling::kCXX11ClangExternalSourceSymbol)
    .value("C2X_CLANG_EXTERNAL_SOURCE_SYMBOL", pasta::ExternalSourceSymbolAttrSpelling::kC2xClangExternalSourceSymbol)
    .value("SPELLING_NOT_CALCULATED", pasta::ExternalSourceSymbolAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FallThroughAttrSpelling>(m, "FallThroughAttrSpelling")
    .value("CXX11_FALLTHROUGH", pasta::FallThroughAttrSpelling::kCXX11Fallthrough)
    .value("C2X_FALLTHROUGH", pasta::FallThroughAttrSpelling::kC2xFallthrough)
    .value("CXX11_CLANG_FALLTHROUGH", pasta::FallThroughAttrSpelling::kCXX11ClangFallthrough)
    .value("GNU_FALLTHROUGH", pasta::FallThroughAttrSpelling::kGNUFallthrough)
    .value("CXX11_GNU_FALLTHROUGH", pasta::FallThroughAttrSpelling::kCXX11GnuFallthrough)
    .value("C2X_GNU_FALLTHROUGH", pasta::FallThroughAttrSpelling::kC2xGnuFallthrough)
    .value("SPELLING_NOT_CALCULATED", pasta::FallThroughAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FastCallAttrSpelling>(m, "FastCallAttrSpelling")
    .value("GNU_FASTCALL", pasta::FastCallAttrSpelling::kGNUFastcall)
    .value("CXX11_GNU_FASTCALL", pasta::FastCallAttrSpelling::kCXX11GnuFastcall)
    .value("C2X_GNU_FASTCALL", pasta::FastCallAttrSpelling::kC2xGnuFastcall)
    .value("KEYWORD_FASTCALL", pasta::FastCallAttrSpelling::kKeywordFastcall)
    .value("SPELLING_NOT_CALCULATED", pasta::FastCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FinalAttrSpelling>(m, "FinalAttrSpelling")
    .value("KEYWORD_FINAL", pasta::FinalAttrSpelling::kKeywordFinal)
    .value("KEYWORD_SEALED", pasta::FinalAttrSpelling::kKeywordSealed)
    .value("SPELLING_NOT_CALCULATED", pasta::FinalAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FlagEnumAttrSpelling>(m, "FlagEnumAttrSpelling")
    .value("GNU_FLAG_ENUM", pasta::FlagEnumAttrSpelling::kGNUFlagEnum)
    .value("CXX11_CLANG_FLAG_ENUM", pasta::FlagEnumAttrSpelling::kCXX11ClangFlagEnum)
    .value("C2X_CLANG_FLAG_ENUM", pasta::FlagEnumAttrSpelling::kC2xClangFlagEnum)
    .value("SPELLING_NOT_CALCULATED", pasta::FlagEnumAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FlattenAttrSpelling>(m, "FlattenAttrSpelling")
    .value("GNU_FLATTEN", pasta::FlattenAttrSpelling::kGNUFlatten)
    .value("CXX11_GNU_FLATTEN", pasta::FlattenAttrSpelling::kCXX11GnuFlatten)
    .value("C2X_GNU_FLATTEN", pasta::FlattenAttrSpelling::kC2xGnuFlatten)
    .value("SPELLING_NOT_CALCULATED", pasta::FlattenAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FormatArgAttrSpelling>(m, "FormatArgAttrSpelling")
    .value("GNU_FORMAT_ARGUMENT", pasta::FormatArgAttrSpelling::kGNUFormatArgument)
    .value("CXX11_GNU_FORMAT_ARGUMENT", pasta::FormatArgAttrSpelling::kCXX11GnuFormatArgument)
    .value("C2X_GNU_FORMAT_ARGUMENT", pasta::FormatArgAttrSpelling::kC2xGnuFormatArgument)
    .value("SPELLING_NOT_CALCULATED", pasta::FormatArgAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FormatAttrSpelling>(m, "FormatAttrSpelling")
    .value("GNU_FORMAT", pasta::FormatAttrSpelling::kGNUFormat)
    .value("CXX11_GNU_FORMAT", pasta::FormatAttrSpelling::kCXX11GnuFormat)
    .value("C2X_GNU_FORMAT", pasta::FormatAttrSpelling::kC2xGnuFormat)
    .value("SPELLING_NOT_CALCULATED", pasta::FormatAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::FunctionDeclTemplatedKind>(m, "FunctionDeclTemplatedKind")
    .value("NON_TEMPLATE", pasta::FunctionDeclTemplatedKind::kNonTemplate)
    .value("FUNCTION_TEMPLATE", pasta::FunctionDeclTemplatedKind::kFunctionTemplate)
    .value("MEMBER_SPECIALIZATION", pasta::FunctionDeclTemplatedKind::kMemberSpecialization)
    .value("FUNCTION_TEMPLATE_SPECIALIZATION", pasta::FunctionDeclTemplatedKind::kFunctionTemplateSpecialization)
    .value("DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION", pasta::FunctionDeclTemplatedKind::kDependentFunctionTemplateSpecialization)
    .value("DEPENDENT_NON_TEMPLATE", pasta::FunctionDeclTemplatedKind::kDependentNonTemplate);

  nb::enum_<pasta::FunctionReturnThunksAttrKind>(m, "FunctionReturnThunksAttrKind")
    .value("KEEP", pasta::FunctionReturnThunksAttrKind::kKeep)
    .value("EXTERN", pasta::FunctionReturnThunksAttrKind::kExtern);

  nb::enum_<pasta::FunctionReturnThunksAttrSpelling>(m, "FunctionReturnThunksAttrSpelling")
    .value("GNU_FUNCTION_RETURN", pasta::FunctionReturnThunksAttrSpelling::kGNUFunctionReturn)
    .value("CXX11_GNU_FUNCTION_RETURN", pasta::FunctionReturnThunksAttrSpelling::kCXX11GnuFunctionReturn)
    .value("C2X_GNU_FUNCTION_RETURN", pasta::FunctionReturnThunksAttrSpelling::kC2xGnuFunctionReturn)
    .value("SPELLING_NOT_CALCULATED", pasta::FunctionReturnThunksAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::GNUInlineAttrSpelling>(m, "GNUInlineAttrSpelling")
    .value("GNU_GNU_INLINE", pasta::GNUInlineAttrSpelling::kGNUGnuInline)
    .value("CXX11_GNU_GNU_INLINE", pasta::GNUInlineAttrSpelling::kCXX11GnuGnuInline)
    .value("C2X_GNU_GNU_INLINE", pasta::GNUInlineAttrSpelling::kC2xGnuGnuInline)
    .value("SPELLING_NOT_CALCULATED", pasta::GNUInlineAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::GuardedVarAttrSpelling>(m, "GuardedVarAttrSpelling")
    .value("GNU_GUARDED_VARIABLE", pasta::GuardedVarAttrSpelling::kGNUGuardedVariable)
    .value("CXX11_CLANG_GUARDED_VARIABLE", pasta::GuardedVarAttrSpelling::kCXX11ClangGuardedVariable)
    .value("SPELLING_NOT_CALCULATED", pasta::GuardedVarAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::HIPManagedAttrSpelling>(m, "HIPManagedAttrSpelling")
    .value("GNU_MANAGED", pasta::HIPManagedAttrSpelling::kGNUManaged)
    .value("DECLSPEC_MANAGED", pasta::HIPManagedAttrSpelling::kDeclspecManaged)
    .value("SPELLING_NOT_CALCULATED", pasta::HIPManagedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::HLSLResourceAttrResourceClass>(m, "HLSLResourceAttrResourceClass")
    .value("SRV", pasta::HLSLResourceAttrResourceClass::kSRV)
    .value("UAV", pasta::HLSLResourceAttrResourceClass::kUAV)
    .value("C_BUFFER", pasta::HLSLResourceAttrResourceClass::kCBuffer)
    .value("SAMPLER", pasta::HLSLResourceAttrResourceClass::kSampler);

  nb::enum_<pasta::HLSLResourceAttrResourceKind>(m, "HLSLResourceAttrResourceKind")
    .value("TEXTURE1_D", pasta::HLSLResourceAttrResourceKind::kTexture1D)
    .value("TEXTURE2_D", pasta::HLSLResourceAttrResourceKind::kTexture2D)
    .value("TEXTURE2_DMS", pasta::HLSLResourceAttrResourceKind::kTexture2DMS)
    .value("TEXTURE3_D", pasta::HLSLResourceAttrResourceKind::kTexture3D)
    .value("TEXTURE_CUBE", pasta::HLSLResourceAttrResourceKind::kTextureCube)
    .value("TEXTURE1_D_ARRAY", pasta::HLSLResourceAttrResourceKind::kTexture1DArray)
    .value("TEXTURE2_D_ARRAY", pasta::HLSLResourceAttrResourceKind::kTexture2DArray)
    .value("TEXTURE2_DMS_ARRAY", pasta::HLSLResourceAttrResourceKind::kTexture2DMSArray)
    .value("TEXTURE_CUBE_ARRAY", pasta::HLSLResourceAttrResourceKind::kTextureCubeArray)
    .value("TYPED_BUFFER", pasta::HLSLResourceAttrResourceKind::kTypedBuffer)
    .value("RAW_BUFFER", pasta::HLSLResourceAttrResourceKind::kRawBuffer)
    .value("STRUCTURED_BUFFER", pasta::HLSLResourceAttrResourceKind::kStructuredBuffer)
    .value("C_BUFFER_KIND", pasta::HLSLResourceAttrResourceKind::kCBufferKind)
    .value("SAMPLER_KIND", pasta::HLSLResourceAttrResourceKind::kSamplerKind)
    .value("T_BUFFER", pasta::HLSLResourceAttrResourceKind::kTBuffer)
    .value("RT_ACCELERATION_STRUCTURE", pasta::HLSLResourceAttrResourceKind::kRTAccelerationStructure)
    .value("FEEDBACK_TEXTURE2_D", pasta::HLSLResourceAttrResourceKind::kFeedbackTexture2D)
    .value("FEEDBACK_TEXTURE2_D_ARRAY", pasta::HLSLResourceAttrResourceKind::kFeedbackTexture2DArray);

  nb::enum_<pasta::HLSLShaderAttrShaderType>(m, "HLSLShaderAttrShaderType")
    .value("PIXEL", pasta::HLSLShaderAttrShaderType::kPixel)
    .value("VERTEX", pasta::HLSLShaderAttrShaderType::kVertex)
    .value("GEOMETRY", pasta::HLSLShaderAttrShaderType::kGeometry)
    .value("HULL", pasta::HLSLShaderAttrShaderType::kHull)
    .value("DOMAIN", pasta::HLSLShaderAttrShaderType::kDomain)
    .value("COMPUTE", pasta::HLSLShaderAttrShaderType::kCompute)
    .value("LIBRARY", pasta::HLSLShaderAttrShaderType::kLibrary)
    .value("RAY_GENERATION", pasta::HLSLShaderAttrShaderType::kRayGeneration)
    .value("INTERSECTION", pasta::HLSLShaderAttrShaderType::kIntersection)
    .value("ANY_HIT", pasta::HLSLShaderAttrShaderType::kAnyHit)
    .value("CLOSEST_HIT", pasta::HLSLShaderAttrShaderType::kClosestHit)
    .value("MISS", pasta::HLSLShaderAttrShaderType::kMiss)
    .value("CALLABLE", pasta::HLSLShaderAttrShaderType::kCallable)
    .value("MESH", pasta::HLSLShaderAttrShaderType::kMesh)
    .value("AMPLIFICATION", pasta::HLSLShaderAttrShaderType::kAmplification);

  nb::enum_<pasta::HotAttrSpelling>(m, "HotAttrSpelling")
    .value("GNU_HOT", pasta::HotAttrSpelling::kGNUHot)
    .value("CXX11_GNU_HOT", pasta::HotAttrSpelling::kCXX11GnuHot)
    .value("C2X_GNU_HOT", pasta::HotAttrSpelling::kC2xGnuHot)
    .value("SPELLING_NOT_CALCULATED", pasta::HotAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::IBActionAttrSpelling>(m, "IBActionAttrSpelling")
    .value("GNU_IBACTION", pasta::IBActionAttrSpelling::kGNUIbaction)
    .value("CXX11_CLANG_IBACTION", pasta::IBActionAttrSpelling::kCXX11ClangIbaction)
    .value("C2X_CLANG_IBACTION", pasta::IBActionAttrSpelling::kC2xClangIbaction)
    .value("SPELLING_NOT_CALCULATED", pasta::IBActionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::IBOutletAttrSpelling>(m, "IBOutletAttrSpelling")
    .value("GNU_IBOUTLET", pasta::IBOutletAttrSpelling::kGNUIboutlet)
    .value("CXX11_CLANG_IBOUTLET", pasta::IBOutletAttrSpelling::kCXX11ClangIboutlet)
    .value("C2X_CLANG_IBOUTLET", pasta::IBOutletAttrSpelling::kC2xClangIboutlet)
    .value("SPELLING_NOT_CALCULATED", pasta::IBOutletAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::IBOutletCollectionAttrSpelling>(m, "IBOutletCollectionAttrSpelling")
    .value("GNU_IBOUTLETCOLLECTION", pasta::IBOutletCollectionAttrSpelling::kGNUIboutletcollection)
    .value("CXX11_CLANG_IBOUTLETCOLLECTION", pasta::IBOutletCollectionAttrSpelling::kCXX11ClangIboutletcollection)
    .value("C2X_CLANG_IBOUTLETCOLLECTION", pasta::IBOutletCollectionAttrSpelling::kC2xClangIboutletcollection)
    .value("SPELLING_NOT_CALCULATED", pasta::IBOutletCollectionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::IFuncAttrSpelling>(m, "IFuncAttrSpelling")
    .value("GNU_IFUNC", pasta::IFuncAttrSpelling::kGNUIfunc)
    .value("CXX11_GNU_IFUNC", pasta::IFuncAttrSpelling::kCXX11GnuIfunc)
    .value("C2X_GNU_IFUNC", pasta::IFuncAttrSpelling::kC2xGnuIfunc)
    .value("SPELLING_NOT_CALCULATED", pasta::IFuncAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ImplicitCastExprOnStack>(m, "ImplicitCastExprOnStack")
    .value("ON_STACK", pasta::ImplicitCastExprOnStack::kOnStack);

  nb::enum_<pasta::ImplicitParamDeclImplicitParamKind>(m, "ImplicitParamDeclImplicitParamKind")
    .value("OBJ_C_SELF", pasta::ImplicitParamDeclImplicitParamKind::kObjCSelf)
    .value("OBJ_C_CMD", pasta::ImplicitParamDeclImplicitParamKind::kObjCCmd)
    .value("CXX_THIS", pasta::ImplicitParamDeclImplicitParamKind::kCXXThis)
    .value("CXXVTT", pasta::ImplicitParamDeclImplicitParamKind::kCXXVTT)
    .value("CAPTURED_CONTEXT", pasta::ImplicitParamDeclImplicitParamKind::kCapturedContext)
    .value("THREAD_PRIVATE_VARIABLE", pasta::ImplicitParamDeclImplicitParamKind::kThreadPrivateVariable)
    .value("OTHER", pasta::ImplicitParamDeclImplicitParamKind::kOther);

  nb::enum_<pasta::InitPriorityAttrSpelling>(m, "InitPriorityAttrSpelling")
    .value("GNU_INITIALIZER_PRIORITY", pasta::InitPriorityAttrSpelling::kGNUInitializerPriority)
    .value("CXX11_GNU_INITIALIZER_PRIORITY", pasta::InitPriorityAttrSpelling::kCXX11GnuInitializerPriority)
    .value("SPELLING_NOT_CALCULATED", pasta::InitPriorityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::IntelOclBiccAttrSpelling>(m, "IntelOclBiccAttrSpelling")
    .value("GNU_INTEL_OCL_BICC", pasta::IntelOclBiccAttrSpelling::kGNUIntelOclBicc)
    .value("CXX11_CLANG_INTEL_OCL_BICC", pasta::IntelOclBiccAttrSpelling::kCXX11ClangIntelOclBicc)
    .value("SPELLING_NOT_CALCULATED", pasta::IntelOclBiccAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::InternalLinkageAttrSpelling>(m, "InternalLinkageAttrSpelling")
    .value("GNU_INTERNAL_LINKAGE", pasta::InternalLinkageAttrSpelling::kGNUInternalLinkage)
    .value("CXX11_CLANG_INTERNAL_LINKAGE", pasta::InternalLinkageAttrSpelling::kCXX11ClangInternalLinkage)
    .value("C2X_CLANG_INTERNAL_LINKAGE", pasta::InternalLinkageAttrSpelling::kC2xClangInternalLinkage)
    .value("SPELLING_NOT_CALCULATED", pasta::InternalLinkageAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::LTOVisibilityPublicAttrSpelling>(m, "LTOVisibilityPublicAttrSpelling")
    .value("GNU_LTO_VISIBILITY_PUBLIC", pasta::LTOVisibilityPublicAttrSpelling::kGNULtoVisibilityPublic)
    .value("CXX11_CLANG_LTO_VISIBILITY_PUBLIC", pasta::LTOVisibilityPublicAttrSpelling::kCXX11ClangLtoVisibilityPublic)
    .value("C2X_CLANG_LTO_VISIBILITY_PUBLIC", pasta::LTOVisibilityPublicAttrSpelling::kC2xClangLtoVisibilityPublic)
    .value("SPELLING_NOT_CALCULATED", pasta::LTOVisibilityPublicAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::LeafAttrSpelling>(m, "LeafAttrSpelling")
    .value("GNU_LEAF", pasta::LeafAttrSpelling::kGNULeaf)
    .value("CXX11_GNU_LEAF", pasta::LeafAttrSpelling::kCXX11GnuLeaf)
    .value("C2X_GNU_LEAF", pasta::LeafAttrSpelling::kC2xGnuLeaf)
    .value("SPELLING_NOT_CALCULATED", pasta::LeafAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::LifetimeBoundAttrSpelling>(m, "LifetimeBoundAttrSpelling")
    .value("GNU_LIFETIMEBOUND", pasta::LifetimeBoundAttrSpelling::kGNULifetimebound)
    .value("CXX11_CLANG_LIFETIMEBOUND", pasta::LifetimeBoundAttrSpelling::kCXX11ClangLifetimebound)
    .value("SPELLING_NOT_CALCULATED", pasta::LifetimeBoundAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::LikelyAttrSpelling>(m, "LikelyAttrSpelling")
    .value("CXX11_LIKELY", pasta::LikelyAttrSpelling::kCXX11Likely)
    .value("C2X_CLANG_LIKELY", pasta::LikelyAttrSpelling::kC2xClangLikely)
    .value("SPELLING_NOT_CALCULATED", pasta::LikelyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::LinkageSpecDeclLanguageIDs>(m, "LinkageSpecDeclLanguageIDs")
    .value("C", pasta::LinkageSpecDeclLanguageIDs::kC)
    .value("CXX", pasta::LinkageSpecDeclLanguageIDs::kCxx);

  nb::enum_<pasta::LoaderUninitializedAttrSpelling>(m, "LoaderUninitializedAttrSpelling")
    .value("GNU_LOADER_UNINITIALIZED", pasta::LoaderUninitializedAttrSpelling::kGNULoaderUninitialized)
    .value("CXX11_CLANG_LOADER_UNINITIALIZED", pasta::LoaderUninitializedAttrSpelling::kCXX11ClangLoaderUninitialized)
    .value("C2X_CLANG_LOADER_UNINITIALIZED", pasta::LoaderUninitializedAttrSpelling::kC2xClangLoaderUninitialized)
    .value("SPELLING_NOT_CALCULATED", pasta::LoaderUninitializedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::LoopHintAttrLoopHintState>(m, "LoopHintAttrLoopHintState")
    .value("ENABLE", pasta::LoopHintAttrLoopHintState::kEnable)
    .value("DISABLE", pasta::LoopHintAttrLoopHintState::kDisable)
    .value("NUMERIC", pasta::LoopHintAttrLoopHintState::kNumeric)
    .value("FIXED_WIDTH", pasta::LoopHintAttrLoopHintState::kFixedWidth)
    .value("SCALABLE_WIDTH", pasta::LoopHintAttrLoopHintState::kScalableWidth)
    .value("ASSUME_SAFETY", pasta::LoopHintAttrLoopHintState::kAssumeSafety)
    .value("FULL", pasta::LoopHintAttrLoopHintState::kFull);

  nb::enum_<pasta::LoopHintAttrOptionType>(m, "LoopHintAttrOptionType")
    .value("VECTORIZE", pasta::LoopHintAttrOptionType::kVectorize)
    .value("VECTORIZE_WIDTH", pasta::LoopHintAttrOptionType::kVectorizeWidth)
    .value("INTERLEAVE", pasta::LoopHintAttrOptionType::kInterleave)
    .value("INTERLEAVE_COUNT", pasta::LoopHintAttrOptionType::kInterleaveCount)
    .value("UNROLL", pasta::LoopHintAttrOptionType::kUnroll)
    .value("UNROLL_COUNT", pasta::LoopHintAttrOptionType::kUnrollCount)
    .value("UNROLL_AND_JAM", pasta::LoopHintAttrOptionType::kUnrollAndJam)
    .value("UNROLL_AND_JAM_COUNT", pasta::LoopHintAttrOptionType::kUnrollAndJamCount)
    .value("PIPELINE_DISABLED", pasta::LoopHintAttrOptionType::kPipelineDisabled)
    .value("PIPELINE_INITIATION_INTERVAL", pasta::LoopHintAttrOptionType::kPipelineInitiationInterval)
    .value("DISTRIBUTE", pasta::LoopHintAttrOptionType::kDistribute)
    .value("VECTORIZE_PREDICATE", pasta::LoopHintAttrOptionType::kVectorizePredicate);

  nb::enum_<pasta::LoopHintAttrSpelling>(m, "LoopHintAttrSpelling")
    .value("PRAGMA_CLANG_LOOP", pasta::LoopHintAttrSpelling::kPragmaClangLoop)
    .value("PRAGMA_UNROLL", pasta::LoopHintAttrSpelling::kPragmaUnroll)
    .value("PRAGMA_NOUNROLL", pasta::LoopHintAttrSpelling::kPragmaNounroll)
    .value("PRAGMA_UNROLL_AND_JAM", pasta::LoopHintAttrSpelling::kPragmaUnrollAndJam)
    .value("PRAGMA_NOUNROLL_AND_JAM", pasta::LoopHintAttrSpelling::kPragmaNounrollAndJam)
    .value("SPELLING_NOT_CALCULATED", pasta::LoopHintAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MIGServerRoutineAttrSpelling>(m, "MIGServerRoutineAttrSpelling")
    .value("GNU_MIG_SERVER_ROUTINE", pasta::MIGServerRoutineAttrSpelling::kGNUMigServerRoutine)
    .value("CXX11_CLANG_MIG_SERVER_ROUTINE", pasta::MIGServerRoutineAttrSpelling::kCXX11ClangMigServerRoutine)
    .value("C2X_CLANG_MIG_SERVER_ROUTINE", pasta::MIGServerRoutineAttrSpelling::kC2xClangMigServerRoutine)
    .value("SPELLING_NOT_CALCULATED", pasta::MIGServerRoutineAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MSABIAttrSpelling>(m, "MSABIAttrSpelling")
    .value("GNU_MS_ABI", pasta::MSABIAttrSpelling::kGNUMsAbi)
    .value("CXX11_GNU_MS_ABI", pasta::MSABIAttrSpelling::kCXX11GnuMsAbi)
    .value("C2X_GNU_MS_ABI", pasta::MSABIAttrSpelling::kC2xGnuMsAbi)
    .value("SPELLING_NOT_CALCULATED", pasta::MSABIAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MSInheritanceAttrSpelling>(m, "MSInheritanceAttrSpelling")
    .value("KEYWORD_SINGLE_INHERITANCE", pasta::MSInheritanceAttrSpelling::kKeywordSingleInheritance)
    .value("KEYWORD_MULTIPLE_INHERITANCE", pasta::MSInheritanceAttrSpelling::kKeywordMultipleInheritance)
    .value("KEYWORD_VIRTUAL_INHERITANCE", pasta::MSInheritanceAttrSpelling::kKeywordVirtualInheritance)
    .value("KEYWORD_UNSPECIFIED_INHERITANCE", pasta::MSInheritanceAttrSpelling::kKeywordUnspecifiedInheritance)
    .value("SPELLING_NOT_CALCULATED", pasta::MSInheritanceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MSP430InterruptAttrSpelling>(m, "MSP430InterruptAttrSpelling")
    .value("GNU_INTERRUPT", pasta::MSP430InterruptAttrSpelling::kGNUInterrupt)
    .value("CXX11_GNU_INTERRUPT", pasta::MSP430InterruptAttrSpelling::kCXX11GnuInterrupt)
    .value("C2X_GNU_INTERRUPT", pasta::MSP430InterruptAttrSpelling::kC2xGnuInterrupt)
    .value("SPELLING_NOT_CALCULATED", pasta::MSP430InterruptAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MSStructAttrSpelling>(m, "MSStructAttrSpelling")
    .value("GNU_MS_STRUCT", pasta::MSStructAttrSpelling::kGNUMsStruct)
    .value("CXX11_GNU_MS_STRUCT", pasta::MSStructAttrSpelling::kCXX11GnuMsStruct)
    .value("C2X_GNU_MS_STRUCT", pasta::MSStructAttrSpelling::kC2xGnuMsStruct)
    .value("SPELLING_NOT_CALCULATED", pasta::MSStructAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MayAliasAttrSpelling>(m, "MayAliasAttrSpelling")
    .value("GNU_MAY_ALIAS", pasta::MayAliasAttrSpelling::kGNUMayAlias)
    .value("CXX11_GNU_MAY_ALIAS", pasta::MayAliasAttrSpelling::kCXX11GnuMayAlias)
    .value("C2X_GNU_MAY_ALIAS", pasta::MayAliasAttrSpelling::kC2xGnuMayAlias)
    .value("SPELLING_NOT_CALCULATED", pasta::MayAliasAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MaybeUndefAttrSpelling>(m, "MaybeUndefAttrSpelling")
    .value("GNU_MAYBE_UNDEF", pasta::MaybeUndefAttrSpelling::kGNUMaybeUndef)
    .value("CXX11_CLANG_MAYBE_UNDEF", pasta::MaybeUndefAttrSpelling::kCXX11ClangMaybeUndef)
    .value("C2X_CLANG_MAYBE_UNDEF", pasta::MaybeUndefAttrSpelling::kC2xClangMaybeUndef)
    .value("SPELLING_NOT_CALCULATED", pasta::MaybeUndefAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MicroMipsAttrSpelling>(m, "MicroMipsAttrSpelling")
    .value("GNU_MICROMIPS", pasta::MicroMipsAttrSpelling::kGNUMicromips)
    .value("CXX11_GNU_MICROMIPS", pasta::MicroMipsAttrSpelling::kCXX11GnuMicromips)
    .value("C2X_GNU_MICROMIPS", pasta::MicroMipsAttrSpelling::kC2xGnuMicromips)
    .value("SPELLING_NOT_CALCULATED", pasta::MicroMipsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MinSizeAttrSpelling>(m, "MinSizeAttrSpelling")
    .value("GNU_MINSIZE", pasta::MinSizeAttrSpelling::kGNUMinsize)
    .value("CXX11_CLANG_MINSIZE", pasta::MinSizeAttrSpelling::kCXX11ClangMinsize)
    .value("C2X_CLANG_MINSIZE", pasta::MinSizeAttrSpelling::kC2xClangMinsize)
    .value("SPELLING_NOT_CALCULATED", pasta::MinSizeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MinVectorWidthAttrSpelling>(m, "MinVectorWidthAttrSpelling")
    .value("GNU_MIN_VECTOR_WIDTH", pasta::MinVectorWidthAttrSpelling::kGNUMinVectorWidth)
    .value("CXX11_CLANG_MIN_VECTOR_WIDTH", pasta::MinVectorWidthAttrSpelling::kCXX11ClangMinVectorWidth)
    .value("C2X_CLANG_MIN_VECTOR_WIDTH", pasta::MinVectorWidthAttrSpelling::kC2xClangMinVectorWidth)
    .value("SPELLING_NOT_CALCULATED", pasta::MinVectorWidthAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::Mips16AttrSpelling>(m, "Mips16AttrSpelling")
    .value("GNU_MIPS16", pasta::Mips16AttrSpelling::kGNUMips16)
    .value("CXX11_GNU_MIPS16", pasta::Mips16AttrSpelling::kCXX11GnuMips16)
    .value("C2X_GNU_MIPS16", pasta::Mips16AttrSpelling::kC2xGnuMips16)
    .value("SPELLING_NOT_CALCULATED", pasta::Mips16AttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MipsInterruptAttrInterruptType>(m, "MipsInterruptAttrInterruptType")
    .value("SW0", pasta::MipsInterruptAttrInterruptType::kSw0)
    .value("SW1", pasta::MipsInterruptAttrInterruptType::kSw1)
    .value("HW0", pasta::MipsInterruptAttrInterruptType::kHw0)
    .value("HW1", pasta::MipsInterruptAttrInterruptType::kHw1)
    .value("HW2", pasta::MipsInterruptAttrInterruptType::kHw2)
    .value("HW3", pasta::MipsInterruptAttrInterruptType::kHw3)
    .value("HW4", pasta::MipsInterruptAttrInterruptType::kHw4)
    .value("HW5", pasta::MipsInterruptAttrInterruptType::kHw5)
    .value("EIC", pasta::MipsInterruptAttrInterruptType::kEic);

  nb::enum_<pasta::MipsInterruptAttrSpelling>(m, "MipsInterruptAttrSpelling")
    .value("GNU_INTERRUPT", pasta::MipsInterruptAttrSpelling::kGNUInterrupt)
    .value("CXX11_GNU_INTERRUPT", pasta::MipsInterruptAttrSpelling::kCXX11GnuInterrupt)
    .value("C2X_GNU_INTERRUPT", pasta::MipsInterruptAttrSpelling::kC2xGnuInterrupt)
    .value("SPELLING_NOT_CALCULATED", pasta::MipsInterruptAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MipsLongCallAttrSpelling>(m, "MipsLongCallAttrSpelling")
    .value("GNU_LONG_CALL", pasta::MipsLongCallAttrSpelling::kGNULongCall)
    .value("CXX11_GNU_LONG_CALL", pasta::MipsLongCallAttrSpelling::kCXX11GnuLongCall)
    .value("C2X_GNU_LONG_CALL", pasta::MipsLongCallAttrSpelling::kC2xGnuLongCall)
    .value("GNU_FAR", pasta::MipsLongCallAttrSpelling::kGNUFar)
    .value("CXX11_GNU_FAR", pasta::MipsLongCallAttrSpelling::kCXX11GnuFar)
    .value("C2X_GNU_FAR", pasta::MipsLongCallAttrSpelling::kC2xGnuFar)
    .value("SPELLING_NOT_CALCULATED", pasta::MipsLongCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MipsShortCallAttrSpelling>(m, "MipsShortCallAttrSpelling")
    .value("GNU_SHORT_CALL", pasta::MipsShortCallAttrSpelling::kGNUShortCall)
    .value("CXX11_GNU_SHORT_CALL", pasta::MipsShortCallAttrSpelling::kCXX11GnuShortCall)
    .value("C2X_GNU_SHORT_CALL", pasta::MipsShortCallAttrSpelling::kC2xGnuShortCall)
    .value("GNU_NEAR", pasta::MipsShortCallAttrSpelling::kGNUNear)
    .value("CXX11_GNU_NEAR", pasta::MipsShortCallAttrSpelling::kCXX11GnuNear)
    .value("C2X_GNU_NEAR", pasta::MipsShortCallAttrSpelling::kC2xGnuNear)
    .value("SPELLING_NOT_CALCULATED", pasta::MipsShortCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ModeAttrSpelling>(m, "ModeAttrSpelling")
    .value("GNU_MODE", pasta::ModeAttrSpelling::kGNUMode)
    .value("CXX11_GNU_MODE", pasta::ModeAttrSpelling::kCXX11GnuMode)
    .value("C2X_GNU_MODE", pasta::ModeAttrSpelling::kC2xGnuMode)
    .value("SPELLING_NOT_CALCULATED", pasta::ModeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::MustTailAttrSpelling>(m, "MustTailAttrSpelling")
    .value("GNU_MUSTTAIL", pasta::MustTailAttrSpelling::kGNUMusttail)
    .value("CXX11_CLANG_MUSTTAIL", pasta::MustTailAttrSpelling::kCXX11ClangMusttail)
    .value("C2X_CLANG_MUSTTAIL", pasta::MustTailAttrSpelling::kC2xClangMusttail)
    .value("SPELLING_NOT_CALCULATED", pasta::MustTailAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NSConsumedAttrSpelling>(m, "NSConsumedAttrSpelling")
    .value("GNU_NS_CONSUMED", pasta::NSConsumedAttrSpelling::kGNUNsConsumed)
    .value("CXX11_CLANG_NS_CONSUMED", pasta::NSConsumedAttrSpelling::kCXX11ClangNsConsumed)
    .value("C2X_CLANG_NS_CONSUMED", pasta::NSConsumedAttrSpelling::kC2xClangNsConsumed)
    .value("SPELLING_NOT_CALCULATED", pasta::NSConsumedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NSConsumesSelfAttrSpelling>(m, "NSConsumesSelfAttrSpelling")
    .value("GNU_NS_CONSUMES_SELF", pasta::NSConsumesSelfAttrSpelling::kGNUNsConsumesSelf)
    .value("CXX11_CLANG_NS_CONSUMES_SELF", pasta::NSConsumesSelfAttrSpelling::kCXX11ClangNsConsumesSelf)
    .value("C2X_CLANG_NS_CONSUMES_SELF", pasta::NSConsumesSelfAttrSpelling::kC2xClangNsConsumesSelf)
    .value("SPELLING_NOT_CALCULATED", pasta::NSConsumesSelfAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NSReturnsAutoreleasedAttrSpelling>(m, "NSReturnsAutoreleasedAttrSpelling")
    .value("GNU_NS_RETURNS_AUTORELEASED", pasta::NSReturnsAutoreleasedAttrSpelling::kGNUNsReturnsAutoreleased)
    .value("CXX11_CLANG_NS_RETURNS_AUTORELEASED", pasta::NSReturnsAutoreleasedAttrSpelling::kCXX11ClangNsReturnsAutoreleased)
    .value("C2X_CLANG_NS_RETURNS_AUTORELEASED", pasta::NSReturnsAutoreleasedAttrSpelling::kC2xClangNsReturnsAutoreleased)
    .value("SPELLING_NOT_CALCULATED", pasta::NSReturnsAutoreleasedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NSReturnsNotRetainedAttrSpelling>(m, "NSReturnsNotRetainedAttrSpelling")
    .value("GNU_NS_RETURNS_NOT_RETAINED", pasta::NSReturnsNotRetainedAttrSpelling::kGNUNsReturnsNotRetained)
    .value("CXX11_CLANG_NS_RETURNS_NOT_RETAINED", pasta::NSReturnsNotRetainedAttrSpelling::kCXX11ClangNsReturnsNotRetained)
    .value("C2X_CLANG_NS_RETURNS_NOT_RETAINED", pasta::NSReturnsNotRetainedAttrSpelling::kC2xClangNsReturnsNotRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::NSReturnsNotRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NSReturnsRetainedAttrSpelling>(m, "NSReturnsRetainedAttrSpelling")
    .value("GNU_NS_RETURNS_RETAINED", pasta::NSReturnsRetainedAttrSpelling::kGNUNsReturnsRetained)
    .value("CXX11_CLANG_NS_RETURNS_RETAINED", pasta::NSReturnsRetainedAttrSpelling::kCXX11ClangNsReturnsRetained)
    .value("C2X_CLANG_NS_RETURNS_RETAINED", pasta::NSReturnsRetainedAttrSpelling::kC2xClangNsReturnsRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::NSReturnsRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NakedAttrSpelling>(m, "NakedAttrSpelling")
    .value("GNU_NAKED", pasta::NakedAttrSpelling::kGNUNaked)
    .value("CXX11_GNU_NAKED", pasta::NakedAttrSpelling::kCXX11GnuNaked)
    .value("C2X_GNU_NAKED", pasta::NakedAttrSpelling::kC2xGnuNaked)
    .value("DECLSPEC_NAKED", pasta::NakedAttrSpelling::kDeclspecNaked)
    .value("SPELLING_NOT_CALCULATED", pasta::NakedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NamedDeclExplicitVisibilityKind>(m, "NamedDeclExplicitVisibilityKind")
    .value("VISIBILITY_FOR_TYPE", pasta::NamedDeclExplicitVisibilityKind::kVisibilityForType)
    .value("VISIBILITY_FOR_VALUE", pasta::NamedDeclExplicitVisibilityKind::kVisibilityForValue);

  nb::enum_<pasta::NoBuiltinAttrSpelling>(m, "NoBuiltinAttrSpelling")
    .value("GNU_NO_BUILTIN", pasta::NoBuiltinAttrSpelling::kGNUNoBuiltin)
    .value("CXX11_CLANG_NO_BUILTIN", pasta::NoBuiltinAttrSpelling::kCXX11ClangNoBuiltin)
    .value("C2X_CLANG_NO_BUILTIN", pasta::NoBuiltinAttrSpelling::kC2xClangNoBuiltin)
    .value("SPELLING_NOT_CALCULATED", pasta::NoBuiltinAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoCommonAttrSpelling>(m, "NoCommonAttrSpelling")
    .value("GNU_NOCOMMON", pasta::NoCommonAttrSpelling::kGNUNocommon)
    .value("CXX11_GNU_NOCOMMON", pasta::NoCommonAttrSpelling::kCXX11GnuNocommon)
    .value("C2X_GNU_NOCOMMON", pasta::NoCommonAttrSpelling::kC2xGnuNocommon)
    .value("SPELLING_NOT_CALCULATED", pasta::NoCommonAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoDebugAttrSpelling>(m, "NoDebugAttrSpelling")
    .value("GNU_NODEBUG", pasta::NoDebugAttrSpelling::kGNUNodebug)
    .value("CXX11_GNU_NODEBUG", pasta::NoDebugAttrSpelling::kCXX11GnuNodebug)
    .value("C2X_GNU_NODEBUG", pasta::NoDebugAttrSpelling::kC2xGnuNodebug)
    .value("SPELLING_NOT_CALCULATED", pasta::NoDebugAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoDerefAttrSpelling>(m, "NoDerefAttrSpelling")
    .value("GNU_NODEREF", pasta::NoDerefAttrSpelling::kGNUNoderef)
    .value("CXX11_CLANG_NODEREF", pasta::NoDerefAttrSpelling::kCXX11ClangNoderef)
    .value("C2X_CLANG_NODEREF", pasta::NoDerefAttrSpelling::kC2xClangNoderef)
    .value("SPELLING_NOT_CALCULATED", pasta::NoDerefAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoDestroyAttrSpelling>(m, "NoDestroyAttrSpelling")
    .value("GNU_NO_DESTROY", pasta::NoDestroyAttrSpelling::kGNUNoDestroy)
    .value("CXX11_CLANG_NO_DESTROY", pasta::NoDestroyAttrSpelling::kCXX11ClangNoDestroy)
    .value("SPELLING_NOT_CALCULATED", pasta::NoDestroyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoDuplicateAttrSpelling>(m, "NoDuplicateAttrSpelling")
    .value("GNU_NODUPLICATE", pasta::NoDuplicateAttrSpelling::kGNUNoduplicate)
    .value("CXX11_CLANG_NODUPLICATE", pasta::NoDuplicateAttrSpelling::kCXX11ClangNoduplicate)
    .value("C2X_CLANG_NODUPLICATE", pasta::NoDuplicateAttrSpelling::kC2xClangNoduplicate)
    .value("SPELLING_NOT_CALCULATED", pasta::NoDuplicateAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoEscapeAttrSpelling>(m, "NoEscapeAttrSpelling")
    .value("GNU_NOESCAPE", pasta::NoEscapeAttrSpelling::kGNUNoescape)
    .value("CXX11_CLANG_NOESCAPE", pasta::NoEscapeAttrSpelling::kCXX11ClangNoescape)
    .value("C2X_CLANG_NOESCAPE", pasta::NoEscapeAttrSpelling::kC2xClangNoescape)
    .value("SPELLING_NOT_CALCULATED", pasta::NoEscapeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoInlineAttrSpelling>(m, "NoInlineAttrSpelling")
    .value("KEYWORD_NOINLINE", pasta::NoInlineAttrSpelling::kKeywordNoinline)
    .value("GNU_NOINLINE", pasta::NoInlineAttrSpelling::kGNUNoinline)
    .value("CXX11_GNU_NOINLINE", pasta::NoInlineAttrSpelling::kCXX11GnuNoinline)
    .value("C2X_GNU_NOINLINE", pasta::NoInlineAttrSpelling::kC2xGnuNoinline)
    .value("CXX11_CLANG_NOINLINE", pasta::NoInlineAttrSpelling::kCXX11ClangNoinline)
    .value("C2X_CLANG_NOINLINE", pasta::NoInlineAttrSpelling::kC2xClangNoinline)
    .value("DECLSPEC_NOINLINE", pasta::NoInlineAttrSpelling::kDeclspecNoinline)
    .value("SPELLING_NOT_CALCULATED", pasta::NoInlineAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoInstrumentFunctionAttrSpelling>(m, "NoInstrumentFunctionAttrSpelling")
    .value("GNU_NO_INSTRUMENT_FUNCTION", pasta::NoInstrumentFunctionAttrSpelling::kGNUNoInstrumentFunction)
    .value("CXX11_GNU_NO_INSTRUMENT_FUNCTION", pasta::NoInstrumentFunctionAttrSpelling::kCXX11GnuNoInstrumentFunction)
    .value("C2X_GNU_NO_INSTRUMENT_FUNCTION", pasta::NoInstrumentFunctionAttrSpelling::kC2xGnuNoInstrumentFunction)
    .value("SPELLING_NOT_CALCULATED", pasta::NoInstrumentFunctionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoMergeAttrSpelling>(m, "NoMergeAttrSpelling")
    .value("GNU_NOMERGE", pasta::NoMergeAttrSpelling::kGNUNomerge)
    .value("CXX11_CLANG_NOMERGE", pasta::NoMergeAttrSpelling::kCXX11ClangNomerge)
    .value("C2X_CLANG_NOMERGE", pasta::NoMergeAttrSpelling::kC2xClangNomerge)
    .value("SPELLING_NOT_CALCULATED", pasta::NoMergeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoMicroMipsAttrSpelling>(m, "NoMicroMipsAttrSpelling")
    .value("GNU_NOMICROMIPS", pasta::NoMicroMipsAttrSpelling::kGNUNomicromips)
    .value("CXX11_GNU_NOMICROMIPS", pasta::NoMicroMipsAttrSpelling::kCXX11GnuNomicromips)
    .value("C2X_GNU_NOMICROMIPS", pasta::NoMicroMipsAttrSpelling::kC2xGnuNomicromips)
    .value("SPELLING_NOT_CALCULATED", pasta::NoMicroMipsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoMips16AttrSpelling>(m, "NoMips16AttrSpelling")
    .value("GNU_NOMIPS16", pasta::NoMips16AttrSpelling::kGNUNomips16)
    .value("CXX11_GNU_NOMIPS16", pasta::NoMips16AttrSpelling::kCXX11GnuNomips16)
    .value("C2X_GNU_NOMIPS16", pasta::NoMips16AttrSpelling::kC2xGnuNomips16)
    .value("SPELLING_NOT_CALCULATED", pasta::NoMips16AttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoProfileFunctionAttrSpelling>(m, "NoProfileFunctionAttrSpelling")
    .value("GNU_NO_PROFILE_INSTRUMENT_FUNCTION", pasta::NoProfileFunctionAttrSpelling::kGNUNoProfileInstrumentFunction)
    .value("CXX11_GNU_NO_PROFILE_INSTRUMENT_FUNCTION", pasta::NoProfileFunctionAttrSpelling::kCXX11GnuNoProfileInstrumentFunction)
    .value("C2X_GNU_NO_PROFILE_INSTRUMENT_FUNCTION", pasta::NoProfileFunctionAttrSpelling::kC2xGnuNoProfileInstrumentFunction)
    .value("SPELLING_NOT_CALCULATED", pasta::NoProfileFunctionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoRandomizeLayoutAttrSpelling>(m, "NoRandomizeLayoutAttrSpelling")
    .value("GNU_NO_RANDOMIZE_LAYOUT", pasta::NoRandomizeLayoutAttrSpelling::kGNUNoRandomizeLayout)
    .value("CXX11_GNU_NO_RANDOMIZE_LAYOUT", pasta::NoRandomizeLayoutAttrSpelling::kCXX11GnuNoRandomizeLayout)
    .value("C2X_GNU_NO_RANDOMIZE_LAYOUT", pasta::NoRandomizeLayoutAttrSpelling::kC2xGnuNoRandomizeLayout)
    .value("SPELLING_NOT_CALCULATED", pasta::NoRandomizeLayoutAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoReturnAttrSpelling>(m, "NoReturnAttrSpelling")
    .value("GNU_NORETURN", pasta::NoReturnAttrSpelling::kGNUNoreturn)
    .value("CXX11_GNU_NORETURN", pasta::NoReturnAttrSpelling::kCXX11GnuNoreturn)
    .value("C2X_GNU_NORETURN", pasta::NoReturnAttrSpelling::kC2xGnuNoreturn)
    .value("DECLSPEC_NORETURN", pasta::NoReturnAttrSpelling::kDeclspecNoreturn)
    .value("SPELLING_NOT_CALCULATED", pasta::NoReturnAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoSanitizeAttrSpelling>(m, "NoSanitizeAttrSpelling")
    .value("GNU_NO_SANITIZE", pasta::NoSanitizeAttrSpelling::kGNUNoSanitize)
    .value("CXX11_CLANG_NO_SANITIZE", pasta::NoSanitizeAttrSpelling::kCXX11ClangNoSanitize)
    .value("C2X_CLANG_NO_SANITIZE", pasta::NoSanitizeAttrSpelling::kC2xClangNoSanitize)
    .value("SPELLING_NOT_CALCULATED", pasta::NoSanitizeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoSpeculativeLoadHardeningAttrSpelling>(m, "NoSpeculativeLoadHardeningAttrSpelling")
    .value("GNU_NO_SPECULATIVE_LOAD_HARDENING", pasta::NoSpeculativeLoadHardeningAttrSpelling::kGNUNoSpeculativeLoadHardening)
    .value("CXX11_CLANG_NO_SPECULATIVE_LOAD_HARDENING", pasta::NoSpeculativeLoadHardeningAttrSpelling::kCXX11ClangNoSpeculativeLoadHardening)
    .value("C2X_CLANG_NO_SPECULATIVE_LOAD_HARDENING", pasta::NoSpeculativeLoadHardeningAttrSpelling::kC2xClangNoSpeculativeLoadHardening)
    .value("SPELLING_NOT_CALCULATED", pasta::NoSpeculativeLoadHardeningAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoSplitStackAttrSpelling>(m, "NoSplitStackAttrSpelling")
    .value("GNU_NO_SPLIT_STACK", pasta::NoSplitStackAttrSpelling::kGNUNoSplitStack)
    .value("CXX11_GNU_NO_SPLIT_STACK", pasta::NoSplitStackAttrSpelling::kCXX11GnuNoSplitStack)
    .value("C2X_GNU_NO_SPLIT_STACK", pasta::NoSplitStackAttrSpelling::kC2xGnuNoSplitStack)
    .value("SPELLING_NOT_CALCULATED", pasta::NoSplitStackAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoStackProtectorAttrSpelling>(m, "NoStackProtectorAttrSpelling")
    .value("GNU_NO_STACK_PROTECTOR", pasta::NoStackProtectorAttrSpelling::kGNUNoStackProtector)
    .value("CXX11_CLANG_NO_STACK_PROTECTOR", pasta::NoStackProtectorAttrSpelling::kCXX11ClangNoStackProtector)
    .value("C2X_CLANG_NO_STACK_PROTECTOR", pasta::NoStackProtectorAttrSpelling::kC2xClangNoStackProtector)
    .value("DECLSPEC_SAFEBUFFERS", pasta::NoStackProtectorAttrSpelling::kDeclspecSafebuffers)
    .value("SPELLING_NOT_CALCULATED", pasta::NoStackProtectorAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoThreadSafetyAnalysisAttrSpelling>(m, "NoThreadSafetyAnalysisAttrSpelling")
    .value("GNU_NO_THREAD_SAFETY_ANALYSIS", pasta::NoThreadSafetyAnalysisAttrSpelling::kGNUNoThreadSafetyAnalysis)
    .value("CXX11_CLANG_NO_THREAD_SAFETY_ANALYSIS", pasta::NoThreadSafetyAnalysisAttrSpelling::kCXX11ClangNoThreadSafetyAnalysis)
    .value("C2X_CLANG_NO_THREAD_SAFETY_ANALYSIS", pasta::NoThreadSafetyAnalysisAttrSpelling::kC2xClangNoThreadSafetyAnalysis)
    .value("SPELLING_NOT_CALCULATED", pasta::NoThreadSafetyAnalysisAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoThrowAttrSpelling>(m, "NoThrowAttrSpelling")
    .value("GNU_NOTHROW", pasta::NoThrowAttrSpelling::kGNUNothrow)
    .value("CXX11_GNU_NOTHROW", pasta::NoThrowAttrSpelling::kCXX11GnuNothrow)
    .value("C2X_GNU_NOTHROW", pasta::NoThrowAttrSpelling::kC2xGnuNothrow)
    .value("DECLSPEC_NOTHROW", pasta::NoThrowAttrSpelling::kDeclspecNothrow)
    .value("SPELLING_NOT_CALCULATED", pasta::NoThrowAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NoUwtableAttrSpelling>(m, "NoUwtableAttrSpelling")
    .value("GNU_NOUWTABLE", pasta::NoUwtableAttrSpelling::kGNUNouwtable)
    .value("CXX11_CLANG_NOUWTABLE", pasta::NoUwtableAttrSpelling::kCXX11ClangNouwtable)
    .value("C2X_CLANG_NOUWTABLE", pasta::NoUwtableAttrSpelling::kC2xClangNouwtable)
    .value("SPELLING_NOT_CALCULATED", pasta::NoUwtableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NonNullAttrSpelling>(m, "NonNullAttrSpelling")
    .value("GNU_NONNULL", pasta::NonNullAttrSpelling::kGNUNonnull)
    .value("CXX11_GNU_NONNULL", pasta::NonNullAttrSpelling::kCXX11GnuNonnull)
    .value("C2X_GNU_NONNULL", pasta::NonNullAttrSpelling::kC2xGnuNonnull)
    .value("SPELLING_NOT_CALCULATED", pasta::NonNullAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::NotTailCalledAttrSpelling>(m, "NotTailCalledAttrSpelling")
    .value("GNU_NOT_TAIL_CALLED", pasta::NotTailCalledAttrSpelling::kGNUNotTailCalled)
    .value("CXX11_CLANG_NOT_TAIL_CALLED", pasta::NotTailCalledAttrSpelling::kCXX11ClangNotTailCalled)
    .value("C2X_CLANG_NOT_TAIL_CALLED", pasta::NotTailCalledAttrSpelling::kC2xClangNotTailCalled)
    .value("SPELLING_NOT_CALCULATED", pasta::NotTailCalledAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OMPAllocateDeclAttrAllocatorTypeTy>(m, "OMPAllocateDeclAttrAllocatorTypeTy")
    .value("OMP_NULL_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPNullMemoryAlloc)
    .value("OMP_DEFAULT_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPDefaultMemoryAlloc)
    .value("OMP_LARGE_CAP_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPLargeCapMemoryAlloc)
    .value("OMP_CONST_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPConstMemoryAlloc)
    .value("OMP_HIGH_BW_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPHighBWMemoryAlloc)
    .value("OMP_LOW_LAT_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPLowLatMemoryAlloc)
    .value("OMPC_GROUP_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPCGroupMemoryAlloc)
    .value("OMPP_TEAM_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPPTeamMemoryAlloc)
    .value("OMP_THREAD_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPThreadMemoryAlloc)
    .value("OMP_USER_DEFINED_MEMORY_ALLOC", pasta::OMPAllocateDeclAttrAllocatorTypeTy::kOMPUserDefinedMemoryAlloc);

  nb::enum_<pasta::OMPDeclareReductionDeclInitKind>(m, "OMPDeclareReductionDeclInitKind")
    .value("CALL_INITIALIZER", pasta::OMPDeclareReductionDeclInitKind::kCallInitializer)
    .value("DIRECT_INITIALIZER", pasta::OMPDeclareReductionDeclInitKind::kDirectInitializer)
    .value("COPY_INITIALIZER", pasta::OMPDeclareReductionDeclInitKind::kCopyInitializer);

  nb::enum_<pasta::OMPDeclareSimdDeclAttrBranchStateTy>(m, "OMPDeclareSimdDeclAttrBranchStateTy")
    .value("UNDEFINED", pasta::OMPDeclareSimdDeclAttrBranchStateTy::kUndefined)
    .value("INBRANCH", pasta::OMPDeclareSimdDeclAttrBranchStateTy::kInbranch)
    .value("NOTINBRANCH", pasta::OMPDeclareSimdDeclAttrBranchStateTy::kNotinbranch);

  nb::enum_<pasta::OMPDeclareTargetDeclAttrDevTypeTy>(m, "OMPDeclareTargetDeclAttrDevTypeTy")
    .value("HOST", pasta::OMPDeclareTargetDeclAttrDevTypeTy::kHost)
    .value("NO_HOST", pasta::OMPDeclareTargetDeclAttrDevTypeTy::kNoHost)
    .value("ANY", pasta::OMPDeclareTargetDeclAttrDevTypeTy::kAny);

  nb::enum_<pasta::OMPDeclareTargetDeclAttrMapTypeTy>(m, "OMPDeclareTargetDeclAttrMapTypeTy")
    .value("TO", pasta::OMPDeclareTargetDeclAttrMapTypeTy::kTo)
    .value("ENTER", pasta::OMPDeclareTargetDeclAttrMapTypeTy::kEnter)
    .value("LINK", pasta::OMPDeclareTargetDeclAttrMapTypeTy::kLink);

  nb::enum_<pasta::OSConsumedAttrSpelling>(m, "OSConsumedAttrSpelling")
    .value("GNU_OS_CONSUMED", pasta::OSConsumedAttrSpelling::kGNUOsConsumed)
    .value("CXX11_CLANG_OS_CONSUMED", pasta::OSConsumedAttrSpelling::kCXX11ClangOsConsumed)
    .value("C2X_CLANG_OS_CONSUMED", pasta::OSConsumedAttrSpelling::kC2xClangOsConsumed)
    .value("SPELLING_NOT_CALCULATED", pasta::OSConsumedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OSConsumesThisAttrSpelling>(m, "OSConsumesThisAttrSpelling")
    .value("GNU_OS_CONSUMES_THIS", pasta::OSConsumesThisAttrSpelling::kGNUOsConsumesThis)
    .value("CXX11_CLANG_OS_CONSUMES_THIS", pasta::OSConsumesThisAttrSpelling::kCXX11ClangOsConsumesThis)
    .value("C2X_CLANG_OS_CONSUMES_THIS", pasta::OSConsumesThisAttrSpelling::kC2xClangOsConsumesThis)
    .value("SPELLING_NOT_CALCULATED", pasta::OSConsumesThisAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OSReturnsNotRetainedAttrSpelling>(m, "OSReturnsNotRetainedAttrSpelling")
    .value("GNU_OS_RETURNS_NOT_RETAINED", pasta::OSReturnsNotRetainedAttrSpelling::kGNUOsReturnsNotRetained)
    .value("CXX11_CLANG_OS_RETURNS_NOT_RETAINED", pasta::OSReturnsNotRetainedAttrSpelling::kCXX11ClangOsReturnsNotRetained)
    .value("C2X_CLANG_OS_RETURNS_NOT_RETAINED", pasta::OSReturnsNotRetainedAttrSpelling::kC2xClangOsReturnsNotRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::OSReturnsNotRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OSReturnsRetainedAttrSpelling>(m, "OSReturnsRetainedAttrSpelling")
    .value("GNU_OS_RETURNS_RETAINED", pasta::OSReturnsRetainedAttrSpelling::kGNUOsReturnsRetained)
    .value("CXX11_CLANG_OS_RETURNS_RETAINED", pasta::OSReturnsRetainedAttrSpelling::kCXX11ClangOsReturnsRetained)
    .value("C2X_CLANG_OS_RETURNS_RETAINED", pasta::OSReturnsRetainedAttrSpelling::kC2xClangOsReturnsRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::OSReturnsRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OSReturnsRetainedOnNonZeroAttrSpelling>(m, "OSReturnsRetainedOnNonZeroAttrSpelling")
    .value("GNU_OS_RETURNS_RETAINED_ON_NON_ZERO", pasta::OSReturnsRetainedOnNonZeroAttrSpelling::kGNUOsReturnsRetainedOnNonZero)
    .value("CXX11_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO", pasta::OSReturnsRetainedOnNonZeroAttrSpelling::kCXX11ClangOsReturnsRetainedOnNonZero)
    .value("C2X_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO", pasta::OSReturnsRetainedOnNonZeroAttrSpelling::kC2xClangOsReturnsRetainedOnNonZero)
    .value("SPELLING_NOT_CALCULATED", pasta::OSReturnsRetainedOnNonZeroAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OSReturnsRetainedOnZeroAttrSpelling>(m, "OSReturnsRetainedOnZeroAttrSpelling")
    .value("GNU_OS_RETURNS_RETAINED_ON_ZERO", pasta::OSReturnsRetainedOnZeroAttrSpelling::kGNUOsReturnsRetainedOnZero)
    .value("CXX11_CLANG_OS_RETURNS_RETAINED_ON_ZERO", pasta::OSReturnsRetainedOnZeroAttrSpelling::kCXX11ClangOsReturnsRetainedOnZero)
    .value("C2X_CLANG_OS_RETURNS_RETAINED_ON_ZERO", pasta::OSReturnsRetainedOnZeroAttrSpelling::kC2xClangOsReturnsRetainedOnZero)
    .value("SPELLING_NOT_CALCULATED", pasta::OSReturnsRetainedOnZeroAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCBoxableAttrSpelling>(m, "ObjCBoxableAttrSpelling")
    .value("GNU_OBJC_BOXABLE", pasta::ObjCBoxableAttrSpelling::kGNUObjcBoxable)
    .value("CXX11_CLANG_OBJC_BOXABLE", pasta::ObjCBoxableAttrSpelling::kCXX11ClangObjcBoxable)
    .value("C2X_CLANG_OBJC_BOXABLE", pasta::ObjCBoxableAttrSpelling::kC2xClangObjcBoxable)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCBoxableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCBridgeAttrSpelling>(m, "ObjCBridgeAttrSpelling")
    .value("GNU_OBJC_BRIDGE", pasta::ObjCBridgeAttrSpelling::kGNUObjcBridge)
    .value("CXX11_CLANG_OBJC_BRIDGE", pasta::ObjCBridgeAttrSpelling::kCXX11ClangObjcBridge)
    .value("C2X_CLANG_OBJC_BRIDGE", pasta::ObjCBridgeAttrSpelling::kC2xClangObjcBridge)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCBridgeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCBridgeMutableAttrSpelling>(m, "ObjCBridgeMutableAttrSpelling")
    .value("GNU_OBJC_BRIDGE_MUTABLE", pasta::ObjCBridgeMutableAttrSpelling::kGNUObjcBridgeMutable)
    .value("CXX11_CLANG_OBJC_BRIDGE_MUTABLE", pasta::ObjCBridgeMutableAttrSpelling::kCXX11ClangObjcBridgeMutable)
    .value("C2X_CLANG_OBJC_BRIDGE_MUTABLE", pasta::ObjCBridgeMutableAttrSpelling::kC2xClangObjcBridgeMutable)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCBridgeMutableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCBridgeRelatedAttrSpelling>(m, "ObjCBridgeRelatedAttrSpelling")
    .value("GNU_OBJC_BRIDGE_RELATED", pasta::ObjCBridgeRelatedAttrSpelling::kGNUObjcBridgeRelated)
    .value("CXX11_CLANG_OBJC_BRIDGE_RELATED", pasta::ObjCBridgeRelatedAttrSpelling::kCXX11ClangObjcBridgeRelated)
    .value("C2X_CLANG_OBJC_BRIDGE_RELATED", pasta::ObjCBridgeRelatedAttrSpelling::kC2xClangObjcBridgeRelated)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCBridgeRelatedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCClassStubAttrSpelling>(m, "ObjCClassStubAttrSpelling")
    .value("GNU_OBJC_CLASS_STUB", pasta::ObjCClassStubAttrSpelling::kGNUObjcClassStub)
    .value("CXX11_CLANG_OBJC_CLASS_STUB", pasta::ObjCClassStubAttrSpelling::kCXX11ClangObjcClassStub)
    .value("C2X_CLANG_OBJC_CLASS_STUB", pasta::ObjCClassStubAttrSpelling::kC2xClangObjcClassStub)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCClassStubAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCDesignatedInitializerAttrSpelling>(m, "ObjCDesignatedInitializerAttrSpelling")
    .value("GNU_OBJC_DESIGNATED_INITIALIZER", pasta::ObjCDesignatedInitializerAttrSpelling::kGNUObjcDesignatedInitializer)
    .value("CXX11_CLANG_OBJC_DESIGNATED_INITIALIZER", pasta::ObjCDesignatedInitializerAttrSpelling::kCXX11ClangObjcDesignatedInitializer)
    .value("C2X_CLANG_OBJC_DESIGNATED_INITIALIZER", pasta::ObjCDesignatedInitializerAttrSpelling::kC2xClangObjcDesignatedInitializer)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCDesignatedInitializerAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCDirectAttrSpelling>(m, "ObjCDirectAttrSpelling")
    .value("GNU_OBJC_DIRECT", pasta::ObjCDirectAttrSpelling::kGNUObjcDirect)
    .value("CXX11_CLANG_OBJC_DIRECT", pasta::ObjCDirectAttrSpelling::kCXX11ClangObjcDirect)
    .value("C2X_CLANG_OBJC_DIRECT", pasta::ObjCDirectAttrSpelling::kC2xClangObjcDirect)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCDirectAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCDirectMembersAttrSpelling>(m, "ObjCDirectMembersAttrSpelling")
    .value("GNU_OBJC_DIRECT_MEMBERS", pasta::ObjCDirectMembersAttrSpelling::kGNUObjcDirectMembers)
    .value("CXX11_CLANG_OBJC_DIRECT_MEMBERS", pasta::ObjCDirectMembersAttrSpelling::kCXX11ClangObjcDirectMembers)
    .value("C2X_CLANG_OBJC_DIRECT_MEMBERS", pasta::ObjCDirectMembersAttrSpelling::kC2xClangObjcDirectMembers)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCDirectMembersAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCExceptionAttrSpelling>(m, "ObjCExceptionAttrSpelling")
    .value("GNU_OBJC_EXCEPTION", pasta::ObjCExceptionAttrSpelling::kGNUObjcException)
    .value("CXX11_CLANG_OBJC_EXCEPTION", pasta::ObjCExceptionAttrSpelling::kCXX11ClangObjcException)
    .value("C2X_CLANG_OBJC_EXCEPTION", pasta::ObjCExceptionAttrSpelling::kC2xClangObjcException)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCExceptionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCExplicitProtocolImplAttrSpelling>(m, "ObjCExplicitProtocolImplAttrSpelling")
    .value("GNU_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION", pasta::ObjCExplicitProtocolImplAttrSpelling::kGNUObjcProtocolRequiresExplicitImplementation)
    .value("CXX11_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION", pasta::ObjCExplicitProtocolImplAttrSpelling::kCXX11ClangObjcProtocolRequiresExplicitImplementation)
    .value("C2X_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION", pasta::ObjCExplicitProtocolImplAttrSpelling::kC2xClangObjcProtocolRequiresExplicitImplementation)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCExplicitProtocolImplAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCExternallyRetainedAttrSpelling>(m, "ObjCExternallyRetainedAttrSpelling")
    .value("GNU_OBJC_EXTERNALLY_RETAINED", pasta::ObjCExternallyRetainedAttrSpelling::kGNUObjcExternallyRetained)
    .value("CXX11_CLANG_OBJC_EXTERNALLY_RETAINED", pasta::ObjCExternallyRetainedAttrSpelling::kCXX11ClangObjcExternallyRetained)
    .value("C2X_CLANG_OBJC_EXTERNALLY_RETAINED", pasta::ObjCExternallyRetainedAttrSpelling::kC2xClangObjcExternallyRetained)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCExternallyRetainedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCGCAttrSpelling>(m, "ObjCGCAttrSpelling")
    .value("GNU_OBJC_GC", pasta::ObjCGCAttrSpelling::kGNUObjcGc)
    .value("CXX11_CLANG_OBJC_GC", pasta::ObjCGCAttrSpelling::kCXX11ClangObjcGc)
    .value("C2X_CLANG_OBJC_GC", pasta::ObjCGCAttrSpelling::kC2xClangObjcGc)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCGCAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCIndependentClassAttrSpelling>(m, "ObjCIndependentClassAttrSpelling")
    .value("GNU_OBJC_INDEPENDENT_CLASS", pasta::ObjCIndependentClassAttrSpelling::kGNUObjcIndependentClass)
    .value("CXX11_CLANG_OBJC_INDEPENDENT_CLASS", pasta::ObjCIndependentClassAttrSpelling::kCXX11ClangObjcIndependentClass)
    .value("C2X_CLANG_OBJC_INDEPENDENT_CLASS", pasta::ObjCIndependentClassAttrSpelling::kC2xClangObjcIndependentClass)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCIndependentClassAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCIvarDeclAccessControl>(m, "ObjCIvarDeclAccessControl")
    .value("NONE", pasta::ObjCIvarDeclAccessControl::kNone)
    .value("PRIVATE", pasta::ObjCIvarDeclAccessControl::kPrivate)
    .value("PROTECTED", pasta::ObjCIvarDeclAccessControl::kProtected)
    .value("PUBLIC", pasta::ObjCIvarDeclAccessControl::kPublic)
    .value("PACKAGE", pasta::ObjCIvarDeclAccessControl::kPackage);

  nb::enum_<pasta::ObjCMessageExprReceiverKind>(m, "ObjCMessageExprReceiverKind")
    .value("CLASS", pasta::ObjCMessageExprReceiverKind::kClass)
    .value("INSTANCE", pasta::ObjCMessageExprReceiverKind::kInstance)
    .value("SUPER_CLASS", pasta::ObjCMessageExprReceiverKind::kSuperClass)
    .value("SUPER_INSTANCE", pasta::ObjCMessageExprReceiverKind::kSuperInstance);

  nb::enum_<pasta::ObjCMethodDeclImplementationControl>(m, "ObjCMethodDeclImplementationControl")
    .value("NONE", pasta::ObjCMethodDeclImplementationControl::kNone)
    .value("REQUIRED", pasta::ObjCMethodDeclImplementationControl::kRequired)
    .value("OPTIONAL", pasta::ObjCMethodDeclImplementationControl::kOptional);

  nb::enum_<pasta::ObjCMethodFamilyAttrFamilyKind>(m, "ObjCMethodFamilyAttrFamilyKind")
    .value("NONE", pasta::ObjCMethodFamilyAttrFamilyKind::kNone)
    .value("ALLOC", pasta::ObjCMethodFamilyAttrFamilyKind::kAlloc)
    .value("COPY", pasta::ObjCMethodFamilyAttrFamilyKind::kCopy)
    .value("INITIALIZER", pasta::ObjCMethodFamilyAttrFamilyKind::kInitializer)
    .value("MUTABLE_COPY", pasta::ObjCMethodFamilyAttrFamilyKind::kMutableCopy)
    .value("NEW", pasta::ObjCMethodFamilyAttrFamilyKind::kNew);

  nb::enum_<pasta::ObjCMethodFamilyAttrSpelling>(m, "ObjCMethodFamilyAttrSpelling")
    .value("GNU_OBJC_METHOD_FAMILY", pasta::ObjCMethodFamilyAttrSpelling::kGNUObjcMethodFamily)
    .value("CXX11_CLANG_OBJC_METHOD_FAMILY", pasta::ObjCMethodFamilyAttrSpelling::kCXX11ClangObjcMethodFamily)
    .value("C2X_CLANG_OBJC_METHOD_FAMILY", pasta::ObjCMethodFamilyAttrSpelling::kC2xClangObjcMethodFamily)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCMethodFamilyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCNSObjectAttrSpelling>(m, "ObjCNSObjectAttrSpelling")
    .value("GNUNS_OBJECT", pasta::ObjCNSObjectAttrSpelling::kGNUNSObject)
    .value("CXX11_CLANG_NS_OBJECT", pasta::ObjCNSObjectAttrSpelling::kCXX11ClangNSObject)
    .value("C2X_CLANG_NS_OBJECT", pasta::ObjCNSObjectAttrSpelling::kC2xClangNSObject)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCNSObjectAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCNonLazyClassAttrSpelling>(m, "ObjCNonLazyClassAttrSpelling")
    .value("GNU_OBJC_NONLAZY_CLASS", pasta::ObjCNonLazyClassAttrSpelling::kGNUObjcNonlazyClass)
    .value("CXX11_CLANG_OBJC_NONLAZY_CLASS", pasta::ObjCNonLazyClassAttrSpelling::kCXX11ClangObjcNonlazyClass)
    .value("C2X_CLANG_OBJC_NONLAZY_CLASS", pasta::ObjCNonLazyClassAttrSpelling::kC2xClangObjcNonlazyClass)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCNonLazyClassAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCNonRuntimeProtocolAttrSpelling>(m, "ObjCNonRuntimeProtocolAttrSpelling")
    .value("GNU_OBJC_NON_RUNTIME_PROTOCOL", pasta::ObjCNonRuntimeProtocolAttrSpelling::kGNUObjcNonRuntimeProtocol)
    .value("CXX11_CLANG_OBJC_NON_RUNTIME_PROTOCOL", pasta::ObjCNonRuntimeProtocolAttrSpelling::kCXX11ClangObjcNonRuntimeProtocol)
    .value("C2X_CLANG_OBJC_NON_RUNTIME_PROTOCOL", pasta::ObjCNonRuntimeProtocolAttrSpelling::kC2xClangObjcNonRuntimeProtocol)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCNonRuntimeProtocolAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCOwnershipAttrSpelling>(m, "ObjCOwnershipAttrSpelling")
    .value("GNU_OBJC_OWNERSHIP", pasta::ObjCOwnershipAttrSpelling::kGNUObjcOwnership)
    .value("CXX11_CLANG_OBJC_OWNERSHIP", pasta::ObjCOwnershipAttrSpelling::kCXX11ClangObjcOwnership)
    .value("C2X_CLANG_OBJC_OWNERSHIP", pasta::ObjCOwnershipAttrSpelling::kC2xClangObjcOwnership)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCOwnershipAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCPreciseLifetimeAttrSpelling>(m, "ObjCPreciseLifetimeAttrSpelling")
    .value("GNU_OBJC_PRECISE_LIFETIME", pasta::ObjCPreciseLifetimeAttrSpelling::kGNUObjcPreciseLifetime)
    .value("CXX11_CLANG_OBJC_PRECISE_LIFETIME", pasta::ObjCPreciseLifetimeAttrSpelling::kCXX11ClangObjcPreciseLifetime)
    .value("C2X_CLANG_OBJC_PRECISE_LIFETIME", pasta::ObjCPreciseLifetimeAttrSpelling::kC2xClangObjcPreciseLifetime)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCPreciseLifetimeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCPropertyDeclPropertyControl>(m, "ObjCPropertyDeclPropertyControl")
    .value("NONE", pasta::ObjCPropertyDeclPropertyControl::kNone)
    .value("REQUIRED", pasta::ObjCPropertyDeclPropertyControl::kRequired)
    .value("OPTIONAL", pasta::ObjCPropertyDeclPropertyControl::kOptional);

  nb::enum_<pasta::ObjCPropertyDeclSetterKind>(m, "ObjCPropertyDeclSetterKind")
    .value("ASSIGN", pasta::ObjCPropertyDeclSetterKind::kAssign)
    .value("RETAIN", pasta::ObjCPropertyDeclSetterKind::kRetain)
    .value("COPY", pasta::ObjCPropertyDeclSetterKind::kCopy)
    .value("WEAK", pasta::ObjCPropertyDeclSetterKind::kWeak);

  nb::enum_<pasta::ObjCPropertyImplDeclKind>(m, "ObjCPropertyImplDeclKind")
    .value("SYNTHESIZE", pasta::ObjCPropertyImplDeclKind::kSynthesize)
    .value("DYNAMIC", pasta::ObjCPropertyImplDeclKind::kDynamic);

  nb::enum_<pasta::ObjCRequiresPropertyDefsAttrSpelling>(m, "ObjCRequiresPropertyDefsAttrSpelling")
    .value("GNU_OBJC_REQUIRES_PROPERTY_DEFINITIONS", pasta::ObjCRequiresPropertyDefsAttrSpelling::kGNUObjcRequiresPropertyDefinitions)
    .value("CXX11_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS", pasta::ObjCRequiresPropertyDefsAttrSpelling::kCXX11ClangObjcRequiresPropertyDefinitions)
    .value("C2X_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS", pasta::ObjCRequiresPropertyDefsAttrSpelling::kC2xClangObjcRequiresPropertyDefinitions)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCRequiresPropertyDefsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCRequiresSuperAttrSpelling>(m, "ObjCRequiresSuperAttrSpelling")
    .value("GNU_OBJC_REQUIRES_SUPER", pasta::ObjCRequiresSuperAttrSpelling::kGNUObjcRequiresSuper)
    .value("CXX11_CLANG_OBJC_REQUIRES_SUPER", pasta::ObjCRequiresSuperAttrSpelling::kCXX11ClangObjcRequiresSuper)
    .value("C2X_CLANG_OBJC_REQUIRES_SUPER", pasta::ObjCRequiresSuperAttrSpelling::kC2xClangObjcRequiresSuper)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCRequiresSuperAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCReturnsInnerPointerAttrSpelling>(m, "ObjCReturnsInnerPointerAttrSpelling")
    .value("GNU_OBJC_RETURNS_INNER_POINTER", pasta::ObjCReturnsInnerPointerAttrSpelling::kGNUObjcReturnsInnerPointer)
    .value("CXX11_CLANG_OBJC_RETURNS_INNER_POINTER", pasta::ObjCReturnsInnerPointerAttrSpelling::kCXX11ClangObjcReturnsInnerPointer)
    .value("C2X_CLANG_OBJC_RETURNS_INNER_POINTER", pasta::ObjCReturnsInnerPointerAttrSpelling::kC2xClangObjcReturnsInnerPointer)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCReturnsInnerPointerAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCRootClassAttrSpelling>(m, "ObjCRootClassAttrSpelling")
    .value("GNU_OBJC_ROOT_CLASS", pasta::ObjCRootClassAttrSpelling::kGNUObjcRootClass)
    .value("CXX11_CLANG_OBJC_ROOT_CLASS", pasta::ObjCRootClassAttrSpelling::kCXX11ClangObjcRootClass)
    .value("C2X_CLANG_OBJC_ROOT_CLASS", pasta::ObjCRootClassAttrSpelling::kC2xClangObjcRootClass)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCRootClassAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCRuntimeNameAttrSpelling>(m, "ObjCRuntimeNameAttrSpelling")
    .value("GNU_OBJC_RUNTIME_NAME", pasta::ObjCRuntimeNameAttrSpelling::kGNUObjcRuntimeName)
    .value("CXX11_CLANG_OBJC_RUNTIME_NAME", pasta::ObjCRuntimeNameAttrSpelling::kCXX11ClangObjcRuntimeName)
    .value("C2X_CLANG_OBJC_RUNTIME_NAME", pasta::ObjCRuntimeNameAttrSpelling::kC2xClangObjcRuntimeName)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCRuntimeNameAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCRuntimeVisibleAttrSpelling>(m, "ObjCRuntimeVisibleAttrSpelling")
    .value("GNU_OBJC_RUNTIME_VISIBLE", pasta::ObjCRuntimeVisibleAttrSpelling::kGNUObjcRuntimeVisible)
    .value("CXX11_CLANG_OBJC_RUNTIME_VISIBLE", pasta::ObjCRuntimeVisibleAttrSpelling::kCXX11ClangObjcRuntimeVisible)
    .value("C2X_CLANG_OBJC_RUNTIME_VISIBLE", pasta::ObjCRuntimeVisibleAttrSpelling::kC2xClangObjcRuntimeVisible)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCRuntimeVisibleAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ObjCSubclassingRestrictedAttrSpelling>(m, "ObjCSubclassingRestrictedAttrSpelling")
    .value("GNU_OBJC_SUBCLASSING_RESTRICTED", pasta::ObjCSubclassingRestrictedAttrSpelling::kGNUObjcSubclassingRestricted)
    .value("CXX11_CLANG_OBJC_SUBCLASSING_RESTRICTED", pasta::ObjCSubclassingRestrictedAttrSpelling::kCXX11ClangObjcSubclassingRestricted)
    .value("C2X_CLANG_OBJC_SUBCLASSING_RESTRICTED", pasta::ObjCSubclassingRestrictedAttrSpelling::kC2xClangObjcSubclassingRestricted)
    .value("SPELLING_NOT_CALCULATED", pasta::ObjCSubclassingRestrictedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLAccessAttrSpelling>(m, "OpenCLAccessAttrSpelling")
    .value("KEYWORD_READ_ONLY", pasta::OpenCLAccessAttrSpelling::kKeywordReadOnly)
    .value("KEYWORD_WRITE_ONLY", pasta::OpenCLAccessAttrSpelling::kKeywordWriteOnly)
    .value("KEYWORD_READ_WRITE", pasta::OpenCLAccessAttrSpelling::kKeywordReadWrite)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLAccessAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLConstantAddressSpaceAttrSpelling>(m, "OpenCLConstantAddressSpaceAttrSpelling")
    .value("KEYWORD_CONSTANT", pasta::OpenCLConstantAddressSpaceAttrSpelling::kKeywordConstant)
    .value("GNU_OPENCL_CONSTANT", pasta::OpenCLConstantAddressSpaceAttrSpelling::kGNUOpenclConstant)
    .value("CXX11_CLANG_OPENCL_CONSTANT", pasta::OpenCLConstantAddressSpaceAttrSpelling::kCXX11ClangOpenclConstant)
    .value("C2X_CLANG_OPENCL_CONSTANT", pasta::OpenCLConstantAddressSpaceAttrSpelling::kC2xClangOpenclConstant)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLConstantAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLGenericAddressSpaceAttrSpelling>(m, "OpenCLGenericAddressSpaceAttrSpelling")
    .value("KEYWORD_GENERIC", pasta::OpenCLGenericAddressSpaceAttrSpelling::kKeywordGeneric)
    .value("GNU_OPENCL_GENERIC", pasta::OpenCLGenericAddressSpaceAttrSpelling::kGNUOpenclGeneric)
    .value("CXX11_CLANG_OPENCL_GENERIC", pasta::OpenCLGenericAddressSpaceAttrSpelling::kCXX11ClangOpenclGeneric)
    .value("C2X_CLANG_OPENCL_GENERIC", pasta::OpenCLGenericAddressSpaceAttrSpelling::kC2xClangOpenclGeneric)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLGenericAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLGlobalAddressSpaceAttrSpelling>(m, "OpenCLGlobalAddressSpaceAttrSpelling")
    .value("KEYWORD_GLOBAL", pasta::OpenCLGlobalAddressSpaceAttrSpelling::kKeywordGlobal)
    .value("GNU_OPENCL_GLOBAL", pasta::OpenCLGlobalAddressSpaceAttrSpelling::kGNUOpenclGlobal)
    .value("CXX11_CLANG_OPENCL_GLOBAL", pasta::OpenCLGlobalAddressSpaceAttrSpelling::kCXX11ClangOpenclGlobal)
    .value("C2X_CLANG_OPENCL_GLOBAL", pasta::OpenCLGlobalAddressSpaceAttrSpelling::kC2xClangOpenclGlobal)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLGlobalAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling>(m, "OpenCLGlobalDeviceAddressSpaceAttrSpelling")
    .value("GNU_OPENCL_GLOBAL_DEVICE", pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling::kGNUOpenclGlobalDevice)
    .value("CXX11_CLANG_OPENCL_GLOBAL_DEVICE", pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling::kCXX11ClangOpenclGlobalDevice)
    .value("C2X_CLANG_OPENCL_GLOBAL_DEVICE", pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling::kC2xClangOpenclGlobalDevice)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLGlobalHostAddressSpaceAttrSpelling>(m, "OpenCLGlobalHostAddressSpaceAttrSpelling")
    .value("GNU_OPENCL_GLOBAL_HOST", pasta::OpenCLGlobalHostAddressSpaceAttrSpelling::kGNUOpenclGlobalHost)
    .value("CXX11_CLANG_OPENCL_GLOBAL_HOST", pasta::OpenCLGlobalHostAddressSpaceAttrSpelling::kCXX11ClangOpenclGlobalHost)
    .value("C2X_CLANG_OPENCL_GLOBAL_HOST", pasta::OpenCLGlobalHostAddressSpaceAttrSpelling::kC2xClangOpenclGlobalHost)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLGlobalHostAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLKernelAttrSpelling>(m, "OpenCLKernelAttrSpelling")
    .value("KEYWORD_KERNEL", pasta::OpenCLKernelAttrSpelling::kKeywordKernel)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLKernelAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLLocalAddressSpaceAttrSpelling>(m, "OpenCLLocalAddressSpaceAttrSpelling")
    .value("KEYWORD_LOCAL", pasta::OpenCLLocalAddressSpaceAttrSpelling::kKeywordLocal)
    .value("GNU_OPENCL_LOCAL", pasta::OpenCLLocalAddressSpaceAttrSpelling::kGNUOpenclLocal)
    .value("CXX11_CLANG_OPENCL_LOCAL", pasta::OpenCLLocalAddressSpaceAttrSpelling::kCXX11ClangOpenclLocal)
    .value("C2X_CLANG_OPENCL_LOCAL", pasta::OpenCLLocalAddressSpaceAttrSpelling::kC2xClangOpenclLocal)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLLocalAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OpenCLPrivateAddressSpaceAttrSpelling>(m, "OpenCLPrivateAddressSpaceAttrSpelling")
    .value("KEYWORD_PRIVATE", pasta::OpenCLPrivateAddressSpaceAttrSpelling::kKeywordPrivate)
    .value("GNU_OPENCL_PRIVATE", pasta::OpenCLPrivateAddressSpaceAttrSpelling::kGNUOpenclPrivate)
    .value("CXX11_CLANG_OPENCL_PRIVATE", pasta::OpenCLPrivateAddressSpaceAttrSpelling::kCXX11ClangOpenclPrivate)
    .value("C2X_CLANG_OPENCL_PRIVATE", pasta::OpenCLPrivateAddressSpaceAttrSpelling::kC2xClangOpenclPrivate)
    .value("SPELLING_NOT_CALCULATED", pasta::OpenCLPrivateAddressSpaceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OptimizeNoneAttrSpelling>(m, "OptimizeNoneAttrSpelling")
    .value("GNU_OPTNONE", pasta::OptimizeNoneAttrSpelling::kGNUOptnone)
    .value("CXX11_CLANG_OPTNONE", pasta::OptimizeNoneAttrSpelling::kCXX11ClangOptnone)
    .value("C2X_CLANG_OPTNONE", pasta::OptimizeNoneAttrSpelling::kC2xClangOptnone)
    .value("SPELLING_NOT_CALCULATED", pasta::OptimizeNoneAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OverloadableAttrSpelling>(m, "OverloadableAttrSpelling")
    .value("GNU_OVERLOADABLE", pasta::OverloadableAttrSpelling::kGNUOverloadable)
    .value("CXX11_CLANG_OVERLOADABLE", pasta::OverloadableAttrSpelling::kCXX11ClangOverloadable)
    .value("C2X_CLANG_OVERLOADABLE", pasta::OverloadableAttrSpelling::kC2xClangOverloadable)
    .value("SPELLING_NOT_CALCULATED", pasta::OverloadableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::OwnershipAttrOwnershipKind>(m, "OwnershipAttrOwnershipKind")
    .value("HOLDS", pasta::OwnershipAttrOwnershipKind::kHolds)
    .value("RETURNS", pasta::OwnershipAttrOwnershipKind::kReturns)
    .value("TAKES", pasta::OwnershipAttrOwnershipKind::kTakes);

  nb::enum_<pasta::OwnershipAttrSpelling>(m, "OwnershipAttrSpelling")
    .value("GNU_OWNERSHIP_HOLDS", pasta::OwnershipAttrSpelling::kGNUOwnershipHolds)
    .value("CXX11_CLANG_OWNERSHIP_HOLDS", pasta::OwnershipAttrSpelling::kCXX11ClangOwnershipHolds)
    .value("C2X_CLANG_OWNERSHIP_HOLDS", pasta::OwnershipAttrSpelling::kC2xClangOwnershipHolds)
    .value("GNU_OWNERSHIP_RETURNS", pasta::OwnershipAttrSpelling::kGNUOwnershipReturns)
    .value("CXX11_CLANG_OWNERSHIP_RETURNS", pasta::OwnershipAttrSpelling::kCXX11ClangOwnershipReturns)
    .value("C2X_CLANG_OWNERSHIP_RETURNS", pasta::OwnershipAttrSpelling::kC2xClangOwnershipReturns)
    .value("GNU_OWNERSHIP_TAKES", pasta::OwnershipAttrSpelling::kGNUOwnershipTakes)
    .value("CXX11_CLANG_OWNERSHIP_TAKES", pasta::OwnershipAttrSpelling::kCXX11ClangOwnershipTakes)
    .value("C2X_CLANG_OWNERSHIP_TAKES", pasta::OwnershipAttrSpelling::kC2xClangOwnershipTakes)
    .value("SPELLING_NOT_CALCULATED", pasta::OwnershipAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PackedAttrSpelling>(m, "PackedAttrSpelling")
    .value("GNU_PACKED", pasta::PackedAttrSpelling::kGNUPacked)
    .value("CXX11_GNU_PACKED", pasta::PackedAttrSpelling::kCXX11GnuPacked)
    .value("C2X_GNU_PACKED", pasta::PackedAttrSpelling::kC2xGnuPacked)
    .value("SPELLING_NOT_CALCULATED", pasta::PackedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ParamTypestateAttrConsumedState>(m, "ParamTypestateAttrConsumedState")
    .value("UNKNOWN", pasta::ParamTypestateAttrConsumedState::kUnknown)
    .value("CONSUMED", pasta::ParamTypestateAttrConsumedState::kConsumed)
    .value("UNCONSUMED", pasta::ParamTypestateAttrConsumedState::kUnconsumed);

  nb::enum_<pasta::ParamTypestateAttrSpelling>(m, "ParamTypestateAttrSpelling")
    .value("GNU_PARAMETER_TYPESTATE", pasta::ParamTypestateAttrSpelling::kGNUParameterTypestate)
    .value("CXX11_CLANG_PARAMETER_TYPESTATE", pasta::ParamTypestateAttrSpelling::kCXX11ClangParameterTypestate)
    .value("SPELLING_NOT_CALCULATED", pasta::ParamTypestateAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PascalAttrSpelling>(m, "PascalAttrSpelling")
    .value("GNU_PASCAL", pasta::PascalAttrSpelling::kGNUPascal)
    .value("CXX11_CLANG_PASCAL", pasta::PascalAttrSpelling::kCXX11ClangPascal)
    .value("C2X_CLANG_PASCAL", pasta::PascalAttrSpelling::kC2xClangPascal)
    .value("KEYWORD_PASCAL", pasta::PascalAttrSpelling::kKeywordPascal)
    .value("SPELLING_NOT_CALCULATED", pasta::PascalAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PassObjectSizeAttrSpelling>(m, "PassObjectSizeAttrSpelling")
    .value("GNU_PASS_OBJECT_SIZE", pasta::PassObjectSizeAttrSpelling::kGNUPassObjectSize)
    .value("CXX11_CLANG_PASS_OBJECT_SIZE", pasta::PassObjectSizeAttrSpelling::kCXX11ClangPassObjectSize)
    .value("C2X_CLANG_PASS_OBJECT_SIZE", pasta::PassObjectSizeAttrSpelling::kC2xClangPassObjectSize)
    .value("GNU_PASS_DYNAMIC_OBJECT_SIZE", pasta::PassObjectSizeAttrSpelling::kGNUPassDynamicObjectSize)
    .value("CXX11_CLANG_PASS_DYNAMIC_OBJECT_SIZE", pasta::PassObjectSizeAttrSpelling::kCXX11ClangPassDynamicObjectSize)
    .value("C2X_CLANG_PASS_DYNAMIC_OBJECT_SIZE", pasta::PassObjectSizeAttrSpelling::kC2xClangPassDynamicObjectSize)
    .value("SPELLING_NOT_CALCULATED", pasta::PassObjectSizeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PatchableFunctionEntryAttrSpelling>(m, "PatchableFunctionEntryAttrSpelling")
    .value("GNU_PATCHABLE_FUNCTION_ENTRY", pasta::PatchableFunctionEntryAttrSpelling::kGNUPatchableFunctionEntry)
    .value("CXX11_GNU_PATCHABLE_FUNCTION_ENTRY", pasta::PatchableFunctionEntryAttrSpelling::kCXX11GnuPatchableFunctionEntry)
    .value("C2X_GNU_PATCHABLE_FUNCTION_ENTRY", pasta::PatchableFunctionEntryAttrSpelling::kC2xGnuPatchableFunctionEntry)
    .value("SPELLING_NOT_CALCULATED", pasta::PatchableFunctionEntryAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PcsAttrPCSType>(m, "PcsAttrPCSType")
    .value("AAPCS", pasta::PcsAttrPCSType::kAAPCS)
    .value("VFP", pasta::PcsAttrPCSType::kVFP);

  nb::enum_<pasta::PcsAttrSpelling>(m, "PcsAttrSpelling")
    .value("GNU_PCS", pasta::PcsAttrSpelling::kGNUPcs)
    .value("CXX11_GNU_PCS", pasta::PcsAttrSpelling::kCXX11GnuPcs)
    .value("C2X_GNU_PCS", pasta::PcsAttrSpelling::kC2xGnuPcs)
    .value("SPELLING_NOT_CALCULATED", pasta::PcsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PredefinedExprIdentKind>(m, "PredefinedExprIdentKind")
    .value("FUNC", pasta::PredefinedExprIdentKind::kFunc)
    .value("FUNCTION", pasta::PredefinedExprIdentKind::kFunction)
    .value("L_FUNCTION", pasta::PredefinedExprIdentKind::kLFunction)
    .value("FUNC_D_NAME", pasta::PredefinedExprIdentKind::kFuncDName)
    .value("FUNC_SIG", pasta::PredefinedExprIdentKind::kFuncSig)
    .value("L_FUNC_SIG", pasta::PredefinedExprIdentKind::kLFuncSig)
    .value("PRETTY_FUNCTION", pasta::PredefinedExprIdentKind::kPrettyFunction)
    .value("PRETTY_FUNCTION_NO_VIRTUAL", pasta::PredefinedExprIdentKind::kPrettyFunctionNoVirtual);

  nb::enum_<pasta::PreferredNameAttrSpelling>(m, "PreferredNameAttrSpelling")
    .value("GNU_PREFERRED_NAME", pasta::PreferredNameAttrSpelling::kGNUPreferredName)
    .value("CXX11_CLANG_PREFERRED_NAME", pasta::PreferredNameAttrSpelling::kCXX11ClangPreferredName)
    .value("SPELLING_NOT_CALCULATED", pasta::PreferredNameAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PreserveAllAttrSpelling>(m, "PreserveAllAttrSpelling")
    .value("GNU_PRESERVE_ALL", pasta::PreserveAllAttrSpelling::kGNUPreserveAll)
    .value("CXX11_CLANG_PRESERVE_ALL", pasta::PreserveAllAttrSpelling::kCXX11ClangPreserveAll)
    .value("C2X_CLANG_PRESERVE_ALL", pasta::PreserveAllAttrSpelling::kC2xClangPreserveAll)
    .value("SPELLING_NOT_CALCULATED", pasta::PreserveAllAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PreserveMostAttrSpelling>(m, "PreserveMostAttrSpelling")
    .value("GNU_PRESERVE_MOST", pasta::PreserveMostAttrSpelling::kGNUPreserveMost)
    .value("CXX11_CLANG_PRESERVE_MOST", pasta::PreserveMostAttrSpelling::kCXX11ClangPreserveMost)
    .value("C2X_CLANG_PRESERVE_MOST", pasta::PreserveMostAttrSpelling::kC2xClangPreserveMost)
    .value("SPELLING_NOT_CALCULATED", pasta::PreserveMostAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PtGuardedVarAttrSpelling>(m, "PtGuardedVarAttrSpelling")
    .value("GNU_PT_GUARDED_VARIABLE", pasta::PtGuardedVarAttrSpelling::kGNUPtGuardedVariable)
    .value("CXX11_CLANG_PT_GUARDED_VARIABLE", pasta::PtGuardedVarAttrSpelling::kCXX11ClangPtGuardedVariable)
    .value("SPELLING_NOT_CALCULATED", pasta::PtGuardedVarAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::PureAttrSpelling>(m, "PureAttrSpelling")
    .value("GNU_PURE", pasta::PureAttrSpelling::kGNUPure)
    .value("CXX11_GNU_PURE", pasta::PureAttrSpelling::kCXX11GnuPure)
    .value("C2X_GNU_PURE", pasta::PureAttrSpelling::kC2xGnuPure)
    .value("SPELLING_NOT_CALCULATED", pasta::PureAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::QualifiedTypeDestructionKind>(m, "QualifiedTypeDestructionKind")
    .value("NONE", pasta::QualifiedTypeDestructionKind::kNone)
    .value("CXX_DESTRUCTOR", pasta::QualifiedTypeDestructionKind::kCxxDestructor)
    .value("OBJC_STRONG_LIFETIME", pasta::QualifiedTypeDestructionKind::kObjcStrongLifetime)
    .value("OBJC_WEAK_LIFETIME", pasta::QualifiedTypeDestructionKind::kObjcWeakLifetime)
    .value("NONTRIVIAL_C_STRUCT", pasta::QualifiedTypeDestructionKind::kNontrivialCStruct);

  nb::enum_<pasta::QualifiedTypePrimitiveCopyKind>(m, "QualifiedTypePrimitiveCopyKind")
    .value("TRIVIAL", pasta::QualifiedTypePrimitiveCopyKind::kTrivial)
    .value("VOLATILE_TRIVIAL", pasta::QualifiedTypePrimitiveCopyKind::kVolatileTrivial)
    .value("ARC_STRONG", pasta::QualifiedTypePrimitiveCopyKind::kARCStrong)
    .value("ARC_WEAK", pasta::QualifiedTypePrimitiveCopyKind::kARCWeak)
    .value("STRUCT", pasta::QualifiedTypePrimitiveCopyKind::kStruct);

  nb::enum_<pasta::QualifiedTypePrimitiveDefaultInitializeKind>(m, "QualifiedTypePrimitiveDefaultInitializeKind")
    .value("TRIVIAL", pasta::QualifiedTypePrimitiveDefaultInitializeKind::kTrivial)
    .value("ARC_STRONG", pasta::QualifiedTypePrimitiveDefaultInitializeKind::kARCStrong)
    .value("ARC_WEAK", pasta::QualifiedTypePrimitiveDefaultInitializeKind::kARCWeak)
    .value("STRUCT", pasta::QualifiedTypePrimitiveDefaultInitializeKind::kStruct);

  nb::enum_<pasta::RISCVInterruptAttrInterruptType>(m, "RISCVInterruptAttrInterruptType")
    .value("USER", pasta::RISCVInterruptAttrInterruptType::kUser)
    .value("SUPERVISOR", pasta::RISCVInterruptAttrInterruptType::kSupervisor)
    .value("MACHINE", pasta::RISCVInterruptAttrInterruptType::kMachine);

  nb::enum_<pasta::RISCVInterruptAttrSpelling>(m, "RISCVInterruptAttrSpelling")
    .value("GNU_INTERRUPT", pasta::RISCVInterruptAttrSpelling::kGNUInterrupt)
    .value("CXX11_GNU_INTERRUPT", pasta::RISCVInterruptAttrSpelling::kCXX11GnuInterrupt)
    .value("C2X_GNU_INTERRUPT", pasta::RISCVInterruptAttrSpelling::kC2xGnuInterrupt)
    .value("SPELLING_NOT_CALCULATED", pasta::RISCVInterruptAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::RandomizeLayoutAttrSpelling>(m, "RandomizeLayoutAttrSpelling")
    .value("GNU_RANDOMIZE_LAYOUT", pasta::RandomizeLayoutAttrSpelling::kGNURandomizeLayout)
    .value("CXX11_GNU_RANDOMIZE_LAYOUT", pasta::RandomizeLayoutAttrSpelling::kCXX11GnuRandomizeLayout)
    .value("C2X_GNU_RANDOMIZE_LAYOUT", pasta::RandomizeLayoutAttrSpelling::kC2xGnuRandomizeLayout)
    .value("SPELLING_NOT_CALCULATED", pasta::RandomizeLayoutAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReadOnlyPlacementAttrSpelling>(m, "ReadOnlyPlacementAttrSpelling")
    .value("GNU_ENFORCE_READ_ONLY_PLACEMENT", pasta::ReadOnlyPlacementAttrSpelling::kGNUEnforceReadOnlyPlacement)
    .value("CXX11_CLANG_ENFORCE_READ_ONLY_PLACEMENT", pasta::ReadOnlyPlacementAttrSpelling::kCXX11ClangEnforceReadOnlyPlacement)
    .value("C2X_CLANG_ENFORCE_READ_ONLY_PLACEMENT", pasta::ReadOnlyPlacementAttrSpelling::kC2xClangEnforceReadOnlyPlacement)
    .value("SPELLING_NOT_CALCULATED", pasta::ReadOnlyPlacementAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::RecordDeclArgPassingKind>(m, "RecordDeclArgPassingKind")
    .value("CAN_PASS_IN_REGS", pasta::RecordDeclArgPassingKind::kCanPassInRegs)
    .value("CANNOT_PASS_IN_REGS", pasta::RecordDeclArgPassingKind::kCannotPassInRegs)
    .value("CAN_NEVER_PASS_IN_REGS", pasta::RecordDeclArgPassingKind::kCanNeverPassInRegs);

  nb::enum_<pasta::RegCallAttrSpelling>(m, "RegCallAttrSpelling")
    .value("GNU_REGCALL", pasta::RegCallAttrSpelling::kGNURegcall)
    .value("CXX11_GNU_REGCALL", pasta::RegCallAttrSpelling::kCXX11GnuRegcall)
    .value("C2X_GNU_REGCALL", pasta::RegCallAttrSpelling::kC2xGnuRegcall)
    .value("KEYWORD_REGCALL", pasta::RegCallAttrSpelling::kKeywordRegcall)
    .value("SPELLING_NOT_CALCULATED", pasta::RegCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReinitializesAttrSpelling>(m, "ReinitializesAttrSpelling")
    .value("GNU_REINITIALIZES", pasta::ReinitializesAttrSpelling::kGNUReinitializes)
    .value("CXX11_CLANG_REINITIALIZES", pasta::ReinitializesAttrSpelling::kCXX11ClangReinitializes)
    .value("SPELLING_NOT_CALCULATED", pasta::ReinitializesAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReleaseCapabilityAttrSpelling>(m, "ReleaseCapabilityAttrSpelling")
    .value("GNU_RELEASE_CAPABILITY", pasta::ReleaseCapabilityAttrSpelling::kGNUReleaseCapability)
    .value("CXX11_CLANG_RELEASE_CAPABILITY", pasta::ReleaseCapabilityAttrSpelling::kCXX11ClangReleaseCapability)
    .value("GNU_RELEASE_SHARED_CAPABILITY", pasta::ReleaseCapabilityAttrSpelling::kGNUReleaseSharedCapability)
    .value("CXX11_CLANG_RELEASE_SHARED_CAPABILITY", pasta::ReleaseCapabilityAttrSpelling::kCXX11ClangReleaseSharedCapability)
    .value("GNU_RELEASE_GENERIC_CAPABILITY", pasta::ReleaseCapabilityAttrSpelling::kGNUReleaseGenericCapability)
    .value("CXX11_CLANG_RELEASE_GENERIC_CAPABILITY", pasta::ReleaseCapabilityAttrSpelling::kCXX11ClangReleaseGenericCapability)
    .value("GNU_UNLOCK_FUNCTION", pasta::ReleaseCapabilityAttrSpelling::kGNUUnlockFunction)
    .value("CXX11_CLANG_UNLOCK_FUNCTION", pasta::ReleaseCapabilityAttrSpelling::kCXX11ClangUnlockFunction)
    .value("SPELLING_NOT_CALCULATED", pasta::ReleaseCapabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReleaseHandleAttrSpelling>(m, "ReleaseHandleAttrSpelling")
    .value("GNU_RELEASE_HANDLE", pasta::ReleaseHandleAttrSpelling::kGNUReleaseHandle)
    .value("CXX11_CLANG_RELEASE_HANDLE", pasta::ReleaseHandleAttrSpelling::kCXX11ClangReleaseHandle)
    .value("C2X_CLANG_RELEASE_HANDLE", pasta::ReleaseHandleAttrSpelling::kC2xClangReleaseHandle)
    .value("SPELLING_NOT_CALCULATED", pasta::ReleaseHandleAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::RequiresCapabilityAttrSpelling>(m, "RequiresCapabilityAttrSpelling")
    .value("GNU_REQUIRES_CAPABILITY", pasta::RequiresCapabilityAttrSpelling::kGNURequiresCapability)
    .value("CXX11_CLANG_REQUIRES_CAPABILITY", pasta::RequiresCapabilityAttrSpelling::kCXX11ClangRequiresCapability)
    .value("GNU_EXCLUSIVE_LOCKS_REQUIRED", pasta::RequiresCapabilityAttrSpelling::kGNUExclusiveLocksRequired)
    .value("CXX11_CLANG_EXCLUSIVE_LOCKS_REQUIRED", pasta::RequiresCapabilityAttrSpelling::kCXX11ClangExclusiveLocksRequired)
    .value("GNU_REQUIRES_SHARED_CAPABILITY", pasta::RequiresCapabilityAttrSpelling::kGNURequiresSharedCapability)
    .value("CXX11_CLANG_REQUIRES_SHARED_CAPABILITY", pasta::RequiresCapabilityAttrSpelling::kCXX11ClangRequiresSharedCapability)
    .value("GNU_SHARED_LOCKS_REQUIRED", pasta::RequiresCapabilityAttrSpelling::kGNUSharedLocksRequired)
    .value("CXX11_CLANG_SHARED_LOCKS_REQUIRED", pasta::RequiresCapabilityAttrSpelling::kCXX11ClangSharedLocksRequired)
    .value("SPELLING_NOT_CALCULATED", pasta::RequiresCapabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::RestrictAttrSpelling>(m, "RestrictAttrSpelling")
    .value("DECLSPEC_RESTRICT", pasta::RestrictAttrSpelling::kDeclspecRestrict)
    .value("GNU_MALLOC", pasta::RestrictAttrSpelling::kGNUMalloc)
    .value("CXX11_GNU_MALLOC", pasta::RestrictAttrSpelling::kCXX11GnuMalloc)
    .value("C2X_GNU_MALLOC", pasta::RestrictAttrSpelling::kC2xGnuMalloc)
    .value("SPELLING_NOT_CALCULATED", pasta::RestrictAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::RetainAttrSpelling>(m, "RetainAttrSpelling")
    .value("GNU_RETAIN", pasta::RetainAttrSpelling::kGNURetain)
    .value("CXX11_GNU_RETAIN", pasta::RetainAttrSpelling::kCXX11GnuRetain)
    .value("C2X_GNU_RETAIN", pasta::RetainAttrSpelling::kC2xGnuRetain)
    .value("SPELLING_NOT_CALCULATED", pasta::RetainAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReturnTypestateAttrConsumedState>(m, "ReturnTypestateAttrConsumedState")
    .value("UNKNOWN", pasta::ReturnTypestateAttrConsumedState::kUnknown)
    .value("CONSUMED", pasta::ReturnTypestateAttrConsumedState::kConsumed)
    .value("UNCONSUMED", pasta::ReturnTypestateAttrConsumedState::kUnconsumed);

  nb::enum_<pasta::ReturnTypestateAttrSpelling>(m, "ReturnTypestateAttrSpelling")
    .value("GNU_RETURN_TYPESTATE", pasta::ReturnTypestateAttrSpelling::kGNUReturnTypestate)
    .value("CXX11_CLANG_RETURN_TYPESTATE", pasta::ReturnTypestateAttrSpelling::kCXX11ClangReturnTypestate)
    .value("SPELLING_NOT_CALCULATED", pasta::ReturnTypestateAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReturnsNonNullAttrSpelling>(m, "ReturnsNonNullAttrSpelling")
    .value("GNU_RETURNS_NONNULL", pasta::ReturnsNonNullAttrSpelling::kGNUReturnsNonnull)
    .value("CXX11_GNU_RETURNS_NONNULL", pasta::ReturnsNonNullAttrSpelling::kCXX11GnuReturnsNonnull)
    .value("C2X_GNU_RETURNS_NONNULL", pasta::ReturnsNonNullAttrSpelling::kC2xGnuReturnsNonnull)
    .value("SPELLING_NOT_CALCULATED", pasta::ReturnsNonNullAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ReturnsTwiceAttrSpelling>(m, "ReturnsTwiceAttrSpelling")
    .value("GNU_RETURNS_TWICE", pasta::ReturnsTwiceAttrSpelling::kGNUReturnsTwice)
    .value("CXX11_GNU_RETURNS_TWICE", pasta::ReturnsTwiceAttrSpelling::kCXX11GnuReturnsTwice)
    .value("C2X_GNU_RETURNS_TWICE", pasta::ReturnsTwiceAttrSpelling::kC2xGnuReturnsTwice)
    .value("SPELLING_NOT_CALCULATED", pasta::ReturnsTwiceAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SYCLKernelAttrSpelling>(m, "SYCLKernelAttrSpelling")
    .value("GNU_SYCL_KERNEL", pasta::SYCLKernelAttrSpelling::kGNUSyclKernel)
    .value("CXX11_CLANG_SYCL_KERNEL", pasta::SYCLKernelAttrSpelling::kCXX11ClangSyclKernel)
    .value("C2X_CLANG_SYCL_KERNEL", pasta::SYCLKernelAttrSpelling::kC2xClangSyclKernel)
    .value("SPELLING_NOT_CALCULATED", pasta::SYCLKernelAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SYCLSpecialClassAttrSpelling>(m, "SYCLSpecialClassAttrSpelling")
    .value("GNU_SYCL_SPECIAL_CLASS", pasta::SYCLSpecialClassAttrSpelling::kGNUSyclSpecialClass)
    .value("CXX11_CLANG_SYCL_SPECIAL_CLASS", pasta::SYCLSpecialClassAttrSpelling::kCXX11ClangSyclSpecialClass)
    .value("C2X_CLANG_SYCL_SPECIAL_CLASS", pasta::SYCLSpecialClassAttrSpelling::kC2xClangSyclSpecialClass)
    .value("SPELLING_NOT_CALCULATED", pasta::SYCLSpecialClassAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ScopedLockableAttrSpelling>(m, "ScopedLockableAttrSpelling")
    .value("GNU_SCOPED_LOCKABLE", pasta::ScopedLockableAttrSpelling::kGNUScopedLockable)
    .value("CXX11_CLANG_SCOPED_LOCKABLE", pasta::ScopedLockableAttrSpelling::kCXX11ClangScopedLockable)
    .value("SPELLING_NOT_CALCULATED", pasta::ScopedLockableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SectionAttrSpelling>(m, "SectionAttrSpelling")
    .value("GNU_SECTION", pasta::SectionAttrSpelling::kGNUSection)
    .value("CXX11_GNU_SECTION", pasta::SectionAttrSpelling::kCXX11GnuSection)
    .value("C2X_GNU_SECTION", pasta::SectionAttrSpelling::kC2xGnuSection)
    .value("DECLSPEC_ALLOCATE", pasta::SectionAttrSpelling::kDeclspecAllocate)
    .value("SPELLING_NOT_CALCULATED", pasta::SectionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SelectAnyAttrSpelling>(m, "SelectAnyAttrSpelling")
    .value("DECLSPEC_SELECTANY", pasta::SelectAnyAttrSpelling::kDeclspecSelectany)
    .value("GNU_SELECTANY", pasta::SelectAnyAttrSpelling::kGNUSelectany)
    .value("CXX11_GNU_SELECTANY", pasta::SelectAnyAttrSpelling::kCXX11GnuSelectany)
    .value("C2X_GNU_SELECTANY", pasta::SelectAnyAttrSpelling::kC2xGnuSelectany)
    .value("SPELLING_NOT_CALCULATED", pasta::SelectAnyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SentinelAttrSpelling>(m, "SentinelAttrSpelling")
    .value("GNU_SENTINEL", pasta::SentinelAttrSpelling::kGNUSentinel)
    .value("CXX11_GNU_SENTINEL", pasta::SentinelAttrSpelling::kCXX11GnuSentinel)
    .value("C2X_GNU_SENTINEL", pasta::SentinelAttrSpelling::kC2xGnuSentinel)
    .value("SPELLING_NOT_CALCULATED", pasta::SentinelAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SetTypestateAttrConsumedState>(m, "SetTypestateAttrConsumedState")
    .value("UNKNOWN", pasta::SetTypestateAttrConsumedState::kUnknown)
    .value("CONSUMED", pasta::SetTypestateAttrConsumedState::kConsumed)
    .value("UNCONSUMED", pasta::SetTypestateAttrConsumedState::kUnconsumed);

  nb::enum_<pasta::SetTypestateAttrSpelling>(m, "SetTypestateAttrSpelling")
    .value("GNU_TYPESTATE", pasta::SetTypestateAttrSpelling::kGNUTypestate)
    .value("CXX11_CLANG_TYPESTATE", pasta::SetTypestateAttrSpelling::kCXX11ClangTypestate)
    .value("SPELLING_NOT_CALCULATED", pasta::SetTypestateAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SourceLocExprIdentKind>(m, "SourceLocExprIdentKind")
    .value("FUNCTION", pasta::SourceLocExprIdentKind::kFunction)
    .value("FILE", pasta::SourceLocExprIdentKind::kFile)
    .value("LINE", pasta::SourceLocExprIdentKind::kLine)
    .value("COLUMN", pasta::SourceLocExprIdentKind::kColumn)
    .value("SOURCE_TOKEN_STRUCT", pasta::SourceLocExprIdentKind::kSourceTokenStruct);

  nb::enum_<pasta::SpeculativeLoadHardeningAttrSpelling>(m, "SpeculativeLoadHardeningAttrSpelling")
    .value("GNU_SPECULATIVE_LOAD_HARDENING", pasta::SpeculativeLoadHardeningAttrSpelling::kGNUSpeculativeLoadHardening)
    .value("CXX11_CLANG_SPECULATIVE_LOAD_HARDENING", pasta::SpeculativeLoadHardeningAttrSpelling::kCXX11ClangSpeculativeLoadHardening)
    .value("C2X_CLANG_SPECULATIVE_LOAD_HARDENING", pasta::SpeculativeLoadHardeningAttrSpelling::kC2xClangSpeculativeLoadHardening)
    .value("SPELLING_NOT_CALCULATED", pasta::SpeculativeLoadHardeningAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::StandaloneDebugAttrSpelling>(m, "StandaloneDebugAttrSpelling")
    .value("GNU_STANDALONE_DEBUG", pasta::StandaloneDebugAttrSpelling::kGNUStandaloneDebug)
    .value("CXX11_CLANG_STANDALONE_DEBUG", pasta::StandaloneDebugAttrSpelling::kCXX11ClangStandaloneDebug)
    .value("SPELLING_NOT_CALCULATED", pasta::StandaloneDebugAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::StdCallAttrSpelling>(m, "StdCallAttrSpelling")
    .value("GNU_STDCALL", pasta::StdCallAttrSpelling::kGNUStdcall)
    .value("CXX11_GNU_STDCALL", pasta::StdCallAttrSpelling::kCXX11GnuStdcall)
    .value("C2X_GNU_STDCALL", pasta::StdCallAttrSpelling::kC2xGnuStdcall)
    .value("KEYWORD_STDCALL", pasta::StdCallAttrSpelling::kKeywordStdcall)
    .value("SPELLING_NOT_CALCULATED", pasta::StdCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::StmtLikelihood>(m, "StmtLikelihood")
    .value("UNLIKELY", pasta::StmtLikelihood::kUnlikely)
    .value("NONE", pasta::StmtLikelihood::kNone)
    .value("LIKELY", pasta::StmtLikelihood::kLikely);

  nb::enum_<pasta::StmtKind>(m, "StmtKind")
    .value("GCC_ASM_STMT", pasta::StmtKind::kGCCAsmStmt)
    .value("MS_ASM_STMT", pasta::StmtKind::kMSAsmStmt)
    .value("BREAK_STMT", pasta::StmtKind::kBreakStmt)
    .value("CXX_CATCH_STMT", pasta::StmtKind::kCXXCatchStmt)
    .value("CXX_FOR_RANGE_STMT", pasta::StmtKind::kCXXForRangeStmt)
    .value("CXX_TRY_STMT", pasta::StmtKind::kCXXTryStmt)
    .value("CAPTURED_STMT", pasta::StmtKind::kCapturedStmt)
    .value("COMPOUND_STMT", pasta::StmtKind::kCompoundStmt)
    .value("CONTINUE_STMT", pasta::StmtKind::kContinueStmt)
    .value("CORETURN_STMT", pasta::StmtKind::kCoreturnStmt)
    .value("COROUTINE_BODY_STMT", pasta::StmtKind::kCoroutineBodyStmt)
    .value("DECL_STMT", pasta::StmtKind::kDeclStmt)
    .value("DO_STMT", pasta::StmtKind::kDoStmt)
    .value("FOR_STMT", pasta::StmtKind::kForStmt)
    .value("GOTO_STMT", pasta::StmtKind::kGotoStmt)
    .value("IF_STMT", pasta::StmtKind::kIfStmt)
    .value("INDIRECT_GOTO_STMT", pasta::StmtKind::kIndirectGotoStmt)
    .value("MS_DEPENDENT_EXISTS_STMT", pasta::StmtKind::kMSDependentExistsStmt)
    .value("NULL_STMT", pasta::StmtKind::kNullStmt)
    .value("OMP_CANONICAL_LOOP", pasta::StmtKind::kOMPCanonicalLoop)
    .value("OMP_ATOMIC_DIRECTIVE", pasta::StmtKind::kOMPAtomicDirective)
    .value("OMP_BARRIER_DIRECTIVE", pasta::StmtKind::kOMPBarrierDirective)
    .value("OMP_CANCEL_DIRECTIVE", pasta::StmtKind::kOMPCancelDirective)
    .value("OMP_CANCELLATION_POINT_DIRECTIVE", pasta::StmtKind::kOMPCancellationPointDirective)
    .value("OMP_CRITICAL_DIRECTIVE", pasta::StmtKind::kOMPCriticalDirective)
    .value("OMP_DEPOBJ_DIRECTIVE", pasta::StmtKind::kOMPDepobjDirective)
    .value("OMP_DISPATCH_DIRECTIVE", pasta::StmtKind::kOMPDispatchDirective)
    .value("OMP_ERROR_DIRECTIVE", pasta::StmtKind::kOMPErrorDirective)
    .value("OMP_FLUSH_DIRECTIVE", pasta::StmtKind::kOMPFlushDirective)
    .value("OMP_INTEROP_DIRECTIVE", pasta::StmtKind::kOMPInteropDirective)
    .value("OMP_DISTRIBUTE_DIRECTIVE", pasta::StmtKind::kOMPDistributeDirective)
    .value("OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE", pasta::StmtKind::kOMPDistributeParallelForDirective)
    .value("OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE", pasta::StmtKind::kOMPDistributeParallelForSimdDirective)
    .value("OMP_DISTRIBUTE_SIMD_DIRECTIVE", pasta::StmtKind::kOMPDistributeSimdDirective)
    .value("OMP_FOR_DIRECTIVE", pasta::StmtKind::kOMPForDirective)
    .value("OMP_FOR_SIMD_DIRECTIVE", pasta::StmtKind::kOMPForSimdDirective)
    .value("OMP_GENERIC_LOOP_DIRECTIVE", pasta::StmtKind::kOMPGenericLoopDirective)
    .value("OMP_MASKED_TASK_LOOP_DIRECTIVE", pasta::StmtKind::kOMPMaskedTaskLoopDirective)
    .value("OMP_MASKED_TASK_LOOP_SIMD_DIRECTIVE", pasta::StmtKind::kOMPMaskedTaskLoopSimdDirective)
    .value("OMP_MASTER_TASK_LOOP_DIRECTIVE", pasta::StmtKind::kOMPMasterTaskLoopDirective)
    .value("OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE", pasta::StmtKind::kOMPMasterTaskLoopSimdDirective)
    .value("OMP_PARALLEL_FOR_DIRECTIVE", pasta::StmtKind::kOMPParallelForDirective)
    .value("OMP_PARALLEL_FOR_SIMD_DIRECTIVE", pasta::StmtKind::kOMPParallelForSimdDirective)
    .value("OMP_PARALLEL_GENERIC_LOOP_DIRECTIVE", pasta::StmtKind::kOMPParallelGenericLoopDirective)
    .value("OMP_PARALLEL_MASKED_TASK_LOOP_DIRECTIVE", pasta::StmtKind::kOMPParallelMaskedTaskLoopDirective)
    .value("OMP_PARALLEL_MASKED_TASK_LOOP_SIMD_DIRECTIVE", pasta::StmtKind::kOMPParallelMaskedTaskLoopSimdDirective)
    .value("OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE", pasta::StmtKind::kOMPParallelMasterTaskLoopDirective)
    .value("OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE", pasta::StmtKind::kOMPParallelMasterTaskLoopSimdDirective)
    .value("OMP_SIMD_DIRECTIVE", pasta::StmtKind::kOMPSimdDirective)
    .value("OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTargetParallelForSimdDirective)
    .value("OMP_TARGET_PARALLEL_GENERIC_LOOP_DIRECTIVE", pasta::StmtKind::kOMPTargetParallelGenericLoopDirective)
    .value("OMP_TARGET_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTargetSimdDirective)
    .value("OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE", pasta::StmtKind::kOMPTargetTeamsDistributeDirective)
    .value("OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE", pasta::StmtKind::kOMPTargetTeamsDistributeParallelForDirective)
    .value("OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTargetTeamsDistributeParallelForSimdDirective)
    .value("OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTargetTeamsDistributeSimdDirective)
    .value("OMP_TARGET_TEAMS_GENERIC_LOOP_DIRECTIVE", pasta::StmtKind::kOMPTargetTeamsGenericLoopDirective)
    .value("OMP_TASK_LOOP_DIRECTIVE", pasta::StmtKind::kOMPTaskLoopDirective)
    .value("OMP_TASK_LOOP_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTaskLoopSimdDirective)
    .value("OMP_TEAMS_DISTRIBUTE_DIRECTIVE", pasta::StmtKind::kOMPTeamsDistributeDirective)
    .value("OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE", pasta::StmtKind::kOMPTeamsDistributeParallelForDirective)
    .value("OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTeamsDistributeParallelForSimdDirective)
    .value("OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE", pasta::StmtKind::kOMPTeamsDistributeSimdDirective)
    .value("OMP_TEAMS_GENERIC_LOOP_DIRECTIVE", pasta::StmtKind::kOMPTeamsGenericLoopDirective)
    .value("OMP_TILE_DIRECTIVE", pasta::StmtKind::kOMPTileDirective)
    .value("OMP_UNROLL_DIRECTIVE", pasta::StmtKind::kOMPUnrollDirective)
    .value("OMP_MASKED_DIRECTIVE", pasta::StmtKind::kOMPMaskedDirective)
    .value("OMP_MASTER_DIRECTIVE", pasta::StmtKind::kOMPMasterDirective)
    .value("OMP_META_DIRECTIVE", pasta::StmtKind::kOMPMetaDirective)
    .value("OMP_ORDERED_DIRECTIVE", pasta::StmtKind::kOMPOrderedDirective)
    .value("OMP_PARALLEL_DIRECTIVE", pasta::StmtKind::kOMPParallelDirective)
    .value("OMP_PARALLEL_MASKED_DIRECTIVE", pasta::StmtKind::kOMPParallelMaskedDirective)
    .value("OMP_PARALLEL_MASTER_DIRECTIVE", pasta::StmtKind::kOMPParallelMasterDirective)
    .value("OMP_PARALLEL_SECTIONS_DIRECTIVE", pasta::StmtKind::kOMPParallelSectionsDirective)
    .value("OMP_SCAN_DIRECTIVE", pasta::StmtKind::kOMPScanDirective)
    .value("OMP_SECTION_DIRECTIVE", pasta::StmtKind::kOMPSectionDirective)
    .value("OMP_SECTIONS_DIRECTIVE", pasta::StmtKind::kOMPSectionsDirective)
    .value("OMP_SINGLE_DIRECTIVE", pasta::StmtKind::kOMPSingleDirective)
    .value("OMP_TARGET_DATA_DIRECTIVE", pasta::StmtKind::kOMPTargetDataDirective)
    .value("OMP_TARGET_DIRECTIVE", pasta::StmtKind::kOMPTargetDirective)
    .value("OMP_TARGET_ENTER_DATA_DIRECTIVE", pasta::StmtKind::kOMPTargetEnterDataDirective)
    .value("OMP_TARGET_EXIT_DATA_DIRECTIVE", pasta::StmtKind::kOMPTargetExitDataDirective)
    .value("OMP_TARGET_PARALLEL_DIRECTIVE", pasta::StmtKind::kOMPTargetParallelDirective)
    .value("OMP_TARGET_PARALLEL_FOR_DIRECTIVE", pasta::StmtKind::kOMPTargetParallelForDirective)
    .value("OMP_TARGET_TEAMS_DIRECTIVE", pasta::StmtKind::kOMPTargetTeamsDirective)
    .value("OMP_TARGET_UPDATE_DIRECTIVE", pasta::StmtKind::kOMPTargetUpdateDirective)
    .value("OMP_TASK_DIRECTIVE", pasta::StmtKind::kOMPTaskDirective)
    .value("OMP_TASKGROUP_DIRECTIVE", pasta::StmtKind::kOMPTaskgroupDirective)
    .value("OMP_TASKWAIT_DIRECTIVE", pasta::StmtKind::kOMPTaskwaitDirective)
    .value("OMP_TASKYIELD_DIRECTIVE", pasta::StmtKind::kOMPTaskyieldDirective)
    .value("OMP_TEAMS_DIRECTIVE", pasta::StmtKind::kOMPTeamsDirective)
    .value("OBJ_C_AT_CATCH_STMT", pasta::StmtKind::kObjCAtCatchStmt)
    .value("OBJ_C_AT_FINALLY_STMT", pasta::StmtKind::kObjCAtFinallyStmt)
    .value("OBJ_C_AT_SYNCHRONIZED_STMT", pasta::StmtKind::kObjCAtSynchronizedStmt)
    .value("OBJ_C_AT_THROW_STMT", pasta::StmtKind::kObjCAtThrowStmt)
    .value("OBJ_C_AT_TRY_STMT", pasta::StmtKind::kObjCAtTryStmt)
    .value("OBJ_C_AUTORELEASE_POOL_STMT", pasta::StmtKind::kObjCAutoreleasePoolStmt)
    .value("OBJ_C_FOR_COLLECTION_STMT", pasta::StmtKind::kObjCForCollectionStmt)
    .value("RETURN_STMT", pasta::StmtKind::kReturnStmt)
    .value("SEH_EXCEPT_STMT", pasta::StmtKind::kSEHExceptStmt)
    .value("SEH_FINALLY_STMT", pasta::StmtKind::kSEHFinallyStmt)
    .value("SEH_LEAVE_STMT", pasta::StmtKind::kSEHLeaveStmt)
    .value("SEH_TRY_STMT", pasta::StmtKind::kSEHTryStmt)
    .value("CASE_STMT", pasta::StmtKind::kCaseStmt)
    .value("DEFAULT_STMT", pasta::StmtKind::kDefaultStmt)
    .value("SWITCH_STMT", pasta::StmtKind::kSwitchStmt)
    .value("ATTRIBUTED_STMT", pasta::StmtKind::kAttributedStmt)
    .value("BINARY_CONDITIONAL_OPERATOR", pasta::StmtKind::kBinaryConditionalOperator)
    .value("CONDITIONAL_OPERATOR", pasta::StmtKind::kConditionalOperator)
    .value("ADDR_LABEL_EXPR", pasta::StmtKind::kAddrLabelExpr)
    .value("ARRAY_INIT_INDEX_EXPR", pasta::StmtKind::kArrayInitIndexExpr)
    .value("ARRAY_INIT_LOOP_EXPR", pasta::StmtKind::kArrayInitLoopExpr)
    .value("ARRAY_SUBSCRIPT_EXPR", pasta::StmtKind::kArraySubscriptExpr)
    .value("ARRAY_TYPE_TRAIT_EXPR", pasta::StmtKind::kArrayTypeTraitExpr)
    .value("AS_TYPE_EXPR", pasta::StmtKind::kAsTypeExpr)
    .value("ATOMIC_EXPR", pasta::StmtKind::kAtomicExpr)
    .value("BINARY_OPERATOR", pasta::StmtKind::kBinaryOperator)
    .value("COMPOUND_ASSIGN_OPERATOR", pasta::StmtKind::kCompoundAssignOperator)
    .value("BLOCK_EXPR", pasta::StmtKind::kBlockExpr)
    .value("CXX_BIND_TEMPORARY_EXPR", pasta::StmtKind::kCXXBindTemporaryExpr)
    .value("CXX_BOOL_LITERAL_EXPR", pasta::StmtKind::kCXXBoolLiteralExpr)
    .value("CXX_CONSTRUCT_EXPR", pasta::StmtKind::kCXXConstructExpr)
    .value("CXX_TEMPORARY_OBJECT_EXPR", pasta::StmtKind::kCXXTemporaryObjectExpr)
    .value("CXX_DEFAULT_ARG_EXPR", pasta::StmtKind::kCXXDefaultArgExpr)
    .value("CXX_DEFAULT_INIT_EXPR", pasta::StmtKind::kCXXDefaultInitExpr)
    .value("CXX_DELETE_EXPR", pasta::StmtKind::kCXXDeleteExpr)
    .value("CXX_DEPENDENT_SCOPE_MEMBER_EXPR", pasta::StmtKind::kCXXDependentScopeMemberExpr)
    .value("CXX_FOLD_EXPR", pasta::StmtKind::kCXXFoldExpr)
    .value("CXX_INHERITED_CTOR_INIT_EXPR", pasta::StmtKind::kCXXInheritedCtorInitExpr)
    .value("CXX_NEW_EXPR", pasta::StmtKind::kCXXNewExpr)
    .value("CXX_NOEXCEPT_EXPR", pasta::StmtKind::kCXXNoexceptExpr)
    .value("CXX_NULL_PTR_LITERAL_EXPR", pasta::StmtKind::kCXXNullPtrLiteralExpr)
    .value("CXX_PAREN_LIST_INIT_EXPR", pasta::StmtKind::kCXXParenListInitExpr)
    .value("CXX_PSEUDO_DESTRUCTOR_EXPR", pasta::StmtKind::kCXXPseudoDestructorExpr)
    .value("CXX_REWRITTEN_BINARY_OPERATOR", pasta::StmtKind::kCXXRewrittenBinaryOperator)
    .value("CXX_SCALAR_VALUE_INIT_EXPR", pasta::StmtKind::kCXXScalarValueInitExpr)
    .value("CXX_STD_INITIALIZER_LIST_EXPR", pasta::StmtKind::kCXXStdInitializerListExpr)
    .value("CXX_THIS_EXPR", pasta::StmtKind::kCXXThisExpr)
    .value("CXX_THROW_EXPR", pasta::StmtKind::kCXXThrowExpr)
    .value("CXX_TYPEID_EXPR", pasta::StmtKind::kCXXTypeidExpr)
    .value("CXX_UNRESOLVED_CONSTRUCT_EXPR", pasta::StmtKind::kCXXUnresolvedConstructExpr)
    .value("CXX_UUIDOF_EXPR", pasta::StmtKind::kCXXUuidofExpr)
    .value("CALL_EXPR", pasta::StmtKind::kCallExpr)
    .value("CUDA_KERNEL_CALL_EXPR", pasta::StmtKind::kCUDAKernelCallExpr)
    .value("CXX_MEMBER_CALL_EXPR", pasta::StmtKind::kCXXMemberCallExpr)
    .value("CXX_OPERATOR_CALL_EXPR", pasta::StmtKind::kCXXOperatorCallExpr)
    .value("USER_DEFINED_LITERAL", pasta::StmtKind::kUserDefinedLiteral)
    .value("BUILTIN_BIT_CAST_EXPR", pasta::StmtKind::kBuiltinBitCastExpr)
    .value("C_STYLE_CAST_EXPR", pasta::StmtKind::kCStyleCastExpr)
    .value("CXX_FUNCTIONAL_CAST_EXPR", pasta::StmtKind::kCXXFunctionalCastExpr)
    .value("CXX_ADDRSPACE_CAST_EXPR", pasta::StmtKind::kCXXAddrspaceCastExpr)
    .value("CXX_CONST_CAST_EXPR", pasta::StmtKind::kCXXConstCastExpr)
    .value("CXX_DYNAMIC_CAST_EXPR", pasta::StmtKind::kCXXDynamicCastExpr)
    .value("CXX_REINTERPRET_CAST_EXPR", pasta::StmtKind::kCXXReinterpretCastExpr)
    .value("CXX_STATIC_CAST_EXPR", pasta::StmtKind::kCXXStaticCastExpr)
    .value("OBJ_C_BRIDGED_CAST_EXPR", pasta::StmtKind::kObjCBridgedCastExpr)
    .value("IMPLICIT_CAST_EXPR", pasta::StmtKind::kImplicitCastExpr)
    .value("CHARACTER_LITERAL", pasta::StmtKind::kCharacterLiteral)
    .value("CHOOSE_EXPR", pasta::StmtKind::kChooseExpr)
    .value("COMPOUND_LITERAL_EXPR", pasta::StmtKind::kCompoundLiteralExpr)
    .value("CONCEPT_SPECIALIZATION_EXPR", pasta::StmtKind::kConceptSpecializationExpr)
    .value("CONVERT_VECTOR_EXPR", pasta::StmtKind::kConvertVectorExpr)
    .value("COAWAIT_EXPR", pasta::StmtKind::kCoawaitExpr)
    .value("COYIELD_EXPR", pasta::StmtKind::kCoyieldExpr)
    .value("DECL_REF_EXPR", pasta::StmtKind::kDeclRefExpr)
    .value("DEPENDENT_COAWAIT_EXPR", pasta::StmtKind::kDependentCoawaitExpr)
    .value("DEPENDENT_SCOPE_DECL_REF_EXPR", pasta::StmtKind::kDependentScopeDeclRefExpr)
    .value("DESIGNATED_INIT_EXPR", pasta::StmtKind::kDesignatedInitExpr)
    .value("DESIGNATED_INIT_UPDATE_EXPR", pasta::StmtKind::kDesignatedInitUpdateExpr)
    .value("EXPRESSION_TRAIT_EXPR", pasta::StmtKind::kExpressionTraitExpr)
    .value("EXT_VECTOR_ELEMENT_EXPR", pasta::StmtKind::kExtVectorElementExpr)
    .value("FIXED_POINT_LITERAL", pasta::StmtKind::kFixedPointLiteral)
    .value("FLOATING_LITERAL", pasta::StmtKind::kFloatingLiteral)
    .value("CONSTANT_EXPR", pasta::StmtKind::kConstantExpr)
    .value("EXPR_WITH_CLEANUPS", pasta::StmtKind::kExprWithCleanups)
    .value("FUNCTION_PARM_PACK_EXPR", pasta::StmtKind::kFunctionParmPackExpr)
    .value("GNU_NULL_EXPR", pasta::StmtKind::kGNUNullExpr)
    .value("GENERIC_SELECTION_EXPR", pasta::StmtKind::kGenericSelectionExpr)
    .value("IMAGINARY_LITERAL", pasta::StmtKind::kImaginaryLiteral)
    .value("IMPLICIT_VALUE_INIT_EXPR", pasta::StmtKind::kImplicitValueInitExpr)
    .value("INIT_LIST_EXPR", pasta::StmtKind::kInitListExpr)
    .value("INTEGER_LITERAL", pasta::StmtKind::kIntegerLiteral)
    .value("LAMBDA_EXPR", pasta::StmtKind::kLambdaExpr)
    .value("MS_PROPERTY_REF_EXPR", pasta::StmtKind::kMSPropertyRefExpr)
    .value("MS_PROPERTY_SUBSCRIPT_EXPR", pasta::StmtKind::kMSPropertySubscriptExpr)
    .value("MATERIALIZE_TEMPORARY_EXPR", pasta::StmtKind::kMaterializeTemporaryExpr)
    .value("MATRIX_SUBSCRIPT_EXPR", pasta::StmtKind::kMatrixSubscriptExpr)
    .value("MEMBER_EXPR", pasta::StmtKind::kMemberExpr)
    .value("NO_INIT_EXPR", pasta::StmtKind::kNoInitExpr)
    .value("OMP_ARRAY_SECTION_EXPR", pasta::StmtKind::kOMPArraySectionExpr)
    .value("OMP_ARRAY_SHAPING_EXPR", pasta::StmtKind::kOMPArrayShapingExpr)
    .value("OMP_ITERATOR_EXPR", pasta::StmtKind::kOMPIteratorExpr)
    .value("OBJ_C_ARRAY_LITERAL", pasta::StmtKind::kObjCArrayLiteral)
    .value("OBJ_C_AVAILABILITY_CHECK_EXPR", pasta::StmtKind::kObjCAvailabilityCheckExpr)
    .value("OBJ_C_BOOL_LITERAL_EXPR", pasta::StmtKind::kObjCBoolLiteralExpr)
    .value("OBJ_C_BOXED_EXPR", pasta::StmtKind::kObjCBoxedExpr)
    .value("OBJ_C_DICTIONARY_LITERAL", pasta::StmtKind::kObjCDictionaryLiteral)
    .value("OBJ_C_ENCODE_EXPR", pasta::StmtKind::kObjCEncodeExpr)
    .value("OBJ_C_INDIRECT_COPY_RESTORE_EXPR", pasta::StmtKind::kObjCIndirectCopyRestoreExpr)
    .value("OBJ_C_ISA_EXPR", pasta::StmtKind::kObjCIsaExpr)
    .value("OBJ_C_IVAR_REF_EXPR", pasta::StmtKind::kObjCIvarRefExpr)
    .value("OBJ_C_MESSAGE_EXPR", pasta::StmtKind::kObjCMessageExpr)
    .value("OBJ_C_PROPERTY_REF_EXPR", pasta::StmtKind::kObjCPropertyRefExpr)
    .value("OBJ_C_PROTOCOL_EXPR", pasta::StmtKind::kObjCProtocolExpr)
    .value("OBJ_C_SELECTOR_EXPR", pasta::StmtKind::kObjCSelectorExpr)
    .value("OBJ_C_STRING_LITERAL", pasta::StmtKind::kObjCStringLiteral)
    .value("OBJ_C_SUBSCRIPT_REF_EXPR", pasta::StmtKind::kObjCSubscriptRefExpr)
    .value("OFFSET_OF_EXPR", pasta::StmtKind::kOffsetOfExpr)
    .value("OPAQUE_VALUE_EXPR", pasta::StmtKind::kOpaqueValueExpr)
    .value("UNRESOLVED_LOOKUP_EXPR", pasta::StmtKind::kUnresolvedLookupExpr)
    .value("UNRESOLVED_MEMBER_EXPR", pasta::StmtKind::kUnresolvedMemberExpr)
    .value("PACK_EXPANSION_EXPR", pasta::StmtKind::kPackExpansionExpr)
    .value("PAREN_EXPR", pasta::StmtKind::kParenExpr)
    .value("PAREN_LIST_EXPR", pasta::StmtKind::kParenListExpr)
    .value("PREDEFINED_EXPR", pasta::StmtKind::kPredefinedExpr)
    .value("PSEUDO_OBJECT_EXPR", pasta::StmtKind::kPseudoObjectExpr)
    .value("RECOVERY_EXPR", pasta::StmtKind::kRecoveryExpr)
    .value("REQUIRES_EXPR", pasta::StmtKind::kRequiresExpr)
    .value("SYCL_UNIQUE_STABLE_NAME_EXPR", pasta::StmtKind::kSYCLUniqueStableNameExpr)
    .value("SHUFFLE_VECTOR_EXPR", pasta::StmtKind::kShuffleVectorExpr)
    .value("SIZE_OF_PACK_EXPR", pasta::StmtKind::kSizeOfPackExpr)
    .value("SOURCE_LOC_EXPR", pasta::StmtKind::kSourceLocExpr)
    .value("STMT_EXPR", pasta::StmtKind::kStmtExpr)
    .value("STRING_LITERAL", pasta::StmtKind::kStringLiteral)
    .value("SUBST_NON_TYPE_TEMPLATE_PARM_EXPR", pasta::StmtKind::kSubstNonTypeTemplateParmExpr)
    .value("SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR", pasta::StmtKind::kSubstNonTypeTemplateParmPackExpr)
    .value("TYPE_TRAIT_EXPR", pasta::StmtKind::kTypeTraitExpr)
    .value("TYPO_EXPR", pasta::StmtKind::kTypoExpr)
    .value("UNARY_EXPR_OR_TYPE_TRAIT_EXPR", pasta::StmtKind::kUnaryExprOrTypeTraitExpr)
    .value("UNARY_OPERATOR", pasta::StmtKind::kUnaryOperator)
    .value("VA_ARG_EXPR", pasta::StmtKind::kVAArgExpr)
    .value("LABEL_STMT", pasta::StmtKind::kLabelStmt)
    .value("WHILE_STMT", pasta::StmtKind::kWhileStmt);

  nb::enum_<pasta::StringLiteralStringKind>(m, "StringLiteralStringKind")
    .value("ORDINARY", pasta::StringLiteralStringKind::kOrdinary)
    .value("WIDE", pasta::StringLiteralStringKind::kWide)
    .value("UTF8", pasta::StringLiteralStringKind::kUTF8)
    .value("UTF16", pasta::StringLiteralStringKind::kUTF16)
    .value("UTF32", pasta::StringLiteralStringKind::kUTF32);

  nb::enum_<pasta::SwiftAsyncAttrKind>(m, "SwiftAsyncAttrKind")
    .value("NONE", pasta::SwiftAsyncAttrKind::kNone)
    .value("SWIFT_PRIVATE", pasta::SwiftAsyncAttrKind::kSwiftPrivate)
    .value("NOT_SWIFT_PRIVATE", pasta::SwiftAsyncAttrKind::kNotSwiftPrivate);

  nb::enum_<pasta::SwiftAsyncAttrSpelling>(m, "SwiftAsyncAttrSpelling")
    .value("GNU_SWIFT_ASYNC", pasta::SwiftAsyncAttrSpelling::kGNUSwiftAsync)
    .value("CXX11_CLANG_SWIFT_ASYNC", pasta::SwiftAsyncAttrSpelling::kCXX11ClangSwiftAsync)
    .value("C2X_CLANG_SWIFT_ASYNC", pasta::SwiftAsyncAttrSpelling::kC2xClangSwiftAsync)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftAsyncAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftAsyncCallAttrSpelling>(m, "SwiftAsyncCallAttrSpelling")
    .value("GNU_SWIFTASYNCCALL", pasta::SwiftAsyncCallAttrSpelling::kGNUSwiftasynccall)
    .value("CXX11_CLANG_SWIFTASYNCCALL", pasta::SwiftAsyncCallAttrSpelling::kCXX11ClangSwiftasynccall)
    .value("C2X_CLANG_SWIFTASYNCCALL", pasta::SwiftAsyncCallAttrSpelling::kC2xClangSwiftasynccall)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftAsyncCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftAsyncContextAttrSpelling>(m, "SwiftAsyncContextAttrSpelling")
    .value("GNU_SWIFT_ASYNC_CONTEXT", pasta::SwiftAsyncContextAttrSpelling::kGNUSwiftAsyncContext)
    .value("CXX11_CLANG_SWIFT_ASYNC_CONTEXT", pasta::SwiftAsyncContextAttrSpelling::kCXX11ClangSwiftAsyncContext)
    .value("C2X_CLANG_SWIFT_ASYNC_CONTEXT", pasta::SwiftAsyncContextAttrSpelling::kC2xClangSwiftAsyncContext)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftAsyncContextAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftAsyncErrorAttrConventionKind>(m, "SwiftAsyncErrorAttrConventionKind")
    .value("NONE", pasta::SwiftAsyncErrorAttrConventionKind::kNone)
    .value("NON_NULL_ERROR", pasta::SwiftAsyncErrorAttrConventionKind::kNonNullError)
    .value("ZERO_ARGUMENT", pasta::SwiftAsyncErrorAttrConventionKind::kZeroArgument)
    .value("NON_ZERO_ARGUMENT", pasta::SwiftAsyncErrorAttrConventionKind::kNonZeroArgument);

  nb::enum_<pasta::SwiftAsyncErrorAttrSpelling>(m, "SwiftAsyncErrorAttrSpelling")
    .value("GNU_SWIFT_ASYNC_ERROR", pasta::SwiftAsyncErrorAttrSpelling::kGNUSwiftAsyncError)
    .value("CXX11_CLANG_SWIFT_ASYNC_ERROR", pasta::SwiftAsyncErrorAttrSpelling::kCXX11ClangSwiftAsyncError)
    .value("C2X_CLANG_SWIFT_ASYNC_ERROR", pasta::SwiftAsyncErrorAttrSpelling::kC2xClangSwiftAsyncError)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftAsyncErrorAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftCallAttrSpelling>(m, "SwiftCallAttrSpelling")
    .value("GNU_SWIFTCALL", pasta::SwiftCallAttrSpelling::kGNUSwiftcall)
    .value("CXX11_CLANG_SWIFTCALL", pasta::SwiftCallAttrSpelling::kCXX11ClangSwiftcall)
    .value("C2X_CLANG_SWIFTCALL", pasta::SwiftCallAttrSpelling::kC2xClangSwiftcall)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftContextAttrSpelling>(m, "SwiftContextAttrSpelling")
    .value("GNU_SWIFT_CONTEXT", pasta::SwiftContextAttrSpelling::kGNUSwiftContext)
    .value("CXX11_CLANG_SWIFT_CONTEXT", pasta::SwiftContextAttrSpelling::kCXX11ClangSwiftContext)
    .value("C2X_CLANG_SWIFT_CONTEXT", pasta::SwiftContextAttrSpelling::kC2xClangSwiftContext)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftContextAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftErrorAttrConventionKind>(m, "SwiftErrorAttrConventionKind")
    .value("NONE", pasta::SwiftErrorAttrConventionKind::kNone)
    .value("NON_NULL_ERROR", pasta::SwiftErrorAttrConventionKind::kNonNullError)
    .value("NULL_RESULT", pasta::SwiftErrorAttrConventionKind::kNullResult)
    .value("ZERO_RESULT", pasta::SwiftErrorAttrConventionKind::kZeroResult)
    .value("NON_ZERO_RESULT", pasta::SwiftErrorAttrConventionKind::kNonZeroResult);

  nb::enum_<pasta::SwiftErrorResultAttrSpelling>(m, "SwiftErrorResultAttrSpelling")
    .value("GNU_SWIFT_ERROR_RESULT", pasta::SwiftErrorResultAttrSpelling::kGNUSwiftErrorResult)
    .value("CXX11_CLANG_SWIFT_ERROR_RESULT", pasta::SwiftErrorResultAttrSpelling::kCXX11ClangSwiftErrorResult)
    .value("C2X_CLANG_SWIFT_ERROR_RESULT", pasta::SwiftErrorResultAttrSpelling::kC2xClangSwiftErrorResult)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftErrorResultAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftIndirectResultAttrSpelling>(m, "SwiftIndirectResultAttrSpelling")
    .value("GNU_SWIFT_INDIRECT_RESULT", pasta::SwiftIndirectResultAttrSpelling::kGNUSwiftIndirectResult)
    .value("CXX11_CLANG_SWIFT_INDIRECT_RESULT", pasta::SwiftIndirectResultAttrSpelling::kCXX11ClangSwiftIndirectResult)
    .value("C2X_CLANG_SWIFT_INDIRECT_RESULT", pasta::SwiftIndirectResultAttrSpelling::kC2xClangSwiftIndirectResult)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftIndirectResultAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SwiftNewTypeAttrNewtypeKind>(m, "SwiftNewTypeAttrNewtypeKind")
    .value("STRUCT", pasta::SwiftNewTypeAttrNewtypeKind::kStruct)
    .value("ENUM", pasta::SwiftNewTypeAttrNewtypeKind::kEnum);

  nb::enum_<pasta::SwiftNewTypeAttrSpelling>(m, "SwiftNewTypeAttrSpelling")
    .value("GNU_SWIFT_NEWTYPE", pasta::SwiftNewTypeAttrSpelling::kGNUSwiftNewtype)
    .value("GNU_SWIFT_WRAPPER", pasta::SwiftNewTypeAttrSpelling::kGNUSwiftWrapper)
    .value("SPELLING_NOT_CALCULATED", pasta::SwiftNewTypeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::SysVABIAttrSpelling>(m, "SysVABIAttrSpelling")
    .value("GNU_SYSV_ABI", pasta::SysVABIAttrSpelling::kGNUSysvAbi)
    .value("CXX11_GNU_SYSV_ABI", pasta::SysVABIAttrSpelling::kCXX11GnuSysvAbi)
    .value("C2X_GNU_SYSV_ABI", pasta::SysVABIAttrSpelling::kC2xGnuSysvAbi)
    .value("SPELLING_NOT_CALCULATED", pasta::SysVABIAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TLSModelAttrSpelling>(m, "TLSModelAttrSpelling")
    .value("GNU_TLS_MODEL", pasta::TLSModelAttrSpelling::kGNUTlsModel)
    .value("CXX11_GNU_TLS_MODEL", pasta::TLSModelAttrSpelling::kCXX11GnuTlsModel)
    .value("C2X_GNU_TLS_MODEL", pasta::TLSModelAttrSpelling::kC2xGnuTlsModel)
    .value("SPELLING_NOT_CALCULATED", pasta::TLSModelAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TargetAttrSpelling>(m, "TargetAttrSpelling")
    .value("GNU_TARGET", pasta::TargetAttrSpelling::kGNUTarget)
    .value("CXX11_GNU_TARGET", pasta::TargetAttrSpelling::kCXX11GnuTarget)
    .value("C2X_GNU_TARGET", pasta::TargetAttrSpelling::kC2xGnuTarget)
    .value("SPELLING_NOT_CALCULATED", pasta::TargetAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TargetClonesAttrSpelling>(m, "TargetClonesAttrSpelling")
    .value("GNU_TARGET_CLONES", pasta::TargetClonesAttrSpelling::kGNUTargetClones)
    .value("CXX11_GNU_TARGET_CLONES", pasta::TargetClonesAttrSpelling::kCXX11GnuTargetClones)
    .value("C2X_GNU_TARGET_CLONES", pasta::TargetClonesAttrSpelling::kC2xGnuTargetClones)
    .value("SPELLING_NOT_CALCULATED", pasta::TargetClonesAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TargetVersionAttrSpelling>(m, "TargetVersionAttrSpelling")
    .value("GNU_TARGET_VERSION", pasta::TargetVersionAttrSpelling::kGNUTargetVersion)
    .value("CXX11_GNU_TARGET_VERSION", pasta::TargetVersionAttrSpelling::kCXX11GnuTargetVersion)
    .value("C2X_GNU_TARGET_VERSION", pasta::TargetVersionAttrSpelling::kC2xGnuTargetVersion)
    .value("SPELLING_NOT_CALCULATED", pasta::TargetVersionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TemplateArgumentKind>(m, "TemplateArgumentKind")
    .value("EMPTY", pasta::TemplateArgumentKind::kEmpty)
    .value("TYPE", pasta::TemplateArgumentKind::kType)
    .value("DECLARATION", pasta::TemplateArgumentKind::kDeclaration)
    .value("NULL_POINTER", pasta::TemplateArgumentKind::kNullPointer)
    .value("INTEGRAL", pasta::TemplateArgumentKind::kIntegral)
    .value("TEMPLATE", pasta::TemplateArgumentKind::kTemplate)
    .value("TEMPLATE_EXPANSION", pasta::TemplateArgumentKind::kTemplateExpansion)
    .value("EXPRESSION", pasta::TemplateArgumentKind::kExpression)
    .value("PACK", pasta::TemplateArgumentKind::kPack);

  nb::enum_<pasta::TestTypestateAttrConsumedState>(m, "TestTypestateAttrConsumedState")
    .value("CONSUMED", pasta::TestTypestateAttrConsumedState::kConsumed)
    .value("UNCONSUMED", pasta::TestTypestateAttrConsumedState::kUnconsumed);

  nb::enum_<pasta::TestTypestateAttrSpelling>(m, "TestTypestateAttrSpelling")
    .value("GNU_TEST_TYPESTATE", pasta::TestTypestateAttrSpelling::kGNUTestTypestate)
    .value("CXX11_CLANG_TEST_TYPESTATE", pasta::TestTypestateAttrSpelling::kCXX11ClangTestTypestate)
    .value("SPELLING_NOT_CALCULATED", pasta::TestTypestateAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ThisCallAttrSpelling>(m, "ThisCallAttrSpelling")
    .value("GNU_THISCALL", pasta::ThisCallAttrSpelling::kGNUThiscall)
    .value("CXX11_GNU_THISCALL", pasta::ThisCallAttrSpelling::kCXX11GnuThiscall)
    .value("C2X_GNU_THISCALL", pasta::ThisCallAttrSpelling::kC2xGnuThiscall)
    .value("KEYWORD_THISCALL", pasta::ThisCallAttrSpelling::kKeywordThiscall)
    .value("SPELLING_NOT_CALCULATED", pasta::ThisCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TransparentUnionAttrSpelling>(m, "TransparentUnionAttrSpelling")
    .value("GNU_TRANSPARENT_UNION", pasta::TransparentUnionAttrSpelling::kGNUTransparentUnion)
    .value("CXX11_GNU_TRANSPARENT_UNION", pasta::TransparentUnionAttrSpelling::kCXX11GnuTransparentUnion)
    .value("C2X_GNU_TRANSPARENT_UNION", pasta::TransparentUnionAttrSpelling::kC2xGnuTransparentUnion)
    .value("SPELLING_NOT_CALCULATED", pasta::TransparentUnionAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TrivialABIAttrSpelling>(m, "TrivialABIAttrSpelling")
    .value("GNU_TRIVIAL_ABI", pasta::TrivialABIAttrSpelling::kGNUTrivialAbi)
    .value("CXX11_CLANG_TRIVIAL_ABI", pasta::TrivialABIAttrSpelling::kCXX11ClangTrivialAbi)
    .value("SPELLING_NOT_CALCULATED", pasta::TrivialABIAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TryAcquireCapabilityAttrSpelling>(m, "TryAcquireCapabilityAttrSpelling")
    .value("GNU_TRY_ACQUIRE_CAPABILITY", pasta::TryAcquireCapabilityAttrSpelling::kGNUTryAcquireCapability)
    .value("CXX11_CLANG_TRY_ACQUIRE_CAPABILITY", pasta::TryAcquireCapabilityAttrSpelling::kCXX11ClangTryAcquireCapability)
    .value("GNU_TRY_ACQUIRE_SHARED_CAPABILITY", pasta::TryAcquireCapabilityAttrSpelling::kGNUTryAcquireSharedCapability)
    .value("CXX11_CLANG_TRY_ACQUIRE_SHARED_CAPABILITY", pasta::TryAcquireCapabilityAttrSpelling::kCXX11ClangTryAcquireSharedCapability)
    .value("SPELLING_NOT_CALCULATED", pasta::TryAcquireCapabilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TypeScalarTypeKind>(m, "TypeScalarTypeKind")
    .value("C_POINTER", pasta::TypeScalarTypeKind::kCPointer)
    .value("BLOCK_POINTER", pasta::TypeScalarTypeKind::kBlockPointer)
    .value("OBJ_C_OBJECT_POINTER", pasta::TypeScalarTypeKind::kObjCObjectPointer)
    .value("MEMBER_POINTER", pasta::TypeScalarTypeKind::kMemberPointer)
    .value("BOOLEAN", pasta::TypeScalarTypeKind::kBoolean)
    .value("INTEGRAL", pasta::TypeScalarTypeKind::kIntegral)
    .value("FLOATING", pasta::TypeScalarTypeKind::kFloating)
    .value("INTEGRAL_COMPLEX", pasta::TypeScalarTypeKind::kIntegralComplex)
    .value("FLOATING_COMPLEX", pasta::TypeScalarTypeKind::kFloatingComplex)
    .value("FIXED_POINT", pasta::TypeScalarTypeKind::kFixedPoint);

  nb::enum_<pasta::TypeKind>(m, "TypeKind")
    .value("ADJUSTED", pasta::TypeKind::kAdjusted)
    .value("DECAYED", pasta::TypeKind::kDecayed)
    .value("CONSTANT_ARRAY", pasta::TypeKind::kConstantArray)
    .value("DEPENDENT_SIZED_ARRAY", pasta::TypeKind::kDependentSizedArray)
    .value("INCOMPLETE_ARRAY", pasta::TypeKind::kIncompleteArray)
    .value("VARIABLE_ARRAY", pasta::TypeKind::kVariableArray)
    .value("ATOMIC", pasta::TypeKind::kAtomic)
    .value("ATTRIBUTED", pasta::TypeKind::kAttributed)
    .value("BTF_TAG_ATTRIBUTED", pasta::TypeKind::kBTFTagAttributed)
    .value("BIT_INT", pasta::TypeKind::kBitInt)
    .value("BLOCK_POINTER", pasta::TypeKind::kBlockPointer)
    .value("BUILTIN", pasta::TypeKind::kBuiltin)
    .value("COMPLEX", pasta::TypeKind::kComplex)
    .value("DECLTYPE", pasta::TypeKind::kDecltype)
    .value("AUTO", pasta::TypeKind::kAuto)
    .value("DEDUCED_TEMPLATE_SPECIALIZATION", pasta::TypeKind::kDeducedTemplateSpecialization)
    .value("DEPENDENT_ADDRESS_SPACE", pasta::TypeKind::kDependentAddressSpace)
    .value("DEPENDENT_BIT_INT", pasta::TypeKind::kDependentBitInt)
    .value("DEPENDENT_NAME", pasta::TypeKind::kDependentName)
    .value("DEPENDENT_SIZED_EXT_VECTOR", pasta::TypeKind::kDependentSizedExtVector)
    .value("DEPENDENT_TEMPLATE_SPECIALIZATION", pasta::TypeKind::kDependentTemplateSpecialization)
    .value("DEPENDENT_VECTOR", pasta::TypeKind::kDependentVector)
    .value("ELABORATED", pasta::TypeKind::kElaborated)
    .value("FUNCTION_NO_PROTO", pasta::TypeKind::kFunctionNoProto)
    .value("FUNCTION_PROTO", pasta::TypeKind::kFunctionProto)
    .value("INJECTED_CLASS_NAME", pasta::TypeKind::kInjectedClassName)
    .value("MACRO_QUALIFIED", pasta::TypeKind::kMacroQualified)
    .value("CONSTANT_MATRIX", pasta::TypeKind::kConstantMatrix)
    .value("DEPENDENT_SIZED_MATRIX", pasta::TypeKind::kDependentSizedMatrix)
    .value("MEMBER_POINTER", pasta::TypeKind::kMemberPointer)
    .value("OBJ_C_OBJECT_POINTER", pasta::TypeKind::kObjCObjectPointer)
    .value("OBJ_C_OBJECT", pasta::TypeKind::kObjCObject)
    .value("OBJ_C_INTERFACE", pasta::TypeKind::kObjCInterface)
    .value("OBJ_C_TYPE_PARAM", pasta::TypeKind::kObjCTypeParam)
    .value("PACK_EXPANSION", pasta::TypeKind::kPackExpansion)
    .value("PAREN", pasta::TypeKind::kParen)
    .value("PIPE", pasta::TypeKind::kPipe)
    .value("POINTER", pasta::TypeKind::kPointer)
    .value("L_VALUE_REFERENCE", pasta::TypeKind::kLValueReference)
    .value("R_VALUE_REFERENCE", pasta::TypeKind::kRValueReference)
    .value("SUBST_TEMPLATE_TYPE_PARM_PACK", pasta::TypeKind::kSubstTemplateTypeParmPack)
    .value("SUBST_TEMPLATE_TYPE_PARM", pasta::TypeKind::kSubstTemplateTypeParm)
    .value("ENUM", pasta::TypeKind::kEnum)
    .value("RECORD", pasta::TypeKind::kRecord)
    .value("TEMPLATE_SPECIALIZATION", pasta::TypeKind::kTemplateSpecialization)
    .value("TEMPLATE_TYPE_PARM", pasta::TypeKind::kTemplateTypeParm)
    .value("TYPE_OF_EXPR", pasta::TypeKind::kTypeOfExpr)
    .value("TYPE_OF", pasta::TypeKind::kTypeOf)
    .value("TYPEDEF", pasta::TypeKind::kTypedef)
    .value("UNARY_TRANSFORM", pasta::TypeKind::kUnaryTransform)
    .value("UNRESOLVED_USING", pasta::TypeKind::kUnresolvedUsing)
    .value("USING", pasta::TypeKind::kUsing)
    .value("VECTOR", pasta::TypeKind::kVector)
    .value("EXT_VECTOR", pasta::TypeKind::kExtVector)
    .value("QUALIFIED", pasta::TypeKind::kQualified);

  nb::enum_<pasta::TypeTagForDatatypeAttrSpelling>(m, "TypeTagForDatatypeAttrSpelling")
    .value("GNU_TYPE_TAG_FOR_DATATYPE", pasta::TypeTagForDatatypeAttrSpelling::kGNUTypeTagForDatatype)
    .value("CXX11_CLANG_TYPE_TAG_FOR_DATATYPE", pasta::TypeTagForDatatypeAttrSpelling::kCXX11ClangTypeTagForDatatype)
    .value("C2X_CLANG_TYPE_TAG_FOR_DATATYPE", pasta::TypeTagForDatatypeAttrSpelling::kC2xClangTypeTagForDatatype)
    .value("SPELLING_NOT_CALCULATED", pasta::TypeTagForDatatypeAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TypeVisibilityAttrSpelling>(m, "TypeVisibilityAttrSpelling")
    .value("GNU_TYPE_VISIBILITY", pasta::TypeVisibilityAttrSpelling::kGNUTypeVisibility)
    .value("CXX11_CLANG_TYPE_VISIBILITY", pasta::TypeVisibilityAttrSpelling::kCXX11ClangTypeVisibility)
    .value("C2X_CLANG_TYPE_VISIBILITY", pasta::TypeVisibilityAttrSpelling::kC2xClangTypeVisibility)
    .value("SPELLING_NOT_CALCULATED", pasta::TypeVisibilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::TypeVisibilityAttrVisibilityType>(m, "TypeVisibilityAttrVisibilityType")
    .value("DEFAULT", pasta::TypeVisibilityAttrVisibilityType::kDefault)
    .value("HIDDEN", pasta::TypeVisibilityAttrVisibilityType::kHidden)
    .value("PROTECTED", pasta::TypeVisibilityAttrVisibilityType::kProtected);

  nb::enum_<pasta::UnaryTransformTypeUTTKind>(m, "UnaryTransformTypeUTTKind")
    .value("ADD_LVALUE_REFERENCE", pasta::UnaryTransformTypeUTTKind::kAddLvalueReference)
    .value("ADD_POINTER", pasta::UnaryTransformTypeUTTKind::kAddPointer)
    .value("ADD_RVALUE_REFERENCE", pasta::UnaryTransformTypeUTTKind::kAddRvalueReference)
    .value("DECAY", pasta::UnaryTransformTypeUTTKind::kDecay)
    .value("MAKE_SIGNED", pasta::UnaryTransformTypeUTTKind::kMakeSigned)
    .value("MAKE_UNSIGNED", pasta::UnaryTransformTypeUTTKind::kMakeUnsigned)
    .value("REMOVE_ALL_EXTENTS", pasta::UnaryTransformTypeUTTKind::kRemoveAllExtents)
    .value("REMOVE_CONST", pasta::UnaryTransformTypeUTTKind::kRemoveConst)
    .value("REMOVE_CV", pasta::UnaryTransformTypeUTTKind::kRemoveCV)
    .value("REMOVE_CV_REFERENCE", pasta::UnaryTransformTypeUTTKind::kRemoveCVReference)
    .value("REMOVE_EXTENT", pasta::UnaryTransformTypeUTTKind::kRemoveExtent)
    .value("REMOVE_POINTER", pasta::UnaryTransformTypeUTTKind::kRemovePointer)
    .value("REMOVE_REFERENCE", pasta::UnaryTransformTypeUTTKind::kRemoveReference)
    .value("REMOVE_RESTRICT", pasta::UnaryTransformTypeUTTKind::kRemoveRestrict)
    .value("REMOVE_VOLATILE", pasta::UnaryTransformTypeUTTKind::kRemoveVolatile)
    .value("ENUM_UNDERLYING_TYPE", pasta::UnaryTransformTypeUTTKind::kEnumUnderlyingType);

  nb::enum_<pasta::UnavailableAttrImplicitReason>(m, "UnavailableAttrImplicitReason")
    .value("NONE", pasta::UnavailableAttrImplicitReason::kNone)
    .value("ARC_FORBIDDEN_TYPE", pasta::UnavailableAttrImplicitReason::kARCForbiddenType)
    .value("FORBIDDEN_WEAK", pasta::UnavailableAttrImplicitReason::kForbiddenWeak)
    .value("ARC_FORBIDDEN_CONVERSION", pasta::UnavailableAttrImplicitReason::kARCForbiddenConversion)
    .value("ARC_INIT_RETURNS_UNRELATED", pasta::UnavailableAttrImplicitReason::kARCInitReturnsUnrelated)
    .value("ARC_FIELD_WITH_OWNERSHIP", pasta::UnavailableAttrImplicitReason::kARCFieldWithOwnership);

  nb::enum_<pasta::UnavailableAttrSpelling>(m, "UnavailableAttrSpelling")
    .value("GNU_UNAVAILABLE", pasta::UnavailableAttrSpelling::kGNUUnavailable)
    .value("CXX11_CLANG_UNAVAILABLE", pasta::UnavailableAttrSpelling::kCXX11ClangUnavailable)
    .value("C2X_CLANG_UNAVAILABLE", pasta::UnavailableAttrSpelling::kC2xClangUnavailable)
    .value("SPELLING_NOT_CALCULATED", pasta::UnavailableAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UninitializedAttrSpelling>(m, "UninitializedAttrSpelling")
    .value("GNU_UNINITIALIZED", pasta::UninitializedAttrSpelling::kGNUUninitialized)
    .value("CXX11_CLANG_UNINITIALIZED", pasta::UninitializedAttrSpelling::kCXX11ClangUninitialized)
    .value("SPELLING_NOT_CALCULATED", pasta::UninitializedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UnlikelyAttrSpelling>(m, "UnlikelyAttrSpelling")
    .value("CXX11_UNLIKELY", pasta::UnlikelyAttrSpelling::kCXX11Unlikely)
    .value("C2X_CLANG_UNLIKELY", pasta::UnlikelyAttrSpelling::kC2xClangUnlikely)
    .value("SPELLING_NOT_CALCULATED", pasta::UnlikelyAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UnusedAttrSpelling>(m, "UnusedAttrSpelling")
    .value("CXX11_MAYBE_UNUSED", pasta::UnusedAttrSpelling::kCXX11MaybeUnused)
    .value("GNU_UNUSED", pasta::UnusedAttrSpelling::kGNUUnused)
    .value("CXX11_GNU_UNUSED", pasta::UnusedAttrSpelling::kCXX11GnuUnused)
    .value("C2X_GNU_UNUSED", pasta::UnusedAttrSpelling::kC2xGnuUnused)
    .value("C2X_MAYBE_UNUSED", pasta::UnusedAttrSpelling::kC2xMaybeUnused)
    .value("SPELLING_NOT_CALCULATED", pasta::UnusedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UseHandleAttrSpelling>(m, "UseHandleAttrSpelling")
    .value("GNU_USE_HANDLE", pasta::UseHandleAttrSpelling::kGNUUseHandle)
    .value("CXX11_CLANG_USE_HANDLE", pasta::UseHandleAttrSpelling::kCXX11ClangUseHandle)
    .value("C2X_CLANG_USE_HANDLE", pasta::UseHandleAttrSpelling::kC2xClangUseHandle)
    .value("SPELLING_NOT_CALCULATED", pasta::UseHandleAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UsedAttrSpelling>(m, "UsedAttrSpelling")
    .value("GNU_USED", pasta::UsedAttrSpelling::kGNUUsed)
    .value("CXX11_GNU_USED", pasta::UsedAttrSpelling::kCXX11GnuUsed)
    .value("C2X_GNU_USED", pasta::UsedAttrSpelling::kC2xGnuUsed)
    .value("SPELLING_NOT_CALCULATED", pasta::UsedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UserDefinedLiteralLiteralOperatorKind>(m, "UserDefinedLiteralLiteralOperatorKind")
    .value("RAW", pasta::UserDefinedLiteralLiteralOperatorKind::kRaw)
    .value("TEMPLATE", pasta::UserDefinedLiteralLiteralOperatorKind::kTemplate)
    .value("INTEGER", pasta::UserDefinedLiteralLiteralOperatorKind::kInteger)
    .value("FLOATING", pasta::UserDefinedLiteralLiteralOperatorKind::kFloating)
    .value("STRING", pasta::UserDefinedLiteralLiteralOperatorKind::kString)
    .value("CHARACTER", pasta::UserDefinedLiteralLiteralOperatorKind::kCharacter);

  nb::enum_<pasta::UsingIfExistsAttrSpelling>(m, "UsingIfExistsAttrSpelling")
    .value("GNU_USING_IF_EXISTS", pasta::UsingIfExistsAttrSpelling::kGNUUsingIfExists)
    .value("CXX11_CLANG_USING_IF_EXISTS", pasta::UsingIfExistsAttrSpelling::kCXX11ClangUsingIfExists)
    .value("SPELLING_NOT_CALCULATED", pasta::UsingIfExistsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::UuidAttrSpelling>(m, "UuidAttrSpelling")
    .value("DECLSPEC_UUID", pasta::UuidAttrSpelling::kDeclspecUuid)
    .value("MICROSOFT_UUID", pasta::UuidAttrSpelling::kMicrosoftUuid)
    .value("SPELLING_NOT_CALCULATED", pasta::UuidAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::VarDeclDefinitionKind>(m, "VarDeclDefinitionKind")
    .value("DECLARATION_ONLY", pasta::VarDeclDefinitionKind::kDeclarationOnly)
    .value("TENTATIVE_DEFINITION", pasta::VarDeclDefinitionKind::kTentativeDefinition)
    .value("DEFINITION", pasta::VarDeclDefinitionKind::kDefinition);

  nb::enum_<pasta::VarDeclInitializationStyle>(m, "VarDeclInitializationStyle")
    .value("C_INIT", pasta::VarDeclInitializationStyle::kCInit)
    .value("CALL_INITIALIZER", pasta::VarDeclInitializationStyle::kCallInitializer)
    .value("LIST_INITIALIZER", pasta::VarDeclInitializationStyle::kListInitializer)
    .value("PARENTHESIS_LIST_INITIALIZER", pasta::VarDeclInitializationStyle::kParenthesisListInitializer);

  nb::enum_<pasta::VarDeclTLSKind>(m, "VarDeclTLSKind")
    .value("NONE", pasta::VarDeclTLSKind::kNone)
    .value("STATIC", pasta::VarDeclTLSKind::kStatic)
    .value("DYNAMIC", pasta::VarDeclTLSKind::kDynamic);

  nb::enum_<pasta::VecReturnAttrSpelling>(m, "VecReturnAttrSpelling")
    .value("GNU_VECRETURN", pasta::VecReturnAttrSpelling::kGNUVecreturn)
    .value("CXX11_CLANG_VECRETURN", pasta::VecReturnAttrSpelling::kCXX11ClangVecreturn)
    .value("SPELLING_NOT_CALCULATED", pasta::VecReturnAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::VectorCallAttrSpelling>(m, "VectorCallAttrSpelling")
    .value("GNU_VECTORCALL", pasta::VectorCallAttrSpelling::kGNUVectorcall)
    .value("CXX11_CLANG_VECTORCALL", pasta::VectorCallAttrSpelling::kCXX11ClangVectorcall)
    .value("C2X_CLANG_VECTORCALL", pasta::VectorCallAttrSpelling::kC2xClangVectorcall)
    .value("KEYWORD_VECTORCALL", pasta::VectorCallAttrSpelling::kKeywordVectorcall)
    .value("SPELLING_NOT_CALCULATED", pasta::VectorCallAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::VectorTypeVectorKind>(m, "VectorTypeVectorKind")
    .value("GENERIC_VECTOR", pasta::VectorTypeVectorKind::kGenericVector)
    .value("ALTI_VEC_VECTOR", pasta::VectorTypeVectorKind::kAltiVecVector)
    .value("ALTI_VEC_PIXEL", pasta::VectorTypeVectorKind::kAltiVecPixel)
    .value("ALTI_VEC_BOOLEAN", pasta::VectorTypeVectorKind::kAltiVecBoolean)
    .value("NEON_VECTOR", pasta::VectorTypeVectorKind::kNeonVector)
    .value("NEON_POLY_VECTOR", pasta::VectorTypeVectorKind::kNeonPolyVector)
    .value("SVE_FIXED_LENGTH_DATA_VECTOR", pasta::VectorTypeVectorKind::kSveFixedLengthDataVector)
    .value("SVE_FIXED_LENGTH_PREDICATE_VECTOR", pasta::VectorTypeVectorKind::kSveFixedLengthPredicateVector);

  nb::enum_<pasta::VisibilityAttrSpelling>(m, "VisibilityAttrSpelling")
    .value("GNU_VISIBILITY", pasta::VisibilityAttrSpelling::kGNUVisibility)
    .value("CXX11_GNU_VISIBILITY", pasta::VisibilityAttrSpelling::kCXX11GnuVisibility)
    .value("C2X_GNU_VISIBILITY", pasta::VisibilityAttrSpelling::kC2xGnuVisibility)
    .value("SPELLING_NOT_CALCULATED", pasta::VisibilityAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::VisibilityAttrVisibilityType>(m, "VisibilityAttrVisibilityType")
    .value("DEFAULT", pasta::VisibilityAttrVisibilityType::kDefault)
    .value("HIDDEN", pasta::VisibilityAttrVisibilityType::kHidden)
    .value("PROTECTED", pasta::VisibilityAttrVisibilityType::kProtected);

  nb::enum_<pasta::WarnUnusedAttrSpelling>(m, "WarnUnusedAttrSpelling")
    .value("GNU_WARN_UNUSED", pasta::WarnUnusedAttrSpelling::kGNUWarnUnused)
    .value("CXX11_GNU_WARN_UNUSED", pasta::WarnUnusedAttrSpelling::kCXX11GnuWarnUnused)
    .value("C2X_GNU_WARN_UNUSED", pasta::WarnUnusedAttrSpelling::kC2xGnuWarnUnused)
    .value("SPELLING_NOT_CALCULATED", pasta::WarnUnusedAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WarnUnusedResultAttrSpelling>(m, "WarnUnusedResultAttrSpelling")
    .value("CXX11_NODISCARD", pasta::WarnUnusedResultAttrSpelling::kCXX11Nodiscard)
    .value("C2X_NODISCARD", pasta::WarnUnusedResultAttrSpelling::kC2xNodiscard)
    .value("CXX11_CLANG_WARN_UNUSED_RESULT", pasta::WarnUnusedResultAttrSpelling::kCXX11ClangWarnUnusedResult)
    .value("GNU_WARN_UNUSED_RESULT", pasta::WarnUnusedResultAttrSpelling::kGNUWarnUnusedResult)
    .value("CXX11_GNU_WARN_UNUSED_RESULT", pasta::WarnUnusedResultAttrSpelling::kCXX11GnuWarnUnusedResult)
    .value("C2X_GNU_WARN_UNUSED_RESULT", pasta::WarnUnusedResultAttrSpelling::kC2xGnuWarnUnusedResult)
    .value("SPELLING_NOT_CALCULATED", pasta::WarnUnusedResultAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WeakAttrSpelling>(m, "WeakAttrSpelling")
    .value("GNU_WEAK", pasta::WeakAttrSpelling::kGNUWeak)
    .value("CXX11_GNU_WEAK", pasta::WeakAttrSpelling::kCXX11GnuWeak)
    .value("C2X_GNU_WEAK", pasta::WeakAttrSpelling::kC2xGnuWeak)
    .value("SPELLING_NOT_CALCULATED", pasta::WeakAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WeakImportAttrSpelling>(m, "WeakImportAttrSpelling")
    .value("GNU_WEAK_IMPORT", pasta::WeakImportAttrSpelling::kGNUWeakImport)
    .value("CXX11_CLANG_WEAK_IMPORT", pasta::WeakImportAttrSpelling::kCXX11ClangWeakImport)
    .value("C2X_CLANG_WEAK_IMPORT", pasta::WeakImportAttrSpelling::kC2xClangWeakImport)
    .value("SPELLING_NOT_CALCULATED", pasta::WeakImportAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WeakRefAttrSpelling>(m, "WeakRefAttrSpelling")
    .value("GNU_WEAKREF", pasta::WeakRefAttrSpelling::kGNUWeakref)
    .value("CXX11_GNU_WEAKREF", pasta::WeakRefAttrSpelling::kCXX11GnuWeakref)
    .value("C2X_GNU_WEAKREF", pasta::WeakRefAttrSpelling::kC2xGnuWeakref)
    .value("SPELLING_NOT_CALCULATED", pasta::WeakRefAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WebAssemblyExportNameAttrSpelling>(m, "WebAssemblyExportNameAttrSpelling")
    .value("GNU_EXPORT_NAME", pasta::WebAssemblyExportNameAttrSpelling::kGNUExportName)
    .value("CXX11_CLANG_EXPORT_NAME", pasta::WebAssemblyExportNameAttrSpelling::kCXX11ClangExportName)
    .value("C2X_CLANG_EXPORT_NAME", pasta::WebAssemblyExportNameAttrSpelling::kC2xClangExportName)
    .value("SPELLING_NOT_CALCULATED", pasta::WebAssemblyExportNameAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WebAssemblyImportModuleAttrSpelling>(m, "WebAssemblyImportModuleAttrSpelling")
    .value("GNU_IMPORT_MODULE", pasta::WebAssemblyImportModuleAttrSpelling::kGNUImportModule)
    .value("CXX11_CLANG_IMPORT_MODULE", pasta::WebAssemblyImportModuleAttrSpelling::kCXX11ClangImportModule)
    .value("C2X_CLANG_IMPORT_MODULE", pasta::WebAssemblyImportModuleAttrSpelling::kC2xClangImportModule)
    .value("SPELLING_NOT_CALCULATED", pasta::WebAssemblyImportModuleAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::WebAssemblyImportNameAttrSpelling>(m, "WebAssemblyImportNameAttrSpelling")
    .value("GNU_IMPORT_NAME", pasta::WebAssemblyImportNameAttrSpelling::kGNUImportName)
    .value("CXX11_CLANG_IMPORT_NAME", pasta::WebAssemblyImportNameAttrSpelling::kCXX11ClangImportName)
    .value("C2X_CLANG_IMPORT_NAME", pasta::WebAssemblyImportNameAttrSpelling::kC2xClangImportName)
    .value("SPELLING_NOT_CALCULATED", pasta::WebAssemblyImportNameAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::X86ForceAlignArgPointerAttrSpelling>(m, "X86ForceAlignArgPointerAttrSpelling")
    .value("GNU_FORCE_ALIGN_ARGUMENT_POINTER", pasta::X86ForceAlignArgPointerAttrSpelling::kGNUForceAlignArgumentPointer)
    .value("CXX11_GNU_FORCE_ALIGN_ARGUMENT_POINTER", pasta::X86ForceAlignArgPointerAttrSpelling::kCXX11GnuForceAlignArgumentPointer)
    .value("C2X_GNU_FORCE_ALIGN_ARGUMENT_POINTER", pasta::X86ForceAlignArgPointerAttrSpelling::kC2xGnuForceAlignArgumentPointer)
    .value("SPELLING_NOT_CALCULATED", pasta::X86ForceAlignArgPointerAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::XRayInstrumentAttrSpelling>(m, "XRayInstrumentAttrSpelling")
    .value("GNU_XRAY_ALWAYS_INSTRUMENT", pasta::XRayInstrumentAttrSpelling::kGNUXrayAlwaysInstrument)
    .value("CXX11_CLANG_XRAY_ALWAYS_INSTRUMENT", pasta::XRayInstrumentAttrSpelling::kCXX11ClangXrayAlwaysInstrument)
    .value("C2X_CLANG_XRAY_ALWAYS_INSTRUMENT", pasta::XRayInstrumentAttrSpelling::kC2xClangXrayAlwaysInstrument)
    .value("GNU_XRAY_NEVER_INSTRUMENT", pasta::XRayInstrumentAttrSpelling::kGNUXrayNeverInstrument)
    .value("CXX11_CLANG_XRAY_NEVER_INSTRUMENT", pasta::XRayInstrumentAttrSpelling::kCXX11ClangXrayNeverInstrument)
    .value("C2X_CLANG_XRAY_NEVER_INSTRUMENT", pasta::XRayInstrumentAttrSpelling::kC2xClangXrayNeverInstrument)
    .value("SPELLING_NOT_CALCULATED", pasta::XRayInstrumentAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::XRayLogArgsAttrSpelling>(m, "XRayLogArgsAttrSpelling")
    .value("GNU_XRAY_LOG_ARGUMENTS", pasta::XRayLogArgsAttrSpelling::kGNUXrayLogArguments)
    .value("CXX11_CLANG_XRAY_LOG_ARGUMENTS", pasta::XRayLogArgsAttrSpelling::kCXX11ClangXrayLogArguments)
    .value("C2X_CLANG_XRAY_LOG_ARGUMENTS", pasta::XRayLogArgsAttrSpelling::kC2xClangXrayLogArguments)
    .value("SPELLING_NOT_CALCULATED", pasta::XRayLogArgsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ZeroCallUsedRegsAttrSpelling>(m, "ZeroCallUsedRegsAttrSpelling")
    .value("GNU_ZERO_CALL_USED_REGS", pasta::ZeroCallUsedRegsAttrSpelling::kGNUZeroCallUsedRegs)
    .value("CXX11_GNU_ZERO_CALL_USED_REGS", pasta::ZeroCallUsedRegsAttrSpelling::kCXX11GnuZeroCallUsedRegs)
    .value("C2X_GNU_ZERO_CALL_USED_REGS", pasta::ZeroCallUsedRegsAttrSpelling::kC2xGnuZeroCallUsedRegs)
    .value("SPELLING_NOT_CALCULATED", pasta::ZeroCallUsedRegsAttrSpelling::kSpellingNotCalculated);

  nb::enum_<pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind>(m, "ZeroCallUsedRegsAttrZeroCallUsedRegsKind")
    .value("SKIP", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kSkip)
    .value("USED_GPR_ARG", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kUsedGPRArg)
    .value("USED_GPR", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kUsedGPR)
    .value("USED_ARGUMENT", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kUsedArgument)
    .value("USED", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kUsed)
    .value("ALL_GPR_ARG", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kAllGPRArg)
    .value("ALL_GPR", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kAllGPR)
    .value("ALL_ARGUMENT", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kAllArgument)
    .value("ALL", pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind::kAll);

  nb::enum_<pasta::ASTDumpOutputFormat>(m, "ASTDumpOutputFormat")
    .value("DEFAULT", pasta::ASTDumpOutputFormat::kDefault)
    .value("JSON", pasta::ASTDumpOutputFormat::kJSON);

  nb::enum_<pasta::AccessSpecifier>(m, "AccessSpecifier")
    .value("PUBLIC", pasta::AccessSpecifier::kPublic)
    .value("PROTECTED", pasta::AccessSpecifier::kProtected)
    .value("PRIVATE", pasta::AccessSpecifier::kPrivate)
    .value("NONE", pasta::AccessSpecifier::kNone);

  nb::enum_<pasta::AddrSpaceMapMangling>(m, "AddrSpaceMapMangling")
    .value("TARGET", pasta::AddrSpaceMapMangling::kTarget)
    .value("ON", pasta::AddrSpaceMapMangling::kOn)
    .value("OFF", pasta::AddrSpaceMapMangling::kOff);

  nb::enum_<pasta::AlignRequirementKind>(m, "AlignRequirementKind")
    .value("NONE", pasta::AlignRequirementKind::kNone)
    .value("REQUIRED_BY_TYPEDEF", pasta::AlignRequirementKind::kRequiredByTypedef)
    .value("REQUIRED_BY_RECORD", pasta::AlignRequirementKind::kRequiredByRecord)
    .value("REQUIRED_BY_ENUM", pasta::AlignRequirementKind::kRequiredByEnum);

  nb::enum_<pasta::AltivecSrcCompatKind>(m, "AltivecSrcCompatKind")
    .value("MIXED", pasta::AltivecSrcCompatKind::kMixed)
    .value("GCC", pasta::AltivecSrcCompatKind::kGCC)
    .value("XL", pasta::AltivecSrcCompatKind::kXL)
    .value("DEFAULT", pasta::AltivecSrcCompatKind::kDefault);

  nb::enum_<pasta::ArgumentKind>(m, "ArgumentKind")
    .value("STD_STRING", pasta::ArgumentKind::kStdString)
    .value("C_STRING", pasta::ArgumentKind::kCString)
    .value("SINT", pasta::ArgumentKind::kSint)
    .value("UINT", pasta::ArgumentKind::kUint)
    .value("TOKENKIND", pasta::ArgumentKind::kTokenkind)
    .value("IDENTIFIERINFO", pasta::ArgumentKind::kIdentifierinfo)
    .value("ADDRSPACE", pasta::ArgumentKind::kAddrspace)
    .value("QUALIFIED", pasta::ArgumentKind::kQualified)
    .value("QUALTYPE", pasta::ArgumentKind::kQualtype)
    .value("DECLARATIONNAME", pasta::ArgumentKind::kDeclarationname)
    .value("NAMEDDECL", pasta::ArgumentKind::kNameddecl)
    .value("NESTEDNAMESPEC", pasta::ArgumentKind::kNestednamespec)
    .value("DECLCONTEXT", pasta::ArgumentKind::kDeclcontext)
    .value("QUALTYPE_PAIR", pasta::ArgumentKind::kQualtypePair)
    .value("ATTRIBUTE", pasta::ArgumentKind::kAttribute);

  nb::enum_<pasta::ArrayTypeTrait>(m, "ArrayTypeTrait")
    .value("ARRAY_RANK", pasta::ArrayTypeTrait::kArrayRank)
    .value("ARRAY_EXTENT", pasta::ArrayTypeTrait::kArrayExtent);

  nb::enum_<pasta::AtomicScopeModelKind>(m, "AtomicScopeModelKind")
    .value("NONE", pasta::AtomicScopeModelKind::kNone)
    .value("OPEN_CL", pasta::AtomicScopeModelKind::kOpenCL)
    .value("HIP", pasta::AtomicScopeModelKind::kHIP);

  nb::enum_<pasta::AutoTypeKeyword>(m, "AutoTypeKeyword")
    .value("AUTO", pasta::AutoTypeKeyword::kAuto)
    .value("DECLTYPE_AUTO", pasta::AutoTypeKeyword::kDecltypeAuto)
    .value("GNU_AUTO_TYPE", pasta::AutoTypeKeyword::kGNUAutoType);

  nb::enum_<pasta::AvailabilityResult>(m, "AvailabilityResult")
    .value("AVAILABLE", pasta::AvailabilityResult::kAvailable)
    .value("NOT_YET_INTRODUCED", pasta::AvailabilityResult::kNotYetIntroduced)
    .value("DEPRECATED", pasta::AvailabilityResult::kDeprecated)
    .value("UNAVAILABLE", pasta::AvailabilityResult::kUnavailable);

  nb::enum_<pasta::BinaryOperatorKind>(m, "BinaryOperatorKind")
    .value("POINTER_MEMORY_D", pasta::BinaryOperatorKind::kPointerMemoryD)
    .value("POINTER_MEMORY_I", pasta::BinaryOperatorKind::kPointerMemoryI)
    .value("MUL", pasta::BinaryOperatorKind::kMul)
    .value("DIV", pasta::BinaryOperatorKind::kDiv)
    .value("REM", pasta::BinaryOperatorKind::kRem)
    .value("ADD", pasta::BinaryOperatorKind::kAdd)
    .value("SUB", pasta::BinaryOperatorKind::kSub)
    .value("SHL", pasta::BinaryOperatorKind::kShl)
    .value("SHR", pasta::BinaryOperatorKind::kShr)
    .value("CMP", pasta::BinaryOperatorKind::kCmp)
    .value("LT", pasta::BinaryOperatorKind::kLT)
    .value("GT", pasta::BinaryOperatorKind::kGT)
    .value("LE", pasta::BinaryOperatorKind::kLE)
    .value("GE", pasta::BinaryOperatorKind::kGE)
    .value("EQ", pasta::BinaryOperatorKind::kEQ)
    .value("NE", pasta::BinaryOperatorKind::kNE)
    .value("AND", pasta::BinaryOperatorKind::kAnd)
    .value("XOR", pasta::BinaryOperatorKind::kXor)
    .value("OR", pasta::BinaryOperatorKind::kOr)
    .value("L_AND", pasta::BinaryOperatorKind::kLAnd)
    .value("L_OR", pasta::BinaryOperatorKind::kLOr)
    .value("ASSIGN", pasta::BinaryOperatorKind::kAssign)
    .value("MUL_ASSIGN", pasta::BinaryOperatorKind::kMulAssign)
    .value("DIV_ASSIGN", pasta::BinaryOperatorKind::kDivAssign)
    .value("REM_ASSIGN", pasta::BinaryOperatorKind::kRemAssign)
    .value("ADD_ASSIGN", pasta::BinaryOperatorKind::kAddAssign)
    .value("SUB_ASSIGN", pasta::BinaryOperatorKind::kSubAssign)
    .value("SHL_ASSIGN", pasta::BinaryOperatorKind::kShlAssign)
    .value("SHR_ASSIGN", pasta::BinaryOperatorKind::kShrAssign)
    .value("AND_ASSIGN", pasta::BinaryOperatorKind::kAndAssign)
    .value("XOR_ASSIGN", pasta::BinaryOperatorKind::kXorAssign)
    .value("OR_ASSIGN", pasta::BinaryOperatorKind::kOrAssign)
    .value("COMMA", pasta::BinaryOperatorKind::kComma);

  nb::enum_<pasta::Bits>(m, "Bits")
    .value("NONE", pasta::Bits::kNone)
    .value("UNEXPANDED_PACK", pasta::Bits::kUnexpandedPack)
    .value("INSTANTIATION", pasta::Bits::kInstantiation)
    .value("TYPE", pasta::Bits::kType)
    .value("VALUE", pasta::Bits::kValue)
    .value("DEPENDENT", pasta::Bits::kDependent)
    .value("ERROR", pasta::Bits::kError)
    .value("VARIABLY_MODIFIED", pasta::Bits::kVariablyModified)
    .value("SYNTACTIC", pasta::Bits::kSyntactic)
    .value("SEMANTIC", pasta::Bits::kSemantic);

  nb::enum_<pasta::CallingConv>(m, "CallingConv")
    .value("C", pasta::CallingConv::kC)
    .value("X86_STD_CALL", pasta::CallingConv::kX86StdCall)
    .value("X86_FAST_CALL", pasta::CallingConv::kX86FastCall)
    .value("X86_THIS_CALL", pasta::CallingConv::kX86ThisCall)
    .value("X86_VECTOR_CALL", pasta::CallingConv::kX86VectorCall)
    .value("X86_PASCAL", pasta::CallingConv::kX86Pascal)
    .value("WIN64", pasta::CallingConv::kWin64)
    .value("X8664_SYS_V", pasta::CallingConv::kX8664SysV)
    .value("X86_REG_CALL", pasta::CallingConv::kX86RegCall)
    .value("AAPCS", pasta::CallingConv::kAAPCS)
    .value("AAPCSVFP", pasta::CallingConv::kAAPCSVFP)
    .value("INTEL_OCL_BICC", pasta::CallingConv::kIntelOclBicc)
    .value("SPIR_FUNCTION", pasta::CallingConv::kSpirFunction)
    .value("OPEN_CL_KERNEL", pasta::CallingConv::kOpenCLKernel)
    .value("SWIFT", pasta::CallingConv::kSwift)
    .value("SWIFT_ASYNC", pasta::CallingConv::kSwiftAsync)
    .value("PRESERVE_MOST", pasta::CallingConv::kPreserveMost)
    .value("PRESERVE_ALL", pasta::CallingConv::kPreserveAll)
    .value("A_ARCH64_VECTOR_CALL", pasta::CallingConv::kAArch64VectorCall)
    .value("A_ARCH64_SVEPCS", pasta::CallingConv::kAArch64SVEPCS)
    .value("AMDGPU_KERNEL_CALL", pasta::CallingConv::kAMDGPUKernelCall);

  nb::enum_<pasta::CanThrowResult>(m, "CanThrowResult")
    .value("CANNOT", pasta::CanThrowResult::kCannot)
    .value("DEPENDENT", pasta::CanThrowResult::kDependent)
    .value("CAN", pasta::CanThrowResult::kCan);

  nb::enum_<pasta::CapturedRegionKind>(m, "CapturedRegionKind")
    .value("DEFAULT", pasta::CapturedRegionKind::kDefault)
    .value("OBJ_C_AT_FINALLY", pasta::CapturedRegionKind::kObjCAtFinally)
    .value("OPEN_MP", pasta::CapturedRegionKind::kOpenMP);

  nb::enum_<pasta::CastKind>(m, "CastKind")
    .value("DEPENDENT", pasta::CastKind::kDependent)
    .value("BIT_CAST", pasta::CastKind::kBitCast)
    .value("L_VALUE_BIT_CAST", pasta::CastKind::kLValueBitCast)
    .value("L_VALUE_TO_R_VALUE_BIT_CAST", pasta::CastKind::kLValueToRValueBitCast)
    .value("L_VALUE_TO_R_VALUE", pasta::CastKind::kLValueToRValue)
    .value("NO_OPERATION", pasta::CastKind::kNoOperation)
    .value("BASE_TO_DERIVED", pasta::CastKind::kBaseToDerived)
    .value("DERIVED_TO_BASE", pasta::CastKind::kDerivedToBase)
    .value("UNCHECKED_DERIVED_TO_BASE", pasta::CastKind::kUncheckedDerivedToBase)
    .value("DYNAMIC", pasta::CastKind::kDynamic)
    .value("TO_UNION", pasta::CastKind::kToUnion)
    .value("ARRAY_TO_POINTER_DECAY", pasta::CastKind::kArrayToPointerDecay)
    .value("FUNCTION_TO_POINTER_DECAY", pasta::CastKind::kFunctionToPointerDecay)
    .value("NULL_TO_POINTER", pasta::CastKind::kNullToPointer)
    .value("NULL_TO_MEMBER_POINTER", pasta::CastKind::kNullToMemberPointer)
    .value("BASE_TO_DERIVED_MEMBER_POINTER", pasta::CastKind::kBaseToDerivedMemberPointer)
    .value("DERIVED_TO_BASE_MEMBER_POINTER", pasta::CastKind::kDerivedToBaseMemberPointer)
    .value("MEMBER_POINTER_TO_BOOLEAN", pasta::CastKind::kMemberPointerToBoolean)
    .value("REINTERPRET_MEMBER_POINTER", pasta::CastKind::kReinterpretMemberPointer)
    .value("USER_DEFINED_CONVERSION", pasta::CastKind::kUserDefinedConversion)
    .value("CONSTRUCTOR_CONVERSION", pasta::CastKind::kConstructorConversion)
    .value("INTEGRAL_TO_POINTER", pasta::CastKind::kIntegralToPointer)
    .value("POINTER_TO_INTEGRAL", pasta::CastKind::kPointerToIntegral)
    .value("POINTER_TO_BOOLEAN", pasta::CastKind::kPointerToBoolean)
    .value("TO_VOID", pasta::CastKind::kToVoid)
    .value("MATRIX_CAST", pasta::CastKind::kMatrixCast)
    .value("VECTOR_SPLAT", pasta::CastKind::kVectorSplat)
    .value("INTEGRAL_CAST", pasta::CastKind::kIntegralCast)
    .value("INTEGRAL_TO_BOOLEAN", pasta::CastKind::kIntegralToBoolean)
    .value("INTEGRAL_TO_FLOATING", pasta::CastKind::kIntegralToFloating)
    .value("FLOATING_TO_FIXED_POINT", pasta::CastKind::kFloatingToFixedPoint)
    .value("FIXED_POINT_TO_FLOATING", pasta::CastKind::kFixedPointToFloating)
    .value("FIXED_POINT_CAST", pasta::CastKind::kFixedPointCast)
    .value("FIXED_POINT_TO_INTEGRAL", pasta::CastKind::kFixedPointToIntegral)
    .value("INTEGRAL_TO_FIXED_POINT", pasta::CastKind::kIntegralToFixedPoint)
    .value("FIXED_POINT_TO_BOOLEAN", pasta::CastKind::kFixedPointToBoolean)
    .value("FLOATING_TO_INTEGRAL", pasta::CastKind::kFloatingToIntegral)
    .value("FLOATING_TO_BOOLEAN", pasta::CastKind::kFloatingToBoolean)
    .value("BOOLEAN_TO_SIGNED_INTEGRAL", pasta::CastKind::kBooleanToSignedIntegral)
    .value("FLOATING_CAST", pasta::CastKind::kFloatingCast)
    .value("C_POINTER_TO_OBJ_C_POINTER_CAST", pasta::CastKind::kCPointerToObjCPointerCast)
    .value("BLOCK_POINTER_TO_OBJ_C_POINTER_CAST", pasta::CastKind::kBlockPointerToObjCPointerCast)
    .value("ANY_POINTER_TO_BLOCK_POINTER_CAST", pasta::CastKind::kAnyPointerToBlockPointerCast)
    .value("OBJ_C_OBJECT_L_VALUE_CAST", pasta::CastKind::kObjCObjectLValueCast)
    .value("FLOATING_REAL_TO_COMPLEX", pasta::CastKind::kFloatingRealToComplex)
    .value("FLOATING_COMPLEX_TO_REAL", pasta::CastKind::kFloatingComplexToReal)
    .value("FLOATING_COMPLEX_TO_BOOLEAN", pasta::CastKind::kFloatingComplexToBoolean)
    .value("FLOATING_COMPLEX_CAST", pasta::CastKind::kFloatingComplexCast)
    .value("FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX", pasta::CastKind::kFloatingComplexToIntegralComplex)
    .value("INTEGRAL_REAL_TO_COMPLEX", pasta::CastKind::kIntegralRealToComplex)
    .value("INTEGRAL_COMPLEX_TO_REAL", pasta::CastKind::kIntegralComplexToReal)
    .value("INTEGRAL_COMPLEX_TO_BOOLEAN", pasta::CastKind::kIntegralComplexToBoolean)
    .value("INTEGRAL_COMPLEX_CAST", pasta::CastKind::kIntegralComplexCast)
    .value("INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX", pasta::CastKind::kIntegralComplexToFloatingComplex)
    .value("ARC_PRODUCE_OBJECT", pasta::CastKind::kARCProduceObject)
    .value("ARC_CONSUME_OBJECT", pasta::CastKind::kARCConsumeObject)
    .value("ARC_RECLAIM_RETURNED_OBJECT", pasta::CastKind::kARCReclaimReturnedObject)
    .value("ARC_EXTEND_BLOCK_OBJECT", pasta::CastKind::kARCExtendBlockObject)
    .value("ATOMIC_TO_NON_ATOMIC", pasta::CastKind::kAtomicToNonAtomic)
    .value("NON_ATOMIC_TO_ATOMIC", pasta::CastKind::kNonAtomicToAtomic)
    .value("COPY_AND_AUTORELEASE_BLOCK_OBJECT", pasta::CastKind::kCopyAndAutoreleaseBlockObject)
    .value("BUILTIN_FN_TO_FN_POINTER", pasta::CastKind::kBuiltinFnToFnPointer)
    .value("ZERO_TO_OCL_OPAQUE_TYPE", pasta::CastKind::kZeroToOCLOpaqueType)
    .value("ADDRESS_SPACE_CONVERSION", pasta::CastKind::kAddressSpaceConversion)
    .value("INT_TO_OCL_SAMPLER", pasta::CastKind::kIntToOCLSampler);

  nb::enum_<pasta::ClangABI>(m, "ClangABI")
    .value("VER38", pasta::ClangABI::kVer38)
    .value("VER4", pasta::ClangABI::kVer4)
    .value("VER6", pasta::ClangABI::kVer6)
    .value("VER7", pasta::ClangABI::kVer7)
    .value("VER9", pasta::ClangABI::kVer9)
    .value("VER11", pasta::ClangABI::kVer11)
    .value("VER12", pasta::ClangABI::kVer12)
    .value("VER14", pasta::ClangABI::kVer14)
    .value("VER15", pasta::ClangABI::kVer15)
    .value("LATEST", pasta::ClangABI::kLatest);

  nb::enum_<pasta::CommentKind>(m, "CommentKind")
    .value("INVALID", pasta::CommentKind::kInvalid)
    .value("ORDINARY_BCPL", pasta::CommentKind::kOrdinaryBCPL)
    .value("ORDINARY_C", pasta::CommentKind::kOrdinaryC)
    .value("BCPL_SLASH", pasta::CommentKind::kBCPLSlash)
    .value("BCPL_EXCL", pasta::CommentKind::kBCPLExcl)
    .value("JAVA_DOC", pasta::CommentKind::kJavaDoc)
    .value("QT", pasta::CommentKind::kQt)
    .value("MERGED", pasta::CommentKind::kMerged);

  nb::enum_<pasta::ComparisonCategoryResult>(m, "ComparisonCategoryResult")
    .value("EQUAL", pasta::ComparisonCategoryResult::kEqual)
    .value("EQUIVALENT", pasta::ComparisonCategoryResult::kEquivalent)
    .value("LESS", pasta::ComparisonCategoryResult::kLess)
    .value("GREATER", pasta::ComparisonCategoryResult::kGreater)
    .value("UNORDERED", pasta::ComparisonCategoryResult::kUnordered);

  nb::enum_<pasta::ComparisonCategoryType>(m, "ComparisonCategoryType")
    .value("PARTIAL_ORDERING", pasta::ComparisonCategoryType::kPartialOrdering)
    .value("WEAK_ORDERING", pasta::ComparisonCategoryType::kWeakOrdering)
    .value("STRONG_ORDERING", pasta::ComparisonCategoryType::kStrongOrdering);

  nb::enum_<pasta::CompilingModuleKind>(m, "CompilingModuleKind")
    .value("NONE", pasta::CompilingModuleKind::kNone)
    .value("MODULE_MAP", pasta::CompilingModuleKind::kModuleMap)
    .value("HEADER_UNIT", pasta::CompilingModuleKind::kHeaderUnit)
    .value("MODULE_INTERFACE", pasta::CompilingModuleKind::kModuleInterface);

  nb::enum_<pasta::ConstexprSpecKind>(m, "ConstexprSpecKind")
    .value("UNSPECIFIED", pasta::ConstexprSpecKind::kUnspecified)
    .value("CONSTEXPR", pasta::ConstexprSpecKind::kConstexpr)
    .value("CONSTEVAL", pasta::ConstexprSpecKind::kConsteval)
    .value("CONSTINIT", pasta::ConstexprSpecKind::kConstinit);

  nb::enum_<pasta::CoreFoundationABI>(m, "CoreFoundationABI")
    .value("UNSPECIFIED", pasta::CoreFoundationABI::kUnspecified)
    .value("STANDALONE", pasta::CoreFoundationABI::kStandalone)
    .value("OBJECTIVE_C", pasta::CoreFoundationABI::kObjectiveC)
    .value("SWIFT", pasta::CoreFoundationABI::kSwift)
    .value("SWIFT50", pasta::CoreFoundationABI::kSwift50)
    .value("SWIFT42", pasta::CoreFoundationABI::kSwift42)
    .value("SWIFT41", pasta::CoreFoundationABI::kSwift41);

  nb::enum_<pasta::DataPositionTy>(m, "DataPositionTy")
    .value("POSX", pasta::DataPositionTy::kPOSX)
    .value("POSV", pasta::DataPositionTy::kPOSV)
    .value("POSE", pasta::DataPositionTy::kPOSE)
    .value("POS_UPDATE_EXPRESSION", pasta::DataPositionTy::kPOSUpdateExpression)
    .value("POSD", pasta::DataPositionTy::kPOSD)
    .value("POS_CONDITION", pasta::DataPositionTy::kPOSCondition)
    .value("POSR", pasta::DataPositionTy::kPOSR);

  nb::enum_<pasta::DebugSrcHashKind>(m, "DebugSrcHashKind")
    .value("DSHMD5", pasta::DebugSrcHashKind::kDSHMD5)
    .value("DSHSHA1", pasta::DebugSrcHashKind::kDSHSHA1)
    .value("DSHSHA256", pasta::DebugSrcHashKind::kDSHSHA256);

  nb::enum_<pasta::DefaultArgKind>(m, "DefaultArgKind")
    .value("NONE", pasta::DefaultArgKind::kNone)
    .value("UNPARSED", pasta::DefaultArgKind::kUnparsed)
    .value("UNINSTANTIATED", pasta::DefaultArgKind::kUninstantiated)
    .value("NORMAL", pasta::DefaultArgKind::kNormal);

  nb::enum_<pasta::DefaultCallingConvention>(m, "DefaultCallingConvention")
    .value("NONE", pasta::DefaultCallingConvention::kNone)
    .value("C_DECL", pasta::DefaultCallingConvention::kCDecl)
    .value("FAST_CALL", pasta::DefaultCallingConvention::kFastCall)
    .value("STD_CALL", pasta::DefaultCallingConvention::kStdCall)
    .value("VECTOR_CALL", pasta::DefaultCallingConvention::kVectorCall)
    .value("REG_CALL", pasta::DefaultCallingConvention::kRegCall);

  nb::enum_<pasta::DefaultVisiblityExportMapping>(m, "DefaultVisiblityExportMapping")
    .value("NONE", pasta::DefaultVisiblityExportMapping::kNone)
    .value("EXPLICIT", pasta::DefaultVisiblityExportMapping::kExplicit)
    .value("ALL", pasta::DefaultVisiblityExportMapping::kAll);

  nb::enum_<pasta::DiagnosticLevelMask>(m, "DiagnosticLevelMask")
    .value("NONE", pasta::DiagnosticLevelMask::kNone)
    .value("NOTE", pasta::DiagnosticLevelMask::kNote)
    .value("REMARK", pasta::DiagnosticLevelMask::kRemark)
    .value("WARNING", pasta::DiagnosticLevelMask::kWarning)
    .value("ERROR", pasta::DiagnosticLevelMask::kError)
    .value("ALL", pasta::DiagnosticLevelMask::kAll);

  nb::enum_<pasta::ElaboratedTypeKeyword>(m, "ElaboratedTypeKeyword")
    .value("STRUCT", pasta::ElaboratedTypeKeyword::kStruct)
    .value("INTERFACE", pasta::ElaboratedTypeKeyword::kInterface)
    .value("UNION", pasta::ElaboratedTypeKeyword::kUnion)
    .value("CLASS", pasta::ElaboratedTypeKeyword::kClass)
    .value("ENUM", pasta::ElaboratedTypeKeyword::kEnum)
    .value("TYPENAME", pasta::ElaboratedTypeKeyword::kTypename)
    .value("NONE", pasta::ElaboratedTypeKeyword::kNone);

  nb::enum_<pasta::EmbedBitcodeKind>(m, "EmbedBitcodeKind")
    .value("EMBED_OFF", pasta::EmbedBitcodeKind::kEmbedOff)
    .value("EMBED_ALL", pasta::EmbedBitcodeKind::kEmbedAll)
    .value("EMBED_BITCODE", pasta::EmbedBitcodeKind::kEmbedBitcode)
    .value("EMBED_MARKER", pasta::EmbedBitcodeKind::kEmbedMarker);

  nb::enum_<pasta::EscapeChar>(m, "EscapeChar")
    .value("SINGLE", pasta::EscapeChar::kSingle)
    .value("DOUBLE", pasta::EscapeChar::kDouble)
    .value("SINGLE_AND_DOUBLE", pasta::EscapeChar::kSingleAndDouble);

  nb::enum_<pasta::ExceptionHandlingKind>(m, "ExceptionHandlingKind")
    .value("NONE", pasta::ExceptionHandlingKind::kNone)
    .value("SJ_LJ", pasta::ExceptionHandlingKind::kSjLj)
    .value("WIN_EH", pasta::ExceptionHandlingKind::kWinEH)
    .value("DWARF_CFI", pasta::ExceptionHandlingKind::kDwarfCFI)
    .value("WASM", pasta::ExceptionHandlingKind::kWasm);

  nb::enum_<pasta::ExceptionSpecificationType>(m, "ExceptionSpecificationType")
    .value("NONE", pasta::ExceptionSpecificationType::kNone)
    .value("DYNAMIC_NONE", pasta::ExceptionSpecificationType::kDynamicNone)
    .value("DYNAMIC", pasta::ExceptionSpecificationType::kDynamic)
    .value("MS_ANY", pasta::ExceptionSpecificationType::kMSAny)
    .value("NO_THROW", pasta::ExceptionSpecificationType::kNoThrow)
    .value("BASIC_NOEXCEPT", pasta::ExceptionSpecificationType::kBasicNoexcept)
    .value("DEPENDENT_NOEXCEPT", pasta::ExceptionSpecificationType::kDependentNoexcept)
    .value("NOEXCEPT_FALSE", pasta::ExceptionSpecificationType::kNoexceptFalse)
    .value("NOEXCEPT_TRUE", pasta::ExceptionSpecificationType::kNoexceptTrue)
    .value("UNEVALUATED", pasta::ExceptionSpecificationType::kUnevaluated)
    .value("UNINSTANTIATED", pasta::ExceptionSpecificationType::kUninstantiated)
    .value("UNPARSED", pasta::ExceptionSpecificationType::kUnparsed);

  nb::enum_<pasta::ExcessPrecisionKind>(m, "ExcessPrecisionKind")
    .value("FPP_STANDARD", pasta::ExcessPrecisionKind::kFPPStandard)
    .value("FPP_FAST", pasta::ExcessPrecisionKind::kFPPFast)
    .value("FPP_NONE", pasta::ExcessPrecisionKind::kFPPNone);

  nb::enum_<pasta::ExclusionType>(m, "ExclusionType")
    .value("ALLOW", pasta::ExclusionType::kAllow)
    .value("SKIP", pasta::ExclusionType::kSkip)
    .value("FORBID", pasta::ExclusionType::kForbid);

  nb::enum_<pasta::ExplicitSpecKind>(m, "ExplicitSpecKind")
    .value("RESOLVED_FALSE", pasta::ExplicitSpecKind::kResolvedFalse)
    .value("RESOLVED_TRUE", pasta::ExplicitSpecKind::kResolvedTrue)
    .value("UNRESOLVED", pasta::ExplicitSpecKind::kUnresolved);

  nb::enum_<pasta::ExprDependence>(m, "ExprDependence")
    .value("UNEXPANDED_PACK", pasta::ExprDependence::kUnexpandedPack)
    .value("INSTANTIATION", pasta::ExprDependence::kInstantiation)
    .value("TYPE", pasta::ExprDependence::kType)
    .value("VALUE", pasta::ExprDependence::kValue)
    .value("ERROR", pasta::ExprDependence::kError)
    .value("NONE", pasta::ExprDependence::kNone)
    .value("ALL", pasta::ExprDependence::kAll)
    .value("TYPE_VALUE", pasta::ExprDependence::kTypeValue)
    .value("TYPE_INSTANTIATION", pasta::ExprDependence::kTypeInstantiation)
    .value("VALUE_INSTANTIATION", pasta::ExprDependence::kValueInstantiation)
    .value("TYPE_VALUE_INSTANTIATION", pasta::ExprDependence::kTypeValueInstantiation)
    .value("ERROR_DEPENDENT", pasta::ExprDependence::kErrorDependent);

  nb::enum_<pasta::ExprObjectKind>(m, "ExprObjectKind")
    .value("ORDINARY", pasta::ExprObjectKind::kOrdinary)
    .value("BIT_FIELD", pasta::ExprObjectKind::kBitField)
    .value("VECTOR_COMPONENT", pasta::ExprObjectKind::kVectorComponent)
    .value("OBJ_C_PROPERTY", pasta::ExprObjectKind::kObjCProperty)
    .value("OBJ_C_SUBSCRIPT", pasta::ExprObjectKind::kObjCSubscript)
    .value("MATRIX_COMPONENT", pasta::ExprObjectKind::kMatrixComponent);

  nb::enum_<pasta::ExprOffsets>(m, "ExprOffsets")
    .value("ALLOCATOR", pasta::ExprOffsets::kAllocator)
    .value("ALLOCATOR_TRAITS", pasta::ExprOffsets::kAllocatorTraits)
    .value("TOTAL", pasta::ExprOffsets::kTotal);

  nb::enum_<pasta::ExprValueKind>(m, "ExprValueKind")
    .value("PR_VALUE", pasta::ExprValueKind::kPRValue)
    .value("L_VALUE", pasta::ExprValueKind::kLValue)
    .value("X_VALUE", pasta::ExprValueKind::kXValue);

  nb::enum_<pasta::ExpressionTrait>(m, "ExpressionTrait")
    .value("IS_L_VALUE_EXPRESSION", pasta::ExpressionTrait::kIsLValueExpression)
    .value("IS_R_VALUE_EXPRESSION", pasta::ExpressionTrait::kIsRValueExpression);

  nb::enum_<pasta::ExtKind>(m, "ExtKind")
    .value("ALWAYS", pasta::ExtKind::kAlways)
    .value("NEVER", pasta::ExtKind::kNever)
    .value("REPLY_HAZY", pasta::ExtKind::kReplyHazy);

  nb::enum_<pasta::ExtendArgsKind>(m, "ExtendArgsKind")
    .value("EXTEND_TO32", pasta::ExtendArgsKind::kExtendTo32)
    .value("EXTEND_TO64", pasta::ExtendArgsKind::kExtendTo64);

  nb::enum_<pasta::FPEvalMethodKind>(m, "FPEvalMethodKind")
    .value("FEM_INDETERMINABLE", pasta::FPEvalMethodKind::kFEMIndeterminable)
    .value("FEM_SOURCE", pasta::FPEvalMethodKind::kFEMSource)
    .value("FEM_DOUBLE", pasta::FPEvalMethodKind::kFEMDouble)
    .value("FEM_EXTENDED", pasta::FPEvalMethodKind::kFEMExtended)
    .value("FEM_UNSET_ON_COMMAND_LINE", pasta::FPEvalMethodKind::kFEMUnsetOnCommandLine);

  nb::enum_<pasta::FPExceptionModeKind>(m, "FPExceptionModeKind")
    .value("IGNORE", pasta::FPExceptionModeKind::kIgnore)
    .value("MAY_TRAP", pasta::FPExceptionModeKind::kMayTrap)
    .value("STRICT", pasta::FPExceptionModeKind::kStrict)
    .value("DEFAULT", pasta::FPExceptionModeKind::kDefault);

  nb::enum_<pasta::FPModeKind>(m, "FPModeKind")
    .value("OFF", pasta::FPModeKind::kOff)
    .value("ON", pasta::FPModeKind::kOn)
    .value("FAST", pasta::FPModeKind::kFast)
    .value("FAST_HONOR_PRAGMAS", pasta::FPModeKind::kFastHonorPragmas);

  nb::enum_<pasta::FiniteLoopsKind>(m, "FiniteLoopsKind")
    .value("LANGUAGE", pasta::FiniteLoopsKind::kLanguage)
    .value("ALWAYS", pasta::FiniteLoopsKind::kAlways)
    .value("NEVER", pasta::FiniteLoopsKind::kNever);

  nb::enum_<pasta::Flags>(m, "Flags")
    .value("F_INLINE", pasta::Flags::kFInline)
    .value("F_NESTED", pasta::Flags::kFNested);

  nb::enum_<pasta::FramePointerKind>(m, "FramePointerKind")
    .value("NONE", pasta::FramePointerKind::kNone)
    .value("NON_LEAF", pasta::FramePointerKind::kNonLeaf)
    .value("ALL", pasta::FramePointerKind::kAll);

  nb::enum_<pasta::GC>(m, "GC")
    .value("GC_NONE", pasta::GC::kGCNone)
    .value("WEAK", pasta::GC::kWeak)
    .value("STRONG", pasta::GC::kStrong);

  nb::enum_<pasta::GCMode>(m, "GCMode")
    .value("NON_GC", pasta::GCMode::kNonGC)
    .value("GC_ONLY", pasta::GCMode::kGCOnly)
    .value("HYBRID_GC", pasta::GCMode::kHybridGC);

  nb::enum_<pasta::GPUDefaultStreamKind>(m, "GPUDefaultStreamKind")
    .value("LEGACY", pasta::GPUDefaultStreamKind::kLegacy)
    .value("PER_THREAD", pasta::GPUDefaultStreamKind::kPerThread);

  nb::enum_<pasta::GVALinkage>(m, "GVALinkage")
    .value("INTERNAL", pasta::GVALinkage::kInternal)
    .value("AVAILABLE_EXTERNALLY", pasta::GVALinkage::kAvailableExternally)
    .value("DISCARDABLE_ODR", pasta::GVALinkage::kDiscardableODR)
    .value("STRONG_EXTERNAL", pasta::GVALinkage::kStrongExternal)
    .value("STRONG_ODR", pasta::GVALinkage::kStrongODR);

  nb::enum_<pasta::GetBuiltinTypeError>(m, "GetBuiltinTypeError")
    .value("NONE", pasta::GetBuiltinTypeError::kNone)
    .value("MISSING_TYPE", pasta::GetBuiltinTypeError::kMissingType)
    .value("MISSING_STDIO", pasta::GetBuiltinTypeError::kMissingStdio)
    .value("MISSING", pasta::GetBuiltinTypeError::kMissing)
    .value("MISSING_UCONTEXT", pasta::GetBuiltinTypeError::kMissingUcontext);

  nb::enum_<pasta::HLSLLangStd>(m, "HLSLLangStd")
    .value("HLSL_UNSET", pasta::HLSLLangStd::kHLSLUnset)
    .value("HLSL2015", pasta::HLSLLangStd::kHLSL2015)
    .value("HLSL2016", pasta::HLSLLangStd::kHLSL2016)
    .value("HLSL2017", pasta::HLSLLangStd::kHLSL2017)
    .value("HLSL2018", pasta::HLSLLangStd::kHLSL2018)
    .value("HLSL2021", pasta::HLSLLangStd::kHLSL2021)
    .value("HLSL202X", pasta::HLSLLangStd::kHLSL202x);

  nb::enum_<pasta::ID>(m, "ID")
    .value("WORK_GROUP", pasta::ID::kWorkGroup)
    .value("DEVICE", pasta::ID::kDevice)
    .value("ALL_SVM_DEVICES", pasta::ID::kAllSVMDevices)
    .value("SUB_GROUP", pasta::ID::kSubGroup);

  nb::enum_<pasta::IdentifierInfoFlag>(m, "IdentifierInfoFlag")
    .value("ZERO_ARGUMENT", pasta::IdentifierInfoFlag::kZeroArgument)
    .value("ONE_ARGUMENT", pasta::IdentifierInfoFlag::kOneArgument)
    .value("MULTI_ARGUMENT", pasta::IdentifierInfoFlag::kMultiArgument)
    .value("ARGUMENT_FLAGS", pasta::IdentifierInfoFlag::kArgumentFlags);

  nb::enum_<pasta::IfStatementKind>(m, "IfStatementKind")
    .value("ORDINARY", pasta::IfStatementKind::kOrdinary)
    .value("CONSTEXPR", pasta::IfStatementKind::kConstexpr)
    .value("CONSTEVAL_NON_NEGATED", pasta::IfStatementKind::kConstevalNonNegated)
    .value("CONSTEVAL_NEGATED", pasta::IfStatementKind::kConstevalNegated);

  nb::enum_<pasta::ImbueAttribute>(m, "ImbueAttribute")
    .value("NONE", pasta::ImbueAttribute::kNONE)
    .value("ALWAYS", pasta::ImbueAttribute::kALWAYS)
    .value("NEVER", pasta::ImbueAttribute::kNEVER)
    .value("ALWAYSARG1", pasta::ImbueAttribute::kALWAYSARG1);

  nb::enum_<pasta::InClassInitStyle>(m, "InClassInitStyle")
    .value("NO_INITIALIZER", pasta::InClassInitStyle::kNoInitializer)
    .value("COPY_INITIALIZER", pasta::InClassInitStyle::kCopyInitializer)
    .value("LIST_INITIALIZER", pasta::InClassInitStyle::kListInitializer);

  nb::enum_<pasta::InheritedDesignatedInitializersState>(m, "InheritedDesignatedInitializersState")
    .value("UNKNOWN", pasta::InheritedDesignatedInitializersState::kUnknown)
    .value("INHERITED", pasta::InheritedDesignatedInitializersState::kInherited)
    .value("NOT_INHERITED", pasta::InheritedDesignatedInitializersState::kNotInherited);

  nb::enum_<pasta::InitStorageKind>(m, "InitStorageKind")
    .value("NO_INITIALIZER", pasta::InitStorageKind::kNoInitializer)
    .value("IN_CLASS_COPY_INITIALIZER", pasta::InitStorageKind::kInClassCopyInitializer)
    .value("IN_CLASS_LIST_INITIALIZER", pasta::InitStorageKind::kInClassListInitializer)
    .value("CAPTURED_VLA_TYPE", pasta::InitStorageKind::kCapturedVLAType);

  nb::enum_<pasta::InlineAsmDialectKind>(m, "InlineAsmDialectKind")
    .value("IADATT", pasta::InlineAsmDialectKind::kIADATT)
    .value("IAD_INTEL", pasta::InlineAsmDialectKind::kIADIntel);

  nb::enum_<pasta::InlineVariableDefinitionKind>(m, "InlineVariableDefinitionKind")
    .value("NONE", pasta::InlineVariableDefinitionKind::kNone)
    .value("WEAK", pasta::InlineVariableDefinitionKind::kWeak)
    .value("WEAK_UNKNOWN", pasta::InlineVariableDefinitionKind::kWeakUnknown)
    .value("STRONG", pasta::InlineVariableDefinitionKind::kStrong);

  nb::enum_<pasta::InliningMethod>(m, "InliningMethod")
    .value("NORMAL_INLINING", pasta::InliningMethod::kNormalInlining)
    .value("ONLY_HINT_INLINING", pasta::InliningMethod::kOnlyHintInlining)
    .value("ONLY_ALWAYS_INLINING", pasta::InliningMethod::kOnlyAlwaysInlining);

  nb::enum_<pasta::Kinds>(m, "Kinds")
    .value("L_VALUE", pasta::Kinds::kLValue)
    .value("X_VALUE", pasta::Kinds::kXValue)
    .value("FUNCTION", pasta::Kinds::kFunction)
    .value("VOID", pasta::Kinds::kVoid)
    .value("ADDRESSABLE_VOID", pasta::Kinds::kAddressableVoid)
    .value("DUPLICATE_VECTOR_COMPONENTS", pasta::Kinds::kDuplicateVectorComponents)
    .value("MEMBER_FUNCTION", pasta::Kinds::kMemberFunction)
    .value("SUB_OBJ_C_PROPERTY_SETTING", pasta::Kinds::kSubObjCPropertySetting)
    .value("CLASS_TEMPORARY", pasta::Kinds::kClassTemporary)
    .value("ARRAY_TEMPORARY", pasta::Kinds::kArrayTemporary)
    .value("OBJ_C_MESSAGE_R_VALUE", pasta::Kinds::kObjCMessageRValue)
    .value("PR_VALUE", pasta::Kinds::kPRValue);

  nb::enum_<pasta::LambdaCaptureDefault>(m, "LambdaCaptureDefault")
    .value("NONE", pasta::LambdaCaptureDefault::kNone)
    .value("BY_COPY", pasta::LambdaCaptureDefault::kByCopy)
    .value("BY_REFERENCE", pasta::LambdaCaptureDefault::kByReference);

  nb::enum_<pasta::LambdaCaptureKind>(m, "LambdaCaptureKind")
    .value("THIS", pasta::LambdaCaptureKind::kThis)
    .value("STAR_THIS", pasta::LambdaCaptureKind::kStarThis)
    .value("BY_COPY", pasta::LambdaCaptureKind::kByCopy)
    .value("BY_REFERENCE", pasta::LambdaCaptureKind::kByReference)
    .value("VLA_TYPE", pasta::LambdaCaptureKind::kVLAType);

  nb::enum_<pasta::LangAS>(m, "LangAS")
    .value("DEFAULT", pasta::LangAS::kDefault)
    .value("OPENCL_GLOBAL", pasta::LangAS::kOpenclGlobal)
    .value("OPENCL_LOCAL", pasta::LangAS::kOpenclLocal)
    .value("OPENCL_CONSTANT", pasta::LangAS::kOpenclConstant)
    .value("OPENCL_PRIVATE", pasta::LangAS::kOpenclPrivate)
    .value("OPENCL_GENERIC", pasta::LangAS::kOpenclGeneric)
    .value("OPENCL_GLOBAL_DEVICE", pasta::LangAS::kOpenclGlobalDevice)
    .value("OPENCL_GLOBAL_HOST", pasta::LangAS::kOpenclGlobalHost)
    .value("CUDA_DEVICE", pasta::LangAS::kCudaDevice)
    .value("CUDA_CONSTANT", pasta::LangAS::kCudaConstant)
    .value("CUDA_SHARED", pasta::LangAS::kCudaShared)
    .value("SYCL_GLOBAL", pasta::LangAS::kSyclGlobal)
    .value("SYCL_GLOBAL_DEVICE", pasta::LangAS::kSyclGlobalDevice)
    .value("SYCL_GLOBAL_HOST", pasta::LangAS::kSyclGlobalHost)
    .value("SYCL_LOCAL", pasta::LangAS::kSyclLocal)
    .value("SYCL_PRIVATE", pasta::LangAS::kSyclPrivate)
    .value("PTR32_SPTR", pasta::LangAS::kPtr32Sptr)
    .value("PTR32_UPTR", pasta::LangAS::kPtr32Uptr)
    .value("PTR64", pasta::LangAS::kPtr64)
    .value("HLSL_GROUPSHARED", pasta::LangAS::kHlslGroupshared);

  nb::enum_<pasta::LangFeatures>(m, "LangFeatures")
    .value("LINE_COMMENT", pasta::LangFeatures::kLineComment)
    .value("C99", pasta::LangFeatures::kC99)
    .value("C11", pasta::LangFeatures::kC11)
    .value("C17", pasta::LangFeatures::kC17)
    .value("C2X", pasta::LangFeatures::kC2x)
    .value("C_PLUS_PLUS", pasta::LangFeatures::kCPlusPlus)
    .value("C_PLUS_PLUS11", pasta::LangFeatures::kCPlusPlus11)
    .value("C_PLUS_PLUS14", pasta::LangFeatures::kCPlusPlus14)
    .value("C_PLUS_PLUS17", pasta::LangFeatures::kCPlusPlus17)
    .value("C_PLUS_PLUS20", pasta::LangFeatures::kCPlusPlus20)
    .value("C_PLUS_PLUS2B", pasta::LangFeatures::kCPlusPlus2b)
    .value("DIGRAPHS", pasta::LangFeatures::kDigraphs)
    .value("GNU_MODE", pasta::LangFeatures::kGNUMode)
    .value("HEX_FLOAT", pasta::LangFeatures::kHexFloat)
    .value("OPEN_CL", pasta::LangFeatures::kOpenCL)
    .value("HLSL", pasta::LangFeatures::kHLSL);

  nb::enum_<pasta::Language>(m, "Language")
    .value("UNKNOWN", pasta::Language::kUnknown)
    .value("ASSEMBLY", pasta::Language::kAssembly)
    .value("LLVMIR", pasta::Language::kLLVMIR)
    .value("C", pasta::Language::kC)
    .value("CXX", pasta::Language::kCXX)
    .value("OBJ_C", pasta::Language::kObjC)
    .value("OBJ_CXX", pasta::Language::kObjCXX)
    .value("OPEN_CL", pasta::Language::kOpenCL)
    .value("OPEN_CLCXX", pasta::Language::kOpenCLCXX)
    .value("CUDA", pasta::Language::kCUDA)
    .value("RENDER_SCRIPT", pasta::Language::kRenderScript)
    .value("HIP", pasta::Language::kHIP)
    .value("HLSL", pasta::Language::kHLSL);

  nb::enum_<pasta::LanguageLinkage>(m, "LanguageLinkage")
    .value("C_LANGUAGE_LINKAGE", pasta::LanguageLinkage::kCLanguageLinkage)
    .value("CXX_LANGUAGE_LINKAGE", pasta::LanguageLinkage::kCXXLanguageLinkage)
    .value("NO_LANGUAGE_LINKAGE", pasta::LanguageLinkage::kNoLanguageLinkage);

  nb::enum_<pasta::LaxVectorConversionKind>(m, "LaxVectorConversionKind")
    .value("NONE", pasta::LaxVectorConversionKind::kNone)
    .value("INTEGER", pasta::LaxVectorConversionKind::kInteger)
    .value("ALL", pasta::LaxVectorConversionKind::kAll);

  nb::enum_<pasta::Level>(m, "Level")
    .value("IGNORED", pasta::Level::kIgnored)
    .value("NOTE", pasta::Level::kNote)
    .value("REMARK", pasta::Level::kRemark)
    .value("WARNING", pasta::Level::kWarning)
    .value("ERROR", pasta::Level::kError)
    .value("FATAL", pasta::Level::kFatal);

  nb::enum_<pasta::Linkage>(m, "Linkage")
    .value("NO_LINKAGE", pasta::Linkage::kNoLinkage)
    .value("INTERNAL_LINKAGE", pasta::Linkage::kInternalLinkage)
    .value("UNIQUE_EXTERNAL_LINKAGE", pasta::Linkage::kUniqueExternalLinkage)
    .value("VISIBLE_NO_LINKAGE", pasta::Linkage::kVisibleNoLinkage)
    .value("MODULE_INTERNAL_LINKAGE", pasta::Linkage::kModuleInternalLinkage)
    .value("MODULE_LINKAGE", pasta::Linkage::kModuleLinkage)
    .value("EXTERNAL_LINKAGE", pasta::Linkage::kExternalLinkage);

  nb::enum_<pasta::MSInheritanceModel>(m, "MSInheritanceModel")
    .value("SINGLE", pasta::MSInheritanceModel::kSingle)
    .value("MULTIPLE", pasta::MSInheritanceModel::kMultiple)
    .value("VIRTUAL", pasta::MSInheritanceModel::kVirtual)
    .value("UNSPECIFIED", pasta::MSInheritanceModel::kUnspecified);

  nb::enum_<pasta::MSVCMajorVersion>(m, "MSVCMajorVersion")
    .value("MSVC2010", pasta::MSVCMajorVersion::kMSVC2010)
    .value("MSVC2012", pasta::MSVCMajorVersion::kMSVC2012)
    .value("MSVC2013", pasta::MSVCMajorVersion::kMSVC2013)
    .value("MSVC2015", pasta::MSVCMajorVersion::kMSVC2015)
    .value("MSVC2017", pasta::MSVCMajorVersion::kMSVC2017)
    .value("MSVC20175", pasta::MSVCMajorVersion::kMSVC20175)
    .value("MSVC20177", pasta::MSVCMajorVersion::kMSVC20177)
    .value("MSVC2019", pasta::MSVCMajorVersion::kMSVC2019)
    .value("MSVC20195", pasta::MSVCMajorVersion::kMSVC20195)
    .value("MSVC20198", pasta::MSVCMajorVersion::kMSVC20198);

  nb::enum_<pasta::MSVtorDispMode>(m, "MSVtorDispMode")
    .value("NEVER", pasta::MSVtorDispMode::kNever)
    .value("FOR_VIRTUAL_BASE_OVERRIDE", pasta::MSVtorDispMode::kForVirtualBaseOverride)
    .value("FOR_VF_TABLE", pasta::MSVtorDispMode::kForVFTable);

  nb::enum_<pasta::MethodRefFlags>(m, "MethodRefFlags")
    .value("METHOD_REFERENCE_NONE", pasta::MethodRefFlags::kMethodReferenceNone)
    .value("METHOD_REFERENCE_GETTER", pasta::MethodRefFlags::kMethodReferenceGetter)
    .value("METHOD_REFERENCE_SETTER", pasta::MethodRefFlags::kMethodReferenceSetter);

  nb::enum_<pasta::ModifiableType>(m, "ModifiableType")
    .value("UNTESTED", pasta::ModifiableType::kUntested)
    .value("MODIFIABLE", pasta::ModifiableType::kModifiable)
    .value("R_VALUE", pasta::ModifiableType::kRValue)
    .value("FUNCTION", pasta::ModifiableType::kFunction)
    .value("L_VALUE_CAST", pasta::ModifiableType::kLValueCast)
    .value("NO_SETTER_PROPERTY", pasta::ModifiableType::kNoSetterProperty)
    .value("CONST_QUALIFIED", pasta::ModifiableType::kConstQualified)
    .value("CONST_QUALIFIED_FIELD", pasta::ModifiableType::kConstQualifiedField)
    .value("CONST_ADDRESS_SPACE", pasta::ModifiableType::kConstAddressSpace)
    .value("ARRAY_TYPE", pasta::ModifiableType::kArrayType)
    .value("INCOMPLETE_TYPE", pasta::ModifiableType::kIncompleteType);

  nb::enum_<pasta::MultiVersionKind>(m, "MultiVersionKind")
    .value("NONE", pasta::MultiVersionKind::kNone)
    .value("TARGET", pasta::MultiVersionKind::kTarget)
    .value("CPU_SPECIFIC", pasta::MultiVersionKind::kCPUSpecific)
    .value("CPU_DISPATCH", pasta::MultiVersionKind::kCPUDispatch)
    .value("TARGET_CLONES", pasta::MultiVersionKind::kTargetClones)
    .value("TARGET_VERSION", pasta::MultiVersionKind::kTargetVersion);

  nb::enum_<pasta::NameKind>(m, "NameKind")
    .value("TEMPLATE", pasta::NameKind::kTemplate)
    .value("OVERLOADED_TEMPLATE", pasta::NameKind::kOverloadedTemplate)
    .value("ASSUMED_TEMPLATE", pasta::NameKind::kAssumedTemplate)
    .value("QUALIFIED_TEMPLATE", pasta::NameKind::kQualifiedTemplate)
    .value("DEPENDENT_TEMPLATE", pasta::NameKind::kDependentTemplate)
    .value("SUBST_TEMPLATE_TEMPLATE_PARM", pasta::NameKind::kSubstTemplateTemplateParm)
    .value("SUBST_TEMPLATE_TEMPLATE_PARM_PACK", pasta::NameKind::kSubstTemplateTemplateParmPack)
    .value("USING_TEMPLATE", pasta::NameKind::kUsingTemplate);

  nb::enum_<pasta::NeedExtraManglingDecl>(m, "NeedExtraManglingDecl")
    .value("NEED_EXTRA_MANGLING_DECLARATION", pasta::NeedExtraManglingDecl::kNeedExtraManglingDeclaration);

  nb::enum_<pasta::NestedNameSpecifierDependence>(m, "NestedNameSpecifierDependence")
    .value("UNEXPANDED_PACK", pasta::NestedNameSpecifierDependence::kUnexpandedPack)
    .value("INSTANTIATION", pasta::NestedNameSpecifierDependence::kInstantiation)
    .value("DEPENDENT", pasta::NestedNameSpecifierDependence::kDependent)
    .value("ERROR", pasta::NestedNameSpecifierDependence::kError)
    .value("NONE", pasta::NestedNameSpecifierDependence::kNone)
    .value("DEPENDENT_INSTANTIATION", pasta::NestedNameSpecifierDependence::kDependentInstantiation)
    .value("ALL", pasta::NestedNameSpecifierDependence::kAll);

  nb::enum_<pasta::NonOdrUseReason>(m, "NonOdrUseReason")
    .value("NONE", pasta::NonOdrUseReason::kNone)
    .value("UNEVALUATED", pasta::NonOdrUseReason::kUnevaluated)
    .value("CONSTANT", pasta::NonOdrUseReason::kConstant)
    .value("DISCARDED", pasta::NonOdrUseReason::kDiscarded);

  nb::enum_<pasta::NonceObjCInterface>(m, "NonceObjCInterface")
    .value("OBJ_C_INTERFACE", pasta::NonceObjCInterface::kObjCInterface);

  nb::enum_<pasta::NullabilityKind>(m, "NullabilityKind")
    .value("NON_NULL", pasta::NullabilityKind::kNonNull)
    .value("NULLABLE", pasta::NullabilityKind::kNullable)
    .value("UNSPECIFIED", pasta::NullabilityKind::kUnspecified)
    .value("NULLABLE_RESULT", pasta::NullabilityKind::kNullableResult);

  nb::enum_<pasta::ObjCBridgeCastKind>(m, "ObjCBridgeCastKind")
    .value("BRIDGE", pasta::ObjCBridgeCastKind::kBridge)
    .value("BRIDGE_TRANSFER", pasta::ObjCBridgeCastKind::kBridgeTransfer)
    .value("BRIDGE_RETAINED", pasta::ObjCBridgeCastKind::kBridgeRetained);

  nb::enum_<pasta::ObjCDispatchMethodKind>(m, "ObjCDispatchMethodKind")
    .value("LEGACY", pasta::ObjCDispatchMethodKind::kLegacy)
    .value("NON_LEGACY", pasta::ObjCDispatchMethodKind::kNonLegacy)
    .value("MIXED", pasta::ObjCDispatchMethodKind::kMixed);

  nb::enum_<pasta::ObjCInstanceTypeFamily>(m, "ObjCInstanceTypeFamily")
    .value("NONE", pasta::ObjCInstanceTypeFamily::kNone)
    .value("ARRAY", pasta::ObjCInstanceTypeFamily::kArray)
    .value("DICTIONARY", pasta::ObjCInstanceTypeFamily::kDictionary)
    .value("SINGLETON", pasta::ObjCInstanceTypeFamily::kSingleton)
    .value("INITIALIZER", pasta::ObjCInstanceTypeFamily::kInitializer)
    .value("RETURNS_SELF", pasta::ObjCInstanceTypeFamily::kReturnsSelf);

  nb::enum_<pasta::ObjCKeywordKind>(m, "ObjCKeywordKind")
    .value("NOT_KEYWORD", pasta::ObjCKeywordKind::kNotKeyword)
    .value("CLASS", pasta::ObjCKeywordKind::kClass)
    .value("COMPATIBILITY_ALIAS", pasta::ObjCKeywordKind::kCompatibilityAlias)
    .value("DEFINITIONS", pasta::ObjCKeywordKind::kDefinitions)
    .value("ENCODE", pasta::ObjCKeywordKind::kEncode)
    .value("OBJC_END", pasta::ObjCKeywordKind::kObjcEnd)
    .value("IMPLEMENTATION", pasta::ObjCKeywordKind::kImplementation)
    .value("INTERFACE", pasta::ObjCKeywordKind::kInterface)
    .value("PRIVATE", pasta::ObjCKeywordKind::kPrivate)
    .value("PROTECTED", pasta::ObjCKeywordKind::kProtected)
    .value("PROTOCOL", pasta::ObjCKeywordKind::kProtocol)
    .value("PUBLIC", pasta::ObjCKeywordKind::kPublic)
    .value("SELECTOR", pasta::ObjCKeywordKind::kSelector)
    .value("THROW", pasta::ObjCKeywordKind::kThrow)
    .value("TRY", pasta::ObjCKeywordKind::kTry)
    .value("CATCH", pasta::ObjCKeywordKind::kCatch)
    .value("FINALLY", pasta::ObjCKeywordKind::kFinally)
    .value("SYNCHRONIZED", pasta::ObjCKeywordKind::kSynchronized)
    .value("AUTORELEASEPOOL", pasta::ObjCKeywordKind::kAutoreleasepool)
    .value("PROPERTY", pasta::ObjCKeywordKind::kProperty)
    .value("PACKAGE", pasta::ObjCKeywordKind::kPackage)
    .value("REQUIRED", pasta::ObjCKeywordKind::kRequired)
    .value("OPTIONAL", pasta::ObjCKeywordKind::kOptional)
    .value("SYNTHESIZE", pasta::ObjCKeywordKind::kSynthesize)
    .value("DYNAMIC", pasta::ObjCKeywordKind::kDynamic)
    .value("IMPORT", pasta::ObjCKeywordKind::kImport)
    .value("AVAILABLE", pasta::ObjCKeywordKind::kAvailable);

  nb::enum_<pasta::ObjCLifetime>(m, "ObjCLifetime")
    .value("NONE", pasta::ObjCLifetime::kNone)
    .value("EXPLICIT_NONE", pasta::ObjCLifetime::kExplicitNone)
    .value("STRONG", pasta::ObjCLifetime::kStrong)
    .value("WEAK", pasta::ObjCLifetime::kWeak)
    .value("AUTORELEASING", pasta::ObjCLifetime::kAutoreleasing);

  nb::enum_<pasta::ObjCMethodFamily>(m, "ObjCMethodFamily")
    .value("NONE", pasta::ObjCMethodFamily::kNone)
    .value("ALLOC", pasta::ObjCMethodFamily::kAlloc)
    .value("COPY", pasta::ObjCMethodFamily::kCopy)
    .value("INITIALIZER", pasta::ObjCMethodFamily::kInitializer)
    .value("MUTABLE_COPY", pasta::ObjCMethodFamily::kMutableCopy)
    .value("NEW", pasta::ObjCMethodFamily::kNew)
    .value("AUTORELEASE", pasta::ObjCMethodFamily::kAutorelease)
    .value("DEALLOC", pasta::ObjCMethodFamily::kDealloc)
    .value("FINALIZE", pasta::ObjCMethodFamily::kFinalize)
    .value("RELEASE", pasta::ObjCMethodFamily::kRelease)
    .value("RETAIN", pasta::ObjCMethodFamily::kRetain)
    .value("RETAIN_COUNT", pasta::ObjCMethodFamily::kRetainCount)
    .value("SELF", pasta::ObjCMethodFamily::kSelf)
    .value("INITIALIZE", pasta::ObjCMethodFamily::kInitialize)
    .value("PERFORM_SELECTOR", pasta::ObjCMethodFamily::kPerformSelector);

  nb::enum_<pasta::ObjCPropertyQueryKind>(m, "ObjCPropertyQueryKind")
    .value("QUERY_UNKNOWN", pasta::ObjCPropertyQueryKind::kQueryUnknown)
    .value("QUERY_INSTANCE", pasta::ObjCPropertyQueryKind::kQueryInstance)
    .value("QUERY_CLASS", pasta::ObjCPropertyQueryKind::kQueryClass);

  nb::enum_<pasta::ObjCStringFormatFamily>(m, "ObjCStringFormatFamily")
    .value("NONE", pasta::ObjCStringFormatFamily::kNone)
    .value("NS_STRING", pasta::ObjCStringFormatFamily::kNSString)
    .value("CF_STRING", pasta::ObjCStringFormatFamily::kCFString);

  nb::enum_<pasta::ObjCSubstitutionContext>(m, "ObjCSubstitutionContext")
    .value("ORDINARY", pasta::ObjCSubstitutionContext::kOrdinary)
    .value("RESULT", pasta::ObjCSubstitutionContext::kResult)
    .value("PARAMETER", pasta::ObjCSubstitutionContext::kParameter)
    .value("PROPERTY", pasta::ObjCSubstitutionContext::kProperty)
    .value("SUPERCLASS", pasta::ObjCSubstitutionContext::kSuperclass);

  nb::enum_<pasta::ObjCTypeParamVariance>(m, "ObjCTypeParamVariance")
    .value("INVARIANT", pasta::ObjCTypeParamVariance::kInvariant)
    .value("COVARIANT", pasta::ObjCTypeParamVariance::kCovariant)
    .value("CONTRAVARIANT", pasta::ObjCTypeParamVariance::kContravariant);

  nb::enum_<pasta::OnOffSwitch>(m, "OnOffSwitch")
    .value("ON", pasta::OnOffSwitch::kON)
    .value("OFF", pasta::OnOffSwitch::kOFF)
    .value("DEFAULT", pasta::OnOffSwitch::kDEFAULT);

  nb::enum_<pasta::OnStackType>(m, "OnStackType")
    .value("ON_STACK", pasta::OnStackType::kOnStack);

  nb::enum_<pasta::OpenMPAdjustArgsOpKind>(m, "OpenMPAdjustArgsOpKind")
    .value("ADJUSTARGS_NOTHING", pasta::OpenMPAdjustArgsOpKind::kADJUSTARGSNothing)
    .value("ADJUSTARGS_NEED_DEVICE_POINTER", pasta::OpenMPAdjustArgsOpKind::kADJUSTARGSNeedDevicePointer)
    .value("ADJUSTARGS_UNKNOWN", pasta::OpenMPAdjustArgsOpKind::kADJUSTARGSUnknown);

  nb::enum_<pasta::OpenMPAtClauseKind>(m, "OpenMPAtClauseKind")
    .value("AT_COMPILATION", pasta::OpenMPAtClauseKind::kATCompilation)
    .value("AT_EXECUTION", pasta::OpenMPAtClauseKind::kATExecution)
    .value("AT_UNKNOWN", pasta::OpenMPAtClauseKind::kATUnknown);

  nb::enum_<pasta::OpenMPAtomicDefaultMemOrderClauseKind>(m, "OpenMPAtomicDefaultMemOrderClauseKind")
    .value("SEQ_CST", pasta::OpenMPAtomicDefaultMemOrderClauseKind::kSeqCst)
    .value("ACQ_REL", pasta::OpenMPAtomicDefaultMemOrderClauseKind::kAcqRel)
    .value("RELAXED", pasta::OpenMPAtomicDefaultMemOrderClauseKind::kRelaxed)
    .value("UNKNOWN", pasta::OpenMPAtomicDefaultMemOrderClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPBindClauseKind>(m, "OpenMPBindClauseKind")
    .value("BIND_TEAMS", pasta::OpenMPBindClauseKind::kBINDTeams)
    .value("BIND_PARALLEL", pasta::OpenMPBindClauseKind::kBINDParallel)
    .value("BIND_THREAD", pasta::OpenMPBindClauseKind::kBINDThread)
    .value("BIND_UNKNOWN", pasta::OpenMPBindClauseKind::kBINDUnknown);

  nb::enum_<pasta::OpenMPDefaultmapClauseKind>(m, "OpenMPDefaultmapClauseKind")
    .value("SCALAR", pasta::OpenMPDefaultmapClauseKind::kScalar)
    .value("AGGREGATE", pasta::OpenMPDefaultmapClauseKind::kAggregate)
    .value("POINTER", pasta::OpenMPDefaultmapClauseKind::kPointer)
    .value("UNKNOWN", pasta::OpenMPDefaultmapClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPDefaultmapClauseModifier>(m, "OpenMPDefaultmapClauseModifier")
    .value("UNKNOWN", pasta::OpenMPDefaultmapClauseModifier::kUnknown)
    .value("ALLOC", pasta::OpenMPDefaultmapClauseModifier::kAlloc)
    .value("TO", pasta::OpenMPDefaultmapClauseModifier::kTo)
    .value("FROM", pasta::OpenMPDefaultmapClauseModifier::kFrom)
    .value("TOFROM", pasta::OpenMPDefaultmapClauseModifier::kTofrom)
    .value("NONE", pasta::OpenMPDefaultmapClauseModifier::kNone)
    .value("DEFAULT", pasta::OpenMPDefaultmapClauseModifier::kDefault)
    .value("PRESENT", pasta::OpenMPDefaultmapClauseModifier::kPresent);

  nb::enum_<pasta::OpenMPDependClauseKind>(m, "OpenMPDependClauseKind")
    .value("IN", pasta::OpenMPDependClauseKind::kIn)
    .value("OUT", pasta::OpenMPDependClauseKind::kOut)
    .value("INOUT", pasta::OpenMPDependClauseKind::kInout)
    .value("MUTEXINOUTSET", pasta::OpenMPDependClauseKind::kMutexinoutset)
    .value("DEPOBJ", pasta::OpenMPDependClauseKind::kDepobj)
    .value("SOURCE", pasta::OpenMPDependClauseKind::kSource)
    .value("SINK", pasta::OpenMPDependClauseKind::kSink)
    .value("INOUTSET", pasta::OpenMPDependClauseKind::kInoutset)
    .value("OUTALLMEMORY", pasta::OpenMPDependClauseKind::kOutallmemory)
    .value("INOUTALLMEMORY", pasta::OpenMPDependClauseKind::kInoutallmemory)
    .value("UNKNOWN", pasta::OpenMPDependClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPDeviceClauseModifier>(m, "OpenMPDeviceClauseModifier")
    .value("ANCESTOR", pasta::OpenMPDeviceClauseModifier::kAncestor)
    .value("DEVICE_NUM", pasta::OpenMPDeviceClauseModifier::kDeviceNum)
    .value("UNKNOWN", pasta::OpenMPDeviceClauseModifier::kUnknown);

  nb::enum_<pasta::OpenMPDeviceType>(m, "OpenMPDeviceType")
    .value("HOST", pasta::OpenMPDeviceType::kHost)
    .value("NOHOST", pasta::OpenMPDeviceType::kNohost)
    .value("ANY", pasta::OpenMPDeviceType::kAny)
    .value("UNKNOWN", pasta::OpenMPDeviceType::kUnknown);

  nb::enum_<pasta::OpenMPDistScheduleClauseKind>(m, "OpenMPDistScheduleClauseKind")
    .value("STATIC", pasta::OpenMPDistScheduleClauseKind::kStatic)
    .value("UNKNOWN", pasta::OpenMPDistScheduleClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPGrainsizeClauseModifier>(m, "OpenMPGrainsizeClauseModifier")
    .value("GRAINSIZE_STRICT", pasta::OpenMPGrainsizeClauseModifier::kGRAINSIZEStrict)
    .value("GRAINSIZE_UNKNOWN", pasta::OpenMPGrainsizeClauseModifier::kGRAINSIZEUnknown);

  nb::enum_<pasta::OpenMPLastprivateModifier>(m, "OpenMPLastprivateModifier")
    .value("CONDITIONAL", pasta::OpenMPLastprivateModifier::kConditional)
    .value("UNKNOWN", pasta::OpenMPLastprivateModifier::kUnknown);

  nb::enum_<pasta::OpenMPLinearClauseKind>(m, "OpenMPLinearClauseKind")
    .value("VALUE", pasta::OpenMPLinearClauseKind::kValue)
    .value("REFERENCE", pasta::OpenMPLinearClauseKind::kReference)
    .value("UVAL", pasta::OpenMPLinearClauseKind::kUval)
    .value("UNKNOWN", pasta::OpenMPLinearClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPMapClauseKind>(m, "OpenMPMapClauseKind")
    .value("ALLOC", pasta::OpenMPMapClauseKind::kAlloc)
    .value("TO", pasta::OpenMPMapClauseKind::kTo)
    .value("FROM", pasta::OpenMPMapClauseKind::kFrom)
    .value("TOFROM", pasta::OpenMPMapClauseKind::kTofrom)
    .value("DELETE", pasta::OpenMPMapClauseKind::kDelete)
    .value("RELEASE", pasta::OpenMPMapClauseKind::kRelease)
    .value("UNKNOWN", pasta::OpenMPMapClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPMapModifierKind>(m, "OpenMPMapModifierKind")
    .value("UNKNOWN", pasta::OpenMPMapModifierKind::kUnknown)
    .value("ALWAYS", pasta::OpenMPMapModifierKind::kAlways)
    .value("CLOSE", pasta::OpenMPMapModifierKind::kClose)
    .value("MAPPER", pasta::OpenMPMapModifierKind::kMapper)
    .value("ITERATOR", pasta::OpenMPMapModifierKind::kIterator)
    .value("PRESENT", pasta::OpenMPMapModifierKind::kPresent)
    .value("OMPX_HOLD", pasta::OpenMPMapModifierKind::kOmpxHold);

  nb::enum_<pasta::OpenMPMotionModifierKind>(m, "OpenMPMotionModifierKind")
    .value("MOTIONMODIFIER_MAPPER", pasta::OpenMPMotionModifierKind::kMOTIONMODIFIERMapper)
    .value("MOTIONMODIFIER_PRESENT", pasta::OpenMPMotionModifierKind::kMOTIONMODIFIERPresent)
    .value("MOTIONMODIFIER_UNKNOWN", pasta::OpenMPMotionModifierKind::kMOTIONMODIFIERUnknown);

  nb::enum_<pasta::OpenMPNumTasksClauseModifier>(m, "OpenMPNumTasksClauseModifier")
    .value("NUMTASKS_STRICT", pasta::OpenMPNumTasksClauseModifier::kNUMTASKSStrict)
    .value("NUMTASKS_UNKNOWN", pasta::OpenMPNumTasksClauseModifier::kNUMTASKSUnknown);

  nb::enum_<pasta::OpenMPOrderClauseKind>(m, "OpenMPOrderClauseKind")
    .value("CONCURRENT", pasta::OpenMPOrderClauseKind::kConcurrent)
    .value("UNKNOWN", pasta::OpenMPOrderClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPOrderClauseModifier>(m, "OpenMPOrderClauseModifier")
    .value("MODIFIER_UNKNOWN", pasta::OpenMPOrderClauseModifier::kMODIFIERUnknown)
    .value("MODIFIER_REPRODUCIBLE", pasta::OpenMPOrderClauseModifier::kMODIFIERReproducible)
    .value("MODIFIER_UNCONSTRAINED", pasta::OpenMPOrderClauseModifier::kMODIFIERUnconstrained)
    .value("MODIFIER_LAST", pasta::OpenMPOrderClauseModifier::kMODIFIERLast);

  nb::enum_<pasta::OpenMPReductionClauseModifier>(m, "OpenMPReductionClauseModifier")
    .value("DEFAULT", pasta::OpenMPReductionClauseModifier::kDefault)
    .value("INSCAN", pasta::OpenMPReductionClauseModifier::kInscan)
    .value("TASK", pasta::OpenMPReductionClauseModifier::kTask)
    .value("UNKNOWN", pasta::OpenMPReductionClauseModifier::kUnknown);

  nb::enum_<pasta::OpenMPScheduleClauseKind>(m, "OpenMPScheduleClauseKind")
    .value("STATIC", pasta::OpenMPScheduleClauseKind::kStatic)
    .value("DYNAMIC", pasta::OpenMPScheduleClauseKind::kDynamic)
    .value("GUIDED", pasta::OpenMPScheduleClauseKind::kGuided)
    .value("AUTO", pasta::OpenMPScheduleClauseKind::kAuto)
    .value("RUNTIME", pasta::OpenMPScheduleClauseKind::kRuntime)
    .value("UNKNOWN", pasta::OpenMPScheduleClauseKind::kUnknown);

  nb::enum_<pasta::OpenMPScheduleClauseModifier>(m, "OpenMPScheduleClauseModifier")
    .value("UNKNOWN", pasta::OpenMPScheduleClauseModifier::kUnknown)
    .value("MONOTONIC", pasta::OpenMPScheduleClauseModifier::kMonotonic)
    .value("NONMONOTONIC", pasta::OpenMPScheduleClauseModifier::kNonmonotonic)
    .value("SIMD", pasta::OpenMPScheduleClauseModifier::kSimd);

  nb::enum_<pasta::OpenMPSeverityClauseKind>(m, "OpenMPSeverityClauseKind")
    .value("SEVERITY_FATAL", pasta::OpenMPSeverityClauseKind::kSEVERITYFatal)
    .value("SEVERITY_WARNING", pasta::OpenMPSeverityClauseKind::kSEVERITYWarning)
    .value("SEVERITY_UNKNOWN", pasta::OpenMPSeverityClauseKind::kSEVERITYUnknown);

  nb::enum_<pasta::OverloadedOperatorKind>(m, "OverloadedOperatorKind")
    .value("NONE", pasta::OverloadedOperatorKind::kNone)
    .value("NEW", pasta::OverloadedOperatorKind::kNew)
    .value("DELETE", pasta::OverloadedOperatorKind::kDelete)
    .value("ARRAY_NEW", pasta::OverloadedOperatorKind::kArrayNew)
    .value("ARRAY_DELETE", pasta::OverloadedOperatorKind::kArrayDelete)
    .value("PLUS", pasta::OverloadedOperatorKind::kPlus)
    .value("MINUS", pasta::OverloadedOperatorKind::kMinus)
    .value("STAR", pasta::OverloadedOperatorKind::kStar)
    .value("SLASH", pasta::OverloadedOperatorKind::kSlash)
    .value("PERCENT", pasta::OverloadedOperatorKind::kPercent)
    .value("CARET", pasta::OverloadedOperatorKind::kCaret)
    .value("AMP", pasta::OverloadedOperatorKind::kAmp)
    .value("PIPE", pasta::OverloadedOperatorKind::kPipe)
    .value("TILDE", pasta::OverloadedOperatorKind::kTilde)
    .value("EXCLAIM", pasta::OverloadedOperatorKind::kExclaim)
    .value("EQUAL", pasta::OverloadedOperatorKind::kEqual)
    .value("LESS", pasta::OverloadedOperatorKind::kLess)
    .value("GREATER", pasta::OverloadedOperatorKind::kGreater)
    .value("PLUS_EQUAL", pasta::OverloadedOperatorKind::kPlusEqual)
    .value("MINUS_EQUAL", pasta::OverloadedOperatorKind::kMinusEqual)
    .value("STAR_EQUAL", pasta::OverloadedOperatorKind::kStarEqual)
    .value("SLASH_EQUAL", pasta::OverloadedOperatorKind::kSlashEqual)
    .value("PERCENT_EQUAL", pasta::OverloadedOperatorKind::kPercentEqual)
    .value("CARET_EQUAL", pasta::OverloadedOperatorKind::kCaretEqual)
    .value("AMP_EQUAL", pasta::OverloadedOperatorKind::kAmpEqual)
    .value("PIPE_EQUAL", pasta::OverloadedOperatorKind::kPipeEqual)
    .value("LESS_LESS", pasta::OverloadedOperatorKind::kLessLess)
    .value("GREATER_GREATER", pasta::OverloadedOperatorKind::kGreaterGreater)
    .value("LESS_LESS_EQUAL", pasta::OverloadedOperatorKind::kLessLessEqual)
    .value("GREATER_GREATER_EQUAL", pasta::OverloadedOperatorKind::kGreaterGreaterEqual)
    .value("EQUAL_EQUAL", pasta::OverloadedOperatorKind::kEqualEqual)
    .value("EXCLAIM_EQUAL", pasta::OverloadedOperatorKind::kExclaimEqual)
    .value("LESS_EQUAL", pasta::OverloadedOperatorKind::kLessEqual)
    .value("GREATER_EQUAL", pasta::OverloadedOperatorKind::kGreaterEqual)
    .value("SPACESHIP", pasta::OverloadedOperatorKind::kSpaceship)
    .value("AMP_AMP", pasta::OverloadedOperatorKind::kAmpAmp)
    .value("PIPE_PIPE", pasta::OverloadedOperatorKind::kPipePipe)
    .value("PLUS_PLUS", pasta::OverloadedOperatorKind::kPlusPlus)
    .value("MINUS_MINUS", pasta::OverloadedOperatorKind::kMinusMinus)
    .value("COMMA", pasta::OverloadedOperatorKind::kComma)
    .value("ARROW_STAR", pasta::OverloadedOperatorKind::kArrowStar)
    .value("ARROW", pasta::OverloadedOperatorKind::kArrow)
    .value("CALL", pasta::OverloadedOperatorKind::kCall)
    .value("SUBSCRIPT", pasta::OverloadedOperatorKind::kSubscript)
    .value("CONDITIONAL", pasta::OverloadedOperatorKind::kConditional)
    .value("COAWAIT", pasta::OverloadedOperatorKind::kCoawait);

  nb::enum_<pasta::OverloadsShown>(m, "OverloadsShown")
    .value("ALL", pasta::OverloadsShown::kAll)
    .value("BEST", pasta::OverloadsShown::kBest);

  nb::enum_<pasta::PPKeywordKind>(m, "PPKeywordKind")
    .value("NOT_KEYWORD", pasta::PPKeywordKind::kNotKeyword)
    .value("IF", pasta::PPKeywordKind::kIf)
    .value("IFDEF", pasta::PPKeywordKind::kIfdef)
    .value("IFNDEF", pasta::PPKeywordKind::kIfndef)
    .value("ELIF", pasta::PPKeywordKind::kElif)
    .value("ELIFDEF", pasta::PPKeywordKind::kElifdef)
    .value("ELIFNDEF", pasta::PPKeywordKind::kElifndef)
    .value("ELSE", pasta::PPKeywordKind::kElse)
    .value("ENDIF", pasta::PPKeywordKind::kEndif)
    .value("DEFINED", pasta::PPKeywordKind::kDefined)
    .value("INCLUDE", pasta::PPKeywordKind::kInclude)
    .value("__INCLUDE_MACROS", pasta::PPKeywordKind::k__IncludeMacros)
    .value("DEFINE", pasta::PPKeywordKind::kDefine)
    .value("UNDEF", pasta::PPKeywordKind::kUndef)
    .value("LINE", pasta::PPKeywordKind::kLine)
    .value("ERROR", pasta::PPKeywordKind::kError)
    .value("PRAGMA", pasta::PPKeywordKind::kPragma)
    .value("IMPORT", pasta::PPKeywordKind::kImport)
    .value("INCLUDE_NEXT", pasta::PPKeywordKind::kIncludeNext)
    .value("WARNING", pasta::PPKeywordKind::kWarning)
    .value("IDENTIFIER", pasta::PPKeywordKind::kIdentifier)
    .value("SCCS", pasta::PPKeywordKind::kSccs)
    .value("ASSERT", pasta::PPKeywordKind::kAssert)
    .value("UNASSERT", pasta::PPKeywordKind::kUnassert)
    .value("__PUBLIC_MACRO", pasta::PPKeywordKind::k__PublicMacro)
    .value("__PRIVATE_MACRO", pasta::PPKeywordKind::k__PrivateMacro);

  nb::enum_<pasta::ParameterABI>(m, "ParameterABI")
    .value("ORDINARY", pasta::ParameterABI::kOrdinary)
    .value("SWIFT_INDIRECT_RESULT", pasta::ParameterABI::kSwiftIndirectResult)
    .value("SWIFT_ERROR_RESULT", pasta::ParameterABI::kSwiftErrorResult)
    .value("SWIFT_CONTEXT", pasta::ParameterABI::kSwiftContext)
    .value("SWIFT_ASYNC_CONTEXT", pasta::ParameterABI::kSwiftAsyncContext);

  nb::enum_<pasta::ParenLocsOffsets>(m, "ParenLocsOffsets")
    .value("L_PAREN_TOKEN", pasta::ParenLocsOffsets::kLParenToken)
    .value("R_PAREN_TOKEN", pasta::ParenLocsOffsets::kRParenToken)
    .value("TOTAL", pasta::ParenLocsOffsets::kTotal);

  nb::enum_<pasta::PragmaFloatControlKind>(m, "PragmaFloatControlKind")
    .value("UNKNOWN", pasta::PragmaFloatControlKind::kUnknown)
    .value("PRECISE", pasta::PragmaFloatControlKind::kPrecise)
    .value("NO_PRECISE", pasta::PragmaFloatControlKind::kNoPrecise)
    .value("EXCEPT", pasta::PragmaFloatControlKind::kExcept)
    .value("NO_EXCEPT", pasta::PragmaFloatControlKind::kNoExcept)
    .value("PUSH", pasta::PragmaFloatControlKind::kPush)
    .value("POP", pasta::PragmaFloatControlKind::kPop);

  nb::enum_<pasta::PragmaMSCommentKind>(m, "PragmaMSCommentKind")
    .value("UNKNOWN", pasta::PragmaMSCommentKind::kUnknown)
    .value("LINKER", pasta::PragmaMSCommentKind::kLinker)
    .value("LIB", pasta::PragmaMSCommentKind::kLib)
    .value("COMPILER", pasta::PragmaMSCommentKind::kCompiler)
    .value("EXE_STRING", pasta::PragmaMSCommentKind::kExeString)
    .value("USER", pasta::PragmaMSCommentKind::kUser);

  nb::enum_<pasta::PragmaMSPointersToMembersKind>(m, "PragmaMSPointersToMembersKind")
    .value("BEST_CASE", pasta::PragmaMSPointersToMembersKind::kBestCase)
    .value("FULL_GENERALITY_SINGLE_INHERITANCE", pasta::PragmaMSPointersToMembersKind::kFullGeneralitySingleInheritance)
    .value("FULL_GENERALITY_MULTIPLE_INHERITANCE", pasta::PragmaMSPointersToMembersKind::kFullGeneralityMultipleInheritance)
    .value("FULL_GENERALITY_VIRTUAL_INHERITANCE", pasta::PragmaMSPointersToMembersKind::kFullGeneralityVirtualInheritance);

  nb::enum_<pasta::PragmaMSStructKind>(m, "PragmaMSStructKind")
    .value("OFF", pasta::PragmaMSStructKind::kOFF)
    .value("ON", pasta::PragmaMSStructKind::kON);

  nb::enum_<pasta::PragmaSectionFlag>(m, "PragmaSectionFlag")
    .value("NONE", pasta::PragmaSectionFlag::kNone)
    .value("READ", pasta::PragmaSectionFlag::kRead)
    .value("WRITE", pasta::PragmaSectionFlag::kWrite)
    .value("EXECUTE", pasta::PragmaSectionFlag::kExecute)
    .value("IMPLICIT", pasta::PragmaSectionFlag::kImplicit)
    .value("ZERO_INITIALIZER", pasta::PragmaSectionFlag::kZeroInitializer)
    .value("INVALID", pasta::PragmaSectionFlag::kInvalid);

  nb::enum_<pasta::ProfileInstrKind>(m, "ProfileInstrKind")
    .value("PROFILE_NONE", pasta::ProfileInstrKind::kProfileNone)
    .value("PROFILE_CLANG_INSTR", pasta::ProfileInstrKind::kProfileClangInstr)
    .value("PROFILE_IR_INSTR", pasta::ProfileInstrKind::kProfileIRInstr)
    .value("PROFILE_CSIR_INSTR", pasta::ProfileInstrKind::kProfileCSIRInstr);

  nb::enum_<pasta::Qualified>(m, "Qualified")
    .value("NONE", pasta::Qualified::kNone)
    .value("AS_WRITTEN", pasta::Qualified::kAsWritten)
    .value("FULLY", pasta::Qualified::kFully);

  nb::enum_<pasta::RangeExprOffset>(m, "RangeExprOffset")
    .value("BEGIN", pasta::RangeExprOffset::kBegin)
    .value("END", pasta::RangeExprOffset::kEnd)
    .value("STEP", pasta::RangeExprOffset::kStep)
    .value("TOTAL", pasta::RangeExprOffset::kTotal);

  nb::enum_<pasta::RangeLocOffset>(m, "RangeLocOffset")
    .value("ASSIGN_TOKEN", pasta::RangeLocOffset::kAssignToken)
    .value("SECOND_COLON_TOKEN", pasta::RangeLocOffset::kSecondColonToken)
    .value("TOTAL", pasta::RangeLocOffset::kTotal);

  nb::enum_<pasta::RefQualifierKind>(m, "RefQualifierKind")
    .value("NONE", pasta::RefQualifierKind::kNone)
    .value("L_VALUE", pasta::RefQualifierKind::kLValue)
    .value("R_VALUE", pasta::RefQualifierKind::kRValue);

  nb::enum_<pasta::RemarkKind>(m, "RemarkKind")
    .value("MISSING", pasta::RemarkKind::kMissing)
    .value("ENABLED", pasta::RemarkKind::kEnabled)
    .value("ENABLED_EVERYTHING", pasta::RemarkKind::kEnabledEverything)
    .value("DISABLED", pasta::RemarkKind::kDisabled)
    .value("DISABLED_EVERYTHING", pasta::RemarkKind::kDisabledEverything)
    .value("WITH_PATTERN", pasta::RemarkKind::kWithPattern);

  nb::enum_<pasta::ReservedIdentifierStatus>(m, "ReservedIdentifierStatus")
    .value("NOT_RESERVED", pasta::ReservedIdentifierStatus::kNotReserved)
    .value("STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE", pasta::ReservedIdentifierStatus::kStartsWithUnderscoreAtGlobalScope)
    .value("STARTS_WITH_UNDERSCORE_AND_IS_EXTERN_C", pasta::ReservedIdentifierStatus::kStartsWithUnderscoreAndIsExternC)
    .value("STARTS_WITH_DOUBLE_UNDERSCORE", pasta::ReservedIdentifierStatus::kStartsWithDoubleUnderscore)
    .value("STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER", pasta::ReservedIdentifierStatus::kStartsWithUnderscoreFollowedByCapitalLetter)
    .value("CONTAINS_DOUBLE_UNDERSCORE", pasta::ReservedIdentifierStatus::kContainsDoubleUnderscore);

  nb::enum_<pasta::SFINAEResponse>(m, "SFINAEResponse")
    .value("SUBSTITUTION_FAILURE", pasta::SFINAEResponse::kSubstitutionFailure)
    .value("SUPPRESS", pasta::SFINAEResponse::kSuppress)
    .value("REPORT", pasta::SFINAEResponse::kReport)
    .value("ACCESS_CONTROL", pasta::SFINAEResponse::kAccessControl);

  nb::enum_<pasta::SYCLMajorVersion>(m, "SYCLMajorVersion")
    .value("NONE", pasta::SYCLMajorVersion::kNone)
    .value("2017", pasta::SYCLMajorVersion::k2017)
    .value("2020", pasta::SYCLMajorVersion::k2020)
    .value("DEFAULT", pasta::SYCLMajorVersion::kDefault);

  nb::enum_<pasta::SanitizerOrdinal>(m, "SanitizerOrdinal")
    .value("ADDRESS", pasta::SanitizerOrdinal::kAddress)
    .value("POINTER_COMPARE", pasta::SanitizerOrdinal::kPointerCompare)
    .value("POINTER_SUBTRACT", pasta::SanitizerOrdinal::kPointerSubtract)
    .value("KERNEL_ADDRESS", pasta::SanitizerOrdinal::kKernelAddress)
    .value("HW_ADDRESS", pasta::SanitizerOrdinal::kHWAddress)
    .value("KERNEL_HW_ADDRESS", pasta::SanitizerOrdinal::kKernelHWAddress)
    .value("MEMTAG_STACK", pasta::SanitizerOrdinal::kMemtagStack)
    .value("MEMTAG_HEAP", pasta::SanitizerOrdinal::kMemtagHeap)
    .value("MEMTAG_GLOBALS", pasta::SanitizerOrdinal::kMemtagGlobals)
    .value("MEMORY_TAG_GROUP", pasta::SanitizerOrdinal::kMemoryTagGroup)
    .value("MEMORY", pasta::SanitizerOrdinal::kMemory)
    .value("KERNEL_MEMORY", pasta::SanitizerOrdinal::kKernelMemory)
    .value("FUZZER", pasta::SanitizerOrdinal::kFuzzer)
    .value("FUZZER_NO_LINK", pasta::SanitizerOrdinal::kFuzzerNoLink)
    .value("THREAD", pasta::SanitizerOrdinal::kThread)
    .value("LEAK", pasta::SanitizerOrdinal::kLeak)
    .value("ALIGNMENT", pasta::SanitizerOrdinal::kAlignment)
    .value("ARRAY_BOUNDS", pasta::SanitizerOrdinal::kArrayBounds)
    .value("BOOLEAN", pasta::SanitizerOrdinal::kBoolean)
    .value("BUILTIN", pasta::SanitizerOrdinal::kBuiltin)
    .value("ENUM", pasta::SanitizerOrdinal::kEnum)
    .value("FLOAT_CAST_OVERFLOW", pasta::SanitizerOrdinal::kFloatCastOverflow)
    .value("FLOAT_DIVIDE_BY_ZERO", pasta::SanitizerOrdinal::kFloatDivideByZero)
    .value("FUNCTION", pasta::SanitizerOrdinal::kFunction)
    .value("INTEGER_DIVIDE_BY_ZERO", pasta::SanitizerOrdinal::kIntegerDivideByZero)
    .value("NONNULL_ATTRIBUTE", pasta::SanitizerOrdinal::kNonnullAttribute)
    .value("NULL", pasta::SanitizerOrdinal::kNull)
    .value("NULLABILITY_ARGUMENT", pasta::SanitizerOrdinal::kNullabilityArgument)
    .value("NULLABILITY_ASSIGN", pasta::SanitizerOrdinal::kNullabilityAssign)
    .value("NULLABILITY_RETURN", pasta::SanitizerOrdinal::kNullabilityReturn)
    .value("NULLABILITY_GROUP", pasta::SanitizerOrdinal::kNullabilityGroup)
    .value("OBJECT_SIZE", pasta::SanitizerOrdinal::kObjectSize)
    .value("POINTER_OVERFLOW", pasta::SanitizerOrdinal::kPointerOverflow)
    .value("RETURN", pasta::SanitizerOrdinal::kReturn)
    .value("RETURNS_NONNULL_ATTRIBUTE", pasta::SanitizerOrdinal::kReturnsNonnullAttribute)
    .value("SHIFT_BASE", pasta::SanitizerOrdinal::kShiftBase)
    .value("SHIFT_EXPONENT", pasta::SanitizerOrdinal::kShiftExponent)
    .value("SHIFT_GROUP", pasta::SanitizerOrdinal::kShiftGroup)
    .value("SIGNED_INTEGER_OVERFLOW", pasta::SanitizerOrdinal::kSignedIntegerOverflow)
    .value("UNREACHABLE", pasta::SanitizerOrdinal::kUnreachable)
    .value("VLA_BOUND", pasta::SanitizerOrdinal::kVLABound)
    .value("VPTR", pasta::SanitizerOrdinal::kVptr)
    .value("UNSIGNED_INTEGER_OVERFLOW", pasta::SanitizerOrdinal::kUnsignedIntegerOverflow)
    .value("UNSIGNED_SHIFT_BASE", pasta::SanitizerOrdinal::kUnsignedShiftBase)
    .value("DATA_FLOW", pasta::SanitizerOrdinal::kDataFlow)
    .value("CFI_CAST_STRICT", pasta::SanitizerOrdinal::kCFICastStrict)
    .value("CFI_DERIVED_CAST", pasta::SanitizerOrdinal::kCFIDerivedCast)
    .value("CFII_CALL", pasta::SanitizerOrdinal::kCFIICall)
    .value("CFIMF_CALL", pasta::SanitizerOrdinal::kCFIMFCall)
    .value("CFI_UNRELATED_CAST", pasta::SanitizerOrdinal::kCFIUnrelatedCast)
    .value("CFINV_CALL", pasta::SanitizerOrdinal::kCFINVCall)
    .value("CFIV_CALL", pasta::SanitizerOrdinal::kCFIVCall)
    .value("CFI_GROUP", pasta::SanitizerOrdinal::kCFIGroup)
    .value("KCFI", pasta::SanitizerOrdinal::kKCFI)
    .value("SAFE_STACK", pasta::SanitizerOrdinal::kSafeStack)
    .value("SHADOW_CALL_STACK", pasta::SanitizerOrdinal::kShadowCallStack)
    .value("UNDEFINED_GROUP", pasta::SanitizerOrdinal::kUndefinedGroup)
    .value("UNDEFINED_TRAP_GROUP", pasta::SanitizerOrdinal::kUndefinedTrapGroup)
    .value("IMPLICIT_UNSIGNED_INTEGER_TRUNCATION", pasta::SanitizerOrdinal::kImplicitUnsignedIntegerTruncation)
    .value("IMPLICIT_SIGNED_INTEGER_TRUNCATION", pasta::SanitizerOrdinal::kImplicitSignedIntegerTruncation)
    .value("IMPLICIT_INTEGER_TRUNCATION_GROUP", pasta::SanitizerOrdinal::kImplicitIntegerTruncationGroup)
    .value("IMPLICIT_INTEGER_SIGN_CHANGE", pasta::SanitizerOrdinal::kImplicitIntegerSignChange)
    .value("IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP", pasta::SanitizerOrdinal::kImplicitIntegerArithmeticValueChangeGroup)
    .value("OBJ_C_CAST", pasta::SanitizerOrdinal::kObjCCast)
    .value("IMPLICIT_CONVERSION_GROUP", pasta::SanitizerOrdinal::kImplicitConversionGroup)
    .value("INTEGER_GROUP", pasta::SanitizerOrdinal::kIntegerGroup)
    .value("LOCAL_BOUNDS", pasta::SanitizerOrdinal::kLocalBounds)
    .value("BOUNDS_GROUP", pasta::SanitizerOrdinal::kBoundsGroup)
    .value("SCUDO", pasta::SanitizerOrdinal::kScudo)
    .value("ALL_GROUP", pasta::SanitizerOrdinal::kAllGroup)
    .value("COUNT", pasta::SanitizerOrdinal::kCount);

  nb::enum_<pasta::SelectorLocationsKind>(m, "SelectorLocationsKind")
    .value("NON_STANDARD", pasta::SelectorLocationsKind::kNonStandard)
    .value("STANDARD_NO_SPACE", pasta::SelectorLocationsKind::kStandardNoSpace)
    .value("STANDARD_WITH_SPACE", pasta::SelectorLocationsKind::kStandardWithSpace);

  nb::enum_<pasta::ShaderStage>(m, "ShaderStage")
    .value("PIXEL", pasta::ShaderStage::kPixel)
    .value("VERTEX", pasta::ShaderStage::kVertex)
    .value("GEOMETRY", pasta::ShaderStage::kGeometry)
    .value("HULL", pasta::ShaderStage::kHull)
    .value("DOMAIN", pasta::ShaderStage::kDomain)
    .value("COMPUTE", pasta::ShaderStage::kCompute)
    .value("LIBRARY", pasta::ShaderStage::kLibrary)
    .value("RAY_GENERATION", pasta::ShaderStage::kRayGeneration)
    .value("INTERSECTION", pasta::ShaderStage::kIntersection)
    .value("ANY_HIT", pasta::ShaderStage::kAnyHit)
    .value("CLOSEST_HIT", pasta::ShaderStage::kClosestHit)
    .value("MISS", pasta::ShaderStage::kMiss)
    .value("CALLABLE", pasta::ShaderStage::kCallable)
    .value("MESH", pasta::ShaderStage::kMesh)
    .value("AMPLIFICATION", pasta::ShaderStage::kAmplification)
    .value("INVALID", pasta::ShaderStage::kInvalid);

  nb::enum_<pasta::SignReturnAddressKeyKind>(m, "SignReturnAddressKeyKind")
    .value("A_KEY", pasta::SignReturnAddressKeyKind::kAKey)
    .value("B_KEY", pasta::SignReturnAddressKeyKind::kBKey);

  nb::enum_<pasta::SignReturnAddressScopeKind>(m, "SignReturnAddressScopeKind")
    .value("NONE", pasta::SignReturnAddressScopeKind::kNone)
    .value("NON_LEAF", pasta::SignReturnAddressScopeKind::kNonLeaf)
    .value("ALL", pasta::SignReturnAddressScopeKind::kAll);

  nb::enum_<pasta::SignedOverflowBehaviorTy>(m, "SignedOverflowBehaviorTy")
    .value("UNDEFINED", pasta::SignedOverflowBehaviorTy::kUndefined)
    .value("DEFINED", pasta::SignedOverflowBehaviorTy::kDefined)
    .value("TRAPPING", pasta::SignedOverflowBehaviorTy::kTrapping);

  nb::enum_<pasta::SpecialMemberFlags>(m, "SpecialMemberFlags")
    .value("DEFAULT_CONSTRUCTOR", pasta::SpecialMemberFlags::kDefaultConstructor)
    .value("COPY_CONSTRUCTOR", pasta::SpecialMemberFlags::kCopyConstructor)
    .value("MOVE_CONSTRUCTOR", pasta::SpecialMemberFlags::kMoveConstructor)
    .value("COPY_ASSIGNMENT", pasta::SpecialMemberFlags::kCopyAssignment)
    .value("MOVE_ASSIGNMENT", pasta::SpecialMemberFlags::kMoveAssignment)
    .value("DESTRUCTOR", pasta::SpecialMemberFlags::kDestructor)
    .value("ALL", pasta::SpecialMemberFlags::kAll);

  nb::enum_<pasta::SpecifierKind>(m, "SpecifierKind")
    .value("IDENTIFIER", pasta::SpecifierKind::kIdentifier)
    .value("NAMESPACE", pasta::SpecifierKind::kNamespace)
    .value("NAMESPACE_ALIAS", pasta::SpecifierKind::kNamespaceAlias)
    .value("TYPE_SPEC", pasta::SpecifierKind::kTypeSpec)
    .value("TYPE_SPEC_WITH_TEMPLATE", pasta::SpecifierKind::kTypeSpecWithTemplate)
    .value("GLOBAL", pasta::SpecifierKind::kGlobal)
    .value("SUPER", pasta::SpecifierKind::kSuper);

  nb::enum_<pasta::StackProtectorMode>(m, "StackProtectorMode")
    .value("OFF", pasta::StackProtectorMode::kOff)
    .value("ON", pasta::StackProtectorMode::kOn)
    .value("STRONG", pasta::StackProtectorMode::kStrong)
    .value("REQ", pasta::StackProtectorMode::kReq);

  nb::enum_<pasta::StorageClass>(m, "StorageClass")
    .value("NONE", pasta::StorageClass::kNone)
    .value("EXTERN", pasta::StorageClass::kExtern)
    .value("STATIC", pasta::StorageClass::kStatic)
    .value("PRIVATE_EXTERN", pasta::StorageClass::kPrivateExtern)
    .value("AUTO", pasta::StorageClass::kAuto)
    .value("REGISTER", pasta::StorageClass::kRegister);

  nb::enum_<pasta::StorageDuration>(m, "StorageDuration")
    .value("FULL_EXPRESSION", pasta::StorageDuration::kFullExpression)
    .value("AUTOMATIC", pasta::StorageDuration::kAutomatic)
    .value("THREAD", pasta::StorageDuration::kThread)
    .value("STATIC", pasta::StorageDuration::kStatic)
    .value("DYNAMIC", pasta::StorageDuration::kDynamic);

  nb::enum_<pasta::StoredNameKind>(m, "StoredNameKind")
    .value("STORED_IDENTIFIER", pasta::StoredNameKind::kStoredIdentifier)
    .value("STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR", pasta::StoredNameKind::kStoredObjCZeroArgumentSelector)
    .value("STORED_OBJ_C_ONE_ARGUMENT_SELECTOR", pasta::StoredNameKind::kStoredObjCOneArgumentSelector)
    .value("STORED_CXX_CONSTRUCTOR_NAME", pasta::StoredNameKind::kStoredCXXConstructorName)
    .value("STORED_CXX_DESTRUCTOR_NAME", pasta::StoredNameKind::kStoredCXXDestructorName)
    .value("STORED_CXX_CONVERSION_FUNCTION_NAME", pasta::StoredNameKind::kStoredCXXConversionFunctionName)
    .value("STORED_CXX_OPERATOR_NAME", pasta::StoredNameKind::kStoredCXXOperatorName)
    .value("STORED_DECLARATION_NAME_EXTRA", pasta::StoredNameKind::kStoredDeclarationNameExtra)
    .value("POINTER_MASK", pasta::StoredNameKind::kPointerMask)
    .value("UNCOMMON_NAME_KIND_OFFSET", pasta::StoredNameKind::kUncommonNameKindOffset);

  nb::enum_<pasta::StoredSpecifierKind>(m, "StoredSpecifierKind")
    .value("STORED_IDENTIFIER", pasta::StoredSpecifierKind::kStoredIdentifier)
    .value("STORED_DECLARATION", pasta::StoredSpecifierKind::kStoredDeclaration)
    .value("STORED_TYPE_SPEC", pasta::StoredSpecifierKind::kStoredTypeSpec)
    .value("STORED_TYPE_SPEC_WITH_TEMPLATE", pasta::StoredSpecifierKind::kStoredTypeSpecWithTemplate);

  nb::enum_<pasta::StrictFlexArraysLevelKind>(m, "StrictFlexArraysLevelKind")
    .value("DEFAULT", pasta::StrictFlexArraysLevelKind::kDefault)
    .value("ONE_ZERO_OR_INCOMPLETE", pasta::StrictFlexArraysLevelKind::kOneZeroOrIncomplete)
    .value("ZERO_OR_INCOMPLETE", pasta::StrictFlexArraysLevelKind::kZeroOrIncomplete)
    .value("INCOMPLETE_ONLY", pasta::StrictFlexArraysLevelKind::kIncompleteOnly);

  nb::enum_<pasta::StructReturnConventionKind>(m, "StructReturnConventionKind")
    .value("DEFAULT", pasta::StructReturnConventionKind::kDefault)
    .value("ON_STACK", pasta::StructReturnConventionKind::kOnStack)
    .value("IN_REGS", pasta::StructReturnConventionKind::kInRegs);

  nb::enum_<pasta::SubExpr>(m, "SubExpr")
    .value("CALLEE", pasta::SubExpr::kCallee)
    .value("LHS", pasta::SubExpr::kLHS)
    .value("RHS", pasta::SubExpr::kRHS)
    .value("COUNT", pasta::SubExpr::kCount);

  nb::enum_<pasta::SubStmt>(m, "SubStmt")
    .value("BODY", pasta::SubStmt::kBody)
    .value("PROMISE", pasta::SubStmt::kPromise)
    .value("INITIALIZER_SUSPEND", pasta::SubStmt::kInitializerSuspend)
    .value("FINAL_SUSPEND", pasta::SubStmt::kFinalSuspend)
    .value("ON_EXCEPTION", pasta::SubStmt::kOnException)
    .value("ON_FALLTHROUGH", pasta::SubStmt::kOnFallthrough)
    .value("ALLOCATE", pasta::SubStmt::kAllocate)
    .value("DEALLOCATE", pasta::SubStmt::kDeallocate)
    .value("RETURN_VALUE", pasta::SubStmt::kReturnValue)
    .value("RETURN_STATEMENT", pasta::SubStmt::kReturnStatement)
    .value("RETURN_STATEMENT_ON_ALLOC_FAILURE", pasta::SubStmt::kReturnStatementOnAllocFailure);

  nb::enum_<pasta::SwiftAsyncFramePointerKind>(m, "SwiftAsyncFramePointerKind")
    .value("AUTO", pasta::SwiftAsyncFramePointerKind::kAuto)
    .value("ALWAYS", pasta::SwiftAsyncFramePointerKind::kAlways)
    .value("NEVER", pasta::SwiftAsyncFramePointerKind::kNever)
    .value("DEFAULT", pasta::SwiftAsyncFramePointerKind::kDefault);

  nb::enum_<pasta::SyncScope>(m, "SyncScope")
    .value("HIP_SINGLE_THREAD", pasta::SyncScope::kHIPSingleThread)
    .value("HIP_WAVEFRONT", pasta::SyncScope::kHIPWavefront)
    .value("HIP_WORKGROUP", pasta::SyncScope::kHIPWorkgroup)
    .value("HIP_AGENT", pasta::SyncScope::kHIPAgent)
    .value("HIP_SYSTEM", pasta::SyncScope::kHIPSystem)
    .value("OPEN_CL_WORK_GROUP", pasta::SyncScope::kOpenCLWorkGroup)
    .value("OPEN_CL_DEVICE", pasta::SyncScope::kOpenCLDevice)
    .value("OPEN_CL_ALL_SVM_DEVICES", pasta::SyncScope::kOpenCLAllSVMDevices)
    .value("OPEN_CL_SUB_GROUP", pasta::SyncScope::kOpenCLSubGroup);

  nb::enum_<pasta::Syntax>(m, "Syntax")
    .value("GNU", pasta::Syntax::kGNU)
    .value("CXX11", pasta::Syntax::kCXX11)
    .value("C2X", pasta::Syntax::kC2x)
    .value("DECLSPEC", pasta::Syntax::kDeclspec)
    .value("MICROSOFT", pasta::Syntax::kMicrosoft)
    .value("KEYWORD", pasta::Syntax::kKeyword)
    .value("PRAGMA", pasta::Syntax::kPragma)
    .value("CONTEXT_SENSITIVE_KEYWORD", pasta::Syntax::kContextSensitiveKeyword)
    .value("HLSL_SEMANTIC", pasta::Syntax::kHLSLSemantic);

  nb::enum_<pasta::TLSModel>(m, "TLSModel")
    .value("GENERAL_DYNAMIC_TLS_MODEL", pasta::TLSModel::kGeneralDynamicTLSModel)
    .value("LOCAL_DYNAMIC_TLS_MODEL", pasta::TLSModel::kLocalDynamicTLSModel)
    .value("INITIAL_EXEC_TLS_MODEL", pasta::TLSModel::kInitialExecTLSModel)
    .value("LOCAL_EXEC_TLS_MODEL", pasta::TLSModel::kLocalExecTLSModel);

  nb::enum_<pasta::TQ>(m, "TQ")
    .value("CONST", pasta::TQ::kConst)
    .value("RESTRICT", pasta::TQ::kRestrict)
    .value("VOLATILE", pasta::TQ::kVolatile)
    .value("CVR_MASK", pasta::TQ::kCVRMask);

  nb::enum_<pasta::TagTypeKind>(m, "TagTypeKind")
    .value("STRUCT", pasta::TagTypeKind::kStruct)
    .value("INTERFACE", pasta::TagTypeKind::kInterface)
    .value("UNION", pasta::TagTypeKind::kUnion)
    .value("CLASS", pasta::TagTypeKind::kClass)
    .value("ENUM", pasta::TagTypeKind::kEnum);

  nb::enum_<pasta::TailPaddingUseRules>(m, "TailPaddingUseRules")
    .value("ALWAYS_USE_TAIL_PADDING", pasta::TailPaddingUseRules::kAlwaysUseTailPadding)
    .value("USE_TAIL_PADDING_UNLESS_POD03", pasta::TailPaddingUseRules::kUseTailPaddingUnlessPOD03)
    .value("USE_TAIL_PADDING_UNLESS_POD11", pasta::TailPaddingUseRules::kUseTailPaddingUnlessPOD11);

  nb::enum_<pasta::TemplateArgumentDependence>(m, "TemplateArgumentDependence")
    .value("UNEXPANDED_PACK", pasta::TemplateArgumentDependence::kUnexpandedPack)
    .value("INSTANTIATION", pasta::TemplateArgumentDependence::kInstantiation)
    .value("DEPENDENT", pasta::TemplateArgumentDependence::kDependent)
    .value("ERROR", pasta::TemplateArgumentDependence::kError)
    .value("NONE", pasta::TemplateArgumentDependence::kNone)
    .value("DEPENDENT_INSTANTIATION", pasta::TemplateArgumentDependence::kDependentInstantiation)
    .value("ALL", pasta::TemplateArgumentDependence::kAll);

  nb::enum_<pasta::TemplateNameDependence>(m, "TemplateNameDependence")
    .value("UNEXPANDED_PACK", pasta::TemplateNameDependence::kUnexpandedPack)
    .value("INSTANTIATION", pasta::TemplateNameDependence::kInstantiation)
    .value("DEPENDENT", pasta::TemplateNameDependence::kDependent)
    .value("ERROR", pasta::TemplateNameDependence::kError)
    .value("NONE", pasta::TemplateNameDependence::kNone)
    .value("DEPENDENT_INSTANTIATION", pasta::TemplateNameDependence::kDependentInstantiation)
    .value("ALL", pasta::TemplateNameDependence::kAll);

  nb::enum_<pasta::TemplateSpecializationKind>(m, "TemplateSpecializationKind")
    .value("UNDECLARED", pasta::TemplateSpecializationKind::kUndeclared)
    .value("IMPLICIT_INSTANTIATION", pasta::TemplateSpecializationKind::kImplicitInstantiation)
    .value("EXPLICIT_SPECIALIZATION", pasta::TemplateSpecializationKind::kExplicitSpecialization)
    .value("EXPLICIT_INSTANTIATION_DECLARATION", pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration)
    .value("EXPLICIT_INSTANTIATION_DEFINITION", pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition);

  nb::enum_<pasta::TextDiagnosticFormat>(m, "TextDiagnosticFormat")
    .value("CLANG", pasta::TextDiagnosticFormat::kClang)
    .value("MSVC", pasta::TextDiagnosticFormat::kMSVC)
    .value("VI", pasta::TextDiagnosticFormat::kVi)
    .value("SARIF", pasta::TextDiagnosticFormat::kSARIF);

  nb::enum_<pasta::ThreadModelKind>(m, "ThreadModelKind")
    .value("POSIX", pasta::ThreadModelKind::kPOSIX)
    .value("SINGLE", pasta::ThreadModelKind::kSingle);

  nb::enum_<pasta::ThreadStorageClassSpecifier>(m, "ThreadStorageClassSpecifier")
    .value("UNSPECIFIED", pasta::ThreadStorageClassSpecifier::kUnspecified)
    .value("__THREAD", pasta::ThreadStorageClassSpecifier::k__Thread)
    .value("THREAD_LOCAL", pasta::ThreadStorageClassSpecifier::kThreadLocal)
    .value("_THREAD_LOCAL", pasta::ThreadStorageClassSpecifier::k_ThreadLocal);

  nb::enum_<pasta::TokenKind>(m, "TokenKind")
    .value("UNKNOWN", pasta::TokenKind::kUnknown)
    .value("END_OF_FILE", pasta::TokenKind::kEndOfFile)
    .value("END_OF_DIRECTIVE", pasta::TokenKind::kEndOfDirective)
    .value("CODE_COMPLETION", pasta::TokenKind::kCodeCompletion)
    .value("COMMENT", pasta::TokenKind::kComment)
    .value("IDENTIFIER", pasta::TokenKind::kIdentifier)
    .value("RAW_IDENTIFIER", pasta::TokenKind::kRawIdentifier)
    .value("NUMERIC_CONSTANT", pasta::TokenKind::kNumericConstant)
    .value("CHARACTER_CONSTANT", pasta::TokenKind::kCharacterConstant)
    .value("WIDE_CHARACTER_CONSTANT", pasta::TokenKind::kWideCharacterConstant)
    .value("UTF8_CHARACTER_CONSTANT", pasta::TokenKind::kUtf8CharacterConstant)
    .value("UTF16_CHARACTER_CONSTANT", pasta::TokenKind::kUtf16CharacterConstant)
    .value("UTF32_CHARACTER_CONSTANT", pasta::TokenKind::kUtf32CharacterConstant)
    .value("STRING_LITERAL", pasta::TokenKind::kStringLiteral)
    .value("WIDE_STRING_LITERAL", pasta::TokenKind::kWideStringLiteral)
    .value("HEADER_NAME", pasta::TokenKind::kHeaderName)
    .value("UTF8_STRING_LITERAL", pasta::TokenKind::kUtf8StringLiteral)
    .value("UTF16_STRING_LITERAL", pasta::TokenKind::kUtf16StringLiteral)
    .value("UTF32_STRING_LITERAL", pasta::TokenKind::kUtf32StringLiteral)
    .value("L_SQUARE", pasta::TokenKind::kLSquare)
    .value("R_SQUARE", pasta::TokenKind::kRSquare)
    .value("L_PARENTHESIS", pasta::TokenKind::kLParenthesis)
    .value("R_PARENTHESIS", pasta::TokenKind::kRParenthesis)
    .value("L_BRACE_TOKEN", pasta::TokenKind::kLBraceToken)
    .value("R_BRACE_TOKEN", pasta::TokenKind::kRBraceToken)
    .value("PERIOD", pasta::TokenKind::kPeriod)
    .value("ELLIPSIS", pasta::TokenKind::kEllipsis)
    .value("AMP", pasta::TokenKind::kAmp)
    .value("AMP_AMP", pasta::TokenKind::kAmpAmp)
    .value("AMP_EQUAL", pasta::TokenKind::kAmpEqual)
    .value("STAR", pasta::TokenKind::kStar)
    .value("STAR_EQUAL", pasta::TokenKind::kStarEqual)
    .value("PLUS", pasta::TokenKind::kPlus)
    .value("PLUS_PLUS", pasta::TokenKind::kPlusPlus)
    .value("PLUS_EQUAL", pasta::TokenKind::kPlusEqual)
    .value("MINUS", pasta::TokenKind::kMinus)
    .value("ARROW", pasta::TokenKind::kArrow)
    .value("MINUS_MINUS", pasta::TokenKind::kMinusMinus)
    .value("MINUS_EQUAL", pasta::TokenKind::kMinusEqual)
    .value("TILDE", pasta::TokenKind::kTilde)
    .value("EXCLAIM", pasta::TokenKind::kExclaim)
    .value("EXCLAIM_EQUAL", pasta::TokenKind::kExclaimEqual)
    .value("SLASH", pasta::TokenKind::kSlash)
    .value("SLASH_EQUAL", pasta::TokenKind::kSlashEqual)
    .value("PERCENT", pasta::TokenKind::kPercent)
    .value("PERCENT_EQUAL", pasta::TokenKind::kPercentEqual)
    .value("LESS", pasta::TokenKind::kLess)
    .value("LESS_LESS", pasta::TokenKind::kLessLess)
    .value("LESS_EQUAL", pasta::TokenKind::kLessEqual)
    .value("LESS_LESS_EQUAL", pasta::TokenKind::kLessLessEqual)
    .value("SPACESHIP", pasta::TokenKind::kSpaceship)
    .value("GREATER", pasta::TokenKind::kGreater)
    .value("GREATER_GREATER", pasta::TokenKind::kGreaterGreater)
    .value("GREATER_EQUAL", pasta::TokenKind::kGreaterEqual)
    .value("GREATER_GREATER_EQUAL", pasta::TokenKind::kGreaterGreaterEqual)
    .value("CARET", pasta::TokenKind::kCaret)
    .value("CARET_EQUAL", pasta::TokenKind::kCaretEqual)
    .value("PIPE", pasta::TokenKind::kPipe)
    .value("PIPE_PIPE", pasta::TokenKind::kPipePipe)
    .value("PIPE_EQUAL", pasta::TokenKind::kPipeEqual)
    .value("QUESTION", pasta::TokenKind::kQuestion)
    .value("COLON", pasta::TokenKind::kColon)
    .value("SEMI", pasta::TokenKind::kSemi)
    .value("EQUAL", pasta::TokenKind::kEqual)
    .value("EQUAL_EQUAL", pasta::TokenKind::kEqualEqual)
    .value("COMMA", pasta::TokenKind::kComma)
    .value("HASH", pasta::TokenKind::kHash)
    .value("HASH_HASH", pasta::TokenKind::kHashHash)
    .value("HASHAT", pasta::TokenKind::kHashat)
    .value("PERIOD_STAR", pasta::TokenKind::kPeriodStar)
    .value("ARROW_STAR", pasta::TokenKind::kArrowStar)
    .value("COLON_COLON", pasta::TokenKind::kColonColon)
    .value("AT", pasta::TokenKind::kAt)
    .value("LESS_LESS_LESS", pasta::TokenKind::kLessLessLess)
    .value("GREATER_GREATER_GREATER", pasta::TokenKind::kGreaterGreaterGreater)
    .value("CARETCARET", pasta::TokenKind::kCaretcaret)
    .value("KEYWORD_AUTO", pasta::TokenKind::kKeywordAuto)
    .value("KEYWORD_BREAK", pasta::TokenKind::kKeywordBreak)
    .value("KEYWORD_CASE", pasta::TokenKind::kKeywordCase)
    .value("KEYWORD_CHARACTER", pasta::TokenKind::kKeywordCharacter)
    .value("KEYWORD_CONST", pasta::TokenKind::kKeywordConst)
    .value("KEYWORD_CONTINUE", pasta::TokenKind::kKeywordContinue)
    .value("KEYWORD_DEFAULT", pasta::TokenKind::kKeywordDefault)
    .value("KEYWORD_DO", pasta::TokenKind::kKeywordDo)
    .value("KEYWORD_DOUBLE", pasta::TokenKind::kKeywordDouble)
    .value("KEYWORD_ELSE", pasta::TokenKind::kKeywordElse)
    .value("KEYWORD_ENUM", pasta::TokenKind::kKeywordEnum)
    .value("KEYWORD_EXTERN", pasta::TokenKind::kKeywordExtern)
    .value("KEYWORD_FLOAT", pasta::TokenKind::kKeywordFloat)
    .value("KEYWORD_FOR", pasta::TokenKind::kKeywordFor)
    .value("KEYWORD_GOTO", pasta::TokenKind::kKeywordGoto)
    .value("KEYWORD_IF", pasta::TokenKind::kKeywordIf)
    .value("KEYWORD_INT", pasta::TokenKind::kKeywordInt)
    .value("KEYWORD__EXT_INT", pasta::TokenKind::kKeyword_ExtInt)
    .value("KEYWORD__BIT_INT", pasta::TokenKind::kKeyword_BitInt)
    .value("KEYWORD_LONG", pasta::TokenKind::kKeywordLong)
    .value("KEYWORD_REGISTER", pasta::TokenKind::kKeywordRegister)
    .value("KEYWORD_RETURN", pasta::TokenKind::kKeywordReturn)
    .value("KEYWORD_SHORT", pasta::TokenKind::kKeywordShort)
    .value("KEYWORD_SIGNED", pasta::TokenKind::kKeywordSigned)
    .value("KEYWORD_SIZEOF", pasta::TokenKind::kKeywordSizeof)
    .value("KEYWORD_STATIC", pasta::TokenKind::kKeywordStatic)
    .value("KEYWORD_STRUCT", pasta::TokenKind::kKeywordStruct)
    .value("KEYWORD_SWITCH", pasta::TokenKind::kKeywordSwitch)
    .value("KEYWORD_TYPEDEF", pasta::TokenKind::kKeywordTypedef)
    .value("KEYWORD_UNION", pasta::TokenKind::kKeywordUnion)
    .value("KEYWORD_UNSIGNED", pasta::TokenKind::kKeywordUnsigned)
    .value("KEYWORD_VOID", pasta::TokenKind::kKeywordVoid)
    .value("KEYWORD_VOLATILE", pasta::TokenKind::kKeywordVolatile)
    .value("KEYWORD_WHILE", pasta::TokenKind::kKeywordWhile)
    .value("KEYWORD__ALIGNAS", pasta::TokenKind::kKeyword_Alignas)
    .value("KEYWORD__ALIGNOF", pasta::TokenKind::kKeyword_Alignof)
    .value("KEYWORD__ATOMIC", pasta::TokenKind::kKeyword_Atomic)
    .value("KEYWORD__BOOLEAN", pasta::TokenKind::kKeyword_Boolean)
    .value("KEYWORD__COMPLEX", pasta::TokenKind::kKeyword_Complex)
    .value("KEYWORD__GENERIC", pasta::TokenKind::kKeyword_Generic)
    .value("KEYWORD__IMAGINARY", pasta::TokenKind::kKeyword_Imaginary)
    .value("KEYWORD__NORETURN", pasta::TokenKind::kKeyword_Noreturn)
    .value("KEYWORD__STATIC_ASSERT", pasta::TokenKind::kKeyword_StaticAssert)
    .value("KEYWORD__THREAD_LOCAL", pasta::TokenKind::kKeyword_ThreadLocal)
    .value("KEYWORD___FUNC__", pasta::TokenKind::kKeyword__Func__)
    .value("KEYWORD___OBJC_YES", pasta::TokenKind::kKeyword__ObjcYes)
    .value("KEYWORD___OBJC_NO", pasta::TokenKind::kKeyword__ObjcNo)
    .value("KEYWORD_ASSEMBLY", pasta::TokenKind::kKeywordAssembly)
    .value("KEYWORD_BOOLEAN", pasta::TokenKind::kKeywordBoolean)
    .value("KEYWORD_CATCH", pasta::TokenKind::kKeywordCatch)
    .value("KEYWORD_CLASS", pasta::TokenKind::kKeywordClass)
    .value("KEYWORD_CONST_CAST", pasta::TokenKind::kKeywordConstCast)
    .value("KEYWORD_DELETE", pasta::TokenKind::kKeywordDelete)
    .value("KEYWORD_DYNAMIC_CAST", pasta::TokenKind::kKeywordDynamicCast)
    .value("KEYWORD_EXPLICIT", pasta::TokenKind::kKeywordExplicit)
    .value("KEYWORD_EXPORT", pasta::TokenKind::kKeywordExport)
    .value("KEYWORD_FALSE", pasta::TokenKind::kKeywordFalse)
    .value("KEYWORD_FRIEND", pasta::TokenKind::kKeywordFriend)
    .value("KEYWORD_MUTABLE", pasta::TokenKind::kKeywordMutable)
    .value("KEYWORD_NAMESPACE", pasta::TokenKind::kKeywordNamespace)
    .value("KEYWORD_NEW", pasta::TokenKind::kKeywordNew)
    .value("KEYWORD_OPERATOR", pasta::TokenKind::kKeywordOperator)
    .value("KEYWORD_PRIVATE", pasta::TokenKind::kKeywordPrivate)
    .value("KEYWORD_PROTECTED", pasta::TokenKind::kKeywordProtected)
    .value("KEYWORD_PUBLIC", pasta::TokenKind::kKeywordPublic)
    .value("KEYWORD_REINTERPRET_CAST", pasta::TokenKind::kKeywordReinterpretCast)
    .value("KEYWORD_STATIC_CAST", pasta::TokenKind::kKeywordStaticCast)
    .value("KEYWORD_TEMPLATE", pasta::TokenKind::kKeywordTemplate)
    .value("KEYWORD_THIS", pasta::TokenKind::kKeywordThis)
    .value("KEYWORD_THROW", pasta::TokenKind::kKeywordThrow)
    .value("KEYWORD_TRUE", pasta::TokenKind::kKeywordTrue)
    .value("KEYWORD_TRY", pasta::TokenKind::kKeywordTry)
    .value("KEYWORD_TYPENAME", pasta::TokenKind::kKeywordTypename)
    .value("KEYWORD_TYPEID", pasta::TokenKind::kKeywordTypeid)
    .value("KEYWORD_USING", pasta::TokenKind::kKeywordUsing)
    .value("KEYWORD_VIRTUAL", pasta::TokenKind::kKeywordVirtual)
    .value("KEYWORD_WCHAR_T", pasta::TokenKind::kKeywordWcharT)
    .value("KEYWORD_RESTRICT", pasta::TokenKind::kKeywordRestrict)
    .value("KEYWORD_INLINE", pasta::TokenKind::kKeywordInline)
    .value("KEYWORD_ALIGNAS", pasta::TokenKind::kKeywordAlignas)
    .value("KEYWORD_ALIGNOF", pasta::TokenKind::kKeywordAlignof)
    .value("KEYWORD_CHAR16_T", pasta::TokenKind::kKeywordChar16T)
    .value("KEYWORD_CHAR32_T", pasta::TokenKind::kKeywordChar32T)
    .value("KEYWORD_CONSTEXPR", pasta::TokenKind::kKeywordConstexpr)
    .value("KEYWORD_DECLTYPE", pasta::TokenKind::kKeywordDecltype)
    .value("KEYWORD_NOEXCEPT", pasta::TokenKind::kKeywordNoexcept)
    .value("KEYWORD_NULLPTR", pasta::TokenKind::kKeywordNullptr)
    .value("KEYWORD_STATIC_ASSERT", pasta::TokenKind::kKeywordStaticAssert)
    .value("KEYWORD_THREAD_LOCAL", pasta::TokenKind::kKeywordThreadLocal)
    .value("KEYWORD_CO_AWAIT", pasta::TokenKind::kKeywordCoAwait)
    .value("KEYWORD_CO_RETURN", pasta::TokenKind::kKeywordCoReturn)
    .value("KEYWORD_CO_YIELD", pasta::TokenKind::kKeywordCoYield)
    .value("KEYWORD_MODULE", pasta::TokenKind::kKeywordModule)
    .value("KEYWORD_IMPORT", pasta::TokenKind::kKeywordImport)
    .value("KEYWORD_CONSTEVAL", pasta::TokenKind::kKeywordConsteval)
    .value("KEYWORD_CONSTINIT", pasta::TokenKind::kKeywordConstinit)
    .value("KEYWORD_CONCEPT", pasta::TokenKind::kKeywordConcept)
    .value("KEYWORD_REQUIRES", pasta::TokenKind::kKeywordRequires)
    .value("KEYWORD_CHAR8_T", pasta::TokenKind::kKeywordChar8T)
    .value("KEYWORD__FLOAT16", pasta::TokenKind::kKeyword_Float16)
    .value("KEYWORD_TYPEOF", pasta::TokenKind::kKeywordTypeof)
    .value("KEYWORD_TYPEOF_UNQUALIFIED", pasta::TokenKind::kKeywordTypeofUnqualified)
    .value("KEYWORD__ACCUM", pasta::TokenKind::kKeyword_Accum)
    .value("KEYWORD__FRACT", pasta::TokenKind::kKeyword_Fract)
    .value("KEYWORD__SAT", pasta::TokenKind::kKeyword_Sat)
    .value("KEYWORD__DECIMAL32", pasta::TokenKind::kKeyword_Decimal32)
    .value("KEYWORD__DECIMAL64", pasta::TokenKind::kKeyword_Decimal64)
    .value("KEYWORD__DECIMAL128", pasta::TokenKind::kKeyword_Decimal128)
    .value("KEYWORD___NULL", pasta::TokenKind::kKeyword__Null)
    .value("KEYWORD___ALIGNOF", pasta::TokenKind::kKeyword__Alignof)
    .value("KEYWORD___ATTRIBUTE", pasta::TokenKind::kKeyword__Attribute)
    .value("KEYWORD___BUILTIN_CHOOSE_EXPRESSION", pasta::TokenKind::kKeyword__BuiltinChooseExpression)
    .value("KEYWORD___BUILTIN_OFFSETOF", pasta::TokenKind::kKeyword__BuiltinOffsetof)
    .value("KEYWORD___BUILTIN_FILE", pasta::TokenKind::kKeyword__BuiltinFILE)
    .value("KEYWORD___BUILTIN_FUNCTION", pasta::TokenKind::kKeyword__BuiltinFUNCTION)
    .value("KEYWORD___BUILTIN_LINE", pasta::TokenKind::kKeyword__BuiltinLINE)
    .value("KEYWORD___BUILTIN_COLUMN", pasta::TokenKind::kKeyword__BuiltinCOLUMN)
    .value("KEYWORD___BUILTIN_SOURCE_TOKEN", pasta::TokenKind::kKeyword__BuiltinSourceToken)
    .value("KEYWORD___BUILTIN_TYPES_COMPATIBLE_P", pasta::TokenKind::kKeyword__BuiltinTypesCompatibleP)
    .value("KEYWORD___BUILTIN_VA_ARGUMENT", pasta::TokenKind::kKeyword__BuiltinVaArgument)
    .value("KEYWORD___EXTENSION__", pasta::TokenKind::kKeyword__Extension__)
    .value("KEYWORD___FLOAT128", pasta::TokenKind::kKeyword__Float128)
    .value("KEYWORD___IBM128", pasta::TokenKind::kKeyword__Ibm128)
    .value("KEYWORD___IMAG", pasta::TokenKind::kKeyword__Imag)
    .value("KEYWORD___INT128", pasta::TokenKind::kKeyword__Int128)
    .value("KEYWORD___LABEL__", pasta::TokenKind::kKeyword__Label__)
    .value("KEYWORD___REAL", pasta::TokenKind::kKeyword__Real)
    .value("KEYWORD___THREAD", pasta::TokenKind::kKeyword__Thread)
    .value("KEYWORD___FUNCTION__", pasta::TokenKind::kKeyword__FUNCTION__)
    .value("KEYWORD___PRETTYFUNCTION__", pasta::TokenKind::kKeyword__PRETTYFUNCTION__)
    .value("KEYWORD___AUTO_TYPE", pasta::TokenKind::kKeyword__AutoType)
    .value("KEYWORD___FUNCDNAME__", pasta::TokenKind::kKeyword__FUNCDNAME__)
    .value("KEYWORD___FUNCSIG__", pasta::TokenKind::kKeyword__FUNCSIG__)
    .value("KEYWORD_LFUNCTION__", pasta::TokenKind::kKeywordLFUNCTION__)
    .value("KEYWORD_LFUNCSIG__", pasta::TokenKind::kKeywordLFUNCSIG__)
    .value("KEYWORD___IS_INTERFACE_CLASS", pasta::TokenKind::kKeyword__IsInterfaceClass)
    .value("KEYWORD___IS_SEALED", pasta::TokenKind::kKeyword__IsSealed)
    .value("KEYWORD___IS_DESTRUCTIBLE", pasta::TokenKind::kKeyword__IsDestructible)
    .value("KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE", pasta::TokenKind::kKeyword__IsTriviallyDestructible)
    .value("KEYWORD___IS_NOTHROW_DESTRUCTIBLE", pasta::TokenKind::kKeyword__IsNothrowDestructible)
    .value("KEYWORD___IS_NOTHROW_ASSIGNABLE", pasta::TokenKind::kKeyword__IsNothrowAssignable)
    .value("KEYWORD___IS_CONSTRUCTIBLE", pasta::TokenKind::kKeyword__IsConstructible)
    .value("KEYWORD___IS_NOTHROW_CONSTRUCTIBLE", pasta::TokenKind::kKeyword__IsNothrowConstructible)
    .value("KEYWORD___IS_ASSIGNABLE", pasta::TokenKind::kKeyword__IsAssignable)
    .value("KEYWORD___HAS_NOTHROW_MOVE_ASSIGN", pasta::TokenKind::kKeyword__HasNothrowMoveAssign)
    .value("KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN", pasta::TokenKind::kKeyword__HasTrivialMoveAssign)
    .value("KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR", pasta::TokenKind::kKeyword__HasTrivialMoveConstructor)
    .value("KEYWORD___HAS_NOTHROW_ASSIGN", pasta::TokenKind::kKeyword__HasNothrowAssign)
    .value("KEYWORD___HAS_NOTHROW_COPY", pasta::TokenKind::kKeyword__HasNothrowCopy)
    .value("KEYWORD___HAS_NOTHROW_CONSTRUCTOR", pasta::TokenKind::kKeyword__HasNothrowConstructor)
    .value("KEYWORD___HAS_TRIVIAL_ASSIGN", pasta::TokenKind::kKeyword__HasTrivialAssign)
    .value("KEYWORD___HAS_TRIVIAL_COPY", pasta::TokenKind::kKeyword__HasTrivialCopy)
    .value("KEYWORD___HAS_TRIVIAL_CONSTRUCTOR", pasta::TokenKind::kKeyword__HasTrivialConstructor)
    .value("KEYWORD___HAS_TRIVIAL_DESTRUCTOR", pasta::TokenKind::kKeyword__HasTrivialDestructor)
    .value("KEYWORD___HAS_VIRTUAL_DESTRUCTOR", pasta::TokenKind::kKeyword__HasVirtualDestructor)
    .value("KEYWORD___IS_ABSTRACT", pasta::TokenKind::kKeyword__IsAbstract)
    .value("KEYWORD___IS_AGGREGATE", pasta::TokenKind::kKeyword__IsAggregate)
    .value("KEYWORD___IS_BASE_OF", pasta::TokenKind::kKeyword__IsBaseOf)
    .value("KEYWORD___IS_CLASS", pasta::TokenKind::kKeyword__IsClass)
    .value("KEYWORD___IS_CONVERTIBLE_TO", pasta::TokenKind::kKeyword__IsConvertibleTo)
    .value("KEYWORD___IS_EMPTY", pasta::TokenKind::kKeyword__IsEmpty)
    .value("KEYWORD___IS_ENUM", pasta::TokenKind::kKeyword__IsEnum)
    .value("KEYWORD___IS_FINAL", pasta::TokenKind::kKeyword__IsFinal)
    .value("KEYWORD___IS_LITERAL", pasta::TokenKind::kKeyword__IsLiteral)
    .value("KEYWORD___IS_POD", pasta::TokenKind::kKeyword__IsPod)
    .value("KEYWORD___IS_POLYMORPHIC", pasta::TokenKind::kKeyword__IsPolymorphic)
    .value("KEYWORD___IS_STANDARD_LAYOUT", pasta::TokenKind::kKeyword__IsStandardLayout)
    .value("KEYWORD___IS_TRIVIAL", pasta::TokenKind::kKeyword__IsTrivial)
    .value("KEYWORD___IS_TRIVIALLY_ASSIGNABLE", pasta::TokenKind::kKeyword__IsTriviallyAssignable)
    .value("KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE", pasta::TokenKind::kKeyword__IsTriviallyConstructible)
    .value("KEYWORD___IS_TRIVIALLY_COPYABLE", pasta::TokenKind::kKeyword__IsTriviallyCopyable)
    .value("KEYWORD___IS_UNION", pasta::TokenKind::kKeyword__IsUnion)
    .value("KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS", pasta::TokenKind::kKeyword__HasUniqueObjectRepresentations)
    .value("KEYWORD___ADD_LVALUE_REFERENCE", pasta::TokenKind::kKeyword__AddLvalueReference)
    .value("KEYWORD___ADD_POINTER", pasta::TokenKind::kKeyword__AddPointer)
    .value("KEYWORD___ADD_RVALUE_REFERENCE", pasta::TokenKind::kKeyword__AddRvalueReference)
    .value("KEYWORD___DECAY", pasta::TokenKind::kKeyword__Decay)
    .value("KEYWORD___MAKE_SIGNED", pasta::TokenKind::kKeyword__MakeSigned)
    .value("KEYWORD___MAKE_UNSIGNED", pasta::TokenKind::kKeyword__MakeUnsigned)
    .value("KEYWORD___REMOVE_ALL_EXTENTS", pasta::TokenKind::kKeyword__RemoveAllExtents)
    .value("KEYWORD___REMOVE_CONST", pasta::TokenKind::kKeyword__RemoveConst)
    .value("KEYWORD___REMOVE_CV", pasta::TokenKind::kKeyword__RemoveCv)
    .value("KEYWORD___REMOVE_CVREF", pasta::TokenKind::kKeyword__RemoveCvref)
    .value("KEYWORD___REMOVE_EXTENT", pasta::TokenKind::kKeyword__RemoveExtent)
    .value("KEYWORD___REMOVE_POINTER", pasta::TokenKind::kKeyword__RemovePointer)
    .value("KEYWORD___REMOVE_REFERENCE_T", pasta::TokenKind::kKeyword__RemoveReferenceT)
    .value("KEYWORD___REMOVE_RESTRICT", pasta::TokenKind::kKeyword__RemoveRestrict)
    .value("KEYWORD___REMOVE_VOLATILE", pasta::TokenKind::kKeyword__RemoveVolatile)
    .value("KEYWORD___UNDERLYING_TYPE", pasta::TokenKind::kKeyword__UnderlyingType)
    .value("KEYWORD___IS_TRIVIALLY_RELOCATABLE", pasta::TokenKind::kKeyword__IsTriviallyRelocatable)
    .value("KEYWORD___IS_BOUNDED_ARRAY", pasta::TokenKind::kKeyword__IsBoundedArray)
    .value("KEYWORD___IS_UNBOUNDED_ARRAY", pasta::TokenKind::kKeyword__IsUnboundedArray)
    .value("KEYWORD___IS_NULLPTR", pasta::TokenKind::kKeyword__IsNullptr)
    .value("KEYWORD___IS_SCOPED_ENUM", pasta::TokenKind::kKeyword__IsScopedEnum)
    .value("KEYWORD___IS_REFERENCEABLE", pasta::TokenKind::kKeyword__IsReferenceable)
    .value("KEYWORD___REFERENCE_BINDS_TO_TEMPORARY", pasta::TokenKind::kKeyword__ReferenceBindsToTemporary)
    .value("KEYWORD___IS_LVALUE_EXPRESSION", pasta::TokenKind::kKeyword__IsLvalueExpression)
    .value("KEYWORD___IS_RVALUE_EXPRESSION", pasta::TokenKind::kKeyword__IsRvalueExpression)
    .value("KEYWORD___IS_ARITHMETIC", pasta::TokenKind::kKeyword__IsArithmetic)
    .value("KEYWORD___IS_FLOATING_POINT", pasta::TokenKind::kKeyword__IsFloatingPoint)
    .value("KEYWORD___IS_INTEGRAL", pasta::TokenKind::kKeyword__IsIntegral)
    .value("KEYWORD___IS_COMPLETE_TYPE", pasta::TokenKind::kKeyword__IsCompleteType)
    .value("KEYWORD___IS_VOID", pasta::TokenKind::kKeyword__IsVoid)
    .value("KEYWORD___IS_ARRAY", pasta::TokenKind::kKeyword__IsArray)
    .value("KEYWORD___IS_FUNCTION", pasta::TokenKind::kKeyword__IsFunction)
    .value("KEYWORD___IS_REFERENCE", pasta::TokenKind::kKeyword__IsReference)
    .value("KEYWORD___IS_LVALUE_REFERENCE", pasta::TokenKind::kKeyword__IsLvalueReference)
    .value("KEYWORD___IS_RVALUE_REFERENCE", pasta::TokenKind::kKeyword__IsRvalueReference)
    .value("KEYWORD___IS_FUNDAMENTAL", pasta::TokenKind::kKeyword__IsFundamental)
    .value("KEYWORD___IS_OBJECT", pasta::TokenKind::kKeyword__IsObject)
    .value("KEYWORD___IS_SCALAR", pasta::TokenKind::kKeyword__IsScalar)
    .value("KEYWORD___IS_COMPOUND", pasta::TokenKind::kKeyword__IsCompound)
    .value("KEYWORD___IS_POINTER", pasta::TokenKind::kKeyword__IsPointer)
    .value("KEYWORD___IS_MEMBER_OBJECT_POINTER", pasta::TokenKind::kKeyword__IsMemberObjectPointer)
    .value("KEYWORD___IS_MEMBER_FUNCTION_POINTER", pasta::TokenKind::kKeyword__IsMemberFunctionPointer)
    .value("KEYWORD___IS_MEMBER_POINTER", pasta::TokenKind::kKeyword__IsMemberPointer)
    .value("KEYWORD___IS_CONST", pasta::TokenKind::kKeyword__IsConst)
    .value("KEYWORD___IS_VOLATILE", pasta::TokenKind::kKeyword__IsVolatile)
    .value("KEYWORD___IS_SIGNED", pasta::TokenKind::kKeyword__IsSigned)
    .value("KEYWORD___IS_UNSIGNED", pasta::TokenKind::kKeyword__IsUnsigned)
    .value("KEYWORD___IS_SAME", pasta::TokenKind::kKeyword__IsSame)
    .value("KEYWORD___IS_CONVERTIBLE", pasta::TokenKind::kKeyword__IsConvertible)
    .value("KEYWORD___ARRAY_RANK", pasta::TokenKind::kKeyword__ArrayRank)
    .value("KEYWORD___ARRAY_EXTENT", pasta::TokenKind::kKeyword__ArrayExtent)
    .value("KEYWORD___PRIVATE_EXTERN__", pasta::TokenKind::kKeyword__PrivateExtern__)
    .value("KEYWORD___MODULE_PRIVATE__", pasta::TokenKind::kKeyword__ModulePrivate__)
    .value("KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR", pasta::TokenKind::kKeyword__BuiltinPtrauthTypeDiscriminator)
    .value("KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE", pasta::TokenKind::kKeyword__BuiltinXnuTypeSignature)
    .value("KEYWORD___BUILTIN_XNU_TYPE_SUMMARY", pasta::TokenKind::kKeyword__BuiltinXnuTypeSummary)
    .value("KEYWORD___BUILTIN_TMO_TYPE_METADATA", pasta::TokenKind::kKeyword__BuiltinTmoTypeMetadata)
    .value("KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE", pasta::TokenKind::kKeyword__BuiltinXnuTypesCompatible)
    .value("KEYWORD___DECLSPEC", pasta::TokenKind::kKeyword__Declspec)
    .value("KEYWORD___CDECL", pasta::TokenKind::kKeyword__Cdecl)
    .value("KEYWORD___STDCALL", pasta::TokenKind::kKeyword__Stdcall)
    .value("KEYWORD___FASTCALL", pasta::TokenKind::kKeyword__Fastcall)
    .value("KEYWORD___THISCALL", pasta::TokenKind::kKeyword__Thiscall)
    .value("KEYWORD___REGCALL", pasta::TokenKind::kKeyword__Regcall)
    .value("KEYWORD___VECTORCALL", pasta::TokenKind::kKeyword__Vectorcall)
    .value("KEYWORD___FORCEINLINE", pasta::TokenKind::kKeyword__Forceinline)
    .value("KEYWORD___UNALIGNED", pasta::TokenKind::kKeyword__Unaligned)
    .value("KEYWORD___SUPER", pasta::TokenKind::kKeyword__Super)
    .value("KEYWORD___GLOBAL", pasta::TokenKind::kKeyword__Global)
    .value("KEYWORD___LOCAL", pasta::TokenKind::kKeyword__Local)
    .value("KEYWORD___CONSTANT", pasta::TokenKind::kKeyword__Constant)
    .value("KEYWORD___PRIVATE", pasta::TokenKind::kKeyword__Private)
    .value("KEYWORD___GENERIC", pasta::TokenKind::kKeyword__Generic)
    .value("KEYWORD___KERNEL", pasta::TokenKind::kKeyword__Kernel)
    .value("KEYWORD___READ_ONLY", pasta::TokenKind::kKeyword__ReadOnly)
    .value("KEYWORD___WRITE_ONLY", pasta::TokenKind::kKeyword__WriteOnly)
    .value("KEYWORD___READ_WRITE", pasta::TokenKind::kKeyword__ReadWrite)
    .value("KEYWORD___BUILTIN_ASTYPE", pasta::TokenKind::kKeyword__BuiltinAstype)
    .value("KEYWORD_VEC_STEP", pasta::TokenKind::kKeywordVecStep)
    .value("KEYWORD_IMAGE_1D_T", pasta::TokenKind::kKeywordImage1dT)
    .value("KEYWORD_IMAGE_1D_ARRAY_T", pasta::TokenKind::kKeywordImage1dArrayT)
    .value("KEYWORD_IMAGE_1D_BUFFER_T", pasta::TokenKind::kKeywordImage1dBufferT)
    .value("KEYWORD_IMAGE_2D_T", pasta::TokenKind::kKeywordImage2dT)
    .value("KEYWORD_IMAGE_2D_ARRAY_T", pasta::TokenKind::kKeywordImage2dArrayT)
    .value("KEYWORD_IMAGE_2D_DEPTH_T", pasta::TokenKind::kKeywordImage2dDepthT)
    .value("KEYWORD_IMAGE_2D_ARRAY_DEPTH_T", pasta::TokenKind::kKeywordImage2dArrayDepthT)
    .value("KEYWORD_IMAGE_2D_MSAA_T", pasta::TokenKind::kKeywordImage2dMsaaT)
    .value("KEYWORD_IMAGE_2D_ARRAY_MSAA_T", pasta::TokenKind::kKeywordImage2dArrayMsaaT)
    .value("KEYWORD_IMAGE_2D_MSAA_DEPTH_T", pasta::TokenKind::kKeywordImage2dMsaaDepthT)
    .value("KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T", pasta::TokenKind::kKeywordImage2dArrayMsaaDepthT)
    .value("KEYWORD_IMAGE_3D_T", pasta::TokenKind::kKeywordImage3dT)
    .value("KEYWORD_PIPE", pasta::TokenKind::kKeywordPipe)
    .value("KEYWORD_ADDRSPACE_CAST", pasta::TokenKind::kKeywordAddrspaceCast)
    .value("KEYWORD___NOINLINE__", pasta::TokenKind::kKeyword__Noinline__)
    .value("KEYWORD_CBUFFER", pasta::TokenKind::kKeywordCbuffer)
    .value("KEYWORD_TBUFFER", pasta::TokenKind::kKeywordTbuffer)
    .value("KEYWORD_GROUPSHARED", pasta::TokenKind::kKeywordGroupshared)
    .value("KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN", pasta::TokenKind::kKeyword__BuiltinOmpRequiredSimdAlign)
    .value("KEYWORD___PASCAL", pasta::TokenKind::kKeyword__Pascal)
    .value("KEYWORD___VECTOR", pasta::TokenKind::kKeyword__Vector)
    .value("KEYWORD___PIXEL", pasta::TokenKind::kKeyword__Pixel)
    .value("KEYWORD___BOOLEAN", pasta::TokenKind::kKeyword__Boolean)
    .value("KEYWORD___BF16", pasta::TokenKind::kKeyword__Bf16)
    .value("KEYWORD_HALF", pasta::TokenKind::kKeywordHalf)
    .value("KEYWORD___BRIDGE", pasta::TokenKind::kKeyword__Bridge)
    .value("KEYWORD___BRIDGE_TRANSFER", pasta::TokenKind::kKeyword__BridgeTransfer)
    .value("KEYWORD___BRIDGE_RETAINED", pasta::TokenKind::kKeyword__BridgeRetained)
    .value("KEYWORD___BRIDGE_RETAIN", pasta::TokenKind::kKeyword__BridgeRetain)
    .value("KEYWORD___COVARIANT", pasta::TokenKind::kKeyword__Covariant)
    .value("KEYWORD___CONTRAVARIANT", pasta::TokenKind::kKeyword__Contravariant)
    .value("KEYWORD___KINDOF", pasta::TokenKind::kKeyword__Kindof)
    .value("KEYWORD__NONNULL", pasta::TokenKind::kKeyword_Nonnull)
    .value("KEYWORD__NULLABLE", pasta::TokenKind::kKeyword_Nullable)
    .value("KEYWORD__NULLABLE_RESULT", pasta::TokenKind::kKeyword_NullableResult)
    .value("KEYWORD__NULL_UNSPECIFIED", pasta::TokenKind::kKeyword_NullUnspecified)
    .value("KEYWORD___PTR64", pasta::TokenKind::kKeyword__Ptr64)
    .value("KEYWORD___PTR32", pasta::TokenKind::kKeyword__Ptr32)
    .value("KEYWORD___SPTR", pasta::TokenKind::kKeyword__Sptr)
    .value("KEYWORD___UPTR", pasta::TokenKind::kKeyword__Uptr)
    .value("KEYWORD___W64", pasta::TokenKind::kKeyword__W64)
    .value("KEYWORD___UUIDOF", pasta::TokenKind::kKeyword__Uuidof)
    .value("KEYWORD___TRY", pasta::TokenKind::kKeyword__Try)
    .value("KEYWORD___FINALLY", pasta::TokenKind::kKeyword__Finally)
    .value("KEYWORD___LEAVE", pasta::TokenKind::kKeyword__Leave)
    .value("KEYWORD___INT64", pasta::TokenKind::kKeyword__Int64)
    .value("KEYWORD___IF_EXISTS", pasta::TokenKind::kKeyword__IfExists)
    .value("KEYWORD___IF_NOT_EXISTS", pasta::TokenKind::kKeyword__IfNotExists)
    .value("KEYWORD___SINGLE_INHERITANCE", pasta::TokenKind::kKeyword__SingleInheritance)
    .value("KEYWORD___MULTIPLE_INHERITANCE", pasta::TokenKind::kKeyword__MultipleInheritance)
    .value("KEYWORD___VIRTUAL_INHERITANCE", pasta::TokenKind::kKeyword__VirtualInheritance)
    .value("KEYWORD___INTERFACE", pasta::TokenKind::kKeyword__Interface)
    .value("KEYWORD___BUILTIN_CONVERTVECTOR", pasta::TokenKind::kKeyword__BuiltinConvertvector)
    .value("KEYWORD___BUILTIN_BIT_CAST", pasta::TokenKind::kKeyword__BuiltinBitCast)
    .value("KEYWORD___BUILTIN_AVAILABLE", pasta::TokenKind::kKeyword__BuiltinAvailable)
    .value("KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME", pasta::TokenKind::kKeyword__BuiltinSyclUniqueStableName)
    .value("KEYWORD___UNKNOWN_ANYTYPE", pasta::TokenKind::kKeyword__UnknownAnytype)
    .value("ANNOT_CXXSCOPE", pasta::TokenKind::kAnnotCxxscope)
    .value("ANNOT_TYPENAME", pasta::TokenKind::kAnnotTypename)
    .value("ANNOT_TEMPLATE_ID", pasta::TokenKind::kAnnotTemplateId)
    .value("ANNOT_NON_TYPE", pasta::TokenKind::kAnnotNonType)
    .value("ANNOT_NON_TYPE_UNDECLARED", pasta::TokenKind::kAnnotNonTypeUndeclared)
    .value("ANNOT_NON_TYPE_DEPENDENT", pasta::TokenKind::kAnnotNonTypeDependent)
    .value("ANNOT_OVERLOAD", pasta::TokenKind::kAnnotOverload)
    .value("ANNOT_PRIMARY_EXPRESSION", pasta::TokenKind::kAnnotPrimaryExpression)
    .value("ANNOT_DECLTYPE", pasta::TokenKind::kAnnotDecltype)
    .value("ANNOT_PRAGMA_UNUSED", pasta::TokenKind::kAnnotPragmaUnused)
    .value("ANNOT_PRAGMA_VIS", pasta::TokenKind::kAnnotPragmaVis)
    .value("ANNOT_PRAGMA_PACK", pasta::TokenKind::kAnnotPragmaPack)
    .value("ANNOT_PRAGMA_PARSER_CRASH", pasta::TokenKind::kAnnotPragmaParserCrash)
    .value("ANNOT_PRAGMA_CAPTURED", pasta::TokenKind::kAnnotPragmaCaptured)
    .value("ANNOT_PRAGMA_DUMP", pasta::TokenKind::kAnnotPragmaDump)
    .value("ANNOT_PRAGMA_MSSTRUCT", pasta::TokenKind::kAnnotPragmaMsstruct)
    .value("ANNOT_PRAGMA_ALIGN", pasta::TokenKind::kAnnotPragmaAlign)
    .value("ANNOT_PRAGMA_WEAK", pasta::TokenKind::kAnnotPragmaWeak)
    .value("ANNOT_PRAGMA_WEAKALIAS", pasta::TokenKind::kAnnotPragmaWeakalias)
    .value("ANNOT_PRAGMA_REDEFINE_EXTNAME", pasta::TokenKind::kAnnotPragmaRedefineExtname)
    .value("ANNOT_PRAGMA_FP_CONTRACT", pasta::TokenKind::kAnnotPragmaFpContract)
    .value("ANNOT_PRAGMA_FENV_ACCESS", pasta::TokenKind::kAnnotPragmaFenvAccess)
    .value("ANNOT_PRAGMA_FENV_ACCESS_MS", pasta::TokenKind::kAnnotPragmaFenvAccessMs)
    .value("ANNOT_PRAGMA_FENV_ROUND", pasta::TokenKind::kAnnotPragmaFenvRound)
    .value("ANNOT_PRAGMA_FLOAT_CONTROL", pasta::TokenKind::kAnnotPragmaFloatControl)
    .value("ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS", pasta::TokenKind::kAnnotPragmaMsPointersToMembers)
    .value("ANNOT_PRAGMA_MS_VTORDISP", pasta::TokenKind::kAnnotPragmaMsVtordisp)
    .value("ANNOT_PRAGMA_MS_PRAGMA", pasta::TokenKind::kAnnotPragmaMsPragma)
    .value("ANNOT_PRAGMA_OPENCL_EXTENSION", pasta::TokenKind::kAnnotPragmaOpenclExtension)
    .value("ANNOT_ATTRIBUTE_OPENMP", pasta::TokenKind::kAnnotAttributeOpenmp)
    .value("ANNOT_PRAGMA_OPENMP", pasta::TokenKind::kAnnotPragmaOpenmp)
    .value("ANNOT_PRAGMA_OPENMP_END", pasta::TokenKind::kAnnotPragmaOpenmpEnd)
    .value("ANNOT_PRAGMA_LOOP_HINT", pasta::TokenKind::kAnnotPragmaLoopHint)
    .value("ANNOT_PRAGMA_FP", pasta::TokenKind::kAnnotPragmaFp)
    .value("ANNOT_PRAGMA_ATTRIBUTE", pasta::TokenKind::kAnnotPragmaAttribute)
    .value("ANNOT_PRAGMA_RISCV", pasta::TokenKind::kAnnotPragmaRiscv)
    .value("ANNOT_MODULE_INCLUDE", pasta::TokenKind::kAnnotModuleInclude)
    .value("ANNOT_MODULE_BEGIN", pasta::TokenKind::kAnnotModuleBegin)
    .value("ANNOT_MODULE_END", pasta::TokenKind::kAnnotModuleEnd)
    .value("ANNOT_HEADER_UNIT", pasta::TokenKind::kAnnotHeaderUnit);

  nb::enum_<pasta::TrailingAllocKind>(m, "TrailingAllocKind")
    .value("TAK_INHERITS_CONSTRUCTOR", pasta::TrailingAllocKind::kTAKInheritsConstructor)
    .value("TAK_HAS_TAIL_EXPLICIT", pasta::TrailingAllocKind::kTAKHasTailExplicit);

  nb::enum_<pasta::TranslationUnitKind>(m, "TranslationUnitKind")
    .value("COMPLETE", pasta::TranslationUnitKind::kComplete)
    .value("PREFIX", pasta::TranslationUnitKind::kPrefix)
    .value("MODULE", pasta::TranslationUnitKind::kModule)
    .value("INCREMENTAL", pasta::TranslationUnitKind::kIncremental);

  nb::enum_<pasta::TrivialAutoVarInitKind>(m, "TrivialAutoVarInitKind")
    .value("UNINITIALIZED", pasta::TrivialAutoVarInitKind::kUninitialized)
    .value("ZERO", pasta::TrivialAutoVarInitKind::kZero)
    .value("PATTERN", pasta::TrivialAutoVarInitKind::kPattern);

  nb::enum_<pasta::TypeDependence>(m, "TypeDependence")
    .value("UNEXPANDED_PACK", pasta::TypeDependence::kUnexpandedPack)
    .value("INSTANTIATION", pasta::TypeDependence::kInstantiation)
    .value("DEPENDENT", pasta::TypeDependence::kDependent)
    .value("VARIABLY_MODIFIED", pasta::TypeDependence::kVariablyModified)
    .value("ERROR", pasta::TypeDependence::kError)
    .value("NONE", pasta::TypeDependence::kNone)
    .value("ALL", pasta::TypeDependence::kAll)
    .value("DEPENDENT_INSTANTIATION", pasta::TypeDependence::kDependentInstantiation);

  nb::enum_<pasta::TypeLocClass>(m, "TypeLocClass")
    .value("ADJUSTED", pasta::TypeLocClass::kAdjusted)
    .value("DECAYED", pasta::TypeLocClass::kDecayed)
    .value("CONSTANT_ARRAY", pasta::TypeLocClass::kConstantArray)
    .value("DEPENDENT_SIZED_ARRAY", pasta::TypeLocClass::kDependentSizedArray)
    .value("INCOMPLETE_ARRAY", pasta::TypeLocClass::kIncompleteArray)
    .value("VARIABLE_ARRAY", pasta::TypeLocClass::kVariableArray)
    .value("ATOMIC", pasta::TypeLocClass::kAtomic)
    .value("ATTRIBUTED", pasta::TypeLocClass::kAttributed)
    .value("BTF_TAG_ATTRIBUTED", pasta::TypeLocClass::kBTFTagAttributed)
    .value("BIT_INT", pasta::TypeLocClass::kBitInt)
    .value("BLOCK_POINTER", pasta::TypeLocClass::kBlockPointer)
    .value("BUILTIN", pasta::TypeLocClass::kBuiltin)
    .value("COMPLEX", pasta::TypeLocClass::kComplex)
    .value("DECLTYPE", pasta::TypeLocClass::kDecltype)
    .value("AUTO", pasta::TypeLocClass::kAuto)
    .value("DEDUCED_TEMPLATE_SPECIALIZATION", pasta::TypeLocClass::kDeducedTemplateSpecialization)
    .value("DEPENDENT_ADDRESS_SPACE", pasta::TypeLocClass::kDependentAddressSpace)
    .value("DEPENDENT_BIT_INT", pasta::TypeLocClass::kDependentBitInt)
    .value("DEPENDENT_NAME", pasta::TypeLocClass::kDependentName)
    .value("DEPENDENT_SIZED_EXT_VECTOR", pasta::TypeLocClass::kDependentSizedExtVector)
    .value("DEPENDENT_TEMPLATE_SPECIALIZATION", pasta::TypeLocClass::kDependentTemplateSpecialization)
    .value("DEPENDENT_VECTOR", pasta::TypeLocClass::kDependentVector)
    .value("ELABORATED", pasta::TypeLocClass::kElaborated)
    .value("FUNCTION_NO_PROTO", pasta::TypeLocClass::kFunctionNoProto)
    .value("FUNCTION_PROTO", pasta::TypeLocClass::kFunctionProto)
    .value("INJECTED_CLASS_NAME", pasta::TypeLocClass::kInjectedClassName)
    .value("MACRO_QUALIFIED", pasta::TypeLocClass::kMacroQualified)
    .value("CONSTANT_MATRIX", pasta::TypeLocClass::kConstantMatrix)
    .value("DEPENDENT_SIZED_MATRIX", pasta::TypeLocClass::kDependentSizedMatrix)
    .value("MEMBER_POINTER", pasta::TypeLocClass::kMemberPointer)
    .value("OBJ_C_OBJECT_POINTER", pasta::TypeLocClass::kObjCObjectPointer)
    .value("OBJ_C_OBJECT", pasta::TypeLocClass::kObjCObject)
    .value("OBJ_C_INTERFACE", pasta::TypeLocClass::kObjCInterface)
    .value("OBJ_C_TYPE_PARAMETER", pasta::TypeLocClass::kObjCTypeParameter)
    .value("PACK_EXPANSION", pasta::TypeLocClass::kPackExpansion)
    .value("PARENTHESIS", pasta::TypeLocClass::kParenthesis)
    .value("PIPE", pasta::TypeLocClass::kPipe)
    .value("POINTER", pasta::TypeLocClass::kPointer)
    .value("L_VALUE_REFERENCE", pasta::TypeLocClass::kLValueReference)
    .value("R_VALUE_REFERENCE", pasta::TypeLocClass::kRValueReference)
    .value("SUBST_TEMPLATE_TYPE_PARM_PACK", pasta::TypeLocClass::kSubstTemplateTypeParmPack)
    .value("SUBST_TEMPLATE_TYPE_PARM", pasta::TypeLocClass::kSubstTemplateTypeParm)
    .value("ENUM", pasta::TypeLocClass::kEnum)
    .value("RECORD", pasta::TypeLocClass::kRecord)
    .value("TEMPLATE_SPECIALIZATION", pasta::TypeLocClass::kTemplateSpecialization)
    .value("TEMPLATE_TYPE_PARM", pasta::TypeLocClass::kTemplateTypeParm)
    .value("TYPE_OF_EXPRESSION", pasta::TypeLocClass::kTypeOfExpression)
    .value("TYPE_OF", pasta::TypeLocClass::kTypeOf)
    .value("TYPEDEF", pasta::TypeLocClass::kTypedef)
    .value("UNARY_TRANSFORM", pasta::TypeLocClass::kUnaryTransform)
    .value("UNRESOLVED_USING", pasta::TypeLocClass::kUnresolvedUsing)
    .value("USING", pasta::TypeLocClass::kUsing)
    .value("VECTOR", pasta::TypeLocClass::kVector)
    .value("EXT_VECTOR", pasta::TypeLocClass::kExtVector)
    .value("QUALIFIED", pasta::TypeLocClass::kQualified);

  nb::enum_<pasta::TypeOfKind>(m, "TypeOfKind")
    .value("QUALIFIED", pasta::TypeOfKind::kQualified)
    .value("UNQUALIFIED", pasta::TypeOfKind::kUnqualified);

  nb::enum_<pasta::TypeSpecifierSign>(m, "TypeSpecifierSign")
    .value("UNSPECIFIED", pasta::TypeSpecifierSign::kUnspecified)
    .value("SIGNED", pasta::TypeSpecifierSign::kSigned)
    .value("UNSIGNED", pasta::TypeSpecifierSign::kUnsigned);

  nb::enum_<pasta::TypeSpecifierType>(m, "TypeSpecifierType")
    .value("UNSPECIFIED", pasta::TypeSpecifierType::kUnspecified)
    .value("VOID", pasta::TypeSpecifierType::kVoid)
    .value("CHARACTER", pasta::TypeSpecifierType::kCharacter)
    .value("WCHAR", pasta::TypeSpecifierType::kWchar)
    .value("CHAR8", pasta::TypeSpecifierType::kChar8)
    .value("CHAR16", pasta::TypeSpecifierType::kChar16)
    .value("CHAR32", pasta::TypeSpecifierType::kChar32)
    .value("INT", pasta::TypeSpecifierType::kInt)
    .value("INT128", pasta::TypeSpecifierType::kInt128)
    .value("BITINT", pasta::TypeSpecifierType::kBitint)
    .value("HALF", pasta::TypeSpecifierType::kHalf)
    .value("FLOAT16", pasta::TypeSpecifierType::kFloat16)
    .value("ACCUM", pasta::TypeSpecifierType::kAccum)
    .value("FRACT", pasta::TypeSpecifierType::kFract)
    .value("B_FLOAT16", pasta::TypeSpecifierType::kBFloat16)
    .value("FLOAT", pasta::TypeSpecifierType::kFloat)
    .value("DOUBLE", pasta::TypeSpecifierType::kDouble)
    .value("FLOAT128", pasta::TypeSpecifierType::kFloat128)
    .value("IBM128", pasta::TypeSpecifierType::kIbm128)
    .value("BOOLEAN", pasta::TypeSpecifierType::kBoolean)
    .value("DECIMAL32", pasta::TypeSpecifierType::kDecimal32)
    .value("DECIMAL64", pasta::TypeSpecifierType::kDecimal64)
    .value("DECIMAL128", pasta::TypeSpecifierType::kDecimal128)
    .value("ENUM", pasta::TypeSpecifierType::kEnum)
    .value("UNION", pasta::TypeSpecifierType::kUnion)
    .value("STRUCT", pasta::TypeSpecifierType::kStruct)
    .value("CLASS", pasta::TypeSpecifierType::kClass)
    .value("INTERFACE", pasta::TypeSpecifierType::kInterface)
    .value("TYPENAME", pasta::TypeSpecifierType::kTypename)
    .value("TYPEOF_TYPE", pasta::TypeSpecifierType::kTypeofType)
    .value("TYPEOF_EXPRESSION", pasta::TypeSpecifierType::kTypeofExpression)
    .value("TYPEOF_UNQUALIFIED_TYPE", pasta::TypeSpecifierType::kTypeofUnqualifiedType)
    .value("TYPEOF_UNQUALIFIED_EXPRESSION", pasta::TypeSpecifierType::kTypeofUnqualifiedExpression)
    .value("DECLTYPE", pasta::TypeSpecifierType::kDecltype)
    .value("ADD_LVALUE_REFERENCE", pasta::TypeSpecifierType::kAddLvalueReference)
    .value("ADD_POINTER", pasta::TypeSpecifierType::kAddPointer)
    .value("ADD_RVALUE_REFERENCE", pasta::TypeSpecifierType::kAddRvalueReference)
    .value("DECAY", pasta::TypeSpecifierType::kDecay)
    .value("MAKE_SIGNED", pasta::TypeSpecifierType::kMakeSigned)
    .value("MAKE_UNSIGNED", pasta::TypeSpecifierType::kMakeUnsigned)
    .value("REMOVE_ALL_EXTENTS", pasta::TypeSpecifierType::kRemoveAllExtents)
    .value("REMOVE_CONST", pasta::TypeSpecifierType::kRemoveConst)
    .value("REMOVE_CV", pasta::TypeSpecifierType::kRemoveCv)
    .value("REMOVE_CVREF", pasta::TypeSpecifierType::kRemoveCvref)
    .value("REMOVE_EXTENT", pasta::TypeSpecifierType::kRemoveExtent)
    .value("REMOVE_POINTER", pasta::TypeSpecifierType::kRemovePointer)
    .value("REMOVE_REFERENCE_T", pasta::TypeSpecifierType::kRemoveReferenceT)
    .value("REMOVE_RESTRICT", pasta::TypeSpecifierType::kRemoveRestrict)
    .value("REMOVE_VOLATILE", pasta::TypeSpecifierType::kRemoveVolatile)
    .value("UNDERLYING_TYPE", pasta::TypeSpecifierType::kUnderlyingType)
    .value("AUTO", pasta::TypeSpecifierType::kAuto)
    .value("DECLTYPE_AUTO", pasta::TypeSpecifierType::kDecltypeAuto)
    .value("AUTO_TYPE", pasta::TypeSpecifierType::kAutoType)
    .value("UNKNOWN_ANYTYPE", pasta::TypeSpecifierType::kUnknownAnytype)
    .value("ATOMIC", pasta::TypeSpecifierType::kAtomic)
    .value("IMAGE_1D_T", pasta::TypeSpecifierType::kImage1dT)
    .value("IMAGE_1D_ARRAY_T", pasta::TypeSpecifierType::kImage1dArrayT)
    .value("IMAGE_1D_BUFFER_T", pasta::TypeSpecifierType::kImage1dBufferT)
    .value("IMAGE_2D_T", pasta::TypeSpecifierType::kImage2dT)
    .value("IMAGE_2D_ARRAY_T", pasta::TypeSpecifierType::kImage2dArrayT)
    .value("IMAGE_2D_DEPTH_T", pasta::TypeSpecifierType::kImage2dDepthT)
    .value("IMAGE_2D_ARRAY_DEPTH_T", pasta::TypeSpecifierType::kImage2dArrayDepthT)
    .value("IMAGE_2D_MSAA_T", pasta::TypeSpecifierType::kImage2dMsaaT)
    .value("IMAGE_2D_ARRAY_MSAA_T", pasta::TypeSpecifierType::kImage2dArrayMsaaT)
    .value("IMAGE_2D_MSAA_DEPTH_T", pasta::TypeSpecifierType::kImage2dMsaaDepthT)
    .value("IMAGE_2D_ARRAY_MSAA_DEPTH_T", pasta::TypeSpecifierType::kImage2dArrayMsaaDepthT)
    .value("IMAGE_3D_T", pasta::TypeSpecifierType::kImage3dT)
    .value("ERROR", pasta::TypeSpecifierType::kError);

  nb::enum_<pasta::TypeSpecifierWidth>(m, "TypeSpecifierWidth")
    .value("UNSPECIFIED", pasta::TypeSpecifierWidth::kUnspecified)
    .value("SHORT", pasta::TypeSpecifierWidth::kShort)
    .value("LONG", pasta::TypeSpecifierWidth::kLong)
    .value("LONG_LONG", pasta::TypeSpecifierWidth::kLongLong);

  nb::enum_<pasta::TypeSpecifiersPipe>(m, "TypeSpecifiersPipe")
    .value("UNSPECIFIED", pasta::TypeSpecifiersPipe::kUnspecified)
    .value("PIPE", pasta::TypeSpecifiersPipe::kPipe);

  nb::enum_<pasta::TypeTrait>(m, "TypeTrait")
    .value("IS_INTERFACE_CLASS", pasta::TypeTrait::kIsInterfaceClass)
    .value("IS_SEALED", pasta::TypeTrait::kIsSealed)
    .value("IS_DESTRUCTIBLE", pasta::TypeTrait::kIsDestructible)
    .value("IS_TRIVIALLY_DESTRUCTIBLE", pasta::TypeTrait::kIsTriviallyDestructible)
    .value("IS_NOTHROW_DESTRUCTIBLE", pasta::TypeTrait::kIsNothrowDestructible)
    .value("HAS_NOTHROW_MOVE_ASSIGN", pasta::TypeTrait::kHasNothrowMoveAssign)
    .value("HAS_TRIVIAL_MOVE_ASSIGN", pasta::TypeTrait::kHasTrivialMoveAssign)
    .value("HAS_TRIVIAL_MOVE_CONSTRUCTOR", pasta::TypeTrait::kHasTrivialMoveConstructor)
    .value("HAS_NOTHROW_ASSIGN", pasta::TypeTrait::kHasNothrowAssign)
    .value("HAS_NOTHROW_COPY", pasta::TypeTrait::kHasNothrowCopy)
    .value("HAS_NOTHROW_CONSTRUCTOR", pasta::TypeTrait::kHasNothrowConstructor)
    .value("HAS_TRIVIAL_ASSIGN", pasta::TypeTrait::kHasTrivialAssign)
    .value("HAS_TRIVIAL_COPY", pasta::TypeTrait::kHasTrivialCopy)
    .value("HAS_TRIVIAL_DEFAULT_CONSTRUCTOR", pasta::TypeTrait::kHasTrivialDefaultConstructor)
    .value("HAS_TRIVIAL_DESTRUCTOR", pasta::TypeTrait::kHasTrivialDestructor)
    .value("HAS_VIRTUAL_DESTRUCTOR", pasta::TypeTrait::kHasVirtualDestructor)
    .value("IS_ABSTRACT", pasta::TypeTrait::kIsAbstract)
    .value("IS_AGGREGATE", pasta::TypeTrait::kIsAggregate)
    .value("IS_CLASS", pasta::TypeTrait::kIsClass)
    .value("IS_EMPTY", pasta::TypeTrait::kIsEmpty)
    .value("IS_ENUM", pasta::TypeTrait::kIsEnum)
    .value("IS_FINAL", pasta::TypeTrait::kIsFinal)
    .value("IS_LITERAL", pasta::TypeTrait::kIsLiteral)
    .value("IS_POD", pasta::TypeTrait::kIsPOD)
    .value("IS_POLYMORPHIC", pasta::TypeTrait::kIsPolymorphic)
    .value("IS_STANDARD_LAYOUT", pasta::TypeTrait::kIsStandardLayout)
    .value("IS_TRIVIAL", pasta::TypeTrait::kIsTrivial)
    .value("IS_TRIVIALLY_COPYABLE", pasta::TypeTrait::kIsTriviallyCopyable)
    .value("IS_UNION", pasta::TypeTrait::kIsUnion)
    .value("HAS_UNIQUE_OBJECT_REPRESENTATIONS", pasta::TypeTrait::kHasUniqueObjectRepresentations)
    .value("IS_TRIVIALLY_RELOCATABLE", pasta::TypeTrait::kIsTriviallyRelocatable)
    .value("IS_BOUNDED_ARRAY", pasta::TypeTrait::kIsBoundedArray)
    .value("IS_UNBOUNDED_ARRAY", pasta::TypeTrait::kIsUnboundedArray)
    .value("IS_NULL_POINTER", pasta::TypeTrait::kIsNullPointer)
    .value("IS_SCOPED_ENUM", pasta::TypeTrait::kIsScopedEnum)
    .value("IS_REFERENCEABLE", pasta::TypeTrait::kIsReferenceable)
    .value("IS_ARITHMETIC", pasta::TypeTrait::kIsArithmetic)
    .value("IS_FLOATING_POINT", pasta::TypeTrait::kIsFloatingPoint)
    .value("IS_INTEGRAL", pasta::TypeTrait::kIsIntegral)
    .value("IS_COMPLETE_TYPE", pasta::TypeTrait::kIsCompleteType)
    .value("IS_VOID", pasta::TypeTrait::kIsVoid)
    .value("IS_ARRAY", pasta::TypeTrait::kIsArray)
    .value("IS_FUNCTION", pasta::TypeTrait::kIsFunction)
    .value("IS_REFERENCE", pasta::TypeTrait::kIsReference)
    .value("IS_LVALUE_REFERENCE", pasta::TypeTrait::kIsLvalueReference)
    .value("IS_RVALUE_REFERENCE", pasta::TypeTrait::kIsRvalueReference)
    .value("IS_FUNDAMENTAL", pasta::TypeTrait::kIsFundamental)
    .value("IS_OBJECT", pasta::TypeTrait::kIsObject)
    .value("IS_SCALAR", pasta::TypeTrait::kIsScalar)
    .value("IS_COMPOUND", pasta::TypeTrait::kIsCompound)
    .value("IS_POINTER", pasta::TypeTrait::kIsPointer)
    .value("IS_MEMBER_OBJECT_POINTER", pasta::TypeTrait::kIsMemberObjectPointer)
    .value("IS_MEMBER_FUNCTION_POINTER", pasta::TypeTrait::kIsMemberFunctionPointer)
    .value("IS_MEMBER_POINTER", pasta::TypeTrait::kIsMemberPointer)
    .value("IS_CONST", pasta::TypeTrait::kIsConst)
    .value("IS_VOLATILE", pasta::TypeTrait::kIsVolatile)
    .value("IS_SIGNED", pasta::TypeTrait::kIsSigned)
    .value("IS_UNSIGNED", pasta::TypeTrait::kIsUnsigned)
    .value("TYPE_COMPATIBLE", pasta::TypeTrait::kTypeCompatible)
    .value("IS_NOTHROW_ASSIGNABLE", pasta::TypeTrait::kIsNothrowAssignable)
    .value("IS_ASSIGNABLE", pasta::TypeTrait::kIsAssignable)
    .value("IS_BASE_OF", pasta::TypeTrait::kIsBaseOf)
    .value("IS_CONVERTIBLE_TO", pasta::TypeTrait::kIsConvertibleTo)
    .value("IS_TRIVIALLY_ASSIGNABLE", pasta::TypeTrait::kIsTriviallyAssignable)
    .value("REFERENCE_BINDS_TO_TEMPORARY", pasta::TypeTrait::kReferenceBindsToTemporary)
    .value("IS_SAME", pasta::TypeTrait::kIsSame)
    .value("IS_CONVERTIBLE", pasta::TypeTrait::kIsConvertible)
    .value("XNU_TYPE_COMPATIBLE", pasta::TypeTrait::kXNUTypeCompatible)
    .value("IS_CONSTRUCTIBLE", pasta::TypeTrait::kIsConstructible)
    .value("IS_NOTHROW_CONSTRUCTIBLE", pasta::TypeTrait::kIsNothrowConstructible)
    .value("IS_TRIVIALLY_CONSTRUCTIBLE", pasta::TypeTrait::kIsTriviallyConstructible);

  nb::enum_<pasta::UnaryExprOrTypeTrait>(m, "UnaryExprOrTypeTrait")
    .value("SIZE_OF", pasta::UnaryExprOrTypeTrait::kSizeOf)
    .value("ALIGN_OF", pasta::UnaryExprOrTypeTrait::kAlignOf)
    .value("PREFERRED_ALIGN_OF", pasta::UnaryExprOrTypeTrait::kPreferredAlignOf)
    .value("POINTER_AUTH_TYPE_DISCRIMINATOR", pasta::UnaryExprOrTypeTrait::kPointerAuthTypeDiscriminator)
    .value("XNU_TYPE_SIGNATURE", pasta::UnaryExprOrTypeTrait::kXNUTypeSignature)
    .value("XNU_TYPE_SUMMARY", pasta::UnaryExprOrTypeTrait::kXNUTypeSummary)
    .value("TMO_TYPE_GET_METADATA", pasta::UnaryExprOrTypeTrait::kTMOTypeGetMetadata)
    .value("VEC_STEP", pasta::UnaryExprOrTypeTrait::kVecStep)
    .value("OPEN_MP_REQUIRED_SIMD_ALIGN", pasta::UnaryExprOrTypeTrait::kOpenMPRequiredSimdAlign);

  nb::enum_<pasta::UnaryOperatorKind>(m, "UnaryOperatorKind")
    .value("POST_INCREMENT", pasta::UnaryOperatorKind::kPostIncrement)
    .value("POST_DEC", pasta::UnaryOperatorKind::kPostDec)
    .value("PRE_INCREMENT", pasta::UnaryOperatorKind::kPreIncrement)
    .value("PRE_DEC", pasta::UnaryOperatorKind::kPreDec)
    .value("ADDRESS_OF", pasta::UnaryOperatorKind::kAddressOf)
    .value("DEREF", pasta::UnaryOperatorKind::kDeref)
    .value("PLUS", pasta::UnaryOperatorKind::kPlus)
    .value("MINUS", pasta::UnaryOperatorKind::kMinus)
    .value("NOT", pasta::UnaryOperatorKind::kNot)
    .value("L_NOT", pasta::UnaryOperatorKind::kLNot)
    .value("REAL", pasta::UnaryOperatorKind::kReal)
    .value("IMAG", pasta::UnaryOperatorKind::kImag)
    .value("EXTENSION", pasta::UnaryOperatorKind::kExtension)
    .value("COAWAIT", pasta::UnaryOperatorKind::kCoawait);

  nb::enum_<pasta::APValueKind>(m, "APValueKind")
    .value("NONE", pasta::APValueKind::kNone)
    .value("INDETERMINATE", pasta::APValueKind::kIndeterminate)
    .value("INT", pasta::APValueKind::kInt)
    .value("FLOAT", pasta::APValueKind::kFloat)
    .value("FIXED_POINT", pasta::APValueKind::kFixedPoint)
    .value("COMPLEX_INT", pasta::APValueKind::kComplexInt)
    .value("COMPLEX_FLOAT", pasta::APValueKind::kComplexFloat)
    .value("L_VALUE", pasta::APValueKind::kLValue)
    .value("VECTOR", pasta::APValueKind::kVector)
    .value("ARRAY", pasta::APValueKind::kArray)
    .value("STRUCT", pasta::APValueKind::kStruct)
    .value("UNION", pasta::APValueKind::kUnion)
    .value("MEMBER_POINTER", pasta::APValueKind::kMemberPointer)
    .value("ADDRESS_LABEL_DIFF", pasta::APValueKind::kAddressLabelDiff);

  nb::enum_<pasta::VectorLibrary>(m, "VectorLibrary")
    .value("NO_LIBRARY", pasta::VectorLibrary::kNoLibrary)
    .value("ACCELERATE", pasta::VectorLibrary::kAccelerate)
    .value("LIBMVEC", pasta::VectorLibrary::kLIBMVEC)
    .value("MASSV", pasta::VectorLibrary::kMASSV)
    .value("SVML", pasta::VectorLibrary::kSVML)
    .value("SLEEF", pasta::VectorLibrary::kSLEEF)
    .value("DARWIN_LIBSYSTEM_M", pasta::VectorLibrary::kDarwinLibsystemM);

  nb::enum_<pasta::Visibility>(m, "Visibility")
    .value("HIDDEN_VISIBILITY", pasta::Visibility::kHiddenVisibility)
    .value("PROTECTED_VISIBILITY", pasta::Visibility::kProtectedVisibility)
    .value("DEFAULT_VISIBILITY", pasta::Visibility::kDefaultVisibility);


}
} // namespace pasta
