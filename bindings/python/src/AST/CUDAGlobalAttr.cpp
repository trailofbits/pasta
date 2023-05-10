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

void RegisterCUDAGlobalAttr(py::module_ &m) {
  py::class_<CUDAGlobalAttr, InheritableAttr>(m, "CUDAGlobalAttr")
    .def("__hash__", [](const CUDAGlobalAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CUDAGlobalAttr& a, const CUDAGlobalAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &CUDAGlobalAttr::Spelling);
}
} // namespace pasta
