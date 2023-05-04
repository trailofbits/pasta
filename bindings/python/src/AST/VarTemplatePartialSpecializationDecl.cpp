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

void RegisterVarTemplatePartialSpecializationDecl(py::module_ &m) {
  py::class_<VarTemplatePartialSpecializationDecl, Decl, DeclaratorDecl, NamedDecl, ValueDecl, VarDecl, VarTemplateSpecializationDecl>(m, "VarTemplatePartialSpecializationDecl")
    .def("__hash__", [](const VarTemplatePartialSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const VarTemplatePartialSpecializationDecl& a, const VarTemplatePartialSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("InstantiatedFromMember", &VarTemplatePartialSpecializationDecl::InstantiatedFromMember)
    .def_property_readonly("TemplateParameters", &VarTemplatePartialSpecializationDecl::TemplateParameters)
    .def_property_readonly("HasAssociatedConstraints", &VarTemplatePartialSpecializationDecl::HasAssociatedConstraints);
}
} // namespace pasta
