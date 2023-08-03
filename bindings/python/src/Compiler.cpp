/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>

#include "bindings.h"

#include <nanobind/stl/string_view.h>

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

  nb::class_<Compiler>(m, "Compiler")
    .def_static("create_host_compiler", &Compiler::CreateHostCompiler)
    .def_static("create", &Compiler::Create)
    .def("create_jobs_for_command", &Compiler::CreateJobsForCommand);
}
}  // namespace pasta