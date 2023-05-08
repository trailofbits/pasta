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

void RegisterCXXTryStmt(py::module_ &m) {
  py::class_<CXXTryStmt, Stmt>(m, "CXXTryStmt")
    .def("__hash__", [](const CXXTryStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXTryStmt& a, const CXXTryStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXTryStmt::Children)
    .def_property_readonly("begin_token", &CXXTryStmt::BeginToken)
    .def_property_readonly("end_token", &CXXTryStmt::EndToken)
    .def_property_readonly("num_handlers", &CXXTryStmt::NumHandlers)
    .def_property_readonly("try_block", &CXXTryStmt::TryBlock)
    .def_property_readonly("try_token", &CXXTryStmt::TryToken);
}
} // namespace pasta
