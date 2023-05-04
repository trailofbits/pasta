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

void RegisterCUDALaunchBoundsAttr(py::module_ &m) {
  py::class_<CUDALaunchBoundsAttr, Attr, InheritableAttr>(m, "CUDALaunchBoundsAttr")
    .def("__hash__", [](const CUDALaunchBoundsAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CUDALaunchBoundsAttr& a, const CUDALaunchBoundsAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("MaxThreads", &CUDALaunchBoundsAttr::MaxThreads)
    .def_property_readonly("MinBlocks", &CUDALaunchBoundsAttr::MinBlocks)
    .def_property_readonly("Spelling", &CUDALaunchBoundsAttr::Spelling);
}
} // namespace pasta