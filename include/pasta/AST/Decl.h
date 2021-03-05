/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "Token.h"

namespace clang {
class AccessSpecDecl;
class BindingDecl;
class BlockDecl;
class BuiltinTemplateDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class CapturedDecl;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class ConceptDecl;
class ConstructorUsingShadowDecl;
class Decl;
class DeclContext;
class DeclaratorDecl;
class DecompositionDecl;
class EmptyDecl;
class EnumConstantDecl;
class EnumDecl;
class ExportDecl;
class ExternCContextDecl;
class FieldDecl;
class FileScopeAsmDecl;
class FriendDecl;
class FriendTemplateDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class ImplicitParamDecl;
class ImportDecl;
class IndirectFieldDecl;
class LabelDecl;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class MSGuidDecl;
class MSPropertyDecl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NonTypeTemplateParmDecl;
class OMPAllocateDecl;
class OMPCapturedExprDecl;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPRequiresDecl;
class OMPThreadPrivateDecl;
class ObjCAtDefsFieldDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCProtocolDecl;
class ObjCTypeParamDecl;
class ParmVarDecl;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class RecordDecl;
class RedeclarableTemplateDecl;
class RequiresExprBodyDecl;
class StaticAssertDecl;
class TagDecl;
class TemplateDecl;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TranslationUnitDecl;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UsingDecl;
class UsingDirectiveDecl;
class UsingPackDecl;
class UsingShadowDecl;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
}  // namespace clang
namespace pasta {
class AST;
class ASTImpl;

enum class DeclKind : unsigned {
  kAccessSpec,
  kBinding,
  kBlock,
  kBuiltinTemplate,
  kCXXConstructor,
  kCXXConversion,
  kCXXDeductionGuide,
  kCXXDestructor,
  kCXXMethod,
  kCXXRecord,
  kCaptured,
  kClassScopeFunctionSpecialization,
  kClassTemplate,
  kClassTemplatePartialSpecialization,
  kClassTemplateSpecialization,
  kConcept,
  kConstructorUsingShadow,
  kDeclarator,
  kDecomposition,
  kEmpty,
  kEnumConstant,
  kEnum,
  kExport,
  kExternCContext,
  kField,
  kFileScopeAsm,
  kFriend,
  kFriendTemplate,
  kFunction,
  kFunctionTemplate,
  kImplicitParam,
  kImport,
  kIndirectField,
  kLabel,
  kLifetimeExtendedTemporary,
  kLinkageSpec,
  kMSGuid,
  kMSProperty,
  kNamed,
  kNamespaceAlias,
  kNamespace,
  kNonTypeTemplateParm,
  kOMPAllocate,
  kOMPCapturedExpr,
  kOMPDeclareMapper,
  kOMPDeclareReduction,
  kOMPRequires,
  kOMPThreadPrivate,
  kObjCAtDefsField,
  kObjCCategory,
  kObjCCategoryImpl,
  kObjCCompatibleAlias,
  kObjCContainer,
  kObjCImpl,
  kObjCImplementation,
  kObjCInterface,
  kObjCIvar,
  kObjCMethod,
  kObjCProperty,
  kObjCPropertyImpl,
  kObjCProtocol,
  kObjCTypeParam,
  kParmVar,
  kPragmaComment,
  kPragmaDetectMismatch,
  kRecord,
  kRedeclarableTemplate,
  kRequiresExprBody,
  kStaticAssert,
  kTag,
  kTemplate,
  kTemplateTemplateParm,
  kTemplateTypeParm,
  kTranslationUnit,
  kTypeAlias,
  kTypeAliasTemplate,
  kType,
  kTypedef,
  kTypedefName,
  kUnresolvedUsingTypename,
  kUnresolvedUsingValue,
  kUsing,
  kUsingDirective,
  kUsingPack,
  kUsingShadow,
  kValue,
  kVar,
  kVarTemplate,
  kVarTemplatePartialSpecialization,
  kVarTemplateSpecialization,
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
  kOMPNullMemAlloc = 0,
  kOMPDefaultMemAlloc = 1,
  kOMPLargeCapMemAlloc = 2,
  kOMPConstMemAlloc = 3,
  kOMPHighBWMemAlloc = 4,
  kOMPLowLatMemAlloc = 5,
  kOMPCGroupMemAlloc = 6,
  kOMPPTeamMemAlloc = 7,
  kOMPThreadMemAlloc = 8,
  kOMPUserDefinedMemAlloc = 9,
};

enum class ArgKind : unsigned int {
  kNull = 0,
  kType = 1,
  kDeclaration = 2,
  kNullPtr = 3,
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
  kStd_string = 0,
  kC_string = 1,
  kSint = 2,
  kUint = 3,
  kTokenkind = 4,
  kIdentifierinfo = 5,
  kAddrspace = 6,
  kQual = 7,
  kQualtype = 8,
  kDeclarationname = 9,
  kNameddecl = 10,
  kNestednamespec = 11,
  kDeclcontext = 12,
  kQualtype_pair = 13,
  kAttr = 14,
};

enum class ArraySizeModifier : unsigned int {
  kNormal = 0,
  kStatic = 1,
  kStar = 2,
};

enum class ArrayTypeTrait : unsigned int {
  kArrayRank = 0,
  kArrayExtent = 1,
  kLast = 1,
};

enum class AtomicOp : unsigned int {
  kC11_atomic_init = 0,
  kC11_atomic_load = 1,
  kC11_atomic_store = 2,
  kC11_atomic_exchange = 3,
  kC11_atomic_compare_exchange_strong = 4,
  kC11_atomic_compare_exchange_weak = 5,
  kC11_atomic_fetch_add = 6,
  kC11_atomic_fetch_sub = 7,
  kC11_atomic_fetch_and = 8,
  kC11_atomic_fetch_or = 9,
  kC11_atomic_fetch_xor = 10,
  kC11_atomic_fetch_max = 11,
  kC11_atomic_fetch_min = 12,
  kAtomic_load = 13,
  kAtomic_load_n = 14,
  kAtomic_store = 15,
  kAtomic_store_n = 16,
  kAtomic_exchange = 17,
  kAtomic_exchange_n = 18,
  kAtomic_compare_exchange = 19,
  kAtomic_compare_exchange_n = 20,
  kAtomic_fetch_add = 21,
  kAtomic_fetch_sub = 22,
  kAtomic_fetch_and = 23,
  kAtomic_fetch_or = 24,
  kAtomic_fetch_xor = 25,
  kAtomic_fetch_nand = 26,
  kAtomic_add_fetch = 27,
  kAtomic_sub_fetch = 28,
  kAtomic_and_fetch = 29,
  kAtomic_or_fetch = 30,
  kAtomic_xor_fetch = 31,
  kAtomic_max_fetch = 32,
  kAtomic_min_fetch = 33,
  kAtomic_nand_fetch = 34,
  kOpencl_atomic_init = 35,
  kOpencl_atomic_load = 36,
  kOpencl_atomic_store = 37,
  kOpencl_atomic_exchange = 38,
  kOpencl_atomic_compare_exchange_strong = 39,
  kOpencl_atomic_compare_exchange_weak = 40,
  kOpencl_atomic_fetch_add = 41,
  kOpencl_atomic_fetch_sub = 42,
  kOpencl_atomic_fetch_and = 43,
  kOpencl_atomic_fetch_or = 44,
  kOpencl_atomic_fetch_xor = 45,
  kOpencl_atomic_fetch_min = 46,
  kOpencl_atomic_fetch_max = 47,
  kAtomic_fetch_min = 48,
  kAtomic_fetch_max = 49,
  kBI_First = 0,
};

enum class AtomicScopeModelKind : int {
  kNone = 0,
  kOpenCL = 1,
};

enum class AutoTypeKeyword : int {
  kAuto = 0,
  kDecltypeAuto = 1,
  kGNUAutoType = 2,
};

enum class AvailabilityResult : unsigned int {
  kAR_Available = 0,
  kAR_NotYetIntroduced = 1,
  kAR_Deprecated = 2,
  kAR_Unavailable = 3,
};

enum class BinaryOperatorKind : unsigned int {
  kPtrMemD = 0,
  kPtrMemI = 1,
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
};

enum class BlockType : unsigned int {
  kByRef = 0,
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
  kX86_64SysV = 7,
  kX86RegCall = 8,
  kAAPCS = 9,
  kAAPCS_VFP = 10,
  kIntelOclBicc = 11,
  kSpirFunction = 12,
  kOpenCLKernel = 13,
  kSwift = 14,
  kPreserveMost = 15,
  kPreserveAll = 16,
  kAArch64VectorCall = 17,
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
  kNoOp = 5,
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
  kVectorSplat = 25,
  kIntegralCast = 26,
  kIntegralToBoolean = 27,
  kIntegralToFloating = 28,
  kFixedPointCast = 29,
  kFixedPointToIntegral = 30,
  kIntegralToFixedPoint = 31,
  kFixedPointToBoolean = 32,
  kFloatingToIntegral = 33,
  kFloatingToBoolean = 34,
  kBooleanToSignedIntegral = 35,
  kFloatingCast = 36,
  kCPointerToObjCPointerCast = 37,
  kBlockPointerToObjCPointerCast = 38,
  kAnyPointerToBlockPointerCast = 39,
  kObjCObjectLValueCast = 40,
  kFloatingRealToComplex = 41,
  kFloatingComplexToReal = 42,
  kFloatingComplexToBoolean = 43,
  kFloatingComplexCast = 44,
  kFloatingComplexToIntegralComplex = 45,
  kIntegralRealToComplex = 46,
  kIntegralComplexToReal = 47,
  kIntegralComplexToBoolean = 48,
  kIntegralComplexCast = 49,
  kIntegralComplexToFloatingComplex = 50,
  kARCProduceObject = 51,
  kARCConsumeObject = 52,
  kARCReclaimReturnedObject = 53,
  kARCExtendBlockObject = 54,
  kAtomicToNonAtomic = 55,
  kNonAtomicToAtomic = 56,
  kCopyAndAutoreleaseBlockObject = 57,
  kBuiltinFnToFnPtr = 58,
  kZeroToOCLOpaqueType = 59,
  kAddressSpaceConversion = 60,
  kIntToOCLSampler = 61,
};

enum class CharacterKind : unsigned int {
  kAscii = 0,
  kWide = 1,
  kUTF8 = 2,
  kUTF16 = 3,
  kUTF32 = 4,
};

enum class ClangABI : int {
  kVer3_8 = 0,
  kVer4 = 1,
  kVer6 = 2,
  kVer7 = 3,
  kVer9 = 4,
  kLatest = 5,
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
  kLast = 4,
};

enum class ComparisonCategoryType : unsigned char {
  kPartialOrdering = 0,
  kWeakOrdering = 1,
  kStrongOrdering = 2,
  kFirst = 0,
  kLast = 2,
};

enum class CompilingModuleKind : unsigned int {
  kNone = 0,
  kModuleMap = 1,
  kHeaderModule = 2,
  kModuleInterface = 3,
};

enum class ConstExprUsage : unsigned int {
  kEvaluateForCodeGen = 0,
  kEvaluateForMangling = 1,
};

enum class ConstexprSpecKind : unsigned int {
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

enum class CoreFoundationABI : int {
  kUnspecified = 0,
  kStandalone = 1,
  kObjectiveC = 2,
  kSwift = 3,
  kSwift5_0 = 4,
  kSwift4_2 = 5,
  kSwift4_1 = 6,
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
  kCxx_destructor = 1,
  kObjc_strong_lifetime = 2,
  kObjc_weak_lifetime = 3,
  kNontrivial_c_struct = 4,
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
  kRValue = 0,
  kLValue = 1,
  kXValue = 2,
};

enum class ExpressionTrait : unsigned int {
  kIsLValueExpr = 0,
  kIsRValueExpr = 1,
  kLast = 1,
};

enum class ExtKind : unsigned int {
  kAlways = 0,
  kNever = 1,
  kReplyHazy = 2,
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
};

enum class FamilyKind : unsigned int {
  kNone = 0,
  kAlloc = 1,
  kCopy = 2,
  kInit = 3,
  kMutableCopy = 4,
  kNew = 5,
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
  kMissing_type = 1,
  kMissing_stdio = 2,
  kMissing_setjmp = 3,
  kMissing_ucontext = 4,
};

enum class GuardArg : unsigned int {
  kNocf = 0,
};

enum class ID : unsigned int {
  kWorkGroup = 1,
  kDevice = 2,
  kAllSVMDevices = 3,
  kSubGroup = 4,
  kLast = 4,
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
  kUniqueStableNameType = 8,
  kUniqueStableNameExpr = 9,
};

enum class IdentifierInfoFlag : unsigned int {
  kZeroArg = 1,
  kOneArg = 2,
  kMultiArg = 7,
  kArgFlags = 7,
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
  kALWAYS_ARG1 = 3,
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
  kNoInit = 0,
  kCopyInit = 1,
  kListInit = 2,
};

enum class InheritedDesignatedInitializersState : unsigned int {
  kUnknown = 0,
  kInherited = 1,
  kNotInherited = 2,
};

enum class InitKind : unsigned int {
  kCallInit = 0,
  kDirectInit = 1,
  kCopyInit = 2,
};

enum class InitStorageKind : unsigned int {
  kNoInit = 0,
  kInClassCopyInit = 1,
  kInClassListInit = 2,
  kCapturedVLAType = 3,
};

enum class InitializationStyle : unsigned int {
  kCInit = 0,
  kCallInit = 1,
  kListInit = 2,
};

enum class InlineVariableDefinitionKind : int {
  kNone = 0,
  kWeak = 1,
  kWeakUnknown = 2,
  kStrong = 3,
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
  kByRef = 2,
};

enum class LambdaCaptureKind : unsigned int {
  kThis = 0,
  kStarThis = 1,
  kByCopy = 2,
  kByRef = 3,
  kVLAType = 4,
};

enum class LangAS : unsigned int {
  kDefault = 0,
  kOpencl_global = 1,
  kOpencl_local = 2,
  kOpencl_constant = 3,
  kOpencl_private = 4,
  kOpencl_generic = 5,
  kCuda_device = 6,
  kCuda_constant = 7,
  kCuda_shared = 8,
  kPtr32_sptr = 9,
  kPtr32_uptr = 10,
  kPtr64 = 11,
  kFirstTargetAddressSpace = 12,
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
  kAssumeSafety = 3,
  kFull = 4,
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
  kMSVC2017_5 = 1912,
  kMSVC2017_7 = 1914,
};

enum class MSVtorDispMode : int {
  kNever = 0,
  kForVBaseOverride = 1,
  kForVFTable = 2,
};

enum class MapTypeTy : unsigned int {
  kTo = 0,
  kLink = 1,
};

enum class MethodRefFlags : unsigned int {
  kMethodRef_None = 0,
  kMethodRef_Getter = 1,
  kMethodRef_Setter = 2,
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
  kNeedExtraManglingDecl = 0,
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

enum class Nonce_ObjCInterface : unsigned int {
  kObjCInterface = 0,
};

enum class NullPointerConstantKind : unsigned int {
  kNotNull = 0,
  kZeroExpression = 1,
  kZeroLiteral = 2,
  kCXX11_nullptr = 3,
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

enum class ObjCInstanceTypeFamily : unsigned int {
  kNone = 0,
  kArray = 1,
  kDictionary = 2,
  kSingleton = 3,
  kInit = 4,
  kReturnsSelf = 5,
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
  kInit = 3,
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
  kQuery_unknown = 0,
  kQuery_instance = 1,
  kQuery_class = 2,
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

enum class OnStackType : unsigned int {
  kOnStack = 0,
};

enum class OnStack_t : unsigned int {
  kOnStack = 0,
};

enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned int {
  kSeq_cst = 0,
  kAcq_rel = 1,
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
  kDevice_num = 1,
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

enum class OpenMPFromModifierKind : unsigned int {
  kMapper = 0,
  kUnknown = 1,
};

enum class OpenMPLastprivateModifier : unsigned int {
  kConditional = 0,
  kUnknown = 1,
};

enum class OpenMPLinearClauseKind : unsigned int {
  kVal = 0,
  kRef = 1,
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

enum class OpenMPToModifierKind : unsigned int {
  kMapper = 0,
  kUnknown = 1,
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
  kArray_New = 3,
  kArray_Delete = 4,
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
  kNUM_OVERLOADED_OPERATORS = 46,
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

enum class ParameterABI : int {
  kOrdinary = 0,
  kSwiftIndirectResult = 1,
  kSwiftErrorResult = 2,
  kSwiftContext = 3,
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
  kExeStr = 4,
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
  kZeroInit = 16,
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
  kAssignLoc = 0,
  kFirstColonLoc = 1,
  kSecondColonLoc = 2,
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

enum class SanitizerOrdinal : unsigned long long {
  kAddress = 0,
  kPointerCompare = 1,
  kPointerSubtract = 2,
  kKernelAddress = 3,
  kHWAddress = 4,
  kKernelHWAddress = 5,
  kMemTag = 6,
  kMemory = 7,
  kKernelMemory = 8,
  kFuzzer = 9,
  kFuzzerNoLink = 10,
  kThread = 11,
  kLeak = 12,
  kAlignment = 13,
  kArrayBounds = 14,
  kBool = 15,
  kBuiltin = 16,
  kEnum = 17,
  kFloatCastOverflow = 18,
  kFloatDivideByZero = 19,
  kFunction = 20,
  kIntegerDivideByZero = 21,
  kNonnullAttribute = 22,
  kNull = 23,
  kNullabilityArg = 24,
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
  kDataFlow = 40,
  kCFICastStrict = 41,
  kCFIDerivedCast = 42,
  kCFIICall = 43,
  kCFIMFCall = 44,
  kCFIUnrelatedCast = 45,
  kCFINVCall = 46,
  kCFIVCall = 47,
  kCFIGroup = 48,
  kSafeStack = 49,
  kShadowCallStack = 50,
  kUndefinedGroup = 51,
  kUndefinedTrapGroup = 52,
  kImplicitUnsignedIntegerTruncation = 53,
  kImplicitSignedIntegerTruncation = 54,
  kImplicitIntegerTruncationGroup = 55,
  kImplicitIntegerSignChange = 56,
  kImplicitIntegerArithmeticValueChangeGroup = 57,
  kObjCCast = 58,
  kImplicitConversionGroup = 59,
  kIntegerGroup = 60,
  kLocalBounds = 61,
  kBoundsGroup = 62,
  kScudo = 63,
  kAllGroup = 64,
  kCount = 65,
};

enum class ScalarTypeKind : unsigned int {
  kCPointer = 0,
  kBlockPointer = 1,
  kObjCObjectPointer = 2,
  kMemberPointer = 3,
  kBool = 4,
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
  kGNU_aarch64_vector_pcs = 0,
  kCXX11_clang_aarch64_vector_pcs = 1,
  kC2x_clang_aarch64_vector_pcs = 2,
  kSpellingNotCalculated = 15,
};

enum class StackProtectorMode : unsigned int {
  kOff = 0,
  kOn = 1,
  kStrong = 2,
  kReq = 3,
};

enum class StmtClass : unsigned int {
  kNoStmtClass = 0,
  kGCCAsmStmtClass = 1,
  kMSAsmStmtClass = 2,
  kBreakStmtClass = 3,
  kCXXCatchStmtClass = 4,
  kCXXForRangeStmtClass = 5,
  kCXXTryStmtClass = 6,
  kCapturedStmtClass = 7,
  kCompoundStmtClass = 8,
  kContinueStmtClass = 9,
  kCoreturnStmtClass = 10,
  kCoroutineBodyStmtClass = 11,
  kDeclStmtClass = 12,
  kDoStmtClass = 13,
  kForStmtClass = 14,
  kGotoStmtClass = 15,
  kIfStmtClass = 16,
  kIndirectGotoStmtClass = 17,
  kMSDependentExistsStmtClass = 18,
  kNullStmtClass = 19,
  kOMPAtomicDirectiveClass = 20,
  kOMPBarrierDirectiveClass = 21,
  kOMPCancelDirectiveClass = 22,
  kOMPCancellationPointDirectiveClass = 23,
  kOMPCriticalDirectiveClass = 24,
  kOMPDepobjDirectiveClass = 25,
  kOMPFlushDirectiveClass = 26,
  kOMPDistributeDirectiveClass = 27,
  kOMPDistributeParallelForDirectiveClass = 28,
  kOMPDistributeParallelForSimdDirectiveClass = 29,
  kOMPDistributeSimdDirectiveClass = 30,
  kOMPForDirectiveClass = 31,
  kOMPForSimdDirectiveClass = 32,
  kOMPMasterTaskLoopDirectiveClass = 33,
  kOMPMasterTaskLoopSimdDirectiveClass = 34,
  kOMPParallelForDirectiveClass = 35,
  kOMPParallelForSimdDirectiveClass = 36,
  kOMPParallelMasterTaskLoopDirectiveClass = 37,
  kOMPParallelMasterTaskLoopSimdDirectiveClass = 38,
  kOMPSimdDirectiveClass = 39,
  kOMPTargetParallelForSimdDirectiveClass = 40,
  kOMPTargetSimdDirectiveClass = 41,
  kOMPTargetTeamsDistributeDirectiveClass = 42,
  kOMPTargetTeamsDistributeParallelForDirectiveClass = 43,
  kOMPTargetTeamsDistributeParallelForSimdDirectiveClass = 44,
  kOMPTargetTeamsDistributeSimdDirectiveClass = 45,
  kOMPTaskLoopDirectiveClass = 46,
  kOMPTaskLoopSimdDirectiveClass = 47,
  kOMPTeamsDistributeDirectiveClass = 48,
  kOMPTeamsDistributeParallelForDirectiveClass = 49,
  kOMPTeamsDistributeParallelForSimdDirectiveClass = 50,
  kOMPTeamsDistributeSimdDirectiveClass = 51,
  kOMPMasterDirectiveClass = 52,
  kOMPOrderedDirectiveClass = 53,
  kOMPParallelDirectiveClass = 54,
  kOMPParallelMasterDirectiveClass = 55,
  kOMPParallelSectionsDirectiveClass = 56,
  kOMPScanDirectiveClass = 57,
  kOMPSectionDirectiveClass = 58,
  kOMPSectionsDirectiveClass = 59,
  kOMPSingleDirectiveClass = 60,
  kOMPTargetDataDirectiveClass = 61,
  kOMPTargetDirectiveClass = 62,
  kOMPTargetEnterDataDirectiveClass = 63,
  kOMPTargetExitDataDirectiveClass = 64,
  kOMPTargetParallelDirectiveClass = 65,
  kOMPTargetParallelForDirectiveClass = 66,
  kOMPTargetTeamsDirectiveClass = 67,
  kOMPTargetUpdateDirectiveClass = 68,
  kOMPTaskDirectiveClass = 69,
  kOMPTaskgroupDirectiveClass = 70,
  kOMPTaskwaitDirectiveClass = 71,
  kOMPTaskyieldDirectiveClass = 72,
  kOMPTeamsDirectiveClass = 73,
  kObjCAtCatchStmtClass = 74,
  kObjCAtFinallyStmtClass = 75,
  kObjCAtSynchronizedStmtClass = 76,
  kObjCAtThrowStmtClass = 77,
  kObjCAtTryStmtClass = 78,
  kObjCAutoreleasePoolStmtClass = 79,
  kObjCForCollectionStmtClass = 80,
  kReturnStmtClass = 81,
  kSEHExceptStmtClass = 82,
  kSEHFinallyStmtClass = 83,
  kSEHLeaveStmtClass = 84,
  kSEHTryStmtClass = 85,
  kCaseStmtClass = 86,
  kDefaultStmtClass = 87,
  kSwitchStmtClass = 88,
  kAttributedStmtClass = 89,
  kBinaryConditionalOperatorClass = 90,
  kConditionalOperatorClass = 91,
  kAddrLabelExprClass = 92,
  kArrayInitIndexExprClass = 93,
  kArrayInitLoopExprClass = 94,
  kArraySubscriptExprClass = 95,
  kArrayTypeTraitExprClass = 96,
  kAsTypeExprClass = 97,
  kAtomicExprClass = 98,
  kBinaryOperatorClass = 99,
  kCompoundAssignOperatorClass = 100,
  kBlockExprClass = 101,
  kCXXBindTemporaryExprClass = 102,
  kCXXBoolLiteralExprClass = 103,
  kCXXConstructExprClass = 104,
  kCXXTemporaryObjectExprClass = 105,
  kCXXDefaultArgExprClass = 106,
  kCXXDefaultInitExprClass = 107,
  kCXXDeleteExprClass = 108,
  kCXXDependentScopeMemberExprClass = 109,
  kCXXFoldExprClass = 110,
  kCXXInheritedCtorInitExprClass = 111,
  kCXXNewExprClass = 112,
  kCXXNoexceptExprClass = 113,
  kCXXNullPtrLiteralExprClass = 114,
  kCXXPseudoDestructorExprClass = 115,
  kCXXRewrittenBinaryOperatorClass = 116,
  kCXXScalarValueInitExprClass = 117,
  kCXXStdInitializerListExprClass = 118,
  kCXXThisExprClass = 119,
  kCXXThrowExprClass = 120,
  kCXXTypeidExprClass = 121,
  kCXXUnresolvedConstructExprClass = 122,
  kCXXUuidofExprClass = 123,
  kCallExprClass = 124,
  kCUDAKernelCallExprClass = 125,
  kCXXMemberCallExprClass = 126,
  kCXXOperatorCallExprClass = 127,
  kUserDefinedLiteralClass = 128,
  kBuiltinBitCastExprClass = 129,
  kCStyleCastExprClass = 130,
  kCXXFunctionalCastExprClass = 131,
  kCXXAddrspaceCastExprClass = 132,
  kCXXConstCastExprClass = 133,
  kCXXDynamicCastExprClass = 134,
  kCXXReinterpretCastExprClass = 135,
  kCXXStaticCastExprClass = 136,
  kObjCBridgedCastExprClass = 137,
  kImplicitCastExprClass = 138,
  kCharacterLiteralClass = 139,
  kChooseExprClass = 140,
  kCompoundLiteralExprClass = 141,
  kConceptSpecializationExprClass = 142,
  kConvertVectorExprClass = 143,
  kCoawaitExprClass = 144,
  kCoyieldExprClass = 145,
  kDeclRefExprClass = 146,
  kDependentCoawaitExprClass = 147,
  kDependentScopeDeclRefExprClass = 148,
  kDesignatedInitExprClass = 149,
  kDesignatedInitUpdateExprClass = 150,
  kExpressionTraitExprClass = 151,
  kExtVectorElementExprClass = 152,
  kFixedPointLiteralClass = 153,
  kFloatingLiteralClass = 154,
  kConstantExprClass = 155,
  kExprWithCleanupsClass = 156,
  kFunctionParmPackExprClass = 157,
  kGNUNullExprClass = 158,
  kGenericSelectionExprClass = 159,
  kImaginaryLiteralClass = 160,
  kImplicitValueInitExprClass = 161,
  kInitListExprClass = 162,
  kIntegerLiteralClass = 163,
  kLambdaExprClass = 164,
  kMSPropertyRefExprClass = 165,
  kMSPropertySubscriptExprClass = 166,
  kMaterializeTemporaryExprClass = 167,
  kMatrixSubscriptExprClass = 168,
  kMemberExprClass = 169,
  kNoInitExprClass = 170,
  kOMPArraySectionExprClass = 171,
  kOMPArrayShapingExprClass = 172,
  kOMPIteratorExprClass = 173,
  kObjCArrayLiteralClass = 174,
  kObjCAvailabilityCheckExprClass = 175,
  kObjCBoolLiteralExprClass = 176,
  kObjCBoxedExprClass = 177,
  kObjCDictionaryLiteralClass = 178,
  kObjCEncodeExprClass = 179,
  kObjCIndirectCopyRestoreExprClass = 180,
  kObjCIsaExprClass = 181,
  kObjCIvarRefExprClass = 182,
  kObjCMessageExprClass = 183,
  kObjCPropertyRefExprClass = 184,
  kObjCProtocolExprClass = 185,
  kObjCSelectorExprClass = 186,
  kObjCStringLiteralClass = 187,
  kObjCSubscriptRefExprClass = 188,
  kOffsetOfExprClass = 189,
  kOpaqueValueExprClass = 190,
  kUnresolvedLookupExprClass = 191,
  kUnresolvedMemberExprClass = 192,
  kPackExpansionExprClass = 193,
  kParenExprClass = 194,
  kParenListExprClass = 195,
  kPredefinedExprClass = 196,
  kPseudoObjectExprClass = 197,
  kRecoveryExprClass = 198,
  kRequiresExprClass = 199,
  kShuffleVectorExprClass = 200,
  kSizeOfPackExprClass = 201,
  kSourceLocExprClass = 202,
  kStmtExprClass = 203,
  kStringLiteralClass = 204,
  kSubstNonTypeTemplateParmExprClass = 205,
  kSubstNonTypeTemplateParmPackExprClass = 206,
  kTypeTraitExprClass = 207,
  kTypoExprClass = 208,
  kUnaryExprOrTypeTraitExprClass = 209,
  kUnaryOperatorClass = 210,
  kVAArgExprClass = 211,
  kLabelStmtClass = 212,
  kWhileStmtClass = 213,
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
  kStoredObjCZeroArgSelector = 1,
  kStoredObjCOneArgSelector = 2,
  kStoredCXXConstructorName = 3,
  kStoredCXXDestructorName = 4,
  kStoredCXXConversionFunctionName = 5,
  kStoredCXXOperatorName = 6,
  kStoredDeclarationNameExtra = 7,
  kPtrMask = 7,
  kUncommonNameKindOffset = 8,
};

enum class StoredSpecifierKind : unsigned int {
  kStoredIdentifier = 0,
  kStoredDecl = 1,
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

enum class SubExpr : unsigned int {
  kCommon = 0,
  kReady = 1,
  kSuspend = 2,
  kResume = 3,
  kCount = 4,
};

enum class SubStmt : unsigned int {
  kBody = 0,
  kPromise = 1,
  kInitSuspend = 2,
  kFinalSuspend = 3,
  kOnException = 4,
  kOnFallthrough = 5,
  kAllocate = 6,
  kDeallocate = 7,
  kReturnValue = 8,
  kResultDecl = 9,
  kReturnStmt = 10,
  kReturnStmtOnAllocFailure = 11,
  kFirstParamMove = 12,
};

enum class SyncScope : int {
  kOpenCLWorkGroup = 0,
  kOpenCLDevice = 1,
  kOpenCLAllSVMDevices = 2,
  kOpenCLSubGroup = 3,
  kLast = 3,
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

enum class ThreadStorageClassSpecifier : unsigned int {
  kUnspecified = 0,
  k__thread = 1,
  kThread_local = 2,
  k_Thread_local = 3,
};

enum class TraillingAllocKind : unsigned int {
  kTAKInheritsConstructor = 1,
  kTAKHasTailExplicit = 2,
};

enum class TranslationUnitKind : unsigned int {
  kComplete = 0,
  kPrefix = 1,
  kModule = 2,
};

enum class TrivialAutoVarInitKind : int {
  kUninitialized = 0,
  kZero = 1,
  kPattern = 2,
};

enum class TypeClass : unsigned int {
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
  kTypeLast = 51,
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
  kQualified = 52,
};

enum class TypeSpecifierSign : unsigned int {
  kUnspecified = 0,
  kSigned = 1,
  kUnsigned = 2,
};

enum class TypeSpecifierType : unsigned int {
  kUnspecified = 0,
  kVoid = 1,
  kChar = 2,
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
  kBool = 18,
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
  kTypeofExpr = 29,
  kDecltype = 30,
  kUnderlyingType = 31,
  kAuto = 32,
  kDecltype_auto = 33,
  kAuto_type = 34,
  kUnknown_anytype = 35,
  kAtomic = 36,
  kImage1d_t = 37,
  kImage1d_array_t = 38,
  kImage1d_buffer_t = 39,
  kImage2d_t = 40,
  kImage2d_array_t = 41,
  kImage2d_depth_t = 42,
  kImage2d_array_depth_t = 43,
  kImage2d_msaa_t = 44,
  kImage2d_array_msaa_t = 45,
  kImage2d_msaa_depth_t = 46,
  kImage2d_array_msaa_depth_t = 47,
  kImage3d_t = 48,
  kError = 49,
};

enum class TypeSpecifierWidth : unsigned int {
  kUnspecified = 0,
  kShort = 1,
  kLong = 2,
  kLonglong = 3,
};

enum class TypeSpecifiersPipe : unsigned int {
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
  kLast = 4,
};

enum class UnaryOperatorKind : unsigned int {
  kPostInc = 0,
  kPostDec = 1,
  kPreInc = 2,
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

enum class ValueKind : unsigned int {
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
  kByRef = 1,
  kByCopy = 2,
  kVLAType = 3,
};

enum class VectorKind : unsigned int {
  kGenericVector = 0,
  kAltiVecVector = 1,
  kAltiVecPixel = 2,
  kAltiVecBool = 3,
  kNeonVector = 4,
  kNeonPolyVector = 5,
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

class DeclBuilder;
class AccessSpecDecl;
class BindingDecl;
class BlockDecl;
class BuiltinTemplateDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class CapturedDecl;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class ConceptDecl;
class ConstructorUsingShadowDecl;
class Decl;
class DeclContext;
class DeclaratorDecl;
class DecompositionDecl;
class EmptyDecl;
class EnumConstantDecl;
class EnumDecl;
class ExportDecl;
class ExternCContextDecl;
class FieldDecl;
class FileScopeAsmDecl;
class FriendDecl;
class FriendTemplateDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class ImplicitParamDecl;
class ImportDecl;
class IndirectFieldDecl;
class LabelDecl;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class MSGuidDecl;
class MSPropertyDecl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NonTypeTemplateParmDecl;
class OMPAllocateDecl;
class OMPCapturedExprDecl;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPRequiresDecl;
class OMPThreadPrivateDecl;
class ObjCAtDefsFieldDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCProtocolDecl;
class ObjCTypeParamDecl;
class ParmVarDecl;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class RecordDecl;
class RedeclarableTemplateDecl;
class RequiresExprBodyDecl;
class StaticAssertDecl;
class TagDecl;
class TemplateDecl;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TranslationUnitDecl;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UsingDecl;
class UsingDirectiveDecl;
class UsingPackDecl;
class UsingShadowDecl;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
class DeclContext {
 public:
  DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *) {}
};

class Decl {
 public:
  ~Decl(void) = default;
  Decl(const Decl &) = default;
  Decl(Decl &&) noexcept = default;
  Decl &operator=(const Decl &) = default;
  Decl &operator=(Decl &&) noexcept = default;

  // Attrs
  AccessSpecifier Access(void) const;
  AccessSpecifier AccessUnsafe(void) const;
  ::pasta::FunctionDecl AsFunction(void) const;
  std::optional<::pasta::Token> BeginToken(void) const;
  // Body
  ::pasta::Decl CanonicalDecl(void) const;
  ::pasta::DeclContext DeclContext(void) const;
  std::optional<::pasta::Token> EndToken(void) const;
  // FriendObjectKind
  uint32_t GlobalID(void) const;
  uint32_t IdentifierNamespace(void) const;
  // ImportedOwningModule
  ::pasta::DeclContext LexicalDeclContext(void) const;
  // LocalOwningModule
  std::optional<::pasta::Token> Token(void) const;
  // ModuleOwnershipKind
  ::pasta::Decl MostRecentDecl(void) const;
  ::pasta::Decl NextDeclInContext(void) const;
  ::pasta::Decl NonClosureContext(void) const;
  // OwningModule
  uint32_t OwningModuleID(void) const;
  ::pasta::Decl PreviousDecl(void) const;
  // TokenRange
  ::pasta::TranslationUnitDecl TranslationUnitDecl(void) const;
  bool HasAttrs(void) const;
  bool HasBody(void) const;
  bool HasOwningModule(void) const;
  bool HasTagIdentifierNamespace(void) const;
  bool IsCanonicalDecl(void) const;
  bool IsDefinedOutsideFunctionOrMethod(void) const;
  bool IsDeprecated(void) const;
  bool IsFirstDecl(void) const;
  bool IsFromASTFile(void) const;
  bool IsFunctionOrFunctionTemplate(void) const;
  bool IsImplicit(void) const;
  // IsInIdentifierNamespace
  bool IsInvalidDecl(void) const;
  bool IsModulePrivate(void) const;
  bool IsTemplateParameter(void) const;
  bool IsThisDeclarationReferenced(void) const;
  bool IsTopLevelDeclInObjCContainer(void) const;
  bool IsUnavailable(void) const;
  bool IsUnconditionallyVisible(void) const;
  // Redecls
  inline DeclKind Kind(void) const {
    return kind;
  }

  std::string_view KindName(void) const;

 protected:
  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::AccessSpecDecl *AccessSpecDecl;
    const ::clang::BindingDecl *BindingDecl;
    const ::clang::BlockDecl *BlockDecl;
    const ::clang::BuiltinTemplateDecl *BuiltinTemplateDecl;
    const ::clang::CXXConstructorDecl *CXXConstructorDecl;
    const ::clang::CXXConversionDecl *CXXConversionDecl;
    const ::clang::CXXDeductionGuideDecl *CXXDeductionGuideDecl;
    const ::clang::CXXDestructorDecl *CXXDestructorDecl;
    const ::clang::CXXMethodDecl *CXXMethodDecl;
    const ::clang::CXXRecordDecl *CXXRecordDecl;
    const ::clang::CapturedDecl *CapturedDecl;
    const ::clang::ClassScopeFunctionSpecializationDecl *ClassScopeFunctionSpecializationDecl;
    const ::clang::ClassTemplateDecl *ClassTemplateDecl;
    const ::clang::ClassTemplatePartialSpecializationDecl *ClassTemplatePartialSpecializationDecl;
    const ::clang::ClassTemplateSpecializationDecl *ClassTemplateSpecializationDecl;
    const ::clang::ConceptDecl *ConceptDecl;
    const ::clang::ConstructorUsingShadowDecl *ConstructorUsingShadowDecl;
    const ::clang::Decl *Decl;
    const ::clang::DeclaratorDecl *DeclaratorDecl;
    const ::clang::DecompositionDecl *DecompositionDecl;
    const ::clang::EmptyDecl *EmptyDecl;
    const ::clang::EnumConstantDecl *EnumConstantDecl;
    const ::clang::EnumDecl *EnumDecl;
    const ::clang::ExportDecl *ExportDecl;
    const ::clang::ExternCContextDecl *ExternCContextDecl;
    const ::clang::FieldDecl *FieldDecl;
    const ::clang::FileScopeAsmDecl *FileScopeAsmDecl;
    const ::clang::FriendDecl *FriendDecl;
    const ::clang::FriendTemplateDecl *FriendTemplateDecl;
    const ::clang::FunctionDecl *FunctionDecl;
    const ::clang::FunctionTemplateDecl *FunctionTemplateDecl;
    const ::clang::ImplicitParamDecl *ImplicitParamDecl;
    const ::clang::ImportDecl *ImportDecl;
    const ::clang::IndirectFieldDecl *IndirectFieldDecl;
    const ::clang::LabelDecl *LabelDecl;
    const ::clang::LifetimeExtendedTemporaryDecl *LifetimeExtendedTemporaryDecl;
    const ::clang::LinkageSpecDecl *LinkageSpecDecl;
    const ::clang::MSGuidDecl *MSGuidDecl;
    const ::clang::MSPropertyDecl *MSPropertyDecl;
    const ::clang::NamedDecl *NamedDecl;
    const ::clang::NamespaceAliasDecl *NamespaceAliasDecl;
    const ::clang::NamespaceDecl *NamespaceDecl;
    const ::clang::NonTypeTemplateParmDecl *NonTypeTemplateParmDecl;
    const ::clang::OMPAllocateDecl *OMPAllocateDecl;
    const ::clang::OMPCapturedExprDecl *OMPCapturedExprDecl;
    const ::clang::OMPDeclareMapperDecl *OMPDeclareMapperDecl;
    const ::clang::OMPDeclareReductionDecl *OMPDeclareReductionDecl;
    const ::clang::OMPRequiresDecl *OMPRequiresDecl;
    const ::clang::OMPThreadPrivateDecl *OMPThreadPrivateDecl;
    const ::clang::ObjCAtDefsFieldDecl *ObjCAtDefsFieldDecl;
    const ::clang::ObjCCategoryDecl *ObjCCategoryDecl;
    const ::clang::ObjCCategoryImplDecl *ObjCCategoryImplDecl;
    const ::clang::ObjCCompatibleAliasDecl *ObjCCompatibleAliasDecl;
    const ::clang::ObjCContainerDecl *ObjCContainerDecl;
    const ::clang::ObjCImplDecl *ObjCImplDecl;
    const ::clang::ObjCImplementationDecl *ObjCImplementationDecl;
    const ::clang::ObjCInterfaceDecl *ObjCInterfaceDecl;
    const ::clang::ObjCIvarDecl *ObjCIvarDecl;
    const ::clang::ObjCMethodDecl *ObjCMethodDecl;
    const ::clang::ObjCPropertyDecl *ObjCPropertyDecl;
    const ::clang::ObjCPropertyImplDecl *ObjCPropertyImplDecl;
    const ::clang::ObjCProtocolDecl *ObjCProtocolDecl;
    const ::clang::ObjCTypeParamDecl *ObjCTypeParamDecl;
    const ::clang::ParmVarDecl *ParmVarDecl;
    const ::clang::PragmaCommentDecl *PragmaCommentDecl;
    const ::clang::PragmaDetectMismatchDecl *PragmaDetectMismatchDecl;
    const ::clang::RecordDecl *RecordDecl;
    const ::clang::RedeclarableTemplateDecl *RedeclarableTemplateDecl;
    const ::clang::RequiresExprBodyDecl *RequiresExprBodyDecl;
    const ::clang::StaticAssertDecl *StaticAssertDecl;
    const ::clang::TagDecl *TagDecl;
    const ::clang::TemplateDecl *TemplateDecl;
    const ::clang::TemplateTemplateParmDecl *TemplateTemplateParmDecl;
    const ::clang::TemplateTypeParmDecl *TemplateTypeParmDecl;
    const ::clang::TranslationUnitDecl *TranslationUnitDecl;
    const ::clang::TypeAliasDecl *TypeAliasDecl;
    const ::clang::TypeAliasTemplateDecl *TypeAliasTemplateDecl;
    const ::clang::TypeDecl *TypeDecl;
    const ::clang::TypedefDecl *TypedefDecl;
    const ::clang::TypedefNameDecl *TypedefNameDecl;
    const ::clang::UnresolvedUsingTypenameDecl *UnresolvedUsingTypenameDecl;
    const ::clang::UnresolvedUsingValueDecl *UnresolvedUsingValueDecl;
    const ::clang::UsingDecl *UsingDecl;
    const ::clang::UsingDirectiveDecl *UsingDirectiveDecl;
    const ::clang::UsingPackDecl *UsingPackDecl;
    const ::clang::UsingShadowDecl *UsingShadowDecl;
    const ::clang::ValueDecl *ValueDecl;
    const ::clang::VarDecl *VarDecl;
    const ::clang::VarTemplateDecl *VarTemplateDecl;
    const ::clang::VarTemplatePartialSpecializationDecl *VarTemplatePartialSpecializationDecl;
    const ::clang::VarTemplateSpecializationDecl *VarTemplateSpecializationDecl;
  } u;
  DeclKind kind;

  inline explicit Decl(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Decl *decl_,
                       DeclKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    u.Decl = decl_;
  }

 private:
  Decl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit Decl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

class EmptyDecl : public Decl {
 public:
  ~EmptyDecl(void) = default;
  EmptyDecl(const EmptyDecl &) = default;
  EmptyDecl(EmptyDecl &&) noexcept = default;
  EmptyDecl &operator=(const EmptyDecl &) = default;
  EmptyDecl &operator=(EmptyDecl &&) noexcept = default;

 private:
  EmptyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit EmptyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::EmptyDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(EmptyDecl));

class ExportDecl : public Decl {
 public:
  ~ExportDecl(void) = default;
  ExportDecl(const ExportDecl &) = default;
  ExportDecl(ExportDecl &&) noexcept = default;
  ExportDecl &operator=(const ExportDecl &) = default;
  ExportDecl &operator=(ExportDecl &&) noexcept = default;

  std::optional<::pasta::Token> EndToken(void) const;
  std::optional<::pasta::Token> ExportToken(void) const;
  std::optional<::pasta::Token> RBraceToken(void) const;
  // TokenRange
  bool HasBraces(void) const;
 private:
  ExportDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ExportDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ExportDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ExportDecl));

class ExternCContextDecl : public Decl {
 public:
  ~ExternCContextDecl(void) = default;
  ExternCContextDecl(const ExternCContextDecl &) = default;
  ExternCContextDecl(ExternCContextDecl &&) noexcept = default;
  ExternCContextDecl &operator=(const ExternCContextDecl &) = default;
  ExternCContextDecl &operator=(ExternCContextDecl &&) noexcept = default;

 private:
  ExternCContextDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ExternCContextDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ExternCContextDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ExternCContextDecl));

class FileScopeAsmDecl : public Decl {
 public:
  ~FileScopeAsmDecl(void) = default;
  FileScopeAsmDecl(const FileScopeAsmDecl &) = default;
  FileScopeAsmDecl(FileScopeAsmDecl &&) noexcept = default;
  FileScopeAsmDecl &operator=(const FileScopeAsmDecl &) = default;
  FileScopeAsmDecl &operator=(FileScopeAsmDecl &&) noexcept = default;

  std::optional<::pasta::Token> AsmToken(void) const;
  // AsmString
  std::optional<::pasta::Token> RParenToken(void) const;
  // TokenRange
 private:
  FileScopeAsmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FileScopeAsmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::FileScopeAsmDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FileScopeAsmDecl));

class FriendDecl : public Decl {
 public:
  ~FriendDecl(void) = default;
  FriendDecl(const FriendDecl &) = default;
  FriendDecl(FriendDecl &&) noexcept = default;
  FriendDecl &operator=(const FriendDecl &) = default;
  FriendDecl &operator=(FriendDecl &&) noexcept = default;

  ::pasta::NamedDecl FindFriendDecl(void) const;
  std::optional<::pasta::Token> FriendToken(void) const;
  // FriendType
  uint32_t FriendTypeNumTemplateParameterLists(void) const;
  // FriendTypeTemplateParameterList
  // TokenRange
  bool IsUnsupportedFriend(void) const;
 private:
  FriendDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FriendDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::FriendDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FriendDecl));

class FriendTemplateDecl : public Decl {
 public:
  ~FriendTemplateDecl(void) = default;
  FriendTemplateDecl(const FriendTemplateDecl &) = default;
  FriendTemplateDecl(FriendTemplateDecl &&) noexcept = default;
  FriendTemplateDecl &operator=(const FriendTemplateDecl &) = default;
  FriendTemplateDecl &operator=(FriendTemplateDecl &&) noexcept = default;

  ::pasta::NamedDecl FindFriendDecl(void) const;
  std::optional<::pasta::Token> FriendToken(void) const;
  // FriendType
  uint32_t NumTemplateParameters(void) const;
  // TemplateParameterList
 private:
  FriendTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FriendTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::FriendTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FriendTemplateDecl));

class ImportDecl : public Decl {
 public:
  ~ImportDecl(void) = default;
  ImportDecl(const ImportDecl &) = default;
  ImportDecl(ImportDecl &&) noexcept = default;
  ImportDecl &operator=(const ImportDecl &) = default;
  ImportDecl &operator=(ImportDecl &&) noexcept = default;

  // ImportedModule
 private:
  ImportDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ImportDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ImportDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ImportDecl));

class LifetimeExtendedTemporaryDecl : public Decl {
 public:
  ~LifetimeExtendedTemporaryDecl(void) = default;
  LifetimeExtendedTemporaryDecl(const LifetimeExtendedTemporaryDecl &) = default;
  LifetimeExtendedTemporaryDecl(LifetimeExtendedTemporaryDecl &&) noexcept = default;
  LifetimeExtendedTemporaryDecl &operator=(const LifetimeExtendedTemporaryDecl &) = default;
  LifetimeExtendedTemporaryDecl &operator=(LifetimeExtendedTemporaryDecl &&) noexcept = default;

  // ChildrenExpr
  ::pasta::ValueDecl ExtendingDecl(void) const;
  uint32_t ManglingNumber(void) const;
  // TemporaryExpr
  // Value
 private:
  LifetimeExtendedTemporaryDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit LifetimeExtendedTemporaryDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::LifetimeExtendedTemporaryDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(LifetimeExtendedTemporaryDecl));

class LinkageSpecDecl : public Decl {
 public:
  ~LinkageSpecDecl(void) = default;
  LinkageSpecDecl(const LinkageSpecDecl &) = default;
  LinkageSpecDecl(LinkageSpecDecl &&) noexcept = default;
  LinkageSpecDecl &operator=(const LinkageSpecDecl &) = default;
  LinkageSpecDecl &operator=(LinkageSpecDecl &&) noexcept = default;

  std::optional<::pasta::Token> EndToken(void) const;
  std::optional<::pasta::Token> ExternToken(void) const;
  // Language
  std::optional<::pasta::Token> RBraceToken(void) const;
  // TokenRange
  bool HasBraces(void) const;
 private:
  LinkageSpecDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit LinkageSpecDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::LinkageSpecDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(LinkageSpecDecl));

class NamedDecl : public Decl {
 public:
  ~NamedDecl(void) = default;
  NamedDecl(const NamedDecl &) = default;
  NamedDecl(NamedDecl &&) noexcept = default;
  NamedDecl &operator=(const NamedDecl &) = default;
  NamedDecl &operator=(NamedDecl &&) noexcept = default;

  // DeclName
  Linkage FormalLinkage(void) const;
  // Identifier
  ::pasta::NamedDecl MostRecentDecl(void) const;
  std::string_view Name(void) const;
  std::string NameAsString(void) const;
  ::pasta::NamedDecl UnderlyingDecl(void) const;
  Visibility Visibility(void) const;
  bool HasExternalFormalLinkage(void) const;
  bool HasLinkageBeenComputed(void) const;
  bool IsCXXClassMember(void) const;
  bool IsExternallyDeclarable(void) const;
  bool IsExternallyVisible(void) const;
 private:
  NamedDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NamedDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::NamedDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NamedDecl));

class NamespaceAliasDecl : public NamedDecl {
 public:
  ~NamespaceAliasDecl(void) = default;
  NamespaceAliasDecl(const NamespaceAliasDecl &) = default;
  NamespaceAliasDecl(NamespaceAliasDecl &&) noexcept = default;
  NamespaceAliasDecl &operator=(const NamespaceAliasDecl &) = default;
  NamespaceAliasDecl &operator=(NamespaceAliasDecl &&) noexcept = default;

