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

void RegisterOMPDeclareVariantAttr(py::module_ &m) {
  py::class_<OMPDeclareVariantAttr, InheritableAttr>(m, "OMPDeclareVariantAttr")
    .def("__hash__", [](const OMPDeclareVariantAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OMPDeclareVariantAttr& a, const OMPDeclareVariantAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &OMPDeclareVariantAttr::Spelling)
    .def_property_readonly("variant_func_reference", &OMPDeclareVariantAttr::VariantFuncReference);
}
} // namespace pasta
