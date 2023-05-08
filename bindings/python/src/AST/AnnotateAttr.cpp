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

void RegisterAnnotateAttr(py::module_ &m) {
  py::class_<AnnotateAttr, InheritableParamAttr>(m, "AnnotateAttr")
    .def("__hash__", [](const AnnotateAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AnnotateAttr& a, const AnnotateAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Annotation", &AnnotateAttr::Annotation)
    .def_property_readonly("AnnotationLength", &AnnotateAttr::AnnotationLength)
    .def_property_readonly("Spelling", &AnnotateAttr::Spelling);
}
} // namespace pasta
