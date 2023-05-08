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
    .def("__hash__", [](const AdjustedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const AdjustedType& a, const AdjustedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &AdjustedType::Desugar)
    .def_property_readonly("resolved_type", &AdjustedType::ResolvedType)
    .def_property_readonly("original_type", &AdjustedType::OriginalType)
    .def_property_readonly("is_sugared", &AdjustedType::IsSugared);
}
} // namespace pasta