  std::optional<::pasta::Token> AliasToken(void) const;
  ::pasta::NamedDecl AliasedNamespace(void) const;
  ::pasta::NamespaceAliasDecl CanonicalDecl(void) const;
  ::pasta::NamespaceDecl Namespace(void) const;
  std::optional<::pasta::Token> NamespaceToken(void) const;
  // Qualifier
  // QualifierToken
  // TokenRange
  std::optional<::pasta::Token> TargetNameToken(void) const;
 private:
  NamespaceAliasDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NamespaceAliasDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::NamespaceAliasDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NamespaceAliasDecl));

class NamespaceDecl : public NamedDecl {
 public:
  ~NamespaceDecl(void) = default;
  NamespaceDecl(const NamespaceDecl &) = default;
  NamespaceDecl(NamespaceDecl &&) noexcept = default;
  NamespaceDecl &operator=(const NamespaceDecl &) = default;
  NamespaceDecl &operator=(NamespaceDecl &&) noexcept = default;

  ::pasta::NamespaceDecl AnonymousNamespace(void) const;
  std::optional<::pasta::Token> BeginToken(void) const;
  ::pasta::NamespaceDecl CanonicalDecl(void) const;
  std::optional<::pasta::Token> RBraceToken(void) const;
  // TokenRange
  bool IsAnonymousNamespace(void) const;
  bool IsInline(void) const;
 private:
  NamespaceDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NamespaceDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::NamespaceDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NamespaceDecl));

class OMPAllocateDecl : public Decl {
 public:
  ~OMPAllocateDecl(void) = default;
  OMPAllocateDecl(const OMPAllocateDecl &) = default;
  OMPAllocateDecl(OMPAllocateDecl &&) noexcept = default;
  OMPAllocateDecl &operator=(const OMPAllocateDecl &) = default;
  OMPAllocateDecl &operator=(OMPAllocateDecl &&) noexcept = default;

