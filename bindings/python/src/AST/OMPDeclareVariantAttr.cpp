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

void RegisterOMPDeclareVariantAttr(py::module_ &m) {
  py::class_<OMPDeclareVariantAttr, Attr, InheritableAttr>(m, "OMPDeclareVariantAttr")
    .def("__hash__", [](const OMPDeclareVariantAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OMPDeclareVariantAttr& a, const OMPDeclareVariantAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &OMPDeclareVariantAttr::Spelling)
    .def_property_readonly("VariantFuncReference", &OMPDeclareVariantAttr::VariantFuncReference);
}
} // namespace pasta