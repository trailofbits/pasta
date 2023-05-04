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
    .def_property_readonly("Children", &CXXTryStmt::Children)
    .def_property_readonly("BeginToken", &CXXTryStmt::BeginToken)
    .def_property_readonly("EndToken", &CXXTryStmt::EndToken)
    .def_property_readonly("NumHandlers", &CXXTryStmt::NumHandlers)
    .def_property_readonly("TryBlock", &CXXTryStmt::TryBlock)
    .def_property_readonly("TryToken", &CXXTryStmt::TryToken);
}
} // namespace pasta
