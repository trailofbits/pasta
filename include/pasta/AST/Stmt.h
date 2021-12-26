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
  virtual void VisitForStmt(const ForStmt &);
  virtual void VisitFullExpr(const FullExpr &);
  virtual void VisitFunctionParmPackExpr(const FunctionParmPackExpr &);
  virtual void VisitGCCAsmStmt(const GCCAsmStmt &);
  virtual void VisitGNUNullExpr(const GNUNullExpr &);
  virtual void VisitGenericSelectionExpr(const GenericSelectionExpr &);
  virtual void VisitGotoStmt(const GotoStmt &);
  virtual void VisitIfStmt(const IfStmt &);
  virtual void VisitImplicitValueInitExpr(const ImplicitValueInitExpr &);
  virtual void VisitIndirectGotoStmt(const IndirectGotoStmt &);
  virtual void VisitInitListExpr(const InitListExpr &);
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
  virtual void VisitOMPIteratorExpr(const OMPIteratorExpr &);
  virtual void VisitObjCAtCatchStmt(const ObjCAtCatchStmt &);
  virtual void VisitObjCAtFinallyStmt(const ObjCAtFinallyStmt &);
  virtual void VisitObjCAtSynchronizedStmt(const ObjCAtSynchronizedStmt &);
  virtual void VisitObjCAtThrowStmt(const ObjCAtThrowStmt &);
  virtual void VisitObjCAtTryStmt(const ObjCAtTryStmt &);
  virtual void VisitObjCAutoreleasePoolStmt(const ObjCAutoreleasePoolStmt &);
  virtual void VisitObjCAvailabilityCheckExpr(const ObjCAvailabilityCheckExpr &);
  virtual void VisitObjCBoolLiteralExpr(const ObjCBoolLiteralExpr &);
  virtual void VisitObjCBoxedExpr(const ObjCBoxedExpr &);
  virtual void VisitObjCEncodeExpr(const ObjCEncodeExpr &);
  virtual void VisitObjCForCollectionStmt(const ObjCForCollectionStmt &);
  virtual void VisitObjCIndirectCopyRestoreExpr(const ObjCIndirectCopyRestoreExpr &);
  virtual void VisitObjCIsaExpr(const ObjCIsaExpr &);
  virtual void VisitObjCIvarRefExpr(const ObjCIvarRefExpr &);
  virtual void VisitObjCMessageExpr(const ObjCMessageExpr &);
  virtual void VisitObjCPropertyRefExpr(const ObjCPropertyRefExpr &);
  virtual void VisitObjCProtocolExpr(const ObjCProtocolExpr &);
  virtual void VisitObjCSelectorExpr(const ObjCSelectorExpr &);
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
  virtual void VisitShuffleVectorExpr(const ShuffleVectorExpr &);
  virtual void VisitSizeOfPackExpr(const SizeOfPackExpr &);
  virtual void VisitSourceLocExpr(const SourceLocExpr &);
  virtual void VisitStmtExpr(const StmtExpr &);
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
  virtual void VisitImplicitCastExpr(const ImplicitCastExpr &);
  virtual void VisitObjCBridgedCastExpr(const ObjCBridgedCastExpr &);
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
  ::pasta::Stmt IgnoreContainers(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // ID: (long long)
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
    const ::clang::ExpressionTraitExpr *ExpressionTraitExpr;
    const ::clang::ExtVectorElementExpr *ExtVectorElementExpr;
    const ::clang::ForStmt *ForStmt;
    const ::clang::FullExpr *FullExpr;
    const ::clang::FunctionParmPackExpr *FunctionParmPackExpr;
    const ::clang::GCCAsmStmt *GCCAsmStmt;
    const ::clang::GNUNullExpr *GNUNullExpr;
    const ::clang::GenericSelectionExpr *GenericSelectionExpr;
    const ::clang::GotoStmt *GotoStmt;
    const ::clang::IfStmt *IfStmt;
    const ::clang::ImplicitCastExpr *ImplicitCastExpr;
    const ::clang::ImplicitValueInitExpr *ImplicitValueInitExpr;
    const ::clang::IndirectGotoStmt *IndirectGotoStmt;
    const ::clang::InitListExpr *InitListExpr;
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
    const ::clang::OMPIteratorExpr *OMPIteratorExpr;
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
    const ::clang::ObjCEncodeExpr *ObjCEncodeExpr;
    const ::clang::ObjCForCollectionStmt *ObjCForCollectionStmt;
    const ::clang::ObjCIndirectCopyRestoreExpr *ObjCIndirectCopyRestoreExpr;
    const ::clang::ObjCIsaExpr *ObjCIsaExpr;
    const ::clang::ObjCIvarRefExpr *ObjCIvarRefExpr;
    const ::clang::ObjCMessageExpr *ObjCMessageExpr;
    const ::clang::ObjCPropertyRefExpr *ObjCPropertyRefExpr;
    const ::clang::ObjCProtocolExpr *ObjCProtocolExpr;
    const ::clang::ObjCSelectorExpr *ObjCSelectorExpr;
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
    const ::clang::ShuffleVectorExpr *ShuffleVectorExpr;
    const ::clang::SizeOfPackExpr *SizeOfPackExpr;
    const ::clang::SourceLocExpr *SourceLocExpr;
    const ::clang::Stmt *Stmt;
    const ::clang::StmtExpr *StmtExpr;
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
  ::pasta::Stmt SubStmt(void) const;
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
  ::pasta::Expr Cond(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclStmt(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt Init(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::SwitchCase SwitchCaseList(void) const;
  ::pasta::Token SwitchToken(void) const;
  bool HasInitStorage(void) const;
  bool HasVarStorage(void) const;
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
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ExpressionTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ExtVectorElementExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, FullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, FunctionParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, GNUNullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, GenericSelectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ImplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ImplicitValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, InitListExpr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCBoxedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCBridgedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCEncodeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCIsaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCIvarRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCMessageExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCProtocolExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ObjCSelectorExpr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, ShuffleVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SizeOfPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SourceLocExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, StmtExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, TypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, TypoExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnresolvedLookupExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, UnresolvedMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueStmt, VAArgExpr)
  ::pasta::Expr ExprStmt(void) const;
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
  ::pasta::Expr Cond(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclStmt(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Token WhileToken(void) const;
  bool HasVarStorage(void) const;
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
  // Begin_inputs: (clang::Stmt::CastIterator<clang::Expr, const clang::Expr *const, const clang::Stmt *const>)
  // Begin_outputs: (clang::Stmt::CastIterator<clang::Expr, const clang::Expr *const, const clang::Stmt *const>)
  std::vector<::pasta::Stmt> Children(void) const;
  // End_inputs: (clang::Stmt::CastIterator<clang::Expr, const clang::Expr *const, const clang::Stmt *const>)
  // End_outputs: (clang::Stmt::CastIterator<clang::Expr, const clang::Expr *const, const clang::Stmt *const>)
  std::string GenerateAsmString(void) const;
  ::pasta::Token AsmToken(void) const;
  ::pasta::Token BeginToken(void) const;
  // Clobber: (llvm::StringRef)
  ::pasta::Token EndToken(void) const;
  // InputConstraint: (llvm::StringRef)
  // InputExpr: (const clang::Expr *)
  uint32_t NumClobbers(void) const;
  uint32_t NumInputs(void) const;
  uint32_t NumOutputs(void) const;
  uint32_t NumPlusOperands(void) const;
  // OutputConstraint: (llvm::StringRef)
  // OutputExpr: (const clang::Expr *)
  std::vector<::pasta::Expr> Inputs(void) const;
  // IsOutputPlusConstraint: (bool)
  bool IsSimple(void) const;
  bool IsVolatile(void) const;
  std::vector<::pasta::Expr> Outputs(void) const;
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
  ::pasta::Token AttrToken(void) const;
  // Attributes: (llvm::ArrayRef<const clang::Attr *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Stmt SubStmt(void) const;
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
  ::pasta::VarDecl ExceptionDecl(void) const;
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
  ::pasta::DeclStmt BeginStmt(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Token CoawaitToken(void) const;
  ::pasta::Token ColonToken(void) const;
  ::pasta::Expr Cond(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::DeclStmt EndStmt(void) const;
  ::pasta::Token ForToken(void) const;
  ::pasta::Expr Inc(void) const;
  ::pasta::Stmt Init(void) const;
  ::pasta::DeclStmt LoopVarStmt(void) const;
  ::pasta::VarDecl LoopVariable(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr RangeInit(void) const;
  ::pasta::DeclStmt RangeStmt(void) const;
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
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CXXTryStmt)
};

static_assert(sizeof(Stmt) == sizeof(CXXTryStmt));

class CapturedStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CapturedStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, CapturedStmt)
  // Capture_inits: (llvm::iterator_range<clang::Expr *const *>)
  // Captures: (llvm::iterator_range<const clang::CapturedStmt::Capture *>)
  // CapturesVariable: (bool)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::CapturedDecl CapturedDecl(void) const;
  ::pasta::RecordDecl CapturedRecordDecl(void) const;
  enum CapturedRegionKind CapturedRegionKind(void) const;
  ::pasta::Stmt FindCapturedStmt(void) const;
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
  bool CaseStmtIsGNURange(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token CaseToken(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Stmt SubStmt(void) const;
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
  ::pasta::Stmt Body_back(void) const;
  ::pasta::Stmt Body_front(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LBracToken(void) const;
  ::pasta::Token RBracToken(void) const;
  ::pasta::Stmt StmtExprResult(void) const;
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
  ::pasta::Stmt FinalSuspendStmt(void) const;
  ::pasta::Stmt InitSuspendStmt(void) const;
  // ParamMoves: (llvm::ArrayRef<const clang::Stmt *>)
  ::pasta::VarDecl PromiseDecl(void) const;
  ::pasta::Stmt PromiseDeclStmt(void) const;
  ::pasta::Stmt ResultDecl(void) const;
  ::pasta::Stmt ReturnStmt(void) const;
  ::pasta::Stmt ReturnStmtOnAllocFailure(void) const;
  ::pasta::Expr ReturnValueInit(void) const;
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
  // DeclGroup: (const clang::DeclGroupRef)
  ::pasta::Token EndToken(void) const;
  ::pasta::Decl SingleDecl(void) const;
  bool IsSingleDecl(void) const;
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
  ::pasta::Stmt SubStmt(void) const;
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
  ::pasta::Expr Cond(void) const;
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
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ExpressionTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ExtVectorElementExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, FullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, FunctionParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, GNUNullExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, GenericSelectionExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ImplicitCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ImplicitValueInitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, InitListExpr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCAvailabilityCheckExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCBoolLiteralExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCBoxedExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCBridgedCastExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCEncodeExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCIndirectCopyRestoreExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCIsaExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCIvarRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCMessageExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCPropertyRefExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCProtocolExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ObjCSelectorExpr)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, ShuffleVectorExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SizeOfPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SourceLocExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, StmtExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SubstNonTypeTemplateParmExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, SubstNonTypeTemplateParmPackExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, TypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, TypoExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnaryExprOrTypeTraitExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnaryOperator)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnresolvedLookupExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, UnresolvedMemberExpr)
  PASTA_DECLARE_DERIVED_OPERATORS(Expr, VAArgExpr)
  // Classify: (clang::Expr::Classification)
  // ClassifyLValue: (clang::Expr::LValueClassification)
  // ClassifyModifiable: (clang::Expr::Classification)
  // EvaluateAsBooleanCondition: (bool)
  // EvaluateAsConstantExpr: (bool)
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
  ::pasta::Expr IgnoreParenBaseCasts(void) const;
  ::pasta::Expr IgnoreParenCasts(void) const;
  ::pasta::Expr IgnoreParenImpCasts(void) const;
  ::pasta::Expr IgnoreParenLValueCasts(void) const;
  ::pasta::Expr IgnoreParenNoopCasts(void) const;
  ::pasta::Expr IgnoreParens(void) const;
  ::pasta::Expr IgnoreUnlessSpelledInSource(void) const;
  bool ContainsErrors(void) const;
  bool ContainsUnexpandedParameterPack(void) const;
  ::pasta::CXXRecordDecl BestDynamicClassType(void) const;
  ::pasta::Expr BestDynamicClassTypeExpr(void) const;
  // Dependence: (clang::ExprDependenceScope::ExprDependence)
  ::pasta::Token ExprToken(void) const;
  // FPFeaturesInEffect: (clang::FPOptions)
  // IntegerConstantExpr: (llvm::Optional<llvm::APSInt>)
  ::pasta::ObjCPropertyRefExpr ObjCProperty(void) const;
  enum ExprObjectKind ObjectKind(void) const;
  ::pasta::Decl ReferencedDeclOfCallee(void) const;
  ::pasta::FieldDecl SourceBitField(void) const;
  ::pasta::Type Type(void) const;
  enum ExprValueKind ValueKind(void) const;
  bool HasNonTrivialCall(void) const;
  bool IsBoundMemberFunction(void) const;
  bool IsCXX11ConstantExpr(void) const;
  bool IsCXX98IntegralConstantExpr(void) const;
  // IsConstantInitializer: (bool)
  bool IsDefaultArgument(void) const;
  bool IsEvaluatable(void) const;
  bool IsGLValue(void) const;
  bool IsImplicitCXXThis(void) const;
  bool IsInstantiationDependent(void) const;
  bool IsIntegerConstantExpr(void) const;
  bool IsKnownToHaveBooleanValue(void) const;
  bool IsLValue(void) const;
  // IsModifiableLvalue: (clang::Expr::isModifiableLvalueResult)
  // IsNullPointerConstant: (clang::Expr::NullPointerConstantKind)
  bool IsOBJCGCCandidate(void) const;
  bool IsObjCSelfExpr(void) const;
  bool IsOrdinaryOrBitFieldObject(void) const;
  bool IsRValue(void) const;
  bool IsReadIfDiscardedInCPlusPlus11(void) const;
  // IsTemporaryObject: (bool)
  bool IsTypeDependent(void) const;
  // IsUnusedResultAWarning: (bool)
  bool IsValueDependent(void) const;
  bool IsXValue(void) const;
  bool RefersToBitField(void) const;
  bool RefersToGlobalRegisterVar(void) const;
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

class ForStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ForStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ForStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Expr Cond(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclStmt(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ForToken(void) const;
  ::pasta::Expr Inc(void) const;
  ::pasta::Stmt Init(void) const;
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
  ::pasta::Expr SubExpr(void) const;
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
  // Begin: (clang::VarDecl *const *)
  std::vector<::pasta::Stmt> Children(void) const;
  // End: (clang::VarDecl *const *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Expansion: (clang::VarDecl *)
  uint32_t NumExpansions(void) const;
  ::pasta::VarDecl ParameterPack(void) const;
  ::pasta::Token ParameterPackLocation(void) const;
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
  // AnalyzeAsmString: (unsigned int)
  // Begin_labels: (clang::Stmt::CastIterator<clang::AddrLabelExpr, const clang::AddrLabelExpr *const, const clang::Stmt *const>)
  // End_labels: (clang::Stmt::CastIterator<clang::AddrLabelExpr, const clang::AddrLabelExpr *const, const clang::Stmt *const>)
  std::string GenerateAsmString(void) const;
  // AsmString: (const clang::StringLiteral *)
  ::pasta::Token BeginToken(void) const;
  // Clobber: (llvm::StringRef)
  // ClobberStringLiteral: (const clang::StringLiteral *)
  ::pasta::Token EndToken(void) const;
  // InputConstraint: (llvm::StringRef)
  // InputConstraintLiteral: (const clang::StringLiteral *)
  // InputExpr: (const clang::Expr *)
  // InputIdentifier: (clang::IdentifierInfo *)
  // InputName: (llvm::StringRef)
  // LabelExpr: (clang::AddrLabelExpr *)
  // LabelIdentifier: (clang::IdentifierInfo *)
  // LabelName: (llvm::StringRef)
  // NamedOperand: (int)
  uint32_t NumLabels(void) const;
  // OutputConstraint: (llvm::StringRef)
  // OutputConstraintLiteral: (const clang::StringLiteral *)
  // OutputExpr: (const clang::Expr *)
  // OutputIdentifier: (clang::IdentifierInfo *)
  // OutputName: (llvm::StringRef)
  ::pasta::Token RParenToken(void) const;
  bool IsAsmGoto(void) const;
  // Labels: (llvm::iterator_range<clang::Stmt::CastIterator<clang::AddrLabelExpr, const clang::AddrLabelExpr *const, const clang::Stmt *const>>)
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
  ::pasta::Token TokenLocation(void) const;
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
  // AssocExprs: (llvm::ArrayRef<clang::Expr *>)
  // AssocTypeSourceInfos: (llvm::ArrayRef<clang::TypeSourceInfo *>)
  // Association: (clang::GenericSelectionExpr::AssociationTy<true>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr ControllingExpr(void) const;
  ::pasta::Token DefaultToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token GenericToken(void) const;
  uint32_t NumAssocs(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr ResultExpr(void) const;
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
  ::pasta::Expr Cond(void) const;
  ::pasta::VarDecl ConditionVariable(void) const;
  ::pasta::DeclStmt ConditionVariableDeclStmt(void) const;
  ::pasta::Stmt Else(void) const;
  ::pasta::Token ElseToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token IfToken(void) const;
  ::pasta::Stmt Init(void) const;
  ::pasta::Token LParenToken(void) const;
  // NondiscardedCase: (llvm::Optional<const clang::Stmt *>)
  ::pasta::Token RParenToken(void) const;
  ::pasta::Stmt Then(void) const;
  bool HasElseStorage(void) const;
  bool HasInitStorage(void) const;
  bool HasVarStorage(void) const;
  bool IsConstexpr(void) const;
  bool IsObjCAvailabilityCheck(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(IfStmt)
};

static_assert(sizeof(Stmt) == sizeof(IfStmt));

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
  // Begin: (clang::Stmt *const *)
  std::vector<::pasta::Stmt> Children(void) const;
  // End: (clang::Stmt *const *)
  ::pasta::Expr ArrayFiller(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  // Init: (const clang::Expr *)
  ::pasta::FieldDecl InitializedFieldInUnion(void) const;
  // Initializers: (clang::Expr *const *)
  ::pasta::Token LBraceToken(void) const;
  uint32_t NumInits(void) const;
  ::pasta::Token RBraceToken(void) const;
  ::pasta::InitListExpr SemanticForm(void) const;
  ::pasta::InitListExpr SyntacticForm(void) const;
  bool HadArrayRangeDesignator(void) const;
  bool HasArrayFiller(void) const;
  // Initializers: (llvm::ArrayRef<clang::Expr *>)
  bool IsExplicit(void) const;
  // IsIdiomaticZeroInitializer: (bool)
  bool IsSemanticForm(void) const;
  bool IsStringLiteralInit(void) const;
  bool IsSyntacticForm(void) const;
  bool IsTransparent(void) const;
  // Rbegin: (std::reverse_iterator<clang::Stmt *const *>)
  // Rend: (std::reverse_iterator<clang::Stmt *const *>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(InitListExpr)
};

static_assert(sizeof(Stmt) == sizeof(InitListExpr));

class LabelStmt : public ValueStmt {
 private:
  using ValueStmt::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LabelStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, LabelStmt)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, LabelStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::LabelDecl Decl(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token IdentToken(void) const;
  std::string_view Name(void) const;
  ::pasta::Stmt SubStmt(void) const;
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
  // Capture_inits: (llvm::iterator_range<clang::Expr *const *>)
  // Captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  std::vector<::pasta::Stmt> Children(void) const;
  // Explicit_captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::CXXMethodDecl CallOperator(void) const;
  enum LambdaCaptureDefault CaptureDefault(void) const;
  ::pasta::Token CaptureDefaultToken(void) const;
  ::pasta::CompoundStmt CompoundStmtBody(void) const;
  ::pasta::FunctionTemplateDecl DependentCallOperator(void) const;
  ::pasta::Token EndToken(void) const;
  std::vector<::pasta::NamedDecl> ExplicitTemplateParameters(void) const;
  ::pasta::TokenRange IntroducerRange(void) const;
  ::pasta::CXXRecordDecl LambdaClass(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
  ::pasta::Expr TrailingRequiresClause(void) const;
  bool HasExplicitParameters(void) const;
  bool HasExplicitResultType(void) const;
  // Implicit_captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  bool IsGenericLambda(void) const;
  // IsInitCapture: (bool)
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
  std::string GenerateAsmString(void) const;
  // AllConstraints: (llvm::ArrayRef<llvm::StringRef>)
  // AllExprs: (llvm::ArrayRef<clang::Expr *>)
  std::string_view AsmString(void) const;
  ::pasta::Token BeginToken(void) const;
  // Clobber: (llvm::StringRef)
  // Clobbers: (llvm::ArrayRef<llvm::StringRef>)
  ::pasta::Token EndToken(void) const;
  // InputConstraint: (llvm::StringRef)
  // InputExpr: (const clang::Expr *)
  ::pasta::Token LBraceToken(void) const;
  // OutputConstraint: (llvm::StringRef)
  // OutputExpr: (const clang::Expr *)
  bool HasBraces(void) const;
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
  ::pasta::CompoundStmt SubStmt(void) const;
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
  ::pasta::Expr BaseExpr(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token MemberToken(void) const;
  ::pasta::MSPropertyDecl PropertyDecl(void) const;
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
  ::pasta::Token ExprToken(void) const;
  ::pasta::Expr Idx(void) const;
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
  ::pasta::ValueDecl ExtendingDecl(void) const;
  ::pasta::LifetimeExtendedTemporaryDecl LifetimeExtendedTemporaryDecl(void) const;
  uint32_t ManglingNumber(void) const;
  // OrCreateValue: (clang::APValue *)
  enum StorageDuration StorageDuration(void) const;
  ::pasta::Expr SubExpr(void) const;
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
  ::pasta::Expr ColumnIdx(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExprToken(void) const;
  ::pasta::Token RBracketToken(void) const;
  ::pasta::Expr RowIdx(void) const;
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
  ::pasta::Token ExprToken(void) const;
  // FoundDecl: (clang::DeclAccessPair)
  ::pasta::Token LAngleToken(void) const;
  ::pasta::ValueDecl MemberDecl(void) const;
  ::pasta::Token MemberToken(void) const;
  // MemberNameInfo: (clang::DeclarationNameInfo)
  uint32_t NumTemplateArgs(void) const;
  ::pasta::Token OperatorToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArgs: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HadMultipleCandidates(void) const;
  bool HasExplicitTemplateArgs(void) const;
  bool HasQualifier(void) const;
  bool HasTemplateKeyword(void) const;
  bool IsArrow(void) const;
  bool IsImplicitAccess(void) const;
  enum NonOdrUseReason IsNonOdrUse(void) const;
  // PerformsVirtualDispatch: (bool)
  // Template_arguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
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
  ::pasta::Token ColonLocFirst(void) const;
  ::pasta::Token ColonLocSecond(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExprToken(void) const;
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
  // BracketsRanges: (llvm::ArrayRef<clang::SourceRange>)
  // Dimensions: (llvm::ArrayRef<clang::Expr *>)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(OMPArrayShapingExpr)
};

static_assert(sizeof(Stmt) == sizeof(OMPArrayShapingExpr));

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
  // IteratorDecl: (const clang::Decl *)
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

class ObjCAtCatchStmt : public Stmt {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtCatchStmt)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCAtCatchStmt)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::Token AtCatchToken(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Stmt CatchBody(void) const;
  ::pasta::VarDecl CatchParamDecl(void) const;
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
  ::pasta::Expr SynchExpr(void) const;
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
  ::pasta::Expr ThrowExpr(void) const;
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
  // CatchStmt: (const clang::ObjCAtCatchStmt *)
  ::pasta::Token EndToken(void) const;
  ::pasta::ObjCAtFinallyStmt FinallyStmt(void) const;
  uint32_t NumCatchStmts(void) const;
  ::pasta::Stmt TryBody(void) const;
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
  ::pasta::Stmt SubStmt(void) const;
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
  ::pasta::Expr SubExpr(void) const;
  bool IsExpressibleAsConstantInitializer(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCBoxedExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCBoxedExpr));

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
  ::pasta::Token ExprToken(void) const;
  ::pasta::Expr SubExpr(void) const;
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
  ::pasta::Token BaseLocEnd(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExprToken(void) const;
  ::pasta::Token IsaMemberToken(void) const;
  ::pasta::Token OpToken(void) const;
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
  ::pasta::ObjCIvarDecl Decl(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  ::pasta::Token OpToken(void) const;
  bool IsArrow(void) const;
  bool IsFreeIvar(void) const;
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
  // Arg: (const clang::Expr *)
  // Args: (const clang::Expr *const *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Type CallReturnType(void) const;
  ::pasta::Type ClassReceiver(void) const;
  // ClassReceiverTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr InstanceReceiver(void) const;
  ::pasta::Token LeftToken(void) const;
  ::pasta::ObjCMethodDecl MethodDecl(void) const;
  enum ObjCMethodFamily MethodFamily(void) const;
  uint32_t NumArgs(void) const;
  uint32_t NumSelectorLocs(void) const;
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
  bool IsDelegateInitCall(void) const;
  bool IsImplicit(void) const;
  bool IsInstanceMessage(void) const;
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
  ::pasta::Token ReceiverLocation(void) const;
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
  uint32_t NumArgs(void) const;
  ::pasta::Token RParenToken(void) const;
  // Selector: (clang::Selector)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(ObjCSelectorExpr)
};

static_assert(sizeof(Stmt) == sizeof(ObjCSelectorExpr));

class ObjCSubscriptRefExpr : public Expr {
 private:
  using Expr::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCSubscriptRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Expr, ObjCSubscriptRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(Stmt, ObjCSubscriptRefExpr)
  PASTA_DECLARE_BASE_OPERATORS(ValueStmt, ObjCSubscriptRefExpr)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::ObjCMethodDecl AtIndexMethodDecl(void) const;
  ::pasta::Expr BaseExpr(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr KeyExpr(void) const;
  ::pasta::Token RBracket(void) const;
  bool IsArraySubscriptRefExpr(void) const;
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
  // IndexExpr: (const clang::Expr *)
  uint32_t NumComponents(void) const;
  uint32_t NumExpressions(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Token RParenToken(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
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
  ::pasta::Token ExprToken(void) const;
  ::pasta::Token Token(void) const;
  ::pasta::Expr SourceExpr(void) const;
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
  uint32_t NumDecls(void) const;
  uint32_t NumTemplateArgs(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArgs: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HasExplicitTemplateArgs(void) const;
  bool HasTemplateKeyword(void) const;
  // Template_arguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
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
  ::pasta::Expr SubExpr(void) const;
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
  // Expr: (const clang::Expr *)
  ::pasta::Token LParenToken(void) const;
  uint32_t NumExprs(void) const;
  ::pasta::Token RParenToken(void) const;
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
  // FunctionName: (const clang::StringLiteral *)
  // IdentKind: (clang::PredefinedExpr::IdentKind)
  std::string_view IdentKindName(void) const;
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
  ::pasta::Token ExprToken(void) const;
  uint32_t NumSemanticExprs(void) const;
  ::pasta::Expr ResultExpr(void) const;
  uint32_t ResultExprIndex(void) const;
  // SemanticExpr: (const clang::Expr *)
  ::pasta::Expr SyntacticForm(void) const;
  // Semantics: (llvm::iterator_range<const clang::Expr *const *>)
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
  // SubExpressions: (llvm::ArrayRef<const clang::Expr *>)
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
  ::pasta::Expr FilterExpr(void) const;
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
  // Expr: (const clang::Expr *)
  uint32_t NumSubExprs(void) const;
  ::pasta::Token RParenToken(void) const;
  // ShuffleMaskIdx: (llvm::APSInt)
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
  std::string_view BuiltinStr(void) const;
  ::pasta::Token EndToken(void) const;
  // IdentKind: (clang::SourceLocExpr::IdentKind)
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
  ::pasta::CompoundStmt SubStmt(void) const;
  uint32_t TemplateDepth(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(StmtExpr)
};

static_assert(sizeof(Stmt) == sizeof(StmtExpr));

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
  ::pasta::Token ParameterPackLocation(void) const;
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
  // Arg: (clang::TypeSourceInfo *)
  // Args: (llvm::ArrayRef<clang::TypeSourceInfo *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  uint32_t NumArgs(void) const;
  enum TypeTrait Trait(void) const;
  bool Value(void) const;
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
  ::pasta::Expr ArgumentExpr(void) const;
  ::pasta::Type ArgumentType(void) const;
  // ArgumentTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
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
  ::pasta::Token ExprToken(void) const;
  // FPFeaturesInEffect: (clang::FPOptions)
  // FPOptionsOverride: (clang::FPOptionsOverride)
  enum UnaryOperatorKind Opcode(void) const;
  ::pasta::Token OperatorToken(void) const;
  // StoredFPFeatures: (clang::FPOptionsOverride)
  ::pasta::Expr SubExpr(void) const;
  bool HasStoredFPFeatures(void) const;
  bool IsArithmeticOp(void) const;
  bool IsDecrementOp(void) const;
  // IsFEnvAccessOn: (bool)
  // IsFPContractableWithinStatement: (bool)
  bool IsIncrementDecrementOp(void) const;
  bool IsIncrementOp(void) const;
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
  ::pasta::Token ExprToken(void) const;
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
  ::pasta::Expr SubExpr(void) const;
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
  ::pasta::Expr Cond(void) const;
  ::pasta::Expr FalseExpr(void) const;
  ::pasta::Token QuestionToken(void) const;
  ::pasta::Expr TrueExpr(void) const;
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
  ::pasta::OpaqueValueExpr CommonExpr(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr SubExpr(void) const;
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
  ::pasta::Token ExprToken(void) const;
  ::pasta::Expr Idx(void) const;
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
  // Value: (unsigned long long)
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
  ::pasta::Expr SrcExpr(void) const;
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
  uint32_t NumSubExprs(void) const;
  // Op: (clang::AtomicExpr::AtomicOp)
  ::pasta::Expr Order(void) const;
  ::pasta::Expr OrderFail(void) const;
  ::pasta::Expr Ptr(void) const;
  ::pasta::Token RParenToken(void) const;
  ::pasta::Expr Scope(void) const;
  // ScopeModel: (std::unique_ptr<clang::AtomicScopeModel, std::default_delete<clang::AtomicScopeModel>>)
  // SubExprs: (const clang::Expr *const *)
  ::pasta::Expr Val1(void) const;
  ::pasta::Expr Val2(void) const;
  ::pasta::Type ValueType(void) const;
  ::pasta::Expr Weak(void) const;
  bool IsCmpXChg(void) const;
  bool IsOpenCL(void) const;
  bool IsVolatile(void) const;
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
  ::pasta::Expr Cond(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr FalseExpr(void) const;
  ::pasta::OpaqueValueExpr OpaqueValue(void) const;
  ::pasta::Expr TrueExpr(void) const;
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
  ::pasta::Token ExprToken(void) const;
  // FPFeatures: (clang::FPOptionsOverride)
  // FPFeaturesInEffect: (clang::FPOptions)
  ::pasta::Expr LHS(void) const;
  enum BinaryOperatorKind Opcode(void) const;
  std::string_view OpcodeStr(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Expr RHS(void) const;
  // StoredFPFeatures: (clang::FPOptionsOverride)
  bool HasStoredFPFeatures(void) const;
  bool IsAdditiveOp(void) const;
  bool IsAssignmentOp(void) const;
  bool IsBitwiseOp(void) const;
  bool IsCommaOp(void) const;
  bool IsComparisonOp(void) const;
  bool IsCompoundAssignmentOp(void) const;
  bool IsEqualityOp(void) const;
  // IsFEnvAccessOn: (bool)
  // IsFPContractableWithinStatement: (bool)
  bool IsLogicalOp(void) const;
  bool IsMultiplicativeOp(void) const;
  bool IsPtrMemOp(void) const;
  bool IsRelationalOp(void) const;
  bool IsShiftAssignOp(void) const;
  bool IsShiftOp(void) const;
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
  ::pasta::BlockDecl BlockDecl(void) const;
  ::pasta::Stmt Body(void) const;
  ::pasta::Token CaretLocation(void) const;
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
  ::pasta::Expr SubExpr(void) const;
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
  // Arg: (const clang::Expr *)
  // Args: (const clang::Expr *const *)
  ::pasta::Token BeginToken(void) const;
  // ConstructionKind: (clang::CXXConstructExpr::ConstructionKind)
  ::pasta::CXXConstructorDecl Constructor(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  uint32_t NumArgs(void) const;
  ::pasta::TokenRange ParenOrBraceRange(void) const;
  bool HadMultipleCandidates(void) const;
  bool IsElidable(void) const;
  bool IsListInitialization(void) const;
  bool IsStdInitListInitialization(void) const;
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
  ::pasta::Expr Expr(void) const;
  ::pasta::Token ExprToken(void) const;
  ::pasta::ParmVarDecl Param(void) const;
  ::pasta::DeclContext UsedContext(void) const;
  ::pasta::Token UsedLocation(void) const;
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
  ::pasta::Expr Expr(void) const;
  ::pasta::FieldDecl Field(void) const;
  ::pasta::DeclContext UsedContext(void) const;
  ::pasta::Token UsedLocation(void) const;
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
  uint32_t NumTemplateArgs(void) const;
  ::pasta::Token OperatorToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArgs: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HasExplicitTemplateArgs(void) const;
  bool HasTemplateKeyword(void) const;
  bool IsArrow(void) const;
  bool IsImplicitAccess(void) const;
  // Template_arguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
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
  ::pasta::Expr Init(void) const;
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
  bool ConstructsVBase(void) const;
  ::pasta::Token BeginToken(void) const;
  // ConstructionKind: (clang::CXXConstructExpr::ConstructionKind)
  ::pasta::CXXConstructorDecl Constructor(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token Token(void) const;
  bool InheritedFromVBase(void) const;
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
  // ArraySize: (llvm::Optional<const clang::Expr *>)
  ::pasta::Token BeginToken(void) const;
  ::pasta::CXXConstructExpr ConstructExpr(void) const;
  ::pasta::TokenRange DirectInitRange(void) const;
  ::pasta::Token EndToken(void) const;
  // InitializationStyle: (clang::CXXNewExpr::InitializationStyle)
  ::pasta::Expr Initializer(void) const;
  uint32_t NumPlacementArgs(void) const;
  ::pasta::FunctionDecl OperatorDelete(void) const;
  ::pasta::FunctionDecl OperatorNew(void) const;
  // PlacementArg: (const clang::Expr *)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::TokenRange TypeIdParens(void) const;
  bool HasInitializer(void) const;
  bool IsArray(void) const;
  bool IsGlobalNew(void) const;
  bool IsParenTypeId(void) const;
  bool PassAlignment(void) const;
  std::vector<::pasta::Expr> Placement_arguments(void) const;
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
  ::pasta::Token ExprToken(void) const;
  ::pasta::Expr LHS(void) const;
  enum BinaryOperatorKind Opcode(void) const;
  std::string_view OpcodeStr(void) const;
  enum BinaryOperatorKind Operator(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Expr SemanticForm(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsAssignmentOp(void) const;
  bool IsComparisonOp(void) const;
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
  ::pasta::Expr SubExpr(void) const;
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
  ::pasta::Expr SubExpr(void) const;
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
  ::pasta::Expr ExprOperand(void) const;
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
  // Arguments: (llvm::iterator_range<const clang::Expr *const *>)
  std::vector<::pasta::Stmt> Children(void) const;
  // Arg: (const clang::Expr *)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LParenToken(void) const;
  uint32_t NumArgs(void) const;
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
  ::pasta::Expr ExprOperand(void) const;
  ::pasta::MSGuidDecl GuidDecl(void) const;
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
  std::vector<::pasta::Expr> Arguments(void) const;
  std::vector<::pasta::Stmt> Children(void) const;
  // ADLCallKind: (clang::CallExpr::ADLCallKind)
  // Arg: (const clang::Expr *)
  // Args: (const clang::Expr *const *)
  ::pasta::Token BeginToken(void) const;
  uint32_t BuiltinCallee(void) const;
  ::pasta::Type CallReturnType(void) const;
  ::pasta::Expr Callee(void) const;
  ::pasta::Decl CalleeDecl(void) const;
  ::pasta::FunctionDecl DirectCallee(void) const;
  ::pasta::Token EndToken(void) const;
  // FPFeatures: (clang::FPOptionsOverride)
  // FPFeaturesInEffect: (clang::FPOptions)
  uint32_t NumArgs(void) const;
  uint32_t NumCommas(void) const;
  ::pasta::Token RParenToken(void) const;
  // StoredFPFeatures: (clang::FPOptionsOverride)
  // UnusedResultAttr: (const clang::Attr *)
  bool HasStoredFPFeatures(void) const;
  bool HasUnusedResultAttr(void) const;
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
  ::pasta::Expr SubExpr(void) const;
  ::pasta::Expr SubExprAsWritten(void) const;
  ::pasta::FieldDecl TargetUnionField(void) const;
  bool HasStoredFPFeatures(void) const;
  // Path: (llvm::iterator_range<const clang::CXXBaseSpecifier *const *>)
 protected:
  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(CastExpr)
};

static_assert(sizeof(Stmt) == sizeof(CastExpr));

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
  ::pasta::Expr ChosenSubExpr(void) const;
  ::pasta::Expr Cond(void) const;
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
  ::pasta::Expr Cond(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Expr FalseExpr(void) const;
  ::pasta::Expr LHS(void) const;
  ::pasta::Expr RHS(void) const;
  ::pasta::Expr TrueExpr(void) const;
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
  // ResultAPValueKind: (clang::APValue::ValueKind)
  // ResultAsAPSInt: (llvm::APSInt)
  // ResultAsAPValue: (clang::APValue &)
  // ResultStorageKind: (clang::ConstantExpr::ResultStorageKind)
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
  ::pasta::Expr SrcExpr(void) const;
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
  ::pasta::Expr CommonExpr(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::Token KeywordToken(void) const;
  ::pasta::OpaqueValueExpr OpaqueValue(void) const;
  ::pasta::Expr ReadyExpr(void) const;
  ::pasta::Expr ResumeExpr(void) const;
  ::pasta::Expr SuspendExpr(void) const;
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
  ::pasta::ValueDecl Decl(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::NamedDecl FoundDecl(void) const;
  ::pasta::Token LAngleToken(void) const;
  ::pasta::Token Token(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  uint32_t NumTemplateArgs(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArgs: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HadMultipleCandidates(void) const;
  bool HasExplicitTemplateArgs(void) const;
  bool HasQualifier(void) const;
  bool HasTemplateKWAndArgsInfo(void) const;
  bool HasTemplateKeyword(void) const;
  enum NonOdrUseReason IsNonOdrUse(void) const;
  bool RefersToEnclosingVariableOrCapture(void) const;
  // Template_arguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
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
  // DeclName: (clang::DeclarationName)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token LAngleToken(void) const;
  ::pasta::Token Token(void) const;
  // NameInfo: (const clang::DeclarationNameInfo &)
  uint32_t NumTemplateArgs(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token RAngleToken(void) const;
  // TemplateArgs: (const clang::TemplateArgumentLoc *)
  ::pasta::Token TemplateKeywordToken(void) const;
  bool HasExplicitTemplateArgs(void) const;
  bool HasTemplateKeyword(void) const;
  // Template_arguments: (llvm::ArrayRef<clang::TemplateArgumentLoc>)
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
  ::pasta::Expr Init(void) const;
  uint32_t NumSubExprs(void) const;
  // SubExpr: (clang::Expr *)
  bool IsDirectInit(void) const;
  uint32_t Size(void) const;
  bool UsesGNUSyntax(void) const;
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
  ::pasta::Token ExprToken(void) const;
  ::pasta::Expr ImplicitObjectArgument(void) const;
  ::pasta::CXXMethodDecl MethodDecl(void) const;
  ::pasta::Type ObjectType(void) const;
  ::pasta::CXXRecordDecl RecordDecl(void) const;
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
  ::pasta::Token ExprToken(void) const;
  enum OverloadedOperatorKind Operator(void) const;
  ::pasta::Token OperatorToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsAssignmentOp(void) const;
  bool IsComparisonOp(void) const;
  bool IsInfixBinaryOp(void) const;
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
