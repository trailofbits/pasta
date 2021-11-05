/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/DeclPrinter.h>

#include <vector>

#include "DeclPrinter.h"

namespace pasta {

class FatToken;
class ASTImpl;

size_t FatTokenRange::Size(void) const noexcept {
  return static_cast<size_t>(after_last - first);
}

DeclPrinter::DeclPrinter(AST &ast_, const pasta::Decl &decl_)
    : ast(ast_),
      impl(std::make_shared<DeclPrinterImpl>(ast_.UnderlyingAST(),  ast_.UnderlyingPP(), decl_.u.Decl)){}

DeclPrinter::~DeclPrinter() {}

FatTokenRange DeclPrinter::Tokens() {
  llvm::errs() << "Tokens size " << impl->tokens.size() << "\n";
  auto begin = impl->tokens.data();
  auto end =  &(begin[impl->tokens.size() - 1]);
  llvm::errs() << end - begin << "\n";
  return FatTokenRange(ast.impl, begin,  &(begin[impl->tokens.size() - 1]));
}

}  // namespace pasta
