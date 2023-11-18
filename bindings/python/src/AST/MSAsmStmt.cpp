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

void RegisterMSAsmStmt(nb::module_ &m) {
  nb::class_<MSAsmStmt, AsmStmt>(m, "MSAsmStmt")
    .def_prop_ro("children", &MSAsmStmt::Children)
    .def_prop_ro("generate_assembly_string", &MSAsmStmt::GenerateAssemblyString)
    .def_prop_ro("all_constraints", &MSAsmStmt::AllConstraints)
    .def_prop_ro("all_expressions", &MSAsmStmt::AllExpressions)
    .def_prop_ro("assembly_string", &MSAsmStmt::AssemblyString)
    .def_prop_ro("begin_token", &MSAsmStmt::BeginToken)
    .def_prop_ro("clobbers", &MSAsmStmt::Clobbers)
    .def_prop_ro("end_token", &MSAsmStmt::EndToken)
    .def_prop_ro("l_brace_token", &MSAsmStmt::LBraceToken)
    .def_prop_ro("has_braces", &MSAsmStmt::HasBraces);
}
} // namespace pasta
