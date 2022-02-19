/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#ifdef PASTA_IN_BOOTSTRAP
#  include "StmtBootstrap.h"
#else
#include <variant>
#include <vector>
#include <pasta/Util/Compiler.h>
#include "Forward.h"

#include "StmtManual.h"

#define PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(base) \
    friend class AST; \
    friend class ASTImpl; \
    friend class StmtBuilder; \
    friend class StmtVisitor; \
    friend class PrintedTokenRange; \
    base(void) = delete; \
    explicit base( \
        std::shared_ptr<ASTImpl> ast_, \
        const ::clang::Stmt *decl_); \
   public: \
    const clang::base *RawStmt(void) const noexcept { \
      return u.base; \
    }

namespace pasta {
class StmtVisitor {
 public:
  virtual ~StmtVisitor(void);
  void Accept(const Stmt &);
  virtual void VisitStmt(const Stmt &);
  virtual void VisitSwitchCase(const SwitchCase &);
  virtual void VisitSwitchStmt(const SwitchStmt &);
  virtual void VisitValueStmt(const ValueStmt &);
  virtual void VisitWhileStmt(const WhileStmt &);
  virtual void VisitAsmStmt(const AsmStmt &);
  virtual void VisitAttributedStmt(const AttributedStmt &);
  virtual void VisitBreakStmt(const BreakStmt &);
  virtual void VisitCXXCatchStmt(const CXXCatchStmt &);
  virtual void VisitCXXForRangeStmt(const CXXForRangeStmt &);
  virtual void VisitCXXTryStmt(const CXXTryStmt &);
  virtual void VisitCapturedStmt(const CapturedStmt &);
  virtual void VisitCaseStmt(const CaseStmt &);
  virtual void VisitCompoundStmt(const CompoundStmt &);
  virtual void VisitContinueStmt(const ContinueStmt &);
  virtual void VisitCoreturnStmt(const CoreturnStmt &);
  virtual void VisitCoroutineBodyStmt(const CoroutineBodyStmt &);
  virtual void VisitDeclStmt(const DeclStmt &);
  virtual void VisitDefaultStmt(const DefaultStmt &);
  virtual void VisitDoStmt(const DoStmt &);
  virtual void VisitExpr(const Expr &);
  virtual void VisitExpressionTraitExpr(const ExpressionTraitExpr &);
  virtual void VisitExtVectorElementExpr(const ExtVectorElementExpr &);
  virtual void VisitFixedPointLiteral(const FixedPointLiteral &);
  virtual void VisitFloatingLiteral(const FloatingLiteral &);
  virtual void VisitForStmt(const ForStmt &);
  virtual void VisitFullExpr(const FullExpr &);
  virtual void VisitFunctionParmPackExpr(const FunctionParmPackExpr &);
  virtual void VisitGCCAsmStmt(const GCCAsmStmt &);
  virtual void VisitGNUNullExpr(const GNUNullExpr &);
  virtual void VisitGenericSelectionExpr(const GenericSelectionExpr &);
  virtual void VisitGotoStmt(const GotoStmt &);
  virtual void VisitIfStmt(const IfStmt &);
  virtual void VisitImaginaryLiteral(const ImaginaryLiteral &);
  virtual void VisitImplicitValueInitExpr(const ImplicitValueInitExpr &);
  virtual void VisitIndirectGotoStmt(const IndirectGotoStmt &);
  virtual void VisitInitListExpr(const InitListExpr &);
  virtual void VisitIntegerLiteral(const IntegerLiteral &);
  virtual void VisitLabelStmt(const LabelStmt &);
  virtual void VisitLambdaExpr(const LambdaExpr &);
  virtual void VisitMSAsmStmt(const MSAsmStmt &);
  virtual void VisitMSDependentExistsStmt(const MSDependentExistsStmt &);
  virtual void VisitMSPropertyRefExpr(const MSPropertyRefExpr &);
  virtual void VisitMSPropertySubscriptExpr(const MSPropertySubscriptExpr &);
  virtual void VisitMaterializeTemporaryExpr(const MaterializeTemporaryExpr &);
  virtual void VisitMatrixSubscriptExpr(const MatrixSubscriptExpr &);
  virtual void VisitMemberExpr(const MemberExpr &);
  virtual void VisitNoInitExpr(const NoInitExpr &);
  virtual void VisitNullStmt(const NullStmt &);
  virtual void VisitOMPArraySectionExpr(const OMPArraySectionExpr &);
  virtual void VisitOMPArrayShapingExpr(const OMPArrayShapingExpr &);
  virtual void VisitOMPCanonicalLoop(const OMPCanonicalLoop &);
  virtual void VisitOMPExecutableDirective(const OMPExecutableDirective &);
  virtual void VisitOMPFlushDirective(const OMPFlushDirective &);
  virtual void VisitOMPInteropDirective(const OMPInteropDirective &);
  virtual void VisitOMPIteratorExpr(const OMPIteratorExpr &);
  virtual void VisitOMPLoopBasedDirective(const OMPLoopBasedDirective &);
  virtual void VisitOMPLoopDirective(const OMPLoopDirective &);
  virtual void VisitOMPMaskedDirective(const OMPMaskedDirective &);
  virtual void VisitOMPMasterDirective(const OMPMasterDirective &);
  virtual void VisitOMPMasterTaskLoopDirective(const OMPMasterTaskLoopDirective &);
  virtual void VisitOMPMasterTaskLoopSimdDirective(const OMPMasterTaskLoopSimdDirective &);
  virtual void VisitOMPOrderedDirective(const OMPOrderedDirective &);
  virtual void VisitOMPParallelDirective(const OMPParallelDirective &);
  virtual void VisitOMPParallelForDirective(const OMPParallelForDirective &);
  virtual void VisitOMPParallelForSimdDirective(const OMPParallelForSimdDirective &);
  virtual void VisitOMPParallelMasterDirective(const OMPParallelMasterDirective &);
  virtual void VisitOMPParallelMasterTaskLoopDirective(const OMPParallelMasterTaskLoopDirective &);
  virtual void VisitOMPParallelMasterTaskLoopSimdDirective(const OMPParallelMasterTaskLoopSimdDirective &);
  virtual void VisitOMPParallelSectionsDirective(const OMPParallelSectionsDirective &);
  virtual void VisitOMPScanDirective(const OMPScanDirective &);
  virtual void VisitOMPSectionDirective(const OMPSectionDirective &);
  virtual void VisitOMPSectionsDirective(const OMPSectionsDirective &);
  virtual void VisitOMPSimdDirective(const OMPSimdDirective &);
  virtual void VisitOMPSingleDirective(const OMPSingleDirective &);
  virtual void VisitOMPTargetDataDirective(const OMPTargetDataDirective &);
  virtual void VisitOMPTargetDirective(const OMPTargetDirective &);
  virtual void VisitOMPTargetEnterDataDirective(const OMPTargetEnterDataDirective &);
  virtual void VisitOMPTargetExitDataDirective(const OMPTargetExitDataDirective &);
  virtual void VisitOMPTargetParallelDirective(const OMPTargetParallelDirective &);
  virtual void VisitOMPTargetParallelForDirective(const OMPTargetParallelForDirective &);
  virtual void VisitOMPTargetParallelForSimdDirective(const OMPTargetParallelForSimdDirective &);
  virtual void VisitOMPTargetSimdDirective(const OMPTargetSimdDirective &);
  virtual void VisitOMPTargetTeamsDirective(const OMPTargetTeamsDirective &);
  virtual void VisitOMPTargetTeamsDistributeDirective(const OMPTargetTeamsDistributeDirective &);
  virtual void VisitOMPTargetTeamsDistributeParallelForDirective(const OMPTargetTeamsDistributeParallelForDirective &);
  virtual void VisitOMPTargetTeamsDistributeParallelForSimdDirective(const OMPTargetTeamsDistributeParallelForSimdDirective &);
  virtual void VisitOMPTargetTeamsDistributeSimdDirective(const OMPTargetTeamsDistributeSimdDirective &);
  virtual void VisitOMPTargetUpdateDirective(const OMPTargetUpdateDirective &);
  virtual void VisitOMPTaskDirective(const OMPTaskDirective &);
  virtual void VisitOMPTaskLoopDirective(const OMPTaskLoopDirective &);
  virtual void VisitOMPTaskLoopSimdDirective(const OMPTaskLoopSimdDirective &);
  virtual void VisitOMPTaskgroupDirective(const OMPTaskgroupDirective &);
  virtual void VisitOMPTaskwaitDirective(const OMPTaskwaitDirective &);
  virtual void VisitOMPTaskyieldDirective(const OMPTaskyieldDirective &);
  virtual void VisitOMPTeamsDirective(const OMPTeamsDirective &);
  virtual void VisitOMPTeamsDistributeDirective(const OMPTeamsDistributeDirective &);
  virtual void VisitOMPTeamsDistributeParallelForDirective(const OMPTeamsDistributeParallelForDirective &);
  virtual void VisitOMPTeamsDistributeParallelForSimdDirective(const OMPTeamsDistributeParallelForSimdDirective &);
  virtual void VisitOMPTeamsDistributeSimdDirective(const OMPTeamsDistributeSimdDirective &);
  virtual void VisitOMPTileDirective(const OMPTileDirective &);
  virtual void VisitOMPUnrollDirective(const OMPUnrollDirective &);
  virtual void VisitObjCArrayLiteral(const ObjCArrayLiteral &);
  virtual void VisitObjCAtCatchStmt(const ObjCAtCatchStmt &);
  virtual void VisitObjCAtFinallyStmt(const ObjCAtFinallyStmt &);
  virtual void VisitObjCAtSynchronizedStmt(const ObjCAtSynchronizedStmt &);
  virtual void VisitObjCAtThrowStmt(const ObjCAtThrowStmt &);
  virtual void VisitObjCAtTryStmt(const ObjCAtTryStmt &);
  virtual void VisitObjCAutoreleasePoolStmt(const ObjCAutoreleasePoolStmt &);
  virtual void VisitObjCAvailabilityCheckExpr(const ObjCAvailabilityCheckExpr &);
  virtual void VisitObjCBoolLiteralExpr(const ObjCBoolLiteralExpr &);
  virtual void VisitObjCBoxedExpr(const ObjCBoxedExpr &);
  virtual void VisitObjCDictionaryLiteral(const ObjCDictionaryLiteral &);
  virtual void VisitObjCEncodeExpr(const ObjCEncodeExpr &);
  virtual void VisitObjCForCollectionStmt(const ObjCForCollectionStmt &);
  virtual void VisitObjCIndirectCopyRestoreExpr(const ObjCIndirectCopyRestoreExpr &);
  virtual void VisitObjCIsaExpr(const ObjCIsaExpr &);
  virtual void VisitObjCIvarRefExpr(const ObjCIvarRefExpr &);
  virtual void VisitObjCMessageExpr(const ObjCMessageExpr &);
  virtual void VisitObjCPropertyRefExpr(const ObjCPropertyRefExpr &);
  virtual void VisitObjCProtocolExpr(const ObjCProtocolExpr &);
  virtual void VisitObjCSelectorExpr(const ObjCSelectorExpr &);
  virtual void VisitObjCStringLiteral(const ObjCStringLiteral &);
  virtual void VisitObjCSubscriptRefExpr(const ObjCSubscriptRefExpr &);
  virtual void VisitOffsetOfExpr(const OffsetOfExpr &);
  virtual void VisitOpaqueValueExpr(const OpaqueValueExpr &);
  virtual void VisitOverloadExpr(const OverloadExpr &);
  virtual void VisitPackExpansionExpr(const PackExpansionExpr &);
  virtual void VisitParenExpr(const ParenExpr &);
  virtual void VisitParenListExpr(const ParenListExpr &);
  virtual void VisitPredefinedExpr(const PredefinedExpr &);
  virtual void VisitPseudoObjectExpr(const PseudoObjectExpr &);
  virtual void VisitRecoveryExpr(const RecoveryExpr &);
  virtual void VisitRequiresExpr(const RequiresExpr &);
  virtual void VisitReturnStmt(const ReturnStmt &);
  virtual void VisitSEHExceptStmt(const SEHExceptStmt &);
  virtual void VisitSEHFinallyStmt(const SEHFinallyStmt &);
  virtual void VisitSEHLeaveStmt(const SEHLeaveStmt &);
  virtual void VisitSEHTryStmt(const SEHTryStmt &);
  virtual void VisitSYCLUniqueStableNameExpr(const SYCLUniqueStableNameExpr &);
  virtual void VisitShuffleVectorExpr(const ShuffleVectorExpr &);
  virtual void VisitSizeOfPackExpr(const SizeOfPackExpr &);
  virtual void VisitSourceLocExpr(const SourceLocExpr &);
  virtual void VisitStmtExpr(const StmtExpr &);
  virtual void VisitStringLiteral(const StringLiteral &);
  virtual void VisitSubstNonTypeTemplateParmExpr(const SubstNonTypeTemplateParmExpr &);
  virtual void VisitSubstNonTypeTemplateParmPackExpr(const SubstNonTypeTemplateParmPackExpr &);
  virtual void VisitTypeTraitExpr(const TypeTraitExpr &);
  virtual void VisitTypoExpr(const TypoExpr &);
  virtual void VisitUnaryExprOrTypeTraitExpr(const UnaryExprOrTypeTraitExpr &);
  virtual void VisitUnaryOperator(const UnaryOperator &);
  virtual void VisitUnresolvedLookupExpr(const UnresolvedLookupExpr &);
  virtual void VisitUnresolvedMemberExpr(const UnresolvedMemberExpr &);
  virtual void VisitVAArgExpr(const VAArgExpr &);
  virtual void VisitAbstractConditionalOperator(const AbstractConditionalOperator &);
  virtual void VisitAddrLabelExpr(const AddrLabelExpr &);
  virtual void VisitArrayInitIndexExpr(const ArrayInitIndexExpr &);
  virtual void VisitArrayInitLoopExpr(const ArrayInitLoopExpr &);
  virtual void VisitArraySubscriptExpr(const ArraySubscriptExpr &);
  virtual void VisitArrayTypeTraitExpr(const ArrayTypeTraitExpr &);
  virtual void VisitAsTypeExpr(const AsTypeExpr &);
  virtual void VisitAtomicExpr(const AtomicExpr &);
  virtual void VisitBinaryConditionalOperator(const BinaryConditionalOperator &);
  virtual void VisitBinaryOperator(const BinaryOperator &);
  virtual void VisitBlockExpr(const BlockExpr &);
  virtual void VisitCXXBindTemporaryExpr(const CXXBindTemporaryExpr &);
  virtual void VisitCXXBoolLiteralExpr(const CXXBoolLiteralExpr &);
  virtual void VisitCXXConstructExpr(const CXXConstructExpr &);
  virtual void VisitCXXDefaultArgExpr(const CXXDefaultArgExpr &);
  virtual void VisitCXXDefaultInitExpr(const CXXDefaultInitExpr &);
  virtual void VisitCXXDeleteExpr(const CXXDeleteExpr &);
  virtual void VisitCXXDependentScopeMemberExpr(const CXXDependentScopeMemberExpr &);
  virtual void VisitCXXFoldExpr(const CXXFoldExpr &);
  virtual void VisitCXXInheritedCtorInitExpr(const CXXInheritedCtorInitExpr &);
  virtual void VisitCXXNewExpr(const CXXNewExpr &);
  virtual void VisitCXXNoexceptExpr(const CXXNoexceptExpr &);
  virtual void VisitCXXNullPtrLiteralExpr(const CXXNullPtrLiteralExpr &);
  virtual void VisitCXXPseudoDestructorExpr(const CXXPseudoDestructorExpr &);
  virtual void VisitCXXRewrittenBinaryOperator(const CXXRewrittenBinaryOperator &);
  virtual void VisitCXXScalarValueInitExpr(const CXXScalarValueInitExpr &);
  virtual void VisitCXXStdInitializerListExpr(const CXXStdInitializerListExpr &);
  virtual void VisitCXXTemporaryObjectExpr(const CXXTemporaryObjectExpr &);
  virtual void VisitCXXThisExpr(const CXXThisExpr &);
  virtual void VisitCXXThrowExpr(const CXXThrowExpr &);
  virtual void VisitCXXTypeidExpr(const CXXTypeidExpr &);
  virtual void VisitCXXUnresolvedConstructExpr(const CXXUnresolvedConstructExpr &);
  virtual void VisitCXXUuidofExpr(const CXXUuidofExpr &);
  virtual void VisitCallExpr(const CallExpr &);
  virtual void VisitCastExpr(const CastExpr &);
  virtual void VisitCharacterLiteral(const CharacterLiteral &);
  virtual void VisitChooseExpr(const ChooseExpr &);
  virtual void VisitCompoundAssignOperator(const CompoundAssignOperator &);
  virtual void VisitCompoundLiteralExpr(const CompoundLiteralExpr &);
  virtual void VisitConceptSpecializationExpr(const ConceptSpecializationExpr &);
  virtual void VisitConditionalOperator(const ConditionalOperator &);
  virtual void VisitConstantExpr(const ConstantExpr &);
  virtual void VisitConvertVectorExpr(const ConvertVectorExpr &);
  virtual void VisitCoroutineSuspendExpr(const CoroutineSuspendExpr &);
  virtual void VisitCoyieldExpr(const CoyieldExpr &);
  virtual void VisitDeclRefExpr(const DeclRefExpr &);
  virtual void VisitDependentCoawaitExpr(const DependentCoawaitExpr &);
  virtual void VisitDependentScopeDeclRefExpr(const DependentScopeDeclRefExpr &);
  virtual void VisitDesignatedInitExpr(const DesignatedInitExpr &);
  virtual void VisitDesignatedInitUpdateExpr(const DesignatedInitUpdateExpr &);
  virtual void VisitExplicitCastExpr(const ExplicitCastExpr &);
  virtual void VisitExprWithCleanups(const ExprWithCleanups &);
  virtual void VisitImplicitCastExpr(const ImplicitCastExpr &);
  virtual void VisitOMPAtomicDirective(const OMPAtomicDirective &);
  virtual void VisitOMPBarrierDirective(const OMPBarrierDirective &);
  virtual void VisitOMPCancelDirective(const OMPCancelDirective &);
  virtual void VisitOMPCancellationPointDirective(const OMPCancellationPointDirective &);
  virtual void VisitOMPCriticalDirective(const OMPCriticalDirective &);
  virtual void VisitOMPDepobjDirective(const OMPDepobjDirective &);
  virtual void VisitOMPDispatchDirective(const OMPDispatchDirective &);
  virtual void VisitOMPDistributeDirective(const OMPDistributeDirective &);
  virtual void VisitOMPDistributeParallelForDirective(const OMPDistributeParallelForDirective &);
  virtual void VisitOMPDistributeParallelForSimdDirective(const OMPDistributeParallelForSimdDirective &);
  virtual void VisitOMPDistributeSimdDirective(const OMPDistributeSimdDirective &);
  virtual void VisitOMPForDirective(const OMPForDirective &);
  virtual void VisitOMPForSimdDirective(const OMPForSimdDirective &);
  virtual void VisitObjCBridgedCastExpr(const ObjCBridgedCastExpr &);
  virtual void VisitUserDefinedLiteral(const UserDefinedLiteral &);
  virtual void VisitBuiltinBitCastExpr(const BuiltinBitCastExpr &);
  virtual void VisitCStyleCastExpr(const CStyleCastExpr &);
  virtual void VisitCUDAKernelCallExpr(const CUDAKernelCallExpr &);
  virtual void VisitCXXFunctionalCastExpr(const CXXFunctionalCastExpr &);
  virtual void VisitCXXMemberCallExpr(const CXXMemberCallExpr &);
  virtual void VisitCXXNamedCastExpr(const CXXNamedCastExpr &);
  virtual void VisitCXXOperatorCallExpr(const CXXOperatorCallExpr &);
  virtual void VisitCXXReinterpretCastExpr(const CXXReinterpretCastExpr &);
  virtual void VisitCXXStaticCastExpr(const CXXStaticCastExpr &);
  virtual void VisitCoawaitExpr(const CoawaitExpr &);
  virtual void VisitCXXAddrspaceCastExpr(const CXXAddrspaceCastExpr &);
  virtual void VisitCXXConstCastExpr(const CXXConstCastExpr &);
  virtual void VisitCXXDynamicCastExpr(const CXXDynamicCastExpr &);
};

class Stmt {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Stmt)
  friend class TokenContext;
  static std::optional<::pasta::Stmt> From(const TokenContext &);
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, AbstractConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, AddrLabelExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ArrayInitIndexExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ArrayInitLoopExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ArraySubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ArrayTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, AsTypeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, AsmStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, AtomicExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, AttributedStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, BinaryConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, BinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, BlockExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, BreakStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, BuiltinBitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CStyleCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CUDAKernelCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXAddrspaceCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXBindTemporaryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXCatchStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXConstCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXDefaultArgExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXDefaultInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXDeleteExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXDependentScopeMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXDynamicCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXFoldExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXForRangeStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXFunctionalCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXInheritedCtorInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXMemberCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXNamedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXNewExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXNoexceptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXNullPtrLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXOperatorCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXPseudoDestructorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXReinterpretCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXRewrittenBinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXScalarValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXStaticCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXStdInitializerListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXTemporaryObjectExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXThisExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXThrowExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXTryStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXTypeidExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXUnresolvedConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CXXUuidofExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CapturedStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CaseStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CharacterLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ChooseExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CompoundAssignOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CompoundLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CompoundStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ConceptSpecializationExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ConstantExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ContinueStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ConvertVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CoreturnStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CoroutineBodyStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CoroutineSuspendExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, CoyieldExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DeclRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DeclStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DefaultStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DependentCoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DependentScopeDeclRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DesignatedInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DesignatedInitUpdateExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, DoStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ExplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, Expr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ExprWithCleanups)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ExpressionTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ExtVectorElementExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, FixedPointLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, FloatingLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ForStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, FullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, FunctionParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, GCCAsmStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, GNUNullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, GenericSelectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, GotoStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, IfStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ImaginaryLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ImplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ImplicitValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, IndirectGotoStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, InitListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, IntegerLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, LabelStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, LambdaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MSAsmStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MSDependentExistsStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MSPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MSPropertySubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MaterializeTemporaryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MatrixSubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, MemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, NoInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, NullStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPArraySectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPArrayShapingExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPAtomicDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPBarrierDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPCancelDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPCancellationPointDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPCanonicalLoop)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPCriticalDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPDepobjDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPDispatchDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPExecutableDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPFlushDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPInteropDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPIteratorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPLoopBasedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPMaskedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPMasterDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPOrderedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelMasterDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPParallelSectionsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPScanDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPSectionDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPSectionsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPSingleDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetDataDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetEnterDataDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetExitDataDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetParallelDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTargetUpdateDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTaskDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTaskgroupDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTaskwaitDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTaskyieldDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTeamsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPTileDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OMPUnrollDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCArrayLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAtCatchStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAtFinallyStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAtSynchronizedStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAtThrowStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAtTryStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAutoreleasePoolStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCBoxedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCBridgedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCDictionaryLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCEncodeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCForCollectionStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCIsaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCIvarRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCMessageExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCProtocolExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCSelectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCStringLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ObjCSubscriptRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OffsetOfExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OpaqueValueExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, OverloadExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, PackExpansionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ParenExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ParenListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, PredefinedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, PseudoObjectExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, RecoveryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, RequiresExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ReturnStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SEHExceptStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SEHFinallyStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SEHLeaveStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SEHTryStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SYCLUniqueStableNameExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ShuffleVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SizeOfPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SourceLocExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, StmtExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, StringLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SwitchCase)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, SwitchStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, TypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, TypoExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, UnaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, UnresolvedLookupExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, UnresolvedMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, UserDefinedLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, VAArgExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, ValueStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(Stmt, WhileStmt)
  ::pasta::Stmt IgnoreContainers(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  int64_t ID(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::StmtKind Kind(void) const;
  std::string_view KindName(void) const;
  ::pasta::Stmt StripLabelLikeStatements(void) const;
  inline bool operator==(const Stmt &that) const noexcept {
    return u.opaque == that.u.opaque;
  }
 protected:
  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::AbstractConditionalOperator *AbstractConditionalOperator;
    const ::clang::AddrLabelExpr *AddrLabelExpr;
    const ::clang::ArrayInitIndexExpr *ArrayInitIndexExpr;
    const ::clang::ArrayInitLoopExpr *ArrayInitLoopExpr;
    const ::clang::ArraySubscriptExpr *ArraySubscriptExpr;
    const ::clang::ArrayTypeTraitExpr *ArrayTypeTraitExpr;
    const ::clang::AsTypeExpr *AsTypeExpr;
    const ::clang::AsmStmt *AsmStmt;
    const ::clang::AtomicExpr *AtomicExpr;
    const ::clang::AttributedStmt *AttributedStmt;
    const ::clang::BinaryConditionalOperator *BinaryConditionalOperator;
    const ::clang::BinaryOperator *BinaryOperator;
    const ::clang::BlockExpr *BlockExpr;
    const ::clang::BreakStmt *BreakStmt;
    const ::clang::BuiltinBitCastExpr *BuiltinBitCastExpr;
    const ::clang::CStyleCastExpr *CStyleCastExpr;
    const ::clang::CUDAKernelCallExpr *CUDAKernelCallExpr;
    const ::clang::CXXAddrspaceCastExpr *CXXAddrspaceCastExpr;
    const ::clang::CXXBindTemporaryExpr *CXXBindTemporaryExpr;
    const ::clang::CXXBoolLiteralExpr *CXXBoolLiteralExpr;
    const ::clang::CXXCatchStmt *CXXCatchStmt;
    const ::clang::CXXConstCastExpr *CXXConstCastExpr;
    const ::clang::CXXConstructExpr *CXXConstructExpr;
    const ::clang::CXXDefaultArgExpr *CXXDefaultArgExpr;
    const ::clang::CXXDefaultInitExpr *CXXDefaultInitExpr;
    const ::clang::CXXDeleteExpr *CXXDeleteExpr;
    const ::clang::CXXDependentScopeMemberExpr *CXXDependentScopeMemberExpr;
    const ::clang::CXXDynamicCastExpr *CXXDynamicCastExpr;
    const ::clang::CXXFoldExpr *CXXFoldExpr;
    const ::clang::CXXForRangeStmt *CXXForRangeStmt;
    const ::clang::CXXFunctionalCastExpr *CXXFunctionalCastExpr;
    const ::clang::CXXInheritedCtorInitExpr *CXXInheritedCtorInitExpr;
    const ::clang::CXXMemberCallExpr *CXXMemberCallExpr;
    const ::clang::CXXNamedCastExpr *CXXNamedCastExpr;
    const ::clang::CXXNewExpr *CXXNewExpr;
    const ::clang::CXXNoexceptExpr *CXXNoexceptExpr;
    const ::clang::CXXNullPtrLiteralExpr *CXXNullPtrLiteralExpr;
    const ::clang::CXXOperatorCallExpr *CXXOperatorCallExpr;
    const ::clang::CXXPseudoDestructorExpr *CXXPseudoDestructorExpr;
    const ::clang::CXXReinterpretCastExpr *CXXReinterpretCastExpr;
    const ::clang::CXXRewrittenBinaryOperator *CXXRewrittenBinaryOperator;
    const ::clang::CXXScalarValueInitExpr *CXXScalarValueInitExpr;
    const ::clang::CXXStaticCastExpr *CXXStaticCastExpr;
    const ::clang::CXXStdInitializerListExpr *CXXStdInitializerListExpr;
    const ::clang::CXXTemporaryObjectExpr *CXXTemporaryObjectExpr;
    const ::clang::CXXThisExpr *CXXThisExpr;
    const ::clang::CXXThrowExpr *CXXThrowExpr;
    const ::clang::CXXTryStmt *CXXTryStmt;
    const ::clang::CXXTypeidExpr *CXXTypeidExpr;
    const ::clang::CXXUnresolvedConstructExpr *CXXUnresolvedConstructExpr;
    const ::clang::CXXUuidofExpr *CXXUuidofExpr;
    const ::clang::CallExpr *CallExpr;
    const ::clang::CapturedStmt *CapturedStmt;
    const ::clang::CaseStmt *CaseStmt;
    const ::clang::CastExpr *CastExpr;
    const ::clang::CharacterLiteral *CharacterLiteral;
    const ::clang::ChooseExpr *ChooseExpr;
    const ::clang::CoawaitExpr *CoawaitExpr;
    const ::clang::CompoundAssignOperator *CompoundAssignOperator;
    const ::clang::CompoundLiteralExpr *CompoundLiteralExpr;
    const ::clang::CompoundStmt *CompoundStmt;
    const ::clang::ConceptSpecializationExpr *ConceptSpecializationExpr;
    const ::clang::ConditionalOperator *ConditionalOperator;
    const ::clang::ConstantExpr *ConstantExpr;
    const ::clang::ContinueStmt *ContinueStmt;
    const ::clang::ConvertVectorExpr *ConvertVectorExpr;
    const ::clang::CoreturnStmt *CoreturnStmt;
    const ::clang::CoroutineBodyStmt *CoroutineBodyStmt;
    const ::clang::CoroutineSuspendExpr *CoroutineSuspendExpr;
    const ::clang::CoyieldExpr *CoyieldExpr;
    const ::clang::DeclRefExpr *DeclRefExpr;
    const ::clang::DeclStmt *DeclStmt;
    const ::clang::DefaultStmt *DefaultStmt;
    const ::clang::DependentCoawaitExpr *DependentCoawaitExpr;
    const ::clang::DependentScopeDeclRefExpr *DependentScopeDeclRefExpr;
    const ::clang::DesignatedInitExpr *DesignatedInitExpr;
    const ::clang::DesignatedInitUpdateExpr *DesignatedInitUpdateExpr;
    const ::clang::DoStmt *DoStmt;
    const ::clang::ExplicitCastExpr *ExplicitCastExpr;
    const ::clang::Expr *Expr;
    const ::clang::ExprWithCleanups *ExprWithCleanups;
    const ::clang::ExpressionTraitExpr *ExpressionTraitExpr;
    const ::clang::ExtVectorElementExpr *ExtVectorElementExpr;
    const ::clang::FixedPointLiteral *FixedPointLiteral;
    const ::clang::FloatingLiteral *FloatingLiteral;
    const ::clang::ForStmt *ForStmt;
    const ::clang::FullExpr *FullExpr;
    const ::clang::FunctionParmPackExpr *FunctionParmPackExpr;
    const ::clang::GCCAsmStmt *GCCAsmStmt;
    const ::clang::GNUNullExpr *GNUNullExpr;
    const ::clang::GenericSelectionExpr *GenericSelectionExpr;
    const ::clang::GotoStmt *GotoStmt;
    const ::clang::IfStmt *IfStmt;
    const ::clang::ImaginaryLiteral *ImaginaryLiteral;
    const ::clang::ImplicitCastExpr *ImplicitCastExpr;
    const ::clang::ImplicitValueInitExpr *ImplicitValueInitExpr;
    const ::clang::IndirectGotoStmt *IndirectGotoStmt;
    const ::clang::InitListExpr *InitListExpr;
    const ::clang::IntegerLiteral *IntegerLiteral;
    const ::clang::LabelStmt *LabelStmt;
    const ::clang::LambdaExpr *LambdaExpr;
    const ::clang::MSAsmStmt *MSAsmStmt;
    const ::clang::MSDependentExistsStmt *MSDependentExistsStmt;
    const ::clang::MSPropertyRefExpr *MSPropertyRefExpr;
    const ::clang::MSPropertySubscriptExpr *MSPropertySubscriptExpr;
    const ::clang::MaterializeTemporaryExpr *MaterializeTemporaryExpr;
    const ::clang::MatrixSubscriptExpr *MatrixSubscriptExpr;
    const ::clang::MemberExpr *MemberExpr;
    const ::clang::NoInitExpr *NoInitExpr;
    const ::clang::NullStmt *NullStmt;
    const ::clang::OMPArraySectionExpr *OMPArraySectionExpr;
    const ::clang::OMPArrayShapingExpr *OMPArrayShapingExpr;
    const ::clang::OMPAtomicDirective *OMPAtomicDirective;
    const ::clang::OMPBarrierDirective *OMPBarrierDirective;
    const ::clang::OMPCancelDirective *OMPCancelDirective;
    const ::clang::OMPCancellationPointDirective *OMPCancellationPointDirective;
    const ::clang::OMPCanonicalLoop *OMPCanonicalLoop;
    const ::clang::OMPCriticalDirective *OMPCriticalDirective;
    const ::clang::OMPDepobjDirective *OMPDepobjDirective;
    const ::clang::OMPDispatchDirective *OMPDispatchDirective;
    const ::clang::OMPDistributeDirective *OMPDistributeDirective;
    const ::clang::OMPDistributeParallelForDirective *OMPDistributeParallelForDirective;
    const ::clang::OMPDistributeParallelForSimdDirective *OMPDistributeParallelForSimdDirective;
    const ::clang::OMPDistributeSimdDirective *OMPDistributeSimdDirective;
    const ::clang::OMPExecutableDirective *OMPExecutableDirective;
    const ::clang::OMPFlushDirective *OMPFlushDirective;
    const ::clang::OMPForDirective *OMPForDirective;
    const ::clang::OMPForSimdDirective *OMPForSimdDirective;
    const ::clang::OMPInteropDirective *OMPInteropDirective;
    const ::clang::OMPIteratorExpr *OMPIteratorExpr;
    const ::clang::OMPLoopBasedDirective *OMPLoopBasedDirective;
    const ::clang::OMPLoopDirective *OMPLoopDirective;
    const ::clang::OMPMaskedDirective *OMPMaskedDirective;
    const ::clang::OMPMasterDirective *OMPMasterDirective;
    const ::clang::OMPMasterTaskLoopDirective *OMPMasterTaskLoopDirective;
    const ::clang::OMPMasterTaskLoopSimdDirective *OMPMasterTaskLoopSimdDirective;
    const ::clang::OMPOrderedDirective *OMPOrderedDirective;
    const ::clang::OMPParallelDirective *OMPParallelDirective;
    const ::clang::OMPParallelForDirective *OMPParallelForDirective;
    const ::clang::OMPParallelForSimdDirective *OMPParallelForSimdDirective;
    const ::clang::OMPParallelMasterDirective *OMPParallelMasterDirective;
    const ::clang::OMPParallelMasterTaskLoopDirective *OMPParallelMasterTaskLoopDirective;
    const ::clang::OMPParallelMasterTaskLoopSimdDirective *OMPParallelMasterTaskLoopSimdDirective;
    const ::clang::OMPParallelSectionsDirective *OMPParallelSectionsDirective;
    const ::clang::OMPScanDirective *OMPScanDirective;
    const ::clang::OMPSectionDirective *OMPSectionDirective;
    const ::clang::OMPSectionsDirective *OMPSectionsDirective;
    const ::clang::OMPSimdDirective *OMPSimdDirective;
    const ::clang::OMPSingleDirective *OMPSingleDirective;
    const ::clang::OMPTargetDataDirective *OMPTargetDataDirective;
    const ::clang::OMPTargetDirective *OMPTargetDirective;
    const ::clang::OMPTargetEnterDataDirective *OMPTargetEnterDataDirective;
    const ::clang::OMPTargetExitDataDirective *OMPTargetExitDataDirective;
    const ::clang::OMPTargetParallelDirective *OMPTargetParallelDirective;
    const ::clang::OMPTargetParallelForDirective *OMPTargetParallelForDirective;
    const ::clang::OMPTargetParallelForSimdDirective *OMPTargetParallelForSimdDirective;
    const ::clang::OMPTargetSimdDirective *OMPTargetSimdDirective;
    const ::clang::OMPTargetTeamsDirective *OMPTargetTeamsDirective;
    const ::clang::OMPTargetTeamsDistributeDirective *OMPTargetTeamsDistributeDirective;
    const ::clang::OMPTargetTeamsDistributeParallelForDirective *OMPTargetTeamsDistributeParallelForDirective;
    const ::clang::OMPTargetTeamsDistributeParallelForSimdDirective *OMPTargetTeamsDistributeParallelForSimdDirective;
    const ::clang::OMPTargetTeamsDistributeSimdDirective *OMPTargetTeamsDistributeSimdDirective;
    const ::clang::OMPTargetUpdateDirective *OMPTargetUpdateDirective;
    const ::clang::OMPTaskDirective *OMPTaskDirective;
    const ::clang::OMPTaskLoopDirective *OMPTaskLoopDirective;
    const ::clang::OMPTaskLoopSimdDirective *OMPTaskLoopSimdDirective;
    const ::clang::OMPTaskgroupDirective *OMPTaskgroupDirective;
    const ::clang::OMPTaskwaitDirective *OMPTaskwaitDirective;
    const ::clang::OMPTaskyieldDirective *OMPTaskyieldDirective;
    const ::clang::OMPTeamsDirective *OMPTeamsDirective;
    const ::clang::OMPTeamsDistributeDirective *OMPTeamsDistributeDirective;
    const ::clang::OMPTeamsDistributeParallelForDirective *OMPTeamsDistributeParallelForDirective;
    const ::clang::OMPTeamsDistributeParallelForSimdDirective *OMPTeamsDistributeParallelForSimdDirective;
    const ::clang::OMPTeamsDistributeSimdDirective *OMPTeamsDistributeSimdDirective;
    const ::clang::OMPTileDirective *OMPTileDirective;
    const ::clang::OMPUnrollDirective *OMPUnrollDirective;
    const ::clang::ObjCArrayLiteral *ObjCArrayLiteral;
    const ::clang::ObjCAtCatchStmt *ObjCAtCatchStmt;
    const ::clang::ObjCAtFinallyStmt *ObjCAtFinallyStmt;
    const ::clang::ObjCAtSynchronizedStmt *ObjCAtSynchronizedStmt;
    const ::clang::ObjCAtThrowStmt *ObjCAtThrowStmt;
    const ::clang::ObjCAtTryStmt *ObjCAtTryStmt;
    const ::clang::ObjCAutoreleasePoolStmt *ObjCAutoreleasePoolStmt;
    const ::clang::ObjCAvailabilityCheckExpr *ObjCAvailabilityCheckExpr;
    const ::clang::ObjCBoolLiteralExpr *ObjCBoolLiteralExpr;
    const ::clang::ObjCBoxedExpr *ObjCBoxedExpr;
    const ::clang::ObjCBridgedCastExpr *ObjCBridgedCastExpr;
    const ::clang::ObjCDictionaryLiteral *ObjCDictionaryLiteral;
    const ::clang::ObjCEncodeExpr *ObjCEncodeExpr;
    const ::clang::ObjCForCollectionStmt *ObjCForCollectionStmt;
    const ::clang::ObjCIndirectCopyRestoreExpr *ObjCIndirectCopyRestoreExpr;
    const ::clang::ObjCIsaExpr *ObjCIsaExpr;
    const ::clang::ObjCIvarRefExpr *ObjCIvarRefExpr;
    const ::clang::ObjCMessageExpr *ObjCMessageExpr;
    const ::clang::ObjCPropertyRefExpr *ObjCPropertyRefExpr;
    const ::clang::ObjCProtocolExpr *ObjCProtocolExpr;
    const ::clang::ObjCSelectorExpr *ObjCSelectorExpr;
    const ::clang::ObjCStringLiteral *ObjCStringLiteral;
    const ::clang::ObjCSubscriptRefExpr *ObjCSubscriptRefExpr;
    const ::clang::OffsetOfExpr *OffsetOfExpr;
    const ::clang::OpaqueValueExpr *OpaqueValueExpr;
    const ::clang::OverloadExpr *OverloadExpr;
    const ::clang::PackExpansionExpr *PackExpansionExpr;
    const ::clang::ParenExpr *ParenExpr;
    const ::clang::ParenListExpr *ParenListExpr;
    const ::clang::PredefinedExpr *PredefinedExpr;
    const ::clang::PseudoObjectExpr *PseudoObjectExpr;
    const ::clang::RecoveryExpr *RecoveryExpr;
    const ::clang::RequiresExpr *RequiresExpr;
    const ::clang::ReturnStmt *ReturnStmt;
    const ::clang::SEHExceptStmt *SEHExceptStmt;
    const ::clang::SEHFinallyStmt *SEHFinallyStmt;
    const ::clang::SEHLeaveStmt *SEHLeaveStmt;
    const ::clang::SEHTryStmt *SEHTryStmt;
    const ::clang::SYCLUniqueStableNameExpr *SYCLUniqueStableNameExpr;
    const ::clang::ShuffleVectorExpr *ShuffleVectorExpr;
    const ::clang::SizeOfPackExpr *SizeOfPackExpr;
    const ::clang::SourceLocExpr *SourceLocExpr;
    const ::clang::Stmt *Stmt;
    const ::clang::StmtExpr *StmtExpr;
    const ::clang::StringLiteral *StringLiteral;
    const ::clang::SubstNonTypeTemplateParmExpr *SubstNonTypeTemplateParmExpr;
    const ::clang::SubstNonTypeTemplateParmPackExpr *SubstNonTypeTemplateParmPackExpr;
    const ::clang::SwitchCase *SwitchCase;
    const ::clang::SwitchStmt *SwitchStmt;
    const ::clang::TypeTraitExpr *TypeTraitExpr;
    const ::clang::TypoExpr *TypoExpr;
    const ::clang::UnaryExprOrTypeTraitExpr *UnaryExprOrTypeTraitExpr;
    const ::clang::UnaryOperator *UnaryOperator;
    const ::clang::UnresolvedLookupExpr *UnresolvedLookupExpr;
    const ::clang::UnresolvedMemberExpr *UnresolvedMemberExpr;
    const ::clang::UserDefinedLiteral *UserDefinedLiteral;
    const ::clang::VAArgExpr *VAArgExpr;
    const ::clang::ValueStmt *ValueStmt;
    const ::clang::WhileStmt *WhileStmt;
    const void *opaque;
  } u;
  StmtKind kind;

  inline explicit Stmt(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Stmt *decl_,
                       StmtKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    u.Stmt = decl_;
  }

 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(Stmt)
};

