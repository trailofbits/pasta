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

void RegisterCXXDeleteExpr(nb::module_ &m) {
  nb::class_<CXXDeleteExpr, Expr>(m, "CXXDeleteExpr")
    .def_prop_ro("children", &CXXDeleteExpr::Children)
    .def_prop_ro("does_usual_array_delete_want_size", &CXXDeleteExpr::DoesUsualArrayDeleteWantSize)
    .def_prop_ro("argument", &CXXDeleteExpr::Argument)
    .def_prop_ro("begin_token", &CXXDeleteExpr::BeginToken)
    .def_prop_ro("destroyed_type", &CXXDeleteExpr::DestroyedType)
    .def_prop_ro("end_token", &CXXDeleteExpr::EndToken)
    .def_prop_ro("operator_delete", &CXXDeleteExpr::OperatorDelete)
    .def_prop_ro("is_array_form", &CXXDeleteExpr::IsArrayForm)
    .def_prop_ro("is_array_form_as_written", &CXXDeleteExpr::IsArrayFormAsWritten)
    .def_prop_ro("is_global_delete", &CXXDeleteExpr::IsGlobalDelete);
}
} // namespace pasta
