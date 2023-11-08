/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/AST.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#include <clang/AST/Type.h>
#include <clang/AST/PrettyPrinter.h>
#include <clang/Basic/Builtins.h>
#include <clang/Basic/FileManager.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include <pasta/Util/FileManager.h>
#include <pasta/Util/File.h>
#include <pasta/Util/Result.h>
#include <string>
#include <unordered_map>
#include <variant>
#include <mutex>

#include "Macro.h"
#include "Token.h"

#ifndef PASTA_LLVM_18
#define AS_C23 AS_C2x
#endif

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

class RootMacroNode;

class ASTImpl : public std::enable_shared_from_this<ASTImpl> {
 public:
  explicit ASTImpl(File main_source_file_);
  ~ASTImpl(void);

  // Try to return the file token at the specified location.
  std::optional<FileToken> FileTokenAt(clang::SourceLocation loc);

  // Try to return the token at the specified location.
  TokenImpl *RawTokenAt(clang::SourceLocation loc);

  // Try to return the token at the specified location.
  Token TokenAt(clang::SourceLocation loc);

  // Try to return the token at the specified location.
  Token TokenAt(const TokenImpl *tok);

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

  std::mutex bounds_mutex;

  using BoundingTokens = std::pair<TokenImpl *, TokenImpl *>;

  std::unordered_map<void *, std::pair<TokenImpl *, TokenImpl *>> bounds;

  struct FunctionProto {
    bool has_variable_form{false};
    TokenImpl *l_paren{nullptr};
    TokenImpl *r_paren{nullptr};
    TokenImpl *ellipsis{nullptr};
    std::vector<BoundingTokens *> params;
  };

  // The location of a `...` for a given `FunctionDecl`.
  std::unordered_map<clang::FunctionDecl *, FunctionProto> func_proto;

  // Remapped declarations (for the sake of bounds checks).
  std::unordered_map<clang::Decl *, clang::Decl *> remapped_decls;

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

  // List of macro directives.
  RootMacroNode root_macro_node;

  // List of parsed tokens. We run the pre-processor, and each lexed token is
  // added here. We also inject in some other tokens, such as whitespace and
  // comments.
  //
  // NOTE(pag): If this is modified, then so should `num_lines`, and
  //            `preprocessed_code`.
  // TODO(pag): Better abstraction for these types of modifications.
  std::vector<TokenImpl> tokens;

  // Maps from tokens with `TokenImpl::is_macro_name` set to the macro node
  // associated with the define macro directive.
  std::unordered_map<uint32_t, Node> tokens_to_macro_definitions;

  // Number of lines in `preprocessed_code`, which should match up with
  // `tokens.size()`.
  //
  // NOTE(pag): If this is modified, then so should `preprocessed_code`, and
  //            `tokens`.
  // TODO(pag): Better abstraction for these types of modifications.
  unsigned num_lines{0u};

  // Huge "file" containing one token per line. Sometimes some lines are empty.
  // This represents all code after pre-processing, and the relationship is that
  // there is one line per token in `tokens` above.
  //
  // NOTE(pag): If this is modified, then so should `num_lines`, and `tokens`.
  // TODO(pag): Better abstraction for these types of modifications.
  std::string preprocessed_code;

  // This is a backup store of data for token data, so that we don't need to
  // go back to the source manager to find the token data (as we need to find
  // it to fill up `preprocessed_code` anyway).
  std::string backup_token_data;

  // Useful for when we want to print tokens of decls and such.
  std::unique_ptr<clang::PrintingPolicy> printing_policy;

  // Where we expect the next macro use end location to be.
  clang::SourceLocation macro_use_end_loc;

  // We swap in our own builtins, derived from the target-specific ones.
  std::vector<clang::Builtin::Info> target_specific_records;
  std::vector<clang::Builtin::Info> aux_target_specific_records;

  // Append a marker token to the parsed token list.
  void AppendMarker(clang::SourceLocation loc, TokenRole role);

  // Append a token to the end of the AST. `offset` is the offset in
  // `preprocessed_code`, and `len` is the length in bytes of the token itself.
  void AppendToken(const clang::Token &tok, size_t offset, size_t len,
                   TokenRole role);

  // Append a token to the end of the AST. `offset` is the offset in
  // `backup_token_data`, and `len` is the length in bytes of the token itself.
  void AppendBackupToken(const clang::Token &tok, size_t offset, size_t len,
                         TokenRole role);

  // Try to return the inclusive bounds of a given declaration in terms of
  // parsed tokens. This doesn't not try to expand the range to the ending
  // of macro expansions.
  std::pair<TokenImpl *, TokenImpl *> DeclBounds(clang::Decl *decl);

  std::pair<TokenImpl *, TokenImpl *> PartitionDeclContext(
      clang::DeclContext *dc);

  // Return a token range for the bounds of a declaration.
  TokenRange DeclTokenRange(const clang::Decl *decl);
  TokenRange DeclTokenRange(const clang::Decl *decl,
                            std::unique_lock<std::mutex> locker);

  // Mark tokens as being part of macros.
  void MarkMacroTokens(void);

  // Link in macro tokens to the token contexts of tokens with macro roles.
  void LinkMacroTokenContexts(void);

  // Figure out lexical parentage. This is an important pre-processing step
  // prior to bounds calculation.
  void PreprocessLexicalParentage(void);

 private:
  ASTImpl(void) = delete;
};

}  // namespace pasta
