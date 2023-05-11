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

void RegisterExportDecl(py::module_ &m) {
  py::class_<ExportDecl, Decl>(m, "ExportDecl")
    .def("__hash__", [](const ExportDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("end_token", &ExportDecl::EndToken)
    .def_property_readonly("export_token", &ExportDecl::ExportToken)
    .def_property_readonly("r_brace_token", &ExportDecl::RBraceToken)
    .def_property_readonly("has_braces", &ExportDecl::HasBraces);
}
} // namespace pasta
