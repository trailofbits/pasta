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

void RegisterCXXDefaultInitExpr(nb::module_ &m) {
  nb::class_<CXXDefaultInitExpr, Expr>(m, "CXXDefaultInitExpr")
    .def("__hash__", [](const CXXDefaultInitExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXDefaultInitExpr::Children)
    .def_prop_ro("begin_token", &CXXDefaultInitExpr::BeginToken)
    .def_prop_ro("end_token", &CXXDefaultInitExpr::EndToken)
    .def_prop_ro("expression", &CXXDefaultInitExpr::Expression)
    .def_prop_ro("field", &CXXDefaultInitExpr::Field)
    .def_prop_ro("rewritten_expression", &CXXDefaultInitExpr::RewrittenExpression)
    .def_prop_ro("used_context", &CXXDefaultInitExpr::UsedContext)
    .def_prop_ro("used_token", &CXXDefaultInitExpr::UsedToken)
    .def_prop_ro("has_rewritten_initializer", &CXXDefaultInitExpr::HasRewrittenInitializer);
}
} // namespace pasta
