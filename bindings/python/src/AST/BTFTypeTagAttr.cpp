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

void RegisterBTFTypeTagAttr(py::module_ &m) {
  py::class_<BTFTypeTagAttr, TypeAttr>(m, "BTFTypeTagAttr")
    .def("__hash__", [](const BTFTypeTagAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("btf_type_tag", &BTFTypeTagAttr::BTFTypeTag)
    .def_property_readonly("btf_type_tag_length", &BTFTypeTagAttr::BTFTypeTagLength)
    .def_property_readonly("spelling", &BTFTypeTagAttr::Spelling);
}
} // namespace pasta