  // Clauses
  // Varlists
 private:
  OMPAllocateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPAllocateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::OMPAllocateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPAllocateDecl));

class OMPRequiresDecl : public Decl {
 public:
  ~OMPRequiresDecl(void) = default;
  OMPRequiresDecl(const OMPRequiresDecl &) = default;
  OMPRequiresDecl(OMPRequiresDecl &&) noexcept = default;
  OMPRequiresDecl &operator=(const OMPRequiresDecl &) = default;
  OMPRequiresDecl &operator=(OMPRequiresDecl &&) noexcept = default;

  // Clauses
 private:
  OMPRequiresDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPRequiresDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::OMPRequiresDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPRequiresDecl));

class OMPThreadPrivateDecl : public Decl {
 public:
  ~OMPThreadPrivateDecl(void) = default;
  OMPThreadPrivateDecl(const OMPThreadPrivateDecl &) = default;
  OMPThreadPrivateDecl(OMPThreadPrivateDecl &&) noexcept = default;
  OMPThreadPrivateDecl &operator=(const OMPThreadPrivateDecl &) = default;
  OMPThreadPrivateDecl &operator=(OMPThreadPrivateDecl &&) noexcept = default;

  // Varlists
 private:
  OMPThreadPrivateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPThreadPrivateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::OMPThreadPrivateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPThreadPrivateDecl));

