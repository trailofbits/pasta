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

void RegisterPackExpansionType(py::module_ &m) {
  py::class_<PackExpansionType, Type>(m, "PackExpansionType")
    .def_property_readonly("Desugar", &PackExpansionType::Desugar)
    .def_property_readonly("NumExpansions", &PackExpansionType::NumExpansions)
    .def_property_readonly("Pattern", &PackExpansionType::Pattern)
    .def_property_readonly("IsSugared", &PackExpansionType::IsSugared);
}
} // namespace pasta
