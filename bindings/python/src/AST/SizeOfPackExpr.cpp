/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterSizeOfPackExpr(nb::module_ &m) {
  nb::class_<SizeOfPackExpr, Expr>(m, "SizeOfPackExpr")
    .def("__hash__", [](const SizeOfPackExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &SizeOfPackExpr::Children)
    .def_prop_ro("begin_token", &SizeOfPackExpr::BeginToken)
    .def_prop_ro("end_token", &SizeOfPackExpr::EndToken)
    .def_prop_ro("operator_token", &SizeOfPackExpr::OperatorToken)
    .def_prop_ro("pack", &SizeOfPackExpr::Pack)
    .def_prop_ro("pack_length", &SizeOfPackExpr::PackLength)
    .def_prop_ro("pack_token", &SizeOfPackExpr::PackToken)
    .def_prop_ro("partial_arguments", &SizeOfPackExpr::PartialArguments)
    .def_prop_ro("r_paren_token", &SizeOfPackExpr::RParenToken)
    .def_prop_ro("is_partially_substituted", &SizeOfPackExpr::IsPartiallySubstituted);
}
} // namespace pasta
