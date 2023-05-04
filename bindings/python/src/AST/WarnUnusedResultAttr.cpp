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

void RegisterWarnUnusedResultAttr(py::module_ &m) {
  py::class_<WarnUnusedResultAttr, Attr, InheritableAttr>(m, "WarnUnusedResultAttr")
    .def("__hash__", [](const WarnUnusedResultAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const WarnUnusedResultAttr& a, const WarnUnusedResultAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("IsCXX11NoDiscard", &WarnUnusedResultAttr::IsCXX11NoDiscard)
    .def_property_readonly("Message", &WarnUnusedResultAttr::Message)
    .def_property_readonly("MessageLength", &WarnUnusedResultAttr::MessageLength)
    .def_property_readonly("SemanticSpelling", &WarnUnusedResultAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &WarnUnusedResultAttr::Spelling);
}
} // namespace pasta