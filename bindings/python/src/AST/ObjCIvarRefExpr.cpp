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

void RegisterObjCIvarRefExpr(nb::module_ &m) {
  nb::class_<ObjCIvarRefExpr, Expr>(m, "ObjCIvarRefExpr")
    .def("__hash__", [](const ObjCIvarRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCIvarRefExpr::Children)
    .def_prop_ro("base", &ObjCIvarRefExpr::Base)
    .def_prop_ro("begin_token", &ObjCIvarRefExpr::BeginToken)
    .def_prop_ro("declaration", &ObjCIvarRefExpr::Declaration)
    .def_prop_ro("end_token", &ObjCIvarRefExpr::EndToken)
    .def_prop_ro("token", &ObjCIvarRefExpr::Token)
    .def_prop_ro("operation_token", &ObjCIvarRefExpr::OperationToken)
    .def_prop_ro("is_arrow", &ObjCIvarRefExpr::IsArrow)
    .def_prop_ro("is_free_instance_variable", &ObjCIvarRefExpr::IsFreeInstanceVariable);
}
} // namespace pasta
