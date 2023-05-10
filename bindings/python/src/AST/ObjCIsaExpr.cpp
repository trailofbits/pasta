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

void RegisterObjCIsaExpr(py::module_ &m) {
  py::class_<ObjCIsaExpr, Expr>(m, "ObjCIsaExpr")
    .def("__hash__", [](const ObjCIsaExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCIsaExpr& a, const ObjCIsaExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCIsaExpr::Children)
    .def_property_readonly("base", &ObjCIsaExpr::Base)
    .def_property_readonly("base_token_end", &ObjCIsaExpr::BaseTokenEnd)
    .def_property_readonly("begin_token", &ObjCIsaExpr::BeginToken)
    .def_property_readonly("end_token", &ObjCIsaExpr::EndToken)
    .def_property_readonly("expression_token", &ObjCIsaExpr::ExpressionToken)
    .def_property_readonly("isa_member_token", &ObjCIsaExpr::IsaMemberToken)
    .def_property_readonly("operation_token", &ObjCIsaExpr::OperationToken)
    .def_property_readonly("is_arrow", &ObjCIsaExpr::IsArrow);
}
} // namespace pasta
