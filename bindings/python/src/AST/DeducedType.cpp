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

void RegisterDeducedType(py::module_ &m) {
  py::class_<DeducedType, Type>(m, "DeducedType")
    .def_property_readonly("Desugar", &DeducedType::Desugar)
    .def_property_readonly("ResolvedType", &DeducedType::ResolvedType)
    .def_property_readonly("IsDeduced", &DeducedType::IsDeduced)
    .def_property_readonly("IsSugared", &DeducedType::IsSugared);
}
} // namespace pasta
