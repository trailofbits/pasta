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

void RegisterVarTemplateSpecializationDecl(py::module_ &m) {
  py::class_<VarTemplateSpecializationDecl, VarDecl>(m, "VarTemplateSpecializationDecl")
    .def("__hash__", [](const VarTemplateSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const VarTemplateSpecializationDecl& a, const VarTemplateSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("ExternToken", &VarTemplateSpecializationDecl::ExternToken)
    .def_property_readonly("InstantiatedFrom", &VarTemplateSpecializationDecl::InstantiatedFrom)
    .def_property_readonly("PointOfInstantiation", &VarTemplateSpecializationDecl::PointOfInstantiation)
    .def_property_readonly("SpecializationKind", &VarTemplateSpecializationDecl::SpecializationKind)
    .def_property_readonly("SpecializedTemplate", &VarTemplateSpecializationDecl::SpecializedTemplate)
    .def_property_readonly("SpecializedTemplateOrPartial", &VarTemplateSpecializationDecl::SpecializedTemplateOrPartial)
    .def_property_readonly("TemplateArguments", &VarTemplateSpecializationDecl::TemplateArguments)
    .def_property_readonly("TemplateInstantiationArguments", &VarTemplateSpecializationDecl::TemplateInstantiationArguments)
    .def_property_readonly("TemplateKeywordToken", &VarTemplateSpecializationDecl::TemplateKeywordToken)
    .def_property_readonly("TypeAsWritten", &VarTemplateSpecializationDecl::TypeAsWritten)
    .def_property_readonly("IsClassScopeExplicitSpecialization", &VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization)
    .def_property_readonly("IsExplicitInstantiationOrSpecialization", &VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization)
    .def_property_readonly("IsExplicitSpecialization", &VarTemplateSpecializationDecl::IsExplicitSpecialization);
}
} // namespace pasta
