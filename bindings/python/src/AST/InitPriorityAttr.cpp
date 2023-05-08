/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterInitPriorityAttr(py::module_ &m) {
  py::class_<InitPriorityAttr, InheritableAttr>(m, "InitPriorityAttr")
    .def("__hash__", [](const InitPriorityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const InitPriorityAttr& a, const InitPriorityAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("priority", &InitPriorityAttr::Priority)
    .def_property_readonly("spelling", &InitPriorityAttr::Spelling);
}
} // namespace pasta
