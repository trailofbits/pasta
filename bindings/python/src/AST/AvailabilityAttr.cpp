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

void RegisterAvailabilityAttr(py::module_ &m) {
  py::class_<AvailabilityAttr, InheritableAttr>(m, "AvailabilityAttr")
    .def("__hash__", [](const AvailabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AvailabilityAttr& a, const AvailabilityAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("message", &AvailabilityAttr::Message)
    .def_property_readonly("message_length", &AvailabilityAttr::MessageLength)
    .def_property_readonly("replacement", &AvailabilityAttr::Replacement)
    .def_property_readonly("replacement_length", &AvailabilityAttr::ReplacementLength)
    .def_property_readonly("spelling", &AvailabilityAttr::Spelling)
    .def_property_readonly("strict", &AvailabilityAttr::Strict)
    .def_property_readonly("unavailable", &AvailabilityAttr::Unavailable);
}
} // namespace pasta
