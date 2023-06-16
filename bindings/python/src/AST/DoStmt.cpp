/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterDoStmt(nb::module_ &m) {
  nb::class_<DoStmt, Stmt>(m, "DoStmt")
    .def("__hash__", [](const DoStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &DoStmt::Children)
    .def_prop_ro("begin_token", &DoStmt::BeginToken)
    .def_prop_ro("body", &DoStmt::Body)
    .def_prop_ro("condition", &DoStmt::Condition)
    .def_prop_ro("do_token", &DoStmt::DoToken)
    .def_prop_ro("end_token", &DoStmt::EndToken)
    .def_prop_ro("r_paren_token", &DoStmt::RParenToken)
    .def_prop_ro("while_token", &DoStmt::WhileToken);
}
} // namespace pasta
