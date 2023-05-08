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

void RegisterTemplateTypeParmType(py::module_ &m) {
  py::class_<TemplateTypeParmType, Type>(m, "TemplateTypeParmType")
    .def("__hash__", [](const TemplateTypeParmType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TemplateTypeParmType& a, const TemplateTypeParmType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &TemplateTypeParmType::Desugar)
    .def_property_readonly("declaration", &TemplateTypeParmType::Declaration)
    .def_property_readonly("depth", &TemplateTypeParmType::Depth)
    .def_property_readonly("index", &TemplateTypeParmType::Index)
    .def_property_readonly("is_parameter_pack", &TemplateTypeParmType::IsParameterPack)
    .def_property_readonly("is_sugared", &TemplateTypeParmType::IsSugared);
}
} // namespace pasta
