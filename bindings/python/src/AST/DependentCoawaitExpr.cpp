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

void RegisterDependentCoawaitExpr(nb::module_ &m) {
  nb::class_<DependentCoawaitExpr, Expr>(m, "DependentCoawaitExpr")
    .def_prop_ro("children", &DependentCoawaitExpr::Children)
    .def_prop_ro("begin_token", &DependentCoawaitExpr::BeginToken)
    .def_prop_ro("end_token", &DependentCoawaitExpr::EndToken)
    .def_prop_ro("keyword_token", &DependentCoawaitExpr::KeywordToken)
    .def_prop_ro("operand", &DependentCoawaitExpr::Operand)
    .def_prop_ro("operator_coawait_lookup", &DependentCoawaitExpr::OperatorCoawaitLookup);
}
} // namespace pasta
