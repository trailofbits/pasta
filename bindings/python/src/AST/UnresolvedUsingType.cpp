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

void RegisterUnresolvedUsingType(py::module_ &m) {
  py::class_<UnresolvedUsingType, Type>(m, "UnresolvedUsingType")
    .def_property_readonly("Desugar", &UnresolvedUsingType::Desugar)
    .def_property_readonly("Declaration", &UnresolvedUsingType::Declaration)
    .def_property_readonly("IsSugared", &UnresolvedUsingType::IsSugared);
}
} // namespace pasta
