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

void RegisterExtVectorElementExpr(nb::module_ &m) {
  nb::class_<ExtVectorElementExpr, Expr>(m, "ExtVectorElementExpr")
    .def("__hash__", [](const ExtVectorElementExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ExtVectorElementExpr::Children)
    .def_prop_ro("contains_duplicate_elements", &ExtVectorElementExpr::ContainsDuplicateElements)
    .def_prop_ro("accessor_token", &ExtVectorElementExpr::AccessorToken)
    .def_prop_ro("base", &ExtVectorElementExpr::Base)
    .def_prop_ro("begin_token", &ExtVectorElementExpr::BeginToken)
    .def_prop_ro("end_token", &ExtVectorElementExpr::EndToken)
    .def_prop_ro("num_elements", &ExtVectorElementExpr::NumElements)
    .def_prop_ro("is_arrow", &ExtVectorElementExpr::IsArrow);
}
} // namespace pasta
