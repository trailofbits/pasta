//===--- DeclPrinter.cpp - Printing implementation for Decl ASTs ----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the Decl::print method, which pretty prints the
// AST back out to C/Objective-C/C++/Objective-C++ code.
//
//===----------------------------------------------------------------------===//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclBase.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/DeclVisitor.h>
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

#include <clang/Frontend/CompilerInstance.h>
#pragma clang diagnostic pop

#include <cassert>
#include <string>

#include "raw_ostream.h"
#include "Printer.h"
#include "../Token.h"

namespace pasta {

class PrintedTokenRangeImpl;

class DeclPrinter : public clang::DeclVisitor<DeclPrinter> {
  raw_string_ostream &Out;
  clang::PrintingPolicy Policy;
  const clang::ASTContext &Context;
  unsigned Indentation;
  bool PrintInstantiation;

  raw_string_ostream& Indent() { return Indent(static_cast<int>(Indentation)); }
  raw_string_ostream& Indent(int Indentation);
  void ProcessDeclGroup(clang::SmallVectorImpl<clang::Decl*>& Decls);
  void Print(clang::AccessSpecifier AS);
  void PrintConstructorInitializers(clang::CXXConstructorDecl *CDecl,
                                    std::function<void(void)> &ProtoFn);
  /// Print an Objective-C method type in parentheses.
  ///
  /// \param Quals The Objective-C declaration qualifiers.
  /// \param T The type to print.
  void PrintObjCMethodType(clang::ASTContext &Ctx, clang::Decl::ObjCDeclQualifier Quals,
                           clang::QualType T);
  void PrintObjCTypeParams(clang::ObjCTypeParamList *Params);


 public:
   DeclPrinter(raw_string_ostream &Out, const clang::PrintingPolicy &Policy,
               const clang::ASTContext &Context, PrintedTokenRangeImpl &tokens_,
               unsigned Indentation = 0,bool PrintInstantiation = false)
       : Out(Out), Policy(Policy), Context(Context), Indentation(Indentation),
         PrintInstantiation(PrintInstantiation), tokens(tokens_) {}

   void VisitDeclContext(clang::DeclContext *DC, bool Indent = true);
   void VisitTranslationUnitDecl(clang::TranslationUnitDecl *D);
   void VisitTypedefDecl(clang::TypedefDecl *D);
   void VisitTypeAliasDecl(clang::TypeAliasDecl *D);
   void VisitEnumDecl(clang::EnumDecl *D);
   void VisitRecordDecl(clang::RecordDecl *D);
   void VisitEnumConstantDecl(clang::EnumConstantDecl *D);
   void VisitEmptyDecl(clang::EmptyDecl *D);
   void VisitFunctionDecl(clang::FunctionDecl *D);
   void VisitFriendDecl(clang::FriendDecl *D);
   void VisitFieldDecl(clang::FieldDecl *D);
   void VisitVarDecl(clang::VarDecl *D);
   void VisitLabelDecl(clang::LabelDecl *D);
   void VisitParmVarDecl(clang::ParmVarDecl *D);
   void VisitFileScopeAsmDecl(clang::FileScopeAsmDecl *D);
   void VisitImportDecl(clang::ImportDecl *D);
   void VisitStaticAssertDecl(clang::StaticAssertDecl *D);
   void VisitNamespaceDecl(clang::NamespaceDecl *D);
   void VisitUsingDirectiveDecl(clang::UsingDirectiveDecl *D);
   void VisitNamespaceAliasDecl(clang::NamespaceAliasDecl *D);
   void VisitCXXRecordDecl(clang::CXXRecordDecl *D);
   void VisitLinkageSpecDecl(clang::LinkageSpecDecl *D);
   void VisitTemplateDecl(const clang::TemplateDecl *D);
   void VisitFunctionTemplateDecl(clang::FunctionTemplateDecl *D);
   void VisitClassTemplateDecl(clang::ClassTemplateDecl *D);
   void VisitClassTemplateSpecializationDecl(
       clang::ClassTemplateSpecializationDecl *D);

