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

void RegisterIntegerLiteral(nb::module_ &m) {
  nb::class_<IntegerLiteral, Expr>(m, "IntegerLiteral")
    .def_prop_ro("children", &IntegerLiteral::Children)
    .def_prop_ro("begin_token", &IntegerLiteral::BeginToken)
    .def_prop_ro("end_token", &IntegerLiteral::EndToken)
    .def_prop_ro("token", &IntegerLiteral::Token);
}
} // namespace pasta
