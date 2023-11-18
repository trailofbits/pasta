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

void RegisterCXXThrowExpr(nb::module_ &m) {
  nb::class_<CXXThrowExpr, Expr>(m, "CXXThrowExpr")
    .def_prop_ro("children", &CXXThrowExpr::Children)
    .def_prop_ro("begin_token", &CXXThrowExpr::BeginToken)
    .def_prop_ro("end_token", &CXXThrowExpr::EndToken)
    .def_prop_ro("sub_expression", &CXXThrowExpr::SubExpression)
    .def_prop_ro("throw_token", &CXXThrowExpr::ThrowToken)
    .def_prop_ro("is_thrown_variable_in_scope", &CXXThrowExpr::IsThrownVariableInScope);
}
} // namespace pasta
