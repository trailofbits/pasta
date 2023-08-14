/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterIndirectGotoStmt(nb::module_ &m) {
  nb::class_<IndirectGotoStmt, Stmt>(m, "IndirectGotoStmt")
    .def("__hash__", [](const IndirectGotoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &IndirectGotoStmt::Children)
    .def_prop_ro("begin_token", &IndirectGotoStmt::BeginToken)
    .def_prop_ro("constant_target", &IndirectGotoStmt::ConstantTarget)
    .def_prop_ro("end_token", &IndirectGotoStmt::EndToken)
    .def_prop_ro("goto_token", &IndirectGotoStmt::GotoToken)
    .def_prop_ro("star_token", &IndirectGotoStmt::StarToken)
    .def_prop_ro("target", &IndirectGotoStmt::Target);
}
} // namespace pasta
