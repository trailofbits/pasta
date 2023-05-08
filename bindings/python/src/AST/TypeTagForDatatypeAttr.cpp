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

void RegisterTypeTagForDatatypeAttr(py::module_ &m) {
  py::class_<TypeTagForDatatypeAttr, InheritableAttr>(m, "TypeTagForDatatypeAttr")
    .def("__hash__", [](const TypeTagForDatatypeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TypeTagForDatatypeAttr& a, const TypeTagForDatatypeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("LayoutCompatible", &TypeTagForDatatypeAttr::LayoutCompatible)
    .def_property_readonly("MatchingCType", &TypeTagForDatatypeAttr::MatchingCType)
    .def_property_readonly("MatchingCTypeToken", &TypeTagForDatatypeAttr::MatchingCTypeToken)
    .def_property_readonly("MustBeNull", &TypeTagForDatatypeAttr::MustBeNull)
    .def_property_readonly("Spelling", &TypeTagForDatatypeAttr::Spelling);
}
} // namespace pasta
