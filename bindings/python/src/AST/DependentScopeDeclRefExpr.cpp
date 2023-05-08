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

void RegisterDependentScopeDeclRefExpr(py::module_ &m) {
  py::class_<DependentScopeDeclRefExpr, Expr>(m, "DependentScopeDeclRefExpr")
    .def("__hash__", [](const DependentScopeDeclRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DependentScopeDeclRefExpr& a, const DependentScopeDeclRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &DependentScopeDeclRefExpr::Children)
    .def_property_readonly("BeginToken", &DependentScopeDeclRefExpr::BeginToken)
    .def_property_readonly("EndToken", &DependentScopeDeclRefExpr::EndToken)
    .def_property_readonly("LAngleToken", &DependentScopeDeclRefExpr::LAngleToken)
    .def_property_readonly("NumTemplateArguments", &DependentScopeDeclRefExpr::NumTemplateArguments)
    .def_property_readonly("RAngleToken", &DependentScopeDeclRefExpr::RAngleToken)
    .def_property_readonly("TemplateKeywordToken", &DependentScopeDeclRefExpr::TemplateKeywordToken)
    .def_property_readonly("HasExplicitTemplateArguments", &DependentScopeDeclRefExpr::HasExplicitTemplateArguments)
    .def_property_readonly("HasTemplateKeyword", &DependentScopeDeclRefExpr::HasTemplateKeyword);
}
} // namespace pasta
