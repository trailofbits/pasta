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
    .def("__hash__", [](const LinkageSpecDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const LinkageSpecDecl& a, const LinkageSpecDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("end_token", &LinkageSpecDecl::EndToken)
    .def_property_readonly("extern_token", &LinkageSpecDecl::ExternToken)
    .def_property_readonly("language", &LinkageSpecDecl::Language)
    .def_property_readonly("r_brace_token", &LinkageSpecDecl::RBraceToken)
    .def_property_readonly("has_braces", &LinkageSpecDecl::HasBraces);
}
} // namespace pasta