class SwitchCase : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwitchCase)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SwitchCase)
  PASTA_DECLARE_DERIVED_OPERATORS(SwitchCase, CaseStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(SwitchCase, DefaultStmt)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token ColonToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token KeywordToken(void) const;
  ::pasta::SwitchCase NextSwitchCase(void) const;
  ::pasta::Stmt SubStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SwitchCase)
};

static_assert(sizeof(Stmt) == sizeof(SwitchCase));

class SwitchStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SwitchStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SwitchStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclarationStatement(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt Initializer(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::SwitchCase SwitchCaseList(void) const;
  ::pasta::Token SwitchToken(void) const;
  bool HasInitializerStorage(void) const;
  bool HasVariableStorage(void) const;
  bool IsAllEnumCasesCovered(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SwitchStmt)
};

static_assert(sizeof(Stmt) == sizeof(SwitchStmt));

class ValueStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ValueStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ValueStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, AbstractConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, AddrLabelExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ArrayInitIndexExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ArrayInitLoopExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ArraySubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ArrayTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, AsTypeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, AtomicExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, AttributedStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, BinaryConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, BinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, BlockExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, BuiltinBitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CStyleCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CUDAKernelCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXAddrspaceCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXBindTemporaryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXConstCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXDefaultArgExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXDefaultInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXDeleteExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXDependentScopeMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXDynamicCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXFoldExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXFunctionalCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXInheritedCtorInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXMemberCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXNamedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXNewExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXNoexceptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXNullPtrLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXOperatorCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXPseudoDestructorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXReinterpretCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXRewrittenBinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXScalarValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXStaticCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXStdInitializerListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXTemporaryObjectExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXThisExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXThrowExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXTypeidExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXUnresolvedConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CXXUuidofExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CharacterLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ChooseExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CompoundAssignOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CompoundLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ConceptSpecializationExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ConstantExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ConvertVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CoroutineSuspendExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, CoyieldExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, DeclRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, DependentCoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, DependentScopeDeclRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, DesignatedInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, DesignatedInitUpdateExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ExplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, Expr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ExprWithCleanups)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ExpressionTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ExtVectorElementExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, FixedPointLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, FloatingLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, FullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, FunctionParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, GNUNullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, GenericSelectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ImaginaryLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ImplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ImplicitValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, InitListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, IntegerLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, LabelStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, LambdaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, MSPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, MSPropertySubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, MaterializeTemporaryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, MatrixSubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, MemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, NoInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, OMPArraySectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, OMPArrayShapingExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, OMPIteratorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCArrayLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCBoxedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCBridgedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCDictionaryLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCEncodeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCIsaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCIvarRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCMessageExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCProtocolExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCSelectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCStringLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCSubscriptRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, OffsetOfExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, OpaqueValueExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, OverloadExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, PackExpansionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ParenExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ParenListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, PredefinedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, PseudoObjectExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, RecoveryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, RequiresExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SYCLUniqueStableNameExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ShuffleVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SizeOfPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SourceLocExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, StmtExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, StringLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, TypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, TypoExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnresolvedLookupExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnresolvedMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UserDefinedLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, VAArgExpr)
  ::pasta::Expr ExpressionStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ValueStmt)
};

