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

void RegisterClassTemplateDecl(py::module_ &m) {
  py::class_<ClassTemplateDecl, RedeclarableTemplateDecl>(m, "ClassTemplateDecl")
    .def("__hash__", [](const ClassTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ClassTemplateDecl& a, const ClassTemplateDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &ClassTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("InstantiatedFromMemberTemplate", &ClassTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("MostRecentDeclaration", &ClassTemplateDecl::MostRecentDeclaration)
    .def_property_readonly("PreviousDeclaration", &ClassTemplateDecl::PreviousDeclaration)
    .def_property_readonly("TemplatedDeclaration", &ClassTemplateDecl::TemplatedDeclaration)
    .def_property_readonly("IsThisDeclarationADefinition", &ClassTemplateDecl::IsThisDeclarationADefinition)
    .def_property_readonly("Specializations", &ClassTemplateDecl::Specializations);
}
} // namespace pasta
