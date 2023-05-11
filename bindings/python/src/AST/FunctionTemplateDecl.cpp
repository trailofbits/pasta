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

void RegisterFunctionTemplateDecl(py::module_ &m) {
  py::class_<FunctionTemplateDecl, RedeclarableTemplateDecl>(m, "FunctionTemplateDecl")
    .def("__hash__", [](const FunctionTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &FunctionTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("instantiated_from_member_template", &FunctionTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("most_recent_declaration", &FunctionTemplateDecl::MostRecentDeclaration)
    .def_property_readonly("previous_declaration", &FunctionTemplateDecl::PreviousDeclaration)
    .def_property_readonly("templated_declaration", &FunctionTemplateDecl::TemplatedDeclaration)
    .def_property_readonly("is_abbreviated", &FunctionTemplateDecl::IsAbbreviated)
    .def_property_readonly("is_this_declaration_a_definition", &FunctionTemplateDecl::IsThisDeclarationADefinition)
    .def_property_readonly("specializations", &FunctionTemplateDecl::Specializations);
}
} // namespace pasta
