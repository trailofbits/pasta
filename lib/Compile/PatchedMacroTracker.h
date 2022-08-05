/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"

#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

#if defined(LLVM_CLANG_HAS_PASTA_EVENTS)

#include <pasta/Util/Compiler.h>

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

namespace pasta {
namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, CurTokenLexer, std::unique_ptr<clang::TokenLexer>);
}  // namespace detail

// Tracks macros using patched-in events to Clang.
class PatchedMacroTracker : public clang::PPCallbacks {
 private:
  clang::Preprocessor &pp;
  clang::SourceManager &sm;
  clang::CompilerInstance &ci;
  clang::LangOptions &lo;

  ASTImpl * const ast;
  llvm::raw_string_ostream token_data_stream;
  llvm::raw_string_ostream backup_token_data_stream;

  std::string indent;

  int depth{0};
  int skip_count{0};
  clang::Token last_token;
  bool last_token_was_added{false};
  std::string tok_data;
  std::vector<MacroNodeImpl *> nodes;
  std::vector<MacroDirectiveImpl *> directives;
  std::vector<MacroExpansionImpl *> expansions;
  std::vector<MacroArgumentImpl *> arguments;
  std::vector<MacroSubstitutionImpl *> substitutions;
  MacroDirectiveImpl *last_directive{nullptr};
  std::unordered_map<const clang::MacroInfo *, MacroDirectiveImpl *> defines;

 public:

  explicit PatchedMacroTracker(clang::Preprocessor &pp_,
                               clang::SourceManager &sm_,
                               ASTImpl *ast_)
      : pp(pp_),
        sm(sm_),
        ci(*(ast_->ci)),
        lo(ci.getLangOpts()),
        ast(ast_),
        token_data_stream(ast->preprocessed_code),
        backup_token_data_stream(ast->backup_token_data) {
    (void) pp;
    nodes.push_back(&(ast->root_macro_node));
  }

  virtual ~PatchedMacroTracker(void) {}

  void Clear(void) {
    assert(!depth);
    assert(nodes.size() == 1u);
    assert(directives.empty());
    assert(expansions.empty());
    depth = 0;
    defines.clear();
  }

  void Push(const clang::Token &tok) {
    if (!depth) {
      ast->AppendMarker(tok.getLocation(), TokenRole::kBeginOfMacroExpansionMarker);
    }
    ++depth;
  }

  void Pop(const clang::Token &tok) {
    assert(0 < depth);
    --depth;
    if (!depth) {
      ast->AppendMarker(tok.getLocation(), TokenRole::kEndOfMacroExpansionMarker);
    }
  }

  // Add a token in.
  void DoToken(const clang::Token &tok, uintptr_t) {
    last_token = tok;

    if (1u == nodes.size() || tok.is(clang::tok::eod) ||
        tok.is(clang::tok::eof)) {
      last_token_was_added = false;
      return;
    }

    // Get the token data, and add the data to the AST's backup region, and a
    // empty newline to the normal token data, so that the 1:1 mapping between
    // line numbers in parsed source locations and tokens recorded matches up.
    tok_data.clear();
    auto offset = ast->backup_token_data.size();
    if (::pasta::TryReadRawToken(sm, lo, tok, &tok_data)) {
      backup_token_data_stream << tok_data;
      backup_token_data_stream.flush();
    }
    token_data_stream << '\n';
    token_data_stream.flush();
    ast->num_lines++;

    // Add the token to the AST.
    auto tok_index = ast->tokens.size();
    ast->AppendBackupToken(tok, offset, tok_data.size());
    ast->tokens.back().role = static_cast<TokenKindBase>(
        TokenRole::kMacroExpansionToken);

    // Add the token to the node.
    nodes.back()->nodes.push_back(tok_index);
    last_token_was_added = true;
  }

  void DoBeginSkippedArea(const clang::Token &tok, uintptr_t data) {
    DoBeginDirective(tok, data);
    directives.back()->is_skipped = true;
  }

