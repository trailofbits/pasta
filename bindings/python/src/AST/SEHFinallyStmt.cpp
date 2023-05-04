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

void RegisterSEHFinallyStmt(py::module_ &m) {
  py::class_<SEHFinallyStmt, Stmt>(m, "SEHFinallyStmt")
    .def("__hash__", [](const SEHFinallyStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SEHFinallyStmt& a, const SEHFinallyStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &SEHFinallyStmt::Children)
    .def_property_readonly("BeginToken", &SEHFinallyStmt::BeginToken)
    .def_property_readonly("Block", &SEHFinallyStmt::Block)
    .def_property_readonly("EndToken", &SEHFinallyStmt::EndToken)
    .def_property_readonly("FinallyToken", &SEHFinallyStmt::FinallyToken);
}
} // namespace pasta