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

void RegisterPackExpansionType(py::module_ &m) {
  py::class_<PackExpansionType, Type>(m, "PackExpansionType")
    .def("__hash__", [](const PackExpansionType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const PackExpansionType& a, const PackExpansionType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &PackExpansionType::Desugar)
    .def_property_readonly("num_expansions", &PackExpansionType::NumExpansions)
    .def_property_readonly("pattern", &PackExpansionType::Pattern)
    .def_property_readonly("is_sugared", &PackExpansionType::IsSugared);
}
} // namespace pasta
