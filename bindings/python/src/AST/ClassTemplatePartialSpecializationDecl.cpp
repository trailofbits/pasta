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

void RegisterClassTemplatePartialSpecializationDecl(py::module_ &m) {
  py::class_<ClassTemplatePartialSpecializationDecl, CXXRecordDecl, ClassTemplateSpecializationDecl, Decl, NamedDecl, RecordDecl, TagDecl, TypeDecl>(m, "ClassTemplatePartialSpecializationDecl")
    .def_property_readonly("InjectedSpecializationType", &ClassTemplatePartialSpecializationDecl::InjectedSpecializationType)
    .def_property_readonly("InstantiatedFromMember", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMember)
    .def_property_readonly("InstantiatedFromMemberTemplate", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("TemplateParameters", &ClassTemplatePartialSpecializationDecl::TemplateParameters)
    .def_property_readonly("HasAssociatedConstraints", &ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints);
}
} // namespace pasta
