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

void RegisterGCCAsmStmt(py::module_ &m) {
  py::class_<GCCAsmStmt, AsmStmt>(m, "GCCAsmStmt")
    .def("__hash__", [](const GCCAsmStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def("generate_assembly_string", &GCCAsmStmt::GenerateAssemblyString)
    .def_property_readonly("assembly_string", &GCCAsmStmt::AssemblyString)
    .def_property_readonly("begin_token", &GCCAsmStmt::BeginToken)
    .def_property_readonly("end_token", &GCCAsmStmt::EndToken)
    .def_property_readonly("num_labels", &GCCAsmStmt::NumLabels)
    .def_property_readonly("r_paren_token", &GCCAsmStmt::RParenToken)
    .def_property_readonly("is_assembly_goto", &GCCAsmStmt::IsAssemblyGoto)
    .def_property_readonly("labels", &GCCAsmStmt::Labels);
}
} // namespace pasta
