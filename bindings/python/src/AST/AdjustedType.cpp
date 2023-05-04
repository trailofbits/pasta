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

void RegisterAdjustedType(py::module_ &m) {
  py::class_<AdjustedType, Type>(m, "AdjustedType")
    .def_property_readonly("Desugar", &AdjustedType::Desugar)
    .def_property_readonly("ResolvedType", &AdjustedType::ResolvedType)
    .def_property_readonly("OriginalType", &AdjustedType::OriginalType)
    .def_property_readonly("IsSugared", &AdjustedType::IsSugared);
}
} // namespace pasta
