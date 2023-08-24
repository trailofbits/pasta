//===- TypePrinter.cpp - Pretty-Print Clang Types -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This contains code to print types from Clang's type system.
//
//===----------------------------------------------------------------------===//

#include "DeclStmtPrinter.h"

namespace pasta {

/// RAII object that enables printing of the ARC __strong lifetime
/// qualifier.
class IncludeStrongLifetimeRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

 public:
  explicit IncludeStrongLifetimeRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy),
        Old(Policy.SuppressStrongLifetime) {
    if (!Policy.SuppressLifetimeQualifiers)
      Policy.SuppressStrongLifetime = false;
  }

  ~IncludeStrongLifetimeRAII() {
    Policy.SuppressStrongLifetime = Old;
  }
};

class ParamPolicyRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

 public:
  explicit ParamPolicyRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy),
        Old(Policy.SuppressSpecifiers) {
    Policy.SuppressSpecifiers = false;
  }

  ~ParamPolicyRAII() {
    Policy.SuppressSpecifiers = Old;
  }
};

class DefaultTemplateArgsPolicyRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

public:
  explicit DefaultTemplateArgsPolicyRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy), Old(Policy.SuppressDefaultTemplateArgs) {
    Policy.SuppressDefaultTemplateArgs = false;
  }

  ~DefaultTemplateArgsPolicyRAII() {
    Policy.SuppressDefaultTemplateArgs = Old;
  }
};

class ElaboratedTypePolicyRAII {
  clang::PrintingPolicy &Policy;
  bool SuppressTagKeyword;
  bool SuppressScope;

 public:
  explicit ElaboratedTypePolicyRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy) {
    SuppressTagKeyword = Policy.SuppressTagKeyword;
    SuppressScope = Policy.SuppressScope;
    Policy.SuppressTagKeyword = true;
    Policy.SuppressScope = true;
  }

  ~ElaboratedTypePolicyRAII() {
    Policy.SuppressTagKeyword = SuppressTagKeyword;
    Policy.SuppressScope = SuppressScope;
  }
};

/// A utility class that uses RAII to save and restore the value of a variable.
template<typename T>
struct SaveAndRestore {
  SaveAndRestore(T &X)
      : X(X),
        OldValue(X) {}

  SaveAndRestore(T &X, const T &NewValue)
      : X(X),
        OldValue(X) {
    X = NewValue;
  }
  ~SaveAndRestore() {
    X = OldValue;
  }
  T get() {
    return OldValue;
  }

 private:
  T &X;
  T OldValue;
};

static void AppendTypeQualList(pasta::raw_string_ostream &OS, unsigned TypeQuals,
                               bool HasRestrictKeyword) {
  bool appendSpace = false;
  if (TypeQuals & clang::Qualifiers::Const) {
    OS << "const";
    appendSpace = true;
  }
  if (TypeQuals & clang::Qualifiers::Volatile) {
    if (appendSpace) OS << ' ';
    OS << "volatile";
    appendSpace = true;
  }
  if (TypeQuals & clang::Qualifiers::Restrict) {
    if (appendSpace) OS << ' ';
    if (HasRestrictKeyword) {
      OS << "restrict";
    } else {
      OS << "__restrict";
    }
  }
}

/// Print a template integral argument value.
///
/// \param TemplArg the TemplateArgument instance to print.
///
/// \param Out the raw_ostream instance to use for printing.
///
/// \param Policy the printing policy for EnumConstantDecl printing.
///
/// \param IncludeType If set, ensure that the type of the expression printed
/// matches the type of the template argument.
static void printIntegral(Printer &printer, const clang::TemplateArgument &TemplArg,
                          raw_string_ostream &Out, PrintedTokenRangeImpl &tokens,
                          const clang::PrintingPolicy &Policy, bool IncludeType) {
  const clang::Type *T = TemplArg.getIntegralType().getTypePtr();
  const llvm::APSInt &Val = TemplArg.getAsIntegral();

  if (Policy.UseEnumerators) {
    if (const clang::EnumType *ET = T->getAs<clang::EnumType>()) {
      for (const clang::EnumConstantDecl *ECD : ET->getDecl()->enumerators()) {
        // In Sema::CheckTemplateArugment, enum template arguments value are
        // extended to the size of the integer underlying the enum type.  This
        // may create a size difference between the enum value and template
        // argument value, requiring isSameValue here instead of operator==.
        if (llvm::APSInt::isSameValue(ECD->getInitVal(), Val)) {
          PrintQualifiedName(printer, ECD, Policy);
          return;
        }
      }
    }
  }

  if (Policy.MSVCFormatting)
    IncludeType = false;

  if (T->isBooleanType()) {
    if (!Policy.MSVCFormatting)
      Out << (Val.getBoolValue() ? "true" : "false");
    else
      Out << Val;
  } else if (T->isCharType()) {
    if (IncludeType) {
      if (T->isSpecificBuiltinType(clang::BuiltinType::SChar))
        Out << "(signed char)";
      else if (T->isSpecificBuiltinType(clang::BuiltinType::UChar))
        Out << "(unsigned char)";
    }
    clang::CharacterLiteral::print(Val.getZExtValue(), clang::CharacterLiteral::Ascii, Out);
  } else if (T->isAnyCharacterType() && !Policy.MSVCFormatting) {
    clang::CharacterLiteral::CharacterKind Kind;
    if (T->isWideCharType())
      Kind = clang::CharacterLiteral::Wide;
    else if (T->isChar8Type())
      Kind = clang::CharacterLiteral::UTF8;
    else if (T->isChar16Type())
      Kind = clang::CharacterLiteral::UTF16;
    else if (T->isChar32Type())
      Kind = clang::CharacterLiteral::UTF32;
    else
      Kind = clang::CharacterLiteral::Ascii;
    clang::CharacterLiteral::print(Val.getExtValue(), Kind, Out);
  } else if (IncludeType) {
    if (const auto *BT = T->getAs<clang::BuiltinType>()) {
      switch (BT->getKind()) {
      case clang::BuiltinType::ULongLong:
        Out << Val << "ULL";
        break;
      case clang::BuiltinType::LongLong:
        Out << Val << "LL";
        break;
      case clang::BuiltinType::ULong:
        Out << Val << "UL";
        break;
      case clang::BuiltinType::Long:
        Out << Val << "L";
        break;
      case clang::BuiltinType::UInt:
        Out << Val << "U";
        break;
      case clang::BuiltinType::Int:
        Out << Val;
        break;
      default:
        Out << "(" << T->getCanonicalTypeInternal().getAsString(Policy) << ")"
            << Val;
        break;
      }
    } else
      Out << "(" << T->getCanonicalTypeInternal().getAsString(Policy) << ")"
          << Val;
  } else
    Out << Val;
}

static unsigned getArrayDepth(clang::QualType type) {
  unsigned count = 0;
  while (const auto *arrayType = type->getAsArrayTypeUnsafe()) {
    count++;
    type = arrayType->getElementType();
  }
  return count;
}

static bool needsAmpersandOnTemplateArg(clang::QualType paramType,
                                        clang::QualType argType) {
  // Generally, if the parameter type is a pointer, we must be taking the
  // address of something and need a &.  However, if the argument is an array,
  // this could be implicit via array-to-pointer decay.
  if (!paramType->isPointerType())
    return paramType->isMemberPointerType();
  if (argType->isArrayType())
    return getArrayDepth(argType) == getArrayDepth(paramType->getPointeeType());
  return true;
}

void printArgument(Printer &printer, const clang::TemplateArgument &A,
                   const clang::PrintingPolicy &Policy,
                   bool IncludeType) {
  auto &Out = printer.Out;
  auto &tokens = printer.tokens;

  TokenPrinterContext ctx(Out, &A, tokens);

  switch (A.getKind()) {
  case clang::TemplateArgument::Null:
    Out << "(no value)";
    break;

  case clang::TemplateArgument::Type: {
    clang::PrintingPolicy SubPolicy(Policy);
    SubPolicy.SuppressStrongLifetime = true;

    TypePrinter printer(Out, SubPolicy, tokens, 0);
    printer.print(A.getAsType(), "", nullptr);
    break;
  }

  case clang::TemplateArgument::Declaration: {
    clang::NamedDecl *ND = clang::dyn_cast<clang::NamedDecl>(A.getAsDecl());
    if (A.getParamTypeForDecl()->isRecordType()) {
      if (auto *TPO = clang::dyn_cast<clang::TemplateParamObjectDecl>(ND)) {
        TPO->getType().getUnqualifiedType().print(Out, Policy);
        TPO->printAsInit(Out, Policy);
        break;
      }
    }
    if (auto *VD = clang::dyn_cast<clang::ValueDecl>(ND)) {
      if (needsAmpersandOnTemplateArg(A.getParamTypeForDecl(), VD->getType()))
        Out << "&";
    }

    PrintQualifiedName(printer, ND, Policy);
    break;
  }

  case clang::TemplateArgument::NullPtr:
    // FIXME: Include the type if it's not obvious from the context.
    Out << "nullptr";
    break;

  case clang::TemplateArgument::Template:
    A.getAsTemplate().print(Out, Policy, clang::TemplateName::Qualified::Fully);
    break;

  case clang::TemplateArgument::TemplateExpansion:
    A.getAsTemplateOrTemplatePattern().print(Out, Policy);
    Out << "...";
    break;

  case clang::TemplateArgument::Integral:
    printIntegral(printer, A, Out, tokens, Policy, IncludeType);
    break;

  case clang::TemplateArgument::Expression: {
    StmtPrinter stmtPrinter(Out, nullptr, tokens, Policy, 0, "\n",
                            &tokens.ast_context);
    stmtPrinter.Visit(A.getAsExpr());
    break;
  }

  case clang::TemplateArgument::Pack:
    Out << "<";
    bool First = true;
    for (const clang::TemplateArgument &P : A.pack_elements()) {
      if (First)
        First = false;
      else
        Out << ", ";

      printArgument(printer, P, Policy, IncludeType);
    }
    Out << ">";
    break;
  }
}

