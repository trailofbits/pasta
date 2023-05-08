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

void RegisterTemplateDecl(py::module_ &m) {
  py::class_<TemplateDecl, NamedDecl>(m, "TemplateDecl")
    .def("__hash__", [](const TemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TemplateDecl& a, const TemplateDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("TemplateParameters", &TemplateDecl::TemplateParameters)
    .def_property_readonly("TemplatedDeclaration", &TemplateDecl::TemplatedDeclaration)
    .def_property_readonly("HasAssociatedConstraints", &TemplateDecl::HasAssociatedConstraints)
    .def_property_readonly("IsTypeAlias", &TemplateDecl::IsTypeAlias);
}
} // namespace pasta
