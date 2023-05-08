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
    .def("__hash__", [](const DeducedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DeducedType& a, const DeducedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DeducedType::Desugar)
    .def_property_readonly("resolved_type", &DeducedType::ResolvedType)
    .def_property_readonly("is_deduced", &DeducedType::IsDeduced)
    .def_property_readonly("is_sugared", &DeducedType::IsSugared);
}
} // namespace pasta
