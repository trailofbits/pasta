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

void RegisterGotoStmt(py::module_ &m) {
  py::class_<GotoStmt, Stmt>(m, "GotoStmt")
    .def("__hash__", [](const GotoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const GotoStmt& a, const GotoStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &GotoStmt::Children)
    .def_property_readonly("BeginToken", &GotoStmt::BeginToken)
    .def_property_readonly("EndToken", &GotoStmt::EndToken)
    .def_property_readonly("GotoToken", &GotoStmt::GotoToken)
    .def_property_readonly("Label", &GotoStmt::Label)
    .def_property_readonly("LabelToken", &GotoStmt::LabelToken);
}
} // namespace pasta
