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
        : Policy(Policy), Old(Policy.SuppressStrongLifetime) {
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
        : Policy(Policy), Old(Policy.SuppressSpecifiers) {
      Policy.SuppressSpecifiers = false;
    }

    ~ParamPolicyRAII() {
      Policy.SuppressSpecifiers = Old;
    }
  };

  class ElaboratedTypePolicyRAII {
    clang::PrintingPolicy &Policy;
    bool SuppressTagKeyword;
    bool SuppressScope;

  public:
    explicit ElaboratedTypePolicyRAII(clang::PrintingPolicy &Policy) : Policy(Policy) {
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
  template <typename T> struct SaveAndRestore {
    SaveAndRestore(T &X) : X(X), OldValue(X) {}
    SaveAndRestore(T &X, const T &NewValue) : X(X), OldValue(X) {
      X = NewValue;
    }
    ~SaveAndRestore() { X = OldValue; }
    T get() { return OldValue; }

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
                        raw_string_ostream &OS,
                        clang::StringRef PlaceHolder,
                        std::function<std::string(void)> *placeHolderFn) {
  clang::SplitQualType split = splitAccordingToPolicy(t, Policy);
  print(split.Ty, split.Quals, OS, PlaceHolder, placeHolderFn);
}

void TypePrinter::print(const clang::Type *T,
                        clang::Qualifiers Quals,
                        raw_string_ostream &OS,
                        clang::StringRef PlaceHolder,
                        std::function<std::string(void)> *placeHolderFn) {
  if (!T) {
    OS << "NULL TYPE";
    return;
  }

  SaveAndRestore<bool> PHVal(HasEmptyPlaceHolder, PlaceHolder.empty());

  printBefore(T, Quals, OS);
  if (placeHolderFn != nullptr) {
    OS << (*placeHolderFn)();
  } else {
    OS << PlaceHolder;
  }
  printAfter(T, Quals, OS);
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
  clang::Type::TypeClass TC = T->getTypeClass();
  if (const auto *AT = clang::dyn_cast<clang::AutoType>(T))
    TC = AT->desugar()->getTypeClass();
  if (const auto *Subst = clang::dyn_cast<clang::SubstTemplateTypeParmType>(T))
    TC = Subst->getReplacementType()->getTypeClass();

  switch (TC) {
    case clang::Type::Auto:
    case clang::Type::Builtin:
    case clang::Type::Complex:
    case clang::Type::UnresolvedUsing:
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
    case clang::Type::ExtInt:
    case clang::Type::DependentExtInt:
      CanPrefixQualifiers = true;
      break;

    case clang::Type::ObjCObjectPointer:
      CanPrefixQualifiers = T->isObjCIdType() || T->isObjCClassType() ||
        T->isObjCQualifiedIdType() || T->isObjCQualifiedClassType();
      break;

    case clang::Type::ConstantArray:
    case clang::Type::IncompleteArray:
    case clang::Type::VariableArray:
    case clang::Type::DependentSizedArray:
      NeedARCStrongQualifier = true;
      LLVM_FALLTHROUGH;

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
      const auto *AttrTy = clang::cast<clang::AttributedType>(T);
      CanPrefixQualifiers = AttrTy->getAttrKind() == clang::attr::AddressSpace;
    }
  }

  return CanPrefixQualifiers;
}

void TypePrinter::printBefore(clang::QualType T, raw_string_ostream &OS) {
  clang::SplitQualType Split = splitAccordingToPolicy(T, Policy);

  // If we have cv1 T, where T is substituted for cv2 U, only print cv1 - cv2
  // at this level.
  clang::Qualifiers Quals = Split.Quals;
  if (const auto *Subst = clang::dyn_cast<clang::SubstTemplateTypeParmType>(Split.Ty))
    Quals -= clang::QualType(Subst, 0).getQualifiers();

  printBefore(Split.Ty, Quals, OS);
}

/// Prints the part of the type string before an identifier, e.g. for
/// "int foo[10]" it prints "int ".
void TypePrinter::printBefore(const clang::Type *T, clang::Qualifiers Quals, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (Policy.SuppressSpecifiers && T->isSpecifierType())
    return;

  SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder);

  // Print qualifiers as appropriate.

  bool CanPrefixQualifiers = false;
  bool NeedARCStrongQualifier = false;
  CanPrefixQualifiers = canPrefixQualifiers(T, NeedARCStrongQualifier);

  if (CanPrefixQualifiers && !Quals.empty()) {
    if (NeedARCStrongQualifier) {
      IncludeStrongLifetimeRAII Strong(Policy);
      Quals.print(OS, Policy, /*appendSpaceIfNonEmpty=*/true);
    } else {
      Quals.print(OS, Policy, /*appendSpaceIfNonEmpty=*/true);
    }
  }

  bool hasAfterQuals = false;
  if (!CanPrefixQualifiers && !Quals.empty()) {
    hasAfterQuals = !Quals.isEmptyWhenPrinted(Policy);
    if (hasAfterQuals)
      HasEmptyPlaceHolder = false;
  }

  switch (T->getTypeClass()) {
#define ABSTRACT_TYPE(CLASS, PARENT)
#define TYPE(CLASS, PARENT) case clang::Type::CLASS: \
    print##CLASS##Before(clang::cast<clang::CLASS##Type>(T), OS); \
    break;
#include "clang/AST/TypeNodes.inc"
  }

  if (hasAfterQuals) {
    if (NeedARCStrongQualifier) {
      IncludeStrongLifetimeRAII Strong(Policy);
      Quals.print(OS, Policy, /*appendSpaceIfNonEmpty=*/!PrevPHIsEmpty.get());
    } else {
      Quals.print(OS, Policy, /*appendSpaceIfNonEmpty=*/!PrevPHIsEmpty.get());
    }
  }
}

