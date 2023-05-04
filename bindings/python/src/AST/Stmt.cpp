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

void RegisterStmt(py::module_ &m) {
  py::class_<Stmt>(m, "Stmt")
    .def("__hash__", [](const Stmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("IgnoreContainers", &Stmt::IgnoreContainers)
    .def_property_readonly("Children", &Stmt::Children)
    .def_property_readonly("BeginToken", &Stmt::BeginToken)
    .def_property_readonly("EndToken", &Stmt::EndToken)
    .def("ID", &Stmt::ID)
    .def_property_readonly("Tokens", &Stmt::Tokens)
    .def_property_readonly("Kind", &Stmt::Kind)
    .def_property_readonly("KindName", &Stmt::KindName)
    .def_property_readonly("StripLabelLikeStatements", &Stmt::StripLabelLikeStatements);
}
} // namespace pasta
