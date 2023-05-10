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

void RegisterObjCAutoreleasePoolStmt(py::module_ &m) {
  py::class_<ObjCAutoreleasePoolStmt, Stmt>(m, "ObjCAutoreleasePoolStmt")
    .def("__hash__", [](const ObjCAutoreleasePoolStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAutoreleasePoolStmt& a, const ObjCAutoreleasePoolStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCAutoreleasePoolStmt::Children)
    .def_property_readonly("at_token", &ObjCAutoreleasePoolStmt::AtToken)
    .def_property_readonly("begin_token", &ObjCAutoreleasePoolStmt::BeginToken)
    .def_property_readonly("end_token", &ObjCAutoreleasePoolStmt::EndToken)
    .def_property_readonly("sub_statement", &ObjCAutoreleasePoolStmt::SubStatement);
}
} // namespace pasta
