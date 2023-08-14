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

void RegisterBlockExpr(nb::module_ &m) {
  nb::class_<BlockExpr, Expr>(m, "BlockExpr")
    .def("__hash__", [](const BlockExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &BlockExpr::Children)
    .def_prop_ro("begin_token", &BlockExpr::BeginToken)
    .def_prop_ro("block_declaration", &BlockExpr::BlockDeclaration)
    .def_prop_ro("body", &BlockExpr::Body)
    .def_prop_ro("caret_token", &BlockExpr::CaretToken)
    .def_prop_ro("end_token", &BlockExpr::EndToken)
    .def_prop_ro("function_type", &BlockExpr::FunctionType);
}
} // namespace pasta
