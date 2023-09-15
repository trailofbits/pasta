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

void RegisterFixedPointLiteral(nb::module_ &m) {
  nb::class_<FixedPointLiteral, Expr>(m, "FixedPointLiteral")
    .def("__hash__", [](const FixedPointLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &FixedPointLiteral::Children)
    .def_prop_ro("begin_token", &FixedPointLiteral::BeginToken)
    .def_prop_ro("end_token", &FixedPointLiteral::EndToken)
    .def_prop_ro("token", &FixedPointLiteral::Token)
    .def_prop_ro("scale", &FixedPointLiteral::Scale);
}
} // namespace pasta
