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

void RegisterTypeAliasTemplateDecl(py::module_ &m) {
  py::class_<TypeAliasTemplateDecl, Decl, NamedDecl, RedeclarableTemplateDecl, TemplateDecl>(m, "TypeAliasTemplateDecl")
    .def_property_readonly("CanonicalDeclaration", &TypeAliasTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("InstantiatedFromMemberTemplate", &TypeAliasTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("PreviousDeclaration", &TypeAliasTemplateDecl::PreviousDeclaration)
    .def_property_readonly("TemplatedDeclaration", &TypeAliasTemplateDecl::TemplatedDeclaration);
}
} // namespace pasta
