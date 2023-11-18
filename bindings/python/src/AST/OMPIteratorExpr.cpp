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

void RegisterOMPIteratorExpr(nb::module_ &m) {
  nb::class_<OMPIteratorExpr, Expr>(m, "OMPIteratorExpr")
    .def_prop_ro("children", &OMPIteratorExpr::Children)
    .def_prop_ro("begin_token", &OMPIteratorExpr::BeginToken)
    .def_prop_ro("end_token", &OMPIteratorExpr::EndToken)
    .def_prop_ro("iterator_kw_token", &OMPIteratorExpr::IteratorKwToken)
    .def_prop_ro("l_paren_token", &OMPIteratorExpr::LParenToken)
    .def_prop_ro("r_paren_token", &OMPIteratorExpr::RParenToken)
    .def_prop_ro("num_of_iterators", &OMPIteratorExpr::NumOfIterators);
}
} // namespace pasta
