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

void RegisterConstantExpr(nb::module_ &m) {
  nb::class_<ConstantExpr, FullExpr>(m, "ConstantExpr")
    .def_prop_ro("children", &ConstantExpr::Children)
    .def_prop_ro("begin_token", &ConstantExpr::BeginToken)
    .def_prop_ro("end_token", &ConstantExpr::EndToken)
    .def_prop_ro("result_as_aps_int", &ConstantExpr::ResultAsAPSInt)
    .def_prop_ro("result_storage_kind", &ConstantExpr::ResultStorageKind)
    .def_prop_ro("has_ap_value_result", &ConstantExpr::HasAPValueResult)
    .def_prop_ro("is_immediate_invocation", &ConstantExpr::IsImmediateInvocation);
}
} // namespace pasta
