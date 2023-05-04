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

void RegisterOMPExecutableDirective(py::module_ &m) {
  py::class_<OMPExecutableDirective, Stmt>(m, "OMPExecutableDirective")
    .def("__hash__", [](const OMPExecutableDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPExecutableDirective& a, const OMPExecutableDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &OMPExecutableDirective::Children)
    .def_property_readonly("AssociatedStatement", &OMPExecutableDirective::AssociatedStatement)
    .def_property_readonly("BeginToken", &OMPExecutableDirective::BeginToken)
    .def_property_readonly("EndToken", &OMPExecutableDirective::EndToken)
    .def_property_readonly("InnermostCapturedStatement", &OMPExecutableDirective::InnermostCapturedStatement)
    .def_property_readonly("NumClauses", &OMPExecutableDirective::NumClauses)
    .def_property_readonly("RawStatement", &OMPExecutableDirective::RawStatement)
    .def_property_readonly("StructuredBlock", &OMPExecutableDirective::StructuredBlock)
    .def_property_readonly("HasAssociatedStatement", &OMPExecutableDirective::HasAssociatedStatement)
    .def_property_readonly("IsStandaloneDirective", &OMPExecutableDirective::IsStandaloneDirective);
}
} // namespace pasta