static void printArgument(Printer &printer, const clang::TemplateArgumentLoc &A,
                          const clang::PrintingPolicy &PP,
                          bool IncludeType) {
  auto &OS = printer.OS;
  auto &tokens = printer.tokens;

  const clang::TemplateArgument::ArgKind &Kind = A.getArgument().getKind();
  if (Kind == clang::TemplateArgument::ArgKind::Type) {
    TokenPrinterContext ctx(OS, &A.getArgument(), tokens);

    TypePrinter printer(OS, PP, tokens, 0);
    printer.print(A.getTypeSourceInfo()->getType(), "", nullptr);
    return;
  }
  printArgument(printer, A.getArgument(), PP, IncludeType);
}

static const clang::TemplateArgument &getArgument(
    const clang::TemplateArgument &A) {
  return A;
}

static const clang::TemplateArgument &getArgument(
    const clang::TemplateArgumentLoc &A) {
  return A.getArgument();
}

static bool IsDefaulted(clang::ASTContext &Ctx,
                        const clang::TemplateArgument &A,
                        const clang::NamedDecl *P,
                        llvm::ArrayRef<clang::TemplateArgument> OrigArgs,
                        unsigned Depth) {
#if LLVM_VERSION_MAJOR <= 16
  return clang::isSubstitutedDefaultArgument(Ctx, A, P,
                                             OrigArgs, Depth);
#else
  (void) Ctx;
  (void) P;
  (void) OrigArgs;
  (void) Depth;
  return A.getIsDefaulted();
#endif
}

template <typename TA>
static void
printTo(Printer &printer, llvm::ArrayRef<TA> Args,
        const clang::PrintingPolicy &Policy,
        const clang::TemplateParameterList *TPL,
        bool IsPack, unsigned ParmIndex) {

  auto &OS = printer.OS;
  auto &tokens = printer.tokens;

  // Drop trailing template arguments that match default arguments.
  if (TPL && Policy.SuppressDefaultTemplateArgs &&
      !Policy.PrintCanonicalTypes && !Args.empty() && !IsPack &&
      Args.size() <= TPL->size()) {
    llvm::SmallVector<clang::TemplateArgument, 8> OrigArgs;
    for (const TA &A : Args)
      OrigArgs.push_back(getArgument(A));
    while (!Args.empty() && IsDefaulted(tokens.ast_context,
                                        getArgument(Args.back()),
                                        TPL->getParam(Args.size() - 1),
                                        OrigArgs, TPL->getDepth()))
      Args = Args.drop_back();
  }

  const char *Comma = Policy.MSVCFormatting ? "," : ", ";
  if (!IsPack)
    OS << '<';

  bool NeedSpace = false;
  bool FirstArg = true;
  for (const auto &Arg : Args) {
    if (FirstArg) {
      OS << ' ';  // avoid printing the diagraph '<:'.
    }

    const clang::TemplateArgument &Argument = getArgument(Arg);
    if (Argument.getKind() == clang::TemplateArgument::Pack) {
      if (Argument.pack_size() && !FirstArg)
        OS << Comma;
      printTo(printer, Argument.getPackAsArray(), Policy, TPL,
              /*IsPack*/ true, ParmIndex);
    } else {
      if (!FirstArg)
        OS << Comma;
      // Tries to print the argument with location info if exists.
      printArgument(printer, Arg, Policy,
                    clang::TemplateParameterList::shouldIncludeTypeForArgument(
                        Policy, TPL, ParmIndex));
    }

    // If the last character of our string is '>', add another space to
    // keep the two '>''s separate tokens.
    if (!OS.str().empty()) {
      NeedSpace = Policy.SplitTemplateClosers && OS.str().back() == '>';
      FirstArg = false;
    }

    // Use same template parameter for all elements of Pack
    if (!IsPack)
      ParmIndex++;
  }

  if (!IsPack) {
    if (NeedSpace)
      OS << ' ';
    OS << '>';
  }
}

void printTemplateArgumentList(Printer &printer,
                               const clang::TemplateArgumentListInfo &Args,
                               const clang::PrintingPolicy &Policy,
                               const clang::TemplateParameterList *TPL) {
  printTemplateArgumentList(printer, Args.arguments(), Policy, TPL);
}

void printTemplateArgumentList(Printer &printer,
                               llvm::ArrayRef<clang::TemplateArgument> Args,
                               const clang::PrintingPolicy &Policy,
                               const clang::TemplateParameterList *TPL) {
  printTo(printer, Args, Policy, TPL, /*isPack*/ false, /*parmIndex*/ 0);
}

void printTemplateArgumentList(Printer &printer,
                               llvm::ArrayRef<clang::TemplateArgumentLoc> Args,
                               const clang::PrintingPolicy &Policy,
                               const clang::TemplateParameterList *TPL) {
  printTo(printer, Args, Policy, TPL, /*isPack*/ false, /*parmIndex*/ 0);
}

void TypePrinter::spaceBeforePlaceHolder(raw_string_ostream &OS) {
  if (!HasEmptyPlaceHolder)
    OS << ' ';
}

static clang::SplitQualType splitAccordingToPolicy(clang::QualType QT,
                                            const clang::PrintingPolicy &Policy) {
  if (Policy.PrintCanonicalTypes)
    QT = QT.getCanonicalType();
  return QT.split();
}

void TypePrinter::print(clang::QualType t,
                        clang::StringRef PlaceHolder,
                        std::function<void(void)> *placeHolderFn) {
  if (placeHolderFn) {
    printBeforeAfter(t, OS, *placeHolderFn);

  } else if (!PlaceHolder.empty()) {
    auto IdentFn = [&, PlaceHolder = std::move(PlaceHolder)] (void) {
      OS << PlaceHolder;
    };
    printBeforeAfter(t, OS, std::move(IdentFn));

  } else {
    printBeforeAfter(t, OS, [] () {});
  }
}

bool TypePrinter::canPrefixQualifiers(const clang::Type *T,
                                      bool &NeedARCStrongQualifier) {
  // CanPrefixQualifiers - We prefer to print type qualifiers before the type,
  // so that we get "const int" instead of "int const", but we can't do this if
  // the type is complex.  For example if the type is "int*", we *must* print
  // "int * const", printing "const int *" is different.  Only do this when the
  // type expands to a simple string.
  bool CanPrefixQualifiers = false;
  NeedARCStrongQualifier = false;
  const clang::Type *UnderlyingType = T;
  if (const auto *AT = clang::dyn_cast<clang::AutoType>(T))
    UnderlyingType = AT->desugar().getTypePtr();
  if (const auto *Subst = clang::dyn_cast<clang::SubstTemplateTypeParmType>(T))
    UnderlyingType = Subst->getReplacementType().getTypePtr();
  clang::Type::TypeClass TC = UnderlyingType->getTypeClass();

  switch (TC) {
    case clang::Type::Auto:
    case clang::Type::Builtin:
    case clang::Type::Complex:
    case clang::Type::UnresolvedUsing:
    case clang::Type::Using:
    case clang::Type::Typedef:
    case clang::Type::TypeOfExpr:
    case clang::Type::TypeOf:
    case clang::Type::Decltype:
    case clang::Type::UnaryTransform:
    case clang::Type::Record:
    case clang::Type::Enum:
    case clang::Type::Elaborated:
    case clang::Type::TemplateTypeParm:
    case clang::Type::SubstTemplateTypeParmPack:
    case clang::Type::DeducedTemplateSpecialization:
    case clang::Type::TemplateSpecialization:
    case clang::Type::InjectedClassName:
    case clang::Type::DependentName:
    case clang::Type::DependentTemplateSpecialization:
    case clang::Type::ObjCObject:
    case clang::Type::ObjCTypeParam:
    case clang::Type::ObjCInterface:
    case clang::Type::Atomic:
    case clang::Type::Pipe:
    case clang::Type::BitInt:
    case clang::Type::DependentBitInt:
    case clang::Type::BTFTagAttributed:
      CanPrefixQualifiers = true;
      break;

    case clang::Type::ObjCObjectPointer:
      CanPrefixQualifiers = T->isObjCIdType() || T->isObjCClassType() ||
        T->isObjCQualifiedIdType() || T->isObjCQualifiedClassType();
      break;

    case clang::Type::VariableArray:
    case clang::Type::DependentSizedArray:
      NeedARCStrongQualifier = true;
      LLVM_FALLTHROUGH;

    case clang::Type::ConstantArray:
    case clang::Type::IncompleteArray:
      return canPrefixQualifiers(
          clang::cast<clang::ArrayType>(UnderlyingType)->getElementType().getTypePtr(),
          NeedARCStrongQualifier);

    case clang::Type::Adjusted:
    case clang::Type::Decayed:
    case clang::Type::Pointer:
    case clang::Type::BlockPointer:
    case clang::Type::LValueReference:
    case clang::Type::RValueReference:
    case clang::Type::MemberPointer:
    case clang::Type::DependentAddressSpace:
    case clang::Type::DependentVector:
    case clang::Type::DependentSizedExtVector:
    case clang::Type::Vector:
    case clang::Type::ExtVector:
    case clang::Type::ConstantMatrix:
    case clang::Type::DependentSizedMatrix:
    case clang::Type::FunctionProto:
    case clang::Type::FunctionNoProto:
    case clang::Type::Paren:
    case clang::Type::PackExpansion:
    case clang::Type::SubstTemplateTypeParm:
    case clang::Type::MacroQualified:
      CanPrefixQualifiers = false;
      break;

    case clang::Type::Attributed: {
      // We still want to print the address_space before the type if it is an
      // address_space attribute.
      const auto *AttrTy = clang::cast<clang::AttributedType>(UnderlyingType);
      CanPrefixQualifiers = AttrTy->getAttrKind() == clang::attr::AddressSpace;
      break;
    }
  }

  return CanPrefixQualifiers;
}

