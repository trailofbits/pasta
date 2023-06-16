/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterVAArgExpr(nb::module_ &m) {
  nb::class_<VAArgExpr, Expr>(m, "VAArgExpr")
    .def("__hash__", [](const VAArgExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &VAArgExpr::Children)
    .def_prop_ro("begin_token", &VAArgExpr::BeginToken)
    .def_prop_ro("builtin_token", &VAArgExpr::BuiltinToken)
    .def_prop_ro("end_token", &VAArgExpr::EndToken)
    .def_prop_ro("r_paren_token", &VAArgExpr::RParenToken)
    .def_prop_ro("sub_expression", &VAArgExpr::SubExpression)
    .def_prop_ro("written_type", &VAArgExpr::WrittenType)
    .def_prop_ro("is_microsoft_abi", &VAArgExpr::IsMicrosoftABI);
}
} // namespace pasta
