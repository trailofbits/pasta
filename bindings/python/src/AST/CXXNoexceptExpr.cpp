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

void RegisterCXXNoexceptExpr(nb::module_ &m) {
  nb::class_<CXXNoexceptExpr, Expr>(m, "CXXNoexceptExpr")
    .def("__hash__", [](const CXXNoexceptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXNoexceptExpr::Children)
    .def_prop_ro("begin_token", &CXXNoexceptExpr::BeginToken)
    .def_prop_ro("end_token", &CXXNoexceptExpr::EndToken)
    .def_prop_ro("operand", &CXXNoexceptExpr::Operand)
    .def_prop_ro("tokens", &CXXNoexceptExpr::Tokens)
    .def_prop_ro("value", &CXXNoexceptExpr::Value);
}
} // namespace pasta