static_assert(sizeof(Stmt) == sizeof(ValueStmt));

class WhileStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(WhileStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, WhileStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclarationStatement(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Token WhileToken(void) const;
  bool HasVariableStorage(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(WhileStmt)
};

static_assert(sizeof(Stmt) == sizeof(WhileStmt));

class AsmStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AsmStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, AsmStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(AsmStmt, GCCAsmStmt)
  PASTA_DECLARE_DERIVED_OPERATORS(AsmStmt, MSAsmStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  std::string GenerateAssemblyString(void) const;
  ::pasta::Token AssemblyToken(void) const;
  ::pasta::Token BeginToken(void) const;
  // Clobber: (llvm::StringRef)
  ::pasta::Token EndToken(void) const;
  // InputConstraint: (llvm::StringRef)
  // InputExpression: (const clang::Expr *)
  uint32_t NumClobbers(void) const;
  uint32_t NumInputs(void) const;
  uint32_t NumOutputs(void) const;
  uint32_t NumPlusOperands(void) const;
  // OutputConstraint: (llvm::StringRef)
  // OutputExpression: (const clang::Expr *)
  std::vector<::pasta::Expr> Inputs(void) const;
  // IsOutputPlusConstraint: (bool)
  bool IsSimple(void) const;
  bool IsVolatile(void) const;
  std::vector<::pasta::Expr> Outputs(void) const;
  std::vector<std::string_view> OutputConstraints(void) const;
  std::vector<::pasta::Expr> OutputExpressions(void) const;
  std::vector<std::string_view> InputConstraints(void) const;
  std::vector<::pasta::Expr> InputExpressions(void) const;
  std::vector<std::string_view> Clobbers(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(AsmStmt)
};

static_assert(sizeof(Stmt) == sizeof(AsmStmt));

class AttributedStmt : public ValueStmt {
 private:
  using ValueStmt::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AttributedStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, AttributedStmt)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, AttributedStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AttributeToken(void) const;
  // Attributes: (llvm::ArrayRef<const clang::Attr *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt SubStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(AttributedStmt)
};

static_assert(sizeof(Stmt) == sizeof(AttributedStmt));

class BreakStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BreakStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, BreakStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BreakToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(BreakStmt)
};

static_assert(sizeof(Stmt) == sizeof(BreakStmt));

class CXXCatchStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXCatchStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXCatchStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token CatchToken(void) const;
  ::pasta::Type CaughtType(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::VarDecl ExceptionDeclaration(void) const;
  ::pasta::Stmt HandlerBlock(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXCatchStmt)
};

static_assert(sizeof(Stmt) == sizeof(CXXCatchStmt));

class CXXForRangeStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXForRangeStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXForRangeStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::DeclStmt BeginStatement(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Token CoawaitToken(void) const;
  ::pasta::Token ColonToken(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::DeclStmt EndStatement(void) const;
  ::pasta::Token ForToken(void) const;
  ::pasta::Expr Increment(void) const;
  ::pasta::Stmt Initializer(void) const;
  ::pasta::DeclStmt LoopVariableStatement(void) const;
  ::pasta::VarDecl LoopVariable(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr RangeInitializer(void) const;
  ::pasta::DeclStmt RangeStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXForRangeStmt)
};

static_assert(sizeof(Stmt) == sizeof(CXXForRangeStmt));

class CXXTryStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXTryStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXTryStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Handler: (const clang::CXXCatchStmt *)
  uint32_t NumHandlers(void) const;
  ::pasta::CompoundStmt TryBlock(void) const;
  ::pasta::Token TryToken(void) const;
  std::vector<::pasta::CXXCatchStmt> Handlers(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXTryStmt)
};

static_assert(sizeof(Stmt) == sizeof(CXXTryStmt));

class CapturedStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CapturedStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CapturedStmt)
  // CaptureInitializers: (llvm::iterator_range<clang::Expr *const *>)
  // Captures: (llvm::iterator_range<const clang::CapturedStmt::Capture *>)
  // CapturesVariable: (bool)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::CapturedDecl CapturedDeclaration(void) const;
  ::pasta::RecordDecl CapturedRecordDeclaration(void) const;
  enum CapturedRegionKind CapturedRegionKind(void) const;
  ::pasta::Stmt CapturedStatement(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CapturedStmt)
};

static_assert(sizeof(Stmt) == sizeof(CapturedStmt));

class CaseStmt : public SwitchCase {
 private:
  using SwitchCase::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CaseStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CaseStmt)
  PASTA_DECLARE_BASE_OPERATORS(SwitchCase, CaseStmt)
  bool CaseStatementIsGNURange(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token CaseToken(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Stmt SubStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CaseStmt)
};

static_assert(sizeof(Stmt) == sizeof(CaseStmt));

class CompoundStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CompoundStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CompoundStmt)
  // Body: (llvm::iterator_range<clang::Stmt *const *>)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LBracToken(void) const;
  ::pasta::Token RBracToken(void) const;
  ::pasta::Stmt StatementExpressionResult(void) const;
  uint32_t Size(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CompoundStmt)
};

static_assert(sizeof(Stmt) == sizeof(CompoundStmt));

class ContinueStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ContinueStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ContinueStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token ContinueToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ContinueStmt)
};

static_assert(sizeof(Stmt) == sizeof(ContinueStmt));

class CoreturnStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CoreturnStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CoreturnStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token KeywordToken(void) const;
  ::pasta::Expr Operand(void) const;
  ::pasta::Expr PromiseCall(void) const;
  bool IsImplicit(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CoreturnStmt)
};

static_assert(sizeof(Stmt) == sizeof(CoreturnStmt));

class CoroutineBodyStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CoroutineBodyStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CoroutineBodyStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Allocate(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Deallocate(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt ExceptionHandler(void) const;
  ::pasta::Stmt FallthroughHandler(void) const;
  ::pasta::Stmt FinalSuspendStatement(void) const;
  ::pasta::Stmt InitializerSuspendStatement(void) const;
  std::vector<::pasta::Stmt> ParamMoves(void) const;
  ::pasta::VarDecl PromiseDeclaration(void) const;
  ::pasta::Stmt PromiseDeclarationStatement(void) const;
  ::pasta::Stmt ResultDeclaration(void) const;
  ::pasta::Stmt ReturnStatement(void) const;
  ::pasta::Stmt ReturnStatementOnAllocFailure(void) const;
  ::pasta::Expr ReturnValueInitializer(void) const;
  bool HasDependentPromiseType(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CoroutineBodyStmt)
};

static_assert(sizeof(Stmt) == sizeof(CoroutineBodyStmt));

class DeclStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DeclStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  // Declarations: (llvm::iterator_range<clang::Decl *const *>)
  ::pasta::Token BeginToken(void) const;
  // DeclarationGroup: (const clang::DeclGroupRef)
  ::pasta::Token EndToken(void) const;
  ::pasta::Decl SingleDeclaration(void) const;
  bool IsSingleDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DeclStmt)
};

static_assert(sizeof(Stmt) == sizeof(DeclStmt));

class DefaultStmt : public SwitchCase {
 private:
  using SwitchCase::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DefaultStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DefaultStmt)
  PASTA_DECLARE_BASE_OPERATORS(SwitchCase, DefaultStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token DefaultToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt SubStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DefaultStmt)
};

static_assert(sizeof(Stmt) == sizeof(DefaultStmt));

class DoStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DoStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DoStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Token DoToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Token WhileToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DoStmt)
};

static_assert(sizeof(Stmt) == sizeof(DoStmt));