void TypePrinter::printAfter(clang::QualType t, raw_string_ostream &OS) {
  clang::SplitQualType split = splitAccordingToPolicy(t, Policy);
  printAfter(split.Ty, split.Quals, OS);
}

/// Prints the part of the type string after an identifier, e.g. for
/// "int foo[10]" it prints "[10]".
void TypePrinter::printAfter(const clang::Type *T, clang::Qualifiers Quals, raw_string_ostream &OS) {
  switch (T->getTypeClass()) {
#define ABSTRACT_TYPE(CLASS, PARENT)
#define TYPE(CLASS, PARENT) case clang::Type::CLASS: \
    print##CLASS##After(clang::cast<clang::CLASS##Type>(T), OS); \
    break;
#include "clang/AST/TypeNodes.inc"
  }
}

void TypePrinter::printBuiltinBefore(const clang::BuiltinType *T, raw_string_ostream &OS) {
  OS << T->getName(Policy);
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printBuiltinAfter(const clang::BuiltinType *T, raw_string_ostream &OS) {}

void TypePrinter::printComplexBefore(const clang::ComplexType *T, raw_string_ostream &OS) {
  OS << "_Complex ";
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printComplexAfter(const clang::ComplexType *T, raw_string_ostream &OS) {
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printPointerBefore(const clang::PointerType *T, raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getPointeeType(), OS);
  // Handle things like 'int (*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << '(';
  OS << '*';
}

void TypePrinter::printPointerAfter(const clang::PointerType *T, raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  // Handle things like 'int (*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << ')';
  printAfter(T->getPointeeType(), OS);
}

void TypePrinter::printBlockPointerBefore(const clang::BlockPointerType *T,
                                          raw_string_ostream &OS) {
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getPointeeType(), OS);
  OS << '^';
}

void TypePrinter::printBlockPointerAfter(const clang::BlockPointerType *T,
                                          raw_string_ostream &OS) {
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printAfter(T->getPointeeType(), OS);
}

// When printing a reference, the referenced type might also be a reference.
// If so, we want to skip that before printing the inner type.
static clang::QualType skipTopLevelReferences(clang::QualType T) {
  if (auto *Ref = T->getAs<clang::ReferenceType>())
    return skipTopLevelReferences(Ref->getPointeeTypeAsWritten());
  return T;
}

void TypePrinter::printLValueReferenceBefore(const clang::LValueReferenceType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  printBefore(Inner, OS);
  // Handle things like 'int (&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner))
    OS << '(';
  OS << '&';
}

void TypePrinter::printLValueReferenceAfter(const clang::LValueReferenceType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  // Handle things like 'int (&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner))
    OS << ')';
  printAfter(Inner, OS);
}

void TypePrinter::printRValueReferenceBefore(const clang::RValueReferenceType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  printBefore(Inner, OS);
  // Handle things like 'int (&&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner))
    OS << '(';
  OS << "&&";
}

void TypePrinter::printRValueReferenceAfter(const clang::RValueReferenceType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  // Handle things like 'int (&&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner))
    OS << ')';
  printAfter(Inner, OS);
}

void TypePrinter::printMemberPointerBefore(const clang::MemberPointerType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getPointeeType(), OS);
  // Handle things like 'int (Cls::*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << '(';

  clang::PrintingPolicy InnerPolicy(Policy);
  InnerPolicy.IncludeTagDefinition = false;
  TypePrinter(InnerPolicy, tokens).print(clang::QualType(T->getClass(), 0), OS, clang::StringRef());

  OS << "::*";
}

void TypePrinter::printMemberPointerAfter(const clang::MemberPointerType *T,
                                          raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  // Handle things like 'int (Cls::*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << ')';
  printAfter(T->getPointeeType(), OS);
}

void TypePrinter::printConstantArrayBefore(const clang::ConstantArrayType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printConstantArrayAfter(const clang::ConstantArrayType *T,
                                          raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << '[';
  if (T->getIndexTypeQualifiers().hasQualifiers()) {
    AppendTypeQualList(OS, T->getIndexTypeCVRQualifiers(),
                       Policy.Restrict);
    OS << ' ';
  }

  if (T->getSizeModifier() == clang::ArrayType::Static)
    OS << "static ";

  OS << T->getSize().getZExtValue() << ']';
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printIncompleteArrayBefore(const clang::IncompleteArrayType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}


void TypePrinter::printIncompleteArrayAfter(const clang::IncompleteArrayType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << "[]";
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printVariableArrayBefore(const clang::VariableArrayType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printVariableArrayAfter(const clang::VariableArrayType *T,
                                          raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << '[';
  if (T->getIndexTypeQualifiers().hasQualifiers()) {
    AppendTypeQualList(OS, T->getIndexTypeCVRQualifiers(), Policy.Restrict);
    OS << ' ';
  }

  if (T->getSizeModifier() == clang::VariableArrayType::Static)
    OS << "static ";
  else if (T->getSizeModifier() == clang::VariableArrayType::Star)
    OS << '*';

  if (T->getSizeExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getSizeExpr()));
  }
  OS << ']';

  printAfter(T->getElementType(), OS);
}

void TypePrinter::printAdjustedBefore(const clang::AdjustedType *T, raw_string_ostream &OS) {
  // Print the adjusted representation, otherwise the adjustment will be
  // invisible.
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getAdjustedType(), OS);
}

void TypePrinter::printAdjustedAfter(const clang::AdjustedType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getAdjustedType(), OS);
}

