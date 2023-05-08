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

void RegisterUnresolvedUsingTypenameDecl(py::module_ &m) {
  py::class_<UnresolvedUsingTypenameDecl, TypeDecl>(m, "UnresolvedUsingTypenameDecl")
    .def("__hash__", [](const UnresolvedUsingTypenameDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UnresolvedUsingTypenameDecl& a, const UnresolvedUsingTypenameDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &UnresolvedUsingTypenameDecl::CanonicalDeclaration)
    .def_property_readonly("ellipsis_token", &UnresolvedUsingTypenameDecl::EllipsisToken)
    .def_property_readonly("typename_token", &UnresolvedUsingTypenameDecl::TypenameToken)
    .def_property_readonly("using_token", &UnresolvedUsingTypenameDecl::UsingToken)
    .def_property_readonly("is_pack_expansion", &UnresolvedUsingTypenameDecl::IsPackExpansion);
}
} // namespace pasta
