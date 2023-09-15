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

void RegisterCXXFunctionalCastExpr(nb::module_ &m) {
  nb::class_<CXXFunctionalCastExpr, ExplicitCastExpr>(m, "CXXFunctionalCastExpr")
    .def("__hash__", [](const CXXFunctionalCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &CXXFunctionalCastExpr::BeginToken)
    .def_prop_ro("end_token", &CXXFunctionalCastExpr::EndToken)
    .def_prop_ro("l_paren_token", &CXXFunctionalCastExpr::LParenToken)
    .def_prop_ro("r_paren_token", &CXXFunctionalCastExpr::RParenToken)
    .def_prop_ro("is_list_initialization", &CXXFunctionalCastExpr::IsListInitialization);
}
} // namespace pasta
