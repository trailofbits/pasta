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
    .def_property_readonly("ExternToken", &ClassTemplateSpecializationDecl::ExternToken)
    .def_property_readonly("InstantiatedFrom", &ClassTemplateSpecializationDecl::InstantiatedFrom)
    .def_property_readonly("PointOfInstantiation", &ClassTemplateSpecializationDecl::PointOfInstantiation)
    .def_property_readonly("SpecializationKind", &ClassTemplateSpecializationDecl::SpecializationKind)
    .def_property_readonly("SpecializedTemplate", &ClassTemplateSpecializationDecl::SpecializedTemplate)
    .def_property_readonly("SpecializedTemplateOrPartial", &ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial)
    .def_property_readonly("TemplateArguments", &ClassTemplateSpecializationDecl::TemplateArguments)
    .def_property_readonly("TemplateInstantiationArguments", &ClassTemplateSpecializationDecl::TemplateInstantiationArguments)
    .def_property_readonly("TemplateKeywordToken", &ClassTemplateSpecializationDecl::TemplateKeywordToken)
    .def_property_readonly("TypeAsWritten", &ClassTemplateSpecializationDecl::TypeAsWritten)
    .def_property_readonly("IsClassScopeExplicitSpecialization", &ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization)
    .def_property_readonly("IsExplicitInstantiationOrSpecialization", &ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization)
    .def_property_readonly("IsExplicitSpecialization", &ClassTemplateSpecializationDecl::IsExplicitSpecialization);
}
} // namespace pasta
