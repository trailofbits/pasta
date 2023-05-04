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

void RegisterObjCIsaExpr(py::module_ &m) {
  py::class_<ObjCIsaExpr, Expr, Stmt, ValueStmt>(m, "ObjCIsaExpr")
    .def("__hash__", [](const ObjCIsaExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCIsaExpr& a, const ObjCIsaExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCIsaExpr::Children)
    .def_property_readonly("Base", &ObjCIsaExpr::Base)
    .def_property_readonly("BaseTokenEnd", &ObjCIsaExpr::BaseTokenEnd)
    .def_property_readonly("BeginToken", &ObjCIsaExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCIsaExpr::EndToken)
    .def_property_readonly("ExpressionToken", &ObjCIsaExpr::ExpressionToken)
    .def_property_readonly("IsaMemberToken", &ObjCIsaExpr::IsaMemberToken)
    .def_property_readonly("OperationToken", &ObjCIsaExpr::OperationToken)
    .def_property_readonly("IsArrow", &ObjCIsaExpr::IsArrow);
}
} // namespace pasta
