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

void RegisterDesignatedInitExpr(nb::module_ &m) {
  nb::class_<DesignatedInitExpr, Expr>(m, "DesignatedInitExpr")
    .def_prop_ro("children", &DesignatedInitExpr::Children)
    .def_prop_ro("designators", &DesignatedInitExpr::Designators)
    .def_prop_ro("begin_token", &DesignatedInitExpr::BeginToken)
    .def_prop_ro("designator", &DesignatedInitExpr::Designator)
    .def_prop_ro("designators_tokens", &DesignatedInitExpr::DesignatorsTokens)
    .def_prop_ro("end_token", &DesignatedInitExpr::EndToken)
    .def_prop_ro("equal_or_colon_token", &DesignatedInitExpr::EqualOrColonToken)
    .def_prop_ro("initializer", &DesignatedInitExpr::Initializer)
    .def_prop_ro("num_sub_expressions", &DesignatedInitExpr::NumSubExpressions)
    .def_prop_ro("is_direct_initializer", &DesignatedInitExpr::IsDirectInitializer)
    .def_prop_ro("size", &DesignatedInitExpr::Size)
    .def_prop_ro("uses_gnu_syntax", &DesignatedInitExpr::UsesGNUSyntax);
}
} // namespace pasta
