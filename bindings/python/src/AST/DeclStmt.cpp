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

void RegisterDeclStmt(py::module_ &m) {
  py::class_<DeclStmt, Stmt>(m, "DeclStmt")
    .def_property_readonly("Children", &DeclStmt::Children)
    .def_property_readonly("Declarations", &DeclStmt::Declarations)
    .def_property_readonly("BeginToken", &DeclStmt::BeginToken)
    .def_property_readonly("EndToken", &DeclStmt::EndToken)
    .def_property_readonly("SingleDeclaration", &DeclStmt::SingleDeclaration)
    .def_property_readonly("IsSingleDeclaration", &DeclStmt::IsSingleDeclaration);
}
} // namespace pasta
