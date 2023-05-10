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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterAutoType(py::module_ &m) {
  py::class_<AutoType, DeducedType>(m, "AutoType")
    .def("__hash__", [](const AutoType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const AutoType& a, const AutoType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("keyword", &AutoType::Keyword)
    .def_property_readonly("type_constraint_arguments", &AutoType::TypeConstraintArguments)
    .def_property_readonly("type_constraint_concept", &AutoType::TypeConstraintConcept)
    .def_property_readonly("is_constrained", &AutoType::IsConstrained)
    .def_property_readonly("is_decltype_auto", &AutoType::IsDecltypeAuto)
    .def_property_readonly("is_gnu_auto_type", &AutoType::IsGNUAutoType);
}
} // namespace pasta
