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

void RegisterGotoStmt(nb::module_ &m) {
  nb::class_<GotoStmt, Stmt>(m, "GotoStmt")
    .def("__hash__", [](const GotoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &GotoStmt::Children)
    .def_prop_ro("begin_token", &GotoStmt::BeginToken)
    .def_prop_ro("end_token", &GotoStmt::EndToken)
    .def_prop_ro("goto_token", &GotoStmt::GotoToken)
    .def_prop_ro("label", &GotoStmt::Label)
    .def_prop_ro("label_token", &GotoStmt::LabelToken);
}
} // namespace pasta