   void VisitClassTemplatePartialSpecializationDecl(
       clang::ClassTemplatePartialSpecializationDecl *D);
   void VisitObjCMethodDecl(clang::ObjCMethodDecl *D);
   void VisitObjCImplementationDecl(clang::ObjCImplementationDecl *D);
   void VisitObjCInterfaceDecl(clang::ObjCInterfaceDecl *D);
   void VisitObjCProtocolDecl(clang::ObjCProtocolDecl *D);
   void VisitObjCCategoryImplDecl(clang::ObjCCategoryImplDecl *D);

   void VisitObjCCategoryDecl(clang::ObjCCategoryDecl *D);
   void VisitObjCCompatibleAliasDecl(clang::ObjCCompatibleAliasDecl *D);
   void VisitObjCPropertyDecl(clang::ObjCPropertyDecl *D);
   void VisitObjCPropertyImplDecl(clang::ObjCPropertyImplDecl *D);
   void VisitUnresolvedUsingTypenameDecl(clang::UnresolvedUsingTypenameDecl *D);
   void VisitUnresolvedUsingValueDecl(clang::UnresolvedUsingValueDecl *D);
   void VisitUsingDecl(clang::UsingDecl *D);
   void VisitUsingShadowDecl(clang::UsingShadowDecl *D);
   void VisitOMPThreadPrivateDecl(clang::OMPThreadPrivateDecl *D);
   void VisitOMPAllocateDecl(clang::OMPAllocateDecl *D);
   void VisitOMPRequiresDecl(clang::OMPRequiresDecl *D);
   void VisitOMPDeclareReductionDecl(clang::OMPDeclareReductionDecl *D);
   void VisitOMPDeclareMapperDecl(clang::OMPDeclareMapperDecl *D);
   void VisitOMPCapturedExprDecl(clang::OMPCapturedExprDecl *D);
   void VisitTemplateTypeParmDecl(const clang::TemplateTypeParmDecl *TTP);
   void VisitNonTypeTemplateParmDecl(const clang::NonTypeTemplateParmDecl *NTTP);
   void printTemplateParameters(const clang::TemplateParameterList *Params,
                                bool OmitTemplateKW = false);
   void printTemplateArguments(llvm::ArrayRef<clang::TemplateArgument> Args);
   void printTemplateArguments(llvm::ArrayRef<clang::TemplateArgumentLoc> Args);
   void prettyPrintAttributes(clang::Decl *D);
   void prettyPrintPragmas(clang::Decl *D);
   void printDeclType(clang::QualType T, llvm::StringRef DeclName, bool Pack = false);

   void printPrettyStmt(clang::Stmt *stmt_,
                        raw_string_ostream &Out,
                        clang::PrinterHelper *Helper,
                        const clang::PrintingPolicy &Policy,
                        unsigned Indentation = 0, clang::StringRef NL = "\n");

   void printQualType(clang::QualType qt,
                      raw_string_ostream &OS,
                      const clang::PrintingPolicy &Policy);

   void printQualType(clang::QualType qt,
                     raw_string_ostream &OS,
                     const clang::PrintingPolicy &Policy,
                     std::function<void(void)> ProtoFn,
                     unsigned Indentation = 0);


   PrintedTokenRangeImpl &tokens;
};

//===----------------------------------------------------------------------===//
// StmtPrinter Visitor
//===----------------------------------------------------------------------===//

class StmtPrinter : public clang::StmtVisitor<StmtPrinter> {
  pasta::raw_string_ostream &OS;
  unsigned IndentLevel;
  clang::PrinterHelper* Helper;
  clang::PrintingPolicy Policy;
  std::string NL;
  const clang::ASTContext *Context;

  public:
    StmtPrinter(pasta::raw_string_ostream &os, clang::PrinterHelper *helper,
                PrintedTokenRangeImpl &tokens_,
                const clang::PrintingPolicy &Policy, unsigned Indentation = 0,
                clang::StringRef NL = "\n", const clang::ASTContext *Context = nullptr)
        : OS(os), IndentLevel(Indentation), Helper(helper), Policy(Policy),
          NL(NL), Context(Context), tokens(tokens_) {}

