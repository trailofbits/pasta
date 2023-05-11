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

void RegisterReferenceType(py::module_ &m) {
  py::class_<ReferenceType, Type>(m, "ReferenceType")
    .def("__hash__", [](const ReferenceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("pointee_type", &ReferenceType::PointeeType)
    .def_property_readonly("pointee_type_as_written", &ReferenceType::PointeeTypeAsWritten)
    .def_property_readonly("is_inner_reference", &ReferenceType::IsInnerReference)
    .def_property_readonly("is_spelled_as_l_value", &ReferenceType::IsSpelledAsLValue);
}
} // namespace pasta
