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
  py::class_<WebAssemblyImportModuleAttr, Attr, InheritableAttr>(m, "WebAssemblyImportModuleAttr")
    .def_property_readonly("ImportModule", &WebAssemblyImportModuleAttr::ImportModule)
    .def_property_readonly("ImportModuleLength", &WebAssemblyImportModuleAttr::ImportModuleLength)
    .def_property_readonly("Spelling", &WebAssemblyImportModuleAttr::Spelling);
}
} // namespace ogler
