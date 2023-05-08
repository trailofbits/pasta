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
    .def_property_readonly("ignore_containers", &Stmt::IgnoreContainers)
    .def_property_readonly("children", &Stmt::Children)
    .def_property_readonly("begin_token", &Stmt::BeginToken)
    .def_property_readonly("end_token", &Stmt::EndToken)
    .def("id", &Stmt::ID)
    .def_property_readonly("tokens", &Stmt::Tokens)
    .def_property_readonly("kind", &Stmt::Kind)
    .def_property_readonly("kind_name", &Stmt::KindName)
    .def_property_readonly("strip_label_like_statements", &Stmt::StripLabelLikeStatements);
}
} // namespace pasta
