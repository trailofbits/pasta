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

void RegisterClassTemplateSpecializationDecl(py::module_ &m) {
  py::class_<ClassTemplateSpecializationDecl, CXXRecordDecl>(m, "ClassTemplateSpecializationDecl")
    .def("__hash__", [](const ClassTemplateSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ClassTemplateSpecializationDecl& a, const ClassTemplateSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("extern_token", &ClassTemplateSpecializationDecl::ExternToken)
    .def_property_readonly("instantiated_from", &ClassTemplateSpecializationDecl::InstantiatedFrom)
    .def_property_readonly("point_of_instantiation", &ClassTemplateSpecializationDecl::PointOfInstantiation)
    .def_property_readonly("specialization_kind", &ClassTemplateSpecializationDecl::SpecializationKind)
    .def_property_readonly("specialized_template", &ClassTemplateSpecializationDecl::SpecializedTemplate)
    .def_property_readonly("specialized_template_or_partial", &ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial)
    .def_property_readonly("template_arguments", &ClassTemplateSpecializationDecl::TemplateArguments)
    .def_property_readonly("template_instantiation_arguments", &ClassTemplateSpecializationDecl::TemplateInstantiationArguments)
    .def_property_readonly("template_keyword_token", &ClassTemplateSpecializationDecl::TemplateKeywordToken)
    .def_property_readonly("type_as_written", &ClassTemplateSpecializationDecl::TypeAsWritten)
    .def_property_readonly("is_class_scope_explicit_specialization", &ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization)
    .def_property_readonly("is_explicit_instantiation_or_specialization", &ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization)
    .def_property_readonly("is_explicit_specialization", &ClassTemplateSpecializationDecl::IsExplicitSpecialization);
}
} // namespace pasta
