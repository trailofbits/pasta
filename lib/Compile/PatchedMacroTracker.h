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
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/FileEntry.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/TokenKinds.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/PPCallbacksEventKind.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

#if !defined(LLVM_CLANG_HAS_PASTA_EVENTS)
# error "PASTA requires patches to clang::PPCallbacks."
#endif

#include <pasta/Util/Compiler.h>

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

namespace pasta {

// Tracks macros using patched-in events to Clang.
class PatchedMacroTracker : public clang::PPCallbacks {
 private:
  clang::Preprocessor &pp;
  clang::SourceManager &sm;
  clang::CompilerInstance &ci;
  clang::LangOptions &lo;
  clang::Token skipped_hash;

  ASTImpl * const ast;
  // llvm::raw_string_ostream token_data_stream;
  // llvm::raw_string_ostream backup_token_data_stream;

  std::string indent;
  bool suppress_indent{false};

  int depth{0};

  // NOTE(pag): `macro_skip_count` tells us if we're inside of a cancelled
  //            macro. `cond_skip_depth` tells us if we're inside of section
  //            of code disabled by a conditional directive.
  int cond_skip_depth{0};
  int macro_skip_count{0};

  bool skipped_area_recursive_lock{false};

  std::vector<MacroDirectiveImpl *> includes;
  clang::Token last_token;
  bool last_token_was_added{false};
  EventKind last_event{EventKind::TokenFromLexer};

  std::vector<std::string> tok_data_vec;
  size_t next_tok_data{0};


  std::vector<MacroNodeImpl *> popped_nodes;

  std::vector<MacroNodeImpl *> nodes;
  std::vector<MacroDirectiveImpl *> directives;
  std::vector<MacroExpansionImpl *> expansions;
  std::vector<MacroArgumentImpl *> arguments;
  std::vector<MacroSubstitutionImpl *> substitutions;
  std::vector<MacroSubstitutionImpl *> stringifies;
  std::vector<MacroParameterSubstitutionImpl *> params;

  MacroVAOptImpl *vaopt{nullptr};
  MacroVAOptArgumentImpl *vaopt_arg{nullptr};

  // The last concatenation. If we read a token after doing a concatenation,
  // then we want to re-parent the concatenation into the place where the
  // token was used.
  MacroSubstitutionImpl *last_concatenation{nullptr};

  // Normally this is the most recent directive; however, in the case of
  // conditional directives, this is the last top-level one. In this latter
  // case, there may be more recent directives, but they are all inside of
  // a skipped code area.
  MacroDirectiveImpl *last_directive{nullptr};

  std::unordered_map<const clang::MacroInfo *, MacroDirectiveImpl *> defines;

  // In evil scenarios where pre-expansion is cancelled (e.g. due to a nested
  // _Pragma()), Clang may presend us with an EOD/EOF that is really
  // meant to be a comma or closing parenthesis. This trips up our pre-
  // expansion argument prefix injection logic. So to handle this, we try
  // to recover the intended token from its location.
  std::unordered_map<clang::SourceLocation::UIntTy, clang::Token>
      end_of_arg_toks;

  // Values to substitute for `__COUNTER__`. We need to try to maintain a
  // semblance of uniqueness, but also we want to try to have better
  // reproducibility across translation units, where the same macro in the
  // same header using a `__COUNTER__` ends up expanding to the same value.
  std::unordered_map<unsigned, unsigned> next_counter_value;
  unsigned last_counter_id{0};

 public:

  explicit PatchedMacroTracker(clang::Preprocessor &pp_,
                               clang::SourceManager &sm_,
                               ASTImpl *ast_);

  void Clear(void);

  virtual ~PatchedMacroTracker(void);

  void FlushPopped(void);

 private:

  void SetupNode(MacroNodeImpl *node);
  void PopNode(void);

  void Push(const clang::Token &tok);
  void Pop(const clang::Token &tok);

  bool TryExtractHeaderName(const clang::Token &tok);

  // Returns `true` if adding to the parent node ended up wrapping this thing
  // in an argument.
  bool AddToParentNode(Node node);

  // Add a token in.
  void DoToken(const clang::Token &tok, uintptr_t);

  // Notify us that we're skipping `tok`.
  void SkipToken(const clang::Token &tok, uintptr_t);

  std::optional<clang::Token> FindDirectiveHash(const clang::Token &tok);

  MacroExpansionImpl *DoPreExpansionSetup(MacroExpansionImpl *);

  void DoBeginSkippedArea(const clang::Token &tok, uintptr_t data);

  void DoBeginDirective(const clang::Token &tok, uintptr_t data);

  // Mark this as being a directive with a name.
  void DoSetNamedDirective(const clang::Token &, uintptr_t);
  void DoEndNonDirective(const clang::Token &tok, uintptr_t data);
  void DoEndDirective(const clang::Token &tok, uintptr_t data);
  void DoBeginMacroExpansion(const clang::Token &tok, uintptr_t data);
  void DoBeginMacroCallArgument(const clang::Token &, uintptr_t);
  void DoEndMacroCallArgument(const clang::Token &, uintptr_t);
  void DoEndMacroCallArgumentList(const clang::Token &tok, uintptr_t);
  void DoBeginVariadicCallArgumentList(const clang::Token &, uintptr_t);
  void DoBeginPreArgumentExpansion(const clang::Token &, uintptr_t);
  void DoEndPreArgumentExpansion(const clang::Token &, uintptr_t);
  void DoSwitchToExpansion(const clang::Token &, uintptr_t);
  void DoPrepareToCancelExpansion(const clang::Token &, uintptr_t);
  void DoCancelExpansion(const clang::Token &, uintptr_t);
  void DoEndMacroExpansion(const clang::Token &tok, uintptr_t data);
  void DoBeginSubstitution(const clang::Token &tok, uintptr_t data);
  void DoBeginDelayedSubstitution(const clang::Token &tok, uintptr_t data);
  void DoSwitchToSubstitution(const clang::Token &, uintptr_t);
  void DoEndSubstitution(const clang::Token &tok, uintptr_t data);

