/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterBlockExpr(py::module_ &m) {
  py::class_<BlockExpr, Expr>(m, "BlockExpr")
    .def("__hash__", [](const BlockExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const BlockExpr& a, const BlockExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &BlockExpr::Children)
    .def_property_readonly("begin_token", &BlockExpr::BeginToken)
    .def_property_readonly("block_declaration", &BlockExpr::BlockDeclaration)
    .def_property_readonly("body", &BlockExpr::Body)
    .def_property_readonly("caret_token", &BlockExpr::CaretToken)
    .def_property_readonly("end_token", &BlockExpr::EndToken)
    .def_property_readonly("function_type", &BlockExpr::FunctionType);
}
} // namespace pasta
