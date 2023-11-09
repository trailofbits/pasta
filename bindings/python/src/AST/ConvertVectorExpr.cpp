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

void RegisterConvertVectorExpr(nb::module_ &m) {
  nb::class_<ConvertVectorExpr, Expr>(m, "ConvertVectorExpr")
    .def("__hash__", [](const ConvertVectorExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ConvertVectorExpr::Children)
    .def_prop_ro("begin_token", &ConvertVectorExpr::BeginToken)
    .def_prop_ro("builtin_token", &ConvertVectorExpr::BuiltinToken)
    .def_prop_ro("end_token", &ConvertVectorExpr::EndToken)
    .def_prop_ro("r_paren_token", &ConvertVectorExpr::RParenToken)
    .def_prop_ro("src_expression", &ConvertVectorExpr::SrcExpression)
    .def_prop_ro("type", &ConvertVectorExpr::Type);
}
} // namespace pasta