  void DoBeginConcatenation(const clang::Token &tok, uintptr_t data);
  void DoConcatenationOperatorToken(const clang::Token &tok, uintptr_t data);
  void DoConcatenationAccumulationToken(const clang::Token &tok, uintptr_t data);
  void DoEndConcatenation(const clang::Token &tok, uintptr_t data);

  void DoBeforeParameterSubstitutions(const clang::Token &tok, uintptr_t data);
  void DoAfterParameterSubstitutions(const clang::Token &tok, uintptr_t data);

  void DoBeforeMacroParameterUse(const clang::Token &tok, uintptr_t data);
  void DoAfterMacroParameterUse(const clang::Token &tok, uintptr_t data);

  void DoBeforeVAOpt(const clang::Token &tok, uintptr_t data);
  void DoAfterVAOpt(const clang::Token &tok, uintptr_t data);

  void DoBeforeStringify(const clang::Token &tok, uintptr_t data);
  void DoAfterStringify(const clang::Token &tok, uintptr_t data);

 public:
  void Event(const clang::Token &tok, EventKind kind, uintptr_t data) final;

  // Callback invoked whenever an inclusion directive of any kind (`#include`,
  // `#import`, etc.) has been processed, regardless of whether the inclusion
  // will actually result in an inclusion.
  void InclusionDirective(
      clang::SourceLocation /* hash_loc */,
      const clang::Token &include_tok,
      llvm::StringRef /* file_name */,
      bool /* is_angled */,
      clang::CharSourceRange /* file_name_range */,
      clang::OptionalFileEntryRef /* file */,
      llvm::StringRef /* search_path */,
      llvm::StringRef /* relative_path */,
      const clang::Module * /* imported */,
      clang::SrcMgr::CharacteristicKind /* file_type */) final;

  // Each time we enter a source file, try to keep track of it.
  void FileChanged(clang::SourceLocation loc,
                   clang::PPCallbacks::FileChangeReason reason,
                   clang::SrcMgr::CharacteristicKind file_type,
                   clang::FileID file_id = clang::FileID()) final;

  // Called when we leave the main file.
  void EndOfMainFile(void) final;

  // Callback invoked when a `#ident` or `#sccs` directive is read.
  void Ident(clang::SourceLocation loc, clang::StringRef) final;

  // Callback invoked when start reading any pragma directive.
  void PragmaDirective(clang::SourceLocation loc,
                       clang::PragmaIntroducerKind introducer) final;

  // Hook called when a source range is skipped.
  void SourceRangeSkipped(clang::SourceRange,
                          clang::SourceLocation /* endif_loc */) final;

  // Hook called whenever an `#if` is seen.
  //
  // NOTE(pag): `condition_range` might point into file locations.
  void If(clang::SourceLocation,
          clang::SourceRange /* condition_range */,
          ConditionValueKind) final;

  // Hook called whenever an `#elif` is seen.
  //
  // NOTE(pag): `condition_range` might point into file locations.
  void Elif(clang::SourceLocation,
            clang::SourceRange /* condition_range */,
            ConditionValueKind, clang::SourceLocation /* if_loc */) final;

  // Hook called whenever an `#ifdef` is seen.
  void Ifdef(clang::SourceLocation,
             const clang::Token & /* macro_name_tested */,
             const clang::MacroDefinition &) final;

  // Hook called whenever an `#ifndef` is seen.
  void Ifndef(clang::SourceLocation,
              const clang::Token & /* macro_name_tested */,
              const clang::MacroDefinition &) final;

  // Hook called whenever an `#elifdef` branch is taken.
  void Elifdef(clang::SourceLocation, const clang::Token &,
               const clang::MacroDefinition &) final;

  // Hook called whenever an `#elifdef` is skipped.
  void Elifdef(clang::SourceLocation, clang::SourceRange,
               clang::SourceLocation) final;

  // Hook called whenever an `#elifndef` branch is taken.
  void Elifndef(clang::SourceLocation, const clang::Token &,
                const clang::MacroDefinition &) final;

  // Hook called whenever an `#elifndef` is skipped.
  void Elifndef(clang::SourceLocation, clang::SourceRange,
                clang::SourceLocation) final;

  /// Hook called whenever an `#else` is seen.
  void Else(clang::SourceLocation,
            clang::SourceLocation /* if_loc */) final;

  // Hook called whenever an `#endif` is seen.
  void Endif(clang::SourceLocation,
             clang::SourceLocation /* if_loc */) final;

  // Hook called whenever a macro definition is seen.
  void MacroDefined(const clang::Token &name_tok,
                    const clang::MacroDirective *directive) final;

  // Hook called whenever a macro `#undef` is seen.
  //
  // NOTE(pag): `directive` can't be trusted.
  void MacroUndefined(const clang::Token &,
                      const clang::MacroDefinition &,
                      const clang::MacroDirective *directive) final;

  // Called by Preprocessor::HandleMacroExpandedIdentifier when a
  // macro invocation is found. We want to inject placeholder tokens into
  // the parsed range that relates to where the macro is in the original file.
  // Thus, we are trying to narrow down on the set of expansions that happen
  // at a file level, and not "sub-expansions" inside of other macro expansions.
  void MacroExpands(const clang::Token &,
                    const clang::MacroDefinition &,
                    clang::SourceRange /* use_range */,
                    const clang::MacroArgs *) final;
};

}  // namespace pasta
