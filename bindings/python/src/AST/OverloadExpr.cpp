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

void RegisterOverloadExpr(py::module_ &m) {
  py::class_<OverloadExpr, Expr, Stmt, ValueStmt>(m, "OverloadExpr")
    .def_property_readonly("LAngleToken", &OverloadExpr::LAngleToken)
    .def_property_readonly("NameToken", &OverloadExpr::NameToken)
    .def_property_readonly("NamingClass", &OverloadExpr::NamingClass)
    .def_property_readonly("NumDeclarations", &OverloadExpr::NumDeclarations)
    .def_property_readonly("NumTemplateArguments", &OverloadExpr::NumTemplateArguments)
    .def_property_readonly("RAngleToken", &OverloadExpr::RAngleToken)
    .def_property_readonly("TemplateKeywordToken", &OverloadExpr::TemplateKeywordToken)
    .def_property_readonly("HasExplicitTemplateArguments", &OverloadExpr::HasExplicitTemplateArguments)
    .def_property_readonly("HasTemplateKeyword", &OverloadExpr::HasTemplateKeyword);
}
} // namespace pasta
