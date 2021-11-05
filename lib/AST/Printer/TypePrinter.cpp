

#include "clang/AST/ASTContext.h"
#include "clang/AST/Attr.h"
#include "clang/AST/Decl.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/DeclCXX.h"
#include "clang/AST/DeclObjC.h"
#include "clang/AST/DeclTemplate.h"
#include "clang/AST/Expr.h"
#include "clang/AST/NestedNameSpecifier.h"
#include "clang/AST/PrettyPrinter.h"
#include "clang/AST/TemplateBase.h"
#include "clang/AST/TemplateName.h"
#include "clang/AST/Type.h"
#include "clang/Basic/AddressSpaces.h"
#include "clang/Basic/ExceptionSpecificationType.h"
#include "clang/Basic/IdentifierTable.h"
#include "clang/Basic/LLVM.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/Specifiers.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Twine.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/SaveAndRestore.h"

#include <cassert>
#include <string>

#include "raw_ostream.h"

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

  class TypePrinter {
    clang::PrintingPolicy Policy;
    unsigned Indentation;
    bool HasEmptyPlaceHolder = false;
    bool InsideCCAttribute = false;

  public:
    explicit TypePrinter(const clang::PrintingPolicy &Policy, unsigned Indentation = 0)
        : Policy(Policy), Indentation(Indentation) {}

    void print(const clang::Type *ty, clang::Qualifiers qs, raw_string_ostream &OS,
               clang::StringRef PlaceHolder);
    void print(clang::QualType T, raw_string_ostream &OS, clang::StringRef PlaceHolder);

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

void TypePrinter::print(clang::QualType t, raw_string_ostream &OS, clang::StringRef PlaceHolder) {
  clang::SplitQualType split = splitAccordingToPolicy(t, Policy);
  print(split.Ty, split.Quals, OS, PlaceHolder);
}

void TypePrinter::print(const clang::Type *T, clang::Qualifiers Quals,
                        raw_string_ostream &OS, clang::StringRef PlaceHolder) {
  if (!T) {
    OS << "NULL TYPE";
    return;
  }

  clang::SaveAndRestore<bool> PHVal(HasEmptyPlaceHolder, PlaceHolder.empty());

  printBefore(T, Quals, OS);
  OS << PlaceHolder;
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
  if (Policy.SuppressSpecifiers && T->isSpecifierType())
    return;

  clang::SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder);

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
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getPointeeType(), OS);
  // Handle things like 'int (*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << '(';
  OS << '*';
}

void TypePrinter::printPointerAfter(const clang::PointerType *T, raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  // Handle things like 'int (*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << ')';
  printAfter(T->getPointeeType(), OS);
}

void TypePrinter::printBlockPointerBefore(const clang::BlockPointerType *T,
                                          raw_string_ostream &OS) {
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getPointeeType(), OS);
  OS << '^';
}

void TypePrinter::printBlockPointerAfter(const clang::BlockPointerType *T,
                                          raw_string_ostream &OS) {
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
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
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
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
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  // Handle things like 'int (&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner))
    OS << ')';
  printAfter(Inner, OS);
}

void TypePrinter::printRValueReferenceBefore(const clang::RValueReferenceType *T,
                                             raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
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
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  clang::QualType Inner = skipTopLevelReferences(T->getPointeeTypeAsWritten());
  // Handle things like 'int (&&A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(Inner))
    OS << ')';
  printAfter(Inner, OS);
}

void TypePrinter::printMemberPointerBefore(const clang::MemberPointerType *T,
                                           raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getPointeeType(), OS);
  // Handle things like 'int (Cls::*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << '(';

  clang::PrintingPolicy InnerPolicy(Policy);
  InnerPolicy.IncludeTagDefinition = false;
  TypePrinter(InnerPolicy).print(clang::QualType(T->getClass(), 0), OS, clang::StringRef());

  OS << "::*";
}

void TypePrinter::printMemberPointerAfter(const clang::MemberPointerType *T,
                                          raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  // Handle things like 'int (Cls::*A)[4];' correctly.
  // FIXME: this should include vectors, but vectors use attributes I guess.
  if (clang::isa<clang::ArrayType>(T->getPointeeType()))
    OS << ')';
  printAfter(T->getPointeeType(), OS);
}