void TypePrinter::printBeforeAfter(
    clang::QualType t, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  if (t.isNull()) {
    IdentFn();
    return;
  }

  clang::SplitQualType Split = splitAccordingToPolicy(t, Policy);
  const clang::Type *T = Split.Ty;
  clang::Qualifiers Quals = Split.Quals;

  auto suppress_specifiers = Policy.SuppressSpecifiers && T->isSpecifierType();
  bool hasAfterQuals = false;

  bool CanPrefixQualifiers = false;
  bool NeedARCStrongQualifier = false;

  SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder);
  if (!suppress_specifiers) {

    // Print qualifiers as appropriate.

    CanPrefixQualifiers = canPrefixQualifiers(T, NeedARCStrongQualifier);

    if (CanPrefixQualifiers && !Quals.empty()) {
      if (NeedARCStrongQualifier) {
        IncludeStrongLifetimeRAII Strong(Policy);
        Quals.print(OS, Policy, /*appendSpaceIfNonEmpty=*/true);
      } else {
        Quals.print(OS, Policy, /*appendSpaceIfNonEmpty=*/true);
      }
    }

    if (!CanPrefixQualifiers && !Quals.empty()) {
      hasAfterQuals = !Quals.isEmptyWhenPrinted(Policy);
      if (hasAfterQuals)
        HasEmptyPlaceHolder = false;
    }
  }

  if (hasAfterQuals) {
    auto appendSpaceIfNonEmpty = !PrevPHIsEmpty.get();
    IdentFn = [=, &OS, IdentFn = std::move(IdentFn)] (void) {
      if (NeedARCStrongQualifier) {
        IncludeStrongLifetimeRAII Strong(Policy);
        Quals.print(OS, Policy, appendSpaceIfNonEmpty);
      } else {
        Quals.print(OS, Policy, appendSpaceIfNonEmpty);
      }
      IdentFn();
    };
  }

  switch (T->getTypeClass()) {
#define ABSTRACT_TYPE(CLASS, PARENT)
#define TYPE(CLASS, PARENT) case clang::Type::CLASS: \
    print##CLASS(clang::cast<clang::CLASS##Type>(T), OS, std::move(IdentFn)); \
    break;
#include "clang/AST/TypeNodes.inc"
  }
}

void TypePrinter::printBuiltin(const clang::BuiltinType *T,
                               raw_string_ostream &OS,
                               std::function<void(void)> IdentFn) {
  {
    TokenPrinterContext ctx(OS, T, tokens);
    OS << T->getName(Policy);
  }
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printComplex(const clang::ComplexType *T, raw_string_ostream &OS,
                               std::function<void(void)> IdentFn) {
  {
    TokenPrinterContext ctx(OS, T, tokens);
    OS << "_Complex ";
    print(T->getElementType(), llvm::StringRef());
  }
  IdentFn();
}

void TypePrinter::printPointer(const clang::PointerType *T, raw_string_ostream &OS,
                               std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    {
      TokenPrinterContext jump_up_stack(ctx, no_alias_tag{});
      OS << '*';
    }
    IdentFn();
  };

  // Handle things like 'int (*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType())) {
    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      {
        TokenPrinterContext jump_up_stack(ctx);
        OS << '(';
      }
      IdentFn();
      TokenPrinterContext jump_up_stack(ctx);
      OS << ')';
    };
  }

  TagDefinitionPolicyRAII disable_tags(Policy);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getPointeeType(), OS, std::move(IdentFn));
}

void TypePrinter::printBlockPointer(const clang::BlockPointerType *T,
                                    raw_string_ostream &OS,
                                    std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    {
      TokenPrinterContext jump_up_stack(ctx, no_alias_tag{});
      OS << '^';
    }
    IdentFn();
  };

  TagDefinitionPolicyRAII disable_tags(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getPointeeType(), OS, std::move(IdentFn));
}

// When printing a reference, the referenced type might also be a reference.
// If so, we want to skip that before printing the inner type.
static clang::QualType skipTopLevelReferences(clang::QualType T) {
  if (auto *Ref = T->getAs<clang::ReferenceType>())
    return skipTopLevelReferences(Ref->getPointeeTypeAsWritten());
  return T;
}

void TypePrinter::printLValueReference(const clang::LValueReferenceType *T,
                                       raw_string_ostream &OS,
                                       std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    {
      TokenPrinterContext jump_up_stack(ctx, no_alias_tag{});
      OS << '&';
    }
    IdentFn();
  };

  // Handle things like 'int (&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner)) {
    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      {
        TokenPrinterContext jump_up_stack(ctx);
        OS << '(';
      }
      IdentFn();
      TokenPrinterContext jump_up_stack(ctx);
      OS << ')';
    };
  }

  TagDefinitionPolicyRAII disable_tags(Policy);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(Inner, OS, std::move(IdentFn));
}

void TypePrinter::printRValueReference(const clang::RValueReferenceType *T,
                                       raw_string_ostream &OS,
                                       std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    {
      TokenPrinterContext jump_up_stack(ctx, no_alias_tag{});
      OS << "&&";
    }
    IdentFn();
  };

  // Handle things like 'int (&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner)) {
    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      {
        TokenPrinterContext jump_up_stack(ctx);
        OS << '(';
      }
      IdentFn();
      TokenPrinterContext jump_up_stack(ctx);
      OS << ')';
    };
  }

  TagDefinitionPolicyRAII disable_tags(Policy);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(Inner, OS, std::move(IdentFn));
}

void TypePrinter::printMemberPointer(const clang::MemberPointerType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    {
      TokenPrinterContext jump_up_stack(ctx);
      TagDefinitionPolicyRAII tag_raii(Policy);
      TypePrinter(OS, Policy, tokens).print(
          clang::QualType(T->getClass(), 0), clang::StringRef());
      OS << "::*";
    }
    IdentFn();
  };

  // Handle things like 'int (Cls::*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType())) {
    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      {
        TokenPrinterContext jump_up_stack(ctx);
        OS << "(";
      }
      IdentFn();
      TokenPrinterContext jump_up_stack(ctx);
      OS << ')';
    };
  }

  TagDefinitionPolicyRAII disable_tags(Policy);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getPointeeType(), OS, std::move(IdentFn));
}

void TypePrinter::printConstantArray(const clang::ConstantArrayType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();

    TokenPrinterContext jump_up_stack(ctx);
    OS << '[';
    if (T->getIndexTypeQualifiers().hasQualifiers()) {
      AppendTypeQualList(OS, T->getIndexTypeCVRQualifiers(),
                         Policy.Restrict);
      OS << ' ';
    }

    if (T->getSizeModifier() == clang::ArrayType::Static)
      OS << "static ";

    if (const clang::Expr *Expr = T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit(const_cast<clang::Expr *>(Expr));

    } else {
      OS << T->getSize().getZExtValue();
    }

    OS << ']';
  };

  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printIncompleteArray(const clang::IncompleteArrayType *T,
                                       raw_string_ostream &OS,
                                       std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();

    TokenPrinterContext jump_up_stack(ctx);
    OS << "[]";
  };

  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printVariableArray(const clang::VariableArrayType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << '[';
    if (T->getIndexTypeQualifiers().hasQualifiers()) {
      AppendTypeQualList(OS, T->getIndexTypeCVRQualifiers(),
                         Policy.Restrict);
      OS << ' ';
    }

    if (T->getSizeModifier() == clang::ArrayType::Static)
      OS << "static ";
    else if (T->getSizeModifier() == clang::VariableArrayType::Star)
      OS << '*';

    if (const clang::Expr *Expr = T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit(const_cast<clang::Expr *>(Expr));
    }

    OS << ']';
  };

  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printAdjusted(const clang::AdjustedType *T,
                                raw_string_ostream &OS,
                                std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  // Print the original type, as that is more reflective of what is actually
  // in the code.
  printBeforeAfter(T->getOriginalType(), OS, std::move(IdentFn));
}

void TypePrinter::printDecayed(const clang::DecayedType *T,
                               raw_string_ostream &OS,
                               std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  // Print the decayed representation, otherwise the adjustment will be
  // invisible.
  printBeforeAfter(T->getDecayedType(), OS, std::move(IdentFn));
}

void TypePrinter::printDependentSizedArray(
    const clang::DependentSizedArrayType *T,
    raw_string_ostream &OS, std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << '[';
    if (const clang::Expr *Expr = T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit(const_cast<clang::Expr *>(Expr));
    }
    OS << ']';
  };

  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printDependentAddressSpace(
    const clang::DependentAddressSpaceType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << " __attribute__((address_space(";
    if (T->getAddrSpaceExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getAddrSpaceExpr()));
    }
    OS << ")))";
  };

  printBeforeAfter(T->getPointeeType(), OS, std::move(IdentFn));
}

