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

void RegisterNoSanitizeAttr(py::module_ &m) {
  py::class_<NoSanitizeAttr, InheritableAttr>(m, "NoSanitizeAttr")
    .def("__hash__", [](const NoSanitizeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NoSanitizeAttr& a, const NoSanitizeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &NoSanitizeAttr::Spelling)
    .def_property_readonly("has_coverage", &NoSanitizeAttr::HasCoverage);
}
} // namespace pasta
