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

void RegisterUnavailableAttr(py::module_ &m) {
  py::class_<UnavailableAttr, Attr, InheritableAttr>(m, "UnavailableAttr")
    .def_property_readonly("ImplicitReason", &UnavailableAttr::ImplicitReason)
    .def_property_readonly("Message", &UnavailableAttr::Message)
    .def_property_readonly("MessageLength", &UnavailableAttr::MessageLength)
    .def_property_readonly("Spelling", &UnavailableAttr::Spelling);
}
} // namespace pasta
