/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterTypeTraitExpr(nb::module_ &m) {
  nb::class_<TypeTraitExpr, Expr>(m, "TypeTraitExpr")
    .def_prop_ro("children", &TypeTraitExpr::Children)
    .def_prop_ro("begin_token", &TypeTraitExpr::BeginToken)
    .def_prop_ro("end_token", &TypeTraitExpr::EndToken)
    .def_prop_ro("num_arguments", &TypeTraitExpr::NumArguments)
    .def_prop_ro("trait", &TypeTraitExpr::Trait)
    .def_prop_ro("value", &TypeTraitExpr::Value);
}
} // namespace pasta
