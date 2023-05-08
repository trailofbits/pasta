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

void RegisterOpenCLLocalAddressSpaceAttr(py::module_ &m) {
  py::class_<OpenCLLocalAddressSpaceAttr, TypeAttr>(m, "OpenCLLocalAddressSpaceAttr")
    .def("__hash__", [](const OpenCLLocalAddressSpaceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OpenCLLocalAddressSpaceAttr& a, const OpenCLLocalAddressSpaceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &OpenCLLocalAddressSpaceAttr::SemanticSpelling)
    .def_property_readonly("spelling", &OpenCLLocalAddressSpaceAttr::Spelling);
}
} // namespace pasta
