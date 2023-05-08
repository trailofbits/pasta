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

void RegisterCodeSegAttr(py::module_ &m) {
  py::class_<CodeSegAttr, InheritableAttr>(m, "CodeSegAttr")
    .def("__hash__", [](const CodeSegAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CodeSegAttr& a, const CodeSegAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("name", &CodeSegAttr::Name)
    .def_property_readonly("name_length", &CodeSegAttr::NameLength)
    .def_property_readonly("spelling", &CodeSegAttr::Spelling);
}
} // namespace pasta
