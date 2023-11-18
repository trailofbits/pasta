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

void RegisterObjCAvailabilityCheckExpr(nb::module_ &m) {
  nb::class_<ObjCAvailabilityCheckExpr, Expr>(m, "ObjCAvailabilityCheckExpr")
    .def_prop_ro("children", &ObjCAvailabilityCheckExpr::Children)
    .def_prop_ro("begin_token", &ObjCAvailabilityCheckExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCAvailabilityCheckExpr::EndToken)
    .def_prop_ro("tokens", &ObjCAvailabilityCheckExpr::Tokens)
    .def_prop_ro("has_version", &ObjCAvailabilityCheckExpr::HasVersion);
}
} // namespace pasta
