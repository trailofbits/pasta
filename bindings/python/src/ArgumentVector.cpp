/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Util/FileSystem.h>

#include "bindings.h"
#include <pasta/Util/ArgumentVector.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/string.h>

namespace pasta {

namespace nb = nanobind;
void RegisterArgumentVector(nb::module_ &m) {
  nb::class_<ArgumentVector>(m, "ArgumentVector")
    .def(nb::init<const std::string &>())
    .def(nb::init<std::string_view>())
    .def(nb::init<const std::vector<std::string> &>())
    .def(nb::init<const std::vector<const char *> &>())
    .def("reset", nb::overload_cast<std::string_view>(&ArgumentVector::Reset))
    .def("reset", nb::overload_cast<const std::vector<std::string> &>(&ArgumentVector::Reset))
    .def("reset", nb::overload_cast<const std::vector<const char *> &>(&ArgumentVector::Reset))
    .def_prop_ro("arguments", &ArgumentVector::Arguments)
    .def("join", &ArgumentVector::Join, nb::arg("sep") = " ");
}
}  // namespace pasta