void TypePrinter::printDecayedBefore(const clang::DecayedType *T, raw_string_ostream &OS) {
  // Print as though it's a pointer.
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAdjustedBefore(T, OS);
}

void TypePrinter::printDecayedAfter(const clang::DecayedType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAdjustedAfter(T, OS);
}

void TypePrinter::printDependentSizedArrayBefore(
    const clang::DependentSizedArrayType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printDependentSizedArrayAfter(
    const clang::DependentSizedArrayType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << '[';
  if (T->getSizeExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getSizeExpr()));
  }
  OS << ']';
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printDependentAddressSpaceBefore(
    const clang::DependentAddressSpaceType *T, raw_string_ostream &OS) {
  printBefore(T->getPointeeType(), OS);
}

void TypePrinter::printDependentAddressSpaceAfter(
    const clang::DependentAddressSpaceType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << " __attribute__((address_space(";
  if (T->getAddrSpaceExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getAddrSpaceExpr()));
  }
  OS << ")))";
  printAfter(T->getPointeeType(), OS);
}

void TypePrinter::printDependentSizedExtVectorBefore(
    const clang::DependentSizedExtVectorType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printDependentSizedExtVectorAfter(
    const clang::DependentSizedExtVectorType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << " __attribute__((ext_vector_type(";
  if (T->getSizeExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getSizeExpr()));
  }
  OS << ")))";
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printVectorBefore(const clang::VectorType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  switch (T->getVectorKind()) {
  case clang::VectorType::AltiVecPixel:
    OS << "__vector __pixel ";
    break;
  case clang::VectorType::AltiVecBool:
    OS << "__vector __bool ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::AltiVecVector:
    OS << "__vector ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::NeonVector:
    OS << "__attribute__((neon_vector_type("
       << T->getNumElements() << "))) ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::NeonPolyVector:
    OS << "__attribute__((neon_polyvector_type(" <<
          T->getNumElements() << "))) ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::GenericVector: {
    // FIXME: We prefer to print the size directly here, but have no way
    // to get the size of the type.
    OS << "__attribute__((__vector_size__("
       << T->getNumElements()
       << " * sizeof(";
    print(T->getElementType(), OS, clang::StringRef());
    OS << ")))) ";
    printBefore(T->getElementType(), OS);
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
    print(T->getElementType(), OS, clang::StringRef());
    // Multiply by 8 for the number of bits.
    OS << ") * 8))) ";
    printBefore(T->getElementType(), OS);
  }
}

void TypePrinter::printVectorAfter(const clang::VectorType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printDependentVectorBefore(
    const clang::DependentVectorType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  switch (T->getVectorKind()) {
  case clang::VectorType::AltiVecPixel:
    OS << "__vector __pixel ";
    break;
  case clang::VectorType::AltiVecBool:
    OS << "__vector __bool ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::AltiVecVector:
    OS << "__vector ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::NeonVector:
    OS << "__attribute__((neon_vector_type(";
    if (T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getSizeExpr()));
    }
    OS << "))) ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::NeonPolyVector:
    OS << "__attribute__((neon_polyvector_type(";
    if (T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getSizeExpr()));
    }
    OS << "))) ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::GenericVector: {
    // FIXME: We prefer to print the size directly here, but have no way
    // to get the size of the type.
    OS << "__attribute__((__vector_size__(";
    if (T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getSizeExpr()));
    }
    OS << " * sizeof(";
    print(T->getElementType(), OS, clang::StringRef());
    OS << ")))) ";
    printBefore(T->getElementType(), OS);
    break;
  }
  case clang::VectorType::SveFixedLengthDataVector:
  case clang::VectorType::SveFixedLengthPredicateVector:
    // FIXME: We prefer to print the size directly here, but have no way
    // to get the size of the type.
    OS << "__attribute__((__arm_sve_vector_bits__(";
    if (T->getSizeExpr()) {
      StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                              &(tokens.ast_context));
      stmtPrinter.Visit((T->getSizeExpr()));

      if (T->getVectorKind() == clang::VectorType::SveFixedLengthPredicateVector)
        // Predicates take a bit per byte of the vector size, multiply by 8 to
        // get the number of bits passed to the attribute.
        OS << " * 8";
      OS << " * sizeof(";
      print(T->getElementType(), OS, clang::StringRef());
      // Multiply by 8 for the number of bits.
      OS << ") * 8";
    }
    OS << "))) ";
    printBefore(T->getElementType(), OS);
  }
}

