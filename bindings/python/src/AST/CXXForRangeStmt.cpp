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

void RegisterCXXForRangeStmt(py::module_ &m) {
  py::class_<CXXForRangeStmt, Stmt>(m, "CXXForRangeStmt")
    .def_property_readonly("Children", &CXXForRangeStmt::Children)
    .def_property_readonly("BeginToken", &CXXForRangeStmt::BeginToken)
    .def_property_readonly("BeginStatement", &CXXForRangeStmt::BeginStatement)
    .def_property_readonly("Body", &CXXForRangeStmt::Body)
    .def_property_readonly("CoawaitToken", &CXXForRangeStmt::CoawaitToken)
    .def_property_readonly("ColonToken", &CXXForRangeStmt::ColonToken)
    .def_property_readonly("Condition", &CXXForRangeStmt::Condition)
    .def_property_readonly("EndToken", &CXXForRangeStmt::EndToken)
    .def_property_readonly("EndStatement", &CXXForRangeStmt::EndStatement)
    .def_property_readonly("ForToken", &CXXForRangeStmt::ForToken)
    .def_property_readonly("Increment", &CXXForRangeStmt::Increment)
    .def_property_readonly("Initializer", &CXXForRangeStmt::Initializer)
    .def_property_readonly("LoopVariableStatement", &CXXForRangeStmt::LoopVariableStatement)
    .def_property_readonly("LoopVariable", &CXXForRangeStmt::LoopVariable)
    .def_property_readonly("RParenToken", &CXXForRangeStmt::RParenToken)
    .def_property_readonly("RangeInitializer", &CXXForRangeStmt::RangeInitializer)
    .def_property_readonly("RangeStatement", &CXXForRangeStmt::RangeStatement);
}
} // namespace pasta
