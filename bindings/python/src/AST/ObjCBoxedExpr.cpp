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

void RegisterObjCBoxedExpr(py::module_ &m) {
  py::class_<ObjCBoxedExpr, Expr>(m, "ObjCBoxedExpr")
    .def("__hash__", [](const ObjCBoxedExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCBoxedExpr& a, const ObjCBoxedExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCBoxedExpr::Children)
    .def_property_readonly("AtToken", &ObjCBoxedExpr::AtToken)
    .def_property_readonly("BeginToken", &ObjCBoxedExpr::BeginToken)
    .def_property_readonly("BoxingMethod", &ObjCBoxedExpr::BoxingMethod)
    .def_property_readonly("EndToken", &ObjCBoxedExpr::EndToken)
    .def_property_readonly("Tokens", &ObjCBoxedExpr::Tokens)
    .def_property_readonly("SubExpression", &ObjCBoxedExpr::SubExpression)
    .def_property_readonly("IsExpressibleAsConstantInitializer", &ObjCBoxedExpr::IsExpressibleAsConstantInitializer);
}
} // namespace pasta
