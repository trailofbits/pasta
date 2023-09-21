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

void RegisterCStyleCastExpr(nb::module_ &m) {
  nb::class_<CStyleCastExpr, ExplicitCastExpr>(m, "CStyleCastExpr")
    .def("__hash__", [](const CStyleCastExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &CStyleCastExpr::BeginToken)
    .def_prop_ro("end_token", &CStyleCastExpr::EndToken)
    .def_prop_ro("l_paren_token", &CStyleCastExpr::LParenToken)
    .def_prop_ro("r_paren_token", &CStyleCastExpr::RParenToken);
}
} // namespace pasta
