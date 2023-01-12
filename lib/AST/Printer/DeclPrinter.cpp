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

#include "DeclStmtPrinter.h"

namespace pasta {

class PrintedTokenRangeImpl;


void Decl_printGroup(clang::Decl** Begin, size_t NumDecls,
                     raw_string_ostream &Out, const clang::PrintingPolicy &Policy,
                     unsigned Indentation, PrintedTokenRangeImpl &tokens) {
  if (NumDecls == 1) {
    DeclPrinter Printer(Out, Policy,  (*Begin)->getASTContext(), tokens, Indentation);
    Printer.Visit((*Begin));
    return;
  }
  clang::Decl** End = Begin + NumDecls;
  clang::TagDecl* TD = clang::dyn_cast<clang::TagDecl>(*Begin);
  if (TD)
    ++Begin;
  clang::PrintingPolicy SubPolicy(Policy);
  bool isFirst = true;
  for ( ; Begin != End; ++Begin) {
    if (isFirst) {
      if(TD)
        SubPolicy.IncludeTagDefinition = true;
      SubPolicy.SuppressSpecifiers = false;
      isFirst = false;
    } else {
      if (!isFirst) Out << ", ";
      SubPolicy.IncludeTagDefinition = false;
      SubPolicy.SuppressSpecifiers = true;
    }
    DeclPrinter Printer(Out, SubPolicy,  (*Begin)->getASTContext(), tokens, Indentation);
    Printer.Visit((*Begin));
  }
}

static clang::QualType GetBaseType(clang::QualType T) {
  // FIXME: This should be on the Type class!
  clang::QualType BaseType = T;
  while (!BaseType->isSpecifierType()) {
    if (const clang::PointerType *PTy = BaseType->getAs<clang::PointerType>())
      BaseType = PTy->getPointeeType();
    else if (const clang::BlockPointerType *BPy = BaseType->getAs<clang::BlockPointerType>())
      BaseType = BPy->getPointeeType();
    else if (const clang::ArrayType* ATy = clang::dyn_cast<clang::ArrayType>(BaseType))
      BaseType = ATy->getElementType();
    else if (const clang::FunctionType* FTy = BaseType->getAs<clang::FunctionType>())
      BaseType = FTy->getReturnType();
    else if (const clang::VectorType *VTy = BaseType->getAs<clang::VectorType>())
      BaseType = VTy->getElementType();
    else if (const clang::ReferenceType *RTy = BaseType->getAs<clang::ReferenceType>())
      BaseType = RTy->getPointeeType();
    else if (const clang::AutoType *ATy = BaseType->getAs<clang::AutoType>())
      BaseType = ATy->getDeducedType();
    else if (const clang::ParenType *PTy = BaseType->getAs<clang::ParenType>())
      BaseType = PTy->desugar();
    else
      // This must be a syntax error.
      break;
  }
  return BaseType;
}

static clang::QualType getDeclType(clang::Decl* D) {
  if (clang::TypedefNameDecl* TDD = clang::dyn_cast<clang::TypedefNameDecl>(D))
    return TDD->getUnderlyingType();
  if (clang::ValueDecl* VD = clang::dyn_cast<clang::ValueDecl>(D))
    return VD->getType();
  return clang::QualType();
}

raw_string_ostream& DeclPrinter::Indent(int Indentation) {
  for (int i = 0; i != Indentation; ++i)
    Out << "  ";
  return Out;
}


void DeclPrinter::printQualType(clang::QualType qt,
                   raw_string_ostream &OS,
                   const clang::PrintingPolicy &Policy) {
  TypePrinter(Policy, tokens, Indentation).print(qt, OS, "");
}

void DeclPrinter::printQualType(clang::QualType qt,
                                raw_string_ostream &OS,
                                const clang::PrintingPolicy &Policy,
                                std::function<void(void)> ProtoFn,
                                unsigned Indentation) {
  TypePrinter(Policy, tokens, Indentation).print(qt, OS, "", &ProtoFn);
}

void DeclPrinter::printPrettyStmt(clang::Stmt *stmt_,
                                  raw_string_ostream &Out,
                                  clang::PrinterHelper *Helper,
                                  const clang::PrintingPolicy &Policy,
                                  unsigned Indentation, clang::StringRef NL) {
  StmtPrinter stmtPrinter(Out, Helper, tokens, Policy, Indentation, NL, &Context);
  stmtPrinter.Visit(const_cast<clang::Stmt *>(stmt_));
}

void DeclPrinter::prettyPrintAttributes(clang::Decl *D) {
  if (Policy.PolishForDeclaration)
    return;

  if (D->hasAttrs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);

    clang::AttrVec &Attrs = D->getAttrs();
    for (auto *A : Attrs) {
      if (A->isInherited() || A->isImplicit())
        continue;
      switch (A->getKind()) {
#define ATTR(X)
#define PRAGMA_SPELLING_ATTR(X) case clang::attr::X:
#include "clang/Basic/AttrList.inc"
        break;
      default:
        PrintAttribute(Out, A, tokens, Policy);
        break;
      }
    }
  }
}

// TODO(pag): This seems to overlap with `prettyPrintAttributes` and is
//            sometimes called in similar contexts, e.g. `VisitFunctionDecl`;
//            investigate this.
void DeclPrinter::prettyPrintPragmas(clang::Decl *D) {
  if (Policy.PolishForDeclaration)
    return;

  if (D->hasAttrs()) {
    TagDefinitionPolicyRAII disable_tags(Policy);

    clang::AttrVec &Attrs = D->getAttrs();
    for (auto *A : Attrs) {
      switch (A->getKind()) {
#define ATTR(X)
#define PRAGMA_SPELLING_ATTR(X) case clang::attr::X:
#include "clang/Basic/AttrList.inc"
        PrintAttribute(Out, A, tokens, Policy);
        Indent();
        break;
      default:
        break;
      }
    }
  }
}

void DeclPrinter::printDeclType(clang::QualType T, std::function<void(void)> NameFn, bool Pack) {
  // Normally, a PackExpansionType is written as T[3]... (for instance, as a
  // template argument), but if it is the type of a declaration, the ellipsis
  // is placed before the name being declared.
  if (auto *PET = T->getAs<clang::PackExpansionType>()) {
    Pack = true;
    T = PET->getPattern();
  }

  printQualType(T, Out, Policy, [=, NameFn = std::move(NameFn), this] () {
    if (Pack) {
      Out << "...";
    }
    NameFn();
  }, Indentation);
}

void DeclPrinter::ProcessDeclGroup(clang::SmallVectorImpl<clang::Decl*>& Decls) {
  this->Indent();
  Decl_printGroup(Decls.data(), static_cast<unsigned>(Decls.size()), Out,
                  Policy, Indentation, tokens);
  Out << ";\n";
  Decls.clear();

}

void DeclPrinter::Print(clang::AccessSpecifier AS) {
  const auto AccessSpelling = getAccessSpelling(AS);
  if (AccessSpelling.empty())
    llvm_unreachable("No access specifier!");
  Out << AccessSpelling;
}

void DeclPrinter::PrintConstructorInitializers(
    TokenPrinterContext &ctx, clang::CXXConstructorDecl *CDecl,
    std::function<void(void)> &ProtoFn) {
  bool HasInitializerList = false;
  std::vector<const clang::CXXCtorInitializer *> inits;
  for (const auto *BMInitializer : CDecl->inits()) {
    if (BMInitializer->isInClassMemberInitializer() ||
        (CDecl->getBeginLoc().isValid() && !BMInitializer->isWritten()))
      continue;
    inits.push_back(BMInitializer);
  }

  // Put them in source order if it seems like there was source.
  if (CDecl->getBeginLoc().isValid()) {
    std::sort(inits.begin(), inits.end(),
              [] (const clang::CXXCtorInitializer *a,
                  const clang::CXXCtorInitializer *b) {
      return a->getSourceOrder() < b->getSourceOrder();
    });
  }

  for (const auto *BMInitializer : inits) {
    if (!HasInitializerList) {
      ProtoFn();
      Out << " : ";
      ProtoFn = [] (void) -> void {};  // Reset in caller
      HasInitializerList = true;
    } else
      Out << ", ";

    if (BMInitializer->isAnyMemberInitializer()) {
      clang::FieldDecl *FD = BMInitializer->getAnyMember();
      Out << *FD;
    } else {
      printQualType(clang::QualType(BMInitializer->getBaseClass(), 0), Out, Policy);
    }

    Out << "(";
    ctx.MarkLocation(BMInitializer->getLParenLoc());

    if (!BMInitializer->getInit()) {
      // Nothing to print
    } else {
      clang::Expr *Init = BMInitializer->getInit();
      if (clang::ExprWithCleanups *Tmp = clang::dyn_cast<clang::ExprWithCleanups>(Init))
        Init = Tmp->getSubExpr();

      Init = Init->IgnoreParens();

      clang::Expr *SimpleInit = nullptr;
      clang::Expr **Args = nullptr;
      unsigned NumArgs = 0;
      if (clang::ParenListExpr *ParenList = clang::dyn_cast<clang::ParenListExpr>(Init)) {
        Args = ParenList->getExprs();
        NumArgs = ParenList->getNumExprs();
      } else if (clang::CXXConstructExpr *Construct = clang::dyn_cast<clang::CXXConstructExpr>(Init)) {
        Args = Construct->getArgs();
        NumArgs = Construct->getNumArgs();
      } else
        SimpleInit = Init;

      if (SimpleInit)
        printPrettyStmt(SimpleInit, Out, nullptr, Policy, Indentation);
      else {
        for (unsigned I = 0; I != NumArgs; ++I) {
          assert(Args[I] != nullptr && "Expected non-null Expr");
          if (clang::isa<clang::CXXDefaultArgExpr>(Args[I]))
            break;

          if (I)
            Out << ", ";
          printPrettyStmt(Args[I], Out, nullptr, Policy, Indentation);
        }
      }
    }
    Out << ")";
    ctx.MarkLocation(BMInitializer->getRParenLoc());
    if (BMInitializer->isPackExpansion())
      Out << "...";
  }
}

