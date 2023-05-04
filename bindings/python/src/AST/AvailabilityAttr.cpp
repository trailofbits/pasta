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

void RegisterAvailabilityAttr(py::module_ &m) {
  py::class_<AvailabilityAttr, Attr, InheritableAttr>(m, "AvailabilityAttr")
    .def_property_readonly("Message", &AvailabilityAttr::Message)
    .def_property_readonly("MessageLength", &AvailabilityAttr::MessageLength)
    .def_property_readonly("Replacement", &AvailabilityAttr::Replacement)
    .def_property_readonly("ReplacementLength", &AvailabilityAttr::ReplacementLength)
    .def_property_readonly("Spelling", &AvailabilityAttr::Spelling)
    .def_property_readonly("Strict", &AvailabilityAttr::Strict)
    .def_property_readonly("Unavailable", &AvailabilityAttr::Unavailable);
}
} // namespace pasta
