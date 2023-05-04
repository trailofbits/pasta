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

void RegisterExportDecl(py::module_ &m) {
  py::class_<ExportDecl, Decl>(m, "ExportDecl")
    .def_property_readonly("EndToken", &ExportDecl::EndToken)
    .def_property_readonly("ExportToken", &ExportDecl::ExportToken)
    .def_property_readonly("RBraceToken", &ExportDecl::RBraceToken)
    .def_property_readonly("HasBraces", &ExportDecl::HasBraces);
}
} // namespace pasta
