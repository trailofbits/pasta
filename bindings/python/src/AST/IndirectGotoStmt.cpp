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

void RegisterIndirectGotoStmt(py::module_ &m) {
  py::class_<IndirectGotoStmt, Stmt>(m, "IndirectGotoStmt")
    .def("__hash__", [](const IndirectGotoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &IndirectGotoStmt::Children)
    .def_property_readonly("begin_token", &IndirectGotoStmt::BeginToken)
    .def_property_readonly("constant_target", &IndirectGotoStmt::ConstantTarget)
    .def_property_readonly("end_token", &IndirectGotoStmt::EndToken)
    .def_property_readonly("goto_token", &IndirectGotoStmt::GotoToken)
    .def_property_readonly("star_token", &IndirectGotoStmt::StarToken)
    .def_property_readonly("target", &IndirectGotoStmt::Target);
}
} // namespace pasta
