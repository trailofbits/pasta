/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#include <clang/AST/RecursiveASTVisitor.h>
#pragma clang diagnostic pop

#include <map>
#include <sstream>
#include <string>
#include <unordered_set>

namespace pasta {

class MacroGenerator : public clang::RecursiveASTVisitor<MacroGenerator> {
 public:
  MacroGenerator(const clang::ASTContext *ctx);

  ~MacroGenerator(void);

  bool VisitEnumDecl(clang::EnumDecl *decl);
  bool VisitCXXRecordDecl(clang::CXXRecordDecl *decl);

 private:
  const clang::ASTContext *context;
  std::unordered_set<std::string> acceptable_class_names;
  std::unordered_set<std::string> unacceptable_enum_names;
  std::map<std::string, clang::CXXRecordDecl *> decl_classes;

  // Enums in the `clang` namespace.
  std::map<std::string, clang::EnumDecl *> decl_enums;
};

}  // namespace pasta
