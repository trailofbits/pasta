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

void RegisterDefaultStmt(py::module_ &m) {
  py::class_<DefaultStmt, Stmt, SwitchCase>(m, "DefaultStmt")
    .def_property_readonly("Children", &DefaultStmt::Children)
    .def_property_readonly("BeginToken", &DefaultStmt::BeginToken)
    .def_property_readonly("DefaultToken", &DefaultStmt::DefaultToken)
    .def_property_readonly("EndToken", &DefaultStmt::EndToken)
    .def_property_readonly("SubStatement", &DefaultStmt::SubStatement);
}
} // namespace pasta
