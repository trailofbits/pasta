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

void RegisterSourceLocExpr(py::module_ &m) {
  py::class_<SourceLocExpr, Expr, Stmt, ValueStmt>(m, "SourceLocExpr")
    .def_property_readonly("Children", &SourceLocExpr::Children)
    .def_property_readonly("BeginToken", &SourceLocExpr::BeginToken)
    .def_property_readonly("BuiltinString", &SourceLocExpr::BuiltinString)
    .def_property_readonly("EndToken", &SourceLocExpr::EndToken)
    .def_property_readonly("IdentifierKind", &SourceLocExpr::IdentifierKind)
    .def_property_readonly("Token", &SourceLocExpr::Token)
    .def_property_readonly("ParentContext", &SourceLocExpr::ParentContext)
    .def_property_readonly("IsIntType", &SourceLocExpr::IsIntType);
}
} // namespace pasta
