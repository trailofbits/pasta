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

void RegisterAsmStmt(py::module_ &m) {
  py::class_<AsmStmt, Stmt>(m, "AsmStmt")
    .def_property_readonly("Children", &AsmStmt::Children)
    .def("GenerateAssemblyString", &AsmStmt::GenerateAssemblyString)
    .def_property_readonly("AssemblyToken", &AsmStmt::AssemblyToken)
    .def_property_readonly("BeginToken", &AsmStmt::BeginToken)
    .def_property_readonly("EndToken", &AsmStmt::EndToken)
    .def_property_readonly("NumClobbers", &AsmStmt::NumClobbers)
    .def_property_readonly("NumInputs", &AsmStmt::NumInputs)
    .def_property_readonly("NumOutputs", &AsmStmt::NumOutputs)
    .def_property_readonly("NumPlusOperands", &AsmStmt::NumPlusOperands)
    .def_property_readonly("Inputs", &AsmStmt::Inputs)
    .def_property_readonly("IsSimple", &AsmStmt::IsSimple)
    .def_property_readonly("IsVolatile", &AsmStmt::IsVolatile)
    .def_property_readonly("Outputs", &AsmStmt::Outputs);
}
} // namespace pasta