class ObjCCompatibleAliasDecl : public NamedDecl {
 public:
  ~ObjCCompatibleAliasDecl(void) = default;
  ObjCCompatibleAliasDecl(const ObjCCompatibleAliasDecl &) = default;
  ObjCCompatibleAliasDecl(ObjCCompatibleAliasDecl &&) noexcept = default;
  ObjCCompatibleAliasDecl &operator=(const ObjCCompatibleAliasDecl &) = default;
  ObjCCompatibleAliasDecl &operator=(ObjCCompatibleAliasDecl &&) noexcept = default;

  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
 private:
  ObjCCompatibleAliasDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCCompatibleAliasDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCCompatibleAliasDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCCompatibleAliasDecl));

class ObjCContainerDecl : public NamedDecl {
 public:
  ~ObjCContainerDecl(void) = default;
  ObjCContainerDecl(const ObjCContainerDecl &) = default;
  ObjCContainerDecl(ObjCContainerDecl &&) noexcept = default;
  ObjCContainerDecl &operator=(const ObjCContainerDecl &) = default;
  ObjCContainerDecl &operator=(ObjCContainerDecl &&) noexcept = default;

  // Class_methods
  // Class_properties
  // CollectPropertiesToImplement
  // AtEndRange
  std::optional<::pasta::Token> AtStartToken(void) const;
  // ClassMethod
  // InstanceMethod
  // TokenRange
  // Instance_methods
  // Instance_properties
  // Methods
  // Properties
 private:
  ObjCContainerDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCContainerDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCContainerDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCContainerDecl));

class ObjCImplDecl : public ObjCContainerDecl {
 public:
  ~ObjCImplDecl(void) = default;
  ObjCImplDecl(const ObjCImplDecl &) = default;
  ObjCImplDecl(ObjCImplDecl &&) noexcept = default;
  ObjCImplDecl &operator=(const ObjCImplDecl &) = default;
  ObjCImplDecl &operator=(ObjCImplDecl &&) noexcept = default;

  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  // Property_impls
 private:
  ObjCImplDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCImplDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCImplDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCImplDecl));

class ObjCImplementationDecl : public ObjCImplDecl {
 public:
  ~ObjCImplementationDecl(void) = default;
  ObjCImplementationDecl(const ObjCImplementationDecl &) = default;
  ObjCImplementationDecl(ObjCImplementationDecl &&) noexcept = default;
  ObjCImplementationDecl &operator=(const ObjCImplementationDecl &) = default;
  ObjCImplementationDecl &operator=(ObjCImplementationDecl &&) noexcept = default;

  // Identifier
  std::optional<::pasta::Token> IvarLBraceToken(void) const;
  std::optional<::pasta::Token> IvarRBraceToken(void) const;
  std::string_view Name(void) const;
  std::string NameAsString(void) const;
  uint32_t NumIvarInitializers(void) const;
  ::pasta::ObjCInterfaceDecl SuperClass(void) const;
  std::optional<::pasta::Token> SuperClassToken(void) const;
  bool HasDestructors(void) const;
  bool HasNonZeroConstructors(void) const;
  // Inits
  // Ivars
 private:
  ObjCImplementationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCImplementationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCImplementationDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCImplementationDecl));

class ObjCInterfaceDecl : public ObjCContainerDecl {
 public:
  ~ObjCInterfaceDecl(void) = default;
  ObjCInterfaceDecl(const ObjCInterfaceDecl &) = default;
  ObjCInterfaceDecl(ObjCInterfaceDecl &&) noexcept = default;
  ObjCInterfaceDecl &operator=(const ObjCInterfaceDecl &) = default;
  ObjCInterfaceDecl &operator=(ObjCInterfaceDecl &&) noexcept = default;

  // All_referenced_protocols
  bool DeclaresOrInheritsDesignatedInitializers(void) const;
  ::pasta::ObjCInterfaceDecl CanonicalDecl(void) const;
  ::pasta::ObjCCategoryDecl CategoryListRaw(void) const;
  // CategoryMethod
  ::pasta::ObjCInterfaceDecl Definition(void) const;
  std::optional<::pasta::Token> EndOfDefinitionToken(void) const;
  // ReferencedProtocols
  // TokenRange
  // SuperClassTInfo
  // SuperClassType
  // TypeForDecl
  // TypeParamListAsWritten
  bool HasDefinition(void) const;
  bool IsImplicitInterfaceDecl(void) const;
  // IsSuperClassOf
  bool IsThisDeclarationADefinition(void) const;
  // Ivars
  // Known_categories
  // Known_extensions
  // LookupClassMethod
  // LookupInstanceMethod
  // LookupPropertyAccessor
  // Protocol_locs
  // Protocols
  // Visible_categories
  // Visible_extensions
 private:
  ObjCInterfaceDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCInterfaceDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCInterfaceDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCInterfaceDecl));

class ObjCMethodDecl : public NamedDecl {
 public:
  ~ObjCMethodDecl(void) = default;
  ObjCMethodDecl(const ObjCMethodDecl &) = default;
  ObjCMethodDecl(ObjCMethodDecl &&) noexcept = default;
  ObjCMethodDecl &operator=(const ObjCMethodDecl &) = default;
  ObjCMethodDecl &operator=(ObjCMethodDecl &&) noexcept = default;

  std::optional<::pasta::Token> BeginToken(void) const;
  ::pasta::ObjCMethodDecl CanonicalDecl(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  ::pasta::ImplicitParamDecl CmdDecl(void) const;
  std::optional<::pasta::Token> DeclaratorEndToken(void) const;
  // ImplementationControl
  uint32_t NumSelectorLocs(void) const;
  // ObjCDeclQualifier
  // ParamDecl
  // ReturnType
  // ReturnTypeSourceInfo
  // Selector
  // SelectorToken
  std::optional<::pasta::Token> SelectorStartToken(void) const;
  ::pasta::ImplicitParamDecl SelfDecl(void) const;
  // TokenRange
  bool HasBody(void) const;
  bool HasRedeclaration(void) const;
  bool HasRelatedResultType(void) const;
  bool HasSkippedBody(void) const;
  bool IsClassMethod(void) const;
  bool IsDefined(void) const;
  bool IsInstanceMethod(void) const;
  bool IsOptional(void) const;
  bool IsOverriding(void) const;
  bool IsPropertyAccessor(void) const;
  bool IsRedeclaration(void) const;
  bool IsSynthesizedAccessorStub(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsVariadic(void) const;
  // Parameters
 private:
  ObjCMethodDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCMethodDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCMethodDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCMethodDecl));

class ObjCPropertyDecl : public NamedDecl {
 public:
  ~ObjCPropertyDecl(void) = default;
  ObjCPropertyDecl(const ObjCPropertyDecl &) = default;
  ObjCPropertyDecl(ObjCPropertyDecl &&) noexcept = default;
  ObjCPropertyDecl &operator=(const ObjCPropertyDecl &) = default;
  ObjCPropertyDecl &operator=(ObjCPropertyDecl &&) noexcept = default;

