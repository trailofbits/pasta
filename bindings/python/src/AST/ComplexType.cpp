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

void RegisterComplexType(py::module_ &m) {
  py::class_<ComplexType, Type>(m, "ComplexType")
    .def("__hash__", [](const ComplexType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ComplexType& a, const ComplexType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &ComplexType::Desugar)
    .def_property_readonly("ElementType", &ComplexType::ElementType)
    .def_property_readonly("IsSugared", &ComplexType::IsSugared);
}
} // namespace pasta
