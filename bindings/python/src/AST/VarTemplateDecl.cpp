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

void RegisterVarTemplateDecl(py::module_ &m) {
  py::class_<VarTemplateDecl, RedeclarableTemplateDecl>(m, "VarTemplateDecl")
    .def("__hash__", [](const VarTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &VarTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("instantiated_from_member_template", &VarTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("most_recent_declaration", &VarTemplateDecl::MostRecentDeclaration)
    .def_property_readonly("previous_declaration", &VarTemplateDecl::PreviousDeclaration)
    .def_property_readonly("templated_declaration", &VarTemplateDecl::TemplatedDeclaration)
    .def_property_readonly("is_this_declaration_a_definition", &VarTemplateDecl::IsThisDeclarationADefinition)
    .def_property_readonly("specializations", &VarTemplateDecl::Specializations);
}
} // namespace pasta
