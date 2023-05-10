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

void RegisterObjCSubscriptRefExpr(py::module_ &m) {
  py::class_<ObjCSubscriptRefExpr, Expr>(m, "ObjCSubscriptRefExpr")
    .def("__hash__", [](const ObjCSubscriptRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCSubscriptRefExpr& a, const ObjCSubscriptRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCSubscriptRefExpr::Children)
    .def_property_readonly("at_index_method_declaration", &ObjCSubscriptRefExpr::AtIndexMethodDeclaration)
    .def_property_readonly("base_expression", &ObjCSubscriptRefExpr::BaseExpression)
    .def_property_readonly("begin_token", &ObjCSubscriptRefExpr::BeginToken)
    .def_property_readonly("end_token", &ObjCSubscriptRefExpr::EndToken)
    .def_property_readonly("key_expression", &ObjCSubscriptRefExpr::KeyExpression)
    .def_property_readonly("r_bracket_token", &ObjCSubscriptRefExpr::RBracketToken)
    .def_property_readonly("is_array_subscript_reference_expression", &ObjCSubscriptRefExpr::IsArraySubscriptReferenceExpression);
}
} // namespace pasta
