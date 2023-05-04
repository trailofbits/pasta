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

void RegisterElaboratedType(py::module_ &m) {
  py::class_<ElaboratedType, Type, TypeWithKeyword>(m, "ElaboratedType")
    .def_property_readonly("Desugar", &ElaboratedType::Desugar)
    .def_property_readonly("NamedType", &ElaboratedType::NamedType)
    .def_property_readonly("OwnedTagDeclaration", &ElaboratedType::OwnedTagDeclaration)
    .def_property_readonly("IsSugared", &ElaboratedType::IsSugared);
}
} // namespace pasta
