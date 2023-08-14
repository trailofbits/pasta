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

void RegisterSEHLeaveStmt(nb::module_ &m) {
  nb::class_<SEHLeaveStmt, Stmt>(m, "SEHLeaveStmt")
    .def("__hash__", [](const SEHLeaveStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &SEHLeaveStmt::Children)
    .def_prop_ro("begin_token", &SEHLeaveStmt::BeginToken)
    .def_prop_ro("end_token", &SEHLeaveStmt::EndToken)
    .def_prop_ro("leave_token", &SEHLeaveStmt::LeaveToken);
}
} // namespace pasta
