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

void RegisterDLLExportStaticLocalAttr(py::module_ &m) {
  py::class_<DLLExportStaticLocalAttr, InheritableAttr>(m, "DLLExportStaticLocalAttr")
    .def("__hash__", [](const DLLExportStaticLocalAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const DLLExportStaticLocalAttr& a, const DLLExportStaticLocalAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &DLLExportStaticLocalAttr::Spelling);
}
} // namespace pasta
