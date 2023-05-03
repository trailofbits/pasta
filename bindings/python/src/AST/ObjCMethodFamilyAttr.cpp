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

void RegisterObjCMethodFamilyAttr(py::module_ &m) {
  py::class_<ObjCMethodFamilyAttr, Attr, InheritableAttr>(m, "ObjCMethodFamilyAttr")
    .def_property_readonly("Family", &ObjCMethodFamilyAttr::Family)
    .def_property_readonly("Spelling", &ObjCMethodFamilyAttr::Spelling);
}
} // namespace ogler
