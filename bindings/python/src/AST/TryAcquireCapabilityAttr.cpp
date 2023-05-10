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

void RegisterTryAcquireCapabilityAttr(py::module_ &m) {
  py::class_<TryAcquireCapabilityAttr, InheritableAttr>(m, "TryAcquireCapabilityAttr")
    .def("__hash__", [](const TryAcquireCapabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TryAcquireCapabilityAttr& a, const TryAcquireCapabilityAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &TryAcquireCapabilityAttr::SemanticSpelling)
    .def_property_readonly("spelling", &TryAcquireCapabilityAttr::Spelling)
    .def_property_readonly("success_value", &TryAcquireCapabilityAttr::SuccessValue)
    .def_property_readonly("is_shared", &TryAcquireCapabilityAttr::IsShared);
}
} // namespace pasta
