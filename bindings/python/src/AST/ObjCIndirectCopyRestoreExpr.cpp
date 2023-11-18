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

void RegisterObjCIndirectCopyRestoreExpr(nb::module_ &m) {
  nb::class_<ObjCIndirectCopyRestoreExpr, Expr>(m, "ObjCIndirectCopyRestoreExpr")
    .def_prop_ro("children", &ObjCIndirectCopyRestoreExpr::Children)
    .def_prop_ro("begin_token", &ObjCIndirectCopyRestoreExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCIndirectCopyRestoreExpr::EndToken)
    .def_prop_ro("expression_token", &ObjCIndirectCopyRestoreExpr::ExpressionToken)
    .def_prop_ro("sub_expression", &ObjCIndirectCopyRestoreExpr::SubExpression)
    .def_prop_ro("should_copy", &ObjCIndirectCopyRestoreExpr::ShouldCopy);
}
} // namespace pasta