  std::optional<::pasta::Token> AtToken(void) const;
  ::pasta::ObjCMethodDecl GetterMethodDecl(void) const;
  // GetterName
  std::optional<::pasta::Token> GetterNameToken(void) const;
  std::optional<::pasta::Token> LParenToken(void) const;
  // PropertyAttributes
  // PropertyAttributesAsWritten
  // PropertyImplementation
  ::pasta::ObjCIvarDecl PropertyIvarDecl(void) const;
  ObjCPropertyQueryKind QueryKind(void) const;
  // SetterKind
  ::pasta::ObjCMethodDecl SetterMethodDecl(void) const;
  // SetterName
  std::optional<::pasta::Token> SetterNameToken(void) const;
  // TokenRange
  // Type
  // TypeSourceInfo
  bool IsAtomic(void) const;
  bool IsClassProperty(void) const;
  bool IsDirectProperty(void) const;
  bool IsInstanceProperty(void) const;
  bool IsOptional(void) const;
  bool IsReadOnly(void) const;
  bool IsRetaining(void) const;
 private:
  ObjCPropertyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCPropertyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCPropertyDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyDecl));

class ObjCPropertyImplDecl : public Decl {
 public:
  ~ObjCPropertyImplDecl(void) = default;
  ObjCPropertyImplDecl(const ObjCPropertyImplDecl &) = default;
  ObjCPropertyImplDecl(ObjCPropertyImplDecl &&) noexcept = default;
  ObjCPropertyImplDecl &operator=(const ObjCPropertyImplDecl &) = default;
  ObjCPropertyImplDecl &operator=(ObjCPropertyImplDecl &&) noexcept = default;

  std::optional<::pasta::Token> BeginToken(void) const;
  // GetterCXXConstructor
  ::pasta::ObjCMethodDecl GetterMethodDecl(void) const;
  ::pasta::ObjCPropertyDecl PropertyDecl(void) const;
  // PropertyImplementation
  ::pasta::ObjCIvarDecl PropertyIvarDecl(void) const;
  std::optional<::pasta::Token> PropertyIvarDeclToken(void) const;
  // SetterCXXAssignment
  ::pasta::ObjCMethodDecl SetterMethodDecl(void) const;
  bool IsIvarNameSpecified(void) const;
 private:
  ObjCPropertyImplDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCPropertyImplDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCPropertyImplDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyImplDecl));

class ObjCProtocolDecl : public ObjCContainerDecl {
 public:
  ~ObjCProtocolDecl(void) = default;
  ObjCProtocolDecl(const ObjCProtocolDecl &) = default;
  ObjCProtocolDecl(ObjCProtocolDecl &&) noexcept = default;
  ObjCProtocolDecl &operator=(const ObjCProtocolDecl &) = default;
  ObjCProtocolDecl &operator=(ObjCProtocolDecl &&) noexcept = default;

  ::pasta::ObjCProtocolDecl CanonicalDecl(void) const;
  ::pasta::ObjCProtocolDecl Definition(void) const;
  // ReferencedProtocols
  // TokenRange
  bool HasDefinition(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // LookupClassMethod
  // LookupInstanceMethod
  // Protocol_locs
  // Protocols
 private:
  ObjCProtocolDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCProtocolDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCProtocolDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCProtocolDecl));

class PragmaCommentDecl : public Decl {
 public:
  ~PragmaCommentDecl(void) = default;
  PragmaCommentDecl(const PragmaCommentDecl &) = default;
  PragmaCommentDecl(PragmaCommentDecl &&) noexcept = default;
  PragmaCommentDecl &operator=(const PragmaCommentDecl &) = default;
  PragmaCommentDecl &operator=(PragmaCommentDecl &&) noexcept = default;

  std::string_view Arg(void) const;
  PragmaMSCommentKind CommentKind(void) const;
 private:
  PragmaCommentDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit PragmaCommentDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::PragmaCommentDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(PragmaCommentDecl));

class PragmaDetectMismatchDecl : public Decl {
 public:
  ~PragmaDetectMismatchDecl(void) = default;
  PragmaDetectMismatchDecl(const PragmaDetectMismatchDecl &) = default;
  PragmaDetectMismatchDecl(PragmaDetectMismatchDecl &&) noexcept = default;
  PragmaDetectMismatchDecl &operator=(const PragmaDetectMismatchDecl &) = default;
  PragmaDetectMismatchDecl &operator=(PragmaDetectMismatchDecl &&) noexcept = default;

  std::string_view Name(void) const;
  std::string_view Value(void) const;
 private:
  PragmaDetectMismatchDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit PragmaDetectMismatchDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::PragmaDetectMismatchDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(PragmaDetectMismatchDecl));

class RequiresExprBodyDecl : public Decl {
 public:
  ~RequiresExprBodyDecl(void) = default;
  RequiresExprBodyDecl(const RequiresExprBodyDecl &) = default;
  RequiresExprBodyDecl(RequiresExprBodyDecl &&) noexcept = default;
  RequiresExprBodyDecl &operator=(const RequiresExprBodyDecl &) = default;
  RequiresExprBodyDecl &operator=(RequiresExprBodyDecl &&) noexcept = default;

 private:
  RequiresExprBodyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit RequiresExprBodyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::RequiresExprBodyDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(RequiresExprBodyDecl));

class StaticAssertDecl : public Decl {
 public:
  ~StaticAssertDecl(void) = default;
  StaticAssertDecl(const StaticAssertDecl &) = default;
  StaticAssertDecl(StaticAssertDecl &&) noexcept = default;
  StaticAssertDecl &operator=(const StaticAssertDecl &) = default;
  StaticAssertDecl &operator=(StaticAssertDecl &&) noexcept = default;

  // AssertExpr
  // Message
  std::optional<::pasta::Token> RParenToken(void) const;
  // TokenRange
  bool IsFailed(void) const;
 private:
  StaticAssertDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit StaticAssertDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::StaticAssertDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(StaticAssertDecl));

class TemplateDecl : public NamedDecl {
 public:
  ~TemplateDecl(void) = default;
  TemplateDecl(const TemplateDecl &) = default;
  TemplateDecl(TemplateDecl &&) noexcept = default;
  TemplateDecl &operator=(const TemplateDecl &) = default;
  TemplateDecl &operator=(TemplateDecl &&) noexcept = default;

  // TokenRange
  // TemplateParameters
  ::pasta::NamedDecl TemplatedDecl(void) const;
 private:
  TemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateDecl));

class TemplateTemplateParmDecl : public TemplateDecl {
 public:
  ~TemplateTemplateParmDecl(void) = default;
  TemplateTemplateParmDecl(const TemplateTemplateParmDecl &) = default;
  TemplateTemplateParmDecl(TemplateTemplateParmDecl &&) noexcept = default;
  TemplateTemplateParmDecl &operator=(const TemplateTemplateParmDecl &) = default;
  TemplateTemplateParmDecl &operator=(TemplateTemplateParmDecl &&) noexcept = default;

  bool DefaultArgumentWasInherited(void) const;
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionTemplateParameters
  uint32_t NumExpansionTemplateParameters(void) const;
  // TokenRange
  bool HasDefaultArgument(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 private:
  TemplateTemplateParmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateTemplateParmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TemplateTemplateParmDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateTemplateParmDecl));

class TranslationUnitDecl : public Decl {
 public:
  ~TranslationUnitDecl(void) = default;
  TranslationUnitDecl(const TranslationUnitDecl &) = default;
  TranslationUnitDecl(TranslationUnitDecl &&) noexcept = default;
  TranslationUnitDecl &operator=(const TranslationUnitDecl &) = default;
  TranslationUnitDecl &operator=(TranslationUnitDecl &&) noexcept = default;

  // ASTContext
  ::pasta::NamespaceDecl AnonymousNamespace(void) const;
 private:
  TranslationUnitDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TranslationUnitDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TranslationUnitDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TranslationUnitDecl));

class TypeDecl : public NamedDecl {
 public:
  ~TypeDecl(void) = default;
  TypeDecl(const TypeDecl &) = default;
  TypeDecl(TypeDecl &&) noexcept = default;
  TypeDecl &operator=(const TypeDecl &) = default;
  TypeDecl &operator=(TypeDecl &&) noexcept = default;

  std::optional<::pasta::Token> BeginToken(void) const;
  // TokenRange
  // TypeForDecl
 private:
  TypeDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypeDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TypeDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypeDecl));

class TypedefNameDecl : public TypeDecl {
 public:
  ~TypedefNameDecl(void) = default;
  TypedefNameDecl(const TypedefNameDecl &) = default;
  TypedefNameDecl(TypedefNameDecl &&) noexcept = default;
  TypedefNameDecl &operator=(const TypedefNameDecl &) = default;
  TypedefNameDecl &operator=(TypedefNameDecl &&) noexcept = default;

  ::pasta::TypedefNameDecl CanonicalDecl(void) const;
  // TypeSourceInfo
  // UnderlyingType
  bool IsModed(void) const;
  bool IsTransparentTag(void) const;
 private:
  TypedefNameDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypedefNameDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TypedefNameDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypedefNameDecl));

class UnresolvedUsingTypenameDecl : public TypeDecl {
 public:
  ~UnresolvedUsingTypenameDecl(void) = default;
  UnresolvedUsingTypenameDecl(const UnresolvedUsingTypenameDecl &) = default;
  UnresolvedUsingTypenameDecl(UnresolvedUsingTypenameDecl &&) noexcept = default;
  UnresolvedUsingTypenameDecl &operator=(const UnresolvedUsingTypenameDecl &) = default;
  UnresolvedUsingTypenameDecl &operator=(UnresolvedUsingTypenameDecl &&) noexcept = default;

  ::pasta::UnresolvedUsingTypenameDecl CanonicalDecl(void) const;
  std::optional<::pasta::Token> EllipsisToken(void) const;
  // NameInfo
  // Qualifier
  // QualifierToken
  std::optional<::pasta::Token> TypenameToken(void) const;
  std::optional<::pasta::Token> UsingToken(void) const;
  bool IsPackExpansion(void) const;
 private:
  UnresolvedUsingTypenameDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UnresolvedUsingTypenameDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::UnresolvedUsingTypenameDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingTypenameDecl));

class UsingDecl : public NamedDecl {
 public:
  ~UsingDecl(void) = default;
  UsingDecl(const UsingDecl &) = default;
  UsingDecl(UsingDecl &&) noexcept = default;
  UsingDecl &operator=(const UsingDecl &) = default;
  UsingDecl &operator=(UsingDecl &&) noexcept = default;

  ::pasta::UsingDecl CanonicalDecl(void) const;
  // NameInfo
  // Qualifier
  // QualifierToken
  std::optional<::pasta::Token> UsingToken(void) const;
  bool HasTypename(void) const;
  bool IsAccessDeclaration(void) const;
  // Shadows
 private:
  UsingDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::UsingDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingDecl));

class UsingDirectiveDecl : public NamedDecl {
 public:
  ~UsingDirectiveDecl(void) = default;
  UsingDirectiveDecl(const UsingDirectiveDecl &) = default;
  UsingDirectiveDecl(UsingDirectiveDecl &&) noexcept = default;
  UsingDirectiveDecl &operator=(const UsingDirectiveDecl &) = default;
  UsingDirectiveDecl &operator=(UsingDirectiveDecl &&) noexcept = default;

  ::pasta::DeclContext CommonAncestor(void) const;
  std::optional<::pasta::Token> IdentLocation(void) const;
  std::optional<::pasta::Token> NamespaceKeyLocation(void) const;
  ::pasta::NamespaceDecl NominatedNamespace(void) const;
  ::pasta::NamedDecl NominatedNamespaceAsWritten(void) const;
  // Qualifier
  // QualifierToken
  // TokenRange
  std::optional<::pasta::Token> UsingToken(void) const;
 private:
  UsingDirectiveDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingDirectiveDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::UsingDirectiveDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingDirectiveDecl));

class UsingPackDecl : public NamedDecl {
 public:
  ~UsingPackDecl(void) = default;
  UsingPackDecl(const UsingPackDecl &) = default;
  UsingPackDecl(UsingPackDecl &&) noexcept = default;
  UsingPackDecl &operator=(const UsingPackDecl &) = default;
  UsingPackDecl &operator=(UsingPackDecl &&) noexcept = default;

  // Expansions
  ::pasta::UsingPackDecl CanonicalDecl(void) const;
  ::pasta::NamedDecl InstantiatedFromUsingDecl(void) const;
  // TokenRange
 private:
  UsingPackDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingPackDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::UsingPackDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingPackDecl));

class UsingShadowDecl : public NamedDecl {
 public:
  ~UsingShadowDecl(void) = default;
  UsingShadowDecl(const UsingShadowDecl &) = default;
  UsingShadowDecl(UsingShadowDecl &&) noexcept = default;
  UsingShadowDecl &operator=(const UsingShadowDecl &) = default;
  UsingShadowDecl &operator=(UsingShadowDecl &&) noexcept = default;

  ::pasta::UsingShadowDecl CanonicalDecl(void) const;
  ::pasta::UsingShadowDecl NextUsingShadowDecl(void) const;
  ::pasta::NamedDecl TargetDecl(void) const;
 private:
  UsingShadowDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingShadowDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::UsingShadowDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingShadowDecl));

class ValueDecl : public NamedDecl {
 public:
  ~ValueDecl(void) = default;
  ValueDecl(const ValueDecl &) = default;
  ValueDecl(ValueDecl &&) noexcept = default;
  ValueDecl &operator=(const ValueDecl &) = default;
  ValueDecl &operator=(ValueDecl &&) noexcept = default;

  // Type
 private:
  ValueDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ValueDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ValueDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ValueDecl));

class AccessSpecDecl : public Decl {
 public:
  ~AccessSpecDecl(void) = default;
  AccessSpecDecl(const AccessSpecDecl &) = default;
  AccessSpecDecl(AccessSpecDecl &&) noexcept = default;
  AccessSpecDecl &operator=(const AccessSpecDecl &) = default;
  AccessSpecDecl &operator=(AccessSpecDecl &&) noexcept = default;

  std::optional<::pasta::Token> AccessSpecifierToken(void) const;
  std::optional<::pasta::Token> ColonToken(void) const;
  // TokenRange
 private:
  AccessSpecDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit AccessSpecDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::AccessSpecDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(AccessSpecDecl));

class BindingDecl : public ValueDecl {
 public:
  ~BindingDecl(void) = default;
  BindingDecl(const BindingDecl &) = default;
  BindingDecl(BindingDecl &&) noexcept = default;
  BindingDecl &operator=(const BindingDecl &) = default;
  BindingDecl &operator=(BindingDecl &&) noexcept = default;

  // Binding
 private:
  BindingDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit BindingDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::BindingDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(BindingDecl));

class BlockDecl : public Decl {
 public:
  ~BlockDecl(void) = default;
  BlockDecl(const BlockDecl &) = default;
  BlockDecl(BlockDecl &&) noexcept = default;
  BlockDecl &operator=(const BlockDecl &) = default;
  BlockDecl &operator=(BlockDecl &&) noexcept = default;

  bool BlockMissingReturnType(void) const;
  bool CanAvoidCopyToHeap(void) const;
  // Captures
  bool CapturesCXXThis(void) const;
  bool DoesNotEscape(void) const;
  ::pasta::Decl BlockManglingContextDecl(void) const;
  uint32_t BlockManglingNumber(void) const;
  // Body
  std::optional<::pasta::Token> CaretLocation(void) const;
  // CompoundBody
  uint32_t NumCaptures(void) const;
  uint32_t NumParams(void) const;
  // ParamDecl
  // SignatureAsWritten
  bool HasCaptures(void) const;
  bool IsConversionFromLambda(void) const;
  bool IsVariadic(void) const;
  // Parameters
 private:
  BlockDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit BlockDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::BlockDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(BlockDecl));

