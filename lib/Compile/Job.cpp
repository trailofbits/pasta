/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Job.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
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
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/Option/ArgList.h>
#include <llvm/Option/Option.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Path.h>
#include <llvm/Support/VirtualFileSystem.h>

#pragma clang diagnostic pop

#include <pasta/Compile/Command.h>
#include <pasta/Util/FileSystem.h>

#include <cstring>
#include <memory>
#include <sstream>

#include "Command.h"
#include "Compiler.h"
#include "Diagnostic.h"

namespace pasta {

CompileJob::~CompileJob(void) {
  if (impl) {
    delete impl;
  }
}

CompileJob::CompileJob(CompileJob &&that) noexcept : impl(that.impl) {
  that.impl = nullptr;
}

CompileJob &CompileJob::operator=(CompileJob &&that) noexcept {
  std::swap(impl, that.impl);
  return *this;
}

CompileJob::CompileJob(CompileJobImpl *impl_) : impl(impl_) {}

// Return an argument vector associated with this compilation job.
const ArgumentVector &CompileJob::Arguments(void) const {
  return impl->argv;
}

// Return the working directory in which this command executes.
std::string_view CompileJob::WorkingDirectory(void) const {
  return impl->working_dir;
}

// Return the compiler resource directory that this command should use.
std::string_view CompileJob::ResourceDirectory(void) const {
  return impl->resource_dir;
}

// Return the compiler system root directory that this command should use.
std::string_view CompileJob::SystemRootDirectory(void) const {
  return impl->sysroot_dir;
}

// Return the target triple to use.
std::string_view CompileJob::TargetTriple(void) const {
  return impl->target_triple;
}

// Return the auxiliary target triple to use.
std::string_view CompileJob::AuxiliaryTargetTriple(void) const {
  return impl->aux_triple;
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
    case clang::driver::options::OPT_gcc_toolchain_legacy_spelling: return true;

    // NOTE(pag): These two are here because they do not affect actual
    //            inclusion paths, and therefore must be part of the final
    //            rendered command.
    case clang::driver::options::OPT__include_EQ:
    case clang::driver::options::OPT_include:
    default: return false;
  }
}

// Adjust the compiler command (found in `args`), creating a new one and
// returning it. The new one should have all include paths fully realized.
static ArgumentVector
CreateAdjustedCompilerCommand(const Compiler &compiler,
                              const CompileCommand &command,
                              const llvm::opt::InputArgList &args) {

  llvm::opt::ArgStringList parsed_args;
  llvm::opt::ArgStringList parsed_inc_args;

  std::filesystem::path working_dir(command.WorkingDirectory());
  std::filesystem::path sysroot_to_use(compiler.SystemRootDirectory());
  std::filesystem::path resource_dir_to_use;

  if (!compiler.ResourceDirectory().empty()) {
    std::filesystem::path(compiler.ResourceDirectory())
        .swap(resource_dir_to_use);
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
                 id == clang::driver::options::
                           OPT_gcc_toolchain_legacy_spelling) {
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
  new_args.emplace_back(compiler.ExecutablePath());

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

  compiler.ForEachSystemIncludeDirectory([&](std::string_view include_path) {
    new_args.emplace_back("-isystem");
    new_args.emplace_back(include_path);
  });

  compiler.ForEachUserIncludeDirectory([&](std::string_view include_path) {
    new_args.emplace_back("-iquote");
    new_args.emplace_back(include_path);
  });

  compiler.ForEachFrameworkDirectory([&](std::string_view include_path) {
    if (!std::filesystem::exists(include_path)) {
      new_args.emplace_back("-iframeworkwithsysroot");
    } else {
      new_args.emplace_back("-iframework");
    }
    new_args.emplace_back(include_path);
  });

  // Finally, add in all non-include related arguments from the compile command.
  for (auto parsed_arg : parsed_args) {
    new_args.emplace_back(parsed_arg);
  }

  return ArgumentVector(new_args);
}

}  // namespace

