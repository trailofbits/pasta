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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
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
#pragma clang diagnostic pop

#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Compiler.h>

#include "FileSystem.h"

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

  for (clang::Token tok; ; ) {
    pp.Lex(tok);

    if (tok.is(clang::tok::eof)) {
      impl.AppendToken(tok, 0, 0);
      break;
    }

    if (tok.isOneOf(clang::tok::unknown, clang::tok::comment,
                    clang::tok::code_completion) ||
        !TryReadRawToken(source_manager, lang_opts, tok, &tok_data) ||
        tok_data.empty()) {
      if (tok_data.empty()) {
        impl.AppendToken(tok, 0, 0);
      } else {
        backup_os.flush();
        impl.AppendBackupToken(tok, impl.backup_token_data.size(),
                               tok_data.size());
        backup_os << tok_data;
      }
      os << '\n';
      continue;
    }

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
  }

  pp.EndSourceFile();

  os.flush();

#if PASTA_DEBUG_RUN
  // NOTE(pag): If there's a compiler error that "shouldn't happen," then
  //            enabling the below code can help diagnose it.
  auto fd = open("/tmp/source.cpp", O_TRUNC | O_CREAT | O_WRONLY, 0666);
  write(fd, impl.preprocessed_code.data(), impl.preprocessed_code.size());
  close(fd);
#endif  // PASTA_DEBUG_RUN
}

}  // namespace


// Tracks open files.
class ParsedFileTracker : public clang::PPCallbacks {
 private:
  clang::SourceManager &sm;
  const clang::LangOptions &lang_opts;
  const pasta::FileManager fm;
  std::shared_ptr<pasta::FileSystem> fs;
  const std::filesystem::path cwd;
  ASTImpl * const ast;

  std::unordered_set<pasta::FileImpl *> seen;

 public:
  explicit ParsedFileTracker(clang::SourceManager &sm_,
                             const clang::LangOptions &lang_opts_,
                             const pasta::FileManager &fm_,
                             std::filesystem::path cwd_,
                             ASTImpl *ast_)
      : sm(sm_),
        lang_opts(lang_opts_),
        fm(fm_),
        fs(fm.FileSystem()),
        cwd(std::move(cwd_)),
        ast(ast_) {}

  virtual ~ParsedFileTracker(void) {}

