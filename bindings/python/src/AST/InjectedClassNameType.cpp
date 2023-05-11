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

void RegisterInjectedClassNameType(py::module_ &m) {
  py::class_<InjectedClassNameType, Type>(m, "InjectedClassNameType")
    .def("__hash__", [](const InjectedClassNameType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &InjectedClassNameType::Desugar)
    .def_property_readonly("declaration", &InjectedClassNameType::Declaration)
    .def_property_readonly("injected_specialization_type", &InjectedClassNameType::InjectedSpecializationType)
    .def_property_readonly("injected_tst", &InjectedClassNameType::InjectedTST)
    .def_property_readonly("is_sugared", &InjectedClassNameType::IsSugared);
}
} // namespace pasta
