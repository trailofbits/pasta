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

void RegisterCUDADeviceAttr(py::module_ &m) {
  py::class_<CUDADeviceAttr, InheritableAttr>(m, "CUDADeviceAttr")
    .def("__hash__", [](const CUDADeviceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CUDADeviceAttr& a, const CUDADeviceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &CUDADeviceAttr::Spelling);
}
} // namespace pasta
