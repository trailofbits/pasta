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

void RegisterEnforceTCBAttr(py::module_ &m) {
  py::class_<EnforceTCBAttr, Attr, InheritableAttr>(m, "EnforceTCBAttr")
    .def_property_readonly("Spelling", &EnforceTCBAttr::Spelling)
    .def_property_readonly("TCBName", &EnforceTCBAttr::TCBName)
    .def_property_readonly("TCBNameLength", &EnforceTCBAttr::TCBNameLength);
}
} // namespace ogler
