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

void RegisterClassTemplatePartialSpecializationDecl(py::module_ &m) {
  py::class_<ClassTemplatePartialSpecializationDecl, ClassTemplateSpecializationDecl>(m, "ClassTemplatePartialSpecializationDecl")
    .def("__hash__", [](const ClassTemplatePartialSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ClassTemplatePartialSpecializationDecl& a, const ClassTemplatePartialSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("injected_specialization_type", &ClassTemplatePartialSpecializationDecl::InjectedSpecializationType)
    .def_property_readonly("instantiated_from_member", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMember)
    .def_property_readonly("instantiated_from_member_template", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("template_parameters", &ClassTemplatePartialSpecializationDecl::TemplateParameters)
    .def_property_readonly("has_associated_constraints", &ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints);
}
} // namespace pasta