//----------------------------------------------------------------------------
// Common C declarations
//----------------------------------------------------------------------------

void DeclPrinter::VisitDeclContext(clang::DeclContext *DC, bool Indent) {
  if (Policy.TerseOutput)
    return;

  if (Indent)
    Indentation += Policy.Indentation;

  clang::SmallVector<clang::Decl*, 2> Decls;
  for (clang::DeclContext::decl_iterator D = DC->decls_begin(), DEnd = DC->decls_end();
       D != DEnd; ++D) {

    // Don't print ObjCIvarDecls, as they are printed when visiting the
    // containing ObjCInterfaceDecl.
    if (clang::isa<clang::ObjCIvarDecl>(*D))
      continue;

    // Skip over implicit declarations in pretty-printing mode.
    if (D->isImplicit())
      continue;

    // Don't print implicit specializations, as they are printed when visiting
    // corresponding templates.
    if (auto FD = clang::dyn_cast<clang::FunctionDecl>(*D))
      if (FD->getTemplateSpecializationKind() == clang::TSK_ImplicitInstantiation &&
          !clang::isa<clang::ClassTemplateSpecializationDecl>(DC))
        continue;

    // The next bits of code handle stuff like "struct {int x;} a,b"; we're
    // forced to merge the declarations because there's no other way to
    // refer to the struct in question.  When that struct is named instead, we
    // also need to merge to avoid splitting off a stand-alone struct
    // declaration that produces the warning ext_no_declarators in some
    // contexts.
    //
    // This limited merging is safe without a bunch of other checks because it
    // only merges declarations directly referring to the tag, not typedefs.
    //
    // Check whether the current declaration should be grouped with a previous
    // non-free-standing tag declaration.
    clang::QualType CurDeclType = getDeclType(*D);
    if (!Decls.empty() && !CurDeclType.isNull()) {
      clang::QualType BaseType = GetBaseType(CurDeclType);
      if (!BaseType.isNull() && clang::isa<clang::ElaboratedType>(BaseType) &&
          clang::cast<clang::ElaboratedType>(BaseType)->getOwnedTagDecl() == Decls[0]) {
        Decls.push_back(*D);
        continue;
      }
    }

    // If we have a merged group waiting to be handled, handle it now.
    if (!Decls.empty())
      ProcessDeclGroup(Decls);

    // If the current declaration is not a free standing declaration, save it
    // so we can merge it with the subsequent declaration(s) using it.
    if (clang::isa<clang::TagDecl>(*D) && !clang::cast<clang::TagDecl>(*D)->isFreeStanding()) {
      Decls.push_back(*D);
      continue;
    }

    if (clang::isa<clang::AccessSpecDecl>(*D)) {
      Indentation -= Policy.Indentation;
      this->Indent();
      Print(D->getAccess());
      Out << ":\n";
      Indentation += Policy.Indentation;
      continue;
    }

    this->Indent();
    Visit(*D);

    // FIXME: Need to be able to tell the DeclPrinter when
    const char *Terminator = nullptr;
    if (clang::isa<clang::OMPThreadPrivateDecl>(*D) || clang::isa<clang::OMPDeclareReductionDecl>(*D) ||
        clang::isa<clang::OMPDeclareMapperDecl>(*D) || clang::isa<clang::OMPRequiresDecl>(*D) ||
        clang::isa<clang::OMPAllocateDecl>(*D))
      Terminator = nullptr;
    else if (clang::isa<clang::ObjCMethodDecl>(*D) && clang::cast<clang::ObjCMethodDecl>(*D)->hasBody())
      Terminator = nullptr;
    else if (auto FD = clang::dyn_cast<clang::FunctionDecl>(*D)) {
      if (FD->isExplicitlyDefaulted() || FD->isDeletedAsWritten() || FD->isPure())
        Terminator = ";";
      else if (FD->isThisDeclarationADefinition())
        Terminator = nullptr;
      else
        Terminator = ";";
    } else if (auto TD = clang::dyn_cast<clang::FunctionTemplateDecl>(*D)) {
      if (TD->getTemplatedDecl()->isExplicitlyDefaulted() ||
          TD->getTemplatedDecl()->isDeletedAsWritten() ||
          TD->getTemplatedDecl()->isPure())
        Terminator = ";";
      else if (TD->getTemplatedDecl()->isThisDeclarationADefinition())
        Terminator = nullptr;
      else
        Terminator = ";";
    } else if (isa<clang::NamespaceDecl, clang::LinkageSpecDecl, clang::ObjCImplementationDecl,
                   clang::ObjCInterfaceDecl, clang::ObjCProtocolDecl, clang::ObjCCategoryImplDecl,
                   clang::ObjCCategoryDecl>(*D))
      Terminator = nullptr;
    else if (clang::isa<clang::EnumConstantDecl>(*D)) {
      clang::DeclContext::decl_iterator Next = D;
      ++Next;
      if (Next != DEnd)
        Terminator = ",";
    } else
      Terminator = ";";

    if (Terminator)
      Out << Terminator;
    if (!Policy.TerseOutput &&
        ((clang::isa<clang::FunctionDecl>(*D) &&
          clang::cast<clang::FunctionDecl>(*D)->doesThisDeclarationHaveABody()) ||
         (clang::isa<clang::FunctionTemplateDecl>(*D) &&
          clang::cast<clang::FunctionTemplateDecl>(*D)->getTemplatedDecl()->doesThisDeclarationHaveABody())))
      ; // StmtPrinter already added '\n' after CompoundStmt.
    else
      Out << "\n";

    // Declare target attribute is special one, natural spelling for the pragma
    // assumes "ending" construct so print it here.
    if (D->hasAttr<clang::OMPDeclareTargetDeclAttr>())
      Out << "#pragma omp end declare target\n";
  }

  if (!Decls.empty())
    ProcessDeclGroup(Decls);

  if (Indent)
    Indentation -= Policy.Indentation;
}

void DeclPrinter::VisitTranslationUnitDecl(clang::TranslationUnitDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  VisitDeclContext(D, false);
}

void DeclPrinter::VisitTypedefDecl(clang::TypedefDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (!Policy.SuppressSpecifiers) {
    Out << "typedef ";
    ctx.MarkLocation(D->getBeginLoc());

    if (D->isModulePrivate())
      Out << "__module_private__ ";
  }

  TagDefinitionPolicyRAII disable_tags(Policy);
  clang::QualType Ty = D->getTypeSourceInfo()->getType();
  printQualType(
      Ty, Out, Policy,
      [&] () {
        if (auto name = D->getName(); !name.empty()) {
          TokenPrinterContext jump_up_stack(ctx);
          Out << name;
          ctx.MarkLocation(D->getLocation());
        }
      },
      Indentation);
  prettyPrintAttributes(D);
}

void DeclPrinter::VisitTypeAliasDecl(clang::TypeAliasDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "using ";
  ctx.MarkLocation(D->getBeginLoc());
  Out << *D;
  ctx.MarkLocation(D->getLocation());
  prettyPrintAttributes(D);
  Out << " = ";
  TagDefinitionPolicyRAII disable_tags(Policy);
  printQualType(D->getTypeSourceInfo()->getType(), Out, Policy);
}

void DeclPrinter::VisitEnumDecl(clang::EnumDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  auto printed_tag = (Policy.IncludeTagDefinition || !D->getIdentifier()) &&
                     Out.printed_defs.emplace(D).second;
  if (!Policy.SuppressSpecifiers && D->isModulePrivate())
    Out << "__module_private__ ";
  Out << "enum";


  if (tokens.ast) {
    auto tag_loc = D->getInnerLocStart();
    if (auto tag_tok = tokens.ast->RawTokenAt(tag_loc)) {
      if (tag_tok->Kind() == clang::tok::kw_enum) {
        ctx.MarkLocation(tag_loc);
      }
    }
  }

  if (D->isScoped()) {
    if (D->isScopedUsingClassTag())
      Out << " class";
    else
      Out << " struct";
  }

  prettyPrintAttributes(D);

  if (D->getDeclName())
    Out << ' ' << D->getDeclName();

  if (D->isFixed()) {
    Out << " :";

    if (tokens.ast) {
      const TokenImpl *tok =
          tokens.ast->RawTokenAt(D->getIntegerTypeRange().getBegin());
      for (auto i = 0; tok && i < 4; ++i) {
        const TokenImpl &t = tok[-i];
        if (t.Kind() == clang::tok::colon) {
          ctx.MarkLocation(t);
          break;
        }
      }
    }

    Out << " " <<  D->getIntegerType().stream(Policy);
  }


  if (D->isCompleteDefinition() && printed_tag) {
    for (auto R : D->redecls()) {
      Out.printed_defs.emplace(R);
    }

    auto braces = D->getBraceRange();
    Out << " {";
    ctx.MarkLocation(braces.getBegin());
    Out << '\n';
    VisitDeclContext(D);
    Indent() << "}";
    ctx.MarkLocation(braces.getEnd());
  }
}

