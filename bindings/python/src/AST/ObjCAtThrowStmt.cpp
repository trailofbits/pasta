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

void RegisterObjCAtThrowStmt(py::module_ &m) {
  py::class_<ObjCAtThrowStmt, Stmt>(m, "ObjCAtThrowStmt")
    .def("__hash__", [](const ObjCAtThrowStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAtThrowStmt& a, const ObjCAtThrowStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCAtThrowStmt::Children)
    .def_property_readonly("BeginToken", &ObjCAtThrowStmt::BeginToken)
    .def_property_readonly("EndToken", &ObjCAtThrowStmt::EndToken)
    .def_property_readonly("ThrowExpression", &ObjCAtThrowStmt::ThrowExpression)
    .def_property_readonly("ThrowToken", &ObjCAtThrowStmt::ThrowToken);
}
} // namespace pasta
