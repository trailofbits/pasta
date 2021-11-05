

#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclBase.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/ExprObjC.h>
#include <clang/AST/ExprOpenMP.h>
#include <clang/AST/NestedNameSpecifier.h>
#include <clang/AST/OpenMPClause.h>
#include <clang/AST/PrettyPrinter.h>
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtCXX.h>
#include <clang/AST/StmtObjC.h>
#include <clang/AST/StmtOpenMP.h>
#include <clang/AST/StmtVisitor.h>
#include <clang/AST/TemplateBase.h>
#include <clang/AST/Type.h>
#include <clang/Basic/CharInfo.h>
#include <clang/Basic/ExpressionTraits.h>
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/JsonSupport.h>
#include <clang/Basic/LLVM.h>
#include <clang/Basic/Lambda.h>
#include <clang/Basic/OpenMPKinds.h>
#include <clang/Basic/OperatorKinds.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/TypeTraits.h>
#include <clang/Lex/Lexer.h>
#include <llvm/ADT/ArrayRef.h>
#include <llvm/ADT/SmallString.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Casting.h>
#include <llvm/Support/Compiler.h>
#include <llvm/Support/ErrorHandling.h>
#include <llvm/Support/Format.h>

#include <clang/Basic/LangOptions.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Preprocessor.h>

#include <cassert>
#include <string>

#include "raw_ostream.h"
#include "../DeclPrinter.h"


//===----------------------------------------------------------------------===//
// StmtPrinter Visitor
//===----------------------------------------------------------------------===//

namespace pasta {

// Get the language option if the preprocessor instance
// is not available
static const clang::LangOptions &GetLangOptions() {
  static clang::LangOptions g_options;
  static std::once_flag g_once_flag;
  std::call_once(g_once_flag, []() {
    g_options.LineComment = true;
    g_options.C99 = true;
    g_options.C11 = true;
    g_options.CPlusPlus = true;
    g_options.CPlusPlus11 = true;
    g_options.CPlusPlus14 = true;
    g_options.CPlusPlus17 = true;
  });
  return g_options;
}

static std::unique_ptr<clang::Lexer>
getLexerStartingFromLoc(clang::SourceManager &sm, std::string str_buffer) {
  clang::StringRef buffer(str_buffer.data(), str_buffer.length());
  return std::make_unique<clang::Lexer>(
      clang::SourceLocation(),
      GetLangOptions(), buffer.begin(), buffer.data(),
      buffer.end());
}

static std::unique_ptr<clang::Lexer>
getLexerStartingFromLoc(const clang::Preprocessor &pp, std::string str_buffer) {
  auto &sm = pp.getSourceManager();
  auto Buf = llvm::MemoryBuffer::getMemBufferCopy(str_buffer);
  return std::make_unique<clang::Lexer>(
      clang::SourceLocation(), pp.getLangOpts(),
      Buf->getBufferStart(), Buf->getBufferStart(), Buf->getBufferEnd());
}

class PrintContext {
 public:
  PrintContext(const clang::Preprocessor &pp_, pasta::raw_string_ostream &out_,
               const clang::Stmt *stmt_, std::vector<FatTokenImpl> &tokens_,
               std::string caller_ = "")
               : pp(pp_), stmt(stmt_), out(out_), start_loc(out_.size()),
               tokens(tokens_), caller_fn(caller_) {}

  ~PrintContext(void) {
    llvm::errs() <<  "Stmt PrinterContext " << out.str() << " " << caller_fn << "\n";

    auto num_tokens = tokens.size();
    auto end_loc = out.str().size();

    auto lexer = getLexerStartingFromLoc(pp, out.str());
    if (!lexer.get()) {
      return;
    }

    clang::Token tok;
    lexer->SetKeepWhitespaceMode(true);
    lexer->SetCommentRetentionState(true);
    lexer->LexFromRawLexer(tok);
    int tok_index = 0;

    while (tok.isNot(clang::tok::eof)) {
      if (tok_index >= num_tokens) {
        auto loc = tok.getLocation().getRawEncoding();
        std::string tok_data;
        if (TryReadRawToken(pp.getSourceManager(), pp.getLangOpts(), tok, &tok_data)) {
          tokens.emplace_back(FatTokenImpl(loc, tok_data));
        }
      }

      tok_index++;
      lexer->LexFromRawLexer(tok);
    }

    // Update the decl pointer for Fat Tokens
    for (auto &tok : tokens) {
      auto offset = tok.getLocation();
      if ((offset >= start_loc) && (offset < end_loc) && (tok.stmt == nullptr)) {
        tok.stmt = stmt;
      }
    }
  }


  const clang::Preprocessor &pp;
  const clang::Stmt *stmt;
  pasta::raw_string_ostream &out;
  size_t start_loc;

  std::vector<FatTokenImpl> &tokens;
  std::string caller_fn;
};

  class StmtPrinter : public clang::StmtVisitor<StmtPrinter> {
    pasta::raw_string_ostream &OS;
    unsigned IndentLevel;
    clang::PrinterHelper* Helper;
    clang::PrintingPolicy Policy;
    std::string NL;
    const clang::ASTContext *Context;

  public:
    StmtPrinter(pasta::raw_string_ostream &os, clang::PrinterHelper *helper,
               const clang::Preprocessor &pp_, std::vector<FatTokenImpl> &tokens_,
                const clang::PrintingPolicy &Policy, unsigned Indentation = 0,
                clang::StringRef NL = "\n", const clang::ASTContext *Context = nullptr)
        : OS(os), IndentLevel(Indentation), Helper(helper), Policy(Policy),
          NL(NL), Context(Context), pp(pp_), tokens(tokens_) {}

    void PrintStmt(clang::Stmt *S) { PrintStmt(S, Policy.Indentation); }

    void PrintStmt(clang::Stmt *S, unsigned SubIndent) {
      IndentLevel += SubIndent;
      if (S && clang::isa<clang::Expr>(S)) {
        // If this is an expr used in a stmt context, indent and newline it.
        Indent();
        Visit(S);
        OS << ";" << NL;
      } else if (S) {
        Visit(S);
      } else {
        Indent() << "<<<NULL STATEMENT>>>" << NL;
      }
      IndentLevel -= SubIndent;
    }

    void PrintInitStmt(clang::Stmt *S, unsigned PrefixWidth) {
      // FIXME: Cope better with odd prefix widths.
      IndentLevel += (PrefixWidth + 1) / 2;
      if (auto *DS = clang::dyn_cast<clang::DeclStmt>(S))
        PrintRawDeclStmt(DS);
      else
        PrintExpr(clang::cast<clang::Expr>(S));
      OS << "; ";
      IndentLevel -= (PrefixWidth + 1) / 2;
    }

    void PrintControlledStmt(clang::Stmt *S) {
      if (auto *CS = clang::dyn_cast<clang::CompoundStmt>(S)) {
        OS << " ";
        PrintRawCompoundStmt(CS);
        OS << NL;
      } else {
        OS << NL;
        PrintStmt(S);
      }
    }

    void PrintRawCompoundStmt(clang::CompoundStmt *S);
    void PrintRawDecl(clang::Decl *D);
    void PrintRawDeclStmt(const clang::DeclStmt *S);
    void PrintRawIfStmt(clang::IfStmt *If);
    void PrintRawCXXCatchStmt(clang::CXXCatchStmt *Catch);
    void PrintCallArgs(clang::CallExpr *E);
    void PrintRawSEHExceptHandler(clang::SEHExceptStmt *S);
    void PrintRawSEHFinallyStmt(clang::SEHFinallyStmt *S);
    void PrintOMPExecutableDirective(clang::OMPExecutableDirective *S,
                                     bool ForceNoStmt = false);

    void PrintExpr(clang::Expr *E) {
      PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
      if (E)
        Visit(E);
      else
        OS << "<null expr>";
    }

    pasta::raw_string_ostream &Indent(int Delta = 0) {
      for (unsigned i = 0, e = IndentLevel+Delta; i < e; ++i)
        OS << "  ";
      return OS;
    }

    void Visit(clang::Stmt* S) {
      if (Helper && Helper->handledStmt(S,OS))
          return;
      else clang::StmtVisitor<StmtPrinter>::Visit(S);
    }

    void VisitStmt(clang::Stmt *Node) LLVM_ATTRIBUTE_UNUSED {
      Indent() << "<<unknown stmt type>>" << NL;
    }