void DeclPrinter::VisitRecordDecl(clang::RecordDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  auto printed_tag = (Policy.IncludeTagDefinition || !D->getIdentifier()) &&
                     Out.printed_defs.emplace(D).second;

  if (!Policy.SuppressSpecifiers && D->isModulePrivate())
    Out << "__module_private__ ";
  Out << D->getKindName();

  if (tokens.ast) {
    auto tag_loc = D->getInnerLocStart();
    if (auto tag_tok = tokens.ast->RawTokenAt(tag_loc)) {
      switch (tag_tok->Kind()) {
        case clang::tok::kw_struct:
        case clang::tok::kw_union:
          ctx.MarkLocation(tag_loc);
          break;
        default:
          break;
      }
    }
  }

  prettyPrintAttributes(D);

  if (D->getIdentifier())
    Out << ' ' << *D;

  if (D->isCompleteDefinition() && printed_tag) {
    for (auto R : D->redecls()) {
      Out.printed_defs.emplace(R);
    }

    auto braces = D->getBraceRange();
    Out << " {";
    ctx.MarkLocation(braces.getBegin());
    Out << '\n';
    VisitDeclContext(D);
    Indent() << "}";
    ctx.MarkLocation(braces.getEnd());
  }
}

void DeclPrinter::VisitEnumConstantDecl(clang::EnumConstantDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << *D;
  prettyPrintAttributes(D);
  if (clang::Expr *Init = D->getInitExpr()) {
    Out << " = ";
    StmtPrinter stmtPrinter(Out, nullptr, tokens, Policy, Indentation, "\n", &Context);
    stmtPrinter.Visit(const_cast<clang::Expr *>(Init));
  }
}

void DeclPrinter::VisitFunctionDecl(clang::FunctionDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);

  // Comes up with destructors and such, but if we're printing a method, then
  // we definitely don't want to print its enclosing class anywhere inside of
  // it.
  if (auto M = clang::dyn_cast<clang::CXXMethodDecl>(D)) {
    if (auto C = clang::dyn_cast<clang::CXXRecordDecl>(M->getParent())) {
      for (auto R : C->redecls()) {
        Out.printed_defs.emplace(R);
      }
    }
  }

  if (!D->getDescribedFunctionTemplate() &&
      !D->isFunctionTemplateSpecialization())
    prettyPrintPragmas(D);

  if (D->isFunctionTemplateSpecialization()) {
    Out << "template <> ";
  }

  else if (!D->getDescribedFunctionTemplate()) {
    for (unsigned I = 0, NumTemplateParams = D->getNumTemplateParameterLists();
         I < NumTemplateParams; ++I)
      printTemplateParameters(D->getTemplateParameterList(I));
  }

  auto printed_attributes = false;
  if (clang::isa<clang::CXXConstructorDecl>(D) ||
      clang::isa<clang::CXXDestructorDecl>(D)) {
    prettyPrintAttributes(D);
    printed_attributes = true;
  }

  clang::CXXConstructorDecl *CDecl = clang::dyn_cast<clang::CXXConstructorDecl>(D);
  clang::CXXConversionDecl *ConversionDecl = clang::dyn_cast<clang::CXXConversionDecl>(D);
  clang::CXXDeductionGuideDecl *GuideDecl = clang::dyn_cast<clang::CXXDeductionGuideDecl>(D);
  if (!Policy.SuppressSpecifiers) {
    switch (D->getStorageClass()) {
    case clang::SC_None: break;
    case clang::SC_Extern: Out << "extern "; break;
    case clang::SC_Static: Out << "static "; break;
    case clang::SC_PrivateExtern: Out << "__private_extern__ "; break;
    case clang::SC_Auto: case clang::SC_Register:
      llvm_unreachable("invalid for functions");
    }

    if (D->isInlineSpecified())  Out << "inline ";
    if (D->isVirtualAsWritten()) Out << "virtual ";
    if (D->isModulePrivate())    Out << "__module_private__ ";
    if (D->isConstexprSpecified() && !D->isExplicitlyDefaulted())
      Out << "constexpr ";
    if (D->isConsteval())
      Out << "consteval ";

    clang::ExplicitSpecifier ES = clang::ExplicitSpecifier::getFromDecl(D);
    if (ES.isSpecified()) {
      Out << "explicit";
      if (ES.getExpr()) {
        Out << "(";
        {
          StmtPrinter stmtPrinter(Out, nullptr, tokens, Policy, Indentation,
                                  "\n", &tokens.ast_context);
          stmtPrinter.Visit(const_cast<clang::Expr *>(ES.getExpr()));
        }
        Out << ")";
      }
      Out << " ";
    }
  }

  clang::PrintingPolicy SubPolicy(Policy);
  SubPolicy.SuppressSpecifiers = false;
  SubPolicy.IncludeTagDefinition = false;

  std::function<void(void)> ProtoFn = [=](void) -> void { };
  std::function<void(void)> EmtpyProtoFn = [](void) -> void { };
  if (Policy.FullyQualifiedName) {
    ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
      ProtoFn();
      TokenPrinterContext jump_up_stack(ctx);
      Out << D->getQualifiedNameAsString();
      ctx.MarkLocation(D->getLocation());
    };
  } else {
    ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
      ProtoFn();
      TokenPrinterContext jump_up_stack(ctx);
      if (!Policy.SuppressScope) {
        if (const clang::NestedNameSpecifier *NS = D->getQualifier()) {
          TagDefinitionPolicyRAII disable_tags(Policy);
          NS->print(Out, Policy);
        }
      }

      TagDefinitionPolicyRAII disable_tags(Policy);
      D->getNameInfo().printName(Out, Policy);
      ctx.MarkLocation(D->getLocation());
    };
  }

  if (GuideDecl) {
    ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
      ProtoFn();
      TokenPrinterContext jump_up_stack(ctx);
      Out << GuideDecl->getDeducedTemplate()->getDeclName().getAsString();
    };
  }
  if (D->isFunctionTemplateSpecialization()) {
    ProtoFn = [=, ProtoFn = std::move(ProtoFn), this] (void) {
      ProtoFn();
      DeclPrinter TArgPrinter(Out, SubPolicy, Context, tokens, Indentation);

      const auto *TArgAsWritten = D->getTemplateSpecializationArgsAsWritten();
      const clang::TemplateParameterList *TPL = D->getTemplateSpecializationInfo()
                                                ->getTemplate()
                                                ->getTemplateParameters();
      if (TArgAsWritten && !Policy.PrintCanonicalTypes)
        TArgPrinter.printTemplateArguments(TArgAsWritten->arguments(), TPL, true);
      else if (const clang::TemplateArgumentList *TArgs =
                   D->getTemplateSpecializationArgs())
        TArgPrinter.printTemplateArguments(TArgs->asArray(), TPL, true);
    };
  }

  clang::QualType Ty = D->getType();
  while (const clang::ParenType *PT = clang::dyn_cast<clang::ParenType>(Ty)) {
    ProtoFn = [=, ProtoFn = std::move(ProtoFn), this] (void) {
      TokenPrinterContext ctx(Out, PT, this->tokens);
      Out << '(';
      ProtoFn();
      Out << ')';
    };
    Ty = PT->getInnerType();
  }

  if (const clang::FunctionType *AFT = Ty->getAs<clang::FunctionType>()) {
    const clang::FunctionProtoType *FT = nullptr;
    if (D->hasWrittenPrototype())
      FT = clang::dyn_cast<clang::FunctionProtoType>(AFT);

    // We want to figure out if there's an explicit `void` in the declaration
    // for the parameter list.
    clang::SourceLocation uses_explicit_void;
    bool has_source_code = false;
    if (clang::TypeSourceInfo *FTSI = D->getTypeSourceInfo();
        FTSI && !D->getNumParams()) {
      if (auto FTL = FTSI->getTypeLoc().getAs<clang::FunctionTypeLoc>();
          !FTL.isNull()) {
        if (auto l_paren = FTL.getLParenLoc();
            l_paren.isValid() && l_paren.isFileID()) {
          has_source_code = true;
          clang::SourceLocation after_l_paren = l_paren.getLocWithOffset(1);
          clang::Token tok;
          if (TryLexRawToken(D->getASTContext(), after_l_paren, &tok)) {
            if (tok.getKind() == clang::tok::raw_identifier &&
                tok.getRawIdentifier() == "void") {
              uses_explicit_void = tok.getLocation();
            }
          }
        }
      }
    }

    // Try to see if the last parameter is followed by a comma before
    // the `...`. This is tricky because we might need to skip over a closing
    // parenthesis, e.g. `void foo(void (*bar)...)` or over an identifier, e.g.
    // `void foo(int bar...)`.
    auto loc_of_comma_after_param = [&] (clang::ParmVarDecl *P) -> clang::SourceLocation {
      if (!P) {
        return {};
      }
      clang::SourceLocation param_end = P->getEndLoc();
      if (!param_end.isValid() || !param_end.isFileID()) {
        return {};  // Default.
      }

      clang::Token tok;
      if (!TryLexRawToken(D->getASTContext(), param_end, &tok)) {
        return {};
      }

      auto after_param_end = tok.getLocation().getLocWithOffset(
          static_cast<int>(tok.getLength()));
      if (!TryLexRawToken(D->getASTContext(), after_param_end, &tok)) {
        return {};
      }

      if (tok.getKind() == clang::tok::comma) {
        return tok.getLocation();
      } else {
        return {};
      }
    };

//    if (FT) {
//      ProtoFn = [=, ProtoFn = std::move(ProtoFn)] (void) {
//        ProtoFn();
//        Out << '(';
//
//        if (uses_explicit_void.isValid()) {  // Does the original code use `void`?
//          Out << "void";
//          ctx.MarkLocation(uses_explicit_void);
//
//        } else if (!has_source_code && !D->getNumParams() &&
//                   SubPolicy.UseVoidForZeroParams) {
//          Out << "void";
//
//        } else {
//          DeclPrinter ParamPrinter(Out, SubPolicy, Context, tokens, Indentation);
//
//
//          bool leading_comma = true;
//          for (unsigned i = 0, e = D->getNumParams(); i != e; ++i) {
//            if (i) {
//              Out << ", ";
//            }
//            clang::ParmVarDecl *P = D->getParamDecl(i);
//            ParamPrinter.VisitParmVarDecl(P);
//            // Try to see if the last parameter is followed by a comma before
//            // the `...`.
//            if ((i + 1u) == e && FT->isVariadic()) {
//              leading_comma = variadic_leading_comma(P);
//            }
//          }
//
//          if (FT->isVariadic()) {
//            if (leading_comma && D->getNumParams()) {
//              Out << ", ";
//            }
//
//            Out << "...";
//            if (D->getEllipsisLoc().isValid()) {
//              ctx.MarkLocation(D->getEllipsisLoc());
//            } else {
//              ctx.MarkLocation(FT->getEllipsisLoc());
//            }
//          }
//        }
//        Out << ")";
//      };
//    } else if (D->doesThisDeclarationHaveABody() && !D->hasPrototype()) {
      ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
        ProtoFn();
        TokenPrinterContext jump_up_stack(ctx);
        Out << "(";

        if (uses_explicit_void.isValid()) {
          Out << "void";
          ctx.MarkLocation(uses_explicit_void);

        } else if (!has_source_code && !D->getNumParams() &&
                   SubPolicy.UseVoidForZeroParams &&
                   Context.getLangOpts().CPlusPlus) {
          Out << "void";

        } else {
          clang::ParmVarDecl *LastP = nullptr;
          for (unsigned i = 0, e = D->getNumParams(); i != e; ++i) {
            if (i) {
              Out << ", ";
              ctx.MarkLocation(loc_of_comma_after_param(LastP));
            }
            clang::ParmVarDecl *P = D->getParamDecl(i);
            DeclPrinter ParamPrinter(Out, SubPolicy, Context, tokens, Indentation);
            ParamPrinter.VisitParmVarDecl(P);
            LastP = P;
          }

          if (D->isVariadic()) {
            if (D->getNumParams()) {
              Out << ", ";
              ctx.MarkLocation(loc_of_comma_after_param(LastP));
            }
            Out << "...";
            ctx.MarkLocation(D->getEllipsisLoc());
          }
        }
        Out << ")";
      };
