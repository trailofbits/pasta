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
  py::class_<MSAsmStmt, AsmStmt, Stmt>(m, "MSAsmStmt")
    .def_property_readonly("Children", &MSAsmStmt::Children)
    .def("GenerateAssemblyString", &MSAsmStmt::GenerateAssemblyString)
    .def_property_readonly("AllConstraints", &MSAsmStmt::AllConstraints)
    .def_property_readonly("AllExpressions", &MSAsmStmt::AllExpressions)
    .def_property_readonly("AssemblyString", &MSAsmStmt::AssemblyString)
    .def_property_readonly("BeginToken", &MSAsmStmt::BeginToken)
    .def_property_readonly("Clobbers", &MSAsmStmt::Clobbers)
    .def_property_readonly("EndToken", &MSAsmStmt::EndToken)
    .def_property_readonly("LBraceToken", &MSAsmStmt::LBraceToken)
    .def_property_readonly("HasBraces", &MSAsmStmt::HasBraces);
}
} // namespace pasta
