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

void RegisterWebAssemblyImportNameAttr(py::module_ &m) {
  py::class_<WebAssemblyImportNameAttr, InheritableAttr>(m, "WebAssemblyImportNameAttr")
    .def("__hash__", [](const WebAssemblyImportNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const WebAssemblyImportNameAttr& a, const WebAssemblyImportNameAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("ImportName", &WebAssemblyImportNameAttr::ImportName)
    .def_property_readonly("ImportNameLength", &WebAssemblyImportNameAttr::ImportNameLength)
    .def_property_readonly("Spelling", &WebAssemblyImportNameAttr::Spelling);
}
} // namespace pasta
