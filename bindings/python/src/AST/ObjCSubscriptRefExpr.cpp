/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterObjCSubscriptRefExpr(nb::module_ &m) {
  nb::class_<ObjCSubscriptRefExpr, Expr>(m, "ObjCSubscriptRefExpr")
    .def("__hash__", [](const ObjCSubscriptRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCSubscriptRefExpr::Children)
    .def_prop_ro("at_index_method_declaration", &ObjCSubscriptRefExpr::AtIndexMethodDeclaration)
    .def_prop_ro("base_expression", &ObjCSubscriptRefExpr::BaseExpression)
    .def_prop_ro("begin_token", &ObjCSubscriptRefExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCSubscriptRefExpr::EndToken)
    .def_prop_ro("key_expression", &ObjCSubscriptRefExpr::KeyExpression)
    .def_prop_ro("r_bracket_token", &ObjCSubscriptRefExpr::RBracketToken)
    .def_prop_ro("is_array_subscript_reference_expression", &ObjCSubscriptRefExpr::IsArraySubscriptReferenceExpression);
}
} // namespace pasta
