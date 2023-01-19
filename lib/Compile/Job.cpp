/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Job.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Driver/Compilation.h>
#include <clang/Driver/Driver.h>
#include <clang/Driver/Options.h>
#include <clang/Driver/Tool.h>
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
#pragma GCC diagnostic pop

#include <pasta/Compile/Command.h>
#include <pasta/Util/FileSystem.h>

#include <cstring>
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>

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

// Return the compiler system root include directory that this command
// should use.
std::filesystem::path CompileJob::SystemRootIncludeDirectory(void) const {
  return impl->isysroot_dir;
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

static bool OmitOption(unsigned id) {
  switch (id) {
    case clang::driver::options::OPT_cc1:
    case clang::driver::options::OPT_cc1as:
    case clang::driver::options::OPT_fdebug_compilation_dir_EQ:
    case clang::driver::options::OPT_fcoverage_compilation_dir_EQ:
    case clang::driver::options::OPT_fcoverage_mapping:
    case clang::driver::options::OPT_fcoverage_prefix_map_EQ:
    case clang::driver::options::OPT_fcrash_diagnostics_dir:
    case clang::driver::options::OPT_frandom_seed_EQ:
    case clang::driver::options::OPT_frandomize_layout_seed_EQ:
    case clang::driver::options::OPT_frandomize_layout_seed_file_EQ:
    case clang::driver::options::OPT_frewrite_map_file_EQ:
    case clang::driver::options::OPT_fprofile_remapping_file_EQ:
    case clang::driver::options::OPT_fmodules_embed_file_EQ:
    case clang::driver::options::OPT_coverage_data_file_EQ:
    case clang::driver::options::OPT_coverage_data_file:
    case clang::driver::options::OPT_coverage_notes_file_EQ:
    case clang::driver::options::OPT_coverage_notes_file:
    case clang::driver::options::OPT_foptimization_record_file_EQ:
      return true;
    default:
      return false;
  }
}

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
    case clang::driver::options::OPT_gcc_toolchain: return true;

    // NOTE(pag): These two are here because they do not affect actual
    //            inclusion paths, and therefore must be part of the final
    //            rendered command.
    case clang::driver::options::OPT__include_EQ:
    case clang::driver::options::OPT_include:
    default: return false;
  }
}

// Render an option with an optional prefix, e.g. `-Xclang`.
static void RenderPrefixed(const llvm::opt::Arg *arg,
                           std::vector<std::string> &output,
                           const char *prefix) {
  const auto &opt = arg->getOption();
  auto render_style = opt.getRenderStyle();
  if (opt.hasNoOptAsInput()) {
    render_style = llvm::opt::Option::RenderValuesStyle;
  }

  switch (render_style) {
    case llvm::opt::Option::RenderCommaJoinedStyle: {
      std::stringstream ss;
      ss << arg->getSpelling().str();
      auto sep = "";
      for (auto val : arg->getValues()) {
        ss << sep << val;
        sep = ",";
      }

      if (prefix) {
        output.emplace_back(prefix);
      }

      output.emplace_back(ss.str());
      break;
    }
    case llvm::opt::Option::RenderJoinedStyle: {
      std::stringstream ss;
      ss << arg->getSpelling().str();
      const auto max_i = arg->getNumValues();
      if (max_i) {
        ss << arg->getValue(0);
      }

      if (prefix) {
        output.emplace_back(prefix);
      }

      output.emplace_back(ss.str());

      for (auto i = 1u; i < max_i; ++i) {
        if (prefix) {
          output.emplace_back(prefix);
        }
        output.emplace_back(arg->getValue(i));
      }
      break;
    }
    case llvm::opt::Option::RenderSeparateStyle: {
      if (prefix) {
        output.emplace_back(prefix);
      }

      output.emplace_back(arg->getSpelling().str());

      for (auto val : arg->getValues()) {
        if (prefix) {
          output.emplace_back(prefix);
        }
        output.emplace_back(val);
      }
      break;
    }
    case llvm::opt::Option::RenderValuesStyle:
      for (auto val : arg->getValues()) {
        if (prefix) {
          output.emplace_back(prefix);
        }
        output.emplace_back(val);
      }
      break;
  }
}

