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

void RegisterCXXCatchStmt(py::module_ &m) {
  py::class_<CXXCatchStmt, Stmt>(m, "CXXCatchStmt")
    .def("__hash__", [](const CXXCatchStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXCatchStmt& a, const CXXCatchStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXCatchStmt::Children)
    .def_property_readonly("begin_token", &CXXCatchStmt::BeginToken)
    .def_property_readonly("catch_token", &CXXCatchStmt::CatchToken)
    .def_property_readonly("caught_type", &CXXCatchStmt::CaughtType)
    .def_property_readonly("end_token", &CXXCatchStmt::EndToken)
    .def_property_readonly("exception_declaration", &CXXCatchStmt::ExceptionDeclaration)
    .def_property_readonly("handler_block", &CXXCatchStmt::HandlerBlock);
}
} // namespace pasta
