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

void RegisterStaticAssertDecl(py::module_ &m) {
  py::class_<StaticAssertDecl, Decl>(m, "StaticAssertDecl")
    .def("__hash__", [](const StaticAssertDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const StaticAssertDecl& a, const StaticAssertDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("assert_expression", &StaticAssertDecl::AssertExpression)
    .def_property_readonly("message", &StaticAssertDecl::Message)
    .def_property_readonly("r_paren_token", &StaticAssertDecl::RParenToken)
    .def_property_readonly("is_failed", &StaticAssertDecl::IsFailed);
}
} // namespace pasta
