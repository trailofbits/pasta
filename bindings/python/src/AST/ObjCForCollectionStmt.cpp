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

void RegisterObjCForCollectionStmt(py::module_ &m) {
  py::class_<ObjCForCollectionStmt, Stmt>(m, "ObjCForCollectionStmt")
    .def("__hash__", [](const ObjCForCollectionStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCForCollectionStmt::Children)
    .def_property_readonly("begin_token", &ObjCForCollectionStmt::BeginToken)
    .def_property_readonly("body", &ObjCForCollectionStmt::Body)
    .def_property_readonly("collection", &ObjCForCollectionStmt::Collection)
    .def_property_readonly("element", &ObjCForCollectionStmt::Element)
    .def_property_readonly("end_token", &ObjCForCollectionStmt::EndToken)
    .def_property_readonly("for_token", &ObjCForCollectionStmt::ForToken)
    .def_property_readonly("r_paren_token", &ObjCForCollectionStmt::RParenToken);
}
} // namespace pasta