class BuiltinTemplateDecl : public TemplateDecl {
 public:
  ~BuiltinTemplateDecl(void) = default;
  BuiltinTemplateDecl(const BuiltinTemplateDecl &) = default;
  BuiltinTemplateDecl(BuiltinTemplateDecl &&) noexcept = default;
  BuiltinTemplateDecl &operator=(const BuiltinTemplateDecl &) = default;
  BuiltinTemplateDecl &operator=(BuiltinTemplateDecl &&) noexcept = default;

  // BuiltinTemplateKind
  // TokenRange
 private:
  BuiltinTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit BuiltinTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::BuiltinTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(BuiltinTemplateDecl));

class CapturedDecl : public Decl {
 public:
  ~CapturedDecl(void) = default;
  CapturedDecl(const CapturedDecl &) = default;
  CapturedDecl(CapturedDecl &&) noexcept = default;
  CapturedDecl &operator=(const CapturedDecl &) = default;
  CapturedDecl &operator=(CapturedDecl &&) noexcept = default;

  ::pasta::ImplicitParamDecl ContextParam(void) const;
  uint32_t ContextParamPosition(void) const;
  uint32_t NumParams(void) const;
  // Param
  // Parameters
 private:
  CapturedDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CapturedDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CapturedDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CapturedDecl));

class ClassScopeFunctionSpecializationDecl : public Decl {
 public:
  ~ClassScopeFunctionSpecializationDecl(void) = default;
  ClassScopeFunctionSpecializationDecl(const ClassScopeFunctionSpecializationDecl &) = default;
  ClassScopeFunctionSpecializationDecl(ClassScopeFunctionSpecializationDecl &&) noexcept = default;
  ClassScopeFunctionSpecializationDecl &operator=(const ClassScopeFunctionSpecializationDecl &) = default;
  ClassScopeFunctionSpecializationDecl &operator=(ClassScopeFunctionSpecializationDecl &&) noexcept = default;

  ::pasta::CXXMethodDecl Specialization(void) const;
  // TemplateArgsAsWritten
  bool HasExplicitTemplateArgs(void) const;
 private:
  ClassScopeFunctionSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassScopeFunctionSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ClassScopeFunctionSpecializationDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassScopeFunctionSpecializationDecl));

class ConceptDecl : public TemplateDecl {
 public:
  ~ConceptDecl(void) = default;
  ConceptDecl(const ConceptDecl &) = default;
  ConceptDecl(ConceptDecl &&) noexcept = default;
  ConceptDecl &operator=(const ConceptDecl &) = default;
  ConceptDecl &operator=(ConceptDecl &&) noexcept = default;

  // ConstraintExpr
  // TokenRange
  bool IsTypeConcept(void) const;
 private:
  ConceptDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ConceptDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ConceptDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ConceptDecl));

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 public:
  ~ConstructorUsingShadowDecl(void) = default;
  ConstructorUsingShadowDecl(const ConstructorUsingShadowDecl &) = default;
  ConstructorUsingShadowDecl(ConstructorUsingShadowDecl &&) noexcept = default;
  ConstructorUsingShadowDecl &operator=(const ConstructorUsingShadowDecl &) = default;
  ConstructorUsingShadowDecl &operator=(ConstructorUsingShadowDecl &&) noexcept = default;

  bool ConstructsVirtualBase(void) const;
  ::pasta::CXXRecordDecl ConstructedBaseClass(void) const;
  ::pasta::ConstructorUsingShadowDecl ConstructedBaseClassShadowDecl(void) const;
  ::pasta::ConstructorUsingShadowDecl NominatedBaseClassShadowDecl(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
 private:
  ConstructorUsingShadowDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ConstructorUsingShadowDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ConstructorUsingShadowDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ConstructorUsingShadowDecl));

class DeclaratorDecl : public ValueDecl {
 public:
  ~DeclaratorDecl(void) = default;
  DeclaratorDecl(const DeclaratorDecl &) = default;
  DeclaratorDecl(DeclaratorDecl &&) noexcept = default;
  DeclaratorDecl &operator=(const DeclaratorDecl &) = default;
  DeclaratorDecl &operator=(DeclaratorDecl &&) noexcept = default;

  std::optional<::pasta::Token> BeginToken(void) const;
  std::optional<::pasta::Token> InnerLocStart(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  // Qualifier
  // QualifierToken
  // TemplateParameterList
  // TrailingRequiresClause
  // TypeSourceInfo
 private:
  DeclaratorDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit DeclaratorDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::DeclaratorDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(DeclaratorDecl));

class EnumConstantDecl : public ValueDecl {
 public:
  ~EnumConstantDecl(void) = default;
  EnumConstantDecl(const EnumConstantDecl &) = default;
  EnumConstantDecl(EnumConstantDecl &&) noexcept = default;
  EnumConstantDecl &operator=(const EnumConstantDecl &) = default;
  EnumConstantDecl &operator=(EnumConstantDecl &&) noexcept = default;

  ::pasta::EnumConstantDecl CanonicalDecl(void) const;
  // InitExpr
  // InitVal
 private:
  EnumConstantDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit EnumConstantDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::EnumConstantDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(EnumConstantDecl));

class FieldDecl : public DeclaratorDecl {
 public:
  ~FieldDecl(void) = default;
  FieldDecl(const FieldDecl &) = default;
  FieldDecl(FieldDecl &&) noexcept = default;
  FieldDecl &operator=(const FieldDecl &) = default;
  FieldDecl &operator=(FieldDecl &&) noexcept = default;

  // BitWidth
  ::pasta::FieldDecl CanonicalDecl(void) const;
  // CapturedVLAType
  InClassInitStyle InClassInitStyle(void) const;
  // InClassInitializer
  ::pasta::RecordDecl Parent(void) const;
  bool HasCapturedVLAType(void) const;
  bool HasInClassInitializer(void) const;
  bool IsBitField(void) const;
  bool IsMutable(void) const;
  bool IsUnnamedBitfield(void) const;
 private:
  FieldDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FieldDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::FieldDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FieldDecl));

class FunctionDecl : public DeclaratorDecl {
 public:
  ~FunctionDecl(void) = default;
  FunctionDecl(const FunctionDecl &) = default;
  FunctionDecl(FunctionDecl &&) noexcept = default;
  FunctionDecl &operator=(const FunctionDecl &) = default;
  FunctionDecl &operator=(FunctionDecl &&) noexcept = default;

  bool DoesThisDeclarationHaveABody(void) const;
  // AssociatedConstraints
  // Body
  // CallResultType
  ::pasta::FunctionDecl CanonicalDecl(void) const;
  ConstexprSpecKind ConstexprKind(void) const;
  // DeclaredReturnType
  ::pasta::FunctionDecl Definition(void) const;
  std::optional<::pasta::Token> EllipsisToken(void) const;
  ExceptionSpecificationType ExceptionSpecType(void) const;
  // NameInfo
  // ParamDecl
  // ReturnType
  StorageClass StorageClass(void) const;
  bool HasBody(void) const;
  bool HasImplicitReturnZero(void) const;
  bool HasInheritedPrototype(void) const;
  bool HasPrototype(void) const;
  bool HasSkippedBody(void) const;
  bool HasWrittenPrototype(void) const;
  bool InstantiationIsPending(void) const;
  bool IsConsteval(void) const;
  bool IsConstexpr(void) const;
  bool IsConstexprSpecified(void) const;
  bool IsDefaulted(void) const;
  bool IsDefined(void) const;
  bool IsDeleted(void) const;
  bool IsDeletedAsWritten(void) const;
  bool IsExplicitlyDefaulted(void) const;
  bool IsFunctionTemplateSpecialization(void) const;
  bool IsInlineSpecified(void) const;
  bool IsInlined(void) const;
  bool IsLateTemplateParsed(void) const;
  bool IsMultiVersion(void) const;
  bool IsOverloadedOperator(void) const;
  bool IsPure(void) const;
  bool IsStatic(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsTrivial(void) const;
  bool IsTrivialForCall(void) const;
  bool IsUserProvided(void) const;
  bool IsVirtualAsWritten(void) const;
  // Parameters
  bool UsesFPIntrin(void) const;
  bool UsesSEHTry(void) const;
  bool WillHaveBody(void) const;
 private:
  FunctionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FunctionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::FunctionDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FunctionDecl));

class IndirectFieldDecl : public ValueDecl {
 public:
  ~IndirectFieldDecl(void) = default;
  IndirectFieldDecl(const IndirectFieldDecl &) = default;
  IndirectFieldDecl(IndirectFieldDecl &&) noexcept = default;
  IndirectFieldDecl &operator=(const IndirectFieldDecl &) = default;
  IndirectFieldDecl &operator=(IndirectFieldDecl &&) noexcept = default;

  // Chain
  ::pasta::FieldDecl AnonField(void) const;
  ::pasta::IndirectFieldDecl CanonicalDecl(void) const;
  uint32_t ChainingSize(void) const;
  ::pasta::VarDecl VarDecl(void) const;
 private:
  IndirectFieldDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit IndirectFieldDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::IndirectFieldDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(IndirectFieldDecl));

class LabelDecl : public NamedDecl {
 public:
  ~LabelDecl(void) = default;
  LabelDecl(const LabelDecl &) = default;
  LabelDecl(LabelDecl &&) noexcept = default;
  LabelDecl &operator=(const LabelDecl &) = default;
  LabelDecl &operator=(LabelDecl &&) noexcept = default;

  std::string_view MSAsmLabel(void) const;
  // TokenRange
  // Stmt
  bool IsGnuLocal(void) const;
  bool IsMSAsmLabel(void) const;
  bool IsResolvedMSAsmLabel(void) const;
 private:
  LabelDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit LabelDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::LabelDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(LabelDecl));

class MSGuidDecl : public ValueDecl {
 public:
  ~MSGuidDecl(void) = default;
  MSGuidDecl(const MSGuidDecl &) = default;
  MSGuidDecl(MSGuidDecl &&) noexcept = default;
  MSGuidDecl &operator=(const MSGuidDecl &) = default;
  MSGuidDecl &operator=(MSGuidDecl &&) noexcept = default;

  // Parts
 private:
  MSGuidDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit MSGuidDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::MSGuidDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(MSGuidDecl));

class MSPropertyDecl : public DeclaratorDecl {
 public:
  ~MSPropertyDecl(void) = default;
  MSPropertyDecl(const MSPropertyDecl &) = default;
  MSPropertyDecl(MSPropertyDecl &&) noexcept = default;
  MSPropertyDecl &operator=(const MSPropertyDecl &) = default;
  MSPropertyDecl &operator=(MSPropertyDecl &&) noexcept = default;

  // GetterId
  // SetterId
  bool HasGetter(void) const;
  bool HasSetter(void) const;
 private:
  MSPropertyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit MSPropertyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::MSPropertyDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(MSPropertyDecl));

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 public:
  ~NonTypeTemplateParmDecl(void) = default;
  NonTypeTemplateParmDecl(const NonTypeTemplateParmDecl &) = default;
  NonTypeTemplateParmDecl(NonTypeTemplateParmDecl &&) noexcept = default;
  NonTypeTemplateParmDecl &operator=(const NonTypeTemplateParmDecl &) = default;
  NonTypeTemplateParmDecl &operator=(NonTypeTemplateParmDecl &&) noexcept = default;

  bool DefaultArgumentWasInherited(void) const;
  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionType
  // ExpansionTypeSourceInfo
  uint32_t NumExpansionTypes(void) const;
  // PlaceholderTypeConstraint
  bool HasDefaultArgument(void) const;
  bool HasPlaceholderTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 private:
  NonTypeTemplateParmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NonTypeTemplateParmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::NonTypeTemplateParmDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NonTypeTemplateParmDecl));

class OMPDeclareMapperDecl : public ValueDecl {
 public:
  ~OMPDeclareMapperDecl(void) = default;
  OMPDeclareMapperDecl(const OMPDeclareMapperDecl &) = default;
  OMPDeclareMapperDecl(OMPDeclareMapperDecl &&) noexcept = default;
  OMPDeclareMapperDecl &operator=(const OMPDeclareMapperDecl &) = default;
  OMPDeclareMapperDecl &operator=(OMPDeclareMapperDecl &&) noexcept = default;

  // Clauses
  // MapperVarRef
 private:
  OMPDeclareMapperDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPDeclareMapperDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::OMPDeclareMapperDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPDeclareMapperDecl));

class OMPDeclareReductionDecl : public ValueDecl {
 public:
  ~OMPDeclareReductionDecl(void) = default;
  OMPDeclareReductionDecl(const OMPDeclareReductionDecl &) = default;
  OMPDeclareReductionDecl(OMPDeclareReductionDecl &&) noexcept = default;
  OMPDeclareReductionDecl &operator=(const OMPDeclareReductionDecl &) = default;
  OMPDeclareReductionDecl &operator=(OMPDeclareReductionDecl &&) noexcept = default;

  // Combiner
  // CombinerIn
  // CombinerOut
  // InitOrig
  // InitPriv
  // Initializer
  // InitializerKind
 private:
  OMPDeclareReductionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPDeclareReductionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::OMPDeclareReductionDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPDeclareReductionDecl));

class ObjCAtDefsFieldDecl : public FieldDecl {
 public:
  ~ObjCAtDefsFieldDecl(void) = default;
  ObjCAtDefsFieldDecl(const ObjCAtDefsFieldDecl &) = default;
  ObjCAtDefsFieldDecl(ObjCAtDefsFieldDecl &&) noexcept = default;
  ObjCAtDefsFieldDecl &operator=(const ObjCAtDefsFieldDecl &) = default;
  ObjCAtDefsFieldDecl &operator=(ObjCAtDefsFieldDecl &&) noexcept = default;

 private:
  ObjCAtDefsFieldDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCAtDefsFieldDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCAtDefsFieldDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCAtDefsFieldDecl));

class ObjCCategoryDecl : public ObjCContainerDecl {
 public:
  ~ObjCCategoryDecl(void) = default;
  ObjCCategoryDecl(const ObjCCategoryDecl &) = default;
  ObjCCategoryDecl(ObjCCategoryDecl &&) noexcept = default;
  ObjCCategoryDecl &operator=(const ObjCCategoryDecl &) = default;
  ObjCCategoryDecl &operator=(ObjCCategoryDecl &&) noexcept = default;

  bool IsClassExtension(void) const;
  std::optional<::pasta::Token> CategoryNameToken(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  std::optional<::pasta::Token> IvarLBraceToken(void) const;
  std::optional<::pasta::Token> IvarRBraceToken(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategory(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategoryRaw(void) const;
  // ReferencedProtocols
  // TypeParamList
  // Ivars
  // Protocol_locs
  // Protocols
 private:
  ObjCCategoryDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCCategoryDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCCategoryDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCCategoryDecl));

class ObjCCategoryImplDecl : public ObjCImplDecl {
 public:
  ~ObjCCategoryImplDecl(void) = default;
  ObjCCategoryImplDecl(const ObjCCategoryImplDecl &) = default;
  ObjCCategoryImplDecl(ObjCCategoryImplDecl &&) noexcept = default;
  ObjCCategoryImplDecl &operator=(const ObjCCategoryImplDecl &) = default;
  ObjCCategoryImplDecl &operator=(ObjCCategoryImplDecl &&) noexcept = default;

  std::optional<::pasta::Token> CategoryNameToken(void) const;
 private:
  ObjCCategoryImplDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCCategoryImplDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCCategoryImplDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCCategoryImplDecl));

class ObjCIvarDecl : public FieldDecl {
 public:
  ~ObjCIvarDecl(void) = default;
  ObjCIvarDecl(const ObjCIvarDecl &) = default;
  ObjCIvarDecl(ObjCIvarDecl &&) noexcept = default;
  ObjCIvarDecl &operator=(const ObjCIvarDecl &) = default;
  ObjCIvarDecl &operator=(ObjCIvarDecl &&) noexcept = default;

