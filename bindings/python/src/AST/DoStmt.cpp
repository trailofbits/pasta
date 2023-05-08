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
    .def("__hash__", [](const DoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DoStmt& a, const DoStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &DoStmt::Children)
    .def_property_readonly("begin_token", &DoStmt::BeginToken)
    .def_property_readonly("body", &DoStmt::Body)
    .def_property_readonly("condition", &DoStmt::Condition)
    .def_property_readonly("do_token", &DoStmt::DoToken)
    .def_property_readonly("end_token", &DoStmt::EndToken)
    .def_property_readonly("r_paren_token", &DoStmt::RParenToken)
    .def_property_readonly("while_token", &DoStmt::WhileToken);
}
} // namespace pasta
