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

void RegisterOMPAtomicDirective(py::module_ &m) {
  py::class_<OMPAtomicDirective, OMPExecutableDirective, Stmt>(m, "OMPAtomicDirective")
    .def_property_readonly("ConditionExpression", &OMPAtomicDirective::ConditionExpression)
    .def_property_readonly("D", &OMPAtomicDirective::D)
    .def_property_readonly("Expression", &OMPAtomicDirective::Expression)
    .def_property_readonly("R", &OMPAtomicDirective::R)
    .def_property_readonly("UpdateExpression", &OMPAtomicDirective::UpdateExpression)
    .def_property_readonly("V", &OMPAtomicDirective::V)
    .def_property_readonly("X", &OMPAtomicDirective::X)
    .def_property_readonly("IsFailOnly", &OMPAtomicDirective::IsFailOnly)
    .def_property_readonly("IsPostfixUpdate", &OMPAtomicDirective::IsPostfixUpdate)
    .def_property_readonly("IsXLHSInRHSPart", &OMPAtomicDirective::IsXLHSInRHSPart);
}
} // namespace pasta
