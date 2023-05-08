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

void RegisterSubstNonTypeTemplateParmExpr(py::module_ &m) {
  py::class_<SubstNonTypeTemplateParmExpr, Expr>(m, "SubstNonTypeTemplateParmExpr")
    .def("__hash__", [](const SubstNonTypeTemplateParmExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SubstNonTypeTemplateParmExpr& a, const SubstNonTypeTemplateParmExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &SubstNonTypeTemplateParmExpr::Children)
    .def_property_readonly("associated_declaration", &SubstNonTypeTemplateParmExpr::AssociatedDeclaration)
    .def_property_readonly("begin_token", &SubstNonTypeTemplateParmExpr::BeginToken)
    .def_property_readonly("end_token", &SubstNonTypeTemplateParmExpr::EndToken)
    .def_property_readonly("index", &SubstNonTypeTemplateParmExpr::Index)
    .def_property_readonly("name_token", &SubstNonTypeTemplateParmExpr::NameToken)
    .def_property_readonly("pack_index", &SubstNonTypeTemplateParmExpr::PackIndex)
    .def_property_readonly("parameter", &SubstNonTypeTemplateParmExpr::Parameter)
    .def("parameter_type", &SubstNonTypeTemplateParmExpr::ParameterType)
    .def_property_readonly("replacement", &SubstNonTypeTemplateParmExpr::Replacement)
    .def_property_readonly("is_reference_parameter", &SubstNonTypeTemplateParmExpr::IsReferenceParameter);
}
} // namespace pasta
