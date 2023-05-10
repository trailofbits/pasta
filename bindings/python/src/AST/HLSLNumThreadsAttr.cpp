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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterHLSLNumThreadsAttr(py::module_ &m) {
  py::class_<HLSLNumThreadsAttr, InheritableAttr>(m, "HLSLNumThreadsAttr")
    .def("__hash__", [](const HLSLNumThreadsAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const HLSLNumThreadsAttr& a, const HLSLNumThreadsAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &HLSLNumThreadsAttr::Spelling);
}
} // namespace pasta
