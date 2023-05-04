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

void RegisterMacroQualifiedType(py::module_ &m) {
  py::class_<MacroQualifiedType, Type>(m, "MacroQualifiedType")
    .def("__hash__", [](const MacroQualifiedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const MacroQualifiedType& a, const MacroQualifiedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &MacroQualifiedType::Desugar)
    .def_property_readonly("ModifiedType", &MacroQualifiedType::ModifiedType)
    .def_property_readonly("UnderlyingType", &MacroQualifiedType::UnderlyingType)
    .def_property_readonly("IsSugared", &MacroQualifiedType::IsSugared);
}
} // namespace pasta