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

void RegisterCXXForRangeStmt(py::module_ &m) {
  py::class_<CXXForRangeStmt, Stmt>(m, "CXXForRangeStmt")
    .def("__hash__", [](const CXXForRangeStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXForRangeStmt& a, const CXXForRangeStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXForRangeStmt::Children)
    .def_property_readonly("begin_token", &CXXForRangeStmt::BeginToken)
    .def_property_readonly("begin_statement", &CXXForRangeStmt::BeginStatement)
    .def_property_readonly("body", &CXXForRangeStmt::Body)
    .def_property_readonly("coawait_token", &CXXForRangeStmt::CoawaitToken)
    .def_property_readonly("colon_token", &CXXForRangeStmt::ColonToken)
    .def_property_readonly("condition", &CXXForRangeStmt::Condition)
    .def_property_readonly("end_token", &CXXForRangeStmt::EndToken)
    .def_property_readonly("end_statement", &CXXForRangeStmt::EndStatement)
    .def_property_readonly("for_token", &CXXForRangeStmt::ForToken)
    .def_property_readonly("increment", &CXXForRangeStmt::Increment)
    .def_property_readonly("initializer", &CXXForRangeStmt::Initializer)
    .def_property_readonly("loop_variable_statement", &CXXForRangeStmt::LoopVariableStatement)
    .def_property_readonly("loop_variable", &CXXForRangeStmt::LoopVariable)
    .def_property_readonly("r_paren_token", &CXXForRangeStmt::RParenToken)
    .def_property_readonly("range_initializer", &CXXForRangeStmt::RangeInitializer)
    .def_property_readonly("range_statement", &CXXForRangeStmt::RangeStatement);
}
} // namespace pasta