void TypePrinter::printDependentVectorAfter(const clang::DependentVectorType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printExtVectorBefore(const clang::ExtVectorType *T,
                                       raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printExtVectorAfter(const clang::ExtVectorType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getElementType(), OS);
  OS << " __attribute__((ext_vector_type(";
  OS << T->getNumElements();
  OS << ")))";
}

void TypePrinter::printConstantMatrixBefore(const clang::ConstantMatrixType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getElementType(), OS);
  OS << " __attribute__((matrix_type(";
  OS << T->getNumRows() << ", " << T->getNumColumns();
  OS << ")))";
}

void TypePrinter::printConstantMatrixAfter(const clang::ConstantMatrixType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printDependentSizedMatrixBefore(const clang::DependentSizedMatrixType *T,
                                                  raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getElementType(), OS);
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
}

void TypePrinter::printDependentSizedMatrixAfter(const clang::DependentSizedMatrixType *T,
                                                 raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printFunctionProtoBefore(const clang::FunctionProtoType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (T->hasTrailingReturn()) {
    OS << "auto ";
    if (!HasEmptyPlaceHolder)
      OS << '(';
  } else {
    // If needed for precedence reasons, wrap the inner part in grouping parens.
    SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder, false);
    printBefore(T->getReturnType(), OS);
    if (!PrevPHIsEmpty.get())
      OS << '(';
  }
}

static void FunctionProtoType_printExceptionSpecification(
    const clang::FunctionProtoType *T, PrintedTokenRangeImpl &tokens,
    raw_string_ostream &OS,
    const clang::PrintingPolicy &Policy) {
  if (T->hasDynamicExceptionSpec()) {
    OS << " throw(";
    if (T->getExceptionSpecType() == clang::EST_MSAny)
      OS << "...";
    else
      for (unsigned I = 0, N = T->getNumExceptions(); I != N; ++I) {
        if (I)
          OS << ", ";

        TypePrinter printer(Policy, tokens, 0);
        printer.print(T->getExceptionType(I), OS, "", nullptr);
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

void TypePrinter::printFunctionProtoAfter(const clang::FunctionProtoType *T,
                                          raw_string_ostream &OS) {
  // If needed for precedence reasons, wrap the inner part in grouping parens.
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (!HasEmptyPlaceHolder)
    OS << ')';
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);

  OS << '(';
  {
    ParamPolicyRAII ParamPolicy(Policy);
    for (unsigned i = 0, e = T->getNumParams(); i != e; ++i) {
      if (i) OS << ", ";

      auto EPI = T->getExtParameterInfo(i);
      if (EPI.isConsumed()) OS << "__attribute__((ns_consumed)) ";
      if (EPI.isNoEscape())
        OS << "__attribute__((noescape)) ";
      auto ABI = EPI.getABI();
      if (ABI != clang::ParameterABI::Ordinary)
        OS << "__attribute__((" << clang::getParameterABISpelling(ABI) << ")) ";

      print(T->getParamType(i), OS, clang::StringRef());
    }
  }

  if (T->isVariadic()) {
    if (T->getNumParams())
      OS << ", ";
    OS << "...";
  } else if (T->getNumParams() == 0 && Policy.UseVoidForZeroParams) {
    // Do not emit int() if we have a proto, emit 'int(void)'.
    OS << "void";
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

  if (T->hasTrailingReturn()) {
    OS << " -> ";
    print(T->getReturnType(), OS, clang::StringRef());
  } else
    printAfter(T->getReturnType(), OS);
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

void TypePrinter::printFunctionNoProtoBefore(const clang::FunctionNoProtoType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // If needed for precedence reasons, wrap the inner part in grouping parens.
  SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder, false);
  printBefore(T->getReturnType(), OS);
  if (!PrevPHIsEmpty.get())
    OS << '(';
}

void TypePrinter::printFunctionNoProtoAfter(const clang::FunctionNoProtoType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // If needed for precedence reasons, wrap the inner part in grouping parens.
  if (!HasEmptyPlaceHolder)
    OS << ')';
  SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);

  OS << "()";
  printFunctionAfter(T->getExtInfo(), OS);
  printAfter(T->getReturnType(), OS);
}

void TypePrinter::printTypeSpec(clang::NamedDecl *D, raw_string_ostream &OS) {

  TokenPrinterContext ctx(OS, D, tokens, __FUNCTION__);

  // Compute the full nested-name-specifier for this type.
  // In C, this will always be empty except when the type
  // being printed is anonymous within other Record.
  if (!Policy.SuppressScope)
    AppendScope(D->getDeclContext(), OS, D->getDeclName());

  clang::IdentifierInfo *II = D->getIdentifier();
  OS << II->getName();
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printUnresolvedUsingBefore(const clang::UnresolvedUsingType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printTypeSpec(T->getDecl(), OS);
}

void TypePrinter::printUnresolvedUsingAfter(const clang::UnresolvedUsingType *T,
                                            raw_string_ostream &OS) {}

void TypePrinter::printTypedefBefore(const clang::TypedefType *T,
                                     raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printTypeSpec(T->getDecl(), OS);
}

void TypePrinter::printMacroQualifiedBefore(const clang::MacroQualifiedType *T,
                                            raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  clang::StringRef MacroName = T->getMacroIdentifier()->getName();
  OS << MacroName << " ";

  // Since this type is meant to print the macro instead of the whole attribute,
  // we trim any attributes and go directly to the original modified type.
  printBefore(T->getModifiedType(), OS);
}

void TypePrinter::printMacroQualifiedAfter(const clang::MacroQualifiedType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getModifiedType(), OS);
}

void TypePrinter::printTypedefAfter(const clang::TypedefType *T, raw_string_ostream &OS) {}

void TypePrinter::printTypeOfExprBefore(const clang::TypeOfExprType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << "typeof ";
  if (T->getUnderlyingExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getUnderlyingExpr()));
  }
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTypeOfExprAfter(const clang::TypeOfExprType *T,
                                       raw_string_ostream &OS) {}

void TypePrinter::printTypeOfBefore(const clang::TypeOfType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << "typeof(";
  print(T->getUnderlyingType(), OS, clang::StringRef());
  OS << ')';
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTypeOfAfter(const clang::TypeOfType *T, raw_string_ostream &OS) {}

void TypePrinter::printDecltypeBefore(const clang::DecltypeType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << "decltype(";
  if (T->getUnderlyingExpr()) {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getUnderlyingExpr()));
  }
  OS << ')';
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printDecltypeAfter(const clang::DecltypeType *T, raw_string_ostream &OS) {}

void TypePrinter::printUnaryTransformBefore(const clang::UnaryTransformType *T,
                                            raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);

  switch (T->getUTTKind()) {
    case clang::UnaryTransformType::EnumUnderlyingType:
      OS << "__underlying_type(";
      print(T->getBaseType(), OS, clang::StringRef());
      OS << ')';
      spaceBeforePlaceHolder(OS);
      return;
  }

  printBefore(T->getBaseType(), OS);
}

