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

void RegisterTemplateDecl(py::module_ &m) {
  py::class_<TemplateDecl, NamedDecl>(m, "TemplateDecl")
    .def("__hash__", [](const TemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("template_parameters", &TemplateDecl::TemplateParameters)
    .def_property_readonly("templated_declaration", &TemplateDecl::TemplatedDeclaration)
    .def_property_readonly("has_associated_constraints", &TemplateDecl::HasAssociatedConstraints)
    .def_property_readonly("is_type_alias", &TemplateDecl::IsTypeAlias);
}
} // namespace pasta
