/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Job.h"

#include <pasta/Compile/Command.h>
#include <pasta/Util/FileSystem.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticIDs.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>

#include <clang/Driver/Compilation.h>
#include <clang/Driver/Driver.h>
#include <clang/Driver/Options.h>

#include <clang/Frontend/CompilerInvocation.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Frontend/FrontendOptions.h>
#include <clang/Frontend/PCHContainerOperations.h>

#include <clang/Lex/PreprocessorOptions.h>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Path.h>
#include <llvm/Support/VirtualFileSystem.h>

#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>

#include <llvm/ADT/SmallVector.h>
#include <llvm/Option/ArgList.h>
#include <llvm/Option/Option.h>

#pragma clang diagnostic pop

#include "Command.h"
#include "Compiler.h"

namespace pasta {

CompileJob::~CompileJob(void) {}

CompileJob::CompileJob(std::unique_ptr<CompileJobImpl> impl_)
    : impl(std::move(impl_)) {}

// Return an argument vector associated with this compilation job.
const ArgumentVector &CompileJob::Arguments(void) const {
  return impl->argv;
}

// Return the working directory in which this command executes.
std::string_view CompileJob::WorkingDirectory(void) const {
  return impl->working_dir;
}

// Return the path to the source file that this job compiles.
std::string_view CompileJob::SourceFile(void) const {
  return impl->source_file;
}

namespace {

static bool IsIncludeOption(unsigned id) {
  switch (id) {
    case clang::driver::options::OPT_I_:
    case clang::driver::options::OPT_idirafter:
    case clang::driver::options::OPT_iframeworkwithsysroot:
    case clang::driver::options::OPT_iframework:
    case clang::driver::options::OPT__SLASH_imsvc:
    case clang::driver::options::OPT_imultilib:
    case clang::driver::options::OPT__include_barrier:
    case clang::driver::options::OPT__include_directory_after_EQ:
    case clang::driver::options::OPT__include_directory_after:
    case clang::driver::options::OPT__include_directory_EQ:
    case clang::driver::options::OPT__include_directory:
    case clang::driver::options::OPT__include_prefix_EQ:
    case clang::driver::options::OPT__include_prefix:
    case clang::driver::options::OPT__include_with_prefix_after_EQ:
    case clang::driver::options::OPT__include_with_prefix_after:
    case clang::driver::options::OPT__include_with_prefix_before_EQ:
    case clang::driver::options::OPT__include_with_prefix_before:
    case clang::driver::options::OPT__include_with_prefix_EQ:
    case clang::driver::options::OPT__include_with_prefix:
    case clang::driver::options::OPT_internal_externc_isystem:
    case clang::driver::options::OPT_internal_isystem:
    case clang::driver::options::OPT_iprefix:
    case clang::driver::options::OPT_iquote:
    case clang::driver::options::OPT_isysroot:
    case clang::driver::options::OPT_isystem_after:
    case clang::driver::options::OPT_isystem:
    case clang::driver::options::OPT_ivfsoverlay:
    case clang::driver::options::OPT_iwithprefixbefore:
    case clang::driver::options::OPT_iwithprefix:
    case clang::driver::options::OPT_iwithsysroot:
    case clang::driver::options::OPT_I:
    case clang::driver::options::OPT__SLASH_I:
    case clang::driver::options::OPT_c_isystem:
    case clang::driver::options::OPT_cxx_isystem:
    case clang::driver::options::OPT__no_standard_includes:
    case clang::driver::options::OPT_nostdinc:
    case clang::driver::options::OPT_nostdincxx:
    case clang::driver::options::OPT_nostdlibinc:
    case clang::driver::options::OPT_nostdsysteminc:
    case clang::driver::options::OPT_objc_isystem:
    case clang::driver::options::OPT_resource_dir_EQ:
    case clang::driver::options::OPT_resource_dir:
    case clang::driver::options::OPT_nobuiltininc:
    case clang::driver::options::OPT_gcc_toolchain:
    case clang::driver::options::OPT_gcc_toolchain_legacy_spelling:
      return true;

    // NOTE(pag): These two are here because they do not affect actual
    //            inclusion paths, and therefore must be part of the final
    //            rendered command.
    case clang::driver::options::OPT__include_EQ:
    case clang::driver::options::OPT_include:
    default:
      return false;
  }
}

// Adjust the compiler command (found in `args`), creating a new one and
// returning it. The new one should have all include paths fully realized.
static ArgumentVector CreateAdjustedCompilerCommand(
    CompilerImpl &compiler, const CompileCommandImpl &command,
    const llvm::opt::InputArgList &args, const ArgumentVector &old_args) {

  llvm::opt::ArgStringList parsed_args;
  llvm::opt::ArgStringList parsed_inc_args;

  std::filesystem::path working_dir(command.working_dir);
  std::filesystem::path sysroot_to_use(compiler.sysroot_dir);
  std::filesystem::path resource_dir_to_use;

  if (!compiler.resource_dir.empty()) {
    std::filesystem::path(compiler.resource_dir).swap(resource_dir_to_use);
  }

  // Strip out all include path/file related arguments from non-include-related
  // arguments.
  for (auto arg : args) {
    const auto id = arg->getOption().getID();
    if (IsIncludeOption(id)) {
      if (id == clang::driver::options::OPT_isysroot) {
        auto path = AbsolutePath(arg->getValue(), working_dir);
        if (std::filesystem::is_directory(path)) {
          CanonicalPath(path).swap(sysroot_to_use);
          continue;
        }

      } else if (id == clang::driver::options::OPT_resource_dir_EQ ||
                 id == clang::driver::options::OPT_resource_dir) {
        auto path = AbsolutePath(arg->getValue(), working_dir);
        if (IsResourceDir(path)) {
          CanonicalPath(path).swap(resource_dir_to_use);
          continue;
        }

      } else if (id == clang::driver::options::OPT_gcc_toolchain ||
                 id == clang::driver::options::OPT_gcc_toolchain_legacy_spelling) {
        arg->render(args, parsed_inc_args);

      } else {
        arg->render(args, parsed_inc_args);
      }
    } else {
      arg->render(args, parsed_args);
    }
  }

  // Build up a new command to execute to ask the compiler to give us its
  // resolved include order based on the paths. Basically, the compiler is
  // the trusted oracle.
  std::vector<std::string> new_args;
  new_args.reserve(parsed_inc_args.size() + 16u);
  new_args.emplace_back(compiler.compiler_exe);

  // Force the language.
  new_args.emplace_back("-x");
  switch (compiler.target_lang) {
    case TargetLanguage::kC:
      new_args.emplace_back("c");
      break;
    case TargetLanguage::kCXX:
      new_args.emplace_back("c++");
      break;
  }

  if (!sysroot_to_use.empty()) {
    new_args.emplace_back("-isysroot");
    new_args.emplace_back(sysroot_to_use.string());
  }

  if (!resource_dir_to_use.empty()) {
    new_args.emplace_back("-resource-dir");
    new_args.emplace_back(resource_dir_to_use.string());
  }

  new_args.emplace_back("-nostdinc");
  new_args.emplace_back("-Xclang");
  new_args.emplace_back("-nostdinc++");
  new_args.emplace_back("-Xclang");
  new_args.emplace_back("-nobuiltininc");

  // First, add in all include arguments parsed out of the compile command.
  // Their values take precedence over any of the builtin include paths of
  // `compiler`.
  for (auto parsed_arg : parsed_inc_args) {
    if (parsed_arg[0] == '-') {
      new_args.emplace_back(parsed_arg);
      continue;
    }

    auto path = AbsolutePath(parsed_arg, working_dir);
    if (std::filesystem::exists(path)) {
      new_args.emplace_back(CanonicalPath(path).string());
    } else {
      new_args.emplace_back(parsed_arg);
    }
  }

  // Then, add in the builtin include paths of `compiler`.

  for (auto include_path : compiler.system_includes) {
    if (!include_path.empty()) {
      new_args.emplace_back("-isystem");
      new_args.emplace_back(include_path);
    }
  }

  for (auto include_path : compiler.user_includes) {
    if (!include_path.empty()) {
      new_args.emplace_back("-iquote");
      new_args.emplace_back(include_path);
    }
  }

  for (auto include_path : compiler.frameworks) {
    if (!std::filesystem::exists(include_path)) {
      new_args.emplace_back("-iframeworkwithsysroot");
    } else {
      new_args.emplace_back("-iframework");
    }
    new_args.emplace_back(include_path);
  }

  // Finally, add in all non-include related arguments from the compile command.
  for (auto parsed_arg : parsed_args) {
    new_args.emplace_back(parsed_arg);
  }

  return ArgumentVector(new_args);
}

}  // namespace

// The list of compiler jobs associated with this command.
llvm::Expected<std::vector<CompileJob>> CompileCommand::Jobs(
    const Compiler &compiler) const {

  // Parse the arguments. This isn't necessary for compilation, but it's
  // possible that our command string splitting isn't quite right, and so
  // parsing for everything serves as a good lint for the command string
  // splitter.
  std::unique_ptr<llvm::opt::OptTable> option_info_table(
      clang::driver::createDriverOptTable());

  auto missing_arg_index = 0u;
  auto missing_arg_count = 0u;
  auto parsed_args = option_info_table->ParseArgs(
      Arguments().Arguments(),
      missing_arg_index, missing_arg_count,
      clang::driver::options::DriverOption | clang::driver::options::CC1Option,
      clang::driver::options::CLOption);

  // Something didn't parse.
  if (0 < missing_arg_count) {
    return llvm::createStringError(
        std::make_error_code(std::errc::invalid_argument),
        "Unable to parse %u command-line options in command '%s'. First unparsed option is: '%s'",
        missing_arg_count, Arguments().Join().c_str(),
        Arguments().Arguments()[missing_arg_index]);
  }

  auto new_args = CreateAdjustedCompilerCommand(
      *(compiler.impl), *impl, parsed_args, Arguments());
}

}  // namespace pasta
