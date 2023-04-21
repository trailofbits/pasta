#include <pasta/Compile/Command.h>

#include "bindings.h"

#include <pasta/Util/ArgumentVector.h>

namespace pasta {

namespace py = pybind11;
void RegisterCompileCommand(py::module_ &m) {
  py::class_<CompileCommand>(m, "CompileCommand")
    .def_static("create_from_arguments", &CompileCommand::CreateFromArguments)
    .def_property_readonly("arguments", &CompileCommand::Arguments)
    .def_property_readonly("working_directory", &CompileCommand::WorkingDirectory);
}
}  // namespace pasta