class Expr : public ValueStmt {
 private:
  using ValueStmt::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Expr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, Expr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, Expr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, AbstractConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, AddrLabelExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ArrayInitIndexExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ArrayInitLoopExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ArraySubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ArrayTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, AsTypeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, AtomicExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, BinaryConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, BinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, BlockExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, BuiltinBitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CStyleCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CUDAKernelCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXBindTemporaryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXConstCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXDefaultArgExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXDefaultInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXDeleteExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXDependentScopeMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXDynamicCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXFoldExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXFunctionalCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXInheritedCtorInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXMemberCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXNamedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXNewExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXNoexceptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXNullPtrLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXOperatorCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXPseudoDestructorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXReinterpretCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXRewrittenBinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXScalarValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXStaticCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXStdInitializerListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXTemporaryObjectExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXThisExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXThrowExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXTypeidExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXUnresolvedConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CXXUuidofExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CharacterLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ChooseExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CompoundAssignOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CompoundLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ConceptSpecializationExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ConstantExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ConvertVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CoroutineSuspendExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, CoyieldExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, DeclRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, DependentCoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, DependentScopeDeclRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, DesignatedInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, DesignatedInitUpdateExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ExplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ExprWithCleanups)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ExpressionTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ExtVectorElementExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, FixedPointLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, FloatingLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, FullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, FunctionParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, GNUNullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, GenericSelectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ImaginaryLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ImplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ImplicitValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, InitListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, IntegerLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, LambdaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, MSPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, MSPropertySubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, MaterializeTemporaryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, MatrixSubscriptExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, MemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, NoInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, OMPArraySectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, OMPArrayShapingExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, OMPIteratorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCArrayLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCBoxedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCBridgedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCDictionaryLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCEncodeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCIsaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCIvarRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCMessageExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCProtocolExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCSelectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCStringLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCSubscriptRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, OffsetOfExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, OpaqueValueExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, OverloadExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, PackExpansionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ParenExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ParenListExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, PredefinedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, PseudoObjectExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, RecoveryExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, RequiresExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SYCLUniqueStableNameExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ShuffleVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SizeOfPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SourceLocExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, StmtExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, StringLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, TypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, TypoExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnresolvedLookupExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnresolvedMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UserDefinedLiteral)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, VAArgExpr)
  // Classify: (clang::Expr::Classification)
  // ClassifyLValue: (clang::Expr::LValueClassification)
  // ClassifyModifiable: (clang::Expr::Classification)
  // EvaluateAsBooleanCondition: (bool)
  // EvaluateAsConstantExpression: (bool)
  // EvaluateAsFixedPoint: (bool)
  // EvaluateAsFloat: (bool)
  // EvaluateAsInitializer: (bool)
  // EvaluateAsInt: (bool)
  // EvaluateAsLValue: (bool)
  // EvaluateAsRValue: (bool)
  // EvaluateKnownConstInt: (llvm::APSInt)
  // EvaluateKnownConstIntCheckOverflow: (llvm::APSInt)
  // EvaluateWithSubstitution: (bool)
  bool HasSideEffects(void) const;
  ::pasta::Expr IgnoreCasts(void) const;
  ::pasta::Expr IgnoreConversionOperatorSingleStep(void) const;
  ::pasta::Expr IgnoreImpCasts(void) const;
  ::pasta::Expr IgnoreImplicit(void) const;
  ::pasta::Expr IgnoreImplicitAsWritten(void) const;
  ::pasta::Expr IgnoreParenthesisBaseCasts(void) const;
  ::pasta::Expr IgnoreParenthesisCasts(void) const;
  ::pasta::Expr IgnoreParenthesisImpCasts(void) const;
  ::pasta::Expr IgnoreParenthesisLValueCasts(void) const;
  ::pasta::Expr IgnoreParenthesisNoopCasts(void) const;
  ::pasta::Expr IgnoreParentheses(void) const;
  ::pasta::Expr IgnoreUnlessSpelledInSource(void) const;
  bool ContainsErrors(void) const;
  bool ContainsUnexpandedParameterPack(void) const;
  ::pasta::CXXRecordDecl BestDynamicClassType(void) const;
  ::pasta::Expr BestDynamicClassTypeExpression(void) const;
  // Dependence: (clang::ExprDependenceScope::ExprDependence)
  ::pasta::Token ExpressionToken(void) const;
  // FPFeaturesInEffect: (clang::FPOptions)
  // IntegerConstantExpression: (llvm::Optional<llvm::APSInt>)
  ::pasta::ObjCPropertyRefExpr ObjCProperty(void) const;
  enum ExprObjectKind ObjectKind(void) const;
  ::pasta::Decl ReferencedDeclarationOfCallee(void) const;
  ::pasta::FieldDecl SourceBitField(void) const;
  ::pasta::Type Type(void) const;
  enum ExprValueKind ValueKind(void) const;
  bool HasNonTrivialCall(void) const;
  bool IsBoundMemberFunction(void) const;
  bool IsCXX11ConstantExpression(void) const;
  bool IsCXX98IntegralConstantExpression(void) const;
  // IsConstantInitializer: (bool)
  bool IsDefaultArgument(void) const;
  bool IsEvaluatable(void) const;
  bool IsGLValue(void) const;
  bool IsImplicitCXXThis(void) const;
  bool IsInstantiationDependent(void) const;
  bool IsIntegerConstantExpression(void) const;
  bool IsKnownToHaveBooleanValue(void) const;
  bool IsLValue(void) const;
  // IsModifiableLvalue: (clang::Expr::isModifiableLvalueResult)
  // IsNullPointerConstant: (clang::Expr::NullPointerConstantKind)
  bool IsOBJCGCCandidate(void) const;
  bool IsObjCSelfExpression(void) const;
  bool IsOrdinaryOrBitFieldObject(void) const;
  bool IsPRValue(void) const;
  bool IsReadIfDiscardedInCPlusPlus11(void) const;
  // IsTemporaryObject: (bool)
  bool IsTypeDependent(void) const;
  // IsUnusedResultAWarning: (bool)
  bool IsValueDependent(void) const;
  bool IsXValue(void) const;
  bool RefersToBitField(void) const;
  bool RefersToGlobalRegisterVariable(void) const;
  bool RefersToMatrixElement(void) const;
  bool RefersToVectorElement(void) const;
  // TryEvaluateObjectSize: (bool)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(Expr)
};

static_assert(sizeof(Stmt) == sizeof(Expr));

class ExpressionTraitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExpressionTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ExpressionTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ExpressionTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ExpressionTraitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr QueriedExpression(void) const;
  enum ExpressionTrait Trait(void) const;
  bool Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ExpressionTraitExpr)
};

static_assert(sizeof(Stmt) == sizeof(ExpressionTraitExpr));

class ExtVectorElementExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExtVectorElementExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ExtVectorElementExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ExtVectorElementExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ExtVectorElementExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  bool ContainsDuplicateElements(void) const;
  // Accessor: (clang::IdentifierInfo &)
  ::pasta::Token AccessorToken(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  uint32_t NumElements(void) const;
  bool IsArrow(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ExtVectorElementExpr)
};

static_assert(sizeof(Stmt) == sizeof(ExtVectorElementExpr));

class FixedPointLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FixedPointLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, FixedPointLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, FixedPointLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, FixedPointLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  uint32_t Scale(void) const;
  // ValueAsString: (std::string)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(FixedPointLiteral)
};

static_assert(sizeof(Stmt) == sizeof(FixedPointLiteral));

class FloatingLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FloatingLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, FloatingLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, FloatingLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, FloatingLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  // RawSemantics: (llvm::APFloatBase::Semantics)
  // Semantics: (const llvm::fltSemantics &)
  // Value: (llvm::APFloat)
  // ValueAsApproximateDouble: (double)
  bool IsExact(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(FloatingLiteral)
};

static_assert(sizeof(Stmt) == sizeof(FloatingLiteral));

class ForStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ForStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ForStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclarationStatement(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ForToken(void) const;
  ::pasta::Expr Increment(void) const;
  ::pasta::Stmt Initializer(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ForStmt)
};

static_assert(sizeof(Stmt) == sizeof(ForStmt));

class FullExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FullExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, FullExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, FullExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, FullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(FullExpr, ConstantExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(FullExpr, ExprWithCleanups)
  ::pasta::Expr SubExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(FullExpr)
};

static_assert(sizeof(Stmt) == sizeof(FullExpr));

class FunctionParmPackExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionParmPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, FunctionParmPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, FunctionParmPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, FunctionParmPackExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Expansion: (clang::VarDecl *)
  uint32_t NumExpansions(void) const;
  ::pasta::VarDecl ParameterPack(void) const;
  ::pasta::Token ParameterPackToken(void) const;
  std::vector<::pasta::VarDecl> Expansions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(FunctionParmPackExpr)
};

static_assert(sizeof(Stmt) == sizeof(FunctionParmPackExpr));

class GCCAsmStmt : public AsmStmt {
 private:
  using AsmStmt::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GCCAsmStmt)
  PASTA_DECLARE_BASE_OPERATORS(AsmStmt, GCCAsmStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, GCCAsmStmt)
  // AnalyzeAssemblyString: (unsigned int)
  std::string GenerateAssemblyString(void) const;
  ::pasta::StringLiteral AssemblyString(void) const;
  ::pasta::Token BeginToken(void) const;
  // Clobber: (llvm::StringRef)
  // ClobberStringLiteral: (const clang::StringLiteral *)
  ::pasta::Token EndToken(void) const;
  // InputConstraint: (llvm::StringRef)
  // InputConstraintLiteral: (const clang::StringLiteral *)
  // InputExpression: (const clang::Expr *)
  // InputIdentifier: (clang::IdentifierInfo *)
  // InputName: (llvm::StringRef)
  // LabelExpression: (clang::AddrLabelExpr *)
  // LabelIdentifier: (clang::IdentifierInfo *)
  // LabelName: (llvm::StringRef)
  // NamedOperand: (int)
  uint32_t NumLabels(void) const;
  // OutputConstraint: (llvm::StringRef)
  // OutputConstraintLiteral: (const clang::StringLiteral *)
  // OutputExpression: (const clang::Expr *)
  // OutputIdentifier: (clang::IdentifierInfo *)
  // OutputName: (llvm::StringRef)
  ::pasta::Token RParenToken(void) const;
  bool IsAssemblyGoto(void) const;
  std::vector<::pasta::AddrLabelExpr> Labels(void) const;
  std::vector<std::string_view> OutputConstraints(void) const;
  std::vector<::pasta::StringLiteral> OutputConstraintLiterals(void) const;
  std::vector<::pasta::Expr> OutputExpressions(void) const;
  // !!! Output getNumOutputs getOutputIdentifier (empty ret type = (clang::IdentifierInfo *))
  std::vector<std::string_view> OutputNames(void) const;
  std::vector<std::string_view> InputConstraints(void) const;
  std::vector<::pasta::StringLiteral> InputConstraintLiterals(void) const;
  std::vector<::pasta::Expr> InputExpressions(void) const;
  // !!! Input getNumInputs getInputIdentifier (empty ret type = (clang::IdentifierInfo *))
  std::vector<std::string_view> InputNames(void) const;
  std::vector<std::string_view> Clobbers(void) const;
  std::vector<::pasta::StringLiteral> ClobberStringLiterals(void) const;
  std::vector<::pasta::AddrLabelExpr> LabelExpressions(void) const;
  // !!! Label getNumLabels getLabelIdentifier (empty ret type = (clang::IdentifierInfo *))
  std::vector<std::string_view> LabelNames(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(GCCAsmStmt)
};

static_assert(sizeof(Stmt) == sizeof(GCCAsmStmt));

class GNUNullExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GNUNullExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, GNUNullExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, GNUNullExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, GNUNullExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token TokenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(GNUNullExpr)
};

static_assert(sizeof(Stmt) == sizeof(GNUNullExpr));

class GenericSelectionExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GenericSelectionExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, GenericSelectionExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, GenericSelectionExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, GenericSelectionExpr)
  // Associations: (llvm::iterator_range<clang::GenericSelectionExpr::AssociationIteratorTy<true>>)
  std::vector<::pasta::Stmt> Children(void) const;
  std::vector<::pasta::Expr> AssociationExpressions(void) const;
  // AssociationTypeSourceInfos: (llvm::ArrayRef<clang::TypeSourceInfo *>)
  // Association: (clang::GenericSelectionExpr::AssociationTy<true>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr ControllingExpression(void) const;
  ::pasta::Token DefaultToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token GenericToken(void) const;
  uint32_t NumAssociations(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr ResultExpression(void) const;
  uint32_t ResultIndex(void) const;
  bool IsResultDependent(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(GenericSelectionExpr)
};

static_assert(sizeof(Stmt) == sizeof(GenericSelectionExpr));

class GotoStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(GotoStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, GotoStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token GotoToken(void) const;
  ::pasta::LabelDecl Label(void) const;
  ::pasta::Token LabelToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(GotoStmt)
};

static_assert(sizeof(Stmt) == sizeof(GotoStmt));

class IfStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IfStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, IfStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclarationStatement(void) const;
  ::pasta::Stmt Else(void) const;
  ::pasta::Token ElseToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token IfToken(void) const;
  ::pasta::Stmt Initializer(void) const;
  ::pasta::Token LParenToken(void) const;
  // NondiscardedCase: (llvm::Optional<const clang::Stmt *>)
  ::pasta::Token RParenToken(void) const;
  ::pasta::Stmt Then(void) const;
  bool HasElseStorage(void) const;
  bool HasInitializerStorage(void) const;
  bool HasVariableStorage(void) const;
  bool IsConstexpr(void) const;
  bool IsObjCAvailabilityCheck(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(IfStmt)
};

static_assert(sizeof(Stmt) == sizeof(IfStmt));

class ImaginaryLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImaginaryLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ImaginaryLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ImaginaryLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ImaginaryLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr SubExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ImaginaryLiteral)
};

static_assert(sizeof(Stmt) == sizeof(ImaginaryLiteral));

class ImplicitValueInitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImplicitValueInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ImplicitValueInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ImplicitValueInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ImplicitValueInitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ImplicitValueInitExpr)
};

static_assert(sizeof(Stmt) == sizeof(ImplicitValueInitExpr));

class IndirectGotoStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IndirectGotoStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, IndirectGotoStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::LabelDecl ConstantTarget(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token GotoToken(void) const;
  ::pasta::Token StarToken(void) const;
  ::pasta::Expr Target(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(IndirectGotoStmt)
};

static_assert(sizeof(Stmt) == sizeof(IndirectGotoStmt));

class InitListExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InitListExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, InitListExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, InitListExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, InitListExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr ArrayFiller(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Initializer: (const clang::Expr *)
  ::pasta::FieldDecl InitializedFieldInUnion(void) const;
  // Initializers: (clang::Expr *const *)
  ::pasta::Token LBraceToken(void) const;
  uint32_t NumInitializers(void) const;
  ::pasta::Token RBraceToken(void) const;
  ::pasta::InitListExpr SemanticForm(void) const;
  ::pasta::InitListExpr SyntacticForm(void) const;
  bool HadArrayRangeDesignator(void) const;
  bool HasArrayFiller(void) const;
  std::vector<::pasta::Expr> Initializers(void) const;
  bool IsExplicit(void) const;
  // IsIdiomaticZeroInitializer: (bool)
  bool IsSemanticForm(void) const;
  bool IsStringLiteralInitializer(void) const;
  bool IsSyntacticForm(void) const;
  bool IsTransparent(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(InitListExpr)
};

static_assert(sizeof(Stmt) == sizeof(InitListExpr));

class IntegerLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IntegerLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, IntegerLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, IntegerLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, IntegerLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(IntegerLiteral)
};

static_assert(sizeof(Stmt) == sizeof(IntegerLiteral));

class LabelStmt : public ValueStmt {
 private:
  using ValueStmt::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LabelStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, LabelStmt)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, LabelStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::LabelDecl Declaration(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token IdentifierToken(void) const;
  std::string_view Name(void) const;
  ::pasta::Stmt SubStatement(void) const;
  bool IsSideEntry(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(LabelStmt)
};

static_assert(sizeof(Stmt) == sizeof(LabelStmt));

class LambdaExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LambdaExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, LambdaExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, LambdaExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, LambdaExpr)
  // CaptureInitializers: (llvm::iterator_range<clang::Expr *const *>)
  // Captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  std::vector<::pasta::Stmt> Children(void) const;
  // ExplicitCaptures: (llvm::iterator_range<const clang::LambdaCapture *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::CXXMethodDecl CallOperator(void) const;
  enum LambdaCaptureDefault CaptureDefault(void) const;
  ::pasta::Token CaptureDefaultToken(void) const;
  ::pasta::CompoundStmt CompoundStatementBody(void) const;
  ::pasta::FunctionTemplateDecl DependentCallOperator(void) const;
  ::pasta::Token EndToken(void) const;
  std::vector<::pasta::NamedDecl> ExplicitTemplateParameters(void) const;
  ::pasta::TokenRange IntroducerRange(void) const;
  ::pasta::CXXRecordDecl LambdaClass(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
  ::pasta::Expr TrailingRequiresClause(void) const;
  bool HasExplicitParameters(void) const;
  bool HasExplicitResultType(void) const;
  // ImplicitCaptures: (llvm::iterator_range<const clang::LambdaCapture *>)
  bool IsGenericLambda(void) const;
  // IsInitializerCapture: (bool)
  bool IsMutable(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(LambdaExpr)
};

static_assert(sizeof(Stmt) == sizeof(LambdaExpr));

class MSAsmStmt : public AsmStmt {
 private:
  using AsmStmt::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSAsmStmt)
  PASTA_DECLARE_BASE_OPERATORS(AsmStmt, MSAsmStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MSAsmStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  std::string GenerateAssemblyString(void) const;
  std::vector<std::string_view> AllConstraints(void) const;
  std::vector<::pasta::Expr> AllExpressions(void) const;
  std::string_view AssemblyString(void) const;
  ::pasta::Token BeginToken(void) const;
  // Clobber: (llvm::StringRef)
  std::vector<std::string_view> Clobbers(void) const;
  ::pasta::Token EndToken(void) const;
  // InputConstraint: (llvm::StringRef)
  // InputExpression: (const clang::Expr *)
  ::pasta::Token LBraceToken(void) const;
  // OutputConstraint: (llvm::StringRef)
  // OutputExpression: (const clang::Expr *)
  bool HasBraces(void) const;
  std::vector<std::string_view> OutputConstraints(void) const;
  std::vector<::pasta::Expr> OutputExpressions(void) const;
  std::vector<std::string_view> InputConstraints(void) const;
  std::vector<::pasta::Expr> InputExpressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MSAsmStmt)
};

static_assert(sizeof(Stmt) == sizeof(MSAsmStmt));

class MSDependentExistsStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSDependentExistsStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MSDependentExistsStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token KeywordToken(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::CompoundStmt SubStatement(void) const;
  bool IsIfExists(void) const;
  bool IsIfNotExists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MSDependentExistsStmt)
};

