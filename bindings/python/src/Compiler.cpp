#include <pasta/Compile/Compiler.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterCompiler(py::module_ &m) {
  py::class_<Compiler>(m, "Compiler")
    .def_static("create_host_compiler", &Compiler::CreateHostCompiler)
    .def("create_jobs_for_command", &Compiler::CreateJobsForCommand);
}
}  // namespace pasta