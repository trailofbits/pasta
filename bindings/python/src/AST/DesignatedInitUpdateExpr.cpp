/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterDesignatedInitUpdateExpr(nb::module_ &m) {
  nb::class_<DesignatedInitUpdateExpr, Expr>(m, "DesignatedInitUpdateExpr")
    .def("__hash__", [](const DesignatedInitUpdateExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &DesignatedInitUpdateExpr::Children)
    .def_prop_ro("base", &DesignatedInitUpdateExpr::Base)
    .def_prop_ro("begin_token", &DesignatedInitUpdateExpr::BeginToken)
    .def_prop_ro("end_token", &DesignatedInitUpdateExpr::EndToken)
    .def_prop_ro("updater", &DesignatedInitUpdateExpr::Updater);
}
} // namespace pasta
