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

void RegisterCXXStdInitializerListExpr(nb::module_ &m) {
  nb::class_<CXXStdInitializerListExpr, Expr>(m, "CXXStdInitializerListExpr")
    .def("__hash__", [](const CXXStdInitializerListExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXStdInitializerListExpr::Children)
    .def_prop_ro("begin_token", &CXXStdInitializerListExpr::BeginToken)
    .def_prop_ro("end_token", &CXXStdInitializerListExpr::EndToken)
    .def_prop_ro("tokens", &CXXStdInitializerListExpr::Tokens)
    .def_prop_ro("sub_expression", &CXXStdInitializerListExpr::SubExpression);
}
} // namespace pasta
