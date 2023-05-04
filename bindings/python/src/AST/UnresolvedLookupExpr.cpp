/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterUnresolvedLookupExpr(py::module_ &m) {
  py::class_<UnresolvedLookupExpr, Expr, OverloadExpr, Stmt, ValueStmt>(m, "UnresolvedLookupExpr")
    .def_property_readonly("Children", &UnresolvedLookupExpr::Children)
    .def_property_readonly("BeginToken", &UnresolvedLookupExpr::BeginToken)
    .def_property_readonly("EndToken", &UnresolvedLookupExpr::EndToken)
    .def_property_readonly("NamingClass", &UnresolvedLookupExpr::NamingClass)
    .def_property_readonly("IsOverloaded", &UnresolvedLookupExpr::IsOverloaded)
    .def_property_readonly("RequiresADL", &UnresolvedLookupExpr::RequiresADL);
}
} // namespace pasta
