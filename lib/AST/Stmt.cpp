/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#define PASTA_IN_STMT_CPP
#ifndef PASTA_IN_BOOTSTRAP
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtCXX.h>
#include <clang/AST/StmtObjC.h>
#include <clang/AST/StmtOpenMP.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprConcepts.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/ExprObjC.h>
#include <clang/AST/ExprOpenMP.h>
#include <clang/Frontend/CompilerInstance.h>
#pragma clang diagnostic pop

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include "AST.h"
#include "Builder.h"

#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \
    std::optional<class derived> derived::From(const class base &that) { \
      if (auto stmt_ptr = clang::dyn_cast<clang::derived>(that.u.base)) { \
        return StmtBuilder::Create<class derived>(that.ast, stmt_ptr); \
      } else { \
        return std::nullopt; \
      } \
    }

#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, that.u.Stmt) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), that.u.Stmt) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.Stmt = that.u.Stmt; \
      kind = that.kind; \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      if (this != &that) { \
        ast = std::move(that.ast); \
        u.Stmt = that.u.Stmt; \
        kind = that.kind; \
      } \
      return *this; \
    }

namespace pasta {

StmtVisitor::~StmtVisitor(void) {}

void StmtVisitor::Accept(const Stmt &stmt) {
  switch (stmt.Kind()) {
#define PASTA_VISIT_STMT(name) \
    case StmtKind::k ## name: \
      Visit ## name(reinterpret_cast<const name &>(stmt)); \
      break;

    PASTA_FOR_EACH_STMT_IMPL(PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_IGNORE_ABSTRACT)
#undef PASTA_VISIT_STMT
  }
}

void StmtVisitor::VisitStmt(const Stmt &stmt) {
  (void) stmt;
}

void StmtVisitor::VisitSwitchCase(const SwitchCase &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitSwitchStmt(const SwitchStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitValueStmt(const ValueStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitWhileStmt(const WhileStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitAsmStmt(const AsmStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitAttributedStmt(const AttributedStmt &stmt) {
  VisitValueStmt(stmt);
}

void StmtVisitor::VisitBreakStmt(const BreakStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCXXCatchStmt(const CXXCatchStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCXXForRangeStmt(const CXXForRangeStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCXXTryStmt(const CXXTryStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCapturedStmt(const CapturedStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCaseStmt(const CaseStmt &stmt) {
  VisitSwitchCase(stmt);
}

void StmtVisitor::VisitCompoundStmt(const CompoundStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitContinueStmt(const ContinueStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCoreturnStmt(const CoreturnStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitCoroutineBodyStmt(const CoroutineBodyStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitDeclStmt(const DeclStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitDefaultStmt(const DefaultStmt &stmt) {
  VisitSwitchCase(stmt);
}

void StmtVisitor::VisitDoStmt(const DoStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitExpr(const Expr &stmt) {
  VisitValueStmt(stmt);
}

void StmtVisitor::VisitExpressionTraitExpr(const ExpressionTraitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitExtVectorElementExpr(const ExtVectorElementExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitFixedPointLiteral(const FixedPointLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitFloatingLiteral(const FloatingLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitForStmt(const ForStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitFullExpr(const FullExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitFunctionParmPackExpr(const FunctionParmPackExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitGCCAsmStmt(const GCCAsmStmt &stmt) {
  VisitAsmStmt(stmt);
}

void StmtVisitor::VisitGNUNullExpr(const GNUNullExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitGenericSelectionExpr(const GenericSelectionExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitGotoStmt(const GotoStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitIfStmt(const IfStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitImaginaryLiteral(const ImaginaryLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitImplicitValueInitExpr(const ImplicitValueInitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitIndirectGotoStmt(const IndirectGotoStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitInitListExpr(const InitListExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitIntegerLiteral(const IntegerLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitLabelStmt(const LabelStmt &stmt) {
  VisitValueStmt(stmt);
}

void StmtVisitor::VisitLambdaExpr(const LambdaExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitMSAsmStmt(const MSAsmStmt &stmt) {
  VisitAsmStmt(stmt);
}

void StmtVisitor::VisitMSDependentExistsStmt(const MSDependentExistsStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitMSPropertyRefExpr(const MSPropertyRefExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitMSPropertySubscriptExpr(const MSPropertySubscriptExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitMaterializeTemporaryExpr(const MaterializeTemporaryExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitMatrixSubscriptExpr(const MatrixSubscriptExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitMemberExpr(const MemberExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitNoInitExpr(const NoInitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitNullStmt(const NullStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitOMPArraySectionExpr(const OMPArraySectionExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOMPArrayShapingExpr(const OMPArrayShapingExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOMPExecutableDirective(const OMPExecutableDirective &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitOMPFlushDirective(const OMPFlushDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPIteratorExpr(const OMPIteratorExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOMPLoopDirective(const OMPLoopDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPMasterDirective(const OMPMasterDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPMasterTaskLoopDirective(const OMPMasterTaskLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPMasterTaskLoopSimdDirective(const OMPMasterTaskLoopSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPOrderedDirective(const OMPOrderedDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPParallelDirective(const OMPParallelDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPParallelForDirective(const OMPParallelForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPParallelForSimdDirective(const OMPParallelForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPParallelMasterDirective(const OMPParallelMasterDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPParallelMasterTaskLoopDirective(const OMPParallelMasterTaskLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPParallelMasterTaskLoopSimdDirective(const OMPParallelMasterTaskLoopSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPParallelSectionsDirective(const OMPParallelSectionsDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPScanDirective(const OMPScanDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPSectionDirective(const OMPSectionDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPSectionsDirective(const OMPSectionsDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPSimdDirective(const OMPSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPSingleDirective(const OMPSingleDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetDataDirective(const OMPTargetDataDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetDirective(const OMPTargetDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetEnterDataDirective(const OMPTargetEnterDataDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetExitDataDirective(const OMPTargetExitDataDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetParallelDirective(const OMPTargetParallelDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetParallelForDirective(const OMPTargetParallelForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetParallelForSimdDirective(const OMPTargetParallelForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetSimdDirective(const OMPTargetSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetTeamsDirective(const OMPTargetTeamsDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTargetTeamsDistributeDirective(const OMPTargetTeamsDistributeDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetTeamsDistributeParallelForDirective(const OMPTargetTeamsDistributeParallelForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetTeamsDistributeParallelForSimdDirective(const OMPTargetTeamsDistributeParallelForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetTeamsDistributeSimdDirective(const OMPTargetTeamsDistributeSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTargetUpdateDirective(const OMPTargetUpdateDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTaskDirective(const OMPTaskDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTaskLoopDirective(const OMPTaskLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTaskLoopSimdDirective(const OMPTaskLoopSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTaskgroupDirective(const OMPTaskgroupDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTaskwaitDirective(const OMPTaskwaitDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTaskyieldDirective(const OMPTaskyieldDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTeamsDirective(const OMPTeamsDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPTeamsDistributeDirective(const OMPTeamsDistributeDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTeamsDistributeParallelForDirective(const OMPTeamsDistributeParallelForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTeamsDistributeParallelForSimdDirective(const OMPTeamsDistributeParallelForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTeamsDistributeSimdDirective(const OMPTeamsDistributeSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitObjCArrayLiteral(const ObjCArrayLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCAtCatchStmt(const ObjCAtCatchStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCAtFinallyStmt(const ObjCAtFinallyStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCAtSynchronizedStmt(const ObjCAtSynchronizedStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCAtThrowStmt(const ObjCAtThrowStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCAtTryStmt(const ObjCAtTryStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCAutoreleasePoolStmt(const ObjCAutoreleasePoolStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCAvailabilityCheckExpr(const ObjCAvailabilityCheckExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCBoolLiteralExpr(const ObjCBoolLiteralExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCBoxedExpr(const ObjCBoxedExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCDictionaryLiteral(const ObjCDictionaryLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCEncodeExpr(const ObjCEncodeExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCForCollectionStmt(const ObjCForCollectionStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitObjCIndirectCopyRestoreExpr(const ObjCIndirectCopyRestoreExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCIsaExpr(const ObjCIsaExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCIvarRefExpr(const ObjCIvarRefExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCMessageExpr(const ObjCMessageExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCPropertyRefExpr(const ObjCPropertyRefExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCProtocolExpr(const ObjCProtocolExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCSelectorExpr(const ObjCSelectorExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCStringLiteral(const ObjCStringLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitObjCSubscriptRefExpr(const ObjCSubscriptRefExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOffsetOfExpr(const OffsetOfExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOpaqueValueExpr(const OpaqueValueExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOverloadExpr(const OverloadExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitPackExpansionExpr(const PackExpansionExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitParenExpr(const ParenExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitParenListExpr(const ParenListExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitPredefinedExpr(const PredefinedExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitPseudoObjectExpr(const PseudoObjectExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitRecoveryExpr(const RecoveryExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitRequiresExpr(const RequiresExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitReturnStmt(const ReturnStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitSEHExceptStmt(const SEHExceptStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitSEHFinallyStmt(const SEHFinallyStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitSEHLeaveStmt(const SEHLeaveStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitSEHTryStmt(const SEHTryStmt &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitShuffleVectorExpr(const ShuffleVectorExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitSizeOfPackExpr(const SizeOfPackExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitSourceLocExpr(const SourceLocExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitStmtExpr(const StmtExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitStringLiteral(const StringLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitSubstNonTypeTemplateParmExpr(const SubstNonTypeTemplateParmExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitSubstNonTypeTemplateParmPackExpr(const SubstNonTypeTemplateParmPackExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitTypeTraitExpr(const TypeTraitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitTypoExpr(const TypoExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitUnaryExprOrTypeTraitExpr(const UnaryExprOrTypeTraitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitUnaryOperator(const UnaryOperator &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitUnresolvedLookupExpr(const UnresolvedLookupExpr &stmt) {
  VisitOverloadExpr(stmt);
}

void StmtVisitor::VisitUnresolvedMemberExpr(const UnresolvedMemberExpr &stmt) {
  VisitOverloadExpr(stmt);
}

void StmtVisitor::VisitVAArgExpr(const VAArgExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitAbstractConditionalOperator(const AbstractConditionalOperator &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitAddrLabelExpr(const AddrLabelExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitArrayInitIndexExpr(const ArrayInitIndexExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitArrayInitLoopExpr(const ArrayInitLoopExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitArraySubscriptExpr(const ArraySubscriptExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitArrayTypeTraitExpr(const ArrayTypeTraitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitAsTypeExpr(const AsTypeExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitAtomicExpr(const AtomicExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitBinaryConditionalOperator(const BinaryConditionalOperator &stmt) {
  VisitAbstractConditionalOperator(stmt);
}

void StmtVisitor::VisitBinaryOperator(const BinaryOperator &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitBlockExpr(const BlockExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXBindTemporaryExpr(const CXXBindTemporaryExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXBoolLiteralExpr(const CXXBoolLiteralExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXConstructExpr(const CXXConstructExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXDefaultArgExpr(const CXXDefaultArgExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXDefaultInitExpr(const CXXDefaultInitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXDeleteExpr(const CXXDeleteExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXDependentScopeMemberExpr(const CXXDependentScopeMemberExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXFoldExpr(const CXXFoldExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXInheritedCtorInitExpr(const CXXInheritedCtorInitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXNewExpr(const CXXNewExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXNoexceptExpr(const CXXNoexceptExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXNullPtrLiteralExpr(const CXXNullPtrLiteralExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXPseudoDestructorExpr(const CXXPseudoDestructorExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXRewrittenBinaryOperator(const CXXRewrittenBinaryOperator &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXScalarValueInitExpr(const CXXScalarValueInitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXStdInitializerListExpr(const CXXStdInitializerListExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXTemporaryObjectExpr(const CXXTemporaryObjectExpr &stmt) {
  VisitCXXConstructExpr(stmt);
}

void StmtVisitor::VisitCXXThisExpr(const CXXThisExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXThrowExpr(const CXXThrowExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXTypeidExpr(const CXXTypeidExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXUnresolvedConstructExpr(const CXXUnresolvedConstructExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCXXUuidofExpr(const CXXUuidofExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCallExpr(const CallExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCastExpr(const CastExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCharacterLiteral(const CharacterLiteral &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitChooseExpr(const ChooseExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCompoundAssignOperator(const CompoundAssignOperator &stmt) {
  VisitBinaryOperator(stmt);
}

void StmtVisitor::VisitCompoundLiteralExpr(const CompoundLiteralExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitConceptSpecializationExpr(const ConceptSpecializationExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitConditionalOperator(const ConditionalOperator &stmt) {
  VisitAbstractConditionalOperator(stmt);
}

void StmtVisitor::VisitConstantExpr(const ConstantExpr &stmt) {
  VisitFullExpr(stmt);
}

void StmtVisitor::VisitConvertVectorExpr(const ConvertVectorExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCoroutineSuspendExpr(const CoroutineSuspendExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitCoyieldExpr(const CoyieldExpr &stmt) {
  VisitCoroutineSuspendExpr(stmt);
}

void StmtVisitor::VisitDeclRefExpr(const DeclRefExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitDependentCoawaitExpr(const DependentCoawaitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitDependentScopeDeclRefExpr(const DependentScopeDeclRefExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitDesignatedInitExpr(const DesignatedInitExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitDesignatedInitUpdateExpr(const DesignatedInitUpdateExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitExplicitCastExpr(const ExplicitCastExpr &stmt) {
  VisitCastExpr(stmt);
}

void StmtVisitor::VisitExprWithCleanups(const ExprWithCleanups &stmt) {
  VisitFullExpr(stmt);
}

void StmtVisitor::VisitImplicitCastExpr(const ImplicitCastExpr &stmt) {
  VisitCastExpr(stmt);
}

void StmtVisitor::VisitOMPAtomicDirective(const OMPAtomicDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPBarrierDirective(const OMPBarrierDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPCancelDirective(const OMPCancelDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPCancellationPointDirective(const OMPCancellationPointDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPCriticalDirective(const OMPCriticalDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPDepobjDirective(const OMPDepobjDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPDistributeDirective(const OMPDistributeDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPDistributeParallelForDirective(const OMPDistributeParallelForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPDistributeParallelForSimdDirective(const OMPDistributeParallelForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPDistributeSimdDirective(const OMPDistributeSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPForDirective(const OMPForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPForSimdDirective(const OMPForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitObjCBridgedCastExpr(const ObjCBridgedCastExpr &stmt) {
  VisitExplicitCastExpr(stmt);
}

void StmtVisitor::VisitUserDefinedLiteral(const UserDefinedLiteral &stmt) {
  VisitCallExpr(stmt);
}

void StmtVisitor::VisitBuiltinBitCastExpr(const BuiltinBitCastExpr &stmt) {
  VisitExplicitCastExpr(stmt);
}

void StmtVisitor::VisitCStyleCastExpr(const CStyleCastExpr &stmt) {
  VisitExplicitCastExpr(stmt);
}

void StmtVisitor::VisitCUDAKernelCallExpr(const CUDAKernelCallExpr &stmt) {
  VisitCallExpr(stmt);
}

void StmtVisitor::VisitCXXFunctionalCastExpr(const CXXFunctionalCastExpr &stmt) {
  VisitExplicitCastExpr(stmt);
}

void StmtVisitor::VisitCXXMemberCallExpr(const CXXMemberCallExpr &stmt) {
  VisitCallExpr(stmt);
}

void StmtVisitor::VisitCXXNamedCastExpr(const CXXNamedCastExpr &stmt) {
  VisitExplicitCastExpr(stmt);
}

void StmtVisitor::VisitCXXOperatorCallExpr(const CXXOperatorCallExpr &stmt) {
  VisitCallExpr(stmt);
}

void StmtVisitor::VisitCXXReinterpretCastExpr(const CXXReinterpretCastExpr &stmt) {
  VisitCXXNamedCastExpr(stmt);
}

void StmtVisitor::VisitCXXStaticCastExpr(const CXXStaticCastExpr &stmt) {
  VisitCXXNamedCastExpr(stmt);
}

void StmtVisitor::VisitCoawaitExpr(const CoawaitExpr &stmt) {
  VisitCoroutineSuspendExpr(stmt);
}

void StmtVisitor::VisitCXXAddrspaceCastExpr(const CXXAddrspaceCastExpr &stmt) {
  VisitCXXNamedCastExpr(stmt);
}

void StmtVisitor::VisitCXXConstCastExpr(const CXXConstCastExpr &stmt) {
  VisitCXXNamedCastExpr(stmt);
}

void StmtVisitor::VisitCXXDynamicCastExpr(const CXXDynamicCastExpr &stmt) {
  VisitCXXNamedCastExpr(stmt);
}

Stmt::Stmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_, static_cast<::pasta::StmtKind>(stmt_->getStmtClass())) {}
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, AbstractConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, AddrLabelExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ArrayInitIndexExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ArrayInitLoopExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ArraySubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ArrayTypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, AsTypeExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, AsmStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, AtomicExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, AttributedStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, BinaryConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, BinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, BlockExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, BreakStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, BuiltinBitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CStyleCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CUDAKernelCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXAddrspaceCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXBindTemporaryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXBoolLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXCatchStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXConstCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXDefaultArgExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXDefaultInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXDeleteExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXDependentScopeMemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXDynamicCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXFoldExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXForRangeStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXFunctionalCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXInheritedCtorInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXMemberCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXNamedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXNewExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXNoexceptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXNullPtrLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXOperatorCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXPseudoDestructorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXReinterpretCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXRewrittenBinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXScalarValueInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXStaticCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXStdInitializerListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXTemporaryObjectExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXThisExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXThrowExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXTryStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXTypeidExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXUnresolvedConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXUuidofExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CapturedStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CaseStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CharacterLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ChooseExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CompoundAssignOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CompoundLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CompoundStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ConceptSpecializationExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ConstantExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ContinueStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ConvertVectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CoreturnStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CoroutineBodyStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CoroutineSuspendExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CoyieldExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DeclRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DeclStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DefaultStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DependentCoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DependentScopeDeclRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DesignatedInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DesignatedInitUpdateExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, DoStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ExplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, Expr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ExprWithCleanups)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ExpressionTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ExtVectorElementExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, FixedPointLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, FloatingLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ForStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, FullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, FunctionParmPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, GCCAsmStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, GNUNullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, GenericSelectionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, GotoStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, IfStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ImaginaryLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ImplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ImplicitValueInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, IndirectGotoStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, InitListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, IntegerLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, LabelStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, LambdaExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MSAsmStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MSDependentExistsStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MSPropertyRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MSPropertySubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MaterializeTemporaryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MatrixSubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, MemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, NoInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, NullStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPArraySectionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPArrayShapingExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPAtomicDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPBarrierDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPCancelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPCancellationPointDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPCriticalDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDepobjDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPExecutableDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPFlushDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPIteratorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMasterDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPOrderedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelMasterDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelSectionsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPScanDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPSectionDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPSectionsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPSingleDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetDataDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetEnterDataDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetExitDataDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetParallelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetUpdateDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTaskDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTaskgroupDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTaskwaitDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTaskyieldDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTeamsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCArrayLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAtCatchStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAtFinallyStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAtSynchronizedStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAtThrowStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAtTryStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAutoreleasePoolStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCBoolLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCBoxedExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCBridgedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCDictionaryLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCEncodeExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCForCollectionStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCIndirectCopyRestoreExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCIsaExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCIvarRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCMessageExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCPropertyRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCProtocolExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCSelectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCStringLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ObjCSubscriptRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OffsetOfExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OpaqueValueExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OverloadExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, PackExpansionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ParenExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ParenListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, PredefinedExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, PseudoObjectExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, RecoveryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, RequiresExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ReturnStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SEHExceptStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SEHFinallyStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SEHLeaveStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SEHTryStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ShuffleVectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SizeOfPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SourceLocExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, StmtExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, StringLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SubstNonTypeTemplateParmExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SubstNonTypeTemplateParmPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SwitchCase)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SwitchStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, TypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, TypoExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, UnaryExprOrTypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, UnaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, UnresolvedLookupExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, UnresolvedMemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, UserDefinedLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, VAArgExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, ValueStmt)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, WhileStmt)
::pasta::Stmt Stmt::IgnoreContainers(void) const {
  auto &self = *(u.Stmt);
  auto val = self.IgnoreContainers();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "Stmt::IgnoreContainers can return nullptr!");
  __builtin_unreachable();
}

// 0: Stmt::
// 0: Stmt::
std::vector<::pasta::Stmt> Stmt::Children(void) const {
  auto &self = *(u.Stmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token Stmt::BeginToken(void) const {
  auto &self = *(u.Stmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token Stmt::EndToken(void) const {
  auto &self = *(u.Stmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

int64_t Stmt::ID(void) const {
  auto &self = *(u.Stmt);
  auto val = self.getID(ast->ci->getASTContext());
  return val;
}

::pasta::TokenRange Stmt::TokenRange(void) const {
  auto &self = *(u.Stmt);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::StmtKind Stmt::Kind(void) const {
  auto &self = *(u.Stmt);
  auto val = self.getStmtClass();
  return static_cast<::pasta::StmtKind>(val);
}

std::string_view Stmt::KindName(void) const {
  auto &self = *(u.Stmt);
  auto val = self.getStmtClassName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "Stmt::KindName can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt Stmt::StripLabelLikeStatements(void) const {
  auto &self = *(u.Stmt);
  auto val = self.stripLabelLikeStatements();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "Stmt::StripLabelLikeStatements can return nullptr!");
  __builtin_unreachable();
}

SwitchCase::SwitchCase(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SwitchCase)
PASTA_DEFINE_DERIVED_OPERATORS(SwitchCase, CaseStmt)
PASTA_DEFINE_DERIVED_OPERATORS(SwitchCase, DefaultStmt)
::pasta::Token SwitchCase::BeginToken(void) const {
  auto &self = *(u.SwitchCase);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchCase::ColonToken(void) const {
  auto &self = *(u.SwitchCase);
  auto val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchCase::EndToken(void) const {
  auto &self = *(u.SwitchCase);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchCase::KeywordToken(void) const {
  auto &self = *(u.SwitchCase);
  auto val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::SwitchCase SwitchCase::NextSwitchCase(void) const {
  auto &self = *(u.SwitchCase);
  auto val = self.getNextSwitchCase();
  if (val) {
    return StmtBuilder::Create<::pasta::SwitchCase>(ast, val);
  }
  assert(false && "SwitchCase::NextSwitchCase can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt SwitchCase::SubStmt(void) const {
  auto &self = *(u.SwitchCase);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "SwitchCase::SubStmt can return nullptr!");
  __builtin_unreachable();
}

SwitchStmt::SwitchStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SwitchStmt)
std::vector<::pasta::Stmt> SwitchStmt::Children(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SwitchStmt::BeginToken(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt SwitchStmt::Body(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "SwitchStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr SwitchStmt::Cond(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "SwitchStmt::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl SwitchStmt::ConditionVariable(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getConditionVariable();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "SwitchStmt::ConditionVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclStmt SwitchStmt::ConditionVariableDeclStmt(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getConditionVariableDeclStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "SwitchStmt::ConditionVariableDeclStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SwitchStmt::EndToken(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt SwitchStmt::Init(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "SwitchStmt::Init can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SwitchStmt::LParenToken(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchStmt::RParenToken(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::SwitchCase SwitchStmt::SwitchCaseList(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getSwitchCaseList();
  if (val) {
    return StmtBuilder::Create<::pasta::SwitchCase>(ast, val);
  }
  assert(false && "SwitchStmt::SwitchCaseList can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SwitchStmt::SwitchToken(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.getSwitchLoc();
  return ast->TokenAt(val);
}

bool SwitchStmt::HasInitStorage(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.hasInitStorage();
  return val;
}

bool SwitchStmt::HasVarStorage(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.hasVarStorage();
  return val;
}

bool SwitchStmt::IsAllEnumCasesCovered(void) const {
  auto &self = *(u.SwitchStmt);
  auto val = self.isAllEnumCasesCovered();
  return val;
}

ValueStmt::ValueStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ValueStmt)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, AbstractConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, AddrLabelExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ArrayInitIndexExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ArrayInitLoopExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ArraySubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ArrayTypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, AsTypeExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, AtomicExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, AttributedStmt)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, BinaryConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, BinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, BlockExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, BuiltinBitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CStyleCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CUDAKernelCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXAddrspaceCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXBindTemporaryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXBoolLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXConstCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXDefaultArgExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXDefaultInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXDeleteExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXDependentScopeMemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXDynamicCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXFoldExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXFunctionalCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXInheritedCtorInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXMemberCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXNamedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXNewExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXNoexceptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXNullPtrLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXOperatorCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXPseudoDestructorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXReinterpretCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXRewrittenBinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXScalarValueInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXStaticCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXStdInitializerListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXTemporaryObjectExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXThisExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXThrowExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXTypeidExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXUnresolvedConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXUuidofExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CharacterLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ChooseExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CompoundAssignOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CompoundLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ConceptSpecializationExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ConstantExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ConvertVectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CoroutineSuspendExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CoyieldExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, DeclRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, DependentCoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, DependentScopeDeclRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, DesignatedInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, DesignatedInitUpdateExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ExplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, Expr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ExprWithCleanups)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ExpressionTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ExtVectorElementExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, FixedPointLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, FloatingLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, FullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, FunctionParmPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, GNUNullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, GenericSelectionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ImaginaryLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ImplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ImplicitValueInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, InitListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, IntegerLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, LabelStmt)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, LambdaExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, MSPropertyRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, MSPropertySubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, MaterializeTemporaryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, MatrixSubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, MemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, NoInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, OMPArraySectionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, OMPArrayShapingExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, OMPIteratorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCArrayLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCBoolLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCBoxedExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCBridgedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCDictionaryLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCEncodeExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCIndirectCopyRestoreExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCIsaExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCIvarRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCMessageExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCPropertyRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCProtocolExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCSelectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCStringLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ObjCSubscriptRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, OffsetOfExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, OpaqueValueExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, OverloadExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, PackExpansionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ParenExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ParenListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, PredefinedExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, PseudoObjectExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, RecoveryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, RequiresExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, ShuffleVectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, SizeOfPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, SourceLocExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, StmtExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, StringLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, SubstNonTypeTemplateParmExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, SubstNonTypeTemplateParmPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, TypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, TypoExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, UnaryExprOrTypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, UnaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, UnresolvedLookupExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, UnresolvedMemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, UserDefinedLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, VAArgExpr)
::pasta::Expr ValueStmt::ExprStmt(void) const {
  auto &self = *(u.ValueStmt);
  auto val = self.getExprStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ValueStmt::ExprStmt can return nullptr!");
  __builtin_unreachable();
}

WhileStmt::WhileStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, WhileStmt)
std::vector<::pasta::Stmt> WhileStmt::Children(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token WhileStmt::BeginToken(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt WhileStmt::Body(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "WhileStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr WhileStmt::Cond(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "WhileStmt::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl WhileStmt::ConditionVariable(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getConditionVariable();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "WhileStmt::ConditionVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclStmt WhileStmt::ConditionVariableDeclStmt(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getConditionVariableDeclStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "WhileStmt::ConditionVariableDeclStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token WhileStmt::EndToken(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token WhileStmt::LParenToken(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token WhileStmt::RParenToken(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token WhileStmt::WhileToken(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.getWhileLoc();
  return ast->TokenAt(val);
}

bool WhileStmt::HasVarStorage(void) const {
  auto &self = *(u.WhileStmt);
  auto val = self.hasVarStorage();
  return val;
}

AsmStmt::AsmStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, AsmStmt)
PASTA_DEFINE_DERIVED_OPERATORS(AsmStmt, GCCAsmStmt)
PASTA_DEFINE_DERIVED_OPERATORS(AsmStmt, MSAsmStmt)
// 0: AsmStmt::
// 0: AsmStmt::
std::vector<::pasta::Stmt> AsmStmt::Children(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: AsmStmt::
// 0: AsmStmt::
std::string AsmStmt::GenerateAsmString(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.generateAsmString(ast->ci->getASTContext());
  return val;
}

::pasta::Token AsmStmt::AsmToken(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getAsmLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsmStmt::BeginToken(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: AsmStmt::Clobber
::pasta::Token AsmStmt::EndToken(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: AsmStmt::InputConstraint
// 1: AsmStmt::InputExpr
uint32_t AsmStmt::NumClobbers(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getNumClobbers();
  return val;
}

uint32_t AsmStmt::NumInputs(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getNumInputs();
  return val;
}

uint32_t AsmStmt::NumOutputs(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getNumOutputs();
  return val;
}

uint32_t AsmStmt::NumPlusOperands(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.getNumPlusOperands();
  return val;
}

// 1: AsmStmt::OutputConstraint
// 1: AsmStmt::OutputExpr
std::vector<::pasta::Expr> AsmStmt::Inputs(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.inputs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

// 1: AsmStmt::IsOutputPlusConstraint
bool AsmStmt::IsSimple(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.isSimple();
  return val;
}

bool AsmStmt::IsVolatile(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.isVolatile();
  return val;
}

std::vector<::pasta::Expr> AsmStmt::Outputs(void) const {
  auto &self = *(u.AsmStmt);
  auto val = self.outputs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<std::string_view> AsmStmt::OutputConstraints(void) const {
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    __builtin_unreachable();
  };
  std::vector<std::string_view> ret;
  auto count = u.AsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getOutputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> AsmStmt::OutputExprs(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.AsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getOutputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> AsmStmt::InputConstraints(void) const {
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    __builtin_unreachable();
  };
  std::vector<std::string_view> ret;
  auto count = u.AsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getInputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> AsmStmt::InputExprs(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.AsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getInputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> AsmStmt::Clobbers(void) const {
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    __builtin_unreachable();
  };
  std::vector<std::string_view> ret;
  auto count = u.AsmStmt->getNumClobbers();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getClobber(i)));
  }
  return ret;
}

AttributedStmt::AttributedStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ValueStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, AttributedStmt)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AttributedStmt)
std::vector<::pasta::Stmt> AttributedStmt::Children(void) const {
  auto &self = *(u.AttributedStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token AttributedStmt::AttrToken(void) const {
  auto &self = *(u.AttributedStmt);
  auto val = self.getAttrLoc();
  return ast->TokenAt(val);
}

// 0: AttributedStmt::Attributes
::pasta::Token AttributedStmt::BeginToken(void) const {
  auto &self = *(u.AttributedStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AttributedStmt::EndToken(void) const {
  auto &self = *(u.AttributedStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt AttributedStmt::SubStmt(void) const {
  auto &self = *(u.AttributedStmt);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "AttributedStmt::SubStmt can return nullptr!");
  __builtin_unreachable();
}

BreakStmt::BreakStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, BreakStmt)
std::vector<::pasta::Stmt> BreakStmt::Children(void) const {
  auto &self = *(u.BreakStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token BreakStmt::BeginToken(void) const {
  auto &self = *(u.BreakStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token BreakStmt::BreakToken(void) const {
  auto &self = *(u.BreakStmt);
  auto val = self.getBreakLoc();
  return ast->TokenAt(val);
}

::pasta::Token BreakStmt::EndToken(void) const {
  auto &self = *(u.BreakStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

CXXCatchStmt::CXXCatchStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXCatchStmt)
std::vector<::pasta::Stmt> CXXCatchStmt::Children(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXCatchStmt::BeginToken(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXCatchStmt::CatchToken(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.getCatchLoc();
  return ast->TokenAt(val);
}

::pasta::Type CXXCatchStmt::CaughtType(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.getCaughtType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token CXXCatchStmt::EndToken(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::VarDecl CXXCatchStmt::ExceptionDecl(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.getExceptionDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "CXXCatchStmt::ExceptionDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CXXCatchStmt::HandlerBlock(void) const {
  auto &self = *(u.CXXCatchStmt);
  auto val = self.getHandlerBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CXXCatchStmt::HandlerBlock can return nullptr!");
  __builtin_unreachable();
}

CXXForRangeStmt::CXXForRangeStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXForRangeStmt)
std::vector<::pasta::Stmt> CXXForRangeStmt::Children(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXForRangeStmt::BeginToken(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::DeclStmt CXXForRangeStmt::BeginStmt(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getBeginStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "CXXForRangeStmt::BeginStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CXXForRangeStmt::Body(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CXXForRangeStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXForRangeStmt::CoawaitToken(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getCoawaitLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXForRangeStmt::ColonToken(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXForRangeStmt::Cond(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXForRangeStmt::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXForRangeStmt::EndToken(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::DeclStmt CXXForRangeStmt::EndStmt(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getEndStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "CXXForRangeStmt::EndStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXForRangeStmt::ForToken(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getForLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXForRangeStmt::Inc(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXForRangeStmt::Inc can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CXXForRangeStmt::Init(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CXXForRangeStmt::Init can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclStmt CXXForRangeStmt::LoopVarStmt(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getLoopVarStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "CXXForRangeStmt::LoopVarStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl CXXForRangeStmt::LoopVariable(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getLoopVariable();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "CXXForRangeStmt::LoopVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXForRangeStmt::RParenToken(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXForRangeStmt::RangeInit(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getRangeInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXForRangeStmt::RangeInit can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclStmt CXXForRangeStmt::RangeStmt(void) const {
  auto &self = *(u.CXXForRangeStmt);
  auto val = self.getRangeStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "CXXForRangeStmt::RangeStmt can return nullptr!");
  __builtin_unreachable();
}

CXXTryStmt::CXXTryStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXTryStmt)
std::vector<::pasta::Stmt> CXXTryStmt::Children(void) const {
  auto &self = *(u.CXXTryStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXTryStmt::BeginToken(void) const {
  auto &self = *(u.CXXTryStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXTryStmt::EndToken(void) const {
  auto &self = *(u.CXXTryStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: CXXTryStmt::Handler
uint32_t CXXTryStmt::NumHandlers(void) const {
  auto &self = *(u.CXXTryStmt);
  auto val = self.getNumHandlers();
  return val;
}

::pasta::CompoundStmt CXXTryStmt::TryBlock(void) const {
  auto &self = *(u.CXXTryStmt);
  auto val = self.getTryBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "CXXTryStmt::TryBlock can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXTryStmt::TryToken(void) const {
  auto &self = *(u.CXXTryStmt);
  auto val = self.getTryLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::CXXCatchStmt> CXXTryStmt::Handlers(void) const {
  auto convert_elem = [&] (const clang::CXXCatchStmt * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::CXXCatchStmt>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::CXXCatchStmt> ret;
  auto count = u.CXXTryStmt->getNumHandlers();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXTryStmt->getHandler(i)));
  }
  return ret;
}

CapturedStmt::CapturedStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CapturedStmt)
// 0: CapturedStmt::
// 0: CapturedStmt::
// 0: CapturedStmt::
// 0: CapturedStmt::
// 0: CapturedStmt::Capture_inits
// 0: CapturedStmt::
// 0: CapturedStmt::Captures
// 1: CapturedStmt::CapturesVariable
std::vector<::pasta::Stmt> CapturedStmt::Children(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CapturedStmt::BeginToken(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CapturedDecl CapturedStmt::CapturedDecl(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getCapturedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CapturedDecl>(ast, val);
  }
  assert(false && "CapturedStmt::CapturedDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl CapturedStmt::CapturedRecordDecl(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getCapturedRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "CapturedStmt::CapturedRecordDecl can return nullptr!");
  __builtin_unreachable();
}

enum CapturedRegionKind CapturedStmt::CapturedRegionKind(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getCapturedRegionKind();
  return static_cast<::pasta::CapturedRegionKind>(static_cast<unsigned int>(val));
}

::pasta::Stmt CapturedStmt::FindCapturedStmt(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getCapturedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CapturedStmt::FindCapturedStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CapturedStmt::EndToken(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange CapturedStmt::TokenRange(void) const {
  auto &self = *(u.CapturedStmt);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

CaseStmt::CaseStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : SwitchCase(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CaseStmt)
PASTA_DEFINE_BASE_OPERATORS(SwitchCase, CaseStmt)
bool CaseStmt::CaseStmtIsGNURange(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.caseStmtIsGNURange();
  return val;
}

std::vector<::pasta::Stmt> CaseStmt::Children(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CaseStmt::BeginToken(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CaseStmt::CaseToken(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getCaseLoc();
  return ast->TokenAt(val);
}

::pasta::Token CaseStmt::EllipsisToken(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::Token CaseStmt::EndToken(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CaseStmt::LHS(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CaseStmt::LHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CaseStmt::RHS(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CaseStmt::RHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CaseStmt::SubStmt(void) const {
  auto &self = *(u.CaseStmt);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CaseStmt::SubStmt can return nullptr!");
  __builtin_unreachable();
}

CompoundStmt::CompoundStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CompoundStmt)
// 0: CompoundStmt::Body
::pasta::Stmt CompoundStmt::Body_back(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.body_back();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CompoundStmt::Body_back can return nullptr!");
  __builtin_unreachable();
}

// 0: CompoundStmt::
// 0: CompoundStmt::
// 0: CompoundStmt::
::pasta::Stmt CompoundStmt::Body_front(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.body_front();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CompoundStmt::Body_front can return nullptr!");
  __builtin_unreachable();
}

// 0: CompoundStmt::
// 0: CompoundStmt::
std::vector<::pasta::Stmt> CompoundStmt::Children(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CompoundStmt::BeginToken(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundStmt::EndToken(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundStmt::LBracToken(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.getLBracLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundStmt::RBracToken(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.getRBracLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt CompoundStmt::StmtExprResult(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.getStmtExprResult();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CompoundStmt::StmtExprResult can return nullptr!");
  __builtin_unreachable();
}

uint32_t CompoundStmt::Size(void) const {
  auto &self = *(u.CompoundStmt);
  auto val = self.size();
  return val;
}

ContinueStmt::ContinueStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ContinueStmt)
std::vector<::pasta::Stmt> ContinueStmt::Children(void) const {
  auto &self = *(u.ContinueStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ContinueStmt::BeginToken(void) const {
  auto &self = *(u.ContinueStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ContinueStmt::ContinueToken(void) const {
  auto &self = *(u.ContinueStmt);
  auto val = self.getContinueLoc();
  return ast->TokenAt(val);
}

::pasta::Token ContinueStmt::EndToken(void) const {
  auto &self = *(u.ContinueStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

CoreturnStmt::CoreturnStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CoreturnStmt)
std::vector<::pasta::Stmt> CoreturnStmt::Children(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CoreturnStmt::BeginToken(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CoreturnStmt::EndToken(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CoreturnStmt::KeywordToken(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CoreturnStmt::Operand(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoreturnStmt::Operand can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CoreturnStmt::PromiseCall(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.getPromiseCall();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoreturnStmt::PromiseCall can return nullptr!");
  __builtin_unreachable();
}

bool CoreturnStmt::IsImplicit(void) const {
  auto &self = *(u.CoreturnStmt);
  auto val = self.isImplicit();
  return val;
}

CoroutineBodyStmt::CoroutineBodyStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CoroutineBodyStmt)
std::vector<::pasta::Stmt> CoroutineBodyStmt::Children(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr CoroutineBodyStmt::Allocate(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getAllocate();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::Allocate can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CoroutineBodyStmt::BeginToken(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt CoroutineBodyStmt::Body(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CoroutineBodyStmt::Deallocate(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getDeallocate();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::Deallocate can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CoroutineBodyStmt::EndToken(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt CoroutineBodyStmt::ExceptionHandler(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getExceptionHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::ExceptionHandler can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::FallthroughHandler(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getFallthroughHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::FallthroughHandler can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::FinalSuspendStmt(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getFinalSuspendStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::FinalSuspendStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::InitSuspendStmt(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getInitSuspendStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::InitSuspendStmt can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::Stmt> CoroutineBodyStmt::ParamMoves(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getParamMoves();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::VarDecl CoroutineBodyStmt::PromiseDecl(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getPromiseDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::PromiseDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::PromiseDeclStmt(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getPromiseDeclStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::PromiseDeclStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::ResultDecl(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getResultDecl();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::ResultDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::ReturnStmt(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getReturnStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::ReturnStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt CoroutineBodyStmt::ReturnStmtOnAllocFailure(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getReturnStmtOnAllocFailure();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::ReturnStmtOnAllocFailure can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CoroutineBodyStmt::ReturnValueInit(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.getReturnValueInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineBodyStmt::ReturnValueInit can return nullptr!");
  __builtin_unreachable();
}

bool CoroutineBodyStmt::HasDependentPromiseType(void) const {
  auto &self = *(u.CoroutineBodyStmt);
  auto val = self.hasDependentPromiseType();
  return val;
}

DeclStmt::DeclStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, DeclStmt)
std::vector<::pasta::Stmt> DeclStmt::Children(void) const {
  auto &self = *(u.DeclStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: DeclStmt::
// 0: DeclStmt::
// 0: DeclStmt::Declarations
::pasta::Token DeclStmt::BeginToken(void) const {
  auto &self = *(u.DeclStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: DeclStmt::DeclGroup
::pasta::Token DeclStmt::EndToken(void) const {
  auto &self = *(u.DeclStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Decl DeclStmt::SingleDecl(void) const {
  auto &self = *(u.DeclStmt);
  auto val = self.getSingleDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "DeclStmt::SingleDecl can return nullptr!");
  __builtin_unreachable();
}

bool DeclStmt::IsSingleDecl(void) const {
  auto &self = *(u.DeclStmt);
  auto val = self.isSingleDecl();
  return val;
}

DefaultStmt::DefaultStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : SwitchCase(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, DefaultStmt)
PASTA_DEFINE_BASE_OPERATORS(SwitchCase, DefaultStmt)
std::vector<::pasta::Stmt> DefaultStmt::Children(void) const {
  auto &self = *(u.DefaultStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token DefaultStmt::BeginToken(void) const {
  auto &self = *(u.DefaultStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DefaultStmt::DefaultToken(void) const {
  auto &self = *(u.DefaultStmt);
  auto val = self.getDefaultLoc();
  return ast->TokenAt(val);
}

::pasta::Token DefaultStmt::EndToken(void) const {
  auto &self = *(u.DefaultStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt DefaultStmt::SubStmt(void) const {
  auto &self = *(u.DefaultStmt);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "DefaultStmt::SubStmt can return nullptr!");
  __builtin_unreachable();
}

DoStmt::DoStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, DoStmt)
std::vector<::pasta::Stmt> DoStmt::Children(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token DoStmt::BeginToken(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt DoStmt::Body(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "DoStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr DoStmt::Cond(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DoStmt::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DoStmt::DoToken(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getDoLoc();
  return ast->TokenAt(val);
}

::pasta::Token DoStmt::EndToken(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DoStmt::RParenToken(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token DoStmt::WhileToken(void) const {
  auto &self = *(u.DoStmt);
  auto val = self.getWhileLoc();
  return ast->TokenAt(val);
}

Expr::Expr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ValueStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, Expr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, Expr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, AbstractConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, AddrLabelExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ArrayInitIndexExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ArrayInitLoopExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ArraySubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ArrayTypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, AsTypeExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, AtomicExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, BinaryConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, BinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, BlockExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, BuiltinBitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CStyleCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CUDAKernelCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXAddrspaceCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXBindTemporaryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXBoolLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXConstCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXDefaultArgExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXDefaultInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXDeleteExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXDependentScopeMemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXDynamicCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXFoldExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXFunctionalCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXInheritedCtorInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXMemberCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXNamedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXNewExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXNoexceptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXNullPtrLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXOperatorCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXPseudoDestructorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXReinterpretCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXRewrittenBinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXScalarValueInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXStaticCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXStdInitializerListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXTemporaryObjectExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXThisExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXThrowExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXTypeidExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXUnresolvedConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXUuidofExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CharacterLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ChooseExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CompoundAssignOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CompoundLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ConceptSpecializationExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ConstantExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ConvertVectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CoroutineSuspendExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CoyieldExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, DeclRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, DependentCoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, DependentScopeDeclRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, DesignatedInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, DesignatedInitUpdateExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ExplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ExprWithCleanups)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ExpressionTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ExtVectorElementExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, FixedPointLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, FloatingLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, FullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, FunctionParmPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, GNUNullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, GenericSelectionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ImaginaryLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ImplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ImplicitValueInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, InitListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, IntegerLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, LambdaExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, MSPropertyRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, MSPropertySubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, MaterializeTemporaryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, MatrixSubscriptExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, MemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, NoInitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, OMPArraySectionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, OMPArrayShapingExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, OMPIteratorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCArrayLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCBoolLiteralExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCBoxedExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCBridgedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCDictionaryLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCEncodeExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCIndirectCopyRestoreExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCIsaExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCIvarRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCMessageExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCPropertyRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCProtocolExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCSelectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCStringLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ObjCSubscriptRefExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, OffsetOfExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, OpaqueValueExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, OverloadExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, PackExpansionExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ParenExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ParenListExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, PredefinedExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, PseudoObjectExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, RecoveryExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, RequiresExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, ShuffleVectorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, SizeOfPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, SourceLocExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, StmtExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, StringLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, SubstNonTypeTemplateParmExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, SubstNonTypeTemplateParmPackExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, TypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, TypoExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, UnaryExprOrTypeTraitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, UnaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, UnresolvedLookupExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, UnresolvedMemberExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, UserDefinedLiteral)
PASTA_DEFINE_DERIVED_OPERATORS(Expr, VAArgExpr)
// 1: Expr::Classify
// 1: Expr::ClassifyLValue
// 2: ClassifyModifiable
// 2: EvaluateAsBooleanCondition
// 2: EvaluateAsConstantExpr
// 2: EvaluateAsFixedPoint
// 2: EvaluateAsFloat
// 5: Expr::EvaluateAsInitializer
// 2: EvaluateAsInt
// 2: EvaluateAsLValue
// 2: EvaluateAsRValue
// 1: Expr::EvaluateKnownConstInt
// 1: Expr::EvaluateKnownConstIntCheckOverflow
// 4: Expr::EvaluateWithSubstitution
bool Expr::HasSideEffects(void) const {
  auto &self = *(u.Expr);
  auto val = self.HasSideEffects(ast->ci->getASTContext());
  return val;
}

::pasta::Expr Expr::IgnoreCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreConversionOperatorSingleStep(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreConversionOperatorSingleStep();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreConversionOperatorSingleStep can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreImpCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreImpCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreImpCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreImplicit(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreImplicit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreImplicit can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreImplicitAsWritten(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreImplicitAsWritten();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreImplicitAsWritten can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreParenBaseCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreParenBaseCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreParenBaseCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreParenCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreParenCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreParenCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreParenImpCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreParenImpCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreParenImpCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreParenLValueCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreParenLValueCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreParenLValueCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreParenNoopCasts(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreParenNoopCasts(ast->ci->getASTContext());
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreParenNoopCasts can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreParens(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreParens();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreParens can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::IgnoreUnlessSpelledInSource(void) const {
  auto &self = *(u.Expr);
  auto val = self.IgnoreUnlessSpelledInSource();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::IgnoreUnlessSpelledInSource can return nullptr!");
  __builtin_unreachable();
}

bool Expr::ContainsErrors(void) const {
  auto &self = *(u.Expr);
  auto val = self.containsErrors();
  return val;
}

bool Expr::ContainsUnexpandedParameterPack(void) const {
  auto &self = *(u.Expr);
  auto val = self.containsUnexpandedParameterPack();
  return val;
}

::pasta::CXXRecordDecl Expr::BestDynamicClassType(void) const {
  auto &self = *(u.Expr);
  auto val = self.getBestDynamicClassType();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "Expr::BestDynamicClassType can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr Expr::BestDynamicClassTypeExpr(void) const {
  auto &self = *(u.Expr);
  auto val = self.getBestDynamicClassTypeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "Expr::BestDynamicClassTypeExpr can return nullptr!");
  __builtin_unreachable();
}

// 0: Expr::Dependence
::pasta::Token Expr::ExprToken(void) const {
  auto &self = *(u.Expr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 1: Expr::FPFeaturesInEffect
// 1: Expr::IntegerConstantExpr
::pasta::ObjCPropertyRefExpr Expr::ObjCProperty(void) const {
  auto &self = *(u.Expr);
  auto val = self.getObjCProperty();
  if (val) {
    return StmtBuilder::Create<::pasta::ObjCPropertyRefExpr>(ast, val);
  }
  assert(false && "Expr::ObjCProperty can return nullptr!");
  __builtin_unreachable();
}

enum ExprObjectKind Expr::ObjectKind(void) const {
  auto &self = *(u.Expr);
  auto val = self.getObjectKind();
  return static_cast<::pasta::ExprObjectKind>(static_cast<unsigned int>(val));
}

::pasta::Decl Expr::ReferencedDeclOfCallee(void) const {
  auto &self = *(u.Expr);
  auto val = self.getReferencedDeclOfCallee();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Expr::ReferencedDeclOfCallee can return nullptr!");
  __builtin_unreachable();
}

::pasta::FieldDecl Expr::SourceBitField(void) const {
  auto &self = *(u.Expr);
  auto val = self.getSourceBitField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "Expr::SourceBitField can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type Expr::Type(void) const {
  auto &self = *(u.Expr);
  auto val = self.getType();
  return TypeBuilder::Build(ast, val);
}

enum ExprValueKind Expr::ValueKind(void) const {
  auto &self = *(u.Expr);
  auto val = self.getValueKind();
  return static_cast<::pasta::ExprValueKind>(static_cast<unsigned int>(val));
}

bool Expr::HasNonTrivialCall(void) const {
  auto &self = *(u.Expr);
  auto val = self.hasNonTrivialCall(ast->ci->getASTContext());
  return val;
}

bool Expr::IsBoundMemberFunction(void) const {
  auto &self = *(u.Expr);
  auto val = self.isBoundMemberFunction(ast->ci->getASTContext());
  return val;
}

bool Expr::IsCXX11ConstantExpr(void) const {
  auto &self = *(u.Expr);
  auto val = self.isCXX11ConstantExpr(ast->ci->getASTContext());
  return val;
}

bool Expr::IsCXX98IntegralConstantExpr(void) const {
  auto &self = *(u.Expr);
  auto val = self.isCXX98IntegralConstantExpr(ast->ci->getASTContext());
  return val;
}

// 2: IsConstantInitializer
bool Expr::IsDefaultArgument(void) const {
  auto &self = *(u.Expr);
  auto val = self.isDefaultArgument();
  return val;
}

bool Expr::IsEvaluatable(void) const {
  auto &self = *(u.Expr);
  auto val = self.isEvaluatable(ast->ci->getASTContext());
  return val;
}

bool Expr::IsGLValue(void) const {
  auto &self = *(u.Expr);
  auto val = self.isGLValue();
  return val;
}

bool Expr::IsImplicitCXXThis(void) const {
  auto &self = *(u.Expr);
  auto val = self.isImplicitCXXThis();
  return val;
}

bool Expr::IsInstantiationDependent(void) const {
  auto &self = *(u.Expr);
  auto val = self.isInstantiationDependent();
  return val;
}

bool Expr::IsIntegerConstantExpr(void) const {
  auto &self = *(u.Expr);
  auto val = self.isIntegerConstantExpr(ast->ci->getASTContext());
  return val;
}

bool Expr::IsKnownToHaveBooleanValue(void) const {
  auto &self = *(u.Expr);
  auto val = self.isKnownToHaveBooleanValue();
  return val;
}

bool Expr::IsLValue(void) const {
  auto &self = *(u.Expr);
  auto val = self.isLValue();
  return val;
}

// 1: Expr::IsModifiableLvalue
// 2: IsNullPointerConstant
bool Expr::IsOBJCGCCandidate(void) const {
  auto &self = *(u.Expr);
  auto val = self.isOBJCGCCandidate(ast->ci->getASTContext());
  return val;
}

bool Expr::IsObjCSelfExpr(void) const {
  auto &self = *(u.Expr);
  auto val = self.isObjCSelfExpr();
  return val;
}

bool Expr::IsOrdinaryOrBitFieldObject(void) const {
  auto &self = *(u.Expr);
  auto val = self.isOrdinaryOrBitFieldObject();
  return val;
}

bool Expr::IsRValue(void) const {
  auto &self = *(u.Expr);
  auto val = self.isRValue();
  return val;
}

bool Expr::IsReadIfDiscardedInCPlusPlus11(void) const {
  auto &self = *(u.Expr);
  auto val = self.isReadIfDiscardedInCPlusPlus11();
  return val;
}

// 2: IsTemporaryObject
bool Expr::IsTypeDependent(void) const {
  auto &self = *(u.Expr);
  auto val = self.isTypeDependent();
  return val;
}

// 5: Expr::IsUnusedResultAWarning
bool Expr::IsValueDependent(void) const {
  auto &self = *(u.Expr);
  auto val = self.isValueDependent();
  return val;
}

bool Expr::IsXValue(void) const {
  auto &self = *(u.Expr);
  auto val = self.isXValue();
  return val;
}

bool Expr::RefersToBitField(void) const {
  auto &self = *(u.Expr);
  auto val = self.refersToBitField();
  return val;
}

bool Expr::RefersToGlobalRegisterVar(void) const {
  auto &self = *(u.Expr);
  auto val = self.refersToGlobalRegisterVar();
  return val;
}

bool Expr::RefersToMatrixElement(void) const {
  auto &self = *(u.Expr);
  auto val = self.refersToMatrixElement();
  return val;
}

bool Expr::RefersToVectorElement(void) const {
  auto &self = *(u.Expr);
  auto val = self.refersToVectorElement();
  return val;
}

// 3: Expr::TryEvaluateObjectSize
ExpressionTraitExpr::ExpressionTraitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ExpressionTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ExpressionTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ExpressionTraitExpr)
std::vector<::pasta::Stmt> ExpressionTraitExpr::Children(void) const {
  auto &self = *(u.ExpressionTraitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ExpressionTraitExpr::BeginToken(void) const {
  auto &self = *(u.ExpressionTraitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExpressionTraitExpr::EndToken(void) const {
  auto &self = *(u.ExpressionTraitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ExpressionTraitExpr::QueriedExpression(void) const {
  auto &self = *(u.ExpressionTraitExpr);
  auto val = self.getQueriedExpression();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ExpressionTraitExpr::QueriedExpression can return nullptr!");
  __builtin_unreachable();
}

enum ExpressionTrait ExpressionTraitExpr::Trait(void) const {
  auto &self = *(u.ExpressionTraitExpr);
  auto val = self.getTrait();
  return static_cast<::pasta::ExpressionTrait>(static_cast<unsigned int>(val));
}

bool ExpressionTraitExpr::Value(void) const {
  auto &self = *(u.ExpressionTraitExpr);
  auto val = self.getValue();
  return val;
}

ExtVectorElementExpr::ExtVectorElementExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ExtVectorElementExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ExtVectorElementExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ExtVectorElementExpr)
std::vector<::pasta::Stmt> ExtVectorElementExpr::Children(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

bool ExtVectorElementExpr::ContainsDuplicateElements(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.containsDuplicateElements();
  return val;
}

// 0: ExtVectorElementExpr::Accessor
::pasta::Token ExtVectorElementExpr::AccessorToken(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.getAccessorLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ExtVectorElementExpr::Base(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ExtVectorElementExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ExtVectorElementExpr::BeginToken(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExtVectorElementExpr::EndToken(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ExtVectorElementExpr::NumElements(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.getNumElements();
  return val;
}

bool ExtVectorElementExpr::IsArrow(void) const {
  auto &self = *(u.ExtVectorElementExpr);
  auto val = self.isArrow();
  return val;
}

FixedPointLiteral::FixedPointLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, FixedPointLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, FixedPointLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, FixedPointLiteral)
std::vector<::pasta::Stmt> FixedPointLiteral::Children(void) const {
  auto &self = *(u.FixedPointLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token FixedPointLiteral::BeginToken(void) const {
  auto &self = *(u.FixedPointLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token FixedPointLiteral::EndToken(void) const {
  auto &self = *(u.FixedPointLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token FixedPointLiteral::Token(void) const {
  auto &self = *(u.FixedPointLiteral);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t FixedPointLiteral::Scale(void) const {
  auto &self = *(u.FixedPointLiteral);
  auto val = self.getScale();
  return val;
}

// 1: FixedPointLiteral::ValueAsString
FloatingLiteral::FloatingLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, FloatingLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, FloatingLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, FloatingLiteral)
std::vector<::pasta::Stmt> FloatingLiteral::Children(void) const {
  auto &self = *(u.FloatingLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token FloatingLiteral::BeginToken(void) const {
  auto &self = *(u.FloatingLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token FloatingLiteral::EndToken(void) const {
  auto &self = *(u.FloatingLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token FloatingLiteral::Token(void) const {
  auto &self = *(u.FloatingLiteral);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

// 0: FloatingLiteral::RawSemantics
// 0: FloatingLiteral::Semantics
// 0: FloatingLiteral::Value
// 0: FloatingLiteral::ValueAsApproximateDouble
bool FloatingLiteral::IsExact(void) const {
  auto &self = *(u.FloatingLiteral);
  auto val = self.isExact();
  return val;
}

ForStmt::ForStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ForStmt)
std::vector<::pasta::Stmt> ForStmt::Children(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ForStmt::BeginToken(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ForStmt::Body(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ForStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ForStmt::Cond(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ForStmt::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl ForStmt::ConditionVariable(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getConditionVariable();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "ForStmt::ConditionVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclStmt ForStmt::ConditionVariableDeclStmt(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getConditionVariableDeclStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "ForStmt::ConditionVariableDeclStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ForStmt::EndToken(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ForStmt::ForToken(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getForLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ForStmt::Inc(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ForStmt::Inc can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt ForStmt::Init(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ForStmt::Init can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ForStmt::LParenToken(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token ForStmt::RParenToken(void) const {
  auto &self = *(u.ForStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

FullExpr::FullExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, FullExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, FullExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, FullExpr)
PASTA_DEFINE_DERIVED_OPERATORS(FullExpr, ConstantExpr)
PASTA_DEFINE_DERIVED_OPERATORS(FullExpr, ExprWithCleanups)
::pasta::Expr FullExpr::SubExpr(void) const {
  auto &self = *(u.FullExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "FullExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

FunctionParmPackExpr::FunctionParmPackExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, FunctionParmPackExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, FunctionParmPackExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, FunctionParmPackExpr)
// 0: FunctionParmPackExpr::Begin
std::vector<::pasta::Stmt> FunctionParmPackExpr::Children(void) const {
  auto &self = *(u.FunctionParmPackExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: FunctionParmPackExpr::End
::pasta::Token FunctionParmPackExpr::BeginToken(void) const {
  auto &self = *(u.FunctionParmPackExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token FunctionParmPackExpr::EndToken(void) const {
  auto &self = *(u.FunctionParmPackExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: FunctionParmPackExpr::Expansion
uint32_t FunctionParmPackExpr::NumExpansions(void) const {
  auto &self = *(u.FunctionParmPackExpr);
  auto val = self.getNumExpansions();
  return val;
}

::pasta::VarDecl FunctionParmPackExpr::ParameterPack(void) const {
  auto &self = *(u.FunctionParmPackExpr);
  auto val = self.getParameterPack();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "FunctionParmPackExpr::ParameterPack can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FunctionParmPackExpr::ParameterPackLocation(void) const {
  auto &self = *(u.FunctionParmPackExpr);
  auto val = self.getParameterPackLocation();
  return ast->TokenAt(val);
}

std::vector<::pasta::VarDecl> FunctionParmPackExpr::Expansions(void) const {
  auto convert_elem = [&] (clang::VarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::VarDecl> ret;
  auto count = u.FunctionParmPackExpr->getNumExpansions();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FunctionParmPackExpr->getExpansion(i)));
  }
  return ret;
}

GCCAsmStmt::GCCAsmStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : AsmStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(AsmStmt, GCCAsmStmt)
PASTA_DEFINE_BASE_OPERATORS(Stmt, GCCAsmStmt)
// 3: GCCAsmStmt::AnalyzeAsmString
// 0: GCCAsmStmt::
// 0: GCCAsmStmt::
std::string GCCAsmStmt::GenerateAsmString(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.generateAsmString(ast->ci->getASTContext());
  return val;
}

::pasta::StringLiteral GCCAsmStmt::AsmString(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.getAsmString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "GCCAsmStmt::AsmString can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token GCCAsmStmt::BeginToken(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: GCCAsmStmt::Clobber
// 1: GCCAsmStmt::ClobberStringLiteral
::pasta::Token GCCAsmStmt::EndToken(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: GCCAsmStmt::InputConstraint
// 1: GCCAsmStmt::InputConstraintLiteral
// 1: GCCAsmStmt::InputExpr
// 1: GCCAsmStmt::InputIdentifier
// 1: GCCAsmStmt::InputName
// 1: GCCAsmStmt::LabelExpr
// 1: GCCAsmStmt::LabelIdentifier
// 1: GCCAsmStmt::LabelName
// 1: GCCAsmStmt::NamedOperand
uint32_t GCCAsmStmt::NumLabels(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.getNumLabels();
  return val;
}

// 1: GCCAsmStmt::OutputConstraint
// 1: GCCAsmStmt::OutputConstraintLiteral
// 1: GCCAsmStmt::OutputExpr
// 1: GCCAsmStmt::OutputIdentifier
// 1: GCCAsmStmt::OutputName
::pasta::Token GCCAsmStmt::RParenToken(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool GCCAsmStmt::IsAsmGoto(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.isAsmGoto();
  return val;
}

std::vector<::pasta::AddrLabelExpr> GCCAsmStmt::Labels(void) const {
  auto &self = *(u.GCCAsmStmt);
  auto val = self.labels();
  std::vector<::pasta::AddrLabelExpr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::AddrLabelExpr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::AddrLabelExpr> GCCAsmStmt::LabelExprs(void) const {
  auto convert_elem = [&] (clang::AddrLabelExpr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::AddrLabelExpr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::AddrLabelExpr> ret;
  auto count = u.GCCAsmStmt->getNumLabels();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getLabelExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::LabelNames(void) const {
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    __builtin_unreachable();
  };
  std::vector<std::string_view> ret;
  auto count = u.GCCAsmStmt->getNumLabels();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getLabelName(i)));
  }
  return ret;
}

GNUNullExpr::GNUNullExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, GNUNullExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, GNUNullExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, GNUNullExpr)
std::vector<::pasta::Stmt> GNUNullExpr::Children(void) const {
  auto &self = *(u.GNUNullExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token GNUNullExpr::BeginToken(void) const {
  auto &self = *(u.GNUNullExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token GNUNullExpr::EndToken(void) const {
  auto &self = *(u.GNUNullExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token GNUNullExpr::TokenLocation(void) const {
  auto &self = *(u.GNUNullExpr);
  auto val = self.getTokenLocation();
  return ast->TokenAt(val);
}

GenericSelectionExpr::GenericSelectionExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, GenericSelectionExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, GenericSelectionExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, GenericSelectionExpr)
// 0: GenericSelectionExpr::Associations
std::vector<::pasta::Stmt> GenericSelectionExpr::Children(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> GenericSelectionExpr::AssocExprs(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getAssocExprs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

// 0: GenericSelectionExpr::AssocTypeSourceInfos
// 1: GenericSelectionExpr::Association
::pasta::Token GenericSelectionExpr::BeginToken(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr GenericSelectionExpr::ControllingExpr(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getControllingExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "GenericSelectionExpr::ControllingExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token GenericSelectionExpr::DefaultToken(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getDefaultLoc();
  return ast->TokenAt(val);
}

::pasta::Token GenericSelectionExpr::EndToken(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token GenericSelectionExpr::GenericToken(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getGenericLoc();
  return ast->TokenAt(val);
}

uint32_t GenericSelectionExpr::NumAssocs(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getNumAssocs();
  return val;
}

::pasta::Token GenericSelectionExpr::RParenToken(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr GenericSelectionExpr::ResultExpr(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getResultExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "GenericSelectionExpr::ResultExpr can return nullptr!");
  __builtin_unreachable();
}

uint32_t GenericSelectionExpr::ResultIndex(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.getResultIndex();
  return val;
}

bool GenericSelectionExpr::IsResultDependent(void) const {
  auto &self = *(u.GenericSelectionExpr);
  auto val = self.isResultDependent();
  return val;
}

GotoStmt::GotoStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, GotoStmt)
std::vector<::pasta::Stmt> GotoStmt::Children(void) const {
  auto &self = *(u.GotoStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token GotoStmt::BeginToken(void) const {
  auto &self = *(u.GotoStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token GotoStmt::EndToken(void) const {
  auto &self = *(u.GotoStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token GotoStmt::GotoToken(void) const {
  auto &self = *(u.GotoStmt);
  auto val = self.getGotoLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl GotoStmt::Label(void) const {
  auto &self = *(u.GotoStmt);
  auto val = self.getLabel();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  assert(false && "GotoStmt::Label can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token GotoStmt::LabelToken(void) const {
  auto &self = *(u.GotoStmt);
  auto val = self.getLabelLoc();
  return ast->TokenAt(val);
}

IfStmt::IfStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, IfStmt)
std::vector<::pasta::Stmt> IfStmt::Children(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token IfStmt::BeginToken(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr IfStmt::Cond(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "IfStmt::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl IfStmt::ConditionVariable(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getConditionVariable();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "IfStmt::ConditionVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclStmt IfStmt::ConditionVariableDeclStmt(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getConditionVariableDeclStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  assert(false && "IfStmt::ConditionVariableDeclStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt IfStmt::Else(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getElse();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "IfStmt::Else can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token IfStmt::ElseToken(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getElseLoc();
  return ast->TokenAt(val);
}

::pasta::Token IfStmt::EndToken(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token IfStmt::IfToken(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getIfLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt IfStmt::Init(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "IfStmt::Init can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token IfStmt::LParenToken(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

// 1: IfStmt::NondiscardedCase
::pasta::Token IfStmt::RParenToken(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt IfStmt::Then(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.getThen();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "IfStmt::Then can return nullptr!");
  __builtin_unreachable();
}

bool IfStmt::HasElseStorage(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.hasElseStorage();
  return val;
}

bool IfStmt::HasInitStorage(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.hasInitStorage();
  return val;
}

bool IfStmt::HasVarStorage(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.hasVarStorage();
  return val;
}

bool IfStmt::IsConstexpr(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.isConstexpr();
  return val;
}

bool IfStmt::IsObjCAvailabilityCheck(void) const {
  auto &self = *(u.IfStmt);
  auto val = self.isObjCAvailabilityCheck();
  return val;
}

ImaginaryLiteral::ImaginaryLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ImaginaryLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ImaginaryLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ImaginaryLiteral)
std::vector<::pasta::Stmt> ImaginaryLiteral::Children(void) const {
  auto &self = *(u.ImaginaryLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ImaginaryLiteral::BeginToken(void) const {
  auto &self = *(u.ImaginaryLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ImaginaryLiteral::EndToken(void) const {
  auto &self = *(u.ImaginaryLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ImaginaryLiteral::SubExpr(void) const {
  auto &self = *(u.ImaginaryLiteral);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ImaginaryLiteral::SubExpr can return nullptr!");
  __builtin_unreachable();
}

ImplicitValueInitExpr::ImplicitValueInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ImplicitValueInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ImplicitValueInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ImplicitValueInitExpr)
std::vector<::pasta::Stmt> ImplicitValueInitExpr::Children(void) const {
  auto &self = *(u.ImplicitValueInitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ImplicitValueInitExpr::BeginToken(void) const {
  auto &self = *(u.ImplicitValueInitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ImplicitValueInitExpr::EndToken(void) const {
  auto &self = *(u.ImplicitValueInitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

IndirectGotoStmt::IndirectGotoStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, IndirectGotoStmt)
std::vector<::pasta::Stmt> IndirectGotoStmt::Children(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token IndirectGotoStmt::BeginToken(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl IndirectGotoStmt::ConstantTarget(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.getConstantTarget();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  assert(false && "IndirectGotoStmt::ConstantTarget can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token IndirectGotoStmt::EndToken(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token IndirectGotoStmt::GotoToken(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.getGotoLoc();
  return ast->TokenAt(val);
}

::pasta::Token IndirectGotoStmt::StarToken(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.getStarLoc();
  return ast->TokenAt(val);
}

::pasta::Expr IndirectGotoStmt::Target(void) const {
  auto &self = *(u.IndirectGotoStmt);
  auto val = self.getTarget();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "IndirectGotoStmt::Target can return nullptr!");
  __builtin_unreachable();
}

InitListExpr::InitListExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, InitListExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, InitListExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, InitListExpr)
// 0: InitListExpr::Begin
std::vector<::pasta::Stmt> InitListExpr::Children(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: InitListExpr::End
::pasta::Expr InitListExpr::ArrayFiller(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getArrayFiller();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "InitListExpr::ArrayFiller can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token InitListExpr::BeginToken(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token InitListExpr::EndToken(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: InitListExpr::Init
::pasta::FieldDecl InitListExpr::InitializedFieldInUnion(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getInitializedFieldInUnion();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "InitListExpr::InitializedFieldInUnion can return nullptr!");
  __builtin_unreachable();
}

// 0: InitListExpr::Initializers
::pasta::Token InitListExpr::LBraceToken(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getLBraceLoc();
  return ast->TokenAt(val);
}

uint32_t InitListExpr::NumInits(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getNumInits();
  return val;
}

::pasta::Token InitListExpr::RBraceToken(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::InitListExpr InitListExpr::SemanticForm(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getSemanticForm();
  if (val) {
    return StmtBuilder::Create<::pasta::InitListExpr>(ast, val);
  }
  assert(false && "InitListExpr::SemanticForm can return nullptr!");
  __builtin_unreachable();
}

::pasta::InitListExpr InitListExpr::SyntacticForm(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.getSyntacticForm();
  if (val) {
    return StmtBuilder::Create<::pasta::InitListExpr>(ast, val);
  }
  assert(false && "InitListExpr::SyntacticForm can return nullptr!");
  __builtin_unreachable();
}

bool InitListExpr::HadArrayRangeDesignator(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.hadArrayRangeDesignator();
  return val;
}

bool InitListExpr::HasArrayFiller(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.hasArrayFiller();
  return val;
}

std::vector<::pasta::Expr> InitListExpr::Initializers(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.inits();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

bool InitListExpr::IsExplicit(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.isExplicit();
  return val;
}

// 1: InitListExpr::IsIdiomaticZeroInitializer
bool InitListExpr::IsSemanticForm(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.isSemanticForm();
  return val;
}

bool InitListExpr::IsStringLiteralInit(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.isStringLiteralInit();
  return val;
}

bool InitListExpr::IsSyntacticForm(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.isSyntacticForm();
  return val;
}

bool InitListExpr::IsTransparent(void) const {
  auto &self = *(u.InitListExpr);
  auto val = self.isTransparent();
  return val;
}

// 0: InitListExpr::Rbegin
// 0: InitListExpr::Rend
std::vector<::pasta::Expr> InitListExpr::Inits(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.InitListExpr->getNumInits();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.InitListExpr->getInit(i)));
  }
  return ret;
}

IntegerLiteral::IntegerLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, IntegerLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, IntegerLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, IntegerLiteral)
std::vector<::pasta::Stmt> IntegerLiteral::Children(void) const {
  auto &self = *(u.IntegerLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token IntegerLiteral::BeginToken(void) const {
  auto &self = *(u.IntegerLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token IntegerLiteral::EndToken(void) const {
  auto &self = *(u.IntegerLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token IntegerLiteral::Token(void) const {
  auto &self = *(u.IntegerLiteral);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

LabelStmt::LabelStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ValueStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, LabelStmt)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, LabelStmt)
std::vector<::pasta::Stmt> LabelStmt::Children(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token LabelStmt::BeginToken(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl LabelStmt::Decl(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  assert(false && "LabelStmt::Decl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token LabelStmt::EndToken(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token LabelStmt::IdentToken(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.getIdentLoc();
  return ast->TokenAt(val);
}

std::string_view LabelStmt::Name(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.getName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "LabelStmt::Name can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt LabelStmt::SubStmt(void) const {
  auto &self = *(u.LabelStmt);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "LabelStmt::SubStmt can return nullptr!");
  __builtin_unreachable();
}

LambdaExpr::LambdaExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, LambdaExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, LambdaExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, LambdaExpr)
// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::Capture_inits
// 0: LambdaExpr::
// 0: LambdaExpr::Captures
std::vector<::pasta::Stmt> LambdaExpr::Children(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::Explicit_captures
::pasta::Token LambdaExpr::BeginToken(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt LambdaExpr::Body(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "LambdaExpr::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXMethodDecl LambdaExpr::CallOperator(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "LambdaExpr::CallOperator can return nullptr!");
  __builtin_unreachable();
}

enum LambdaCaptureDefault LambdaExpr::CaptureDefault(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(static_cast<unsigned int>(val));
}

::pasta::Token LambdaExpr::CaptureDefaultToken(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getCaptureDefaultLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt LambdaExpr::CompoundStmtBody(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getCompoundStmtBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "LambdaExpr::CompoundStmtBody can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl LambdaExpr::DependentCallOperator(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getDependentCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "LambdaExpr::DependentCallOperator can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token LambdaExpr::EndToken(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::NamedDecl> LambdaExpr::ExplicitTemplateParameters(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getExplicitTemplateParameters();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::TokenRange LambdaExpr::IntroducerRange(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getIntroducerRange();
  return ast->TokenRangeFrom(val);
}

::pasta::CXXRecordDecl LambdaExpr::LambdaClass(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getLambdaClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "LambdaExpr::LambdaClass can return nullptr!");
  __builtin_unreachable();
}

// 0: LambdaExpr::TemplateParameterList
::pasta::Expr LambdaExpr::TrailingRequiresClause(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.getTrailingRequiresClause();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "LambdaExpr::TrailingRequiresClause can return nullptr!");
  __builtin_unreachable();
}

bool LambdaExpr::HasExplicitParameters(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.hasExplicitParameters();
  return val;
}

bool LambdaExpr::HasExplicitResultType(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.hasExplicitResultType();
  return val;
}

// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::Implicit_captures
bool LambdaExpr::IsGenericLambda(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.isGenericLambda();
  return val;
}

// 1: LambdaExpr::IsInitCapture
bool LambdaExpr::IsMutable(void) const {
  auto &self = *(u.LambdaExpr);
  auto val = self.isMutable();
  return val;
}

MSAsmStmt::MSAsmStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : AsmStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(AsmStmt, MSAsmStmt)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MSAsmStmt)
std::vector<::pasta::Stmt> MSAsmStmt::Children(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

std::string MSAsmStmt::GenerateAsmString(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.generateAsmString(ast->ci->getASTContext());
  return val;
}

std::vector<std::string_view> MSAsmStmt::AllConstraints(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getAllConstraints();
  std::vector<std::string_view> ret;
  for (auto sr : val) {
    std::string_view sv(sr.data(), sr.size());
    ret.emplace_back(std::move(sv));
  }
  return ret;
}

std::vector<::pasta::Expr> MSAsmStmt::AllExprs(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getAllExprs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::string_view MSAsmStmt::AsmString(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getAsmString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token MSAsmStmt::BeginToken(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: MSAsmStmt::Clobber
std::vector<std::string_view> MSAsmStmt::Clobbers(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getClobbers();
  std::vector<std::string_view> ret;
  for (auto sr : val) {
    std::string_view sv(sr.data(), sr.size());
    ret.emplace_back(std::move(sv));
  }
  return ret;
}

::pasta::Token MSAsmStmt::EndToken(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: MSAsmStmt::InputConstraint
// 1: MSAsmStmt::InputExpr
::pasta::Token MSAsmStmt::LBraceToken(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.getLBraceLoc();
  return ast->TokenAt(val);
}

// 1: MSAsmStmt::OutputConstraint
// 1: MSAsmStmt::OutputExpr
bool MSAsmStmt::HasBraces(void) const {
  auto &self = *(u.MSAsmStmt);
  auto val = self.hasBraces();
  return val;
}

MSDependentExistsStmt::MSDependentExistsStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, MSDependentExistsStmt)
std::vector<::pasta::Stmt> MSDependentExistsStmt::Children(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token MSDependentExistsStmt::BeginToken(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSDependentExistsStmt::EndToken(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSDependentExistsStmt::KeywordToken(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

// 0: MSDependentExistsStmt::NameInfo
// 0: MSDependentExistsStmt::QualifierToken
::pasta::CompoundStmt MSDependentExistsStmt::SubStmt(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "MSDependentExistsStmt::SubStmt can return nullptr!");
  __builtin_unreachable();
}

bool MSDependentExistsStmt::IsIfExists(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.isIfExists();
  return val;
}

bool MSDependentExistsStmt::IsIfNotExists(void) const {
  auto &self = *(u.MSDependentExistsStmt);
  auto val = self.isIfNotExists();
  return val;
}

MSPropertyRefExpr::MSPropertyRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, MSPropertyRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MSPropertyRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, MSPropertyRefExpr)
std::vector<::pasta::Stmt> MSPropertyRefExpr::Children(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr MSPropertyRefExpr::BaseExpr(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.getBaseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MSPropertyRefExpr::BaseExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MSPropertyRefExpr::BeginToken(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertyRefExpr::EndToken(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertyRefExpr::MemberToken(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.getMemberLoc();
  return ast->TokenAt(val);
}

::pasta::MSPropertyDecl MSPropertyRefExpr::PropertyDecl(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.getPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::MSPropertyDecl>(ast, val);
  }
  assert(false && "MSPropertyRefExpr::PropertyDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: MSPropertyRefExpr::QualifierToken
::pasta::TokenRange MSPropertyRefExpr::TokenRange(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool MSPropertyRefExpr::IsArrow(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.isArrow();
  return val;
}

bool MSPropertyRefExpr::IsImplicitAccess(void) const {
  auto &self = *(u.MSPropertyRefExpr);
  auto val = self.isImplicitAccess();
  return val;
}

MSPropertySubscriptExpr::MSPropertySubscriptExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, MSPropertySubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MSPropertySubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, MSPropertySubscriptExpr)
std::vector<::pasta::Stmt> MSPropertySubscriptExpr::Children(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr MSPropertySubscriptExpr::Base(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MSPropertySubscriptExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MSPropertySubscriptExpr::BeginToken(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertySubscriptExpr::EndToken(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertySubscriptExpr::ExprToken(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr MSPropertySubscriptExpr::Idx(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.getIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MSPropertySubscriptExpr::Idx can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MSPropertySubscriptExpr::RBracketToken(void) const {
  auto &self = *(u.MSPropertySubscriptExpr);
  auto val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

MaterializeTemporaryExpr::MaterializeTemporaryExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, MaterializeTemporaryExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MaterializeTemporaryExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, MaterializeTemporaryExpr)
std::vector<::pasta::Stmt> MaterializeTemporaryExpr::Children(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token MaterializeTemporaryExpr::BeginToken(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MaterializeTemporaryExpr::EndToken(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ValueDecl MaterializeTemporaryExpr::ExtendingDecl(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getExtendingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "MaterializeTemporaryExpr::ExtendingDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::LifetimeExtendedTemporaryDecl MaterializeTemporaryExpr::LifetimeExtendedTemporaryDecl(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getLifetimeExtendedTemporaryDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::LifetimeExtendedTemporaryDecl>(ast, val);
  }
  assert(false && "MaterializeTemporaryExpr::LifetimeExtendedTemporaryDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t MaterializeTemporaryExpr::ManglingNumber(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getManglingNumber();
  return val;
}

// 1: MaterializeTemporaryExpr::OrCreateValue
enum StorageDuration MaterializeTemporaryExpr::StorageDuration(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(static_cast<unsigned int>(val));
}

::pasta::Expr MaterializeTemporaryExpr::SubExpr(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MaterializeTemporaryExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

bool MaterializeTemporaryExpr::IsBoundToLvalueReference(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.isBoundToLvalueReference();
  return val;
}

bool MaterializeTemporaryExpr::IsUsableInConstantExpressions(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  auto val = self.isUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

MatrixSubscriptExpr::MatrixSubscriptExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, MatrixSubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MatrixSubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, MatrixSubscriptExpr)
std::vector<::pasta::Stmt> MatrixSubscriptExpr::Children(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr MatrixSubscriptExpr::Base(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MatrixSubscriptExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MatrixSubscriptExpr::BeginToken(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr MatrixSubscriptExpr::ColumnIdx(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getColumnIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MatrixSubscriptExpr::ColumnIdx can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MatrixSubscriptExpr::EndToken(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MatrixSubscriptExpr::ExprToken(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token MatrixSubscriptExpr::RBracketToken(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr MatrixSubscriptExpr::RowIdx(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.getRowIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MatrixSubscriptExpr::RowIdx can return nullptr!");
  __builtin_unreachable();
}

bool MatrixSubscriptExpr::IsIncomplete(void) const {
  auto &self = *(u.MatrixSubscriptExpr);
  auto val = self.isIncomplete();
  return val;
}

MemberExpr::MemberExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, MemberExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MemberExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, MemberExpr)
std::vector<::pasta::Stmt> MemberExpr::Children(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr MemberExpr::Base(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "MemberExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MemberExpr::BeginToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MemberExpr::EndToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MemberExpr::ExprToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::FoundDecl
::pasta::Token MemberExpr::LAngleToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

::pasta::ValueDecl MemberExpr::MemberDecl(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getMemberDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "MemberExpr::MemberDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token MemberExpr::MemberToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getMemberLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::MemberNameInfo
uint32_t MemberExpr::NumTemplateArgs(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getNumTemplateArgs();
  return val;
}

::pasta::Token MemberExpr::OperatorToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::Qualifier
// 0: MemberExpr::QualifierToken
::pasta::Token MemberExpr::RAngleToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::TemplateArgs
::pasta::Token MemberExpr::TemplateKeywordToken(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool MemberExpr::HadMultipleCandidates(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.hadMultipleCandidates();
  return val;
}

bool MemberExpr::HasExplicitTemplateArgs(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.hasExplicitTemplateArgs();
  return val;
}

bool MemberExpr::HasQualifier(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.hasQualifier();
  return val;
}

bool MemberExpr::HasTemplateKeyword(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.hasTemplateKeyword();
  return val;
}

bool MemberExpr::IsArrow(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.isArrow();
  return val;
}

bool MemberExpr::IsImplicitAccess(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.isImplicitAccess();
  return val;
}

enum NonOdrUseReason MemberExpr::IsNonOdrUse(void) const {
  auto &self = *(u.MemberExpr);
  auto val = self.isNonOdrUse();
  return static_cast<::pasta::NonOdrUseReason>(static_cast<unsigned int>(val));
}

// 1: MemberExpr::PerformsVirtualDispatch
// 0: MemberExpr::Template_arguments
NoInitExpr::NoInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, NoInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, NoInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, NoInitExpr)
std::vector<::pasta::Stmt> NoInitExpr::Children(void) const {
  auto &self = *(u.NoInitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token NoInitExpr::BeginToken(void) const {
  auto &self = *(u.NoInitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token NoInitExpr::EndToken(void) const {
  auto &self = *(u.NoInitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

NullStmt::NullStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, NullStmt)
std::vector<::pasta::Stmt> NullStmt::Children(void) const {
  auto &self = *(u.NullStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token NullStmt::BeginToken(void) const {
  auto &self = *(u.NullStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token NullStmt::EndToken(void) const {
  auto &self = *(u.NullStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token NullStmt::SemiToken(void) const {
  auto &self = *(u.NullStmt);
  auto val = self.getSemiLoc();
  return ast->TokenAt(val);
}

bool NullStmt::HasLeadingEmptyMacro(void) const {
  auto &self = *(u.NullStmt);
  auto val = self.hasLeadingEmptyMacro();
  return val;
}

OMPArraySectionExpr::OMPArraySectionExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OMPArraySectionExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPArraySectionExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OMPArraySectionExpr)
std::vector<::pasta::Stmt> OMPArraySectionExpr::Children(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr OMPArraySectionExpr::Base(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPArraySectionExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token OMPArraySectionExpr::BeginToken(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::ColonLocFirst(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getColonLocFirst();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::ColonLocSecond(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getColonLocSecond();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::EndToken(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::ExprToken(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr OMPArraySectionExpr::Length(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getLength();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPArraySectionExpr::Length can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPArraySectionExpr::LowerBound(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getLowerBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPArraySectionExpr::LowerBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token OMPArraySectionExpr::RBracketToken(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr OMPArraySectionExpr::Stride(void) const {
  auto &self = *(u.OMPArraySectionExpr);
  auto val = self.getStride();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPArraySectionExpr::Stride can return nullptr!");
  __builtin_unreachable();
}

OMPArrayShapingExpr::OMPArrayShapingExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OMPArrayShapingExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPArrayShapingExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OMPArrayShapingExpr)
std::vector<::pasta::Stmt> OMPArrayShapingExpr::Children(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr OMPArrayShapingExpr::Base(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPArrayShapingExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token OMPArrayShapingExpr::BeginToken(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::TokenRange> OMPArrayShapingExpr::BracketsRanges(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getBracketsRanges();
  std::vector<::pasta::TokenRange> ret;
  for (auto sr : val) {
    ret.emplace_back(ast->TokenRangeFrom(sr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPArrayShapingExpr::Dimensions(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getDimensions();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token OMPArrayShapingExpr::EndToken(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArrayShapingExpr::LParenToken(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArrayShapingExpr::RParenToken(void) const {
  auto &self = *(u.OMPArrayShapingExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

OMPExecutableDirective::OMPExecutableDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPExecutableDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPAtomicDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPBarrierDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPCancelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPCancellationPointDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPCriticalDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDepobjDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPFlushDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPOrderedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMasterDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelSectionsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPScanDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSectionDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSectionsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPSingleDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetDataDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetEnterDataDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetExitDataDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetUpdateDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskgroupDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskwaitDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTaskyieldDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeSimdDirective)
std::vector<::pasta::Stmt> OMPExecutableDirective::Children(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: OMPExecutableDirective::Clauses
::pasta::Stmt OMPExecutableDirective::AssociatedStmt(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getAssociatedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "OMPExecutableDirective::AssociatedStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token OMPExecutableDirective::BeginToken(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: OMPExecutableDirective::FindCapturedStmt
// 1: OMPExecutableDirective::Clause
// 0: OMPExecutableDirective::DirectiveKind
::pasta::Token OMPExecutableDirective::EndToken(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::CapturedStmt OMPExecutableDirective::InnermostCapturedStmt(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getInnermostCapturedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::CapturedStmt>(ast, val);
  }
  assert(false && "OMPExecutableDirective::InnermostCapturedStmt can return nullptr!");
  __builtin_unreachable();
}

uint32_t OMPExecutableDirective::NumClauses(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getNumClauses();
  return val;
}

::pasta::Stmt OMPExecutableDirective::FindRawStmt(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getRawStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "OMPExecutableDirective::FindRawStmt can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt OMPExecutableDirective::StructuredBlock(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.getStructuredBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "OMPExecutableDirective::StructuredBlock can return nullptr!");
  __builtin_unreachable();
}

bool OMPExecutableDirective::HasAssociatedStmt(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.hasAssociatedStmt();
  return val;
}

bool OMPExecutableDirective::IsStandaloneDirective(void) const {
  auto &self = *(u.OMPExecutableDirective);
  auto val = self.isStandaloneDirective();
  return val;
}

OMPFlushDirective::OMPFlushDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPFlushDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPFlushDirective)
OMPIteratorExpr::OMPIteratorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OMPIteratorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPIteratorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OMPIteratorExpr)
std::vector<::pasta::Stmt> OMPIteratorExpr::Children(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 1: OMPIteratorExpr::AssignToken
::pasta::Token OMPIteratorExpr::BeginToken(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::ColonToken
::pasta::Token OMPIteratorExpr::EndToken(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::Helper
// 1: OMPIteratorExpr::IteratorDecl
::pasta::Token OMPIteratorExpr::IteratorKwToken(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.getIteratorKwLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::IteratorRange
::pasta::Token OMPIteratorExpr::LParenToken(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPIteratorExpr::RParenToken(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::SecondColonToken
uint32_t OMPIteratorExpr::NumOfIterators(void) const {
  auto &self = *(u.OMPIteratorExpr);
  auto val = self.numOfIterators();
  return val;
}

OMPLoopDirective::OMPLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeSimdDirective)
std::vector<::pasta::Expr> OMPLoopDirective::Counters(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.counters();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Dependent_counters(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.dependent_counters();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Dependent_inits(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.dependent_inits();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Finals(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.finals();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Finals_conditions(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.finals_conditions();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Stmt OMPLoopDirective::Body(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "OMPLoopDirective::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CalcLastIteration(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCalcLastIteration();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CalcLastIteration can return nullptr!");
  __builtin_unreachable();
}

uint32_t OMPLoopDirective::CollapsedNumber(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCollapsedNumber();
  return val;
}

::pasta::Expr OMPLoopDirective::CombinedCond(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedCond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedDistCond(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedDistCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedDistCond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedEnsureUpperBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedEnsureUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedEnsureUpperBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedInit(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedInit can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedLowerBoundVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedLowerBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedLowerBoundVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedNextLowerBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedNextLowerBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedNextLowerBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedNextUpperBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedNextUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedNextUpperBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedParForInDistCond(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedParForInDistCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedParForInDistCond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::CombinedUpperBoundVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCombinedUpperBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::CombinedUpperBoundVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::Cond(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::DistInc(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getDistInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::DistInc can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::EnsureUpperBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getEnsureUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::EnsureUpperBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::Inc(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::Inc can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::Init(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::Init can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::IsLastIterVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getIsLastIterVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::IsLastIterVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::IterationVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getIterationVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::IterationVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::LastIteration(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getLastIteration();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::LastIteration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::LowerBoundVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getLowerBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::LowerBoundVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::NextLowerBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getNextLowerBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::NextLowerBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::NextUpperBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getNextUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::NextUpperBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::NumIterations(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getNumIterations();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::NumIterations can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::PreCond(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getPreCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::PreCond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt OMPLoopDirective::PreInits(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getPreInits();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "OMPLoopDirective::PreInits can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::PrevEnsureUpperBound(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getPrevEnsureUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::PrevEnsureUpperBound can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::PrevLowerBoundVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getPrevLowerBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::PrevLowerBoundVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::PrevUpperBoundVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getPrevUpperBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::PrevUpperBoundVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::StrideVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getStrideVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::StrideVariable can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPLoopDirective::UpperBoundVariable(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.getUpperBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPLoopDirective::UpperBoundVariable can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::Expr> OMPLoopDirective::Initializers(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.inits();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Private_counters(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.private_counters();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Updates(void) const {
  auto &self = *(u.OMPLoopDirective);
  auto val = self.updates();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

OMPMasterDirective::OMPMasterDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMasterDirective)
OMPMasterTaskLoopDirective::OMPMasterTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMasterTaskLoopDirective)
bool OMPMasterTaskLoopDirective::HasCancel(void) const {
  auto &self = *(u.OMPMasterTaskLoopDirective);
  auto val = self.hasCancel();
  return val;
}

OMPMasterTaskLoopSimdDirective::OMPMasterTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMasterTaskLoopSimdDirective)
OMPOrderedDirective::OMPOrderedDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPOrderedDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPOrderedDirective)
OMPParallelDirective::OMPParallelDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelDirective)
::pasta::Expr OMPParallelDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPParallelDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPParallelDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPParallelDirective::HasCancel(void) const {
  auto &self = *(u.OMPParallelDirective);
  auto val = self.hasCancel();
  return val;
}

OMPParallelForDirective::OMPParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelForDirective)
::pasta::Expr OMPParallelForDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPParallelForDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPParallelForDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPParallelForDirective::HasCancel(void) const {
  auto &self = *(u.OMPParallelForDirective);
  auto val = self.hasCancel();
  return val;
}

OMPParallelForSimdDirective::OMPParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelForSimdDirective)
OMPParallelMasterDirective::OMPParallelMasterDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMasterDirective)
::pasta::Expr OMPParallelMasterDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPParallelMasterDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPParallelMasterDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

OMPParallelMasterTaskLoopDirective::OMPParallelMasterTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMasterTaskLoopDirective)
bool OMPParallelMasterTaskLoopDirective::HasCancel(void) const {
  auto &self = *(u.OMPParallelMasterTaskLoopDirective);
  auto val = self.hasCancel();
  return val;
}

OMPParallelMasterTaskLoopSimdDirective::OMPParallelMasterTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMasterTaskLoopSimdDirective)
OMPParallelSectionsDirective::OMPParallelSectionsDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelSectionsDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelSectionsDirective)
::pasta::Expr OMPParallelSectionsDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPParallelSectionsDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPParallelSectionsDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPParallelSectionsDirective::HasCancel(void) const {
  auto &self = *(u.OMPParallelSectionsDirective);
  auto val = self.hasCancel();
  return val;
}

OMPScanDirective::OMPScanDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPScanDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPScanDirective)
OMPSectionDirective::OMPSectionDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPSectionDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPSectionDirective)
bool OMPSectionDirective::HasCancel(void) const {
  auto &self = *(u.OMPSectionDirective);
  auto val = self.hasCancel();
  return val;
}

OMPSectionsDirective::OMPSectionsDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPSectionsDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPSectionsDirective)
::pasta::Expr OMPSectionsDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPSectionsDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPSectionsDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPSectionsDirective::HasCancel(void) const {
  auto &self = *(u.OMPSectionsDirective);
  auto val = self.hasCancel();
  return val;
}

OMPSimdDirective::OMPSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPSimdDirective)
OMPSingleDirective::OMPSingleDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPSingleDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPSingleDirective)
OMPTargetDataDirective::OMPTargetDataDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetDataDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetDataDirective)
OMPTargetDirective::OMPTargetDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetDirective)
OMPTargetEnterDataDirective::OMPTargetEnterDataDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetEnterDataDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetEnterDataDirective)
OMPTargetExitDataDirective::OMPTargetExitDataDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetExitDataDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetExitDataDirective)
OMPTargetParallelDirective::OMPTargetParallelDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetParallelDirective)
::pasta::Expr OMPTargetParallelDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPTargetParallelDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPTargetParallelDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPTargetParallelDirective::HasCancel(void) const {
  auto &self = *(u.OMPTargetParallelDirective);
  auto val = self.hasCancel();
  return val;
}

OMPTargetParallelForDirective::OMPTargetParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetParallelForDirective)
::pasta::Expr OMPTargetParallelForDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPTargetParallelForDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPTargetParallelForDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPTargetParallelForDirective::HasCancel(void) const {
  auto &self = *(u.OMPTargetParallelForDirective);
  auto val = self.hasCancel();
  return val;
}

OMPTargetParallelForSimdDirective::OMPTargetParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetParallelForSimdDirective)
OMPTargetSimdDirective::OMPTargetSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetSimdDirective)
OMPTargetTeamsDirective::OMPTargetTeamsDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDirective)
OMPTargetTeamsDistributeDirective::OMPTargetTeamsDistributeDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeDirective)
OMPTargetTeamsDistributeParallelForDirective::OMPTargetTeamsDistributeParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForDirective)
::pasta::Expr OMPTargetTeamsDistributeParallelForDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPTargetTeamsDistributeParallelForDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPTargetTeamsDistributeParallelForDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPTargetTeamsDistributeParallelForDirective::HasCancel(void) const {
  auto &self = *(u.OMPTargetTeamsDistributeParallelForDirective);
  auto val = self.hasCancel();
  return val;
}

OMPTargetTeamsDistributeParallelForSimdDirective::OMPTargetTeamsDistributeParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForSimdDirective)
OMPTargetTeamsDistributeSimdDirective::OMPTargetTeamsDistributeSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeSimdDirective)
OMPTargetUpdateDirective::OMPTargetUpdateDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetUpdateDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetUpdateDirective)
OMPTaskDirective::OMPTaskDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskDirective)
bool OMPTaskDirective::HasCancel(void) const {
  auto &self = *(u.OMPTaskDirective);
  auto val = self.hasCancel();
  return val;
}

OMPTaskLoopDirective::OMPTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskLoopDirective)
bool OMPTaskLoopDirective::HasCancel(void) const {
  auto &self = *(u.OMPTaskLoopDirective);
  auto val = self.hasCancel();
  return val;
}

OMPTaskLoopSimdDirective::OMPTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskLoopSimdDirective)
OMPTaskgroupDirective::OMPTaskgroupDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskgroupDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskgroupDirective)
::pasta::Expr OMPTaskgroupDirective::ReductionRef(void) const {
  auto &self = *(u.OMPTaskgroupDirective);
  auto val = self.getReductionRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPTaskgroupDirective::ReductionRef can return nullptr!");
  __builtin_unreachable();
}

OMPTaskwaitDirective::OMPTaskwaitDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskwaitDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskwaitDirective)
OMPTaskyieldDirective::OMPTaskyieldDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskyieldDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskyieldDirective)
OMPTeamsDirective::OMPTeamsDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDirective)
OMPTeamsDistributeDirective::OMPTeamsDistributeDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeDirective)
OMPTeamsDistributeParallelForDirective::OMPTeamsDistributeParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeParallelForDirective)
::pasta::Expr OMPTeamsDistributeParallelForDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPTeamsDistributeParallelForDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPTeamsDistributeParallelForDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPTeamsDistributeParallelForDirective::HasCancel(void) const {
  auto &self = *(u.OMPTeamsDistributeParallelForDirective);
  auto val = self.hasCancel();
  return val;
}

OMPTeamsDistributeParallelForSimdDirective::OMPTeamsDistributeParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeParallelForSimdDirective)
OMPTeamsDistributeSimdDirective::OMPTeamsDistributeSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeSimdDirective)
ObjCArrayLiteral::ObjCArrayLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCArrayLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCArrayLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCArrayLiteral)
std::vector<::pasta::Stmt> ObjCArrayLiteral::Children(void) const {
  auto &self = *(u.ObjCArrayLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::ObjCMethodDecl ObjCArrayLiteral::ArrayWithObjectsMethod(void) const {
  auto &self = *(u.ObjCArrayLiteral);
  auto val = self.getArrayWithObjectsMethod();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCArrayLiteral::ArrayWithObjectsMethod can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCArrayLiteral::BeginToken(void) const {
  auto &self = *(u.ObjCArrayLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: ObjCArrayLiteral::Element
// 0: ObjCArrayLiteral::Elements
::pasta::Token ObjCArrayLiteral::EndToken(void) const {
  auto &self = *(u.ObjCArrayLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCArrayLiteral::NumElements(void) const {
  auto &self = *(u.ObjCArrayLiteral);
  auto val = self.getNumElements();
  return val;
}

::pasta::TokenRange ObjCArrayLiteral::TokenRange(void) const {
  auto &self = *(u.ObjCArrayLiteral);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

std::vector<::pasta::Expr> ObjCArrayLiteral::Elements(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.ObjCArrayLiteral->getNumElements();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCArrayLiteral->getElement(i)));
  }
  return ret;
}

ObjCAtCatchStmt::ObjCAtCatchStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtCatchStmt)
std::vector<::pasta::Stmt> ObjCAtCatchStmt::Children(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAtCatchStmt::AtCatchToken(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.getAtCatchLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtCatchStmt::BeginToken(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCAtCatchStmt::CatchBody(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.getCatchBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCAtCatchStmt::CatchBody can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl ObjCAtCatchStmt::CatchParamDecl(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.getCatchParamDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "ObjCAtCatchStmt::CatchParamDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCAtCatchStmt::EndToken(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtCatchStmt::RParenToken(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool ObjCAtCatchStmt::HasEllipsis(void) const {
  auto &self = *(u.ObjCAtCatchStmt);
  auto val = self.hasEllipsis();
  return val;
}

ObjCAtFinallyStmt::ObjCAtFinallyStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtFinallyStmt)
std::vector<::pasta::Stmt> ObjCAtFinallyStmt::Children(void) const {
  auto &self = *(u.ObjCAtFinallyStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAtFinallyStmt::AtFinallyToken(void) const {
  auto &self = *(u.ObjCAtFinallyStmt);
  auto val = self.getAtFinallyLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtFinallyStmt::BeginToken(void) const {
  auto &self = *(u.ObjCAtFinallyStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtFinallyStmt::EndToken(void) const {
  auto &self = *(u.ObjCAtFinallyStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCAtFinallyStmt::FinallyBody(void) const {
  auto &self = *(u.ObjCAtFinallyStmt);
  auto val = self.getFinallyBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCAtFinallyStmt::FinallyBody can return nullptr!");
  __builtin_unreachable();
}

ObjCAtSynchronizedStmt::ObjCAtSynchronizedStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtSynchronizedStmt)
std::vector<::pasta::Stmt> ObjCAtSynchronizedStmt::Children(void) const {
  auto &self = *(u.ObjCAtSynchronizedStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAtSynchronizedStmt::AtSynchronizedToken(void) const {
  auto &self = *(u.ObjCAtSynchronizedStmt);
  auto val = self.getAtSynchronizedLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtSynchronizedStmt::BeginToken(void) const {
  auto &self = *(u.ObjCAtSynchronizedStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtSynchronizedStmt::EndToken(void) const {
  auto &self = *(u.ObjCAtSynchronizedStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt ObjCAtSynchronizedStmt::SynchBody(void) const {
  auto &self = *(u.ObjCAtSynchronizedStmt);
  auto val = self.getSynchBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "ObjCAtSynchronizedStmt::SynchBody can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ObjCAtSynchronizedStmt::SynchExpr(void) const {
  auto &self = *(u.ObjCAtSynchronizedStmt);
  auto val = self.getSynchExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCAtSynchronizedStmt::SynchExpr can return nullptr!");
  __builtin_unreachable();
}

ObjCAtThrowStmt::ObjCAtThrowStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtThrowStmt)
std::vector<::pasta::Stmt> ObjCAtThrowStmt::Children(void) const {
  auto &self = *(u.ObjCAtThrowStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAtThrowStmt::BeginToken(void) const {
  auto &self = *(u.ObjCAtThrowStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtThrowStmt::EndToken(void) const {
  auto &self = *(u.ObjCAtThrowStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCAtThrowStmt::ThrowExpr(void) const {
  auto &self = *(u.ObjCAtThrowStmt);
  auto val = self.getThrowExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCAtThrowStmt::ThrowExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCAtThrowStmt::ThrowToken(void) const {
  auto &self = *(u.ObjCAtThrowStmt);
  auto val = self.getThrowLoc();
  return ast->TokenAt(val);
}

ObjCAtTryStmt::ObjCAtTryStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtTryStmt)
std::vector<::pasta::Stmt> ObjCAtTryStmt::Children(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAtTryStmt::AtTryToken(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.getAtTryLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtTryStmt::BeginToken(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: ObjCAtTryStmt::CatchStmt
::pasta::Token ObjCAtTryStmt::EndToken(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCAtFinallyStmt ObjCAtTryStmt::FinallyStmt(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.getFinallyStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::ObjCAtFinallyStmt>(ast, val);
  }
  assert(false && "ObjCAtTryStmt::FinallyStmt can return nullptr!");
  __builtin_unreachable();
}

uint32_t ObjCAtTryStmt::NumCatchStmts(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.getNumCatchStmts();
  return val;
}

::pasta::Stmt ObjCAtTryStmt::TryBody(void) const {
  auto &self = *(u.ObjCAtTryStmt);
  auto val = self.getTryBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCAtTryStmt::TryBody can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::ObjCAtCatchStmt> ObjCAtTryStmt::CatchStmts(void) const {
  auto convert_elem = [&] (const clang::ObjCAtCatchStmt * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::ObjCAtCatchStmt>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ObjCAtCatchStmt> ret;
  auto count = u.ObjCAtTryStmt->getNumCatchStmts();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCAtTryStmt->getCatchStmt(i)));
  }
  return ret;
}

ObjCAutoreleasePoolStmt::ObjCAutoreleasePoolStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAutoreleasePoolStmt)
std::vector<::pasta::Stmt> ObjCAutoreleasePoolStmt::Children(void) const {
  auto &self = *(u.ObjCAutoreleasePoolStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAutoreleasePoolStmt::AtToken(void) const {
  auto &self = *(u.ObjCAutoreleasePoolStmt);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAutoreleasePoolStmt::BeginToken(void) const {
  auto &self = *(u.ObjCAutoreleasePoolStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAutoreleasePoolStmt::EndToken(void) const {
  auto &self = *(u.ObjCAutoreleasePoolStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCAutoreleasePoolStmt::SubStmt(void) const {
  auto &self = *(u.ObjCAutoreleasePoolStmt);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCAutoreleasePoolStmt::SubStmt can return nullptr!");
  __builtin_unreachable();
}

ObjCAvailabilityCheckExpr::ObjCAvailabilityCheckExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCAvailabilityCheckExpr)
std::vector<::pasta::Stmt> ObjCAvailabilityCheckExpr::Children(void) const {
  auto &self = *(u.ObjCAvailabilityCheckExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCAvailabilityCheckExpr::BeginToken(void) const {
  auto &self = *(u.ObjCAvailabilityCheckExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAvailabilityCheckExpr::EndToken(void) const {
  auto &self = *(u.ObjCAvailabilityCheckExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ObjCAvailabilityCheckExpr::TokenRange(void) const {
  auto &self = *(u.ObjCAvailabilityCheckExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ObjCAvailabilityCheckExpr::HasVersion(void) const {
  auto &self = *(u.ObjCAvailabilityCheckExpr);
  auto val = self.hasVersion();
  return val;
}

ObjCBoolLiteralExpr::ObjCBoolLiteralExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCBoolLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCBoolLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCBoolLiteralExpr)
std::vector<::pasta::Stmt> ObjCBoolLiteralExpr::Children(void) const {
  auto &self = *(u.ObjCBoolLiteralExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCBoolLiteralExpr::BeginToken(void) const {
  auto &self = *(u.ObjCBoolLiteralExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBoolLiteralExpr::EndToken(void) const {
  auto &self = *(u.ObjCBoolLiteralExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBoolLiteralExpr::Token(void) const {
  auto &self = *(u.ObjCBoolLiteralExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

bool ObjCBoolLiteralExpr::Value(void) const {
  auto &self = *(u.ObjCBoolLiteralExpr);
  auto val = self.getValue();
  return val;
}

ObjCBoxedExpr::ObjCBoxedExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCBoxedExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCBoxedExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCBoxedExpr)
// 0: ObjCBoxedExpr::
// 0: ObjCBoxedExpr::
std::vector<::pasta::Stmt> ObjCBoxedExpr::Children(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCBoxedExpr::AtToken(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBoxedExpr::BeginToken(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCBoxedExpr::BoxingMethod(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.getBoxingMethod();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCBoxedExpr::BoxingMethod can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCBoxedExpr::EndToken(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ObjCBoxedExpr::TokenRange(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Expr ObjCBoxedExpr::SubExpr(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCBoxedExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

bool ObjCBoxedExpr::IsExpressibleAsConstantInitializer(void) const {
  auto &self = *(u.ObjCBoxedExpr);
  auto val = self.isExpressibleAsConstantInitializer();
  return val;
}

ObjCDictionaryLiteral::ObjCDictionaryLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCDictionaryLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCDictionaryLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCDictionaryLiteral)
std::vector<::pasta::Stmt> ObjCDictionaryLiteral::Children(void) const {
  auto &self = *(u.ObjCDictionaryLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCDictionaryLiteral::BeginToken(void) const {
  auto &self = *(u.ObjCDictionaryLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCDictionaryLiteral::DictWithObjectsMethod(void) const {
  auto &self = *(u.ObjCDictionaryLiteral);
  auto val = self.getDictWithObjectsMethod();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCDictionaryLiteral::DictWithObjectsMethod can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCDictionaryLiteral::EndToken(void) const {
  auto &self = *(u.ObjCDictionaryLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: ObjCDictionaryLiteral::KeyValueElement
uint32_t ObjCDictionaryLiteral::NumElements(void) const {
  auto &self = *(u.ObjCDictionaryLiteral);
  auto val = self.getNumElements();
  return val;
}

::pasta::TokenRange ObjCDictionaryLiteral::TokenRange(void) const {
  auto &self = *(u.ObjCDictionaryLiteral);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

ObjCEncodeExpr::ObjCEncodeExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCEncodeExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCEncodeExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCEncodeExpr)
std::vector<::pasta::Stmt> ObjCEncodeExpr::Children(void) const {
  auto &self = *(u.ObjCEncodeExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCEncodeExpr::AtToken(void) const {
  auto &self = *(u.ObjCEncodeExpr);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCEncodeExpr::BeginToken(void) const {
  auto &self = *(u.ObjCEncodeExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCEncodeExpr::EncodedType(void) const {
  auto &self = *(u.ObjCEncodeExpr);
  auto val = self.getEncodedType();
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCEncodeExpr::EncodedTypeSourceInfo
::pasta::Token ObjCEncodeExpr::EndToken(void) const {
  auto &self = *(u.ObjCEncodeExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCEncodeExpr::RParenToken(void) const {
  auto &self = *(u.ObjCEncodeExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

ObjCForCollectionStmt::ObjCForCollectionStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCForCollectionStmt)
std::vector<::pasta::Stmt> ObjCForCollectionStmt::Children(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCForCollectionStmt::BeginToken(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCForCollectionStmt::Body(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCForCollectionStmt::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ObjCForCollectionStmt::Collection(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getCollection();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCForCollectionStmt::Collection can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt ObjCForCollectionStmt::Element(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getElement();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCForCollectionStmt::Element can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCForCollectionStmt::EndToken(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCForCollectionStmt::ForToken(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getForLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCForCollectionStmt::RParenToken(void) const {
  auto &self = *(u.ObjCForCollectionStmt);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

ObjCIndirectCopyRestoreExpr::ObjCIndirectCopyRestoreExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCIndirectCopyRestoreExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCIndirectCopyRestoreExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCIndirectCopyRestoreExpr)
std::vector<::pasta::Stmt> ObjCIndirectCopyRestoreExpr::Children(void) const {
  auto &self = *(u.ObjCIndirectCopyRestoreExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCIndirectCopyRestoreExpr::BeginToken(void) const {
  auto &self = *(u.ObjCIndirectCopyRestoreExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIndirectCopyRestoreExpr::EndToken(void) const {
  auto &self = *(u.ObjCIndirectCopyRestoreExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIndirectCopyRestoreExpr::ExprToken(void) const {
  auto &self = *(u.ObjCIndirectCopyRestoreExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCIndirectCopyRestoreExpr::SubExpr(void) const {
  auto &self = *(u.ObjCIndirectCopyRestoreExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCIndirectCopyRestoreExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

bool ObjCIndirectCopyRestoreExpr::ShouldCopy(void) const {
  auto &self = *(u.ObjCIndirectCopyRestoreExpr);
  auto val = self.shouldCopy();
  return val;
}

ObjCIsaExpr::ObjCIsaExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCIsaExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCIsaExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCIsaExpr)
std::vector<::pasta::Stmt> ObjCIsaExpr::Children(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr ObjCIsaExpr::Base(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCIsaExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCIsaExpr::BaseLocEnd(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getBaseLocEnd();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::BeginToken(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::EndToken(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::ExprToken(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::IsaMemberToken(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getIsaMemberLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::OpToken(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.getOpLoc();
  return ast->TokenAt(val);
}

bool ObjCIsaExpr::IsArrow(void) const {
  auto &self = *(u.ObjCIsaExpr);
  auto val = self.isArrow();
  return val;
}

ObjCIvarRefExpr::ObjCIvarRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCIvarRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCIvarRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCIvarRefExpr)
std::vector<::pasta::Stmt> ObjCIvarRefExpr::Children(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr ObjCIvarRefExpr::Base(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCIvarRefExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCIvarRefExpr::BeginToken(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCIvarDecl ObjCIvarRefExpr::Decl(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCIvarRefExpr::Decl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCIvarRefExpr::EndToken(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIvarRefExpr::Token(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIvarRefExpr::OpToken(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.getOpLoc();
  return ast->TokenAt(val);
}

bool ObjCIvarRefExpr::IsArrow(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.isArrow();
  return val;
}

bool ObjCIvarRefExpr::IsFreeIvar(void) const {
  auto &self = *(u.ObjCIvarRefExpr);
  auto val = self.isFreeIvar();
  return val;
}

ObjCMessageExpr::ObjCMessageExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCMessageExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCMessageExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCMessageExpr)
// 0: ObjCMessageExpr::
// 0: ObjCMessageExpr::
std::vector<::pasta::Expr> ObjCMessageExpr::Arguments(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Stmt> ObjCMessageExpr::Children(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 1: ObjCMessageExpr::Arg
// 0: ObjCMessageExpr::Args
::pasta::Token ObjCMessageExpr::BeginToken(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCMessageExpr::CallReturnType(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getCallReturnType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ObjCMessageExpr::ClassReceiver(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getClassReceiver();
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCMessageExpr::ClassReceiverTypeInfo
::pasta::Token ObjCMessageExpr::EndToken(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCMessageExpr::InstanceReceiver(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getInstanceReceiver();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCMessageExpr::InstanceReceiver can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMessageExpr::LeftToken(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getLeftLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCMessageExpr::MethodDecl(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCMessageExpr::MethodDecl can return nullptr!");
  __builtin_unreachable();
}

enum ObjCMethodFamily ObjCMessageExpr::MethodFamily(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getMethodFamily();
  return static_cast<::pasta::ObjCMethodFamily>(static_cast<unsigned int>(val));
}

uint32_t ObjCMessageExpr::NumArgs(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getNumArgs();
  return val;
}

uint32_t ObjCMessageExpr::NumSelectorLocs(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getNumSelectorLocs();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCMessageExpr::ReceiverInterface(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getReceiverInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCMessageExpr::ReceiverInterface can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCMessageExpr::ReceiverKind
::pasta::TokenRange ObjCMessageExpr::ReceiverRange(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getReceiverRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type ObjCMessageExpr::ReceiverType(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getReceiverType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token ObjCMessageExpr::RightToken(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getRightLoc();
  return ast->TokenAt(val);
}

// 0: ObjCMessageExpr::Selector
// 1: ObjCMessageExpr::SelectorToken
::pasta::Token ObjCMessageExpr::SelectorStartToken(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getSelectorStartLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCMessageExpr::SuperToken(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getSuperLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCMessageExpr::SuperType(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.getSuperType();
  return TypeBuilder::Build(ast, val);
}

bool ObjCMessageExpr::IsClassMessage(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.isClassMessage();
  return val;
}

bool ObjCMessageExpr::IsDelegateInitCall(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.isDelegateInitCall();
  return val;
}

bool ObjCMessageExpr::IsImplicit(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.isImplicit();
  return val;
}

bool ObjCMessageExpr::IsInstanceMessage(void) const {
  auto &self = *(u.ObjCMessageExpr);
  auto val = self.isInstanceMessage();
  return val;
}

std::vector<::pasta::Token> ObjCMessageExpr::SelectorTokens(void) const {
  auto convert_elem = [&] (clang::SourceLocation val) {
    return ast->TokenAt(val);
  };
  std::vector<::pasta::Token> ret;
  auto count = u.ObjCMessageExpr->getNumSelectorLocs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCMessageExpr->getSelectorLoc(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> ObjCMessageExpr::Args(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.ObjCMessageExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCMessageExpr->getArg(i)));
  }
  return ret;
}

ObjCPropertyRefExpr::ObjCPropertyRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCPropertyRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCPropertyRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCPropertyRefExpr)
std::vector<::pasta::Stmt> ObjCPropertyRefExpr::Children(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr ObjCPropertyRefExpr::Base(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCPropertyRefExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyRefExpr::BeginToken(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCInterfaceDecl ObjCPropertyRefExpr::ClassReceiver(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getClassReceiver();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCPropertyRefExpr::ClassReceiver can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyRefExpr::EndToken(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCPropertyDecl ObjCPropertyRefExpr::ExplicitProperty(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getExplicitProperty();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  assert(false && "ObjCPropertyRefExpr::ExplicitProperty can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyRefExpr::GetterSelector
::pasta::ObjCMethodDecl ObjCPropertyRefExpr::ImplicitPropertyGetter(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getImplicitPropertyGetter();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyRefExpr::ImplicitPropertyGetter can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCPropertyRefExpr::ImplicitPropertySetter(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getImplicitPropertySetter();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyRefExpr::ImplicitPropertySetter can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyRefExpr::Token(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Token ObjCPropertyRefExpr::ReceiverLocation(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getReceiverLocation();
  return ast->TokenAt(val);
}

::pasta::Type ObjCPropertyRefExpr::ReceiverType(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getReceiverType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCPropertyRefExpr::SetterSelector
::pasta::Type ObjCPropertyRefExpr::SuperReceiverType(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.getSuperReceiverType();
  return TypeBuilder::Build(ast, val);
}

bool ObjCPropertyRefExpr::IsClassReceiver(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isClassReceiver();
  return val;
}

bool ObjCPropertyRefExpr::IsExplicitProperty(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isExplicitProperty();
  return val;
}

bool ObjCPropertyRefExpr::IsImplicitProperty(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isImplicitProperty();
  return val;
}

bool ObjCPropertyRefExpr::IsMessagingGetter(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isMessagingGetter();
  return val;
}

bool ObjCPropertyRefExpr::IsMessagingSetter(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isMessagingSetter();
  return val;
}

bool ObjCPropertyRefExpr::IsObjectReceiver(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isObjectReceiver();
  return val;
}

bool ObjCPropertyRefExpr::IsSuperReceiver(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  auto val = self.isSuperReceiver();
  return val;
}

ObjCProtocolExpr::ObjCProtocolExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCProtocolExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCProtocolExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCProtocolExpr)
std::vector<::pasta::Stmt> ObjCProtocolExpr::Children(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCProtocolExpr::AtToken(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCProtocolExpr::BeginToken(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCProtocolExpr::EndToken(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCProtocolDecl ObjCProtocolExpr::Protocol(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.getProtocol();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolExpr::Protocol can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCProtocolExpr::ProtocolIdToken(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.getProtocolIdLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCProtocolExpr::RParenToken(void) const {
  auto &self = *(u.ObjCProtocolExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

ObjCSelectorExpr::ObjCSelectorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCSelectorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCSelectorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCSelectorExpr)
std::vector<::pasta::Stmt> ObjCSelectorExpr::Children(void) const {
  auto &self = *(u.ObjCSelectorExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCSelectorExpr::AtToken(void) const {
  auto &self = *(u.ObjCSelectorExpr);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCSelectorExpr::BeginToken(void) const {
  auto &self = *(u.ObjCSelectorExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCSelectorExpr::EndToken(void) const {
  auto &self = *(u.ObjCSelectorExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCSelectorExpr::NumArgs(void) const {
  auto &self = *(u.ObjCSelectorExpr);
  auto val = self.getNumArgs();
  return val;
}

::pasta::Token ObjCSelectorExpr::RParenToken(void) const {
  auto &self = *(u.ObjCSelectorExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: ObjCSelectorExpr::Selector
ObjCStringLiteral::ObjCStringLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCStringLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCStringLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCStringLiteral)
std::vector<::pasta::Stmt> ObjCStringLiteral::Children(void) const {
  auto &self = *(u.ObjCStringLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ObjCStringLiteral::AtToken(void) const {
  auto &self = *(u.ObjCStringLiteral);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCStringLiteral::BeginToken(void) const {
  auto &self = *(u.ObjCStringLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCStringLiteral::EndToken(void) const {
  auto &self = *(u.ObjCStringLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::StringLiteral ObjCStringLiteral::String(void) const {
  auto &self = *(u.ObjCStringLiteral);
  auto val = self.getString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "ObjCStringLiteral::String can return nullptr!");
  __builtin_unreachable();
}

ObjCSubscriptRefExpr::ObjCSubscriptRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCSubscriptRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCSubscriptRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCSubscriptRefExpr)
std::vector<::pasta::Stmt> ObjCSubscriptRefExpr::Children(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::ObjCMethodDecl ObjCSubscriptRefExpr::AtIndexMethodDecl(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.getAtIndexMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCSubscriptRefExpr::AtIndexMethodDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ObjCSubscriptRefExpr::BaseExpr(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.getBaseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCSubscriptRefExpr::BaseExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCSubscriptRefExpr::BeginToken(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCSubscriptRefExpr::EndToken(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCSubscriptRefExpr::KeyExpr(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.getKeyExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCSubscriptRefExpr::KeyExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCSubscriptRefExpr::RBracket(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.getRBracket();
  return ast->TokenAt(val);
}

bool ObjCSubscriptRefExpr::IsArraySubscriptRefExpr(void) const {
  auto &self = *(u.ObjCSubscriptRefExpr);
  auto val = self.isArraySubscriptRefExpr();
  return val;
}

OffsetOfExpr::OffsetOfExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OffsetOfExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OffsetOfExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OffsetOfExpr)
std::vector<::pasta::Stmt> OffsetOfExpr::Children(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token OffsetOfExpr::BeginToken(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: OffsetOfExpr::Component
::pasta::Token OffsetOfExpr::EndToken(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: OffsetOfExpr::IndexExpr
uint32_t OffsetOfExpr::NumComponents(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.getNumComponents();
  return val;
}

uint32_t OffsetOfExpr::NumExpressions(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.getNumExpressions();
  return val;
}

::pasta::Token OffsetOfExpr::OperatorToken(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Token OffsetOfExpr::RParenToken(void) const {
  auto &self = *(u.OffsetOfExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: OffsetOfExpr::TypeSourceInfo
OpaqueValueExpr::OpaqueValueExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OpaqueValueExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OpaqueValueExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OpaqueValueExpr)
std::vector<::pasta::Stmt> OpaqueValueExpr::Children(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token OpaqueValueExpr::BeginToken(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token OpaqueValueExpr::EndToken(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token OpaqueValueExpr::ExprToken(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token OpaqueValueExpr::Token(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Expr OpaqueValueExpr::SourceExpr(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.getSourceExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OpaqueValueExpr::SourceExpr can return nullptr!");
  __builtin_unreachable();
}

bool OpaqueValueExpr::IsUnique(void) const {
  auto &self = *(u.OpaqueValueExpr);
  auto val = self.isUnique();
  return val;
}

OverloadExpr::OverloadExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OverloadExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OverloadExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OverloadExpr)
PASTA_DEFINE_DERIVED_OPERATORS(OverloadExpr, UnresolvedLookupExpr)
PASTA_DEFINE_DERIVED_OPERATORS(OverloadExpr, UnresolvedMemberExpr)
// 0: OverloadExpr::Declarations
// 0: OverloadExpr::
// 0: OverloadExpr::
::pasta::Token OverloadExpr::LAngleToken(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

// 0: OverloadExpr::Name
// 0: OverloadExpr::NameInfo
::pasta::Token OverloadExpr::NameToken(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getNameLoc();
  return ast->TokenAt(val);
}

::pasta::CXXRecordDecl OverloadExpr::NamingClass(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getNamingClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "OverloadExpr::NamingClass can return nullptr!");
  __builtin_unreachable();
}

uint32_t OverloadExpr::NumDecls(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getNumDecls();
  return val;
}

uint32_t OverloadExpr::NumTemplateArgs(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getNumTemplateArgs();
  return val;
}

// 0: OverloadExpr::Qualifier
// 0: OverloadExpr::QualifierToken
::pasta::Token OverloadExpr::RAngleToken(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: OverloadExpr::TemplateArgs
::pasta::Token OverloadExpr::TemplateKeywordToken(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool OverloadExpr::HasExplicitTemplateArgs(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.hasExplicitTemplateArgs();
  return val;
}

bool OverloadExpr::HasTemplateKeyword(void) const {
  auto &self = *(u.OverloadExpr);
  auto val = self.hasTemplateKeyword();
  return val;
}

// 0: OverloadExpr::Template_arguments
PackExpansionExpr::PackExpansionExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, PackExpansionExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, PackExpansionExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, PackExpansionExpr)
std::vector<::pasta::Stmt> PackExpansionExpr::Children(void) const {
  auto &self = *(u.PackExpansionExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token PackExpansionExpr::BeginToken(void) const {
  auto &self = *(u.PackExpansionExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token PackExpansionExpr::EllipsisToken(void) const {
  auto &self = *(u.PackExpansionExpr);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::Token PackExpansionExpr::EndToken(void) const {
  auto &self = *(u.PackExpansionExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<unsigned> PackExpansionExpr::NumExpansions(void) const {
  auto &self = *(u.PackExpansionExpr);
  auto val = self.getNumExpansions();
  if (val.hasValue()) {
    return val.getValue();
  } else {
    return std::nullopt;
  }
}

::pasta::Expr PackExpansionExpr::Pattern(void) const {
  auto &self = *(u.PackExpansionExpr);
  auto val = self.getPattern();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "PackExpansionExpr::Pattern can return nullptr!");
  __builtin_unreachable();
}

ParenExpr::ParenExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ParenExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ParenExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ParenExpr)
std::vector<::pasta::Stmt> ParenExpr::Children(void) const {
  auto &self = *(u.ParenExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ParenExpr::BeginToken(void) const {
  auto &self = *(u.ParenExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ParenExpr::EndToken(void) const {
  auto &self = *(u.ParenExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ParenExpr::LParen(void) const {
  auto &self = *(u.ParenExpr);
  auto val = self.getLParen();
  return ast->TokenAt(val);
}

::pasta::Token ParenExpr::RParen(void) const {
  auto &self = *(u.ParenExpr);
  auto val = self.getRParen();
  return ast->TokenAt(val);
}

::pasta::Expr ParenExpr::SubExpr(void) const {
  auto &self = *(u.ParenExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ParenExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

ParenListExpr::ParenListExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ParenListExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ParenListExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ParenListExpr)
std::vector<::pasta::Stmt> ParenListExpr::Children(void) const {
  auto &self = *(u.ParenListExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ParenListExpr::BeginToken(void) const {
  auto &self = *(u.ParenListExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ParenListExpr::EndToken(void) const {
  auto &self = *(u.ParenListExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: ParenListExpr::FindExpr
::pasta::Token ParenListExpr::LParenToken(void) const {
  auto &self = *(u.ParenListExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

uint32_t ParenListExpr::NumExprs(void) const {
  auto &self = *(u.ParenListExpr);
  auto val = self.getNumExprs();
  return val;
}

::pasta::Token ParenListExpr::RParenToken(void) const {
  auto &self = *(u.ParenListExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::Expr> ParenListExpr::FindExprs(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.ParenListExpr->getNumExprs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ParenListExpr->getExpr(i)));
  }
  return ret;
}

PredefinedExpr::PredefinedExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, PredefinedExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, PredefinedExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, PredefinedExpr)
std::vector<::pasta::Stmt> PredefinedExpr::Children(void) const {
  auto &self = *(u.PredefinedExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token PredefinedExpr::BeginToken(void) const {
  auto &self = *(u.PredefinedExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token PredefinedExpr::EndToken(void) const {
  auto &self = *(u.PredefinedExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::StringLiteral PredefinedExpr::FunctionName(void) const {
  auto &self = *(u.PredefinedExpr);
  auto val = self.getFunctionName();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "PredefinedExpr::FunctionName can return nullptr!");
  __builtin_unreachable();
}

// 0: PredefinedExpr::IdentKind
std::string_view PredefinedExpr::IdentKindName(void) const {
  auto &self = *(u.PredefinedExpr);
  auto val = self.getIdentKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token PredefinedExpr::Token(void) const {
  auto &self = *(u.PredefinedExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

PseudoObjectExpr::PseudoObjectExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, PseudoObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, PseudoObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, PseudoObjectExpr)
std::vector<::pasta::Stmt> PseudoObjectExpr::Children(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token PseudoObjectExpr::BeginToken(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token PseudoObjectExpr::EndToken(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token PseudoObjectExpr::ExprToken(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

uint32_t PseudoObjectExpr::NumSemanticExprs(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getNumSemanticExprs();
  return val;
}

::pasta::Expr PseudoObjectExpr::ResultExpr(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getResultExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "PseudoObjectExpr::ResultExpr can return nullptr!");
  __builtin_unreachable();
}

uint32_t PseudoObjectExpr::ResultExprIndex(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getResultExprIndex();
  return val;
}

// 1: PseudoObjectExpr::SemanticExpr
::pasta::Expr PseudoObjectExpr::SyntacticForm(void) const {
  auto &self = *(u.PseudoObjectExpr);
  auto val = self.getSyntacticForm();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "PseudoObjectExpr::SyntacticForm can return nullptr!");
  __builtin_unreachable();
}

// 0: PseudoObjectExpr::Semantics
// 0: PseudoObjectExpr::
// 0: PseudoObjectExpr::
std::vector<::pasta::Expr> PseudoObjectExpr::SemanticExprs(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.PseudoObjectExpr->getNumSemanticExprs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.PseudoObjectExpr->getSemanticExpr(i)));
  }
  return ret;
}

RecoveryExpr::RecoveryExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, RecoveryExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, RecoveryExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, RecoveryExpr)
::pasta::Token RecoveryExpr::BeginToken(void) const {
  auto &self = *(u.RecoveryExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token RecoveryExpr::EndToken(void) const {
  auto &self = *(u.RecoveryExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::Expr> RecoveryExpr::SubExpressions(void) const {
  auto &self = *(u.RecoveryExpr);
  auto val = self.subExpressions();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

RequiresExpr::RequiresExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, RequiresExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, RequiresExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, RequiresExpr)
std::vector<::pasta::Stmt> RequiresExpr::Children(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token RequiresExpr::BeginToken(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::RequiresExprBodyDecl RequiresExpr::Body(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.getBody();
  if (val) {
    return DeclBuilder::Create<::pasta::RequiresExprBodyDecl>(ast, val);
  }
  assert(false && "RequiresExpr::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token RequiresExpr::EndToken(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::ParmVarDecl> RequiresExpr::LocalParameters(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.getLocalParameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::Token RequiresExpr::RBraceToken(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

// 0: RequiresExpr::Requirements
::pasta::Token RequiresExpr::RequiresKWToken(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.getRequiresKWLoc();
  return ast->TokenAt(val);
}

bool RequiresExpr::IsSatisfied(void) const {
  auto &self = *(u.RequiresExpr);
  auto val = self.isSatisfied();
  return val;
}

ReturnStmt::ReturnStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ReturnStmt)
std::vector<::pasta::Stmt> ReturnStmt::Children(void) const {
  auto &self = *(u.ReturnStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ReturnStmt::BeginToken(void) const {
  auto &self = *(u.ReturnStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ReturnStmt::EndToken(void) const {
  auto &self = *(u.ReturnStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::VarDecl ReturnStmt::NRVOCandidate(void) const {
  auto &self = *(u.ReturnStmt);
  auto val = self.getNRVOCandidate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "ReturnStmt::NRVOCandidate can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ReturnStmt::RetValue(void) const {
  auto &self = *(u.ReturnStmt);
  auto val = self.getRetValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ReturnStmt::RetValue can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ReturnStmt::ReturnToken(void) const {
  auto &self = *(u.ReturnStmt);
  auto val = self.getReturnLoc();
  return ast->TokenAt(val);
}

SEHExceptStmt::SEHExceptStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHExceptStmt)
std::vector<::pasta::Stmt> SEHExceptStmt::Children(void) const {
  auto &self = *(u.SEHExceptStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SEHExceptStmt::BeginToken(void) const {
  auto &self = *(u.SEHExceptStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt SEHExceptStmt::Block(void) const {
  auto &self = *(u.SEHExceptStmt);
  auto val = self.getBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "SEHExceptStmt::Block can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SEHExceptStmt::EndToken(void) const {
  auto &self = *(u.SEHExceptStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHExceptStmt::ExceptToken(void) const {
  auto &self = *(u.SEHExceptStmt);
  auto val = self.getExceptLoc();
  return ast->TokenAt(val);
}

::pasta::Expr SEHExceptStmt::FilterExpr(void) const {
  auto &self = *(u.SEHExceptStmt);
  auto val = self.getFilterExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "SEHExceptStmt::FilterExpr can return nullptr!");
  __builtin_unreachable();
}

SEHFinallyStmt::SEHFinallyStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHFinallyStmt)
std::vector<::pasta::Stmt> SEHFinallyStmt::Children(void) const {
  auto &self = *(u.SEHFinallyStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SEHFinallyStmt::BeginToken(void) const {
  auto &self = *(u.SEHFinallyStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt SEHFinallyStmt::Block(void) const {
  auto &self = *(u.SEHFinallyStmt);
  auto val = self.getBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "SEHFinallyStmt::Block can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SEHFinallyStmt::EndToken(void) const {
  auto &self = *(u.SEHFinallyStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHFinallyStmt::FinallyToken(void) const {
  auto &self = *(u.SEHFinallyStmt);
  auto val = self.getFinallyLoc();
  return ast->TokenAt(val);
}

SEHLeaveStmt::SEHLeaveStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHLeaveStmt)
std::vector<::pasta::Stmt> SEHLeaveStmt::Children(void) const {
  auto &self = *(u.SEHLeaveStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SEHLeaveStmt::BeginToken(void) const {
  auto &self = *(u.SEHLeaveStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHLeaveStmt::EndToken(void) const {
  auto &self = *(u.SEHLeaveStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHLeaveStmt::LeaveToken(void) const {
  auto &self = *(u.SEHLeaveStmt);
  auto val = self.getLeaveLoc();
  return ast->TokenAt(val);
}

SEHTryStmt::SEHTryStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHTryStmt)
std::vector<::pasta::Stmt> SEHTryStmt::Children(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SEHTryStmt::BeginToken(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHTryStmt::EndToken(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::SEHExceptStmt SEHTryStmt::ExceptHandler(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getExceptHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::SEHExceptStmt>(ast, val);
  }
  assert(false && "SEHTryStmt::ExceptHandler can return nullptr!");
  __builtin_unreachable();
}

::pasta::SEHFinallyStmt SEHTryStmt::FinallyHandler(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getFinallyHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::SEHFinallyStmt>(ast, val);
  }
  assert(false && "SEHTryStmt::FinallyHandler can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt SEHTryStmt::Handler(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "SEHTryStmt::Handler can return nullptr!");
  __builtin_unreachable();
}

bool SEHTryStmt::IsCXXTry(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getIsCXXTry();
  return val;
}

::pasta::CompoundStmt SEHTryStmt::TryBlock(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getTryBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "SEHTryStmt::TryBlock can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SEHTryStmt::TryToken(void) const {
  auto &self = *(u.SEHTryStmt);
  auto val = self.getTryLoc();
  return ast->TokenAt(val);
}

ShuffleVectorExpr::ShuffleVectorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ShuffleVectorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ShuffleVectorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ShuffleVectorExpr)
std::vector<::pasta::Stmt> ShuffleVectorExpr::Children(void) const {
  auto &self = *(u.ShuffleVectorExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ShuffleVectorExpr::BeginToken(void) const {
  auto &self = *(u.ShuffleVectorExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ShuffleVectorExpr::BuiltinToken(void) const {
  auto &self = *(u.ShuffleVectorExpr);
  auto val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token ShuffleVectorExpr::EndToken(void) const {
  auto &self = *(u.ShuffleVectorExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: ShuffleVectorExpr::FindExpr
uint32_t ShuffleVectorExpr::NumSubExprs(void) const {
  auto &self = *(u.ShuffleVectorExpr);
  auto val = self.getNumSubExprs();
  return val;
}

::pasta::Token ShuffleVectorExpr::RParenToken(void) const {
  auto &self = *(u.ShuffleVectorExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 2: ShuffleMaskIdx
SizeOfPackExpr::SizeOfPackExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, SizeOfPackExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, SizeOfPackExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, SizeOfPackExpr)
std::vector<::pasta::Stmt> SizeOfPackExpr::Children(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SizeOfPackExpr::BeginToken(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SizeOfPackExpr::EndToken(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SizeOfPackExpr::OperatorToken(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl SizeOfPackExpr::Pack(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getPack();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "SizeOfPackExpr::Pack can return nullptr!");
  __builtin_unreachable();
}

uint32_t SizeOfPackExpr::PackLength(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getPackLength();
  return val;
}

::pasta::Token SizeOfPackExpr::PackToken(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getPackLoc();
  return ast->TokenAt(val);
}

// 0: SizeOfPackExpr::PartialArguments
::pasta::Token SizeOfPackExpr::RParenToken(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool SizeOfPackExpr::IsPartiallySubstituted(void) const {
  auto &self = *(u.SizeOfPackExpr);
  auto val = self.isPartiallySubstituted();
  return val;
}

SourceLocExpr::SourceLocExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, SourceLocExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, SourceLocExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, SourceLocExpr)
// 2: EvaluateInContext
std::vector<::pasta::Stmt> SourceLocExpr::Children(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SourceLocExpr::BeginToken(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::string_view SourceLocExpr::BuiltinStr(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.getBuiltinStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token SourceLocExpr::EndToken(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: SourceLocExpr::IdentKind
::pasta::Token SourceLocExpr::Token(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::DeclContext SourceLocExpr::ParentContext(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.getParentContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "SourceLocExpr::ParentContext can return nullptr!");
  __builtin_unreachable();
}

bool SourceLocExpr::IsIntType(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.isIntType();
  return val;
}

bool SourceLocExpr::IsStringType(void) const {
  auto &self = *(u.SourceLocExpr);
  auto val = self.isStringType();
  return val;
}

StmtExpr::StmtExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, StmtExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, StmtExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, StmtExpr)
std::vector<::pasta::Stmt> StmtExpr::Children(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token StmtExpr::BeginToken(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token StmtExpr::EndToken(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token StmtExpr::LParenToken(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token StmtExpr::RParenToken(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt StmtExpr::SubStmt(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "StmtExpr::SubStmt can return nullptr!");
  __builtin_unreachable();
}

uint32_t StmtExpr::TemplateDepth(void) const {
  auto &self = *(u.StmtExpr);
  auto val = self.getTemplateDepth();
  return val;
}

StringLiteral::StringLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, StringLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, StringLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, StringLiteral)
std::vector<::pasta::Stmt> StringLiteral::Children(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

bool StringLiteral::ContainsNonAscii(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.containsNonAscii();
  return val;
}

bool StringLiteral::ContainsNonAsciiOrNull(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.containsNonAsciiOrNull();
  return val;
}

::pasta::Token StringLiteral::BeginToken(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

uint32_t StringLiteral::ByteLength(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getByteLength();
  return val;
}

std::string_view StringLiteral::Bytes(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getBytes();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

uint32_t StringLiteral::CharByteWidth(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getCharByteWidth();
  return val;
}

// 1: StringLiteral::CodeUnit
::pasta::Token StringLiteral::EndToken(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: StringLiteral::
uint32_t StringLiteral::Length(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getLength();
  return val;
}

// 4: StringLiteral::LocationOfByte
uint32_t StringLiteral::NumConcatenated(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getNumConcatenated();
  return val;
}

// 1: StringLiteral::StrTokenToken
std::string_view StringLiteral::String(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.getString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

bool StringLiteral::IsAscii(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.isAscii();
  return val;
}

bool StringLiteral::IsPascal(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.isPascal();
  return val;
}

bool StringLiteral::IsUTF16(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.isUTF16();
  return val;
}

bool StringLiteral::IsUTF32(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.isUTF32();
  return val;
}

bool StringLiteral::IsUTF8(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.isUTF8();
  return val;
}

bool StringLiteral::IsWide(void) const {
  auto &self = *(u.StringLiteral);
  auto val = self.isWide();
  return val;
}

// 0: StringLiteral::
// 0: StringLiteral::
SubstNonTypeTemplateParmExpr::SubstNonTypeTemplateParmExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, SubstNonTypeTemplateParmExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, SubstNonTypeTemplateParmExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, SubstNonTypeTemplateParmExpr)
std::vector<::pasta::Stmt> SubstNonTypeTemplateParmExpr::Children(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token SubstNonTypeTemplateParmExpr::BeginToken(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SubstNonTypeTemplateParmExpr::EndToken(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SubstNonTypeTemplateParmExpr::NameToken(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.getNameLoc();
  return ast->TokenAt(val);
}

::pasta::NonTypeTemplateParmDecl SubstNonTypeTemplateParmExpr::Parameter(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.getParameter();
  if (val) {
    return DeclBuilder::Create<::pasta::NonTypeTemplateParmDecl>(ast, val);
  }
  assert(false && "SubstNonTypeTemplateParmExpr::Parameter can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type SubstNonTypeTemplateParmExpr::ParameterType(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.getParameterType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr SubstNonTypeTemplateParmExpr::Replacement(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.getReplacement();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "SubstNonTypeTemplateParmExpr::Replacement can return nullptr!");
  __builtin_unreachable();
}

bool SubstNonTypeTemplateParmExpr::IsReferenceParameter(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  auto val = self.isReferenceParameter();
  return val;
}

SubstNonTypeTemplateParmPackExpr::SubstNonTypeTemplateParmPackExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, SubstNonTypeTemplateParmPackExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, SubstNonTypeTemplateParmPackExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, SubstNonTypeTemplateParmPackExpr)
std::vector<::pasta::Stmt> SubstNonTypeTemplateParmPackExpr::Children(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmPackExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: SubstNonTypeTemplateParmPackExpr::ArgumentPack
::pasta::Token SubstNonTypeTemplateParmPackExpr::BeginToken(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmPackExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SubstNonTypeTemplateParmPackExpr::EndToken(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmPackExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::NonTypeTemplateParmDecl SubstNonTypeTemplateParmPackExpr::ParameterPack(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmPackExpr);
  auto val = self.getParameterPack();
  if (val) {
    return DeclBuilder::Create<::pasta::NonTypeTemplateParmDecl>(ast, val);
  }
  assert(false && "SubstNonTypeTemplateParmPackExpr::ParameterPack can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token SubstNonTypeTemplateParmPackExpr::ParameterPackLocation(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmPackExpr);
  auto val = self.getParameterPackLocation();
  return ast->TokenAt(val);
}

TypeTraitExpr::TypeTraitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, TypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, TypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, TypeTraitExpr)
std::vector<::pasta::Stmt> TypeTraitExpr::Children(void) const {
  auto &self = *(u.TypeTraitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 1: TypeTraitExpr::Arg
// 0: TypeTraitExpr::Args
::pasta::Token TypeTraitExpr::BeginToken(void) const {
  auto &self = *(u.TypeTraitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token TypeTraitExpr::EndToken(void) const {
  auto &self = *(u.TypeTraitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t TypeTraitExpr::NumArgs(void) const {
  auto &self = *(u.TypeTraitExpr);
  auto val = self.getNumArgs();
  return val;
}

enum TypeTrait TypeTraitExpr::Trait(void) const {
  auto &self = *(u.TypeTraitExpr);
  auto val = self.getTrait();
  return static_cast<::pasta::TypeTrait>(static_cast<unsigned int>(val));
}

bool TypeTraitExpr::Value(void) const {
  auto &self = *(u.TypeTraitExpr);
  auto val = self.getValue();
  return val;
}

TypoExpr::TypoExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, TypoExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, TypoExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, TypoExpr)
std::vector<::pasta::Stmt> TypoExpr::Children(void) const {
  auto &self = *(u.TypoExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token TypoExpr::BeginToken(void) const {
  auto &self = *(u.TypoExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token TypoExpr::EndToken(void) const {
  auto &self = *(u.TypoExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

UnaryExprOrTypeTraitExpr::UnaryExprOrTypeTraitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, UnaryExprOrTypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, UnaryExprOrTypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, UnaryExprOrTypeTraitExpr)
std::vector<::pasta::Stmt> UnaryExprOrTypeTraitExpr::Children(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr UnaryExprOrTypeTraitExpr::ArgumentExpr(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getArgumentExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "UnaryExprOrTypeTraitExpr::ArgumentExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type UnaryExprOrTypeTraitExpr::ArgumentType(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getArgumentType();
  return TypeBuilder::Build(ast, val);
}

// 0: UnaryExprOrTypeTraitExpr::ArgumentTypeInfo
::pasta::Token UnaryExprOrTypeTraitExpr::BeginToken(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryExprOrTypeTraitExpr::EndToken(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: UnaryExprOrTypeTraitExpr::
::pasta::Token UnaryExprOrTypeTraitExpr::OperatorToken(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryExprOrTypeTraitExpr::RParenToken(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Type UnaryExprOrTypeTraitExpr::TypeOfArgument(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.getTypeOfArgument();
  return TypeBuilder::Build(ast, val);
}

bool UnaryExprOrTypeTraitExpr::IsArgumentType(void) const {
  auto &self = *(u.UnaryExprOrTypeTraitExpr);
  auto val = self.isArgumentType();
  return val;
}

UnaryOperator::UnaryOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, UnaryOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, UnaryOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, UnaryOperator)
bool UnaryOperator::CanOverflow(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.canOverflow();
  return val;
}

std::vector<::pasta::Stmt> UnaryOperator::Children(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token UnaryOperator::BeginToken(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryOperator::EndToken(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryOperator::ExprToken(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 1: UnaryOperator::FPFeaturesInEffect
// 0: UnaryOperator::FPOptionsOverride
enum UnaryOperatorKind UnaryOperator::Opcode(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.getOpcode();
  return static_cast<::pasta::UnaryOperatorKind>(static_cast<unsigned int>(val));
}

::pasta::Token UnaryOperator::OperatorToken(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: UnaryOperator::StoredFPFeatures
::pasta::Expr UnaryOperator::SubExpr(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "UnaryOperator::SubExpr can return nullptr!");
  __builtin_unreachable();
}

bool UnaryOperator::HasStoredFPFeatures(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.hasStoredFPFeatures();
  return val;
}

bool UnaryOperator::IsArithmeticOp(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.isArithmeticOp();
  return val;
}

bool UnaryOperator::IsDecrementOp(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.isDecrementOp();
  return val;
}

// 1: UnaryOperator::IsFEnvAccessOn
// 1: UnaryOperator::IsFPContractableWithinStatement
bool UnaryOperator::IsIncrementDecrementOp(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.isIncrementDecrementOp();
  return val;
}

bool UnaryOperator::IsIncrementOp(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.isIncrementOp();
  return val;
}

bool UnaryOperator::IsPostfix(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.isPostfix();
  return val;
}

bool UnaryOperator::IsPrefix(void) const {
  auto &self = *(u.UnaryOperator);
  auto val = self.isPrefix();
  return val;
}

UnresolvedLookupExpr::UnresolvedLookupExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OverloadExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, UnresolvedLookupExpr)
PASTA_DEFINE_BASE_OPERATORS(OverloadExpr, UnresolvedLookupExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, UnresolvedLookupExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, UnresolvedLookupExpr)
std::vector<::pasta::Stmt> UnresolvedLookupExpr::Children(void) const {
  auto &self = *(u.UnresolvedLookupExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token UnresolvedLookupExpr::BeginToken(void) const {
  auto &self = *(u.UnresolvedLookupExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedLookupExpr::EndToken(void) const {
  auto &self = *(u.UnresolvedLookupExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::CXXRecordDecl UnresolvedLookupExpr::NamingClass(void) const {
  auto &self = *(u.UnresolvedLookupExpr);
  auto val = self.getNamingClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "UnresolvedLookupExpr::NamingClass can return nullptr!");
  __builtin_unreachable();
}

bool UnresolvedLookupExpr::IsOverloaded(void) const {
  auto &self = *(u.UnresolvedLookupExpr);
  auto val = self.isOverloaded();
  return val;
}

bool UnresolvedLookupExpr::RequiresADL(void) const {
  auto &self = *(u.UnresolvedLookupExpr);
  auto val = self.requiresADL();
  return val;
}

UnresolvedMemberExpr::UnresolvedMemberExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OverloadExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, UnresolvedMemberExpr)
PASTA_DEFINE_BASE_OPERATORS(OverloadExpr, UnresolvedMemberExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, UnresolvedMemberExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, UnresolvedMemberExpr)
std::vector<::pasta::Stmt> UnresolvedMemberExpr::Children(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr UnresolvedMemberExpr::Base(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "UnresolvedMemberExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type UnresolvedMemberExpr::BaseType(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getBaseType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token UnresolvedMemberExpr::BeginToken(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedMemberExpr::EndToken(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedMemberExpr::ExprToken(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedMemberExpr::MemberToken(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getMemberLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedMemberExpr::MemberName
// 0: UnresolvedMemberExpr::MemberNameInfo
::pasta::CXXRecordDecl UnresolvedMemberExpr::NamingClass(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getNamingClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "UnresolvedMemberExpr::NamingClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedMemberExpr::OperatorToken(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

bool UnresolvedMemberExpr::HasUnresolvedUsing(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.hasUnresolvedUsing();
  return val;
}

bool UnresolvedMemberExpr::IsArrow(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.isArrow();
  return val;
}

bool UnresolvedMemberExpr::IsImplicitAccess(void) const {
  auto &self = *(u.UnresolvedMemberExpr);
  auto val = self.isImplicitAccess();
  return val;
}

VAArgExpr::VAArgExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, VAArgExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, VAArgExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, VAArgExpr)
std::vector<::pasta::Stmt> VAArgExpr::Children(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token VAArgExpr::BeginToken(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token VAArgExpr::BuiltinToken(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token VAArgExpr::EndToken(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token VAArgExpr::RParenToken(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr VAArgExpr::SubExpr(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "VAArgExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

// 0: VAArgExpr::WrittenTypeInfo
bool VAArgExpr::IsMicrosoftABI(void) const {
  auto &self = *(u.VAArgExpr);
  auto val = self.isMicrosoftABI();
  return val;
}

AbstractConditionalOperator::AbstractConditionalOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, AbstractConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, AbstractConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AbstractConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(AbstractConditionalOperator, BinaryConditionalOperator)
PASTA_DEFINE_DERIVED_OPERATORS(AbstractConditionalOperator, ConditionalOperator)
::pasta::Token AbstractConditionalOperator::ColonToken(void) const {
  auto &self = *(u.AbstractConditionalOperator);
  auto val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AbstractConditionalOperator::Cond(void) const {
  auto &self = *(u.AbstractConditionalOperator);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AbstractConditionalOperator::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AbstractConditionalOperator::FalseExpr(void) const {
  auto &self = *(u.AbstractConditionalOperator);
  auto val = self.getFalseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AbstractConditionalOperator::FalseExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token AbstractConditionalOperator::QuestionToken(void) const {
  auto &self = *(u.AbstractConditionalOperator);
  auto val = self.getQuestionLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AbstractConditionalOperator::TrueExpr(void) const {
  auto &self = *(u.AbstractConditionalOperator);
  auto val = self.getTrueExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AbstractConditionalOperator::TrueExpr can return nullptr!");
  __builtin_unreachable();
}

AddrLabelExpr::AddrLabelExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, AddrLabelExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, AddrLabelExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AddrLabelExpr)
std::vector<::pasta::Stmt> AddrLabelExpr::Children(void) const {
  auto &self = *(u.AddrLabelExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token AddrLabelExpr::AmpAmpToken(void) const {
  auto &self = *(u.AddrLabelExpr);
  auto val = self.getAmpAmpLoc();
  return ast->TokenAt(val);
}

::pasta::Token AddrLabelExpr::BeginToken(void) const {
  auto &self = *(u.AddrLabelExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AddrLabelExpr::EndToken(void) const {
  auto &self = *(u.AddrLabelExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl AddrLabelExpr::Label(void) const {
  auto &self = *(u.AddrLabelExpr);
  auto val = self.getLabel();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  assert(false && "AddrLabelExpr::Label can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token AddrLabelExpr::LabelToken(void) const {
  auto &self = *(u.AddrLabelExpr);
  auto val = self.getLabelLoc();
  return ast->TokenAt(val);
}

ArrayInitIndexExpr::ArrayInitIndexExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ArrayInitIndexExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ArrayInitIndexExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ArrayInitIndexExpr)
std::vector<::pasta::Stmt> ArrayInitIndexExpr::Children(void) const {
  auto &self = *(u.ArrayInitIndexExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ArrayInitIndexExpr::BeginToken(void) const {
  auto &self = *(u.ArrayInitIndexExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ArrayInitIndexExpr::EndToken(void) const {
  auto &self = *(u.ArrayInitIndexExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

ArrayInitLoopExpr::ArrayInitLoopExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ArrayInitLoopExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ArrayInitLoopExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ArrayInitLoopExpr)
std::vector<::pasta::Stmt> ArrayInitLoopExpr::Children(void) const {
  auto &self = *(u.ArrayInitLoopExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: ArrayInitLoopExpr::ArraySize
::pasta::Token ArrayInitLoopExpr::BeginToken(void) const {
  auto &self = *(u.ArrayInitLoopExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::OpaqueValueExpr ArrayInitLoopExpr::CommonExpr(void) const {
  auto &self = *(u.ArrayInitLoopExpr);
  auto val = self.getCommonExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::OpaqueValueExpr>(ast, val);
  }
  assert(false && "ArrayInitLoopExpr::CommonExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ArrayInitLoopExpr::EndToken(void) const {
  auto &self = *(u.ArrayInitLoopExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArrayInitLoopExpr::SubExpr(void) const {
  auto &self = *(u.ArrayInitLoopExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ArrayInitLoopExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

ArraySubscriptExpr::ArraySubscriptExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ArraySubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ArraySubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ArraySubscriptExpr)
std::vector<::pasta::Stmt> ArraySubscriptExpr::Children(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr ArraySubscriptExpr::Base(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ArraySubscriptExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ArraySubscriptExpr::BeginToken(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ArraySubscriptExpr::EndToken(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ArraySubscriptExpr::ExprToken(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArraySubscriptExpr::Idx(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ArraySubscriptExpr::Idx can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ArraySubscriptExpr::LHS(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ArraySubscriptExpr::LHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ArraySubscriptExpr::RBracketToken(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArraySubscriptExpr::RHS(void) const {
  auto &self = *(u.ArraySubscriptExpr);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ArraySubscriptExpr::RHS can return nullptr!");
  __builtin_unreachable();
}

ArrayTypeTraitExpr::ArrayTypeTraitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ArrayTypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ArrayTypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ArrayTypeTraitExpr)
std::vector<::pasta::Stmt> ArrayTypeTraitExpr::Children(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ArrayTypeTraitExpr::BeginToken(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArrayTypeTraitExpr::DimensionExpression(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.getDimensionExpression();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ArrayTypeTraitExpr::DimensionExpression can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ArrayTypeTraitExpr::EndToken(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Type ArrayTypeTraitExpr::QueriedType(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.getQueriedType();
  return TypeBuilder::Build(ast, val);
}

// 0: ArrayTypeTraitExpr::QueriedTypeSourceInfo
enum ArrayTypeTrait ArrayTypeTraitExpr::Trait(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.getTrait();
  return static_cast<::pasta::ArrayTypeTrait>(static_cast<unsigned int>(val));
}

uint64_t ArrayTypeTraitExpr::Value(void) const {
  auto &self = *(u.ArrayTypeTraitExpr);
  auto val = self.getValue();
  return val;
}

AsTypeExpr::AsTypeExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, AsTypeExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, AsTypeExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AsTypeExpr)
std::vector<::pasta::Stmt> AsTypeExpr::Children(void) const {
  auto &self = *(u.AsTypeExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token AsTypeExpr::BeginToken(void) const {
  auto &self = *(u.AsTypeExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsTypeExpr::BuiltinToken(void) const {
  auto &self = *(u.AsTypeExpr);
  auto val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsTypeExpr::EndToken(void) const {
  auto &self = *(u.AsTypeExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsTypeExpr::RParenToken(void) const {
  auto &self = *(u.AsTypeExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AsTypeExpr::SrcExpr(void) const {
  auto &self = *(u.AsTypeExpr);
  auto val = self.getSrcExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AsTypeExpr::SrcExpr can return nullptr!");
  __builtin_unreachable();
}

AtomicExpr::AtomicExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, AtomicExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, AtomicExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AtomicExpr)
std::vector<::pasta::Stmt> AtomicExpr::Children(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token AtomicExpr::BeginToken(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AtomicExpr::BuiltinToken(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token AtomicExpr::EndToken(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t AtomicExpr::NumSubExprs(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getNumSubExprs();
  return val;
}

// 0: AtomicExpr::Op
::pasta::Expr AtomicExpr::Order(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getOrder();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::Order can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AtomicExpr::OrderFail(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getOrderFail();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::OrderFail can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AtomicExpr::Ptr(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getPtr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::Ptr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token AtomicExpr::RParenToken(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AtomicExpr::Scope(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getScope();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::Scope can return nullptr!");
  __builtin_unreachable();
}

// 0: AtomicExpr::ScopeModel
// 0: AtomicExpr::SubExprs
::pasta::Expr AtomicExpr::Val1(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getVal1();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::Val1 can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr AtomicExpr::Val2(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getVal2();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::Val2 can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type AtomicExpr::ValueType(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getValueType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr AtomicExpr::Weak(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.getWeak();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "AtomicExpr::Weak can return nullptr!");
  __builtin_unreachable();
}

bool AtomicExpr::IsCmpXChg(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.isCmpXChg();
  return val;
}

bool AtomicExpr::IsOpenCL(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.isOpenCL();
  return val;
}

bool AtomicExpr::IsVolatile(void) const {
  auto &self = *(u.AtomicExpr);
  auto val = self.isVolatile();
  return val;
}

BinaryConditionalOperator::BinaryConditionalOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : AbstractConditionalOperator(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(AbstractConditionalOperator, BinaryConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(Expr, BinaryConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, BinaryConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, BinaryConditionalOperator)
std::vector<::pasta::Stmt> BinaryConditionalOperator::Children(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token BinaryConditionalOperator::BeginToken(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr BinaryConditionalOperator::Common(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getCommon();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BinaryConditionalOperator::Common can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr BinaryConditionalOperator::Cond(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BinaryConditionalOperator::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token BinaryConditionalOperator::EndToken(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr BinaryConditionalOperator::FalseExpr(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getFalseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BinaryConditionalOperator::FalseExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::OpaqueValueExpr BinaryConditionalOperator::OpaqueValue(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getOpaqueValue();
  if (val) {
    return StmtBuilder::Create<::pasta::OpaqueValueExpr>(ast, val);
  }
  assert(false && "BinaryConditionalOperator::OpaqueValue can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr BinaryConditionalOperator::TrueExpr(void) const {
  auto &self = *(u.BinaryConditionalOperator);
  auto val = self.getTrueExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BinaryConditionalOperator::TrueExpr can return nullptr!");
  __builtin_unreachable();
}

BinaryOperator::BinaryOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, BinaryOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, BinaryOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, BinaryOperator)
PASTA_DEFINE_DERIVED_OPERATORS(BinaryOperator, CompoundAssignOperator)
std::vector<::pasta::Stmt> BinaryOperator::Children(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token BinaryOperator::BeginToken(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token BinaryOperator::EndToken(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token BinaryOperator::ExprToken(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 1: BinaryOperator::FPFeatures
// 1: BinaryOperator::FPFeaturesInEffect
::pasta::Expr BinaryOperator::LHS(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BinaryOperator::LHS can return nullptr!");
  __builtin_unreachable();
}

enum BinaryOperatorKind BinaryOperator::Opcode(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getOpcode();
  return static_cast<::pasta::BinaryOperatorKind>(static_cast<unsigned int>(val));
}

std::string_view BinaryOperator::OpcodeStr(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getOpcodeStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token BinaryOperator::OperatorToken(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Expr BinaryOperator::RHS(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BinaryOperator::RHS can return nullptr!");
  __builtin_unreachable();
}

// 0: BinaryOperator::StoredFPFeatures
bool BinaryOperator::HasStoredFPFeatures(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.hasStoredFPFeatures();
  return val;
}

bool BinaryOperator::IsAdditiveOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isAdditiveOp();
  return val;
}

bool BinaryOperator::IsAssignmentOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isAssignmentOp();
  return val;
}

bool BinaryOperator::IsBitwiseOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isBitwiseOp();
  return val;
}

bool BinaryOperator::IsCommaOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isCommaOp();
  return val;
}

bool BinaryOperator::IsComparisonOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isComparisonOp();
  return val;
}

bool BinaryOperator::IsCompoundAssignmentOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isCompoundAssignmentOp();
  return val;
}

bool BinaryOperator::IsEqualityOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isEqualityOp();
  return val;
}

// 1: BinaryOperator::IsFEnvAccessOn
// 1: BinaryOperator::IsFPContractableWithinStatement
bool BinaryOperator::IsLogicalOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isLogicalOp();
  return val;
}

bool BinaryOperator::IsMultiplicativeOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isMultiplicativeOp();
  return val;
}

bool BinaryOperator::IsPtrMemOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isPtrMemOp();
  return val;
}

bool BinaryOperator::IsRelationalOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isRelationalOp();
  return val;
}

bool BinaryOperator::IsShiftAssignOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isShiftAssignOp();
  return val;
}

bool BinaryOperator::IsShiftOp(void) const {
  auto &self = *(u.BinaryOperator);
  auto val = self.isShiftOp();
  return val;
}

BlockExpr::BlockExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, BlockExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, BlockExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, BlockExpr)
std::vector<::pasta::Stmt> BlockExpr::Children(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token BlockExpr::BeginToken(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::BlockDecl BlockExpr::BlockDecl(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.getBlockDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::BlockDecl>(ast, val);
  }
  assert(false && "BlockExpr::BlockDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Stmt BlockExpr::Body(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "BlockExpr::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token BlockExpr::CaretLocation(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.getCaretLocation();
  return ast->TokenAt(val);
}

::pasta::Token BlockExpr::EndToken(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::FunctionProtoType BlockExpr::FunctionType(void) const {
  auto &self = *(u.BlockExpr);
  auto val = self.getFunctionType();
  if (val) {
    return TypeBuilder::Create<::pasta::FunctionProtoType>(ast, val);
  }
  assert(false && "BlockExpr::FunctionType can return nullptr!");
  __builtin_unreachable();
}

CXXBindTemporaryExpr::CXXBindTemporaryExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXBindTemporaryExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXBindTemporaryExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXBindTemporaryExpr)
std::vector<::pasta::Stmt> CXXBindTemporaryExpr::Children(void) const {
  auto &self = *(u.CXXBindTemporaryExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXBindTemporaryExpr::BeginToken(void) const {
  auto &self = *(u.CXXBindTemporaryExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXBindTemporaryExpr::EndToken(void) const {
  auto &self = *(u.CXXBindTemporaryExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXBindTemporaryExpr::SubExpr(void) const {
  auto &self = *(u.CXXBindTemporaryExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXBindTemporaryExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXBindTemporaryExpr::Temporary
CXXBoolLiteralExpr::CXXBoolLiteralExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXBoolLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXBoolLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXBoolLiteralExpr)
std::vector<::pasta::Stmt> CXXBoolLiteralExpr::Children(void) const {
  auto &self = *(u.CXXBoolLiteralExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXBoolLiteralExpr::BeginToken(void) const {
  auto &self = *(u.CXXBoolLiteralExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXBoolLiteralExpr::EndToken(void) const {
  auto &self = *(u.CXXBoolLiteralExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXBoolLiteralExpr::Token(void) const {
  auto &self = *(u.CXXBoolLiteralExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

bool CXXBoolLiteralExpr::Value(void) const {
  auto &self = *(u.CXXBoolLiteralExpr);
  auto val = self.getValue();
  return val;
}

CXXConstructExpr::CXXConstructExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXConstructExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXConstructExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXConstructExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CXXConstructExpr, CXXTemporaryObjectExpr)
// 0: CXXConstructExpr::
// 0: CXXConstructExpr::
std::vector<::pasta::Expr> CXXConstructExpr::Arguments(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Stmt> CXXConstructExpr::Children(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 1: CXXConstructExpr::Arg
// 0: CXXConstructExpr::Args
::pasta::Token CXXConstructExpr::BeginToken(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: CXXConstructExpr::ConstructionKind
::pasta::CXXConstructorDecl CXXConstructExpr::Constructor(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.getConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXConstructExpr::Constructor can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXConstructExpr::EndToken(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXConstructExpr::Token(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t CXXConstructExpr::NumArgs(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.getNumArgs();
  return val;
}

::pasta::TokenRange CXXConstructExpr::ParenOrBraceRange(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.getParenOrBraceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXConstructExpr::HadMultipleCandidates(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.hadMultipleCandidates();
  return val;
}

bool CXXConstructExpr::IsElidable(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.isElidable();
  return val;
}

bool CXXConstructExpr::IsListInitialization(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.isListInitialization();
  return val;
}

bool CXXConstructExpr::IsStdInitListInitialization(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.isStdInitListInitialization();
  return val;
}

bool CXXConstructExpr::RequiresZeroInitialization(void) const {
  auto &self = *(u.CXXConstructExpr);
  auto val = self.requiresZeroInitialization();
  return val;
}

std::vector<::pasta::Expr> CXXConstructExpr::Args(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.CXXConstructExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConstructExpr->getArg(i)));
  }
  return ret;
}

CXXDefaultArgExpr::CXXDefaultArgExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDefaultArgExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDefaultArgExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDefaultArgExpr)
std::vector<::pasta::Stmt> CXXDefaultArgExpr::Children(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXDefaultArgExpr::BeginToken(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXDefaultArgExpr::EndToken(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXDefaultArgExpr::FindExpr(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXDefaultArgExpr::FindExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXDefaultArgExpr::ExprToken(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::ParmVarDecl CXXDefaultArgExpr::Param(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getParam();
  if (val) {
    return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
  }
  assert(false && "CXXDefaultArgExpr::Param can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext CXXDefaultArgExpr::UsedContext(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getUsedContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "CXXDefaultArgExpr::UsedContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXDefaultArgExpr::UsedLocation(void) const {
  auto &self = *(u.CXXDefaultArgExpr);
  auto val = self.getUsedLocation();
  return ast->TokenAt(val);
}

CXXDefaultInitExpr::CXXDefaultInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDefaultInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDefaultInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDefaultInitExpr)
std::vector<::pasta::Stmt> CXXDefaultInitExpr::Children(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXDefaultInitExpr::BeginToken(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXDefaultInitExpr::EndToken(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXDefaultInitExpr::FindExpr(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.getExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXDefaultInitExpr::FindExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::FieldDecl CXXDefaultInitExpr::Field(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.getField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "CXXDefaultInitExpr::Field can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext CXXDefaultInitExpr::UsedContext(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.getUsedContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "CXXDefaultInitExpr::UsedContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXDefaultInitExpr::UsedLocation(void) const {
  auto &self = *(u.CXXDefaultInitExpr);
  auto val = self.getUsedLocation();
  return ast->TokenAt(val);
}

CXXDeleteExpr::CXXDeleteExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDeleteExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDeleteExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDeleteExpr)
std::vector<::pasta::Stmt> CXXDeleteExpr::Children(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

bool CXXDeleteExpr::DoesUsualArrayDeleteWantSize(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.doesUsualArrayDeleteWantSize();
  return val;
}

::pasta::Expr CXXDeleteExpr::Argument(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.getArgument();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXDeleteExpr::Argument can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXDeleteExpr::BeginToken(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Type CXXDeleteExpr::DestroyedType(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.getDestroyedType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token CXXDeleteExpr::EndToken(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::FunctionDecl CXXDeleteExpr::OperatorDelete(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.getOperatorDelete();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXDeleteExpr::OperatorDelete can return nullptr!");
  __builtin_unreachable();
}

bool CXXDeleteExpr::IsArrayForm(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.isArrayForm();
  return val;
}

bool CXXDeleteExpr::IsArrayFormAsWritten(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.isArrayFormAsWritten();
  return val;
}

bool CXXDeleteExpr::IsGlobalDelete(void) const {
  auto &self = *(u.CXXDeleteExpr);
  auto val = self.isGlobalDelete();
  return val;
}

CXXDependentScopeMemberExpr::CXXDependentScopeMemberExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDependentScopeMemberExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDependentScopeMemberExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDependentScopeMemberExpr)
std::vector<::pasta::Stmt> CXXDependentScopeMemberExpr::Children(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr CXXDependentScopeMemberExpr::Base(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXDependentScopeMemberExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type CXXDependentScopeMemberExpr::BaseType(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getBaseType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Token CXXDependentScopeMemberExpr::BeginToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXDependentScopeMemberExpr::EndToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl CXXDependentScopeMemberExpr::FirstQualifierFoundInScope(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getFirstQualifierFoundInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "CXXDependentScopeMemberExpr::FirstQualifierFoundInScope can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXDependentScopeMemberExpr::LAngleToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::Member
::pasta::Token CXXDependentScopeMemberExpr::MemberToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getMemberLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::MemberNameInfo
uint32_t CXXDependentScopeMemberExpr::NumTemplateArgs(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getNumTemplateArgs();
  return val;
}

::pasta::Token CXXDependentScopeMemberExpr::OperatorToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::Qualifier
// 0: CXXDependentScopeMemberExpr::QualifierToken
::pasta::Token CXXDependentScopeMemberExpr::RAngleToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::TemplateArgs
::pasta::Token CXXDependentScopeMemberExpr::TemplateKeywordToken(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool CXXDependentScopeMemberExpr::HasExplicitTemplateArgs(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.hasExplicitTemplateArgs();
  return val;
}

bool CXXDependentScopeMemberExpr::HasTemplateKeyword(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.hasTemplateKeyword();
  return val;
}

bool CXXDependentScopeMemberExpr::IsArrow(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.isArrow();
  return val;
}

bool CXXDependentScopeMemberExpr::IsImplicitAccess(void) const {
  auto &self = *(u.CXXDependentScopeMemberExpr);
  auto val = self.isImplicitAccess();
  return val;
}

// 0: CXXDependentScopeMemberExpr::Template_arguments
CXXFoldExpr::CXXFoldExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXFoldExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXFoldExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXFoldExpr)
std::vector<::pasta::Stmt> CXXFoldExpr::Children(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXFoldExpr::BeginToken(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::UnresolvedLookupExpr CXXFoldExpr::Callee(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getCallee();
  if (val) {
    return StmtBuilder::Create<::pasta::UnresolvedLookupExpr>(ast, val);
  }
  assert(false && "CXXFoldExpr::Callee can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXFoldExpr::EllipsisToken(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFoldExpr::EndToken(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXFoldExpr::Init(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXFoldExpr::Init can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CXXFoldExpr::LHS(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXFoldExpr::LHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXFoldExpr::LParenToken(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

std::optional<unsigned> CXXFoldExpr::NumExpansions(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getNumExpansions();
  if (val.hasValue()) {
    return val.getValue();
  } else {
    return std::nullopt;
  }
}

enum BinaryOperatorKind CXXFoldExpr::Operator(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getOperator();
  return static_cast<::pasta::BinaryOperatorKind>(static_cast<unsigned int>(val));
}

::pasta::Expr CXXFoldExpr::Pattern(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getPattern();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXFoldExpr::Pattern can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CXXFoldExpr::RHS(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXFoldExpr::RHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXFoldExpr::RParenToken(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool CXXFoldExpr::IsLeftFold(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.isLeftFold();
  return val;
}

bool CXXFoldExpr::IsRightFold(void) const {
  auto &self = *(u.CXXFoldExpr);
  auto val = self.isRightFold();
  return val;
}

CXXInheritedCtorInitExpr::CXXInheritedCtorInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXInheritedCtorInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXInheritedCtorInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXInheritedCtorInitExpr)
std::vector<::pasta::Stmt> CXXInheritedCtorInitExpr::Children(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

bool CXXInheritedCtorInitExpr::ConstructsVBase(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.constructsVBase();
  return val;
}

::pasta::Token CXXInheritedCtorInitExpr::BeginToken(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: CXXInheritedCtorInitExpr::ConstructionKind
::pasta::CXXConstructorDecl CXXInheritedCtorInitExpr::Constructor(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.getConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXInheritedCtorInitExpr::Constructor can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXInheritedCtorInitExpr::EndToken(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXInheritedCtorInitExpr::Token(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

bool CXXInheritedCtorInitExpr::InheritedFromVBase(void) const {
  auto &self = *(u.CXXInheritedCtorInitExpr);
  auto val = self.inheritedFromVBase();
  return val;
}

CXXNewExpr::CXXNewExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXNewExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXNewExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXNewExpr)
std::vector<::pasta::Stmt> CXXNewExpr::Children(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

bool CXXNewExpr::DoesUsualArrayDeleteWantSize(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.doesUsualArrayDeleteWantSize();
  return val;
}

::pasta::Type CXXNewExpr::AllocatedType(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getAllocatedType();
  return TypeBuilder::Build(ast, val);
}

// 0: CXXNewExpr::AllocatedTypeSourceInfo
// 0: CXXNewExpr::ArraySize
::pasta::Token CXXNewExpr::BeginToken(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CXXConstructExpr CXXNewExpr::ConstructExpr(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getConstructExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::CXXConstructExpr>(ast, val);
  }
  assert(false && "CXXNewExpr::ConstructExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange CXXNewExpr::DirectInitRange(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getDirectInitRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token CXXNewExpr::EndToken(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CXXNewExpr::InitializationStyle
::pasta::Expr CXXNewExpr::Initializer(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXNewExpr::Initializer can return nullptr!");
  __builtin_unreachable();
}

uint32_t CXXNewExpr::NumPlacementArgs(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getNumPlacementArgs();
  return val;
}

::pasta::FunctionDecl CXXNewExpr::OperatorDelete(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getOperatorDelete();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXNewExpr::OperatorDelete can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionDecl CXXNewExpr::OperatorNew(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getOperatorNew();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXNewExpr::OperatorNew can return nullptr!");
  __builtin_unreachable();
}

// 1: CXXNewExpr::PlacementArg
::pasta::TokenRange CXXNewExpr::TokenRange(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TokenRange CXXNewExpr::TypeIdParens(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.getTypeIdParens();
  return ast->TokenRangeFrom(val);
}

bool CXXNewExpr::HasInitializer(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.hasInitializer();
  return val;
}

bool CXXNewExpr::IsArray(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.isArray();
  return val;
}

bool CXXNewExpr::IsGlobalNew(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.isGlobalNew();
  return val;
}

bool CXXNewExpr::IsParenTypeId(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.isParenTypeId();
  return val;
}

bool CXXNewExpr::PassAlignment(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.passAlignment();
  return val;
}

// 0: CXXNewExpr::
// 0: CXXNewExpr::
std::vector<::pasta::Expr> CXXNewExpr::Placement_arguments(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.placement_arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

// 0: CXXNewExpr::
// 0: CXXNewExpr::
bool CXXNewExpr::ShouldNullCheckAllocation(void) const {
  auto &self = *(u.CXXNewExpr);
  auto val = self.shouldNullCheckAllocation();
  return val;
}

std::vector<::pasta::Expr> CXXNewExpr::PlacementArgs(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.CXXNewExpr->getNumPlacementArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXNewExpr->getPlacementArg(i)));
  }
  return ret;
}

CXXNoexceptExpr::CXXNoexceptExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXNoexceptExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXNoexceptExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXNoexceptExpr)
std::vector<::pasta::Stmt> CXXNoexceptExpr::Children(void) const {
  auto &self = *(u.CXXNoexceptExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXNoexceptExpr::BeginToken(void) const {
  auto &self = *(u.CXXNoexceptExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNoexceptExpr::EndToken(void) const {
  auto &self = *(u.CXXNoexceptExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXNoexceptExpr::Operand(void) const {
  auto &self = *(u.CXXNoexceptExpr);
  auto val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXNoexceptExpr::Operand can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange CXXNoexceptExpr::TokenRange(void) const {
  auto &self = *(u.CXXNoexceptExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXNoexceptExpr::Value(void) const {
  auto &self = *(u.CXXNoexceptExpr);
  auto val = self.getValue();
  return val;
}

CXXNullPtrLiteralExpr::CXXNullPtrLiteralExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXNullPtrLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXNullPtrLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXNullPtrLiteralExpr)
std::vector<::pasta::Stmt> CXXNullPtrLiteralExpr::Children(void) const {
  auto &self = *(u.CXXNullPtrLiteralExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXNullPtrLiteralExpr::BeginToken(void) const {
  auto &self = *(u.CXXNullPtrLiteralExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNullPtrLiteralExpr::EndToken(void) const {
  auto &self = *(u.CXXNullPtrLiteralExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNullPtrLiteralExpr::Token(void) const {
  auto &self = *(u.CXXNullPtrLiteralExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

CXXPseudoDestructorExpr::CXXPseudoDestructorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXPseudoDestructorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXPseudoDestructorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXPseudoDestructorExpr)
std::vector<::pasta::Stmt> CXXPseudoDestructorExpr::Children(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr CXXPseudoDestructorExpr::Base(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXPseudoDestructorExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXPseudoDestructorExpr::BeginToken(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXPseudoDestructorExpr::ColonColonToken(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getColonColonLoc();
  return ast->TokenAt(val);
}

::pasta::Type CXXPseudoDestructorExpr::DestroyedType(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getDestroyedType();
  return TypeBuilder::Build(ast, val);
}

// 0: CXXPseudoDestructorExpr::DestroyedTypeIdentifier
// 0: CXXPseudoDestructorExpr::DestroyedTypeInfo
::pasta::Token CXXPseudoDestructorExpr::DestroyedTypeToken(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getDestroyedTypeLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXPseudoDestructorExpr::EndToken(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXPseudoDestructorExpr::OperatorToken(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: CXXPseudoDestructorExpr::Qualifier
// 0: CXXPseudoDestructorExpr::QualifierToken
// 0: CXXPseudoDestructorExpr::ScopeTypeInfo
::pasta::Token CXXPseudoDestructorExpr::TildeToken(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.getTildeLoc();
  return ast->TokenAt(val);
}

bool CXXPseudoDestructorExpr::HasQualifier(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.hasQualifier();
  return val;
}

bool CXXPseudoDestructorExpr::IsArrow(void) const {
  auto &self = *(u.CXXPseudoDestructorExpr);
  auto val = self.isArrow();
  return val;
}

CXXRewrittenBinaryOperator::CXXRewrittenBinaryOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXRewrittenBinaryOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXRewrittenBinaryOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXRewrittenBinaryOperator)
::pasta::Token CXXRewrittenBinaryOperator::BeginToken(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: CXXRewrittenBinaryOperator::DecomposedForm
::pasta::Token CXXRewrittenBinaryOperator::EndToken(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXRewrittenBinaryOperator::ExprToken(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXRewrittenBinaryOperator::LHS(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXRewrittenBinaryOperator::LHS can return nullptr!");
  __builtin_unreachable();
}

enum BinaryOperatorKind CXXRewrittenBinaryOperator::Opcode(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getOpcode();
  return static_cast<::pasta::BinaryOperatorKind>(static_cast<unsigned int>(val));
}

std::string_view CXXRewrittenBinaryOperator::OpcodeStr(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getOpcodeStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

enum BinaryOperatorKind CXXRewrittenBinaryOperator::Operator(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getOperator();
  return static_cast<::pasta::BinaryOperatorKind>(static_cast<unsigned int>(val));
}

::pasta::Token CXXRewrittenBinaryOperator::OperatorToken(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXRewrittenBinaryOperator::RHS(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXRewrittenBinaryOperator::RHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CXXRewrittenBinaryOperator::SemanticForm(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getSemanticForm();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXRewrittenBinaryOperator::SemanticForm can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange CXXRewrittenBinaryOperator::TokenRange(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXRewrittenBinaryOperator::IsAssignmentOp(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.isAssignmentOp();
  return val;
}

bool CXXRewrittenBinaryOperator::IsComparisonOp(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.isComparisonOp();
  return val;
}

bool CXXRewrittenBinaryOperator::IsReversed(void) const {
  auto &self = *(u.CXXRewrittenBinaryOperator);
  auto val = self.isReversed();
  return val;
}

CXXScalarValueInitExpr::CXXScalarValueInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXScalarValueInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXScalarValueInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXScalarValueInitExpr)
std::vector<::pasta::Stmt> CXXScalarValueInitExpr::Children(void) const {
  auto &self = *(u.CXXScalarValueInitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXScalarValueInitExpr::BeginToken(void) const {
  auto &self = *(u.CXXScalarValueInitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXScalarValueInitExpr::EndToken(void) const {
  auto &self = *(u.CXXScalarValueInitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXScalarValueInitExpr::RParenToken(void) const {
  auto &self = *(u.CXXScalarValueInitExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: CXXScalarValueInitExpr::TypeSourceInfo
CXXStdInitializerListExpr::CXXStdInitializerListExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXStdInitializerListExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXStdInitializerListExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXStdInitializerListExpr)
std::vector<::pasta::Stmt> CXXStdInitializerListExpr::Children(void) const {
  auto &self = *(u.CXXStdInitializerListExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXStdInitializerListExpr::BeginToken(void) const {
  auto &self = *(u.CXXStdInitializerListExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXStdInitializerListExpr::EndToken(void) const {
  auto &self = *(u.CXXStdInitializerListExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange CXXStdInitializerListExpr::TokenRange(void) const {
  auto &self = *(u.CXXStdInitializerListExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Expr CXXStdInitializerListExpr::SubExpr(void) const {
  auto &self = *(u.CXXStdInitializerListExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXStdInitializerListExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

CXXTemporaryObjectExpr::CXXTemporaryObjectExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CXXConstructExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CXXConstructExpr, CXXTemporaryObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXTemporaryObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXTemporaryObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXTemporaryObjectExpr)
::pasta::Token CXXTemporaryObjectExpr::BeginToken(void) const {
  auto &self = *(u.CXXTemporaryObjectExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXTemporaryObjectExpr::EndToken(void) const {
  auto &self = *(u.CXXTemporaryObjectExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CXXTemporaryObjectExpr::TypeSourceInfo
CXXThisExpr::CXXThisExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXThisExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXThisExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXThisExpr)
std::vector<::pasta::Stmt> CXXThisExpr::Children(void) const {
  auto &self = *(u.CXXThisExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXThisExpr::BeginToken(void) const {
  auto &self = *(u.CXXThisExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXThisExpr::EndToken(void) const {
  auto &self = *(u.CXXThisExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXThisExpr::Token(void) const {
  auto &self = *(u.CXXThisExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

bool CXXThisExpr::IsImplicit(void) const {
  auto &self = *(u.CXXThisExpr);
  auto val = self.isImplicit();
  return val;
}

CXXThrowExpr::CXXThrowExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXThrowExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXThrowExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXThrowExpr)
std::vector<::pasta::Stmt> CXXThrowExpr::Children(void) const {
  auto &self = *(u.CXXThrowExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXThrowExpr::BeginToken(void) const {
  auto &self = *(u.CXXThrowExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXThrowExpr::EndToken(void) const {
  auto &self = *(u.CXXThrowExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXThrowExpr::SubExpr(void) const {
  auto &self = *(u.CXXThrowExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXThrowExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXThrowExpr::ThrowToken(void) const {
  auto &self = *(u.CXXThrowExpr);
  auto val = self.getThrowLoc();
  return ast->TokenAt(val);
}

bool CXXThrowExpr::IsThrownVariableInScope(void) const {
  auto &self = *(u.CXXThrowExpr);
  auto val = self.isThrownVariableInScope();
  return val;
}

CXXTypeidExpr::CXXTypeidExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXTypeidExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXTypeidExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXTypeidExpr)
std::vector<::pasta::Stmt> CXXTypeidExpr::Children(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXTypeidExpr::BeginToken(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXTypeidExpr::EndToken(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXTypeidExpr::ExprOperand(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.getExprOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXTypeidExpr::ExprOperand can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange CXXTypeidExpr::TokenRange(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type CXXTypeidExpr::TypeOperand(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.getTypeOperand(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

// 0: CXXTypeidExpr::TypeOperandSourceInfo
bool CXXTypeidExpr::IsMostDerived(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.isMostDerived(ast->ci->getASTContext());
  return val;
}

bool CXXTypeidExpr::IsPotentiallyEvaluated(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.isPotentiallyEvaluated();
  return val;
}

bool CXXTypeidExpr::IsTypeOperand(void) const {
  auto &self = *(u.CXXTypeidExpr);
  auto val = self.isTypeOperand();
  return val;
}

CXXUnresolvedConstructExpr::CXXUnresolvedConstructExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXUnresolvedConstructExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXUnresolvedConstructExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXUnresolvedConstructExpr)
// 0: CXXUnresolvedConstructExpr::
// 0: CXXUnresolvedConstructExpr::
// 0: CXXUnresolvedConstructExpr::Arguments
std::vector<::pasta::Stmt> CXXUnresolvedConstructExpr::Children(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 1: CXXUnresolvedConstructExpr::Arg
::pasta::Token CXXUnresolvedConstructExpr::BeginToken(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXUnresolvedConstructExpr::EndToken(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXUnresolvedConstructExpr::LParenToken(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

uint32_t CXXUnresolvedConstructExpr::NumArgs(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.getNumArgs();
  return val;
}

::pasta::Token CXXUnresolvedConstructExpr::RParenToken(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Type CXXUnresolvedConstructExpr::TypeAsWritten(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.getTypeAsWritten();
  return TypeBuilder::Build(ast, val);
}

// 0: CXXUnresolvedConstructExpr::TypeSourceInfo
bool CXXUnresolvedConstructExpr::IsListInitialization(void) const {
  auto &self = *(u.CXXUnresolvedConstructExpr);
  auto val = self.isListInitialization();
  return val;
}

std::vector<::pasta::Expr> CXXUnresolvedConstructExpr::Args(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.CXXUnresolvedConstructExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXUnresolvedConstructExpr->getArg(i)));
  }
  return ret;
}

CXXUuidofExpr::CXXUuidofExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXUuidofExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXUuidofExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXUuidofExpr)
std::vector<::pasta::Stmt> CXXUuidofExpr::Children(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CXXUuidofExpr::BeginToken(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXUuidofExpr::EndToken(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXUuidofExpr::ExprOperand(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.getExprOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXUuidofExpr::ExprOperand can return nullptr!");
  __builtin_unreachable();
}

::pasta::MSGuidDecl CXXUuidofExpr::GuidDecl(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.getGuidDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::MSGuidDecl>(ast, val);
  }
  assert(false && "CXXUuidofExpr::GuidDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange CXXUuidofExpr::TokenRange(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type CXXUuidofExpr::TypeOperand(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.getTypeOperand(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

// 0: CXXUuidofExpr::TypeOperandSourceInfo
bool CXXUuidofExpr::IsTypeOperand(void) const {
  auto &self = *(u.CXXUuidofExpr);
  auto val = self.isTypeOperand();
  return val;
}

CallExpr::CallExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CallExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CallExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CallExpr, CUDAKernelCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CallExpr, CXXMemberCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CallExpr, CXXOperatorCallExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CallExpr, UserDefinedLiteral)
// 0: CallExpr::
// 0: CallExpr::
std::vector<::pasta::Expr> CallExpr::Arguments(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
  }
  return ret;
}

std::vector<::pasta::Stmt> CallExpr::Children(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: CallExpr::ADLCallKind
// 1: CallExpr::Arg
// 0: CallExpr::Args
::pasta::Token CallExpr::BeginToken(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

uint32_t CallExpr::BuiltinCallee(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getBuiltinCallee();
  return val;
}

::pasta::Type CallExpr::CallReturnType(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getCallReturnType(ast->ci->getASTContext());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr CallExpr::Callee(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getCallee();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CallExpr::Callee can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl CallExpr::CalleeDecl(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getCalleeDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "CallExpr::CalleeDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionDecl CallExpr::DirectCallee(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getDirectCallee();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CallExpr::DirectCallee can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CallExpr::EndToken(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CallExpr::FPFeatures
// 1: CallExpr::FPFeaturesInEffect
uint32_t CallExpr::NumArgs(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getNumArgs();
  return val;
}

uint32_t CallExpr::NumCommas(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getNumCommas();
  return val;
}

::pasta::Token CallExpr::RParenToken(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: CallExpr::StoredFPFeatures
// 1: CallExpr::UnusedResultAttr
bool CallExpr::HasStoredFPFeatures(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.hasStoredFPFeatures();
  return val;
}

bool CallExpr::HasUnusedResultAttr(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.hasUnusedResultAttr(ast->ci->getASTContext());
  return val;
}

bool CallExpr::IsBuiltinAssumeFalse(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.isBuiltinAssumeFalse(ast->ci->getASTContext());
  return val;
}

bool CallExpr::IsCallToStdMove(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.isCallToStdMove();
  return val;
}

bool CallExpr::IsUnevaluatedBuiltinCall(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.isUnevaluatedBuiltinCall(ast->ci->getASTContext());
  return val;
}

bool CallExpr::UsesADL(void) const {
  auto &self = *(u.CallExpr);
  auto val = self.usesADL();
  return val;
}

std::vector<::pasta::Expr> CallExpr::Args(void) const {
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.CallExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CallExpr->getArg(i)));
  }
  return ret;
}

CastExpr::CastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, BuiltinBitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CStyleCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXAddrspaceCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXConstCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXDynamicCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXFunctionalCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXNamedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXReinterpretCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, CXXStaticCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, ExplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, ImplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CastExpr, ObjCBridgedCastExpr)
std::vector<::pasta::Stmt> CastExpr::Children(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

enum CastKind CastExpr::CastKind(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.getCastKind();
  return static_cast<::pasta::CastKind>(static_cast<unsigned int>(val));
}

std::string_view CastExpr::CastKindName(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.getCastKindName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CastExpr::CastKindName can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl CastExpr::ConversionFunction(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.getConversionFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "CastExpr::ConversionFunction can return nullptr!");
  __builtin_unreachable();
}

// 0: CastExpr::FPFeatures
// 1: CastExpr::FPFeaturesInEffect
// 0: CastExpr::StoredFPFeatures
::pasta::Expr CastExpr::SubExpr(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CastExpr::SubExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CastExpr::SubExprAsWritten(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.getSubExprAsWritten();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CastExpr::SubExprAsWritten can return nullptr!");
  __builtin_unreachable();
}

::pasta::FieldDecl CastExpr::TargetUnionField(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.getTargetUnionField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "CastExpr::TargetUnionField can return nullptr!");
  __builtin_unreachable();
}

bool CastExpr::HasStoredFPFeatures(void) const {
  auto &self = *(u.CastExpr);
  auto val = self.hasStoredFPFeatures();
  return val;
}

// 0: CastExpr::Path
// 0: CastExpr::
// 0: CastExpr::
// 0: CastExpr::
// 0: CastExpr::
CharacterLiteral::CharacterLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CharacterLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CharacterLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CharacterLiteral)
std::vector<::pasta::Stmt> CharacterLiteral::Children(void) const {
  auto &self = *(u.CharacterLiteral);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CharacterLiteral::BeginToken(void) const {
  auto &self = *(u.CharacterLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CharacterLiteral::EndToken(void) const {
  auto &self = *(u.CharacterLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CharacterLiteral::
::pasta::Token CharacterLiteral::Token(void) const {
  auto &self = *(u.CharacterLiteral);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t CharacterLiteral::Value(void) const {
  auto &self = *(u.CharacterLiteral);
  auto val = self.getValue();
  return val;
}

ChooseExpr::ChooseExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ChooseExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ChooseExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ChooseExpr)
std::vector<::pasta::Stmt> ChooseExpr::Children(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ChooseExpr::BeginToken(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ChooseExpr::BuiltinToken(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ChooseExpr::ChosenSubExpr(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getChosenSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ChooseExpr::ChosenSubExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ChooseExpr::Cond(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ChooseExpr::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ChooseExpr::EndToken(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ChooseExpr::LHS(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ChooseExpr::LHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ChooseExpr::RHS(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ChooseExpr::RHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ChooseExpr::RParenToken(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool ChooseExpr::IsConditionDependent(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.isConditionDependent();
  return val;
}

bool ChooseExpr::IsConditionTrue(void) const {
  auto &self = *(u.ChooseExpr);
  auto val = self.isConditionTrue();
  return val;
}

CompoundAssignOperator::CompoundAssignOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : BinaryOperator(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(BinaryOperator, CompoundAssignOperator)
PASTA_DEFINE_BASE_OPERATORS(Expr, CompoundAssignOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CompoundAssignOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CompoundAssignOperator)
::pasta::Type CompoundAssignOperator::ComputationLHSType(void) const {
  auto &self = *(u.CompoundAssignOperator);
  auto val = self.getComputationLHSType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type CompoundAssignOperator::ComputationResultType(void) const {
  auto &self = *(u.CompoundAssignOperator);
  auto val = self.getComputationResultType();
  return TypeBuilder::Build(ast, val);
}

CompoundLiteralExpr::CompoundLiteralExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CompoundLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CompoundLiteralExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CompoundLiteralExpr)
std::vector<::pasta::Stmt> CompoundLiteralExpr::Children(void) const {
  auto &self = *(u.CompoundLiteralExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CompoundLiteralExpr::BeginToken(void) const {
  auto &self = *(u.CompoundLiteralExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundLiteralExpr::EndToken(void) const {
  auto &self = *(u.CompoundLiteralExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CompoundLiteralExpr::Initializer(void) const {
  auto &self = *(u.CompoundLiteralExpr);
  auto val = self.getInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CompoundLiteralExpr::Initializer can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CompoundLiteralExpr::LParenToken(void) const {
  auto &self = *(u.CompoundLiteralExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

// 0: CompoundLiteralExpr::TypeSourceInfo
bool CompoundLiteralExpr::IsFileScope(void) const {
  auto &self = *(u.CompoundLiteralExpr);
  auto val = self.isFileScope();
  return val;
}

ConceptSpecializationExpr::ConceptSpecializationExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ConceptSpecializationExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ConceptSpecializationExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ConceptSpecializationExpr)
std::vector<::pasta::Stmt> ConceptSpecializationExpr::Children(void) const {
  auto &self = *(u.ConceptSpecializationExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ConceptSpecializationExpr::BeginToken(void) const {
  auto &self = *(u.ConceptSpecializationExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConceptSpecializationExpr::EndToken(void) const {
  auto &self = *(u.ConceptSpecializationExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: ConceptSpecializationExpr::Satisfaction
// 0: ConceptSpecializationExpr::TemplateArguments
bool ConceptSpecializationExpr::IsSatisfied(void) const {
  auto &self = *(u.ConceptSpecializationExpr);
  auto val = self.isSatisfied();
  return val;
}

ConditionalOperator::ConditionalOperator(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : AbstractConditionalOperator(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(AbstractConditionalOperator, ConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(Expr, ConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ConditionalOperator)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ConditionalOperator)
std::vector<::pasta::Stmt> ConditionalOperator::Children(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ConditionalOperator::BeginToken(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ConditionalOperator::Cond(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConditionalOperator::Cond can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ConditionalOperator::EndToken(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ConditionalOperator::FalseExpr(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getFalseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConditionalOperator::FalseExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ConditionalOperator::LHS(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConditionalOperator::LHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ConditionalOperator::RHS(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConditionalOperator::RHS can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ConditionalOperator::TrueExpr(void) const {
  auto &self = *(u.ConditionalOperator);
  auto val = self.getTrueExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConditionalOperator::TrueExpr can return nullptr!");
  __builtin_unreachable();
}

ConstantExpr::ConstantExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : FullExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ConstantExpr)
PASTA_DEFINE_BASE_OPERATORS(FullExpr, ConstantExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ConstantExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ConstantExpr)
std::vector<::pasta::Stmt> ConstantExpr::Children(void) const {
  auto &self = *(u.ConstantExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: ConstantExpr::APValueResult
::pasta::Token ConstantExpr::BeginToken(void) const {
  auto &self = *(u.ConstantExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConstantExpr::EndToken(void) const {
  auto &self = *(u.ConstantExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: ConstantExpr::ResultAPValueKind
// 0: ConstantExpr::ResultAsAPSInt
// 0: ConstantExpr::ResultAsAPValue
// 0: ConstantExpr::ResultStorageKind
bool ConstantExpr::HasAPValueResult(void) const {
  auto &self = *(u.ConstantExpr);
  auto val = self.hasAPValueResult();
  return val;
}

bool ConstantExpr::IsImmediateInvocation(void) const {
  auto &self = *(u.ConstantExpr);
  auto val = self.isImmediateInvocation();
  return val;
}

ConvertVectorExpr::ConvertVectorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ConvertVectorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ConvertVectorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ConvertVectorExpr)
std::vector<::pasta::Stmt> ConvertVectorExpr::Children(void) const {
  auto &self = *(u.ConvertVectorExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token ConvertVectorExpr::BeginToken(void) const {
  auto &self = *(u.ConvertVectorExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConvertVectorExpr::BuiltinToken(void) const {
  auto &self = *(u.ConvertVectorExpr);
  auto val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConvertVectorExpr::EndToken(void) const {
  auto &self = *(u.ConvertVectorExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConvertVectorExpr::RParenToken(void) const {
  auto &self = *(u.ConvertVectorExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ConvertVectorExpr::SrcExpr(void) const {
  auto &self = *(u.ConvertVectorExpr);
  auto val = self.getSrcExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConvertVectorExpr::SrcExpr can return nullptr!");
  __builtin_unreachable();
}

// 0: ConvertVectorExpr::TypeSourceInfo
CoroutineSuspendExpr::CoroutineSuspendExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CoroutineSuspendExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CoroutineSuspendExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CoroutineSuspendExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CoroutineSuspendExpr, CoawaitExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CoroutineSuspendExpr, CoyieldExpr)
std::vector<::pasta::Stmt> CoroutineSuspendExpr::Children(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token CoroutineSuspendExpr::BeginToken(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CoroutineSuspendExpr::CommonExpr(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getCommonExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineSuspendExpr::CommonExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CoroutineSuspendExpr::EndToken(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CoroutineSuspendExpr::KeywordToken(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::OpaqueValueExpr CoroutineSuspendExpr::OpaqueValue(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getOpaqueValue();
  if (val) {
    return StmtBuilder::Create<::pasta::OpaqueValueExpr>(ast, val);
  }
  assert(false && "CoroutineSuspendExpr::OpaqueValue can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CoroutineSuspendExpr::ReadyExpr(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getReadyExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineSuspendExpr::ReadyExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CoroutineSuspendExpr::ResumeExpr(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getResumeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineSuspendExpr::ResumeExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CoroutineSuspendExpr::SuspendExpr(void) const {
  auto &self = *(u.CoroutineSuspendExpr);
  auto val = self.getSuspendExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoroutineSuspendExpr::SuspendExpr can return nullptr!");
  __builtin_unreachable();
}

CoyieldExpr::CoyieldExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CoroutineSuspendExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CoroutineSuspendExpr, CoyieldExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CoyieldExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CoyieldExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CoyieldExpr)
::pasta::Expr CoyieldExpr::Operand(void) const {
  auto &self = *(u.CoyieldExpr);
  auto val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoyieldExpr::Operand can return nullptr!");
  __builtin_unreachable();
}

DeclRefExpr::DeclRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DeclRefExpr)
std::vector<::pasta::Stmt> DeclRefExpr::Children(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token DeclRefExpr::BeginToken(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ValueDecl DeclRefExpr::Decl(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "DeclRefExpr::Decl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DeclRefExpr::EndToken(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl DeclRefExpr::FoundDecl(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getFoundDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "DeclRefExpr::FoundDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DeclRefExpr::LAngleToken(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclRefExpr::Token(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

// 0: DeclRefExpr::NameInfo
uint32_t DeclRefExpr::NumTemplateArgs(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getNumTemplateArgs();
  return val;
}

// 0: DeclRefExpr::Qualifier
// 0: DeclRefExpr::QualifierToken
::pasta::Token DeclRefExpr::RAngleToken(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: DeclRefExpr::TemplateArgs
::pasta::Token DeclRefExpr::TemplateKeywordToken(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool DeclRefExpr::HadMultipleCandidates(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.hadMultipleCandidates();
  return val;
}

bool DeclRefExpr::HasExplicitTemplateArgs(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.hasExplicitTemplateArgs();
  return val;
}

bool DeclRefExpr::HasQualifier(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.hasQualifier();
  return val;
}

bool DeclRefExpr::HasTemplateKWAndArgsInfo(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.hasTemplateKWAndArgsInfo();
  return val;
}

bool DeclRefExpr::HasTemplateKeyword(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.hasTemplateKeyword();
  return val;
}

enum NonOdrUseReason DeclRefExpr::IsNonOdrUse(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.isNonOdrUse();
  return static_cast<::pasta::NonOdrUseReason>(static_cast<unsigned int>(val));
}

bool DeclRefExpr::RefersToEnclosingVariableOrCapture(void) const {
  auto &self = *(u.DeclRefExpr);
  auto val = self.refersToEnclosingVariableOrCapture();
  return val;
}

// 0: DeclRefExpr::Template_arguments
DependentCoawaitExpr::DependentCoawaitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DependentCoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DependentCoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DependentCoawaitExpr)
std::vector<::pasta::Stmt> DependentCoawaitExpr::Children(void) const {
  auto &self = *(u.DependentCoawaitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token DependentCoawaitExpr::BeginToken(void) const {
  auto &self = *(u.DependentCoawaitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentCoawaitExpr::EndToken(void) const {
  auto &self = *(u.DependentCoawaitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentCoawaitExpr::KeywordToken(void) const {
  auto &self = *(u.DependentCoawaitExpr);
  auto val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DependentCoawaitExpr::Operand(void) const {
  auto &self = *(u.DependentCoawaitExpr);
  auto val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DependentCoawaitExpr::Operand can return nullptr!");
  __builtin_unreachable();
}

::pasta::UnresolvedLookupExpr DependentCoawaitExpr::OperatorCoawaitLookup(void) const {
  auto &self = *(u.DependentCoawaitExpr);
  auto val = self.getOperatorCoawaitLookup();
  if (val) {
    return StmtBuilder::Create<::pasta::UnresolvedLookupExpr>(ast, val);
  }
  assert(false && "DependentCoawaitExpr::OperatorCoawaitLookup can return nullptr!");
  __builtin_unreachable();
}

DependentScopeDeclRefExpr::DependentScopeDeclRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DependentScopeDeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DependentScopeDeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DependentScopeDeclRefExpr)
std::vector<::pasta::Stmt> DependentScopeDeclRefExpr::Children(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Token DependentScopeDeclRefExpr::BeginToken(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: DependentScopeDeclRefExpr::DeclName
::pasta::Token DependentScopeDeclRefExpr::EndToken(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentScopeDeclRefExpr::LAngleToken(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentScopeDeclRefExpr::Token(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

// 0: DependentScopeDeclRefExpr::NameInfo
uint32_t DependentScopeDeclRefExpr::NumTemplateArgs(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getNumTemplateArgs();
  return val;
}

// 0: DependentScopeDeclRefExpr::Qualifier
// 0: DependentScopeDeclRefExpr::QualifierToken
::pasta::Token DependentScopeDeclRefExpr::RAngleToken(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: DependentScopeDeclRefExpr::TemplateArgs
::pasta::Token DependentScopeDeclRefExpr::TemplateKeywordToken(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool DependentScopeDeclRefExpr::HasExplicitTemplateArgs(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.hasExplicitTemplateArgs();
  return val;
}

bool DependentScopeDeclRefExpr::HasTemplateKeyword(void) const {
  auto &self = *(u.DependentScopeDeclRefExpr);
  auto val = self.hasTemplateKeyword();
  return val;
}

// 0: DependentScopeDeclRefExpr::Template_arguments
DesignatedInitExpr::DesignatedInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DesignatedInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DesignatedInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DesignatedInitExpr)
std::vector<::pasta::Stmt> DesignatedInitExpr::Children(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

// 0: DesignatedInitExpr::Designators
// 1: DesignatedInitExpr::ArrayIndex
// 1: DesignatedInitExpr::ArrayRangeEnd
// 1: DesignatedInitExpr::ArrayRangeStart
::pasta::Token DesignatedInitExpr::BeginToken(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: DesignatedInitExpr::Designator
::pasta::TokenRange DesignatedInitExpr::DesignatorsSourceRange(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.getDesignatorsSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token DesignatedInitExpr::EndToken(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DesignatedInitExpr::EqualOrColonToken(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.getEqualOrColonLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DesignatedInitExpr::Init(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DesignatedInitExpr::Init can return nullptr!");
  __builtin_unreachable();
}

uint32_t DesignatedInitExpr::NumSubExprs(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.getNumSubExprs();
  return val;
}

// 1: DesignatedInitExpr::SubExpr
bool DesignatedInitExpr::IsDirectInit(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.isDirectInit();
  return val;
}

uint32_t DesignatedInitExpr::Size(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.size();
  return val;
}

bool DesignatedInitExpr::UsesGNUSyntax(void) const {
  auto &self = *(u.DesignatedInitExpr);
  auto val = self.usesGNUSyntax();
  return val;
}

std::vector<::pasta::Expr> DesignatedInitExpr::SubExprs(void) const {
  auto convert_elem = [&] (clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::Expr> ret;
  auto count = u.DesignatedInitExpr->getNumSubExprs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.DesignatedInitExpr->getSubExpr(i)));
  }
  return ret;
}

DesignatedInitUpdateExpr::DesignatedInitUpdateExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DesignatedInitUpdateExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DesignatedInitUpdateExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DesignatedInitUpdateExpr)
std::vector<::pasta::Stmt> DesignatedInitUpdateExpr::Children(void) const {
  auto &self = *(u.DesignatedInitUpdateExpr);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::Expr DesignatedInitUpdateExpr::Base(void) const {
  auto &self = *(u.DesignatedInitUpdateExpr);
  auto val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DesignatedInitUpdateExpr::Base can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DesignatedInitUpdateExpr::BeginToken(void) const {
  auto &self = *(u.DesignatedInitUpdateExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DesignatedInitUpdateExpr::EndToken(void) const {
  auto &self = *(u.DesignatedInitUpdateExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::InitListExpr DesignatedInitUpdateExpr::Updater(void) const {
  auto &self = *(u.DesignatedInitUpdateExpr);
  auto val = self.getUpdater();
  if (val) {
    return StmtBuilder::Create<::pasta::InitListExpr>(ast, val);
  }
  assert(false && "DesignatedInitUpdateExpr::Updater can return nullptr!");
  __builtin_unreachable();
}

ExplicitCastExpr::ExplicitCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, ExplicitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, ExplicitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ExplicitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ExplicitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, BuiltinBitCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CStyleCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXAddrspaceCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXConstCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXDynamicCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXFunctionalCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXNamedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXReinterpretCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, CXXStaticCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(ExplicitCastExpr, ObjCBridgedCastExpr)
::pasta::Type ExplicitCastExpr::TypeAsWritten(void) const {
  auto &self = *(u.ExplicitCastExpr);
  auto val = self.getTypeAsWritten();
  return TypeBuilder::Build(ast, val);
}

// 0: ExplicitCastExpr::TypeInfoAsWritten
ExprWithCleanups::ExprWithCleanups(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : FullExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ExprWithCleanups)
PASTA_DEFINE_BASE_OPERATORS(FullExpr, ExprWithCleanups)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ExprWithCleanups)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ExprWithCleanups)
std::vector<::pasta::Stmt> ExprWithCleanups::Children(void) const {
  auto &self = *(u.ExprWithCleanups);
  auto val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

bool ExprWithCleanups::CleanupsHaveSideEffects(void) const {
  auto &self = *(u.ExprWithCleanups);
  auto val = self.cleanupsHaveSideEffects();
  return val;
}

::pasta::Token ExprWithCleanups::BeginToken(void) const {
  auto &self = *(u.ExprWithCleanups);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExprWithCleanups::EndToken(void) const {
  auto &self = *(u.ExprWithCleanups);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ExprWithCleanups::NumObjects(void) const {
  auto &self = *(u.ExprWithCleanups);
  auto val = self.getNumObjects();
  return val;
}

// 1: ExprWithCleanups::Object
// 0: ExprWithCleanups::Objects
std::vector<std::variant<std::monostate, ::pasta::BlockDecl, ::pasta::CompoundLiteralExpr>> ExprWithCleanups::Objects(void) const {
  auto convert_elem = [&] (llvm::PointerUnion<clang::BlockDecl *, clang::CompoundLiteralExpr *> val) {
    std::variant<std::monostate, ::pasta::BlockDecl, ::pasta::CompoundLiteralExpr> ret;
    if (val) {
      if (auto a_ptr = val.dyn_cast<clang::BlockDecl *>()) {
        ret = DeclBuilder::Create<::pasta::BlockDecl>(ast, a_ptr);
      } else if (auto b_ptr = val.dyn_cast<clang::CompoundLiteralExpr *>()) {
        ret = StmtBuilder::Create<::pasta::CompoundLiteralExpr>(ast, b_ptr);
      } else {
        ret = {};
      }
    } else {
      ret = {};
    }
    return ret;
  };
  std::vector<std::variant<std::monostate, ::pasta::BlockDecl, ::pasta::CompoundLiteralExpr>> ret;
  auto count = u.ExprWithCleanups->getNumObjects();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ExprWithCleanups->getObject(i)));
  }
  return ret;
}

ImplicitCastExpr::ImplicitCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, ImplicitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, ImplicitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ImplicitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ImplicitCastExpr)
::pasta::Token ImplicitCastExpr::BeginToken(void) const {
  auto &self = *(u.ImplicitCastExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ImplicitCastExpr::EndToken(void) const {
  auto &self = *(u.ImplicitCastExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

bool ImplicitCastExpr::IsPartOfExplicitCast(void) const {
  auto &self = *(u.ImplicitCastExpr);
  auto val = self.isPartOfExplicitCast();
  return val;
}

OMPAtomicDirective::OMPAtomicDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPAtomicDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPAtomicDirective)
::pasta::Expr OMPAtomicDirective::FindExpr(void) const {
  auto &self = *(u.OMPAtomicDirective);
  auto val = self.getExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAtomicDirective::FindExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPAtomicDirective::UpdateExpr(void) const {
  auto &self = *(u.OMPAtomicDirective);
  auto val = self.getUpdateExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAtomicDirective::UpdateExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPAtomicDirective::V(void) const {
  auto &self = *(u.OMPAtomicDirective);
  auto val = self.getV();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAtomicDirective::V can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPAtomicDirective::X(void) const {
  auto &self = *(u.OMPAtomicDirective);
  auto val = self.getX();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPAtomicDirective::X can return nullptr!");
  __builtin_unreachable();
}

bool OMPAtomicDirective::IsPostfixUpdate(void) const {
  auto &self = *(u.OMPAtomicDirective);
  auto val = self.isPostfixUpdate();
  return val;
}

bool OMPAtomicDirective::IsXLHSInRHSPart(void) const {
  auto &self = *(u.OMPAtomicDirective);
  auto val = self.isXLHSInRHSPart();
  return val;
}

OMPBarrierDirective::OMPBarrierDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPBarrierDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPBarrierDirective)
OMPCancelDirective::OMPCancelDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPCancelDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPCancelDirective)
// 0: OMPCancelDirective::CancelRegion
OMPCancellationPointDirective::OMPCancellationPointDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPCancellationPointDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPCancellationPointDirective)
// 0: OMPCancellationPointDirective::CancelRegion
OMPCriticalDirective::OMPCriticalDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPCriticalDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPCriticalDirective)
// 0: OMPCriticalDirective::DirectiveName
OMPDepobjDirective::OMPDepobjDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDepobjDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDepobjDirective)
OMPDistributeDirective::OMPDistributeDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeDirective)
OMPDistributeParallelForDirective::OMPDistributeParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeParallelForDirective)
::pasta::Expr OMPDistributeParallelForDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPDistributeParallelForDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDistributeParallelForDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPDistributeParallelForDirective::HasCancel(void) const {
  auto &self = *(u.OMPDistributeParallelForDirective);
  auto val = self.hasCancel();
  return val;
}

OMPDistributeParallelForSimdDirective::OMPDistributeParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeParallelForSimdDirective)
OMPDistributeSimdDirective::OMPDistributeSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeSimdDirective)
OMPForDirective::OMPForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPForDirective)
::pasta::Expr OMPForDirective::TaskReductionRefExpr(void) const {
  auto &self = *(u.OMPForDirective);
  auto val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPForDirective::TaskReductionRefExpr can return nullptr!");
  __builtin_unreachable();
}

bool OMPForDirective::HasCancel(void) const {
  auto &self = *(u.OMPForDirective);
  auto val = self.hasCancel();
  return val;
}

OMPForSimdDirective::OMPForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPForSimdDirective)
ObjCBridgedCastExpr::ObjCBridgedCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ExplicitCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, ObjCBridgedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, ObjCBridgedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCBridgedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCBridgedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCBridgedCastExpr)
::pasta::Token ObjCBridgedCastExpr::BeginToken(void) const {
  auto &self = *(u.ObjCBridgedCastExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBridgedCastExpr::BridgeKeywordToken(void) const {
  auto &self = *(u.ObjCBridgedCastExpr);
  auto val = self.getBridgeKeywordLoc();
  return ast->TokenAt(val);
}

enum ObjCBridgeCastKind ObjCBridgedCastExpr::BridgeKind(void) const {
  auto &self = *(u.ObjCBridgedCastExpr);
  auto val = self.getBridgeKind();
  return static_cast<::pasta::ObjCBridgeCastKind>(static_cast<unsigned int>(val));
}

std::string_view ObjCBridgedCastExpr::BridgeKindName(void) const {
  auto &self = *(u.ObjCBridgedCastExpr);
  auto val = self.getBridgeKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token ObjCBridgedCastExpr::EndToken(void) const {
  auto &self = *(u.ObjCBridgedCastExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBridgedCastExpr::LParenToken(void) const {
  auto &self = *(u.ObjCBridgedCastExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

UserDefinedLiteral::UserDefinedLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CallExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CallExpr, UserDefinedLiteral)
PASTA_DEFINE_BASE_OPERATORS(Expr, UserDefinedLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, UserDefinedLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, UserDefinedLiteral)
::pasta::Token UserDefinedLiteral::BeginToken(void) const {
  auto &self = *(u.UserDefinedLiteral);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr UserDefinedLiteral::CookedLiteral(void) const {
  auto &self = *(u.UserDefinedLiteral);
  auto val = self.getCookedLiteral();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "UserDefinedLiteral::CookedLiteral can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UserDefinedLiteral::EndToken(void) const {
  auto &self = *(u.UserDefinedLiteral);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: UserDefinedLiteral::LiteralOperatorKind
// 0: UserDefinedLiteral::UDSuffix
::pasta::Token UserDefinedLiteral::UDSuffixToken(void) const {
  auto &self = *(u.UserDefinedLiteral);
  auto val = self.getUDSuffixLoc();
  return ast->TokenAt(val);
}

BuiltinBitCastExpr::BuiltinBitCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ExplicitCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, BuiltinBitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, BuiltinBitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, BuiltinBitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, BuiltinBitCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, BuiltinBitCastExpr)
::pasta::Token BuiltinBitCastExpr::BeginToken(void) const {
  auto &self = *(u.BuiltinBitCastExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token BuiltinBitCastExpr::EndToken(void) const {
  auto &self = *(u.BuiltinBitCastExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

CStyleCastExpr::CStyleCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ExplicitCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, CStyleCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CStyleCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CStyleCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CStyleCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CStyleCastExpr)
::pasta::Token CStyleCastExpr::BeginToken(void) const {
  auto &self = *(u.CStyleCastExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CStyleCastExpr::EndToken(void) const {
  auto &self = *(u.CStyleCastExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CStyleCastExpr::LParenToken(void) const {
  auto &self = *(u.CStyleCastExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token CStyleCastExpr::RParenToken(void) const {
  auto &self = *(u.CStyleCastExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

CUDAKernelCallExpr::CUDAKernelCallExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CallExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CallExpr, CUDAKernelCallExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CUDAKernelCallExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CUDAKernelCallExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CUDAKernelCallExpr)
::pasta::CallExpr CUDAKernelCallExpr::Config(void) const {
  auto &self = *(u.CUDAKernelCallExpr);
  auto val = self.getConfig();
  if (val) {
    return StmtBuilder::Create<::pasta::CallExpr>(ast, val);
  }
  assert(false && "CUDAKernelCallExpr::Config can return nullptr!");
  __builtin_unreachable();
}

CXXFunctionalCastExpr::CXXFunctionalCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ExplicitCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXFunctionalCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXFunctionalCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXFunctionalCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXFunctionalCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXFunctionalCastExpr)
::pasta::Token CXXFunctionalCastExpr::BeginToken(void) const {
  auto &self = *(u.CXXFunctionalCastExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFunctionalCastExpr::EndToken(void) const {
  auto &self = *(u.CXXFunctionalCastExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFunctionalCastExpr::LParenToken(void) const {
  auto &self = *(u.CXXFunctionalCastExpr);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFunctionalCastExpr::RParenToken(void) const {
  auto &self = *(u.CXXFunctionalCastExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool CXXFunctionalCastExpr::IsListInitialization(void) const {
  auto &self = *(u.CXXFunctionalCastExpr);
  auto val = self.isListInitialization();
  return val;
}

CXXMemberCallExpr::CXXMemberCallExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CallExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CallExpr, CXXMemberCallExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXMemberCallExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXMemberCallExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXMemberCallExpr)
::pasta::Token CXXMemberCallExpr::ExprToken(void) const {
  auto &self = *(u.CXXMemberCallExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXMemberCallExpr::ImplicitObjectArgument(void) const {
  auto &self = *(u.CXXMemberCallExpr);
  auto val = self.getImplicitObjectArgument();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXMemberCallExpr::ImplicitObjectArgument can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXMethodDecl CXXMemberCallExpr::MethodDecl(void) const {
  auto &self = *(u.CXXMemberCallExpr);
  auto val = self.getMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMemberCallExpr::MethodDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type CXXMemberCallExpr::ObjectType(void) const {
  auto &self = *(u.CXXMemberCallExpr);
  auto val = self.getObjectType();
  return TypeBuilder::Build(ast, val);
}

::pasta::CXXRecordDecl CXXMemberCallExpr::RecordDecl(void) const {
  auto &self = *(u.CXXMemberCallExpr);
  auto val = self.getRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXMemberCallExpr::RecordDecl can return nullptr!");
  __builtin_unreachable();
}

CXXNamedCastExpr::CXXNamedCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ExplicitCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXNamedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXNamedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXNamedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXNamedCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXNamedCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXAddrspaceCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXConstCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXDynamicCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXReinterpretCastExpr)
PASTA_DEFINE_DERIVED_OPERATORS(CXXNamedCastExpr, CXXStaticCastExpr)
::pasta::TokenRange CXXNamedCastExpr::AngleBrackets(void) const {
  auto &self = *(u.CXXNamedCastExpr);
  auto val = self.getAngleBrackets();
  return ast->TokenRangeFrom(val);
}

::pasta::Token CXXNamedCastExpr::BeginToken(void) const {
  auto &self = *(u.CXXNamedCastExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::string_view CXXNamedCastExpr::CastName(void) const {
  auto &self = *(u.CXXNamedCastExpr);
  auto val = self.getCastName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "CXXNamedCastExpr::CastName can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token CXXNamedCastExpr::EndToken(void) const {
  auto &self = *(u.CXXNamedCastExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNamedCastExpr::OperatorToken(void) const {
  auto &self = *(u.CXXNamedCastExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNamedCastExpr::RParenToken(void) const {
  auto &self = *(u.CXXNamedCastExpr);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

CXXOperatorCallExpr::CXXOperatorCallExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CallExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CallExpr, CXXOperatorCallExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXOperatorCallExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXOperatorCallExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXOperatorCallExpr)
::pasta::Token CXXOperatorCallExpr::BeginToken(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXOperatorCallExpr::EndToken(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXOperatorCallExpr::ExprToken(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.getExprLoc();
  return ast->TokenAt(val);
}

enum OverloadedOperatorKind CXXOperatorCallExpr::Operator(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.getOperator();
  return static_cast<::pasta::OverloadedOperatorKind>(static_cast<int>(val));
}

::pasta::Token CXXOperatorCallExpr::OperatorToken(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange CXXOperatorCallExpr::TokenRange(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXOperatorCallExpr::IsAssignmentOp(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.isAssignmentOp();
  return val;
}

bool CXXOperatorCallExpr::IsComparisonOp(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.isComparisonOp();
  return val;
}

bool CXXOperatorCallExpr::IsInfixBinaryOp(void) const {
  auto &self = *(u.CXXOperatorCallExpr);
  auto val = self.isInfixBinaryOp();
  return val;
}

CXXReinterpretCastExpr::CXXReinterpretCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CXXNamedCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CXXNamedCastExpr, CXXReinterpretCastExpr)
PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXReinterpretCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXReinterpretCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXReinterpretCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXReinterpretCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXReinterpretCastExpr)
CXXStaticCastExpr::CXXStaticCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CXXNamedCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CXXNamedCastExpr, CXXStaticCastExpr)
PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXStaticCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXStaticCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXStaticCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXStaticCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXStaticCastExpr)
CoawaitExpr::CoawaitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CoroutineSuspendExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CoroutineSuspendExpr, CoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CoawaitExpr)
::pasta::Expr CoawaitExpr::Operand(void) const {
  auto &self = *(u.CoawaitExpr);
  auto val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CoawaitExpr::Operand can return nullptr!");
  __builtin_unreachable();
}

bool CoawaitExpr::IsImplicit(void) const {
  auto &self = *(u.CoawaitExpr);
  auto val = self.isImplicit();
  return val;
}

CXXAddrspaceCastExpr::CXXAddrspaceCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CXXNamedCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CXXNamedCastExpr, CXXAddrspaceCastExpr)
PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXAddrspaceCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXAddrspaceCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXAddrspaceCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXAddrspaceCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXAddrspaceCastExpr)
CXXConstCastExpr::CXXConstCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CXXNamedCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CXXNamedCastExpr, CXXConstCastExpr)
PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXConstCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXConstCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXConstCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXConstCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXConstCastExpr)
CXXDynamicCastExpr::CXXDynamicCastExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CXXNamedCastExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CXXNamedCastExpr, CXXDynamicCastExpr)
PASTA_DEFINE_BASE_OPERATORS(CastExpr, CXXDynamicCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ExplicitCastExpr, CXXDynamicCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDynamicCastExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDynamicCastExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDynamicCastExpr)
bool CXXDynamicCastExpr::IsAlwaysNull(void) const {
  auto &self = *(u.CXXDynamicCastExpr);
  auto val = self.isAlwaysNull();
  return val;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
