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

void RegisterBTFTagAttributedType(py::module_ &m) {
  py::class_<BTFTagAttributedType, Type>(m, "BTFTagAttributedType")
    .def("__hash__", [](const BTFTagAttributedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const BTFTagAttributedType& a, const BTFTagAttributedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &BTFTagAttributedType::Desugar)
    .def_property_readonly("Attribute", &BTFTagAttributedType::Attribute)
    .def_property_readonly("WrappedType", &BTFTagAttributedType::WrappedType)
    .def_property_readonly("IsSugared", &BTFTagAttributedType::IsSugared);
}
} // namespace pasta