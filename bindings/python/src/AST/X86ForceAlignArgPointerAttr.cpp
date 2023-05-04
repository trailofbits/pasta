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

void RegisterX86ForceAlignArgPointerAttr(py::module_ &m) {
  py::class_<X86ForceAlignArgPointerAttr, Attr, InheritableAttr>(m, "X86ForceAlignArgPointerAttr")
    .def("__hash__", [](const X86ForceAlignArgPointerAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const X86ForceAlignArgPointerAttr& a, const X86ForceAlignArgPointerAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &X86ForceAlignArgPointerAttr::Spelling);
}
} // namespace pasta