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

void RegisterExplicitCastExpr(nb::module_ &m) {
  nb::class_<ExplicitCastExpr, CastExpr>(m, "ExplicitCastExpr")
    .def("__hash__", [](const ExplicitCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("type_as_written", &ExplicitCastExpr::TypeAsWritten)
    .def_prop_ro("type_info_as_written", &ExplicitCastExpr::TypeInfoAsWritten);
}
} // namespace pasta
