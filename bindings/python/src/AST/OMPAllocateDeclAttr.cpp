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

void RegisterOMPAllocateDeclAttr(py::module_ &m) {
  py::class_<OMPAllocateDeclAttr, Attr, InheritableAttr>(m, "OMPAllocateDeclAttr")
    .def("__hash__", [](const OMPAllocateDeclAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OMPAllocateDeclAttr& a, const OMPAllocateDeclAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Alignment", &OMPAllocateDeclAttr::Alignment)
    .def_property_readonly("Allocator", &OMPAllocateDeclAttr::Allocator)
    .def_property_readonly("AllocatorType", &OMPAllocateDeclAttr::AllocatorType)
    .def_property_readonly("Spelling", &OMPAllocateDeclAttr::Spelling);
}
} // namespace pasta
