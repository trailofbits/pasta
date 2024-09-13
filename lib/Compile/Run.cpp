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
#include <memory>
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
#include <clang/Basic/DiagnosticLex.h>
#include <clang/Basic/DiagnosticSema.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Driver/Options.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <clang/Parse/Parser.h>
#include <clang/Sema/Sema.h>
#include <llvm/Option/ArgList.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/TargetParser/Host.h>
#pragma GCC diagnostic pop

#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Compiler.h>

#include "ParsedFileTracker.h"
#include "FileSystem.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-private-field"
#if !defined(LLVM_CLANG_HAS_PASTA_EVENTS)
# error "Missing PASTA patches to Clang for tracking macro events"
#endif
#include "PatchedMacroTracker.h"
#include "SplitTokenTracker.h"
#pragma GCC diagnostic pop

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

namespace pasta {
namespace detail {

PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Decl, Loc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TemplateParameterList, LAngleLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TemplateParameterList, RAngleLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, ASTTemplateArgumentListInfo, LAngleLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, ASTTemplateArgumentListInfo, RAngleLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TemplateParameterList, TemplateLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, DeclaratorDecl, InnerLocStart, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, FunctionDecl, EndRangeLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TypeDecl, LocStart, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, FileScopeAsmDecl, RParenLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, ExportDecl, RBraceLoc, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, LabelDecl, LocStart, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, NamespaceDecl, LocStart, clang::SourceLocation);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, NamespaceDecl, RBraceLoc, clang::SourceLocation);

PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, TLSSupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, VLASupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasLegalHalfType, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat128, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat16, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasBFloat16, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasIbm128, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasLongDouble, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFPReturn, bool);

PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, FileEntry, File,
                                  std::unique_ptr<llvm::vfs::File>);
}  // namespace detail

extern void PreprocessCode(ASTImpl &impl, clang::CompilerInstance &ci,
                           clang::Preprocessor &pp, PatchedMacroTracker &pmt);

extern void AddCustomBuiltinsToPreprocessor(ASTImpl &ast,
                                            clang::Preprocessor &pp);

