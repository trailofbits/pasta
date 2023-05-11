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

void RegisterCharacterLiteral(py::module_ &m) {
  py::class_<CharacterLiteral, Expr>(m, "CharacterLiteral")
    .def("__hash__", [](const CharacterLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CharacterLiteral::Children)
    .def_property_readonly("begin_token", &CharacterLiteral::BeginToken)
    .def_property_readonly("end_token", &CharacterLiteral::EndToken)
    .def_property_readonly("kind", &CharacterLiteral::Kind)
    .def_property_readonly("token", &CharacterLiteral::Token)
    .def_property_readonly("value", &CharacterLiteral::Value);
}
} // namespace pasta
