/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <unordered_set>
#include <string>

#include <clang/AST/RecursiveASTVisitor.h>

namespace pasta {
namespace {
static std::string_view MacroAccessSpecifier(const clang::Decl *decl) {
  switch (decl->getAccess()) {
    case clang::AccessSpecifier::AS_private:
      return "_PRIVATE_";
    case clang::AccessSpecifier::AS_protected:
      return "_PROTECTED_";
    default:
      return "_";
  }
}
}  // namespace

class MacroGenerator : public clang::RecursiveASTVisitor<MacroGenerator> {
 public:
  MacroGenerator(void) {
#define DECL(Type, Base) acceptable_names.insert(#Type "Decl");
#include "clang/AST/DeclNodes.inc"
#undef DECL
  }

  bool VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
    const auto ns_dc = decl->getEnclosingNamespaceContext();
    if (!ns_dc) {
      return true;
    }
    if (!ns_dc->isNamespace()) {
      return true;
    }

    const auto ns = clang::NamespaceDecl::castFromDeclContext(ns_dc);
    if (ns->getName() != "clang") {
      return true;
    }

    const unsigned decl_id = identifier++;
    const auto decl_name = decl->getName().str();
    if (!acceptable_names.count(decl_name)) {
      return true;
    }

    llvm::errs() << "PASTA_BEGIN_CLANG_WRAPPER(" << decl_name << ", "
                 << decl_id << ");\n";

    // Methods
    for (const auto method : decl->methods()) {
      llvm::errs() << "  PASTA" << MacroAccessSpecifier(method);
      if (method->isOverloadedOperator()) {
        llvm::errs() << "OPERATOR";
      } else {
        llvm::errs() << "METHOD";
      }
      llvm::errs() << "(" << decl->getName() << ", " << decl_id << ", "
                   << method->getNameInfo().getAsString() << ");\n";
    }

    // Fields
    for (const auto field : decl->fields()) {
      llvm::errs() << "  PASTA" << MacroAccessSpecifier(field)
          << "FIELD(" << decl->getName() << ", " << decl_id << ", "
          << field->getName() << ");\n";
    }

    // Destructor.
    if (const auto dtor = decl->getDestructor(); dtor) {
      llvm::errs() << "  PASTA" << MacroAccessSpecifier(dtor)
                   << "DTOR(" << decl->getName() << ", " << decl_id << ", "
                   << dtor->getNameInfo().getAsString() << ");\n";
    }

    llvm::errs() << "PASTA_END_CLANG_WRAPPER(" << decl->getName() << ", "
                 << decl_id << ");\n\n";

    return true;
  }

 private:
  // Unique identifier for each macro generated
  static unsigned identifier;

  std::unordered_set<std::string> acceptable_names;
};

unsigned MacroGenerator::identifier = 0;

}  // namespace pasta