void TypePrinter::printDependentSizedExtVector(
    const clang::DependentSizedExtVectorType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << " __attribute__((ext_vector_type(";
    if (T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getSizeExpr()));
    }
    OS << ")))";
  };

  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printVector(
    const clang::VectorType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  switch (T->getVectorKind()) {
    case clang::VectorType::AltiVecPixel:
      OS << "__vector __pixel ";
      break;
    case clang::VectorType::AltiVecBool:
      OS << "__vector __bool ";
      break;
    case clang::VectorType::AltiVecVector:
      OS << "__vector ";
      break;
    case clang::VectorType::NeonVector:
      OS << "__attribute__((neon_vector_type("
         << T->getNumElements() << "))) ";
      break;
    case clang::VectorType::NeonPolyVector:
      OS << "__attribute__((neon_polyvector_type(" <<
            T->getNumElements() << "))) ";
      break;
    case clang::VectorType::GenericVector: {
      // FIXME: We prefer to print the size directly here, but have no way
      // to get the size of the type.
      OS << "__attribute__((__vector_size__("
         << T->getNumElements()
         << " * sizeof(";
      print(T->getElementType(), clang::StringRef());
      OS << ")))) ";
      break;
    }
    case clang::VectorType::SveFixedLengthDataVector:
    case clang::VectorType::SveFixedLengthPredicateVector:
      // FIXME: We prefer to print the size directly here, but have no way
      // to get the size of the type.
      OS << "__attribute__((__arm_sve_vector_bits__(";

      if (T->getVectorKind() == clang::VectorType::SveFixedLengthPredicateVector)
        // Predicates take a bit per byte of the vector size, multiply by 8 to
        // get the number of bits passed to the attribute.
        OS << T->getNumElements() * 8;
      else
        OS << T->getNumElements();

      OS << " * sizeof(";
      print(T->getElementType(), clang::StringRef());
      // Multiply by 8 for the number of bits.
      OS << ") * 8))) ";
      break;
  }

  // TODO(pag): Why are altivecpixel types different?
  if (T->getVectorKind() != clang::VectorType::AltiVecPixel) {
    printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
  } else {
    IdentFn();
  }
}

void TypePrinter::printDependentVector(
    const clang::DependentVectorType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  auto SizeFn = [&] (void) {
    if (T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getSizeExpr()));
    }
  };

  switch (T->getVectorKind()) {
    case clang::VectorType::AltiVecPixel:
      OS << "__vector __pixel ";
      break;
    case clang::VectorType::AltiVecBool:
      OS << "__vector __bool ";
      break;
    case clang::VectorType::AltiVecVector:
      OS << "__vector ";
      break;
    case clang::VectorType::NeonVector:
      OS << "__attribute__((neon_vector_type(";
      SizeFn();
      OS << "))) ";
      break;
    case clang::VectorType::NeonPolyVector:
      OS << "__attribute__((neon_polyvector_type(";
      SizeFn();
      OS << "))) ";
      break;
    case clang::VectorType::GenericVector: {
      // FIXME: We prefer to print the size directly here, but have no way
      // to get the size of the type.
      OS << "__attribute__((__vector_size__(";
      SizeFn();
      OS << " * sizeof(";
      print(T->getElementType(), clang::StringRef());
      OS << ")))) ";
      break;
    }
    case clang::VectorType::SveFixedLengthDataVector:
    case clang::VectorType::SveFixedLengthPredicateVector:
      // FIXME: We prefer to print the size directly here, but have no way
      // to get the size of the type.
      OS << "__attribute__((__arm_sve_vector_bits__(";
      SizeFn();

      if (T->getVectorKind() == clang::VectorType::SveFixedLengthPredicateVector)
        // Predicates take a bit per byte of the vector size, multiply by 8 to
        // get the number of bits passed to the attribute.
        OS << " * 8";

      OS << " * sizeof(";
      print(T->getElementType(), clang::StringRef());
      // Multiply by 8 for the number of bits.
      OS << ") * 8))) ";
      break;
  }

  // TODO(pag): Why are altivecpixel types different?
  if (T->getVectorKind() != clang::VectorType::AltiVecPixel) {
    printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
  } else {
    IdentFn();
  }
}

void TypePrinter::printExtVector(
    const clang::ExtVectorType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();

    TokenPrinterContext jump_up_stack(ctx);
    OS << " __attribute__((ext_vector_type("
       << T->getNumElements()
       << ")))";
  };

  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printConstantMatrix(
    const clang::ConstantMatrixType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << " __attribute__((matrix_type("
       << T->getNumRows() << ", " << T->getNumColumns()
       << ")))";
  };

  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

void TypePrinter::printDependentSizedMatrix(
    const clang::DependentSizedMatrixType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << " __attribute__((matrix_type(";
    if (T->getRowExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getRowExpr()));
    }
    OS << ", ";
    if (T->getColumnExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getColumnExpr()));
    }
    OS << ")))";
  };

  printBeforeAfter(T->getElementType(), OS, std::move(IdentFn));
}

static void FunctionProtoType_printExceptionSpecification(
    const clang::FunctionProtoType *T, PrintedTokenRangeImpl &tokens,
    raw_string_ostream &OS, const clang::PrintingPolicy &Policy) {

  if (T->hasDynamicExceptionSpec()) {
    OS << " throw(";
    if (T->getExceptionSpecType() == clang::EST_MSAny)
      OS << "...";
    else
      for (unsigned I = 0, N = T->getNumExceptions(); I != N; ++I) {
        if (I)
          OS << ", ";

        TypePrinter printer(OS, Policy, tokens, 0);
        printer.print(T->getExceptionType(I), "", nullptr);
      }
    OS << ')';
  } else if (clang::EST_NoThrow == T->getExceptionSpecType()) {
    OS << " __attribute__((nothrow))";
  } else if (clang::isNoexceptExceptionSpec(T->getExceptionSpecType())) {
    OS << " noexcept";
    // FIXME:Is it useful to print out the expression for a non-dependent
    // noexcept specification?
    if (clang::isComputedNoexcept(T->getExceptionSpecType())) {
      OS << '(';
      if (T->getNoexceptExpr()) {
        StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                                &(tokens.ast_context));
        stmtPrinter.Visit((T->getNoexceptExpr()));
      }
      OS << ')';
    }
  }
}

void TypePrinter::printFunctionProto(const clang::FunctionProtoType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  if (T->hasTrailingReturn()) {
    if (!HasEmptyPlaceHolder) {
      IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
        {
          TokenPrinterContext jump_up_stack(ctx);
          OS << '(';
        }
        IdentFn();

        TokenPrinterContext jump_up_stack(ctx);
        OS << ')';
      };
    }

    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      {
        TokenPrinterContext jump_up_stack(ctx);
        OS << "auto ";
      }
      IdentFn();
    };

  } else {
    // If needed for precedence reasons, wrap the inner part in grouping parens.
    if (!HasEmptyPlaceHolder) {
      IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
        {
          TokenPrinterContext jump_up_stack(ctx);
          OS << '(';
        }
        IdentFn();
        TokenPrinterContext jump_up_stack(ctx);
        OS << ')';
      };
    }
  }

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << '(';
    {
//      TokenPrinterContext ctx(OS, "ParameterTypeList", tokens);
      {
        ParamPolicyRAII ParamPolicy(Policy);
        TagDefinitionPolicyRAII disable_tags(Policy);

        for (unsigned i = 0, e = T->getNumParams(); i != e; ++i) {
          if (i) OS << ", ";

//          TokenPrinterContext ctx(OS, "ParameterType", tokens);

          auto EPI = T->getExtParameterInfo(i);
          if (EPI.isConsumed()) {
            OS << "__attribute__((ns_consumed)) ";
          }
          if (EPI.isNoEscape()) {
            OS << "__attribute__((noescape)) ";
          }
          auto ABI = EPI.getABI();
          if (ABI != clang::ParameterABI::Ordinary) {
            OS << "__attribute__((" << clang::getParameterABISpelling(ABI) << ")) ";
          }

          print(T->getParamType(i), clang::StringRef());
        }
      }

      if (T->isVariadic()) {
        if (T->getNumParams())
          OS << ", ";

        OS << "...";
        ctx.MarkLocation(T->getEllipsisLoc());

      } else if (T->getNumParams() == 0 && Policy.UseVoidForZeroParams) {
        // Do not emit int() if we have a proto, emit 'int(void)'.
        OS << "void";
      }
    }
    OS << ')';

    clang::FunctionType::ExtInfo Info = T->getExtInfo();

    printFunctionAfter(Info, OS);

    if (!T->getMethodQuals().empty())
      OS << " " << T->getMethodQuals().getAsString();

    switch (T->getRefQualifier()) {
    case clang::RQ_None:
      break;

    case clang::RQ_LValue:
      OS << " &";
      break;

    case clang::RQ_RValue:
      OS << " &&";
      break;
    }

    FunctionProtoType_printExceptionSpecification(T, tokens, OS, Policy);
  };

  if (T->hasTrailingReturn()) {
    IdentFn();
    OS << " -> ";
    print(T->getReturnType(), clang::StringRef());
  } else {
    printBeforeAfter(T->getReturnType(), OS, std::move(IdentFn));
  }
}

