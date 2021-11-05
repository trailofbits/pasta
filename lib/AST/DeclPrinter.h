
#pragma once

#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Preprocessor.h>

#include <vector>

#include "AST.h"
#include "Token.h"

namespace pasta {

class FatToken;
class raw_string_ostream;

struct FatTokenImpl {
 public:
  inline FatTokenImpl(uint32_t opaque_source_loc_, std::string data_,
                      const clang::Decl *decl_ = nullptr, const clang::Stmt *stmt_ = nullptr,
                      const clang::Type *type_ = nullptr)
      :  opaque_source_loc(opaque_source_loc_),
         data(data_), decl(decl_),
         stmt(stmt_), type(type_){}

  // Return the source location of this token.
  inline uint32_t getLocation(void) const {
    return opaque_source_loc;
  }

  // The raw encoding of the source location of the token.
  uint32_t opaque_source_loc;

  // Data
  std::string data;

  // The decl associated with the token
  const clang::Decl *decl;

  // The stmt associated with the token
  const clang::Stmt *stmt;

  // The types associated with the token
  const clang::Type *type;
};

class DeclPrinterImpl : public std::enable_shared_from_this<DeclPrinterImpl> {
 public:
  DeclPrinterImpl(clang::ASTContext &ast_, clang::Preprocessor &pp_, const clang::Decl *decl_);

  ~DeclPrinterImpl(void) {}

  clang::Preprocessor &pp;
  const clang::Decl *decl;
  std::string out_buffer;
  std::vector<FatTokenImpl> tokens;

 private:
  DeclPrinterImpl() = delete;
};

class StmtPrinterImpl : public std::enable_shared_from_this<StmtPrinterImpl> {
 public:
  StmtPrinterImpl(const clang::ASTContext &ast_, const clang::Preprocessor &pp_, const clang::Stmt *stmt_);

  ~StmtPrinterImpl(void){}

  const clang::ASTContext &ast;
  const clang::Preprocessor &pp;
  const clang::Stmt *stmt;
  std::string out_buffer;
  std::vector<FatTokenImpl> tokens;

 private:
  StmtPrinterImpl() = delete;
};

} // namespace pasta