static_assert(sizeof(Stmt) == sizeof(MSDependentExistsStmt));

class MSPropertyRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSPropertyRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, MSPropertyRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MSPropertyRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, MSPropertyRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr BaseExpression(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token MemberToken(void) const;
  ::pasta::MSPropertyDecl PropertyDeclaration(void) const;
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  bool IsArrow(void) const;
  bool IsImplicitAccess(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MSPropertyRefExpr)
};

static_assert(sizeof(Stmt) == sizeof(MSPropertyRefExpr));

class MSPropertySubscriptExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSPropertySubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, MSPropertySubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MSPropertySubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, MSPropertySubscriptExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Expr Index(void) const;
  ::pasta::Token RBracketToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MSPropertySubscriptExpr)
};

static_assert(sizeof(Stmt) == sizeof(MSPropertySubscriptExpr));

class MaterializeTemporaryExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MaterializeTemporaryExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, MaterializeTemporaryExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MaterializeTemporaryExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, MaterializeTemporaryExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::ValueDecl ExtendingDeclaration(void) const;
  ::pasta::LifetimeExtendedTemporaryDecl LifetimeExtendedTemporaryDeclaration(void) const;
  uint32_t ManglingNumber(void) const;
  // OrCreateValue: (clang::APValue *)
  enum StorageDuration StorageDuration(void) const;
  ::pasta::Expr SubExpression(void) const;
  bool IsBoundToLvalueReference(void) const;
  bool IsUsableInConstantExpressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MaterializeTemporaryExpr)
};

static_assert(sizeof(Stmt) == sizeof(MaterializeTemporaryExpr));

class MatrixSubscriptExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MatrixSubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, MatrixSubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MatrixSubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, MatrixSubscriptExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr ColumnIndex(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Token RBracketToken(void) const;
  ::pasta::Expr RowIndex(void) const;
  bool IsIncomplete(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MatrixSubscriptExpr)
};

static_assert(sizeof(Stmt) == sizeof(MatrixSubscriptExpr));

class MemberExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, MemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, MemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, MemberExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  // FoundDeclaration: (clang::DeclAccessPair)
  ::pasta::Token LAngleToken(void) const;
  ::pasta::ValueDecl MemberDeclaration(void) const;
  ::pasta::Token MemberToken(void) const;
  // MemberNameInfo: (clang::DeclarationNameInfo)
  uint32_t NumTemplateArguments(void) const;
  ::pasta::Token OperatorToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArguments: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HadMultipleCandidates(void) const;
  bool HasExplicitTemplateArguments(void) const;
  bool HasQualifier(void) const;
  bool HasTemplateKeyword(void) const;
  bool IsArrow(void) const;
  bool IsImplicitAccess(void) const;
  enum NonOdrUseReason IsNonOdrUse(void) const;
  // PerformsVirtualDispatch: (bool)
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(MemberExpr)
};

static_assert(sizeof(Stmt) == sizeof(MemberExpr));

class NoInitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NoInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, NoInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, NoInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, NoInitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(NoInitExpr)
};

static_assert(sizeof(Stmt) == sizeof(NoInitExpr));

class NullStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NullStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, NullStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token SemiToken(void) const;
  bool HasLeadingEmptyMacro(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(NullStmt)
};

static_assert(sizeof(Stmt) == sizeof(NullStmt));

class OMPArraySectionExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPArraySectionExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, OMPArraySectionExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPArraySectionExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, OMPArraySectionExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token ColonTokenFirst(void) const;
  ::pasta::Token ColonTokenSecond(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Expr Length(void) const;
  ::pasta::Expr LowerBound(void) const;
  ::pasta::Token RBracketToken(void) const;
  ::pasta::Expr Stride(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPArraySectionExpr)
};

static_assert(sizeof(Stmt) == sizeof(OMPArraySectionExpr));

class OMPArrayShapingExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPArrayShapingExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, OMPArrayShapingExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPArrayShapingExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, OMPArrayShapingExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  std::vector<::pasta::TokenRange> BracketsRanges(void) const;
  std::vector<::pasta::Expr> Dimensions(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPArrayShapingExpr)
};

static_assert(sizeof(Stmt) == sizeof(OMPArrayShapingExpr));

class OMPCanonicalLoop : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCanonicalLoop)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPCanonicalLoop)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::CapturedStmt DistanceFunc(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt LoopStatement(void) const;
  ::pasta::CapturedStmt LoopVariableFunc(void) const;
  ::pasta::DeclRefExpr LoopVariableReference(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPCanonicalLoop)
};

static_assert(sizeof(Stmt) == sizeof(OMPCanonicalLoop));

class OMPExecutableDirective : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPExecutableDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPExecutableDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPAtomicDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPBarrierDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPCancelDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPCancellationPointDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPCriticalDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDepobjDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDispatchDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPFlushDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPInteropDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPLoopBasedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMaskedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPOrderedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMasterDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelSectionsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPScanDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSectionDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSectionsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSingleDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetDataDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetEnterDataDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetExitDataDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetUpdateDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskgroupDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskwaitDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskyieldDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTileDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPExecutableDirective, OMPUnrollDirective)
  std::vector<::pasta::Stmt> Children(void) const;
  // Clauses: (llvm::ArrayRef<clang::OMPClause *>)
  ::pasta::Stmt AssociatedStatement(void) const;
  ::pasta::Token BeginToken(void) const;
  // CapturedStatement: (const clang::CapturedStmt *)
  // Clause: (clang::OMPClause *)
  // DirectiveKind: (llvm::omp::Directive)
  ::pasta::Token EndToken(void) const;
  ::pasta::CapturedStmt InnermostCapturedStatement(void) const;
  uint32_t NumClauses(void) const;
  ::pasta::Stmt RawStatement(void) const;
  ::pasta::Stmt StructuredBlock(void) const;
  bool HasAssociatedStatement(void) const;
  bool IsStandaloneDirective(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPExecutableDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPExecutableDirective));

class OMPFlushDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPFlushDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPFlushDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPFlushDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPFlushDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPFlushDirective));

class OMPInteropDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPInteropDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPInteropDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPInteropDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPInteropDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPInteropDirective));

class OMPIteratorExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPIteratorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, OMPIteratorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPIteratorExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, OMPIteratorExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  // AssignToken: (clang::SourceLocation)
  ::pasta::Token BeginToken(void) const;
  // ColonToken: (clang::SourceLocation)
  ::pasta::Token EndToken(void) const;
  // Helper: (const clang::OMPIteratorHelperData &)
  // IteratorDeclaration: (const clang::Decl *)
  ::pasta::Token IteratorKwToken(void) const;
  // IteratorRange: (const clang::OMPIteratorExpr::IteratorRange)
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  // SecondColonToken: (clang::SourceLocation)
  uint32_t NumOfIterators(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPIteratorExpr)
};

static_assert(sizeof(Stmt) == sizeof(OMPIteratorExpr));

class OMPLoopBasedDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPLoopBasedDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPLoopBasedDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPLoopBasedDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTileDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPUnrollDirective)
  uint32_t LoopsNumber(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPLoopBasedDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPLoopBasedDirective));

class OMPLoopDirective : public OMPLoopBasedDirective {
 private:
  using OMPLoopBasedDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTaskLoopDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeSimdDirective)
  std::vector<::pasta::Expr> Counters(void) const;
  std::vector<::pasta::Expr> DependentCounters(void) const;
  std::vector<::pasta::Expr> DependentInitializers(void) const;
  std::vector<::pasta::Expr> Finals(void) const;
  std::vector<::pasta::Expr> FinalsConditions(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr CalculateLastIteration(void) const;
  ::pasta::Expr CombinedCondition(void) const;
  ::pasta::Expr CombinedDistanceCondition(void) const;
  ::pasta::Expr CombinedEnsureUpperBound(void) const;
  ::pasta::Expr CombinedInitializer(void) const;
  ::pasta::Expr CombinedLowerBoundVariable(void) const;
  ::pasta::Expr CombinedNextLowerBound(void) const;
  ::pasta::Expr CombinedNextUpperBound(void) const;
  ::pasta::Expr CombinedParallelForInDistanceCondition(void) const;
  ::pasta::Expr CombinedUpperBoundVariable(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Expr DistanceIncrement(void) const;
  ::pasta::Expr EnsureUpperBound(void) const;
  ::pasta::Expr Increment(void) const;
  ::pasta::Expr Initializer(void) const;
  ::pasta::Expr IsLastIterationVariable(void) const;
  ::pasta::Expr IterationVariable(void) const;
  ::pasta::Expr LastIteration(void) const;
  ::pasta::Expr LowerBoundVariable(void) const;
  ::pasta::Expr NextLowerBound(void) const;
  ::pasta::Expr NextUpperBound(void) const;
  ::pasta::Expr NumIterations(void) const;
  ::pasta::Expr PreCondition(void) const;
  ::pasta::Stmt PreInitializers(void) const;
  ::pasta::Expr PrevEnsureUpperBound(void) const;
  ::pasta::Expr PrevLowerBoundVariable(void) const;
  ::pasta::Expr PrevUpperBoundVariable(void) const;
  ::pasta::Expr StrideVariable(void) const;
  ::pasta::Expr UpperBoundVariable(void) const;
  std::vector<::pasta::Expr> Initializers(void) const;
  std::vector<::pasta::Expr> PrivateCounters(void) const;
  std::vector<::pasta::Expr> Updates(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPLoopDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPLoopDirective));

class OMPMaskedDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPMaskedDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPMaskedDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPMaskedDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPMaskedDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPMaskedDirective));

class OMPMasterDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPMasterDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPMasterDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPMasterDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPMasterDirective));

class OMPMasterTaskLoopDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPMasterTaskLoopDirective)
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPMasterTaskLoopDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPMasterTaskLoopDirective));

class OMPMasterTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPMasterTaskLoopSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPMasterTaskLoopSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPMasterTaskLoopSimdDirective));

class OMPOrderedDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPOrderedDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPOrderedDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPOrderedDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPOrderedDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPOrderedDirective));

class OMPParallelDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelDirective));

class OMPParallelForDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelForDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelForDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelForDirective));

class OMPParallelForSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelForSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelForSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelForSimdDirective));

class OMPParallelMasterDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelMasterDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelMasterDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelMasterDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelMasterDirective));

class OMPParallelMasterTaskLoopDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelMasterTaskLoopDirective)
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelMasterTaskLoopDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelMasterTaskLoopDirective));

class OMPParallelMasterTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelMasterTaskLoopSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelMasterTaskLoopSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelMasterTaskLoopSimdDirective));

class OMPParallelSectionsDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPParallelSectionsDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelSectionsDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPParallelSectionsDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPParallelSectionsDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPParallelSectionsDirective));

class OMPScanDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPScanDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPScanDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPScanDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPScanDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPScanDirective));

class OMPSectionDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPSectionDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPSectionDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPSectionDirective)
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPSectionDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPSectionDirective));

class OMPSectionsDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPSectionsDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPSectionsDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPSectionsDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPSectionsDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPSectionsDirective));

class OMPSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPSimdDirective));

class OMPSingleDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPSingleDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPSingleDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPSingleDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPSingleDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPSingleDirective));

class OMPTargetDataDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetDataDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetDataDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetDataDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetDataDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetDataDirective));

class OMPTargetDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetDirective));

class OMPTargetEnterDataDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetEnterDataDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetEnterDataDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetEnterDataDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetEnterDataDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetEnterDataDirective));

class OMPTargetExitDataDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetExitDataDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetExitDataDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetExitDataDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetExitDataDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetExitDataDirective));

class OMPTargetParallelDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetParallelDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetParallelDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetParallelDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetParallelDirective));

class OMPTargetParallelForDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetParallelForDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetParallelForDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetParallelForDirective));

class OMPTargetParallelForSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetParallelForSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetParallelForSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetParallelForSimdDirective));

class OMPTargetSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetSimdDirective));

class OMPTargetTeamsDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetTeamsDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetTeamsDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetTeamsDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetTeamsDirective));

class OMPTargetTeamsDistributeDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetTeamsDistributeDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetTeamsDistributeDirective));

class OMPTargetTeamsDistributeParallelForDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetTeamsDistributeParallelForDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetTeamsDistributeParallelForDirective));

class OMPTargetTeamsDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetTeamsDistributeParallelForSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetTeamsDistributeParallelForSimdDirective));

class OMPTargetTeamsDistributeSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetTeamsDistributeSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetTeamsDistributeSimdDirective));

class OMPTargetUpdateDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTargetUpdateDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetUpdateDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTargetUpdateDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTargetUpdateDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTargetUpdateDirective));

class OMPTaskDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTaskDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTaskDirective)
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTaskDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTaskDirective));

class OMPTaskLoopDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTaskLoopDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTaskLoopDirective)
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTaskLoopDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTaskLoopDirective));

class OMPTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTaskLoopSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTaskLoopSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTaskLoopSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTaskLoopSimdDirective));

class OMPTaskgroupDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTaskgroupDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskgroupDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTaskgroupDirective)
  ::pasta::Expr ReductionReference(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTaskgroupDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTaskgroupDirective));

class OMPTaskwaitDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTaskwaitDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskwaitDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTaskwaitDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTaskwaitDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTaskwaitDirective));

class OMPTaskyieldDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTaskyieldDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskyieldDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTaskyieldDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTaskyieldDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTaskyieldDirective));

class OMPTeamsDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTeamsDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTeamsDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTeamsDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTeamsDirective));

class OMPTeamsDistributeDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTeamsDistributeDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTeamsDistributeDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTeamsDistributeDirective));

class OMPTeamsDistributeParallelForDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTeamsDistributeParallelForDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTeamsDistributeParallelForDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTeamsDistributeParallelForDirective));

class OMPTeamsDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTeamsDistributeParallelForSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTeamsDistributeParallelForSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTeamsDistributeParallelForSimdDirective));

class OMPTeamsDistributeSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTeamsDistributeSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTeamsDistributeSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTeamsDistributeSimdDirective));

class OMPTileDirective : public OMPLoopBasedDirective {
 private:
  using OMPLoopBasedDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPTileDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPTileDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTileDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPTileDirective)
  uint32_t NumAssociatedLoops(void) const;
  ::pasta::Stmt PreInitializers(void) const;
  ::pasta::Stmt TransformedStatement(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPTileDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPTileDirective));

class OMPUnrollDirective : public OMPLoopBasedDirective {
 private:
  using OMPLoopBasedDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPUnrollDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPUnrollDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPUnrollDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPUnrollDirective)
  ::pasta::Stmt PreInitializers(void) const;
  ::pasta::Stmt TransformedStatement(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPUnrollDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPUnrollDirective));

class ObjCArrayLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCArrayLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCArrayLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCArrayLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCArrayLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::ObjCMethodDecl ArrayWithObjectsMethod(void) const;
  ::pasta::Token BeginToken(void) const;
  // Element: (const clang::Expr *)
  // Elements: (const clang::Expr *const *)
  ::pasta::Token EndToken(void) const;
  uint32_t NumElements(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  std::vector<::pasta::Expr> Elements(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCArrayLiteral)
};

static_assert(sizeof(Stmt) == sizeof(ObjCArrayLiteral));

class ObjCAtCatchStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtCatchStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAtCatchStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtCatchToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt CatchBody(void) const;
  ::pasta::VarDecl CatchParamDeclaration(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
  bool HasEllipsis(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAtCatchStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAtCatchStmt));

class ObjCAtFinallyStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtFinallyStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAtFinallyStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtFinallyToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt FinallyBody(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAtFinallyStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAtFinallyStmt));

class ObjCAtSynchronizedStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtSynchronizedStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAtSynchronizedStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtSynchronizedToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::CompoundStmt SynchBody(void) const;
  ::pasta::Expr SynchExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAtSynchronizedStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAtSynchronizedStmt));

class ObjCAtThrowStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtThrowStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAtThrowStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr ThrowExpression(void) const;
  ::pasta::Token ThrowToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAtThrowStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAtThrowStmt));

class ObjCAtTryStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtTryStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAtTryStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtTryToken(void) const;
  ::pasta::Token BeginToken(void) const;
  // CatchStatement: (const clang::ObjCAtCatchStmt *)
  ::pasta::Token EndToken(void) const;
  ::pasta::ObjCAtFinallyStmt FinallyStatement(void) const;
  uint32_t NumCatchStatements(void) const;
  ::pasta::Stmt TryBody(void) const;
  std::vector<::pasta::ObjCAtCatchStmt> CatchStatements(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAtTryStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAtTryStmt));

class ObjCAutoreleasePoolStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAutoreleasePoolStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAutoreleasePoolStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt SubStatement(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAutoreleasePoolStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAutoreleasePoolStmt));

class ObjCAvailabilityCheckExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCAvailabilityCheckExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasVersion(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCAvailabilityCheckExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCAvailabilityCheckExpr));

class ObjCBoolLiteralExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBoolLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCBoolLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCBoolLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCBoolLiteralExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  bool Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCBoolLiteralExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCBoolLiteralExpr));

class ObjCBoxedExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBoxedExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCBoxedExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCBoxedExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCBoxedExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ObjCMethodDecl BoxingMethod(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Expr SubExpression(void) const;
  bool IsExpressibleAsConstantInitializer(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCBoxedExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCBoxedExpr));

class ObjCDictionaryLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCDictionaryLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCDictionaryLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCDictionaryLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCDictionaryLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ObjCMethodDecl DictionaryWithObjectsMethod(void) const;
  ::pasta::Token EndToken(void) const;
  // KeyValueElement: (clang::ObjCDictionaryElement)
  uint32_t NumElements(void) const;
  ::pasta::TokenRange TokenRange(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCDictionaryLiteral)
};

static_assert(sizeof(Stmt) == sizeof(ObjCDictionaryLiteral));

class ObjCEncodeExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCEncodeExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCEncodeExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCEncodeExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCEncodeExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Type EncodedType(void) const;
  // EncodedTypeSourceInfo: (clang::TypeSourceInfo *)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCEncodeExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCEncodeExpr));

class ObjCForCollectionStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCForCollectionStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCForCollectionStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Collection(void) const;
  ::pasta::Stmt Element(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ForToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCForCollectionStmt)
};

static_assert(sizeof(Stmt) == sizeof(ObjCForCollectionStmt));

class ObjCIndirectCopyRestoreExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCIndirectCopyRestoreExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Expr SubExpression(void) const;
  bool ShouldCopy(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCIndirectCopyRestoreExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCIndirectCopyRestoreExpr));

class ObjCIsaExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCIsaExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCIsaExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCIsaExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCIsaExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BaseTokenEnd(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Token IsaMemberToken(void) const;
  ::pasta::Token OperationToken(void) const;
  bool IsArrow(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCIsaExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCIsaExpr));

class ObjCIvarRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCIvarRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCIvarRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCIvarRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCIvarRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ObjCIvarDecl Declaration(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  ::pasta::Token OperationToken(void) const;
  bool IsArrow(void) const;
  bool IsFreeInstanceVariable(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCIvarRefExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCIvarRefExpr));

class ObjCMessageExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCMessageExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCMessageExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCMessageExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCMessageExpr)
  std::vector<::pasta::Expr> Arguments(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  // Argument: (const clang::Expr *)
  // Arguments: (const clang::Expr *const *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Type CallReturnType(void) const;
  ::pasta::Type ClassReceiver(void) const;
  // ClassReceiverTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr InstanceReceiver(void) const;
  ::pasta::Token LeftToken(void) const;
  ::pasta::ObjCMethodDecl MethodDeclaration(void) const;
  enum ObjCMethodFamily MethodFamily(void) const;
  uint32_t NumArguments(void) const;
  uint32_t NumSelectorTokens(void) const;
  ::pasta::ObjCInterfaceDecl ReceiverInterface(void) const;
  // ReceiverKind: (clang::ObjCMessageExpr::ReceiverKind)
  ::pasta::TokenRange ReceiverRange(void) const;
  ::pasta::Type ReceiverType(void) const;
  ::pasta::Token RightToken(void) const;
  // Selector: (clang::Selector)
  // SelectorToken: (clang::SourceLocation)
  ::pasta::Token SelectorStartToken(void) const;
  ::pasta::Token SuperToken(void) const;
  ::pasta::Type SuperType(void) const;
  bool IsClassMessage(void) const;
  bool IsDelegateInitializerCall(void) const;
  bool IsImplicit(void) const;
  bool IsInstanceMessage(void) const;
  std::vector<::pasta::Token> SelectorTokens(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCMessageExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCMessageExpr));

class ObjCPropertyRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPropertyRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCPropertyRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCPropertyRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCPropertyRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ObjCInterfaceDecl ClassReceiver(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::ObjCPropertyDecl ExplicitProperty(void) const;
  // GetterSelector: (clang::Selector)
  ::pasta::ObjCMethodDecl ImplicitPropertyGetter(void) const;
  ::pasta::ObjCMethodDecl ImplicitPropertySetter(void) const;
  ::pasta::Token Token(void) const;
  ::pasta::Token ReceiverToken(void) const;
  ::pasta::Type ReceiverType(void) const;
  // SetterSelector: (clang::Selector)
  ::pasta::Type SuperReceiverType(void) const;
  bool IsClassReceiver(void) const;
  bool IsExplicitProperty(void) const;
  bool IsImplicitProperty(void) const;
  bool IsMessagingGetter(void) const;
  bool IsMessagingSetter(void) const;
  bool IsObjectReceiver(void) const;
  bool IsSuperReceiver(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCPropertyRefExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCPropertyRefExpr));

class ObjCProtocolExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCProtocolExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCProtocolExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCProtocolExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCProtocolExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::ObjCProtocolDecl Protocol(void) const;
  ::pasta::Token ProtocolIdToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCProtocolExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCProtocolExpr));

class ObjCSelectorExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCSelectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCSelectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCSelectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCSelectorExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  uint32_t NumArguments(void) const;
  ::pasta::Token RParenToken(void) const;
  // Selector: (clang::Selector)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCSelectorExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCSelectorExpr));

class ObjCStringLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCStringLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCStringLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCStringLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCStringLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::StringLiteral String(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCStringLiteral)
};

static_assert(sizeof(Stmt) == sizeof(ObjCStringLiteral));

class ObjCSubscriptRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCSubscriptRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCSubscriptRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCSubscriptRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCSubscriptRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::ObjCMethodDecl AtIndexMethodDeclaration(void) const;
  ::pasta::Expr BaseExpression(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr KeyExpression(void) const;
  ::pasta::Token RBracket(void) const;
  bool IsArraySubscriptReferenceExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCSubscriptRefExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCSubscriptRefExpr));

class OffsetOfExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OffsetOfExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, OffsetOfExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OffsetOfExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, OffsetOfExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  // Component: (const clang::OffsetOfNode &)
  ::pasta::Token EndToken(void) const;
  // IndexExpression: (const clang::Expr *)
  uint32_t NumComponents(void) const;
  uint32_t NumExpressions(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Token RParenToken(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  // !!! Component getNumComponents getComponent (empty ret type = (const clang::OffsetOfNode &))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OffsetOfExpr)
};

static_assert(sizeof(Stmt) == sizeof(OffsetOfExpr));

class OpaqueValueExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OpaqueValueExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, OpaqueValueExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OpaqueValueExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, OpaqueValueExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Token Token(void) const;
  ::pasta::Expr SourceExpression(void) const;
  bool IsUnique(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OpaqueValueExpr)
};

static_assert(sizeof(Stmt) == sizeof(OpaqueValueExpr));

class OverloadExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OverloadExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, OverloadExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OverloadExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, OverloadExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(OverloadExpr, UnresolvedLookupExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(OverloadExpr, UnresolvedMemberExpr)
  // Declarations: (llvm::iterator_range<clang::UnresolvedSetIterator>)
  ::pasta::Token LAngleToken(void) const;
  // Name: (clang::DeclarationName)
  // NameInfo: (const clang::DeclarationNameInfo &)
  ::pasta::Token NameToken(void) const;
  ::pasta::CXXRecordDecl NamingClass(void) const;
  uint32_t NumDeclarations(void) const;
  uint32_t NumTemplateArguments(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArguments: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HasExplicitTemplateArguments(void) const;
  bool HasTemplateKeyword(void) const;
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OverloadExpr)
};

static_assert(sizeof(Stmt) == sizeof(OverloadExpr));

class PackExpansionExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PackExpansionExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, PackExpansionExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, PackExpansionExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, PackExpansionExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::Token EndToken(void) const;
  std::optional<unsigned> NumExpansions(void) const;
  ::pasta::Expr Pattern(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(PackExpansionExpr)
};

static_assert(sizeof(Stmt) == sizeof(PackExpansionExpr));

class ParenExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParenExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ParenExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ParenExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ParenExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParen(void) const;
  ::pasta::Token RParen(void) const;
  ::pasta::Expr SubExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ParenExpr)
};

static_assert(sizeof(Stmt) == sizeof(ParenExpr));

class ParenListExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParenListExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ParenListExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ParenListExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ParenListExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Expression: (const clang::Expr *)
  ::pasta::Token LParenToken(void) const;
  uint32_t NumExpressions(void) const;
  ::pasta::Token RParenToken(void) const;
  std::vector<::pasta::Expr> Expressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ParenListExpr)
};

static_assert(sizeof(Stmt) == sizeof(ParenListExpr));

class PredefinedExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PredefinedExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, PredefinedExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, PredefinedExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, PredefinedExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::StringLiteral FunctionName(void) const;
  // IdentifierKind: (clang::PredefinedExpr::IdentKind)
  std::string_view IdentifierKindName(void) const;
  ::pasta::Token Token(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(PredefinedExpr)
};

static_assert(sizeof(Stmt) == sizeof(PredefinedExpr));

class PseudoObjectExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PseudoObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, PseudoObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, PseudoObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, PseudoObjectExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  uint32_t NumSemanticExpressions(void) const;
  ::pasta::Expr ResultExpression(void) const;
  uint32_t ResultExpressionIndex(void) const;
  // SemanticExpression: (const clang::Expr *)
  ::pasta::Expr SyntacticForm(void) const;
  std::vector<::pasta::Expr> Semantics(void) const;
  std::vector<::pasta::Expr> SemanticExpressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(PseudoObjectExpr)
};

static_assert(sizeof(Stmt) == sizeof(PseudoObjectExpr));

class RecoveryExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RecoveryExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, RecoveryExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, RecoveryExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, RecoveryExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  std::vector<::pasta::Expr> SubExpressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(RecoveryExpr)
};

static_assert(sizeof(Stmt) == sizeof(RecoveryExpr));

class RequiresExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RequiresExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, RequiresExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, RequiresExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, RequiresExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::RequiresExprBodyDecl Body(void) const;
  ::pasta::Token EndToken(void) const;
  std::vector<::pasta::ParmVarDecl> LocalParameters(void) const;
  ::pasta::Token RBraceToken(void) const;
  // Requirements: (llvm::ArrayRef<clang::concepts::Requirement *>)
  ::pasta::Token RequiresKWToken(void) const;
  bool IsSatisfied(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(RequiresExpr)
};

static_assert(sizeof(Stmt) == sizeof(RequiresExpr));

class ReturnStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReturnStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ReturnStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::VarDecl NRVOCandidate(void) const;
  ::pasta::Expr RetValue(void) const;
  ::pasta::Token ReturnToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ReturnStmt)
};

static_assert(sizeof(Stmt) == sizeof(ReturnStmt));

class SEHExceptStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SEHExceptStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SEHExceptStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::CompoundStmt Block(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExceptToken(void) const;
  ::pasta::Expr FilterExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SEHExceptStmt)
};

static_assert(sizeof(Stmt) == sizeof(SEHExceptStmt));

class SEHFinallyStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SEHFinallyStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SEHFinallyStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::CompoundStmt Block(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token FinallyToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SEHFinallyStmt)
};

static_assert(sizeof(Stmt) == sizeof(SEHFinallyStmt));

class SEHLeaveStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SEHLeaveStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SEHLeaveStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LeaveToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SEHLeaveStmt)
};

static_assert(sizeof(Stmt) == sizeof(SEHLeaveStmt));

class SEHTryStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SEHTryStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SEHTryStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::SEHExceptStmt ExceptHandler(void) const;
  ::pasta::SEHFinallyStmt FinallyHandler(void) const;
  ::pasta::Stmt Handler(void) const;
  bool IsCXXTry(void) const;
  ::pasta::CompoundStmt TryBlock(void) const;
  ::pasta::Token TryToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SEHTryStmt)
};

static_assert(sizeof(Stmt) == sizeof(SEHTryStmt));

class SYCLUniqueStableNameExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SYCLUniqueStableNameExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, SYCLUniqueStableNameExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SYCLUniqueStableNameExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, SYCLUniqueStableNameExpr)
  std::string ComputeName(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token Token(void) const;
  ::pasta::Token RParenToken(void) const;
  // TypeSourceInfo: (const clang::TypeSourceInfo *)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SYCLUniqueStableNameExpr)
};

static_assert(sizeof(Stmt) == sizeof(SYCLUniqueStableNameExpr));

class ShuffleVectorExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ShuffleVectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ShuffleVectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ShuffleVectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ShuffleVectorExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BuiltinToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Expression: (const clang::Expr *)
  uint32_t NumSubExpressions(void) const;
  ::pasta::Token RParenToken(void) const;
  // ShuffleMaskIndex: (llvm::APSInt)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ShuffleVectorExpr)
};

static_assert(sizeof(Stmt) == sizeof(ShuffleVectorExpr));

class SizeOfPackExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SizeOfPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, SizeOfPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SizeOfPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, SizeOfPackExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::NamedDecl Pack(void) const;
  uint32_t PackLength(void) const;
  ::pasta::Token PackToken(void) const;
  // PartialArguments: (llvm::ArrayRef<clang::TemplateArgument>)
  ::pasta::Token RParenToken(void) const;
  bool IsPartiallySubstituted(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SizeOfPackExpr)
};

static_assert(sizeof(Stmt) == sizeof(SizeOfPackExpr));

class SourceLocExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SourceLocExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, SourceLocExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SourceLocExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, SourceLocExpr)
  // EvaluateInContext: (clang::APValue)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  std::string_view BuiltinString(void) const;
  ::pasta::Token EndToken(void) const;
  // IdentifierKind: (clang::SourceLocExpr::IdentKind)
  ::pasta::Token Token(void) const;
  ::pasta::DeclContext ParentContext(void) const;
  bool IsIntType(void) const;
  bool IsStringType(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SourceLocExpr)
};

static_assert(sizeof(Stmt) == sizeof(SourceLocExpr));

class StmtExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StmtExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, StmtExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, StmtExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, StmtExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::CompoundStmt SubStatement(void) const;
  uint32_t TemplateDepth(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(StmtExpr)
};

static_assert(sizeof(Stmt) == sizeof(StmtExpr));

class StringLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StringLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, StringLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, StringLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, StringLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  bool ContainsNonAscii(void) const;
  bool ContainsNonAsciiOrNull(void) const;
  ::pasta::Token BeginToken(void) const;
  uint32_t ByteLength(void) const;
  std::string_view Bytes(void) const;
  uint32_t CharacterByteWidth(void) const;
  // CodeUnit: (unsigned int)
  ::pasta::Token EndToken(void) const;
  // Kind: (clang::StringLiteral::StringKind)
  uint32_t Length(void) const;
  // TokenOfByte: (clang::SourceLocation)
  uint32_t NumConcatenated(void) const;
  // StringTokenToken: (clang::SourceLocation)
  std::string_view String(void) const;
  bool IsAscii(void) const;
  bool IsPascal(void) const;
  bool IsUTF16(void) const;
  bool IsUTF32(void) const;
  bool IsUTF8(void) const;
  bool IsWide(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(StringLiteral)
};

static_assert(sizeof(Stmt) == sizeof(StringLiteral));

class SubstNonTypeTemplateParmExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, SubstNonTypeTemplateParmExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token NameToken(void) const;
  ::pasta::NonTypeTemplateParmDecl Parameter(void) const;
  ::pasta::Type ParameterType(void) const;
  ::pasta::Expr Replacement(void) const;
  bool IsReferenceParameter(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SubstNonTypeTemplateParmExpr)
};

static_assert(sizeof(Stmt) == sizeof(SubstNonTypeTemplateParmExpr));

class SubstNonTypeTemplateParmPackExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, SubstNonTypeTemplateParmPackExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  // ArgumentPack: (clang::TemplateArgument)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::NonTypeTemplateParmDecl ParameterPack(void) const;
  ::pasta::Token ParameterPackToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(SubstNonTypeTemplateParmPackExpr)
};

static_assert(sizeof(Stmt) == sizeof(SubstNonTypeTemplateParmPackExpr));

class TypeTraitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, TypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, TypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, TypeTraitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  // Argument: (clang::TypeSourceInfo *)
  // Arguments: (llvm::ArrayRef<clang::TypeSourceInfo *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  uint32_t NumArguments(void) const;
  enum TypeTrait Trait(void) const;
  bool Value(void) const;
  // !!! Arg getNumArgs getArg (empty ret type = (clang::TypeSourceInfo *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(TypeTraitExpr)
};

static_assert(sizeof(Stmt) == sizeof(TypeTraitExpr));

class TypoExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypoExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, TypoExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, TypoExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, TypoExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(TypoExpr)
};

static_assert(sizeof(Stmt) == sizeof(TypoExpr));

class UnaryExprOrTypeTraitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, UnaryExprOrTypeTraitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr ArgumentExpression(void) const;
  ::pasta::Type ArgumentType(void) const;
  // ArgumentTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  enum UnaryExprOrTypeTrait Kind(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Type TypeOfArgument(void) const;
  bool IsArgumentType(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(UnaryExprOrTypeTraitExpr)
};

static_assert(sizeof(Stmt) == sizeof(UnaryExprOrTypeTraitExpr));

