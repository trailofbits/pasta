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

void RegisterInjectedClassNameType(py::module_ &m) {
  py::class_<InjectedClassNameType, Type>(m, "InjectedClassNameType")
    .def_property_readonly("Desugar", &InjectedClassNameType::Desugar)
    .def_property_readonly("Declaration", &InjectedClassNameType::Declaration)
    .def_property_readonly("InjectedSpecializationType", &InjectedClassNameType::InjectedSpecializationType)
    .def_property_readonly("InjectedTST", &InjectedClassNameType::InjectedTST)
    .def_property_readonly("IsSugared", &InjectedClassNameType::IsSugared);
}
} // namespace pasta