    void PrintStmt(clang::Stmt *S) { PrintStmt(S, Policy.Indentation); }

    void printQualType(clang::QualType type_, raw_string_ostream &OS,
                       const clang::PrintingPolicy &Policy);

    void printQualType(
        clang::QualType type_, raw_string_ostream &OS,
        const clang::PrintingPolicy &Policy,
        std::function<void(void)> *PlaceHolderFn,
        unsigned Indentation = 0);

    void printDecl(clang::Decl *D, raw_string_ostream &Out,
                   const clang::PrintingPolicy &policy_, unsigned Indentation);

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
      TokenPrinterContext ctx(OS, E, tokens, __FUNCTION__);
      if (E)
        Visit(E);
      else
        OS << "<null expr>";
    }

    bool suppress_leading_indent = false;

    pasta::raw_string_ostream &Indent(int Delta = 0) {
      if (!suppress_leading_indent) {
        auto level = static_cast<int>(IndentLevel) + Delta;
        for (int i = 0, e = level; i < e; ++i)
          OS << "  ";
      } else {
        suppress_leading_indent = false;
      }
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

  PrintedTokenRangeImpl &tokens;
};

void Decl_printGroup(clang::Decl** Begin, size_t NumDecls,
                     raw_string_ostream &Out, const clang::PrintingPolicy &Policy,
                     unsigned Indentation, PrintedTokenRangeImpl &tokens);

//===----------------------------------------------------------------------===//
// TypePrinter Visitor
//===----------------------------------------------------------------------===//

class TypePrinter {
  clang::PrintingPolicy Policy;
  unsigned Indentation;
  bool HasEmptyPlaceHolder = false;
  bool InsideCCAttribute = false;

public:
  explicit TypePrinter(const clang::PrintingPolicy &Policy,
                       PrintedTokenRangeImpl &tokens_,
                       unsigned Indentation = 0)
      : Policy(Policy), Indentation(Indentation), tokens(tokens_) {}

  void print(const clang::Type *ty, clang::Qualifiers qs,
             raw_string_ostream &OS, clang::StringRef PlaceHolder,
             std::function<void(void)> *placeHolderFn = nullptr);

  void print(clang::QualType T, raw_string_ostream &OS,
             clang::StringRef PlaceHolder, std::function<void(void)> *placeHolderFn = nullptr);

  static bool canPrefixQualifiers(const clang::Type *T, bool &NeedARCStrongQualifier);
  void spaceBeforePlaceHolder(raw_string_ostream &OS);
  void printTypeSpec(clang::NamedDecl *D, raw_string_ostream &OS);
  void printTemplateId(const clang::TemplateSpecializationType *T, raw_string_ostream &OS,
                       bool FullyQualify);

  void printBefore(clang::QualType T, raw_string_ostream &OS);
  void printAfter(clang::QualType T, raw_string_ostream &OS);
  void AppendScope(clang::DeclContext *DC, raw_string_ostream &OS,
                   clang::DeclarationName NameInScope);
  void printTag(clang::TagDecl *T, raw_string_ostream &OS);
  void printFunctionAfter(const clang::FunctionType::ExtInfo &Info, raw_string_ostream &OS);

#define ABSTRACT_TYPE(CLASS, PARENT)
#define TYPE(CLASS, PARENT) \
  void print##CLASS##Before(const clang::CLASS##Type *T, raw_string_ostream &OS); \
  void print##CLASS##After(const clang::CLASS##Type *T, raw_string_ostream &OS);
#include "clang/AST/TypeNodes.inc"

private:
  void printBefore(const clang::Type *ty, clang::Qualifiers qs, raw_string_ostream &OS);
  void printAfter(const clang::Type *ty, clang::Qualifiers qs, raw_string_ostream &OS);

  PrintedTokenRangeImpl &tokens;
};

} // namespace pasta
