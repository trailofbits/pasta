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

void RegisterCXXUnresolvedConstructExpr(nb::module_ &m) {
  nb::class_<CXXUnresolvedConstructExpr, Expr>(m, "CXXUnresolvedConstructExpr")
    .def("__hash__", [](const CXXUnresolvedConstructExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("arguments", &CXXUnresolvedConstructExpr::Arguments)
    .def_prop_ro("children", &CXXUnresolvedConstructExpr::Children)
    .def_prop_ro("begin_token", &CXXUnresolvedConstructExpr::BeginToken)
    .def_prop_ro("end_token", &CXXUnresolvedConstructExpr::EndToken)
    .def_prop_ro("l_paren_token", &CXXUnresolvedConstructExpr::LParenToken)
    .def_prop_ro("num_arguments", &CXXUnresolvedConstructExpr::NumArguments)
    .def_prop_ro("r_paren_token", &CXXUnresolvedConstructExpr::RParenToken)
    .def_prop_ro("type_as_written", &CXXUnresolvedConstructExpr::TypeAsWritten)
    .def_prop_ro("is_list_initialization", &CXXUnresolvedConstructExpr::IsListInitialization);
}
} // namespace pasta
