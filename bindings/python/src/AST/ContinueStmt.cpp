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

void RegisterContinueStmt(nb::module_ &m) {
  nb::class_<ContinueStmt, Stmt>(m, "ContinueStmt")
    .def("__hash__", [](const ContinueStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ContinueStmt::Children)
    .def_prop_ro("begin_token", &ContinueStmt::BeginToken)
    .def_prop_ro("continue_token", &ContinueStmt::ContinueToken)
    .def_prop_ro("end_token", &ContinueStmt::EndToken);
}
} // namespace pasta