void TypePrinter::printConstantArrayBefore(const clang::ConstantArrayType *T,
                                           raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printConstantArrayAfter(const clang::ConstantArrayType *T,
                                          raw_string_ostream &OS) {
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
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}


void TypePrinter::printIncompleteArrayAfter(const clang::IncompleteArrayType *T,
                                            raw_string_ostream &OS) {
  OS << "[]";
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printVariableArrayBefore(const clang::VariableArrayType *T,
                                           raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printVariableArrayAfter(const clang::VariableArrayType *T,
                                          raw_string_ostream &OS) {
  OS << '[';
  if (T->getIndexTypeQualifiers().hasQualifiers()) {
    AppendTypeQualList(OS, T->getIndexTypeCVRQualifiers(), Policy.Restrict);
    OS << ' ';
  }

  if (T->getSizeModifier() == clang::VariableArrayType::Static)
    OS << "static ";
  else if (T->getSizeModifier() == clang::VariableArrayType::Star)
    OS << '*';

  if (T->getSizeExpr())
    T->getSizeExpr()->printPretty(OS, nullptr, Policy);
  OS << ']';

  printAfter(T->getElementType(), OS);
}

void TypePrinter::printAdjustedBefore(const clang::AdjustedType *T, raw_string_ostream &OS) {
  // Print the adjusted representation, otherwise the adjustment will be
  // invisible.
  printBefore(T->getAdjustedType(), OS);
}

void TypePrinter::printAdjustedAfter(const clang::AdjustedType *T, raw_string_ostream &OS) {
  printAfter(T->getAdjustedType(), OS);
}

void TypePrinter::printDecayedBefore(const clang::DecayedType *T, raw_string_ostream &OS) {
  // Print as though it's a pointer.
  printAdjustedBefore(T, OS);
}

void TypePrinter::printDecayedAfter(const clang::DecayedType *T, raw_string_ostream &OS) {
  printAdjustedAfter(T, OS);
}

void TypePrinter::printDependentSizedArrayBefore(
                                               const clang::DependentSizedArrayType *T,
                                               raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printDependentSizedArrayAfter(
                                               const clang::DependentSizedArrayType *T,
                                               raw_string_ostream &OS) {
  OS << '[';
  if (T->getSizeExpr())
    T->getSizeExpr()->printPretty(OS, nullptr, Policy);
  OS << ']';
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printDependentAddressSpaceBefore(
    const clang::DependentAddressSpaceType *T, raw_string_ostream &OS) {
  printBefore(T->getPointeeType(), OS);
}

void TypePrinter::printDependentAddressSpaceAfter(
    const clang::DependentAddressSpaceType *T, raw_string_ostream &OS) {
  OS << " __attribute__((address_space(";
  if (T->getAddrSpaceExpr())
    T->getAddrSpaceExpr()->printPretty(OS, nullptr, Policy);
  OS << ")))";
  printAfter(T->getPointeeType(), OS);
}

void TypePrinter::printDependentSizedExtVectorBefore(
                                          const clang::DependentSizedExtVectorType *T,
                                          raw_string_ostream &OS) {
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printDependentSizedExtVectorAfter(
                                          const clang::DependentSizedExtVectorType *T,
                                          raw_string_ostream &OS) {
  OS << " __attribute__((ext_vector_type(";
  if (T->getSizeExpr())
    T->getSizeExpr()->printPretty(OS, nullptr, Policy);
  OS << ")))";
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printVectorBefore(const clang::VectorType *T, raw_string_ostream &OS) {
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
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printDependentVectorBefore(
    const clang::DependentVectorType *T, raw_string_ostream &OS) {
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
    if (T->getSizeExpr())
      T->getSizeExpr()->printPretty(OS, nullptr, Policy);
    OS << "))) ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::NeonPolyVector:
    OS << "__attribute__((neon_polyvector_type(";
    if (T->getSizeExpr())
      T->getSizeExpr()->printPretty(OS, nullptr, Policy);
    OS << "))) ";
    printBefore(T->getElementType(), OS);
    break;
  case clang::VectorType::GenericVector: {
    // FIXME: We prefer to print the size directly here, but have no way
    // to get the size of the type.
    OS << "__attribute__((__vector_size__(";
    if (T->getSizeExpr())
      T->getSizeExpr()->printPretty(OS, nullptr, Policy);
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
      T->getSizeExpr()->printPretty(OS, nullptr, Policy);
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

void TypePrinter::printDependentVectorAfter(
    const clang::DependentVectorType *T, raw_string_ostream &OS) {
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printExtVectorBefore(const clang::ExtVectorType *T,
                                       raw_string_ostream &OS) {
  printBefore(T->getElementType(), OS);
}

void TypePrinter::printExtVectorAfter(const clang::ExtVectorType *T, raw_string_ostream &OS) {
  printAfter(T->getElementType(), OS);
  OS << " __attribute__((ext_vector_type(";
  OS << T->getNumElements();
  OS << ")))";
}

void TypePrinter::printConstantMatrixBefore(const clang::ConstantMatrixType *T,
                                            raw_string_ostream &OS) {
  printBefore(T->getElementType(), OS);
  OS << " __attribute__((matrix_type(";
  OS << T->getNumRows() << ", " << T->getNumColumns();
  OS << ")))";
}

void TypePrinter::printConstantMatrixAfter(const clang::ConstantMatrixType *T,
                                           raw_string_ostream &OS) {
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printDependentSizedMatrixBefore(
    const clang::DependentSizedMatrixType *T, raw_string_ostream &OS) {
  printBefore(T->getElementType(), OS);
  OS << " __attribute__((matrix_type(";
  if (T->getRowExpr()) {
    T->getRowExpr()->printPretty(OS, nullptr, Policy);
  }
  OS << ", ";
  if (T->getColumnExpr()) {
    T->getColumnExpr()->printPretty(OS, nullptr, Policy);
  }
  OS << ")))";
}

void TypePrinter::printDependentSizedMatrixAfter(
    const clang::DependentSizedMatrixType *T, raw_string_ostream &OS) {
  printAfter(T->getElementType(), OS);
}

void TypePrinter::printFunctionProtoBefore(const clang::FunctionProtoType *T,
                                           raw_string_ostream &OS) {
  if (T->hasTrailingReturn()) {
    OS << "auto ";
    if (!HasEmptyPlaceHolder)
      OS << '(';
  } else {
    // If needed for precedence reasons, wrap the inner part in grouping parens.
    clang::SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder, false);
    printBefore(T->getReturnType(), OS);
    if (!PrevPHIsEmpty.get())
      OS << '(';
  }
}

void TypePrinter::printFunctionProtoAfter(const clang::FunctionProtoType *T,
                                          raw_string_ostream &OS) {
  // If needed for precedence reasons, wrap the inner part in grouping parens.
  if (!HasEmptyPlaceHolder)
    OS << ')';
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);

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
  T->printExceptionSpecification(OS, Policy);

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
  // If needed for precedence reasons, wrap the inner part in grouping parens.
  clang::SaveAndRestore<bool> PrevPHIsEmpty(HasEmptyPlaceHolder, false);
  printBefore(T->getReturnType(), OS);
  if (!PrevPHIsEmpty.get())
    OS << '(';
}

void TypePrinter::printFunctionNoProtoAfter(const clang::FunctionNoProtoType *T,
                                            raw_string_ostream &OS) {
  // If needed for precedence reasons, wrap the inner part in grouping parens.
  if (!HasEmptyPlaceHolder)
    OS << ')';
  clang::SaveAndRestore<bool> NonEmptyPH(HasEmptyPlaceHolder, false);

  OS << "()";
  printFunctionAfter(T->getExtInfo(), OS);
  printAfter(T->getReturnType(), OS);
}

void TypePrinter::printTypeSpec(clang::NamedDecl *D, raw_string_ostream &OS) {

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
  printTypeSpec(T->getDecl(), OS);
}

void TypePrinter::printUnresolvedUsingAfter(const clang::UnresolvedUsingType *T,
                                            raw_string_ostream &OS) {}

void TypePrinter::printTypedefBefore(const clang::TypedefType *T, raw_string_ostream &OS) {
  printTypeSpec(T->getDecl(), OS);
}

void TypePrinter::printMacroQualifiedBefore(const clang::MacroQualifiedType *T,
                                            raw_string_ostream &OS) {
  clang::StringRef MacroName = T->getMacroIdentifier()->getName();
  OS << MacroName << " ";

  // Since this type is meant to print the macro instead of the whole attribute,
  // we trim any attributes and go directly to the original modified type.
  printBefore(T->getModifiedType(), OS);
}

void TypePrinter::printMacroQualifiedAfter(const clang::MacroQualifiedType *T,
                                           raw_string_ostream &OS) {
  printAfter(T->getModifiedType(), OS);
}

void TypePrinter::printTypedefAfter(const clang::TypedefType *T, raw_string_ostream &OS) {}

void TypePrinter::printTypeOfExprBefore(const clang::TypeOfExprType *T,
                                        raw_string_ostream &OS) {
  OS << "typeof ";
  if (T->getUnderlyingExpr())
    T->getUnderlyingExpr()->printPretty(OS, nullptr, Policy);
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTypeOfExprAfter(const clang::TypeOfExprType *T,
                                       raw_string_ostream &OS) {}

void TypePrinter::printTypeOfBefore(const clang::TypeOfType *T, raw_string_ostream &OS) {
  OS << "typeof(";
  print(T->getUnderlyingType(), OS, clang::StringRef());
  OS << ')';
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printTypeOfAfter(const clang::TypeOfType *T, raw_string_ostream &OS) {}

void TypePrinter::printDecltypeBefore(const clang::DecltypeType *T, raw_string_ostream &OS) {
  OS << "decltype(";
  if (T->getUnderlyingExpr())
    T->getUnderlyingExpr()->printPretty(OS, nullptr, Policy);
  OS << ')';
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printDecltypeAfter(const clang::DecltypeType *T, raw_string_ostream &OS) {}

void TypePrinter::printUnaryTransformBefore(const clang::UnaryTransformType *T,
                                            raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);

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

  switch (T->getUTTKind()) {
    case clang::UnaryTransformType::EnumUnderlyingType:
      return;
  }

  printAfter(T->getBaseType(), OS);
}

void TypePrinter::printAutoBefore(const clang::AutoType *T, raw_string_ostream &OS) {
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
  // If the type has been deduced, do not print 'auto'.
  if (!T->getDeducedType().isNull())
    printAfter(T->getDeducedType(), OS);
}

void TypePrinter::printDeducedTemplateSpecializationBefore(
    const clang::DeducedTemplateSpecializationType *T, raw_string_ostream &OS) {
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
  // If the type has been deduced, print the deduced type.
  if (!T->getDeducedType().isNull())
    printAfter(T->getDeducedType(), OS);
}

void TypePrinter::printAtomicBefore(const clang::AtomicType *T, raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);

  OS << "_Atomic(";
  print(T->getValueType(), OS, clang::StringRef());
  OS << ')';
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printAtomicAfter(const clang::AtomicType *T, raw_string_ostream &OS) {}

void TypePrinter::printPipeBefore(const clang::PipeType *T, raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);

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
  if (T->isUnsigned())
    OS << "unsigned ";
  OS << "_ExtInt(" << T->getNumBits() << ")";
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printExtIntAfter(const clang::ExtIntType *T, raw_string_ostream &OS) {}

void TypePrinter::printDependentExtIntBefore(const clang::DependentExtIntType *T,
                                             raw_string_ostream &OS) {
  if (T->isUnsigned())
    OS << "unsigned ";
  OS << "_ExtInt(";
  T->getNumBitsExpr()->printPretty(OS, nullptr, Policy);
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
    D->print(OS, SubPolicy, Indentation);
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
  printTag(T->getDecl(), OS);
}

void TypePrinter::printEnumAfter(const clang::EnumType *T, raw_string_ostream &OS) {}

void TypePrinter::printTemplateTypeParmBefore(const clang::TemplateTypeParmType *T,
                                              raw_string_ostream &OS) {
  clang::TemplateTypeParmDecl *D = T->getDecl();
  if (D && D->isImplicit()) {
    if (auto *TC = D->getTypeConstraint()) {
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
  IncludeStrongLifetimeRAII Strong(Policy);
  printBefore(T->getReplacementType(), OS);
}

void TypePrinter::printSubstTemplateTypeParmAfter(
                                             const clang::SubstTemplateTypeParmType *T,
                                             raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  printAfter(T->getReplacementType(), OS);
}

void TypePrinter::printSubstTemplateTypeParmPackBefore(
                                        const clang::SubstTemplateTypeParmPackType *T,
                                        raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  printTemplateTypeParmBefore(T->getReplacedParameter(), OS);
}

void TypePrinter::printSubstTemplateTypeParmPackAfter(
                                        const clang::SubstTemplateTypeParmPackType *T,
                                        raw_string_ostream &OS) {
  IncludeStrongLifetimeRAII Strong(Policy);
  printTemplateTypeParmAfter(T->getReplacedParameter(), OS);
}

void TypePrinter::printTemplateId(const clang::TemplateSpecializationType *T,
                                  raw_string_ostream &OS, bool FullyQualify) {
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
                                            const clang::TemplateSpecializationType *T,
                                            raw_string_ostream &OS) {
  printTemplateId(T, OS, Policy.FullyQualifiedName);
}

void TypePrinter::printTemplateSpecializationAfter(
                                            const clang::TemplateSpecializationType *T,
                                            raw_string_ostream &OS) {}

void TypePrinter::printInjectedClassNameBefore(const clang::InjectedClassNameType *T,
                                               raw_string_ostream &OS) {
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
  if (Policy.IncludeTagDefinition && T->getOwnedTagDecl()) {
    clang::TagDecl *OwnedTagDecl = T->getOwnedTagDecl();
    assert(OwnedTagDecl->getTypeForDecl() == T->getNamedType().getTypePtr() &&
           "OwnedTagDecl expected to be a declaration for the type");
    clang::PrintingPolicy SubPolicy = Policy;
    SubPolicy.IncludeTagDefinition = false;
    OwnedTagDecl->print(OS, SubPolicy, Indentation);
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
  if (Policy.IncludeTagDefinition && T->getOwnedTagDecl())
    return;
  ElaboratedTypePolicyRAII PolicyRAII(Policy);
  printAfter(T->getNamedType(), OS);
}

void TypePrinter::printParenBefore(const clang::ParenType *T, raw_string_ostream &OS) {
  if (!HasEmptyPlaceHolder && !clang::isa<clang::FunctionType>(T->getInnerType())) {
    printBefore(T->getInnerType(), OS);
    OS << '(';
  } else
    printBefore(T->getInnerType(), OS);
}

void TypePrinter::printParenAfter(const clang::ParenType *T, raw_string_ostream &OS) {
  if (!HasEmptyPlaceHolder && !clang::isa<clang::FunctionType>(T->getInnerType())) {
    OS << ')';
    printAfter(T->getInnerType(), OS);
  } else
    printAfter(T->getInnerType(), OS);
}

void TypePrinter::printDependentNameBefore(const clang::DependentNameType *T,
                                           raw_string_ostream &OS) {
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
  printBefore(T->getPattern(), OS);
}

void TypePrinter::printPackExpansionAfter(const clang::PackExpansionType *T,
                                          raw_string_ostream &OS) {
  printAfter(T->getPattern(), OS);
  OS << "...";
}

void TypePrinter::printAttributedBefore(const clang::AttributedType *T,
                                        raw_string_ostream &OS) {
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
  // FIXME: Generate this with TableGen.

  // Prefer the macro forms of the GC and ownership qualifiers.
  if (T->getAttrKind() == clang::attr::ObjCGC ||
      T->getAttrKind() == clang::attr::ObjCOwnership)
    return printAfter(T->getEquivalentType(), OS);

  // If this is a calling convention attribute, don't print the implicit CC from
  // the modified type.
  clang::SaveAndRestore<bool> MaybeSuppressCC(InsideCCAttribute, T->isCallingConv());

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
  OS << T->getDecl()->getName();
  spaceBeforePlaceHolder(OS);
}

void TypePrinter::printObjCInterfaceAfter(const clang::ObjCInterfaceType *T,
                                          raw_string_ostream &OS) {}

void TypePrinter::printObjCTypeParamBefore(const clang::ObjCTypeParamType *T,
                                          raw_string_ostream &OS) {
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
  if (T->qual_empty() && T->isUnspecializedAsWritten() &&
      !T->isKindOfTypeAsWritten())
    return printAfter(T->getBaseType(), OS);
}

void TypePrinter::printObjCObjectPointerBefore(const clang::ObjCObjectPointerType *T,
                                               raw_string_ostream &OS) {
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

static
const clang::TemplateArgument &getArgument(const clang::TemplateArgument &A) { return A; }

static const clang::TemplateArgument &getArgument(const clang::TemplateArgumentLoc &A) {
  return A.getArgument();
}

static void printArgument(const clang::TemplateArgument &A, const clang::PrintingPolicy &PP,
                          raw_string_ostream &OS, bool IncludeType) {
  A.print(PP, OS);
}

static void printArgument(const clang::TemplateArgumentLoc &A,
                          const clang::PrintingPolicy &PP, raw_string_ostream &OS,
                          bool IncludeType) {
  const clang::TemplateArgument::ArgKind &Kind = A.getArgument().getKind();
  if (Kind == clang::TemplateArgument::ArgKind::Type)
    return A.getTypeSourceInfo()->getType().print(OS, PP);
  return A.getArgument().print(PP, OS);
}

static bool isSubstitutedTemplateArgument(clang::ASTContext &Ctx, clang::TemplateArgument Arg,
                                          clang::TemplateArgument Pattern,
                                          clang::ArrayRef<clang::TemplateArgument> Args,
                                          unsigned Depth);

static bool isSubstitutedType(clang::ASTContext &Ctx, clang::QualType T, clang::QualType Pattern,
                              clang::ArrayRef<clang::TemplateArgument> Args, unsigned Depth) {
  if (Ctx.hasSameType(T, Pattern))
    return true;

  // A type parameter matches its argument.
  if (auto *TTPT = Pattern->getAs<clang::TemplateTypeParmType>()) {
    if (TTPT->getDepth() == Depth && TTPT->getIndex() < Args.size() &&
        Args[TTPT->getIndex()].getKind() == clang::TemplateArgument::Type) {
      clang::QualType SubstArg = Ctx.getQualifiedType(
          Args[TTPT->getIndex()].getAsType(), Pattern.getQualifiers());
      return Ctx.hasSameType(SubstArg, T);
    }
    return false;
  }

  // FIXME: Recurse into array types.

  // All other cases will need the types to be identically qualified.
  clang::Qualifiers TQual, PatQual;
  T = Ctx.getUnqualifiedArrayType(T, TQual);
  Pattern = Ctx.getUnqualifiedArrayType(Pattern, PatQual);
  if (TQual != PatQual)
    return false;

  // Recurse into pointer-like types.
  {
    clang::QualType TPointee = T->getPointeeType();
    clang::QualType PPointee = Pattern->getPointeeType();
    if (!TPointee.isNull() && !PPointee.isNull())
      return T->getTypeClass() == Pattern->getTypeClass() &&
             isSubstitutedType(Ctx, TPointee, PPointee, Args, Depth);
  }

  // Recurse into template specialization types.
  if (auto *PTST =
          Pattern.getCanonicalType()->getAs<clang::TemplateSpecializationType>()) {
    clang::TemplateName Template;
    clang::ArrayRef<clang::TemplateArgument> TemplateArgs;
    if (auto *TTST = T->getAs<clang::TemplateSpecializationType>()) {
      Template = TTST->getTemplateName();
      TemplateArgs = TTST->template_arguments();
    } else if (auto *CTSD = clang::dyn_cast_or_null<clang::ClassTemplateSpecializationDecl>(
                   T->getAsCXXRecordDecl())) {
      Template = clang::TemplateName(CTSD->getSpecializedTemplate());
      TemplateArgs = CTSD->getTemplateArgs().asArray();
    } else {
      return false;
    }

    if (!isSubstitutedTemplateArgument(Ctx, Template, PTST->getTemplateName(),
                                       Args, Depth))
      return false;
    if (TemplateArgs.size() != PTST->getNumArgs())
      return false;
    for (unsigned I = 0, N = TemplateArgs.size(); I != N; ++I)
      if (!isSubstitutedTemplateArgument(Ctx, TemplateArgs[I], PTST->getArg(I),
                                         Args, Depth))
        return false;
    return true;
  }

  // FIXME: Handle more cases.
  return false;
}

static bool isSubstitutedTemplateArgument(clang::ASTContext &Ctx, clang::TemplateArgument Arg,
                                          clang::TemplateArgument Pattern,
                                          clang::ArrayRef<clang::TemplateArgument> Args,
                                          unsigned Depth) {
  Arg = Ctx.getCanonicalTemplateArgument(Arg);
  Pattern = Ctx.getCanonicalTemplateArgument(Pattern);
  if (Arg.structurallyEquals(Pattern))
    return true;

  if (Pattern.getKind() == clang::TemplateArgument::Expression) {
    if (auto *DRE =
        clang::dyn_cast<clang::DeclRefExpr>(Pattern.getAsExpr()->IgnoreParenImpCasts())) {
      if (auto *NTTP = clang::dyn_cast<clang::NonTypeTemplateParmDecl>(DRE->getDecl()))
        return NTTP->getDepth() == Depth && Args.size() > NTTP->getIndex() &&
               Args[NTTP->getIndex()].structurallyEquals(Arg);
    }
  }

  if (Arg.getKind() != Pattern.getKind())
    return false;

  if (Arg.getKind() == clang::TemplateArgument::Type)
    return isSubstitutedType(Ctx, Arg.getAsType(), Pattern.getAsType(), Args,
                             Depth);

  if (Arg.getKind() == clang::TemplateArgument::Template) {
    clang::TemplateDecl *PatTD = Pattern.getAsTemplate().getAsTemplateDecl();
    if (auto *TTPD = clang::dyn_cast_or_null<clang::TemplateTemplateParmDecl>(PatTD))
      return TTPD->getDepth() == Depth && Args.size() > TTPD->getIndex() &&
             Ctx.getCanonicalTemplateArgument(Args[TTPD->getIndex()])
                 .structurallyEquals(Arg);
  }

  // FIXME: Handle more cases.
  return false;
}

/// Make a best-effort determination of whether the type T can be produced by
/// substituting Args into the default argument of Param.
static bool isSubstitutedDefaultArgument(clang::ASTContext &Ctx, clang::TemplateArgument Arg,
                                         const clang::NamedDecl *Param,
                                         clang::ArrayRef<clang::TemplateArgument> Args,
                                         unsigned Depth) {
  // An empty pack is equivalent to not providing a pack argument.
  if (Arg.getKind() == clang::TemplateArgument::Pack && Arg.pack_size() == 0)
    return true;

  if (auto *TTPD = clang::dyn_cast<clang::TemplateTypeParmDecl>(Param)) {
    return TTPD->hasDefaultArgument() &&
           isSubstitutedTemplateArgument(Ctx, Arg, TTPD->getDefaultArgument(),
                                         Args, Depth);
  } else if (auto *TTPD = clang::dyn_cast<clang::TemplateTemplateParmDecl>(Param)) {
    return TTPD->hasDefaultArgument() &&
           isSubstitutedTemplateArgument(
               Ctx, Arg, TTPD->getDefaultArgument().getArgument(), Args, Depth);
  } else if (auto *NTTPD = clang::dyn_cast<clang::NonTypeTemplateParmDecl>(Param)) {
    return NTTPD->hasDefaultArgument() &&
           isSubstitutedTemplateArgument(Ctx, Arg, NTTPD->getDefaultArgument(),
                                         Args, Depth);
  }
  return false;
}

#if 0
template <typename TA>
static void printTo(raw_string_ostream &OS, clang::ArrayRef<TA> Args,
                    const clang::PrintingPolicy &Policy, bool SkipBrackets,
                    const clang::TemplateParameterList *TPL, bool IsPack,
                    unsigned ParmIndex) {
  // Drop trailing template arguments that match default arguments.
  if (TPL && Policy.SuppressDefaultTemplateArgs &&
      !Policy.PrintCanonicalTypes && !Args.empty() && !IsPack &&
      Args.size() <= TPL->size()) {
    clang::ASTContext &Ctx = TPL->getParam(0)->getASTContext();
    llvm::SmallVector<clang::TemplateArgument, 8> OrigArgs;
    for (const TA &A : Args)
      OrigArgs.push_back(getArgument(A));
    while (!Args.empty() &&
           isSubstitutedDefaultArgument(Ctx, getArgument(Args.back()),
                                        TPL->getParam(Args.size() - 1),
                                        OrigArgs, TPL->getDepth()))
      Args = Args.drop_back();
  }

  const char *Comma = Policy.MSVCFormatting ? "," : ", ";
  if (!SkipBrackets)
    OS << '<';

  bool NeedSpace = false;
  bool FirstArg = true;
  for (const auto &Arg : Args) {
    // Print the argument into a string.
    clang::SmallString<128> Buf;
    llvm::raw_svector_ostream ArgOS(Buf);
    const clang::TemplateArgument &Argument = getArgument(Arg);
    if (Argument.getKind() == clang::TemplateArgument::Pack) {
      if (Argument.pack_size() && !FirstArg)
        OS << Comma;
      // TODO(kumarak)
#if 0
      printTo(ArgOS, Argument.getPackAsArray(), Policy, true, TPL,
              /*IsPack*/ true, ParmIndex);
#endif
    } else {
      if (!FirstArg)
        OS << Comma;
      // Tries to print the argument with location info if exists.
      printArgument(
          Arg, Policy, ArgOS,
          clang::TemplateParameterList::shouldIncludeTypeForArgument(TPL, ParmIndex));
    }
    clang::StringRef ArgString = ArgOS.str();

    // If this is the first argument and its string representation
    // begins with the global scope specifier ('::foo'), add a space
    // to avoid printing the diagraph '<:'.
    if (FirstArg && !ArgString.empty() && ArgString[0] == ':')
      OS << ' ';

    OS << ArgString;

    // If the last character of our string is '>', add another space to
    // keep the two '>''s separate tokens.
    NeedSpace = Policy.SplitTemplateClosers && !ArgString.empty() &&
                ArgString.back() == '>';
    FirstArg = false;

    // Use same template parameter for all elements of Pack
    if (!IsPack)
      ParmIndex++;
  }

  if (NeedSpace)
    OS << ' ';

  if (!SkipBrackets)
    OS << '>';
}
#endif
}

# if 0
std::string Qualifiers::getAsString() const {
  LangOptions LO;
  return getAsString(clang::PrintingPolicy(LO));
}

// Appends qualifiers to the given string, separated by spaces.  Will
// prefix a space if the string is non-empty.  Will not append a final
// space.
std::string Qualifiers::getAsString(const clang::PrintingPolicy &Policy) const {
  SmallString<64> Buf;
  llvm::raw_svector_ostream StrOS(Buf);
  print(StrOS, Policy);
  return std::string(StrOS.str());
}

bool Qualifiers::isEmptyWhenPrinted(const clang::PrintingPolicy &Policy) const {
  if (getCVRQualifiers())
    return false;

  if (getAddressSpace() != LangAS::Default)
    return false;

  if (getObjCGCAttr())
    return false;

  if (Qualifiers::ObjCLifetime lifetime = getObjCLifetime())
    if (!(lifetime == Qualifiers::OCL_Strong && Policy.SuppressStrongLifetime))
      return false;

  return true;
}

std::string Qualifiers::getAddrSpaceAsString(LangAS AS) {
  switch (AS) {
  case LangAS::Default:
    return "";
  case LangAS::opencl_global:
  case LangAS::sycl_global:
    return "__global";
  case LangAS::opencl_local:
  case LangAS::sycl_local:
    return "__local";
  case LangAS::opencl_private:
  case LangAS::sycl_private:
    return "__private";
  case LangAS::opencl_constant:
    return "__constant";
  case LangAS::opencl_generic:
    return "__generic";
  case LangAS::opencl_global_device:
  case LangAS::sycl_global_device:
    return "__global_device";
  case LangAS::opencl_global_host:
  case LangAS::sycl_global_host:
    return "__global_host";
  case LangAS::cuda_device:
    return "__device__";
  case LangAS::cuda_constant:
    return "__constant__";
  case LangAS::cuda_shared:
    return "__shared__";
  case LangAS::ptr32_sptr:
    return "__sptr __ptr32";
  case LangAS::ptr32_uptr:
    return "__uptr __ptr32";
  case LangAS::ptr64:
    return "__ptr64";
  default:
    return std::to_string(toTargetAddressSpace(AS));
  }
}

// Appends qualifiers to the given string, separated by spaces.  Will
// prefix a space if the string is non-empty.  Will not append a final
// space.
void Qualifiers::print(raw_string_ostream &OS, const clang::PrintingPolicy& Policy,
                       bool appendSpaceIfNonEmpty) const {
  bool addSpace = false;

  unsigned quals = getCVRQualifiers();
  if (quals) {
    AppendTypeQualList(OS, quals, Policy.Restrict);
    addSpace = true;
  }
  if (hasUnaligned()) {
    if (addSpace)
      OS << ' ';
    OS << "__unaligned";
    addSpace = true;
  }
  auto ASStr = getAddrSpaceAsString(getAddressSpace());
  if (!ASStr.empty()) {
    if (addSpace)
      OS << ' ';
    addSpace = true;
    // Wrap target address space into an attribute syntax
    if (isTargetAddressSpace(getAddressSpace()))
      OS << "__attribute__((address_space(" << ASStr << ")))";
    else
      OS << ASStr;
  }

  if (Qualifiers::GC gc = getObjCGCAttr()) {
    if (addSpace)
      OS << ' ';
    addSpace = true;
    if (gc == Qualifiers::Weak)
      OS << "__weak";
    else
      OS << "__strong";
  }
  if (Qualifiers::ObjCLifetime lifetime = getObjCLifetime()) {
    if (!(lifetime == Qualifiers::OCL_Strong && Policy.SuppressStrongLifetime)){
      if (addSpace)
        OS << ' ';
      addSpace = true;
    }

    switch (lifetime) {
    case Qualifiers::OCL_None: llvm_unreachable("none but true");
    case Qualifiers::OCL_ExplicitNone: OS << "__unsafe_unretained"; break;
    case Qualifiers::OCL_Strong:
      if (!Policy.SuppressStrongLifetime)
        OS << "__strong";
      break;

    case Qualifiers::OCL_Weak: OS << "__weak"; break;
    case Qualifiers::OCL_Autoreleasing: OS << "__autoreleasing"; break;
    }
  }

  if (appendSpaceIfNonEmpty && addSpace)
    OS << ' ';
}

std::string QualType::getAsString() const {
  return getAsString(split(), LangOptions());
}

std::string QualType::getAsString(const clang::PrintingPolicy &Policy) const {
  std::string S;
  getAsStringInternal(S, Policy);
  return S;
}

std::string QualType::getAsString(const Type *ty, Qualifiers qs,
                                  const clang::PrintingPolicy &Policy) {
  std::string buffer;
  getAsStringInternal(ty, qs, buffer, Policy);
  return buffer;
}

void QualType::print(raw_string_ostream &OS, const clang::PrintingPolicy &Policy,
                     const Twine &PlaceHolder, unsigned Indentation) const {
  print(splitAccordingToPolicy(*this, Policy), OS, Policy, PlaceHolder,
        Indentation);
}

void QualType::print(const Type *ty, Qualifiers qs,
                     raw_string_ostream &OS, const clang::PrintingPolicy &policy,
                     const Twine &PlaceHolder, unsigned Indentation) {
  SmallString<128> PHBuf;
  StringRef PH = PlaceHolder.toStringRef(PHBuf);

  TypePrinter(policy, Indentation).print(ty, qs, OS, PH);
}

void QualType::getAsStringInternal(std::string &Str,
                                   const clang::PrintingPolicy &Policy) const {
  return getAsStringInternal(splitAccordingToPolicy(*this, Policy), Str,
                             Policy);
}
#endif
