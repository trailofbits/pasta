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
#include <llvm/Support/Host.h>
#pragma clang diagnostic pop

#include <pasta/Compile/Command.h>
#include <pasta/Util/FileSystem.h>

#include <cstring>
#include <memory>
#include <sstream>

#include "Command.h"
#include "Compiler.h"
#include "Diagnostic.h"
#include "FileSystem.h"
#include "Version.h"

namespace pasta {

CompileJob::~CompileJob(void) {}

CompileJob::CompileJob(std::shared_ptr<CompileJobImpl> impl_)
    : impl(std::move(impl_)) {}

// Return an argument vector associated with this compilation job.
const ArgumentVector &CompileJob::Arguments(void) const {
  return impl->argv;
}

// Return the working directory in which this command executes.
std::filesystem::path CompileJob::WorkingDirectory(void) const {
  return impl->working_dir;
}

// Return the compiler resource directory that this command should use.
std::filesystem::path CompileJob::ResourceDirectory(void) const {
  return impl->resource_dir;
}

// Return the compiler system root directory that this command should use.
std::filesystem::path CompileJob::SystemRootDirectory(void) const {
  return impl->sysroot_dir;
}

// Return the path to the source file that this job compiles.
File CompileJob::SourceFile(void) const {
  return impl->source_file;
}

// Return the target triple to use.
std::string_view CompileJob::TargetTriple(void) const {
  return impl->target_triple;
}

// Return the auxiliary target triple to use.
std::string_view CompileJob::AuxiliaryTargetTriple(void) const {
  return impl->aux_triple;
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
    case clang::driver::options::OPT__sysroot:
    case clang::driver::options::OPT__sysroot_EQ:
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
CreateAdjustedCompilerCommand(FileSystemView &fs, const Compiler &compiler,
                              const CompileCommand &command,
                              const llvm::opt::InputArgList &args) {

  llvm::opt::ArgStringList parsed_args;
  llvm::opt::ArgStringList parsed_inc_args;

  std::filesystem::path working_dir(command.WorkingDirectory());
  std::filesystem::path sysroot_to_use;
  std::filesystem::path resource_dir_to_use;

  if (!compiler.SystemRootDirectory().empty()) {
    std::filesystem::path(compiler.SystemRootDirectory()).swap(sysroot_to_use);
  }

  if (!compiler.ResourceDirectory().empty()) {
    std::filesystem::path(compiler.ResourceDirectory())
        .swap(resource_dir_to_use);
  }

  // Strip out all include path/file related arguments from non-include-related
  // arguments.
  for (llvm::opt::Arg *arg : args) {
    const auto id = arg->getOption().getID();
    if (IsIncludeOption(id)) {
      if (id == clang::driver::options::OPT_isysroot) {
        auto path = fs.Stat(fs.ParsePath(arg->getValue()));
        if (path.Succeeded() && path->IsDirectory()) {
          sysroot_to_use = std::move(path->real_path);
          continue;
        }

      } else if (id == clang::driver::options::OPT_resource_dir_EQ ||
                 id == clang::driver::options::OPT_resource_dir) {
        auto path = fs.Stat(fs.ParsePath(arg->getValue()));
        if (path.Succeeded() && path->IsDirectory() &&
            fs.IsResourceDir(path->real_path)) {
          resource_dir_to_use = std::move(path->real_path);
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
      arg->renderAsInput(args, parsed_args);
    }
  }

  // Build up a new command to execute to ask the compiler to give us its
  // resolved include order based on the paths. Basically, the compiler is
  // the trusted oracle.
  std::vector<std::string> new_args;
  new_args.reserve(parsed_inc_args.size() + 16u);
  new_args.emplace_back(args.getArgString(0));

  if (!sysroot_to_use.empty()) {
    new_args.emplace_back("-isysroot");
    new_args.emplace_back(sysroot_to_use.generic_string());
  }

  if (!resource_dir_to_use.empty()) {
    new_args.emplace_back("-resource-dir");
    new_args.emplace_back(resource_dir_to_use.generic_string());
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

    auto path = fs.Stat(fs.ParsePath(parsed_arg));
    if (path.Succeeded()) {
      new_args.emplace_back(std::move(path->real_path));
    } else {
      new_args.emplace_back(parsed_arg);
    }
  }

  // Then, add in the built-in include paths of `compiler`.

  compiler.ForEachSystemIncludeDirectory(
      [&](const std::filesystem::path &include_path, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          new_args.emplace_back("-isystem");
        } else {
          new_args.emplace_back("-iwithsysroot");
        }
        new_args.emplace_back(include_path.generic_string());
      });

  compiler.ForEachUserIncludeDirectory(
      [&](const std::filesystem::path &include_path, IncludePathLocation) {
        new_args.emplace_back("-I");
        new_args.emplace_back(include_path.generic_string());
      });

  compiler.ForEachFrameworkDirectory(
      [&](const std::filesystem::path &include_path, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          new_args.emplace_back("-iframework");
        } else {
          new_args.emplace_back("-iframeworkwithsysroot");
        }
        new_args.emplace_back(include_path.generic_string());
      });

  // Finally, add in all non-include related arguments from the compile command.
  for (auto parsed_arg : parsed_args) {
    new_args.emplace_back(parsed_arg);
  }

  return ArgumentVector(new_args);
}

}  // namespace

// The list of compiler jobs associated with this command.
Result<std::vector<CompileJob>, std::string>
Compiler::CreateJobsForCommand(const CompileCommand &command) const {
  std::stringstream err;

  const std::filesystem::path working_dir_path = command.WorkingDirectory();
  const std::string working_dir_str = working_dir_path.generic_string();

  FileSystemView fs(impl->file_manager.FileSystem());
  auto ec = fs.PushWorkingDirectory(working_dir_path);
  if (ec) {
    err << "Could not enter current working directory '"
        << working_dir_str << "' of compile command: " << ec.message();
    return err.str();
  }

  auto diag = std::make_unique<SaveFirstErrorDiagConsumer>();
  llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diagnostics_engine(
      new clang::DiagnosticsEngine(
          new clang::DiagnosticIDs, new clang::DiagnosticOptions, diag.get(),
          false /* DON'T take ownership of the consumer */));

  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_vfs(
      new LLVMFileSystem(impl->file_manager));
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_vfs(
      new llvm::vfs::OverlayFileSystem(real_vfs.get()));
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_vfs(
      new llvm::vfs::InMemoryFileSystem);
  overlay_vfs->pushOverlay(mem_vfs.get());
  overlay_vfs->setCurrentWorkingDirectory(working_dir_str);

  // Make the driver.
#if LLVM_VERSION_NUMBER < LLVM_VERSION(12, 0)
  clang::driver::Driver driver(command.Arguments()[0],
                               llvm::sys::getDefaultTargetTriple(),
                               *diagnostics_engine, overlay_vfs.get());
#else
  auto driver_title = "PASTA Driver";
  clang::driver::Driver driver(
      command.Arguments()[0], llvm::sys::getDefaultTargetTriple(),
      *diagnostics_engine, driver_title, overlay_vfs.get());
#endif

  auto &opts = driver.getOpts();

  auto missing_arg_index = 0u;
  auto missing_arg_count = 0u;

#if LLVM_VERSION_NUMBER < LLVM_VERSION(12, 0)
  unsigned int driver_options =
      clang::driver::options::CC1Option | clang::driver::options::DriverOption;
#else
  unsigned int driver_options =
      clang::driver::options::CC1Option | clang::driver::options::NoXarchOption;
#endif

  auto parsed_args = opts.ParseArgs(
      command.Arguments().Arguments(), missing_arg_index, missing_arg_count,
      driver_options, clang::driver::options::CLOption);

  // Something didn't parse.
  if (0 < missing_arg_count) {
    err << "Unable to parse " << missing_arg_count
        << " command-line options (first unparsed option is: '"
        << command.Arguments().Arguments()[missing_arg_index]
        << "') in command: "
        << command.Arguments().Join();
    return err.str();
  }

  const auto new_args =
      CreateAdjustedCompilerCommand(fs, *this, command, parsed_args);

  driver.setTitle("pasta");
  driver.setCheckInputsExist(false);

  // Set up a reasonable default system root directory.
  if (driver.SysRoot.empty()) {
    if (auto sysroot_arg =
            parsed_args.getLastArg(clang::driver::options::OPT__sysroot_EQ);
        sysroot_arg) {
      driver.SysRoot = fs.ParsePath(sysroot_arg->getValue()).generic_string();

    } else if (auto isysroot_arg =
                   parsed_args.getLastArg(clang::driver::options::OPT_isysroot);
               isysroot_arg) {
      driver.SysRoot = fs.ParsePath(isysroot_arg->getValue()).generic_string();

    } else {
      SystemRootDirectory().generic_string().swap(driver.SysRoot);
    }
  }

  // Set up a reasonable default resource directory.
  if (driver.ResourceDir.empty() ||
      !fs.IsResourceDir(driver.ResourceDir)) {
    ResourceDirectory().generic_string().swap(driver.ResourceDir);
  }

  // Double check the installation directory.
  if (!driver.InstalledDir.empty()) {
    if (auto idir = fs.Stat(driver.InstalledDir);
        !idir.Succeeded() || !idir->IsDirectory()) {
      driver.InstalledDir.clear();
    }
  }

  // If we don't have an installation directory, then substitute our compiler's
  // isntall directory in.
  //
  // TODO(pag): Should we do the other driver things independently?
  if (driver.InstalledDir.empty() && !InstallationDirectory().empty()) {
    InstallationDirectory().generic_string().swap(driver.InstalledDir);
    ExecutablePath().filename().generic_string().swap(driver.Name);
    ExecutablePath().parent_path().generic_string().swap(driver.Dir);
    ExecutablePath().generic_string().swap(driver.ClangExecutable);
  }

  const std::unique_ptr<clang::driver::Compilation> compilation(
      driver.BuildCompilation(new_args.Arguments()));

  if (!compilation) {
    if (diag->error.empty()) {
      err << "Unable to build compilation jobs for command: "
          << new_args.Join();
      return err.str();

    } else {
      err << "Unable to build compilation due to error: "
          << diag->error;
      return err.str();
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
        invocation, job_args, *diagnostics_engine, new_args[0]);

    if (!invocation_is_valid) {
      if (diag->error.empty()) {
        err << "Unable to build compilation jobs for cc1 command: "
            << job_args_to_string();
        return err.str();

      } else {
        err << "Unable to build compilation jobs for cc1 command due to error: "
            << diag->error;
        return err.str();
      }
    }

    const auto &frontend_opts = invocation.getFrontendOpts();
    if (frontend_opts.Inputs.empty()) {
      err << "Empty input file list for cc1 command: "
          << job_args_to_string();
      return err.str();
    }

    auto main_file_path = fs.ParsePath(frontend_opts.Inputs[0].getFile().str());
    auto main_file_stat = fs.Stat(main_file_path);
    if (!main_file_stat.Succeeded()) {
      err << "Main input file '" << main_file_path.generic_string()
          << "' does not exist or cannot be opened: "
          << main_file_stat.TakeError().message();
      return err.str();
    }

    auto main_file = impl->file_manager.OpenFile(main_file_stat.TakeValue());
    if (!main_file.Succeeded()) {
      err << "Main input file '" << main_file_path.generic_string()
          << "' does not exist or cannot be opened: "
          << main_file.TakeError().message();
      return err.str();
    }

    std::vector<std::string> new_argv;
    auto last_was_output = false;
    for (const char *arg : job_args) {

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

        if (auto maybe_info = fs.Stat(arg); maybe_info.Succeeded()) {
          new_argv.emplace_back(maybe_info->real_path.generic_string());
          continue;
        }
      }

      new_argv.emplace_back(arg);
    }

    CompileJob job(std::make_shared<CompileJobImpl>(
        new_argv, impl->file_manager, working_dir_path,
        fs.ParsePath(driver.ResourceDir),
        fs.ParsePath(driver.SysRoot),
        main_file.TakeValue(),
        target_triple, frontend_opts.AuxTriple));
    jobs.emplace_back(std::move(job));
  }

  return jobs;
}

}  // namespace pasta
