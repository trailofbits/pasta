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

void RegisterAsmStmt(py::module_ &m) {
  py::class_<AsmStmt, Stmt>(m, "AsmStmt")
    .def("__hash__", [](const AsmStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &AsmStmt::Children)
    .def("generate_assembly_string", &AsmStmt::GenerateAssemblyString)
    .def_property_readonly("assembly_token", &AsmStmt::AssemblyToken)
    .def_property_readonly("begin_token", &AsmStmt::BeginToken)
    .def_property_readonly("end_token", &AsmStmt::EndToken)
    .def_property_readonly("num_clobbers", &AsmStmt::NumClobbers)
    .def_property_readonly("num_inputs", &AsmStmt::NumInputs)
    .def_property_readonly("num_outputs", &AsmStmt::NumOutputs)
    .def_property_readonly("num_plus_operands", &AsmStmt::NumPlusOperands)
    .def_property_readonly("inputs", &AsmStmt::Inputs)
    .def_property_readonly("is_simple", &AsmStmt::IsSimple)
    .def_property_readonly("is_volatile", &AsmStmt::IsVolatile)
    .def_property_readonly("outputs", &AsmStmt::Outputs);
}
} // namespace pasta
