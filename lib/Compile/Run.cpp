/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"

#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <iostream>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTConsumer.h>
#include <clang/Basic/Builtins.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticIDs.h>
#include <clang/Basic/DiagnosticSema.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <clang/Parse/Parser.h>
#include <clang/Sema/Sema.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Compiler.h>

#include "ParsedFileTracker.h"
#include "FileSystem.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-private-field"
#if defined(LLVM_CLANG_HAS_PASTA_EVENTS)
# include "PatchedMacroTracker.h"
using MacroTracker = pasta::PatchedMacroTracker;
#else
# include "LegacyMacroTracker.h"
using MacroTracker = pasta::LegacyMacroTracker;
#endif
#pragma GCC diagnostic pop

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

#define PASTA_DEBUG_RUN 0

namespace pasta {
namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, TLSSupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, VLASupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasLegalHalfType, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat128, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat16, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, FileEntry, File, std::unique_ptr<llvm::vfs::File>);
}  // namespace detail
namespace {

// Pre-process the code. This does a few things:
//
//    1)  Record all tokens produced as outputs from the preprocessor.
//    2)  Read out the data of each of the non-empty, non-whitespace, non-
//        comment tokens, and dump them into a buffer, `impl.preprocessed_code`.
//        This buffer will have one line for each origin preprocessed token.
//        Thus, we will have Clang re-preprocess this new buffer, and then we'll
//        be able to associated back to original tokens by using the line number
//        of the updated token.
static void PreprocessCode(ASTImpl &impl, clang::CompilerInstance &ci,
                           clang::Preprocessor &pp) {
  auto &source_manager = ci.getSourceManager();
  auto &lang_opts = ci.getLangOpts();

  llvm::raw_string_ostream os(impl.preprocessed_code);
  llvm::raw_string_ostream backup_os(impl.backup_token_data);

  std::string tok_data;
  std::string fixed_tok_data;

  pp.EnterMainSourceFile();

  // NOTE(pag): The `ParsedFileTracker` emits a token for entering files, so
  //            there will be one token already representing entering the main
  //            source file.
  auto &num_lines = impl.num_lines;

  clang::Token tok;
  for (;;) {

    // Check that we're maintaining our key invariant, which is that tokens
    // match up with line numbers.
    assert(num_lines == impl.tokens.size());

    pp.Lex(tok);

    // We might have just lexed the token following some macro expansion.
    impl.TryInjectEndOfMacroExpansion(tok.getLocation());

    // NOTE(pag): We don't need to inject a token here because the
    //            `ParsedFileTracker` will inject the end of file token for
    //            us when the `FileChanged` callback happens.
    if (tok.is(clang::tok::eof)) {
      break;
    }

    tok_data.clear();
    (void) TryReadRawToken(source_manager, lang_opts, tok, &tok_data);

    TokenRole role = TokenRole::kFileToken;

    // Try to merge with the prior token, which was a macro expansion token.
    // What this actually means is that we remove the old version of the token
    // because we'll see it again.
    if (num_lines) {
      TokenImpl &prev_tok = impl.tokens.back();
      if (prev_tok.Role() == TokenRole::kIntermediateMacroExpansionToken &&
          prev_tok.Kind() == tok.getKind() &&
          prev_tok.Location() == tok.getLocation() &&
          prev_tok.Data(impl) == tok_data) {
        assert(impl.preprocessed_code.back() == '\n');
        impl.tokens.pop_back();
        impl.preprocessed_code.pop_back();
        --num_lines;
        role = TokenRole::kFinalMacroExpansionToken;
      }
    }

    if (tok.isOneOf(clang::tok::eod, clang::tok::unknown, clang::tok::comment,
                    clang::tok::code_completion)) {
      if (tok_data.empty()) {

        // Only retain these if they're contributing something in terms of
        // source locations.
        if (auto loc = tok.getLocation(); loc.isValid() && loc.isFileID()) {
          impl.AppendMarker(loc, role);
        }

      // Comments and whitespace are stored "out-of-line" in the
      // `backup_token_data` so that they aren't part of our huge
      // fake file that has one token per line (comments/whitespace
      // might have multiple lines, so we don't want to risk them
      // spanning multiple lines in the fake file, which would break
      // our invariant of line:token, so that we can use a token's
      // line number as an index.
      } else {
        backup_os.flush();
        impl.AppendBackupToken(tok, impl.backup_token_data.size(),
                               tok_data.size());
        backup_os << tok_data;
        os << '\n';
        os.flush();
        ++num_lines;
      }
      continue;
    }

    // Figure out of the token introduces new lines. If so, we'll need
    // to "mute" them.
    auto has_new_line = false;
    for (auto ch : tok_data) {
      if ('\n' == ch || '\r' == ch) {
        has_new_line = true;
      }
    }

    // The token data read has no new lines, great!
    if (!has_new_line) {
      os.flush();
      impl.AppendToken(tok, impl.preprocessed_code.size(), tok_data.size());
      os << tok_data << '\n';
      os.flush();
      ++num_lines;
      continue;
    }

    // The token needs to be modified somehow, so add it to our backups.
    backup_os.flush();
    impl.AppendBackupToken(tok, impl.backup_token_data.size(), tok_data.size());
    backup_os << tok_data;

    // The token data read does have new lines; we need to fix it up.
    fixed_tok_data.clear();
    auto in_string = false;
    auto in_escape = false;

    for (const auto ch : tok_data) {
      if ('\n' == ch || '\r' == ch) {

        if (fixed_tok_data.empty()) {
          in_escape = false;
          continue;

        // Replace with an escaped character.
        } else if (in_string) {
          in_escape = false;

          fixed_tok_data.push_back('\\');
          if ('\n' == ch) {
            fixed_tok_data.push_back('n');
          } else {
            fixed_tok_data.push_back('r');
          }
        } else {
          in_escape = false;
          fixed_tok_data.push_back(' ');
        }

      } else if ('"' == ch) {
        if (in_escape) {
          fixed_tok_data.push_back('\\');
          fixed_tok_data.push_back('"');
          in_escape = false;

        } else if (!in_string) {
          fixed_tok_data.push_back('"');
          in_string = true;

        } else {
          fixed_tok_data.push_back('"');
          in_string = false;
        }

      } else if ('\\' == ch) {
        if (in_escape) {
          fixed_tok_data.push_back('\\');
          fixed_tok_data.push_back('\\');
          in_escape = false;
        } else {
          in_escape = true;
        }

      } else {
        if (in_escape) {
          fixed_tok_data.push_back('\\');
          in_escape = false;
        }
        fixed_tok_data.push_back(ch);
      }
    }

    os << fixed_tok_data << '\n';
    os.flush();
    ++num_lines;
  }

  pp.EndSourceFile();

  os.flush();

  // For some reason Clang doesn't invoke the `ExitFile` thing for the main
  // file.
  if (impl.tokens.back().Kind() != clang::tok::eof) {

    // We didn't get an `ExitFile`.
    if (impl.tokens.back().Role() != TokenRole::kEndOfFileMarker) {
      if (tok.is(clang::tok::eof)) {
        impl.AppendMarker(tok.getLocation().getLocWithOffset(-1),
                          TokenRole::kEndOfFileMarker);
      } else {
        auto loc = source_manager.getLocForEndOfFile(
            source_manager.getMainFileID());
        impl.AppendMarker(loc.getLocWithOffset(-1),
                          TokenRole::kEndOfFileMarker);
      }
    }
    impl.tokens.back().kind = static_cast<TokenKindBase>(clang::tok::eof);
  }

#if PASTA_DEBUG_RUN
  // NOTE(pag): If there's a compiler error that "shouldn't happen," then
  //            enabling the below code can help diagnose it.
  auto fd = open("/tmp/source.cpp", O_TRUNC | O_CREAT | O_WRONLY, 0666);
  write(fd, impl.preprocessed_code.data(), impl.preprocessed_code.size());
  close(fd);
#endif  // PASTA_DEBUG_RUN
}

}  // namespace

