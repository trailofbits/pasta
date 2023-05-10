#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterCompiler(py::module_ &m) {
  py::enum_<TargetLanguage>(m, "TargetLanguage")
    .value("C", TargetLanguage::kC)
    .value("CXX", TargetLanguage::kCXX);

  py::enum_<CompilerName>(m, "CompilerName")
    .value("UNKNOWN", CompilerName::kUnknown)
    .value("CLANG", CompilerName::kClang)
    .value("APPLE_CLANG", CompilerName::kAppleClang)
    .value("CLANG_CL", CompilerName::kClangCL)
    .value("CL", CompilerName::kCL)
    .value("GNU", CompilerName::kGNU);

  py::class_<Compiler>(m, "Compiler")
    .def_static("create_host_compiler", &Compiler::CreateHostCompiler)
    .def_static("create", &Compiler::Create)
    .def("create_jobs_for_command", &Compiler::CreateJobsForCommand);
}
}  // namespace pasta