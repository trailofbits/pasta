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

void RegisterObjCSubclassingRestrictedAttr(py::module_ &m) {
  py::class_<ObjCSubclassingRestrictedAttr, Attr, InheritableAttr>(m, "ObjCSubclassingRestrictedAttr")
    .def_property_readonly("Spelling", &ObjCSubclassingRestrictedAttr::Spelling);
}
} // namespace ogler
