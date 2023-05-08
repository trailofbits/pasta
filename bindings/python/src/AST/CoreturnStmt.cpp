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

void RegisterCoreturnStmt(py::module_ &m) {
  py::class_<CoreturnStmt, Stmt>(m, "CoreturnStmt")
    .def("__hash__", [](const CoreturnStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CoreturnStmt& a, const CoreturnStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CoreturnStmt::Children)
    .def_property_readonly("begin_token", &CoreturnStmt::BeginToken)
    .def_property_readonly("end_token", &CoreturnStmt::EndToken)
    .def_property_readonly("keyword_token", &CoreturnStmt::KeywordToken)
    .def_property_readonly("operand", &CoreturnStmt::Operand)
    .def_property_readonly("promise_call", &CoreturnStmt::PromiseCall)
    .def_property_readonly("is_implicit", &CoreturnStmt::IsImplicit);
}
} // namespace pasta
