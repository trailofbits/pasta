#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterCompileJob(py::module_ &m) {
  py::class_<CompileJob>(m, "CompileJob")
    .def("run", &CompileJob::Run);
}
}  // namespace pasta