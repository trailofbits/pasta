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

void RegisterCapturedStmt(py::module_ &m) {
  py::class_<CapturedStmt, Stmt>(m, "CapturedStmt")
    .def("__hash__", [](const CapturedStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CapturedStmt& a, const CapturedStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CapturedStmt::Children)
    .def_property_readonly("begin_token", &CapturedStmt::BeginToken)
    .def_property_readonly("captured_declaration", &CapturedStmt::CapturedDeclaration)
    .def_property_readonly("captured_record_declaration", &CapturedStmt::CapturedRecordDeclaration)
    .def_property_readonly("captured_region_kind", &CapturedStmt::CapturedRegionKind)
    .def_property_readonly("captured_statement", &CapturedStmt::CapturedStatement)
    .def_property_readonly("end_token", &CapturedStmt::EndToken)
    .def_property_readonly("tokens", &CapturedStmt::Tokens);
}
} // namespace pasta
