/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/AST.h>

#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/FileManager.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include "Token.h"

namespace clang {
class CompilerInstance;
class Preprocessor;
class TranslationUnitDecl;
}  // namespace clang
namespace llvm {
namespace vfs {
class FileSystem;
class InMemoryFileSystem;
class OverlayFileSystem;
}  // namespace vfs
}  // namespace llvm
namespace pasta {

class ASTImpl {
 public:
  ASTImpl(void);
  ~ASTImpl(void);

  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_fs;
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_fs;
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_fs;

  // Preprocessor over the original source code.
  std::shared_ptr<clang::Preprocessor> orig_source_pp;

  // Preprocessor over `preprocessed_code`, the huge file where there is a
  // single toekn per line.
  std::shared_ptr<clang::Preprocessor> token_per_line_pp;

  std::shared_ptr<clang::CompilerInstance> ci;
  llvm::IntrusiveRefCntPtr<clang::FileManager> fm;

  clang::TranslationUnitDecl *tu{nullptr};

  // List of tokens.
  std::vector<TokenImpl> tokens;

  // Huge "file" containing one token per line. Sometimes some lines are empty.
  // This represents all code after pre-processing, and the relationship is that
  // there is one line per token in `tokens` above.
  std::string preprocessed_code;

  // This is a backup store of data for token data, so that we don't need to
  // go back to the source manager to find the token data (as we need to find
  // it to fill up `preprocessed_code` anyway).
  std::string backup_token_data;

  // Append a token to the end of the AST. `offset` is the offset in
  // `preprocessed_code`, and `len` is the length in bytes of the token itself.
  void AppendToken(const clang::Token &tok, size_t offset, size_t len);

  // Append a token to the end of the AST. `offset` is the offset in
  // `backup_token_data`, and `len` is the length in bytes of the token itself.
  void AppendBackupToken(const clang::Token &tok, size_t offset, size_t len);
};

}  // namespace pasta