class UnaryOperator : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, UnaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, UnaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, UnaryOperator)
  bool CanOverflow(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  // FPFeaturesInEffect: (clang::FPOptions)
  // FPOptionsOverride: (clang::FPOptionsOverride)
  enum UnaryOperatorKind Opcode(void) const;
  ::pasta::Token OperatorToken(void) const;
  // StoredFPFeatures: (clang::FPOptionsOverride)
  ::pasta::Expr SubExpression(void) const;
  bool HasStoredFPFeatures(void) const;
  bool IsArithmeticOperation(void) const;
  bool IsDecrementOperation(void) const;
  // IsFEnvAccessOn: (bool)
  // IsFPContractableWithinStatement: (bool)
  bool IsIncrementDecrementOperation(void) const;
  bool IsIncrementOperation(void) const;
  bool IsPostfix(void) const;
  bool IsPrefix(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(UnaryOperator)
};

static_assert(sizeof(Stmt) == sizeof(UnaryOperator));

class UnresolvedLookupExpr : public OverloadExpr {
 private:
  using OverloadExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedLookupExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, UnresolvedLookupExpr)
  PASTA_DECLARE_BASE_OPERATORS(OverloadExpr, UnresolvedLookupExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, UnresolvedLookupExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, UnresolvedLookupExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::CXXRecordDecl NamingClass(void) const;
  bool IsOverloaded(void) const;
  bool RequiresADL(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(UnresolvedLookupExpr)
};

static_assert(sizeof(Stmt) == sizeof(UnresolvedLookupExpr));

class UnresolvedMemberExpr : public OverloadExpr {
 private:
  using OverloadExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, UnresolvedMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(OverloadExpr, UnresolvedMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, UnresolvedMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, UnresolvedMemberExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Type BaseType(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Token MemberToken(void) const;
  // MemberName: (clang::DeclarationName)
  // MemberNameInfo: (const clang::DeclarationNameInfo &)
  ::pasta::CXXRecordDecl NamingClass(void) const;
  ::pasta::Token OperatorToken(void) const;
  bool HasUnresolvedUsing(void) const;
  bool IsArrow(void) const;
  bool IsImplicitAccess(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(UnresolvedMemberExpr)
};

static_assert(sizeof(Stmt) == sizeof(UnresolvedMemberExpr));

class VAArgExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VAArgExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, VAArgExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, VAArgExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, VAArgExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BuiltinToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr SubExpression(void) const;
  // WrittenTypeInfo: (clang::TypeSourceInfo *)
  bool IsMicrosoftABI(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(VAArgExpr)
};

static_assert(sizeof(Stmt) == sizeof(VAArgExpr));

class AbstractConditionalOperator : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AbstractConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, AbstractConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, AbstractConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, AbstractConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(AbstractConditionalOperator, BinaryConditionalOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(AbstractConditionalOperator, ConditionalOperator)
  ::pasta::Token ColonToken(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Expr FalseExpression(void) const;
  ::pasta::Token QuestionToken(void) const;
  ::pasta::Expr TrueExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(AbstractConditionalOperator)
};

static_assert(sizeof(Stmt) == sizeof(AbstractConditionalOperator));

class AddrLabelExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AddrLabelExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, AddrLabelExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, AddrLabelExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, AddrLabelExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AmpAmpToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::LabelDecl Label(void) const;
  ::pasta::Token LabelToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(AddrLabelExpr)
};

static_assert(sizeof(Stmt) == sizeof(AddrLabelExpr));

class ArrayInitIndexExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArrayInitIndexExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ArrayInitIndexExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ArrayInitIndexExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ArrayInitIndexExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ArrayInitIndexExpr)
};

static_assert(sizeof(Stmt) == sizeof(ArrayInitIndexExpr));

class ArrayInitLoopExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArrayInitLoopExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ArrayInitLoopExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ArrayInitLoopExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ArrayInitLoopExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  // ArraySize: (llvm::APInt)
  ::pasta::Token BeginToken(void) const;
  ::pasta::OpaqueValueExpr CommonExpression(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr SubExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ArrayInitLoopExpr)
};

static_assert(sizeof(Stmt) == sizeof(ArrayInitLoopExpr));

class ArraySubscriptExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArraySubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ArraySubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ArraySubscriptExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ArraySubscriptExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Expr Index(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Token RBracketToken(void) const;
  ::pasta::Expr RHS(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ArraySubscriptExpr)
};

static_assert(sizeof(Stmt) == sizeof(ArraySubscriptExpr));

class ArrayTypeTraitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArrayTypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ArrayTypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ArrayTypeTraitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ArrayTypeTraitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr DimensionExpression(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Type QueriedType(void) const;
  // QueriedTypeSourceInfo: (clang::TypeSourceInfo *)
  enum ArrayTypeTrait Trait(void) const;
  uint64_t Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ArrayTypeTraitExpr)
};

static_assert(sizeof(Stmt) == sizeof(ArrayTypeTraitExpr));

class AsTypeExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AsTypeExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, AsTypeExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, AsTypeExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, AsTypeExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BuiltinToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr SrcExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(AsTypeExpr)
};

static_assert(sizeof(Stmt) == sizeof(AsTypeExpr));

class AtomicExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AtomicExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, AtomicExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, AtomicExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, AtomicExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BuiltinToken(void) const;
  ::pasta::Token EndToken(void) const;
  uint32_t NumSubExpressions(void) const;
  // Operation: (clang::AtomicExpr::AtomicOp)
  ::pasta::Expr Order(void) const;
  ::pasta::Expr OrderFail(void) const;
  ::pasta::Expr Pointer(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr Scope(void) const;
  // ScopeModel: (std::unique_ptr<clang::AtomicScopeModel, std::default_delete<clang::AtomicScopeModel>>)
  // SubExpressions: (const clang::Expr *const *)
  ::pasta::Expr Val1(void) const;
  ::pasta::Expr Val2(void) const;
  ::pasta::Type ValueType(void) const;
  ::pasta::Expr Weak(void) const;
  bool IsCmpXChg(void) const;
  bool IsOpenCL(void) const;
  bool IsVolatile(void) const;
  std::vector<::pasta::Expr> SubExpressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(AtomicExpr)
};

static_assert(sizeof(Stmt) == sizeof(AtomicExpr));

class BinaryConditionalOperator : public AbstractConditionalOperator {
 private:
  using AbstractConditionalOperator::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BinaryConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(AbstractConditionalOperator, BinaryConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, BinaryConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, BinaryConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, BinaryConditionalOperator)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr Common(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr FalseExpression(void) const;
  ::pasta::OpaqueValueExpr OpaqueValue(void) const;
  ::pasta::Expr TrueExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(BinaryConditionalOperator)
};

static_assert(sizeof(Stmt) == sizeof(BinaryConditionalOperator));

class BinaryOperator : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BinaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, BinaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, BinaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, BinaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(BinaryOperator, CompoundAssignOperator)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  // FPFeatures: (clang::FPOptionsOverride)
  // FPFeaturesInEffect: (clang::FPOptions)
  ::pasta::Expr LHS(void) const;
  enum BinaryOperatorKind Opcode(void) const;
  std::string_view OpcodeString(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Expr RHS(void) const;
  // StoredFPFeatures: (clang::FPOptionsOverride)
  bool HasStoredFPFeatures(void) const;
  bool IsAdditiveOperation(void) const;
  bool IsAssignmentOperation(void) const;
  bool IsBitwiseOperation(void) const;
  bool IsCommaOperation(void) const;
  bool IsComparisonOperation(void) const;
  bool IsCompoundAssignmentOperation(void) const;
  bool IsEqualityOperation(void) const;
  // IsFEnvAccessOn: (bool)
  // IsFPContractableWithinStatement: (bool)
  bool IsLogicalOperation(void) const;
  bool IsMultiplicativeOperation(void) const;
  bool IsPointerMemoryOperation(void) const;
  bool IsRelationalOperation(void) const;
  bool IsShiftAssignOperation(void) const;
  bool IsShiftOperation(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(BinaryOperator)
};

static_assert(sizeof(Stmt) == sizeof(BinaryOperator));

class BlockExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BlockExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, BlockExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, BlockExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, BlockExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::BlockDecl BlockDeclaration(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Token CaretToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::FunctionProtoType FunctionType(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(BlockExpr)
};

static_assert(sizeof(Stmt) == sizeof(BlockExpr));

class CXXBindTemporaryExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXBindTemporaryExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXBindTemporaryExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXBindTemporaryExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXBindTemporaryExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr SubExpression(void) const;
  // Temporary: (const clang::CXXTemporary *)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXBindTemporaryExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXBindTemporaryExpr));

class CXXBoolLiteralExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXBoolLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXBoolLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXBoolLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXBoolLiteralExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  bool Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXBoolLiteralExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXBoolLiteralExpr));

class CXXConstructExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXConstructExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXConstructExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXConstructExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXConstructExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXConstructExpr, CXXTemporaryObjectExpr)
  std::vector<::pasta::Expr> Arguments(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  // Argument: (const clang::Expr *)
  // Arguments: (const clang::Expr *const *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::ConstructionKind ConstructionKind(void) const;
  ::pasta::CXXConstructorDecl Constructor(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  uint32_t NumArguments(void) const;
  ::pasta::TokenRange ParenthesisOrBraceRange(void) const;
  bool HadMultipleCandidates(void) const;
  bool IsElidable(void) const;
  bool IsListInitialization(void) const;
  bool IsStdInitializerListInitialization(void) const;
  bool RequiresZeroInitialization(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXConstructExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXConstructExpr));

class CXXDefaultArgExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDefaultArgExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXDefaultArgExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXDefaultArgExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXDefaultArgExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr Expression(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::ParmVarDecl Param(void) const;
  ::pasta::DeclContext UsedContext(void) const;
  ::pasta::Token UsedToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXDefaultArgExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXDefaultArgExpr));

class CXXDefaultInitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDefaultInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXDefaultInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXDefaultInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXDefaultInitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr Expression(void) const;
  ::pasta::FieldDecl Field(void) const;
  ::pasta::DeclContext UsedContext(void) const;
  ::pasta::Token UsedToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXDefaultInitExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXDefaultInitExpr));

class CXXDeleteExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDeleteExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXDeleteExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXDeleteExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXDeleteExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  bool DoesUsualArrayDeleteWantSize(void) const;
  ::pasta::Expr Argument(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Type DestroyedType(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::FunctionDecl OperatorDelete(void) const;
  bool IsArrayForm(void) const;
  bool IsArrayFormAsWritten(void) const;
  bool IsGlobalDelete(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXDeleteExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXDeleteExpr));

class CXXDependentScopeMemberExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDependentScopeMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXDependentScopeMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXDependentScopeMemberExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXDependentScopeMemberExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Type BaseType(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::NamedDecl FirstQualifierFoundInScope(void) const;
  ::pasta::Token LAngleToken(void) const;
  // Member: (clang::DeclarationName)
  ::pasta::Token MemberToken(void) const;
  // MemberNameInfo: (const clang::DeclarationNameInfo &)
  uint32_t NumTemplateArguments(void) const;
  ::pasta::Token OperatorToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArguments: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HasExplicitTemplateArguments(void) const;
  bool HasTemplateKeyword(void) const;
  bool IsArrow(void) const;
  bool IsImplicitAccess(void) const;
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXDependentScopeMemberExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXDependentScopeMemberExpr));

class CXXFoldExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXFoldExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXFoldExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXFoldExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXFoldExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::UnresolvedLookupExpr Callee(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr Initializer(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Token LParenToken(void) const;
  std::optional<unsigned> NumExpansions(void) const;
  enum BinaryOperatorKind Operator(void) const;
  ::pasta::Expr Pattern(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Token RParenToken(void) const;
  bool IsLeftFold(void) const;
  bool IsRightFold(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXFoldExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXFoldExpr));

class CXXInheritedCtorInitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXInheritedCtorInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXInheritedCtorInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXInheritedCtorInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXInheritedCtorInitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  bool ConstructsVirtualBase(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ConstructionKind ConstructionKind(void) const;
  ::pasta::CXXConstructorDecl Constructor(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  bool InheritedFromVirtualBase(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXInheritedCtorInitExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXInheritedCtorInitExpr));

class CXXNewExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXNewExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXNewExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXNewExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXNewExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  bool DoesUsualArrayDeleteWantSize(void) const;
  ::pasta::Type AllocatedType(void) const;
  // AllocatedTypeSourceInfo: (clang::TypeSourceInfo *)
  std::optional<::pasta::Expr> ArraySize(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::CXXConstructExpr ConstructExpression(void) const;
  ::pasta::TokenRange DirectInitializerRange(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::InitializationStyle InitializationStyle(void) const;
  ::pasta::Expr Initializer(void) const;
  uint32_t NumPlacementArguments(void) const;
  ::pasta::FunctionDecl OperatorDelete(void) const;
  ::pasta::FunctionDecl OperatorNew(void) const;
  // PlacementArgument: (const clang::Expr *)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::TokenRange TypeIdParentheses(void) const;
  bool HasInitializer(void) const;
  bool IsArray(void) const;
  bool IsGlobalNew(void) const;
  bool IsParenthesisTypeId(void) const;
  bool PassAlignment(void) const;
  std::vector<::pasta::Expr> PlacementArguments(void) const;
  bool ShouldNullCheckAllocation(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXNewExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXNewExpr));

class CXXNoexceptExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXNoexceptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXNoexceptExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXNoexceptExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXNoexceptExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr Operand(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXNoexceptExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXNoexceptExpr));

class CXXNullPtrLiteralExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXNullPtrLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXNullPtrLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXNullPtrLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXNullPtrLiteralExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXNullPtrLiteralExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXNullPtrLiteralExpr));

class CXXPseudoDestructorExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXPseudoDestructorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXPseudoDestructorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXPseudoDestructorExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXPseudoDestructorExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token ColonColonToken(void) const;
  ::pasta::Type DestroyedType(void) const;
  // DestroyedTypeIdentifier: (clang::IdentifierInfo *)
  // DestroyedTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::Token DestroyedTypeToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token OperatorToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  // ScopeTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::Token TildeToken(void) const;
  bool HasQualifier(void) const;
  bool IsArrow(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXPseudoDestructorExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXPseudoDestructorExpr));

class CXXRewrittenBinaryOperator : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXRewrittenBinaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXRewrittenBinaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXRewrittenBinaryOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXRewrittenBinaryOperator)
  ::pasta::Token BeginToken(void) const;
  // DecomposedForm: (clang::CXXRewrittenBinaryOperator::DecomposedForm)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Expr LHS(void) const;
  enum BinaryOperatorKind Opcode(void) const;
  std::string_view OpcodeString(void) const;
  enum BinaryOperatorKind Operator(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Expr SemanticForm(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsAssignmentOperation(void) const;
  bool IsComparisonOperation(void) const;
  bool IsReversed(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXRewrittenBinaryOperator)
};

static_assert(sizeof(Stmt) == sizeof(CXXRewrittenBinaryOperator));

class CXXScalarValueInitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXScalarValueInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXScalarValueInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXScalarValueInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXScalarValueInitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXScalarValueInitExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXScalarValueInitExpr));

class CXXStdInitializerListExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXStdInitializerListExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXStdInitializerListExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXStdInitializerListExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXStdInitializerListExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Expr SubExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXStdInitializerListExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXStdInitializerListExpr));

class CXXTemporaryObjectExpr : public CXXConstructExpr {
 private:
  using CXXConstructExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXTemporaryObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(CXXConstructExpr, CXXTemporaryObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXTemporaryObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXTemporaryObjectExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXTemporaryObjectExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  std::vector<::pasta::Expr> Arguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXTemporaryObjectExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXTemporaryObjectExpr));

class CXXThisExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXThisExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXThisExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXThisExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXThisExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  bool IsImplicit(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXThisExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXThisExpr));

class CXXThrowExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXThrowExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXThrowExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXThrowExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXThrowExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr SubExpression(void) const;
  ::pasta::Token ThrowToken(void) const;
  bool IsThrownVariableInScope(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXThrowExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXThrowExpr));

class CXXTypeidExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXTypeidExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXTypeidExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXTypeidExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXTypeidExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr ExpressionOperand(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Type TypeOperand(void) const;
  // TypeOperandSourceInfo: (clang::TypeSourceInfo *)
  bool IsMostDerived(void) const;
  bool IsPotentiallyEvaluated(void) const;
  bool IsTypeOperand(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXTypeidExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXTypeidExpr));

class CXXUnresolvedConstructExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXUnresolvedConstructExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXUnresolvedConstructExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXUnresolvedConstructExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXUnresolvedConstructExpr)
  std::vector<::pasta::Expr> Arguments(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  // Argument: (const clang::Expr *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  uint32_t NumArguments(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Type TypeAsWritten(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  bool IsListInitialization(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXUnresolvedConstructExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXUnresolvedConstructExpr));

class CXXUuidofExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXUuidofExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXUuidofExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXUuidofExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXUuidofExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr ExpressionOperand(void) const;
  ::pasta::MSGuidDecl GuidDeclaration(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Type TypeOperand(void) const;
  // TypeOperandSourceInfo: (clang::TypeSourceInfo *)
  bool IsTypeOperand(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXUuidofExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXUuidofExpr));

class CallExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CallExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CallExpr, CUDAKernelCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CallExpr, CXXMemberCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CallExpr, CXXOperatorCallExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CallExpr, UserDefinedLiteral)
  std::vector<::pasta::Expr> Arguments(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::ADLCallKind ADLCallKind(void) const;
  // Argument: (const clang::Expr *)
  // Arguments: (const clang::Expr *const *)
  ::pasta::Token BeginToken(void) const;
  uint32_t BuiltinCallee(void) const;
  ::pasta::Type CallReturnType(void) const;
  ::pasta::Expr Callee(void) const;
  ::pasta::Decl CalleeDeclaration(void) const;
  ::pasta::FunctionDecl DirectCallee(void) const;
  ::pasta::Token EndToken(void) const;
  // FPFeatures: (clang::FPOptionsOverride)
  // FPFeaturesInEffect: (clang::FPOptions)
  uint32_t NumArguments(void) const;
  uint32_t NumCommas(void) const;
  ::pasta::Token RParenToken(void) const;
  // StoredFPFeatures: (clang::FPOptionsOverride)
  // UnusedResultAttribute: (const clang::Attr *)
  bool HasStoredFPFeatures(void) const;
  bool HasUnusedResultAttribute(void) const;
  bool IsBuiltinAssumeFalse(void) const;
  bool IsCallToStdMove(void) const;
  bool IsUnevaluatedBuiltinCall(void) const;
  bool UsesADL(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CallExpr)
};

static_assert(sizeof(Stmt) == sizeof(CallExpr));

class CastExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, BuiltinBitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CStyleCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXConstCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXDynamicCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXFunctionalCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXNamedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXReinterpretCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, CXXStaticCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, ExplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, ImplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CastExpr, ObjCBridgedCastExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  enum CastKind CastKind(void) const;
  std::string_view CastKindName(void) const;
  ::pasta::NamedDecl ConversionFunction(void) const;
  // FPFeatures: (clang::FPOptionsOverride)
  // FPFeaturesInEffect: (clang::FPOptions)
  // StoredFPFeatures: (clang::FPOptionsOverride)
  ::pasta::Expr SubExpression(void) const;
  ::pasta::Expr SubExpressionAsWritten(void) const;
  ::pasta::FieldDecl TargetUnionField(void) const;
  bool HasStoredFPFeatures(void) const;
  // Path: (llvm::iterator_range<const clang::CXXBaseSpecifier *const *>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CastExpr));

class CharacterLiteral : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CharacterLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CharacterLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CharacterLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CharacterLiteral)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Kind: (clang::CharacterLiteral::CharacterKind)
  ::pasta::Token Token(void) const;
  uint32_t Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CharacterLiteral)
};

static_assert(sizeof(Stmt) == sizeof(CharacterLiteral));

class ChooseExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ChooseExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ChooseExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ChooseExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ChooseExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BuiltinToken(void) const;
  ::pasta::Expr ChosenSubExpression(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Token RParenToken(void) const;
  bool IsConditionDependent(void) const;
  bool IsConditionTrue(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ChooseExpr)
};

static_assert(sizeof(Stmt) == sizeof(ChooseExpr));

class CompoundAssignOperator : public BinaryOperator {
 private:
  using BinaryOperator::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CompoundAssignOperator)
  PASTA_DECLARE_BASE_OPERATORS(BinaryOperator, CompoundAssignOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CompoundAssignOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CompoundAssignOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CompoundAssignOperator)
  ::pasta::Type ComputationLHSType(void) const;
  ::pasta::Type ComputationResultType(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CompoundAssignOperator)
};

static_assert(sizeof(Stmt) == sizeof(CompoundAssignOperator));

class CompoundLiteralExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CompoundLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CompoundLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CompoundLiteralExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CompoundLiteralExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr Initializer(void) const;
  ::pasta::Token LParenToken(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  bool IsFileScope(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CompoundLiteralExpr)
};

static_assert(sizeof(Stmt) == sizeof(CompoundLiteralExpr));

class ConceptSpecializationExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConceptSpecializationExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ConceptSpecializationExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ConceptSpecializationExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ConceptSpecializationExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Satisfaction: (const clang::ASTConstraintSatisfaction &)
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgument>)
  bool IsSatisfied(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ConceptSpecializationExpr)
};

static_assert(sizeof(Stmt) == sizeof(ConceptSpecializationExpr));

class ConditionalOperator : public AbstractConditionalOperator {
 private:
  using AbstractConditionalOperator::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(AbstractConditionalOperator, ConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ConditionalOperator)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ConditionalOperator)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr Condition(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr FalseExpression(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Expr TrueExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ConditionalOperator)
};

static_assert(sizeof(Stmt) == sizeof(ConditionalOperator));

class ConstantExpr : public FullExpr {
 private:
  using FullExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstantExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ConstantExpr)
  PASTA_DECLARE_BASE_OPERATORS(FullExpr, ConstantExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ConstantExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ConstantExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  // APValueResult: (clang::APValue)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::APValueKind ResultAPValueKind(void) const;
  // ResultAsAPSInt: (llvm::APSInt)
  // ResultAsAPValue: (clang::APValue &)
  ::pasta::ResultStorageKind ResultStorageKind(void) const;
  bool HasAPValueResult(void) const;
  bool IsImmediateInvocation(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ConstantExpr)
};

static_assert(sizeof(Stmt) == sizeof(ConstantExpr));

class ConvertVectorExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConvertVectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ConvertVectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ConvertVectorExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ConvertVectorExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BuiltinToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr SrcExpression(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ConvertVectorExpr)
};

static_assert(sizeof(Stmt) == sizeof(ConvertVectorExpr));

class CoroutineSuspendExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CoroutineSuspendExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CoroutineSuspendExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CoroutineSuspendExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CoroutineSuspendExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CoroutineSuspendExpr, CoawaitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CoroutineSuspendExpr, CoyieldExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr CommonExpression(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token KeywordToken(void) const;
  ::pasta::OpaqueValueExpr OpaqueValue(void) const;
  ::pasta::Expr ReadyExpression(void) const;
  ::pasta::Expr ResumeExpression(void) const;
  ::pasta::Expr SuspendExpression(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CoroutineSuspendExpr)
};

static_assert(sizeof(Stmt) == sizeof(CoroutineSuspendExpr));

class CoyieldExpr : public CoroutineSuspendExpr {
 private:
  using CoroutineSuspendExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CoyieldExpr)
  PASTA_DECLARE_BASE_OPERATORS(CoroutineSuspendExpr, CoyieldExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CoyieldExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CoyieldExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CoyieldExpr)
  ::pasta::Expr Operand(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CoyieldExpr)
};

static_assert(sizeof(Stmt) == sizeof(CoyieldExpr));

class DeclRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, DeclRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DeclRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, DeclRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ValueDecl Declaration(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::NamedDecl FoundDeclaration(void) const;
  ::pasta::Token LAngleToken(void) const;
  ::pasta::Token Token(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  uint32_t NumTemplateArguments(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArguments: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HadMultipleCandidates(void) const;
  bool HasExplicitTemplateArguments(void) const;
  bool HasQualifier(void) const;
  bool HasTemplateKWAndArgumentsInfo(void) const;
  bool HasTemplateKeyword(void) const;
  enum NonOdrUseReason IsNonOdrUse(void) const;
  bool RefersToEnclosingVariableOrCapture(void) const;
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DeclRefExpr)
};

static_assert(sizeof(Stmt) == sizeof(DeclRefExpr));

class DependentCoawaitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentCoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, DependentCoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DependentCoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, DependentCoawaitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token KeywordToken(void) const;
  ::pasta::Expr Operand(void) const;
  ::pasta::UnresolvedLookupExpr OperatorCoawaitLookup(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DependentCoawaitExpr)
};

static_assert(sizeof(Stmt) == sizeof(DependentCoawaitExpr));

class DependentScopeDeclRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentScopeDeclRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, DependentScopeDeclRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DependentScopeDeclRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, DependentScopeDeclRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  // DeclarationName: (clang::DeclarationName)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LAngleToken(void) const;
  ::pasta::Token Token(void) const;
  // NameInfo: (const clang::DeclarationNameInfo &)
  uint32_t NumTemplateArguments(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArguments: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HasExplicitTemplateArguments(void) const;
  bool HasTemplateKeyword(void) const;
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DependentScopeDeclRefExpr)
};

static_assert(sizeof(Stmt) == sizeof(DependentScopeDeclRefExpr));

class DesignatedInitExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DesignatedInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, DesignatedInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DesignatedInitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, DesignatedInitExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  // Designators: (llvm::ArrayRef<clang::DesignatedInitExpr::Designator>)
  // ArrayIndex: (clang::Expr *)
  // ArrayRangeEnd: (clang::Expr *)
  // ArrayRangeStart: (clang::Expr *)
  ::pasta::Token BeginToken(void) const;
  // Designator: (const clang::DesignatedInitExpr::Designator *)
  ::pasta::TokenRange DesignatorsSourceRange(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token EqualOrColonToken(void) const;
  ::pasta::Expr Initializer(void) const;
  uint32_t NumSubExpressions(void) const;
  // SubExpression: (clang::Expr *)
  bool IsDirectInitializer(void) const;
  uint32_t Size(void) const;
  bool UsesGNUSyntax(void) const;
  std::vector<::pasta::Expr> SubExpressions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DesignatedInitExpr)
};

static_assert(sizeof(Stmt) == sizeof(DesignatedInitExpr));

class DesignatedInitUpdateExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DesignatedInitUpdateExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, DesignatedInitUpdateExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, DesignatedInitUpdateExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, DesignatedInitUpdateExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Expr Base(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::InitListExpr Updater(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(DesignatedInitUpdateExpr)
};

static_assert(sizeof(Stmt) == sizeof(DesignatedInitUpdateExpr));

class ExplicitCastExpr : public CastExpr {
 private:
  using CastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, ExplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ExplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ExplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ExplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, BuiltinBitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CStyleCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXConstCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXDynamicCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXFunctionalCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXNamedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXReinterpretCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, CXXStaticCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ExplicitCastExpr, ObjCBridgedCastExpr)
  ::pasta::Type TypeAsWritten(void) const;
  // TypeInfoAsWritten: (clang::TypeSourceInfo *)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ExplicitCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(ExplicitCastExpr));

class ExprWithCleanups : public FullExpr {
 private:
  using FullExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExprWithCleanups)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ExprWithCleanups)
  PASTA_DECLARE_BASE_OPERATORS(FullExpr, ExprWithCleanups)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ExprWithCleanups)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ExprWithCleanups)
  std::vector<::pasta::Stmt> Children(void) const;
  bool CleanupsHaveSideEffects(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  uint32_t NumObjects(void) const;
  // Object: (llvm::PointerUnion<clang::BlockDecl *, clang::CompoundLiteralExpr *>)
  // Objects: (llvm::ArrayRef<llvm::PointerUnion<clang::BlockDecl *, clang::CompoundLiteralExpr *>>)
  std::vector<std::variant<std::monostate, ::pasta::BlockDecl, ::pasta::CompoundLiteralExpr>> Objects(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ExprWithCleanups)
};

static_assert(sizeof(Stmt) == sizeof(ExprWithCleanups));

class ImplicitCastExpr : public CastExpr {
 private:
  using CastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, ImplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ImplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ImplicitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ImplicitCastExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  bool IsPartOfExplicitCast(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ImplicitCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(ImplicitCastExpr));

class OMPAtomicDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPAtomicDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPAtomicDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPAtomicDirective)
  ::pasta::Expr Expression(void) const;
  ::pasta::Expr UpdateExpression(void) const;
  ::pasta::Expr V(void) const;
  ::pasta::Expr X(void) const;
  bool IsPostfixUpdate(void) const;
  bool IsXLHSInRHSPart(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPAtomicDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPAtomicDirective));

class OMPBarrierDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPBarrierDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPBarrierDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPBarrierDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPBarrierDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPBarrierDirective));

class OMPCancelDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCancelDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPCancelDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPCancelDirective)
  // CancelRegion: (llvm::omp::Directive)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPCancelDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPCancelDirective));

class OMPCancellationPointDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCancellationPointDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPCancellationPointDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPCancellationPointDirective)
  // CancelRegion: (llvm::omp::Directive)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPCancellationPointDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPCancellationPointDirective));

class OMPCriticalDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCriticalDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPCriticalDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPCriticalDirective)
  // DirectiveName: (clang::DeclarationNameInfo)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPCriticalDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPCriticalDirective));

class OMPDepobjDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDepobjDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPDepobjDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPDepobjDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPDepobjDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPDepobjDirective));

class OMPDispatchDirective : public OMPExecutableDirective {
 private:
  using OMPExecutableDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDispatchDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPDispatchDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPDispatchDirective)
  ::pasta::Token TargetCallToken(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPDispatchDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPDispatchDirective));

class OMPDistributeDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPDistributeDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPDistributeDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPDistributeDirective));

class OMPDistributeParallelForDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeParallelForDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPDistributeParallelForDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPDistributeParallelForDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPDistributeParallelForDirective));

class OMPDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeParallelForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPDistributeParallelForSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPDistributeParallelForSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPDistributeParallelForSimdDirective));

class OMPDistributeSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPDistributeSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPDistributeSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPDistributeSimdDirective));

class OMPForDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPForDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPForDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPForDirective)
  ::pasta::Expr TaskReductionReferenceExpression(void) const;
  bool HasCancel(void) const;
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPForDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPForDirective));

class OMPForSimdDirective : public OMPLoopDirective {
 private:
  using OMPLoopDirective::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPExecutableDirective, OMPForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopBasedDirective, OMPForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(OMPLoopDirective, OMPForSimdDirective)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, OMPForSimdDirective)
  // !!! Clause getNumClauses getClause (empty ret type = (clang::OMPClause *))
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPForSimdDirective)
};

static_assert(sizeof(Stmt) == sizeof(OMPForSimdDirective));

class ObjCBridgedCastExpr : public ExplicitCastExpr {
 private:
  using ExplicitCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCBridgedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, ObjCBridgedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, ObjCBridgedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCBridgedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCBridgedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCBridgedCastExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token BridgeKeywordToken(void) const;
  enum ObjCBridgeCastKind BridgeKind(void) const;
  std::string_view BridgeKindName(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCBridgedCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCBridgedCastExpr));

class UserDefinedLiteral : public CallExpr {
 private:
  using CallExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UserDefinedLiteral)
  PASTA_DECLARE_BASE_OPERATORS(CallExpr, UserDefinedLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Expr, UserDefinedLiteral)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, UserDefinedLiteral)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, UserDefinedLiteral)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr CookedLiteral(void) const;
  ::pasta::Token EndToken(void) const;
  // LiteralOperatorKind: (clang::UserDefinedLiteral::LiteralOperatorKind)
  // UDSuffix: (const clang::IdentifierInfo *)
  ::pasta::Token UDSuffixToken(void) const;
  std::vector<::pasta::Expr> Arguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(UserDefinedLiteral)
};

static_assert(sizeof(Stmt) == sizeof(UserDefinedLiteral));

class BuiltinBitCastExpr : public ExplicitCastExpr {
 private:
  using ExplicitCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinBitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, BuiltinBitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, BuiltinBitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, BuiltinBitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, BuiltinBitCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, BuiltinBitCastExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(BuiltinBitCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(BuiltinBitCastExpr));

class CStyleCastExpr : public ExplicitCastExpr {
 private:
  using ExplicitCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CStyleCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CStyleCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CStyleCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CStyleCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CStyleCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CStyleCastExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CStyleCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CStyleCastExpr));

class CUDAKernelCallExpr : public CallExpr {
 private:
  using CallExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CUDAKernelCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(CallExpr, CUDAKernelCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CUDAKernelCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CUDAKernelCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CUDAKernelCallExpr)
  ::pasta::CallExpr Config(void) const;
  std::vector<::pasta::Expr> Arguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CUDAKernelCallExpr)
};

static_assert(sizeof(Stmt) == sizeof(CUDAKernelCallExpr));

class CXXFunctionalCastExpr : public ExplicitCastExpr {
 private:
  using ExplicitCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXFunctionalCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXFunctionalCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXFunctionalCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXFunctionalCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXFunctionalCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXFunctionalCastExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  bool IsListInitialization(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXFunctionalCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXFunctionalCastExpr));

class CXXMemberCallExpr : public CallExpr {
 private:
  using CallExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXMemberCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(CallExpr, CXXMemberCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXMemberCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXMemberCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXMemberCallExpr)
  ::pasta::Token ExpressionToken(void) const;
  ::pasta::Expr ImplicitObjectArgument(void) const;
  ::pasta::CXXMethodDecl MethodDeclaration(void) const;
  ::pasta::Type ObjectType(void) const;
  ::pasta::CXXRecordDecl RecordDeclaration(void) const;
  std::vector<::pasta::Expr> Arguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXMemberCallExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXMemberCallExpr));

class CXXNamedCastExpr : public ExplicitCastExpr {
 private:
  using ExplicitCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXNamedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXNamedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXNamedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXNamedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXNamedCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXNamedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXConstCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXDynamicCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXReinterpretCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXStaticCastExpr)
  ::pasta::TokenRange AngleBrackets(void) const;
  ::pasta::Token BeginToken(void) const;
  std::string_view CastName(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXNamedCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXNamedCastExpr));

class CXXOperatorCallExpr : public CallExpr {
 private:
  using CallExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXOperatorCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(CallExpr, CXXOperatorCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXOperatorCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXOperatorCallExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXOperatorCallExpr)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExpressionToken(void) const;
  enum OverloadedOperatorKind Operator(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsAssignmentOperation(void) const;
  bool IsComparisonOperation(void) const;
  bool IsInfixBinaryOperation(void) const;
  std::vector<::pasta::Expr> Arguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXOperatorCallExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXOperatorCallExpr));

class CXXReinterpretCastExpr : public CXXNamedCastExpr {
 private:
  using CXXNamedCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXReinterpretCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CXXNamedCastExpr, CXXReinterpretCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXReinterpretCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXReinterpretCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXReinterpretCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXReinterpretCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXReinterpretCastExpr)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXReinterpretCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXReinterpretCastExpr));

class CXXStaticCastExpr : public CXXNamedCastExpr {
 private:
  using CXXNamedCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXStaticCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CXXNamedCastExpr, CXXStaticCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXStaticCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXStaticCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXStaticCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXStaticCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXStaticCastExpr)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXStaticCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXStaticCastExpr));

class CoawaitExpr : public CoroutineSuspendExpr {
 private:
  using CoroutineSuspendExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(CoroutineSuspendExpr, CoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CoawaitExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CoawaitExpr)
  ::pasta::Expr Operand(void) const;
  bool IsImplicit(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CoawaitExpr)
};

static_assert(sizeof(Stmt) == sizeof(CoawaitExpr));

class CXXAddrspaceCastExpr : public CXXNamedCastExpr {
 private:
  using CXXNamedCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXAddrspaceCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CXXNamedCastExpr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXAddrspaceCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXAddrspaceCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXAddrspaceCastExpr)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXAddrspaceCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXAddrspaceCastExpr));

class CXXConstCastExpr : public CXXNamedCastExpr {
 private:
  using CXXNamedCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXConstCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CXXNamedCastExpr, CXXConstCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXConstCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXConstCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXConstCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXConstCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXConstCastExpr)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXConstCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXConstCastExpr));

class CXXDynamicCastExpr : public CXXNamedCastExpr {
 private:
  using CXXNamedCastExpr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDynamicCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CXXNamedCastExpr, CXXDynamicCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(CastExpr, CXXDynamicCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ExplicitCastExpr, CXXDynamicCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, CXXDynamicCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CXXDynamicCastExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, CXXDynamicCastExpr)
  bool IsAlwaysNull(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXDynamicCastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CXXDynamicCastExpr));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR
#endif  // PASTA_IN_BOOTSTRAP
