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

void RegisterObjCBoolLiteralExpr(py::module_ &m) {
  py::class_<ObjCBoolLiteralExpr, Expr>(m, "ObjCBoolLiteralExpr")
    .def("__hash__", [](const ObjCBoolLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCBoolLiteralExpr& a, const ObjCBoolLiteralExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCBoolLiteralExpr::Children)
    .def_property_readonly("begin_token", &ObjCBoolLiteralExpr::BeginToken)
    .def_property_readonly("end_token", &ObjCBoolLiteralExpr::EndToken)
    .def_property_readonly("token", &ObjCBoolLiteralExpr::Token)
    .def_property_readonly("value", &ObjCBoolLiteralExpr::Value);
}
} // namespace pasta
