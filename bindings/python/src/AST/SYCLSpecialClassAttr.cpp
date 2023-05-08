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

void RegisterSYCLSpecialClassAttr(py::module_ &m) {
  py::class_<SYCLSpecialClassAttr, InheritableAttr>(m, "SYCLSpecialClassAttr")
    .def("__hash__", [](const SYCLSpecialClassAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SYCLSpecialClassAttr& a, const SYCLSpecialClassAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &SYCLSpecialClassAttr::Spelling);
}
} // namespace pasta
