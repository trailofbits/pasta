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

void RegisterAtomicType(py::module_ &m) {
  py::class_<AtomicType, Type>(m, "AtomicType")
    .def("__hash__", [](const AtomicType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const AtomicType& a, const AtomicType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &AtomicType::Desugar)
    .def_property_readonly("ValueType", &AtomicType::ValueType)
    .def_property_readonly("IsSugared", &AtomicType::IsSugared);
}
} // namespace pasta