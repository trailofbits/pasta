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
  py::class_<OverloadExpr, Expr>(m, "OverloadExpr")
    .def("__hash__", [](const OverloadExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OverloadExpr& a, const OverloadExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("l_angle_token", &OverloadExpr::LAngleToken)
    .def_property_readonly("name_token", &OverloadExpr::NameToken)
    .def_property_readonly("naming_class", &OverloadExpr::NamingClass)
    .def_property_readonly("num_declarations", &OverloadExpr::NumDeclarations)
    .def_property_readonly("num_template_arguments", &OverloadExpr::NumTemplateArguments)
    .def_property_readonly("r_angle_token", &OverloadExpr::RAngleToken)
    .def_property_readonly("template_keyword_token", &OverloadExpr::TemplateKeywordToken)
    .def_property_readonly("has_explicit_template_arguments", &OverloadExpr::HasExplicitTemplateArguments)
    .def_property_readonly("has_template_keyword", &OverloadExpr::HasTemplateKeyword);
}
} // namespace pasta