void TypePrinter::printUnaryTransformAfter(const clang::UnaryTransformType *T,
                                           raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);

  switch (T->getUTTKind()) {
    case clang::UnaryTransformType::EnumUnderlyingType:
      return;
  }

  printAfter(T->getBaseType(), OS);
}

void TypePrinter::printAutoBefore(const clang::AutoType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);

  // If the type has been deduced, do not print 'auto'.
  if (!T->getDeducedType().isNull()) {
    printBefore(T->getDeducedType(), OS);
  } else {
    if (T->isConstrained()) {
      // FIXME: Track a TypeConstraint as type sugar, so that we can print the
      // type as it was written.
      T->getTypeConstraintConcept()->getDeclName().print(OS, Policy);
      auto Args = T->getTypeConstraintArguments();
      if (!Args.empty())
        printTemplateArgumentList(
            OS, Args, Policy,
            T->getTypeConstraintConcept()->getTemplateParameters());
      OS << ' ';
    }
    switch (T->getKeyword()) {
    case clang::AutoTypeKeyword::Auto: OS << "auto"; break;
    case clang::AutoTypeKeyword::DecltypeAuto: OS << "decltype(auto)"; break;
    case clang::AutoTypeKeyword::GNUAutoType: OS << "__auto_type"; break;
    }
    spaceBeforePlaceHolder(OS);
  }
}

void TypePrinter::printAutoAfter(const clang::AutoType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // If the type has been deduced, do not print 'auto'.
  if (!T->getDeducedType().isNull())
    printAfter(T->getDeducedType(), OS);
}

void TypePrinter::printDeducedTemplateSpecializationBefore(
    const clang::DeducedTemplateSpecializationType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // If the type has been deduced, print the deduced type.
  if (!T->getDeducedType().isNull()) {
    printBefore(T->getDeducedType(), OS);
  } else {
    IncludeStrongLifetimeRAII Strong(Policy);
    T->getTemplateName().print(OS, Policy);
    spaceBeforePlaceHolder(OS);
  }
}

void TypePrinter::printDeducedTemplateSpecializationAfter(
    const clang::DeducedTemplateSpecializationType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // If the type has been deduced, print the deduced type.
  if (!T->getDeducedType().isNull())
    printAfter(T->getDeducedType(), OS);
}

void TypePrinter::printAtomicBefore(const clang::AtomicType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);

  IncludeStrongLifetimeRAII Strong(Policy);
  OS << "_Atomic(";
  print(T->getValueType(), OS, clang::StringRef());
  OS << ')';
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printAtomicAfter(const clang::AtomicType *T, raw_string_ostream &OS) {}

void TypePrinter::printPipeBefore(const clang::PipeType *T, raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);

  if (T->isReadOnly())
    OS << "read_only ";
  else
    OS << "write_only ";
  OS << "pipe ";
  print(T->getElementType(), OS, clang::StringRef());
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printPipeAfter(const clang::PipeType *T, raw_string_ostream &OS) {}

