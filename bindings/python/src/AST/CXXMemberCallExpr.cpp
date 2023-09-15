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

void RegisterCXXMemberCallExpr(nb::module_ &m) {
  nb::class_<CXXMemberCallExpr, CallExpr>(m, "CXXMemberCallExpr")
    .def("__hash__", [](const CXXMemberCallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("expression_token", &CXXMemberCallExpr::ExpressionToken)
    .def_prop_ro("implicit_object_argument", &CXXMemberCallExpr::ImplicitObjectArgument)
    .def_prop_ro("method_declaration", &CXXMemberCallExpr::MethodDeclaration)
    .def_prop_ro("object_type", &CXXMemberCallExpr::ObjectType)
    .def_prop_ro("record_declaration", &CXXMemberCallExpr::RecordDeclaration);
}
} // namespace pasta
