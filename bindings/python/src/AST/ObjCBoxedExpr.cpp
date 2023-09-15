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

void RegisterObjCBoxedExpr(nb::module_ &m) {
  nb::class_<ObjCBoxedExpr, Expr>(m, "ObjCBoxedExpr")
    .def("__hash__", [](const ObjCBoxedExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCBoxedExpr::Children)
    .def_prop_ro("at_token", &ObjCBoxedExpr::AtToken)
    .def_prop_ro("begin_token", &ObjCBoxedExpr::BeginToken)
    .def_prop_ro("boxing_method", &ObjCBoxedExpr::BoxingMethod)
    .def_prop_ro("end_token", &ObjCBoxedExpr::EndToken)
    .def_prop_ro("tokens", &ObjCBoxedExpr::Tokens)
    .def_prop_ro("sub_expression", &ObjCBoxedExpr::SubExpression)
    .def_prop_ro("is_expressible_as_constant_initializer", &ObjCBoxedExpr::IsExpressibleAsConstantInitializer);
}
} // namespace pasta
