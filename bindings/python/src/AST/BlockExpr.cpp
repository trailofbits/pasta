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
  py::class_<BlockExpr, Expr, Stmt, ValueStmt>(m, "BlockExpr")
    .def_property_readonly("Children", &BlockExpr::Children)
    .def_property_readonly("BeginToken", &BlockExpr::BeginToken)
    .def_property_readonly("BlockDeclaration", &BlockExpr::BlockDeclaration)
    .def_property_readonly("Body", &BlockExpr::Body)
    .def_property_readonly("CaretToken", &BlockExpr::CaretToken)
    .def_property_readonly("EndToken", &BlockExpr::EndToken)
    .def_property_readonly("FunctionType", &BlockExpr::FunctionType);
}
} // namespace pasta
