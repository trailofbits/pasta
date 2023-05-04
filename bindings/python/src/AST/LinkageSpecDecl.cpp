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

void RegisterLinkageSpecDecl(py::module_ &m) {
  py::class_<LinkageSpecDecl, Decl>(m, "LinkageSpecDecl")
    .def_property_readonly("EndToken", &LinkageSpecDecl::EndToken)
    .def_property_readonly("ExternToken", &LinkageSpecDecl::ExternToken)
    .def_property_readonly("Language", &LinkageSpecDecl::Language)
    .def_property_readonly("RBraceToken", &LinkageSpecDecl::RBraceToken)
    .def_property_readonly("HasBraces", &LinkageSpecDecl::HasBraces);
}
} // namespace pasta
