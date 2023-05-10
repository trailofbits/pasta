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

void RegisterAcquireCapabilityAttr(py::module_ &m) {
  py::class_<AcquireCapabilityAttr, InheritableAttr>(m, "AcquireCapabilityAttr")
    .def("__hash__", [](const AcquireCapabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AcquireCapabilityAttr& a, const AcquireCapabilityAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &AcquireCapabilityAttr::SemanticSpelling)
    .def_property_readonly("spelling", &AcquireCapabilityAttr::Spelling)
    .def_property_readonly("is_shared", &AcquireCapabilityAttr::IsShared);
}
} // namespace pasta