// Run a command ans return the AST or the first error.
Result<AST, std::string> CompileJob::Run(void) const {
  std::stringstream err;

  auto ast = std::make_shared<ASTImpl>(SourceFile());
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_vfs(
      new LLVMFileSystem(impl->file_manager));
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_vfs(
      new llvm::vfs::OverlayFileSystem(real_vfs.get()));
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_vfs(
      new llvm::vfs::InMemoryFileSystem);
  overlay_vfs->pushOverlay(mem_vfs.get());
  overlay_vfs->setCurrentWorkingDirectory(
      WorkingDirectory().generic_string());

  auto diag = std::make_unique<SaveFirstErrorDiagConsumer>(ast);
  llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diagnostics_engine(
      new clang::DiagnosticsEngine(new clang::DiagnosticIDs,
                                   new clang::DiagnosticOptions, diag.get(),
                                   false /* Take ownership of the consumer */));

  diagnostics_engine->Reset();
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

  ast->ci = std::make_shared<clang::CompilerInstance>();
  auto &ci = *(ast->ci);
  ci.setDiagnostics(diagnostics_engine.get());
  ci.setASTConsumer(std::make_unique<clang::ASTConsumer>());

  auto &invocation = ci.getInvocation();
  auto &fs_options = invocation.getFileSystemOpts();
  WorkingDirectory().generic_string().swap(fs_options.WorkingDir);

  llvm::IntrusiveRefCntPtr<clang::FileManager> fm(
      new clang::FileManager(fs_options, overlay_vfs.get()));

  ci.setFileManager(fm.get());
  ci.createSourceManager(*fm);

  // Make sure the compiler instance is starting with the approximately
  // the right cross-compilation target info.
  auto &target_opts = invocation.getTargetOpts();
  target_opts.HostTriple = llvm::sys::getDefaultTargetTriple();
  target_opts.Triple = TargetTriple();
  target_opts.ForceEnableInt128 = true;

  auto target_info = clang::TargetInfo::CreateTargetInfo(ci.getDiagnostics(),
                                                         invocation.TargetOpts);

  // Some systems/targets declare/include these types, though the current target
  // may not. Nonetheless, we want to parse them.
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, TLSSupported) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, VLASupported) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat128) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat16) = true;

  const bool had_legal_half_type = target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasLegalHalfType);
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasLegalHalfType) = true;
  
  ci.setTarget(target_info);

  const auto &argv = Arguments();
  llvm::ArrayRef<const char *> argv_arr(argv.Argv(), argv.Size());

