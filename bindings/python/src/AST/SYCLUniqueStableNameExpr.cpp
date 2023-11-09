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

void RegisterSYCLUniqueStableNameExpr(nb::module_ &m) {
  nb::class_<SYCLUniqueStableNameExpr, Expr>(m, "SYCLUniqueStableNameExpr")
    .def("__hash__", [](const SYCLUniqueStableNameExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("compute_name", &SYCLUniqueStableNameExpr::ComputeName)
    .def_prop_ro("children", &SYCLUniqueStableNameExpr::Children)
    .def_prop_ro("begin_token", &SYCLUniqueStableNameExpr::BeginToken)
    .def_prop_ro("end_token", &SYCLUniqueStableNameExpr::EndToken)
    .def_prop_ro("l_paren_token", &SYCLUniqueStableNameExpr::LParenToken)
    .def_prop_ro("token", &SYCLUniqueStableNameExpr::Token)
    .def_prop_ro("r_paren_token", &SYCLUniqueStableNameExpr::RParenToken);
}
} // namespace pasta
