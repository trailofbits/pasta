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

void RegisterFloatingLiteral(nb::module_ &m) {
  nb::class_<FloatingLiteral, Expr>(m, "FloatingLiteral")
    .def_prop_ro("children", &FloatingLiteral::Children)
    .def_prop_ro("begin_token", &FloatingLiteral::BeginToken)
    .def_prop_ro("end_token", &FloatingLiteral::EndToken)
    .def_prop_ro("token", &FloatingLiteral::Token)
    .def_prop_ro("value_as_approximate_double", &FloatingLiteral::ValueAsApproximateDouble)
    .def_prop_ro("is_exact", &FloatingLiteral::IsExact);
}
} // namespace pasta
