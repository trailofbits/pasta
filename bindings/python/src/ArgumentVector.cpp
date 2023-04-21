#include <pasta/Util/FileSystem.h>

#include "bindings.h"
#include <pasta/Util/ArgumentVector.h>

namespace pasta {

namespace py = pybind11;
void RegisterArgumentVector(py::module_ &m) {
  py::class_<ArgumentVector>(m, "ArgumentVector")
    .def(py::init<const std::string &>())
    .def(py::init<std::string_view>())
    .def(py::init<const std::vector<std::string> &>())
    .def(py::init<const std::vector<const char *> &>())
    .def("reset", py::overload_cast<std::string_view>(&ArgumentVector::Reset))
    .def("reset", py::overload_cast<const std::vector<std::string> &>(&ArgumentVector::Reset))
    .def("reset", py::overload_cast<const std::vector<const char *> &>(&ArgumentVector::Reset))
    .def_property_readonly("arguments", &ArgumentVector::Arguments)
    .def("join", &ArgumentVector::Join, py::arg("sep") = " ");
}
}  // namespace pasta