// Adjust the compiler command (found in `args`), creating a new one and
// returning it. The new one should have all include paths fully realized. The
// new compiler command is a "driver compiler command." Thus, if a `-cc1` or
// `-cc1as` command is given to us as input, this procedure lifts it back to
// a driver command, injecting in things like `-Xclang` or `-Xassembler` in
// the various needed places. This procedure also tries to make the implicit
// header search paths explicit.
//
// NOTE(pag): `args` should not contain a leading executable path.
static ArgumentVector
CreateAdjustedCompilerCommand(FileSystemView &fs, const Compiler &compiler,
                              const CompileCommand &command,
                              const llvm::opt::InputArgList &args,
                              const clang::driver::Driver &driver,
                              bool enable_cl) {

  std::vector<std::string> parsed_args;
  std::vector<std::string> parsed_inc_args;

  std::string target_triple = driver.getTargetTriple();
  std::filesystem::path working_dir = command.WorkingDirectory();
  std::filesystem::path sysroot_to_use = driver.SysRoot;
  std::filesystem::path isysroot_to_use = compiler.SystemRootIncludeDirectory();
  std::filesystem::path resource_dir_to_use = driver.ResourceDir;
  bool include_default_search_paths = true;

  std::unordered_map<std::string, std::vector<std::filesystem::path>>
      inputs_to_use;
  unsigned output_id = 0;
  std::filesystem::path output_to_use;

  std::string curr_lang;

//  bool is_cc1 = !!args.getLastArg(clang::driver::options::OPT_cc1);
  bool is_cc1as = !!args.getLastArg(clang::driver::options::OPT_cc1as);

  // Strip out all include path/file related arguments from non-include-related
  // arguments.
  for (llvm::opt::Arg *arg : args) {

    const auto &opt = arg->getOption();
    const char *prefix = nullptr;

    // A linker input argument.
    if (opt.hasFlag(clang::driver::options::LinkerInput)) {
      prefix = "-Xlinker";

    } else if (opt.hasFlag(clang::driver::options::NoDriverOption)) {
      auto is_cc1_opt = opt.hasFlag(clang::driver::options::CC1Option);
      auto is_cc1as_opt = opt.hasFlag(clang::driver::options::CC1AsOption);

      // Applies to either `-cc1` or `-cc1as`; choose one.
      if (is_cc1_opt && is_cc1as_opt) {
        if (is_cc1as) {
          prefix = "-Xassembler";
        } else {
          prefix = "-Xclang";
        }

      // A `-cc1` input argument.
      } else if (is_cc1_opt) {
        prefix = "-Xclang";

      // An assembler `-cc1as` linker argument.
      } else if (is_cc1as_opt) {
        prefix = "-Xassembler";
      }
    }

    const auto id = arg->getOption().getID();
    if (IsIncludeOption(id) && arg->getNumValues()) {
      if (id == clang::driver::options::OPT__sysroot ||
          id == clang::driver::options::OPT__sysroot_EQ) {
        auto path = fs.Stat(fs.ParsePath(arg->getValue()));
        if (path.Succeeded() && path->IsDirectory()) {
          sysroot_to_use = std::move(path->real_path);
          continue;
        }

      } else if (id == clang::driver::options::OPT_isysroot) {
        auto path = fs.Stat(fs.ParsePath(arg->getValue()));
        if (path.Succeeded() && path->IsDirectory()) {
          isysroot_to_use = std::move(path->real_path);
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

      } else if (id == clang::driver::options::OPT_gcc_toolchain) {
        RenderPrefixed(arg, parsed_inc_args, prefix);

      } else {
        RenderPrefixed(arg, parsed_inc_args, prefix);
      }

    // Switch the current language.
    } else if (id == clang::driver::options::OPT_x) {
      curr_lang = arg->getValue();

    // These should have been stripped out prior to calling.
    } else if (id == clang::driver::options::OPT_Xclang ||
               id == clang::driver::options::OPT_Xlinker ||
               id == clang::driver::options::OPT_Xassembler) {
      assert(false);
      RenderPrefixed(arg, parsed_args, prefix);

    // If there is separator writing output to a file, add it as
    // an output file with the separator else it will be treated
    // as an input file.
    } else if (id == clang::driver::options::OPT_o ||
               id == clang::driver::options::OPT__SLASH_o ||
               id == clang::driver::options::OPT__output ||
               id == clang::driver::options::OPT__output_EQ) {

      output_id = id;
      output_to_use = fs.ParsePath(arg->getValue());

    // Capture the main input file.
    } else if (id == clang::driver::options::OPT_INPUT) {
      if (auto path = fs.Stat(fs.ParsePath(arg->getValue()));
          path.Succeeded()) {
        inputs_to_use[curr_lang].emplace_back(path.TakeValue().real_path);

      } else {
        RenderPrefixed(arg, parsed_args, prefix);
      }

    // If we're parsing a `-cc1` command then that changes the interpretation
    // and rendering of some options.
    } else if (OmitOption(id)) {
      // Skip

    // Rename these to `-target`.
    } else if (id == clang::driver::options::OPT_triple ||
               id == clang::driver::options::OPT_triple_EQ ||
               id == clang::driver::options::OPT_target) {
      target_triple = arg->getValue();

    // Ignore these, we'll manually re-introduce them.
    } else if (id == clang::driver::options::OPT_nostdinc ||
               id == clang::driver::options::OPT_nostdincxx ||
               id == clang::driver::options::OPT_nobuiltininc ||
               id == clang::driver::options::OPT_nostdsysteminc) {
      include_default_search_paths = false;

    } else {
      RenderPrefixed(arg, parsed_args, prefix);
    }
  }

  // Build up a new command to execute to ask the compiler to give us its
  // resolved include order based on the paths. Basically, the compiler is
  // the trusted oracle.
  std::vector<std::string> new_args;
  new_args.reserve(parsed_inc_args.size() + parsed_args.size() + 16u);
  new_args.emplace_back(driver.ClangExecutable);

  if (!sysroot_to_use.empty()) {
    new_args.emplace_back("--sysroot=" + sysroot_to_use.generic_string());
  }

  if (!isysroot_to_use.empty()) {
    new_args.emplace_back("-isysroot");
    new_args.emplace_back(isysroot_to_use.generic_string());
  }

  if (!resource_dir_to_use.empty()) {
    new_args.emplace_back("-resource-dir");
    new_args.emplace_back(resource_dir_to_use.generic_string());
  }

  // `Driver::BuildCompilation` is based on front-end arguments.
  if (!target_triple.empty()) {
    new_args.emplace_back("--target=" + target_triple);
  }

  if (!is_cc1as) {
    new_args.emplace_back("-nostdinc");  // CoreOption.

    new_args.emplace_back("-Xclang");
    new_args.emplace_back("-nostdinc++");  // CC1Option.

    new_args.emplace_back("-Xclang");
    new_args.emplace_back("-nobuiltininc");  // CC1Option.

    new_args.emplace_back("-Xclang");
    new_args.emplace_back("-nostdsysteminc");  // CC1Option.
  }

  // First, add in all include arguments parsed out of the compile command.
  // Their values take precedence over any of the builtin include paths of
  // `compiler`.
  for (auto &parsed_arg : parsed_inc_args) {
    if (parsed_arg[0] == '-') {
      new_args.emplace_back(std::move(parsed_arg));
      continue;
    }

    auto path = fs.Stat(fs.ParsePath(parsed_arg));
    if (path.Succeeded()) {
      new_args.emplace_back(path.TakeValue().real_path);
    } else {
      new_args.emplace_back(std::move(parsed_arg));
    }
  }

  // Then, add in the built-in include paths of `compiler`.
  if (include_default_search_paths) {
    for (IncludePath ip : compiler.SystemIncludeDirectories()) {
      if (ip.Location() == IncludePathLocation::kAbsolute) {
        new_args.emplace_back("-isystem");
      } else {
        new_args.emplace_back("-iwithsysroot");
      }
      new_args.emplace_back(ip.Path().generic_string());
    }

    for (IncludePath ip : compiler.UserIncludeDirectories()) {
      if (ip.Location() == IncludePathLocation::kAbsolute) {
        new_args.emplace_back("-I");
        new_args.emplace_back(ip.Path().generic_string());
      }
    }

    for (IncludePath ip : compiler.FrameworkDirectories()) {
      if (ip.Location() == IncludePathLocation::kAbsolute) {
        new_args.emplace_back("-iframework");
      } else {
        new_args.emplace_back("-iframeworkwithsysroot");
      }
      new_args.emplace_back(ip.Path().generic_string());
    }
  }

  // Add in all non-include related arguments from the compile command.
  for (auto &parsed_arg : parsed_args) {
    new_args.emplace_back(std::move(parsed_arg));
  }

  // Render the output argument.
  if (!output_to_use.empty()) {
    switch (output_id) {
      default:
        assert(false);
        [[clang::fallthrough]];
      case clang::driver::options::OPT_o:
        new_args.emplace_back("-o");
        break;
      case clang::driver::options::OPT__SLASH_o:
        new_args.emplace_back("/o");
        break;
      case clang::driver::options::OPT__output:
      case clang::driver::options::OPT__output_EQ:
        new_args.emplace_back("--output");
        break;
    }
    new_args.emplace_back("/dev/null");
  }

  // Finally, render the input arguments as a positional arguments.
  if (inputs_to_use.empty()) {
    new_args.emplace_back("-");
  } else {
    for (const auto &[lang, inputs] : inputs_to_use) {
      if (!lang.empty()) {
        new_args.emplace_back("-Xclang");
        new_args.emplace_back("-x");
        new_args.emplace_back("-Xclang");
        new_args.push_back(lang);
      }
      for (const auto &input : inputs) {
        new_args.emplace_back(input.generic_string());
      }
    }
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

  // Find the compiler executable path.
  auto exe_path = ExecutablePath();
  std::vector<const char *> all_args;
  if (command.Arguments().Size()) {
    auto first_arg = command.Arguments().Argv()[0];

    // Look for the common mistake of omitting the compiler path.
    if (first_arg && first_arg[0] == '-') {
      all_args.push_back(exe_path.c_str());

    } else if (first_arg) {
      exe_path = fs.ParsePath(command.Arguments()[0],
                              InstallationDirectory());
      if (!fs.Stat(exe_path).Succeeded()) {
        exe_path = ExecutablePath();
      }
    }
  }

  // Make the driver.
#if LLVM_VERSION_NUMBER < LLVM_VERSION(12, 0)
  clang::driver::Driver driver(exe_path.generic_string(),
                               TargetTriple(),
                               *diagnostics_engine, overlay_vfs.get());
#else
  auto driver_title = "PASTA Driver";
  clang::driver::Driver driver(
      exe_path.generic_string(), TargetTriple(),
      *diagnostics_engine, driver_title, overlay_vfs.get());
#endif

  auto &opts = driver.getOpts();

  auto missing_arg_index = 0u;
  auto missing_arg_count = 0u;

  bool enable_cl = driver.IsCLMode();

  unsigned int driver_options =
      clang::driver::options::CC1Option |
      clang::driver::options::CC1AsOption |
      clang::driver::options::CoreOption |
      clang::driver::options::NoDriverOption |
      clang::driver::options::NoXarchOption; // Used to be `DriverOption`.
  unsigned int excluded_driver_options = 0;

  if (enable_cl) {
    driver_options |= clang::driver::options::CLOption;
  } else {
    excluded_driver_options |= clang::driver::options::CLOption;
  }

  // Strip out `-Xclang`, etc. because our `CreateAdjustedCompilerCommand`
  // function will do a proper job at re-introducing them.
  for (auto arg : command.Arguments().Arguments()) {
    if (strcmp("-Xclang", arg) &&
        strcmp("-Xlinker", arg) &&
        strcmp("-Xassembler", arg)) {
      all_args.push_back(arg);
    }
  }

  llvm::ArrayRef<const char *> command_args(all_args);
  auto parsed_args = opts.ParseArgs(
      command_args.slice(1u), missing_arg_index, missing_arg_count,
      driver_options, excluded_driver_options);

  // Something didn't parse.
  if (0 < missing_arg_count) {
    err << "Unable to parse " << missing_arg_count
        << " command-line options (first unparsed option is: '"
        << command.Arguments().Arguments()[missing_arg_index]
        << "') in command: "
        << command.Arguments().Join();
    return err.str();
  }

  driver.setTitle("pasta");
  driver.setCheckInputsExist(true);

  if (driver.Dir.empty() || driver.ClangExecutable.empty()) {
    if (!exe_path.empty()) {
      if (driver.Name.empty()) {
        driver.Name = exe_path.filename().generic_string();
      }
      driver.Dir = exe_path.parent_path().generic_string();
      driver.ClangExecutable = exe_path.generic_string();
    }
  }

  // If we don't have an installation directory, then substitute our compiler's
  // install directory in.
  //
  // TODO(pag): Should we do the other driver things independently?
  if (driver.InstalledDir.empty()) {
    driver.InstalledDir = InstallationDirectory().generic_string();
  }

  // Set up a reasonable default system root directory and resource dir.
  driver.SysRoot = SystemRootDirectory().generic_string();
  driver.ResourceDir = ResourceDirectory().generic_string();

  // NOTE(pag): This will read `driver.SysRoot`, `driver.ResourceDir`, and
  //            `driver.ClangExecutable`.
  const auto new_args = CreateAdjustedCompilerCommand(
      fs, *this, command, parsed_args, driver, enable_cl);

  // NOTE(pag): `BuildCompilation` will update the driver `SysRoot` and
  //            `ResourceDir`. The `new_args` should have rendered in things
  //            like the system root directory, the resource directory, etc.
  //
  // NOTE(pag): `BuildCompilation` always does `slice(1)` internally, expecting
  //            `argv[0]` to be the driver.
  const std::unique_ptr<clang::driver::Compilation> compilation(
      driver.BuildCompilation(new_args.Arguments()));

//  std::cerr << "New args: " << new_args.Join() << '\n';

  if (!compilation) {
    if (diag->error.empty()) {
      err << "Unable to build compilation for frontend command: "
          << new_args.Join();
      return err.str();

    } else {
      err << "Unable to build compilation due to error: "
          << diag->error;
      return err.str();
    }
  } else if (!diag->error.empty()) {
    err << "Built compilation for frontend command but got diagnostic: "
        << diag->error;
    return err.str();
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

    }
  }

  auto &cargs = compilation->getArgs();
  std::filesystem::path job_isysroot = SystemRootIncludeDirectory();
  if (auto isysroot_opt = cargs.getLastArg(clang::driver::options::OPT_isysroot)) {
    job_isysroot = fs.ParsePath(isysroot_opt->getValue());
  }

  std::vector<CompileJob> jobs;

  const auto target_triple =
      compilation->getDefaultToolChain().getTriple().str();

  std::string last_job_args_str;

  for (llvm::opt::ArgStringList job_args : cc1_jobs) {
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

//    std::cerr << "%%% InstalledDir = " << driver.InstalledDir << '\n';
//    std::cerr << "%%% ClangExecutable = " << driver.ClangExecutable << '\n';
//    std::cerr << "%%% ResourceDir = " << driver.ResourceDir << '\n';
//    std::cerr << "%%% SysRoot = " << driver.SysRoot << '\n';
//    std::cerr << "%%% Dir = " << driver.Dir << '\n';
//    std::cerr << "%%% TargetTriple = " << driver.getTargetTriple() << '\n';
//    std::cerr << "%%% " << job_args_to_string() << '\n';

    // NOTE(pag): `CreateFromArgs` below requires that we not pass in a
    //            `-cc1` command.
    llvm::ArrayRef<const char *> new_job_args(job_args);
    if (!strcmp(new_job_args.front(), "-cc1")) {
      new_job_args = new_job_args.slice(1);
    }

    clang::CompilerInvocation invocation;
    invocation.getFileSystemOpts().WorkingDir = driver.Dir;
    auto invocation_is_valid = clang::CompilerInvocation::CreateFromArgs(
        invocation, job_args, *diagnostics_engine,
        driver.ClangExecutable.c_str());

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
    } else if (!diag->error.empty()) {
      err << "Built compiler invocation for cc1 command but got diagnostic: "
          << diag->error;
      return err.str();
    }

    const auto &frontend_opts = invocation.getFrontendOpts();
    if (frontend_opts.Inputs.empty()) {
      err << "Empty input file list for cc1 command: "
          << job_args_to_string();
      return err.str();
    }

    auto main_file_str = frontend_opts.Inputs[0].getFile().str();
    auto main_file_path = fs.ParsePath(main_file_str);
    auto main_file_stat = fs.Stat(main_file_path);
    if (!main_file_stat.Succeeded()) {
      err << "Main input file '" << main_file_path.generic_string()
          << "' (found as '" << main_file_str
          << "' in working directory '" << working_dir_str
          << "') does not exist or cannot be opened: "
          << main_file_stat.TakeError().message();
      return err.str();
    }

    auto main_file = impl->file_manager.OpenFile(main_file_stat.TakeValue());
    if (!main_file.Succeeded()) {
      err << "Main input file '" << main_file_path.generic_string()
          << "' (found as '" << main_file_str
          << "' in working directory '" << working_dir_str
          << "') does not exist or cannot be opened: "
          << main_file.TakeError().message();
      return err.str();
    }

    std::vector<std::string> new_argv;
    for (const char *arg : job_args) {

      // Try to fixup any remaining paths.
      llvm::StringRef a(arg);

      // Try to look for things that look file file names, then see if they are
      // file names, and if so, make them absolute paths.
      if (a.contains("./") || a.endswith_insensitive(".o") ||
          a.endswith_insensitive(".cc") || a.endswith_insensitive(".hh") ||
          a.endswith_insensitive(".cpp") || a.endswith_insensitive(".hpp") ||
          a.endswith_insensitive(".c++") || a.endswith_insensitive(".h++") ||
          a.endswith_insensitive(".cxx") || a.endswith_insensitive(".hxx") ||
          a.endswith_insensitive(".c") || a.endswith_insensitive(".h") ||
          a.endswith_insensitive(".gcno") || a.endswith_insensitive(".pch") ||
          a.endswith_insensitive(".s") || a.endswith_insensitive(".asm") ||
          a.endswith_insensitive(".mm") || a.endswith_insensitive(".d") ||
          a.endswith_insensitive(".sdk")) {

        if (auto maybe_info = fs.Stat(arg); maybe_info.Succeeded()) {
          new_argv.emplace_back(
              maybe_info.TakeValue().real_path.generic_string());
          continue;
        }
      }

      new_argv.emplace_back(arg);
    }

    // Check for duplicates after canonicalization.
    std::stringstream ss;
    auto sep = "";
    for (const auto &job_arg : new_argv) {
      ss << sep << job_arg;
      sep = " ";
    }

    auto job_args_str = ss.str();

//    std::cerr << "JOB: " << job_args_str << "\n\n";

    if (last_job_args_str == job_args_str) {
      continue;  // Duplicate.
    } else {
      last_job_args_str = std::move(job_args_str);
    }

    CompileJob job(std::make_shared<CompileJobImpl>(
        new_argv, impl->file_manager, working_dir_path,
        fs.ParsePath(driver.ResourceDir),
        fs.ParsePath(driver.SysRoot),
        job_isysroot,
        main_file.TakeValue(),
        target_triple, frontend_opts.AuxTriple));
    jobs.emplace_back(std::move(job));
  }

  return jobs;
}

}  // namespace pasta
