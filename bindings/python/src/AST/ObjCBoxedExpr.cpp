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

void RegisterObjCBoxedExpr(py::module_ &m) {
  py::class_<ObjCBoxedExpr, Expr>(m, "ObjCBoxedExpr")
    .def("__hash__", [](const ObjCBoxedExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCBoxedExpr& a, const ObjCBoxedExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCBoxedExpr::Children)
    .def_property_readonly("at_token", &ObjCBoxedExpr::AtToken)
    .def_property_readonly("begin_token", &ObjCBoxedExpr::BeginToken)
    .def_property_readonly("boxing_method", &ObjCBoxedExpr::BoxingMethod)
    .def_property_readonly("end_token", &ObjCBoxedExpr::EndToken)
    .def_property_readonly("tokens", &ObjCBoxedExpr::Tokens)
    .def_property_readonly("sub_expression", &ObjCBoxedExpr::SubExpression)
    .def_property_readonly("is_expressible_as_constant_initializer", &ObjCBoxedExpr::IsExpressibleAsConstantInitializer);
}
} // namespace pasta
