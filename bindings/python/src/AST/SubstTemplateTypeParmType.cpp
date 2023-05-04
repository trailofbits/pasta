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

void RegisterSubstTemplateTypeParmType(py::module_ &m) {
  py::class_<SubstTemplateTypeParmType, Type>(m, "SubstTemplateTypeParmType")
    .def("__hash__", [](const SubstTemplateTypeParmType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const SubstTemplateTypeParmType& a, const SubstTemplateTypeParmType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &SubstTemplateTypeParmType::Desugar)
    .def_property_readonly("AssociatedDeclaration", &SubstTemplateTypeParmType::AssociatedDeclaration)
    .def_property_readonly("Index", &SubstTemplateTypeParmType::Index)
    .def_property_readonly("PackIndex", &SubstTemplateTypeParmType::PackIndex)
    .def_property_readonly("ReplacedParameter", &SubstTemplateTypeParmType::ReplacedParameter)
    .def_property_readonly("ReplacementType", &SubstTemplateTypeParmType::ReplacementType)
    .def_property_readonly("IsSugared", &SubstTemplateTypeParmType::IsSugared);
}
} // namespace pasta
