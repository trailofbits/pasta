/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/AST.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Type.h>
#include <clang/AST/PrettyPrinter.h>
#include <clang/Basic/FileManager.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include <pasta/Util/FileManager.h>
#include <pasta/Util/File.h>
#include <pasta/Util/Result.h>
#include <string>
#include <unordered_map>
#include <variant>

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

class ASTImpl : public std::enable_shared_from_this<ASTImpl> {
 public:
  explicit ASTImpl(File main_source_file_);
  ~ASTImpl(void);

  // Try to return the token at the specified location.
  TokenImpl *RawTokenAt(clang::SourceLocation loc);

  // Try to return the token at the specified location.
  Token TokenAt(clang::SourceLocation loc);

  // Try to return the token range from the specified source range.
  TokenRange TokenRangeFrom(clang::SourceRange range);

  // This is an `LLVMFileSystem`, from inside `lib/Compile/FileSystem.h`.
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_fs;

  // A plain old overlay file system.
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_fs;

  // An in-memory file system, which sits in front of the `real_fs`.
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_fs;

  // Preprocessor over the original source code.
  std::shared_ptr<clang::Preprocessor> orig_source_pp;

  // Preprocessor over `preprocessed_code`, the huge file where there is a
  // single token per line.
  std::shared_ptr<clang::Preprocessor> token_per_line_pp;

  // Used to find bounds on declarations.
  std::unordered_map<clang::Decl *, clang::Decl *> lexically_containing_decl;
  std::unordered_map<clang::Decl *, std::pair<TokenImpl *, TokenImpl *>> bounds;

  // Maps parens/brackets/braces to each-other.
  std::unordered_map<TokenImpl *, TokenImpl *> matching;

  std::shared_ptr<clang::CompilerInstance> ci;
  llvm::IntrusiveRefCntPtr<clang::FileManager> fm;

  clang::TranslationUnitDecl *tu{nullptr};

  // The main source file which we parsed.
  ::pasta::File main_source_file;

  // All parsed files.
  std::vector<::pasta::File> parsed_files;

  // Mapping of Clang source manager file IDs to offsets within `parsed_files`.
  std::unordered_map<unsigned  /* clang::FileID */, ::pasta::File> id_to_file;

  // List of parsed tokens. We run the pre-processor, and each lexed token is
  // added here. We also inject in some other tokens, such as whitespace and
  // comments.
  std::vector<TokenImpl> tokens;
  unsigned num_lines{0u};

  // List of token contexts from trying to print the entire AST using the token
  // printer. The `TokenImpl::context_index` fields of the `tokens` vector above
  // point into here.
  //
  // NOTE(pag): The last context in this list holds a raw data pointer to the
  //            `ASTImpl` containing `contexts`. This is so that we can get the
  //            `Decl`s, `Stmt`s, and `Type`s referenced by a token context.
  //            This is safe because a `TokenContext` has a shared pointer to
  //            a vector of contexts (this vector), where that shared pointer
  //            aliases the `ASTImpl`s lifetime.
  std::vector<TokenContextImpl> contexts;

  // Huge "file" containing one token per line. Sometimes some lines are empty.
  // This represents all code after pre-processing, and the relationship is that
  // there is one line per token in `tokens` above.
  std::string preprocessed_code;

  // This is a backup store of data for token data, so that we don't need to
  // go back to the source manager to find the token data (as we need to find
  // it to fill up `preprocessed_code` anyway).
  std::string backup_token_data;

  // Useful for when we want to print tokens of decls and such.
  std::unique_ptr<clang::PrintingPolicy> printing_policy;

  // Where we expect the next macro use end location to be.
  clang::SourceLocation macro_use_end_loc;

  // Try to inject a token to represent the ending of a top-level macro
  // expansion.
  bool TryInjectEndOfMacroExpansion(clang::SourceLocation loc);

  // Append a marker token to the parsed token list.
  void AppendMarker(clang::SourceLocation loc, TokenRole role);

  // Append a token to the end of the AST. `offset` is the offset in
  // `preprocessed_code`, and `len` is the length in bytes of the token itself.
  void AppendToken(const clang::Token &tok, size_t offset, size_t len);

  // Append a token to the end of the AST. `offset` is the offset in
  // `backup_token_data`, and `len` is the length in bytes of the token itself.
  void AppendBackupToken(const clang::Token &tok, size_t offset, size_t len);

  // Try to return the inclusive bounds of a given declaration in terms of
  // parsed tokens. This doesn't not try to expand the range to the ending
  // of macro expansions.
  std::pair<TokenImpl *, TokenImpl *> DeclBounds(clang::Decl *decl);

  // Return a token range for the bounds of a declaration.
  TokenRange DeclTokenRange(const clang::Decl *decl);

  // Try to align parsed tokens with printed tokens. See `AlignTokens.cpp`.
  static Result<std::monostate, std::string> AlignTokens(
      const std::shared_ptr<ASTImpl> &ast_,
      TokenImpl *parsed_begin, TokenImpl *parsed_end,
      PrintedTokenRangeImpl &range, TokenContextIndex decl_context_id,
      bool log=false);

  // Try to align parsed tokens with printed tokens. See `AlignTokens.cpp`.
  static Result<AST, std::string> AlignTokens(std::shared_ptr<ASTImpl> ast);

 private:
  ASTImpl(void) = delete;
};

}  // namespace pasta
