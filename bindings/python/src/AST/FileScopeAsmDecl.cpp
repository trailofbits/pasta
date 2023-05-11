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

void RegisterFileScopeAsmDecl(py::module_ &m) {
  py::class_<FileScopeAsmDecl, Decl>(m, "FileScopeAsmDecl")
    .def("__hash__", [](const FileScopeAsmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("assembly_token", &FileScopeAsmDecl::AssemblyToken)
    .def_property_readonly("assembly_string", &FileScopeAsmDecl::AssemblyString)
    .def_property_readonly("r_paren_token", &FileScopeAsmDecl::RParenToken);
}
} // namespace pasta
