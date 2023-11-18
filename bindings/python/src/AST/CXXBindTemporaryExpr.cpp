/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCXXBindTemporaryExpr(nb::module_ &m) {
  nb::class_<CXXBindTemporaryExpr, Expr>(m, "CXXBindTemporaryExpr")
    .def_prop_ro("children", &CXXBindTemporaryExpr::Children)
    .def_prop_ro("begin_token", &CXXBindTemporaryExpr::BeginToken)
    .def_prop_ro("end_token", &CXXBindTemporaryExpr::EndToken)
    .def_prop_ro("sub_expression", &CXXBindTemporaryExpr::SubExpression);
}
} // namespace pasta