//    }

    if (FT) {
      ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
        ProtoFn();
        TokenPrinterContext jump_up_stack(ctx);
        if (FT->isConst())
          Out << " const";
        if (FT->isVolatile())
          Out << " volatile";
        if (FT->isRestrict())
          Out << " restrict";

        switch (FT->getRefQualifier()) {
        case clang::RQ_None:
          break;
        case clang::RQ_LValue:
          Out << " &";
          break;
        case clang::RQ_RValue:
          Out << " &&";
          break;
        }
      };
    }

    if (FT && FT->hasDynamicExceptionSpec()) {
      ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
        ProtoFn();
        TokenPrinterContext jump_up_stack(ctx);
        Out << " throw(";
        if (FT->getExceptionSpecType() == clang::EST_MSAny)
          Out << "...";
        else
          for (unsigned I = 0, N = FT->getNumExceptions(); I != N; ++I) {
            if (I)
              Out << ", ";

            TypePrinter TP(SubPolicy, this->tokens);
            TP.print(FT->getExceptionType(I), Out, "", nullptr);
          }
        Out << ")";
      };
    } else if (FT && isNoexceptExceptionSpec(FT->getExceptionSpecType())) {
      ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) {
        ProtoFn();
        TokenPrinterContext jump_up_stack(ctx);
        Out << " noexcept";
        if (isComputedNoexcept(FT->getExceptionSpecType())) {
          Out << "(";
          printPrettyStmt(FT->getNoexceptExpr(), Out,
                          nullptr, SubPolicy, Indentation);
          Out << ")";
        }
      };
    }

    if (CDecl) {
      if (!Policy.TerseOutput && !D->isPure() && !D->isDeletedAsWritten() &&
          !D->isExplicitlyDefaulted() && D->isThisDeclarationADefinition())
        PrintConstructorInitializers(ctx, CDecl, ProtoFn);
    } else if (!ConversionDecl && !clang::isa<clang::CXXDestructorDecl>(D)) {
      ProtoFn = [&, ProtoFn = std::move(ProtoFn)] (void) mutable {
        if (FT && FT->hasTrailingReturn()) {
          TokenPrinterContext jump_up_stack(ctx);
          if (!GuideDecl)
            Out << "auto ";
          ProtoFn();
          Out << " -> ";
          ProtoFn = EmtpyProtoFn;
        }

        clang::PrintingPolicy SubPolicy = Policy;
        SubPolicy.IncludeTagDefinition = false;
        printQualType(D->getDeclaredReturnType(), Out, SubPolicy, std::move(ProtoFn));
      };
    }


    ProtoFn();
    ProtoFn = EmtpyProtoFn;

    if (clang::Expr *TrailingRequiresClause = D->getTrailingRequiresClause()) {
      Out << " requires ";
      printPrettyStmt(TrailingRequiresClause, Out, nullptr, SubPolicy, Indentation);
    }
  } else {
    printQualType(Ty, Out, Policy, std::move(ProtoFn));
    ProtoFn = EmtpyProtoFn;
  }

  if (!printed_attributes) {
    prettyPrintAttributes(D);
  }

  if (D->isPure())
    Out << " = 0";
  else if (D->isDeletedAsWritten())
    Out << " = delete";
  else if (D->isExplicitlyDefaulted())
    Out << " = default";
  else if (D->doesThisDeclarationHaveABody()) {
    if (!Policy.TerseOutput) {
      if (!D->hasPrototype() && D->getNumParams()) {
        // This is a K&R function definition, so we need to print the
        // parameters.
        Out << '\n';
        DeclPrinter ParamPrinter(Out, SubPolicy, Context, tokens, Indentation);
        Indentation += Policy.Indentation;
        for (unsigned i = 0, e = D->getNumParams(); i != e; ++i) {
          Indent();
          ParamPrinter.VisitParmVarDecl(D->getParamDecl(i));
          Out << ";\n";
        }
        Indentation -= Policy.Indentation;
      } else
        Out << ' ';

      if (D->getBody()) {
        StmtPrinter stmtPrinter(Out, nullptr, tokens, SubPolicy, Indentation, "\n", &Context);
        stmtPrinter.suppress_leading_indent = true;
        stmtPrinter.Visit(D->getBody());
      }
    } else {
      if (!Policy.TerseOutput && clang::isa<clang::CXXConstructorDecl>(*D))
        Out << " {}";
    }
  }
}

void DeclPrinter::VisitFriendDecl(clang::FriendDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (clang::TypeSourceInfo *TSI = D->getFriendType()) {
    unsigned NumTPLists = D->getFriendTypeNumTemplateParameterLists();
    for (unsigned i = 0; i < NumTPLists; ++i)
      printTemplateParameters(D->getFriendTypeTemplateParameterList(i));
    Out << "friend ";
    Out << " ";
    printQualType(TSI->getType(), Out, Policy);
  }
  else if (clang::FunctionDecl *FD =
      clang::dyn_cast<clang::FunctionDecl>(D->getFriendDecl())) {
    Out << "friend ";
    VisitFunctionDecl(FD);
  }
  else if (clang::FunctionTemplateDecl *FTD =
           clang::dyn_cast<clang::FunctionTemplateDecl>(D->getFriendDecl())) {
    Out << "friend ";
    VisitFunctionTemplateDecl(FTD);
  }
  else if (clang::ClassTemplateDecl *CTD =
           clang::dyn_cast<clang::ClassTemplateDecl>(D->getFriendDecl())) {
    Out << "friend ";
    VisitRedeclarableTemplateDecl(CTD);
  }
}

void DeclPrinter::VisitFieldDecl(clang::FieldDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);

  // FIXME: add printing of pragma attributes if required.
  if (!Policy.SuppressSpecifiers && D->isMutable())
    Out << "mutable ";
  if (!Policy.SuppressSpecifiers && D->isModulePrivate())
    Out << "__module_private__ ";

  printQualType(
      D->getASTContext().getUnqualifiedObjCPointerType(D->getType()),
      Out,
      Policy,
      [&] () {
        if (auto name = D->getName(); !name.empty()) {
          TokenPrinterContext jump_up_stack(ctx);
          Out << name;
          ctx.MarkLocation(D->getLocation());
        }
      },
      Indentation);

  if (D->isBitField()) {
    Out << " : ";
    printPrettyStmt(D->getBitWidth(), Out, nullptr, Policy, Indentation);
  }

  clang::Expr *Init = D->getInClassInitializer();
  if (!Policy.SuppressInitializers && Init) {
    if (D->getInClassInitStyle() == clang::ICIS_ListInit)
      Out << " ";
    else
      Out << " = ";
    printPrettyStmt(Init, Out, nullptr, Policy, Indentation);
  }
  prettyPrintAttributes(D);
}

void DeclPrinter::VisitLabelDecl(clang::LabelDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << *D << ":";
}

