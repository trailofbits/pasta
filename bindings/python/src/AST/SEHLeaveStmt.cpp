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

void RegisterSEHLeaveStmt(py::module_ &m) {
  py::class_<SEHLeaveStmt, Stmt>(m, "SEHLeaveStmt")
    .def("__hash__", [](const SEHLeaveStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SEHLeaveStmt& a, const SEHLeaveStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &SEHLeaveStmt::Children)
    .def_property_readonly("begin_token", &SEHLeaveStmt::BeginToken)
    .def_property_readonly("end_token", &SEHLeaveStmt::EndToken)
    .def_property_readonly("leave_token", &SEHLeaveStmt::LeaveToken);
}
} // namespace pasta
