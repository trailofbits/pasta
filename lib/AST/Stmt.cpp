/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#define PASTA_IN_STMT_CPP
#ifndef PASTA_IN_BOOTSTRAP
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
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
      if (auto stmt_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.Stmt)) { \
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
      class derived new_that(std::forward<class derived>(that)); \
      ast = std::move(new_that.ast); \
      u.Stmt = new_that.u.Stmt; \
      kind = new_that.kind; \
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

void StmtVisitor::VisitOMPCanonicalLoop(const OMPCanonicalLoop &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitOMPExecutableDirective(const OMPExecutableDirective &stmt) {
  VisitStmt(stmt);
}

void StmtVisitor::VisitOMPFlushDirective(const OMPFlushDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPInteropDirective(const OMPInteropDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPIteratorExpr(const OMPIteratorExpr &stmt) {
  VisitExpr(stmt);
}

void StmtVisitor::VisitOMPLoopBasedDirective(const OMPLoopBasedDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPLoopDirective(const OMPLoopDirective &stmt) {
  VisitOMPLoopBasedDirective(stmt);
}

void StmtVisitor::VisitOMPLoopTransformationDirective(const OMPLoopTransformationDirective &stmt) {
  VisitOMPLoopBasedDirective(stmt);
}

void StmtVisitor::VisitOMPMaskedDirective(const OMPMaskedDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPMaskedTaskLoopDirective(const OMPMaskedTaskLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPMaskedTaskLoopSimdDirective(const OMPMaskedTaskLoopSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
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

void StmtVisitor::VisitOMPMetaDirective(const OMPMetaDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
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

void StmtVisitor::VisitOMPParallelGenericLoopDirective(const OMPParallelGenericLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPParallelMaskedDirective(const OMPParallelMaskedDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPParallelMaskedTaskLoopDirective(const OMPParallelMaskedTaskLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPParallelMaskedTaskLoopSimdDirective(const OMPParallelMaskedTaskLoopSimdDirective &stmt) {
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

void StmtVisitor::VisitOMPTargetParallelGenericLoopDirective(const OMPTargetParallelGenericLoopDirective &stmt) {
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

void StmtVisitor::VisitOMPTargetTeamsGenericLoopDirective(const OMPTargetTeamsGenericLoopDirective &stmt) {
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

void StmtVisitor::VisitOMPTeamsGenericLoopDirective(const OMPTeamsGenericLoopDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPTileDirective(const OMPTileDirective &stmt) {
  VisitOMPLoopTransformationDirective(stmt);
}

void StmtVisitor::VisitOMPUnrollDirective(const OMPUnrollDirective &stmt) {
  VisitOMPLoopTransformationDirective(stmt);
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

void StmtVisitor::VisitSYCLUniqueStableNameExpr(const SYCLUniqueStableNameExpr &stmt) {
  VisitExpr(stmt);
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

void StmtVisitor::VisitCXXParenListInitExpr(const CXXParenListInitExpr &stmt) {
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

void StmtVisitor::VisitOMPDispatchDirective(const OMPDispatchDirective &stmt) {
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

void StmtVisitor::VisitOMPErrorDirective(const OMPErrorDirective &stmt) {
  VisitOMPExecutableDirective(stmt);
}

void StmtVisitor::VisitOMPForDirective(const OMPForDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPForSimdDirective(const OMPForSimdDirective &stmt) {
  VisitOMPLoopDirective(stmt);
}

void StmtVisitor::VisitOMPGenericLoopDirective(const OMPGenericLoopDirective &stmt) {
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
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, CXXParenListInitExpr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPCanonicalLoop)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPCriticalDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDepobjDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDispatchDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPErrorDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPExecutableDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPFlushDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPInteropDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPIteratorExpr)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPLoopBasedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPLoopTransformationDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMaskedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMasterDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPMetaDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPOrderedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelMaskedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPParallelMaskedTaskLoopSimdDirective)
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
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTargetTeamsGenericLoopDirective)
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
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTeamsGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPTileDirective)
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, OMPUnrollDirective)
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
PASTA_DEFINE_DERIVED_OPERATORS(Stmt, SYCLUniqueStableNameExpr)
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
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.IgnoreContainers();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("Stmt::IgnoreContainers can return nullptr!");
}

// 0: Stmt::
// 0: Stmt::
std::vector<::pasta::Stmt> Stmt::Children(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token Stmt::BeginToken(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token Stmt::EndToken(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

int64_t Stmt::ID(void) const {
  auto &self = *(u.Stmt);
  decltype(auto) val = self.getID(ast->ci->getASTContext());
  return val;
}

::pasta::TokenRange Stmt::Tokens(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::StmtKind Stmt::Kind(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.getStmtClass();
  return static_cast<enum ::pasta::StmtKind>(val);
}

std::string_view Stmt::KindName(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.getStmtClassName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("Stmt::KindName can return nullptr!");
}

::pasta::Stmt Stmt::StripLabelLikeStatements(void) const {
  auto &self = *const_cast<clang::Stmt *>(u.Stmt);
  decltype(auto) val = self.stripLabelLikeStatements();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("Stmt::StripLabelLikeStatements can return nullptr!");
}

SwitchCase::SwitchCase(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SwitchCase)
PASTA_DEFINE_DERIVED_OPERATORS(SwitchCase, CaseStmt)
PASTA_DEFINE_DERIVED_OPERATORS(SwitchCase, DefaultStmt)
::pasta::Token SwitchCase::BeginToken(void) const {
  auto &self = *const_cast<clang::SwitchCase *>(u.SwitchCase);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchCase::ColonToken(void) const {
  auto &self = *const_cast<clang::SwitchCase *>(u.SwitchCase);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchCase::EndToken(void) const {
  auto &self = *const_cast<clang::SwitchCase *>(u.SwitchCase);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchCase::KeywordToken(void) const {
  auto &self = *const_cast<clang::SwitchCase *>(u.SwitchCase);
  decltype(auto) val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::SwitchCase> SwitchCase::NextSwitchCase(void) const {
  auto &self = *const_cast<clang::SwitchCase *>(u.SwitchCase);
  decltype(auto) val = self.getNextSwitchCase();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::SwitchCase>(ast, val);
  }
}

::pasta::Stmt SwitchCase::SubStatement(void) const {
  auto &self = *const_cast<clang::SwitchCase *>(u.SwitchCase);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("SwitchCase::SubStatement can return nullptr!");
}

SwitchStmt::SwitchStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SwitchStmt)
std::vector<::pasta::Stmt> SwitchStmt::Children(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SwitchStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt SwitchStmt::Body(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("SwitchStmt::Body can return nullptr!");
}

::pasta::Expr SwitchStmt::Condition(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("SwitchStmt::Condition can return nullptr!");
}

std::optional<::pasta::VarDecl> SwitchStmt::ConditionVariable(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getConditionVariable();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

std::optional<::pasta::DeclStmt> SwitchStmt::ConditionVariableDeclarationStatement(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getConditionVariableDeclStmt();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
}

::pasta::Token SwitchStmt::EndToken(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Stmt> SwitchStmt::Initializer(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getInit();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
}

::pasta::Token SwitchStmt::LParenToken(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token SwitchStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::SwitchCase> SwitchStmt::FirstSwitchCase(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getSwitchCaseList();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::SwitchCase>(ast, val);
  }
}

::pasta::Token SwitchStmt::SwitchToken(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.getSwitchLoc();
  return ast->TokenAt(val);
}

bool SwitchStmt::HasInitializerStorage(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.hasInitStorage();
  return val;
}

bool SwitchStmt::HasVariableStorage(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.hasVarStorage();
  return val;
}

bool SwitchStmt::IsAllEnumCasesCovered(void) const {
  auto &self = *const_cast<clang::SwitchStmt *>(u.SwitchStmt);
  decltype(auto) val = self.isAllEnumCasesCovered();
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
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, CXXParenListInitExpr)
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
PASTA_DEFINE_DERIVED_OPERATORS(ValueStmt, SYCLUniqueStableNameExpr)
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
std::optional<::pasta::Expr> ValueStmt::ExpressionStatement(void) const {
  auto &self = *const_cast<clang::ValueStmt *>(u.ValueStmt);
  decltype(auto) val = self.getExprStmt();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

WhileStmt::WhileStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, WhileStmt)
std::vector<::pasta::Stmt> WhileStmt::Children(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token WhileStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt WhileStmt::Body(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("WhileStmt::Body can return nullptr!");
}

::pasta::Expr WhileStmt::Condition(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("WhileStmt::Condition can return nullptr!");
}

std::optional<::pasta::VarDecl> WhileStmt::ConditionVariable(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getConditionVariable();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

std::optional<::pasta::DeclStmt> WhileStmt::ConditionVariableDeclarationStatement(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getConditionVariableDeclStmt();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
}

::pasta::Token WhileStmt::EndToken(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token WhileStmt::LParenToken(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token WhileStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token WhileStmt::WhileToken(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.getWhileLoc();
  return ast->TokenAt(val);
}

bool WhileStmt::HasVariableStorage(void) const {
  auto &self = *const_cast<clang::WhileStmt *>(u.WhileStmt);
  decltype(auto) val = self.hasVarStorage();
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
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: AsmStmt::
// 0: AsmStmt::
std::string AsmStmt::GenerateAssemblyString(void) const {
  auto &self = *(u.AsmStmt);
  decltype(auto) val = self.generateAsmString(ast->ci->getASTContext());
  return val;
}

::pasta::Token AsmStmt::AssemblyToken(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getAsmLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsmStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: AsmStmt::Clobber
::pasta::Token AsmStmt::EndToken(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: AsmStmt::InputConstraint
// 1: AsmStmt::InputExpression
uint32_t AsmStmt::NumClobbers(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getNumClobbers();
  return val;
}

uint32_t AsmStmt::NumInputs(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getNumInputs();
  return val;
}

uint32_t AsmStmt::NumOutputs(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getNumOutputs();
  return val;
}

uint32_t AsmStmt::NumPlusOperands(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.getNumPlusOperands();
  return val;
}

// 1: AsmStmt::OutputConstraint
// 1: AsmStmt::OutputExpression
std::vector<::pasta::Expr> AsmStmt::Inputs(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.inputs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 1: AsmStmt::IsOutputPlusConstraint
bool AsmStmt::IsSimple(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.isSimple();
  return val;
}

bool AsmStmt::IsVolatile(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.isVolatile();
  return val;
}

std::vector<::pasta::Expr> AsmStmt::Outputs(void) const {
  auto &self = *const_cast<clang::AsmStmt *>(u.AsmStmt);
  decltype(auto) val = self.outputs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<std::string_view> AsmStmt::OutputConstraints(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.AsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getOutputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> AsmStmt::OutputExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.AsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getOutputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> AsmStmt::InputConstraints(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.AsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getInputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> AsmStmt::InputExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.AsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AsmStmt->getInputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> AsmStmt::Clobbers(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::AttributedStmt *>(u.AttributedStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token AttributedStmt::AttributeToken(void) const {
  auto &self = *const_cast<clang::AttributedStmt *>(u.AttributedStmt);
  decltype(auto) val = self.getAttrLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::Attr> AttributedStmt::Attributes(void) const {
  auto &self = *const_cast<clang::AttributedStmt *>(u.AttributedStmt);
  decltype(auto) val = self.getAttrs();
  std::vector<::pasta::Attr> ret;
  for (auto attr_ptr : val) {
    if (attr_ptr) {
      ret.emplace_back(AttrBuilder::Create<::pasta::Attr>(ast, attr_ptr));
    }
  }
  return ret;
}

::pasta::Token AttributedStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::AttributedStmt *>(u.AttributedStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AttributedStmt::EndToken(void) const {
  auto &self = *const_cast<clang::AttributedStmt *>(u.AttributedStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt AttributedStmt::SubStatement(void) const {
  auto &self = *const_cast<clang::AttributedStmt *>(u.AttributedStmt);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("AttributedStmt::SubStatement can return nullptr!");
}

BreakStmt::BreakStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, BreakStmt)
std::vector<::pasta::Stmt> BreakStmt::Children(void) const {
  auto &self = *const_cast<clang::BreakStmt *>(u.BreakStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token BreakStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::BreakStmt *>(u.BreakStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token BreakStmt::BreakToken(void) const {
  auto &self = *const_cast<clang::BreakStmt *>(u.BreakStmt);
  decltype(auto) val = self.getBreakLoc();
  return ast->TokenAt(val);
}

::pasta::Token BreakStmt::EndToken(void) const {
  auto &self = *const_cast<clang::BreakStmt *>(u.BreakStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

CXXCatchStmt::CXXCatchStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXCatchStmt)
std::vector<::pasta::Stmt> CXXCatchStmt::Children(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXCatchStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXCatchStmt::CatchToken(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.getCatchLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Type> CXXCatchStmt::CaughtType(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.getCaughtType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

::pasta::Token CXXCatchStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::VarDecl> CXXCatchStmt::ExceptionDeclaration(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.getExceptionDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

::pasta::Stmt CXXCatchStmt::HandlerBlock(void) const {
  auto &self = *const_cast<clang::CXXCatchStmt *>(u.CXXCatchStmt);
  decltype(auto) val = self.getHandlerBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CXXCatchStmt::HandlerBlock can return nullptr!");
}

CXXForRangeStmt::CXXForRangeStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXForRangeStmt)
std::vector<::pasta::Stmt> CXXForRangeStmt::Children(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXForRangeStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::DeclStmt CXXForRangeStmt::BeginStatement(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getBeginStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::BeginStatement can return nullptr!");
}

::pasta::Stmt CXXForRangeStmt::Body(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::Body can return nullptr!");
}

::pasta::Token CXXForRangeStmt::CoawaitToken(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getCoawaitLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXForRangeStmt::ColonToken(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXForRangeStmt::Condition(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::Condition can return nullptr!");
}

::pasta::Token CXXForRangeStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::DeclStmt CXXForRangeStmt::EndStatement(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getEndStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::EndStatement can return nullptr!");
}

::pasta::Token CXXForRangeStmt::ForToken(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getForLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXForRangeStmt::Increment(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::Increment can return nullptr!");
}

std::optional<::pasta::Stmt> CXXForRangeStmt::Initializer(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getInit();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
}

::pasta::DeclStmt CXXForRangeStmt::LoopVariableStatement(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getLoopVarStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::LoopVariableStatement can return nullptr!");
}

::pasta::VarDecl CXXForRangeStmt::LoopVariable(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getLoopVariable();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::LoopVariable can return nullptr!");
}

::pasta::Token CXXForRangeStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXForRangeStmt::RangeInitializer(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getRangeInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::RangeInitializer can return nullptr!");
}

::pasta::DeclStmt CXXForRangeStmt::RangeStatement(void) const {
  auto &self = *const_cast<clang::CXXForRangeStmt *>(u.CXXForRangeStmt);
  decltype(auto) val = self.getRangeStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
  throw std::runtime_error("CXXForRangeStmt::RangeStatement can return nullptr!");
}

CXXTryStmt::CXXTryStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXTryStmt)
std::vector<::pasta::Stmt> CXXTryStmt::Children(void) const {
  auto &self = *const_cast<clang::CXXTryStmt *>(u.CXXTryStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXTryStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXTryStmt *>(u.CXXTryStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXTryStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CXXTryStmt *>(u.CXXTryStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: CXXTryStmt::Handler
uint32_t CXXTryStmt::NumHandlers(void) const {
  auto &self = *const_cast<clang::CXXTryStmt *>(u.CXXTryStmt);
  decltype(auto) val = self.getNumHandlers();
  return val;
}

::pasta::CompoundStmt CXXTryStmt::TryBlock(void) const {
  auto &self = *const_cast<clang::CXXTryStmt *>(u.CXXTryStmt);
  decltype(auto) val = self.getTryBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("CXXTryStmt::TryBlock can return nullptr!");
}

::pasta::Token CXXTryStmt::TryToken(void) const {
  auto &self = *const_cast<clang::CXXTryStmt *>(u.CXXTryStmt);
  decltype(auto) val = self.getTryLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::CXXCatchStmt> CXXTryStmt::Handlers(void) const {
  std::vector<::pasta::CXXCatchStmt> ret;
  auto convert_elem = [&] (const clang::CXXCatchStmt * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::CXXCatchStmt>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
// 0: CapturedStmt::CaptureInitializers
// 0: CapturedStmt::
// 0: CapturedStmt::Captures
// 1: CapturedStmt::CapturesVariable
std::vector<::pasta::Stmt> CapturedStmt::Children(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CapturedStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CapturedDecl CapturedStmt::CapturedDeclaration(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getCapturedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CapturedDecl>(ast, val);
  }
  throw std::runtime_error("CapturedStmt::CapturedDeclaration can return nullptr!");
}

::pasta::RecordDecl CapturedStmt::CapturedRecordDeclaration(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getCapturedRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  throw std::runtime_error("CapturedStmt::CapturedRecordDeclaration can return nullptr!");
}

enum CapturedRegionKind CapturedStmt::CapturedRegionKind(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getCapturedRegionKind();
  return static_cast<::pasta::CapturedRegionKind>(val);
}

::pasta::Stmt CapturedStmt::CapturedStatement(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getCapturedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CapturedStmt::CapturedStatement can return nullptr!");
}

::pasta::Token CapturedStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange CapturedStmt::Tokens(void) const {
  auto &self = *const_cast<clang::CapturedStmt *>(u.CapturedStmt);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

CaseStmt::CaseStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : SwitchCase(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CaseStmt)
PASTA_DEFINE_BASE_OPERATORS(SwitchCase, CaseStmt)
bool CaseStmt::CaseStatementIsGNURange(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.caseStmtIsGNURange();
  return val;
}

std::vector<::pasta::Stmt> CaseStmt::Children(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CaseStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CaseStmt::CaseToken(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getCaseLoc();
  return ast->TokenAt(val);
}

::pasta::Token CaseStmt::EllipsisToken(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::Token CaseStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CaseStmt::LHS(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CaseStmt::LHS can return nullptr!");
}

std::optional<::pasta::Expr> CaseStmt::RHS(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getRHS();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Stmt CaseStmt::SubStatement(void) const {
  auto &self = *const_cast<clang::CaseStmt *>(u.CaseStmt);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CaseStmt::SubStatement can return nullptr!");
}

CompoundStmt::CompoundStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CompoundStmt)
// 0: CompoundStmt::Body
// 0: CompoundStmt::
// 0: CompoundStmt::
// 0: CompoundStmt::
// 0: CompoundStmt::
// 0: CompoundStmt::
// 0: CompoundStmt::
// 0: CompoundStmt::
std::vector<::pasta::Stmt> CompoundStmt::Children(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CompoundStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundStmt::LeftBraceToken(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.getLBracLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundStmt::RightBraceToken(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.getRBracLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Stmt> CompoundStmt::StatementExpressionResult(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.getStmtExprResult();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
}

// 0: CompoundStmt::StoredFPFeatures
bool CompoundStmt::HasStoredFPFeatures(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.hasStoredFPFeatures();
  return val;
}

uint32_t CompoundStmt::Size(void) const {
  auto &self = *const_cast<clang::CompoundStmt *>(u.CompoundStmt);
  decltype(auto) val = self.size();
  return val;
}

ContinueStmt::ContinueStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ContinueStmt)
std::vector<::pasta::Stmt> ContinueStmt::Children(void) const {
  auto &self = *const_cast<clang::ContinueStmt *>(u.ContinueStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ContinueStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ContinueStmt *>(u.ContinueStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ContinueStmt::ContinueToken(void) const {
  auto &self = *const_cast<clang::ContinueStmt *>(u.ContinueStmt);
  decltype(auto) val = self.getContinueLoc();
  return ast->TokenAt(val);
}

::pasta::Token ContinueStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ContinueStmt *>(u.ContinueStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

CoreturnStmt::CoreturnStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CoreturnStmt)
std::vector<::pasta::Stmt> CoreturnStmt::Children(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CoreturnStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CoreturnStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CoreturnStmt::KeywordToken(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CoreturnStmt::Operand(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoreturnStmt::Operand can return nullptr!");
}

::pasta::Expr CoreturnStmt::PromiseCall(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.getPromiseCall();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoreturnStmt::PromiseCall can return nullptr!");
}

bool CoreturnStmt::IsImplicit(void) const {
  auto &self = *const_cast<clang::CoreturnStmt *>(u.CoreturnStmt);
  decltype(auto) val = self.isImplicit();
  return val;
}

CoroutineBodyStmt::CoroutineBodyStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, CoroutineBodyStmt)
std::vector<::pasta::Stmt> CoroutineBodyStmt::Children(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Stmt> CoroutineBodyStmt::ChildrenExclBody(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.childrenExclBody();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr CoroutineBodyStmt::Allocate(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getAllocate();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::Allocate can return nullptr!");
}

::pasta::Token CoroutineBodyStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt CoroutineBodyStmt::Body(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::Body can return nullptr!");
}

::pasta::Expr CoroutineBodyStmt::Deallocate(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getDeallocate();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::Deallocate can return nullptr!");
}

::pasta::Token CoroutineBodyStmt::EndToken(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt CoroutineBodyStmt::ExceptionHandler(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getExceptionHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::ExceptionHandler can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::FallthroughHandler(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getFallthroughHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::FallthroughHandler can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::FinalSuspendStatement(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getFinalSuspendStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::FinalSuspendStatement can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::InitializerSuspendStatement(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getInitSuspendStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::InitializerSuspendStatement can return nullptr!");
}

std::vector<::pasta::Stmt> CoroutineBodyStmt::ParameterMoves(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getParamMoves();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::VarDecl CoroutineBodyStmt::PromiseDeclaration(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getPromiseDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::PromiseDeclaration can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::PromiseDeclarationStatement(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getPromiseDeclStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::PromiseDeclarationStatement can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::ResultDeclaration(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getResultDecl();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::ResultDeclaration can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::ReturnStatement(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getReturnStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::ReturnStatement can return nullptr!");
}

::pasta::Stmt CoroutineBodyStmt::ReturnStatementOnAllocFailure(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getReturnStmtOnAllocFailure();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::ReturnStatementOnAllocFailure can return nullptr!");
}

::pasta::Expr CoroutineBodyStmt::ReturnValue(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getReturnValue();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::ReturnValue can return nullptr!");
}

::pasta::Expr CoroutineBodyStmt::ReturnValueInitializer(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.getReturnValueInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineBodyStmt::ReturnValueInitializer can return nullptr!");
}

bool CoroutineBodyStmt::HasDependentPromiseType(void) const {
  auto &self = *const_cast<clang::CoroutineBodyStmt *>(u.CoroutineBodyStmt);
  decltype(auto) val = self.hasDependentPromiseType();
  return val;
}

DeclStmt::DeclStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, DeclStmt)
std::vector<::pasta::Stmt> DeclStmt::Children(void) const {
  auto &self = *const_cast<clang::DeclStmt *>(u.DeclStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: DeclStmt::
// 0: DeclStmt::
std::vector<::pasta::Decl> DeclStmt::Declarations(void) const {
  auto &self = *const_cast<clang::DeclStmt *>(u.DeclStmt);
  decltype(auto) val = self.decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::Token DeclStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::DeclStmt *>(u.DeclStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: DeclStmt::DeclarationGroup
::pasta::Token DeclStmt::EndToken(void) const {
  auto &self = *const_cast<clang::DeclStmt *>(u.DeclStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Decl> DeclStmt::SingleDeclaration(void) const {
  auto &self = *const_cast<clang::DeclStmt *>(u.DeclStmt);
  if (!IsSingleDeclaration()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getSingleDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

bool DeclStmt::IsSingleDeclaration(void) const {
  auto &self = *const_cast<clang::DeclStmt *>(u.DeclStmt);
  decltype(auto) val = self.isSingleDecl();
  return val;
}

DefaultStmt::DefaultStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : SwitchCase(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, DefaultStmt)
PASTA_DEFINE_BASE_OPERATORS(SwitchCase, DefaultStmt)
std::vector<::pasta::Stmt> DefaultStmt::Children(void) const {
  auto &self = *const_cast<clang::DefaultStmt *>(u.DefaultStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token DefaultStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::DefaultStmt *>(u.DefaultStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DefaultStmt::DefaultToken(void) const {
  auto &self = *const_cast<clang::DefaultStmt *>(u.DefaultStmt);
  decltype(auto) val = self.getDefaultLoc();
  return ast->TokenAt(val);
}

::pasta::Token DefaultStmt::EndToken(void) const {
  auto &self = *const_cast<clang::DefaultStmt *>(u.DefaultStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt DefaultStmt::SubStatement(void) const {
  auto &self = *const_cast<clang::DefaultStmt *>(u.DefaultStmt);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("DefaultStmt::SubStatement can return nullptr!");
}

DoStmt::DoStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, DoStmt)
std::vector<::pasta::Stmt> DoStmt::Children(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token DoStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt DoStmt::Body(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("DoStmt::Body can return nullptr!");
}

::pasta::Expr DoStmt::Condition(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DoStmt::Condition can return nullptr!");
}

::pasta::Token DoStmt::DoToken(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getDoLoc();
  return ast->TokenAt(val);
}

::pasta::Token DoStmt::EndToken(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DoStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token DoStmt::WhileToken(void) const {
  auto &self = *const_cast<clang::DoStmt *>(u.DoStmt);
  decltype(auto) val = self.getWhileLoc();
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
PASTA_DEFINE_DERIVED_OPERATORS(Expr, CXXParenListInitExpr)
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
PASTA_DEFINE_DERIVED_OPERATORS(Expr, SYCLUniqueStableNameExpr)
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
enum ExprLValueClassification Expr::ClassifyLValue(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.ClassifyLValue(ast->ci->getASTContext());
  return static_cast<::pasta::ExprLValueClassification>(val);
}

// 2: ClassifyModifiable
// 2: EvaluateAsBooleanCondition
// 2: EvaluateAsConstantExpression
// 2: EvaluateAsFixedPoint
// 2: EvaluateAsFloat
// 5: Expr::EvaluateAsInitializer
// 2: EvaluateAsInt
// 2: EvaluateAsLValue
// 2: EvaluateAsRValue
// 5: Expr::EvaluateCharacterRangeAsString
std::optional<llvm::APSInt> Expr::EvaluateKnownConstInt(void) const {
  auto &self = *(u.Expr);
  if (self.getType().isNull() || self.isValueDependent()) {
    return std::nullopt;
  } else {
    auto &ac = ast->ci->getASTContext();
    return self.EvaluateKnownConstInt(ac);
  }
  decltype(auto) val = self.EvaluateKnownConstInt(ast->ci->getASTContext());
  return val;
}

std::optional<llvm::APSInt> Expr::EvaluateKnownConstIntCheckOverflow(void) const {
  auto &self = *(u.Expr);
  if (self.getType().isNull() || self.isValueDependent()) {
    return std::nullopt;
  } else {
    auto &ac = ast->ci->getASTContext();
    return self.EvaluateKnownConstIntCheckOverflow(ac);
  }
  decltype(auto) val = self.EvaluateKnownConstIntCheckOverflow(ast->ci->getASTContext());
  return val;
}

// 4: Expr::EvaluateWithSubstitution
bool Expr::HasSideEffects(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.HasSideEffects(ast->ci->getASTContext());
  return val;
}

::pasta::Expr Expr::IgnoreCasts(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreConversionOperatorSingleStep(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreConversionOperatorSingleStep();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreConversionOperatorSingleStep can return nullptr!");
}

::pasta::Expr Expr::IgnoreImplicitCasts(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreImpCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreImplicitCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreImplicit(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreImplicit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreImplicit can return nullptr!");
}

::pasta::Expr Expr::IgnoreImplicitAsWritten(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreImplicitAsWritten();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreImplicitAsWritten can return nullptr!");
}

::pasta::Expr Expr::IgnoreParenthesisBaseCasts(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreParenBaseCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreParenthesisBaseCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreParenthesisCasts(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreParenCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreParenthesisCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreParenthesisImplicitCasts(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreParenImpCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreParenthesisImplicitCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreParenthesisLValueCasts(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreParenLValueCasts();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreParenthesisLValueCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreParenthesisNoopCasts(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.IgnoreParenNoopCasts(ast->ci->getASTContext());
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreParenthesisNoopCasts can return nullptr!");
}

::pasta::Expr Expr::IgnoreParentheses(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreParens();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreParentheses can return nullptr!");
}

::pasta::Expr Expr::IgnoreUnlessSpelledInSource(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.IgnoreUnlessSpelledInSource();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("Expr::IgnoreUnlessSpelledInSource can return nullptr!");
}

bool Expr::ContainsErrors(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.containsErrors();
  return val;
}

bool Expr::ContainsUnexpandedParameterPack(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.containsUnexpandedParameterPack();
  return val;
}

std::optional<::pasta::ValueDecl> Expr::AsBuiltinConstantDeclarationReference(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.getAsBuiltinConstantDeclRef(ast->ci->getASTContext());
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
}

std::optional<::pasta::CXXRecordDecl> Expr::BestDynamicClassType(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  const clang::Expr *E = self.getBestDynamicClassTypeExpr();
  clang::QualType DerivedType = E->getType();
  if (const clang::PointerType *PTy = DerivedType->getAs<clang::PointerType>()) {
    DerivedType = PTy->getPointeeType();
  }
  if (DerivedType->isDependentType()) {
    return std::nullopt;
  }
  const clang::RecordType *Ty = DerivedType->getAs<clang::RecordType>();
  if (!Ty) {
    return std::nullopt;
  }
  clang::Decl *D = Ty->getDecl();
  if (!clang::isa<clang::CXXRecordDecl>(D)) {
    return std::nullopt;
  }
  decltype(auto) val = self.getBestDynamicClassType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

::pasta::ExprDependence Expr::Dependence(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getDependence();
  return static_cast<::pasta::ExprDependence>(val);
}

::pasta::Token Expr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 1: Expr::FPFeaturesInEffect
// 1: Expr::IntegerConstantExpression
std::optional<::pasta::ObjCPropertyRefExpr> Expr::ObjCProperty(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  if (!self.isLValue() || self.getObjectKind() != clang::OK_ObjCProperty) {
    return std::nullopt;
  }
  decltype(auto) val = self.getObjCProperty();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::ObjCPropertyRefExpr>(ast, val);
  }
}

enum ExprObjectKind Expr::ObjectKind(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getObjectKind();
  return static_cast<::pasta::ExprObjectKind>(val);
}

std::optional<::pasta::Decl> Expr::ReferencedDeclarationOfCallee(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getReferencedDeclOfCallee();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

std::optional<::pasta::FieldDecl> Expr::SourceBitField(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getSourceBitField();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
}

std::optional<::pasta::Type> Expr::Type(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

enum ExprValueKind Expr::ValueKind(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.getValueKind();
  return static_cast<::pasta::ExprValueKind>(val);
}

bool Expr::HasNonTrivialCall(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.hasNonTrivialCall(ast->ci->getASTContext());
  return val;
}

bool Expr::IsBoundMemberFunction(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.isBoundMemberFunction(ast->ci->getASTContext());
  return val;
}

std::optional<bool> Expr::IsCXX11ConstantExpression(void) const {
  auto &self = *(u.Expr);
  if (self.getType().isNull() || self.isValueDependent()) {
    return std::nullopt;
  }
  auto &ac = ast->ci->getASTContext();
  if (!ac.getLangOpts().CPlusPlus) {
    return std::nullopt;
  } else {
    return self.isCXX11ConstantExpr(ac);
  }
  decltype(auto) val = self.isCXX11ConstantExpr(ast->ci->getASTContext());
  return val;
}

std::optional<bool> Expr::IsCXX98IntegralConstantExpression(void) const {
  auto &self = *(u.Expr);
  if (self.getType().isNull() || self.isValueDependent()) {
    return std::nullopt;
  } else {
    auto &ac = ast->ci->getASTContext();
    return self.isCXX98IntegralConstantExpr(ac);
  }
  decltype(auto) val = self.isCXX98IntegralConstantExpr(ast->ci->getASTContext());
  return val;
}

// 2: IsConstantInitializer
bool Expr::IsDefaultArgument(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isDefaultArgument();
  return val;
}

std::optional<bool> Expr::IsEvaluatable(void) const {
  auto &self = *(u.Expr);
  if (self.getType().isNull() || self.isValueDependent()) {
    return std::nullopt;
  } else {
    auto &ac = ast->ci->getASTContext();
    return self.isEvaluatable(ac);
  }
  decltype(auto) val = self.isEvaluatable(ast->ci->getASTContext());
  return val;
}

// 2: IsFlexibleArrayMemberLike
bool Expr::IsGLValue(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isGLValue();
  return val;
}

bool Expr::IsImplicitCXXThis(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isImplicitCXXThis();
  return val;
}

bool Expr::IsInstantiationDependent(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isInstantiationDependent();
  return val;
}

std::optional<bool> Expr::IsIntegerConstantExpression(void) const {
  auto &self = *(u.Expr);
  if (self.getType().isNull() || self.isValueDependent()) {
    return std::nullopt;
  } else {
    auto &ac = ast->ci->getASTContext();
    return self.isIntegerConstantExpr(ac);
  }
  decltype(auto) val = self.isIntegerConstantExpr(ast->ci->getASTContext());
  return val;
}

std::optional<bool> Expr::IsKnownToHaveBooleanValue(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  if (self.getType().isNull()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isKnownToHaveBooleanValue();
  return val;
}

bool Expr::IsLValue(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isLValue();
  return val;
}

enum ExprisModifiableLvalueResult Expr::IsModifiableLvalue(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.isModifiableLvalue(ast->ci->getASTContext());
  return static_cast<::pasta::ExprisModifiableLvalueResult>(val);
}

// 2: IsNullPointerConstant
bool Expr::IsOBJCGCCandidate(void) const {
  auto &self = *(u.Expr);
  decltype(auto) val = self.isOBJCGCCandidate(ast->ci->getASTContext());
  return val;
}

bool Expr::IsObjCSelfExpression(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isObjCSelfExpr();
  return val;
}

bool Expr::IsOrdinaryOrBitFieldObject(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isOrdinaryOrBitFieldObject();
  return val;
}

bool Expr::IsPRValue(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isPRValue();
  return val;
}

std::optional<bool> Expr::IsReadIfDiscardedInCPlusPlus11(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  if (self.getType().isNull()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isReadIfDiscardedInCPlusPlus11();
  return val;
}

// 2: IsTemporaryObject
bool Expr::IsTypeDependent(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isTypeDependent();
  return val;
}

// 5: Expr::IsUnusedResultAWarning
bool Expr::IsValueDependent(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isValueDependent();
  return val;
}

bool Expr::IsXValue(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.isXValue();
  return val;
}

bool Expr::RefersToBitField(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.refersToBitField();
  return val;
}

bool Expr::RefersToGlobalRegisterVariable(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.refersToGlobalRegisterVar();
  return val;
}

bool Expr::RefersToMatrixElement(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.refersToMatrixElement();
  return val;
}

bool Expr::RefersToVectorElement(void) const {
  auto &self = *const_cast<clang::Expr *>(u.Expr);
  decltype(auto) val = self.refersToVectorElement();
  return val;
}

// 3: Expr::TryEvaluateObjectSize
// 2: TryEvaluateStringLen
ExpressionTraitExpr::ExpressionTraitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ExpressionTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ExpressionTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ExpressionTraitExpr)
std::vector<::pasta::Stmt> ExpressionTraitExpr::Children(void) const {
  auto &self = *const_cast<clang::ExpressionTraitExpr *>(u.ExpressionTraitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ExpressionTraitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ExpressionTraitExpr *>(u.ExpressionTraitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExpressionTraitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ExpressionTraitExpr *>(u.ExpressionTraitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ExpressionTraitExpr::QueriedExpression(void) const {
  auto &self = *const_cast<clang::ExpressionTraitExpr *>(u.ExpressionTraitExpr);
  decltype(auto) val = self.getQueriedExpression();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ExpressionTraitExpr::QueriedExpression can return nullptr!");
}

enum ExpressionTrait ExpressionTraitExpr::Trait(void) const {
  auto &self = *const_cast<clang::ExpressionTraitExpr *>(u.ExpressionTraitExpr);
  decltype(auto) val = self.getTrait();
  return static_cast<::pasta::ExpressionTrait>(val);
}

bool ExpressionTraitExpr::Value(void) const {
  auto &self = *const_cast<clang::ExpressionTraitExpr *>(u.ExpressionTraitExpr);
  decltype(auto) val = self.getValue();
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
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

bool ExtVectorElementExpr::ContainsDuplicateElements(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.containsDuplicateElements();
  return val;
}

// 0: ExtVectorElementExpr::Accessor
::pasta::Token ExtVectorElementExpr::AccessorToken(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.getAccessorLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ExtVectorElementExpr::Base(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ExtVectorElementExpr::Base can return nullptr!");
}

::pasta::Token ExtVectorElementExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExtVectorElementExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ExtVectorElementExpr::NumElements(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.getNumElements();
  return val;
}

bool ExtVectorElementExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::ExtVectorElementExpr *>(u.ExtVectorElementExpr);
  decltype(auto) val = self.isArrow();
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
  auto &self = *const_cast<clang::FixedPointLiteral *>(u.FixedPointLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token FixedPointLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::FixedPointLiteral *>(u.FixedPointLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token FixedPointLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::FixedPointLiteral *>(u.FixedPointLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token FixedPointLiteral::Token(void) const {
  auto &self = *const_cast<clang::FixedPointLiteral *>(u.FixedPointLiteral);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t FixedPointLiteral::Scale(void) const {
  auto &self = *const_cast<clang::FixedPointLiteral *>(u.FixedPointLiteral);
  decltype(auto) val = self.getScale();
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
  auto &self = *const_cast<clang::FloatingLiteral *>(u.FloatingLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token FloatingLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::FloatingLiteral *>(u.FloatingLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token FloatingLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::FloatingLiteral *>(u.FloatingLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token FloatingLiteral::Token(void) const {
  auto &self = *const_cast<clang::FloatingLiteral *>(u.FloatingLiteral);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

// 0: FloatingLiteral::RawSemantics
// 0: FloatingLiteral::Semantics
// 0: FloatingLiteral::Value
double FloatingLiteral::ValueAsApproximateDouble(void) const {
  auto &self = *const_cast<clang::FloatingLiteral *>(u.FloatingLiteral);
  decltype(auto) val = self.getValueAsApproximateDouble();
  return val;
}

bool FloatingLiteral::IsExact(void) const {
  auto &self = *const_cast<clang::FloatingLiteral *>(u.FloatingLiteral);
  decltype(auto) val = self.isExact();
  return val;
}

ForStmt::ForStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ForStmt)
std::vector<::pasta::Stmt> ForStmt::Children(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ForStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ForStmt::Body(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ForStmt::Body can return nullptr!");
}

std::optional<::pasta::Expr> ForStmt::Condition(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getCond();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::optional<::pasta::VarDecl> ForStmt::ConditionVariable(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getConditionVariable();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

std::optional<::pasta::DeclStmt> ForStmt::ConditionVariableDeclarationStatement(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getConditionVariableDeclStmt();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
}

::pasta::Token ForStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ForStmt::ForToken(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getForLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> ForStmt::Increment(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getInc();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::optional<::pasta::Stmt> ForStmt::Initializer(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getInit();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
}

::pasta::Token ForStmt::LParenToken(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token ForStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::ForStmt *>(u.ForStmt);
  decltype(auto) val = self.getRParenLoc();
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
::pasta::Expr FullExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::FullExpr *>(u.FullExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("FullExpr::SubExpression can return nullptr!");
}

FunctionParmPackExpr::FunctionParmPackExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, FunctionParmPackExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, FunctionParmPackExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, FunctionParmPackExpr)
// 0: FunctionParmPackExpr::
std::vector<::pasta::Stmt> FunctionParmPackExpr::Children(void) const {
  auto &self = *const_cast<clang::FunctionParmPackExpr *>(u.FunctionParmPackExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: FunctionParmPackExpr::
::pasta::Token FunctionParmPackExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::FunctionParmPackExpr *>(u.FunctionParmPackExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token FunctionParmPackExpr::EndToken(void) const {
  auto &self = *const_cast<clang::FunctionParmPackExpr *>(u.FunctionParmPackExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: FunctionParmPackExpr::Expansion
uint32_t FunctionParmPackExpr::NumExpansions(void) const {
  auto &self = *const_cast<clang::FunctionParmPackExpr *>(u.FunctionParmPackExpr);
  decltype(auto) val = self.getNumExpansions();
  return val;
}

::pasta::VarDecl FunctionParmPackExpr::ParameterPack(void) const {
  auto &self = *const_cast<clang::FunctionParmPackExpr *>(u.FunctionParmPackExpr);
  decltype(auto) val = self.getParameterPack();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("FunctionParmPackExpr::ParameterPack can return nullptr!");
}

::pasta::Token FunctionParmPackExpr::ParameterPackToken(void) const {
  auto &self = *const_cast<clang::FunctionParmPackExpr *>(u.FunctionParmPackExpr);
  decltype(auto) val = self.getParameterPackLocation();
  return ast->TokenAt(val);
}

std::vector<::pasta::VarDecl> FunctionParmPackExpr::Expansions(void) const {
  std::vector<::pasta::VarDecl> ret;
  auto convert_elem = [&] (clang::VarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
// 3: GCCAsmStmt::AnalyzeAssemblyString
// 0: GCCAsmStmt::
// 0: GCCAsmStmt::
std::string GCCAsmStmt::GenerateAssemblyString(void) const {
  auto &self = *(u.GCCAsmStmt);
  decltype(auto) val = self.generateAsmString(ast->ci->getASTContext());
  return val;
}

::pasta::StringLiteral GCCAsmStmt::AssemblyString(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.getAsmString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  throw std::runtime_error("GCCAsmStmt::AssemblyString can return nullptr!");
}

::pasta::Token GCCAsmStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: GCCAsmStmt::Clobber
// 1: GCCAsmStmt::ClobberStringLiteral
::pasta::Token GCCAsmStmt::EndToken(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: GCCAsmStmt::InputConstraint
// 1: GCCAsmStmt::InputConstraintLiteral
// 1: GCCAsmStmt::InputExpression
// 1: GCCAsmStmt::InputIdentifier
// 1: GCCAsmStmt::InputName
// 1: GCCAsmStmt::LabelExpression
// 1: GCCAsmStmt::LabelIdentifier
// 1: GCCAsmStmt::LabelName
// 1: GCCAsmStmt::NamedOperand
uint32_t GCCAsmStmt::NumLabels(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.getNumLabels();
  return val;
}

// 1: GCCAsmStmt::OutputConstraint
// 1: GCCAsmStmt::OutputConstraintLiteral
// 1: GCCAsmStmt::OutputExpression
// 1: GCCAsmStmt::OutputIdentifier
// 1: GCCAsmStmt::OutputName
::pasta::Token GCCAsmStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool GCCAsmStmt::IsAssemblyGoto(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.isAsmGoto();
  return val;
}

std::vector<::pasta::AddrLabelExpr> GCCAsmStmt::Labels(void) const {
  auto &self = *const_cast<clang::GCCAsmStmt *>(u.GCCAsmStmt);
  decltype(auto) val = self.labels();
  std::vector<::pasta::AddrLabelExpr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::AddrLabelExpr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::OutputConstraints(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getOutputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::StringLiteral> GCCAsmStmt::OutputConstraintLiterals(void) const {
  std::vector<::pasta::StringLiteral> ret;
  auto convert_elem = [&] (const clang::StringLiteral * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getOutputConstraintLiteral(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> GCCAsmStmt::OutputExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getOutputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::OutputNames(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getOutputName(i)));
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::InputConstraints(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getInputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::StringLiteral> GCCAsmStmt::InputConstraintLiterals(void) const {
  std::vector<::pasta::StringLiteral> ret;
  auto convert_elem = [&] (const clang::StringLiteral * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getInputConstraintLiteral(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> GCCAsmStmt::InputExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getInputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::InputNames(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getInputName(i)));
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::Clobbers(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumClobbers();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getClobber(i)));
  }
  return ret;
}

std::vector<::pasta::StringLiteral> GCCAsmStmt::ClobberStringLiterals(void) const {
  std::vector<::pasta::StringLiteral> ret;
  auto convert_elem = [&] (const clang::StringLiteral * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumClobbers();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getClobberStringLiteral(i)));
  }
  return ret;
}

std::vector<::pasta::AddrLabelExpr> GCCAsmStmt::LabelExpressions(void) const {
  std::vector<::pasta::AddrLabelExpr> ret;
  auto convert_elem = [&] (clang::AddrLabelExpr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::AddrLabelExpr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.GCCAsmStmt->getNumLabels();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.GCCAsmStmt->getLabelExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> GCCAsmStmt::LabelNames(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::GNUNullExpr *>(u.GNUNullExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token GNUNullExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::GNUNullExpr *>(u.GNUNullExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token GNUNullExpr::EndToken(void) const {
  auto &self = *const_cast<clang::GNUNullExpr *>(u.GNUNullExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token GNUNullExpr::TokenToken(void) const {
  auto &self = *const_cast<clang::GNUNullExpr *>(u.GNUNullExpr);
  decltype(auto) val = self.getTokenLocation();
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
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> GenericSelectionExpr::AssociationExpressions(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getAssocExprs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: GenericSelectionExpr::
// 1: GenericSelectionExpr::Association
::pasta::Token GenericSelectionExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> GenericSelectionExpr::ControllingExpression(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  if (!self.isExprPredicate()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getControllingExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::optional<::pasta::Type> GenericSelectionExpr::ControllingType(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  if (!self.isTypePredicate()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getControllingType();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

::pasta::Token GenericSelectionExpr::DefaultToken(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getDefaultLoc();
  return ast->TokenAt(val);
}

::pasta::Token GenericSelectionExpr::EndToken(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token GenericSelectionExpr::GenericToken(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getGenericLoc();
  return ast->TokenAt(val);
}

uint32_t GenericSelectionExpr::NumAssociations(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getNumAssocs();
  return val;
}

::pasta::Token GenericSelectionExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> GenericSelectionExpr::ResultExpression(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  if (self.isResultDependent()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getResultExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

uint32_t GenericSelectionExpr::ResultIndex(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.getResultIndex();
  return val;
}

bool GenericSelectionExpr::IsExpressionPredicate(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.isExprPredicate();
  return val;
}

bool GenericSelectionExpr::IsResultDependent(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.isResultDependent();
  return val;
}

bool GenericSelectionExpr::IsTypePredicate(void) const {
  auto &self = *const_cast<clang::GenericSelectionExpr *>(u.GenericSelectionExpr);
  decltype(auto) val = self.isTypePredicate();
  return val;
}

GotoStmt::GotoStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, GotoStmt)
std::vector<::pasta::Stmt> GotoStmt::Children(void) const {
  auto &self = *const_cast<clang::GotoStmt *>(u.GotoStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token GotoStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::GotoStmt *>(u.GotoStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token GotoStmt::EndToken(void) const {
  auto &self = *const_cast<clang::GotoStmt *>(u.GotoStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token GotoStmt::GotoToken(void) const {
  auto &self = *const_cast<clang::GotoStmt *>(u.GotoStmt);
  decltype(auto) val = self.getGotoLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl GotoStmt::Label(void) const {
  auto &self = *const_cast<clang::GotoStmt *>(u.GotoStmt);
  decltype(auto) val = self.getLabel();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  throw std::runtime_error("GotoStmt::Label can return nullptr!");
}

::pasta::Token GotoStmt::LabelToken(void) const {
  auto &self = *const_cast<clang::GotoStmt *>(u.GotoStmt);
  decltype(auto) val = self.getLabelLoc();
  return ast->TokenAt(val);
}

IfStmt::IfStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, IfStmt)
std::vector<::pasta::Stmt> IfStmt::Children(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token IfStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr IfStmt::Condition(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("IfStmt::Condition can return nullptr!");
}

std::optional<::pasta::VarDecl> IfStmt::ConditionVariable(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getConditionVariable();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

std::optional<::pasta::DeclStmt> IfStmt::ConditionVariableDeclarationStatement(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getConditionVariableDeclStmt();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::DeclStmt>(ast, val);
  }
}

std::optional<::pasta::Stmt> IfStmt::Else(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getElse();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
}

::pasta::Token IfStmt::ElseToken(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getElseLoc();
  return ast->TokenAt(val);
}

::pasta::Token IfStmt::EndToken(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token IfStmt::IfToken(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getIfLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Stmt> IfStmt::Initializer(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getInit();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
}

::pasta::Token IfStmt::LParenToken(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Stmt> IfStmt::NondiscardedCase(void) const {
  auto &self = *(u.IfStmt);
  decltype(auto) val = self.getNondiscardedCase(ast->ci->getASTContext());
  if (val.has_value()) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val.value());
  } else {
    return std::nullopt;
  }
}

::pasta::Token IfStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

enum IfStatementKind IfStmt::StatementKind(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getStatementKind();
  return static_cast<::pasta::IfStatementKind>(val);
}

::pasta::Stmt IfStmt::Then(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.getThen();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("IfStmt::Then can return nullptr!");
}

bool IfStmt::HasElseStorage(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.hasElseStorage();
  return val;
}

bool IfStmt::HasInitializerStorage(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.hasInitStorage();
  return val;
}

bool IfStmt::HasVariableStorage(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.hasVarStorage();
  return val;
}

bool IfStmt::IsConsteval(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.isConsteval();
  return val;
}

bool IfStmt::IsConstexpr(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.isConstexpr();
  return val;
}

bool IfStmt::IsNegatedConsteval(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.isNegatedConsteval();
  return val;
}

bool IfStmt::IsNonNegatedConsteval(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.isNonNegatedConsteval();
  return val;
}

bool IfStmt::IsObjCAvailabilityCheck(void) const {
  auto &self = *const_cast<clang::IfStmt *>(u.IfStmt);
  decltype(auto) val = self.isObjCAvailabilityCheck();
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
  auto &self = *const_cast<clang::ImaginaryLiteral *>(u.ImaginaryLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ImaginaryLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::ImaginaryLiteral *>(u.ImaginaryLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ImaginaryLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::ImaginaryLiteral *>(u.ImaginaryLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ImaginaryLiteral::SubExpression(void) const {
  auto &self = *const_cast<clang::ImaginaryLiteral *>(u.ImaginaryLiteral);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ImaginaryLiteral::SubExpression can return nullptr!");
}

ImplicitValueInitExpr::ImplicitValueInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ImplicitValueInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ImplicitValueInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ImplicitValueInitExpr)
std::vector<::pasta::Stmt> ImplicitValueInitExpr::Children(void) const {
  auto &self = *const_cast<clang::ImplicitValueInitExpr *>(u.ImplicitValueInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ImplicitValueInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ImplicitValueInitExpr *>(u.ImplicitValueInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ImplicitValueInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ImplicitValueInitExpr *>(u.ImplicitValueInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

IndirectGotoStmt::IndirectGotoStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, IndirectGotoStmt)
std::vector<::pasta::Stmt> IndirectGotoStmt::Children(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token IndirectGotoStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::LabelDecl> IndirectGotoStmt::ConstantTarget(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.getConstantTarget();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
}

::pasta::Token IndirectGotoStmt::EndToken(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token IndirectGotoStmt::GotoToken(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.getGotoLoc();
  return ast->TokenAt(val);
}

::pasta::Token IndirectGotoStmt::StarToken(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.getStarLoc();
  return ast->TokenAt(val);
}

::pasta::Expr IndirectGotoStmt::Target(void) const {
  auto &self = *const_cast<clang::IndirectGotoStmt *>(u.IndirectGotoStmt);
  decltype(auto) val = self.getTarget();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("IndirectGotoStmt::Target can return nullptr!");
}

InitListExpr::InitListExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, InitListExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, InitListExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, InitListExpr)
// 0: InitListExpr::
std::vector<::pasta::Stmt> InitListExpr::Children(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: InitListExpr::
std::optional<::pasta::Expr> InitListExpr::ArrayFiller(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getArrayFiller();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Token InitListExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token InitListExpr::EndToken(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: InitListExpr::Initializer
std::optional<::pasta::FieldDecl> InitListExpr::InitializedFieldInUnion(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getInitializedFieldInUnion();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
}

// 0: InitListExpr::Initializers
::pasta::Token InitListExpr::LBraceToken(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getLBraceLoc();
  return ast->TokenAt(val);
}

uint32_t InitListExpr::NumInitializers(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getNumInits();
  return val;
}

::pasta::Token InitListExpr::RBraceToken(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::InitListExpr> InitListExpr::SemanticForm(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getSemanticForm();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::InitListExpr>(ast, val);
  }
}

std::optional<::pasta::InitListExpr> InitListExpr::SyntacticForm(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.getSyntacticForm();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::InitListExpr>(ast, val);
  }
}

bool InitListExpr::HadArrayRangeDesignator(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.hadArrayRangeDesignator();
  return val;
}

bool InitListExpr::HasArrayFiller(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.hasArrayFiller();
  return val;
}

bool InitListExpr::HasDesignatedInitializer(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.hasDesignatedInit();
  return val;
}

std::vector<::pasta::Expr> InitListExpr::Initializers(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.inits();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

bool InitListExpr::IsExplicit(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.isExplicit();
  return val;
}

// 1: InitListExpr::IsIdiomaticZeroInitializer
bool InitListExpr::IsSemanticForm(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.isSemanticForm();
  return val;
}

bool InitListExpr::IsStringLiteralInitializer(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.isStringLiteralInit();
  return val;
}

bool InitListExpr::IsSyntacticForm(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  decltype(auto) val = self.isSyntacticForm();
  return val;
}

std::optional<bool> InitListExpr::IsTransparent(void) const {
  auto &self = *const_cast<clang::InitListExpr *>(u.InitListExpr);
  if (!self.isSemanticForm()) {
    return std::nullopt;
  } else if (self.isGLValue()) {
    if (self.getNumInits() != 1) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.isTransparent();
  return val;
}

// 0: InitListExpr::
// 0: InitListExpr::
IntegerLiteral::IntegerLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, IntegerLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, IntegerLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, IntegerLiteral)
std::vector<::pasta::Stmt> IntegerLiteral::Children(void) const {
  auto &self = *const_cast<clang::IntegerLiteral *>(u.IntegerLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token IntegerLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::IntegerLiteral *>(u.IntegerLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token IntegerLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::IntegerLiteral *>(u.IntegerLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token IntegerLiteral::Token(void) const {
  auto &self = *const_cast<clang::IntegerLiteral *>(u.IntegerLiteral);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

LabelStmt::LabelStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : ValueStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, LabelStmt)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, LabelStmt)
std::vector<::pasta::Stmt> LabelStmt::Children(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token LabelStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl LabelStmt::Declaration(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  throw std::runtime_error("LabelStmt::Declaration can return nullptr!");
}

::pasta::Token LabelStmt::EndToken(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token LabelStmt::IdentifierToken(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.getIdentLoc();
  return ast->TokenAt(val);
}

std::string_view LabelStmt::Name(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.getName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("LabelStmt::Name can return nullptr!");
}

::pasta::Stmt LabelStmt::SubStatement(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("LabelStmt::SubStatement can return nullptr!");
}

bool LabelStmt::IsSideEntry(void) const {
  auto &self = *const_cast<clang::LabelStmt *>(u.LabelStmt);
  decltype(auto) val = self.isSideEntry();
  return val;
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
// 0: LambdaExpr::CaptureInitializers
// 0: LambdaExpr::
// 0: LambdaExpr::Captures
std::vector<::pasta::Stmt> LambdaExpr::Children(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::ExplicitCaptures
::pasta::Token LambdaExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt LambdaExpr::Body(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("LambdaExpr::Body can return nullptr!");
}

::pasta::CXXMethodDecl LambdaExpr::CallOperator(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  throw std::runtime_error("LambdaExpr::CallOperator can return nullptr!");
}

enum LambdaCaptureDefault LambdaExpr::CaptureDefault(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(val);
}

::pasta::Token LambdaExpr::CaptureDefaultToken(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getCaptureDefaultLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt LambdaExpr::CompoundStatementBody(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getCompoundStmtBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("LambdaExpr::CompoundStatementBody can return nullptr!");
}

std::optional<::pasta::FunctionTemplateDecl> LambdaExpr::DependentCallOperator(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getDependentCallOperator();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
}

::pasta::Token LambdaExpr::EndToken(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::NamedDecl> LambdaExpr::ExplicitTemplateParameters(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getExplicitTemplateParameters();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::TokenRange LambdaExpr::IntroducerRange(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getIntroducerRange();
  return ast->TokenRangeFrom(val);
}

::pasta::CXXRecordDecl LambdaExpr::LambdaClass(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getLambdaClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("LambdaExpr::LambdaClass can return nullptr!");
}

std::optional<::pasta::TemplateParameterList> LambdaExpr::TemplateParameterList(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getTemplateParameterList();
  if (!val) {
    return std::nullopt;
  }
  return ::pasta::TemplateParameterList(ast, val);
}

std::optional<::pasta::Expr> LambdaExpr::TrailingRequiresClause(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.getTrailingRequiresClause();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

bool LambdaExpr::HasExplicitParameters(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.hasExplicitParameters();
  return val;
}

bool LambdaExpr::HasExplicitResultType(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.hasExplicitResultType();
  return val;
}

// 0: LambdaExpr::
// 0: LambdaExpr::
// 0: LambdaExpr::ImplicitCaptures
bool LambdaExpr::IsGenericLambda(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.isGenericLambda();
  return val;
}

// 1: LambdaExpr::IsInitializerCapture
bool LambdaExpr::IsMutable(void) const {
  auto &self = *const_cast<clang::LambdaExpr *>(u.LambdaExpr);
  decltype(auto) val = self.isMutable();
  return val;
}

MSAsmStmt::MSAsmStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : AsmStmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(AsmStmt, MSAsmStmt)
PASTA_DEFINE_BASE_OPERATORS(Stmt, MSAsmStmt)
std::vector<::pasta::Stmt> MSAsmStmt::Children(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::string MSAsmStmt::GenerateAssemblyString(void) const {
  auto &self = *(u.MSAsmStmt);
  decltype(auto) val = self.generateAsmString(ast->ci->getASTContext());
  return val;
}

std::vector<std::string_view> MSAsmStmt::AllConstraints(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getAllConstraints();
  std::vector<std::string_view> ret;
  for (auto sr : val) {
    std::string_view sv(sr.data(), sr.size());
    ret.emplace_back(std::move(sv));
  }
  return ret;
}

std::vector<::pasta::Expr> MSAsmStmt::AllExpressions(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getAllExprs();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::string_view MSAsmStmt::AssemblyString(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getAsmString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token MSAsmStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: MSAsmStmt::Clobber
std::vector<std::string_view> MSAsmStmt::Clobbers(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getClobbers();
  std::vector<std::string_view> ret;
  for (auto sr : val) {
    std::string_view sv(sr.data(), sr.size());
    ret.emplace_back(std::move(sv));
  }
  return ret;
}

::pasta::Token MSAsmStmt::EndToken(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: MSAsmStmt::InputConstraint
// 1: MSAsmStmt::InputExpression
::pasta::Token MSAsmStmt::LBraceToken(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.getLBraceLoc();
  return ast->TokenAt(val);
}

// 1: MSAsmStmt::OutputConstraint
// 1: MSAsmStmt::OutputExpression
bool MSAsmStmt::HasBraces(void) const {
  auto &self = *const_cast<clang::MSAsmStmt *>(u.MSAsmStmt);
  decltype(auto) val = self.hasBraces();
  return val;
}

std::vector<std::string_view> MSAsmStmt::OutputConstraints(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.MSAsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.MSAsmStmt->getOutputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> MSAsmStmt::OutputExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.MSAsmStmt->getNumOutputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.MSAsmStmt->getOutputExpr(i)));
  }
  return ret;
}

std::vector<std::string_view> MSAsmStmt::InputConstraints(void) const {
  std::vector<std::string_view> ret;
  auto convert_elem = [&] (llvm::StringRef val) {
    if (auto size = val.size()) {
      return std::string_view(val.data(), size);
    } else {
      return std::string_view();
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.MSAsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.MSAsmStmt->getInputConstraint(i)));
  }
  return ret;
}

std::vector<::pasta::Expr> MSAsmStmt::InputExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.MSAsmStmt->getNumInputs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.MSAsmStmt->getInputExpr(i)));
  }
  return ret;
}

MSDependentExistsStmt::MSDependentExistsStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, MSDependentExistsStmt)
std::vector<::pasta::Stmt> MSDependentExistsStmt::Children(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token MSDependentExistsStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSDependentExistsStmt::EndToken(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSDependentExistsStmt::KeywordToken(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

// 0: MSDependentExistsStmt::NameInfo
// 0: MSDependentExistsStmt::QualifierToken
::pasta::CompoundStmt MSDependentExistsStmt::SubStatement(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("MSDependentExistsStmt::SubStatement can return nullptr!");
}

bool MSDependentExistsStmt::IsIfExists(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.isIfExists();
  return val;
}

bool MSDependentExistsStmt::IsIfNotExists(void) const {
  auto &self = *const_cast<clang::MSDependentExistsStmt *>(u.MSDependentExistsStmt);
  decltype(auto) val = self.isIfNotExists();
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
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr MSPropertyRefExpr::BaseExpression(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.getBaseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MSPropertyRefExpr::BaseExpression can return nullptr!");
}

::pasta::Token MSPropertyRefExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertyRefExpr::EndToken(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertyRefExpr::MemberToken(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.getMemberLoc();
  return ast->TokenAt(val);
}

::pasta::MSPropertyDecl MSPropertyRefExpr::PropertyDeclaration(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.getPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::MSPropertyDecl>(ast, val);
  }
  throw std::runtime_error("MSPropertyRefExpr::PropertyDeclaration can return nullptr!");
}

// 0: MSPropertyRefExpr::QualifierToken
::pasta::TokenRange MSPropertyRefExpr::Tokens(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool MSPropertyRefExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.isArrow();
  return val;
}

bool MSPropertyRefExpr::IsImplicitAccess(void) const {
  auto &self = *const_cast<clang::MSPropertyRefExpr *>(u.MSPropertyRefExpr);
  decltype(auto) val = self.isImplicitAccess();
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
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr MSPropertySubscriptExpr::Base(void) const {
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MSPropertySubscriptExpr::Base can return nullptr!");
}

::pasta::Token MSPropertySubscriptExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertySubscriptExpr::EndToken(void) const {
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MSPropertySubscriptExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr MSPropertySubscriptExpr::Index(void) const {
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.getIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MSPropertySubscriptExpr::Index can return nullptr!");
}

::pasta::Token MSPropertySubscriptExpr::RBracketToken(void) const {
  auto &self = *const_cast<clang::MSPropertySubscriptExpr *>(u.MSPropertySubscriptExpr);
  decltype(auto) val = self.getRBracketLoc();
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
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token MaterializeTemporaryExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MaterializeTemporaryExpr::EndToken(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::ValueDecl> MaterializeTemporaryExpr::ExtendingDeclaration(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getExtendingDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
}

std::optional<::pasta::LifetimeExtendedTemporaryDecl> MaterializeTemporaryExpr::LifetimeExtendedTemporaryDeclaration(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getLifetimeExtendedTemporaryDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::LifetimeExtendedTemporaryDecl>(ast, val);
  }
}

uint32_t MaterializeTemporaryExpr::ManglingNumber(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getManglingNumber();
  return val;
}

// 1: MaterializeTemporaryExpr::OrCreateValue
enum StorageDuration MaterializeTemporaryExpr::StorageDuration(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
}

::pasta::Expr MaterializeTemporaryExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MaterializeTemporaryExpr::SubExpression can return nullptr!");
}

bool MaterializeTemporaryExpr::IsBoundToLvalueReference(void) const {
  auto &self = *const_cast<clang::MaterializeTemporaryExpr *>(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.isBoundToLvalueReference();
  return val;
}

bool MaterializeTemporaryExpr::IsUsableInConstantExpressions(void) const {
  auto &self = *(u.MaterializeTemporaryExpr);
  decltype(auto) val = self.isUsableInConstantExpressions(ast->ci->getASTContext());
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
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr MatrixSubscriptExpr::Base(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MatrixSubscriptExpr::Base can return nullptr!");
}

::pasta::Token MatrixSubscriptExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr MatrixSubscriptExpr::ColumnIndex(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getColumnIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MatrixSubscriptExpr::ColumnIndex can return nullptr!");
}

::pasta::Token MatrixSubscriptExpr::EndToken(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MatrixSubscriptExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token MatrixSubscriptExpr::RBracketToken(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr MatrixSubscriptExpr::RowIndex(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.getRowIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MatrixSubscriptExpr::RowIndex can return nullptr!");
}

bool MatrixSubscriptExpr::IsIncomplete(void) const {
  auto &self = *const_cast<clang::MatrixSubscriptExpr *>(u.MatrixSubscriptExpr);
  decltype(auto) val = self.isIncomplete();
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
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr MemberExpr::Base(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("MemberExpr::Base can return nullptr!");
}

::pasta::Token MemberExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token MemberExpr::EndToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token MemberExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::FoundDeclaration
::pasta::Token MemberExpr::LAngleToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

::pasta::ValueDecl MemberExpr::MemberDeclaration(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getMemberDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  throw std::runtime_error("MemberExpr::MemberDeclaration can return nullptr!");
}

::pasta::Token MemberExpr::MemberToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getMemberLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::MemberNameInfo
uint32_t MemberExpr::NumTemplateArguments(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getNumTemplateArgs();
  return val;
}

::pasta::Token MemberExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::Qualifier
// 0: MemberExpr::QualifierToken
::pasta::Token MemberExpr::RAngleToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: MemberExpr::TemplateArguments
::pasta::Token MemberExpr::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool MemberExpr::HadMultipleCandidates(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.hadMultipleCandidates();
  return val;
}

bool MemberExpr::HasExplicitTemplateArguments(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
}

bool MemberExpr::HasQualifier(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.hasQualifier();
  return val;
}

bool MemberExpr::HasTemplateKeyword(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.hasTemplateKeyword();
  return val;
}

bool MemberExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.isArrow();
  return val;
}

bool MemberExpr::IsImplicitAccess(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.isImplicitAccess();
  return val;
}

enum NonOdrUseReason MemberExpr::IsNonOdrUse(void) const {
  auto &self = *const_cast<clang::MemberExpr *>(u.MemberExpr);
  decltype(auto) val = self.isNonOdrUse();
  return static_cast<::pasta::NonOdrUseReason>(val);
}

// 1: MemberExpr::PerformsVirtualDispatch
// 0: MemberExpr::TemplateArguments
NoInitExpr::NoInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, NoInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, NoInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, NoInitExpr)
std::vector<::pasta::Stmt> NoInitExpr::Children(void) const {
  auto &self = *const_cast<clang::NoInitExpr *>(u.NoInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token NoInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::NoInitExpr *>(u.NoInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token NoInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::NoInitExpr *>(u.NoInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

NullStmt::NullStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, NullStmt)
std::vector<::pasta::Stmt> NullStmt::Children(void) const {
  auto &self = *const_cast<clang::NullStmt *>(u.NullStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token NullStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::NullStmt *>(u.NullStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token NullStmt::EndToken(void) const {
  auto &self = *const_cast<clang::NullStmt *>(u.NullStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token NullStmt::SemiToken(void) const {
  auto &self = *const_cast<clang::NullStmt *>(u.NullStmt);
  decltype(auto) val = self.getSemiLoc();
  return ast->TokenAt(val);
}

bool NullStmt::HasLeadingEmptyMacro(void) const {
  auto &self = *const_cast<clang::NullStmt *>(u.NullStmt);
  decltype(auto) val = self.hasLeadingEmptyMacro();
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
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr OMPArraySectionExpr::Base(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPArraySectionExpr::Base can return nullptr!");
}

::pasta::Token OMPArraySectionExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::FirstColonToken(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getColonLocFirst();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::SecondColonToken(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getColonLocSecond();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::EndToken(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArraySectionExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr OMPArraySectionExpr::Length(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getLength();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPArraySectionExpr::Length can return nullptr!");
}

::pasta::Expr OMPArraySectionExpr::LowerBound(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getLowerBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPArraySectionExpr::LowerBound can return nullptr!");
}

::pasta::Token OMPArraySectionExpr::RBracketToken(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr OMPArraySectionExpr::Stride(void) const {
  auto &self = *const_cast<clang::OMPArraySectionExpr *>(u.OMPArraySectionExpr);
  decltype(auto) val = self.getStride();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPArraySectionExpr::Stride can return nullptr!");
}

OMPArrayShapingExpr::OMPArrayShapingExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OMPArrayShapingExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPArrayShapingExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OMPArrayShapingExpr)
std::vector<::pasta::Stmt> OMPArrayShapingExpr::Children(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr OMPArrayShapingExpr::Base(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPArrayShapingExpr::Base can return nullptr!");
}

::pasta::Token OMPArrayShapingExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::TokenRange> OMPArrayShapingExpr::BracketsRanges(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getBracketsRanges();
  std::vector<::pasta::TokenRange> ret;
  for (auto sr : val) {
    ret.emplace_back(ast->TokenRangeFrom(sr));
  }
  return ret;
}

std::vector<::pasta::Expr> OMPArrayShapingExpr::Dimensions(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getDimensions();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token OMPArrayShapingExpr::EndToken(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArrayShapingExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPArrayShapingExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::OMPArrayShapingExpr *>(u.OMPArrayShapingExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

OMPCanonicalLoop::OMPCanonicalLoop(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPCanonicalLoop)
std::vector<::pasta::Stmt> OMPCanonicalLoop::Children(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token OMPCanonicalLoop::BeginToken(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CapturedStmt OMPCanonicalLoop::DistanceFunc(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.getDistanceFunc();
  if (val) {
    return StmtBuilder::Create<::pasta::CapturedStmt>(ast, val);
  }
  throw std::runtime_error("OMPCanonicalLoop::DistanceFunc can return nullptr!");
}

::pasta::Token OMPCanonicalLoop::EndToken(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt OMPCanonicalLoop::LoopStatement(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.getLoopStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPCanonicalLoop::LoopStatement can return nullptr!");
}

::pasta::CapturedStmt OMPCanonicalLoop::LoopVariableFunc(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.getLoopVarFunc();
  if (val) {
    return StmtBuilder::Create<::pasta::CapturedStmt>(ast, val);
  }
  throw std::runtime_error("OMPCanonicalLoop::LoopVariableFunc can return nullptr!");
}

::pasta::DeclRefExpr OMPCanonicalLoop::LoopVariableReference(void) const {
  auto &self = *const_cast<clang::OMPCanonicalLoop *>(u.OMPCanonicalLoop);
  decltype(auto) val = self.getLoopVarRef();
  if (val) {
    return StmtBuilder::Create<::pasta::DeclRefExpr>(ast, val);
  }
  throw std::runtime_error("OMPCanonicalLoop::LoopVariableReference can return nullptr!");
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
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDispatchDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPErrorDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPFlushDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPInteropDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPLoopBasedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPLoopTransformationDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMaskedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPMetaDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPOrderedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMaskedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPParallelMaskedTaskLoopSimdDirective)
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
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTargetTeamsGenericLoopDirective)
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
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTeamsGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPTileDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPExecutableDirective, OMPUnrollDirective)
std::vector<::pasta::Stmt> OMPExecutableDirective::Children(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: OMPExecutableDirective::Clauses
::pasta::Stmt OMPExecutableDirective::AssociatedStatement(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getAssociatedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPExecutableDirective::AssociatedStatement can return nullptr!");
}

::pasta::Token OMPExecutableDirective::BeginToken(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: OMPExecutableDirective::CapturedStatement
// 1: OMPExecutableDirective::Clause
// 0: OMPExecutableDirective::DirectiveKind
::pasta::Token OMPExecutableDirective::EndToken(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::CapturedStmt OMPExecutableDirective::InnermostCapturedStatement(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getInnermostCapturedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::CapturedStmt>(ast, val);
  }
  throw std::runtime_error("OMPExecutableDirective::InnermostCapturedStatement can return nullptr!");
}

uint32_t OMPExecutableDirective::NumClauses(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getNumClauses();
  return val;
}

::pasta::Stmt OMPExecutableDirective::RawStatement(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getRawStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPExecutableDirective::RawStatement can return nullptr!");
}

::pasta::Stmt OMPExecutableDirective::StructuredBlock(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.getStructuredBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPExecutableDirective::StructuredBlock can return nullptr!");
}

bool OMPExecutableDirective::HasAssociatedStatement(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.hasAssociatedStmt();
  return val;
}

bool OMPExecutableDirective::IsStandaloneDirective(void) const {
  auto &self = *const_cast<clang::OMPExecutableDirective *>(u.OMPExecutableDirective);
  decltype(auto) val = self.isStandaloneDirective();
  return val;
}

OMPFlushDirective::OMPFlushDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPFlushDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPFlushDirective)
OMPInteropDirective::OMPInteropDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPInteropDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPInteropDirective)
OMPIteratorExpr::OMPIteratorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OMPIteratorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPIteratorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OMPIteratorExpr)
std::vector<::pasta::Stmt> OMPIteratorExpr::Children(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 1: OMPIteratorExpr::AssignToken
::pasta::Token OMPIteratorExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::ColonToken
::pasta::Token OMPIteratorExpr::EndToken(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::Helper
// 1: OMPIteratorExpr::IteratorDeclaration
::pasta::Token OMPIteratorExpr::IteratorKwToken(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.getIteratorKwLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::IteratorRange
::pasta::Token OMPIteratorExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token OMPIteratorExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 1: OMPIteratorExpr::SecondColonToken
uint32_t OMPIteratorExpr::NumOfIterators(void) const {
  auto &self = *const_cast<clang::OMPIteratorExpr *>(u.OMPIteratorExpr);
  decltype(auto) val = self.numOfIterators();
  return val;
}

OMPLoopBasedDirective::OMPLoopBasedDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPLoopBasedDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPLoopBasedDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPLoopTransformationDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelMaskedTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTeamsGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPTileDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopBasedDirective, OMPUnrollDirective)
uint32_t OMPLoopBasedDirective::LoopsNumber(void) const {
  auto &self = *const_cast<clang::OMPLoopBasedDirective *>(u.OMPLoopBasedDirective);
  decltype(auto) val = self.getLoopsNumber();
  return val;
}

OMPLoopDirective::OMPLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopBasedDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMaskedTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTargetTeamsGenericLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTaskLoopDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopDirective, OMPTeamsGenericLoopDirective)
std::vector<::pasta::Expr> OMPLoopDirective::Counters(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.counters();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::DependentCounters(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.dependent_counters();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::DependentInitializers(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.dependent_inits();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Finals(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.finals();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::FinalsConditions(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.finals_conditions();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Stmt OMPLoopDirective::Body(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::Body can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CalculateLastIteration(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCalcLastIteration();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CalculateLastIteration can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedCondition(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedCondition can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedDistanceCondition(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedDistCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedDistanceCondition can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedEnsureUpperBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedEnsureUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedEnsureUpperBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedInitializer(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedInitializer can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedLowerBoundVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedLowerBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedLowerBoundVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedNextLowerBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedNextLowerBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedNextLowerBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedNextUpperBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedNextUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedNextUpperBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedParallelForInDistanceCondition(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedParForInDistCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedParallelForInDistanceCondition can return nullptr!");
}

::pasta::Expr OMPLoopDirective::CombinedUpperBoundVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCombinedUpperBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::CombinedUpperBoundVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::Condition(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::Condition can return nullptr!");
}

::pasta::Expr OMPLoopDirective::DistanceIncrement(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getDistInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::DistanceIncrement can return nullptr!");
}

::pasta::Expr OMPLoopDirective::EnsureUpperBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getEnsureUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::EnsureUpperBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::Increment(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getInc();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::Increment can return nullptr!");
}

::pasta::Expr OMPLoopDirective::Initializer(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::Initializer can return nullptr!");
}

::pasta::Expr OMPLoopDirective::IsLastIterationVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getIsLastIterVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::IsLastIterationVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::IterationVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getIterationVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::IterationVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::LastIteration(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getLastIteration();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::LastIteration can return nullptr!");
}

::pasta::Expr OMPLoopDirective::LowerBoundVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getLowerBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::LowerBoundVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::NextLowerBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getNextLowerBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::NextLowerBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::NextUpperBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getNextUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::NextUpperBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::NumIterations(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getNumIterations();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::NumIterations can return nullptr!");
}

::pasta::Expr OMPLoopDirective::PreCondition(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getPreCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::PreCondition can return nullptr!");
}

::pasta::Stmt OMPLoopDirective::PreInitializers(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getPreInits();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::PreInitializers can return nullptr!");
}

::pasta::Expr OMPLoopDirective::PrevEnsureUpperBound(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getPrevEnsureUpperBound();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::PrevEnsureUpperBound can return nullptr!");
}

::pasta::Expr OMPLoopDirective::PrevLowerBoundVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getPrevLowerBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::PrevLowerBoundVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::PrevUpperBoundVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getPrevUpperBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::PrevUpperBoundVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::StrideVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getStrideVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::StrideVariable can return nullptr!");
}

::pasta::Expr OMPLoopDirective::UpperBoundVariable(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.getUpperBoundVariable();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPLoopDirective::UpperBoundVariable can return nullptr!");
}

std::vector<::pasta::Expr> OMPLoopDirective::Initializers(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.inits();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::PrivateCounters(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.private_counters();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Expr> OMPLoopDirective::Updates(void) const {
  auto &self = *const_cast<clang::OMPLoopDirective *>(u.OMPLoopDirective);
  decltype(auto) val = self.updates();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

OMPLoopTransformationDirective::OMPLoopTransformationDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopBasedDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPLoopTransformationDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPLoopTransformationDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPLoopTransformationDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopTransformationDirective, OMPTileDirective)
PASTA_DEFINE_DERIVED_OPERATORS(OMPLoopTransformationDirective, OMPUnrollDirective)
uint32_t OMPLoopTransformationDirective::NumAssociatedLoops(void) const {
  auto &self = *const_cast<clang::OMPLoopTransformationDirective *>(u.OMPLoopTransformationDirective);
  decltype(auto) val = self.getNumAssociatedLoops();
  return val;
}

::pasta::Stmt OMPLoopTransformationDirective::PreInitializers(void) const {
  auto &self = *const_cast<clang::OMPLoopTransformationDirective *>(u.OMPLoopTransformationDirective);
  decltype(auto) val = self.getPreInits();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPLoopTransformationDirective::PreInitializers can return nullptr!");
}

::pasta::Stmt OMPLoopTransformationDirective::TransformedStatement(void) const {
  auto &self = *const_cast<clang::OMPLoopTransformationDirective *>(u.OMPLoopTransformationDirective);
  decltype(auto) val = self.getTransformedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPLoopTransformationDirective::TransformedStatement can return nullptr!");
}

OMPMaskedDirective::OMPMaskedDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMaskedDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMaskedDirective)
OMPMaskedTaskLoopDirective::OMPMaskedTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPMaskedTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMaskedTaskLoopDirective)
bool OMPMaskedTaskLoopDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPMaskedTaskLoopDirective *>(u.OMPMaskedTaskLoopDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPMaskedTaskLoopSimdDirective::OMPMaskedTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPMaskedTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMaskedTaskLoopSimdDirective)
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
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMasterTaskLoopDirective)
bool OMPMasterTaskLoopDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPMasterTaskLoopDirective *>(u.OMPMasterTaskLoopDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPMasterTaskLoopSimdDirective::OMPMasterTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMasterTaskLoopSimdDirective)
OMPMetaDirective::OMPMetaDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPMetaDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPMetaDirective)
::pasta::Stmt OMPMetaDirective::IfStatement(void) const {
  auto &self = *const_cast<clang::OMPMetaDirective *>(u.OMPMetaDirective);
  decltype(auto) val = self.getIfStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPMetaDirective::IfStatement can return nullptr!");
}

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
::pasta::Expr OMPParallelDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPParallelDirective *>(u.OMPParallelDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPParallelDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPParallelDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPParallelDirective *>(u.OMPParallelDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPParallelForDirective::OMPParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelForDirective)
::pasta::Expr OMPParallelForDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPParallelForDirective *>(u.OMPParallelForDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPParallelForDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPParallelForDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPParallelForDirective *>(u.OMPParallelForDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPParallelForSimdDirective::OMPParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelForSimdDirective)
OMPParallelGenericLoopDirective::OMPParallelGenericLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelGenericLoopDirective)
OMPParallelMaskedDirective::OMPParallelMaskedDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMaskedDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMaskedDirective)
::pasta::Expr OMPParallelMaskedDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPParallelMaskedDirective *>(u.OMPParallelMaskedDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPParallelMaskedDirective::TaskReductionReferenceExpression can return nullptr!");
}

OMPParallelMaskedTaskLoopDirective::OMPParallelMaskedTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMaskedTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMaskedTaskLoopDirective)
bool OMPParallelMaskedTaskLoopDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPParallelMaskedTaskLoopDirective *>(u.OMPParallelMaskedTaskLoopDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPParallelMaskedTaskLoopSimdDirective::OMPParallelMaskedTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMaskedTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelMaskedTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMaskedTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMaskedTaskLoopSimdDirective)
OMPParallelMasterDirective::OMPParallelMasterDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMasterDirective)
::pasta::Expr OMPParallelMasterDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPParallelMasterDirective *>(u.OMPParallelMasterDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPParallelMasterDirective::TaskReductionReferenceExpression can return nullptr!");
}

OMPParallelMasterTaskLoopDirective::OMPParallelMasterTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMasterTaskLoopDirective)
bool OMPParallelMasterTaskLoopDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPParallelMasterTaskLoopDirective *>(u.OMPParallelMasterTaskLoopDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPParallelMasterTaskLoopSimdDirective::OMPParallelMasterTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPParallelMasterTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelMasterTaskLoopSimdDirective)
OMPParallelSectionsDirective::OMPParallelSectionsDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPParallelSectionsDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPParallelSectionsDirective)
::pasta::Expr OMPParallelSectionsDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPParallelSectionsDirective *>(u.OMPParallelSectionsDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPParallelSectionsDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPParallelSectionsDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPParallelSectionsDirective *>(u.OMPParallelSectionsDirective);
  decltype(auto) val = self.hasCancel();
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
  auto &self = *const_cast<clang::OMPSectionDirective *>(u.OMPSectionDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPSectionsDirective::OMPSectionsDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPSectionsDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPSectionsDirective)
::pasta::Expr OMPSectionsDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPSectionsDirective *>(u.OMPSectionsDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPSectionsDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPSectionsDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPSectionsDirective *>(u.OMPSectionsDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPSimdDirective::OMPSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPSimdDirective)
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
::pasta::Expr OMPTargetParallelDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPTargetParallelDirective *>(u.OMPTargetParallelDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPTargetParallelDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPTargetParallelDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPTargetParallelDirective *>(u.OMPTargetParallelDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPTargetParallelForDirective::OMPTargetParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetParallelForDirective)
::pasta::Expr OMPTargetParallelForDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPTargetParallelForDirective *>(u.OMPTargetParallelForDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPTargetParallelForDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPTargetParallelForDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPTargetParallelForDirective *>(u.OMPTargetParallelForDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPTargetParallelForSimdDirective::OMPTargetParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetParallelForSimdDirective)
OMPTargetParallelGenericLoopDirective::OMPTargetParallelGenericLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetParallelGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetParallelGenericLoopDirective)
OMPTargetSimdDirective::OMPTargetSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetSimdDirective)
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
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeDirective)
OMPTargetTeamsDistributeParallelForDirective::OMPTargetTeamsDistributeParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForDirective)
::pasta::Expr OMPTargetTeamsDistributeParallelForDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPTargetTeamsDistributeParallelForDirective *>(u.OMPTargetTeamsDistributeParallelForDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPTargetTeamsDistributeParallelForDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPTargetTeamsDistributeParallelForDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPTargetTeamsDistributeParallelForDirective *>(u.OMPTargetTeamsDistributeParallelForDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPTargetTeamsDistributeParallelForSimdDirective::OMPTargetTeamsDistributeParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeParallelForSimdDirective)
OMPTargetTeamsDistributeSimdDirective::OMPTargetTeamsDistributeSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsDistributeSimdDirective)
OMPTargetTeamsGenericLoopDirective::OMPTargetTeamsGenericLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTargetTeamsGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTargetTeamsGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTargetTeamsGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTargetTeamsGenericLoopDirective)
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
  auto &self = *const_cast<clang::OMPTaskDirective *>(u.OMPTaskDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPTaskLoopDirective::OMPTaskLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTaskLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskLoopDirective)
bool OMPTaskLoopDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPTaskLoopDirective *>(u.OMPTaskLoopDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPTaskLoopSimdDirective::OMPTaskLoopSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTaskLoopSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskLoopSimdDirective)
OMPTaskgroupDirective::OMPTaskgroupDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTaskgroupDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTaskgroupDirective)
::pasta::Expr OMPTaskgroupDirective::ReductionReference(void) const {
  auto &self = *const_cast<clang::OMPTaskgroupDirective *>(u.OMPTaskgroupDirective);
  decltype(auto) val = self.getReductionRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPTaskgroupDirective::ReductionReference can return nullptr!");
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
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeDirective)
OMPTeamsDistributeParallelForDirective::OMPTeamsDistributeParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeParallelForDirective)
::pasta::Expr OMPTeamsDistributeParallelForDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPTeamsDistributeParallelForDirective *>(u.OMPTeamsDistributeParallelForDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPTeamsDistributeParallelForDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPTeamsDistributeParallelForDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPTeamsDistributeParallelForDirective *>(u.OMPTeamsDistributeParallelForDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPTeamsDistributeParallelForSimdDirective::OMPTeamsDistributeParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeParallelForSimdDirective)
OMPTeamsDistributeSimdDirective::OMPTeamsDistributeSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsDistributeSimdDirective)
OMPTeamsGenericLoopDirective::OMPTeamsGenericLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTeamsGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTeamsGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPTeamsGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTeamsGenericLoopDirective)
OMPTileDirective::OMPTileDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopTransformationDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPTileDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPTileDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopTransformationDirective, OMPTileDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPTileDirective)
::pasta::Stmt OMPTileDirective::PreInitializers(void) const {
  auto &self = *const_cast<clang::OMPTileDirective *>(u.OMPTileDirective);
  decltype(auto) val = self.getPreInits();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPTileDirective::PreInitializers can return nullptr!");
}

::pasta::Stmt OMPTileDirective::TransformedStatement(void) const {
  auto &self = *const_cast<clang::OMPTileDirective *>(u.OMPTileDirective);
  decltype(auto) val = self.getTransformedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPTileDirective::TransformedStatement can return nullptr!");
}

OMPUnrollDirective::OMPUnrollDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopTransformationDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPUnrollDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPUnrollDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopTransformationDirective, OMPUnrollDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPUnrollDirective)
::pasta::Stmt OMPUnrollDirective::PreInitializers(void) const {
  auto &self = *const_cast<clang::OMPUnrollDirective *>(u.OMPUnrollDirective);
  decltype(auto) val = self.getPreInits();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPUnrollDirective::PreInitializers can return nullptr!");
}

::pasta::Stmt OMPUnrollDirective::TransformedStatement(void) const {
  auto &self = *const_cast<clang::OMPUnrollDirective *>(u.OMPUnrollDirective);
  decltype(auto) val = self.getTransformedStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("OMPUnrollDirective::TransformedStatement can return nullptr!");
}

ObjCArrayLiteral::ObjCArrayLiteral(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCArrayLiteral)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCArrayLiteral)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCArrayLiteral)
std::vector<::pasta::Stmt> ObjCArrayLiteral::Children(void) const {
  auto &self = *const_cast<clang::ObjCArrayLiteral *>(u.ObjCArrayLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::ObjCMethodDecl ObjCArrayLiteral::ArrayWithObjectsMethod(void) const {
  auto &self = *const_cast<clang::ObjCArrayLiteral *>(u.ObjCArrayLiteral);
  decltype(auto) val = self.getArrayWithObjectsMethod();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCArrayLiteral::ArrayWithObjectsMethod can return nullptr!");
}

::pasta::Token ObjCArrayLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCArrayLiteral *>(u.ObjCArrayLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: ObjCArrayLiteral::Element
// 0: ObjCArrayLiteral::Elements
::pasta::Token ObjCArrayLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCArrayLiteral *>(u.ObjCArrayLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCArrayLiteral::NumElements(void) const {
  auto &self = *const_cast<clang::ObjCArrayLiteral *>(u.ObjCArrayLiteral);
  decltype(auto) val = self.getNumElements();
  return val;
}

::pasta::TokenRange ObjCArrayLiteral::Tokens(void) const {
  auto &self = *const_cast<clang::ObjCArrayLiteral *>(u.ObjCArrayLiteral);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

std::vector<::pasta::Expr> ObjCArrayLiteral::Elements(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAtCatchStmt::AtCatchToken(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.getAtCatchLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtCatchStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCAtCatchStmt::CatchBody(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.getCatchBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ObjCAtCatchStmt::CatchBody can return nullptr!");
}

::pasta::VarDecl ObjCAtCatchStmt::CatchParameterDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.getCatchParamDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("ObjCAtCatchStmt::CatchParameterDeclaration can return nullptr!");
}

::pasta::Token ObjCAtCatchStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtCatchStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool ObjCAtCatchStmt::HasEllipsis(void) const {
  auto &self = *const_cast<clang::ObjCAtCatchStmt *>(u.ObjCAtCatchStmt);
  decltype(auto) val = self.hasEllipsis();
  return val;
}

ObjCAtFinallyStmt::ObjCAtFinallyStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtFinallyStmt)
std::vector<::pasta::Stmt> ObjCAtFinallyStmt::Children(void) const {
  auto &self = *const_cast<clang::ObjCAtFinallyStmt *>(u.ObjCAtFinallyStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAtFinallyStmt::AtFinallyToken(void) const {
  auto &self = *const_cast<clang::ObjCAtFinallyStmt *>(u.ObjCAtFinallyStmt);
  decltype(auto) val = self.getAtFinallyLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtFinallyStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAtFinallyStmt *>(u.ObjCAtFinallyStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtFinallyStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAtFinallyStmt *>(u.ObjCAtFinallyStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCAtFinallyStmt::FinallyBody(void) const {
  auto &self = *const_cast<clang::ObjCAtFinallyStmt *>(u.ObjCAtFinallyStmt);
  decltype(auto) val = self.getFinallyBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ObjCAtFinallyStmt::FinallyBody can return nullptr!");
}

ObjCAtSynchronizedStmt::ObjCAtSynchronizedStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtSynchronizedStmt)
std::vector<::pasta::Stmt> ObjCAtSynchronizedStmt::Children(void) const {
  auto &self = *const_cast<clang::ObjCAtSynchronizedStmt *>(u.ObjCAtSynchronizedStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAtSynchronizedStmt::AtSynchronizedToken(void) const {
  auto &self = *const_cast<clang::ObjCAtSynchronizedStmt *>(u.ObjCAtSynchronizedStmt);
  decltype(auto) val = self.getAtSynchronizedLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtSynchronizedStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAtSynchronizedStmt *>(u.ObjCAtSynchronizedStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtSynchronizedStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAtSynchronizedStmt *>(u.ObjCAtSynchronizedStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt ObjCAtSynchronizedStmt::SynchBody(void) const {
  auto &self = *const_cast<clang::ObjCAtSynchronizedStmt *>(u.ObjCAtSynchronizedStmt);
  decltype(auto) val = self.getSynchBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("ObjCAtSynchronizedStmt::SynchBody can return nullptr!");
}

::pasta::Expr ObjCAtSynchronizedStmt::SynchExpression(void) const {
  auto &self = *const_cast<clang::ObjCAtSynchronizedStmt *>(u.ObjCAtSynchronizedStmt);
  decltype(auto) val = self.getSynchExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCAtSynchronizedStmt::SynchExpression can return nullptr!");
}

ObjCAtThrowStmt::ObjCAtThrowStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtThrowStmt)
std::vector<::pasta::Stmt> ObjCAtThrowStmt::Children(void) const {
  auto &self = *const_cast<clang::ObjCAtThrowStmt *>(u.ObjCAtThrowStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAtThrowStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAtThrowStmt *>(u.ObjCAtThrowStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtThrowStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAtThrowStmt *>(u.ObjCAtThrowStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCAtThrowStmt::ThrowExpression(void) const {
  auto &self = *const_cast<clang::ObjCAtThrowStmt *>(u.ObjCAtThrowStmt);
  decltype(auto) val = self.getThrowExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCAtThrowStmt::ThrowExpression can return nullptr!");
}

::pasta::Token ObjCAtThrowStmt::ThrowToken(void) const {
  auto &self = *const_cast<clang::ObjCAtThrowStmt *>(u.ObjCAtThrowStmt);
  decltype(auto) val = self.getThrowLoc();
  return ast->TokenAt(val);
}

ObjCAtTryStmt::ObjCAtTryStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAtTryStmt)
// 0: ObjCAtTryStmt::CatchStatements
// 0: ObjCAtTryStmt::
// 0: ObjCAtTryStmt::
std::vector<::pasta::Stmt> ObjCAtTryStmt::Children(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAtTryStmt::AtTryToken(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.getAtTryLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAtTryStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: ObjCAtTryStmt::CatchStatement
::pasta::Token ObjCAtTryStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCAtFinallyStmt ObjCAtTryStmt::FinallyStatement(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.getFinallyStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::ObjCAtFinallyStmt>(ast, val);
  }
  throw std::runtime_error("ObjCAtTryStmt::FinallyStatement can return nullptr!");
}

uint32_t ObjCAtTryStmt::NumCatchStatements(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.getNumCatchStmts();
  return val;
}

::pasta::Stmt ObjCAtTryStmt::TryBody(void) const {
  auto &self = *const_cast<clang::ObjCAtTryStmt *>(u.ObjCAtTryStmt);
  decltype(auto) val = self.getTryBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ObjCAtTryStmt::TryBody can return nullptr!");
}

std::vector<::pasta::ObjCAtCatchStmt> ObjCAtTryStmt::CatchStatements(void) const {
  std::vector<::pasta::ObjCAtCatchStmt> ret;
  auto convert_elem = [&] (const clang::ObjCAtCatchStmt * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::ObjCAtCatchStmt>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::ObjCAutoreleasePoolStmt *>(u.ObjCAutoreleasePoolStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAutoreleasePoolStmt::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCAutoreleasePoolStmt *>(u.ObjCAutoreleasePoolStmt);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAutoreleasePoolStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAutoreleasePoolStmt *>(u.ObjCAutoreleasePoolStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAutoreleasePoolStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAutoreleasePoolStmt *>(u.ObjCAutoreleasePoolStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCAutoreleasePoolStmt::SubStatement(void) const {
  auto &self = *const_cast<clang::ObjCAutoreleasePoolStmt *>(u.ObjCAutoreleasePoolStmt);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ObjCAutoreleasePoolStmt::SubStatement can return nullptr!");
}

ObjCAvailabilityCheckExpr::ObjCAvailabilityCheckExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCAvailabilityCheckExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCAvailabilityCheckExpr)
std::vector<::pasta::Stmt> ObjCAvailabilityCheckExpr::Children(void) const {
  auto &self = *const_cast<clang::ObjCAvailabilityCheckExpr *>(u.ObjCAvailabilityCheckExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCAvailabilityCheckExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCAvailabilityCheckExpr *>(u.ObjCAvailabilityCheckExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCAvailabilityCheckExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCAvailabilityCheckExpr *>(u.ObjCAvailabilityCheckExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ObjCAvailabilityCheckExpr::Tokens(void) const {
  auto &self = *const_cast<clang::ObjCAvailabilityCheckExpr *>(u.ObjCAvailabilityCheckExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: ObjCAvailabilityCheckExpr::Version
bool ObjCAvailabilityCheckExpr::HasVersion(void) const {
  auto &self = *const_cast<clang::ObjCAvailabilityCheckExpr *>(u.ObjCAvailabilityCheckExpr);
  decltype(auto) val = self.hasVersion();
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
  auto &self = *const_cast<clang::ObjCBoolLiteralExpr *>(u.ObjCBoolLiteralExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCBoolLiteralExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCBoolLiteralExpr *>(u.ObjCBoolLiteralExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBoolLiteralExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCBoolLiteralExpr *>(u.ObjCBoolLiteralExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBoolLiteralExpr::Token(void) const {
  auto &self = *const_cast<clang::ObjCBoolLiteralExpr *>(u.ObjCBoolLiteralExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

bool ObjCBoolLiteralExpr::Value(void) const {
  auto &self = *const_cast<clang::ObjCBoolLiteralExpr *>(u.ObjCBoolLiteralExpr);
  decltype(auto) val = self.getValue();
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
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCBoxedExpr::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBoxedExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCBoxedExpr::BoxingMethod(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.getBoxingMethod();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCBoxedExpr::BoxingMethod can return nullptr!");
}

::pasta::Token ObjCBoxedExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ObjCBoxedExpr::Tokens(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Expr ObjCBoxedExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCBoxedExpr::SubExpression can return nullptr!");
}

bool ObjCBoxedExpr::IsExpressibleAsConstantInitializer(void) const {
  auto &self = *const_cast<clang::ObjCBoxedExpr *>(u.ObjCBoxedExpr);
  decltype(auto) val = self.isExpressibleAsConstantInitializer();
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
  auto &self = *const_cast<clang::ObjCDictionaryLiteral *>(u.ObjCDictionaryLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCDictionaryLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCDictionaryLiteral *>(u.ObjCDictionaryLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCDictionaryLiteral::DictionaryWithObjectsMethod(void) const {
  auto &self = *const_cast<clang::ObjCDictionaryLiteral *>(u.ObjCDictionaryLiteral);
  decltype(auto) val = self.getDictWithObjectsMethod();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCDictionaryLiteral::DictionaryWithObjectsMethod can return nullptr!");
}

::pasta::Token ObjCDictionaryLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCDictionaryLiteral *>(u.ObjCDictionaryLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: ObjCDictionaryLiteral::KeyValueElement
uint32_t ObjCDictionaryLiteral::NumElements(void) const {
  auto &self = *const_cast<clang::ObjCDictionaryLiteral *>(u.ObjCDictionaryLiteral);
  decltype(auto) val = self.getNumElements();
  return val;
}

::pasta::TokenRange ObjCDictionaryLiteral::Tokens(void) const {
  auto &self = *const_cast<clang::ObjCDictionaryLiteral *>(u.ObjCDictionaryLiteral);
  decltype(auto) val = self.getSourceRange();
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
  auto &self = *const_cast<clang::ObjCEncodeExpr *>(u.ObjCEncodeExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCEncodeExpr::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCEncodeExpr *>(u.ObjCEncodeExpr);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCEncodeExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCEncodeExpr *>(u.ObjCEncodeExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCEncodeExpr::EncodedType(void) const {
  auto &self = *const_cast<clang::ObjCEncodeExpr *>(u.ObjCEncodeExpr);
  decltype(auto) val = self.getEncodedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCEncodeExpr::
::pasta::Token ObjCEncodeExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCEncodeExpr *>(u.ObjCEncodeExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCEncodeExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ObjCEncodeExpr *>(u.ObjCEncodeExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

ObjCForCollectionStmt::ObjCForCollectionStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCForCollectionStmt)
std::vector<::pasta::Stmt> ObjCForCollectionStmt::Children(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCForCollectionStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCForCollectionStmt::Body(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ObjCForCollectionStmt::Body can return nullptr!");
}

::pasta::Expr ObjCForCollectionStmt::Collection(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getCollection();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCForCollectionStmt::Collection can return nullptr!");
}

::pasta::Stmt ObjCForCollectionStmt::Element(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getElement();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("ObjCForCollectionStmt::Element can return nullptr!");
}

::pasta::Token ObjCForCollectionStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCForCollectionStmt::ForToken(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getForLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCForCollectionStmt::RParenToken(void) const {
  auto &self = *const_cast<clang::ObjCForCollectionStmt *>(u.ObjCForCollectionStmt);
  decltype(auto) val = self.getRParenLoc();
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
  auto &self = *const_cast<clang::ObjCIndirectCopyRestoreExpr *>(u.ObjCIndirectCopyRestoreExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCIndirectCopyRestoreExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCIndirectCopyRestoreExpr *>(u.ObjCIndirectCopyRestoreExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIndirectCopyRestoreExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCIndirectCopyRestoreExpr *>(u.ObjCIndirectCopyRestoreExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIndirectCopyRestoreExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::ObjCIndirectCopyRestoreExpr *>(u.ObjCIndirectCopyRestoreExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCIndirectCopyRestoreExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::ObjCIndirectCopyRestoreExpr *>(u.ObjCIndirectCopyRestoreExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCIndirectCopyRestoreExpr::SubExpression can return nullptr!");
}

bool ObjCIndirectCopyRestoreExpr::ShouldCopy(void) const {
  auto &self = *const_cast<clang::ObjCIndirectCopyRestoreExpr *>(u.ObjCIndirectCopyRestoreExpr);
  decltype(auto) val = self.shouldCopy();
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
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr ObjCIsaExpr::Base(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCIsaExpr::Base can return nullptr!");
}

::pasta::Token ObjCIsaExpr::BaseTokenEnd(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getBaseLocEnd();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::IsaMemberToken(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getIsaMemberLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIsaExpr::OperationToken(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.getOpLoc();
  return ast->TokenAt(val);
}

bool ObjCIsaExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::ObjCIsaExpr *>(u.ObjCIsaExpr);
  decltype(auto) val = self.isArrow();
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
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr ObjCIvarRefExpr::Base(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCIvarRefExpr::Base can return nullptr!");
}

::pasta::Token ObjCIvarRefExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCIvarDecl ObjCIvarRefExpr::Declaration(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  throw std::runtime_error("ObjCIvarRefExpr::Declaration can return nullptr!");
}

::pasta::Token ObjCIvarRefExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIvarRefExpr::Token(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Token ObjCIvarRefExpr::OperationToken(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.getOpLoc();
  return ast->TokenAt(val);
}

bool ObjCIvarRefExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.isArrow();
  return val;
}

bool ObjCIvarRefExpr::IsFreeInstanceVariable(void) const {
  auto &self = *const_cast<clang::ObjCIvarRefExpr *>(u.ObjCIvarRefExpr);
  decltype(auto) val = self.isFreeIvar();
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
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Stmt> ObjCMessageExpr::Children(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 1: ObjCMessageExpr::Argument
// 0: ObjCMessageExpr::Arguments
::pasta::Token ObjCMessageExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCMessageExpr::CallReturnType(void) const {
  auto &self = *(u.ObjCMessageExpr);
  decltype(auto) val = self.getCallReturnType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ObjCMessageExpr::ClassReceiver(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getClassReceiver();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCMessageExpr::
::pasta::Token ObjCMessageExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCMessageExpr::InstanceReceiver(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getInstanceReceiver();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCMessageExpr::InstanceReceiver can return nullptr!");
}

::pasta::Token ObjCMessageExpr::LeftToken(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getLeftLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCMessageExpr::MethodDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMessageExpr::MethodDeclaration can return nullptr!");
}

enum ObjCMethodFamily ObjCMessageExpr::MethodFamily(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getMethodFamily();
  return static_cast<::pasta::ObjCMethodFamily>(val);
}

uint32_t ObjCMessageExpr::NumArguments(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getNumArgs();
  return val;
}

uint32_t ObjCMessageExpr::NumSelectorTokens(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getNumSelectorLocs();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCMessageExpr::ReceiverInterface(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getReceiverInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMessageExpr::ReceiverInterface can return nullptr!");
}

enum ObjCMessageExprReceiverKind ObjCMessageExpr::ReceiverKind(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getReceiverKind();
  return static_cast<::pasta::ObjCMessageExprReceiverKind>(val);
}

::pasta::TokenRange ObjCMessageExpr::ReceiverRange(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getReceiverRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type ObjCMessageExpr::ReceiverType(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getReceiverType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Token ObjCMessageExpr::RightToken(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getRightLoc();
  return ast->TokenAt(val);
}

// 0: ObjCMessageExpr::Selector
// 1: ObjCMessageExpr::SelectorToken
::pasta::Token ObjCMessageExpr::SelectorStartToken(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getSelectorStartLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCMessageExpr::SuperToken(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getSuperLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCMessageExpr::SuperType(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.getSuperType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool ObjCMessageExpr::IsClassMessage(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.isClassMessage();
  return val;
}

bool ObjCMessageExpr::IsDelegateInitializerCall(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.isDelegateInitCall();
  return val;
}

bool ObjCMessageExpr::IsImplicit(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.isImplicit();
  return val;
}

bool ObjCMessageExpr::IsInstanceMessage(void) const {
  auto &self = *const_cast<clang::ObjCMessageExpr *>(u.ObjCMessageExpr);
  decltype(auto) val = self.isInstanceMessage();
  return val;
}

std::vector<::pasta::Token> ObjCMessageExpr::SelectorTokens(void) const {
  std::vector<::pasta::Token> ret;
  auto convert_elem = [&] (clang::SourceLocation val) {
    return ast->TokenAt(val);
  };
  auto count = u.ObjCMessageExpr->getNumSelectorLocs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCMessageExpr->getSelectorLoc(i)));
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
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr ObjCPropertyRefExpr::Base(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyRefExpr::Base can return nullptr!");
}

::pasta::Token ObjCPropertyRefExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCInterfaceDecl ObjCPropertyRefExpr::ClassReceiver(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getClassReceiver();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyRefExpr::ClassReceiver can return nullptr!");
}

::pasta::Token ObjCPropertyRefExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCPropertyDecl ObjCPropertyRefExpr::ExplicitProperty(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getExplicitProperty();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyRefExpr::ExplicitProperty can return nullptr!");
}

// 0: ObjCPropertyRefExpr::GetterSelector
::pasta::ObjCMethodDecl ObjCPropertyRefExpr::ImplicitPropertyGetter(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getImplicitPropertyGetter();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyRefExpr::ImplicitPropertyGetter can return nullptr!");
}

::pasta::ObjCMethodDecl ObjCPropertyRefExpr::ImplicitPropertySetter(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getImplicitPropertySetter();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyRefExpr::ImplicitPropertySetter can return nullptr!");
}

::pasta::Token ObjCPropertyRefExpr::Token(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Token ObjCPropertyRefExpr::ReceiverToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getReceiverLocation();
  return ast->TokenAt(val);
}

::pasta::Type ObjCPropertyRefExpr::ReceiverType(void) const {
  auto &self = *(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getReceiverType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCPropertyRefExpr::SetterSelector
::pasta::Type ObjCPropertyRefExpr::SuperReceiverType(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.getSuperReceiverType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool ObjCPropertyRefExpr::IsClassReceiver(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isClassReceiver();
  return val;
}

bool ObjCPropertyRefExpr::IsExplicitProperty(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isExplicitProperty();
  return val;
}

bool ObjCPropertyRefExpr::IsImplicitProperty(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isImplicitProperty();
  return val;
}

bool ObjCPropertyRefExpr::IsMessagingGetter(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isMessagingGetter();
  return val;
}

bool ObjCPropertyRefExpr::IsMessagingSetter(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isMessagingSetter();
  return val;
}

bool ObjCPropertyRefExpr::IsObjectReceiver(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isObjectReceiver();
  return val;
}

bool ObjCPropertyRefExpr::IsSuperReceiver(void) const {
  auto &self = *const_cast<clang::ObjCPropertyRefExpr *>(u.ObjCPropertyRefExpr);
  decltype(auto) val = self.isSuperReceiver();
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
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCProtocolExpr::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCProtocolExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCProtocolExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCProtocolDecl ObjCProtocolExpr::Protocol(void) const {
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.getProtocol();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  throw std::runtime_error("ObjCProtocolExpr::Protocol can return nullptr!");
}

::pasta::Token ObjCProtocolExpr::ProtocolIdToken(void) const {
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.getProtocolIdLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCProtocolExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ObjCProtocolExpr *>(u.ObjCProtocolExpr);
  decltype(auto) val = self.getRParenLoc();
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
  auto &self = *const_cast<clang::ObjCSelectorExpr *>(u.ObjCSelectorExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCSelectorExpr::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCSelectorExpr *>(u.ObjCSelectorExpr);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCSelectorExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCSelectorExpr *>(u.ObjCSelectorExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCSelectorExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCSelectorExpr *>(u.ObjCSelectorExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCSelectorExpr::NumArguments(void) const {
  auto &self = *const_cast<clang::ObjCSelectorExpr *>(u.ObjCSelectorExpr);
  decltype(auto) val = self.getNumArgs();
  return val;
}

::pasta::Token ObjCSelectorExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ObjCSelectorExpr *>(u.ObjCSelectorExpr);
  decltype(auto) val = self.getRParenLoc();
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
  auto &self = *const_cast<clang::ObjCStringLiteral *>(u.ObjCStringLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ObjCStringLiteral::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCStringLiteral *>(u.ObjCStringLiteral);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCStringLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCStringLiteral *>(u.ObjCStringLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCStringLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCStringLiteral *>(u.ObjCStringLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::StringLiteral ObjCStringLiteral::String(void) const {
  auto &self = *const_cast<clang::ObjCStringLiteral *>(u.ObjCStringLiteral);
  decltype(auto) val = self.getString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  throw std::runtime_error("ObjCStringLiteral::String can return nullptr!");
}

ObjCSubscriptRefExpr::ObjCSubscriptRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ObjCSubscriptRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ObjCSubscriptRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ObjCSubscriptRefExpr)
std::vector<::pasta::Stmt> ObjCSubscriptRefExpr::Children(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::ObjCMethodDecl ObjCSubscriptRefExpr::AtIndexMethodDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.getAtIndexMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCSubscriptRefExpr::AtIndexMethodDeclaration can return nullptr!");
}

::pasta::Expr ObjCSubscriptRefExpr::BaseExpression(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.getBaseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCSubscriptRefExpr::BaseExpression can return nullptr!");
}

::pasta::Token ObjCSubscriptRefExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCSubscriptRefExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCSubscriptRefExpr::KeyExpression(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.getKeyExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCSubscriptRefExpr::KeyExpression can return nullptr!");
}

::pasta::Token ObjCSubscriptRefExpr::RBracketToken(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.getRBracket();
  return ast->TokenAt(val);
}

bool ObjCSubscriptRefExpr::IsArraySubscriptReferenceExpression(void) const {
  auto &self = *const_cast<clang::ObjCSubscriptRefExpr *>(u.ObjCSubscriptRefExpr);
  decltype(auto) val = self.isArraySubscriptRefExpr();
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
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token OffsetOfExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 1: OffsetOfExpr::Component
::pasta::Token OffsetOfExpr::EndToken(void) const {
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: OffsetOfExpr::IndexExpression
uint32_t OffsetOfExpr::NumComponents(void) const {
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.getNumComponents();
  return val;
}

uint32_t OffsetOfExpr::NumExpressions(void) const {
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.getNumExpressions();
  return val;
}

::pasta::Token OffsetOfExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Token OffsetOfExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::OffsetOfExpr *>(u.OffsetOfExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: OffsetOfExpr::
OpaqueValueExpr::OpaqueValueExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, OpaqueValueExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OpaqueValueExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, OpaqueValueExpr)
std::vector<::pasta::Stmt> OpaqueValueExpr::Children(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token OpaqueValueExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token OpaqueValueExpr::EndToken(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token OpaqueValueExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token OpaqueValueExpr::Token(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Expr OpaqueValueExpr::SourceExpression(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.getSourceExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OpaqueValueExpr::SourceExpression can return nullptr!");
}

bool OpaqueValueExpr::IsUnique(void) const {
  auto &self = *const_cast<clang::OpaqueValueExpr *>(u.OpaqueValueExpr);
  decltype(auto) val = self.isUnique();
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
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

// 0: OverloadExpr::Name
// 0: OverloadExpr::NameInfo
::pasta::Token OverloadExpr::NameToken(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getNameLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::CXXRecordDecl> OverloadExpr::NamingClass(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getNamingClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

uint32_t OverloadExpr::NumDeclarations(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getNumDecls();
  return val;
}

uint32_t OverloadExpr::NumTemplateArguments(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getNumTemplateArgs();
  return val;
}

// 0: OverloadExpr::Qualifier
// 0: OverloadExpr::QualifierToken
::pasta::Token OverloadExpr::RAngleToken(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: OverloadExpr::TemplateArguments
::pasta::Token OverloadExpr::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool OverloadExpr::HasExplicitTemplateArguments(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
}

bool OverloadExpr::HasTemplateKeyword(void) const {
  auto &self = *const_cast<clang::OverloadExpr *>(u.OverloadExpr);
  decltype(auto) val = self.hasTemplateKeyword();
  return val;
}

// 0: OverloadExpr::TemplateArguments
PackExpansionExpr::PackExpansionExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, PackExpansionExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, PackExpansionExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, PackExpansionExpr)
std::vector<::pasta::Stmt> PackExpansionExpr::Children(void) const {
  auto &self = *const_cast<clang::PackExpansionExpr *>(u.PackExpansionExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token PackExpansionExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::PackExpansionExpr *>(u.PackExpansionExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token PackExpansionExpr::EllipsisToken(void) const {
  auto &self = *const_cast<clang::PackExpansionExpr *>(u.PackExpansionExpr);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::Token PackExpansionExpr::EndToken(void) const {
  auto &self = *const_cast<clang::PackExpansionExpr *>(u.PackExpansionExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<unsigned> PackExpansionExpr::NumExpansions(void) const {
  auto &self = *const_cast<clang::PackExpansionExpr *>(u.PackExpansionExpr);
  decltype(auto) val = self.getNumExpansions();
  if (val.has_value()) {
    return val.value();
  } else {
    return std::nullopt;
  }
}

::pasta::Expr PackExpansionExpr::Pattern(void) const {
  auto &self = *const_cast<clang::PackExpansionExpr *>(u.PackExpansionExpr);
  decltype(auto) val = self.getPattern();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("PackExpansionExpr::Pattern can return nullptr!");
}

ParenExpr::ParenExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ParenExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ParenExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ParenExpr)
std::vector<::pasta::Stmt> ParenExpr::Children(void) const {
  auto &self = *const_cast<clang::ParenExpr *>(u.ParenExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ParenExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ParenExpr *>(u.ParenExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ParenExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ParenExpr *>(u.ParenExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ParenExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::ParenExpr *>(u.ParenExpr);
  decltype(auto) val = self.getLParen();
  return ast->TokenAt(val);
}

::pasta::Token ParenExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ParenExpr *>(u.ParenExpr);
  decltype(auto) val = self.getRParen();
  return ast->TokenAt(val);
}

::pasta::Expr ParenExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::ParenExpr *>(u.ParenExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ParenExpr::SubExpression can return nullptr!");
}

ParenListExpr::ParenListExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ParenListExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ParenListExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ParenListExpr)
std::vector<::pasta::Stmt> ParenListExpr::Children(void) const {
  auto &self = *const_cast<clang::ParenListExpr *>(u.ParenListExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ParenListExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ParenListExpr *>(u.ParenListExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ParenListExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ParenListExpr *>(u.ParenListExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: ParenListExpr::Expression
::pasta::Token ParenListExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::ParenListExpr *>(u.ParenListExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

uint32_t ParenListExpr::NumExpressions(void) const {
  auto &self = *const_cast<clang::ParenListExpr *>(u.ParenListExpr);
  decltype(auto) val = self.getNumExprs();
  return val;
}

::pasta::Token ParenListExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ParenListExpr *>(u.ParenListExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::Expr> ParenListExpr::Expressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token PredefinedExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token PredefinedExpr::EndToken(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::StringLiteral PredefinedExpr::FunctionName(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.getFunctionName();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  throw std::runtime_error("PredefinedExpr::FunctionName can return nullptr!");
}

enum PredefinedExprIdentKind PredefinedExpr::IdentifierKind(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.getIdentKind();
  return static_cast<::pasta::PredefinedExprIdentKind>(val);
}

std::string_view PredefinedExpr::IdentifierKindName(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.getIdentKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token PredefinedExpr::Token(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

bool PredefinedExpr::IsTransparent(void) const {
  auto &self = *const_cast<clang::PredefinedExpr *>(u.PredefinedExpr);
  decltype(auto) val = self.isTransparent();
  return val;
}

PseudoObjectExpr::PseudoObjectExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, PseudoObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, PseudoObjectExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, PseudoObjectExpr)
std::vector<::pasta::Stmt> PseudoObjectExpr::Children(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token PseudoObjectExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token PseudoObjectExpr::EndToken(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token PseudoObjectExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

uint32_t PseudoObjectExpr::NumSemanticExpressions(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getNumSemanticExprs();
  return val;
}

::pasta::Expr PseudoObjectExpr::ResultExpression(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getResultExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("PseudoObjectExpr::ResultExpression can return nullptr!");
}

uint32_t PseudoObjectExpr::ResultExpressionIndex(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getResultExprIndex();
  return val;
}

// 1: PseudoObjectExpr::SemanticExpression
::pasta::Expr PseudoObjectExpr::SyntacticForm(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.getSyntacticForm();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("PseudoObjectExpr::SyntacticForm can return nullptr!");
}

std::vector<::pasta::Expr> PseudoObjectExpr::Semantics(void) const {
  auto &self = *const_cast<clang::PseudoObjectExpr *>(u.PseudoObjectExpr);
  decltype(auto) val = self.semantics();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: PseudoObjectExpr::
// 0: PseudoObjectExpr::
std::vector<::pasta::Expr> PseudoObjectExpr::SemanticExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::RecoveryExpr *>(u.RecoveryExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token RecoveryExpr::EndToken(void) const {
  auto &self = *const_cast<clang::RecoveryExpr *>(u.RecoveryExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::Expr> RecoveryExpr::SubExpressions(void) const {
  auto &self = *const_cast<clang::RecoveryExpr *>(u.RecoveryExpr);
  decltype(auto) val = self.subExpressions();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
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
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token RequiresExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::RequiresExprBodyDecl RequiresExpr::Body(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.getBody();
  if (val) {
    return DeclBuilder::Create<::pasta::RequiresExprBodyDecl>(ast, val);
  }
  throw std::runtime_error("RequiresExpr::Body can return nullptr!");
}

::pasta::Token RequiresExpr::EndToken(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::ParmVarDecl> RequiresExpr::LocalParameters(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.getLocalParameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::Token RequiresExpr::RBraceToken(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

// 0: RequiresExpr::Requirements
::pasta::Token RequiresExpr::RequiresKeywordToken(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.getRequiresKWLoc();
  return ast->TokenAt(val);
}

bool RequiresExpr::IsSatisfied(void) const {
  auto &self = *const_cast<clang::RequiresExpr *>(u.RequiresExpr);
  decltype(auto) val = self.isSatisfied();
  return val;
}

ReturnStmt::ReturnStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, ReturnStmt)
std::vector<::pasta::Stmt> ReturnStmt::Children(void) const {
  auto &self = *const_cast<clang::ReturnStmt *>(u.ReturnStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ReturnStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::ReturnStmt *>(u.ReturnStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ReturnStmt::EndToken(void) const {
  auto &self = *const_cast<clang::ReturnStmt *>(u.ReturnStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::VarDecl> ReturnStmt::NRVOCandidate(void) const {
  auto &self = *const_cast<clang::ReturnStmt *>(u.ReturnStmt);
  decltype(auto) val = self.getNRVOCandidate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

std::optional<::pasta::Expr> ReturnStmt::ReturnValue(void) const {
  auto &self = *const_cast<clang::ReturnStmt *>(u.ReturnStmt);
  decltype(auto) val = self.getRetValue();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Token ReturnStmt::ReturnToken(void) const {
  auto &self = *const_cast<clang::ReturnStmt *>(u.ReturnStmt);
  decltype(auto) val = self.getReturnLoc();
  return ast->TokenAt(val);
}

SEHExceptStmt::SEHExceptStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHExceptStmt)
std::vector<::pasta::Stmt> SEHExceptStmt::Children(void) const {
  auto &self = *const_cast<clang::SEHExceptStmt *>(u.SEHExceptStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SEHExceptStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::SEHExceptStmt *>(u.SEHExceptStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt SEHExceptStmt::Block(void) const {
  auto &self = *const_cast<clang::SEHExceptStmt *>(u.SEHExceptStmt);
  decltype(auto) val = self.getBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("SEHExceptStmt::Block can return nullptr!");
}

::pasta::Token SEHExceptStmt::EndToken(void) const {
  auto &self = *const_cast<clang::SEHExceptStmt *>(u.SEHExceptStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHExceptStmt::ExceptToken(void) const {
  auto &self = *const_cast<clang::SEHExceptStmt *>(u.SEHExceptStmt);
  decltype(auto) val = self.getExceptLoc();
  return ast->TokenAt(val);
}

::pasta::Expr SEHExceptStmt::FilterExpression(void) const {
  auto &self = *const_cast<clang::SEHExceptStmt *>(u.SEHExceptStmt);
  decltype(auto) val = self.getFilterExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("SEHExceptStmt::FilterExpression can return nullptr!");
}

SEHFinallyStmt::SEHFinallyStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHFinallyStmt)
std::vector<::pasta::Stmt> SEHFinallyStmt::Children(void) const {
  auto &self = *const_cast<clang::SEHFinallyStmt *>(u.SEHFinallyStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SEHFinallyStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::SEHFinallyStmt *>(u.SEHFinallyStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt SEHFinallyStmt::Block(void) const {
  auto &self = *const_cast<clang::SEHFinallyStmt *>(u.SEHFinallyStmt);
  decltype(auto) val = self.getBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("SEHFinallyStmt::Block can return nullptr!");
}

::pasta::Token SEHFinallyStmt::EndToken(void) const {
  auto &self = *const_cast<clang::SEHFinallyStmt *>(u.SEHFinallyStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHFinallyStmt::FinallyToken(void) const {
  auto &self = *const_cast<clang::SEHFinallyStmt *>(u.SEHFinallyStmt);
  decltype(auto) val = self.getFinallyLoc();
  return ast->TokenAt(val);
}

SEHLeaveStmt::SEHLeaveStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHLeaveStmt)
std::vector<::pasta::Stmt> SEHLeaveStmt::Children(void) const {
  auto &self = *const_cast<clang::SEHLeaveStmt *>(u.SEHLeaveStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SEHLeaveStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::SEHLeaveStmt *>(u.SEHLeaveStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHLeaveStmt::EndToken(void) const {
  auto &self = *const_cast<clang::SEHLeaveStmt *>(u.SEHLeaveStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHLeaveStmt::LeaveToken(void) const {
  auto &self = *const_cast<clang::SEHLeaveStmt *>(u.SEHLeaveStmt);
  decltype(auto) val = self.getLeaveLoc();
  return ast->TokenAt(val);
}

SEHTryStmt::SEHTryStmt(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Stmt, SEHTryStmt)
std::vector<::pasta::Stmt> SEHTryStmt::Children(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SEHTryStmt::BeginToken(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SEHTryStmt::EndToken(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::SEHExceptStmt SEHTryStmt::ExceptHandler(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getExceptHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::SEHExceptStmt>(ast, val);
  }
  throw std::runtime_error("SEHTryStmt::ExceptHandler can return nullptr!");
}

::pasta::SEHFinallyStmt SEHTryStmt::FinallyHandler(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getFinallyHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::SEHFinallyStmt>(ast, val);
  }
  throw std::runtime_error("SEHTryStmt::FinallyHandler can return nullptr!");
}

::pasta::Stmt SEHTryStmt::Handler(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getHandler();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("SEHTryStmt::Handler can return nullptr!");
}

bool SEHTryStmt::IsCXXTry(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getIsCXXTry();
  return val;
}

::pasta::CompoundStmt SEHTryStmt::TryBlock(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getTryBlock();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("SEHTryStmt::TryBlock can return nullptr!");
}

::pasta::Token SEHTryStmt::TryToken(void) const {
  auto &self = *const_cast<clang::SEHTryStmt *>(u.SEHTryStmt);
  decltype(auto) val = self.getTryLoc();
  return ast->TokenAt(val);
}

SYCLUniqueStableNameExpr::SYCLUniqueStableNameExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, SYCLUniqueStableNameExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, SYCLUniqueStableNameExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, SYCLUniqueStableNameExpr)
std::string SYCLUniqueStableNameExpr::ComputeName(void) const {
  auto &self = *(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.ComputeName(ast->ci->getASTContext());
  return val;
}

std::vector<::pasta::Stmt> SYCLUniqueStableNameExpr::Children(void) const {
  auto &self = *const_cast<clang::SYCLUniqueStableNameExpr *>(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SYCLUniqueStableNameExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::SYCLUniqueStableNameExpr *>(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SYCLUniqueStableNameExpr::EndToken(void) const {
  auto &self = *const_cast<clang::SYCLUniqueStableNameExpr *>(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SYCLUniqueStableNameExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::SYCLUniqueStableNameExpr *>(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.getLParenLocation();
  return ast->TokenAt(val);
}

::pasta::Token SYCLUniqueStableNameExpr::Token(void) const {
  auto &self = *const_cast<clang::SYCLUniqueStableNameExpr *>(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::Token SYCLUniqueStableNameExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::SYCLUniqueStableNameExpr *>(u.SYCLUniqueStableNameExpr);
  decltype(auto) val = self.getRParenLocation();
  return ast->TokenAt(val);
}

// 0: SYCLUniqueStableNameExpr::
ShuffleVectorExpr::ShuffleVectorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ShuffleVectorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ShuffleVectorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ShuffleVectorExpr)
std::vector<::pasta::Stmt> ShuffleVectorExpr::Children(void) const {
  auto &self = *const_cast<clang::ShuffleVectorExpr *>(u.ShuffleVectorExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ShuffleVectorExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ShuffleVectorExpr *>(u.ShuffleVectorExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ShuffleVectorExpr::BuiltinToken(void) const {
  auto &self = *const_cast<clang::ShuffleVectorExpr *>(u.ShuffleVectorExpr);
  decltype(auto) val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token ShuffleVectorExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ShuffleVectorExpr *>(u.ShuffleVectorExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 1: ShuffleVectorExpr::Expression
uint32_t ShuffleVectorExpr::NumSubExpressions(void) const {
  auto &self = *const_cast<clang::ShuffleVectorExpr *>(u.ShuffleVectorExpr);
  decltype(auto) val = self.getNumSubExprs();
  return val;
}

::pasta::Token ShuffleVectorExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ShuffleVectorExpr *>(u.ShuffleVectorExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 2: ShuffleMaskIndex
SizeOfPackExpr::SizeOfPackExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, SizeOfPackExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, SizeOfPackExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, SizeOfPackExpr)
std::vector<::pasta::Stmt> SizeOfPackExpr::Children(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SizeOfPackExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SizeOfPackExpr::EndToken(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token SizeOfPackExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl SizeOfPackExpr::Pack(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.getPack();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("SizeOfPackExpr::Pack can return nullptr!");
}

std::optional<uint32_t> SizeOfPackExpr::PackLength(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  if (self.isValueDependent()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getPackLength();
  return val;
}

::pasta::Token SizeOfPackExpr::PackToken(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.getPackLoc();
  return ast->TokenAt(val);
}

std::optional<std::vector<::pasta::TemplateArgument>> SizeOfPackExpr::PartialArguments(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  if (!self.isPartiallySubstituted()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getPartialArguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
}

::pasta::Token SizeOfPackExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool SizeOfPackExpr::IsPartiallySubstituted(void) const {
  auto &self = *const_cast<clang::SizeOfPackExpr *>(u.SizeOfPackExpr);
  decltype(auto) val = self.isPartiallySubstituted();
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
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token SourceLocExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::string_view SourceLocExpr::BuiltinString(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.getBuiltinStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token SourceLocExpr::EndToken(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum SourceLocExprIdentKind SourceLocExpr::IdentifierKind(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.getIdentKind();
  return static_cast<::pasta::SourceLocExprIdentKind>(val);
}

::pasta::Token SourceLocExpr::Token(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

::pasta::DeclContext SourceLocExpr::ParentContext(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.getParentContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("SourceLocExpr::ParentContext can return nullptr!");
}

bool SourceLocExpr::IsIntType(void) const {
  auto &self = *const_cast<clang::SourceLocExpr *>(u.SourceLocExpr);
  decltype(auto) val = self.isIntType();
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
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token StmtExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token StmtExpr::EndToken(void) const {
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token StmtExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token StmtExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt StmtExpr::SubStatement(void) const {
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.getSubStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("StmtExpr::SubStatement can return nullptr!");
}

uint32_t StmtExpr::TemplateDepth(void) const {
  auto &self = *const_cast<clang::StmtExpr *>(u.StmtExpr);
  decltype(auto) val = self.getTemplateDepth();
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
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::optional<bool> StringLiteral::ContainsNonAscii(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  if (self.getCharByteWidth() > 1) {
     return std::nullopt;
  }
  decltype(auto) val = self.containsNonAscii();
  return val;
}

std::optional<bool> StringLiteral::ContainsNonAsciiOrNull(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  if (self.getCharByteWidth() > 1) {
     return std::nullopt;
  }
  decltype(auto) val = self.containsNonAsciiOrNull();
  return val;
}

::pasta::Token StringLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

uint32_t StringLiteral::ByteLength(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getByteLength();
  return val;
}

std::string_view StringLiteral::Bytes(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getBytes();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

uint32_t StringLiteral::CharacterByteWidth(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getCharByteWidth();
  return val;
}

// 1: StringLiteral::CodeUnit
::pasta::Token StringLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum StringLiteralStringKind StringLiteral::LiteralKind(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::StringLiteralStringKind>(val);
}

uint32_t StringLiteral::Length(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getLength();
  return val;
}

// 4: StringLiteral::TokenOfByte
uint32_t StringLiteral::NumConcatenated(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.getNumConcatenated();
  return val;
}

// 1: StringLiteral::StringTokenToken
std::optional<std::string_view> StringLiteral::String(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  if (self.getCharByteWidth() > 1) {
     return std::nullopt;
  }
  decltype(auto) val = self.getString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

bool StringLiteral::IsOrdinary(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isOrdinary();
  return val;
}

bool StringLiteral::IsPascal(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isPascal();
  return val;
}

bool StringLiteral::IsUTF16(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isUTF16();
  return val;
}

bool StringLiteral::IsUTF32(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isUTF32();
  return val;
}

bool StringLiteral::IsUTF8(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isUTF8();
  return val;
}

bool StringLiteral::IsUnevaluated(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isUnevaluated();
  return val;
}

bool StringLiteral::IsWide(void) const {
  auto &self = *const_cast<clang::StringLiteral *>(u.StringLiteral);
  decltype(auto) val = self.isWide();
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
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Decl SubstNonTypeTemplateParmExpr::AssociatedDeclaration(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getAssociatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  throw std::runtime_error("SubstNonTypeTemplateParmExpr::AssociatedDeclaration can return nullptr!");
}

::pasta::Token SubstNonTypeTemplateParmExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SubstNonTypeTemplateParmExpr::EndToken(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t SubstNonTypeTemplateParmExpr::Index(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getIndex();
  return val;
}

::pasta::Token SubstNonTypeTemplateParmExpr::NameToken(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getNameLoc();
  return ast->TokenAt(val);
}

std::optional<unsigned> SubstNonTypeTemplateParmExpr::PackIndex(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getPackIndex();
  if (val.has_value()) {
    return val.value();
  } else {
    return std::nullopt;
  }
}

::pasta::NonTypeTemplateParmDecl SubstNonTypeTemplateParmExpr::Parameter(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getParameter();
  if (val) {
    return DeclBuilder::Create<::pasta::NonTypeTemplateParmDecl>(ast, val);
  }
  throw std::runtime_error("SubstNonTypeTemplateParmExpr::Parameter can return nullptr!");
}

::pasta::Type SubstNonTypeTemplateParmExpr::ParameterType(void) const {
  auto &self = *(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getParameterType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr SubstNonTypeTemplateParmExpr::Replacement(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.getReplacement();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("SubstNonTypeTemplateParmExpr::Replacement can return nullptr!");
}

bool SubstNonTypeTemplateParmExpr::IsReferenceParameter(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmExpr *>(u.SubstNonTypeTemplateParmExpr);
  decltype(auto) val = self.isReferenceParameter();
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
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: SubstNonTypeTemplateParmPackExpr::ArgumentPack
::pasta::Decl SubstNonTypeTemplateParmPackExpr::AssociatedDeclaration(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.getAssociatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  throw std::runtime_error("SubstNonTypeTemplateParmPackExpr::AssociatedDeclaration can return nullptr!");
}

::pasta::Token SubstNonTypeTemplateParmPackExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token SubstNonTypeTemplateParmPackExpr::EndToken(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t SubstNonTypeTemplateParmPackExpr::Index(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.getIndex();
  return val;
}

::pasta::NonTypeTemplateParmDecl SubstNonTypeTemplateParmPackExpr::ParameterPack(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.getParameterPack();
  if (val) {
    return DeclBuilder::Create<::pasta::NonTypeTemplateParmDecl>(ast, val);
  }
  throw std::runtime_error("SubstNonTypeTemplateParmPackExpr::ParameterPack can return nullptr!");
}

::pasta::Token SubstNonTypeTemplateParmPackExpr::ParameterPackToken(void) const {
  auto &self = *const_cast<clang::SubstNonTypeTemplateParmPackExpr *>(u.SubstNonTypeTemplateParmPackExpr);
  decltype(auto) val = self.getParameterPackLocation();
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
  auto &self = *const_cast<clang::TypeTraitExpr *>(u.TypeTraitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 1: TypeTraitExpr::Argument
// 0: TypeTraitExpr::Arguments
::pasta::Token TypeTraitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::TypeTraitExpr *>(u.TypeTraitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token TypeTraitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::TypeTraitExpr *>(u.TypeTraitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t TypeTraitExpr::NumArguments(void) const {
  auto &self = *const_cast<clang::TypeTraitExpr *>(u.TypeTraitExpr);
  decltype(auto) val = self.getNumArgs();
  return val;
}

enum TypeTrait TypeTraitExpr::Trait(void) const {
  auto &self = *const_cast<clang::TypeTraitExpr *>(u.TypeTraitExpr);
  decltype(auto) val = self.getTrait();
  return static_cast<::pasta::TypeTrait>(val);
}

std::optional<bool> TypeTraitExpr::Value(void) const {
  auto &self = *const_cast<clang::TypeTraitExpr *>(u.TypeTraitExpr);
  if (self.isValueDependent()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getValue();
  return val;
}

std::vector<::pasta::Type> TypeTraitExpr::Arguments(void) const {
  std::vector<::pasta::Type> ret;
  auto convert_elem = [&] (clang::TypeSourceInfo * val) {
    return TypeBuilder::Build(ast, val->getType());
  };
  auto count = u.TypeTraitExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.TypeTraitExpr->getArg(i)));
  }
  return ret;
}

TypoExpr::TypoExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, TypoExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, TypoExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, TypoExpr)
std::vector<::pasta::Stmt> TypoExpr::Children(void) const {
  auto &self = *const_cast<clang::TypoExpr *>(u.TypoExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token TypoExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::TypoExpr *>(u.TypoExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token TypoExpr::EndToken(void) const {
  auto &self = *const_cast<clang::TypoExpr *>(u.TypoExpr);
  decltype(auto) val = self.getEndLoc();
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
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::optional<::pasta::Expr> UnaryExprOrTypeTraitExpr::ArgumentExpression(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  if (self.isArgumentType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getArgumentExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::optional<::pasta::Type> UnaryExprOrTypeTraitExpr::ArgumentType(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  if (!self.isArgumentType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getArgumentType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

// 0: UnaryExprOrTypeTraitExpr::
::pasta::Token UnaryExprOrTypeTraitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryExprOrTypeTraitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum UnaryExprOrTypeTrait UnaryExprOrTypeTraitExpr::KeywordKind(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::UnaryExprOrTypeTrait>(val);
}

::pasta::Token UnaryExprOrTypeTraitExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryExprOrTypeTraitExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Type UnaryExprOrTypeTraitExpr::TypeOfArgument(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.getTypeOfArgument();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool UnaryExprOrTypeTraitExpr::IsArgumentType(void) const {
  auto &self = *const_cast<clang::UnaryExprOrTypeTraitExpr *>(u.UnaryExprOrTypeTraitExpr);
  decltype(auto) val = self.isArgumentType();
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
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.canOverflow();
  return val;
}

std::vector<::pasta::Stmt> UnaryOperator::Children(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token UnaryOperator::BeginToken(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryOperator::EndToken(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnaryOperator::ExpressionToken(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 1: UnaryOperator::FPFeaturesInEffect
// 0: UnaryOperator::FPOptionsOverride
enum UnaryOperatorKind UnaryOperator::Opcode(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.getOpcode();
  return static_cast<::pasta::UnaryOperatorKind>(val);
}

::pasta::Token UnaryOperator::OperatorToken(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: UnaryOperator::StoredFPFeatures
::pasta::Expr UnaryOperator::SubExpression(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("UnaryOperator::SubExpression can return nullptr!");
}

bool UnaryOperator::HasStoredFPFeatures(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.hasStoredFPFeatures();
  return val;
}

bool UnaryOperator::IsArithmeticOperation(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.isArithmeticOp();
  return val;
}

bool UnaryOperator::IsDecrementOperation(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.isDecrementOp();
  return val;
}

// 1: UnaryOperator::IsFEnvAccessOn
// 1: UnaryOperator::IsFPContractableWithinStatement
bool UnaryOperator::IsIncrementDecrementOperation(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.isIncrementDecrementOp();
  return val;
}

bool UnaryOperator::IsIncrementOperation(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.isIncrementOp();
  return val;
}

bool UnaryOperator::IsPostfix(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.isPostfix();
  return val;
}

bool UnaryOperator::IsPrefix(void) const {
  auto &self = *const_cast<clang::UnaryOperator *>(u.UnaryOperator);
  decltype(auto) val = self.isPrefix();
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
  auto &self = *const_cast<clang::UnresolvedLookupExpr *>(u.UnresolvedLookupExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token UnresolvedLookupExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::UnresolvedLookupExpr *>(u.UnresolvedLookupExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedLookupExpr::EndToken(void) const {
  auto &self = *const_cast<clang::UnresolvedLookupExpr *>(u.UnresolvedLookupExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::CXXRecordDecl> UnresolvedLookupExpr::NamingClass(void) const {
  auto &self = *const_cast<clang::UnresolvedLookupExpr *>(u.UnresolvedLookupExpr);
  decltype(auto) val = self.getNamingClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

bool UnresolvedLookupExpr::IsOverloaded(void) const {
  auto &self = *const_cast<clang::UnresolvedLookupExpr *>(u.UnresolvedLookupExpr);
  decltype(auto) val = self.isOverloaded();
  return val;
}

bool UnresolvedLookupExpr::RequiresADL(void) const {
  auto &self = *const_cast<clang::UnresolvedLookupExpr *>(u.UnresolvedLookupExpr);
  decltype(auto) val = self.requiresADL();
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
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr UnresolvedMemberExpr::Base(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("UnresolvedMemberExpr::Base can return nullptr!");
}

::pasta::Type UnresolvedMemberExpr::BaseType(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getBaseType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Token UnresolvedMemberExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedMemberExpr::EndToken(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedMemberExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedMemberExpr::MemberToken(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getMemberLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedMemberExpr::MemberName
// 0: UnresolvedMemberExpr::MemberNameInfo
::pasta::CXXRecordDecl UnresolvedMemberExpr::NamingClass(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getNamingClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("UnresolvedMemberExpr::NamingClass can return nullptr!");
}

::pasta::Token UnresolvedMemberExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

bool UnresolvedMemberExpr::HasUnresolvedUsing(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.hasUnresolvedUsing();
  return val;
}

bool UnresolvedMemberExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.isArrow();
  return val;
}

bool UnresolvedMemberExpr::IsImplicitAccess(void) const {
  auto &self = *const_cast<clang::UnresolvedMemberExpr *>(u.UnresolvedMemberExpr);
  decltype(auto) val = self.isImplicitAccess();
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
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token VAArgExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token VAArgExpr::BuiltinToken(void) const {
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token VAArgExpr::EndToken(void) const {
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token VAArgExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr VAArgExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("VAArgExpr::SubExpression can return nullptr!");
}

// 0: VAArgExpr::
bool VAArgExpr::IsMicrosoftABI(void) const {
  auto &self = *const_cast<clang::VAArgExpr *>(u.VAArgExpr);
  decltype(auto) val = self.isMicrosoftABI();
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
  auto &self = *const_cast<clang::AbstractConditionalOperator *>(u.AbstractConditionalOperator);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AbstractConditionalOperator::Condition(void) const {
  auto &self = *const_cast<clang::AbstractConditionalOperator *>(u.AbstractConditionalOperator);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("AbstractConditionalOperator::Condition can return nullptr!");
}

::pasta::Expr AbstractConditionalOperator::FalseExpression(void) const {
  auto &self = *const_cast<clang::AbstractConditionalOperator *>(u.AbstractConditionalOperator);
  decltype(auto) val = self.getFalseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("AbstractConditionalOperator::FalseExpression can return nullptr!");
}

::pasta::Token AbstractConditionalOperator::QuestionToken(void) const {
  auto &self = *const_cast<clang::AbstractConditionalOperator *>(u.AbstractConditionalOperator);
  decltype(auto) val = self.getQuestionLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AbstractConditionalOperator::TrueExpression(void) const {
  auto &self = *const_cast<clang::AbstractConditionalOperator *>(u.AbstractConditionalOperator);
  decltype(auto) val = self.getTrueExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("AbstractConditionalOperator::TrueExpression can return nullptr!");
}

AddrLabelExpr::AddrLabelExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, AddrLabelExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, AddrLabelExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AddrLabelExpr)
std::vector<::pasta::Stmt> AddrLabelExpr::Children(void) const {
  auto &self = *const_cast<clang::AddrLabelExpr *>(u.AddrLabelExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token AddrLabelExpr::AmpAmpToken(void) const {
  auto &self = *const_cast<clang::AddrLabelExpr *>(u.AddrLabelExpr);
  decltype(auto) val = self.getAmpAmpLoc();
  return ast->TokenAt(val);
}

::pasta::Token AddrLabelExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::AddrLabelExpr *>(u.AddrLabelExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AddrLabelExpr::EndToken(void) const {
  auto &self = *const_cast<clang::AddrLabelExpr *>(u.AddrLabelExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::LabelDecl AddrLabelExpr::Label(void) const {
  auto &self = *const_cast<clang::AddrLabelExpr *>(u.AddrLabelExpr);
  decltype(auto) val = self.getLabel();
  if (val) {
    return DeclBuilder::Create<::pasta::LabelDecl>(ast, val);
  }
  throw std::runtime_error("AddrLabelExpr::Label can return nullptr!");
}

::pasta::Token AddrLabelExpr::LabelToken(void) const {
  auto &self = *const_cast<clang::AddrLabelExpr *>(u.AddrLabelExpr);
  decltype(auto) val = self.getLabelLoc();
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
  auto &self = *const_cast<clang::ArrayInitIndexExpr *>(u.ArrayInitIndexExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ArrayInitIndexExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ArrayInitIndexExpr *>(u.ArrayInitIndexExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ArrayInitIndexExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ArrayInitIndexExpr *>(u.ArrayInitIndexExpr);
  decltype(auto) val = self.getEndLoc();
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
  auto &self = *const_cast<clang::ArrayInitLoopExpr *>(u.ArrayInitLoopExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

llvm::APInt ArrayInitLoopExpr::ArraySize(void) const {
  auto &self = *const_cast<clang::ArrayInitLoopExpr *>(u.ArrayInitLoopExpr);
  decltype(auto) val = self.getArraySize();
  return val;
}

::pasta::Token ArrayInitLoopExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ArrayInitLoopExpr *>(u.ArrayInitLoopExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::OpaqueValueExpr ArrayInitLoopExpr::CommonExpression(void) const {
  auto &self = *const_cast<clang::ArrayInitLoopExpr *>(u.ArrayInitLoopExpr);
  decltype(auto) val = self.getCommonExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::OpaqueValueExpr>(ast, val);
  }
  throw std::runtime_error("ArrayInitLoopExpr::CommonExpression can return nullptr!");
}

::pasta::Token ArrayInitLoopExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ArrayInitLoopExpr *>(u.ArrayInitLoopExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArrayInitLoopExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::ArrayInitLoopExpr *>(u.ArrayInitLoopExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ArrayInitLoopExpr::SubExpression can return nullptr!");
}

ArraySubscriptExpr::ArraySubscriptExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ArraySubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ArraySubscriptExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ArraySubscriptExpr)
std::vector<::pasta::Stmt> ArraySubscriptExpr::Children(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr ArraySubscriptExpr::Base(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ArraySubscriptExpr::Base can return nullptr!");
}

::pasta::Token ArraySubscriptExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ArraySubscriptExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ArraySubscriptExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArraySubscriptExpr::Index(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getIdx();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ArraySubscriptExpr::Index can return nullptr!");
}

::pasta::Expr ArraySubscriptExpr::LHS(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ArraySubscriptExpr::LHS can return nullptr!");
}

::pasta::Token ArraySubscriptExpr::RBracketToken(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getRBracketLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArraySubscriptExpr::RHS(void) const {
  auto &self = *const_cast<clang::ArraySubscriptExpr *>(u.ArraySubscriptExpr);
  decltype(auto) val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ArraySubscriptExpr::RHS can return nullptr!");
}

ArrayTypeTraitExpr::ArrayTypeTraitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ArrayTypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ArrayTypeTraitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ArrayTypeTraitExpr)
std::vector<::pasta::Stmt> ArrayTypeTraitExpr::Children(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ArrayTypeTraitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ArrayTypeTraitExpr::DimensionExpression(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.getDimensionExpression();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ArrayTypeTraitExpr::DimensionExpression can return nullptr!");
}

::pasta::Token ArrayTypeTraitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Type ArrayTypeTraitExpr::QueriedType(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.getQueriedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: ArrayTypeTraitExpr::
enum ArrayTypeTrait ArrayTypeTraitExpr::Trait(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.getTrait();
  return static_cast<::pasta::ArrayTypeTrait>(val);
}

uint64_t ArrayTypeTraitExpr::Value(void) const {
  auto &self = *const_cast<clang::ArrayTypeTraitExpr *>(u.ArrayTypeTraitExpr);
  decltype(auto) val = self.getValue();
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
  auto &self = *const_cast<clang::AsTypeExpr *>(u.AsTypeExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token AsTypeExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::AsTypeExpr *>(u.AsTypeExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsTypeExpr::BuiltinToken(void) const {
  auto &self = *const_cast<clang::AsTypeExpr *>(u.AsTypeExpr);
  decltype(auto) val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsTypeExpr::EndToken(void) const {
  auto &self = *const_cast<clang::AsTypeExpr *>(u.AsTypeExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token AsTypeExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::AsTypeExpr *>(u.AsTypeExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr AsTypeExpr::SrcExpression(void) const {
  auto &self = *const_cast<clang::AsTypeExpr *>(u.AsTypeExpr);
  decltype(auto) val = self.getSrcExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("AsTypeExpr::SrcExpression can return nullptr!");
}

AtomicExpr::AtomicExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, AtomicExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, AtomicExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, AtomicExpr)
std::vector<::pasta::Stmt> AtomicExpr::Children(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token AtomicExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token AtomicExpr::BuiltinToken(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token AtomicExpr::EndToken(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t AtomicExpr::NumSubExpressions(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getNumSubExprs();
  return val;
}

enum AtomicExprAtomicOp AtomicExpr::Operation(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getOp();
  return static_cast<::pasta::AtomicExprAtomicOp>(val);
}

::pasta::Expr AtomicExpr::Order(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getOrder();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("AtomicExpr::Order can return nullptr!");
}

std::optional<::pasta::Expr> AtomicExpr::OrderFail(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  if (self.getNumSubExprs() <= 3 /* ORDER_FAIL */) {
    return std::nullopt;
  }
  decltype(auto) val = self.getOrderFail();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Expr AtomicExpr::Pointer(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getPtr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("AtomicExpr::Pointer can return nullptr!");
}

::pasta::Token AtomicExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> AtomicExpr::Scope(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  if (self.getOp() < clang::AtomicExpr::AO__opencl_atomic_load ||
      self.getOp() > clang::AtomicExpr::AO__opencl_atomic_fetch_max) {
    return std::nullopt;
  }
  decltype(auto) val = self.getScope();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

// 0: AtomicExpr::ScopeModel
// 0: AtomicExpr::SubExpressions
std::optional<::pasta::Expr> AtomicExpr::Value1(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  if (self.getOp() != clang::AtomicExpr::AO__c11_atomic_init &&
      self.getOp() != clang::AtomicExpr::AO__opencl_atomic_init &&
      self.getNumSubExprs() <= 2 /* VAL1 */) {
    return std::nullopt;
  }
  decltype(auto) val = self.getVal1();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::optional<::pasta::Expr> AtomicExpr::Value2(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  if (self.getOp() != clang::AtomicExpr::AO__atomic_exchange &&
      self.getNumSubExprs() <= 4 /* VAL2 */) {
    return std::nullopt;
  }
  decltype(auto) val = self.getVal2();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Type AtomicExpr::ValueType(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.getValueType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Expr> AtomicExpr::Weak(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  if (self.getNumSubExprs() <= 5 /* WEAK */) {
    return std::nullopt;
  }
  decltype(auto) val = self.getWeak();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

bool AtomicExpr::IsCmpXChg(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.isCmpXChg();
  return val;
}

bool AtomicExpr::IsOpenCL(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.isOpenCL();
  return val;
}

bool AtomicExpr::IsVolatile(void) const {
  auto &self = *const_cast<clang::AtomicExpr *>(u.AtomicExpr);
  decltype(auto) val = self.isVolatile();
  return val;
}

std::vector<::pasta::Expr> AtomicExpr::SubExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.AtomicExpr->getNumSubExprs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.AtomicExpr->getSubExprs()[i]));
  }
  return ret;
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
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token BinaryConditionalOperator::BeginToken(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr BinaryConditionalOperator::Common(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getCommon();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BinaryConditionalOperator::Common can return nullptr!");
}

::pasta::Expr BinaryConditionalOperator::Condition(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BinaryConditionalOperator::Condition can return nullptr!");
}

::pasta::Token BinaryConditionalOperator::EndToken(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr BinaryConditionalOperator::FalseExpression(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getFalseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BinaryConditionalOperator::FalseExpression can return nullptr!");
}

::pasta::OpaqueValueExpr BinaryConditionalOperator::OpaqueValue(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getOpaqueValue();
  if (val) {
    return StmtBuilder::Create<::pasta::OpaqueValueExpr>(ast, val);
  }
  throw std::runtime_error("BinaryConditionalOperator::OpaqueValue can return nullptr!");
}

::pasta::Expr BinaryConditionalOperator::TrueExpression(void) const {
  auto &self = *const_cast<clang::BinaryConditionalOperator *>(u.BinaryConditionalOperator);
  decltype(auto) val = self.getTrueExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BinaryConditionalOperator::TrueExpression can return nullptr!");
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
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token BinaryOperator::BeginToken(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token BinaryOperator::EndToken(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token BinaryOperator::ExpressionToken(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

// 0: BinaryOperator::FPFeatures
// 1: BinaryOperator::FPFeaturesInEffect
::pasta::Expr BinaryOperator::LHS(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BinaryOperator::LHS can return nullptr!");
}

enum BinaryOperatorKind BinaryOperator::Opcode(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getOpcode();
  return static_cast<::pasta::BinaryOperatorKind>(val);
}

std::string_view BinaryOperator::OpcodeString(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getOpcodeStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token BinaryOperator::OperatorToken(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Expr BinaryOperator::RHS(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BinaryOperator::RHS can return nullptr!");
}

// 0: BinaryOperator::StoredFPFeatures
bool BinaryOperator::HasStoredFPFeatures(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.hasStoredFPFeatures();
  return val;
}

bool BinaryOperator::IsAdditiveOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isAdditiveOp();
  return val;
}

bool BinaryOperator::IsAssignmentOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isAssignmentOp();
  return val;
}

bool BinaryOperator::IsBitwiseOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isBitwiseOp();
  return val;
}

bool BinaryOperator::IsCommaOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isCommaOp();
  return val;
}

bool BinaryOperator::IsComparisonOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isComparisonOp();
  return val;
}

bool BinaryOperator::IsCompoundAssignmentOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isCompoundAssignmentOp();
  return val;
}

bool BinaryOperator::IsEqualityOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isEqualityOp();
  return val;
}

// 1: BinaryOperator::IsFEnvAccessOn
// 1: BinaryOperator::IsFPContractableWithinStatement
bool BinaryOperator::IsLogicalOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isLogicalOp();
  return val;
}

bool BinaryOperator::IsMultiplicativeOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isMultiplicativeOp();
  return val;
}

bool BinaryOperator::IsPointerMemoryOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isPtrMemOp();
  return val;
}

bool BinaryOperator::IsRelationalOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isRelationalOp();
  return val;
}

bool BinaryOperator::IsShiftAssignOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isShiftAssignOp();
  return val;
}

bool BinaryOperator::IsShiftOperation(void) const {
  auto &self = *const_cast<clang::BinaryOperator *>(u.BinaryOperator);
  decltype(auto) val = self.isShiftOp();
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
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token BlockExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::BlockDecl BlockExpr::BlockDeclaration(void) const {
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.getBlockDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::BlockDecl>(ast, val);
  }
  throw std::runtime_error("BlockExpr::BlockDeclaration can return nullptr!");
}

::pasta::Stmt BlockExpr::Body(void) const {
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("BlockExpr::Body can return nullptr!");
}

::pasta::Token BlockExpr::CaretToken(void) const {
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.getCaretLocation();
  return ast->TokenAt(val);
}

::pasta::Token BlockExpr::EndToken(void) const {
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::FunctionProtoType BlockExpr::FunctionType(void) const {
  auto &self = *const_cast<clang::BlockExpr *>(u.BlockExpr);
  decltype(auto) val = self.getFunctionType();
  if (val) {
    return TypeBuilder::Create<::pasta::FunctionProtoType>(ast, val);
  }
  throw std::runtime_error("BlockExpr::FunctionType can return nullptr!");
}

CXXBindTemporaryExpr::CXXBindTemporaryExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXBindTemporaryExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXBindTemporaryExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXBindTemporaryExpr)
std::vector<::pasta::Stmt> CXXBindTemporaryExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXBindTemporaryExpr *>(u.CXXBindTemporaryExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXBindTemporaryExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXBindTemporaryExpr *>(u.CXXBindTemporaryExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXBindTemporaryExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXBindTemporaryExpr *>(u.CXXBindTemporaryExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXBindTemporaryExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::CXXBindTemporaryExpr *>(u.CXXBindTemporaryExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXBindTemporaryExpr::SubExpression can return nullptr!");
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
  auto &self = *const_cast<clang::CXXBoolLiteralExpr *>(u.CXXBoolLiteralExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXBoolLiteralExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXBoolLiteralExpr *>(u.CXXBoolLiteralExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXBoolLiteralExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXBoolLiteralExpr *>(u.CXXBoolLiteralExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXBoolLiteralExpr::Token(void) const {
  auto &self = *const_cast<clang::CXXBoolLiteralExpr *>(u.CXXBoolLiteralExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

bool CXXBoolLiteralExpr::Value(void) const {
  auto &self = *const_cast<clang::CXXBoolLiteralExpr *>(u.CXXBoolLiteralExpr);
  decltype(auto) val = self.getValue();
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
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Stmt> CXXConstructExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 1: CXXConstructExpr::Argument
// 0: CXXConstructExpr::Arguments
::pasta::Token CXXConstructExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

enum CXXConstructExprConstructionKind CXXConstructExpr::ConstructionKind(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getConstructionKind();
  return static_cast<::pasta::CXXConstructExprConstructionKind>(val);
}

::pasta::CXXConstructorDecl CXXConstructExpr::Constructor(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  throw std::runtime_error("CXXConstructExpr::Constructor can return nullptr!");
}

::pasta::Token CXXConstructExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXConstructExpr::Token(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t CXXConstructExpr::NumArguments(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getNumArgs();
  return val;
}

::pasta::TokenRange CXXConstructExpr::ParenthesisOrBraceRange(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.getParenOrBraceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXConstructExpr::HadMultipleCandidates(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.hadMultipleCandidates();
  return val;
}

bool CXXConstructExpr::IsElidable(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.isElidable();
  return val;
}

bool CXXConstructExpr::IsImmediateEscalating(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.isImmediateEscalating();
  return val;
}

bool CXXConstructExpr::IsListInitialization(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.isListInitialization();
  return val;
}

bool CXXConstructExpr::IsStdInitializerListInitialization(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.isStdInitListInitialization();
  return val;
}

bool CXXConstructExpr::RequiresZeroInitialization(void) const {
  auto &self = *const_cast<clang::CXXConstructExpr *>(u.CXXConstructExpr);
  decltype(auto) val = self.requiresZeroInitialization();
  return val;
}

CXXDefaultArgExpr::CXXDefaultArgExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDefaultArgExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDefaultArgExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDefaultArgExpr)
std::vector<::pasta::Stmt> CXXDefaultArgExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr CXXDefaultArgExpr::AdjustedRewrittenExpression(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getAdjustedRewrittenExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXDefaultArgExpr::AdjustedRewrittenExpression can return nullptr!");
}

::pasta::Token CXXDefaultArgExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXDefaultArgExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXDefaultArgExpr::Expression(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXDefaultArgExpr::Expression can return nullptr!");
}

::pasta::Token CXXDefaultArgExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::ParmVarDecl CXXDefaultArgExpr::Parameter(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getParam();
  if (val) {
    return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
  }
  throw std::runtime_error("CXXDefaultArgExpr::Parameter can return nullptr!");
}

std::optional<::pasta::Expr> CXXDefaultArgExpr::RewrittenExpression(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getRewrittenExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::DeclContext CXXDefaultArgExpr::UsedContext(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getUsedContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("CXXDefaultArgExpr::UsedContext can return nullptr!");
}

::pasta::Token CXXDefaultArgExpr::UsedToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.getUsedLocation();
  return ast->TokenAt(val);
}

bool CXXDefaultArgExpr::HasRewrittenInitializer(void) const {
  auto &self = *const_cast<clang::CXXDefaultArgExpr *>(u.CXXDefaultArgExpr);
  decltype(auto) val = self.hasRewrittenInit();
  return val;
}

CXXDefaultInitExpr::CXXDefaultInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDefaultInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDefaultInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDefaultInitExpr)
std::vector<::pasta::Stmt> CXXDefaultInitExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXDefaultInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXDefaultInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> CXXDefaultInitExpr::Expression(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  if (!self.getField()->getInClassInitializer()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::FieldDecl CXXDefaultInitExpr::Field(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.getField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  throw std::runtime_error("CXXDefaultInitExpr::Field can return nullptr!");
}

::pasta::Expr CXXDefaultInitExpr::RewrittenExpression(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.getRewrittenExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXDefaultInitExpr::RewrittenExpression can return nullptr!");
}

::pasta::DeclContext CXXDefaultInitExpr::UsedContext(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.getUsedContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("CXXDefaultInitExpr::UsedContext can return nullptr!");
}

::pasta::Token CXXDefaultInitExpr::UsedToken(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.getUsedLocation();
  return ast->TokenAt(val);
}

bool CXXDefaultInitExpr::HasRewrittenInitializer(void) const {
  auto &self = *const_cast<clang::CXXDefaultInitExpr *>(u.CXXDefaultInitExpr);
  decltype(auto) val = self.hasRewrittenInit();
  return val;
}

CXXDeleteExpr::CXXDeleteExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXDeleteExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXDeleteExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXDeleteExpr)
std::vector<::pasta::Stmt> CXXDeleteExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

bool CXXDeleteExpr::DoesUsualArrayDeleteWantSize(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.doesUsualArrayDeleteWantSize();
  return val;
}

::pasta::Expr CXXDeleteExpr::Argument(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.getArgument();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXDeleteExpr::Argument can return nullptr!");
}

::pasta::Token CXXDeleteExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Type> CXXDeleteExpr::DestroyedType(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.getDestroyedType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

::pasta::Token CXXDeleteExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::FunctionDecl> CXXDeleteExpr::OperatorDelete(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.getOperatorDelete();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

bool CXXDeleteExpr::IsArrayForm(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.isArrayForm();
  return val;
}

bool CXXDeleteExpr::IsArrayFormAsWritten(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.isArrayFormAsWritten();
  return val;
}

bool CXXDeleteExpr::IsGlobalDelete(void) const {
  auto &self = *const_cast<clang::CXXDeleteExpr *>(u.CXXDeleteExpr);
  decltype(auto) val = self.isGlobalDelete();
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
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::optional<::pasta::Expr> CXXDependentScopeMemberExpr::Base(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  if (self.isImplicitAccess()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getBase();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Type CXXDependentScopeMemberExpr::BaseType(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getBaseType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Token CXXDependentScopeMemberExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXDependentScopeMemberExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::NamedDecl> CXXDependentScopeMemberExpr::FirstQualifierFoundInScope(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getFirstQualifierFoundInScope();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
}

::pasta::Token CXXDependentScopeMemberExpr::LAngleToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::Member
::pasta::Token CXXDependentScopeMemberExpr::MemberToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getMemberLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::MemberNameInfo
uint32_t CXXDependentScopeMemberExpr::NumTemplateArguments(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getNumTemplateArgs();
  return val;
}

::pasta::Token CXXDependentScopeMemberExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::Qualifier
// 0: CXXDependentScopeMemberExpr::QualifierToken
::pasta::Token CXXDependentScopeMemberExpr::RAngleToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: CXXDependentScopeMemberExpr::TemplateArguments
::pasta::Token CXXDependentScopeMemberExpr::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool CXXDependentScopeMemberExpr::HasExplicitTemplateArguments(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
}

bool CXXDependentScopeMemberExpr::HasTemplateKeyword(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.hasTemplateKeyword();
  return val;
}

bool CXXDependentScopeMemberExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.isArrow();
  return val;
}

bool CXXDependentScopeMemberExpr::IsImplicitAccess(void) const {
  auto &self = *const_cast<clang::CXXDependentScopeMemberExpr *>(u.CXXDependentScopeMemberExpr);
  decltype(auto) val = self.isImplicitAccess();
  return val;
}

// 0: CXXDependentScopeMemberExpr::TemplateArguments
CXXFoldExpr::CXXFoldExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXFoldExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXFoldExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXFoldExpr)
std::vector<::pasta::Stmt> CXXFoldExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXFoldExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::UnresolvedLookupExpr CXXFoldExpr::Callee(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getCallee();
  if (val) {
    return StmtBuilder::Create<::pasta::UnresolvedLookupExpr>(ast, val);
  }
  throw std::runtime_error("CXXFoldExpr::Callee can return nullptr!");
}

::pasta::Token CXXFoldExpr::EllipsisToken(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFoldExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXFoldExpr::Initializer(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXFoldExpr::Initializer can return nullptr!");
}

::pasta::Expr CXXFoldExpr::LHS(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXFoldExpr::LHS can return nullptr!");
}

::pasta::Token CXXFoldExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

std::optional<unsigned> CXXFoldExpr::NumExpansions(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getNumExpansions();
  if (val.has_value()) {
    return val.value();
  } else {
    return std::nullopt;
  }
}

enum BinaryOperatorKind CXXFoldExpr::Operator(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getOperator();
  return static_cast<::pasta::BinaryOperatorKind>(val);
}

::pasta::Expr CXXFoldExpr::Pattern(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getPattern();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXFoldExpr::Pattern can return nullptr!");
}

::pasta::Expr CXXFoldExpr::RHS(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXFoldExpr::RHS can return nullptr!");
}

::pasta::Token CXXFoldExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool CXXFoldExpr::IsLeftFold(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.isLeftFold();
  return val;
}

bool CXXFoldExpr::IsRightFold(void) const {
  auto &self = *const_cast<clang::CXXFoldExpr *>(u.CXXFoldExpr);
  decltype(auto) val = self.isRightFold();
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
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

bool CXXInheritedCtorInitExpr::ConstructsVirtualBase(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.constructsVBase();
  return val;
}

::pasta::Token CXXInheritedCtorInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

enum CXXConstructExprConstructionKind CXXInheritedCtorInitExpr::ConstructionKind(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.getConstructionKind();
  return static_cast<::pasta::CXXConstructExprConstructionKind>(val);
}

::pasta::CXXConstructorDecl CXXInheritedCtorInitExpr::Constructor(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.getConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  throw std::runtime_error("CXXInheritedCtorInitExpr::Constructor can return nullptr!");
}

::pasta::Token CXXInheritedCtorInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXInheritedCtorInitExpr::Token(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

bool CXXInheritedCtorInitExpr::InheritedFromVirtualBase(void) const {
  auto &self = *const_cast<clang::CXXInheritedCtorInitExpr *>(u.CXXInheritedCtorInitExpr);
  decltype(auto) val = self.inheritedFromVBase();
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
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

bool CXXNewExpr::DoesUsualArrayDeleteWantSize(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.doesUsualArrayDeleteWantSize();
  return val;
}

::pasta::Type CXXNewExpr::AllocatedType(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getAllocatedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: CXXNewExpr::
std::optional<::pasta::Expr> CXXNewExpr::ArraySize(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getArraySize();
  if (val.has_value()) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val.value());
  } else {
    return std::nullopt;
  }
}

::pasta::Token CXXNewExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::CXXConstructExpr> CXXNewExpr::ConstructExpression(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getConstructExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::CXXConstructExpr>(ast, val);
  }
}

::pasta::TokenRange CXXNewExpr::DirectInitializerRange(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getDirectInitRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token CXXNewExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum CXXNewExprInitializationStyle CXXNewExpr::InitializationStyle(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getInitializationStyle();
  return static_cast<::pasta::CXXNewExprInitializationStyle>(val);
}

std::optional<::pasta::Expr> CXXNewExpr::Initializer(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getInitializer();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

uint32_t CXXNewExpr::NumPlacementArguments(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getNumPlacementArgs();
  return val;
}

std::optional<::pasta::FunctionDecl> CXXNewExpr::OperatorDelete(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getOperatorDelete();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

std::optional<::pasta::FunctionDecl> CXXNewExpr::OperatorNew(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getOperatorNew();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

// 1: CXXNewExpr::PlacementArgument
::pasta::TokenRange CXXNewExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TokenRange CXXNewExpr::TypeIdParentheses(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.getTypeIdParens();
  return ast->TokenRangeFrom(val);
}

bool CXXNewExpr::HasInitializer(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.hasInitializer();
  return val;
}

bool CXXNewExpr::IsArray(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.isArray();
  return val;
}

bool CXXNewExpr::IsGlobalNew(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.isGlobalNew();
  return val;
}

bool CXXNewExpr::IsParenthesisTypeId(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.isParenTypeId();
  return val;
}

bool CXXNewExpr::PassAlignment(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.passAlignment();
  return val;
}

// 0: CXXNewExpr::
// 0: CXXNewExpr::
std::vector<::pasta::Expr> CXXNewExpr::PlacementArguments(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.placement_arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: CXXNewExpr::
// 0: CXXNewExpr::
bool CXXNewExpr::ShouldNullCheckAllocation(void) const {
  auto &self = *const_cast<clang::CXXNewExpr *>(u.CXXNewExpr);
  decltype(auto) val = self.shouldNullCheckAllocation();
  return val;
}

CXXNoexceptExpr::CXXNoexceptExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXNoexceptExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXNoexceptExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXNoexceptExpr)
std::vector<::pasta::Stmt> CXXNoexceptExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXNoexceptExpr *>(u.CXXNoexceptExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXNoexceptExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXNoexceptExpr *>(u.CXXNoexceptExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNoexceptExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXNoexceptExpr *>(u.CXXNoexceptExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXNoexceptExpr::Operand(void) const {
  auto &self = *const_cast<clang::CXXNoexceptExpr *>(u.CXXNoexceptExpr);
  decltype(auto) val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXNoexceptExpr::Operand can return nullptr!");
}

::pasta::TokenRange CXXNoexceptExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXNoexceptExpr *>(u.CXXNoexceptExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXNoexceptExpr::Value(void) const {
  auto &self = *const_cast<clang::CXXNoexceptExpr *>(u.CXXNoexceptExpr);
  decltype(auto) val = self.getValue();
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
  auto &self = *const_cast<clang::CXXNullPtrLiteralExpr *>(u.CXXNullPtrLiteralExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXNullPtrLiteralExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXNullPtrLiteralExpr *>(u.CXXNullPtrLiteralExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNullPtrLiteralExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXNullPtrLiteralExpr *>(u.CXXNullPtrLiteralExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNullPtrLiteralExpr::Token(void) const {
  auto &self = *const_cast<clang::CXXNullPtrLiteralExpr *>(u.CXXNullPtrLiteralExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

CXXParenListInitExpr::CXXParenListInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXParenListInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXParenListInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXParenListInitExpr)
std::vector<::pasta::Stmt> CXXParenListInitExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr CXXParenListInitExpr::ArrayFiller(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.getArrayFiller();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXParenListInitExpr::ArrayFiller can return nullptr!");
}

::pasta::Token CXXParenListInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXParenListInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CXXParenListInitExpr::InitializerExpressions
::pasta::Token CXXParenListInitExpr::InitializerToken(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.getInitLoc();
  return ast->TokenAt(val);
}

::pasta::FieldDecl CXXParenListInitExpr::InitializedFieldInUnion(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.getInitializedFieldInUnion();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  throw std::runtime_error("CXXParenListInitExpr::InitializedFieldInUnion can return nullptr!");
}

::pasta::TokenRange CXXParenListInitExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXParenListInitExpr *>(u.CXXParenListInitExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: CXXParenListInitExpr::UserSpecifiedInitializerExpressions
CXXPseudoDestructorExpr::CXXPseudoDestructorExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXPseudoDestructorExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXPseudoDestructorExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXPseudoDestructorExpr)
std::vector<::pasta::Stmt> CXXPseudoDestructorExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr CXXPseudoDestructorExpr::Base(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXPseudoDestructorExpr::Base can return nullptr!");
}

::pasta::Token CXXPseudoDestructorExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXPseudoDestructorExpr::ColonColonToken(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getColonColonLoc();
  return ast->TokenAt(val);
}

::pasta::Type CXXPseudoDestructorExpr::DestroyedType(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getDestroyedType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: CXXPseudoDestructorExpr::DestroyedTypeIdentifier
// 0: CXXPseudoDestructorExpr::
::pasta::Token CXXPseudoDestructorExpr::DestroyedTypeToken(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getDestroyedTypeLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXPseudoDestructorExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXPseudoDestructorExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

// 0: CXXPseudoDestructorExpr::Qualifier
// 0: CXXPseudoDestructorExpr::QualifierToken
// 0: CXXPseudoDestructorExpr::
::pasta::Token CXXPseudoDestructorExpr::TildeToken(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.getTildeLoc();
  return ast->TokenAt(val);
}

bool CXXPseudoDestructorExpr::HasQualifier(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.hasQualifier();
  return val;
}

bool CXXPseudoDestructorExpr::IsArrow(void) const {
  auto &self = *const_cast<clang::CXXPseudoDestructorExpr *>(u.CXXPseudoDestructorExpr);
  decltype(auto) val = self.isArrow();
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
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: CXXRewrittenBinaryOperator::DecomposedForm
::pasta::Token CXXRewrittenBinaryOperator::EndToken(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXRewrittenBinaryOperator::ExpressionToken(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXRewrittenBinaryOperator::LHS(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXRewrittenBinaryOperator::LHS can return nullptr!");
}

enum BinaryOperatorKind CXXRewrittenBinaryOperator::Opcode(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getOpcode();
  return static_cast<::pasta::BinaryOperatorKind>(val);
}

std::string_view CXXRewrittenBinaryOperator::OpcodeString(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getOpcodeStr();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

enum BinaryOperatorKind CXXRewrittenBinaryOperator::Operator(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getOperator();
  return static_cast<::pasta::BinaryOperatorKind>(val);
}

::pasta::Token CXXRewrittenBinaryOperator::OperatorToken(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXRewrittenBinaryOperator::RHS(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXRewrittenBinaryOperator::RHS can return nullptr!");
}

::pasta::Expr CXXRewrittenBinaryOperator::SemanticForm(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getSemanticForm();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXRewrittenBinaryOperator::SemanticForm can return nullptr!");
}

::pasta::TokenRange CXXRewrittenBinaryOperator::Tokens(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXRewrittenBinaryOperator::IsAssignmentOperation(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.isAssignmentOp();
  return val;
}

bool CXXRewrittenBinaryOperator::IsComparisonOperation(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.isComparisonOp();
  return val;
}

bool CXXRewrittenBinaryOperator::IsReversed(void) const {
  auto &self = *const_cast<clang::CXXRewrittenBinaryOperator *>(u.CXXRewrittenBinaryOperator);
  decltype(auto) val = self.isReversed();
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
  auto &self = *const_cast<clang::CXXScalarValueInitExpr *>(u.CXXScalarValueInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXScalarValueInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXScalarValueInitExpr *>(u.CXXScalarValueInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXScalarValueInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXScalarValueInitExpr *>(u.CXXScalarValueInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXScalarValueInitExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CXXScalarValueInitExpr *>(u.CXXScalarValueInitExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: CXXScalarValueInitExpr::
CXXStdInitializerListExpr::CXXStdInitializerListExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXStdInitializerListExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXStdInitializerListExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXStdInitializerListExpr)
std::vector<::pasta::Stmt> CXXStdInitializerListExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXStdInitializerListExpr *>(u.CXXStdInitializerListExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXStdInitializerListExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXStdInitializerListExpr *>(u.CXXStdInitializerListExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXStdInitializerListExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXStdInitializerListExpr *>(u.CXXStdInitializerListExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange CXXStdInitializerListExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXStdInitializerListExpr *>(u.CXXStdInitializerListExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Expr CXXStdInitializerListExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::CXXStdInitializerListExpr *>(u.CXXStdInitializerListExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXStdInitializerListExpr::SubExpression can return nullptr!");
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
  auto &self = *const_cast<clang::CXXTemporaryObjectExpr *>(u.CXXTemporaryObjectExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXTemporaryObjectExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXTemporaryObjectExpr *>(u.CXXTemporaryObjectExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CXXTemporaryObjectExpr::
std::vector<::pasta::Expr> CXXTemporaryObjectExpr::Arguments(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXTemporaryObjectExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXTemporaryObjectExpr->getArg(i)));
  }
  return ret;
}

CXXThisExpr::CXXThisExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXThisExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXThisExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXThisExpr)
std::vector<::pasta::Stmt> CXXThisExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXThisExpr *>(u.CXXThisExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXThisExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXThisExpr *>(u.CXXThisExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXThisExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXThisExpr *>(u.CXXThisExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXThisExpr::Token(void) const {
  auto &self = *const_cast<clang::CXXThisExpr *>(u.CXXThisExpr);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

bool CXXThisExpr::IsImplicit(void) const {
  auto &self = *const_cast<clang::CXXThisExpr *>(u.CXXThisExpr);
  decltype(auto) val = self.isImplicit();
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
  auto &self = *const_cast<clang::CXXThrowExpr *>(u.CXXThrowExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXThrowExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXThrowExpr *>(u.CXXThrowExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXThrowExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXThrowExpr *>(u.CXXThrowExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> CXXThrowExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::CXXThrowExpr *>(u.CXXThrowExpr);
  decltype(auto) val = self.getSubExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Token CXXThrowExpr::ThrowToken(void) const {
  auto &self = *const_cast<clang::CXXThrowExpr *>(u.CXXThrowExpr);
  decltype(auto) val = self.getThrowLoc();
  return ast->TokenAt(val);
}

bool CXXThrowExpr::IsThrownVariableInScope(void) const {
  auto &self = *const_cast<clang::CXXThrowExpr *>(u.CXXThrowExpr);
  decltype(auto) val = self.isThrownVariableInScope();
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
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXTypeidExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXTypeidExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> CXXTypeidExpr::ExpressionOperand(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  if (self.isTypeOperand()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getExprOperand();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::TokenRange CXXTypeidExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type CXXTypeidExpr::TypeOperand(void) const {
  auto &self = *(u.CXXTypeidExpr);
  decltype(auto) val = self.getTypeOperand(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type CXXTypeidExpr::TypeOperandSourceInfo(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.getTypeOperandSourceInfo();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("CXXTypeidExpr::TypeOperandSourceInfo can return nullptr!");
}

std::optional<bool> CXXTypeidExpr::IsMostDerived(void) const {
  auto &self = *(u.CXXTypeidExpr);
  if (self.isTypeOperand()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isMostDerived(ast->ci->getASTContext());
  return val;
}

bool CXXTypeidExpr::IsPotentiallyEvaluated(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.isPotentiallyEvaluated();
  return val;
}

bool CXXTypeidExpr::IsTypeOperand(void) const {
  auto &self = *const_cast<clang::CXXTypeidExpr *>(u.CXXTypeidExpr);
  decltype(auto) val = self.isTypeOperand();
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
std::vector<::pasta::Expr> CXXUnresolvedConstructExpr::Arguments(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Stmt> CXXUnresolvedConstructExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 1: CXXUnresolvedConstructExpr::Argument
::pasta::Token CXXUnresolvedConstructExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXUnresolvedConstructExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXUnresolvedConstructExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

uint32_t CXXUnresolvedConstructExpr::NumArguments(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.getNumArgs();
  return val;
}

::pasta::Token CXXUnresolvedConstructExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Type CXXUnresolvedConstructExpr::TypeAsWritten(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.getTypeAsWritten();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: CXXUnresolvedConstructExpr::
bool CXXUnresolvedConstructExpr::IsListInitialization(void) const {
  auto &self = *const_cast<clang::CXXUnresolvedConstructExpr *>(u.CXXUnresolvedConstructExpr);
  decltype(auto) val = self.isListInitialization();
  return val;
}

CXXUuidofExpr::CXXUuidofExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, CXXUuidofExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CXXUuidofExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CXXUuidofExpr)
std::vector<::pasta::Stmt> CXXUuidofExpr::Children(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CXXUuidofExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXUuidofExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Expr> CXXUuidofExpr::ExpressionOperand(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  if (self.isTypeOperand()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getExprOperand();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::MSGuidDecl CXXUuidofExpr::GuidDeclaration(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.getGuidDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::MSGuidDecl>(ast, val);
  }
  throw std::runtime_error("CXXUuidofExpr::GuidDeclaration can return nullptr!");
}

::pasta::TokenRange CXXUuidofExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type CXXUuidofExpr::TypeOperand(void) const {
  auto &self = *(u.CXXUuidofExpr);
  decltype(auto) val = self.getTypeOperand(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type CXXUuidofExpr::TypeOperandSourceInfo(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.getTypeOperandSourceInfo();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("CXXUuidofExpr::TypeOperandSourceInfo can return nullptr!");
}

bool CXXUuidofExpr::IsTypeOperand(void) const {
  auto &self = *const_cast<clang::CXXUuidofExpr *>(u.CXXUuidofExpr);
  decltype(auto) val = self.isTypeOperand();
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
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.arguments();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Stmt> CallExpr::Children(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

enum CallExprADLCallKind CallExpr::ADLCallKind(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getADLCallKind();
  return static_cast<::pasta::CallExprADLCallKind>(val);
}

// 1: CallExpr::Argument
// 0: CallExpr::Arguments
::pasta::Token CallExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

uint32_t CallExpr::BuiltinCallee(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getBuiltinCallee();
  return val;
}

::pasta::Type CallExpr::CallReturnType(void) const {
  auto &self = *(u.CallExpr);
  decltype(auto) val = self.getCallReturnType(ast->ci->getASTContext());
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Expr CallExpr::Callee(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getCallee();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CallExpr::Callee can return nullptr!");
}

std::optional<::pasta::Decl> CallExpr::CalleeDeclaration(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getCalleeDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

std::optional<::pasta::FunctionDecl> CallExpr::DirectCallee(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getDirectCallee();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

::pasta::Token CallExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: CallExpr::FPFeatures
// 1: CallExpr::FPFeaturesInEffect
uint32_t CallExpr::NumArguments(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getNumArgs();
  return val;
}

::pasta::Token CallExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

// 0: CallExpr::StoredFPFeatures
std::optional<::pasta::Attr> CallExpr::UnusedResultAttribute(void) const {
  auto &self = *(u.CallExpr);
  decltype(auto) val = self.getUnusedResultAttr(ast->ci->getASTContext());
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return AttrBuilder::Create<::pasta::Attr>(ast, val);
  }
}

bool CallExpr::HasStoredFPFeatures(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.hasStoredFPFeatures();
  return val;
}

bool CallExpr::HasUnusedResultAttribute(void) const {
  auto &self = *(u.CallExpr);
  decltype(auto) val = self.hasUnusedResultAttr(ast->ci->getASTContext());
  return val;
}

bool CallExpr::IsBuiltinAssumeFalse(void) const {
  auto &self = *(u.CallExpr);
  decltype(auto) val = self.isBuiltinAssumeFalse(ast->ci->getASTContext());
  return val;
}

bool CallExpr::IsCallToStdMove(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.isCallToStdMove();
  return val;
}

bool CallExpr::IsUnevaluatedBuiltinCall(void) const {
  auto &self = *(u.CallExpr);
  decltype(auto) val = self.isUnevaluatedBuiltinCall(ast->ci->getASTContext());
  return val;
}

bool CallExpr::UsesADL(void) const {
  auto &self = *const_cast<clang::CallExpr *>(u.CallExpr);
  decltype(auto) val = self.usesADL();
  return val;
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
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

enum CastKind CastExpr::CastKind(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.getCastKind();
  return static_cast<::pasta::CastKind>(val);
}

std::string_view CastExpr::CastKindName(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.getCastKindName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("CastExpr::CastKindName can return nullptr!");
}

std::optional<::pasta::NamedDecl> CastExpr::ConversionFunction(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.getConversionFunction();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
}

// 0: CastExpr::FPFeatures
// 1: CastExpr::FPFeaturesInEffect
// 0: CastExpr::StoredFPFeatures
::pasta::Expr CastExpr::SubExpression(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.getSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CastExpr::SubExpression can return nullptr!");
}

::pasta::Expr CastExpr::SubExpressionAsWritten(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.getSubExprAsWritten();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CastExpr::SubExpressionAsWritten can return nullptr!");
}

std::optional<::pasta::FieldDecl> CastExpr::TargetUnionField(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  if (self.getCastKind() != clang::CK_ToUnion) {
    return std::nullopt;
  }
  decltype(auto) val = self.getTargetUnionField();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
}

bool CastExpr::HasStoredFPFeatures(void) const {
  auto &self = *const_cast<clang::CastExpr *>(u.CastExpr);
  decltype(auto) val = self.hasStoredFPFeatures();
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
  auto &self = *const_cast<clang::CharacterLiteral *>(u.CharacterLiteral);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CharacterLiteral::BeginToken(void) const {
  auto &self = *const_cast<clang::CharacterLiteral *>(u.CharacterLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CharacterLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::CharacterLiteral *>(u.CharacterLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum CharacterLiteralCharacterKind CharacterLiteral::LiteralKind(void) const {
  auto &self = *const_cast<clang::CharacterLiteral *>(u.CharacterLiteral);
  decltype(auto) val = self.getKind();
  return static_cast<::pasta::CharacterLiteralCharacterKind>(val);
}

::pasta::Token CharacterLiteral::Token(void) const {
  auto &self = *const_cast<clang::CharacterLiteral *>(u.CharacterLiteral);
  decltype(auto) val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t CharacterLiteral::Value(void) const {
  auto &self = *const_cast<clang::CharacterLiteral *>(u.CharacterLiteral);
  decltype(auto) val = self.getValue();
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
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ChooseExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ChooseExpr::BuiltinToken(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ChooseExpr::ChosenSubExpression(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getChosenSubExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ChooseExpr::ChosenSubExpression can return nullptr!");
}

::pasta::Expr ChooseExpr::Condition(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ChooseExpr::Condition can return nullptr!");
}

::pasta::Token ChooseExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ChooseExpr::LHS(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ChooseExpr::LHS can return nullptr!");
}

::pasta::Expr ChooseExpr::RHS(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ChooseExpr::RHS can return nullptr!");
}

::pasta::Token ChooseExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool ChooseExpr::IsConditionDependent(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.isConditionDependent();
  return val;
}

bool ChooseExpr::IsConditionTrue(void) const {
  auto &self = *const_cast<clang::ChooseExpr *>(u.ChooseExpr);
  decltype(auto) val = self.isConditionTrue();
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
  auto &self = *const_cast<clang::CompoundAssignOperator *>(u.CompoundAssignOperator);
  decltype(auto) val = self.getComputationLHSType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type CompoundAssignOperator::ComputationResultType(void) const {
  auto &self = *const_cast<clang::CompoundAssignOperator *>(u.CompoundAssignOperator);
  decltype(auto) val = self.getComputationResultType();
  assert(!val.isNull());
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
  auto &self = *const_cast<clang::CompoundLiteralExpr *>(u.CompoundLiteralExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CompoundLiteralExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CompoundLiteralExpr *>(u.CompoundLiteralExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CompoundLiteralExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CompoundLiteralExpr *>(u.CompoundLiteralExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CompoundLiteralExpr::Initializer(void) const {
  auto &self = *const_cast<clang::CompoundLiteralExpr *>(u.CompoundLiteralExpr);
  decltype(auto) val = self.getInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CompoundLiteralExpr::Initializer can return nullptr!");
}

::pasta::Token CompoundLiteralExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::CompoundLiteralExpr *>(u.CompoundLiteralExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

// 0: CompoundLiteralExpr::
bool CompoundLiteralExpr::IsFileScope(void) const {
  auto &self = *const_cast<clang::CompoundLiteralExpr *>(u.CompoundLiteralExpr);
  decltype(auto) val = self.isFileScope();
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
  auto &self = *const_cast<clang::ConceptSpecializationExpr *>(u.ConceptSpecializationExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ConceptSpecializationExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ConceptSpecializationExpr *>(u.ConceptSpecializationExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConceptSpecializationExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ConceptSpecializationExpr *>(u.ConceptSpecializationExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: ConceptSpecializationExpr::Satisfaction
::pasta::ImplicitConceptSpecializationDecl ConceptSpecializationExpr::SpecializationDeclaration(void) const {
  auto &self = *const_cast<clang::ConceptSpecializationExpr *>(u.ConceptSpecializationExpr);
  decltype(auto) val = self.getSpecializationDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitConceptSpecializationDecl>(ast, val);
  }
  throw std::runtime_error("ConceptSpecializationExpr::SpecializationDeclaration can return nullptr!");
}

std::vector<::pasta::TemplateArgument> ConceptSpecializationExpr::TemplateArguments(void) const {
  auto &self = *const_cast<clang::ConceptSpecializationExpr *>(u.ConceptSpecializationExpr);
  decltype(auto) val = self.getTemplateArguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
}

bool ConceptSpecializationExpr::IsSatisfied(void) const {
  auto &self = *const_cast<clang::ConceptSpecializationExpr *>(u.ConceptSpecializationExpr);
  decltype(auto) val = self.isSatisfied();
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
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ConditionalOperator::BeginToken(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ConditionalOperator::Condition(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getCond();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConditionalOperator::Condition can return nullptr!");
}

::pasta::Token ConditionalOperator::EndToken(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ConditionalOperator::FalseExpression(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getFalseExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConditionalOperator::FalseExpression can return nullptr!");
}

::pasta::Expr ConditionalOperator::LHS(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getLHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConditionalOperator::LHS can return nullptr!");
}

::pasta::Expr ConditionalOperator::RHS(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getRHS();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConditionalOperator::RHS can return nullptr!");
}

::pasta::Expr ConditionalOperator::TrueExpression(void) const {
  auto &self = *const_cast<clang::ConditionalOperator *>(u.ConditionalOperator);
  decltype(auto) val = self.getTrueExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConditionalOperator::TrueExpression can return nullptr!");
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
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

// 0: ConstantExpr::APValueResult
::pasta::Token ConstantExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConstantExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: ConstantExpr::ResultAPValueKind
llvm::APSInt ConstantExpr::ResultAsAPSInt(void) const {
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.getResultAsAPSInt();
  return val;
}

// 0: ConstantExpr::ResultAsAPValue
enum ConstantExprResultStorageKind ConstantExpr::ResultStorageKind(void) const {
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.getResultStorageKind();
  return static_cast<::pasta::ConstantExprResultStorageKind>(val);
}

bool ConstantExpr::HasAPValueResult(void) const {
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.hasAPValueResult();
  return val;
}

bool ConstantExpr::IsImmediateInvocation(void) const {
  auto &self = *const_cast<clang::ConstantExpr *>(u.ConstantExpr);
  decltype(auto) val = self.isImmediateInvocation();
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
  auto &self = *const_cast<clang::ConvertVectorExpr *>(u.ConvertVectorExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token ConvertVectorExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::ConvertVectorExpr *>(u.ConvertVectorExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConvertVectorExpr::BuiltinToken(void) const {
  auto &self = *const_cast<clang::ConvertVectorExpr *>(u.ConvertVectorExpr);
  decltype(auto) val = self.getBuiltinLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConvertVectorExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ConvertVectorExpr *>(u.ConvertVectorExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ConvertVectorExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::ConvertVectorExpr *>(u.ConvertVectorExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ConvertVectorExpr::SrcExpression(void) const {
  auto &self = *const_cast<clang::ConvertVectorExpr *>(u.ConvertVectorExpr);
  decltype(auto) val = self.getSrcExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConvertVectorExpr::SrcExpression can return nullptr!");
}

// 0: ConvertVectorExpr::
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
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token CoroutineSuspendExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CoroutineSuspendExpr::CommonExpression(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getCommonExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineSuspendExpr::CommonExpression can return nullptr!");
}

::pasta::Token CoroutineSuspendExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CoroutineSuspendExpr::KeywordToken(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::OpaqueValueExpr CoroutineSuspendExpr::OpaqueValue(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getOpaqueValue();
  if (val) {
    return StmtBuilder::Create<::pasta::OpaqueValueExpr>(ast, val);
  }
  throw std::runtime_error("CoroutineSuspendExpr::OpaqueValue can return nullptr!");
}

::pasta::Expr CoroutineSuspendExpr::Operand(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineSuspendExpr::Operand can return nullptr!");
}

::pasta::Expr CoroutineSuspendExpr::ReadyExpression(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getReadyExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineSuspendExpr::ReadyExpression can return nullptr!");
}

::pasta::Expr CoroutineSuspendExpr::ResumeExpression(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getResumeExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineSuspendExpr::ResumeExpression can return nullptr!");
}

::pasta::Expr CoroutineSuspendExpr::SuspendExpression(void) const {
  auto &self = *const_cast<clang::CoroutineSuspendExpr *>(u.CoroutineSuspendExpr);
  decltype(auto) val = self.getSuspendExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CoroutineSuspendExpr::SuspendExpression can return nullptr!");
}

CoyieldExpr::CoyieldExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : CoroutineSuspendExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(CoroutineSuspendExpr, CoyieldExpr)
PASTA_DEFINE_BASE_OPERATORS(Expr, CoyieldExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, CoyieldExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, CoyieldExpr)
DeclRefExpr::DeclRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DeclRefExpr)
std::vector<::pasta::Stmt> DeclRefExpr::Children(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token DeclRefExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ValueDecl DeclRefExpr::Declaration(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  throw std::runtime_error("DeclRefExpr::Declaration can return nullptr!");
}

::pasta::Token DeclRefExpr::EndToken(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl DeclRefExpr::FoundDeclaration(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getFoundDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("DeclRefExpr::FoundDeclaration can return nullptr!");
}

::pasta::Token DeclRefExpr::LAngleToken(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

// 0: DeclRefExpr::NameInfo
uint32_t DeclRefExpr::NumTemplateArguments(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getNumTemplateArgs();
  return val;
}

// 0: DeclRefExpr::Qualifier
// 0: DeclRefExpr::QualifierToken
::pasta::Token DeclRefExpr::RAngleToken(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: DeclRefExpr::TemplateArguments
::pasta::Token DeclRefExpr::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool DeclRefExpr::HadMultipleCandidates(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.hadMultipleCandidates();
  return val;
}

bool DeclRefExpr::HasExplicitTemplateArguments(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
}

bool DeclRefExpr::HasQualifier(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.hasQualifier();
  return val;
}

bool DeclRefExpr::HasTemplateKeywordAndArgumentsInfo(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.hasTemplateKWAndArgsInfo();
  return val;
}

bool DeclRefExpr::HasTemplateKeyword(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.hasTemplateKeyword();
  return val;
}

bool DeclRefExpr::IsImmediateEscalating(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.isImmediateEscalating();
  return val;
}

enum NonOdrUseReason DeclRefExpr::IsNonOdrUse(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.isNonOdrUse();
  return static_cast<::pasta::NonOdrUseReason>(val);
}

bool DeclRefExpr::RefersToEnclosingVariableOrCapture(void) const {
  auto &self = *const_cast<clang::DeclRefExpr *>(u.DeclRefExpr);
  decltype(auto) val = self.refersToEnclosingVariableOrCapture();
  return val;
}

// 0: DeclRefExpr::TemplateArguments
DependentCoawaitExpr::DependentCoawaitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DependentCoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DependentCoawaitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DependentCoawaitExpr)
std::vector<::pasta::Stmt> DependentCoawaitExpr::Children(void) const {
  auto &self = *const_cast<clang::DependentCoawaitExpr *>(u.DependentCoawaitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token DependentCoawaitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::DependentCoawaitExpr *>(u.DependentCoawaitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentCoawaitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::DependentCoawaitExpr *>(u.DependentCoawaitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentCoawaitExpr::KeywordToken(void) const {
  auto &self = *const_cast<clang::DependentCoawaitExpr *>(u.DependentCoawaitExpr);
  decltype(auto) val = self.getKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DependentCoawaitExpr::Operand(void) const {
  auto &self = *const_cast<clang::DependentCoawaitExpr *>(u.DependentCoawaitExpr);
  decltype(auto) val = self.getOperand();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DependentCoawaitExpr::Operand can return nullptr!");
}

::pasta::UnresolvedLookupExpr DependentCoawaitExpr::OperatorCoawaitLookup(void) const {
  auto &self = *const_cast<clang::DependentCoawaitExpr *>(u.DependentCoawaitExpr);
  decltype(auto) val = self.getOperatorCoawaitLookup();
  if (val) {
    return StmtBuilder::Create<::pasta::UnresolvedLookupExpr>(ast, val);
  }
  throw std::runtime_error("DependentCoawaitExpr::OperatorCoawaitLookup can return nullptr!");
}

DependentScopeDeclRefExpr::DependentScopeDeclRefExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DependentScopeDeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DependentScopeDeclRefExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DependentScopeDeclRefExpr)
std::vector<::pasta::Stmt> DependentScopeDeclRefExpr::Children(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Token DependentScopeDeclRefExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

// 0: DependentScopeDeclRefExpr::DeclarationName
::pasta::Token DependentScopeDeclRefExpr::EndToken(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DependentScopeDeclRefExpr::LAngleToken(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.getLAngleLoc();
  return ast->TokenAt(val);
}

// 0: DependentScopeDeclRefExpr::NameInfo
uint32_t DependentScopeDeclRefExpr::NumTemplateArguments(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.getNumTemplateArgs();
  return val;
}

// 0: DependentScopeDeclRefExpr::Qualifier
// 0: DependentScopeDeclRefExpr::QualifierToken
::pasta::Token DependentScopeDeclRefExpr::RAngleToken(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.getRAngleLoc();
  return ast->TokenAt(val);
}

// 0: DependentScopeDeclRefExpr::TemplateArguments
::pasta::Token DependentScopeDeclRefExpr::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

bool DependentScopeDeclRefExpr::HasExplicitTemplateArguments(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
}

bool DependentScopeDeclRefExpr::HasTemplateKeyword(void) const {
  auto &self = *const_cast<clang::DependentScopeDeclRefExpr *>(u.DependentScopeDeclRefExpr);
  decltype(auto) val = self.hasTemplateKeyword();
  return val;
}

// 0: DependentScopeDeclRefExpr::TemplateArguments
DesignatedInitExpr::DesignatedInitExpr(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : Expr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, DesignatedInitExpr)
PASTA_DEFINE_BASE_OPERATORS(Stmt, DesignatedInitExpr)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, DesignatedInitExpr)
std::vector<::pasta::Stmt> DesignatedInitExpr::Children(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::Designator> DesignatedInitExpr::Designators(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.designators();
  std::vector<::pasta::Designator> ret;
  for (const auto &d : val) {
    ret.emplace_back(ast, &d);
  }
  return ret;
}

// 1: DesignatedInitExpr::ArrayIndex
// 1: DesignatedInitExpr::ArrayRangeEnd
// 1: DesignatedInitExpr::ArrayRangeStart
::pasta::Token DesignatedInitExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Designator> DesignatedInitExpr::Designator(unsigned int idx) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  if (idx >= self.designators().size()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getDesignator(idx);
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Designator>(ast, val);
  }
  throw std::runtime_error("The unreachable has been reached");
}

::pasta::TokenRange DesignatedInitExpr::DesignatorsTokens(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.getDesignatorsSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token DesignatedInitExpr::EndToken(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DesignatedInitExpr::EqualOrColonToken(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.getEqualOrColonLoc();
  return ast->TokenAt(val);
}

::pasta::Expr DesignatedInitExpr::Initializer(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DesignatedInitExpr::Initializer can return nullptr!");
}

uint32_t DesignatedInitExpr::NumSubExpressions(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.getNumSubExprs();
  return val;
}

// 1: DesignatedInitExpr::SubExpression
bool DesignatedInitExpr::IsDirectInitializer(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.isDirectInit();
  return val;
}

uint32_t DesignatedInitExpr::Size(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.size();
  return val;
}

bool DesignatedInitExpr::UsesGNUSyntax(void) const {
  auto &self = *const_cast<clang::DesignatedInitExpr *>(u.DesignatedInitExpr);
  decltype(auto) val = self.usesGNUSyntax();
  return val;
}

std::vector<::pasta::Expr> DesignatedInitExpr::SubExpressions(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
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
  auto &self = *const_cast<clang::DesignatedInitUpdateExpr *>(u.DesignatedInitUpdateExpr);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::Expr DesignatedInitUpdateExpr::Base(void) const {
  auto &self = *const_cast<clang::DesignatedInitUpdateExpr *>(u.DesignatedInitUpdateExpr);
  decltype(auto) val = self.getBase();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("DesignatedInitUpdateExpr::Base can return nullptr!");
}

::pasta::Token DesignatedInitUpdateExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::DesignatedInitUpdateExpr *>(u.DesignatedInitUpdateExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DesignatedInitUpdateExpr::EndToken(void) const {
  auto &self = *const_cast<clang::DesignatedInitUpdateExpr *>(u.DesignatedInitUpdateExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::InitListExpr DesignatedInitUpdateExpr::Updater(void) const {
  auto &self = *const_cast<clang::DesignatedInitUpdateExpr *>(u.DesignatedInitUpdateExpr);
  decltype(auto) val = self.getUpdater();
  if (val) {
    return StmtBuilder::Create<::pasta::InitListExpr>(ast, val);
  }
  throw std::runtime_error("DesignatedInitUpdateExpr::Updater can return nullptr!");
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
  auto &self = *const_cast<clang::ExplicitCastExpr *>(u.ExplicitCastExpr);
  decltype(auto) val = self.getTypeAsWritten();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ExplicitCastExpr::TypeInfoAsWritten(void) const {
  auto &self = *const_cast<clang::ExplicitCastExpr *>(u.ExplicitCastExpr);
  decltype(auto) val = self.getTypeInfoAsWritten();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("ExplicitCastExpr::TypeInfoAsWritten can return nullptr!");
}

ExprWithCleanups::ExprWithCleanups(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : FullExpr(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(Expr, ExprWithCleanups)
PASTA_DEFINE_BASE_OPERATORS(FullExpr, ExprWithCleanups)
PASTA_DEFINE_BASE_OPERATORS(Stmt, ExprWithCleanups)
PASTA_DEFINE_BASE_OPERATORS(ValueStmt, ExprWithCleanups)
std::vector<::pasta::Stmt> ExprWithCleanups::Children(void) const {
  auto &self = *const_cast<clang::ExprWithCleanups *>(u.ExprWithCleanups);
  decltype(auto) val = self.children();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

bool ExprWithCleanups::CleanupsHaveSideEffects(void) const {
  auto &self = *const_cast<clang::ExprWithCleanups *>(u.ExprWithCleanups);
  decltype(auto) val = self.cleanupsHaveSideEffects();
  return val;
}

::pasta::Token ExprWithCleanups::BeginToken(void) const {
  auto &self = *const_cast<clang::ExprWithCleanups *>(u.ExprWithCleanups);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExprWithCleanups::EndToken(void) const {
  auto &self = *const_cast<clang::ExprWithCleanups *>(u.ExprWithCleanups);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

uint32_t ExprWithCleanups::NumObjects(void) const {
  auto &self = *const_cast<clang::ExprWithCleanups *>(u.ExprWithCleanups);
  decltype(auto) val = self.getNumObjects();
  return val;
}

// 1: ExprWithCleanups::Object
// 0: ExprWithCleanups::Objects
std::vector<std::variant<std::monostate, ::pasta::BlockDecl, ::pasta::CompoundLiteralExpr>> ExprWithCleanups::Objects(void) const {
  std::vector<std::variant<std::monostate, ::pasta::BlockDecl, ::pasta::CompoundLiteralExpr>> ret;
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
  auto &self = *const_cast<clang::ImplicitCastExpr *>(u.ImplicitCastExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ImplicitCastExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ImplicitCastExpr *>(u.ImplicitCastExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

bool ImplicitCastExpr::IsPartOfExplicitCast(void) const {
  auto &self = *const_cast<clang::ImplicitCastExpr *>(u.ImplicitCastExpr);
  decltype(auto) val = self.isPartOfExplicitCast();
  return val;
}

OMPAtomicDirective::OMPAtomicDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPAtomicDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPAtomicDirective)
::pasta::Expr OMPAtomicDirective::ConditionExpression(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getCondExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::ConditionExpression can return nullptr!");
}

::pasta::Expr OMPAtomicDirective::D(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getD();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::D can return nullptr!");
}

::pasta::Expr OMPAtomicDirective::Expression(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::Expression can return nullptr!");
}

::pasta::Expr OMPAtomicDirective::R(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getR();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::R can return nullptr!");
}

::pasta::Expr OMPAtomicDirective::UpdateExpression(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getUpdateExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::UpdateExpression can return nullptr!");
}

::pasta::Expr OMPAtomicDirective::V(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getV();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::V can return nullptr!");
}

::pasta::Expr OMPAtomicDirective::X(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.getX();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPAtomicDirective::X can return nullptr!");
}

bool OMPAtomicDirective::IsFailOnly(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.isFailOnly();
  return val;
}

bool OMPAtomicDirective::IsPostfixUpdate(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.isPostfixUpdate();
  return val;
}

bool OMPAtomicDirective::IsXLHSInRHSPart(void) const {
  auto &self = *const_cast<clang::OMPAtomicDirective *>(u.OMPAtomicDirective);
  decltype(auto) val = self.isXLHSInRHSPart();
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
OMPDispatchDirective::OMPDispatchDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDispatchDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDispatchDirective)
::pasta::Token OMPDispatchDirective::TargetCallToken(void) const {
  auto &self = *const_cast<clang::OMPDispatchDirective *>(u.OMPDispatchDirective);
  decltype(auto) val = self.getTargetCallLoc();
  return ast->TokenAt(val);
}

OMPDistributeDirective::OMPDistributeDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeDirective)
OMPDistributeParallelForDirective::OMPDistributeParallelForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeParallelForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeParallelForDirective)
::pasta::Expr OMPDistributeParallelForDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPDistributeParallelForDirective *>(u.OMPDistributeParallelForDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDistributeParallelForDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPDistributeParallelForDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPDistributeParallelForDirective *>(u.OMPDistributeParallelForDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPDistributeParallelForSimdDirective::OMPDistributeParallelForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeParallelForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeParallelForSimdDirective)
OMPDistributeSimdDirective::OMPDistributeSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPDistributeSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPDistributeSimdDirective)
OMPErrorDirective::OMPErrorDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPExecutableDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPErrorDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPErrorDirective)
OMPForDirective::OMPForDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPForDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPForDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPForDirective)
::pasta::Expr OMPForDirective::TaskReductionReferenceExpression(void) const {
  auto &self = *const_cast<clang::OMPForDirective *>(u.OMPForDirective);
  decltype(auto) val = self.getTaskReductionRefExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPForDirective::TaskReductionReferenceExpression can return nullptr!");
}

bool OMPForDirective::HasCancel(void) const {
  auto &self = *const_cast<clang::OMPForDirective *>(u.OMPForDirective);
  decltype(auto) val = self.hasCancel();
  return val;
}

OMPForSimdDirective::OMPForSimdDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPForSimdDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPForSimdDirective)
OMPGenericLoopDirective::OMPGenericLoopDirective(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Stmt *stmt_)
    : OMPLoopDirective(std::move(ast_), stmt_) {}

PASTA_DEFINE_BASE_OPERATORS(OMPExecutableDirective, OMPGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopBasedDirective, OMPGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(OMPLoopDirective, OMPGenericLoopDirective)
PASTA_DEFINE_BASE_OPERATORS(Stmt, OMPGenericLoopDirective)
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
  auto &self = *const_cast<clang::ObjCBridgedCastExpr *>(u.ObjCBridgedCastExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBridgedCastExpr::BridgeKeywordToken(void) const {
  auto &self = *const_cast<clang::ObjCBridgedCastExpr *>(u.ObjCBridgedCastExpr);
  decltype(auto) val = self.getBridgeKeywordLoc();
  return ast->TokenAt(val);
}

enum ObjCBridgeCastKind ObjCBridgedCastExpr::BridgeKind(void) const {
  auto &self = *const_cast<clang::ObjCBridgedCastExpr *>(u.ObjCBridgedCastExpr);
  decltype(auto) val = self.getBridgeKind();
  return static_cast<::pasta::ObjCBridgeCastKind>(val);
}

std::string_view ObjCBridgedCastExpr::BridgeKindName(void) const {
  auto &self = *const_cast<clang::ObjCBridgedCastExpr *>(u.ObjCBridgedCastExpr);
  decltype(auto) val = self.getBridgeKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::Token ObjCBridgedCastExpr::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCBridgedCastExpr *>(u.ObjCBridgedCastExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCBridgedCastExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::ObjCBridgedCastExpr *>(u.ObjCBridgedCastExpr);
  decltype(auto) val = self.getLParenLoc();
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
  auto &self = *const_cast<clang::UserDefinedLiteral *>(u.UserDefinedLiteral);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr UserDefinedLiteral::CookedLiteral(void) const {
  auto &self = *const_cast<clang::UserDefinedLiteral *>(u.UserDefinedLiteral);
  decltype(auto) val = self.getCookedLiteral();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("UserDefinedLiteral::CookedLiteral can return nullptr!");
}

::pasta::Token UserDefinedLiteral::EndToken(void) const {
  auto &self = *const_cast<clang::UserDefinedLiteral *>(u.UserDefinedLiteral);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum UserDefinedLiteralLiteralOperatorKind UserDefinedLiteral::LiteralOperatorKind(void) const {
  auto &self = *const_cast<clang::UserDefinedLiteral *>(u.UserDefinedLiteral);
  decltype(auto) val = self.getLiteralOperatorKind();
  return static_cast<::pasta::UserDefinedLiteralLiteralOperatorKind>(val);
}

// 0: UserDefinedLiteral::UDSuffix
::pasta::Token UserDefinedLiteral::UDSuffixToken(void) const {
  auto &self = *const_cast<clang::UserDefinedLiteral *>(u.UserDefinedLiteral);
  decltype(auto) val = self.getUDSuffixLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::Expr> UserDefinedLiteral::Arguments(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.UserDefinedLiteral->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.UserDefinedLiteral->getArg(i)));
  }
  return ret;
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
  auto &self = *const_cast<clang::BuiltinBitCastExpr *>(u.BuiltinBitCastExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token BuiltinBitCastExpr::EndToken(void) const {
  auto &self = *const_cast<clang::BuiltinBitCastExpr *>(u.BuiltinBitCastExpr);
  decltype(auto) val = self.getEndLoc();
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
  auto &self = *const_cast<clang::CStyleCastExpr *>(u.CStyleCastExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CStyleCastExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CStyleCastExpr *>(u.CStyleCastExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CStyleCastExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::CStyleCastExpr *>(u.CStyleCastExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token CStyleCastExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CStyleCastExpr *>(u.CStyleCastExpr);
  decltype(auto) val = self.getRParenLoc();
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
  auto &self = *const_cast<clang::CUDAKernelCallExpr *>(u.CUDAKernelCallExpr);
  decltype(auto) val = self.getConfig();
  if (val) {
    return StmtBuilder::Create<::pasta::CallExpr>(ast, val);
  }
  throw std::runtime_error("CUDAKernelCallExpr::Config can return nullptr!");
}

std::vector<::pasta::Expr> CUDAKernelCallExpr::Arguments(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CUDAKernelCallExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CUDAKernelCallExpr->getArg(i)));
  }
  return ret;
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
  auto &self = *const_cast<clang::CXXFunctionalCastExpr *>(u.CXXFunctionalCastExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFunctionalCastExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXFunctionalCastExpr *>(u.CXXFunctionalCastExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFunctionalCastExpr::LParenToken(void) const {
  auto &self = *const_cast<clang::CXXFunctionalCastExpr *>(u.CXXFunctionalCastExpr);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXFunctionalCastExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CXXFunctionalCastExpr *>(u.CXXFunctionalCastExpr);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool CXXFunctionalCastExpr::IsListInitialization(void) const {
  auto &self = *const_cast<clang::CXXFunctionalCastExpr *>(u.CXXFunctionalCastExpr);
  decltype(auto) val = self.isListInitialization();
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
::pasta::Token CXXMemberCallExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::CXXMemberCallExpr *>(u.CXXMemberCallExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

::pasta::Expr CXXMemberCallExpr::ImplicitObjectArgument(void) const {
  auto &self = *const_cast<clang::CXXMemberCallExpr *>(u.CXXMemberCallExpr);
  decltype(auto) val = self.getImplicitObjectArgument();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("CXXMemberCallExpr::ImplicitObjectArgument can return nullptr!");
}

std::optional<::pasta::CXXMethodDecl> CXXMemberCallExpr::MethodDeclaration(void) const {
  auto &self = *const_cast<clang::CXXMemberCallExpr *>(u.CXXMemberCallExpr);
  decltype(auto) val = self.getMethodDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
}

::pasta::Type CXXMemberCallExpr::ObjectType(void) const {
  auto &self = *const_cast<clang::CXXMemberCallExpr *>(u.CXXMemberCallExpr);
  decltype(auto) val = self.getObjectType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::CXXRecordDecl CXXMemberCallExpr::RecordDeclaration(void) const {
  auto &self = *const_cast<clang::CXXMemberCallExpr *>(u.CXXMemberCallExpr);
  decltype(auto) val = self.getRecordDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("CXXMemberCallExpr::RecordDeclaration can return nullptr!");
}

std::vector<::pasta::Expr> CXXMemberCallExpr::Arguments(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXMemberCallExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXMemberCallExpr->getArg(i)));
  }
  return ret;
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
  auto &self = *const_cast<clang::CXXNamedCastExpr *>(u.CXXNamedCastExpr);
  decltype(auto) val = self.getAngleBrackets();
  return ast->TokenRangeFrom(val);
}

::pasta::Token CXXNamedCastExpr::BeginToken(void) const {
  auto &self = *const_cast<clang::CXXNamedCastExpr *>(u.CXXNamedCastExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::string_view CXXNamedCastExpr::CastName(void) const {
  auto &self = *const_cast<clang::CXXNamedCastExpr *>(u.CXXNamedCastExpr);
  decltype(auto) val = self.getCastName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("CXXNamedCastExpr::CastName can return nullptr!");
}

::pasta::Token CXXNamedCastExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXNamedCastExpr *>(u.CXXNamedCastExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNamedCastExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::CXXNamedCastExpr *>(u.CXXNamedCastExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXNamedCastExpr::RParenToken(void) const {
  auto &self = *const_cast<clang::CXXNamedCastExpr *>(u.CXXNamedCastExpr);
  decltype(auto) val = self.getRParenLoc();
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
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXOperatorCallExpr::EndToken(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token CXXOperatorCallExpr::ExpressionToken(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.getExprLoc();
  return ast->TokenAt(val);
}

enum OverloadedOperatorKind CXXOperatorCallExpr::Operator(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.getOperator();
  return static_cast<::pasta::OverloadedOperatorKind>(val);
}

::pasta::Token CXXOperatorCallExpr::OperatorToken(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.getOperatorLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange CXXOperatorCallExpr::Tokens(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool CXXOperatorCallExpr::IsAssignmentOperation(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.isAssignmentOp();
  return val;
}

bool CXXOperatorCallExpr::IsComparisonOperation(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.isComparisonOp();
  return val;
}

bool CXXOperatorCallExpr::IsInfixBinaryOperation(void) const {
  auto &self = *const_cast<clang::CXXOperatorCallExpr *>(u.CXXOperatorCallExpr);
  decltype(auto) val = self.isInfixBinaryOp();
  return val;
}

std::vector<::pasta::Expr> CXXOperatorCallExpr::Arguments(void) const {
  std::vector<::pasta::Expr> ret;
  auto convert_elem = [&] (const clang::Expr * val) {
    if (val) {
      return StmtBuilder::Create<::pasta::Expr>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXOperatorCallExpr->getNumArgs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXOperatorCallExpr->getArg(i)));
  }
  return ret;
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
bool CoawaitExpr::IsImplicit(void) const {
  auto &self = *const_cast<clang::CoawaitExpr *>(u.CoawaitExpr);
  decltype(auto) val = self.isImplicit();
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
  auto &self = *const_cast<clang::CXXDynamicCastExpr *>(u.CXXDynamicCastExpr);
  decltype(auto) val = self.isAlwaysNull();
  return val;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
