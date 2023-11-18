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

void RegisterCXXBoolLiteralExpr(nb::module_ &m) {
  nb::class_<CXXBoolLiteralExpr, Expr>(m, "CXXBoolLiteralExpr")
    .def_prop_ro("children", &CXXBoolLiteralExpr::Children)
    .def_prop_ro("begin_token", &CXXBoolLiteralExpr::BeginToken)
    .def_prop_ro("end_token", &CXXBoolLiteralExpr::EndToken)
    .def_prop_ro("token", &CXXBoolLiteralExpr::Token)
    .def_prop_ro("value", &CXXBoolLiteralExpr::Value);
}
} // namespace pasta
