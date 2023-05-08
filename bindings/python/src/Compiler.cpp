#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterCompiler(py::module_ &m) {
  py::enum_<TargetLanguage>(m, "TargetLanguage")
    .value("c", TargetLanguage::kC)
    .value("cxx", TargetLanguage::kCXX);

  py::class_<Compiler>(m, "Compiler")
    .def_static("create_host_compiler", &Compiler::CreateHostCompiler)
    .def("create_jobs_for_command", &Compiler::CreateJobsForCommand);
}
}  // namespace pasta