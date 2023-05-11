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

void RegisterOMPExecutableDirective(py::module_ &m) {
  py::class_<OMPExecutableDirective, Stmt>(m, "OMPExecutableDirective")
    .def("__hash__", [](const OMPExecutableDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &OMPExecutableDirective::Children)
    .def_property_readonly("associated_statement", &OMPExecutableDirective::AssociatedStatement)
    .def_property_readonly("begin_token", &OMPExecutableDirective::BeginToken)
    .def_property_readonly("end_token", &OMPExecutableDirective::EndToken)
    .def_property_readonly("innermost_captured_statement", &OMPExecutableDirective::InnermostCapturedStatement)
    .def_property_readonly("num_clauses", &OMPExecutableDirective::NumClauses)
    .def_property_readonly("raw_statement", &OMPExecutableDirective::RawStatement)
    .def_property_readonly("structured_block", &OMPExecutableDirective::StructuredBlock)
    .def_property_readonly("has_associated_statement", &OMPExecutableDirective::HasAssociatedStatement)
    .def_property_readonly("is_standalone_directive", &OMPExecutableDirective::IsStandaloneDirective);
}
} // namespace pasta