// The list of compiler jobs associated with this command.
llvm::Expected<std::vector<CompileJob>>
Compiler::CreateJobsForCommand(const CompileCommand &command) const {

  // Parse the arguments. This isn't necessary for compilation, but it's
  // possible that our command string splitting isn't quite right, and so
  // parsing for everything serves as a good lint for the command string
  // splitter.
  std::unique_ptr<llvm::opt::OptTable> option_info_table(
      clang::driver::createDriverOptTable());

  auto missing_arg_index = 0u;
  auto missing_arg_count = 0u;
  auto parsed_args = option_info_table->ParseArgs(
      command.Arguments().Arguments(), missing_arg_index, missing_arg_count,
      clang::driver::options::DriverOption | clang::driver::options::CC1Option,
      clang::driver::options::CLOption);

  // Something didn't parse.
  if (0 < missing_arg_count) {
    return llvm::createStringError(
        std::make_error_code(std::errc::invalid_argument),
        "Unable to parse %u command-line options (first unparsed option is: "
        "'%s') in command: %s",
        missing_arg_count, command.Arguments().Arguments()[missing_arg_index],
        command.Arguments().Join().c_str());
  }

  const auto new_args =
      CreateAdjustedCompilerCommand(*this, command, parsed_args);

  auto diag = std::make_unique<SaveFirstErrorDiagConsumer>();
  llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diagnostics_engine(
      new clang::DiagnosticsEngine(
          new clang::DiagnosticIDs, new clang::DiagnosticOptions, diag.get(),
          false /* DON'T take ownership of the consumer */));

  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_vfs(
      llvm::vfs::createPhysicalFileSystem().release());
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_vfs(
      new llvm::vfs::OverlayFileSystem(real_vfs.get()));
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_vfs(
      new llvm::vfs::InMemoryFileSystem);
  overlay_vfs->pushOverlay(mem_vfs.get());
  overlay_vfs->setCurrentWorkingDirectory(command.WorkingDirectory().data());

  // Make the driver.
  clang::driver::Driver driver(new_args[0], llvm::sys::getDefaultTargetTriple(),
                               *diagnostics_engine, overlay_vfs.get());

  driver.setTitle("pasta");
  driver.setCheckInputsExist(false);

  std::filesystem::path compiler_exe_path(ExecutablePath());

  driver.Name = compiler_exe_path.filename().string();
  driver.Dir = compiler_exe_path.parent_path().string();
  driver.ResourceDir = ResourceDirectory();
  driver.SysRoot = SystemRootDirectory();
  driver.InstalledDir = InstallationDirectory();
  driver.ClangExecutable = ExecutablePath();

  const std::unique_ptr<clang::driver::Compilation> compilation(
      driver.BuildCompilation(new_args.Arguments()));

  if (!compilation) {
    if (diag->error.empty()) {
      return llvm::createStringError(
          std::make_error_code(std::errc::no_child_process),
          "Unable to build compilation jobs for command: %s",
          new_args.Join().c_str());
    } else {
      return llvm::createStringError(
          std::make_error_code(std::errc::no_child_process),
          diag->error.c_str());
    }
  }

  std::vector<llvm::opt::ArgStringList> cc1_jobs;

  // Collect the argument lists for the sub-jobs of interest.
  for (auto &job : compilation->getJobs()) {

    auto &job_args = job.getArguments();
    if (!job_args.size()) {
      continue;

    // We've got the arguments to pass down to a compiler invocation.
    } else if (!strcmp(job_args[0], "-cc1")) {
      cc1_jobs.push_back(job_args);

    // Probably a linking job.
    } else {
      std::stringstream ss;
      auto sep = "";
      for (const auto &job_arg : job_args) {
        ss << sep << job_arg;
        sep = " ";
      }
    }
  }

  std::vector<CompileJob> jobs;

  const std::filesystem::path working_dir(command.WorkingDirectory());
  const auto target_triple =
      compilation->getDefaultToolChain().getTriple().str();

  for (auto job_args : cc1_jobs) {
    diagnostics_engine->Reset();
    diagnostics_engine->setErrorLimit(1);
    diagnostics_engine->setIgnoreAllWarnings(true);
    diagnostics_engine->setWarningsAsErrors(false);

    auto job_args_to_string = [&job_args](void) {
      std::stringstream ss;
      auto sep = "";
      for (auto arg : job_args) {
        ss << sep << arg;
        sep = " ";
      }
      return ss.str();
    };

    clang::CompilerInvocation invocation;
    invocation.getFileSystemOpts().WorkingDir = driver.Dir;
    auto invocation_is_valid = clang::CompilerInvocation::CreateFromArgs(
        invocation, job_args.data(), job_args.data() + job_args.size(),
        *diagnostics_engine);

    if (!invocation_is_valid) {
      if (diag->error.empty()) {
        return llvm::createStringError(
            std::make_error_code(std::errc::no_child_process),
            "Unable to build compilation jobs for cc1 command: %s",
            job_args_to_string().c_str());

      } else {
        return llvm::createStringError(
            std::make_error_code(std::errc::no_child_process),
            "Unable to build compilation jobs for cc1 command: %s",
            diag->error.c_str());
      }
    }

    const auto &frontend_opts = invocation.getFrontendOpts();
    if (frontend_opts.Inputs.empty()) {
      return llvm::createStringError(
          std::make_error_code(std::errc::no_such_file_or_directory),
          "Empty input file list for cc1 command: %s",
          job_args_to_string().c_str());
    }

    std::vector<std::string> new_argv;
    auto last_was_output = false;
    for (auto arg : job_args) {

      // Try to fixup any remaining paths.
      llvm::StringRef a(arg);
      if (a == "-o") {
        last_was_output = true;

      // Output files will have random-ish names, which is confusing to
      // downstream tools.
      } else if (last_was_output) {
        new_argv.emplace_back("/dev/null");
        last_was_output = false;
        continue;

      } else {
        last_was_output = false;
      }

      // Try to look for things that look file file names, then see if they are
      // file names, and if so, make them absolute paths.
      if (a.contains("../") || a.endswith(".o") || a.endswith(".cc") ||
          a.endswith(".cpp") || a.endswith(".cxx") || a.endswith(".h") ||
          a.endswith(".hxx") || a.endswith(".hh") || a.endswith(".c") ||
          a.endswith(".gcno") || a.endswith(".pch") || a.endswith(".s") ||
          a.endswith(".S") || a.endswith(".asm") || a.endswith(".mm") ||
          a.endswith(".d") || a.endswith(".sdk")) {
        auto maybe_path = AbsolutePath(arg, working_dir);
        if (std::filesystem::exists(maybe_path)) {
          new_argv.emplace_back(CanonicalPath(maybe_path).string());
          continue;
        }
      }

      new_argv.emplace_back(arg);
    }

    CompileJob job(new CompileJobImpl(new_argv, driver.Dir, driver.ResourceDir,
                                      compilation->getSysRoot().str(),
                                      frontend_opts.Inputs[0].getFile().str(),
                                      target_triple, frontend_opts.AuxTriple));
    jobs.emplace_back(std::move(job));
  }

  return jobs;
}

}  // namespace pasta