  // AccessControl
  // CanonicalAccessControl
  ::pasta::ObjCIvarDecl NextIvar(void) const;
  bool Synthesize(void) const;
 private:
  ObjCIvarDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCIvarDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCIvarDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCIvarDecl));

class ObjCTypeParamDecl : public TypedefNameDecl {
 public:
  ~ObjCTypeParamDecl(void) = default;
  ObjCTypeParamDecl(const ObjCTypeParamDecl &) = default;
  ObjCTypeParamDecl(ObjCTypeParamDecl &&) noexcept = default;
  ObjCTypeParamDecl &operator=(const ObjCTypeParamDecl &) = default;
  ObjCTypeParamDecl &operator=(ObjCTypeParamDecl &&) noexcept = default;

  std::optional<::pasta::Token> ColonToken(void) const;
  uint32_t Index(void) const;
  ObjCTypeParamVariance Variance(void) const;
  std::optional<::pasta::Token> VarianceToken(void) const;
  bool HasExplicitBound(void) const;
 private:
  ObjCTypeParamDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCTypeParamDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ObjCTypeParamDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCTypeParamDecl));

class RedeclarableTemplateDecl : public TemplateDecl {
 public:
  ~RedeclarableTemplateDecl(void) = default;
  RedeclarableTemplateDecl(const RedeclarableTemplateDecl &) = default;
  RedeclarableTemplateDecl(RedeclarableTemplateDecl &&) noexcept = default;
  RedeclarableTemplateDecl &operator=(const RedeclarableTemplateDecl &) = default;
  RedeclarableTemplateDecl &operator=(RedeclarableTemplateDecl &&) noexcept = default;

  ::pasta::RedeclarableTemplateDecl CanonicalDecl(void) const;
  ::pasta::RedeclarableTemplateDecl InstantiatedFromMemberTemplate(void) const;
  bool IsMemberSpecialization(void) const;
 private:
  RedeclarableTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit RedeclarableTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::RedeclarableTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(RedeclarableTemplateDecl));

class TagDecl : public TypeDecl {
 public:
  ~TagDecl(void) = default;
  TagDecl(const TagDecl &) = default;
  TagDecl(TagDecl &&) noexcept = default;
  TagDecl &operator=(const TagDecl &) = default;
  TagDecl &operator=(TagDecl &&) noexcept = default;

  // BraceRange
  ::pasta::TagDecl CanonicalDecl(void) const;
  std::optional<::pasta::Token> InnerLocStart(void) const;
  std::string_view KindName(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  // Qualifier
  // QualifierToken
  TagTypeKind TagKind(void) const;
  // TemplateParameterList
  ::pasta::TypedefNameDecl TypedefNameForAnonDecl(void) const;
  bool HasNameForLinkage(void) const;
  bool IsBeingDefined(void) const;
  bool IsClass(void) const;
  bool IsCompleteDefinition(void) const;
  bool IsCompleteDefinitionRequired(void) const;
  bool IsDependentType(void) const;
  bool IsEmbeddedInDeclarator(void) const;
  bool IsEnum(void) const;
  bool IsFreeStanding(void) const;
  bool IsInterface(void) const;
  bool IsStruct(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsUnion(void) const;
  bool MayHaveOutOfDateDef(void) const;
 private:
  TagDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TagDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TagDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TagDecl));

class TemplateTypeParmDecl : public TypeDecl {
 public:
  ~TemplateTypeParmDecl(void) = default;
  TemplateTypeParmDecl(const TemplateTypeParmDecl &) = default;
  TemplateTypeParmDecl(TemplateTypeParmDecl &&) noexcept = default;
  TemplateTypeParmDecl &operator=(const TemplateTypeParmDecl &) = default;
  TemplateTypeParmDecl &operator=(TemplateTypeParmDecl &&) noexcept = default;

  bool DefaultArgumentWasInherited(void) const;
  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // DefaultArgumentInfo
  uint32_t NumExpansionParameters(void) const;
  // TypeConstraint
  bool HasDefaultArgument(void) const;
  bool HasTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool WasDeclaredWithTypename(void) const;
 private:
  TemplateTypeParmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateTypeParmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TemplateTypeParmDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateTypeParmDecl));

class TypeAliasDecl : public TypedefNameDecl {
 public:
  ~TypeAliasDecl(void) = default;
  TypeAliasDecl(const TypeAliasDecl &) = default;
  TypeAliasDecl(TypeAliasDecl &&) noexcept = default;
  TypeAliasDecl &operator=(const TypeAliasDecl &) = default;
  TypeAliasDecl &operator=(TypeAliasDecl &&) noexcept = default;

  ::pasta::TypeAliasTemplateDecl DescribedAliasTemplate(void) const;
 private:
  TypeAliasDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypeAliasDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TypeAliasDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypeAliasDecl));

class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~TypeAliasTemplateDecl(void) = default;
  TypeAliasTemplateDecl(const TypeAliasTemplateDecl &) = default;
  TypeAliasTemplateDecl(TypeAliasTemplateDecl &&) noexcept = default;
  TypeAliasTemplateDecl &operator=(const TypeAliasTemplateDecl &) = default;
  TypeAliasTemplateDecl &operator=(TypeAliasTemplateDecl &&) noexcept = default;

  ::pasta::TypeAliasTemplateDecl CanonicalDecl(void) const;
  ::pasta::TypeAliasTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::TypeAliasTemplateDecl PreviousDecl(void) const;
  ::pasta::TypeAliasDecl TemplatedDecl(void) const;
 private:
  TypeAliasTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypeAliasTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TypeAliasTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypeAliasTemplateDecl));

class TypedefDecl : public TypedefNameDecl {
 public:
  ~TypedefDecl(void) = default;
  TypedefDecl(const TypedefDecl &) = default;
  TypedefDecl(TypedefDecl &&) noexcept = default;
  TypedefDecl &operator=(const TypedefDecl &) = default;
  TypedefDecl &operator=(TypedefDecl &&) noexcept = default;

 private:
  TypedefDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypedefDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::TypedefDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypedefDecl));

class UnresolvedUsingValueDecl : public ValueDecl {
 public:
  ~UnresolvedUsingValueDecl(void) = default;
  UnresolvedUsingValueDecl(const UnresolvedUsingValueDecl &) = default;
  UnresolvedUsingValueDecl(UnresolvedUsingValueDecl &&) noexcept = default;
  UnresolvedUsingValueDecl &operator=(const UnresolvedUsingValueDecl &) = default;
  UnresolvedUsingValueDecl &operator=(UnresolvedUsingValueDecl &&) noexcept = default;

  ::pasta::UnresolvedUsingValueDecl CanonicalDecl(void) const;
  std::optional<::pasta::Token> EllipsisToken(void) const;
  // NameInfo
  // Qualifier
  // QualifierToken
  std::optional<::pasta::Token> UsingToken(void) const;
  bool IsAccessDeclaration(void) const;
  bool IsPackExpansion(void) const;
 private:
  UnresolvedUsingValueDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UnresolvedUsingValueDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::UnresolvedUsingValueDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingValueDecl));

class VarDecl : public DeclaratorDecl {
 public:
  ~VarDecl(void) = default;
  VarDecl(const VarDecl &) = default;
  VarDecl(VarDecl &&) noexcept = default;
  VarDecl &operator=(const VarDecl &) = default;
  VarDecl &operator=(VarDecl &&) noexcept = default;

  ::pasta::VarDecl ActingDefinition(void) const;
  // AnyInitializer
  ::pasta::VarDecl CanonicalDecl(void) const;
  // Init
  // InitStyle
  ::pasta::VarDecl InitializingDeclaration(void) const;
  StorageClass StorageClass(void) const;
  StorageDuration StorageDuration(void) const;
  ThreadStorageClassSpecifier TSCSpec(void) const;
  // HasDefinition
  bool HasExternalStorage(void) const;
  bool HasGlobalStorage(void) const;
  bool HasLocalStorage(void) const;
  bool IsARCPseudoStrong(void) const;
  bool IsCXXForRangeDecl(void) const;
  bool IsConstexpr(void) const;
  bool IsDirectInit(void) const;
  bool IsExceptionVariable(void) const;
  bool IsFileVarDecl(void) const;
  bool IsFunctionOrMethodVarDecl(void) const;
  bool IsInitCapture(void) const;
  bool IsInline(void) const;
  bool IsInlineSpecified(void) const;
  bool IsLocalVarDecl(void) const;
  bool IsLocalVarDeclOrParm(void) const;
  bool IsNRVOVariable(void) const;
  bool IsObjCForDecl(void) const;
  bool IsPreviousDeclInSameBlockScope(void) const;
  bool IsStaticDataMember(void) const;
  bool IsStaticLocal(void) const;
  // IsThisDeclarationADefinition
  bool IsThisDeclarationADemotedDefinition(void) const;
 private:
  VarDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::VarDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarDecl));

class VarTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~VarTemplateDecl(void) = default;
  VarTemplateDecl(const VarTemplateDecl &) = default;
  VarTemplateDecl(VarTemplateDecl &&) noexcept = default;
  VarTemplateDecl &operator=(const VarTemplateDecl &) = default;
  VarTemplateDecl &operator=(VarTemplateDecl &&) noexcept = default;

  ::pasta::VarTemplateDecl CanonicalDecl(void) const;
  ::pasta::VarTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::VarTemplateDecl MostRecentDecl(void) const;
  ::pasta::VarTemplateDecl PreviousDecl(void) const;
  ::pasta::VarDecl TemplatedDecl(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations
 private:
  VarTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::VarTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarTemplateDecl));

class VarTemplateSpecializationDecl : public VarDecl {
 public:
  ~VarTemplateSpecializationDecl(void) = default;
  VarTemplateSpecializationDecl(const VarTemplateSpecializationDecl &) = default;
  VarTemplateSpecializationDecl(VarTemplateSpecializationDecl &&) noexcept = default;
  VarTemplateSpecializationDecl &operator=(const VarTemplateSpecializationDecl &) = default;
  VarTemplateSpecializationDecl &operator=(VarTemplateSpecializationDecl &&) noexcept = default;

  // Profile
  std::optional<::pasta::Token> ExternToken(void) const;
  // InstantiatedFrom
  std::optional<::pasta::Token> PointOfInstantiation(void) const;
  TemplateSpecializationKind SpecializationKind(void) const;
  // SpecializedTemplateOrPartial
  // TemplateArgs
  // TemplateArgsInfo
  // TemplateInstantiationArgs
  std::optional<::pasta::Token> TemplateKeywordToken(void) const;
  // TypeAsWritten
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
 private:
  VarTemplateSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarTemplateSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::VarTemplateSpecializationDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarTemplateSpecializationDecl));

class CXXDeductionGuideDecl : public FunctionDecl {
 public:
  ~CXXDeductionGuideDecl(void) = default;
  CXXDeductionGuideDecl(const CXXDeductionGuideDecl &) = default;
  CXXDeductionGuideDecl(CXXDeductionGuideDecl &&) noexcept = default;
  CXXDeductionGuideDecl &operator=(const CXXDeductionGuideDecl &) = default;
  CXXDeductionGuideDecl &operator=(CXXDeductionGuideDecl &&) noexcept = default;

  ::pasta::TemplateDecl DeducedTemplate(void) const;
  // ExplicitSpecifier
  bool IsCopyDeductionCandidate(void) const;
  bool IsExplicit(void) const;
 private:
  CXXDeductionGuideDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXDeductionGuideDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CXXDeductionGuideDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXDeductionGuideDecl));

class CXXMethodDecl : public FunctionDecl {
 public:
  ~CXXMethodDecl(void) = default;
  CXXMethodDecl(const CXXMethodDecl &) = default;
  CXXMethodDecl(CXXMethodDecl &&) noexcept = default;
  CXXMethodDecl &operator=(const CXXMethodDecl &) = default;
  CXXMethodDecl &operator=(CXXMethodDecl &&) noexcept = default;

  ::pasta::CXXMethodDecl CanonicalDecl(void) const;
  // CorrespondingMethodDeclaredInClass
  // CorrespondingMethodInClass
  // DevirtualizedMethod
  // MethodQualifiers
  ::pasta::CXXMethodDecl MostRecentDecl(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
  RefQualifierKind RefQualifier(void) const;
  bool IsConst(void) const;
  bool IsInstance(void) const;
  bool IsVirtual(void) const;
  bool IsVolatile(void) const;
 private:
  CXXMethodDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXMethodDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CXXMethodDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXMethodDecl));

class ClassTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~ClassTemplateDecl(void) = default;
  ClassTemplateDecl(const ClassTemplateDecl &) = default;
  ClassTemplateDecl(ClassTemplateDecl &&) noexcept = default;
  ClassTemplateDecl &operator=(const ClassTemplateDecl &) = default;
  ClassTemplateDecl &operator=(ClassTemplateDecl &&) noexcept = default;

  ::pasta::ClassTemplateDecl CanonicalDecl(void) const;
  ::pasta::ClassTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::ClassTemplateDecl MostRecentDecl(void) const;
  ::pasta::ClassTemplateDecl PreviousDecl(void) const;
  ::pasta::CXXRecordDecl TemplatedDecl(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations
 private:
  ClassTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ClassTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassTemplateDecl));

class DecompositionDecl : public VarDecl {
 public:
  ~DecompositionDecl(void) = default;
  DecompositionDecl(const DecompositionDecl &) = default;
  DecompositionDecl(DecompositionDecl &&) noexcept = default;
  DecompositionDecl &operator=(const DecompositionDecl &) = default;
  DecompositionDecl &operator=(DecompositionDecl &&) noexcept = default;

  // Bindings
 private:
  DecompositionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit DecompositionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::DecompositionDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(DecompositionDecl));

class EnumDecl : public TagDecl {
 public:
  ~EnumDecl(void) = default;
  EnumDecl(const EnumDecl &) = default;
  EnumDecl(EnumDecl &&) noexcept = default;
  EnumDecl &operator=(const EnumDecl &) = default;
  EnumDecl &operator=(EnumDecl &&) noexcept = default;

  // Enumerators
  ::pasta::EnumDecl CanonicalDecl(void) const;
  ::pasta::EnumDecl Definition(void) const;
  // IntegerType
  // IntegerTypeSourceInfo
  // MemberSpecializationInfo
  ::pasta::EnumDecl MostRecentDecl(void) const;
  uint32_t NumNegativeBits(void) const;
  uint32_t NumPositiveBits(void) const;
  ::pasta::EnumDecl PreviousDecl(void) const;
  // PromotionType
  bool IsComplete(void) const;
  bool IsFixed(void) const;
  bool IsScoped(void) const;
  bool IsScopedUsingClassTag(void) const;
 private:
  EnumDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit EnumDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::EnumDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(EnumDecl));

class FunctionTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~FunctionTemplateDecl(void) = default;
  FunctionTemplateDecl(const FunctionTemplateDecl &) = default;
  FunctionTemplateDecl(FunctionTemplateDecl &&) noexcept = default;
  FunctionTemplateDecl &operator=(const FunctionTemplateDecl &) = default;
  FunctionTemplateDecl &operator=(FunctionTemplateDecl &&) noexcept = default;

  ::pasta::FunctionTemplateDecl CanonicalDecl(void) const;
  ::pasta::FunctionTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::FunctionTemplateDecl MostRecentDecl(void) const;
  ::pasta::FunctionTemplateDecl PreviousDecl(void) const;
  ::pasta::FunctionDecl TemplatedDecl(void) const;
  bool IsAbbreviated(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations
 private:
  FunctionTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FunctionTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::FunctionTemplateDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FunctionTemplateDecl));

class ImplicitParamDecl : public VarDecl {
 public:
  ~ImplicitParamDecl(void) = default;
  ImplicitParamDecl(const ImplicitParamDecl &) = default;
  ImplicitParamDecl(ImplicitParamDecl &&) noexcept = default;
  ImplicitParamDecl &operator=(const ImplicitParamDecl &) = default;
  ImplicitParamDecl &operator=(ImplicitParamDecl &&) noexcept = default;

  // ParameterKind
 private:
  ImplicitParamDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ImplicitParamDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ImplicitParamDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ImplicitParamDecl));

class OMPCapturedExprDecl : public VarDecl {
 public:
  ~OMPCapturedExprDecl(void) = default;
  OMPCapturedExprDecl(const OMPCapturedExprDecl &) = default;
  OMPCapturedExprDecl(OMPCapturedExprDecl &&) noexcept = default;
  OMPCapturedExprDecl &operator=(const OMPCapturedExprDecl &) = default;
  OMPCapturedExprDecl &operator=(OMPCapturedExprDecl &&) noexcept = default;

 private:
  OMPCapturedExprDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPCapturedExprDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::OMPCapturedExprDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPCapturedExprDecl));

class ParmVarDecl : public VarDecl {
 public:
  ~ParmVarDecl(void) = default;
  ParmVarDecl(const ParmVarDecl &) = default;
  ParmVarDecl(ParmVarDecl &&) noexcept = default;
  ParmVarDecl &operator=(const ParmVarDecl &) = default;
  ParmVarDecl &operator=(ParmVarDecl &&) noexcept = default;

  // DefaultArg
  uint32_t FunctionScopeDepth(void) const;
  uint32_t FunctionScopeIndex(void) const;
  // ObjCDeclQualifier
  // UninstantiatedDefaultArg
  bool HasInheritedDefaultArg(void) const;
  bool HasUninstantiatedDefaultArg(void) const;
  bool HasUnparsedDefaultArg(void) const;
  bool IsKNRPromoted(void) const;
  bool IsObjCMethodParameter(void) const;
 private:
  ParmVarDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ParmVarDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ParmVarDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ParmVarDecl));

class RecordDecl : public TagDecl {
 public:
  ~RecordDecl(void) = default;
  RecordDecl(const RecordDecl &) = default;
  RecordDecl(RecordDecl &&) noexcept = default;
  RecordDecl &operator=(const RecordDecl &) = default;
  RecordDecl &operator=(RecordDecl &&) noexcept = default;

  bool CanPassInRegisters(void) const;
  // Fields
  // ArgPassingRestrictions
  ::pasta::RecordDecl Definition(void) const;
  ::pasta::RecordDecl MostRecentDecl(void) const;
  ::pasta::RecordDecl PreviousDecl(void) const;
  bool HasFlexibleArrayMember(void) const;
  bool HasLoadedFieldsFromExternalStorage(void) const;
  bool HasNonTrivialToPrimitiveCopyCUnion(void) const;
  bool HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const;
  bool HasNonTrivialToPrimitiveDestructCUnion(void) const;
  bool HasObjectMember(void) const;
  bool HasVolatileMember(void) const;
  bool IsAnonymousStructOrUnion(void) const;
  bool IsNonTrivialToPrimitiveCopy(void) const;
  bool IsNonTrivialToPrimitiveDefaultInitialize(void) const;
  bool IsNonTrivialToPrimitiveDestroy(void) const;
  bool IsParamDestroyedInCallee(void) const;
 private:
  RecordDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit RecordDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::RecordDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(RecordDecl));

class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 public:
  ~VarTemplatePartialSpecializationDecl(void) = default;
  VarTemplatePartialSpecializationDecl(const VarTemplatePartialSpecializationDecl &) = default;
  VarTemplatePartialSpecializationDecl(VarTemplatePartialSpecializationDecl &&) noexcept = default;
  VarTemplatePartialSpecializationDecl &operator=(const VarTemplatePartialSpecializationDecl &) = default;
  VarTemplatePartialSpecializationDecl &operator=(VarTemplatePartialSpecializationDecl &&) noexcept = default;

  // Profile
  // AssociatedConstraints
  ::pasta::VarTemplatePartialSpecializationDecl InstantiatedFromMember(void) const;
  // TemplateArgsAsWritten
  // TemplateParameters
  bool HasAssociatedConstraints(void) const;
 private:
  VarTemplatePartialSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarTemplatePartialSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::VarTemplatePartialSpecializationDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarTemplatePartialSpecializationDecl));

class CXXConstructorDecl : public CXXMethodDecl {
 public:
  ~CXXConstructorDecl(void) = default;
  CXXConstructorDecl(const CXXConstructorDecl &) = default;
  CXXConstructorDecl(CXXConstructorDecl &&) noexcept = default;
  CXXConstructorDecl &operator=(const CXXConstructorDecl &) = default;
  CXXConstructorDecl &operator=(CXXConstructorDecl &&) noexcept = default;

  ::pasta::CXXConstructorDecl CanonicalDecl(void) const;
  // ExplicitSpecifier
  // InheritedConstructor
  uint32_t NumCtorInitializers(void) const;
  // Inits
  bool IsCopyConstructor(void) const;
  bool IsCopyOrMoveConstructor(void) const;
  bool IsDelegatingConstructor(void) const;
  bool IsExplicit(void) const;
  bool IsInheritingConstructor(void) const;
  bool IsMoveConstructor(void) const;
 private:
  CXXConstructorDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXConstructorDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CXXConstructorDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXConstructorDecl));

class CXXConversionDecl : public CXXMethodDecl {
 public:
  ~CXXConversionDecl(void) = default;
  CXXConversionDecl(const CXXConversionDecl &) = default;
  CXXConversionDecl(CXXConversionDecl &&) noexcept = default;
  CXXConversionDecl &operator=(const CXXConversionDecl &) = default;
  CXXConversionDecl &operator=(CXXConversionDecl &&) noexcept = default;

  ::pasta::CXXConversionDecl CanonicalDecl(void) const;
  // ConversionType
  // ExplicitSpecifier
  bool IsExplicit(void) const;
 private:
  CXXConversionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXConversionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CXXConversionDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXConversionDecl));

class CXXDestructorDecl : public CXXMethodDecl {
 public:
  ~CXXDestructorDecl(void) = default;
  CXXDestructorDecl(const CXXDestructorDecl &) = default;
  CXXDestructorDecl(CXXDestructorDecl &&) noexcept = default;
  CXXDestructorDecl &operator=(const CXXDestructorDecl &) = default;
  CXXDestructorDecl &operator=(CXXDestructorDecl &&) noexcept = default;

  ::pasta::CXXDestructorDecl CanonicalDecl(void) const;
  ::pasta::FunctionDecl OperatorDelete(void) const;
  // OperatorDeleteThisArg
 private:
  CXXDestructorDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXDestructorDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CXXDestructorDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXDestructorDecl));

class CXXRecordDecl : public RecordDecl {
 public:
  ~CXXRecordDecl(void) = default;
  CXXRecordDecl(const CXXRecordDecl &) = default;
  CXXRecordDecl(CXXRecordDecl &&) noexcept = default;
  CXXRecordDecl &operator=(const CXXRecordDecl &) = default;
  CXXRecordDecl &operator=(CXXRecordDecl &&) noexcept = default;

  bool AllowConstDefaultInit(void) const;
  // Bases
  // Captures
  // Constructors
  bool DefaultedCopyConstructorIsDeleted(void) const;
  bool DefaultedDefaultConstructorIsConstexpr(void) const;
  bool DefaultedDestructorIsConstexpr(void) const;
  bool DefaultedDestructorIsDeleted(void) const;
  bool DefaultedMoveConstructorIsDeleted(void) const;
  // Friends
  ::pasta::CXXRecordDecl CanonicalDecl(void) const;
  ::pasta::CXXRecordDecl Definition(void) const;
  LambdaCaptureDefault LambdaCaptureDefault(void) const;
  uint32_t LambdaManglingNumber(void) const;
  // LambdaTypeInfo
  ::pasta::CXXRecordDecl MostRecentDecl(void) const;
  ::pasta::CXXRecordDecl MostRecentNonInjectedDecl(void) const;
  uint32_t NumBases(void) const;
  uint32_t NumVBases(void) const;
  ::pasta::CXXRecordDecl PreviousDecl(void) const;
  bool HasConstexprDefaultConstructor(void) const;
  bool HasConstexprNonCopyMoveConstructor(void) const;
  bool HasCopyAssignmentWithConstParam(void) const;
  bool HasCopyConstructorWithConstParam(void) const;
  bool HasDefaultConstructor(void) const;
  bool HasDefinition(void) const;
  bool HasDirectFields(void) const;
  bool HasFriends(void) const;
  bool HasInClassInitializer(void) const;
  bool HasInheritedAssignment(void) const;
  bool HasInheritedConstructor(void) const;
  bool HasIrrelevantDestructor(void) const;
  bool HasKnownLambdaInternalLinkage(void) const;
  bool HasMoveAssignment(void) const;
  bool HasMoveConstructor(void) const;
  bool HasMutableFields(void) const;
  bool HasNonLiteralTypeFieldsOrBases(void) const;
  bool HasNonTrivialCopyAssignment(void) const;
  bool HasNonTrivialCopyConstructor(void) const;
  bool HasNonTrivialCopyConstructorForCall(void) const;
  bool HasNonTrivialDefaultConstructor(void) const;
  bool HasNonTrivialDestructor(void) const;
  bool HasNonTrivialDestructorForCall(void) const;
  bool HasNonTrivialMoveAssignment(void) const;
  bool HasNonTrivialMoveConstructor(void) const;
  bool HasNonTrivialMoveConstructorForCall(void) const;
  bool HasPrivateFields(void) const;
  bool HasProtectedFields(void) const;
  bool HasSimpleCopyAssignment(void) const;
  bool HasSimpleCopyConstructor(void) const;
  bool HasSimpleDestructor(void) const;
  bool HasSimpleMoveAssignment(void) const;
  bool HasSimpleMoveConstructor(void) const;
  bool HasTrivialCopyAssignment(void) const;
  bool HasTrivialCopyConstructor(void) const;
  bool HasTrivialCopyConstructorForCall(void) const;
  bool HasTrivialDefaultConstructor(void) const;
  bool HasTrivialDestructor(void) const;
  bool HasTrivialDestructorForCall(void) const;
  bool HasTrivialMoveAssignment(void) const;
  bool HasTrivialMoveConstructor(void) const;
  bool HasTrivialMoveConstructorForCall(void) const;
  bool HasUninitializedReferenceMember(void) const;
  bool HasUserDeclaredConstructor(void) const;
  bool HasUserDeclaredCopyAssignment(void) const;
  bool HasUserDeclaredCopyConstructor(void) const;
  bool HasUserDeclaredDestructor(void) const;
  bool HasUserDeclaredMoveAssignment(void) const;
  bool HasUserDeclaredMoveConstructor(void) const;
  bool HasUserDeclaredMoveOperation(void) const;
  bool HasUserProvidedDefaultConstructor(void) const;
  bool HasVariantMembers(void) const;
  bool ImplicitCopyAssignmentHasConstParam(void) const;
  bool ImplicitCopyConstructorHasConstParam(void) const;
  bool IsAbstract(void) const;
  bool IsAggregate(void) const;
  bool IsCXX11StandardLayout(void) const;
  bool IsDependentLambda(void) const;
  bool IsDynamicClass(void) const;
  bool IsEmpty(void) const;
  bool IsLambda(void) const;
  bool IsLiteral(void) const;
  ::pasta::FunctionDecl IsLocalClass(void) const;
  bool IsPOD(void) const;
  bool IsParsingBaseSpecifiers(void) const;
  bool IsPolymorphic(void) const;
  bool IsStandardLayout(void) const;
  bool IsTrivial(void) const;
  bool MayBeDynamicClass(void) const;
  bool MayBeNonDynamicClass(void) const;
  // Methods
  bool NeedsImplicitCopyAssignment(void) const;
  bool NeedsImplicitCopyConstructor(void) const;
  bool NeedsImplicitDefaultConstructor(void) const;
  bool NeedsImplicitDestructor(void) const;
  bool NeedsImplicitMoveAssignment(void) const;
  bool NeedsImplicitMoveConstructor(void) const;
  bool NeedsOverloadResolutionForCopyAssignment(void) const;
  bool NeedsOverloadResolutionForCopyConstructor(void) const;
  bool NeedsOverloadResolutionForDestructor(void) const;
  bool NeedsOverloadResolutionForMoveAssignment(void) const;
  bool NeedsOverloadResolutionForMoveConstructor(void) const;
  // VirtualBases
 private:
  CXXRecordDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXRecordDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::CXXRecordDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXRecordDecl));

class ClassTemplateSpecializationDecl : public CXXRecordDecl {
 public:
  ~ClassTemplateSpecializationDecl(void) = default;
  ClassTemplateSpecializationDecl(const ClassTemplateSpecializationDecl &) = default;
  ClassTemplateSpecializationDecl(ClassTemplateSpecializationDecl &&) noexcept = default;
  ClassTemplateSpecializationDecl &operator=(const ClassTemplateSpecializationDecl &) = default;
  ClassTemplateSpecializationDecl &operator=(ClassTemplateSpecializationDecl &&) noexcept = default;

  // Profile
  std::optional<::pasta::Token> ExternToken(void) const;
  // InstantiatedFrom
  std::optional<::pasta::Token> PointOfInstantiation(void) const;
  TemplateSpecializationKind SpecializationKind(void) const;
  // SpecializedTemplateOrPartial
  // TemplateArgs
  // TemplateInstantiationArgs
  std::optional<::pasta::Token> TemplateKeywordToken(void) const;
  // TypeAsWritten
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
 private:
  ClassTemplateSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassTemplateSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ClassTemplateSpecializationDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassTemplateSpecializationDecl));

class ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 public:
  ~ClassTemplatePartialSpecializationDecl(void) = default;
  ClassTemplatePartialSpecializationDecl(const ClassTemplatePartialSpecializationDecl &) = default;
  ClassTemplatePartialSpecializationDecl(ClassTemplatePartialSpecializationDecl &&) noexcept = default;
  ClassTemplatePartialSpecializationDecl &operator=(const ClassTemplatePartialSpecializationDecl &) = default;
  ClassTemplatePartialSpecializationDecl &operator=(ClassTemplatePartialSpecializationDecl &&) noexcept = default;

  // Profile
  // AssociatedConstraints
  // InjectedSpecializationType
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMember(void) const;
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMemberTemplate(void) const;
  // TemplateArgsAsWritten
  // TemplateParameters
  bool HasAssociatedConstraints(void) const;
 private:
  ClassTemplatePartialSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassTemplatePartialSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::ClassTemplatePartialSpecializationDecl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassTemplatePartialSpecializationDecl));

}  // namespace pasta
