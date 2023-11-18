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

void RegisterOMPArrayShapingExpr(nb::module_ &m) {
  nb::class_<OMPArrayShapingExpr, Expr>(m, "OMPArrayShapingExpr")
    .def_prop_ro("children", &OMPArrayShapingExpr::Children)
    .def_prop_ro("base", &OMPArrayShapingExpr::Base)
    .def_prop_ro("begin_token", &OMPArrayShapingExpr::BeginToken)
    .def_prop_ro("brackets_ranges", &OMPArrayShapingExpr::BracketsRanges)
    .def_prop_ro("dimensions", &OMPArrayShapingExpr::Dimensions)
    .def_prop_ro("end_token", &OMPArrayShapingExpr::EndToken)
    .def_prop_ro("l_paren_token", &OMPArrayShapingExpr::LParenToken)
    .def_prop_ro("r_paren_token", &OMPArrayShapingExpr::RParenToken);
}
} // namespace pasta
