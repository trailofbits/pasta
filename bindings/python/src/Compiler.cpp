/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>

#include "Bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterCompiler(nb::module_ &m) {
  nb::enum_<TargetLanguage>(m, "TargetLanguage")
    .value("C", TargetLanguage::kC)
    .value("CXX", TargetLanguage::kCXX);

  nb::enum_<CompilerName>(m, "CompilerName")
    .value("UNKNOWN", CompilerName::kUnknown)
    .value("CLANG", CompilerName::kClang)
    .value("APPLE_CLANG", CompilerName::kAppleClang)
    .value("CLANG_CL", CompilerName::kClangCL)
    .value("CL", CompilerName::kCL)
    .value("GNU", CompilerName::kGNU);

  nb::enum_<IncludePathLocation>(m, "IncludePathLocation")
    .value("ABSOLUTE", IncludePathLocation::kAbsolute)
    .value("SYSROOT_RELATIVE", IncludePathLocation::kSysrootRelative);

  nb::class_<IncludePath>(m, "IncludePath")
    .def_prop_ro("path", &IncludePath::Path)
    .def_prop_ro("location", &IncludePath::Location);

  nb::class_<Compiler>(m, "Compiler")
    .def_static("create_host_compiler", &Compiler::CreateHostCompiler)
    .def_static("create", &Compiler::Create)
    .def("create_jobs_for_command", &Compiler::CreateJobsForCommand)
    .def_prop_ro("target_language", &Compiler::TargetLanguage)
    .def_prop_ro_static("host_target_triple", &Compiler::HostTargetTriple)
    .def_prop_ro("target_triple", &Compiler::TargetTriple)
    .def_prop_ro("executable_path", &Compiler::ExecutablePath)
    .def_prop_ro("resource_directory", &Compiler::ResourceDirectory)
    .def_prop_ro("system_root_directory", &Compiler::SystemRootDirectory)
    .def_prop_ro("system_root_include_directory", &Compiler::SystemRootIncludeDirectory)
    .def_prop_ro("installation_directory", &Compiler::InstallationDirectory)
    .def_prop_ro("system_include_directories", &Compiler::SystemIncludeDirectories)
    .def_prop_ro("user_include_directories", &Compiler::UserIncludeDirectories)
    .def_prop_ro("framework_directories", &Compiler::FrameworkDirectories);
}
}  // namespace pasta
