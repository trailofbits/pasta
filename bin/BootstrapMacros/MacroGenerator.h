/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <map>
#include <unordered_set>
#include <sstream>
#include <string>

#include <clang/AST/RecursiveASTVisitor.h>

namespace pasta {

class MacroGenerator : public clang::RecursiveASTVisitor<MacroGenerator> {
 public:
  MacroGenerator(const clang::ASTContext *ctx);

  ~MacroGenerator(void);

  bool VisitCXXRecordDecl(clang::CXXRecordDecl *decl);

 private:
  const clang::ASTContext *context;
  std::unordered_set<std::string> acceptable_names;
  std::map<std::string, clang::CXXRecordDecl *> decl_classes;
};

}  // namespace pasta
