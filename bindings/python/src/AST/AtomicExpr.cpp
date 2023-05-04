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

void RegisterAtomicExpr(py::module_ &m) {
  py::class_<AtomicExpr, Expr, Stmt, ValueStmt>(m, "AtomicExpr")
    .def_property_readonly("Children", &AtomicExpr::Children)
    .def_property_readonly("BeginToken", &AtomicExpr::BeginToken)
    .def_property_readonly("BuiltinToken", &AtomicExpr::BuiltinToken)
    .def_property_readonly("EndToken", &AtomicExpr::EndToken)
    .def_property_readonly("NumSubExpressions", &AtomicExpr::NumSubExpressions)
    .def_property_readonly("Operation", &AtomicExpr::Operation)
    .def_property_readonly("Order", &AtomicExpr::Order)
    .def_property_readonly("OrderFail", &AtomicExpr::OrderFail)
    .def_property_readonly("Pointer", &AtomicExpr::Pointer)
    .def_property_readonly("RParenToken", &AtomicExpr::RParenToken)
    .def_property_readonly("Scope", &AtomicExpr::Scope)
    .def_property_readonly("Value1", &AtomicExpr::Value1)
    .def_property_readonly("Value2", &AtomicExpr::Value2)
    .def_property_readonly("ValueType", &AtomicExpr::ValueType)
    .def_property_readonly("Weak", &AtomicExpr::Weak)
    .def_property_readonly("IsCmpXChg", &AtomicExpr::IsCmpXChg)
    .def_property_readonly("IsOpenCL", &AtomicExpr::IsOpenCL)
    .def_property_readonly("IsVolatile", &AtomicExpr::IsVolatile);
}
} // namespace pasta
