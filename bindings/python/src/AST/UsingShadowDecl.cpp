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

void RegisterUsingShadowDecl(py::module_ &m) {
  py::class_<UsingShadowDecl, NamedDecl>(m, "UsingShadowDecl")
    .def("__hash__", [](const UsingShadowDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UsingShadowDecl& a, const UsingShadowDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &UsingShadowDecl::CanonicalDeclaration)
    .def_property_readonly("introducer", &UsingShadowDecl::Introducer)
    .def_property_readonly("next_using_shadow_declaration", &UsingShadowDecl::NextUsingShadowDeclaration)
    .def_property_readonly("target_declaration", &UsingShadowDecl::TargetDeclaration);
}
} // namespace pasta
