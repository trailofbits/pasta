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

void RegisterOpenCLAccessAttr(py::module_ &m) {
  py::class_<OpenCLAccessAttr, Attr>(m, "OpenCLAccessAttr")
    .def("__hash__", [](const OpenCLAccessAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OpenCLAccessAttr& a, const OpenCLAccessAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &OpenCLAccessAttr::SemanticSpelling)
    .def_property_readonly("spelling", &OpenCLAccessAttr::Spelling)
    .def_property_readonly("is_read_only", &OpenCLAccessAttr::IsReadOnly)
    .def_property_readonly("is_read_write", &OpenCLAccessAttr::IsReadWrite)
    .def_property_readonly("is_write_only", &OpenCLAccessAttr::IsWriteOnly);
}
} // namespace pasta