void DeclPrinter::VisitVarDecl(clang::VarDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  prettyPrintPragmas(D);

  clang::QualType T = D->getTypeSourceInfo()
    ? D->getTypeSourceInfo()->getType()
    : D->getASTContext().getUnqualifiedObjCPointerType(D->getType());

  if (!Policy.SuppressSpecifiers) {
    clang::StorageClass SC = D->getStorageClass();
    if (SC != clang::SC_None)
      Out << clang::VarDecl::getStorageClassSpecifierString(SC) << " ";

    switch (D->getTSCSpec()) {
    case clang::TSCS_unspecified:
      break;
    case clang::TSCS___thread:
      Out << "__thread ";
      break;
    case clang::TSCS__Thread_local:
      Out << "_Thread_local ";
      break;
    case clang::TSCS_thread_local:
      Out << "thread_local ";
      break;
    }

    if (D->isModulePrivate())
      Out << "__module_private__ ";

    if (D->isConstexpr()) {
      Out << "constexpr ";
      T.removeLocalConst();
    }
  }

  printDeclType(T, [&] () {
    if (auto name = D->getName(); !name.empty()) {
      TokenPrinterContext jump_up_stack(ctx);
      Out << name;
      ctx.MarkLocation(D->getLocation());
    }
  });

  clang::Expr *Init = D->getInit();
  if (!Policy.SuppressInitializers && Init) {
    bool ImplicitInit = false;
    if (D->isCXXForRangeDecl()) {
      // FIXME: We should print the range expression instead.
      ImplicitInit = true;
    } else if (clang::CXXConstructExpr *Construct =
                  clang::dyn_cast<clang::CXXConstructExpr>(Init->IgnoreImplicit())) {
      if (D->getInitStyle() == clang::VarDecl::CallInit &&
          !Construct->isListInitialization()) {
        ImplicitInit = Construct->getNumArgs() == 0 ||
                       Construct->getArg(0)->isDefaultArgument();
      }
    }
    if (!ImplicitInit) {
      if ((D->getInitStyle() == clang::VarDecl::CallInit) && !clang::isa<clang::ParenListExpr>(Init))
        Out << "(";
      else if (D->getInitStyle() == clang::VarDecl::CInit) {
        Out << " = ";
      }
      clang::PrintingPolicy SubPolicy(Policy);
      SubPolicy.SuppressSpecifiers = false;
      SubPolicy.IncludeTagDefinition = false;
      printPrettyStmt(Init, Out, nullptr, SubPolicy, Indentation);
      if ((D->getInitStyle() == clang::VarDecl::CallInit) && !clang::isa<clang::ParenListExpr>(Init))
        Out << ")";
    }
  }
  prettyPrintAttributes(D);
}

void DeclPrinter::VisitParmVarDecl(clang::ParmVarDecl *D) {
  VisitVarDecl(D);
}

void DeclPrinter::VisitFileScopeAsmDecl(clang::FileScopeAsmDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "__asm (";
  printPrettyStmt(D->getAsmString(), Out, nullptr, Policy, Indentation);
  Out << ")";
  ctx.MarkLocation(D->getRParenLoc());
}

void DeclPrinter::VisitImportDecl(clang::ImportDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "@import " << D->getImportedModule()->getFullModuleName()
      << ";\n";
}

void DeclPrinter::VisitStaticAssertDecl(clang::StaticAssertDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "static_assert(";
  printPrettyStmt(D->getAssertExpr(), Out, nullptr, Policy, Indentation);
  if (clang::StringLiteral *SL = D->getMessage()) {
    Out << ", ";
    printPrettyStmt(SL, Out, nullptr, Policy, Indentation);
  }
  Out << ")";
  ctx.MarkLocation(D->getRParenLoc());
}

//----------------------------------------------------------------------------
// C++ declarations
//----------------------------------------------------------------------------
void DeclPrinter::VisitNamespaceDecl(clang::NamespaceDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (D->isInline())
    Out << "inline ";

  Out << "namespace ";
  if (D->getDeclName())
    Out << D->getDeclName() << ' ';
  Out << "{\n";

  VisitDeclContext(D);
  Indent() << "}";
  ctx.MarkLocation(D->getRBraceLoc());
}

void DeclPrinter::VisitUsingDirectiveDecl(clang::UsingDirectiveDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "using";
  ctx.MarkLocation(D->getUsingLoc());
  Out << "namespace ";
  ctx.MarkLocation(D->getNamespaceKeyLocation());
  if (D->getQualifier()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    D->getQualifier()->print(Out, Policy);
  }
  Out << *D->getNominatedNamespaceAsWritten();
}

void DeclPrinter::VisitNamespaceAliasDecl(clang::NamespaceAliasDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "namespace ";
  ctx.MarkLocation(D->getNamespaceLoc());
  Out << *D;
  ctx.MarkLocation(D->getAliasLoc());
  Out << " = ";
  if (D->getQualifier()) {
    TagDefinitionPolicyRAII disable_tags(Policy);
    D->getQualifier()->print(Out, Policy);
  }
  Out << *D->getAliasedNamespace();
}

void DeclPrinter::VisitEmptyDecl(clang::EmptyDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  prettyPrintAttributes(D);
}

void DeclPrinter::VisitCXXRecordDecl(clang::CXXRecordDecl *D) {
  // FIXME: add printing of pragma attributes if required.
  TokenPrinterContext ctx(Out, D, tokens);

  auto printed_tag = (Policy.IncludeTagDefinition || !D->getIdentifier()) &&
                     Out.printed_defs.emplace(D).second;

  if (!Policy.SuppressSpecifiers && D->isModulePrivate())
    Out << "__module_private__ ";
  Out << D->getKindName();

  prettyPrintAttributes(D);

  if (D->getIdentifier()) {
    Out << ' ' << *D;

    if (auto S = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(D)) {
      TokenPrinterContext ctx(Out, S, tokens);
      clang::ArrayRef<clang::TemplateArgument> Args = S->getTemplateArgs().asArray();
      if (!Policy.PrintCanonicalTypes)
        if (const auto* TSI = S->getTypeAsWritten())
          if (const auto *TST =
                  clang::dyn_cast<clang::TemplateSpecializationType>(TSI->getType()))
            Args = TST->template_arguments();
      printTemplateArguments(Args, S->getSpecializedTemplate()->getTemplateParameters(), false);
    }
  }

  if (D->hasDefinition()) {
    if (D->hasAttr<clang::FinalAttr>()) {
      Out << " final";
    }
  }

  if (D->isCompleteDefinition() && printed_tag) {
    for (auto R : D->redecls()) {
      Out.printed_defs.emplace(R);
    }

    // Print the base classes
    if (D->getNumBases()) {
      Out << " : ";
      for (clang::CXXRecordDecl::base_class_iterator Base = D->bases_begin(),
             BaseEnd = D->bases_end(); Base != BaseEnd; ++Base) {
        if (Base != D->bases_begin())
          Out << ", ";

        if (Base->isVirtual())
          Out << "virtual ";

        clang::AccessSpecifier AS = Base->getAccessSpecifierAsWritten();
        if (AS != clang::AS_none) {
          Print(AS);
          Out << " ";
        }

        printQualType(Base->getType(), Out, Policy);

        if (Base->isPackExpansion()) {
          Out << "...";
          ctx.MarkLocation(Base->getEllipsisLoc());
        }
      }
    }

    // Print the class definition
    // FIXME: Doesn't print access specifiers, e.g., "public:"
    if (Policy.TerseOutput) {
      Out << " {";
      ctx.MarkLocation(D->getBraceRange().getBegin());
      Out << "}";
      ctx.MarkLocation(D->getBraceRange().getEnd());
    } else {
      Out << " {";
      ctx.MarkLocation(D->getBraceRange().getBegin());
      Out << "\n";
      VisitDeclContext(D);
      Indent() << "}";
      ctx.MarkLocation(D->getBraceRange().getEnd());
    }
  }
}

void DeclPrinter::VisitLinkageSpecDecl(clang::LinkageSpecDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  const char *l;
  if (D->getLanguage() == clang::LinkageSpecDecl::lang_c)
    l = "C";
  else {
    assert(D->getLanguage() == clang::LinkageSpecDecl::lang_cxx &&
           "unknown language in linkage specification");
    l = "C++";
  }

  Out << "extern";
  ctx.MarkLocation(D->getExternLoc());
  Out << " \"" << l << "\" ";
  if (D->hasBraces()) {
    Out << "{\n";
    VisitDeclContext(D);
    Indent() << "}";
    ctx.MarkLocation(D->getRBraceLoc());
  } else
    Visit(*D->decls_begin());
}

void DeclPrinter::printTemplateParameters(const clang::TemplateParameterList *Params,
                                          bool OmitTemplateKW) {
  TokenPrinterContext ctx(Out, Params, tokens);

  assert(Params);

  if (!OmitTemplateKW) {
    Out << "template ";
    ctx.MarkLocation(Params->getTemplateLoc());
  }
  Out << '<';
  ctx.MarkLocation(Params->getLAngleLoc());

  bool NeedComma = false;
  for (const clang::Decl *Param : *Params) {
    if (Param->isImplicit())
      continue;

    if (NeedComma)
      Out << ", ";
    else
      NeedComma = true;

    if (const auto *TTP = clang::dyn_cast<clang::TemplateTypeParmDecl>(Param)) {
      VisitTemplateTypeParmDecl(TTP);
    } else if (auto NTTP = clang::dyn_cast<clang::NonTypeTemplateParmDecl>(Param)) {
      VisitNonTypeTemplateParmDecl(NTTP);
    } else if (auto TTPD = clang::dyn_cast<clang::TemplateTemplateParmDecl>(Param)) {
      VisitTemplateDecl(TTPD);
      // FIXME: print the default argument, if present.
    }
  }
  ctx.Tokenize();
  Out << '>';
  ctx.MarkLocation(Params->getRAngleLoc());
  if (!OmitTemplateKW)
    Out << ' ';
}

