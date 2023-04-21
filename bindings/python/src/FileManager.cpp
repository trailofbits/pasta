#include <pasta/Util/FileManager.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterFileManager(py::module_ &m) {
  py::class_<FileManager>(m, "FileManager")
    .def(py::init<std::shared_ptr<FileSystem>>());
}
}  // namespace pasta