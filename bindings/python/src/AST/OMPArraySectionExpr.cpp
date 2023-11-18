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

void RegisterOMPArraySectionExpr(nb::module_ &m) {
  nb::class_<OMPArraySectionExpr, Expr>(m, "OMPArraySectionExpr")
    .def_prop_ro("children", &OMPArraySectionExpr::Children)
    .def_prop_ro("base", &OMPArraySectionExpr::Base)
    .def_prop_ro("begin_token", &OMPArraySectionExpr::BeginToken)
    .def_prop_ro("first_colon_token", &OMPArraySectionExpr::FirstColonToken)
    .def_prop_ro("second_colon_token", &OMPArraySectionExpr::SecondColonToken)
    .def_prop_ro("end_token", &OMPArraySectionExpr::EndToken)
    .def_prop_ro("expression_token", &OMPArraySectionExpr::ExpressionToken)
    .def_prop_ro("length", &OMPArraySectionExpr::Length)
    .def_prop_ro("lower_bound", &OMPArraySectionExpr::LowerBound)
    .def_prop_ro("r_bracket_token", &OMPArraySectionExpr::RBracketToken)
    .def_prop_ro("stride", &OMPArraySectionExpr::Stride);
}
} // namespace pasta
