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

void RegisterGCCAsmStmt(py::module_ &m) {
  py::class_<GCCAsmStmt, AsmStmt, Stmt>(m, "GCCAsmStmt")
    .def("__hash__", [](const GCCAsmStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const GCCAsmStmt& a, const GCCAsmStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def("GenerateAssemblyString", &GCCAsmStmt::GenerateAssemblyString)
    .def_property_readonly("AssemblyString", &GCCAsmStmt::AssemblyString)
    .def_property_readonly("BeginToken", &GCCAsmStmt::BeginToken)
    .def_property_readonly("EndToken", &GCCAsmStmt::EndToken)
    .def_property_readonly("NumLabels", &GCCAsmStmt::NumLabels)
    .def_property_readonly("RParenToken", &GCCAsmStmt::RParenToken)
    .def_property_readonly("IsAssemblyGoto", &GCCAsmStmt::IsAssemblyGoto)
    .def_property_readonly("Labels", &GCCAsmStmt::Labels);
}
} // namespace pasta
