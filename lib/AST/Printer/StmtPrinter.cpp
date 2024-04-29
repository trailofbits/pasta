//===- StmtPrinter.cpp - Printing implementation for Stmt ASTs ------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the Stmt::dumpPretty/Stmt::printPretty methods, which
// pretty print the AST back out to C code.
//
//===----------------------------------------------------------------------===//

#include "DeclStmtPrinter.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wcast-align"
#include <llvm/ADT/StringExtras.h>
#pragma GCC diagnostic pop

//===----------------------------------------------------------------------===//
//  Stmt printing methods.
//===----------------------------------------------------------------------===//

/// PrintRawCompoundStmt - Print a compound stmt without indenting the {, and
/// with no newline after the }.
namespace pasta {

void StmtPrinter::printQualType(clang::QualType type_,
                                raw_string_ostream &OS,
                                const clang::PrintingPolicy &Policy){
  TypePrinter(OS, Policy, tokens, 0).print(type_, "");
}

void StmtPrinter::printQualType(
    clang::QualType type_, raw_string_ostream &OS,
    const clang::PrintingPolicy &Policy,
    std::function<void(void)> *PlaceHolderFn,
    unsigned Indentation) {
  TypePrinter(OS, Policy, tokens, Indentation).print(type_, "", PlaceHolderFn);
}

void StmtPrinter::PrintRawCompoundStmt(clang::CompoundStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "{";
  ctx.MarkLocation(Node->getLBracLoc());

  PrintFPPragmas(Node);
  OS << NL;
  for (auto *I : Node->body())
    PrintStmt(I);

  Indent() << "}";
  ctx.MarkLocation(Node->getRBracLoc());
}


void StmtPrinter::PrintFPPragmas(clang::CompoundStmt *S) {
  if (!S->hasStoredFPFeatures())
    return;
  clang::FPOptionsOverride FPO = S->getStoredFPFeatures();
  bool FEnvAccess = false;
  if (FPO.hasAllowFEnvAccessOverride()) {
    FEnvAccess = FPO.getAllowFEnvAccessOverride();
    Indent() << "#pragma STDC FENV_ACCESS " << (FEnvAccess ? "ON" : "OFF")
             << NL;
  }
  if (FPO.hasSpecifiedExceptionModeOverride()) {
    clang::LangOptions::FPExceptionModeKind EM =
        FPO.getSpecifiedExceptionModeOverride();
    if (!FEnvAccess || EM != clang::LangOptions::FPE_Strict) {
      Indent() << "#pragma clang fp exceptions(";
      switch (FPO.getSpecifiedExceptionModeOverride()) {
      default:
        break;
      case clang::LangOptions::FPE_Ignore:
        OS << "ignore";
        break;
      case clang::LangOptions::FPE_MayTrap:
        OS << "maytrap";
        break;
      case clang::LangOptions::FPE_Strict:
        OS << "strict";
        break;
      }
      OS << ")\n";
    }
  }
  if (FPO.hasConstRoundingModeOverride()) {
    clang::LangOptions::RoundingMode RM = FPO.getConstRoundingModeOverride();
    Indent() << "#pragma STDC FENV_ROUND ";
    switch (RM) {
    case llvm::RoundingMode::TowardZero:
      OS << "FE_TOWARDZERO";
      break;
    case llvm::RoundingMode::NearestTiesToEven:
      OS << "FE_TONEAREST";
      break;
    case llvm::RoundingMode::TowardPositive:
      OS << "FE_UPWARD";
      break;
    case llvm::RoundingMode::TowardNegative:
      OS << "FE_DOWNWARD";
      break;
    case llvm::RoundingMode::NearestTiesToAway:
      OS << "FE_TONEARESTFROMZERO";
      break;
    case llvm::RoundingMode::Dynamic:
      OS << "FE_DYNAMIC";
      break;
    default:
      llvm_unreachable("Invalid rounding mode");
    }
    OS << NL;
  }
}

void StmtPrinter::printDecl(clang::Decl *D,
                            raw_string_ostream &Out,
                            const clang::PrintingPolicy &policy_,
                            unsigned Indentation) {
  DeclPrinter Printer(Out, policy_, D->getASTContext(), tokens, Indentation);
  Printer.Visit(D);
}


void StmtPrinter::PrintRawDecl(clang::Decl *D) {
  DeclPrinter Printer(OS, Policy, D->getASTContext(), tokens, IndentLevel);
  Printer.Visit(D);
}

void StmtPrinter::PrintRawDeclStmt(const clang::DeclStmt *S) {
  TokenPrinterContext ctx(OS, S, tokens);
  clang::SmallVector<clang::Decl *, 2> Decls(S->decls());
  Decl_printGroup(Decls.data(), Decls.size(), OS, Policy, IndentLevel, tokens);
}

void StmtPrinter::VisitNullStmt(clang::NullStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << ";";
  ctx.MarkLocation(Node->getEndLoc());
  OS << NL;
}

void StmtPrinter::VisitDeclStmt(clang::DeclStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent();
  PrintRawDeclStmt(Node);
  OS << ";";
//  ctx.MarkLocation(Node->getEndLoc());
  OS << NL;
}

void StmtPrinter::VisitCompoundStmt(clang::CompoundStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent();
  PrintRawCompoundStmt(Node);
  OS << "" << NL;
}

void StmtPrinter::VisitCaseStmt(clang::CaseStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent(-1) << "case ";
  ctx.MarkLocation(Node->getCaseLoc());
  PrintExpr(Node->getLHS());
  if (Node->getRHS()) {
    OS << " ... ";
    ctx.MarkLocation(Node->getEllipsisLoc());
    PrintExpr(Node->getRHS());
  }
  OS << ":" << NL;

  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::VisitDefaultStmt(clang::DefaultStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent(-1) << "default";
  ctx.MarkLocation(Node->getDefaultLoc());
  OS << ":";
  OS << NL;
  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::VisitLabelStmt(clang::LabelStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent(-1) << Node->getName();
  ctx.MarkLocation(Node->getIdentLoc());
  OS << ":" << NL;
  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::VisitAttributedStmt(clang::AttributedStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  for (const auto *Attr : Node->getAttrs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    PrintAttribute(OS, Attr, tokens, Policy);
  }

  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::PrintRawIfStmt(clang::IfStmt *If) {
  TokenPrinterContext ctx(OS, If, tokens);
  OS << "if ";
  ctx.MarkLocation(If->getIfLoc());
  OS << "(";
  ctx.MarkLocation(If->getLParenLoc());
  if (If->getInit())
    PrintInitStmt(If->getInit(), 4);
  if (const clang::DeclStmt *DS = If->getConditionVariableDeclStmt())
    PrintRawDeclStmt(DS);
  else
    PrintExpr(If->getCond());
  OS << ')';
  ctx.MarkLocation(If->getRParenLoc());

  if (auto *CS = clang::dyn_cast<clang::CompoundStmt>(If->getThen())) {
    OS << ' ';
    PrintRawCompoundStmt(CS);
    OS << (If->getElse() ? " " : NL);
  } else {
    OS << NL;
    PrintStmt(If->getThen());
    if (If->getElse()) Indent();
  }

  if (clang::Stmt *Else = If->getElse()) {
    OS << "else";
    ctx.MarkLocation(If->getElseLoc());

    if (auto *CS = clang::dyn_cast<clang::CompoundStmt>(Else)) {
      OS << ' ';
      PrintRawCompoundStmt(CS);
      OS << NL;
    } else if (auto *ElseIf = clang::dyn_cast<clang::IfStmt>(Else)) {
      OS << ' ';
      PrintRawIfStmt(ElseIf);
    } else {
      OS << NL;
      PrintStmt(If->getElse());
    }
  }
}

void StmtPrinter::VisitIfStmt(clang::IfStmt *If) {
  TokenPrinterContext ctx(OS, If, tokens);
  Indent();
  PrintRawIfStmt(If);
}

void StmtPrinter::VisitSwitchStmt(clang::SwitchStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "switch ";
  ctx.MarkLocation(Node->getSwitchLoc());
  OS << "(";
  ctx.MarkLocation(Node->getLParenLoc());
  if (Node->getInit())
    PrintInitStmt(Node->getInit(), 8);
  if (const clang::DeclStmt *DS = Node->getConditionVariableDeclStmt())
    PrintRawDeclStmt(DS);
  else
    PrintExpr(Node->getCond());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitWhileStmt(clang::WhileStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "while";
  ctx.MarkLocation(Node->getWhileLoc());
  OS << "(";
  ctx.MarkLocation(Node->getLParenLoc());
  if (const clang::DeclStmt *DS = Node->getConditionVariableDeclStmt())
    PrintRawDeclStmt(DS);
  else
    PrintExpr(Node->getCond());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  OS << NL;
  PrintStmt(Node->getBody());
}

void StmtPrinter::VisitDoStmt(clang::DoStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "do ";
  ctx.MarkLocation(Node->getDoLoc());
  if (auto *CS = clang::dyn_cast<clang::CompoundStmt>(Node->getBody())) {
    PrintRawCompoundStmt(CS);
    OS << " ";
  } else {
    OS << NL;
    PrintStmt(Node->getBody());
    Indent();
  }

  OS << "while";
  ctx.MarkLocation(Node->getWhileLoc());
  OS << "(";
  PrintExpr(Node->getCond());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  OS << ";" << NL;
}

void StmtPrinter::VisitForStmt(clang::ForStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "for ";
  ctx.MarkLocation(Node->getForLoc());
  OS << "(";
  ctx.MarkLocation(Node->getLParenLoc());
  if (Node->getInit())
    PrintInitStmt(Node->getInit(), 5);
  else
    OS << (Node->getCond() ? "; " : ";");
  if (Node->getCond())
    PrintExpr(Node->getCond());
  OS << ";";
  if (Node->getInc()) {
    OS << " ";
    PrintExpr(Node->getInc());
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitObjCForCollectionStmt(clang::ObjCForCollectionStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "for ";
  ctx.MarkLocation(Node->getForLoc());
  OS << "(";
  if (auto *DS = clang::dyn_cast<clang::DeclStmt>(Node->getElement()))
    PrintRawDeclStmt(DS);
  else
    PrintExpr(clang::cast<clang::Expr>(Node->getElement()));
  OS << " in ";
  PrintExpr(Node->getCollection());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitCXXForRangeStmt(clang::CXXForRangeStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "for ";
  ctx.MarkLocation(Node->getForLoc());
  OS << "(";
  if (Node->getInit())
    PrintInitStmt(Node->getInit(), 5);
  clang::PrintingPolicy SubPolicy(Policy);
  SubPolicy.SuppressInitializers = true;
  printDecl(Node->getLoopVariable(), OS, SubPolicy, IndentLevel);
  OS << " : ";
  ctx.MarkLocation(Node->getColonLoc());
  PrintExpr(Node->getRangeInit());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitMSDependentExistsStmt(clang::MSDependentExistsStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent();
  if (Node->isIfExists())
    OS << "__if_exists (";
  else
    OS << "__if_not_exists (";

  if (clang::NestedNameSpecifier *Qualifier
        = Node->getQualifierLoc().getNestedNameSpecifier())
    NestedNameSpecifier_print(Qualifier, *this, Policy);

  OS << Node->getNameInfo() << ") ";

  PrintRawCompoundStmt(Node->getSubStmt());
}

void StmtPrinter::VisitGotoStmt(clang::GotoStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "goto ";
  ctx.MarkLocation(Node->getGotoLoc());
  OS << Node->getLabel()->getName();
  ctx.MarkLocation(Node->getLabelLoc());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitIndirectGotoStmt(clang::IndirectGotoStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "goto ";
  ctx.MarkLocation(Node->getGotoLoc());
  OS << "*";
  ctx.MarkLocation(Node->getStarLoc());
  PrintExpr(Node->getTarget());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitContinueStmt(clang::ContinueStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "continue";
  ctx.MarkLocation(Node->getContinueLoc());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitBreakStmt(clang::BreakStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "break";
  ctx.MarkLocation(Node->getBreakLoc());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitReturnStmt(clang::ReturnStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "return";
  ctx.MarkLocation(Node->getReturnLoc());
  if (Node->getRetValue()) {
    OS << " ";
    PrintExpr(Node->getRetValue());
  }
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitGCCAsmStmt(clang::GCCAsmStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "asm ";

  if (Node->isVolatile())
    OS << "volatile ";

  if (Node->isAsmGoto())
    OS << "goto ";

  OS << "(";
  VisitStringLiteral(Node->getAsmString());

  // Outputs
  if (Node->getNumOutputs() != 0 || Node->getNumInputs() != 0 ||
      Node->getNumClobbers() != 0 || Node->getNumLabels() != 0)
    OS << " : ";

  for (unsigned i = 0, e = Node->getNumOutputs(); i != e; ++i) {
    if (i != 0)
      OS << ", ";

    if (!Node->getOutputName(i).empty()) {
      OS << '[';
      OS << Node->getOutputName(i);
      OS << "] ";
    }

    VisitStringLiteral(Node->getOutputConstraintLiteral(i));
    OS << " (";
    Visit(Node->getOutputExpr(i));
    OS << ")";
  }

  // Inputs
  if (Node->getNumInputs() != 0 || Node->getNumClobbers() != 0 ||
      Node->getNumLabels() != 0)
    OS << " : ";

  for (unsigned i = 0, e = Node->getNumInputs(); i != e; ++i) {
    if (i != 0)
      OS << ", ";

    if (!Node->getInputName(i).empty()) {
      OS << '[';
      OS << Node->getInputName(i);
      OS << "] ";
    }

    VisitStringLiteral(Node->getInputConstraintLiteral(i));
    OS << " (";
    Visit(Node->getInputExpr(i));
    OS << ")";
  }

  // Clobbers
  if (Node->getNumClobbers() != 0 || Node->getNumLabels())
    OS << " : ";

  for (unsigned i = 0, e = Node->getNumClobbers(); i != e; ++i) {
    if (i != 0)
      OS << ", ";

    VisitStringLiteral(Node->getClobberStringLiteral(i));
  }

  // Labels
  if (Node->getNumLabels() != 0)
    OS << " : ";

  for (unsigned i = 0, e = Node->getNumLabels(); i != e; ++i) {
    if (i != 0)
      OS << ", ";

    TokenPrinterContext label_ctx(OS, Node->getLabelExpr(i), tokens);
    OS << Node->getLabelName(i);
  }

  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitMSAsmStmt(clang::MSAsmStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // FIXME: Implement MS style inline asm statement printer.
  Indent() << "__asm ";
  ctx.MarkLocation(Node->getAsmLoc());
  if (Node->hasBraces()) {
    OS << "{";
    ctx.MarkLocation(Node->getLBraceLoc());
    OS << NL;
  }
  OS << Node->getAsmString() << NL;
  if (Node->hasBraces()) {
    Indent() << "}" << NL;
  }
}

void StmtPrinter::VisitCapturedStmt(clang::CapturedStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintStmt(Node->getCapturedDecl()->getBody());
}

void StmtPrinter::VisitObjCAtTryStmt(clang::ObjCAtTryStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "@try";
  ctx.MarkLocation(Node->getAtTryLoc());

  if (auto *TS = clang::dyn_cast<clang::CompoundStmt>(Node->getTryBody())) {
    PrintRawCompoundStmt(TS);
    OS << NL;
  }

  for (unsigned I = 0, N = Node->getNumCatchStmts(); I != N; ++I) {
    clang::ObjCAtCatchStmt *catchStmt = Node->getCatchStmt(I);
    Indent() << "@catch";
    ctx.MarkLocation(catchStmt->getAtCatchLoc());
    OS << '(';
    if (catchStmt->getCatchParamDecl()) {
      if (clang::Decl *DS = catchStmt->getCatchParamDecl())
        PrintRawDecl(DS);
    }
    OS << ")";
    if (auto *CS = clang::dyn_cast<clang::CompoundStmt>(catchStmt->getCatchBody())) {
      PrintRawCompoundStmt(CS);
      OS << NL;
    }
  }

  if (auto *FS = static_cast<clang::ObjCAtFinallyStmt *>(Node->getFinallyStmt())) {
    Indent() << "@finally";
    ctx.MarkLocation(FS->getAtFinallyLoc());
    PrintRawCompoundStmt(
        clang::dyn_cast<clang::CompoundStmt>(FS->getFinallyBody()));
    OS << NL;
  }
}

void StmtPrinter::VisitObjCAtFinallyStmt(clang::ObjCAtFinallyStmt *Node) {
}

void StmtPrinter::VisitObjCAtCatchStmt (clang::ObjCAtCatchStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "@catch";
  ctx.MarkLocation(Node->getAtCatchLoc());
  OS << "(...) { /* todo */ } " << NL;
}

void StmtPrinter::VisitObjCAtThrowStmt(clang::ObjCAtThrowStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "@throw";
  ctx.MarkLocation(Node->getThrowLoc());
  if (Node->getThrowExpr()) {
    OS << " ";
    PrintExpr(Node->getThrowExpr());
  }
  OS << ";" << NL;
}

void StmtPrinter::VisitObjCAvailabilityCheckExpr(
    clang::ObjCAvailabilityCheckExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "@available";
  ctx.MarkLocation(Node->getBeginLoc());
  OS << "(...)";
  ctx.MarkLocation(Node->getEndLoc());  // RParen loc.
}

void StmtPrinter::VisitObjCAtSynchronizedStmt(clang::ObjCAtSynchronizedStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "@synchronized";
  ctx.MarkLocation(Node->getBeginLoc());
  OS << " (";
  PrintExpr(Node->getSynchExpr());
  OS << ")";
  PrintRawCompoundStmt(Node->getSynchBody());
  OS << NL;
}

void StmtPrinter::VisitObjCAutoreleasePoolStmt(clang::ObjCAutoreleasePoolStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "@autoreleasepool";
  ctx.MarkLocation(Node->getBeginLoc());
  PrintRawCompoundStmt(clang::dyn_cast<clang::CompoundStmt>(Node->getSubStmt()));
  OS << NL;
}

void StmtPrinter::PrintRawCXXCatchStmt(clang::CXXCatchStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "catch";
  ctx.MarkLocation(Node->getCatchLoc());
  OS << " (";
  if (clang::Decl *ExDecl = Node->getExceptionDecl())
    PrintRawDecl(ExDecl);
  else
    OS << "...";
  OS << ") ";
  PrintRawCompoundStmt(clang::cast<clang::CompoundStmt>(Node->getHandlerBlock()));
}

void StmtPrinter::VisitCXXCatchStmt(clang::CXXCatchStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent();
  PrintRawCXXCatchStmt(Node);
  OS << NL;
}

void StmtPrinter::VisitCXXTryStmt(clang::CXXTryStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "try ";
  ctx.MarkLocation(Node->getTryLoc());
  PrintRawCompoundStmt(Node->getTryBlock());
  for (unsigned i = 0, e = Node->getNumHandlers(); i < e; ++i) {
    OS << " ";
    PrintRawCXXCatchStmt(Node->getHandler(i));
  }
  OS << NL;
}

void StmtPrinter::VisitSEHTryStmt(clang::SEHTryStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << (Node->getIsCXXTry() ? "try " : "__try ");
  ctx.MarkLocation(Node->getTryLoc());
  PrintRawCompoundStmt(Node->getTryBlock());
  clang::SEHExceptStmt *E = Node->getExceptHandler();
  clang::SEHFinallyStmt *F = Node->getFinallyHandler();
  if(E)
    PrintRawSEHExceptHandler(E);
  else {
    assert(F && "Must have a finally block...");
    PrintRawSEHFinallyStmt(F);
  }
  OS << NL;
}

void StmtPrinter::PrintRawSEHFinallyStmt(clang::SEHFinallyStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__finally ";
  ctx.MarkLocation(Node->getFinallyLoc());
  PrintRawCompoundStmt(Node->getBlock());
  OS << NL;
}

void StmtPrinter::PrintRawSEHExceptHandler(clang::SEHExceptStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__except";
  ctx.MarkLocation(Node->getExceptLoc());
  OS << " (";
  VisitExpr(Node->getFilterExpr());
  OS << ")" << NL;
  PrintRawCompoundStmt(Node->getBlock());
  OS << NL;
}

void StmtPrinter::VisitSEHExceptStmt(clang::SEHExceptStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent();
  PrintRawSEHExceptHandler(Node);
  OS << NL;
}

void StmtPrinter::VisitSEHFinallyStmt(clang::SEHFinallyStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent();
  PrintRawSEHFinallyStmt(Node);
  OS << NL;
}

void StmtPrinter::VisitSEHLeaveStmt(clang::SEHLeaveStmt *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "__leave";
  ctx.MarkLocation(Node->getLeaveLoc());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

//===----------------------------------------------------------------------===//
//  OpenMP directives printing methods
//===----------------------------------------------------------------------===//

void StmtPrinter::VisitOMPCanonicalLoop(clang::OMPCanonicalLoop *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintStmt(Node->getLoopStmt());
}

void StmtPrinter::PrintOMPExecutableDirective(clang::OMPExecutableDirective *S,
                                              bool ForceNoStmt) {
  TokenPrinterContext ctx(OS, S, tokens);
  clang::OMPClausePrinter Printer(OS, Policy);
  clang::ArrayRef<clang::OMPClause *> Clauses = S->clauses();
  for (auto *Clause : Clauses)
    if (Clause && !Clause->isImplicit()) {
      OS << ' ';
      Printer.Visit(Clause);
    }
  OS << NL;
  if (!ForceNoStmt && S->hasAssociatedStmt())
    PrintStmt(S->getRawStmt());
}

void StmtPrinter::VisitOMPMetaDirective(clang::OMPMetaDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp metadirective";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelDirective(clang::OMPParallelDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSimdDirective(clang::OMPSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTileDirective(clang::OMPTileDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp tile";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPUnrollDirective(clang::OMPUnrollDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp unroll";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPForDirective(clang::OMPForDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPForSimdDirective(clang::OMPForSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSectionsDirective(clang::OMPSectionsDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp sections";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSectionDirective(clang::OMPSectionDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp section";
  PrintOMPExecutableDirective(Node);
}

#ifdef PASTA_LLVM_18
void StmtPrinter::VisitOMPScopeDirective(clang::OMPScopeDirective *Node) {
  Indent() << "#pragma omp scope";
  PrintOMPExecutableDirective(Node);
}
#endif

void StmtPrinter::VisitOMPSingleDirective(clang::OMPSingleDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp single";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMasterDirective(clang::OMPMasterDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp master";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPCriticalDirective(clang::OMPCriticalDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp critical";
  if (Node->getDirectiveName().getName()) {
    OS << " (";
    Node->getDirectiveName().printName(OS, Policy);
    OS << ")";
  }
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelForDirective(clang::OMPParallelForDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelForSimdDirective(
    clang::OMPParallelForSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMasterDirective(
    clang::OMPParallelMasterDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel master";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMaskedDirective(
    clang::OMPParallelMaskedDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel masked";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelSectionsDirective(
    clang::OMPParallelSectionsDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel sections";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskDirective(clang::OMPTaskDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp task";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskyieldDirective(clang::OMPTaskyieldDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp taskyield";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPBarrierDirective(clang::OMPBarrierDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp barrier";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskwaitDirective(clang::OMPTaskwaitDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp taskwait";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPErrorDirective(clang::OMPErrorDirective *Node) {
 TokenPrinterContext ctx(OS, Node, tokens);
 Indent() << "#pragma omp error";
 PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskgroupDirective(clang::OMPTaskgroupDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp taskgroup";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPFlushDirective(clang::OMPFlushDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp flush";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDepobjDirective(clang::OMPDepobjDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp depobj";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPScanDirective(clang::OMPScanDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp scan";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPOrderedDirective(clang::OMPOrderedDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp ordered";
  PrintOMPExecutableDirective(Node, Node->hasClausesOfKind<clang::OMPDependClause>());
}

void StmtPrinter::VisitOMPAtomicDirective(clang::OMPAtomicDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp atomic";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetDirective(clang::OMPTargetDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetDataDirective(clang::OMPTargetDataDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target data";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetEnterDataDirective(
    clang::OMPTargetEnterDataDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target enter data";
  PrintOMPExecutableDirective(Node, /*ForceNoStmt=*/true);
}

void StmtPrinter::VisitOMPTargetExitDataDirective(
    clang::OMPTargetExitDataDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target exit data";
  PrintOMPExecutableDirective(Node, /*ForceNoStmt=*/true);
}

void StmtPrinter::VisitOMPTargetParallelDirective(
    clang::OMPTargetParallelDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target parallel";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetParallelForDirective(
    clang::OMPTargetParallelForDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDirective(clang::OMPTeamsDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp teams";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPCancellationPointDirective(
    clang::OMPCancellationPointDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp cancellation point "
           << getOpenMPDirectiveName(Node->getCancelRegion());
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPCancelDirective(clang::OMPCancelDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp cancel "
           << getOpenMPDirectiveName(Node->getCancelRegion());
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskLoopDirective(clang::OMPTaskLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskLoopSimdDirective(
    clang::OMPTaskLoopSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMasterTaskLoopDirective(
    clang::OMPMasterTaskLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp master taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMaskedTaskLoopDirective(
    clang::OMPMaskedTaskLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp masked taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMasterTaskLoopSimdDirective(
    clang::OMPMasterTaskLoopSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp master taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMaskedTaskLoopSimdDirective(
    clang::OMPMaskedTaskLoopSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp masked taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMasterTaskLoopDirective(
    clang::OMPParallelMasterTaskLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel master taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMaskedTaskLoopDirective(
    clang::OMPParallelMaskedTaskLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel masked taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMasterTaskLoopSimdDirective(
    clang::OMPParallelMasterTaskLoopSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel master taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMaskedTaskLoopSimdDirective(
    clang::OMPParallelMaskedTaskLoopSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel masked taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDistributeDirective(clang::OMPDistributeDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp distribute";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetUpdateDirective(
    clang::OMPTargetUpdateDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target update";
  PrintOMPExecutableDirective(Node, /*ForceNoStmt=*/true);
}

void StmtPrinter::VisitOMPDistributeParallelForDirective(
    clang::OMPDistributeParallelForDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp distribute parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDistributeParallelForSimdDirective(
    clang::OMPDistributeParallelForSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp distribute parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDistributeSimdDirective(
    clang::OMPDistributeSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp distribute simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetParallelForSimdDirective(
    clang::OMPTargetParallelForSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetSimdDirective(clang::OMPTargetSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeDirective(
    clang::OMPTeamsDistributeDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp teams distribute";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeSimdDirective(
    clang::OMPTeamsDistributeSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp teams distribute simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeParallelForSimdDirective(
    clang::OMPTeamsDistributeParallelForSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp teams distribute parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeParallelForDirective(
    clang::OMPTeamsDistributeParallelForDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp teams distribute parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDirective(clang::OMPTargetTeamsDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target teams";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeDirective(
    clang::OMPTargetTeamsDistributeDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target teams distribute";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeParallelForDirective(
    clang::OMPTargetTeamsDistributeParallelForDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target teams distribute parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeParallelForSimdDirective(
    clang::OMPTargetTeamsDistributeParallelForSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target teams distribute parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMaskedDirective(clang::OMPMaskedDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp masked";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPGenericLoopDirective(
      clang::OMPGenericLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp loop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsGenericLoopDirective(
    clang::OMPTeamsGenericLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp teams loop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsGenericLoopDirective(
    clang::OMPTargetTeamsGenericLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target teams loop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelGenericLoopDirective(
    clang::OMPParallelGenericLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp parallel loop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetParallelGenericLoopDirective(
    clang::OMPTargetParallelGenericLoopDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target parallel loop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeSimdDirective(
    clang::OMPTargetTeamsDistributeSimdDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp target teams distribute simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPInteropDirective(clang::OMPInteropDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp interop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDispatchDirective(clang::OMPDispatchDirective *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Indent() << "#pragma omp dispatch";
  PrintOMPExecutableDirective(Node);
}

//===----------------------------------------------------------------------===//
//  Expr printing methods.
//===----------------------------------------------------------------------===//

void StmtPrinter::VisitSourceLocExpr(clang::SourceLocExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << Node->getBuiltinStr();
  ctx.MarkLocation(Node->getBeginLoc());  // BuiltinLoc.
  OS << "()";
  ctx.MarkLocation(Node->getEndLoc());  // RParenLoc.
}

void StmtPrinter::VisitConstantExpr(clang::ConstantExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitDeclRefExpr(clang::DeclRefExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (const auto *OCED = clang::dyn_cast<clang::OMPCapturedExprDecl>(Node->getDecl())) {
    auto E = OCED->getInit()->IgnoreImpCasts();
    StmtPrinter printer(OS, nullptr, tokens, Policy);
    printer.PrintExpr(const_cast<clang::Expr *>(E));
    return;
  }
  if (const auto *TPOD = clang::dyn_cast<clang::TemplateParamObjectDecl>(Node->getDecl())) {
    TPOD->printAsExpr(OS, Policy);
    return;
  }
  if (Node->getLocation().getRawEncoding() == 7633582) {
    (void) Node->getLocation();   // f 21, __wrap_iter char *
  }
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    NestedNameSpecifier_print(Qualifier, *this, Policy);
  }
  if (Node->hasTemplateKeyword()) {
    OS << "template ";
    ctx.MarkLocation(Node->getTemplateKeywordLoc());
  }
  OS << Node->getNameInfo();
  if (Node->hasExplicitTemplateArgs()) {
      const clang::TemplateParameterList *TPL = nullptr;
    if (!Node->hadMultipleCandidates())
      if (auto *TD = clang::dyn_cast<clang::TemplateDecl>(Node->getDecl()))
        TPL = TD->getTemplateParameters();

    TagDefinitionPolicyRAII disable_tags(Policy);
    printTemplateArgumentList(*this, Node->template_arguments(), Policy, TPL);
  }
}

void StmtPrinter::VisitDependentScopeDeclRefExpr(
    clang::DependentScopeDeclRefExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    NestedNameSpecifier_print(Qualifier, *this, Policy);
  if (Node->hasTemplateKeyword()) {
    OS << "template ";
    ctx.MarkLocation(Node->getTemplateKeywordLoc());
  }
  OS << Node->getNameInfo();
  if (Node->hasExplicitTemplateArgs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    printTemplateArgumentList(*this, Node->template_arguments(), Policy);
  }
}

void StmtPrinter::VisitUnresolvedLookupExpr(clang::UnresolvedLookupExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Node->getQualifier())
    Node->getQualifier()->print(OS, Policy);
  if (Node->hasTemplateKeyword()) {
    OS << "template ";
    ctx.MarkLocation(Node->getTemplateKeywordLoc());
  }
  OS << Node->getNameInfo();
  if (Node->hasExplicitTemplateArgs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    printTemplateArgumentList(*this, Node->template_arguments(), Policy);
  }
}

static bool isImplicitSelf(const clang::Expr *E) {
  if (const auto *DRE = clang::dyn_cast<clang::DeclRefExpr>(E)) {
    if (const auto *PD = clang::dyn_cast<clang::ImplicitParamDecl>(DRE->getDecl())) {
      if (PD->getParameterKind() == clang::ImplicitParamKind::ObjCSelf &&
          DRE->getBeginLoc().isInvalid())
        return true;
    }
  }
  return false;
}

void StmtPrinter::VisitObjCIvarRefExpr(clang::ObjCIvarRefExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Node->getBase()) {
    if (!Policy.SuppressImplicitBase ||
        !isImplicitSelf(Node->getBase()->IgnoreImpCasts())) {
      PrintExpr(Node->getBase());
      OS << (Node->isArrow() ? "->" : ".");
      ctx.MarkLocation(Node->getOpLoc());
    }
  }
  OS << *Node->getDecl();
}

void StmtPrinter::VisitObjCPropertyRefExpr(clang::ObjCPropertyRefExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Node->isSuperReceiver())
    OS << "super.";
  else if (Node->isObjectReceiver() && Node->getBase()) {
    PrintExpr(Node->getBase());
    OS << ".";
  } else if (Node->isClassReceiver() && Node->getClassReceiver()) {
    OS << Node->getClassReceiver()->getName() << ".";
  }

  if (Node->isImplicitProperty()) {
    if (const auto *Getter = Node->getImplicitPropertyGetter())
      Getter->getSelector().print(OS);
    else
      OS << clang::SelectorTable::getPropertyNameFromSetterSelector(
          Node->getImplicitPropertySetter()->getSelector());
  } else
    OS << Node->getExplicitProperty()->getName();
}

void StmtPrinter::VisitObjCSubscriptRefExpr(clang::ObjCSubscriptRefExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBaseExpr());
  OS << "[";
  PrintExpr(Node->getKeyExpr());
  OS << "]";
  ctx.MarkLocation(Node->getRBracket());
}

void StmtPrinter::VisitSYCLUniqueStableNameExpr(
    clang::SYCLUniqueStableNameExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_sycl_unique_stable_name(";
  Node->getTypeSourceInfo()->getType().print(OS, Policy);
  OS << ")";
}

void StmtPrinter::VisitPredefinedExpr(clang::PredefinedExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << clang::PredefinedExpr::getIdentKindName(Node->getIdentKind());
}

void StmtPrinter::VisitCharacterLiteral(clang::CharacterLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  clang::CharacterLiteral::print(Node->getValue(), Node->getKind(), OS);
}

/// Prints the given expression using the original source text. Returns true on
/// success, false otherwise.
static bool printExprAsWritten(pasta::raw_string_ostream &OS, clang::Expr *E,
                               const clang::ASTContext *Context) {
  if (!Context)
    return false;
  bool Invalid = false;
  clang::StringRef Source = clang::Lexer::getSourceText(
      clang::CharSourceRange::getTokenRange(E->getSourceRange()),
      Context->getSourceManager(), Context->getLangOpts(), &Invalid);
  if (!Invalid) {
    OS << Source;
    return true;
  }
  return false;
}

void StmtPrinter::VisitIntegerLiteral(clang::IntegerLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Policy.ConstantsAsWritten && printExprAsWritten(OS, Node, Context)) {
    ctx.MarkLocation(Node->getLocation());
    return;
  }
  bool isSigned = Node->getType()->isSignedIntegerType();
  OS << toString(Node->getValue(), 10, isSigned);

  if (clang::isa<clang::BitIntType>(Node->getType())) {
    OS << (isSigned ? "wb" : "uwb");
    return;
  }

  // Emit suffixes.  Integer literals are always a builtin integer type.
  switch (Node->getType()->castAs<clang::BuiltinType>()->getKind()) {
  default: llvm_unreachable("Unexpected type for integer literal!");
  case clang::BuiltinType::Char_S:
  case clang::BuiltinType::Char_U:    OS << "i8"; break;
  case clang::BuiltinType::UChar:     OS << "Ui8"; break;
  case clang::BuiltinType::SChar:     OS << "i8"; break;
  case clang::BuiltinType::Short:     OS << "i16"; break;
  case clang::BuiltinType::UShort:    OS << "Ui16"; break;
  case clang::BuiltinType::Int:       break; // no suffix.
  case clang::BuiltinType::UInt:      OS << 'U'; break;
  case clang::BuiltinType::Long:      OS << 'L'; break;
  case clang::BuiltinType::ULong:     OS << "UL"; break;
  case clang::BuiltinType::LongLong:  OS << "LL"; break;
  case clang::BuiltinType::ULongLong: OS << "ULL"; break;
  case clang::BuiltinType::Int128:
    break; // no suffix.
  case clang::BuiltinType::UInt128:
    break; // no suffix.
  case clang::BuiltinType::WChar_S:
  case clang::BuiltinType::WChar_U:
    break; // no suffix
  }
  ctx.MarkLocation(Node->getLocation());
}

void StmtPrinter::VisitFixedPointLiteral(clang::FixedPointLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Policy.ConstantsAsWritten && printExprAsWritten(OS, Node, Context)) {
    ctx.MarkLocation(Node->getLocation());
    return;
  }
  OS << Node->getValueAsString(/*Radix=*/10);

  switch (Node->getType()->castAs<clang::BuiltinType>()->getKind()) {
    default: llvm_unreachable("Unexpected type for fixed point literal!");
    case clang::BuiltinType::ShortFract:   OS << "hr"; break;
    case clang::BuiltinType::ShortAccum:   OS << "hk"; break;
    case clang::BuiltinType::UShortFract:  OS << "uhr"; break;
    case clang::BuiltinType::UShortAccum:  OS << "uhk"; break;
    case clang::BuiltinType::Fract:        OS << "r"; break;
    case clang::BuiltinType::Accum:        OS << "k"; break;
    case clang::BuiltinType::UFract:       OS << "ur"; break;
    case clang::BuiltinType::UAccum:       OS << "uk"; break;
    case clang::BuiltinType::LongFract:    OS << "lr"; break;
    case clang::BuiltinType::LongAccum:    OS << "lk"; break;
    case clang::BuiltinType::ULongFract:   OS << "ulr"; break;
    case clang::BuiltinType::ULongAccum:   OS << "ulk"; break;
  }
  ctx.MarkLocation(Node->getLocation());
}

static void PrintFloatingLiteral(pasta::raw_string_ostream &OS,
                                 clang::FloatingLiteral *Node,
                                 bool PrintSuffix) {
  clang::SmallString<16> Str;
  Node->getValue().toString(Str);
  OS << Str;
  if (Str.find_first_not_of("-0123456789") == clang::StringRef::npos)
    OS << '.'; // Trailing dot in order to separate from ints.

  if (!PrintSuffix) {
    return;
  }

  // Emit suffixes.  Float literals are always a builtin float type.
  switch (Node->getType()->castAs<clang::BuiltinType>()->getKind()) {
  default: llvm_unreachable("Unexpected type for float literal!");
  case clang::BuiltinType::Half:       break; // FIXME: suffix?
  case clang::BuiltinType::Double:     break; // no suffix.
  case clang::BuiltinType::Float16:    OS << "F16"; break;
  case clang::BuiltinType::Float:      OS << 'F'; break;
  case clang::BuiltinType::LongDouble: OS << 'L'; break;
  case clang::BuiltinType::Float128:   OS << 'Q'; break;
  }
}

void StmtPrinter::VisitFloatingLiteral(clang::FloatingLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Policy.ConstantsAsWritten && printExprAsWritten(OS, Node, Context)) {
    ctx.MarkLocation(Node->getLocation());
    return;
  }
  PrintFloatingLiteral(OS, Node, /*PrintSuffix=*/true);
  ctx.MarkLocation(Node->getLocation());
}

void StmtPrinter::VisitImaginaryLiteral(clang::ImaginaryLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getSubExpr());
  OS << "i";
  ctx.MarkLocation(Node->getEndLoc());  // TODO(pag): Hrmm.
}

void StmtPrinter::VisitStringLiteral(clang::StringLiteral *Str) {
  TokenPrinterContext ctx(OS, Str, tokens);
  Str->outputString(OS);
  ctx.MarkLocation(Str->getBeginLoc());
}

void StmtPrinter::VisitParenExpr(clang::ParenExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "(";
  ctx.MarkLocation(Node->getLParen());
  PrintExpr(Node->getSubExpr());
  OS << ")";
  ctx.MarkLocation(Node->getRParen());
}

void StmtPrinter::VisitUnaryOperator(clang::UnaryOperator *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (!Node->isPostfix()) {
    OS << clang::UnaryOperator::getOpcodeStr(Node->getOpcode());

    // Print a space if this is an "identifier operator" like __real, or if
    // it might be concatenated incorrectly like '+'.
    switch (Node->getOpcode()) {
    default: break;
    case clang::UO_Real:
    case clang::UO_Imag:
    case clang::UO_Extension:
      OS << ' ';
      break;
    case clang::UO_Plus:
    case clang::UO_Minus:
      if (clang::isa<clang::UnaryOperator>(Node->getSubExpr()))
        OS << ' ';
      break;
    }
  }
  PrintExpr(Node->getSubExpr());

  if (Node->isPostfix())
    OS << clang::UnaryOperator::getOpcodeStr(Node->getOpcode());
}

void StmtPrinter::VisitOffsetOfExpr(clang::OffsetOfExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_offsetof";

  ctx.MarkLocation(Node->getOperatorLoc());
  OS << "(";
  printQualType(Node->getTypeSourceInfo()->getType(), OS, Policy);
  OS << ", ";
  bool PrintedSomething = false;
  std::vector<TokenPrinterContext> contexts;
  for (unsigned i = 0, n = Node->getNumComponents(); i < n; ++i) {
    clang::OffsetOfNode ON = Node->getComponent(i);
    if (ON.getKind() == clang::OffsetOfNode::Array) {
      // Array node
      OS << "[";
      ctx.MarkLocation(ON.getBeginLoc());
      PrintExpr(Node->getIndexExpr(ON.getArrayExprIndex()));
      OS << "]";
      ctx.MarkLocation(ON.getEndLoc());
      PrintedSomething = true;
      continue;
    }

    // Skip implicit base indirections.
    if (ON.getKind() == clang::OffsetOfNode::Base)
      continue;

    // Field or identifier node.
    clang::IdentifierInfo *Id = ON.getFieldName();
    if (!Id)
      continue;

    if (PrintedSomething) {
      OS << ".";
      if (ON.getKind() == clang::OffsetOfNode::Field) {
        ctx.MarkLocation(ON.getBeginLoc());
      }
    } else
      PrintedSomething = true;

    // Make sure we track field names.
    if (ON.getKind() == clang::OffsetOfNode::Field) {
      if (auto FD = ON.getField()) {
        TokenPrinterContext ctx(OS, FD, tokens);
        OS << Id->getName();
        ctx.MarkLocation(ON.getEndLoc());
        continue;
      }
    }

    OS << Id->getName();
    if (ON.getBeginLoc() == ON.getEndLoc()) {
      ctx.MarkLocation(ON.getEndLoc());
    }
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitUnaryExprOrTypeTraitExpr(
    clang::UnaryExprOrTypeTraitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  const char *Spelling = getTraitSpelling(Node->getKind());
  if (Node->getKind() == clang::UETT_AlignOf) {
    if (Policy.Alignof)
      Spelling = "alignof";
    else if (Policy.UnderscoreAlignof)
      Spelling = "_Alignof";
    else
      Spelling = "__alignof";
  }

  OS << Spelling;
  ctx.MarkLocation(Node->getOperatorLoc());

  if (Node->isArgumentType()) {
    OS << '(';
    printQualType(Node->getArgumentType(), OS, Policy);
    OS << ')';
    ctx.MarkLocation(Node->getRParenLoc());
  } else {
    OS << " ";
    PrintExpr(Node->getArgumentExpr());
  }
}

void StmtPrinter::VisitGenericSelectionExpr(clang::GenericSelectionExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "_Generic(";
  PrintExpr(Node->getControllingExpr());
  for (const clang::GenericSelectionExpr::Association Assoc : Node->associations()) {
    OS << ", ";
    clang::QualType T = Assoc.getType();
    if (T.isNull()) {
      OS << "default";
      ctx.MarkLocation(Node->getDefaultLoc());
    } else
      printQualType(T, OS, Policy);
    OS << ": ";
    PrintExpr(Assoc.getAssociationExpr());
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitArraySubscriptExpr(clang::ArraySubscriptExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getLHS());
  OS << "[";
  PrintExpr(Node->getRHS());
  OS << "]";
  ctx.MarkLocation(Node->getRBracketLoc());
}

void StmtPrinter::VisitMatrixSubscriptExpr(clang::MatrixSubscriptExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBase());
  OS << "[";
  PrintExpr(Node->getRowIdx());
  OS << "]";
  OS << "[";
  PrintExpr(Node->getColumnIdx());
  OS << "]";
  ctx.MarkLocation(Node->getRBracketLoc());  // TODO(pag): Which r-bracket is this?
}

void StmtPrinter::VisitOMPArraySectionExpr(clang::OMPArraySectionExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBase());
  OS << "[";
  if (Node->getLowerBound())
    PrintExpr(Node->getLowerBound());
  if (Node->getColonLocFirst().isValid()) {
    OS << ":";
    ctx.MarkLocation(Node->getColonLocFirst());
    if (Node->getLength())
      PrintExpr(Node->getLength());
  }
  if (Node->getColonLocSecond().isValid()) {
    OS << ":";
    ctx.MarkLocation(Node->getColonLocSecond());
    if (Node->getStride())
      PrintExpr(Node->getStride());
  }
  OS << "]";
  ctx.MarkLocation(Node->getRBracketLoc());
}

void StmtPrinter::VisitOMPArrayShapingExpr(clang::OMPArrayShapingExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "(";
  ctx.MarkLocation(Node->getLParenLoc());
  auto i = 0u;
  auto bracks_ranges = Node->getBracketsRanges();
  for (clang::Expr *E : Node->getDimensions()) {
    OS << "[";
    if (i < bracks_ranges.size()) {
      ctx.MarkLocation(bracks_ranges[i].getBegin());
    }
    PrintExpr(E);
    OS << "]";
    if (i < bracks_ranges.size()) {
      ctx.MarkLocation(bracks_ranges[i].getEnd());
    }
    ++i;
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
  PrintExpr(Node->getBase());
}

void StmtPrinter::VisitOMPIteratorExpr(clang::OMPIteratorExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "iterator";
  ctx.MarkLocation(Node->getIteratorKwLoc());
  OS << "(";
  for (unsigned I = 0, E = Node->numOfIterators(); I < E; ++I) {
    auto *VD = clang::cast<clang::ValueDecl>(Node->getIteratorDecl(I));
    printQualType(VD->getType(), OS, Policy);
    const clang::OMPIteratorExpr::IteratorRange Range = Node->getIteratorRange(I);
    OS << " " << VD->getName() << " = ";
    ctx.MarkLocation(Node->getAssignLoc(I));
    PrintExpr(Range.Begin);
    OS << ":";
    ctx.MarkLocation(Node->getColonLoc(I));
    PrintExpr(Range.End);
    if (Range.Step) {
      OS << ":";
      ctx.MarkLocation(Node->getSecondColonLoc(I));
      PrintExpr(Range.Step);
    }
    if (I < E - 1)
      OS << ", ";
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::PrintCallArgs(clang::CallExpr *Call) {
  for (unsigned i = 0, e = Call->getNumArgs(); i != e; ++i) {
    if (clang::isa<clang::CXXDefaultArgExpr>(Call->getArg(i))) {
      // Don't print any defaulted arguments
      break;
    }

    if (i) OS << ", ";
    PrintExpr(Call->getArg(i));
  }
}

void StmtPrinter::VisitCallExpr(clang::CallExpr *Call) {
  TokenPrinterContext ctx(OS, Call, tokens);
  PrintExpr(Call->getCallee());
  OS << "(";
  PrintCallArgs(Call);
  OS << ")";
  ctx.MarkLocation(Call->getRParenLoc());
}

static bool isImplicitThis(const clang::Expr *E) {
  if (const auto *TE = clang::dyn_cast<clang::CXXThisExpr>(E))
    return TE->isImplicit();
  return false;
}

void StmtPrinter::VisitMemberExpr(clang::MemberExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  auto LHS = Node->getBase();
  if (!isImplicitThis(LHS)) {
    PrintExpr(LHS);

    // NOTE(pag): The left-hand side might be a call to an `operator->`, and so
    //            we don't want to re-print the `->`.
    if (Node->isArrow()) {
      if (!tokens.LastTokenIsOneOf(TokenKind::kArrow)) {
        OS << "->";
        ctx.MarkLocation(Node->getOperatorLoc());
      }
    } else {
      if (!tokens.LastTokenIsOneOf(TokenKind::kPeriod)) {
        OS << '.';
        ctx.MarkLocation(Node->getOperatorLoc());
      }
    }
  }

  if (auto *FD = clang::dyn_cast<clang::FieldDecl>(Node->getMemberDecl()))
    if (FD->isAnonymousStructOrUnion())
      return;

  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    NestedNameSpecifier_print(Qualifier, *this, Policy);
  if (Node->hasTemplateKeyword()) {
    OS << "template ";
    ctx.MarkLocation(Node->getTemplateKeywordLoc());
  }
  OS << Node->getMemberNameInfo();
  const clang::TemplateParameterList *TPL = nullptr;
  if (auto *FD = clang::dyn_cast<clang::FunctionDecl>(Node->getMemberDecl())) {
    if (!Node->hadMultipleCandidates())
      if (auto *FTD = FD->getPrimaryTemplate())
        TPL = FTD->getTemplateParameters();
  } else if (auto *VTSD =
                 clang::dyn_cast<clang::VarTemplateSpecializationDecl>(Node->getMemberDecl()))
    TPL = VTSD->getSpecializedTemplate()->getTemplateParameters();
  if (Node->hasExplicitTemplateArgs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    printTemplateArgumentList(*this, Node->template_arguments(), Policy, TPL);
  }
}

void StmtPrinter::VisitObjCIsaExpr(clang::ObjCIsaExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBase());
  OS << (Node->isArrow() ? "->" : ".");
  ctx.MarkLocation(Node->getOpLoc());
  OS << "isa";
  ctx.MarkLocation(Node->getIsaMemberLoc());
}

void StmtPrinter::VisitExtVectorElementExpr(clang::ExtVectorElementExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBase());
  OS << ".";
  OS << Node->getAccessor().getName();
  ctx.MarkLocation(Node->getAccessorLoc());
}

void StmtPrinter::VisitCStyleCastExpr(clang::CStyleCastExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << '(';
  ctx.MarkLocation(Node->getLParenLoc());
  printQualType(Node->getTypeAsWritten(), OS, Policy);
  OS << ')';
  ctx.MarkLocation(Node->getRParenLoc());
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitCompoundLiteralExpr(clang::CompoundLiteralExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << '(';
  ctx.MarkLocation(Node->getLParenLoc());
  printQualType(Node->getType(), OS, Policy);
  OS << ')';
  PrintExpr(Node->getInitializer());
}

void StmtPrinter::VisitImplicitCastExpr(clang::ImplicitCastExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // No need to print anything, simply forward to the subexpression.
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitBinaryOperator(clang::BinaryOperator *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getLHS());
  OS << " " << clang::BinaryOperator::getOpcodeStr(Node->getOpcode()) << " ";
  ctx.MarkLocation(Node->getOperatorLoc());
  PrintExpr(Node->getRHS());
}

void StmtPrinter::VisitCompoundAssignOperator(clang::CompoundAssignOperator *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getLHS());
  OS << " " << clang::BinaryOperator::getOpcodeStr(Node->getOpcode()) << " ";
  ctx.MarkLocation(Node->getOperatorLoc());
  PrintExpr(Node->getRHS());
}

void StmtPrinter::VisitConditionalOperator(clang::ConditionalOperator *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getCond());
  OS << " ? ";
  ctx.MarkLocation(Node->getQuestionLoc());
  PrintExpr(Node->getLHS());
  OS << " : ";
  ctx.MarkLocation(Node->getColonLoc());
  PrintExpr(Node->getRHS());
}

// GNU extensions.

void
StmtPrinter::VisitBinaryConditionalOperator(clang::BinaryConditionalOperator *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getCommon());
  OS << " ?: ";
  ctx.MarkLocation(Node->getQuestionLoc());
  PrintExpr(Node->getFalseExpr());
}

void StmtPrinter::VisitAddrLabelExpr(clang::AddrLabelExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "&&";
  ctx.MarkLocation(Node->getAmpAmpLoc());
  OS << Node->getLabel()->getName();
}

void StmtPrinter::VisitStmtExpr(clang::StmtExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "(";
  PrintRawCompoundStmt(E->getSubStmt());
  OS << ")";
  ctx.MarkLocation(E->getRParenLoc());
}

void StmtPrinter::VisitChooseExpr(clang::ChooseExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_choose_expr";
  ctx.MarkLocation(Node->getBuiltinLoc());
  OS << "(";
  PrintExpr(Node->getCond());
  OS << ", ";
  PrintExpr(Node->getLHS());
  OS << ", ";
  PrintExpr(Node->getRHS());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitGNUNullExpr(clang::GNUNullExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__null";
  ctx.MarkLocation(Node->getTokenLocation());
}

void StmtPrinter::VisitShuffleVectorExpr(clang::ShuffleVectorExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_shufflevector";
  ctx.MarkLocation(Node->getBuiltinLoc());
  OS << "(";
  for (unsigned i = 0, e = Node->getNumSubExprs(); i != e; ++i) {
    if (i) OS << ", ";
    PrintExpr(Node->getExpr(i));
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitConvertVectorExpr(clang::ConvertVectorExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_convertvector";
  ctx.MarkLocation(Node->getBuiltinLoc());
  OS << "(";
  PrintExpr(Node->getSrcExpr());
  OS << ", ";
  printQualType(Node->getType(), OS, Policy);
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitInitListExpr(clang::InitListExpr *Node) {
  if (Node->getSyntacticForm()) {
    Visit(Node->getSyntacticForm());
    return;
  }

  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "{";
  ctx.MarkLocation(Node->getLBraceLoc());

  std::optional<DerivedTokenIndex> comma_loc;
  for (unsigned i = 0, e = Node->getNumInits(); i != e; ++i) {
    if (i) {
      OS << ", ";

      // NOTE(pag): We want to find these commas, because some initializer
      //            lists are *giant* and that can cause bad computational
      //            complexity in AlignTokens.
      if (comma_loc) {
        ctx.MarkLocation(comma_loc.value());
      }
    }

    comma_loc.reset();
    auto E = Node->getInit(i);
    if (!E) {
      OS << "{}";
      continue;
    }
    PrintExpr(E);

    if (!tokens.ast) {
      continue;
    }

    auto raw_tok = tokens.ast->ParsedTokenOffset(E->getEndLoc());
    if (!raw_tok) {
      continue;
    }

    for (auto j = 0u; j <= 1u; ++j) {
      if (tokens.ast->TokenKind(raw_tok.value() + j) == TokenKind::kComma) {
        comma_loc = raw_tok.value() + j;
        break;
      }
    }
  }
  OS << "}";
  ctx.MarkLocation(Node->getRBraceLoc());
}

void StmtPrinter::VisitArrayInitLoopExpr(clang::ArrayInitLoopExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // There's no way to express this expression in any of our supported
  // languages, so just emit something terse and (hopefully) clear.
  OS << "{";
  PrintExpr(Node->getSubExpr());
  OS << "}";
}

void StmtPrinter::VisitArrayInitIndexExpr(clang::ArrayInitIndexExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "*";
}

void StmtPrinter::VisitParenListExpr(clang::ParenListExpr* Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "(";
  ctx.MarkLocation(Node->getLParenLoc());
  for (unsigned i = 0, e = Node->getNumExprs(); i != e; ++i) {
    if (i) OS << ", ";
    PrintExpr(Node->getExpr(i));
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitDesignatedInitExpr(clang::DesignatedInitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  bool NeedsEquals = true;
  for (const clang::DesignatedInitExpr::Designator &D : Node->designators()) {
    TokenPrinterContext ctx(OS, &D, tokens);
    if (D.isFieldDesignator()) {
      if (D.getDotLoc().isInvalid()) {
        if (auto *II = D.getFieldName()) {
          OS << II->getName();
          ctx.MarkLocation(D.getFieldLoc());
          OS << ":";
          ctx.MarkLocation(Node->getEqualOrColonLoc());
          NeedsEquals = false;
        }
      } else {
        OS << ".";
        ctx.MarkLocation(D.getDotLoc());
        OS << D.getFieldName()->getName();
        ctx.MarkLocation(D.getFieldLoc());
      }
    } else {
      OS << "[";
      ctx.MarkLocation(D.getLBracketLoc());
      if (D.isArrayDesignator()) {
        PrintExpr(Node->getArrayIndex(D));
      } else {
        PrintExpr(Node->getArrayRangeStart(D));
        OS << " ... ";
        ctx.MarkLocation(D.getEllipsisLoc());
        PrintExpr(Node->getArrayRangeEnd(D));
      }
      OS << "]";
      ctx.MarkLocation(D.getRBracketLoc());
    }
  }

  if (NeedsEquals) {
    OS << " = ";
    ctx.MarkLocation(Node->getEqualOrColonLoc());
  } else
    OS << " ";
  PrintExpr(Node->getInit());
}

void StmtPrinter::VisitDesignatedInitUpdateExpr(
    clang::DesignatedInitUpdateExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "{";
  ctx.MarkLocation(Node->getBeginLoc());
  OS << "/*base*/";
  PrintExpr(Node->getBase());
  OS << ", ";

  OS << "/*updater*/";
  PrintExpr(Node->getUpdater());
  OS << "}";
  ctx.MarkLocation(Node->getEndLoc());
}

void StmtPrinter::VisitNoInitExpr(clang::NoInitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "/*no init*/";
}

void StmtPrinter::VisitImplicitValueInitExpr(clang::ImplicitValueInitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (Node->getType()->getAsCXXRecordDecl()) {
    printQualType(Node->getType(), OS, Policy);
    OS << "()";
  } else {
    OS << "(";
    printQualType(Node->getType(), OS, Policy);
    OS << ')';
    if (Node->getType()->isRecordType())
      OS << "{}";
    else
      OS << 0;
  }
}

void StmtPrinter::VisitVAArgExpr(clang::VAArgExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_va_arg";
  ctx.MarkLocation(Node->getBuiltinLoc());
  OS << "(";
  PrintExpr(Node->getSubExpr());
  OS << ", ";
  printQualType(Node->getType(), OS, Policy);
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitPseudoObjectExpr(clang::PseudoObjectExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getSyntacticForm());
}

void StmtPrinter::VisitAtomicExpr(clang::AtomicExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  const char *Name = nullptr;
  switch (Node->getOp()) {
#define BUILTIN(ID, TYPE, ATTRS)
#define ATOMIC_BUILTIN(ID, TYPE, ATTRS) \
  case clang::AtomicExpr::AO ## ID: \
    Name = #ID ; \
    break;
#include "clang/Basic/Builtins.def"
  }
  OS << Name;
  ctx.MarkLocation(Node->getBuiltinLoc());
  if (Name) {
    OS << '(';
  }

  // AtomicExpr stores its subexpressions in a permuted order.
  PrintExpr(Node->getPtr());
  if (Node->getOp() != clang::AtomicExpr::AO__c11_atomic_load &&
      Node->getOp() != clang::AtomicExpr::AO__atomic_load_n &&
      Node->getOp() != clang::AtomicExpr::AO__opencl_atomic_load) {
    OS << ", ";
    PrintExpr(Node->getVal1());
  }
  if (Node->getOp() == clang::AtomicExpr::AO__atomic_exchange ||
      Node->isCmpXChg()) {
    OS << ", ";
    PrintExpr(Node->getVal2());
  }
  if (Node->getOp() == clang::AtomicExpr::AO__atomic_compare_exchange ||
      Node->getOp() == clang::AtomicExpr::AO__atomic_compare_exchange_n) {
    OS << ", ";
    PrintExpr(Node->getWeak());
  }
  if (Node->getOp() != clang::AtomicExpr::AO__c11_atomic_init &&
      Node->getOp() != clang::AtomicExpr::AO__opencl_atomic_init) {
    OS << ", ";
    PrintExpr(Node->getOrder());
  }
  if (Node->isCmpXChg()) {
    OS << ", ";
    PrintExpr(Node->getOrderFail());
  }
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

// C++
void StmtPrinter::VisitCXXOperatorCallExpr(clang::CXXOperatorCallExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  clang::OverloadedOperatorKind Kind = Node->getOperator();
  if (Kind == clang::OO_PlusPlus || Kind == clang::OO_MinusMinus) {
    if (Node->getNumArgs() == 1) {
      OS << getOperatorSpelling(Kind);
      ctx.MarkLocation(Node->getOperatorLoc());
      PrintExpr(Node->getArg(0));
    } else {
      PrintExpr(Node->getArg(0));
      OS << getOperatorSpelling(Kind);
      ctx.MarkLocation(Node->getOperatorLoc());
    }
  } else if (Kind == clang::OO_Arrow) {
    PrintExpr(Node->getArg(0));
    OS << getOperatorSpelling(Kind);
    ctx.MarkLocation(Node->getOperatorLoc());

  } else if (Kind == clang::OO_Call || Kind == clang::OO_Subscript) {
    PrintExpr(Node->getArg(0));
    OS << (Kind == clang::OO_Call ? '(' : '[');
    for (unsigned ArgIdx = 1; ArgIdx < Node->getNumArgs(); ++ArgIdx) {
      if (ArgIdx > 1)
        OS << ", ";
      if (!clang::isa<clang::CXXDefaultArgExpr>(Node->getArg(ArgIdx)))
        PrintExpr(Node->getArg(ArgIdx));
    }
    OS << (Kind == clang::OO_Call ? ')' : ']');

  } else if (Node->getNumArgs() == 1) {
    OS << getOperatorSpelling(Kind);
    ctx.MarkLocation(Node->getOperatorLoc());
    PrintExpr(Node->getArg(0));

  } else if (Node->getNumArgs() == 2) {
    PrintExpr(Node->getArg(0));
    OS << ' ' << getOperatorSpelling(Kind);
    ctx.MarkLocation(Node->getOperatorLoc());
    OS << ' ';
    PrintExpr(Node->getArg(1));
  } else {
    llvm_unreachable("unknown overloaded operator");
  }
}

void StmtPrinter::VisitCXXMemberCallExpr(clang::CXXMemberCallExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // If we have a conversion operator call only print the argument.
  clang::CXXMethodDecl *MD = Node->getMethodDecl();
  if (MD && clang::isa<clang::CXXConversionDecl>(MD)) {
    PrintExpr(Node->getImplicitObjectArgument());
    return;
  }
  VisitCallExpr(clang::cast<clang::CallExpr>(Node));
}

void StmtPrinter::VisitCUDAKernelCallExpr(clang::CUDAKernelCallExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getCallee());
  ctx.Tokenize();
  OS << "<<<";
  ctx.Tokenize();
  PrintCallArgs(Node->getConfig());
  OS << ">>>";
  ctx.Tokenize();
  OS << "(";
  PrintCallArgs(Node);
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitCXXRewrittenBinaryOperator(
    clang::CXXRewrittenBinaryOperator *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  clang::CXXRewrittenBinaryOperator::DecomposedForm Decomposed =
      Node->getDecomposedForm();
  PrintExpr(const_cast<clang::Expr*>(Decomposed.LHS));
  OS << ' ' << clang::BinaryOperator::getOpcodeStr(Decomposed.Opcode) << ' ';
  PrintExpr(const_cast<clang::Expr*>(Decomposed.RHS));
}

void StmtPrinter::VisitCXXNamedCastExpr(clang::CXXNamedCastExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << Node->getCastName();
  ctx.MarkLocation(Node->getBeginLoc());
  OS << " <";
  ctx.MarkLocation(Node->getAngleBrackets().getBegin());
  tokens.TryChangeLastKind(TokenKind::kLess, TokenKind::kLAngle);
  {
    TagDefinitionPolicyRAII disable_tags(Policy);
    printQualType(Node->getTypeAsWritten(), OS, Policy);
  }
  OS << " >";
  ctx.MarkLocation(Node->getAngleBrackets().getEnd());
  tokens.TryChangeLastKind(TokenKind::kGreater, TokenKind::kRAngle);
  OS << "(";
  PrintExpr(Node->getSubExpr());
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitCXXStaticCastExpr(clang::CXXStaticCastExpr *Node) {
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXDynamicCastExpr(clang::CXXDynamicCastExpr *Node) {
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXReinterpretCastExpr(clang::CXXReinterpretCastExpr *Node) {
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXConstCastExpr(clang::CXXConstCastExpr *Node) {
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitBuiltinBitCastExpr(clang::BuiltinBitCastExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_bit_cast";
  ctx.MarkLocation(Node->getBeginLoc());  // KWLoc.
  OS << "(";
  printQualType(Node->getTypeInfoAsWritten()->getType(), OS, Policy);
  OS << ", ";
  PrintExpr(Node->getSubExpr());
  OS << ")";
  ctx.MarkLocation(Node->getEndLoc());  // RParenLoc.
}

void StmtPrinter::VisitCXXAddrspaceCastExpr(clang::CXXAddrspaceCastExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXTypeidExpr(clang::CXXTypeidExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "typeid";
  OS << "(";
  if (Node->isTypeOperand()) {
    printQualType(Node->getTypeOperandSourceInfo()->getType(), OS, Policy);
  } else {
    PrintExpr(Node->getExprOperand());
  }
  OS << ")";
}

void StmtPrinter::VisitCXXUuidofExpr(clang::CXXUuidofExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__uuidof(";
  if (Node->isTypeOperand()) {
    printQualType(Node->getTypeOperandSourceInfo()->getType(), OS, Policy);
  } else {
    PrintExpr(Node->getExprOperand());
  }
  OS << ")";
}

void StmtPrinter::VisitMSPropertyRefExpr(clang::MSPropertyRefExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBaseExpr());
  if (Node->isArrow())
    OS << "->";
  else
    OS << ".";
  if (clang::NestedNameSpecifier *Qualifier =
      Node->getQualifierLoc().getNestedNameSpecifier())
    NestedNameSpecifier_print(Qualifier, *this, Policy);
  OS << Node->getPropertyDecl()->getDeclName();
  ctx.MarkLocation(Node->getMemberLoc());
}

void StmtPrinter::VisitMSPropertySubscriptExpr(clang::MSPropertySubscriptExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getBase());
  OS << "[";
  PrintExpr(Node->getIdx());
  OS << "]";
  ctx.MarkLocation(Node->getRBracketLoc());
}

void StmtPrinter::VisitUserDefinedLiteral(clang::UserDefinedLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  switch (Node->getLiteralOperatorKind()) {
  case clang::UserDefinedLiteral::LOK_Raw:
    OS << clang::cast<clang::StringLiteral>(Node->getArg(0)->IgnoreImpCasts())->getString();
    break;
  case clang::UserDefinedLiteral::LOK_Template: {
    const auto *DRE = clang::cast<clang::DeclRefExpr>(Node->getCallee()->IgnoreImpCasts());
    const clang::TemplateArgumentList *Args =
      clang::cast<clang::FunctionDecl>(DRE->getDecl())->getTemplateSpecializationArgs();
    assert(Args);

    if (Args->size() != 1 || Args->get(0).getKind() != clang::TemplateArgument::Pack) {
      const clang::TemplateParameterList *TPL = nullptr;
      if (!DRE->hadMultipleCandidates())
        if (const auto *TD = clang::dyn_cast<clang::TemplateDecl>(DRE->getDecl()))
          TPL = TD->getTemplateParameters();
      OS << "operator \"\"" << Node->getUDSuffix()->getName();
      TagDefinitionPolicyRAII tag_raii(Policy);
      printTemplateArgumentList(*this, Args->asArray(), Policy, TPL);
      OS << "()";
      return;
    }

    const clang::TemplateArgument &Pack = Args->get(0);
    for (const auto &P : Pack.pack_elements()) {
      char C = (char)P.getAsIntegral().getZExtValue();
      OS << C;
    }
    break;
  }
  case clang::UserDefinedLiteral::LOK_Integer: {
    // Print integer literal without suffix.
    const auto *Int = clang::cast<clang::IntegerLiteral>(Node->getCookedLiteral());
    OS << toString(Int->getValue(), 10, /*isSigned*/false);
    break;
  }
  case clang::UserDefinedLiteral::LOK_Floating: {
    // Print floating literal without suffix.
    auto *Float = clang::cast<clang::FloatingLiteral>(Node->getCookedLiteral());
    PrintFloatingLiteral(OS, Float, /*PrintSuffix=*/false);
    break;
  }
  case clang::UserDefinedLiteral::LOK_String:
  case clang::UserDefinedLiteral::LOK_Character:
    PrintExpr(Node->getCookedLiteral());
    break;
  }
  OS << Node->getUDSuffix()->getName();
}

void StmtPrinter::VisitCXXBoolLiteralExpr(clang::CXXBoolLiteralExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << (Node->getValue() ? "true" : "false");
  ctx.MarkLocation(Node->getLocation());
}

void StmtPrinter::VisitCXXNullPtrLiteralExpr(clang::CXXNullPtrLiteralExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "nullptr";
  ctx.MarkLocation(Node->getLocation());
}

void StmtPrinter::VisitCXXThisExpr(clang::CXXThisExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "this";
  ctx.MarkLocation(Node->getLocation());
}

void StmtPrinter::VisitCXXThrowExpr(clang::CXXThrowExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (!Node->getSubExpr()) {
    OS << "throw";
    ctx.MarkLocation(Node->getThrowLoc());
  } else {
    OS << "throw ";
    ctx.MarkLocation(Node->getThrowLoc());
    PrintExpr(Node->getSubExpr());
  }
}

void StmtPrinter::VisitCXXDefaultArgExpr(clang::CXXDefaultArgExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // Nothing to print: we picked up the default argument.
}

void StmtPrinter::VisitCXXDefaultInitExpr(clang::CXXDefaultInitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // Nothing to print: we picked up the default initializer.
}

void StmtPrinter::VisitCXXFunctionalCastExpr(clang::CXXFunctionalCastExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  auto TargetType = Node->getType();
  auto *Auto = TargetType->getContainedDeducedType();
  bool Bare = Auto && Auto->isDeduced();

  // Parenthesize deduced casts.
  if (Bare)
    OS << '(';

  {
    TagDefinitionPolicyRAII disable_tags(Policy);
    TargetType.print(OS, Policy);
  }

  if (Bare)
    OS << ')';

  // No extra braces surrounding the inner construct.
  if (!Node->isListInitialization())
    OS << '(';
  PrintExpr(Node->getSubExpr());
  if (!Node->isListInitialization())
    OS << ')';
}

void StmtPrinter::VisitCXXBindTemporaryExpr(clang::CXXBindTemporaryExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitCXXTemporaryObjectExpr(clang::CXXTemporaryObjectExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  printQualType(Node->getType(), OS, Policy);
  if (Node->isStdInitListInitialization())
    /* Nothing to do; braces are part of creating the std::initializer_list. */;
  else if (Node->isListInitialization())
    OS << "{";
  else
    OS << "(";
  for (clang::CXXTemporaryObjectExpr::arg_iterator Arg = Node->arg_begin(),
                                         ArgEnd = Node->arg_end();
       Arg != ArgEnd; ++Arg) {
    if ((*Arg)->isDefaultArgument())
      break;
    if (Arg != Node->arg_begin())
      OS << ", ";
    PrintExpr(*Arg);
  }
  if (Node->isStdInitListInitialization()) {
    /* See above. */;
  }
  else if (Node->isListInitialization())
    OS << "}";
  else
    OS << ")";
}

void StmtPrinter::VisitLambdaExpr(clang::LambdaExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << '[';
  ctx.MarkLocation(Node->getIntroducerRange().getBegin());
  bool NeedComma = false;
  switch (Node->getCaptureDefault()) {
  case clang::LCD_None:
    break;

  case clang::LCD_ByCopy:
    OS << '=';
    ctx.MarkLocation(Node->getCaptureDefaultLoc());
    NeedComma = true;
    break;

  case clang::LCD_ByRef:
    OS << '&';
    ctx.MarkLocation(Node->getCaptureDefaultLoc());
    NeedComma = true;
    break;
  }
  for (clang::LambdaExpr::capture_iterator C = Node->explicit_capture_begin(),
                                 CEnd = Node->explicit_capture_end();
       C != CEnd;
       ++C) {
    if (C->capturesVLAType())
      continue;

    if (NeedComma)
      OS << ", ";
    NeedComma = true;

    switch (C->getCaptureKind()) {
    case clang::LCK_This:
      OS << "this";
      break;

    case clang::LCK_StarThis:
      OS << "*this";
      break;

    case clang::LCK_ByRef:
      if (Node->getCaptureDefault() != clang::LCD_ByRef || Node->isInitCapture(C)) {
        OS << '&';
      }
      OS << C->getCapturedVar()->getName();
      break;

    case clang::LCK_ByCopy:
      OS << C->getCapturedVar()->getName();
      break;

    case clang::LCK_VLAType:
      llvm_unreachable("VLA type in explicit captures.");
    }

    if (C->isPackExpansion())
      OS << "...";

    if (Node->isInitCapture(C)) {
      // Init captures are always VarDecl.
      clang::VarDecl *D = cast<clang::VarDecl>(C->getCapturedVar());

      llvm::StringRef Pre;
      llvm::StringRef Post;
      if (D->getInitStyle() == clang::VarDecl::CallInit &&
          !clang::isa<clang::ParenListExpr>(D->getInit())) {
        Pre = "(";
        Post = ")";
      } else if (D->getInitStyle() == clang::VarDecl::CInit) {
        Pre = " = ";
      }

      OS << Pre;
      PrintExpr(D->getInit());
      OS << Post;
    }
  }
  OS << ']';
  ctx.MarkLocation(Node->getIntroducerRange().getEnd());

  clang::CXXMethodDecl *Method = Node->getCallOperator();
  TokenPrinterContext ctx2(OS, Method->getParent(), tokens);
  TokenPrinterContext ctx3(OS, Method, tokens);

  if (!Node->getExplicitTemplateParameters().empty()) {
    Node->getTemplateParameterList()->print(
        OS, Node->getLambdaClass()->getASTContext(),
        /*OmitTemplateKW*/true);
  }

  if (Node->hasExplicitParameters()) {
    OS << '(';
    NeedComma = false;
    for (const auto *P : Method->parameters()) {
      if (NeedComma) {
        OS << ", ";
      } else {
        NeedComma = true;
      }
      std::function<void(void)> ParamStrFn = [=] (void) {
        TokenPrinterContext ctx(OS, P, tokens);
        OS << P->getNameAsString();
      };

      printQualType(P->getOriginalType(), OS, Policy, &ParamStrFn);
    }
    if (Method->isVariadic()) {
      if (NeedComma)
        OS << ", ";
      OS << "...";
    }
    OS << ')';

    if (Node->isMutable())
      OS << " mutable";

    auto *Proto = Method->getType()->castAs<clang::FunctionProtoType>();
    Proto->printExceptionSpecification(OS, Policy);

    // FIXME: Attributes

    // Print the trailing return type if it was specified in the source.
    if (Node->hasExplicitResultType()) {
      OS << " -> ";
      printQualType(Proto->getReturnType(), OS, Policy);
    }
  }

  // Print the body.
  OS << ' ';
  PrintRawCompoundStmt(Node->getCompoundStmtBody());
}

void StmtPrinter::VisitCXXScalarValueInitExpr(clang::CXXScalarValueInitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (clang::TypeSourceInfo *TSInfo = Node->getTypeSourceInfo())
    printQualType(TSInfo->getType(), OS, Policy);
  else
    printQualType(Node->getType(), OS, Policy);
  OS << "()";
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitCXXNewExpr(clang::CXXNewExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  if (E->isGlobalNew())
    OS << "::";
  OS << "new ";
  unsigned NumPlace = E->getNumPlacementArgs();
  if (NumPlace > 0 && !clang::isa<clang::CXXDefaultArgExpr>(E->getPlacementArg(0))) {
    OS << "(";
    PrintExpr(E->getPlacementArg(0));
    for (unsigned i = 1; i < NumPlace; ++i) {
      if (clang::isa<clang::CXXDefaultArgExpr>(E->getPlacementArg(i)))
        break;
      OS << ", ";
      PrintExpr(E->getPlacementArg(i));
    }
    OS << ") ";
  }
  if (E->isParenTypeId())
    OS << "(";

  std::function<void(void)> TypeSFn = [] (void) -> void {};
  if (E->isArray()) {
    TypeSFn = [=, Size = E->getArraySize()] (void) {
      OS << '[';
      if (Size && *Size) {
        this->Visit(*Size);
      }
      OS << ']';
    };
  }

  printQualType(E->getAllocatedType(), OS, Policy, &TypeSFn);
  if (E->isParenTypeId())
    OS << ")";

  clang::CXXNewInitializationStyle InitStyle = E->getInitializationStyle();
  if (InitStyle != clang::CXXNewInitializationStyle::None) {
    bool Bare = InitStyle == clang::CXXNewInitializationStyle::Parens &&
                !clang::isa<clang::ParenListExpr>(E->getInitializer());
    if (Bare) {
      OS << "(";
      ctx.MarkLocation(E->getDirectInitRange().getBegin());
    }
    PrintExpr(E->getInitializer());
    if (Bare) {
      OS << ")";
      ctx.MarkLocation(E->getDirectInitRange().getEnd());
    }
  }
}

void StmtPrinter::VisitCXXDeleteExpr(clang::CXXDeleteExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  if (E->isGlobalDelete())
    OS << "::";
  OS << "delete ";
  ctx.MarkLocation(E->getBeginLoc());
  if (E->isArrayForm())
    OS << "[] ";
  PrintExpr(E->getArgument());
}

void StmtPrinter::VisitCXXPseudoDestructorExpr(clang::CXXPseudoDestructorExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  PrintExpr(E->getBase());
  if (E->isArrow())
    OS << "->";
  else
    OS << '.';

  ctx.MarkLocation(E->getOperatorLoc());

  if (E->getQualifier()) {
    E->getQualifier()->print(OS, Policy);

    ctx.MarkLocation(E->getColonColonLoc());  // TODO(pag): Hrmm...
  }

  OS << "~";
  ctx.MarkLocation(E->getTildeLoc());

  if (clang::IdentifierInfo *II = E->getDestroyedTypeIdentifier())
    OS << II->getName();
  else
    printQualType(E->getDestroyedType(), OS, Policy);
}

void StmtPrinter::VisitCXXConstructExpr(clang::CXXConstructExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  if (E->isListInitialization() && !E->isStdInitListInitialization()) {
    OS << "{";
    ctx.MarkLocation(E->getParenOrBraceRange().getBegin());
  }

  for (unsigned i = 0, e = E->getNumArgs(); i != e; ++i) {
    if (clang::isa<clang::CXXDefaultArgExpr>(E->getArg(i))) {
      // Don't print any defaulted arguments
      break;
    }

    if (i) OS << ", ";
    PrintExpr(E->getArg(i));
  }

  if (E->isListInitialization() && !E->isStdInitListInitialization()) {
    OS << "}";
    ctx.MarkLocation(E->getParenOrBraceRange().getEnd());
  }
}

void StmtPrinter::VisitCXXInheritedCtorInitExpr(clang::CXXInheritedCtorInitExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  // Parens are printed by the surrounding context.
  OS << "<forwarded>";  // TODO(pag): Hrmmm...
}

void StmtPrinter::VisitCXXStdInitializerListExpr(clang::CXXStdInitializerListExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  PrintExpr(E->getSubExpr());
}

void StmtPrinter::VisitExprWithCleanups(clang::ExprWithCleanups *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  // Just forward to the subexpression.
  PrintExpr(E->getSubExpr());
}

void
StmtPrinter::VisitCXXUnresolvedConstructExpr(
    clang::CXXUnresolvedConstructExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  printQualType(Node->getTypeAsWritten(), OS, Policy);
  if (!Node->isListInitialization()) {
    OS << "(";
    ctx.MarkLocation(Node->getLParenLoc());
  }
  for (auto Arg = Node->arg_begin(), ArgEnd = Node->arg_end(); Arg != ArgEnd;
       ++Arg) {
    if (Arg != Node->arg_begin())
      OS << ", ";
    PrintExpr(*Arg);
  }
  if (!Node->isListInitialization()) {
    OS << ")";
    ctx.MarkLocation(Node->getRParenLoc());
  }
}

void StmtPrinter::VisitCXXDependentScopeMemberExpr(
    clang::CXXDependentScopeMemberExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (!Node->isImplicitAccess()) {
    PrintExpr(Node->getBase());
    OS << (Node->isArrow() ? "->" : ".");
    ctx.MarkLocation(Node->getOperatorLoc());
  }
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    NestedNameSpecifier_print(Qualifier, *this, Policy);
  if (Node->hasTemplateKeyword()) {
    OS << "template ";
    ctx.MarkLocation(Node->getTemplateKeywordLoc());
  }
  OS << Node->getMemberNameInfo();
  if (Node->hasExplicitTemplateArgs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    printTemplateArgumentList(*this, Node->template_arguments(), Policy);
  }
}

void StmtPrinter::VisitUnresolvedMemberExpr(clang::UnresolvedMemberExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  if (!Node->isImplicitAccess()) {
    PrintExpr(Node->getBase());
    OS << (Node->isArrow() ? "->" : ".");
    ctx.MarkLocation(Node->getOperatorLoc());
  }
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    NestedNameSpecifier_print(Qualifier, *this, Policy);
  if (Node->hasTemplateKeyword()) {
    OS << "template ";
    ctx.MarkLocation(Node->getTemplateKeywordLoc());
  }
  OS << Node->getMemberNameInfo();
  if (Node->hasExplicitTemplateArgs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    printTemplateArgumentList(*this, Node->template_arguments(), Policy);
  }
}

void StmtPrinter::VisitTypeTraitExpr(clang::TypeTraitExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << getTraitSpelling(E->getTrait());
  ctx.MarkLocation(E->getBeginLoc());

  OS << "(";
  for (unsigned I = 0, N = E->getNumArgs(); I != N; ++I) {
    if (I > 0)
      OS << ", ";
    printQualType(E->getArg(I)->getType(), OS, Policy);
  }
  OS << ")";
  ctx.MarkLocation(E->getEndLoc());  // RParenLoc
}

void StmtPrinter::VisitArrayTypeTraitExpr(clang::ArrayTypeTraitExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << getTraitSpelling(E->getTrait());
  ctx.MarkLocation(E->getBeginLoc());
  OS << '(';
  printQualType(E->getQueriedType(), OS, Policy);
  OS << ')';
  ctx.MarkLocation(E->getEndLoc());  // RParenLoc
}

void StmtPrinter::VisitExpressionTraitExpr(clang::ExpressionTraitExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << getTraitSpelling(E->getTrait());
  ctx.MarkLocation(E->getBeginLoc());
  OS << '(';
  PrintExpr(E->getQueriedExpression());
  OS << ')';
  ctx.MarkLocation(E->getEndLoc());  // RParenLoc
}

void StmtPrinter::VisitCXXNoexceptExpr(clang::CXXNoexceptExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "noexcept(";
  PrintExpr(E->getOperand());
  OS << ")";
}

void StmtPrinter::VisitPackExpansionExpr(clang::PackExpansionExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  PrintExpr(E->getPattern());
  OS << "...";
  ctx.MarkLocation(E->getEllipsisLoc());
}

void StmtPrinter::VisitSizeOfPackExpr(clang::SizeOfPackExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "sizeof...";
  ctx.MarkLocation(E->getOperatorLoc());  // TODO(pag): Will it lex as `sizeof` or `sizeof...`?
  OS << "(";
  OS << *E->getPack();
  OS << ")";
  ctx.MarkLocation(E->getRParenLoc());
}

void StmtPrinter::VisitSubstNonTypeTemplateParmPackExpr(
    clang::SubstNonTypeTemplateParmPackExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << *Node->getParameterPack();
}

void StmtPrinter::VisitSubstNonTypeTemplateParmExpr(
    clang::SubstNonTypeTemplateParmExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  Visit(Node->getReplacement());
}

void StmtPrinter::VisitFunctionParmPackExpr(clang::FunctionParmPackExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << *E->getParameterPack();
}

void StmtPrinter::VisitMaterializeTemporaryExpr(clang::MaterializeTemporaryExpr *Node){
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitCXXFoldExpr(clang::CXXFoldExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "(";
  ctx.MarkLocation(E->getLParenLoc());
  if (E->getLHS()) {
    PrintExpr(E->getLHS());
    OS << " " << clang::BinaryOperator::getOpcodeStr(E->getOperator()) << " ";
  }
  OS << "...";
  ctx.MarkLocation(E->getEllipsisLoc());
  if (E->getRHS()) {
    OS << " " << clang::BinaryOperator::getOpcodeStr(E->getOperator()) << " ";
    PrintExpr(E->getRHS());
  }
  OS << ")";
  ctx.MarkLocation(E->getRParenLoc());
}

void StmtPrinter::VisitCXXParenListInitExpr(clang::CXXParenListInitExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "(";
  auto sep = "";
  for (clang::Expr *E : Node->getInitExprs()) {
    OS << sep;
    PrintExpr(E);
    sep = ", ";
  }
  OS << ")";
}

void StmtPrinter::VisitConceptSpecializationExpr(clang::ConceptSpecializationExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  clang::NestedNameSpecifierLoc NNS = E->getNestedNameSpecifierLoc();
  if (NNS)
    NNS.getNestedNameSpecifier()->print(OS, Policy);
  if (E->getTemplateKWLoc().isValid()) {
    OS << "template ";
    ctx.MarkLocation(E->getTemplateKWLoc());
  }
  OS << E->getFoundDecl()->getName();

  TagDefinitionPolicyRAII disable_tags(Policy);
  printTemplateArgumentList(*this,
                            E->getTemplateArgsAsWritten()->arguments(), Policy,
                            E->getNamedConcept()->getTemplateParameters());
}

void StmtPrinter::VisitRequiresExpr(clang::RequiresExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "requires ";
  ctx.MarkLocation(E->getRequiresKWLoc());
  auto LocalParameters = E->getLocalParameters();
  if (!LocalParameters.empty()) {
    OS << "(";
    for (clang::ParmVarDecl *LocalParam : LocalParameters) {
      PrintRawDecl(LocalParam);
      if (LocalParam != LocalParameters.back())
        OS << ", ";
    }

    OS << ") ";
  }
  OS << "{ ";
  auto Requirements = E->getRequirements();
  for (clang::concepts::Requirement *Req : Requirements) {
    if (auto *TypeReq = clang::dyn_cast<clang::concepts::TypeRequirement>(Req)) {
      if (TypeReq->isSubstitutionFailure())
        OS << "<<error-type>>";
      else
        printQualType(TypeReq->getType()->getType(), OS, Policy);
    } else if (auto *ExprReq = clang::dyn_cast<clang::concepts::ExprRequirement>(Req)) {
      if (ExprReq->isCompound())
        OS << "{ ";
      if (ExprReq->isExprSubstitutionFailure())
        OS << "<<error-expression>>";
      else
        PrintExpr(ExprReq->getExpr());
      if (ExprReq->isCompound()) {
        OS << " }";
        if (ExprReq->getNoexceptLoc().isValid())
          OS << " noexcept";
        const auto &RetReq = ExprReq->getReturnTypeRequirement();
        if (!RetReq.isEmpty()) {
          OS << " -> ";
          if (RetReq.isSubstitutionFailure())
            OS << "<<error-type>>";
          else if (RetReq.isTypeConstraint())
            RetReq.getTypeConstraint()->print(OS, Policy);
        }
      }
    } else {
      auto *NestedReq = clang::cast<clang::concepts::NestedRequirement>(Req);
      OS << "requires ";
      if (NestedReq->hasInvalidConstraint())
        OS << "<<error-expression>>";
      else
        PrintExpr(NestedReq->getConstraintExpr());
    }
    OS << "; ";
  }
  OS << "}";
  ctx.MarkLocation(E->getRBraceLoc());
}

// C++ Coroutines TS

void StmtPrinter::VisitCoroutineBodyStmt(clang::CoroutineBodyStmt *S) {
  TokenPrinterContext ctx(OS, S, tokens);
  Visit(S->getBody());
}

void StmtPrinter::VisitCoreturnStmt(clang::CoreturnStmt *S) {
  TokenPrinterContext ctx(OS, S, tokens);
  OS << "co_return";
  ctx.MarkLocation(S->getKeywordLoc());
  if (S->getOperand()) {
    OS << " ";
    Visit(S->getOperand());
  }
  OS << ";";
}

void StmtPrinter::VisitCoawaitExpr(clang::CoawaitExpr *S) {
  TokenPrinterContext ctx(OS, S, tokens);
  OS << "co_await ";
  ctx.MarkLocation(S->getKeywordLoc());
  PrintExpr(S->getOperand());
}

void StmtPrinter::VisitDependentCoawaitExpr(clang::DependentCoawaitExpr *S) {
  TokenPrinterContext ctx(OS, S, tokens);
  OS << "co_await ";
  ctx.MarkLocation(S->getKeywordLoc());
  PrintExpr(S->getOperand());
}

void StmtPrinter::VisitCoyieldExpr(clang::CoyieldExpr *S) {
  TokenPrinterContext ctx(OS, S, tokens);
  OS << "co_yield ";
  ctx.MarkLocation(S->getKeywordLoc());
  PrintExpr(S->getOperand());
}

// Obj-C

void StmtPrinter::VisitObjCStringLiteral(clang::ObjCStringLiteral *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "@";
  ctx.MarkLocation(Node->getAtLoc());
  VisitStringLiteral(Node->getString());
}

void StmtPrinter::VisitObjCBoxedExpr(clang::ObjCBoxedExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "@";
  ctx.MarkLocation(E->getAtLoc());
  Visit(E->getSubExpr());
}

void StmtPrinter::VisitObjCArrayLiteral(clang::ObjCArrayLiteral *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "@[ ";
  clang::ObjCArrayLiteral::child_range Ch = E->children();
  for (auto I = Ch.begin(), E = Ch.end(); I != E; ++I) {
    if (I != Ch.begin())
      OS << ", ";
    Visit(*I);
  }
  OS << " ]";
}

void StmtPrinter::VisitObjCDictionaryLiteral(clang::ObjCDictionaryLiteral *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << "@{ ";
  for (unsigned I = 0, N = E->getNumElements(); I != N; ++I) {
    if (I > 0)
      OS << ", ";

    clang::ObjCDictionaryElement Element = E->getKeyValueElement(I);
    Visit(Element.Key);
    OS << " : ";
    Visit(Element.Value);
    if (Element.isPackExpansion())
      OS << "...";
  }
  OS << " }";
}

void StmtPrinter::VisitObjCEncodeExpr(clang::ObjCEncodeExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "@";
  ctx.MarkLocation(Node->getAtLoc());

  OS << "encode(";
  printQualType(Node->getEncodedType(), OS, Policy);
  OS << ')';
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitObjCSelectorExpr(clang::ObjCSelectorExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "@";
  ctx.MarkLocation(Node->getAtLoc());
  OS << "selector(";
  Node->getSelector().print(OS);
  OS << ')';
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitObjCProtocolExpr(clang::ObjCProtocolExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "@";
  ctx.MarkLocation(Node->getAtLoc());
  OS << "protocol(" << *Node->getProtocol() << ')';
  ctx.MarkLocation(Node->getRParenLoc());
}

void StmtPrinter::VisitObjCMessageExpr(clang::ObjCMessageExpr *Mess) {
  TokenPrinterContext ctx(OS, Mess, tokens);
  OS << "[";
  ctx.MarkLocation(Mess->getBeginLoc());  // LBracLoc
  switch (Mess->getReceiverKind()) {
  case clang::ObjCMessageExpr::Instance:
    PrintExpr(Mess->getInstanceReceiver());
    break;

  case clang::ObjCMessageExpr::Class:
    printQualType(Mess->getClassReceiver(), OS, Policy);
    break;

  case clang::ObjCMessageExpr::SuperInstance:
  case clang::ObjCMessageExpr::SuperClass:
    OS << "Super";
    ctx.MarkLocation(Mess->getSuperLoc());
    break;
  }

  OS << ' ';
  clang::Selector selector = Mess->getSelector();
  if (selector.isUnarySelector()) {
    OS << selector.getNameForSlot(0);
  } else {
    for (unsigned i = 0, e = Mess->getNumArgs(); i != e; ++i) {
      if (i < selector.getNumArgs()) {
        if (i > 0) OS << ' ';
        if (selector.getIdentifierInfoForSlot(i))
          OS << selector.getIdentifierInfoForSlot(i)->getName() << ':';
        else
           OS << ":";
      }
      else OS << ", "; // Handle variadic methods.

      PrintExpr(Mess->getArg(i));
    }
  }
  OS << "]";
  ctx.MarkLocation(Mess->getEndLoc());  // RBracLoc
}

void StmtPrinter::VisitObjCBoolLiteralExpr(clang::ObjCBoolLiteralExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << (Node->getValue() ? "__objc_yes" : "__objc_no");
  ctx.MarkLocation(Node->getLocation());
}

void
StmtPrinter::VisitObjCIndirectCopyRestoreExpr(clang::ObjCIndirectCopyRestoreExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  PrintExpr(E->getSubExpr());
}

void
StmtPrinter::VisitObjCBridgedCastExpr(clang::ObjCBridgedCastExpr *E) {
  TokenPrinterContext ctx(OS, E, tokens);
  OS << '(';
  ctx.MarkLocation(E->getLParenLoc());

  OS << E->getBridgeKindName();
  ctx.MarkLocation(E->getBridgeKeywordLoc());
  printQualType(E->getType(), OS, Policy);
  OS << ')';
  PrintExpr(E->getSubExpr());
}

void StmtPrinter::VisitBlockExpr(clang::BlockExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  clang::BlockDecl *BD = Node->getBlockDecl();
  OS << "^";
  ctx.MarkLocation(Node->getCaretLocation());

  const clang::FunctionType *AFT = Node->getFunctionType();

  if (clang::isa<clang::FunctionNoProtoType>(AFT)) {
    OS << "()";
  } else if (!BD->param_empty() || clang::cast<clang::FunctionProtoType>(AFT)->isVariadic()) {
    OS << '(';
    for (clang::BlockDecl::param_iterator AI = BD->param_begin(),
         E = BD->param_end(); AI != E; ++AI) {
      if (AI != BD->param_begin()) OS << ", ";
      std::function<void(void)> ParamStrFn = [=] (void) {
        clang::ParmVarDecl *P = *AI;
        TokenPrinterContext ctx(OS, P, tokens);
        OS << P->getNameAsString();
      };
      printQualType((*AI)->getType(), OS, Policy, &ParamStrFn);
    }

    const auto *FT = clang::cast<clang::FunctionProtoType>(AFT);
    if (FT->isVariadic()) {
      if (!BD->param_empty()) OS << ", ";
      OS << "...";
    }
    OS << ')';
  }
  OS << "{ }";
}

void StmtPrinter::VisitOpaqueValueExpr(clang::OpaqueValueExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  PrintExpr(Node->getSourceExpr());
}

void StmtPrinter::VisitTypoExpr(clang::TypoExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  // TODO: Print something reasonable for a TypoExpr, if necessary.
  llvm_unreachable("Cannot print TypoExpr nodes");
}

void StmtPrinter::VisitRecoveryExpr(clang::RecoveryExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "<recovery-expr>(";
  const char *Sep = "";
  for (clang::Expr *E : Node->subExpressions()) {
    OS << Sep;
    PrintExpr(E);
    Sep = ", ";
  }
  OS << ')';
}

void StmtPrinter::VisitAsTypeExpr(clang::AsTypeExpr *Node) {
  TokenPrinterContext ctx(OS, Node, tokens);
  OS << "__builtin_astype";
  ctx.MarkLocation(Node->getBuiltinLoc());
  OS << "(";
  PrintExpr(Node->getSrcExpr());
  OS << ", ";
  printQualType(Node->getType(), OS, Policy);
  OS << ")";
  ctx.MarkLocation(Node->getRParenLoc());
}

PrintedTokenRange PrintedTokenRange::Create(clang::ASTContext &context,
                                            const clang::PrintingPolicy &policy,
                                            clang::Stmt *stmt) {
  std::string data;
  raw_string_ostream out(data, 0);
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);

  if (stmt) {
    PrintingPolicyAdaptor ppa;
    PrintingPolicyAdaptorRAII ppa_set_reset(tokens, ppa);
    StmtPrinter printer(out, nullptr, *tokens, policy);
    printer.Visit(stmt);
  }

  tokens->AddTrailingEOF();
  return PrintedTokenRangeImpl::ToPrintedTokenRange(std::move(tokens));
}

PrintedTokenRange PrintedTokenRange::Create(const std::shared_ptr<ASTImpl> &ast,
                                            clang::Stmt *stmt,
                                            const PrintingPolicy &high_pp) {
  std::string data;
  raw_string_ostream out(data, 0);
  auto &context = ast->tu->getASTContext();
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);

  // Top-level context should be the AST.
  tokens->ast = ast;
  tokens->contexts.emplace_back(*ast);

  if (stmt) {
    PrintingPolicyAdaptor ppa(ast, high_pp);
    PrintingPolicyAdaptorRAII ppa_set_reset(tokens, ppa);

    clang::PrintingPolicy pp = *(ast->printing_policy);
    pp.SuppressTemplateArgsInCXXConstructors = true;
    pp.FullyQualifiedName = false;
    pp.TerseOutput = false;
    pp.SuppressDefaultTemplateArgs = false;
    pp.ConstantsAsWritten = true;
    pp.IncludeTagDefinition = high_pp.ShouldPrintTagBodies();

    StmtPrinter printer(out, nullptr, *tokens, pp);
    printer.Visit(stmt);
  }

  tokens->FixupInvalidTokenContexts(kASTTokenContextIndex);
  tokens->AddTrailingEOF();
  return PrintedTokenRangeImpl::ToPrintedTokenRange(std::move(tokens));
}

} // namespace pasta
