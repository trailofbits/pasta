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

void RegisterUserDefinedLiteral(nb::module_ &m) {
  nb::class_<UserDefinedLiteral, CallExpr>(m, "UserDefinedLiteral")
    .def("__hash__", [](const UserDefinedLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &UserDefinedLiteral::BeginToken)
    .def_prop_ro("cooked_literal", &UserDefinedLiteral::CookedLiteral)
    .def_prop_ro("end_token", &UserDefinedLiteral::EndToken)
    .def_prop_ro("literal_operator_kind", &UserDefinedLiteral::LiteralOperatorKind)
    .def_prop_ro("ud_suffix_token", &UserDefinedLiteral::UDSuffixToken);
}
} // namespace pasta
