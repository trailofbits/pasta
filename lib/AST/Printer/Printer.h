/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/Printer.h>

#include <llvm/Support/raw_ostream.h>

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#include "../Token.h"

namespace clang {
class Decl;
class LangOptions;
class SourceLocation;
class SourceManager;
class Stmt;
class Type;
}  // namespace clang
namespace pasta {

class ASTImpl;
class raw_string_ostream;

class PrintedTokenImpl {
 public:
  // Data of this token.
  const std::string data;

  // The context inherited from the token printer.
  const PrintedTokenContext * const context;

  // If there is a specific parsed token associated with this token, then
  // we record its location here.
  clang::SourceLocation parsed_location;

  // Kind of this token.
  clang::tok::TokenKind kind;

  inline PrintedTokenImpl(std::string data_,
                          const PrintedTokenContext *context_,
                          clang::tok::TokenKind kind_)
      : data(std::move(data_)),
        context(context_),
        kind(kind_) {}
};

// The range of data contained in a token.
class PrintedTokenRangeImpl {
 public:

  clang::ASTContext &ast_context;
  std::shared_ptr<ASTImpl> ast;
  std::vector<PrintedTokenImpl> tokens;
  std::vector<std::unique_ptr<PrintedTokenContext>> contexts;
  std::vector<PrintedTokenContext *> context_stack;
  std::vector<TokenPrinterContext *> tokenizer_stack;

  inline PrintedTokenRangeImpl(clang::ASTContext &ast_context_)
      : ast_context(ast_context_) {}

  ~PrintedTokenRangeImpl(void);

  const PrintedTokenContext *PushContext(TokenPrinterContext *tokenizer,
                                         const clang::Stmt *stmt);
  const PrintedTokenContext *PushContext(TokenPrinterContext *tokenizer,
                                         const clang::Decl *decl);
  const PrintedTokenContext *PushContext(TokenPrinterContext *tokenizer,
                                         const clang::Type *type);

  void PopContext(void);
};

// Context class for tokenizing what's inside of a particular stream stream.
class TokenPrinterContext {
 public:
  TokenPrinterContext(raw_string_ostream &out_, const clang::Decl *decl_,
                      PrintedTokenRangeImpl &tokens_, const char *caller_ = "");


  TokenPrinterContext(raw_string_ostream &out_, const clang::Stmt *stmt_,
                      PrintedTokenRangeImpl &tokens_, const char * caller_ = "");

  void Tokenize(void);

  // Mark the last printed token as having location `loc`. This helps to
  // correlate things in the actual parsed tokens with printed tokens.
  void MarkLocation(clang::SourceLocation &loc);

  ~TokenPrinterContext(void);

  pasta::raw_string_ostream &out;
  const PrintedTokenContext * const context;
  PrintedTokenRangeImpl &tokens;
  const char * const caller_fn;
  size_t start_loc;
};

}  // namespace pasta
