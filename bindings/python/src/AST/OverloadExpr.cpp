/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOverloadExpr(nb::module_ &m) {
  nb::class_<OverloadExpr, Expr>(m, "OverloadExpr")
    .def("__hash__", [](const OverloadExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
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
