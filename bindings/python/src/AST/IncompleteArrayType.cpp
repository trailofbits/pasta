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

void RegisterIncompleteArrayType(py::module_ &m) {
  py::class_<IncompleteArrayType, ArrayType>(m, "IncompleteArrayType")
    .def("__hash__", [](const IncompleteArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const IncompleteArrayType& a, const IncompleteArrayType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &IncompleteArrayType::Desugar)
    .def_property_readonly("IsSugared", &IncompleteArrayType::IsSugared);
}
} // namespace pasta
