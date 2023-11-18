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

void RegisterCXXFunctionalCastExpr(nb::module_ &m) {
  nb::class_<CXXFunctionalCastExpr, ExplicitCastExpr>(m, "CXXFunctionalCastExpr")
    .def_prop_ro("begin_token", &CXXFunctionalCastExpr::BeginToken)
    .def_prop_ro("end_token", &CXXFunctionalCastExpr::EndToken)
    .def_prop_ro("l_paren_token", &CXXFunctionalCastExpr::LParenToken)
    .def_prop_ro("r_paren_token", &CXXFunctionalCastExpr::RParenToken)
    .def_prop_ro("is_list_initialization", &CXXFunctionalCastExpr::IsListInitialization);
}
} // namespace pasta
