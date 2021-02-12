/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"
#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"
#include "Token.h"

#include "Visitor/MacroGenerator.h"

//#include <fcntl.h>
//#include <unistd.h>

#include <cassert>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTConsumer.h>
#include <clang/Basic/Builtins.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticIDs.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <clang/Parse/Parser.h>
#include <clang/Sema/Sema.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/VirtualFileSystem.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Compiler.h>

namespace pasta {
namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, TLSSupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, VLASupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasLegalHalfType, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat128, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat16, bool);
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
        impl.AppendBackupToken(tok, impl.backup_token_data.size(), tok_data.size());
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

//  auto fd = open("/tmp/source.cpp", O_TRUNC | O_CREAT | O_WRONLY, 0666);
//  write(fd, impl.preprocessed_code.data(), impl.preprocessed_code.size());
//  close(fd);
}

}  // namespace

// Run a command ans return the AST or the first error.
llvm::Expected<AST> CompileJob::Run(void) const {
  auto ast = std::make_shared<ASTImpl>();
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_vfs(
      llvm::vfs::createPhysicalFileSystem().release());
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_vfs(
      new llvm::vfs::OverlayFileSystem(real_vfs.get()));
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_vfs(
      new llvm::vfs::InMemoryFileSystem);
  overlay_vfs->pushOverlay(mem_vfs.get());
  overlay_vfs->setCurrentWorkingDirectory(WorkingDirectory().data());

  auto diag = std::make_unique<SaveFirstErrorDiagConsumer>(ast);
  auto ci = std::make_shared<clang::CompilerInstance>();
  llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diagnostics_engine(
      new clang::DiagnosticsEngine(new clang::DiagnosticIDs,
                                   new clang::DiagnosticOptions, diag.get(),
                                   false /* Take ownership of the consumer */));

  diagnostics_engine->Reset();
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

  ci->setDiagnostics(diagnostics_engine.get());
  ci->setASTConsumer(std::make_unique<clang::ASTConsumer>());

  auto &invocation = ci->getInvocation();
  auto &fs_options = invocation.getFileSystemOpts();
  fs_options.WorkingDir = WorkingDirectory();

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
      return llvm::createStringError(
          std::make_error_code(std::errc::invalid_argument),
          "Unable to create compiler invocation from command: %s",
          argv.Join().c_str());
    } else {
      return llvm::createStringError(
          std::make_error_code(std::errc::invalid_argument),
          "Unable to create compiler invocation from command: %s",
          diag->error.c_str());
    }
  }

  // Just in case parsing of the command-line args changed this.
  diagnostics_engine->setConstexprBacktraceLimit(0);
  diagnostics_engine->setTemplateBacktraceLimit(0);
  diagnostics_engine->setErrorLimit(1);
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

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
    return llvm::createStringError(
        std::make_error_code(std::errc::no_such_file_or_directory),
        "No input file in compilation command: %s", argv.Join().c_str());

  // There should only be one input files, as we're dealing with `-cc1`
  // commands, not frontend commands.
  } else if (1u < input_files.size()) {
    return llvm::createStringError(
        std::make_error_code(std::errc::too_many_files_open),
        "Too many input files in compilation command: %s", argv.Join().c_str());
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

  // TODO(pag): Eventually add `PPCallbacks` so that we can capture macro
  //            definitions as tokens.

  ci->createPreprocessor(clang::TU_Complete);
  auto &pp = ci->getPreprocessor();

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
    return llvm::createStringError(
        std::make_error_code(std::errc::invalid_argument),
        "Could not add overlay file for '%s'",
        main_file_name.c_str());
  }

  const auto file_entry = fm->getFile("<pasta-input>");
  if (!file_entry) {
    return llvm::createStringError(
        std::make_error_code(std::errc::invalid_argument),
        "Could not add overlay file entry for file '%s'",
        main_file_name.c_str());
  }

  auto &sm = ci->getSourceManager();
  const auto prev_main_file_id = sm.getMainFileID();
  const auto main_file_id = sm.createFileID(
      *file_entry, clang::SourceLocation(), clang::SrcMgr::C_User);

  if (!main_file_id.isValid()) {
    return llvm::createStringError(
        std::make_error_code(std::errc::invalid_argument),
        "Failed to create a valid ID for the overlay file entry for file '%s'",
        main_file_name.c_str());
  }

  if (prev_main_file_id == main_file_id) {
    return llvm::createStringError(
        std::make_error_code(std::errc::invalid_argument),
        "Source manager ID for the overlay file '%s' is the same as the original",
        main_file_name.c_str());
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
      return llvm::createStringError(
          std::make_error_code(std::errc::invalid_argument),
          "A clang diagnostic or uncompilable error was produced when trying "
          "to get an AST from the command: %s",
          argv.Join().c_str());

    } else {
      return llvm::createStringError(
          std::make_error_code(std::errc::invalid_argument),
          "A clang diagnostic or uncompilable error was produced when trying "
          "to get an AST: %s",
          diag->error.c_str());
    }
  }

  ast->real_fs = std::move(real_vfs);
  ast->overlay_fs = std::move(overlay_vfs);
  ast->mem_fs = std::move(mem_vfs);
  ast->ci = std::move(ci);
  ast->fm = std::move(fm);
  ast->tu = ast_context.getTranslationUnitDecl();

  // Visit AST
  // TODO(adrianh): This doesn't seem a very natural location for this function
  // call. I wanted to add a `Walk` method to the AST class that accepts
  // an `RecursiveASTVisitor`, i.e.,
  // template <typename T> AST::Walk(const clang::RecursiveASTVisitor<T> visitor)
  // This would allow the AST to be walked in Bootstrap's `GenerateBindings`, but
  // I couldn't get it to work
  MacroGenerator visitor;
  visitor.TraverseAST(ast->ci->getASTContext());

  return AST(std::move(ast));
}

}  // namespace pasta
