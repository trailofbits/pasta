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

void RegisterOpenCLGlobalDeviceAddressSpaceAttr(py::module_ &m) {
  py::class_<OpenCLGlobalDeviceAddressSpaceAttr, Attr, TypeAttr>(m, "OpenCLGlobalDeviceAddressSpaceAttr")
    .def("__hash__", [](const OpenCLGlobalDeviceAddressSpaceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OpenCLGlobalDeviceAddressSpaceAttr& a, const OpenCLGlobalDeviceAddressSpaceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &OpenCLGlobalDeviceAddressSpaceAttr::Spelling);
}
} // namespace pasta