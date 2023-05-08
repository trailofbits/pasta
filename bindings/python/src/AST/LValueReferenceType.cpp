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

void RegisterLValueReferenceType(py::module_ &m) {
  py::class_<LValueReferenceType, ReferenceType>(m, "LValueReferenceType")
    .def("__hash__", [](const LValueReferenceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const LValueReferenceType& a, const LValueReferenceType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &LValueReferenceType::Desugar)
    .def_property_readonly("IsSugared", &LValueReferenceType::IsSugared);
}
} // namespace pasta
