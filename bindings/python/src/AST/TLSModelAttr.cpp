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

void RegisterTLSModelAttr(py::module_ &m) {
  py::class_<TLSModelAttr, InheritableAttr>(m, "TLSModelAttr")
    .def("__hash__", [](const TLSModelAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TLSModelAttr& a, const TLSModelAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("model", &TLSModelAttr::Model)
    .def_property_readonly("model_length", &TLSModelAttr::ModelLength)
    .def_property_readonly("spelling", &TLSModelAttr::Spelling);
}
} // namespace pasta
