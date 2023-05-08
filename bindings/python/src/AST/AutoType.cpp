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

void RegisterAutoType(py::module_ &m) {
  py::class_<AutoType, DeducedType>(m, "AutoType")
    .def("__hash__", [](const AutoType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const AutoType& a, const AutoType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Keyword", &AutoType::Keyword)
    .def_property_readonly("TypeConstraintArguments", &AutoType::TypeConstraintArguments)
    .def_property_readonly("TypeConstraintConcept", &AutoType::TypeConstraintConcept)
    .def_property_readonly("IsConstrained", &AutoType::IsConstrained)
    .def_property_readonly("IsDecltypeAuto", &AutoType::IsDecltypeAuto)
    .def_property_readonly("IsGNUAutoType", &AutoType::IsGNUAutoType);
}
} // namespace pasta
