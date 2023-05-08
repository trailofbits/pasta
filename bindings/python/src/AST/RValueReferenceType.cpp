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

void RegisterRValueReferenceType(py::module_ &m) {
  py::class_<RValueReferenceType, ReferenceType>(m, "RValueReferenceType")
    .def("__hash__", [](const RValueReferenceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const RValueReferenceType& a, const RValueReferenceType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &RValueReferenceType::Desugar)
    .def_property_readonly("is_sugared", &RValueReferenceType::IsSugared);
}
} // namespace pasta