void TypePrinter::printFunctionAfter(const clang::FunctionType::ExtInfo &Info,
                                     raw_string_ostream &OS) {
  if (!InsideCCAttribute) {
    switch (Info.getCC()) {
    case clang::CC_C:
      // The C calling convention is the default on the vast majority of platforms
      // we support.  If the user wrote it explicitly, it will usually be printed
      // while traversing the AttributedType.  If the type has been desugared, let
      // the canonical spelling be the implicit calling convention.
      // FIXME: It would be better to be explicit in certain contexts, such as a
      // cdecl function typedef used to declare a member function with the
      // Microsoft C++ ABI.
      break;
    case clang::CC_X86StdCall:
      OS << " __attribute__((stdcall))";
      break;
    case clang::CC_X86FastCall:
      OS << " __attribute__((fastcall))";
      break;
    case clang::CC_X86ThisCall:
      OS << " __attribute__((thiscall))";
      break;
    case clang::CC_X86VectorCall:
      OS << " __attribute__((vectorcall))";
      break;
    case clang::CC_X86Pascal:
      OS << " __attribute__((pascal))";
      break;
    case clang::CC_AAPCS:
      OS << " __attribute__((pcs(\"aapcs\")))";
      break;
    case clang::CC_AAPCS_VFP:
      OS << " __attribute__((pcs(\"aapcs-vfp\")))";
      break;
    case clang::CC_AArch64VectorCall:
      OS << "__attribute__((aarch64_vector_pcs))";
      break;
    case clang::CC_AArch64SVEPCS:
      OS << "__attribute__((aarch64_sve_pcs))";
      break;
    case clang::CC_AMDGPUKernelCall:
      OS << "__attribute__((amdgpu_kernel))";
      break;
    case clang::CC_IntelOclBicc:
      OS << " __attribute__((intel_ocl_bicc))";
      break;
    case clang::CC_Win64:
      OS << " __attribute__((ms_abi))";
      break;
    case clang::CC_X86_64SysV:
      OS << " __attribute__((sysv_abi))";
      break;
    case clang::CC_X86RegCall:
      OS << " __attribute__((regcall))";
      break;
    case clang::CC_SpirFunction:
    case clang::CC_OpenCLKernel:
      // Do nothing. These CCs are not available as attributes.
      break;
    case clang::CC_Swift:
      OS << " __attribute__((swiftcall))";
      break;
    case clang::CC_SwiftAsync:
      OS << "__attribute__((swiftasynccall))";
      break;
    case clang::CC_PreserveMost:
      OS << " __attribute__((preserve_most))";
      break;
    case clang::CC_PreserveAll:
      OS << " __attribute__((preserve_all))";
      break;
    }
  }

  if (Info.getNoReturn())
    OS << " __attribute__((noreturn))";
  if (Info.getCmseNSCall())
    OS << " __attribute__((cmse_nonsecure_call))";
  if (Info.getProducesResult())
    OS << " __attribute__((ns_returns_retained))";
  if (Info.getRegParm())
    OS << " __attribute__((regparm ("
       << Info.getRegParm() << ")))";
  if (Info.getNoCallerSavedRegs())
    OS << " __attribute__((no_caller_saved_registers))";
  if (Info.getNoCfCheck())
    OS << " __attribute__((nocf_check))";
}

void TypePrinter::printFunctionNoProto(const clang::FunctionNoProtoType *T,
                                       raw_string_ostream &OS,
                                       std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);

  // If needed for precedence reasons, wrap the inner part in grouping parens.
  SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder, false);
  if (!HasEmptyPlaceHolder) {
    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      {
        TokenPrinterContext jump_up_stack(ctx);
        OS << '(';
      }
      IdentFn();
      TokenPrinterContext jump_up_stack(ctx);
      OS << ')';
    };
  }

  IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    IdentFn();
    TokenPrinterContext jump_up_stack(ctx);
    OS << "()";
    printFunctionAfter(T->getExtInfo(), OS);
  };

  printBeforeAfter(T->getReturnType(), OS, std::move(IdentFn));
}

void TypePrinter::printTypeSpec(clang::NamedDecl *D, raw_string_ostream &OS) {

  TokenPrinterContext ctx(OS, D, tokens);

  // Compute the full nested-name-specifier for this type.
  // In C, this will always be empty except when the type
  // being printed is anonymous within other Record.
  if (!Policy.SuppressScope)
    AppendScope(D->getDeclContext(), OS, D->getDeclName());

  clang::IdentifierInfo *II = D->getIdentifier();
  OS << II->getName();
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printUnresolvedUsing(const clang::UnresolvedUsingType *T,
                                       raw_string_ostream &OS,
                                       std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  printTypeSpec(T->getDecl(), OS);
  IdentFn();
}

void TypePrinter::printUsing(const clang::UsingType *T,
                             raw_string_ostream &OS,
                             std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  // After `namespace b { using a::X }`, is the type X within B a::X or b::X?
  //
  // - b::X is more formally correct given the UsingType model
  // - b::X makes sense if "re-exporting" a symbol in a new namespace
  // - a::X makes sense if "importing" a symbol for convenience
  //
  // The "importing" use seems much more common, so we print a::X.
  // This could be a policy option, but the right choice seems to rest more
  // with the intent of the code than the caller.
  printTypeSpec(T->getFoundDecl()->getUnderlyingDecl(), OS);
  IdentFn();
}

void TypePrinter::printTypedef(const clang::TypedefType *T,
                               raw_string_ostream &OS,
                               std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  printTypeSpec(T->getDecl(), OS);
  IdentFn();
}

void TypePrinter::printMacroQualified(const clang::MacroQualifiedType *T,
                                      raw_string_ostream &OS,
                                      std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);
  clang::StringRef MacroName = T->getMacroIdentifier()->getName();
  OS << MacroName << " ";

  // Since this type is meant to print the macro instead of the whole attribute,
  // we trim any attributes and go directly to the original modified type.
  printBeforeAfter(T->getModifiedType(), OS, std::move(IdentFn));
}

void TypePrinter::printTypeOfExpr(const clang::TypeOfExprType *T,
                                  raw_string_ostream &OS,
                                  std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  OS << (T->getKind() == clang::TypeOfKind::Unqualified ? "typeof_unqual "
                                                        : "typeof ");
  if (T->getUnderlyingExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getUnderlyingExpr()));
  }
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printTypeOf(const clang::TypeOfType *T,
                              raw_string_ostream &OS,
                              std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  OS << (T->getKind() == clang::TypeOfKind::Unqualified ? "typeof_unqual("
                                                        : "typeof(");
  print(T->getUnmodifiedType(), clang::StringRef());
  OS << ')';
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printDecltype(const clang::DecltypeType *T,
                                raw_string_ostream &OS,
                                std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  OS << "decltype(";
  if (T->getUnderlyingExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getUnderlyingExpr()));
  } else {
    print(T->getUnderlyingType(), clang::StringRef());
  }
  OS << ')';
  spaceBeforePlaceHolder(OS);
  IdentFn();
}


