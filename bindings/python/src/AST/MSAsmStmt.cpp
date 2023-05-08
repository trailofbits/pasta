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

void RegisterMSAsmStmt(py::module_ &m) {
  py::class_<MSAsmStmt, AsmStmt>(m, "MSAsmStmt")
    .def("__hash__", [](const MSAsmStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MSAsmStmt& a, const MSAsmStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MSAsmStmt::Children)
    .def("generate_assembly_string", &MSAsmStmt::GenerateAssemblyString)
    .def_property_readonly("all_constraints", &MSAsmStmt::AllConstraints)
    .def_property_readonly("all_expressions", &MSAsmStmt::AllExpressions)
    .def_property_readonly("assembly_string", &MSAsmStmt::AssemblyString)
    .def_property_readonly("begin_token", &MSAsmStmt::BeginToken)
    .def_property_readonly("clobbers", &MSAsmStmt::Clobbers)
    .def_property_readonly("end_token", &MSAsmStmt::EndToken)
    .def_property_readonly("l_brace_token", &MSAsmStmt::LBraceToken)
    .def_property_readonly("has_braces", &MSAsmStmt::HasBraces);
}
} // namespace pasta
