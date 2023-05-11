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

void RegisterGotoStmt(py::module_ &m) {
  py::class_<GotoStmt, Stmt>(m, "GotoStmt")
    .def("__hash__", [](const GotoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &GotoStmt::Children)
    .def_property_readonly("begin_token", &GotoStmt::BeginToken)
    .def_property_readonly("end_token", &GotoStmt::EndToken)
    .def_property_readonly("goto_token", &GotoStmt::GotoToken)
    .def_property_readonly("label", &GotoStmt::Label)
    .def_property_readonly("label_token", &GotoStmt::LabelToken);
}
} // namespace pasta
