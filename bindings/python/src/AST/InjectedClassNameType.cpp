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
    .def("__hash__", [](const InjectedClassNameType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const InjectedClassNameType& a, const InjectedClassNameType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &InjectedClassNameType::Desugar)
    .def_property_readonly("Declaration", &InjectedClassNameType::Declaration)
    .def_property_readonly("InjectedSpecializationType", &InjectedClassNameType::InjectedSpecializationType)
    .def_property_readonly("InjectedTST", &InjectedClassNameType::InjectedTST)
    .def_property_readonly("IsSugared", &InjectedClassNameType::IsSugared);
}
} // namespace pasta