void TypePrinter::printExtIntBefore(const clang::ExtIntType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (T->isUnsigned())
    OS << "unsigned ";
  OS << "_ExtInt(" << T->getNumBits() << ")";
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printExtIntAfter(const clang::ExtIntType *T, raw_string_ostream &OS) {}

void TypePrinter::printDependentExtIntBefore(const clang::DependentExtIntType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (T->isUnsigned())
    OS << "unsigned ";
  OS << "_ExtInt(";
  {
    StmtPrinter stmtPrinter(OS, nullptr, tokens, Policy, 0, "\n",
                            &(tokens.ast_context));
    stmtPrinter.Visit((T->getNumBitsExpr()));
  }
  OS << ")";
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printDependentExtIntAfter(const clang::DependentExtIntType *T,
                                            raw_string_ostream &OS) {}

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
        DC->getParent()->lookup(NameInScope).size() ==
            DC->lookup(NameInScope).size())
      return AppendScope(DC->getParent(), OS, NameInScope);

    AppendScope(DC->getParent(), OS, NS->getDeclName());
    if (NS->getIdentifier())
      OS << NS->getName() << "::";
    else
      OS << "(anonymous namespace)::";
  } else if (const auto *Spec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(DC)) {
    AppendScope(DC->getParent(), OS, Spec->getDeclName());
    IncludeStrongLifetimeRAII Strong(Policy);
    OS << Spec->getIdentifier()->getName();
    const clang::TemplateArgumentList &TemplateArgs = Spec->getTemplateArgs();
    printTemplateArgumentList(
        OS, TemplateArgs.asArray(), Policy,
        Spec->getSpecializedTemplate()->getTemplateParameters());
    OS << "::";
  } else if (const auto *Tag = clang::dyn_cast<clang::TagDecl>(DC)) {
    AppendScope(DC->getParent(), OS, Tag->getDeclName());
    if (clang::TypedefNameDecl *Typedef = Tag->getTypedefNameForAnonDecl())
      OS << Typedef->getIdentifier()->getName() << "::";
    else if (Tag->getIdentifier())
      OS << Tag->getIdentifier()->getName() << "::";
    else
      return;
  } else {
    AppendScope(DC->getParent(), OS, NameInScope);
  }
}

void TypePrinter::printTag(clang::TagDecl *D, raw_string_ostream &OS) {

  if (Policy.IncludeTagDefinition) {
    clang::PrintingPolicy SubPolicy = Policy;
    SubPolicy.IncludeTagDefinition = false;
    DeclPrinter declPrinter(OS, SubPolicy, tokens.ast_context, tokens,
                            Indentation);
    declPrinter.Visit(D);
    spaceBeforePlaceHolder(OS);
    return;
  }

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
        OS, Args, Policy,
        Spec->getSpecializedTemplate()->getTemplateParameters());
  }

  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printRecordBefore(const clang::RecordType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // Print the preferred name if we have one for this type.
  for (const auto *PNA : T->getDecl()->specific_attrs<clang::PreferredNameAttr>()) {
    if (declaresSameEntity(PNA->getTypedefType()->getAsCXXRecordDecl(),
                           T->getDecl())) {
      // Find the outermost typedef or alias template.
      clang::QualType T = PNA->getTypedefType();
      while (true) {
        if (auto *TT = clang::dyn_cast<clang::TypedefType>(T))
          return printTypeSpec(TT->getDecl(), OS);
        if (auto *TST = clang::dyn_cast<clang::TemplateSpecializationType>(T))
          return printTemplateId(TST, OS, /*FullyQualify=*/true);
        T = T->getLocallyUnqualifiedSingleStepDesugaredType();
      }
    }
  }

  printTag(T->getDecl(), OS);
}

void TypePrinter::printRecordAfter(const clang::RecordType *T, raw_string_ostream &OS) {}

void TypePrinter::printEnumBefore(const clang::EnumType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printTag(T->getDecl(), OS);
}

void TypePrinter::printEnumAfter(const clang::EnumType *T, raw_string_ostream &OS) {}

void TypePrinter::printTemplateTypeParmBefore(const clang::TemplateTypeParmType *T,
                                              raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  clang::TemplateTypeParmDecl *D = T->getDecl();
  if (D && D->isImplicit()) {
    TokenPrinterContext ctx2(OS, D, tokens, __FUNCTION__);
    if (auto *TC = D->getTypeConstraint()) {

      TokenPrinterContext ctx(OS, TC, tokens, __FUNCTION__);
      TC->print(OS, Policy);
      OS << ' ';
    }
    OS << "auto";
  } else if (clang::IdentifierInfo *Id = T->getIdentifier())
    OS << Id->getName();
  else
    OS << "type-parameter-" << T->getDepth() << '-' << T->getIndex();

  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTemplateTypeParmAfter(const clang::TemplateTypeParmType *T,
                                             raw_string_ostream &OS) {}

void TypePrinter::printSubstTemplateTypeParmBefore(
                                             const clang::SubstTemplateTypeParmType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  printBefore(T->getReplacementType(), OS);
}

void TypePrinter::printSubstTemplateTypeParmAfter(
                                             const clang::SubstTemplateTypeParmType *T,
                                             raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  printAfter(T->getReplacementType(), OS);
}

void TypePrinter::printSubstTemplateTypeParmPackBefore(
                                        const clang::SubstTemplateTypeParmPackType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  printTemplateTypeParmBefore(T->getReplacedParameter(), OS);
}

void TypePrinter::printSubstTemplateTypeParmPackAfter(
                                        const clang::SubstTemplateTypeParmPackType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);
  printTemplateTypeParmAfter(T->getReplacedParameter(), OS);
}

