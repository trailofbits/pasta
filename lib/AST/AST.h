/*
 * Copyright (c) 2020, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

#define PASTA_LLVM_18

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

  std::optional<DerivedTokenIndex> ParsedTokenOffset(clang::SourceLocation loc) const;

  inline enum TokenKind TokenKind(DerivedTokenIndex index) const {
    return parsed_tokens.Kind(index);
  }

  inline enum TokenKind TokenKind(std::optional<DerivedTokenIndex> index) const {
    return index ? parsed_tokens.Kind(index.value()) : TokenKind::kUnknown;
  }

  ParsedTokenIterator InvalidRawToken(void) const; 
  ParsedTokenIterator RawTokenAt(clang::SourceLocation loc) const;
  ParsedTokenIterator RawTokenAt(DerivedTokenIndex offset_) const;

  // Try to return the token at the specified offset.
  Token TokenAt(DerivedTokenIndex offset);

  // Try to return the token at the specified location.
  Token TokenAt(clang::SourceLocation loc);

  // Try to return the token at the specified offset.
  Token TokenAt(std::optional<DerivedTokenIndex> offset);

  // Try to return the token range from the specified source range.
  TokenRange TokenRangeFrom(clang::SourceRange range);

  // This is an `LLVMFileSystem`, from inside `lib/Compile/FileSystem.h`.
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_fs;

  // A plain old overlay file system.
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_fs;

  // An in-memory file system, which sits in front of the `real_fs`.
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_fs;

  // Preprocessor over the original source code. This fills up `parsed_tokens`
  // and `macro_tokens`. All macro expansion happens by this preprocessor.
  std::shared_ptr<clang::Preprocessor> orig_source_pp;

  // Preprocessor over `parsed_tokens.Data()`. All parsing happens with this
  // preprocessor. We also get to observe token splitting with this
  // preprocessor.
  std::shared_ptr<clang::Preprocessor> parsed_tokens_data_pp;

  // Used to find bounds on declarations.
  std::unordered_map<clang::Decl *, clang::Decl *> lexically_containing_decl;

  using BoundingTokens = std::pair<DerivedTokenIndex, DerivedTokenIndex>;

  std::mutex bounds_mutex;

  // Bounds for AST nodes.
  std::unordered_map<void *, BoundingTokens> bounds;

  // Mapping of parsed token offsets to macros. This applies to begin/end
  // macro markers, and macro directive markers.
  std::unordered_map<DerivedTokenIndex, Node> marker_offset_to_macro;

  struct FunctionProto {
    bool has_variable_form{false};

    // NOTE(pag): `0u` is a "valid invalid" representation, because the first
    //            parsed token is always a beginning of file marker.
    DerivedTokenIndex l_paren{0u};
    DerivedTokenIndex r_paren{0u};
    DerivedTokenIndex ellipsis{0u};
    std::vector<BoundingTokens *> params;

    // TODO(pag): Handle traditional K&R style.
  };

  // The location of a `...` for a given `FunctionDecl`.
  std::unordered_map<clang::FunctionDecl *, FunctionProto> func_proto;

  // Maps parens/brackets/braces to each-other.
  std::unordered_map<DerivedTokenIndex, DerivedTokenIndex> matching;

  std::shared_ptr<clang::CompilerInstance> ci;
  llvm::IntrusiveRefCntPtr<clang::FileManager> fm;

  clang::TranslationUnitDecl *tu{nullptr};

  // The main source file which we parsed.
  ::pasta::File main_source_file;

  // All parsed files.
  std::vector<::pasta::File> parsed_files;

  // Mapping of Clang source manager file IDs to offsets within `parsed_files`.
  std::unordered_map<unsigned  /* clang::FileID */, unsigned> id_to_file_offset;

  // Mapping of a Clang source manager file offset to a File.
  std::unordered_map<unsigned  /* clang::FileID */, ::pasta::File> id_to_file;

  // List of macro directives.
  RootMacroNode root_macro_node;

  // Tracks parsed and macro tokens. Parsed token locations can refer to macro
  // tokens.
  ParsedTokenStorage invalid_tokens;
  ParsedTokenStorage parsed_tokens;
  MacroTokenStorage macro_tokens;

  // Useful for when we want to print tokens of decls and such.
  std::unique_ptr<clang::PrintingPolicy> printing_policy;

  // We swap in our own builtins, derived from the target-specific ones.
  std::vector<clang::Builtin::Info> target_specific_records;
  std::vector<clang::Builtin::Info> aux_target_specific_records;

  // Try to return the inclusive bounds of a given declaration in terms of
  // parsed tokens. This doesn't not try to expand the range to the ending
  // of macro expansions.
  BoundingTokens DeclBounds(clang::Decl *decl);

  DerivedTokenIndex MatchingIndex(DerivedTokenIndex offset);

  // Return a token range for the bounds of a declaration.
  TokenRange DeclTokenRange(const clang::Decl *decl);
  TokenRange DeclTokenRange(const clang::Decl *decl,
                            std::unique_lock<std::mutex> locker);

  // Link in macro tokens to the token contexts of tokens with macro roles.
  void LinkMacroTokenContexts(void);

 private:
  ASTImpl(void) = delete;
};

}  // namespace pasta
