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

void RegisterDependentScopeDeclRefExpr(nb::module_ &m) {
  nb::class_<DependentScopeDeclRefExpr, Expr>(m, "DependentScopeDeclRefExpr")
    .def_prop_ro("children", &DependentScopeDeclRefExpr::Children)
    .def_prop_ro("begin_token", &DependentScopeDeclRefExpr::BeginToken)
    .def_prop_ro("end_token", &DependentScopeDeclRefExpr::EndToken)
    .def_prop_ro("l_angle_token", &DependentScopeDeclRefExpr::LAngleToken)
    .def_prop_ro("num_template_arguments", &DependentScopeDeclRefExpr::NumTemplateArguments)
    .def_prop_ro("r_angle_token", &DependentScopeDeclRefExpr::RAngleToken)
    .def_prop_ro("template_keyword_token", &DependentScopeDeclRefExpr::TemplateKeywordToken)
    .def_prop_ro("has_explicit_template_arguments", &DependentScopeDeclRefExpr::HasExplicitTemplateArguments)
    .def_prop_ro("has_template_keyword", &DependentScopeDeclRefExpr::HasTemplateKeyword);
}
} // namespace pasta
