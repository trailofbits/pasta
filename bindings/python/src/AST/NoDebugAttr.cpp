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

void RegisterNoDebugAttr(py::module_ &m) {
  py::class_<NoDebugAttr, InheritableAttr>(m, "NoDebugAttr")
    .def("__hash__", [](const NoDebugAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NoDebugAttr& a, const NoDebugAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &NoDebugAttr::Spelling);
}
} // namespace pasta