void DeclPrinter::printTemplateArguments(llvm::ArrayRef<clang::TemplateArgument> Args,
                                         const clang::TemplateParameterList *Params,
                                         bool TemplOverloaded) {
  TagDefinitionPolicyRAII tag_raii(Policy);

  Out << "<";
  for (size_t I = 0, E = Args.size(); I < E; ++I) {
    if (I)
      Out << ", ";
    
    TokenPrinterContext ctx(Out, &(Args[I]), tokens);
    if (TemplOverloaded || !Params)
      Args[I].print(Policy, Out, /*IncludeType*/ true);
    else
      Args[I].print(
          Policy, Out,
          clang::TemplateParameterList::shouldIncludeTypeForArgument(
              Policy, Params, static_cast<unsigned int>(I)));
  }
  Out << ">";
}

void DeclPrinter::printTemplateArguments(llvm::ArrayRef<clang::TemplateArgumentLoc> Args,
                                         const clang::TemplateParameterList *Params,
                                         bool TemplOverloaded) {
  TagDefinitionPolicyRAII tag_raii(Policy);

  Out << "<";
  for (size_t I = 0, E = Args.size(); I < E; ++I) {
    if (I)
      Out << ", ";

    TokenPrinterContext ctx(Out, &(Args[I].getArgument()), tokens);
    if (TemplOverloaded)
      Args[I].getArgument().print(Policy, Out, /*IncludeType*/ true);
    else
      Args[I].getArgument().print(
          Policy, Out,
          clang::TemplateParameterList::shouldIncludeTypeForArgument(
              Policy, Params, static_cast<unsigned int>(I)));
  }
  Out << ">";
}

void DeclPrinter::VisitTemplateDecl(const clang::TemplateDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  printTemplateParameters(D->getTemplateParameters());

  if (const clang::TemplateTemplateParmDecl *TTP =
        clang::dyn_cast<clang::TemplateTemplateParmDecl>(D)) {
    Out << "class";

    if (TTP->isParameterPack())
      Out << " ...";
    else if (TTP->getDeclName())
      Out << ' ';

    if (TTP->getDeclName())
      Out << TTP->getDeclName();
  } else if (auto *TD = D->getTemplatedDecl())
    Visit(TD);
  else if (const auto *Concept = clang::dyn_cast<clang::ConceptDecl>(D)) {
    Out << "concept " << Concept->getName();
    ctx.MarkLocation(Concept->getLocation());
    Out << " = " ;
    printPrettyStmt(Concept->getConstraintExpr(), Out, nullptr, Policy, Indentation);
    Out << ";";
  }
}

void DeclPrinter::VisitFunctionTemplateDecl(clang::FunctionTemplateDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  prettyPrintPragmas(D->getTemplatedDecl());
  // Print any leading template parameter lists.
  if (const clang::FunctionDecl *FD = D->getTemplatedDecl()) {
    for (unsigned I = 0, NumTemplateParams = FD->getNumTemplateParameterLists();
         I < NumTemplateParams; ++I)
      printTemplateParameters(FD->getTemplateParameterList(I));
  }
  VisitRedeclarableTemplateDecl(D);
  // Declare target attribute is special one, natural spelling for the pragma
  // assumes "ending" construct so print it here.
  if (D->getTemplatedDecl()->hasAttr<clang::OMPDeclareTargetDeclAttr>())
    Out << "#pragma omp end declare target\n";

  // Never print "instantiations" for deduction guides (they don't really
  // have them).
  if (PrintInstantiation &&
      !clang::isa<clang::CXXDeductionGuideDecl>(D->getTemplatedDecl())) {
    clang::FunctionDecl *PrevDecl = D->getTemplatedDecl();
    const clang::FunctionDecl *Def;
    if (PrevDecl->isDefined(Def) && Def != PrevDecl)
      return;
    for (auto *I : D->specializations())
      if (I->getTemplateSpecializationKind() == clang::TSK_ImplicitInstantiation) {
        if (!PrevDecl->isThisDeclarationADefinition())
          Out << ";\n";
        Indent();
        prettyPrintPragmas(I);
        Visit(I);
      }
  }
}

void DeclPrinter::VisitClassTemplateDecl(clang::ClassTemplateDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  VisitRedeclarableTemplateDecl(D);

  if (PrintInstantiation) {
    for (auto *I : D->specializations())
      if (I->getSpecializationKind() == clang::TSK_ImplicitInstantiation) {
        if (D->isThisDeclarationADefinition())
          Out << ";";
        Out << "\n";
        Visit(I);
      }
  }
}

void DeclPrinter::VisitClassTemplateSpecializationDecl(clang::ClassTemplateSpecializationDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "template";
  ctx.MarkLocation(D->getTemplateKeywordLoc());
  Out << " <> ";
  VisitCXXRecordDecl(D);
}

void DeclPrinter::VisitClassTemplatePartialSpecializationDecl(clang::ClassTemplatePartialSpecializationDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  printTemplateParameters(D->getTemplateParameters());
  VisitCXXRecordDecl(D);
}

//----------------------------------------------------------------------------
// Objective-C declarations
//----------------------------------------------------------------------------

void DeclPrinter::PrintObjCMethodType(clang::ASTContext &Ctx,
                                      clang::Decl::ObjCDeclQualifier Quals,
                                      clang::QualType T) {
  //DeclPrinterContext ctx(Out, Quals);
  Out << '(';
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_In)
    Out << "in ";
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_Inout)
    Out << "inout ";
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_Out)
    Out << "out ";
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_Bycopy)
    Out << "bycopy ";
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_Byref)
    Out << "byref ";
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_Oneway)
    Out << "oneway ";
  if (Quals & clang::Decl::ObjCDeclQualifier::OBJC_TQ_CSNullability) {
    if (auto nullability = clang::AttributedType::stripOuterNullability(T))
      Out << getNullabilitySpelling(*nullability, true) << ' ';
  }
  printQualType(Ctx.getUnqualifiedObjCPointerType(T), Out, Policy);
  Out << ')';
}

void DeclPrinter::PrintObjCTypeParams(clang::ObjCTypeParamList *Params) {
  //DeclPrinterContext ctx(Out, Params);
  Out << "<";
  TagDefinitionPolicyRAII tag_raii(Policy);
  unsigned First = true;
  for (auto *Param : *Params) {
    if (First) {
      First = false;
    } else {
      Out << ", ";
    }

    switch (Param->getVariance()) {
    case clang::ObjCTypeParamVariance::Invariant:
      break;

    case clang::ObjCTypeParamVariance::Covariant:
      Out << "__covariant ";
      break;

    case clang::ObjCTypeParamVariance::Contravariant:
      Out << "__contravariant ";
      break;
    }

    Out << Param->getDeclName();

    if (Param->hasExplicitBound()) {
      Out << " : ";
      printQualType(Param->getUnderlyingType(), Out, Policy);
    }
  }
  Out << ">";
}

void DeclPrinter::VisitObjCMethodDecl(clang::ObjCMethodDecl *OMD) {
  TokenPrinterContext ctx(Out, OMD, tokens);
  if (OMD->isInstanceMethod())
    Out << "- ";
  else
    Out << "+ ";
  if (!OMD->getReturnType().isNull()) {
    PrintObjCMethodType(OMD->getASTContext(), OMD->getObjCDeclQualifier(),
                        OMD->getReturnType());
  }

  std::string name = OMD->getSelector().getAsString();
  std::string::size_type pos, lastPos = 0;
  for (const auto *PI : OMD->parameters()) {
    // FIXME: selector is missing here!
    pos = name.find_first_of(':', lastPos);
    if (lastPos != 0)
      Out << " ";
    Out << name.substr(lastPos, pos - lastPos) << ':';
    PrintObjCMethodType(OMD->getASTContext(),
                        PI->getObjCDeclQualifier(),
                        PI->getType());
    Out << *PI;
    lastPos = pos + 1;
  }

  if (OMD->param_begin() == OMD->param_end())
    Out << name;

  if (OMD->isVariadic())
      Out << ", ...";

  prettyPrintAttributes(OMD);

  if (OMD->getBody() && !Policy.TerseOutput) {
    Out << ' ';
    printPrettyStmt(OMD->getBody(), Out, nullptr, Policy);
  }
  else if (Policy.PolishForDeclaration)
    Out << ';';

  ctx.MarkLocation(OMD->getDeclaratorEndLoc());
}

void DeclPrinter::VisitObjCImplementationDecl(clang::ObjCImplementationDecl *OID) {
  TokenPrinterContext ctx(Out, OID, tokens);
  std::string I = OID->getNameAsString();
  clang::ObjCInterfaceDecl *SID = OID->getSuperClass();

  bool eolnOut = false;
  if (SID)
    Out << "@implementation " << I << " : " << *SID;
  else
    Out << "@implementation " << I;

  if (OID->ivar_size() > 0) {
    Out << "{\n";
    eolnOut = true;
    Indentation += Policy.Indentation;
    for (const auto *I : OID->ivars()) {
      Indent();
      printQualType(
          I->getASTContext().getUnqualifiedObjCPointerType(I->getType()),
          Out, Policy);
      Out << ' ' << *I << ";\n";
    }
    Indentation -= Policy.Indentation;
    Out << "}\n";
  }
  else if (SID || (OID->decls_begin() != OID->decls_end())) {
    Out << "\n";
    eolnOut = true;
  }
  VisitDeclContext(OID, false);
  if (!eolnOut)
    Out << "\n";
  Out << "@end";
}

