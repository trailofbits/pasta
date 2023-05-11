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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterDependentScopeDeclRefExpr(py::module_ &m) {
  py::class_<DependentScopeDeclRefExpr, Expr>(m, "DependentScopeDeclRefExpr")
    .def("__hash__", [](const DependentScopeDeclRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &DependentScopeDeclRefExpr::Children)
    .def_property_readonly("begin_token", &DependentScopeDeclRefExpr::BeginToken)
    .def_property_readonly("end_token", &DependentScopeDeclRefExpr::EndToken)
    .def_property_readonly("l_angle_token", &DependentScopeDeclRefExpr::LAngleToken)
    .def_property_readonly("num_template_arguments", &DependentScopeDeclRefExpr::NumTemplateArguments)
    .def_property_readonly("r_angle_token", &DependentScopeDeclRefExpr::RAngleToken)
    .def_property_readonly("template_keyword_token", &DependentScopeDeclRefExpr::TemplateKeywordToken)
    .def_property_readonly("has_explicit_template_arguments", &DependentScopeDeclRefExpr::HasExplicitTemplateArguments)
    .def_property_readonly("has_template_keyword", &DependentScopeDeclRefExpr::HasTemplateKeyword);
}
} // namespace pasta
