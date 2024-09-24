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

void RegisterOverloadExpr(nb::module_ &m) {
  nb::class_<OverloadExpr, Expr>(m, "OverloadExpr")
    .def_prop_ro("l_angle_token", &OverloadExpr::LAngleToken)
    .def_prop_ro("name_token", &OverloadExpr::NameToken)
    .def_prop_ro("naming_class", &OverloadExpr::NamingClass)
    .def_prop_ro("num_declarations", &OverloadExpr::NumDeclarations)
    .def_prop_ro("num_template_arguments", &OverloadExpr::NumTemplateArguments)
    .def_prop_ro("r_angle_token", &OverloadExpr::RAngleToken)
    .def_prop_ro("template_keyword_token", &OverloadExpr::TemplateKeywordToken)
    .def_prop_ro("has_explicit_template_arguments", &OverloadExpr::HasExplicitTemplateArguments)
    .def_prop_ro("has_template_keyword", &OverloadExpr::HasTemplateKeyword);
}
} // namespace pasta