  // Each time we enter a source file, try to keep track of it.
  void FileChanged(clang::SourceLocation loc,
                   clang::PPCallbacks::FileChangeReason reason,
                   clang::SrcMgr::CharacteristicKind file_type,
                   clang::FileID PrevFID = clang::FileID()) final {
    if (clang::PPCallbacks::EnterFile == reason) {
      switch (file_type) {
        case clang::SrcMgr::CharacteristicKind::C_User:
        case clang::SrcMgr::CharacteristicKind::C_System:
        case clang::SrcMgr::CharacteristicKind::C_ExternCSystem:
          break;
        case clang::SrcMgr::CharacteristicKind::C_User_ModuleMap:
        case clang::SrcMgr::CharacteristicKind::C_System_ModuleMap:
          return;
      }
    } else {
      return;
    }

    const clang::FileID file_id = sm.getFileID(loc);
    const clang::FileEntry *fe = sm.getFileEntryForID(file_id);
    if (!fe) {
      return;
    }

    auto fs_path = fs->ParsePath(fe->getName().str(), cwd, fs->PathKind());
    auto fs_stat = fs->Stat(fs_path, cwd);
    if (fs_stat.Failed()) {
      return;
    }

    auto maybe_file = fm.OpenFile(fs_stat.TakeValue());
    if (maybe_file.Failed()) {
      return;
    }

    auto file = maybe_file.TakeValue();

    // Keep a mapping of Clang file IDs to parsed files.
    auto old_file_it = ast->id_to_file.find(file_id.getHashValue());
    if (old_file_it == ast->id_to_file.end()) {
      ast->id_to_file.emplace(file_id.getHashValue(), file);
    } else {
      assert(old_file_it->second.impl.get() == file.impl.get());
    }

    if (auto [seen_it, added] = seen.emplace(file.impl.get()); !added) {
      return;
    }

    auto maybe_data = file.Data();
    if (maybe_data.Failed()) {
      return;
    }

    ast->parsed_files.emplace_back(std::move(file));

    std::unique_lock<std::mutex> locker(file.impl->tokens_lock);
    if (file.impl->has_tokens) {
      return;
    }

    auto data = maybe_data.TakeValue();
    file.impl->has_tokens = true;
    if (data.empty()) {
      return;
    }

    const char *last_tok_begin = data.data();
    const char * const buff_begin = last_tok_begin;
    const char * const buff_end = &(last_tok_begin[data.size()]);
    clang::Lexer lexer(loc, lang_opts, buff_begin, last_tok_begin, buff_end);
    lexer.SetKeepWhitespaceMode(true);

    // Raw lex this file's tokens.
    clang::Token tok;
    while (!lexer.LexFromRawLexer(tok)) {
      if (tok.is(clang::tok::eof)) {
        break;
      }

      const auto tok_loc = tok.getLocation();
      auto offset = sm.getFileOffset(tok_loc);
      assert(offset < data.size());
      auto ptr = &(buff_begin[offset]);
      file.impl->tokens.emplace_back(
          ptr, sm.getSpellingLineNumber(tok_loc),
          sm.getSpellingColumnNumber(tok_loc),
          tok.getKind());
      last_tok_begin = ptr;
    }

    const auto tok_loc = tok.getLocation();
    file.impl->tokens.emplace_back(
        buff_end, sm.getSpellingLineNumber(tok_loc),
        sm.getSpellingColumnNumber(tok_loc), clang::tok::eof);
  }
};

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

  auto ci = std::make_shared<clang::CompilerInstance>();
  ci->setDiagnostics(diagnostics_engine.get());
  ci->setASTConsumer(std::make_unique<clang::ASTConsumer>());

  auto &invocation = ci->getInvocation();
  auto &fs_options = invocation.getFileSystemOpts();
  WorkingDirectory().generic_string().swap(fs_options.WorkingDir);

  llvm::IntrusiveRefCntPtr<clang::FileManager> fm(
      new clang::FileManager(fs_options, overlay_vfs.get()));

  ci->setFileManager(fm.get());
  ci->createSourceManager(*fm);

  // Make sure the compiler instance is starting with the approximately
  // the right cross-compilation target info.
  auto &target_opts = invocation.getTargetOpts();
  target_opts.HostTriple = llvm::sys::getDefaultTargetTriple();
  target_opts.Triple = TargetTriple();
  target_opts.ForceEnableInt128 = true;

  auto target_info = clang::TargetInfo::CreateTargetInfo(ci->getDiagnostics(),
                                                         invocation.TargetOpts);

  // Some systems/targets declare/include these types, though the current target
  // may not. Nonetheless, we want to parse them.
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, TLSSupported) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, VLASupported) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasLegalHalfType) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat128) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat16) = true;
  ci->setTarget(target_info);

  const auto &argv = Arguments();
  llvm::ArrayRef<const char *> argv_arr(argv.Argv(), argv.Size());
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
  }

  // Just in case parsing of the command-line args changed this.
  diagnostics_engine->setConstexprBacktraceLimit(0);
  diagnostics_engine->setTemplateBacktraceLimit(0);
  diagnostics_engine->setErrorLimit(1);
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

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

  lang_opts->EmitAllDecls = true;
  lang_opts->CXXExceptions = true;
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

  auto &invocation_target = ci->getTarget();

  // Create TargetInfo for the other side of CUDA and OpenMP compilation.
  if ((lang_opts->CUDA || lang_opts->OpenMPIsDevice) &&
      !frontend_opts.AuxTriple.empty()) {
    auto aux_target = std::make_shared<clang::TargetOptions>();
    aux_target->Triple = llvm::Triple::normalize(frontend_opts.AuxTriple);
    aux_target->HostTriple = invocation_target.getTriple().str();
    ci->setAuxTarget(
        clang::TargetInfo::CreateTargetInfo(*diagnostics_engine, aux_target));
  }

  invocation_target.adjust(*lang_opts);
  invocation_target.adjustTargetOptions(ci->getCodeGenOpts(),
                                        ci->getTargetOpts());

  if (auto aux_target = ci->getAuxTarget(); aux_target) {
    invocation_target.setAuxTarget(aux_target);
  }

  // Clear out any dependency file stuff. Sometimes the paths for the dependency
  // files are incorrect, and that shouldn't hold up a build.
  auto &dep_opts = ci->getDependencyOutputOpts();
  dep_opts = clang::DependencyOutputOptions();

  ci->createPreprocessor(clang::TU_Complete);
  auto &pp = ci->getPreprocessor();
  ast->orig_source_pp = ci->getPreprocessorPtr();

  // TODO(pag): Eventually add `PPCallbacks` so that we can capture macro
  //            definitions as tokens.
  {
    std::unique_ptr<clang::PPCallbacks> file_tracker(new ParsedFileTracker(
        ci->getSourceManager(), ci->getLangOpts(),
        impl->file_manager, WorkingDirectory(), ast.get()));
    pp.addPPCallbacks(std::move(file_tracker));
  }
  pp.SetCommentRetentionState(true /* KeepComments */,
                              true /* KeepMacroComments */);

  pp.getBuiltinInfo().initializeBuiltins(pp.getIdentifierTable(), *lang_opts);
  pp.setPragmasEnabled(true);

  // Picks up on the pre-processor and stuff.
  ci->InitializeSourceManager(input_files[0]);
  PreprocessCode(*ast, *ci, pp);

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

  auto &sm = ci->getSourceManager();
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

  ci->createPreprocessor(clang::TU_Complete);
  ci->createASTContext();
  ci->createSema(clang::TU_Complete, nullptr);

  //auto &source_manager = ci->getSourceManager();
  auto &ast_context = ci->getASTContext();
  auto &ast_consumer = ci->getASTConsumer();
  auto &sema = ci->getSema();
  auto &pp2 = ci->getPreprocessor();
  ast->token_per_line_pp = ci->getPreprocessorPtr();

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
    }
  }

  ast->real_fs = std::move(real_vfs);
  ast->overlay_fs = std::move(overlay_vfs);
  ast->mem_fs = std::move(mem_vfs);
  ast->ci = std::move(ci);
  ast->fm = std::move(fm);
  ast->tu = ast_context.getTranslationUnitDecl();
  ast->printing_policy.reset(new clang::PrintingPolicy(*lang_opts));
  return ASTImpl::AlignTokens(std::move(ast));
}

}  // namespace pasta
