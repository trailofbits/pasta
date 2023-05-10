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

void RegisterPatchableFunctionEntryAttr(py::module_ &m) {
  py::class_<PatchableFunctionEntryAttr, InheritableAttr>(m, "PatchableFunctionEntryAttr")
    .def("__hash__", [](const PatchableFunctionEntryAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PatchableFunctionEntryAttr& a, const PatchableFunctionEntryAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("count", &PatchableFunctionEntryAttr::Count)
    .def_property_readonly("spelling", &PatchableFunctionEntryAttr::Spelling);
}
} // namespace pasta
