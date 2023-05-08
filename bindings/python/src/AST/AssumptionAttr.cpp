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

void RegisterAssumptionAttr(py::module_ &m) {
  py::class_<AssumptionAttr, InheritableAttr>(m, "AssumptionAttr")
    .def("__hash__", [](const AssumptionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AssumptionAttr& a, const AssumptionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("assumption", &AssumptionAttr::Assumption)
    .def_property_readonly("assumption_length", &AssumptionAttr::AssumptionLength)
    .def_property_readonly("spelling", &AssumptionAttr::Spelling);
}
} // namespace pasta
