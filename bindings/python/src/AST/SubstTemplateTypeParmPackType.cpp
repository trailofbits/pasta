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

void RegisterSubstTemplateTypeParmPackType(py::module_ &m) {
  py::class_<SubstTemplateTypeParmPackType, Type>(m, "SubstTemplateTypeParmPackType")
    .def_property_readonly("Desugar", &SubstTemplateTypeParmPackType::Desugar)
    .def_property_readonly("AssociatedDeclaration", &SubstTemplateTypeParmPackType::AssociatedDeclaration)
    .def_property_readonly("Final", &SubstTemplateTypeParmPackType::Final)
    .def_property_readonly("Index", &SubstTemplateTypeParmPackType::Index)
    .def_property_readonly("NumArguments", &SubstTemplateTypeParmPackType::NumArguments)
    .def_property_readonly("ReplacedParameter", &SubstTemplateTypeParmPackType::ReplacedParameter)
    .def_property_readonly("IsSugared", &SubstTemplateTypeParmPackType::IsSugared);
}
} // namespace pasta
