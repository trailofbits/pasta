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

void RegisterObjCForCollectionStmt(py::module_ &m) {
  py::class_<ObjCForCollectionStmt, Stmt>(m, "ObjCForCollectionStmt")
    .def_property_readonly("Children", &ObjCForCollectionStmt::Children)
    .def_property_readonly("BeginToken", &ObjCForCollectionStmt::BeginToken)
    .def_property_readonly("Body", &ObjCForCollectionStmt::Body)
    .def_property_readonly("Collection", &ObjCForCollectionStmt::Collection)
    .def_property_readonly("Element", &ObjCForCollectionStmt::Element)
    .def_property_readonly("EndToken", &ObjCForCollectionStmt::EndToken)
    .def_property_readonly("ForToken", &ObjCForCollectionStmt::ForToken)
    .def_property_readonly("RParenToken", &ObjCForCollectionStmt::RParenToken);
}
} // namespace pasta
