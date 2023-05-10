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

void RegisterAnnotateTypeAttr(py::module_ &m) {
  py::class_<AnnotateTypeAttr, TypeAttr>(m, "AnnotateTypeAttr")
    .def("__hash__", [](const AnnotateTypeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AnnotateTypeAttr& a, const AnnotateTypeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("annotation", &AnnotateTypeAttr::Annotation)
    .def_property_readonly("annotation_length", &AnnotateTypeAttr::AnnotationLength)
    .def_property_readonly("spelling", &AnnotateTypeAttr::Spelling);
}
} // namespace pasta
