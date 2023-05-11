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

void RegisterCXXTemporaryObjectExpr(py::module_ &m) {
  py::class_<CXXTemporaryObjectExpr, CXXConstructExpr>(m, "CXXTemporaryObjectExpr")
    .def("__hash__", [](const CXXTemporaryObjectExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &CXXTemporaryObjectExpr::BeginToken)
    .def_property_readonly("end_token", &CXXTemporaryObjectExpr::EndToken)
    .def_property_readonly("type", &CXXTemporaryObjectExpr::Type);
}
} // namespace pasta
