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

void RegisterWebAssemblyImportNameAttr(py::module_ &m) {
  py::class_<WebAssemblyImportNameAttr, InheritableAttr>(m, "WebAssemblyImportNameAttr")
    .def("__hash__", [](const WebAssemblyImportNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("import_name", &WebAssemblyImportNameAttr::ImportName)
    .def_property_readonly("import_name_length", &WebAssemblyImportNameAttr::ImportNameLength)
    .def_property_readonly("spelling", &WebAssemblyImportNameAttr::Spelling);
}
} // namespace pasta