void TypePrinter::printUnaryTransform(const clang::UnaryTransformType *T,
                                      raw_string_ostream &OS,
                                      std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  IncludeStrongLifetimeRAII Strong(Policy);

  static llvm::DenseMap<int, const char *> Transformation = {{
#define TRANSFORM_TYPE_TRAIT_DEF(Enum, Trait)                                  \
  {clang::UnaryTransformType::Enum, "__" #Trait},
#include <clang/Basic/TransformTypeTraits.def>
  }};
  OS << Transformation[T->getUTTKind()] << '(';
  print(T->getBaseType(), llvm::StringRef());
  OS << ')';

  IdentFn();
}

void TypePrinter::printAuto(const clang::AutoType *T, raw_string_ostream &OS,
                            std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

//  // If the type has been deduced, do not print 'auto'.
//  if (!T->getDeducedType().isNull()) {
//    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
//
//    };
//    printBefore(T->getDeducedType(), OS);
//  } else {

  if (T->isConstrained()) {
    TagDefinitionPolicyRAII tag_raii(Policy);
    // FIXME: Track a TypeConstraint as type sugar, so that we can print the
    // type as it was written.
    T->getTypeConstraintConcept()->getDeclName().print(OS, Policy);
    auto Args = T->getTypeConstraintArguments();
    if (!Args.empty()) {
      printTemplateArgumentList(
          *this, Args, Policy,
          T->getTypeConstraintConcept()->getTemplateParameters());
    }
    OS << ' ';
  }

  switch (T->getKeyword()) {
  case clang::AutoTypeKeyword::Auto: OS << "auto"; break;
  case clang::AutoTypeKeyword::DecltypeAuto: OS << "decltype(auto)"; break;
  case clang::AutoTypeKeyword::GNUAutoType: OS << "__auto_type"; break;
  }
  spaceBeforePlaceHolder(OS);

  IdentFn();
}

void TypePrinter::printDeducedTemplateSpecialization(
    const clang::DeducedTemplateSpecializationType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
//  // If the type has been deduced, print the deduced type.
//  if (!T->getDeducedType().isNull()) {
//    printBefore(T->getDeducedType(), OS);
//  } else {
  IncludeStrongLifetimeRAII Strong(Policy);
  T->getTemplateName().print(OS, Policy);
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printAtomic(const clang::AtomicType *T,
                              raw_string_ostream &OS,
                              std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  IncludeStrongLifetimeRAII Strong(Policy);
  OS << "_Atomic ";
  print(T->getValueType(), clang::StringRef());
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printPipe(const clang::PipeType *T, raw_string_ostream &OS,
                            std::function<void(void)> IdentFn) {

  IncludeStrongLifetimeRAII Strong(Policy);
  TokenPrinterContext ctx(OS, T, tokens);

  if (T->isReadOnly())
    OS << "read_only ";
  else
    OS << "write_only ";
  OS << "pipe ";
  print(T->getElementType(), clang::StringRef());
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printBitInt(const clang::BitIntType *T,
                              raw_string_ostream &OS,
                              std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  if (T->isUnsigned())
    OS << "unsigned ";
  OS << "_BitInt(" << T->getNumBits() << ")";
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printDependentBitInt(const clang::DependentBitIntType *T,
                                       raw_string_ostream &OS,
                                       std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  if (T->isUnsigned())
    OS << "unsigned ";
  OS << "_BitInt(";
  {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getNumBitsExpr()));
  }
  OS << ')';
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

/// Appends the given scope to the end of a string.
void TypePrinter::AppendScope(clang::DeclContext *DC, raw_string_ostream &OS,
                              clang::DeclarationName NameInScope) {
  if (DC->isTranslationUnit())
    return;

  // FIXME: Consider replacing this with NamedDecl::printNestedNameSpecifier,
  // which can also print names for function and method scopes.
  if (DC->isFunctionOrMethod())
    return;

  if (Policy.Callbacks && Policy.Callbacks->isScopeVisible(DC))
    return;

  if (const auto *NS = clang::dyn_cast<clang::NamespaceDecl>(DC)) {
    if (Policy.SuppressUnwrittenScope && NS->isAnonymousNamespace())
      return AppendScope(DC->getParent(), OS, NameInScope);

    // Only suppress an inline namespace if the name has the same lookup
    // results in the enclosing namespace.
    if (Policy.SuppressInlineNamespace && NS->isInline() && NameInScope &&
        NS->isRedundantInlineQualifierFor(NameInScope))
      return AppendScope(DC->getParent(), OS, NameInScope);

    AppendScope(DC->getParent(), OS, NS->getDeclName());
    {
      TokenPrinterContext ctx(OS, NS, tokens);
      if (NS->getIdentifier())
        OS << NS->getName();
      else
        OS << "(anonymous namespace)";
    }
    OS << "::";
  } else if (const auto *Spec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(DC)) {
    AppendScope(DC->getParent(), OS, Spec->getDeclName());
    {
      TokenPrinterContext ctx(OS, Spec, tokens);
      IncludeStrongLifetimeRAII Strong(Policy);
      OS << Spec->getIdentifier()->getName();
      const clang::TemplateArgumentList &TemplateArgs = Spec->getTemplateArgs();
      {
        TagDefinitionPolicyRAII tag_raii(Policy);
        printTemplateArgumentList(
            *this, TemplateArgs.asArray(), Policy,
            Spec->getSpecializedTemplate()->getTemplateParameters());
      }
    }
    OS << "::";
  } else if (const auto *Tag = clang::dyn_cast<clang::TagDecl>(DC)) {
    AppendScope(DC->getParent(), OS, Tag->getDeclName());
    if (clang::TypedefNameDecl *Typedef = Tag->getTypedefNameForAnonDecl()) {
      TokenPrinterContext ctx(OS, Typedef, tokens);
      OS << Typedef->getIdentifier()->getName();
    } else if (Tag->getIdentifier()) {
      TokenPrinterContext ctx(OS, Tag, tokens);
      OS << Tag->getIdentifier()->getName();
    } else
      return;
    OS << "::";
  } else {
    AppendScope(DC->getParent(), OS, NameInScope);
  }
}

void TypePrinter::printTag(clang::TagDecl *D, raw_string_ostream &OS) {

  if (Policy.IncludeTagDefinition) {
//    clang::PrintingPolicy SubPolicy = Policy;
//    SubPolicy.IncludeTagDefinition = false;
    DeclPrinter declPrinter(OS, Policy, tokens.ast_context, tokens,
                            Indentation);
    declPrinter.Visit(D);
    spaceBeforePlaceHolder(OS);
    return;
  }

  TokenPrinterContext ctx(OS, D, tokens);

  bool HasKindDecoration = false;

  // We don't print tags unless this is an elaborated type.
  // In C, we just assume every RecordType is an elaborated type.
  if (!Policy.SuppressTagKeyword && !D->getTypedefNameForAnonDecl()) {
    HasKindDecoration = true;
    OS << D->getKindName();
    OS << ' ';
  }

  // Compute the full nested-name-specifier for this type.
  // In C, this will always be empty except when the type
  // being printed is anonymous within other Record.
  if (!Policy.SuppressScope)
    AppendScope(D->getDeclContext(), OS, D->getDeclName());

  if (const clang::IdentifierInfo *II = D->getIdentifier())
    OS << II->getName();
  else if (clang::TypedefNameDecl *Typedef = D->getTypedefNameForAnonDecl()) {
    assert(Typedef->getIdentifier() && "Typedef without identifier?");
    OS << Typedef->getIdentifier()->getName();
  } else {
    // Make an unambiguous representation for anonymous types, e.g.
    //   (anonymous enum at /usr/include/string.h:120:9)
    OS << (Policy.MSVCFormatting ? '`' : '(');

    if (clang::isa<clang::CXXRecordDecl>(D) && clang::cast<clang::CXXRecordDecl>(D)->isLambda()) {
      OS << "lambda";
      HasKindDecoration = true;
    } else if ((clang::isa<clang::RecordDecl>(D) && clang::cast<clang::RecordDecl>(D)->isAnonymousStructOrUnion())) {
      OS << "anonymous";
    } else {
      OS << "unnamed";
    }

    if (Policy.AnonymousTagLocations) {
      // Suppress the redundant tag keyword if we just printed one.
      // We don't have to worry about ElaboratedTypes here because you can't
      // refer to an anonymous type with one.
      if (!HasKindDecoration)
        OS << " " << D->getKindName();

      clang::PresumedLoc PLoc = D->getASTContext().getSourceManager().getPresumedLoc(
          D->getLocation());
      if (PLoc.isValid()) {
        OS << " at ";
        clang::StringRef File = PLoc.getFilename();
        if (auto *Callbacks = Policy.Callbacks)
          OS << Callbacks->remapPath(File);
        else
          OS << File;
        OS << ':' << PLoc.getLine() << ':' << PLoc.getColumn();
      }
    }

    OS << (Policy.MSVCFormatting ? '\'' : ')');
  }

  // If this is a class template specialization, print the template
  // arguments.
  if (const auto *Spec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(D)) {
    clang::ArrayRef<clang::TemplateArgument> Args;
    clang::TypeSourceInfo *TAW = Spec->getTypeAsWritten();
    if (!Policy.PrintCanonicalTypes && TAW) {
      const clang::TemplateSpecializationType *TST =
          clang::cast<clang::TemplateSpecializationType>(TAW->getType());
      Args = TST->template_arguments();
    } else {
      const clang::TemplateArgumentList &TemplateArgs = Spec->getTemplateArgs();
      Args = TemplateArgs.asArray();
    }
    IncludeStrongLifetimeRAII Strong(Policy);
    printTemplateArgumentList(
        *this, Args, Policy,
        Spec->getSpecializedTemplate()->getTemplateParameters());
  }

  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printRecord(const clang::RecordType *T,
                              raw_string_ostream &OS,
                              std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  // Print the preferred name if we have one for this type.
  for (const auto *PNA : T->getDecl()->specific_attrs<clang::PreferredNameAttr>()) {
    if (declaresSameEntity(PNA->getTypedefType()->getAsCXXRecordDecl(),
                           T->getDecl())) {
      // Find the outermost typedef or alias template.
      clang::QualType T = PNA->getTypedefType();
      while (true) {
        if (auto *TT = clang::dyn_cast<clang::TypedefType>(T)) {
          printTypeSpec(TT->getDecl(), OS);
          goto print_ident;
        }
        if (auto *TST = clang::dyn_cast<clang::TemplateSpecializationType>(T)) {
          printTemplateId(TST, OS, /*FullyQualify=*/true);
          goto print_ident;
        }
        T = T->getLocallyUnqualifiedSingleStepDesugaredType();
      }
    }
  }

  printTag(T->getDecl(), OS);

print_ident:
  IdentFn();
}

void TypePrinter::printEnum(const clang::EnumType *T, raw_string_ostream &OS,
                            std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  printTag(T->getDecl(), OS);
  IdentFn();
}

void TypePrinter::printTemplateTypeParm(const clang::TemplateTypeParmType *T,
                                        raw_string_ostream &OS,
                                        std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  clang::TemplateTypeParmDecl *D = T->getDecl();
  if (D && D->isImplicit()) {
    TokenPrinterContext ctx2(OS, D, tokens);
    if (auto *TC = D->getTypeConstraint()) {
      TagDefinitionPolicyRAII disable_tags(Policy);
      TokenPrinterContext ctx3(OS, TC, tokens);
      TC->print(OS, Policy);
      OS << ' ';
    }
    OS << "auto";
  } else if (clang::IdentifierInfo *Id = T->getIdentifier()) {
    OS << Id->getName();
  } else if (D) {
    OS << D->getName();
  } else
    OS << "type-parameter-" << T->getDepth() << '-' << T->getIndex();

  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printSubstTemplateTypeParm(
    const clang::SubstTemplateTypeParmType *T,
    raw_string_ostream &OS, std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);
  IncludeStrongLifetimeRAII Strong(Policy);

  if (auto PT = T->getReplacedParameter()) {
    {
      DeclPrinter declPrinter(OS, Policy, tokens.ast_context, tokens,
                              Indentation);
      declPrinter.Visit(const_cast<clang::TemplateTypeParmDecl *>(PT));
    }
    spaceBeforePlaceHolder(OS);
    IdentFn();
  } else {
    printBeforeAfter(T->getReplacementType(), OS, std::move(IdentFn));
  }
}

void TypePrinter::printSubstTemplateTypeParmPack(
    const clang::SubstTemplateTypeParmPackType *T,
    raw_string_ostream &OS, std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  IncludeStrongLifetimeRAII Strong(Policy);

  {
    DeclPrinter declPrinter(OS, Policy, tokens.ast_context, tokens,
                            Indentation);
    declPrinter.Visit(
        const_cast<clang::TemplateTypeParmDecl *>(T->getReplacedParameter()));
  }
  spaceBeforePlaceHolder(OS);
  IdentFn();

  // TODO(pag): Eventually figure out something better than
  //            `type-parameter-N-M`, or have a printing policy that decides
  //            between printing out the before or the after.

//  if (const clang::TemplateTypeParmDecl *D = T->getReplacedParameter()) {
//    if (D && D->isImplicit()) {
//      if (auto *TC = D->getTypeConstraint()) {
//        TC->print(OS, Policy);
//        OS << ' ';
//      }
//      OS << "auto";
//    } else if (clang::IdentifierInfo *Id = D->getIdentifier())
//      OS << (Policy.CleanUglifiedParameters ? Id->deuglifiedName()
//                                            : Id->getName());
//    else
//      OS << "type-parameter-" << D->getDepth() << '-' << D->getIndex();
//
//    spaceBeforePlaceHolder(OS);
//    printTemplateTypeParm(D, OS, std::move(IdentFn));
//  }
}

void TypePrinter::printTemplateId(const clang::TemplateSpecializationType *T,
                                  raw_string_ostream &OS, bool FullyQualify) {
  TokenPrinterContext ctx(OS, T, tokens);
  IncludeStrongLifetimeRAII Strong(Policy);
  TagDefinitionPolicyRAII tag_raii(Policy);

  std::optional<TokenPrinterContext> decl_ctx;
  if (auto AT = T->desugar(); !AT.isNull()) {
    if (auto RD = AT.getTypePtr()->getAsCXXRecordDecl()) {
      decl_ctx.emplace(OS, RD, tokens);
    }
  }

  clang::TemplateDecl *TD = T->getTemplateName().getAsTemplateDecl();
  // FIXME: Null TD never excercised in test suite.

  if (FullyQualify && TD) {
    if (!Policy.SuppressScope)
      AppendScope(TD->getDeclContext(), OS, TD->getDeclName());

    OS << TD->getName();
  } else {
    T->getTemplateName().print(OS, Policy);
  }


  DefaultTemplateArgsPolicyRAII TemplateArgs(Policy);
  const clang::TemplateParameterList *TPL = TD ? TD->getTemplateParameters() : nullptr;
  printTemplateArgumentList(*this, T->template_arguments(), Policy, TPL);
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTemplateSpecialization(
    const clang::TemplateSpecializationType *T, raw_string_ostream &OS,
    std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  printTemplateId(T, OS, Policy.FullyQualifiedName);
  IdentFn();
}

void TypePrinter::printInjectedClassName(const clang::InjectedClassNameType *T,
                                         raw_string_ostream &OS,
                                         std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  if (Policy.PrintInjectedClassNameWithArguments) {
    return printTemplateSpecialization(T->getInjectedTST(), OS,
                                       std::move(IdentFn));
  }

  IncludeStrongLifetimeRAII Strong(Policy);
  T->getTemplateName().print(OS, Policy);
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printElaborated(const clang::ElaboratedType *T,
                                  raw_string_ostream &OS,
                                  std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  std::optional<TokenPrinterContext> tag_context;

  clang::QualType NT = T->getNamedType();
  const clang::TagType *TT = NT->getAs<clang::TagType>();

  // Inject in the decl, so that we have some "balance" with the owned case.
  if (TT) {
    tag_context.emplace(OS, TT, tokens);
  }

  if (clang::TagDecl *OwnedTagDecl = T->getOwnedTagDecl()) {

    TagDefinitionPolicyRAII enable_tags(Policy, true);

    assert(OwnedTagDecl->getTypeForDecl() == T->getNamedType().getTypePtr() &&
           "OwnedTagDecl expected to be a declaration for the type");
    {
      DeclPrinter declPrinter(OS,Policy, tokens.ast_context, tokens,
                              Indentation);
      declPrinter.Visit(OwnedTagDecl);
    }
    spaceBeforePlaceHolder(OS);
    IdentFn();
  } else {
    TagDefinitionPolicyRAII disable_tags(Policy);

    std::optional<TokenPrinterContext> decl_context;

    // Inject in the decl, so that we have some "balance" with the owned case.
    if (clang::TagDecl *D = T->getAsTagDecl()) {
      decl_context.emplace(OS, D, tokens);
    }

    // The tag definition will take care of these.
    OS << clang::TypeWithKeyword::getKeywordName(T->getKeyword());
    if (T->getKeyword() != clang::ETK_None)
      OS << " ";

    if (clang::NestedNameSpecifier *Qualifier = T->getQualifier())
      PrintNestedNameSpecifier(*this, Qualifier, Policy);

    decl_context.reset();
    tag_context.reset();

    ElaboratedTypePolicyRAII PolicyRAII(Policy);
    printBeforeAfter(NT, OS, std::move(IdentFn));
  }
}

void TypePrinter::printParen(const clang::ParenType *T, raw_string_ostream &OS,
                             std::function<void(void)> IdentFn) {

  if (!HasEmptyPlaceHolder && !clang::isa<clang::FunctionType>(T->getInnerType())) {
    IdentFn = [=, &OS, IdentFn = std::move(IdentFn)] (void) {
      TokenPrinterContext ctx(OS, T, tokens);
      OS << '(';
      IdentFn();
      OS << ')';
    };
  }

  printBeforeAfter(T->getInnerType(), OS, std::move(IdentFn));
}

void TypePrinter::printDependentName(const clang::DependentNameType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  OS << clang::TypeWithKeyword::getKeywordName(T->getKeyword());
  if (T->getKeyword() != clang::ETK_None)
    OS << " ";

  TagDefinitionPolicyRAII disable_tags(Policy);
  PrintNestedNameSpecifier(*this, T->getQualifier(), Policy);

  OS << T->getIdentifier()->getName();
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printDependentTemplateSpecialization(
    const clang::DependentTemplateSpecializationType *T,
    raw_string_ostream &OS, std::function<void(void)> IdentFn) {

  TokenPrinterContext ctx(OS, T, tokens);
  IncludeStrongLifetimeRAII Strong(Policy);
  TagDefinitionPolicyRAII tag_raii(Policy);

  OS << clang::TypeWithKeyword::getKeywordName(T->getKeyword());
  if (T->getKeyword() != clang::ETK_None)
    OS << " ";

  TagDefinitionPolicyRAII disable_tags(Policy);
  if (auto Q = T->getQualifier())
    PrintNestedNameSpecifier(*this, Q, Policy);

  OS << "template " << T->getIdentifier()->getName();
  assert(!Policy.IncludeTagDefinition);
  printTemplateArgumentList(*this, T->template_arguments(), Policy);
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printPackExpansion(const clang::PackExpansionType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  printBeforeAfter(T->getPattern(), OS, std::move(IdentFn));
  OS << "...";
}

void TypePrinter::printAttributed(const clang::AttributedType *T,
                                  raw_string_ostream &OS,
                                  std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  // FIXME: Generate this with TableGen.

  // Print nullability type specifiers.
  if (T->getImmediateNullability()) {
    IdentFn = [=, &OS, IdentFn = std::move(IdentFn)] (void) {
      if (T->getAttrKind() == clang::attr::TypeNonNull)
        OS << " _Nonnull";
      else if (T->getAttrKind() == clang::attr::TypeNullable)
        OS << " _Nullable";
      else if (T->getAttrKind() == clang::attr::TypeNullUnspecified)
        OS << " _Null_unspecified";
      else if (T->getAttrKind() == clang::attr::TypeNullableResult)
        OS << " _Nullable_result";
      else
        llvm_unreachable("unhandled nullability");
      spaceBeforePlaceHolder(OS);
      IdentFn();
    };
  }

  if (T->isMSTypeSpec()) {
    IdentFn = [=, &OS, IdentFn = std::move(IdentFn)] (void) {
      switch (T->getAttrKind()) {
      default: return;
      case clang::attr::Ptr32: OS << " __ptr32"; break;
      case clang::attr::Ptr64: OS << " __ptr64"; break;
      case clang::attr::SPtr: OS << " __sptr"; break;
      case clang::attr::UPtr: OS << " __uptr"; break;
      }
      spaceBeforePlaceHolder(OS);
      IdentFn();
    };
  }

  SaveAndRestore<bool> MaybeSuppressCC(InsideCCAttribute, T->isCallingConv());
  switch (T->getAttrKind()) {

    // Prefer the macro forms of the GC and ownership qualifiers.
    case clang::attr::ObjCGC:
    case clang::attr::ObjCOwnership:
      printBeforeAfter(T->getEquivalentType(), OS, std::move(IdentFn));
      return;

    // Don't print the inert __unsafe_unretained attribute at all.
    case clang::attr::ObjCInertUnsafeUnretained:
      printBeforeAfter(T->getModifiedType(), OS, std::move(IdentFn));
      break;

    case clang::attr::ObjCKindOf:
      OS << "__kindof ";
      printBeforeAfter(T->getModifiedType(), OS, std::move(IdentFn));
      return;

    case clang::attr::LifetimeBound:
      printBeforeAfter(T->getModifiedType(), OS, std::move(IdentFn));
      OS << " [[clang::lifetimebound]]";
      break;

    case clang::attr::AddressSpace:
      // The printing of the address_space attribute is handled by the qualifier
      // since it is still stored in the qualifier. Return early to prevent printing
      // this twice.
      printBeforeAfter(T->getModifiedType(), OS, std::move(IdentFn));
      return;

    case clang::attr::AnnotateType:
      // FIXME: Print the attribute arguments once we have a way to retrieve these
      // here. For the meantime, we just print `[[clang::annotate_type(...)]]`
      // without the arguments so that we know at least that we had _some_
      // annotation on the type.
      OS << " [[clang::annotate_type(...)]]";
      return;

    default:
      printBeforeAfter(T->getModifiedType(), OS, std::move(IdentFn));

      // Some attributes are printed as qualifiers before the type, so we have
      // nothing left to do.
      if (T->isMSTypeSpec() || T->getImmediateNullability()) {
        return;
      }

      // Don't print ns_returns_retained unless it had an effect.
      if (T->getAttrKind() == clang::attr::NSReturnsRetained &&
          !T->getEquivalentType()->castAs<clang::FunctionType>()
                                 ->getExtInfo().getProducesResult()) {
        return;
      }

      OS << " __attribute__((";
      switch (T->getAttrKind()) {
#define TYPE_ATTR(NAME)
#define DECL_OR_TYPE_ATTR(NAME)
#define ATTR(NAME) case clang::attr::NAME:
#include "clang/Basic/AttrList.inc"
          llvm_unreachable("non-type attribute attached to type");

        case clang::attr::BTFTypeTag:
          llvm_unreachable("BTFTypeTag attribute handled separately");

        case clang::attr::OpenCLPrivateAddressSpace:
        case clang::attr::OpenCLGlobalAddressSpace:
        case clang::attr::OpenCLGlobalDeviceAddressSpace:
        case clang::attr::OpenCLGlobalHostAddressSpace:
        case clang::attr::OpenCLLocalAddressSpace:
        case clang::attr::OpenCLConstantAddressSpace:
        case clang::attr::OpenCLGenericAddressSpace:
        case clang::attr::HLSLGroupSharedAddressSpace:
          // FIXME: Update printAttributedBefore to print these once we generate
          // AttributedType nodes for them.
          break;

        case clang::attr::LifetimeBound:
        case clang::attr::TypeNonNull:
        case clang::attr::TypeNullable:
        case clang::attr::TypeNullableResult:
        case clang::attr::TypeNullUnspecified:
        case clang::attr::ObjCGC:
        case clang::attr::ObjCInertUnsafeUnretained:
        case clang::attr::ObjCKindOf:
        case clang::attr::ObjCOwnership:
        case clang::attr::Ptr32:
        case clang::attr::Ptr64:
        case clang::attr::SPtr:
        case clang::attr::UPtr:
        case clang::attr::AddressSpace:
        case clang::attr::CmseNSCall:
        case clang::attr::AnnotateType:
          llvm_unreachable("This attribute should have been handled already");

        case clang::attr::NSReturnsRetained:
          OS << "ns_returns_retained";
          break;

        // FIXME: When Sema learns to form this AttributedType, avoid printing the
        // attribute again in printFunctionProtoAfter.
        case clang::attr::AnyX86NoCfCheck: OS << "nocf_check"; break;
        case clang::attr::CDecl: OS << "cdecl"; break;
        case clang::attr::FastCall: OS << "fastcall"; break;
        case clang::attr::StdCall: OS << "stdcall"; break;
        case clang::attr::ThisCall: OS << "thiscall"; break;
        case clang::attr::SwiftCall: OS << "swiftcall"; break;
        case clang::attr::SwiftAsyncCall: OS << "swiftasynccall"; break;
        case clang::attr::VectorCall: OS << "vectorcall"; break;
        case clang::attr::Pascal: OS << "pascal"; break;
        case clang::attr::MSABI: OS << "ms_abi"; break;
        case clang::attr::SysVABI: OS << "sysv_abi"; break;
        case clang::attr::RegCall: OS << "regcall"; break;
        case clang::attr::Pcs: {
          OS << "pcs(";
         clang::QualType t = T->getEquivalentType();
         while (!t->isFunctionType())
           t = t->getPointeeType();
         OS << (t->castAs<clang::FunctionType>()->getCallConv() == clang::CC_AAPCS ?
               "\"aapcs\"" : "\"aapcs-vfp\"");
         OS << ')';
         break;
        }
        case clang::attr::AArch64VectorPcs: OS << "aarch64_vector_pcs"; break;
        case clang::attr::AArch64SVEPcs: OS << "aarch64_sve_pcs"; break;
        case clang::attr::AMDGPUKernelCall: OS << "amdgpu_kernel"; break;
        case clang::attr::IntelOclBicc: OS << "inteloclbicc"; break;
        case clang::attr::PreserveMost:
          OS << "preserve_most";
          break;

        case clang::attr::PreserveAll:
          OS << "preserve_all";
          break;
        case clang::attr::NoDeref:
          OS << "noderef";
          break;
        case clang::attr::AcquireHandle:
          OS << "acquire_handle";
          break;
        case clang::attr::ArmMveStrictPolymorphism:
          OS << "__clang_arm_mve_strict_polymorphism";
          break;
        }
        OS << "))";
      return;
  }
}

void TypePrinter::printBTFTagAttributed(const clang::BTFTagAttributedType *T,
                                        raw_string_ostream &OS,
                                        std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  printBeforeAfter(T->getWrappedType(), OS,
                   [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
    TokenPrinterContext jump_up_stack(ctx);
    OS << " btf_type_tag(" << T->getAttr()->getBTFTypeTag() << ")";
    IdentFn();
  });
}

void TypePrinter::printObjCInterface(const clang::ObjCInterfaceType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  OS << T->getDecl()->getName();
  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printObjCTypeParam(const clang::ObjCTypeParamType *T,
                                     raw_string_ostream &OS,
                                     std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  OS << T->getDecl()->getName();
  if (!T->qual_empty()) {
    bool isFirst = true;
    OS << '<';
    for (const auto *I : T->quals()) {
      if (isFirst)
        isFirst = false;
      else
        OS << ',';
      OS << I->getName();
    }
    OS << '>';
  }

  spaceBeforePlaceHolder(OS);
  IdentFn();
}

void TypePrinter::printObjCObject(const clang::ObjCObjectType *T,
                                  raw_string_ostream &OS,
                                  std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);
  if (T->qual_empty() && T->isUnspecializedAsWritten() &&
      !T->isKindOfTypeAsWritten())
    return printBeforeAfter(T->getBaseType(), OS, std::move(IdentFn));

  if (T->isKindOfTypeAsWritten())
    OS << "__kindof ";

  print(T->getBaseType(), clang::StringRef());

  if (T->isSpecializedAsWritten()) {
    bool isFirst = true;
    OS << '<';
    for (auto typeArg : T->getTypeArgsAsWritten()) {
      if (isFirst)
        isFirst = false;
      else
        OS << ",";

      print(typeArg, clang::StringRef());
    }
    OS << '>';
  }

  if (!T->qual_empty()) {
    bool isFirst = true;
    OS << '<';
    for (const auto *I : T->quals()) {
      if (isFirst)
        isFirst = false;
      else
        OS << ',';
      OS << I->getName();
    }
    OS << '>';
  }

  spaceBeforePlaceHolder(OS);

  IdentFn();
}

void TypePrinter::printObjCObjectPointer(const clang::ObjCObjectPointerType *T,
                                         raw_string_ostream &OS,
                                         std::function<void(void)> IdentFn) {
  TokenPrinterContext ctx(OS, T, tokens);

  if (!T->isObjCIdType() && !T->isObjCQualifiedIdType() &&
      !T->isObjCClassType() && !T->isObjCQualifiedClassType()) {
    IdentFn = [=, &OS, &ctx, IdentFn = std::move(IdentFn)] (void) {
      // If we need to print the pointer, print it now.
      {
        if (HasEmptyPlaceHolder)
          OS << ' ';

        TokenPrinterContext jump_up_stack(ctx, no_alias_tag{});
        OS << '*';
      }
      IdentFn();
    };
  }

  printBeforeAfter(T->getPointeeType(), OS, std::move(IdentFn));
}

PrintedTokenRange PrintedTokenRange::Create(clang::ASTContext &context,
                                            const clang::PrintingPolicy &policy,
                                            const clang::QualType &type) {
  std::string data;
  raw_string_ostream out(data, 0);
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);

  if (!type.isNull()) {
    PrintingPolicyAdaptor ppa;
    tokens->ppa = &ppa;
    TypePrinter printer(out, policy, *tokens);
    printer.print(type, "", nullptr);
    tokens->ppa = nullptr;
  }

  tokens->tokens.emplace_back(
      0u, 0u, kInvalidTokenContextIndex, 0u, 0u, clang::tok::eof);

  auto num_tokens = tokens->tokens.size();
  auto first = &(tokens->tokens[0]);
  auto after_last = &(first[num_tokens - 1u]);
  return PrintedTokenRange(std::move(tokens), first, after_last);
}

PrintedTokenRange PrintedTokenRange::Create(const std::shared_ptr<ASTImpl> &ast,
                                            const clang::QualType &type,
                                            const PrintingPolicy &pp) {
  std::string data;
  raw_string_ostream out(data, 0);
  auto &context = ast->tu->getASTContext();
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);

  // Top-level context should be the AST.
  tokens->ast = ast;
  tokens->contexts.emplace_back(*ast);

  if (!type.isNull()) {
    PrintingPolicyAdaptor ppa(ast, pp);
    tokens->ppa = &ppa;

    clang::PrintingPolicy pp = *(ast->printing_policy);
    TypePrinter printer(out, pp, *tokens);
    printer.print(type, "", nullptr);
    tokens->ppa = nullptr;
  }

  // Fixup to share the AST as the root context.
  auto max_i = tokens->contexts.size();
  for (auto i = 1u; i < max_i; ++i) {
    TokenContextImpl &context = tokens->contexts[i];
    if (context.parent_index == kInvalidTokenContextIndex) {
      context.parent_index = kASTTokenContextIndex;
    }
  }

  tokens->tokens.emplace_back(
      0u, 0u, kInvalidTokenContextIndex, 0u, 0u, clang::tok::eof);

  auto num_tokens = tokens->tokens.size();
  auto first = &(tokens->tokens[0]);
  auto after_last = &(first[num_tokens - 1u]);

  for (auto tok = first; tok < after_last; ++tok) {
    if (tok->context_index == kInvalidTokenContextIndex) {
      tok->context_index = kASTTokenContextIndex;
    }

#ifndef NDEBUG
    if (tok->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      assert(tok->derived_index != kInvalidDerivedTokenIndex);
    }
#endif
  }

  return PrintedTokenRange(std::move(tokens), first, after_last);
}

}  // namespace pasta
