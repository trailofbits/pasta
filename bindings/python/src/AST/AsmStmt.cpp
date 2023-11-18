/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterAsmStmt(nb::module_ &m) {
  nb::class_<AsmStmt, Stmt>(m, "AsmStmt")
    .def_prop_ro("children", &AsmStmt::Children)
    .def_prop_ro("generate_assembly_string", &AsmStmt::GenerateAssemblyString)
    .def_prop_ro("assembly_token", &AsmStmt::AssemblyToken)
    .def_prop_ro("begin_token", &AsmStmt::BeginToken)
    .def_prop_ro("end_token", &AsmStmt::EndToken)
    .def_prop_ro("num_clobbers", &AsmStmt::NumClobbers)
    .def_prop_ro("num_inputs", &AsmStmt::NumInputs)
    .def_prop_ro("num_outputs", &AsmStmt::NumOutputs)
    .def_prop_ro("num_plus_operands", &AsmStmt::NumPlusOperands)
    .def_prop_ro("inputs", &AsmStmt::Inputs)
    .def_prop_ro("is_simple", &AsmStmt::IsSimple)
    .def_prop_ro("is_volatile", &AsmStmt::IsVolatile)
    .def_prop_ro("outputs", &AsmStmt::Outputs);
}
} // namespace pasta
