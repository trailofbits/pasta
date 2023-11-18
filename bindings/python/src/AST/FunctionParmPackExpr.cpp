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

void RegisterFunctionParmPackExpr(nb::module_ &m) {
  nb::class_<FunctionParmPackExpr, Expr>(m, "FunctionParmPackExpr")
    .def_prop_ro("children", &FunctionParmPackExpr::Children)
    .def_prop_ro("begin_token", &FunctionParmPackExpr::BeginToken)
    .def_prop_ro("end_token", &FunctionParmPackExpr::EndToken)
    .def_prop_ro("num_expansions", &FunctionParmPackExpr::NumExpansions)
    .def_prop_ro("parameter_pack", &FunctionParmPackExpr::ParameterPack)
    .def_prop_ro("parameter_pack_token", &FunctionParmPackExpr::ParameterPackToken);
}
} // namespace pasta