    void VisitExpr(clang::Expr *Node) LLVM_ATTRIBUTE_UNUSED {
      OS << "<<unknown expr type>>";
    }

    void VisitCXXNamedCastExpr(clang::CXXNamedCastExpr *Node);

#define ABSTRACT_STMT(CLASS)
#define STMT(CLASS, PARENT) \
    void Visit##CLASS(clang::CLASS *Node);
#include "clang/AST/StmtNodes.inc"

    const clang::Preprocessor &pp;
    std::vector<FatTokenImpl> &tokens;
  };

} // namespace

//===----------------------------------------------------------------------===//
//  Stmt printing methods.
//===----------------------------------------------------------------------===//

/// PrintRawCompoundStmt - Print a compound stmt without indenting the {, and
/// with no newline after the }.
namespace pasta {

void StmtPrinter::PrintRawCompoundStmt(clang::CompoundStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "{" << NL;
  for (auto *I : Node->body())
    PrintStmt(I);

  Indent() << "}";
}

void StmtPrinter::PrintRawDecl(clang::Decl *D) {
  D->print(OS, Policy, IndentLevel);
}

void StmtPrinter::PrintRawDeclStmt(const clang::DeclStmt *S) {
  PrintContext ctx(pp, OS, S, tokens, __FUNCTION__);
  clang::SmallVector<clang::Decl *, 2> Decls(S->decls());
  clang::Decl::printGroup(Decls.data(), Decls.size(), OS, Policy, IndentLevel);
}

void StmtPrinter::VisitNullStmt(clang::NullStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << ";" << NL;
}

void StmtPrinter::VisitDeclStmt(clang::DeclStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent();
  PrintRawDeclStmt(Node);
  OS << ";" << NL;
}

void StmtPrinter::VisitCompoundStmt(clang::CompoundStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent();
  PrintRawCompoundStmt(Node);
  OS << "" << NL;
}

void StmtPrinter::VisitCaseStmt(clang::CaseStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent(-1) << "case ";
  PrintExpr(Node->getLHS());
  if (Node->getRHS()) {
    OS << " ... ";
    PrintExpr(Node->getRHS());
  }
  OS << ":" << NL;

  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::VisitDefaultStmt(clang::DefaultStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent(-1) << "default:" << NL;
  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::VisitLabelStmt(clang::LabelStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent(-1) << Node->getName() << ":" << NL;
  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::VisitAttributedStmt(clang::AttributedStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  for (const auto *Attr : Node->getAttrs()) {
    Attr->printPretty(OS, Policy);
  }

  PrintStmt(Node->getSubStmt(), 0);
}

void StmtPrinter::PrintRawIfStmt(clang::IfStmt *If) {
  PrintContext ctx(pp, OS, If, tokens, __FUNCTION__);
  OS << "if (";
  if (If->getInit())
    PrintInitStmt(If->getInit(), 4);
  if (const clang::DeclStmt *DS = If->getConditionVariableDeclStmt())
    PrintRawDeclStmt(DS);
  else
    PrintExpr(If->getCond());
  OS << ')';

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
  PrintContext ctx(pp, OS, If, tokens, __FUNCTION__);
  Indent();
  PrintRawIfStmt(If);
}

void StmtPrinter::VisitSwitchStmt(clang::SwitchStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "switch (";
  if (Node->getInit())
    PrintInitStmt(Node->getInit(), 8);
  if (const clang::DeclStmt *DS = Node->getConditionVariableDeclStmt())
    PrintRawDeclStmt(DS);
  else
    PrintExpr(Node->getCond());
  OS << ")";
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitWhileStmt(clang::WhileStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "while (";
  if (const clang::DeclStmt *DS = Node->getConditionVariableDeclStmt())
    PrintRawDeclStmt(DS);
  else
    PrintExpr(Node->getCond());
  OS << ")" << NL;
  PrintStmt(Node->getBody());
}

void StmtPrinter::VisitDoStmt(clang::DoStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "do ";
  if (auto *CS = clang::dyn_cast<clang::CompoundStmt>(Node->getBody())) {
    PrintRawCompoundStmt(CS);
    OS << " ";
  } else {
    OS << NL;
    PrintStmt(Node->getBody());
    Indent();
  }

  OS << "while (";
  PrintExpr(Node->getCond());
  OS << ");" << NL;
}

void StmtPrinter::VisitForStmt(clang::ForStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "for (";
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
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitObjCForCollectionStmt(clang::ObjCForCollectionStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "for (";
  if (auto *DS = clang::dyn_cast<clang::DeclStmt>(Node->getElement()))
    PrintRawDeclStmt(DS);
  else
    PrintExpr(clang::cast<clang::Expr>(Node->getElement()));
  OS << " in ";
  PrintExpr(Node->getCollection());
  OS << ")";
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitCXXForRangeStmt(clang::CXXForRangeStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "for (";
  if (Node->getInit())
    PrintInitStmt(Node->getInit(), 5);
  clang::PrintingPolicy SubPolicy(Policy);
  SubPolicy.SuppressInitializers = true;
  Node->getLoopVariable()->print(OS, SubPolicy, IndentLevel);
  OS << " : ";
  PrintExpr(Node->getRangeInit());
  OS << ")";
  PrintControlledStmt(Node->getBody());
}

void StmtPrinter::VisitMSDependentExistsStmt(clang::MSDependentExistsStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent();
  if (Node->isIfExists())
    OS << "__if_exists (";
  else
    OS << "__if_not_exists (";

  if (clang::NestedNameSpecifier *Qualifier
        = Node->getQualifierLoc().getNestedNameSpecifier())
    Qualifier->print(OS, Policy);

  OS << Node->getNameInfo() << ") ";

  PrintRawCompoundStmt(Node->getSubStmt());
}

void StmtPrinter::VisitGotoStmt(clang::GotoStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "goto " << Node->getLabel()->getName() << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitIndirectGotoStmt(clang::IndirectGotoStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "goto *";
  PrintExpr(Node->getTarget());
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitContinueStmt(clang::ContinueStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "continue;";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitBreakStmt(clang::BreakStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "break;";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitReturnStmt(clang::ReturnStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "return";
  if (Node->getRetValue()) {
    OS << " ";
    PrintExpr(Node->getRetValue());
  }
  OS << ";";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitGCCAsmStmt(clang::GCCAsmStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
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
    OS << Node->getLabelName(i);
  }

  OS << ");";
  if (Policy.IncludeNewlines) OS << NL;
}

void StmtPrinter::VisitMSAsmStmt(clang::MSAsmStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // FIXME: Implement MS style inline asm statement printer.
  Indent() << "__asm ";
  if (Node->hasBraces())
    OS << "{" << NL;
  OS << Node->getAsmString() << NL;
  if (Node->hasBraces())
    Indent() << "}" << NL;
}

void StmtPrinter::VisitCapturedStmt(clang::CapturedStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintStmt(Node->getCapturedDecl()->getBody());
}

void StmtPrinter::VisitObjCAtTryStmt(clang::ObjCAtTryStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "@try";
  if (auto *TS = clang::dyn_cast<clang::CompoundStmt>(Node->getTryBody())) {
    PrintRawCompoundStmt(TS);
    OS << NL;
  }

  for (unsigned I = 0, N = Node->getNumCatchStmts(); I != N; ++I) {
    clang::ObjCAtCatchStmt *catchStmt = Node->getCatchStmt(I);
    Indent() << "@catch(";
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
    PrintRawCompoundStmt(clang::dyn_cast<clang::CompoundStmt>(FS->getFinallyBody()));
    OS << NL;
  }
}

void StmtPrinter::VisitObjCAtFinallyStmt(clang::ObjCAtFinallyStmt *Node) {
}

void StmtPrinter::VisitObjCAtCatchStmt (clang::ObjCAtCatchStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "@catch (...) { /* todo */ } " << NL;
}

void StmtPrinter::VisitObjCAtThrowStmt(clang::ObjCAtThrowStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "@throw";
  if (Node->getThrowExpr()) {
    OS << " ";
    PrintExpr(Node->getThrowExpr());
  }
  OS << ";" << NL;
}

void StmtPrinter::VisitObjCAvailabilityCheckExpr(
    clang::ObjCAvailabilityCheckExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "@available(...)";
}

void StmtPrinter::VisitObjCAtSynchronizedStmt(clang::ObjCAtSynchronizedStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "@synchronized (";
  PrintExpr(Node->getSynchExpr());
  OS << ")";
  PrintRawCompoundStmt(Node->getSynchBody());
  OS << NL;
}

void StmtPrinter::VisitObjCAutoreleasePoolStmt(clang::ObjCAutoreleasePoolStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "@autoreleasepool";
  PrintRawCompoundStmt(dyn_cast<clang::CompoundStmt>(Node->getSubStmt()));
  OS << NL;
}

void StmtPrinter::PrintRawCXXCatchStmt(clang::CXXCatchStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "catch (";
  if (clang::Decl *ExDecl = Node->getExceptionDecl())
    PrintRawDecl(ExDecl);
  else
    OS << "...";
  OS << ") ";
  PrintRawCompoundStmt(cast<clang::CompoundStmt>(Node->getHandlerBlock()));
}

void StmtPrinter::VisitCXXCatchStmt(clang::CXXCatchStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent();
  PrintRawCXXCatchStmt(Node);
  OS << NL;
}

void StmtPrinter::VisitCXXTryStmt(clang::CXXTryStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "try ";
  PrintRawCompoundStmt(Node->getTryBlock());
  for (unsigned i = 0, e = Node->getNumHandlers(); i < e; ++i) {
    OS << " ";
    PrintRawCXXCatchStmt(Node->getHandler(i));
  }
  OS << NL;
}

void StmtPrinter::VisitSEHTryStmt(clang::SEHTryStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << (Node->getIsCXXTry() ? "try " : "__try ");
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__finally ";
  PrintRawCompoundStmt(Node->getBlock());
  OS << NL;
}

void StmtPrinter::PrintRawSEHExceptHandler(clang::SEHExceptStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__except (";
  VisitExpr(Node->getFilterExpr());
  OS << ")" << NL;
  PrintRawCompoundStmt(Node->getBlock());
  OS << NL;
}

void StmtPrinter::VisitSEHExceptStmt(clang::SEHExceptStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent();
  PrintRawSEHExceptHandler(Node);
  OS << NL;
}

void StmtPrinter::VisitSEHFinallyStmt(clang::SEHFinallyStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent();
  PrintRawSEHFinallyStmt(Node);
  OS << NL;
}

void StmtPrinter::VisitSEHLeaveStmt(clang::SEHLeaveStmt *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "__leave;";
  if (Policy.IncludeNewlines) OS << NL;
}

//===----------------------------------------------------------------------===//
//  OpenMP directives printing methods
//===----------------------------------------------------------------------===//

void StmtPrinter::PrintOMPExecutableDirective(clang::OMPExecutableDirective *S,
                                              bool ForceNoStmt) {
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

void StmtPrinter::VisitOMPParallelDirective(clang::OMPParallelDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSimdDirective(clang::OMPSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPForDirective(clang::OMPForDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPForSimdDirective(clang::OMPForSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSectionsDirective(clang::OMPSectionsDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp sections";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSectionDirective(clang::OMPSectionDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp section";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPSingleDirective(clang::OMPSingleDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp single";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMasterDirective(clang::OMPMasterDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp master";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPCriticalDirective(clang::OMPCriticalDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp critical";
  if (Node->getDirectiveName().getName()) {
    OS << " (";
    Node->getDirectiveName().printName(OS, Policy);
    OS << ")";
  }
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelForDirective(clang::OMPParallelForDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelForSimdDirective(
    clang::OMPParallelForSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMasterDirective(
    clang::OMPParallelMasterDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel master";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelSectionsDirective(
    clang::OMPParallelSectionsDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel sections";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskDirective(clang::OMPTaskDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp task";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskyieldDirective(clang::OMPTaskyieldDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp taskyield";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPBarrierDirective(clang::OMPBarrierDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp barrier";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskwaitDirective(clang::OMPTaskwaitDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp taskwait";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskgroupDirective(clang::OMPTaskgroupDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp taskgroup";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPFlushDirective(clang::OMPFlushDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp flush";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDepobjDirective(clang::OMPDepobjDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp depobj";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPScanDirective(clang::OMPScanDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp scan";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPOrderedDirective(clang::OMPOrderedDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp ordered";
  PrintOMPExecutableDirective(Node, Node->hasClausesOfKind<clang::OMPDependClause>());
}

void StmtPrinter::VisitOMPAtomicDirective(clang::OMPAtomicDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp atomic";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetDirective(clang::OMPTargetDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetDataDirective(clang::OMPTargetDataDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target data";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetEnterDataDirective(
    clang::OMPTargetEnterDataDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target enter data";
  PrintOMPExecutableDirective(Node, /*ForceNoStmt=*/true);
}

void StmtPrinter::VisitOMPTargetExitDataDirective(
    clang::OMPTargetExitDataDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target exit data";
  PrintOMPExecutableDirective(Node, /*ForceNoStmt=*/true);
}

void StmtPrinter::VisitOMPTargetParallelDirective(
    clang::OMPTargetParallelDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target parallel";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetParallelForDirective(
    clang::OMPTargetParallelForDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDirective(clang::OMPTeamsDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp teams";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPCancellationPointDirective(
    clang::OMPCancellationPointDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp cancellation point "
           << getOpenMPDirectiveName(Node->getCancelRegion());
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPCancelDirective(clang::OMPCancelDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp cancel "
           << getOpenMPDirectiveName(Node->getCancelRegion());
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskLoopDirective(clang::OMPTaskLoopDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTaskLoopSimdDirective(
    clang::OMPTaskLoopSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMasterTaskLoopDirective(
    clang::OMPMasterTaskLoopDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp master taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPMasterTaskLoopSimdDirective(
    clang::OMPMasterTaskLoopSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp master taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMasterTaskLoopDirective(
    clang::OMPParallelMasterTaskLoopDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel master taskloop";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPParallelMasterTaskLoopSimdDirective(
    clang::OMPParallelMasterTaskLoopSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp parallel master taskloop simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDistributeDirective(clang::OMPDistributeDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp distribute";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetUpdateDirective(
    clang::OMPTargetUpdateDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target update";
  PrintOMPExecutableDirective(Node, /*ForceNoStmt=*/true);
}

void StmtPrinter::VisitOMPDistributeParallelForDirective(
    clang::OMPDistributeParallelForDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp distribute parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDistributeParallelForSimdDirective(
    clang::OMPDistributeParallelForSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp distribute parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPDistributeSimdDirective(
    clang::OMPDistributeSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp distribute simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetParallelForSimdDirective(
    clang::OMPTargetParallelForSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetSimdDirective(clang::OMPTargetSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeDirective(
    clang::OMPTeamsDistributeDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp teams distribute";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeSimdDirective(
    clang::OMPTeamsDistributeSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp teams distribute simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeParallelForSimdDirective(
    clang::OMPTeamsDistributeParallelForSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp teams distribute parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTeamsDistributeParallelForDirective(
    clang::OMPTeamsDistributeParallelForDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp teams distribute parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDirective(clang::OMPTargetTeamsDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target teams";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeDirective(
    clang::OMPTargetTeamsDistributeDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target teams distribute";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeParallelForDirective(
    clang::OMPTargetTeamsDistributeParallelForDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target teams distribute parallel for";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeParallelForSimdDirective(
    clang::OMPTargetTeamsDistributeParallelForSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target teams distribute parallel for simd";
  PrintOMPExecutableDirective(Node);
}

void StmtPrinter::VisitOMPTargetTeamsDistributeSimdDirective(
    clang::OMPTargetTeamsDistributeSimdDirective *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Indent() << "#pragma omp target teams distribute simd";
  PrintOMPExecutableDirective(Node);
}

//===----------------------------------------------------------------------===//
//  Expr printing methods.
//===----------------------------------------------------------------------===//

void StmtPrinter::VisitSourceLocExpr(clang::SourceLocExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << Node->getBuiltinStr() << "()";
}

void StmtPrinter::VisitConstantExpr(clang::ConstantExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitDeclRefExpr(clang::DeclRefExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (const auto *OCED = clang::dyn_cast<clang::OMPCapturedExprDecl>(Node->getDecl())) {
    OCED->getInit()->IgnoreImpCasts()->printPretty(OS, nullptr, Policy);
    return;
  }
  if (const auto *TPOD = clang::dyn_cast<clang::TemplateParamObjectDecl>(Node->getDecl())) {
    TPOD->printAsExpr(OS);
    return;
  }
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    Qualifier->print(OS, Policy);
  if (Node->hasTemplateKeyword())
    OS << "template ";
  OS << Node->getNameInfo();
  if (Node->hasExplicitTemplateArgs())
    printTemplateArgumentList(OS, Node->template_arguments(), Policy);
}

void StmtPrinter::VisitDependentScopeDeclRefExpr(
    clang::DependentScopeDeclRefExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    Qualifier->print(OS, Policy);
  if (Node->hasTemplateKeyword())
    OS << "template ";
  OS << Node->getNameInfo();
  if (Node->hasExplicitTemplateArgs())
    printTemplateArgumentList(OS, Node->template_arguments(), Policy);
}

void StmtPrinter::VisitUnresolvedLookupExpr(clang::UnresolvedLookupExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Node->getQualifier())
    Node->getQualifier()->print(OS, Policy);
  if (Node->hasTemplateKeyword())
    OS << "template ";
  OS << Node->getNameInfo();
  if (Node->hasExplicitTemplateArgs())
    printTemplateArgumentList(OS, Node->template_arguments(), Policy);
}

static bool isImplicitSelf(const clang::Expr *E) {
  if (const auto *DRE = clang::dyn_cast<clang::DeclRefExpr>(E)) {
    if (const auto *PD = clang::dyn_cast<clang::ImplicitParamDecl>(DRE->getDecl())) {
      if (PD->getParameterKind() == clang::ImplicitParamDecl::ObjCSelf &&
          DRE->getBeginLoc().isInvalid())
        return true;
    }
  }
  return false;
}

void StmtPrinter::VisitObjCIvarRefExpr(clang::ObjCIvarRefExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Node->getBase()) {
    if (!Policy.SuppressImplicitBase ||
        !isImplicitSelf(Node->getBase()->IgnoreImpCasts())) {
      PrintExpr(Node->getBase());
      OS << (Node->isArrow() ? "->" : ".");
    }
  }
  OS << *Node->getDecl();
}

void StmtPrinter::VisitObjCPropertyRefExpr(clang::ObjCPropertyRefExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBaseExpr());
  OS << "[";
  PrintExpr(Node->getKeyExpr());
  OS << "]";
}

void StmtPrinter::VisitPredefinedExpr(clang::PredefinedExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << clang::PredefinedExpr::getIdentKindName(Node->getIdentKind());
}

void StmtPrinter::VisitCharacterLiteral(clang::CharacterLiteral *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  unsigned value = Node->getValue();

  switch (Node->getKind()) {
  case clang::CharacterLiteral::Ascii: break; // no prefix.
  case clang::CharacterLiteral::Wide:  OS << 'L'; break;
  case clang::CharacterLiteral::UTF8:  OS << "u8"; break;
  case clang::CharacterLiteral::UTF16: OS << 'u'; break;
  case clang::CharacterLiteral::UTF32: OS << 'U'; break;
  }

  switch (value) {
  case '\\':
    OS << "'\\\\'";
    break;
  case '\'':
    OS << "'\\''";
    break;
  case '\a':
    // TODO: K&R: the meaning of '\\a' is different in traditional C
    OS << "'\\a'";
    break;
  case '\b':
    OS << "'\\b'";
    break;
  // Nonstandard escape sequence.
  /*case '\e':
    OS << "'\\e'";
    break;*/
  case '\f':
    OS << "'\\f'";
    break;
  case '\n':
    OS << "'\\n'";
    break;
  case '\r':
    OS << "'\\r'";
    break;
  case '\t':
    OS << "'\\t'";
    break;
  case '\v':
    OS << "'\\v'";
    break;
  default:
    // A character literal might be sign-extended, which
    // would result in an invalid \U escape sequence.
    // FIXME: multicharacter literals such as '\xFF\xFF\xFF\xFF'
    // are not correctly handled.
    if ((value & ~0xFFu) == ~0xFFu && Node->getKind() == clang::CharacterLiteral::Ascii)
      value &= 0xFFu;
    if (value < 256 && clang::isPrintable((unsigned char)value))
      OS << "'" << (char)value << "'";
    else if (value < 256)
      OS << "'\\x" << llvm::format("%02x", value) << "'";
    else if (value <= 0xFFFF)
      OS << "'\\u" << llvm::format("%04x", value) << "'";
    else
      OS << "'\\U" << llvm::format("%08x", value) << "'";
  }
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Policy.ConstantsAsWritten && printExprAsWritten(OS, Node, Context))
    return;
  bool isSigned = Node->getType()->isSignedIntegerType();
  OS << Node->getValue().toString(10, isSigned);

  // Emit suffixes.  Integer literals are always a builtin integer type.
  switch (Node->getType()->castAs<clang::BuiltinType>()->getKind()) {
  default: llvm_unreachable("Unexpected type for integer literal!");
  case clang::BuiltinType::Char_S:
  case clang::BuiltinType::Char_U:    OS << "i8"; break;
  case clang::BuiltinType::UChar:     OS << "Ui8"; break;
  case clang::BuiltinType::Short:     OS << "i16"; break;
  case clang::BuiltinType::UShort:    OS << "Ui16"; break;
  case clang::BuiltinType::Int:       break; // no suffix.
  case clang::BuiltinType::UInt:      OS << 'U'; break;
  case clang::BuiltinType::Long:      OS << 'L'; break;
  case clang::BuiltinType::ULong:     OS << "UL"; break;
  case clang::BuiltinType::LongLong:  OS << "LL"; break;
  case clang::BuiltinType::ULongLong: OS << "ULL"; break;
  }
}

void StmtPrinter::VisitFixedPointLiteral(clang::FixedPointLiteral *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Policy.ConstantsAsWritten && printExprAsWritten(OS, Node, Context))
    return;
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
}

static void PrintFloatingLiteral(pasta::raw_string_ostream &OS, clang::FloatingLiteral *Node,
                                 bool PrintSuffix) {
  clang::SmallString<16> Str;
  Node->getValue().toString(Str);
  OS << Str;
  if (Str.find_first_not_of("-0123456789") == clang::StringRef::npos)
    OS << '.'; // Trailing dot in order to separate from ints.

  if (!PrintSuffix)
    return;

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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Policy.ConstantsAsWritten && printExprAsWritten(OS, Node, Context))
    return;
  PrintFloatingLiteral(OS, Node, /*PrintSuffix=*/true);
}

void StmtPrinter::VisitImaginaryLiteral(clang::ImaginaryLiteral *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getSubExpr());
  OS << "i";
}

void StmtPrinter::VisitStringLiteral(clang::StringLiteral *Str) {
  Str->outputString(OS);
}

void StmtPrinter::VisitParenExpr(clang::ParenExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "(";
  PrintExpr(Node->getSubExpr());
  OS << ")";
}

void StmtPrinter::VisitUnaryOperator(clang::UnaryOperator *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_offsetof(";
  Node->getTypeSourceInfo()->getType().print(OS, Policy);
  OS << ", ";
  bool PrintedSomething = false;
  for (unsigned i = 0, n = Node->getNumComponents(); i < n; ++i) {
    clang::OffsetOfNode ON = Node->getComponent(i);
    if (ON.getKind() == clang::OffsetOfNode::Array) {
      // Array node
      OS << "[";
      PrintExpr(Node->getIndexExpr(ON.getArrayExprIndex()));
      OS << "]";
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

    if (PrintedSomething)
      OS << ".";
    else
      PrintedSomething = true;
    OS << Id->getName();
  }
  OS << ")";
}

void StmtPrinter::VisitUnaryExprOrTypeTraitExpr(
    clang::UnaryExprOrTypeTraitExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
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

  if (Node->isArgumentType()) {
    OS << '(';
    Node->getArgumentType().print(OS, Policy);
    OS << ')';
  } else {
    OS << " ";
    PrintExpr(Node->getArgumentExpr());
  }
}

void StmtPrinter::VisitGenericSelectionExpr(clang::GenericSelectionExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "_Generic(";
  PrintExpr(Node->getControllingExpr());
  for (const clang::GenericSelectionExpr::Association Assoc : Node->associations()) {
    OS << ", ";
    clang::QualType T = Assoc.getType();
    if (T.isNull())
      OS << "default";
    else
      T.print(OS, Policy);
    OS << ": ";
    PrintExpr(Assoc.getAssociationExpr());
  }
  OS << ")";
}

void StmtPrinter::VisitArraySubscriptExpr(clang::ArraySubscriptExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getLHS());
  OS << "[";
  PrintExpr(Node->getRHS());
  OS << "]";
}

void StmtPrinter::VisitMatrixSubscriptExpr(clang::MatrixSubscriptExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBase());
  OS << "[";
  PrintExpr(Node->getRowIdx());
  OS << "]";
  OS << "[";
  PrintExpr(Node->getColumnIdx());
  OS << "]";
}

void StmtPrinter::VisitOMPArraySectionExpr(clang::OMPArraySectionExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBase());
  OS << "[";
  if (Node->getLowerBound())
    PrintExpr(Node->getLowerBound());
  if (Node->getColonLocFirst().isValid()) {
    OS << ":";
    if (Node->getLength())
      PrintExpr(Node->getLength());
  }
  if (Node->getColonLocSecond().isValid()) {
    OS << ":";
    if (Node->getStride())
      PrintExpr(Node->getStride());
  }
  OS << "]";
}

void StmtPrinter::VisitOMPArrayShapingExpr(clang::OMPArrayShapingExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "(";
  for (clang::Expr *E : Node->getDimensions()) {
    OS << "[";
    PrintExpr(E);
    OS << "]";
  }
  OS << ")";
  PrintExpr(Node->getBase());
}

void StmtPrinter::VisitOMPIteratorExpr(clang::OMPIteratorExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "iterator(";
  for (unsigned I = 0, E = Node->numOfIterators(); I < E; ++I) {
    auto *VD = clang::cast<clang::ValueDecl>(Node->getIteratorDecl(I));
    VD->getType().print(OS, Policy);
    const clang::OMPIteratorExpr::IteratorRange Range = Node->getIteratorRange(I);
    OS << " " << VD->getName() << " = ";
    PrintExpr(Range.Begin);
    OS << ":";
    PrintExpr(Range.End);
    if (Range.Step) {
      OS << ":";
      PrintExpr(Range.Step);
    }
    if (I < E - 1)
      OS << ", ";
  }
  OS << ")";
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
  PrintExpr(Call->getCallee());
  OS << "(";
  PrintCallArgs(Call);
  OS << ")";
}

static bool isImplicitThis(const clang::Expr *E) {
  if (const auto *TE = clang::dyn_cast<clang::CXXThisExpr>(E))
    return TE->isImplicit();
  return false;
}

void StmtPrinter::VisitMemberExpr(clang::MemberExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (!Policy.SuppressImplicitBase || !isImplicitThis(Node->getBase())) {
    PrintExpr(Node->getBase());

    auto *ParentMember = clang::dyn_cast<clang::MemberExpr>(Node->getBase());
    clang::FieldDecl *ParentDecl =
        ParentMember ? clang::dyn_cast<clang::FieldDecl>(ParentMember->getMemberDecl())
                     : nullptr;

    if (!ParentDecl || !ParentDecl->isAnonymousStructOrUnion())
      OS << (Node->isArrow() ? "->" : ".");
  }

  if (auto *FD = clang::dyn_cast<clang::FieldDecl>(Node->getMemberDecl()))
    if (FD->isAnonymousStructOrUnion())
      return;

  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    Qualifier->print(OS, Policy);
  if (Node->hasTemplateKeyword())
    OS << "template ";
  OS << Node->getMemberNameInfo();
  if (Node->hasExplicitTemplateArgs())
    printTemplateArgumentList(OS, Node->template_arguments(), Policy);
}

void StmtPrinter::VisitObjCIsaExpr(clang::ObjCIsaExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBase());
  OS << (Node->isArrow() ? "->isa" : ".isa");
}

void StmtPrinter::VisitExtVectorElementExpr(clang::ExtVectorElementExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBase());
  OS << ".";
  OS << Node->getAccessor().getName();
}

void StmtPrinter::VisitCStyleCastExpr(clang::CStyleCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << '(';
  Node->getTypeAsWritten().print(OS, Policy);
  OS << ')';
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitCompoundLiteralExpr(clang::CompoundLiteralExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << '(';
  Node->getType().print(OS, Policy);
  OS << ')';
  PrintExpr(Node->getInitializer());
}

void StmtPrinter::VisitImplicitCastExpr(clang::ImplicitCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // No need to print anything, simply forward to the subexpression.
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitBinaryOperator(clang::BinaryOperator *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getLHS());
  OS << " " << clang::BinaryOperator::getOpcodeStr(Node->getOpcode()) << " ";
  PrintExpr(Node->getRHS());
}

void StmtPrinter::VisitCompoundAssignOperator(clang::CompoundAssignOperator *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getLHS());
  OS << " " << clang::BinaryOperator::getOpcodeStr(Node->getOpcode()) << " ";
  PrintExpr(Node->getRHS());
}

void StmtPrinter::VisitConditionalOperator(clang::ConditionalOperator *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getCond());
  OS << " ? ";
  PrintExpr(Node->getLHS());
  OS << " : ";
  PrintExpr(Node->getRHS());
}

// GNU extensions.

void
StmtPrinter::VisitBinaryConditionalOperator(clang::BinaryConditionalOperator *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getCommon());
  OS << " ?: ";
  PrintExpr(Node->getFalseExpr());
}

void StmtPrinter::VisitAddrLabelExpr(clang::AddrLabelExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "&&" << Node->getLabel()->getName();
}

void StmtPrinter::VisitStmtExpr(clang::StmtExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << "(";
  PrintRawCompoundStmt(E->getSubStmt());
  OS << ")";
}

void StmtPrinter::VisitChooseExpr(clang::ChooseExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_choose_expr(";
  PrintExpr(Node->getCond());
  OS << ", ";
  PrintExpr(Node->getLHS());
  OS << ", ";
  PrintExpr(Node->getRHS());
  OS << ")";
}

void StmtPrinter::VisitGNUNullExpr(clang::GNUNullExpr *) {
  OS << "__null";
}

void StmtPrinter::VisitShuffleVectorExpr(clang::ShuffleVectorExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_shufflevector(";
  for (unsigned i = 0, e = Node->getNumSubExprs(); i != e; ++i) {
    if (i) OS << ", ";
    PrintExpr(Node->getExpr(i));
  }
  OS << ")";
}

void StmtPrinter::VisitConvertVectorExpr(clang::ConvertVectorExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_convertvector(";
  PrintExpr(Node->getSrcExpr());
  OS << ", ";
  Node->getType().print(OS, Policy);
  OS << ")";
}

void StmtPrinter::VisitInitListExpr(clang::InitListExpr* Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Node->getSyntacticForm()) {
    Visit(Node->getSyntacticForm());
    return;
  }

  OS << "{";
  for (unsigned i = 0, e = Node->getNumInits(); i != e; ++i) {
    if (i) OS << ", ";
    if (Node->getInit(i))
      PrintExpr(Node->getInit(i));
    else
      OS << "{}";
  }
  OS << "}";
}

void StmtPrinter::VisitArrayInitLoopExpr(clang::ArrayInitLoopExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // There's no way to express this expression in any of our supported
  // languages, so just emit something terse and (hopefully) clear.
  OS << "{";
  PrintExpr(Node->getSubExpr());
  OS << "}";
}

void StmtPrinter::VisitArrayInitIndexExpr(clang::ArrayInitIndexExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "*";
}

void StmtPrinter::VisitParenListExpr(clang::ParenListExpr* Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "(";
  for (unsigned i = 0, e = Node->getNumExprs(); i != e; ++i) {
    if (i) OS << ", ";
    PrintExpr(Node->getExpr(i));
  }
  OS << ")";
}

void StmtPrinter::VisitDesignatedInitExpr(clang::DesignatedInitExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  bool NeedsEquals = true;
  for (const clang::DesignatedInitExpr::Designator &D : Node->designators()) {
    if (D.isFieldDesignator()) {
      if (D.getDotLoc().isInvalid()) {
        if (clang::IdentifierInfo *II = D.getFieldName()) {
          OS << II->getName() << ":";
          NeedsEquals = false;
        }
      } else {
        OS << "." << D.getFieldName()->getName();
      }
    } else {
      OS << "[";
      if (D.isArrayDesignator()) {
        PrintExpr(Node->getArrayIndex(D));
      } else {
        PrintExpr(Node->getArrayRangeStart(D));
        OS << " ... ";
        PrintExpr(Node->getArrayRangeEnd(D));
      }
      OS << "]";
    }
  }

  if (NeedsEquals)
    OS << " = ";
  else
    OS << " ";
  PrintExpr(Node->getInit());
}

void StmtPrinter::VisitDesignatedInitUpdateExpr(
    clang::DesignatedInitUpdateExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "{";
  OS << "/*base*/";
  PrintExpr(Node->getBase());
  OS << ", ";

  OS << "/*updater*/";
  PrintExpr(Node->getUpdater());
  OS << "}";
}

void StmtPrinter::VisitNoInitExpr(clang::NoInitExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "/*no init*/";
}

void StmtPrinter::VisitImplicitValueInitExpr(clang::ImplicitValueInitExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (Node->getType()->getAsCXXRecordDecl()) {
    OS << "/*implicit*/";
    Node->getType().print(OS, Policy);
    OS << "()";
  } else {
    OS << "/*implicit*/(";
    Node->getType().print(OS, Policy);
    OS << ')';
    if (Node->getType()->isRecordType())
      OS << "{}";
    else
      OS << 0;
  }
}

void StmtPrinter::VisitVAArgExpr(clang::VAArgExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_va_arg(";
  PrintExpr(Node->getSubExpr());
  OS << ", ";
  Node->getType().print(OS, Policy);
  OS << ")";
}

void StmtPrinter::VisitPseudoObjectExpr(clang::PseudoObjectExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getSyntacticForm());
}

void StmtPrinter::VisitAtomicExpr(clang::AtomicExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  const char *Name = nullptr;
  switch (Node->getOp()) {
#define BUILTIN(ID, TYPE, ATTRS)
#define ATOMIC_BUILTIN(ID, TYPE, ATTRS) \
  case clang::AtomicExpr::AO ## ID: \
    Name = #ID "("; \
    break;
#include "clang/Basic/Builtins.def"
  }
  OS << Name;

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
}

// C++
void StmtPrinter::VisitCXXOperatorCallExpr(clang::CXXOperatorCallExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  clang::OverloadedOperatorKind Kind = Node->getOperator();
  if (Kind == clang::OO_PlusPlus || Kind == clang::OO_MinusMinus) {
    if (Node->getNumArgs() == 1) {
      OS << getOperatorSpelling(Kind) << ' ';
      PrintExpr(Node->getArg(0));
    } else {
      PrintExpr(Node->getArg(0));
      OS << ' ' << getOperatorSpelling(Kind);
    }
  } else if (Kind == clang::OO_Arrow) {
    PrintExpr(Node->getArg(0));
  } else if (Kind == clang::OO_Call) {
    PrintExpr(Node->getArg(0));
    OS << '(';
    for (unsigned ArgIdx = 1; ArgIdx < Node->getNumArgs(); ++ArgIdx) {
      if (ArgIdx > 1)
        OS << ", ";
      if (!clang::isa<clang::CXXDefaultArgExpr>(Node->getArg(ArgIdx)))
        PrintExpr(Node->getArg(ArgIdx));
    }
    OS << ')';
  } else if (Kind == clang::OO_Subscript) {
    PrintExpr(Node->getArg(0));
    OS << '[';
    PrintExpr(Node->getArg(1));
    OS << ']';
  } else if (Node->getNumArgs() == 1) {
    OS << getOperatorSpelling(Kind) << ' ';
    PrintExpr(Node->getArg(0));
  } else if (Node->getNumArgs() == 2) {
    PrintExpr(Node->getArg(0));
    OS << ' ' << getOperatorSpelling(Kind) << ' ';
    PrintExpr(Node->getArg(1));
  } else {
    llvm_unreachable("unknown overloaded operator");
  }
}

void StmtPrinter::VisitCXXMemberCallExpr(clang::CXXMemberCallExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // If we have a conversion operator call only print the argument.
  clang::CXXMethodDecl *MD = Node->getMethodDecl();
  if (MD && clang::isa<clang::CXXConversionDecl>(MD)) {
    PrintExpr(Node->getImplicitObjectArgument());
    return;
  }
  VisitCallExpr(clang::cast<clang::CallExpr>(Node));
}

void StmtPrinter::VisitCUDAKernelCallExpr(clang::CUDAKernelCallExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getCallee());
  OS << "<<<";
  PrintCallArgs(Node->getConfig());
  OS << ">>>(";
  PrintCallArgs(Node);
  OS << ")";
}

void StmtPrinter::VisitCXXRewrittenBinaryOperator(
    clang::CXXRewrittenBinaryOperator *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  clang::CXXRewrittenBinaryOperator::DecomposedForm Decomposed =
      Node->getDecomposedForm();
  PrintExpr(const_cast<clang::Expr*>(Decomposed.LHS));
  OS << ' ' << clang::BinaryOperator::getOpcodeStr(Decomposed.Opcode) << ' ';
  PrintExpr(const_cast<clang::Expr*>(Decomposed.RHS));
}

void StmtPrinter::VisitCXXNamedCastExpr(clang::CXXNamedCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << Node->getCastName() << '<';
  Node->getTypeAsWritten().print(OS, Policy);
  OS << ">(";
  PrintExpr(Node->getSubExpr());
  OS << ")";
}

void StmtPrinter::VisitCXXStaticCastExpr(clang::CXXStaticCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXDynamicCastExpr(clang::CXXDynamicCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXReinterpretCastExpr(clang::CXXReinterpretCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXConstCastExpr(clang::CXXConstCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitBuiltinBitCastExpr(clang::BuiltinBitCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_bit_cast(";
  Node->getTypeInfoAsWritten()->getType().print(OS, Policy);
  OS << ", ";
  PrintExpr(Node->getSubExpr());
  OS << ")";
}

void StmtPrinter::VisitCXXAddrspaceCastExpr(clang::CXXAddrspaceCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  VisitCXXNamedCastExpr(Node);
}

void StmtPrinter::VisitCXXTypeidExpr(clang::CXXTypeidExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "typeid(";
  if (Node->isTypeOperand()) {
    Node->getTypeOperandSourceInfo()->getType().print(OS, Policy);
  } else {
    PrintExpr(Node->getExprOperand());
  }
  OS << ")";
}

void StmtPrinter::VisitCXXUuidofExpr(clang::CXXUuidofExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__uuidof(";
  if (Node->isTypeOperand()) {
    Node->getTypeOperandSourceInfo()->getType().print(OS, Policy);
  } else {
    PrintExpr(Node->getExprOperand());
  }
  OS << ")";
}

void StmtPrinter::VisitMSPropertyRefExpr(clang::MSPropertyRefExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBaseExpr());
  if (Node->isArrow())
    OS << "->";
  else
    OS << ".";
  if (clang::NestedNameSpecifier *Qualifier =
      Node->getQualifierLoc().getNestedNameSpecifier())
    Qualifier->print(OS, Policy);
  OS << Node->getPropertyDecl()->getDeclName();
}

void StmtPrinter::VisitMSPropertySubscriptExpr(clang::MSPropertySubscriptExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getBase());
  OS << "[";
  PrintExpr(Node->getIdx());
  OS << "]";
}

void StmtPrinter::VisitUserDefinedLiteral(clang::UserDefinedLiteral *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  switch (Node->getLiteralOperatorKind()) {
  case clang::UserDefinedLiteral::LOK_Raw:
    OS << clang::cast<clang::StringLiteral>(Node->getArg(0)->IgnoreImpCasts())->getString();
    break;
  case clang::UserDefinedLiteral::LOK_Template: {
    const auto *DRE = clang::cast<clang::DeclRefExpr>(Node->getCallee()->IgnoreImpCasts());
    const clang::TemplateArgumentList *Args =
      clang::cast<clang::FunctionDecl>(DRE->getDecl())->getTemplateSpecializationArgs();
    assert(Args);

    if (Args->size() != 1) {
      OS << "operator\"\"" << Node->getUDSuffix()->getName();
      printTemplateArgumentList(OS, Args->asArray(), Policy);
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
    OS << Int->getValue().toString(10, /*isSigned*/false);
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << (Node->getValue() ? "true" : "false");
}

void StmtPrinter::VisitCXXNullPtrLiteralExpr(clang::CXXNullPtrLiteralExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "nullptr";
}

void StmtPrinter::VisitCXXThisExpr(clang::CXXThisExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "this";
}

void StmtPrinter::VisitCXXThrowExpr(clang::CXXThrowExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (!Node->getSubExpr())
    OS << "throw";
  else {
    OS << "throw ";
    PrintExpr(Node->getSubExpr());
  }
}

void StmtPrinter::VisitCXXDefaultArgExpr(clang::CXXDefaultArgExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // Nothing to print: we picked up the default argument.
}

void StmtPrinter::VisitCXXDefaultInitExpr(clang::CXXDefaultInitExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // Nothing to print: we picked up the default initializer.
}

void StmtPrinter::VisitCXXFunctionalCastExpr(clang::CXXFunctionalCastExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Node->getType().print(OS, Policy);
  // If there are no parens, this is list-initialization, and the braces are
  // part of the syntax of the inner construct.
  if (Node->getLParenLoc().isValid())
    OS << "(";
  PrintExpr(Node->getSubExpr());
  if (Node->getLParenLoc().isValid())
    OS << ")";
}

void StmtPrinter::VisitCXXBindTemporaryExpr(clang::CXXBindTemporaryExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitCXXTemporaryObjectExpr(clang::CXXTemporaryObjectExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Node->getType().print(OS, Policy);
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
  if (Node->isStdInitListInitialization())
    /* See above. */;
  else if (Node->isListInitialization())
    OS << "}";
  else
    OS << ")";
}

void StmtPrinter::VisitLambdaExpr(clang::LambdaExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << '[';
  bool NeedComma = false;
  switch (Node->getCaptureDefault()) {
  case clang::LCD_None:
    break;

  case clang::LCD_ByCopy:
    OS << '=';
    NeedComma = true;
    break;

  case clang::LCD_ByRef:
    OS << '&';
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
      if (Node->getCaptureDefault() != clang::LCD_ByRef || Node->isInitCapture(C))
        OS << '&';
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
      clang::VarDecl *D = C->getCapturedVar();

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

  if (!Node->getExplicitTemplateParameters().empty()) {
    Node->getTemplateParameterList()->print(
        OS, Node->getLambdaClass()->getASTContext(),
        /*OmitTemplateKW*/true);
  }

  if (Node->hasExplicitParameters()) {
    OS << '(';
    clang::CXXMethodDecl *Method = Node->getCallOperator();
    NeedComma = false;
    for (const auto *P : Method->parameters()) {
      if (NeedComma) {
        OS << ", ";
      } else {
        NeedComma = true;
      }
      std::string ParamStr = P->getNameAsString();
      P->getOriginalType().print(OS, Policy, ParamStr);
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
      Proto->getReturnType().print(OS, Policy);
    }
  }

  // Print the body.
  OS << ' ';
  if (Policy.TerseOutput)
    OS << "{}";
  else
    PrintRawCompoundStmt(Node->getCompoundStmtBody());
}

void StmtPrinter::VisitCXXScalarValueInitExpr(clang::CXXScalarValueInitExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (clang::TypeSourceInfo *TSInfo = Node->getTypeSourceInfo())
    TSInfo->getType().print(OS, Policy);
  else
    Node->getType().print(OS, Policy);
  OS << "()";
}

void StmtPrinter::VisitCXXNewExpr(clang::CXXNewExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
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
  std::string TypeS;
  if (clang::Optional<clang::Expr *> Size = E->getArraySize()) {
    llvm::raw_string_ostream s(TypeS);
    s << '[';
    if (*Size)
      (*Size)->printPretty(s, Helper, Policy);
    s << ']';
  }
  E->getAllocatedType().print(OS, Policy, TypeS);
  if (E->isParenTypeId())
    OS << ")";

  clang::CXXNewExpr::InitializationStyle InitStyle = E->getInitializationStyle();
  if (InitStyle) {
    if (InitStyle == clang::CXXNewExpr::CallInit)
      OS << "(";
    PrintExpr(E->getInitializer());
    if (InitStyle == clang::CXXNewExpr::CallInit)
      OS << ")";
  }
}

void StmtPrinter::VisitCXXDeleteExpr(clang::CXXDeleteExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  if (E->isGlobalDelete())
    OS << "::";
  OS << "delete ";
  if (E->isArrayForm())
    OS << "[] ";
  PrintExpr(E->getArgument());
}

void StmtPrinter::VisitCXXPseudoDestructorExpr(clang::CXXPseudoDestructorExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  PrintExpr(E->getBase());
  if (E->isArrow())
    OS << "->";
  else
    OS << '.';
  if (E->getQualifier())
    E->getQualifier()->print(OS, Policy);
  OS << "~";

  if (clang::IdentifierInfo *II = E->getDestroyedTypeIdentifier())
    OS << II->getName();
  else
    E->getDestroyedType().print(OS, Policy);
}

void StmtPrinter::VisitCXXConstructExpr(clang::CXXConstructExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  if (E->isListInitialization() && !E->isStdInitListInitialization())
    OS << "{";

  for (unsigned i = 0, e = E->getNumArgs(); i != e; ++i) {
    if (clang::isa<clang::CXXDefaultArgExpr>(E->getArg(i))) {
      // Don't print any defaulted arguments
      break;
    }

    if (i) OS << ", ";
    PrintExpr(E->getArg(i));
  }

  if (E->isListInitialization() && !E->isStdInitListInitialization())
    OS << "}";
}

void StmtPrinter::VisitCXXInheritedCtorInitExpr(clang::CXXInheritedCtorInitExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  // Parens are printed by the surrounding context.
  OS << "<forwarded>";
}

void StmtPrinter::VisitCXXStdInitializerListExpr(clang::CXXStdInitializerListExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  PrintExpr(E->getSubExpr());
}

void StmtPrinter::VisitExprWithCleanups(clang::ExprWithCleanups *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  // Just forward to the subexpression.
  PrintExpr(E->getSubExpr());
}

void
StmtPrinter::VisitCXXUnresolvedConstructExpr(
    clang::CXXUnresolvedConstructExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Node->getTypeAsWritten().print(OS, Policy);
  OS << "(";
  for (clang::CXXUnresolvedConstructExpr::arg_iterator Arg = Node->arg_begin(),
                                             ArgEnd = Node->arg_end();
       Arg != ArgEnd; ++Arg) {
    if (Arg != Node->arg_begin())
      OS << ", ";
    PrintExpr(*Arg);
  }
  OS << ")";
}

void StmtPrinter::VisitCXXDependentScopeMemberExpr(
    clang::CXXDependentScopeMemberExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (!Node->isImplicitAccess()) {
    PrintExpr(Node->getBase());
    OS << (Node->isArrow() ? "->" : ".");
  }
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    Qualifier->print(OS, Policy);
  if (Node->hasTemplateKeyword())
    OS << "template ";
  OS << Node->getMemberNameInfo();
  if (Node->hasExplicitTemplateArgs())
    printTemplateArgumentList(OS, Node->template_arguments(), Policy);
}

void StmtPrinter::VisitUnresolvedMemberExpr(clang::UnresolvedMemberExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  if (!Node->isImplicitAccess()) {
    PrintExpr(Node->getBase());
    OS << (Node->isArrow() ? "->" : ".");
  }
  if (clang::NestedNameSpecifier *Qualifier = Node->getQualifier())
    Qualifier->print(OS, Policy);
  if (Node->hasTemplateKeyword())
    OS << "template ";
  OS << Node->getMemberNameInfo();
  if (Node->hasExplicitTemplateArgs())
    printTemplateArgumentList(OS, Node->template_arguments(), Policy);
}

void StmtPrinter::VisitTypeTraitExpr(clang::TypeTraitExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << getTraitSpelling(E->getTrait()) << "(";
  for (unsigned I = 0, N = E->getNumArgs(); I != N; ++I) {
    if (I > 0)
      OS << ", ";
    E->getArg(I)->getType().print(OS, Policy);
  }
  OS << ")";
}

void StmtPrinter::VisitArrayTypeTraitExpr(clang::ArrayTypeTraitExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << getTraitSpelling(E->getTrait()) << '(';
  E->getQueriedType().print(OS, Policy);
  OS << ')';
}

void StmtPrinter::VisitExpressionTraitExpr(clang::ExpressionTraitExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << getTraitSpelling(E->getTrait()) << '(';
  PrintExpr(E->getQueriedExpression());
  OS << ')';
}

void StmtPrinter::VisitCXXNoexceptExpr(clang::CXXNoexceptExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << "noexcept(";
  PrintExpr(E->getOperand());
  OS << ")";
}

void StmtPrinter::VisitPackExpansionExpr(clang::PackExpansionExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  PrintExpr(E->getPattern());
  OS << "...";
}

void StmtPrinter::VisitSizeOfPackExpr(clang::SizeOfPackExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << "sizeof...(" << *E->getPack() << ")";
}

void StmtPrinter::VisitSubstNonTypeTemplateParmPackExpr(
    clang::SubstNonTypeTemplateParmPackExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << *Node->getParameterPack();
}

void StmtPrinter::VisitSubstNonTypeTemplateParmExpr(
    clang::SubstNonTypeTemplateParmExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  Visit(Node->getReplacement());
}

void StmtPrinter::VisitFunctionParmPackExpr(clang::FunctionParmPackExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << *E->getParameterPack();
}

void StmtPrinter::VisitMaterializeTemporaryExpr(clang::MaterializeTemporaryExpr *Node){
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getSubExpr());
}

void StmtPrinter::VisitCXXFoldExpr(clang::CXXFoldExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << "(";
  if (E->getLHS()) {
    PrintExpr(E->getLHS());
    OS << " " << clang::BinaryOperator::getOpcodeStr(E->getOperator()) << " ";
  }
  OS << "...";
  if (E->getRHS()) {
    OS << " " << clang::BinaryOperator::getOpcodeStr(E->getOperator()) << " ";
    PrintExpr(E->getRHS());
  }
  OS << ")";
}

void StmtPrinter::VisitConceptSpecializationExpr(clang::ConceptSpecializationExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  clang::NestedNameSpecifierLoc NNS = E->getNestedNameSpecifierLoc();
  if (NNS)
    NNS.getNestedNameSpecifier()->print(OS, Policy);
  if (E->getTemplateKWLoc().isValid())
    OS << "template ";
  OS << E->getFoundDecl()->getName();
  printTemplateArgumentList(OS, E->getTemplateArgsAsWritten()->arguments(),
                            Policy);
}

void StmtPrinter::VisitRequiresExpr(clang::RequiresExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << "requires ";
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
        TypeReq->getType()->getType().print(OS, Policy);
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
      if (NestedReq->isSubstitutionFailure())
        OS << "<<error-expression>>";
      else
        PrintExpr(NestedReq->getConstraintExpr());
    }
    OS << "; ";
  }
  OS << "}";
}

// C++ Coroutines TS

void StmtPrinter::VisitCoroutineBodyStmt(clang::CoroutineBodyStmt *S) {
  PrintContext ctx(pp, OS, S, tokens, __FUNCTION__);
  Visit(S->getBody());
}

void StmtPrinter::VisitCoreturnStmt(clang::CoreturnStmt *S) {
  PrintContext ctx(pp, OS, S, tokens, __FUNCTION__);
  OS << "co_return";
  if (S->getOperand()) {
    OS << " ";
    Visit(S->getOperand());
  }
  OS << ";";
}

void StmtPrinter::VisitCoawaitExpr(clang::CoawaitExpr *S) {
  PrintContext ctx(pp, OS, S, tokens, __FUNCTION__);
  OS << "co_await ";
  PrintExpr(S->getOperand());
}

void StmtPrinter::VisitDependentCoawaitExpr(clang::DependentCoawaitExpr *S) {
  PrintContext ctx(pp, OS, S, tokens, __FUNCTION__);
  OS << "co_await ";
  PrintExpr(S->getOperand());
}

void StmtPrinter::VisitCoyieldExpr(clang::CoyieldExpr *S) {
  PrintContext ctx(pp, OS, S, tokens, __FUNCTION__);
  OS << "co_yield ";
  PrintExpr(S->getOperand());
}

// Obj-C

void StmtPrinter::VisitObjCStringLiteral(clang::ObjCStringLiteral *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "@";
  VisitStringLiteral(Node->getString());
}

void StmtPrinter::VisitObjCBoxedExpr(clang::ObjCBoxedExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << "@";
  Visit(E->getSubExpr());
}

void StmtPrinter::VisitObjCArrayLiteral(clang::ObjCArrayLiteral *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
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
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "@encode(";
  Node->getEncodedType().print(OS, Policy);
  OS << ')';
}

void StmtPrinter::VisitObjCSelectorExpr(clang::ObjCSelectorExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "@selector(";
  Node->getSelector().print(OS);
  OS << ')';
}

void StmtPrinter::VisitObjCProtocolExpr(clang::ObjCProtocolExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "@protocol(" << *Node->getProtocol() << ')';
}

void StmtPrinter::VisitObjCMessageExpr(clang::ObjCMessageExpr *Mess) {
  PrintContext ctx(pp, OS, Mess, tokens, __FUNCTION__);
  OS << "[";
  switch (Mess->getReceiverKind()) {
  case clang::ObjCMessageExpr::Instance:
    PrintExpr(Mess->getInstanceReceiver());
    break;

  case clang::ObjCMessageExpr::Class:
    Mess->getClassReceiver().print(OS, Policy);
    break;

  case clang::ObjCMessageExpr::SuperInstance:
  case clang::ObjCMessageExpr::SuperClass:
    OS << "Super";
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
}

void StmtPrinter::VisitObjCBoolLiteralExpr(clang::ObjCBoolLiteralExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << (Node->getValue() ? "__objc_yes" : "__objc_no");
}

void
StmtPrinter::VisitObjCIndirectCopyRestoreExpr(clang::ObjCIndirectCopyRestoreExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  PrintExpr(E->getSubExpr());
}

void
StmtPrinter::VisitObjCBridgedCastExpr(clang::ObjCBridgedCastExpr *E) {
  PrintContext ctx(pp, OS, E, tokens, __FUNCTION__);
  OS << '(' << E->getBridgeKindName();
  E->getType().print(OS, Policy);
  OS << ')';
  PrintExpr(E->getSubExpr());
}

void StmtPrinter::VisitBlockExpr(clang::BlockExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  clang::BlockDecl *BD = Node->getBlockDecl();
  OS << "^";

  const clang::FunctionType *AFT = Node->getFunctionType();

  if (clang::isa<clang::FunctionNoProtoType>(AFT)) {
    OS << "()";
  } else if (!BD->param_empty() || clang::cast<clang::FunctionProtoType>(AFT)->isVariadic()) {
    OS << '(';
    for (clang::BlockDecl::param_iterator AI = BD->param_begin(),
         E = BD->param_end(); AI != E; ++AI) {
      if (AI != BD->param_begin()) OS << ", ";
      std::string ParamStr = (*AI)->getNameAsString();
      (*AI)->getType().print(OS, Policy, ParamStr);
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  PrintExpr(Node->getSourceExpr());
}

void StmtPrinter::VisitTypoExpr(clang::TypoExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  // TODO: Print something reasonable for a TypoExpr, if necessary.
  llvm_unreachable("Cannot print TypoExpr nodes");
}

void StmtPrinter::VisitRecoveryExpr(clang::RecoveryExpr *Node) {
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
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
  PrintContext ctx(pp, OS, Node, tokens, __FUNCTION__);
  OS << "__builtin_astype(";
  PrintExpr(Node->getSrcExpr());
  OS << ", ";
  Node->getType().print(OS, Policy);
  OS << ")";
}


StmtPrinterImpl::StmtPrinterImpl(const clang::ASTContext &ast_, const clang::Preprocessor &pp_, const clang::Stmt *stmt_)
  : ast(ast_), pp(pp_), stmt(stmt_) {
  raw_string_ostream rss(out_buffer);
  StmtPrinter printer(rss, nullptr, pp, tokens, ast.getPrintingPolicy());
  printer.PrintStmt(const_cast<clang::Stmt*>(stmt_));
}

} // namespace pasta



//===----------------------------------------------------------------------===//
// Stmt method implementations
//===----------------------------------------------------------------------===//

#if 0
void dumpPretty(const ASTContext &Context) const {
  std::string s;
  printPretty(s, nullptr, PrintingPolicy(Context.getLangOpts()));
}

void printPretty(pasta::raw_string_ostream &Out, PrinterHelper *Helper,
                       const PrintingPolicy &Policy, unsigned Indentation,
                       StringRef NL, const ASTContext *Context) const {
  pasta::StmtPrinter P(Out, Helper, Policy, Indentation, NL, Context);
  P.Visit(const_cast<Stmt *>(this));
}

void printJson(pasta::raw_string_ostream &Out, PrinterHelper *Helper,
                     const PrintingPolicy &Policy, bool AddQuotes) const {
  std::string Buf;
  pasta::raw_string_ostream TempOut(Buf);

  printPretty(TempOut, Helper, Policy);

  Out << JsonFormat(TempOut.str(), AddQuotes);
}
#endif