//  // NOTE(pag): `CreateFromArgs` below requires that we not pass in a
//  //            `-cc1` command.
//  if (!argv_arr.empty() && !strcmp(argv_arr.front(), "-cc1")) {
//    argv_arr = argv_arr.slice(1);
//  }

  const auto invocation_is_valid = clang::CompilerInvocation::CreateFromArgs(
      invocation, argv_arr, *diagnostics_engine);

  if (!invocation_is_valid) {
    if (diag->error.empty()) {
      err << "Unable to create compiler invocation from command: "
          << argv.Join();
      return err.str();
    } else {
      err << "Unable to create compiler invocation from command due to error: "
          << diag->error;
      return err.str();
    }
  } else if (!diag->error.empty()) {
    err << "Unable to create compiler invocation from command due to error: "
        << diag->error;
    return err.str();
  }

  // Just in case parsing of the command-line args changed this.
  diagnostics_engine->setConstexprBacktraceLimit(0);
  diagnostics_engine->setTemplateBacktraceLimit(0);
  diagnostics_engine->setErrorLimit(1);
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);
  diagnostics_engine->setErrorsAsFatal(true);

  // Some old GNU code exposes some C++ functions, e.g. `acosf`, as `constexpr`
  // implemented in terms of builtins like `__builtin_acosf`, but really this is
  // not valid. Nonetheless, we want to parse these cases.
  diagnostics_engine->setSeverity(
      clang::diag::note_invalid_subexpr_in_const_expr,
      clang::diag::Severity::Ignored,
      clang::SourceLocation());
  diagnostics_engine->setSeverity(
      clang::diag::ext_constexpr_function_never_constant_expr,
      clang::diag::Severity::Ignored,
      clang::SourceLocation());
  diagnostics_engine->setSeverity(
      clang::diag::ext_init_list_variable_narrowing,
      clang::diag::Severity::Ignored,
      clang::SourceLocation());
  diagnostics_engine->setSeverity(
      clang::diag::warn_init_list_variable_narrowing,
      clang::diag::Severity::Ignored,
      clang::SourceLocation());

  // TODO(pag): Consider setting `UsePredefines` to `false` and using an
  //            `-include` file generated by `mu-import` to deal with platform
  //            and compiler differences.
  //
  // TODO(pag): Generate said pre-define include file.
  //
  // TODO(pag): We can possibly also emit implicitly generated functions
  //            and typedefs (via pretty printing) to this file, and also
  //            disable their generation. This will then hopefully mean
  //            fewer implicit decls in the indexer.
  auto &pp_options = invocation.getPreprocessorOpts();
  pp_options.DetailedRecord = true;
  pp_options.SingleFileParseMode = false;
  pp_options.LexEditorPlaceholders = false;
  pp_options.RetainRemappedFileBuffers = true;

  auto &ppo_options = invocation.getPreprocessorOutputOpts();
  ppo_options = {};  // Reset to defaults.

  const auto lang_opts = invocation.getLangOpts();

  // Disable cpp language option that enable true/false keyword. It
  // can have conflict with C identifiers declaring true/false
  // lang_opts->Bool = true;
  lang_opts->Half = had_legal_half_type;
  lang_opts->WChar = lang_opts->CPlusPlus;
  lang_opts->Char8 = true;
  lang_opts->IEEE128 = true;
  lang_opts->EmitAllDecls = true;
  lang_opts->CXXExceptions = true;
  lang_opts->Coroutines = true;
  lang_opts->Blocks = true;
  lang_opts->POSIXThreads = true;
  lang_opts->HeinousExtensions = true;
  lang_opts->DoubleSquareBracketAttributes = true;
  lang_opts->GNUMode = true;
  lang_opts->GNUKeywords = true;
  lang_opts->GNUAsm = true;
  lang_opts->SpellChecking = false;
  lang_opts->RetainCommentsFromSystemHeaders = false;
  lang_opts->AllowEditorPlaceholders = false;
  lang_opts->CommentOpts.ParseAllComments = false;
  lang_opts->ForceEmitVTables = true;

  // Affects `PPCallbacks`, and also does additional parsing of things in
  // Objective-C mode, e.g. parsing module imports.
  lang_opts->DebuggerSupport = true;

  // TODO(pag): Should pragmas be ignored?

  // Enable C++-style comments, even in C code. If we don't do this, then we
  // can observe two tokens for something like `// foo` in C code, one is a
  // `slash`, the second is a `comment`.
  lang_opts->LineComment = true;

  // Don't get whitespace.
  lang_opts->TraditionalCPP = false;

  auto &frontend_opts = invocation.getFrontendOpts();
  frontend_opts.StatsFile.clear();
  frontend_opts.OverrideRecordLayoutsFile.clear();
  frontend_opts.ASTDumpFilter.clear();

  // TODO(pag): Eventually support? A better way would be to load them into
  //            `Compiler` or into `CompileCommand`.
  frontend_opts.Plugins.clear();
  frontend_opts.ActionName.clear();
  frontend_opts.PluginArgs.clear();
  frontend_opts.AddPluginActions.clear();

  // Go check that we've got an input file, them initialize the source manager
  // with the first input file.
  auto &input_files = frontend_opts.Inputs;
  if (input_files.empty()) {
    err << "No input file in compilation command: " << argv.Join();
    return err.str();

  // There should only be one input files, as we're dealing with `-cc1`
  // commands, not frontend commands.
  } else if (1u < input_files.size()) {
    err << "Too many input files in compilation command: " << argv.Join();
    return err.str();
  }

  auto &invocation_target = ci.getTarget();

  // Create TargetInfo for the other side of CUDA and OpenMP compilation.
  if ((lang_opts->CUDA || lang_opts->OpenMPIsDevice) &&
      !frontend_opts.AuxTriple.empty()) {
    auto aux_target = std::make_shared<clang::TargetOptions>();
    aux_target->Triple = llvm::Triple::normalize(frontend_opts.AuxTriple);
    aux_target->HostTriple = invocation_target.getTriple().str();
    ci.setAuxTarget(
        clang::TargetInfo::CreateTargetInfo(*diagnostics_engine, aux_target));
  }

  invocation_target.adjust(*diagnostics_engine, *lang_opts);
  invocation_target.adjustTargetOptions(ci.getCodeGenOpts(),
                                        ci.getTargetOpts());

  if (auto aux_target = ci.getAuxTarget(); aux_target) {
    invocation_target.setAuxTarget(aux_target);
  }

  // Clear out any dependency file stuff. Sometimes the paths for the dependency
  // files are incorrect, and that shouldn't hold up a build.
  auto &dep_opts = ci.getDependencyOutputOpts();
  dep_opts = clang::DependencyOutputOptions();

  ci.createPreprocessor(clang::TU_Complete);
  auto &pp = ci.getPreprocessor();
  auto &sm = ci.getSourceManager();

  ast->orig_source_pp = ci.getPreprocessorPtr();

  // TODO(pag): Eventually add `PPCallbacks` so that we can capture macro
  //            definitions as tokens.
  auto file_tracker_ptr = new ParsedFileTracker(
      sm, *lang_opts, impl->file_manager, WorkingDirectory(), ast.get());
  {
    std::unique_ptr<clang::PPCallbacks> file_tracker(file_tracker_ptr);
    pp.addPPCallbacks(std::move(file_tracker));
  }

  auto macro_tracker_ptr = new MacroTracker(pp, sm, ast.get());
  {
    std::unique_ptr<clang::PPCallbacks> macro_tracker(macro_tracker_ptr);
    pp.addPPCallbacks(std::move(macro_tracker));
  }

  pp.SetCommentRetentionState(false /* KeepComments */,
                              false /* KeepMacroComments */);

  pp.getBuiltinInfo().initializeBuiltins(pp.getIdentifierTable(), *lang_opts);
  pp.setPragmasEnabled(true);

  // Picks up on the pre-processor and stuff.
  ci.InitializeSourceManager(input_files[0]);
  PreprocessCode(*ast, ci, pp);

  // If we didn't end up tracking any files then something is seriously wrong.
  assert(!ast->id_to_file.empty());

  file_tracker_ptr->Clear();
  macro_tracker_ptr->Clear();

  // Replace the main source file with the preprocessed file.
  const auto main_file_name = input_files[0].getFile().str();
  auto added_file = mem_vfs->addFile(
      "<pasta-input>", std::numeric_limits<time_t>::max(),
      llvm::MemoryBuffer::getMemBuffer(ast->preprocessed_code,
                                       "<pasta-input>", false),
      llvm::None, llvm::None, llvm::sys::fs::file_type::regular_file,
      llvm::sys::fs::perms::all_read);

  if (!added_file) {
    err << "Could not add overlay file for '" << main_file_name << "'";
    return err.str();
  }

  const auto file_entry = fm->getFile("<pasta-input>");
  if (!file_entry) {
    err << "Could not add overlay file entry for file '"
        << main_file_name << "'";
    return err.str();
  }

  const auto prev_main_file_id = sm.getMainFileID();
  const auto main_file_id = sm.createFileID(
      *file_entry, clang::SourceLocation(), clang::SrcMgr::C_User);

  if (!main_file_id.isValid()) {
    err << "Failed to create a valid ID for the overlay file entry for file '"
        << main_file_name << "'";
    return err.str();
  }

  if (prev_main_file_id == main_file_id) {
    err << "Source manager ID for the overlay file '"
        << main_file_name << "' is the same as the original";
    return err.str();
  }

  // Disable `#include`s as we'll only be dealing with a single, already
  // pre-processed file from now on.
  pp_options.SingleFileParseMode = true;
  sm.setMainFileID(main_file_id);

  ci.createPreprocessor(clang::TU_Complete);
  ci.createASTContext();
  ci.createSema(clang::TU_Complete, nullptr);

  //auto &source_manager = ci.getSourceManager();
  auto &ast_context = ci.getASTContext();
  auto &ast_consumer = ci.getASTConsumer();
  auto &sema = ci.getSema();
  auto &pp2 = ci.getPreprocessor();
  ast->token_per_line_pp = ci.getPreprocessorPtr();

  assert(pp2.getLangOpts().EmitAllDecls);
  assert(lang_opts->EmitAllDecls);

  std::unique_ptr<clang::Parser> parser(
      new clang::Parser(pp2, sema, false /* SkipFunctionBodies */));

  pp2.getBuiltinInfo().initializeBuiltins(pp2.getIdentifierTable(), *lang_opts);
  pp2.setPreprocessedOutput(false);
  pp2.setPragmasEnabled(true);
  pp2.EnterMainSourceFile();
  parser->Initialize();

  clang::Parser::DeclGroupPtrTy a_decl;
  for (auto at_eof = parser->ParseFirstTopLevelDecl(a_decl); !at_eof;
       at_eof = parser->ParseTopLevelDecl(a_decl)) {

    // Parsing a dangling top-level semicolon will result in a null declaration.
    if (a_decl && !ast_consumer.HandleTopLevelDecl(a_decl.get())) {
      break;
    }
  }

  // Process any TopLevelDecls generated by #pragma weak.
  for (auto decl : sema.WeakTopLevelDecls()) {
    if (decl && !ast_consumer.HandleTopLevelDecl(clang::DeclGroupRef(decl))) {
      break;
    }
  }

  // Finalize any leftover instantiations.
  sema.PerformPendingInstantiations(false);

  if (diagnostics_engine->hasUncompilableErrorOccurred() ||
      diagnostics_engine->hasFatalErrorOccurred()) {
    if (diag->error.empty()) {
      err << "A clang diagnostic or uncompilable error was produced when trying"
          << " to get an AST: " << argv.Join();
      return err.str();

    } else {
      err << "A clang diagnostic or uncompilable error was produced when trying"
          << " to get an AST due to error: " << diag->error;
      return err.str();
    }
  } else if (!diag->error.empty()) {
    err << "A clang diagnostic was produced when trying"
        << " to get an AST due to error: " << diag->error;
    return err.str();
  }

  ast->real_fs = std::move(real_vfs);
  ast->overlay_fs = std::move(overlay_vfs);
  ast->mem_fs = std::move(mem_vfs);
  ast->fm = std::move(fm);
  ast->tu = ast_context.getTranslationUnitDecl();
  ast->printing_policy.reset(new clang::PrintingPolicy(*lang_opts));

  // Initialize the policy to print tokens as closely as possible to what is
  // written in the original code.
  if (auto policy = ast->printing_policy.get()) {
    policy->ConstantArraySizeAsWritten = true;
    policy->ConstantsAsWritten = true;
    policy->PrintCanonicalTypes = false;
    policy->PrintInjectedClassNameWithArguments = false;
    policy->SuppressUnwrittenScope = true;
    policy->AnonymousTagLocations = false;
    policy->IncludeTagDefinition = true;
  }

#ifdef PASTA_IN_BOOTSTRAP
  return AST(std::move(ast));
#else
  return ASTImpl::AlignTokens(std::move(ast));
#endif
}

}  // namespace pasta
