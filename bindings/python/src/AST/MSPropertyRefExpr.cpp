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

void RegisterMSPropertyRefExpr(py::module_ &m) {
  py::class_<MSPropertyRefExpr, Expr>(m, "MSPropertyRefExpr")
    .def("__hash__", [](const MSPropertyRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MSPropertyRefExpr& a, const MSPropertyRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MSPropertyRefExpr::Children)
    .def_property_readonly("base_expression", &MSPropertyRefExpr::BaseExpression)
    .def_property_readonly("begin_token", &MSPropertyRefExpr::BeginToken)
    .def_property_readonly("end_token", &MSPropertyRefExpr::EndToken)
    .def_property_readonly("member_token", &MSPropertyRefExpr::MemberToken)
    .def_property_readonly("property_declaration", &MSPropertyRefExpr::PropertyDeclaration)
    .def_property_readonly("tokens", &MSPropertyRefExpr::Tokens)
    .def_property_readonly("is_arrow", &MSPropertyRefExpr::IsArrow)
    .def_property_readonly("is_implicit_access", &MSPropertyRefExpr::IsImplicitAccess);
}
} // namespace pasta
