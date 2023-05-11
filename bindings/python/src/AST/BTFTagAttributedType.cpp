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

void RegisterBTFTagAttributedType(py::module_ &m) {
  py::class_<BTFTagAttributedType, Type>(m, "BTFTagAttributedType")
    .def("__hash__", [](const BTFTagAttributedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &BTFTagAttributedType::Desugar)
    .def_property_readonly("attribute", &BTFTagAttributedType::Attribute)
    .def_property_readonly("wrapped_type", &BTFTagAttributedType::WrappedType)
    .def_property_readonly("is_sugared", &BTFTagAttributedType::IsSugared);
}
} // namespace pasta
