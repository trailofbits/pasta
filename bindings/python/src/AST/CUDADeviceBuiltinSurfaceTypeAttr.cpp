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

void RegisterCUDADeviceBuiltinSurfaceTypeAttr(py::module_ &m) {
  py::class_<CUDADeviceBuiltinSurfaceTypeAttr, Attr, InheritableAttr>(m, "CUDADeviceBuiltinSurfaceTypeAttr")
    .def("__hash__", [](const CUDADeviceBuiltinSurfaceTypeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CUDADeviceBuiltinSurfaceTypeAttr& a, const CUDADeviceBuiltinSurfaceTypeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &CUDADeviceBuiltinSurfaceTypeAttr::Spelling);
}
} // namespace pasta
