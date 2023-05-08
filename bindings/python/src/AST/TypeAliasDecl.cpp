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

void RegisterTypeAliasDecl(py::module_ &m) {
  py::class_<TypeAliasDecl, TypedefNameDecl>(m, "TypeAliasDecl")
    .def("__hash__", [](const TypeAliasDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TypeAliasDecl& a, const TypeAliasDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("described_alias_template", &TypeAliasDecl::DescribedAliasTemplate);
}
} // namespace pasta
