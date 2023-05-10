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

void RegisterCXXDynamicCastExpr(py::module_ &m) {
  py::class_<CXXDynamicCastExpr, CXXNamedCastExpr>(m, "CXXDynamicCastExpr")
    .def("__hash__", [](const CXXDynamicCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDynamicCastExpr& a, const CXXDynamicCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("is_always_null", &CXXDynamicCastExpr::IsAlwaysNull);
}
} // namespace pasta
