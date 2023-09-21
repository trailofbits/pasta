/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCXXTypeidExpr(nb::module_ &m) {
  nb::class_<CXXTypeidExpr, Expr>(m, "CXXTypeidExpr")
    .def("__hash__", [](const CXXTypeidExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXTypeidExpr::Children)
    .def_prop_ro("begin_token", &CXXTypeidExpr::BeginToken)
    .def_prop_ro("end_token", &CXXTypeidExpr::EndToken)
    .def_prop_ro("expression_operand", &CXXTypeidExpr::ExpressionOperand)
    .def_prop_ro("tokens", &CXXTypeidExpr::Tokens)
    .def_prop_ro("type_operand", &CXXTypeidExpr::TypeOperand)
    .def_prop_ro("type_operand_source_info", &CXXTypeidExpr::TypeOperandSourceInfo)
    .def_prop_ro("is_most_derived", &CXXTypeidExpr::IsMostDerived)
    .def_prop_ro("is_potentially_evaluated", &CXXTypeidExpr::IsPotentiallyEvaluated)
    .def_prop_ro("is_type_operand", &CXXTypeidExpr::IsTypeOperand);
}
} // namespace pasta
