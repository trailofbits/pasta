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

void RegisterSEHLeaveStmt(py::module_ &m) {
  py::class_<SEHLeaveStmt, Stmt>(m, "SEHLeaveStmt")
    .def_property_readonly("Children", &SEHLeaveStmt::Children)
    .def_property_readonly("BeginToken", &SEHLeaveStmt::BeginToken)
    .def_property_readonly("EndToken", &SEHLeaveStmt::EndToken)
    .def_property_readonly("LeaveToken", &SEHLeaveStmt::LeaveToken);
}
} // namespace pasta
