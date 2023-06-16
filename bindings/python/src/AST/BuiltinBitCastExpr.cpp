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

void RegisterBuiltinBitCastExpr(nb::module_ &m) {
  nb::class_<BuiltinBitCastExpr, ExplicitCastExpr>(m, "BuiltinBitCastExpr")
    .def("__hash__", [](const BuiltinBitCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &BuiltinBitCastExpr::BeginToken)
    .def_prop_ro("end_token", &BuiltinBitCastExpr::EndToken);
}
} // namespace pasta
