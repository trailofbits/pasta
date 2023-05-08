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

void RegisterWebAssemblyImportModuleAttr(py::module_ &m) {
  py::class_<WebAssemblyImportModuleAttr, InheritableAttr>(m, "WebAssemblyImportModuleAttr")
    .def("__hash__", [](const WebAssemblyImportModuleAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const WebAssemblyImportModuleAttr& a, const WebAssemblyImportModuleAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("ImportModule", &WebAssemblyImportModuleAttr::ImportModule)
    .def_property_readonly("ImportModuleLength", &WebAssemblyImportModuleAttr::ImportModuleLength)
    .def_property_readonly("Spelling", &WebAssemblyImportModuleAttr::Spelling);
}
} // namespace pasta
