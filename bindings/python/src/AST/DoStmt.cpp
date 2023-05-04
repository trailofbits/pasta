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

void RegisterDoStmt(py::module_ &m) {
  py::class_<DoStmt, Stmt>(m, "DoStmt")
    .def_property_readonly("Children", &DoStmt::Children)
    .def_property_readonly("BeginToken", &DoStmt::BeginToken)
    .def_property_readonly("Body", &DoStmt::Body)
    .def_property_readonly("Condition", &DoStmt::Condition)
    .def_property_readonly("DoToken", &DoStmt::DoToken)
    .def_property_readonly("EndToken", &DoStmt::EndToken)
    .def_property_readonly("RParenToken", &DoStmt::RParenToken)
    .def_property_readonly("WhileToken", &DoStmt::WhileToken);
}
} // namespace pasta
