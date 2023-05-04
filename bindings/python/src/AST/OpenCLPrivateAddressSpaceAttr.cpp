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

void RegisterOpenCLPrivateAddressSpaceAttr(py::module_ &m) {
  py::class_<OpenCLPrivateAddressSpaceAttr, Attr, TypeAttr>(m, "OpenCLPrivateAddressSpaceAttr")
    .def("__hash__", [](const OpenCLPrivateAddressSpaceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OpenCLPrivateAddressSpaceAttr& a, const OpenCLPrivateAddressSpaceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &OpenCLPrivateAddressSpaceAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &OpenCLPrivateAddressSpaceAttr::Spelling);
}
} // namespace pasta