  void DoBeginDirective(const clang::Token &tok, uintptr_t data) {
    Push(tok);
    MacroDirectiveImpl *directive =
        &(ast->root_macro_node.directives.emplace_back());
    nodes.back()->nodes.emplace_back(directive);
    directive->parent = nodes.back();
    nodes.push_back(directive);
    directives.push_back(directive);
    DoToken(tok, data);
  }

  // Mark this as being a directive with a name.
  void DoSetNamedDirective(const clang::Token &, uintptr_t) {
    assert(!directives.empty());
    assert(nodes.back() == directives.back());
    MacroDirectiveImpl *directive = directives.back();
    if (std::holds_alternative<size_t>(directive->nodes.back())) {
      directive->name_offset = directive->nodes.back();
    } else {
      assert(false);
    }
  }

  void DoEndNonDirective(const clang::Token &tok, uintptr_t data) {
    Pop(tok);
    assert(!directives.empty());
    assert(nodes.back() == directives.back());
    last_directive = directives.back();
    nodes.pop_back();
    directives.pop_back();

    MacroNodeImpl *parent_node = nodes.back();

    // Remove it from the parent, and move all child nodes up to the parent.
    assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
    assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) ==
           last_directive);
    parent_node->nodes.pop_back();
    parent_node->nodes.insert(parent_node->nodes.end(),
                              last_directive->nodes.begin(),
                              last_directive->nodes.end());

    last_directive = nullptr;
  }

  void DoEndDirective(const clang::Token &tok, uintptr_t data) {
    Pop(tok);
    assert(!directives.empty());
    assert(nodes.back() == directives.back());
    last_directive = directives.back();
    nodes.pop_back();
    directives.pop_back();
    MacroNodeImpl *parent_node = nodes.back();
    if (!last_directive->is_skipped) {
      return;
    }

    // If it was skipped, then remove it from the parent. Don't copy any of the
    // tokens in. Inside of skipped regions, we end up seeing partial tokens
    // that we don't want to include, like `#define` but nothing after.
    assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
    assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) ==
           last_directive);
    parent_node->nodes.pop_back();
    last_directive = nullptr;
  }

  void DoBeginMacroExpansion(const clang::Token &tok, uintptr_t data) {
    Push(tok);  // TODO(pag): Which token to pop?
    MacroExpansionImpl *expansion =
        &(ast->root_macro_node.expansions.emplace_back());
    nodes.back()->nodes.emplace_back(expansion);
    expansion->parent = nodes.back();
    nodes.push_back(expansion);
    expansions.push_back(expansion);
    DoToken(tok, data);

    // Link up the expansion with the definition. `data` might be zero in the
    // case of `_Pragma`.
    clang::MacroInfo *mi = reinterpret_cast<clang::MacroInfo *>(data);
    if (auto it = defines.find(mi); it != defines.end()) {
      if (MacroDirectiveImpl *def = it->second) {
        assert(def->kind == MacroDirectiveKind::kDefine);
        assert(def->defined_macro == mi);
        def->macro_uses.push_back(expansion);
        expansion->definition = def;
      }
    }
  }

  void DoBeginMacroCallArgument(const clang::Token &, uintptr_t) {
    assert(!expansions.empty());
    assert(nodes.back() == expansions.back());
    MacroExpansionImpl *expansion = expansions.back();
    assert(!expansion->is_cancelled);

    MacroArgumentImpl *argument =
        &(ast->root_macro_node.arguments.emplace_back());
    argument->is_variadic = expansion->is_variadic;
    argument->index = static_cast<unsigned>(expansion->arguments.size());
    argument->parent = expansion;

    expansion->nodes.emplace_back(argument);
    expansion->arguments.emplace_back(argument);
    if (argument->is_variadic) {
      expansion->variadic_arguments.emplace_back(argument);
    }
    nodes.push_back(argument);
    arguments.push_back(argument);
  }

  void DoEndMacroCallArgument(const clang::Token &, uintptr_t) {
    assert(!expansions.empty());
    assert(!arguments.empty());
    assert(nodes.back() == arguments.back());
    MacroArgumentImpl *argument = arguments.back();
    arguments.pop_back();
    nodes.pop_back();
    assert(nodes.back() == expansions.back());
    assert(std::holds_alternative<MacroNodeImpl *>(argument->parent));
    assert(nodes.back() == std::get<MacroNodeImpl *>(argument->parent));

    // Pop off the `,` or the `)` from the argument, and add it to the
    // expansion.
    if (!argument->nodes.empty()) {
      MacroNodeImpl *parent_node = std::get<MacroNodeImpl *>(argument->parent);
      assert(parent_node->Kind() == MacroNodeKind::kExpansion);
      parent_node->nodes.push_back(argument->nodes.back());
      argument->nodes.pop_back();
    }
  }

  void DoBeginVariadicCallArgumentList(const clang::Token &, uintptr_t) {
    assert(!expansions.empty());
    assert(nodes.back() == expansions.back());
    MacroExpansionImpl *expansion = expansions.back();
    assert(!expansion->is_variadic);
    assert(!expansion->is_cancelled);
    expansion->is_variadic = true;
  }

  void DoSwitchToExpansion(const clang::Token &, uintptr_t) {
    assert(!expansions.empty());
    assert(nodes.back() == expansions.back());
    MacroExpansionImpl *expansion = expansions.back();
    assert(expansion->use_nodes.empty());
    expansion->nodes.swap(expansion->use_nodes);
    assert(!expansion->is_cancelled);
  }

  void DoCancelExpansion(const clang::Token &, uintptr_t) {
    assert(!expansions.empty());
    assert(nodes.back() == expansions.back());
    MacroExpansionImpl *expansion = expansions.back();
    assert(expansion->use_nodes.empty());
    assert(!expansion->is_cancelled);
    expansion->is_cancelled = true;
  }

  void DoEndMacroExpansion(const clang::Token &tok, uintptr_t data) {
    Pop(tok);  // TODO(pag): Which token to pop?
    assert(!expansions.empty());
    MacroExpansionImpl *expansion = expansions.back();
    assert(nodes.back() == expansion);
    nodes.pop_back();
    expansions.pop_back();
    if (expansion->is_cancelled) {
      assert(expansion->use_nodes.empty());
      MacroNodeImpl *parent_node = nodes.back();
      parent_node->nodes.insert(parent_node->nodes.end(),
                                expansion->nodes.begin(),
                                expansion->nodes.end());
    }
  }

  void DoBeginSubstitution(const clang::Token &tok, uintptr_t data) {
    Push(tok);
    MacroSubstitutionImpl *expansion =
        &(ast->root_macro_node.substitutions.emplace_back());
    nodes.back()->nodes.emplace_back(expansion);
    expansion->parent = nodes.back();
    nodes.push_back(expansion);
    substitutions.push_back(expansion);
    DoToken(tok, data);
  }

  void DoBeginDelayedSubstitution(const clang::Token &tok, uintptr_t data) {

    Push(last_token);
    if (last_token_was_added) {
      auto num_tokens = ast->tokens.size();
      std::swap(ast->tokens[num_tokens - 2u], ast->tokens[num_tokens - 1u]);
    }

    MacroSubstitutionImpl *expansion =
        &(ast->root_macro_node.substitutions.emplace_back());

    MacroNodeImpl * const parent_node = nodes.back();
    expansion->parent = parent_node;

    if (last_token_was_added) {
      assert(!parent_node->nodes.empty());
      expansion->nodes.push_back(parent_node->nodes.back());
      parent_node->nodes.pop_back();
    }

    parent_node->nodes.emplace_back(expansion);

    nodes.push_back(expansion);
    substitutions.push_back(expansion);

    DoToken(tok, data);
  }

  void DoSwitchToSubstitution(const clang::Token &, uintptr_t) {
    assert(!substitutions.empty());
    assert(nodes.back() == substitutions.back());
    MacroSubstitutionImpl *expansion = substitutions.back();
    assert(expansion->use_nodes.empty());
    expansion->nodes.swap(expansion->use_nodes);
  }

  void DoEndSubstitution(const clang::Token &tok, uintptr_t data) {
    Pop(tok);  // TODO(pag): Which token to pop?
    assert(!substitutions.empty());
    assert(nodes.back() == substitutions.back());
    nodes.pop_back();
    substitutions.pop_back();
  }

  // PASTA PATCH:
  void Event(const clang::Token &tok, EventKind kind, uintptr_t data) final {
    switch (kind) {
      case TokenFromLexer:
      case TokenFromTokenLexer:
      case TokenFromCachingLexer:
      case TokenFromAfterModuleImportLexer:
        DoToken(tok, data);
        break;
      case BeginSkippedArea: DoBeginSkippedArea(tok, data); break;
      case BeginDirective: DoBeginDirective(tok, data); break;
      case SetNamedDirective: DoSetNamedDirective(tok, data); break;
      case SetUnnamedDirective: break;
      case EndNonDirective: DoEndNonDirective(tok, data); break;
      case EndDirective: DoEndDirective(tok, data); break;
      case BeginMacroExpansion: DoBeginMacroExpansion(tok, data); break;
      case CancelExpansion: DoCancelExpansion(tok, data); break;
      case SwitchToExpansion: DoSwitchToExpansion(tok, data); break;
      case EndMacroExpansion: DoEndMacroExpansion(tok, data); break;
      case BeginMacroCallArgument: DoBeginMacroCallArgument(tok, data); break;
      case EndMacroCallArgument: DoEndMacroCallArgument(tok, data); break;
      case BeginMacroCallArgumentList: break;
      case EndMacroCallArgumentList: break;
      case BeginVariadicCallArgumentList:
        DoBeginVariadicCallArgumentList(tok, data);
        break;
      case EndVariadicCallArgumentList: break;
      case BeginSubstitution: DoBeginSubstitution(tok, data); break;
      case BeginDelayedSubstitution:
        DoBeginDelayedSubstitution(tok, data);
        break;
      case SwitchToSubstitution: DoSwitchToSubstitution(tok, data); break;
      case EndSubstitution: DoEndSubstitution(tok, data); break;

      // TODO(pag): Handle these:
      case BeginSplitToken: break;
      case EndSplitToken: break;
    }
    switch (kind) {
      case EndSplitToken:
      case EndDirective:
      case EndNonDirective:
      case EndMacroExpansion:
      case EndMacroCallArgumentList:
      case EndMacroCallArgument:
      case EndVariadicCallArgumentList:
      case EndSubstitution:
        --depth;
        indent.resize(indent.size() - 2);
        break;
      default:
        break;
    }

    std::cerr << indent;

    switch (kind) {
      case TokenFromLexer: std::cerr << "TokenFromLexer"; break;
      case TokenFromTokenLexer: std::cerr << "TokenFromTokenLexer"; break;
      case TokenFromCachingLexer: std::cerr << "TokenFromCachingLexer"; break;
      case TokenFromAfterModuleImportLexer: std::cerr << "TokenFromAfterModuleImportLexer"; break;
      case BeginSplitToken: std::cerr << "BeginSplitToken"; break;
      case EndSplitToken: std::cerr << "EndSplitToken"; break;
      case BeginDirective: std::cerr << "BeginDirective"; break;
      case BeginSkippedArea: std::cerr << "BeginSkippedArea"; break;
      case SetNamedDirective: std::cerr << "SetNamedDirective"; break;
      case SetUnnamedDirective: std::cerr << "SetUnnamedDirective"; break;
      case EndDirective: std::cerr << "EndDirective"; break;
      case EndNonDirective: std::cerr << "EndNonDirective"; break;
      case BeginMacroExpansion: std::cerr << "BeginMacroExpansion"; break;
      case SwitchToExpansion: std::cerr << "SwitchToExpansion"; break;
      case CancelExpansion: std::cerr << "CancelExpansion"; break;
      case EndMacroExpansion: std::cerr << "EndMacroExpansion"; break;
      case BeginMacroCallArgumentList: std::cerr << "BeginMacroCallArgumentList"; break;
      case EndMacroCallArgumentList: std::cerr << "EndMacroCallArgumentList"; break;
      case BeginMacroCallArgument: std::cerr << "BeginMacroCallArgument"; break;
      case EndMacroCallArgument: std::cerr << "EndMacroCallArgument"; break;
      case BeginVariadicCallArgumentList: std::cerr << "BeginVariadicCallArgumentList"; break;
      case EndVariadicCallArgumentList: std::cerr << "EndVariadicCallArgumentList"; break;
      case BeginSubstitution: std::cerr << "BeginSubstitution"; break;
      case BeginDelayedSubstitution: std::cerr << "BeginDelayedSubstitution"; break;
      case SwitchToSubstitution: std::cerr << "SwitchToSubstitution"; break;
      case EndSubstitution: std::cerr << "EndSubstitution"; break;
    }

    std::cerr << ' ' << clang::tok::getTokenName(tok.getKind());

    if (tok.is(clang::tok::identifier)) {
      std::cerr << ' ' << tok.getIdentifierInfo()->getName().str();
    } else if (tok.is(clang::tok::raw_identifier)) {
      std::cerr << ' ' << tok.getRawIdentifier().str();
    }

    switch (kind) {
      case BeginSplitToken:
      case BeginDirective:
      case BeginSkippedArea:
      case BeginMacroExpansion:
      case BeginMacroCallArgumentList:
      case BeginMacroCallArgument:
      case BeginVariadicCallArgumentList:
      case BeginSubstitution:
      case BeginDelayedSubstitution:
        ++depth;
        indent += "  ";
        break;
      default:
        break;
    }

    std::cerr << '\n';
  }

  // Callback invoked whenever an inclusion directive of any kind (`#include`,
  // `#import`, etc.) has been processed, regardless of whether the inclusion
  // will actually result in an inclusion.
  void InclusionDirective(
      clang::SourceLocation /* hash_loc */, const clang::Token &include_tok,
      llvm::StringRef /* file_name */, bool /* is_angled */,
      clang::CharSourceRange /* file_name_range */,
      const clang::FileEntry * /* file */, llvm::StringRef /* search_path */,
      llvm::StringRef /* relative_path */, const clang::Module * /* imported */,
      clang::SrcMgr::CharacteristicKind /* file_type */) final {


    assert(last_directive != nullptr);
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    switch (include_tok.getIdentifierInfo()->getPPKeywordID()) {
      case clang::tok::pp_include:
        last_directive->kind = MacroDirectiveKind::kInclude;
        break;
      case clang::tok::pp_include_next:
        last_directive->kind = MacroDirectiveKind::kIncludeNext;
        break;
      case clang::tok::pp_import:
        last_directive->kind = MacroDirectiveKind::kImport;
        break;
      case clang::tok::pp___include_macros:
        last_directive->kind = MacroDirectiveKind::kIncludeMacros;
        break;
      default: break;
    }
    std::cerr << indent << "InclusionDirective\n";
  }

