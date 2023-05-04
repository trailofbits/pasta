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

void RegisterBreakStmt(py::module_ &m) {
  py::class_<BreakStmt, Stmt>(m, "BreakStmt")
    .def_property_readonly("Children", &BreakStmt::Children)
    .def_property_readonly("BeginToken", &BreakStmt::BeginToken)
    .def_property_readonly("BreakToken", &BreakStmt::BreakToken)
    .def_property_readonly("EndToken", &BreakStmt::EndToken);
}
} // namespace pasta
