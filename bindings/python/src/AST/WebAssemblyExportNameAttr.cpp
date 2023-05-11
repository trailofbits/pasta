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

void RegisterWebAssemblyExportNameAttr(py::module_ &m) {
  py::class_<WebAssemblyExportNameAttr, InheritableAttr>(m, "WebAssemblyExportNameAttr")
    .def("__hash__", [](const WebAssemblyExportNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("export_name", &WebAssemblyExportNameAttr::ExportName)
    .def_property_readonly("export_name_length", &WebAssemblyExportNameAttr::ExportNameLength)
    .def_property_readonly("spelling", &WebAssemblyExportNameAttr::Spelling);
}
} // namespace pasta
