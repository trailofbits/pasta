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

void RegisterAtomicExpr(py::module_ &m) {
  py::class_<AtomicExpr, Expr>(m, "AtomicExpr")
    .def("__hash__", [](const AtomicExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const AtomicExpr& a, const AtomicExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &AtomicExpr::Children)
    .def_property_readonly("begin_token", &AtomicExpr::BeginToken)
    .def_property_readonly("builtin_token", &AtomicExpr::BuiltinToken)
    .def_property_readonly("end_token", &AtomicExpr::EndToken)
    .def_property_readonly("num_sub_expressions", &AtomicExpr::NumSubExpressions)
    .def_property_readonly("operation", &AtomicExpr::Operation)
    .def_property_readonly("order", &AtomicExpr::Order)
    .def_property_readonly("order_fail", &AtomicExpr::OrderFail)
    .def_property_readonly("pointer", &AtomicExpr::Pointer)
    .def_property_readonly("r_paren_token", &AtomicExpr::RParenToken)
    .def_property_readonly("scope", &AtomicExpr::Scope)
    .def_property_readonly("value1", &AtomicExpr::Value1)
    .def_property_readonly("value2", &AtomicExpr::Value2)
    .def_property_readonly("value_type", &AtomicExpr::ValueType)
    .def_property_readonly("weak", &AtomicExpr::Weak)
    .def_property_readonly("is_cmp_x_chg", &AtomicExpr::IsCmpXChg)
    .def_property_readonly("is_open_cl", &AtomicExpr::IsOpenCL)
    .def_property_readonly("is_volatile", &AtomicExpr::IsVolatile);
}
} // namespace pasta
