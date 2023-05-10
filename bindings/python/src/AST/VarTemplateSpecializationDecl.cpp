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

void RegisterVarTemplateSpecializationDecl(py::module_ &m) {
  py::class_<VarTemplateSpecializationDecl, VarDecl>(m, "VarTemplateSpecializationDecl")
    .def("__hash__", [](const VarTemplateSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const VarTemplateSpecializationDecl& a, const VarTemplateSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("extern_token", &VarTemplateSpecializationDecl::ExternToken)
    .def_property_readonly("instantiated_from", &VarTemplateSpecializationDecl::InstantiatedFrom)
    .def_property_readonly("point_of_instantiation", &VarTemplateSpecializationDecl::PointOfInstantiation)
    .def_property_readonly("specialization_kind", &VarTemplateSpecializationDecl::SpecializationKind)
    .def_property_readonly("specialized_template", &VarTemplateSpecializationDecl::SpecializedTemplate)
    .def_property_readonly("specialized_template_or_partial", &VarTemplateSpecializationDecl::SpecializedTemplateOrPartial)
    .def_property_readonly("template_arguments", &VarTemplateSpecializationDecl::TemplateArguments)
    .def_property_readonly("template_instantiation_arguments", &VarTemplateSpecializationDecl::TemplateInstantiationArguments)
    .def_property_readonly("template_keyword_token", &VarTemplateSpecializationDecl::TemplateKeywordToken)
    .def_property_readonly("type_as_written", &VarTemplateSpecializationDecl::TypeAsWritten)
    .def_property_readonly("is_class_scope_explicit_specialization", &VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization)
    .def_property_readonly("is_explicit_instantiation_or_specialization", &VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization)
    .def_property_readonly("is_explicit_specialization", &VarTemplateSpecializationDecl::IsExplicitSpecialization);
}
} // namespace pasta
