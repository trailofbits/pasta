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

void RegisterOMPAtomicDirective(py::module_ &m) {
  py::class_<OMPAtomicDirective, OMPExecutableDirective>(m, "OMPAtomicDirective")
    .def("__hash__", [](const OMPAtomicDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPAtomicDirective& a, const OMPAtomicDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("condition_expression", &OMPAtomicDirective::ConditionExpression)
    .def_property_readonly("d", &OMPAtomicDirective::D)
    .def_property_readonly("expression", &OMPAtomicDirective::Expression)
    .def_property_readonly("r", &OMPAtomicDirective::R)
    .def_property_readonly("update_expression", &OMPAtomicDirective::UpdateExpression)
    .def_property_readonly("v", &OMPAtomicDirective::V)
    .def_property_readonly("x", &OMPAtomicDirective::X)
    .def_property_readonly("is_fail_only", &OMPAtomicDirective::IsFailOnly)
    .def_property_readonly("is_postfix_update", &OMPAtomicDirective::IsPostfixUpdate)
    .def_property_readonly("is_xlhs_in_rhs_part", &OMPAtomicDirective::IsXLHSInRHSPart);
}
} // namespace pasta
