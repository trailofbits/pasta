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

void RegisterPackExpansionExpr(nb::module_ &m) {
  nb::class_<PackExpansionExpr, Expr>(m, "PackExpansionExpr")
    .def_prop_ro("children", &PackExpansionExpr::Children)
    .def_prop_ro("begin_token", &PackExpansionExpr::BeginToken)
    .def_prop_ro("ellipsis_token", &PackExpansionExpr::EllipsisToken)
    .def_prop_ro("end_token", &PackExpansionExpr::EndToken)
    .def_prop_ro("num_expansions", &PackExpansionExpr::NumExpansions)
    .def_prop_ro("pattern", &PackExpansionExpr::Pattern);
}
} // namespace pasta
