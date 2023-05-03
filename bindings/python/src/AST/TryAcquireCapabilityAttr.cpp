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

void RegisterTryAcquireCapabilityAttr(py::module_ &m) {
  py::class_<TryAcquireCapabilityAttr, Attr, InheritableAttr>(m, "TryAcquireCapabilityAttr")
    .def_property_readonly("SemanticSpelling", &TryAcquireCapabilityAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &TryAcquireCapabilityAttr::Spelling)
    .def_property_readonly("SuccessValue", &TryAcquireCapabilityAttr::SuccessValue)
    .def_property_readonly("IsShared", &TryAcquireCapabilityAttr::IsShared);
}
} // namespace ogler