//  // Callback invoked whenever a source file is skipped as the result
//  // of header guard optimization.
//  void FileSkipped(const clang::FileEntryRef &skipped_file,
//                   const clang::Token &filename_tok,
//                   clang::SrcMgr::CharacteristicKind) final {
//    if (!skipped_file.isValid()) {
//      return;
//    }
//
//    auto it = seen_file_ids.find(skipped_file.getName().str());
//    if (it == seen_file_ids.end()) {
//      return;
//    }
//
//    clang::FileID file_id = it->second;
//
//    // Inject dummy tokens representing the entry and exit of this file.
//    InjectToken(sm.getLocForStartOfFile(file_id),
//                TokenRole::kBeginOfFileMarker);
//    InjectToken(sm.getLocForEndOfFile(file_id),
//                TokenRole::kEndOfFileMarker);
//  }

  // Each time we enter a source file, try to keep track of it.
  void FileChanged(clang::SourceLocation loc,
                   clang::PPCallbacks::FileChangeReason reason,
                   clang::SrcMgr::CharacteristicKind file_type,
                   clang::FileID file_id = clang::FileID()) final {
    if (clang::PPCallbacks::FileChangeReason::EnterFile == reason &&
        file_id.isValid() && !directives.empty()) {

    }
    std::cerr << indent << "FileChanged\n";
  }

  // Callback invoked when a `#ident` or `#sccs` directive is read.
  void Ident(clang::SourceLocation loc, clang::StringRef) final {
    std::cerr << indent << "Ident\n";
  }

  // Callback invoked when start reading any pragma directive.
  void PragmaDirective(clang::SourceLocation loc,
                       clang::PragmaIntroducerKind introducer) final {
    assert(!directives.empty());
    MacroDirectiveImpl *directive = directives.back();
    assert(directive->kind == MacroDirectiveKind::kOther);

    switch (introducer) {
      case clang::PragmaIntroducerKind::PIK_HashPragma:
        directive->kind = MacroDirectiveKind::kHashPragma;
        break;
      case clang::PragmaIntroducerKind::PIK__Pragma:
        directive->kind = MacroDirectiveKind::kC99Pragma;
        break;
      case clang::PragmaIntroducerKind::PIK___pragma:
        directive->kind = MacroDirectiveKind::kMicrosoftPragma;
        break;
    }
  }

  // Hook called when a source range is skipped.
  void SourceRangeSkipped(clang::SourceRange,
                          clang::SourceLocation /* endif_loc */) final {
    std::cerr << indent << "SourceRangeSkipped\n";
  }

  // Hook called whenever an `#if` is seen.
  //
  // NOTE(pag): `condition_range` might point into file locations.
  void If(clang::SourceLocation,
          clang::SourceRange /* condition_range */,
          ConditionValueKind) final {

    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kIf;
    }
    std::cerr << indent << "If\n";
  }

  // Hook called whenever an `#elif` is seen.
  //
  // NOTE(pag): `condition_range` might point into file locations.
  void Elif(clang::SourceLocation,
            clang::SourceRange /* condition_range */,
            ConditionValueKind, clang::SourceLocation /* if_loc */) final {

    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kElseIf;
    }
    std::cerr << indent << "Elif\n";
  }

  // Hook called whenever an `#ifdef` is seen.
  void Ifdef(clang::SourceLocation,
             const clang::Token & /* macro_name_tested */,
             const clang::MacroDefinition &) final {
    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kIfDefined;
    }
    std::cerr << indent << "Ifdef\n";
  }

  // Hook called whenever an `#ifndef` is seen.
  void Ifndef(clang::SourceLocation,
              const clang::Token & /* macro_name_tested */,
              const clang::MacroDefinition &) final {
    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kIfNotDefined;
    }
    std::cerr << indent << "Ifndef\n";
  }

  /// Hook called whenever an `#else` is seen.
  void Else(clang::SourceLocation,
            clang::SourceLocation /* if_loc */) final {
    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kElse;
    }
    std::cerr << indent << "Else\n";
  }

  // Hook called whenever an `#endif` is seen.
  void Endif(clang::SourceLocation,
             clang::SourceLocation /* if_loc */) final {
    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kEndIf;
    }
    std::cerr << indent << "Endif\n";
  }

  // Hook called whenever a macro definition is seen.
  void MacroDefined(const clang::Token &,
                    const clang::MacroDirective *directive) final {
    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kDefine;
      last_directive->defined_macro = directive->getMacroInfo();
    }
    std::cerr << indent << "MacroDefined\n";
  }

  // Hook called whenever a macro `#undef` is seen.
  //
  // NOTE(pag): `directive` can't be trusted.
  void MacroUndefined(const clang::Token &,
                      const clang::MacroDefinition &,
                      const clang::MacroDirective *directive) final {
    if (last_directive != nullptr) {
      assert(last_directive->kind == MacroDirectiveKind::kOther);
      last_directive->kind = MacroDirectiveKind::kUndefine;
      defines.erase(directive->getMacroInfo());
    }
    std::cerr << indent << "MacroUndefined\n";
  }

  // Called by Preprocessor::HandleMacroExpandedIdentifier when a
  // macro invocation is found. We want to inject placeholder tokens into
  // the parsed range that relates to where the macro is in the original file.
  // Thus, we are trying to narrow down on the set of expansions that happen
  // at a file level, and not "sub-expansions" inside of other macro expansions.
  void MacroExpands(const clang::Token &,
                    const clang::MacroDefinition &,
                    clang::SourceRange /* use_range */,
                    const clang::MacroArgs *) final {
    std::cerr << indent << "MacroExpands\n";
  }
};

}  // namespace pasta

#endif
