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

void RegisterAcquireHandleAttr(py::module_ &m) {
  py::class_<AcquireHandleAttr, InheritableAttr>(m, "AcquireHandleAttr")
    .def("__hash__", [](const AcquireHandleAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AcquireHandleAttr& a, const AcquireHandleAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("handle_type", &AcquireHandleAttr::HandleType)
    .def_property_readonly("handle_type_length", &AcquireHandleAttr::HandleTypeLength)
    .def_property_readonly("spelling", &AcquireHandleAttr::Spelling);
}
} // namespace pasta
