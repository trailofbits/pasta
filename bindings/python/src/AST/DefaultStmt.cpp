/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterDefaultStmt(nb::module_ &m) {
  nb::class_<DefaultStmt, SwitchCase>(m, "DefaultStmt")
    .def("__hash__", [](const DefaultStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &DefaultStmt::Children)
    .def_prop_ro("begin_token", &DefaultStmt::BeginToken)
    .def_prop_ro("default_token", &DefaultStmt::DefaultToken)
    .def_prop_ro("end_token", &DefaultStmt::EndToken)
    .def_prop_ro("sub_statement", &DefaultStmt::SubStatement);
}
} // namespace pasta