// Run a command ans return the AST or the first error.
Result<AST, std::string> CompileJob::Run(void) const {
  std::stringstream err;

  std::shared_ptr<ASTImpl> ast = std::make_shared<ASTImpl>(SourceFile());
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_vfs(
      new LLVMFileSystem(impl->file_manager));
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_vfs(
      new llvm::vfs::OverlayFileSystem(real_vfs.get()));
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_vfs(
      new llvm::vfs::InMemoryFileSystem);
  overlay_vfs->pushOverlay(mem_vfs.get());
  overlay_vfs->setCurrentWorkingDirectory(
      WorkingDirectory().generic_string());

  std::unique_ptr<SaveFirstErrorDiagConsumer> diag(
      new SaveFirstErrorDiagConsumer(ast));
  llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diagnostics_engine(
      new clang::DiagnosticsEngine(new clang::DiagnosticIDs,
                                   new clang::DiagnosticOptions, diag.get(),
                                   false /* Take ownership of the consumer */));

  diagnostics_engine->Reset();
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

  ast->ci = std::make_shared<clang::CompilerInstance>();
  clang::CompilerInstance &ci = *(ast->ci);
  ci.setDiagnostics(diagnostics_engine.get());
  ci.setASTConsumer(std::make_unique<clang::ASTConsumer>());

  clang::CompilerInvocation &invocation = ci.getInvocation();
  clang::FileSystemOptions &fs_options = invocation.getFileSystemOpts();
  WorkingDirectory().generic_string().swap(fs_options.WorkingDir);

  llvm::IntrusiveRefCntPtr<clang::FileManager> fm(
      new clang::FileManager(fs_options, overlay_vfs.get()));

  ci.setFileManager(fm.get());
  ci.createSourceManager(*fm);

  const ArgumentVector &argv = Arguments();
  llvm::ArrayRef<const char *> argv_arr(argv.Argv(), argv.Size());

  clang::LangOptions &lang_opts = invocation.getLangOpts();

  // NOTE(pag): Don't default enable `HasLegalHalfType`, as some local variables
  //            might be named `half`. 

  const auto invocation_is_valid = clang::CompilerInvocation::CreateFromArgs(
      invocation, argv_arr, *diagnostics_engine);

  if (!invocation_is_valid) {
    if (diag->error.empty()) {
      err << "Unable to create compiler invocation from command: "
          << argv.Join();
      return err.str();
    }
    err << "Unable to create compiler invocation from command due to error: "
        << diag->error;
    return err.str();
  }

  if (!diag->error.empty()) {
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
  constexpr clang::diag::kind diags_to_ignore[] = {
      clang::diag::note_invalid_subexpr_in_const_expr,
      clang::diag::ext_constexpr_function_never_constant_expr,
      clang::diag::ext_init_list_variable_narrowing,
      clang::diag::warn_init_list_variable_narrowing,
      clang::diag::warn_user_literal_reserved,
      clang::diag::pp_pragma_sysheader_in_main_file,
      clang::diag::pp_pragma_once_in_main_file,
  };

  for (auto kind : diags_to_ignore) {
    diagnostics_engine->setSeverity(kind, clang::diag::Severity::Ignored, {});
  }

  // TODO(pag): Detect CL mode, or pass it through the CompileJob?
  bool enable_cl = false;
  auto missing_arg_index = 0u;
  auto missing_arg_count = 0u;
  auto parsed_args = CompileJobImpl::ParseDriverArguments(
      argv_arr, enable_cl, missing_arg_index, missing_arg_count);

  // Make sure the compiler instance is starting with the approximately
  // the right cross-compilation target info.
  clang::TargetOptions &target_opts = invocation.getTargetOpts();
  target_opts.HostTriple = llvm::sys::getDefaultTargetTriple();
  target_opts.Triple = TargetTriple();
  target_opts.ForceEnableInt128 = true;

  if (parsed_args.hasArg(clang::driver::options::OPT_target_cpu)) {
    target_opts.CPU = parsed_args.getLastArgValue(
        clang::driver::options::OPT_target_cpu);
  }

  if (parsed_args.hasArg(clang::driver::options::OPT_target_feature)) {
    target_opts.Features = parsed_args.getAllArgValues(
        clang::driver::options::OPT_target_feature);
  }

  // Create TargetInfo for the other side of CUDA and OpenMP compilation.
  clang::FrontendOptions &frontend_opts = invocation.getFrontendOpts();
  if ((lang_opts.CUDA || lang_opts.OpenMPIsTargetDevice) &&
      !frontend_opts.AuxTriple.empty()) {
    auto aux_target = std::make_shared<clang::TargetOptions>();
    aux_target->Triple = llvm::Triple::normalize(frontend_opts.AuxTriple);
    aux_target->HostTriple = target_opts.Triple;

    if (parsed_args.hasArg(clang::driver::options::OPT_aux_target_cpu)) {
      aux_target->CPU = parsed_args.getLastArgValue(
          clang::driver::options::OPT_aux_target_cpu);
    }

    if (parsed_args.hasArg(clang::driver::options::OPT_aux_target_feature)) {
      aux_target->Features = parsed_args.getAllArgValues(
          clang::driver::options::OPT_aux_target_feature);
    }

    ci.setAuxTarget(
        clang::TargetInfo::CreateTargetInfo(*diagnostics_engine, aux_target));
  }

  if (!ci.createTarget()) {
    err << "Unable to create compiler target for command: "
        << argv.Join();
    return err.str();
  }

  // Some systems/targets declare/include these types, though the current target
  // may not. Nonetheless, we want to parse them.
  clang::TargetInfo &target_info = ci.getTarget();
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, TLSSupported) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, VLASupported) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat128) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat16) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasBFloat16) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasIbm128) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasLongDouble) = true;
  target_info.*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFPReturn) = true;

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
  clang::PreprocessorOptions &pp_options = invocation.getPreprocessorOpts();
  pp_options.DetailedRecord = false;  // We do our own detailed record keeping.
  pp_options.SingleFileParseMode = false;
  pp_options.LexEditorPlaceholders = false;
  pp_options.RetainRemappedFileBuffers = true;

  // Clear ImplictPCHInclude to avoid using clang
  // pre-serialized ASTs
  pp_options.ImplicitPCHInclude.clear();

  clang::PreprocessorOutputOptions &ppo_options =
      invocation.getPreprocessorOutputOpts();
  ppo_options = {};  // Reset to defaults.

  // Disable cpp language option that enable true/false keyword. It
  // can have conflict with C identifiers declaring true/false
  // lang_opts.Bool = true;
  // lang_opts.Half = had_legal_half_type;
  lang_opts.WChar = lang_opts.CPlusPlus;
  lang_opts.Char8 = true;
  lang_opts.IEEE128 = true;
  lang_opts.EmitAllDecls = true;
  // lang_opts.Blocks = lang_opts.ObjC;
  lang_opts.POSIXThreads = true;
  lang_opts.HeinousExtensions = true;
  lang_opts.DoubleSquareBracketAttributes = true;
  lang_opts.GNUMode = true;
  lang_opts.GNUKeywords = true;
  lang_opts.GNUAsm = true;
  lang_opts.SpellChecking = false;
  lang_opts.RetainCommentsFromSystemHeaders = false;
  lang_opts.AllowEditorPlaceholders = false;
  lang_opts.CommentOpts.ParseAllComments = false;
  lang_opts.ForceEmitVTables = lang_opts.CPlusPlus;

  // Force enable CXXExceptions
  lang_opts.CXXExceptions = true;

  // This is a patch that preserve the lexical context of the
  // template instantiations in AST.
  lang_opts.LexicalTemplateInstantiation = true;

  // This patch triggers aggressive instatiation of templates.
  lang_opts.AggressiveTemplateInstantiation = true;

  // Disable access control checking, e.g. `private`, `protected`.
  lang_opts.AccessControl = false;

  // This is a patch that introduces transparent support for unknown attributes,
  // converting them into annotation attributes.
  lang_opts.UnknownAttrAnnotate = true;

  // This is a patch that makes attributed types store their attributes.
  lang_opts.AttrTypesHaveAttrs = true;

  // Don't try to produce recovery expressions or types.
  lang_opts.RecoveryAST = false;
  lang_opts.RecoveryASTType = false;

  // Affects `PPCallbacks`, and also does additional parsing of things in
  // Objective-C mode, e.g. parsing module imports.
  lang_opts.DebuggerSupport = true;

  // Enable C++-style comments, even in C code. If we don't do this, then we
  // can observe two tokens for something like `// foo` in C code, one is a
  // `slash`, the second is a `comment`.
  lang_opts.LineComment = true;

  // Don't get whitespace.
  lang_opts.TraditionalCPP = false;

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
  llvm::SmallVector<clang::FrontendInputFile, 0> &input_files =
      frontend_opts.Inputs;
  if (input_files.empty()) {
    err << "No input file in compilation command: " << argv.Join();
    return err.str();
  }

  // There should only be one input files, as we're dealing with `-cc1`
  // commands, not frontend commands.
  if (1u < input_files.size()) {
    err << "Too many input files in compilation command: " << argv.Join();
    return err.str();
  }

  clang::TargetInfo &invocation_target = ci.getTarget();
  invocation_target.adjust(*diagnostics_engine, lang_opts);
  if (auto aux_target = ci.getAuxTarget(); aux_target) {
    invocation_target.setAuxTarget(aux_target);
  }

  // Clear out any dependency file stuff. Sometimes the paths for the dependency
  // files are incorrect, and that shouldn't hold up a build.
  clang::DependencyOutputOptions &dep_opts = ci.getDependencyOutputOpts();
  dep_opts = clang::DependencyOutputOptions();

  ci.createPreprocessor(clang::TU_Complete);
  clang::Preprocessor &pp = ci.getPreprocessor();
  clang::SourceManager &sm = ci.getSourceManager();

  ast->orig_source_pp = ci.getPreprocessorPtr();

  // NOTE(pag): Add the macro tracker first so that it can observe changes to
  //            `ASTImpl::id_to_file` enacted by
  //            `ParsedFileTracker::FileChanged`.
  PatchedMacroTracker *macro_tracker_ptr =
      new PatchedMacroTracker(pp, sm, ast.get());
  {
    std::unique_ptr<clang::PPCallbacks> macro_tracker(macro_tracker_ptr);
    pp.addPPCallbacks(std::move(macro_tracker));
  }

  ParsedFileTracker *file_tracker_ptr = new ParsedFileTracker(
      sm, lang_opts, impl->file_manager, WorkingDirectory(), ast.get());
  {
    std::unique_ptr<clang::PPCallbacks> file_tracker(file_tracker_ptr);
    pp.addPPCallbacks(std::move(file_tracker));
  }

  pp.SetCommentRetentionState(false /* KeepComments */,
                              false /* KeepMacroComments */);

  AddCustomBuiltinsToPreprocessor(*ast, pp);
  pp.setPragmasEnabled(true);

  // Picks up on the pre-processor and stuff.
  ci.InitializeSourceManager(input_files[0]);
  PreprocessCode(*ast, ci, pp, *macro_tracker_ptr);

  // If we didn't end up tracking any files then something is seriously wrong.
  assert(!ast->id_to_file.empty());

  // Wipe out the old callbacks and any temporary data they stored.
  file_tracker_ptr->Clear();
  macro_tracker_ptr->Clear();
  pp.clearPPCallbacks();
  macro_tracker_ptr = nullptr;
  file_tracker_ptr = nullptr;

  // Replace the main source file with the preprocessed file.
  const std::string main_file_name = input_files[0].getFile().str();
  bool added_file = mem_vfs->addFile(
      "/pasta", std::numeric_limits<time_t>::max(),
      llvm::MemoryBuffer::getMemBuffer(ast->parsed_tokens.Data(),
                                       "/pasta", false),
      std::nullopt, std::nullopt, llvm::sys::fs::file_type::regular_file,
      llvm::sys::fs::perms::all_read);

  if (!added_file) {
    err << "Could not add overlay file for '" << main_file_name << "'";
    return err.str();
  }

  auto file_entry = fm->getFileRef("/pasta");
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
  clang::ASTContext &ast_context = ci.getASTContext();
  clang::ASTConsumer &ast_consumer = ci.getASTConsumer();
  clang::Sema &sema = ci.getSema();
  clang::Preprocessor &pp2 = ci.getPreprocessor();
  clang::LangOptions &lang_opts2 = ci.getLangOpts();
  ast->parsed_tokens_data_pp = ci.getPreprocessorPtr();

  std::unique_ptr<clang::PPCallbacks> split_tracker(
      new SplitTokenTracker(sm, ast.get()));
  pp2.addPPCallbacks(std::move(split_tracker));

  assert(lang_opts2.EmitAllDecls);
  assert(lang_opts.EmitAllDecls);

  // No longer need pre-defined macros, and these could technically conflict
  // with stuff, e.g. built-in ones if there was an `#undef`.
  lang_opts2.EnablePredefines = false;

  // Include comments in the AST.
  //
  // NOTE(pag): The way that Clang deals with comment parsing *isn't* by
  //            changing the comment retention state in the preprocessor/lexer,
  //            but instead by retroactively inspecting source locations for
  //            leading/training comments.
  lang_opts2.RetainCommentsFromSystemHeaders = true;
  lang_opts2.CommentOpts.ParseAllComments = true;

  std::unique_ptr<clang::Parser> parser(
      new clang::Parser(pp2, sema, false /* SkipFunctionBodies */));

  AddCustomBuiltinsToPreprocessor(*ast, pp2);
  pp2.setPreprocessedOutput(false);
  pp2.setPragmasEnabled(true);
  pp2.EnterMainSourceFile();
  parser->Initialize();
  clang::Sema::ModuleImportState import_state;
  clang::Parser::DeclGroupPtrTy a_decl;
  for (auto at_eof = parser->ParseFirstTopLevelDecl(a_decl, import_state);
       !at_eof; at_eof = parser->ParseTopLevelDecl(a_decl, import_state)) {

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

  sema.PerformDeferredTypeCompletions();
  sema.DefineUsedVTables();

  // Finalize any leftover instantiations.
  sema.PerformPendingInstantiations(false);

  if (diagnostics_engine->hasUncompilableErrorOccurred() ||
      diagnostics_engine->hasFatalErrorOccurred()) {
    if (diag->error.empty()) {
      err << "A clang diagnostic or uncompilable error was produced when trying"
          << " to get an AST: " << argv.Join();
      return err.str();
    }
    err << "A clang diagnostic or uncompilable error was produced when trying"
        << " to get an AST due to error: " << diag->error;
    return err.str();
  }

  if (!diag->error.empty()) {
    err << "A clang diagnostic was produced when trying"
        << " to get an AST due to error: " << diag->error;
    return err.str();
  }

  ast->real_fs = std::move(real_vfs);
  ast->overlay_fs = std::move(overlay_vfs);
  ast->mem_fs = std::move(mem_vfs);
  ast->fm = std::move(fm);
  ast->tu = ast_context.getTranslationUnitDecl();
  ast->printing_policy.reset(new clang::PrintingPolicy(lang_opts));

  // Initialize the policy to print tokens as closely as possible to what is
  // written in the original code.
  if (clang::PrintingPolicy *policy = ast->printing_policy.get()) {
    policy->ConstantArraySizeAsWritten = true;
    policy->ConstantsAsWritten = true;
    policy->PrintCanonicalTypes = false;
    policy->PrintInjectedClassNameWithArguments = false;
    policy->SuppressUnwrittenScope = true;
    policy->AnonymousTagLocations = false;
    policy->IncludeTagDefinition = true;
  }

  ast->LinkMacroTokenContexts();

  return AST(std::move(ast));
}

}  // namespace pasta
