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

void RegisterCXXConstructExpr(py::module_ &m) {
  py::class_<CXXConstructExpr, Expr>(m, "CXXConstructExpr")
    .def("__hash__", [](const CXXConstructExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("arguments", &CXXConstructExpr::Arguments)
    .def_property_readonly("children", &CXXConstructExpr::Children)
    .def_property_readonly("begin_token", &CXXConstructExpr::BeginToken)
    .def_property_readonly("construction_kind", &CXXConstructExpr::ConstructionKind)
    .def_property_readonly("constructor", &CXXConstructExpr::Constructor)
    .def_property_readonly("end_token", &CXXConstructExpr::EndToken)
    .def_property_readonly("token", &CXXConstructExpr::Token)
    .def_property_readonly("num_arguments", &CXXConstructExpr::NumArguments)
    .def_property_readonly("parenthesis_or_brace_range", &CXXConstructExpr::ParenthesisOrBraceRange)
    .def_property_readonly("had_multiple_candidates", &CXXConstructExpr::HadMultipleCandidates)
    .def_property_readonly("is_elidable", &CXXConstructExpr::IsElidable)
    .def_property_readonly("is_list_initialization", &CXXConstructExpr::IsListInitialization)
    .def_property_readonly("is_std_initializer_list_initialization", &CXXConstructExpr::IsStdInitializerListInitialization)
    .def_property_readonly("requires_zero_initialization", &CXXConstructExpr::RequiresZeroInitialization);
}
} // namespace pasta
