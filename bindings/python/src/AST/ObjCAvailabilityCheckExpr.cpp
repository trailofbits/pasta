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

void RegisterObjCAvailabilityCheckExpr(nb::module_ &m) {
  nb::class_<ObjCAvailabilityCheckExpr, Expr>(m, "ObjCAvailabilityCheckExpr")
    .def("__hash__", [](const ObjCAvailabilityCheckExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCAvailabilityCheckExpr::Children)
    .def_prop_ro("begin_token", &ObjCAvailabilityCheckExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCAvailabilityCheckExpr::EndToken)
    .def_prop_ro("tokens", &ObjCAvailabilityCheckExpr::Tokens)
    .def_prop_ro("has_version", &ObjCAvailabilityCheckExpr::HasVersion);
}
} // namespace pasta
