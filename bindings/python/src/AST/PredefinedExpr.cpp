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

void RegisterPredefinedExpr(nb::module_ &m) {
  nb::class_<PredefinedExpr, Expr>(m, "PredefinedExpr")
    .def("__hash__", [](const PredefinedExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &PredefinedExpr::Children)
    .def_prop_ro("begin_token", &PredefinedExpr::BeginToken)
    .def_prop_ro("end_token", &PredefinedExpr::EndToken)
    .def_prop_ro("function_name", &PredefinedExpr::FunctionName)
    .def_prop_ro("identifier_kind", &PredefinedExpr::IdentifierKind)
    .def_prop_ro("identifier_kind_name", &PredefinedExpr::IdentifierKindName)
    .def_prop_ro("token", &PredefinedExpr::Token)
    .def_prop_ro("is_transparent", &PredefinedExpr::IsTransparent);
}
} // namespace pasta
