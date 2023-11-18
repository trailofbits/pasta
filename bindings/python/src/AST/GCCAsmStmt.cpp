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

void RegisterGCCAsmStmt(nb::module_ &m) {
  nb::class_<GCCAsmStmt, AsmStmt>(m, "GCCAsmStmt")
    .def_prop_ro("generate_assembly_string", &GCCAsmStmt::GenerateAssemblyString)
    .def_prop_ro("assembly_string", &GCCAsmStmt::AssemblyString)
    .def_prop_ro("begin_token", &GCCAsmStmt::BeginToken)
    .def_prop_ro("end_token", &GCCAsmStmt::EndToken)
    .def_prop_ro("num_labels", &GCCAsmStmt::NumLabels)
    .def_prop_ro("r_paren_token", &GCCAsmStmt::RParenToken)
    .def_prop_ro("is_assembly_goto", &GCCAsmStmt::IsAssemblyGoto)
    .def_prop_ro("labels", &GCCAsmStmt::Labels);
}
} // namespace pasta
