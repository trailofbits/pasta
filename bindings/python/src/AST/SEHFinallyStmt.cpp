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

void RegisterSEHFinallyStmt(nb::module_ &m) {
  nb::class_<SEHFinallyStmt, Stmt>(m, "SEHFinallyStmt")
    .def_prop_ro("children", &SEHFinallyStmt::Children)
    .def_prop_ro("begin_token", &SEHFinallyStmt::BeginToken)
    .def_prop_ro("block", &SEHFinallyStmt::Block)
    .def_prop_ro("end_token", &SEHFinallyStmt::EndToken)
    .def_prop_ro("finally_token", &SEHFinallyStmt::FinallyToken);
}
} // namespace pasta
