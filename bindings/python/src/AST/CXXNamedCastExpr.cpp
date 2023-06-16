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

void RegisterCXXNamedCastExpr(nb::module_ &m) {
  nb::class_<CXXNamedCastExpr, ExplicitCastExpr>(m, "CXXNamedCastExpr")
    .def("__hash__", [](const CXXNamedCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("angle_brackets", &CXXNamedCastExpr::AngleBrackets)
    .def_prop_ro("begin_token", &CXXNamedCastExpr::BeginToken)
    .def_prop_ro("cast_name", &CXXNamedCastExpr::CastName)
    .def_prop_ro("end_token", &CXXNamedCastExpr::EndToken)
    .def_prop_ro("operator_token", &CXXNamedCastExpr::OperatorToken)
    .def_prop_ro("r_paren_token", &CXXNamedCastExpr::RParenToken);
}
} // namespace pasta