void TypePrinter::printTemplateId(const clang::TemplateSpecializationType *T,
                                  raw_string_ostream &OS, bool FullyQualify) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);

  clang::TemplateDecl *TD = T->getTemplateName().getAsTemplateDecl();
  if (FullyQualify && TD) {
    if (!Policy.SuppressScope)
      AppendScope(TD->getDeclContext(), OS, TD->getDeclName());

    clang::IdentifierInfo *II = TD->getIdentifier();
    OS << II->getName();
  } else {
    T->getTemplateName().print(OS, Policy);
  }

  printTemplateArgumentList(OS, T->template_arguments(), Policy);
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTemplateSpecializationBefore(
    const clang::TemplateSpecializationType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printTemplateId(T, OS, Policy.FullyQualifiedName);
}

void TypePrinter::printTemplateSpecializationAfter(
                                            const clang::TemplateSpecializationType *T,
                                            raw_string_ostream &OS) {}

void TypePrinter::printInjectedClassNameBefore(const clang::InjectedClassNameType *T,
                                               raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (Policy.PrintInjectedClassNameWithArguments)
    return printTemplateSpecializationBefore(T->getInjectedTST(), OS);

  IncludeStrongLifetimeRAII Strong(Policy);
  T->getTemplateName().print(OS, Policy);
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printInjectedClassNameAfter(const clang::InjectedClassNameType *T,
                                               raw_string_ostream &OS) {}

void TypePrinter::printElaboratedBefore(const clang::ElaboratedType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (Policy.IncludeTagDefinition && T->getOwnedTagDecl()) {
    clang::TagDecl *OwnedTagDecl = T->getOwnedTagDecl();
    assert(OwnedTagDecl->getTypeForDecl() == T->getNamedType().getTypePtr() &&
           "OwnedTagDecl expected to be a declaration for the type");
    clang::PrintingPolicy SubPolicy = Policy;
    SubPolicy.IncludeTagDefinition = false;
    DeclPrinter declPrinter(OS, SubPolicy, tokens.ast_context, tokens,
                            Indentation);
    declPrinter.Visit(OwnedTagDecl);
    spaceBeforePlaceHolder(OS);
    return;
  }

  // The tag definition will take care of these.
  if (!Policy.IncludeTagDefinition)
  {
    OS << clang::TypeWithKeyword::getKeywordName(T->getKeyword());
    if (T->getKeyword() != clang::ETK_None)
      OS << " ";
    clang::NestedNameSpecifier *Qualifier = T->getQualifier();
    if (Qualifier)
      Qualifier->print(OS, Policy);
  }

  ElaboratedTypePolicyRAII PolicyRAII(Policy);
  printBefore(T->getNamedType(), OS);
}

void TypePrinter::printElaboratedAfter(const clang::ElaboratedType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (Policy.IncludeTagDefinition && T->getOwnedTagDecl())
    return;
  ElaboratedTypePolicyRAII PolicyRAII(Policy);
  printAfter(T->getNamedType(), OS);
}

void TypePrinter::printParenBefore(const clang::ParenType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (!HasEmptyPlaceHolder && !clang::isa<clang::FunctionType>(T->getInnerType())) {
    printBefore(T->getInnerType(), OS);
    OS << '(';
  } else
    printBefore(T->getInnerType(), OS);
}

void TypePrinter::printParenAfter(const clang::ParenType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (!HasEmptyPlaceHolder && !clang::isa<clang::FunctionType>(T->getInnerType())) {
    OS << ')';
    printAfter(T->getInnerType(), OS);
  } else
    printAfter(T->getInnerType(), OS);
}

void TypePrinter::printDependentNameBefore(const clang::DependentNameType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << clang::TypeWithKeyword::getKeywordName(T->getKeyword());
  if (T->getKeyword() != clang::ETK_None)
    OS << " ";

  T->getQualifier()->print(OS, Policy);

  OS << T->getIdentifier()->getName();
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printDependentNameAfter(const clang::DependentNameType *T,
                                          raw_string_ostream &OS) {}

void TypePrinter::printDependentTemplateSpecializationBefore(
        const clang::DependentTemplateSpecializationType *T, raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  IncludeStrongLifetimeRAII Strong(Policy);

  OS << clang::TypeWithKeyword::getKeywordName(T->getKeyword());
  if (T->getKeyword() != clang::ETK_None)
    OS << " ";

  if (T->getQualifier())
    T->getQualifier()->print(OS, Policy);
  OS << "template " << T->getIdentifier()->getName();
  printTemplateArgumentList(OS, T->template_arguments(), Policy);
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printDependentTemplateSpecializationAfter(
        const clang::DependentTemplateSpecializationType *T, raw_string_ostream &OS) {}

void TypePrinter::printPackExpansionBefore(const clang::PackExpansionType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getPattern(), OS);
}

void TypePrinter::printPackExpansionAfter(const clang::PackExpansionType *T,
                                          raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printAfter(T->getPattern(), OS);
  OS << "...";
}

void TypePrinter::printAttributedBefore(const clang::AttributedType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // FIXME: Generate this with TableGen.

  // Prefer the macro forms of the GC and ownership qualifiers.
  if (T->getAttrKind() == clang::attr::ObjCGC ||
      T->getAttrKind() == clang::attr::ObjCOwnership)
    return printBefore(T->getEquivalentType(), OS);

  if (T->getAttrKind() == clang::attr::ObjCKindOf)
    OS << "__kindof ";

  if (T->getAttrKind() == clang::attr::AddressSpace)
    printBefore(T->getEquivalentType(), OS);
  else
    printBefore(T->getModifiedType(), OS);

  if (T->isMSTypeSpec()) {
    switch (T->getAttrKind()) {
    default: return;
    case clang::attr::Ptr32: OS << " __ptr32"; break;
    case clang::attr::Ptr64: OS << " __ptr64"; break;
    case clang::attr::SPtr: OS << " __sptr"; break;
    case clang::attr::UPtr: OS << " __uptr"; break;
    }
    spaceBeforePlaceHolder(OS);
  }

  // Print nullability type specifiers.
  if (T->getImmediateNullability()) {
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
  }
}

void TypePrinter::printAttributedAfter(const clang::AttributedType *T,
                                       raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  // FIXME: Generate this with TableGen.

  // Prefer the macro forms of the GC and ownership qualifiers.
  if (T->getAttrKind() == clang::attr::ObjCGC ||
      T->getAttrKind() == clang::attr::ObjCOwnership)
    return printAfter(T->getEquivalentType(), OS);

  // If this is a calling convention attribute, don't print the implicit CC from
  // the modified type.
  SaveAndRestore<bool> MaybeSuppressCC(InsideCCAttribute, T->isCallingConv());

  printAfter(T->getModifiedType(), OS);

  // Some attributes are printed as qualifiers before the type, so we have
  // nothing left to do.
  if (T->getAttrKind() == clang::attr::ObjCKindOf ||
      T->isMSTypeSpec() || T->getImmediateNullability())
    return;

  // Don't print the inert __unsafe_unretained attribute at all.
  if (T->getAttrKind() == clang::attr::ObjCInertUnsafeUnretained)
    return;

  // Don't print ns_returns_retained unless it had an effect.
  if (T->getAttrKind() == clang::attr::NSReturnsRetained &&
      !T->getEquivalentType()->castAs<clang::FunctionType>()
                             ->getExtInfo().getProducesResult())
    return;

  if (T->getAttrKind() == clang::attr::LifetimeBound) {
    OS << " [[clang::lifetimebound]]";
    return;
  }

  // The printing of the address_space attribute is handled by the qualifier
  // since it is still stored in the qualifier. Return early to prevent printing
  // this twice.
  if (T->getAttrKind() == clang::attr::AddressSpace)
    return;

  OS << " __attribute__((";
  switch (T->getAttrKind()) {
#define TYPE_ATTR(NAME)
#define DECL_OR_TYPE_ATTR(NAME)
#define ATTR(NAME) case clang::attr::NAME:
#include "clang/Basic/AttrList.inc"
    llvm_unreachable("non-type attribute attached to type");

  case clang::attr::OpenCLPrivateAddressSpace:
  case clang::attr::OpenCLGlobalAddressSpace:
  case clang::attr::OpenCLGlobalDeviceAddressSpace:
  case clang::attr::OpenCLGlobalHostAddressSpace:
  case clang::attr::OpenCLLocalAddressSpace:
  case clang::attr::OpenCLConstantAddressSpace:
  case clang::attr::OpenCLGenericAddressSpace:
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
}

void TypePrinter::printObjCInterfaceBefore(const clang::ObjCInterfaceType *T,
                                           raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  OS << T->getDecl()->getName();
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printObjCInterfaceAfter(const clang::ObjCInterfaceType *T,
                                          raw_string_ostream &OS) {}

void TypePrinter::printObjCTypeParamBefore(const clang::ObjCTypeParamType *T,
                                          raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
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
}

void TypePrinter::printObjCTypeParamAfter(const clang::ObjCTypeParamType *T,
                                          raw_string_ostream &OS) {}

void TypePrinter::printObjCObjectBefore(const clang::ObjCObjectType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (T->qual_empty() && T->isUnspecializedAsWritten() &&
      !T->isKindOfTypeAsWritten())
    return printBefore(T->getBaseType(), OS);

  if (T->isKindOfTypeAsWritten())
    OS << "__kindof ";

  print(T->getBaseType(), OS, clang::StringRef());

  if (T->isSpecializedAsWritten()) {
    bool isFirst = true;
    OS << '<';
    for (auto typeArg : T->getTypeArgsAsWritten()) {
      if (isFirst)
        isFirst = false;
      else
        OS << ",";

      print(typeArg, OS, clang::StringRef());
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
}

void TypePrinter::printObjCObjectAfter(const clang::ObjCObjectType *T,
                                        raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  if (T->qual_empty() && T->isUnspecializedAsWritten() &&
      !T->isKindOfTypeAsWritten())
    return printAfter(T->getBaseType(), OS);
}

void TypePrinter::printObjCObjectPointerBefore(const clang::ObjCObjectPointerType *T,
                                               raw_string_ostream &OS) {
  TokenPrinterContext ctx(OS, T, tokens, __FUNCTION__);
  printBefore(T->getPointeeType(), OS);

  // If we need to print the pointer, print it now.
  if (!T->isObjCIdType() && !T->isObjCQualifiedIdType() &&
      !T->isObjCClassType() && !T->isObjCQualifiedClassType()) {
    if (HasEmptyPlaceHolder)
      OS << ' ';
    OS << '*';
  }
}

void TypePrinter::printObjCObjectPointerAfter(const clang::ObjCObjectPointerType *T,
                                              raw_string_ostream &OS) {}
}