void DeclPrinter::VisitObjCInterfaceDecl(clang::ObjCInterfaceDecl *OID) {
  TokenPrinterContext ctx(Out, OID, tokens);
  std::string I = OID->getNameAsString();
  clang::ObjCInterfaceDecl *SID = OID->getSuperClass();

  if (!OID->isThisDeclarationADefinition()) {
    Out << "@class " << I;

    if (auto TypeParams = OID->getTypeParamListAsWritten()) {
      PrintObjCTypeParams(TypeParams);
    }

    Out << ";";
    return;
  }
  bool eolnOut = false;
  Out << "@interface " << I;

  if (auto TypeParams = OID->getTypeParamListAsWritten()) {
    PrintObjCTypeParams(TypeParams);
  }

  if (SID) {
    Out << " : ";
    printQualType(clang::QualType(OID->getSuperClassType(), 0), Out, Policy);
  }

  // Protocols?
  const clang::ObjCList<clang::ObjCProtocolDecl> &Protocols = OID->getReferencedProtocols();
  if (!Protocols.empty()) {
    for (clang::ObjCList<clang::ObjCProtocolDecl>::iterator I = Protocols.begin(),
         E = Protocols.end(); I != E; ++I)
      Out << (I == Protocols.begin() ? '<' : ',') << **I;
    Out << "> ";
  }

  if (OID->ivar_size() > 0) {
    Out << "{\n";
    eolnOut = true;
    Indentation += Policy.Indentation;
    for (const auto *I : OID->ivars()) {
      Indent();
      printQualType(
          I->getASTContext().getUnqualifiedObjCPointerType(I->getType()),
          Out, Policy);
      Out << ' ' << *I << ";\n";
    }
    Indentation -= Policy.Indentation;
    Out << "}\n";
  }
  else if (SID || (OID->decls_begin() != OID->decls_end())) {
    Out << "\n";
    eolnOut = true;
  }

  VisitDeclContext(OID, false);
  if (!eolnOut)
    Out << "\n";
  Out << "@end";
  // FIXME: implement the rest...
}

void DeclPrinter::VisitObjCProtocolDecl(clang::ObjCProtocolDecl *PID) {
  TokenPrinterContext ctx(Out, PID, tokens);
  if (!PID->isThisDeclarationADefinition()) {
    Out << "@protocol " << *PID << ";\n";
    return;
  }
  // Protocols?
  const clang::ObjCList<clang::ObjCProtocolDecl> &Protocols = PID->getReferencedProtocols();
  if (!Protocols.empty()) {
    Out << "@protocol " << *PID;
    for (clang::ObjCList<clang::ObjCProtocolDecl>::iterator I = Protocols.begin(),
         E = Protocols.end(); I != E; ++I)
      Out << (I == Protocols.begin() ? '<' : ',') << **I;
    Out << ">\n";
  } else
    Out << "@protocol " << *PID << '\n';
  VisitDeclContext(PID, false);
  Out << "@end";
}

void DeclPrinter::VisitObjCCategoryImplDecl(clang::ObjCCategoryImplDecl *PID) {
  TokenPrinterContext ctx(Out, PID, tokens);
  Out << "@implementation ";
  if (const auto *CID = PID->getClassInterface())
    Out << *CID;
  else
    Out << "<<error-type>>";
  Out << '(' << *PID << ")\n";

  VisitDeclContext(PID, false);
  Out << "@end";
  // FIXME: implement the rest...
}

void DeclPrinter::VisitObjCCategoryDecl(clang::ObjCCategoryDecl *PID) {
  TokenPrinterContext ctx(Out, PID, tokens);
  Out << "@interface ";
  if (const auto *CID = PID->getClassInterface())
    Out << *CID;
  else
    Out << "<<error-type>>";
  if (auto TypeParams = PID->getTypeParamList()) {
    PrintObjCTypeParams(TypeParams);
  }
  Out << "(" << *PID << ")\n";
  if (PID->ivar_size() > 0) {
    Out << "{\n";
    Indentation += Policy.Indentation;
    for (const auto *I : PID->ivars()) {
      Indent();
      printQualType(
          I->getASTContext().getUnqualifiedObjCPointerType(I->getType()),
          Out, Policy);
      Out << ' ' << *I << ";\n";
    }
    Indentation -= Policy.Indentation;
    Out << "}\n";
  }

  VisitDeclContext(PID, false);
  Out << "@end";

  // FIXME: implement the rest...
}

void DeclPrinter::VisitObjCCompatibleAliasDecl(clang::ObjCCompatibleAliasDecl *AID) {
  TokenPrinterContext ctx(Out, AID, tokens);
  Out << "@compatibility_alias " << *AID
      << ' ' << *AID->getClassInterface() << ";\n";
}

/// PrintObjCPropertyDecl - print a property declaration.
///
/// Print attributes in the following order:
/// - class
/// - nonatomic | atomic
/// - assign | retain | strong | copy | weak | unsafe_unretained
/// - readwrite | readonly
/// - getter & setter
/// - nullability
void DeclPrinter::VisitObjCPropertyDecl(clang::ObjCPropertyDecl *PDecl) {
  TokenPrinterContext ctx(Out, PDecl, tokens);
  if (PDecl->getPropertyImplementation() == clang::ObjCPropertyDecl::Required)
    Out << "@required\n";
  else if (PDecl->getPropertyImplementation() == clang::ObjCPropertyDecl::Optional)
    Out << "@optional\n";

  clang::QualType T = PDecl->getType();

  Out << "@property";
  if (PDecl->getPropertyAttributes() != clang::ObjCPropertyAttribute::kind_noattr) {
    bool first = true;
    Out << "(";
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_class) {
      Out << (first ? "" : ", ") << "class";
      first = false;
    }

    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_direct) {
      Out << (first ? "" : ", ") << "direct";
      first = false;
    }

    if (PDecl->getPropertyAttributes() &
        clang::ObjCPropertyAttribute::kind_nonatomic) {
      Out << (first ? "" : ", ") << "nonatomic";
      first = false;
    }
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_atomic) {
      Out << (first ? "" : ", ") << "atomic";
      first = false;
    }

    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_assign) {
      Out << (first ? "" : ", ") << "assign";
      first = false;
    }
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_retain) {
      Out << (first ? "" : ", ") << "retain";
      first = false;
    }

    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_strong) {
      Out << (first ? "" : ", ") << "strong";
      first = false;
    }
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_copy) {
      Out << (first ? "" : ", ") << "copy";
      first = false;
    }
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_weak) {
      Out << (first ? "" : ", ") << "weak";
      first = false;
    }
    if (PDecl->getPropertyAttributes() &
        clang::ObjCPropertyAttribute::kind_unsafe_unretained) {
      Out << (first ? "" : ", ") << "unsafe_unretained";
      first = false;
    }

    if (PDecl->getPropertyAttributes() &
        clang::ObjCPropertyAttribute::kind_readwrite) {
      Out << (first ? "" : ", ") << "readwrite";
      first = false;
    }
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_readonly) {
      Out << (first ? "" : ", ") << "readonly";
      first = false;
    }

    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_getter) {
      Out << (first ? "" : ", ") << "getter = ";
      PDecl->getGetterName().print(Out);
      first = false;
    }
    if (PDecl->getPropertyAttributes() & clang::ObjCPropertyAttribute::kind_setter) {
      Out << (first ? "" : ", ") << "setter = ";
      PDecl->getSetterName().print(Out);
      first = false;
    }

    if (PDecl->getPropertyAttributes() &
        clang::ObjCPropertyAttribute::kind_nullability) {
      if (auto nullability = clang::AttributedType::stripOuterNullability(T)) {
        if (*nullability == clang::NullabilityKind::Unspecified &&
            (PDecl->getPropertyAttributes() &
                clang::ObjCPropertyAttribute::kind_null_resettable)) {
          Out << (first ? "" : ", ") << "null_resettable";
        } else {
          Out << (first ? "" : ", ")
              << getNullabilitySpelling(*nullability, true);
        }
        first = false;
      }
    }

    (void) first; // Silence dead store warning due to idiomatic code.
    Out << ")";
  }
  std::string TypeStr = PDecl->getASTContext().getUnqualifiedObjCPointerType(T).
      getAsString(Policy);

  Out << ' ';
  printQualType(
      PDecl->getASTContext().getUnqualifiedObjCPointerType(T),
      Out, Policy);

  if (!clang::StringRef(TypeStr).endswith("*"))
    Out << ' ';
  Out << *PDecl;
  if (Policy.PolishForDeclaration)
    Out << ';';
}

void DeclPrinter::VisitObjCPropertyImplDecl(clang::ObjCPropertyImplDecl *PID) {
  TokenPrinterContext ctx(Out, PID, tokens);
  if (PID->getPropertyImplementation() == clang::ObjCPropertyImplDecl::Synthesize)
    Out << "@synthesize ";
  else
    Out << "@dynamic ";
  Out << *PID->getPropertyDecl();
  if (PID->getPropertyIvarDecl())
    Out << '=' << *PID->getPropertyIvarDecl();
}

