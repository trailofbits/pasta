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

void RegisterImaginaryLiteral(nb::module_ &m) {
  nb::class_<ImaginaryLiteral, Expr>(m, "ImaginaryLiteral")
    .def("__hash__", [](const ImaginaryLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ImaginaryLiteral::Children)
    .def_prop_ro("begin_token", &ImaginaryLiteral::BeginToken)
    .def_prop_ro("end_token", &ImaginaryLiteral::EndToken)
    .def_prop_ro("sub_expression", &ImaginaryLiteral::SubExpression);
}
} // namespace pasta
