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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterCXXInheritedCtorInitExpr(py::module_ &m) {
  py::class_<CXXInheritedCtorInitExpr, Expr>(m, "CXXInheritedCtorInitExpr")
    .def("__hash__", [](const CXXInheritedCtorInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXInheritedCtorInitExpr::Children)
    .def_property_readonly("constructs_virtual_base", &CXXInheritedCtorInitExpr::ConstructsVirtualBase)
    .def_property_readonly("begin_token", &CXXInheritedCtorInitExpr::BeginToken)
    .def_property_readonly("construction_kind", &CXXInheritedCtorInitExpr::ConstructionKind)
    .def_property_readonly("constructor", &CXXInheritedCtorInitExpr::Constructor)
    .def_property_readonly("end_token", &CXXInheritedCtorInitExpr::EndToken)
    .def_property_readonly("token", &CXXInheritedCtorInitExpr::Token)
    .def_property_readonly("inherited_from_virtual_base", &CXXInheritedCtorInitExpr::InheritedFromVirtualBase);
}
} // namespace pasta
