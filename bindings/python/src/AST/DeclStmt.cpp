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

void RegisterDeclStmt(py::module_ &m) {
  py::class_<DeclStmt, Stmt>(m, "DeclStmt")
    .def("__hash__", [](const DeclStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &DeclStmt::Children)
    .def_property_readonly("declarations", &DeclStmt::Declarations)
    .def_property_readonly("begin_token", &DeclStmt::BeginToken)
    .def_property_readonly("end_token", &DeclStmt::EndToken)
    .def_property_readonly("single_declaration", &DeclStmt::SingleDeclaration)
    .def_property_readonly("is_single_declaration", &DeclStmt::IsSingleDeclaration);
}
} // namespace pasta