void DeclPrinter::VisitUsingDecl(clang::UsingDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (!D->isAccessDeclaration()) {
    Out << "using ";
    ctx.MarkLocation(D->getUsingLoc());
  }
  if (D->hasTypename())
    Out << "typename ";

  {
    TagDefinitionPolicyRAII disable_tags(Policy);
    D->getQualifier()->print(Out, Policy);
  }
  // Use the correct record name when the using declaration is used for
  // inheriting constructors.
  for (const auto *Shadow : D->shadows()) {
    if (const auto *ConstructorShadow =
            clang::dyn_cast<clang::ConstructorUsingShadowDecl>(Shadow)) {
      assert(Shadow->getDeclContext() == ConstructorShadow->getDeclContext());
      Out << *ConstructorShadow->getNominatedBaseClass();
      return;
    }
  }
  Out << *D;
}

void DeclPrinter::VisitUsingEnumDecl(clang::UsingEnumDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "using enum " << D->getEnumDecl();
}

void
DeclPrinter::VisitUnresolvedUsingTypenameDecl(clang::UnresolvedUsingTypenameDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "using ";
  ctx.MarkLocation(D->getUsingLoc());
  Out << "typename ";
  ctx.MarkLocation(D->getTypenameLoc());

  TagDefinitionPolicyRAII disable_tags(Policy);
  D->getQualifier()->print(Out, Policy);
  Out << D->getDeclName();
}

void DeclPrinter::VisitUnresolvedUsingValueDecl(clang::UnresolvedUsingValueDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (!D->isAccessDeclaration()) {
    Out << "using ";
    ctx.MarkLocation(D->getUsingLoc());
  }

  TagDefinitionPolicyRAII disable_tags(Policy);
  D->getQualifier()->print(Out, Policy);
  Out << D->getDeclName();
}

void DeclPrinter::VisitUsingShadowDecl(clang::UsingShadowDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  // ignore
}

void DeclPrinter::VisitOMPThreadPrivateDecl(clang::OMPThreadPrivateDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "#pragma omp threadprivate";
  if (!D->varlist_empty()) {
    for (clang::OMPThreadPrivateDecl::varlist_iterator I = D->varlist_begin(),
                                                E = D->varlist_end();
                                                I != E; ++I) {
      Out << (I == D->varlist_begin() ? '(' : ',');
      auto DRE = clang::cast<clang::DeclRefExpr>(*I);
      TokenPrinterContext ctx2(Out, DRE, tokens);
      clang::NamedDecl *ND = DRE->getDecl();
      TokenPrinterContext ctx3(Out, ND, tokens);
      ND->printQualifiedName(Out);
    }
    Out << ")";
  }
}

void DeclPrinter::VisitOMPAllocateDecl(clang::OMPAllocateDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "#pragma omp allocate";
  if (!D->varlist_empty()) {
    for (clang::OMPAllocateDecl::varlist_iterator I = D->varlist_begin(),
                                           E = D->varlist_end();
         I != E; ++I) {
      Out << (I == D->varlist_begin() ? '(' : ',');
      auto DRE = clang::cast<clang::DeclRefExpr>(*I);
      TokenPrinterContext ctx2(Out, DRE, tokens);
      clang::NamedDecl *ND = DRE->getDecl();
      TokenPrinterContext ctx3(Out, ND, tokens);
      ND->printQualifiedName(Out);
    }
    Out << ")";
  }
  if (!D->clauselist_empty()) {
    Out << " ";
    clang::OMPClausePrinter Printer(Out, Policy);
    for (clang::OMPClause *C : D->clauselists())
      Printer.Visit(C);
  }
}

void DeclPrinter::VisitOMPRequiresDecl(clang::OMPRequiresDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  Out << "#pragma omp requires ";
  if (!D->clauselist_empty()) {
    clang::OMPClausePrinter Printer(Out, Policy);
    for (auto I = D->clauselist_begin(), E = D->clauselist_end(); I != E; ++I)
      Printer.Visit(*I);
  }
}

void DeclPrinter::VisitOMPDeclareReductionDecl(clang::OMPDeclareReductionDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (!D->isInvalidDecl()) {
    Out << "#pragma omp declare reduction (";
    if (D->getDeclName().getNameKind() == clang::DeclarationName::CXXOperatorName) {
      const char *OpName =
          getOperatorSpelling(D->getDeclName().getCXXOverloadedOperator());
      assert(OpName && "not an overloaded operator");
      Out << OpName;
    } else {
      assert(D->getDeclName().isIdentifier());
      D->printName(Out);
    }
    Out << " : ";
    printQualType(D->getType(), Out, Policy);
    Out << " : ";
    printPrettyStmt(D->getCombiner(), Out, nullptr, Policy, 0);
    Out << ")";
    if (auto *Init = D->getInitializer()) {
      Out << " initializer(";
      switch (D->getInitializerKind()) {
      case clang::OMPDeclareReductionDecl::DirectInit:
        Out << "omp_priv(";
        break;
      case clang::OMPDeclareReductionDecl::CopyInit:
        Out << "omp_priv = ";
        break;
      case clang::OMPDeclareReductionDecl::CallInit:
        break;
      }
      printPrettyStmt(Init, Out, nullptr, Policy, 0);
      if (D->getInitializerKind() == clang::OMPDeclareReductionDecl::DirectInit)
        Out << ")";
      Out << ")";
    }
  }
}

void DeclPrinter::VisitOMPDeclareMapperDecl(clang::OMPDeclareMapperDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  if (!D->isInvalidDecl()) {
    Out << "#pragma omp declare mapper (";
    D->printName(Out);
    Out << " : ";
    printQualType(D->getType(), Out, Policy);
    Out << " ";
    Out << D->getVarName();
    Out << ")";
    if (!D->clauselist_empty()) {
      clang::OMPClausePrinter Printer(Out, Policy);
      for (auto *C : D->clauselists()) {
        Out << " ";
        Printer.Visit(C);
      }
    }
  }
}

void DeclPrinter::VisitOMPCapturedExprDecl(clang::OMPCapturedExprDecl *D) {
  TokenPrinterContext ctx(Out, D, tokens);
  printPrettyStmt(D->getInit(), Out, nullptr, Policy, Indentation);
}

void DeclPrinter::VisitTemplateTypeParmDecl(const clang::TemplateTypeParmDecl *TTP) {
  TokenPrinterContext ctx(Out, TTP, tokens);
  if (const clang::TypeConstraint *TC = TTP->getTypeConstraint()) {
    TokenPrinterContext ctx(Out, TC, tokens);
    TagDefinitionPolicyRAII disable_tags(Policy);
    TC->print(Out, Policy);
  }
  else if (TTP->wasDeclaredWithTypename())
    Out << "typename";
  else
    Out << "class";

  if (TTP->isParameterPack())
    Out << " ...";
  else if (TTP->getDeclName())
    Out << ' ';

  if (TTP->getDeclName())
    Out << TTP->getDeclName();

  if (TTP->hasDefaultArgument()) {
    Out << " = ";
    {
      TypePrinter printer(Policy, tokens, 0);
      printer.print(TTP->getDefaultArgument(), Out, "", nullptr);
    }
  }
}

void DeclPrinter::VisitNonTypeTemplateParmDecl(
    const clang::NonTypeTemplateParmDecl *NTTP) {
  TokenPrinterContext ctx(Out, NTTP, tokens);
  clang::StringRef Name;
  if (clang::IdentifierInfo *II = NTTP->getIdentifier())
    Name = II->getName();

  printDeclType(
      NTTP->getType(),
      [&, Name = std::move(Name)] () {
        if (!Name.empty()) {
          TokenPrinterContext jump_up_stack(ctx);
          Out << Name;
          ctx.MarkLocation(NTTP->getLocation());
        }
      },
      NTTP->isParameterPack());

  if (NTTP->hasDefaultArgument()) {
    Out << " = ";
    printPrettyStmt(NTTP->getDefaultArgument(), Out, nullptr, Policy, Indentation);
  }
}

// NOTE(pag): This will be in llvm16 I think.
//void DeclPrinter::VisitHLSLBufferDecl(clang::HLSLBufferDecl *D) {
//  TokenPrinterContext ctx(Out, D, tokens);
//  if (D->isCBuffer())
//    Out << "cbuffer ";
//  else
//    Out << "tbuffer ";
//
//  Out << *D;
//
//  prettyPrintAttributes(D);
//
//  Out << " {\n";
//  VisitDeclContext(D);
//  Indent() << "}";
//}

PrintedTokenRange PrintedTokenRange::Create(clang::ASTContext &context,
                                            const clang::PrintingPolicy &policy,
                                            clang::Decl *decl) {
  std::string data;
  raw_string_ostream out(data, 0);
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);

  if (decl) {
    DeclPrinter printer(out, policy, context, *tokens);
    printer.Visit(decl);
  }

  auto num_tokens = tokens->tokens.size();
  if (!num_tokens) {
    return PrintedTokenRange(std::move(tokens));
  } else {
    auto first = &(tokens->tokens[0]);
    auto after_last = &(first[num_tokens]);
    return PrintedTokenRange(std::move(tokens), first, after_last);
  }
}

PrintedTokenRange PrintedTokenRange::Create(const std::shared_ptr<ASTImpl> &ast,
                                            clang::Decl *decl) {
  std::string data;
  raw_string_ostream out(data, 0);
  auto &context = ast->tu->getASTContext();
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);
  tokens->ast = ast;

  if (decl) {
    clang::PrintingPolicy pp = *(ast->printing_policy);
    DeclPrinter printer(out, pp, context, *tokens);
    printer.Visit(decl);
  }

  auto num_tokens = tokens->tokens.size();
  if (!num_tokens) {
    return PrintedTokenRange(std::move(tokens));
  } else {
    auto first = &(tokens->tokens[0]);
    auto after_last = &(first[num_tokens]);
    return PrintedTokenRange(std::move(tokens), first, after_last);
  }
}

}  // namespace pasta
