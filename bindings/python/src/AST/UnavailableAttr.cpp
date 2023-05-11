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

void RegisterUnavailableAttr(py::module_ &m) {
  py::class_<UnavailableAttr, InheritableAttr>(m, "UnavailableAttr")
    .def("__hash__", [](const UnavailableAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("implicit_reason", &UnavailableAttr::ImplicitReason)
    .def_property_readonly("message", &UnavailableAttr::Message)
    .def_property_readonly("message_length", &UnavailableAttr::MessageLength)
    .def_property_readonly("spelling", &UnavailableAttr::Spelling);
}
} // namespace pasta
