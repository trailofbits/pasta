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

void RegisterCXXConstructExpr(py::module_ &m) {
  py::class_<CXXConstructExpr, Expr>(m, "CXXConstructExpr")
    .def("__hash__", [](const CXXConstructExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXConstructExpr& a, const CXXConstructExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Arguments", &CXXConstructExpr::Arguments)
    .def_property_readonly("Children", &CXXConstructExpr::Children)
    .def_property_readonly("BeginToken", &CXXConstructExpr::BeginToken)
    .def_property_readonly("ConstructionKind", &CXXConstructExpr::ConstructionKind)
    .def_property_readonly("Constructor", &CXXConstructExpr::Constructor)
    .def_property_readonly("EndToken", &CXXConstructExpr::EndToken)
    .def_property_readonly("Token", &CXXConstructExpr::Token)
    .def_property_readonly("NumArguments", &CXXConstructExpr::NumArguments)
    .def_property_readonly("ParenthesisOrBraceRange", &CXXConstructExpr::ParenthesisOrBraceRange)
    .def_property_readonly("HadMultipleCandidates", &CXXConstructExpr::HadMultipleCandidates)
    .def_property_readonly("IsElidable", &CXXConstructExpr::IsElidable)
    .def_property_readonly("IsListInitialization", &CXXConstructExpr::IsListInitialization)
    .def_property_readonly("IsStdInitializerListInitialization", &CXXConstructExpr::IsStdInitializerListInitialization)
    .def_property_readonly("RequiresZeroInitialization", &CXXConstructExpr::RequiresZeroInitialization);
}
} // namespace pasta
