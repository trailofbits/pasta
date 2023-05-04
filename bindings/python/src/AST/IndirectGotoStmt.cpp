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

void RegisterIndirectGotoStmt(py::module_ &m) {
  py::class_<IndirectGotoStmt, Stmt>(m, "IndirectGotoStmt")
    .def_property_readonly("Children", &IndirectGotoStmt::Children)
    .def_property_readonly("BeginToken", &IndirectGotoStmt::BeginToken)
    .def_property_readonly("ConstantTarget", &IndirectGotoStmt::ConstantTarget)
    .def_property_readonly("EndToken", &IndirectGotoStmt::EndToken)
    .def_property_readonly("GotoToken", &IndirectGotoStmt::GotoToken)
    .def_property_readonly("StarToken", &IndirectGotoStmt::StarToken)
    .def_property_readonly("Target", &IndirectGotoStmt::Target);
}
} // namespace pasta
