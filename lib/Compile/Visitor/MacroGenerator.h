/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <clang/AST/RecursiveASTVisitor.h>

namespace pasta {
namespace {
std::string_view MacroAccessSpecifier(const clang::Decl *decl) {
  switch (decl->getAccess()) {
    case clang::AccessSpecifier::AS_private: return "_PRIVATE_";
    case clang::AccessSpecifier::AS_protected: return "_PROTECTED_";
    default: return "_";
  }
}
} // namespace

class MacroGenerator : public clang::RecursiveASTVisitor<MacroGenerator> {
 public:
  bool VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
    const unsigned decl_id = identifier++;

    llvm::errs() << "PASTA_BEGIN_CLANG_WRAPPER(" << decl->getName()
                 << ", " << decl_id << ");\n";

    for (const auto method : decl->methods()) {
      llvm::errs() << "  PASTA" << MacroAccessSpecifier(method)
                   << "METHOD(" << decl->getName()
                   << ", " << decl_id
                   << ", " << method->getNameInfo().getAsString() << ");\n";
    }

    for (const auto field : decl->fields()) {
      llvm::errs() << "  PASTA" << MacroAccessSpecifier(field)
                   << "FIELD(" << decl->getName()
                   << ", " << decl_id
                   << ", " << field->getName() << ");\n";
    }

    llvm::errs() << "PASTA_END_CLANG_WRAPPER(" << decl->getName()
                 << ", " << decl_id << ");\n\n";

    return true;
  }

 private:
   // Unique identifier for each macro generated
   static unsigned identifier;
};

unsigned MacroGenerator::identifier = 0;

} // namespace pasta
