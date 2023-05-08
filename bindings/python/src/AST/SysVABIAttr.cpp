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

void RegisterSysVABIAttr(py::module_ &m) {
  py::class_<SysVABIAttr, InheritableAttr>(m, "SysVABIAttr")
    .def("__hash__", [](const SysVABIAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SysVABIAttr& a, const SysVABIAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &SysVABIAttr::Spelling);
}
} // namespace pasta
