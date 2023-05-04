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

void RegisterCXXInheritedCtorInitExpr(py::module_ &m) {
  py::class_<CXXInheritedCtorInitExpr, Expr, Stmt, ValueStmt>(m, "CXXInheritedCtorInitExpr")
    .def_property_readonly("Children", &CXXInheritedCtorInitExpr::Children)
    .def_property_readonly("ConstructsVirtualBase", &CXXInheritedCtorInitExpr::ConstructsVirtualBase)
    .def_property_readonly("BeginToken", &CXXInheritedCtorInitExpr::BeginToken)
    .def_property_readonly("ConstructionKind", &CXXInheritedCtorInitExpr::ConstructionKind)
    .def_property_readonly("Constructor", &CXXInheritedCtorInitExpr::Constructor)
    .def_property_readonly("EndToken", &CXXInheritedCtorInitExpr::EndToken)
    .def_property_readonly("Token", &CXXInheritedCtorInitExpr::Token)
    .def_property_readonly("InheritedFromVirtualBase", &CXXInheritedCtorInitExpr::InheritedFromVirtualBase);
}
} // namespace pasta
