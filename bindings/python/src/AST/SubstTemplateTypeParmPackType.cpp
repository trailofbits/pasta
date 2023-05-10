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

void RegisterSubstTemplateTypeParmPackType(py::module_ &m) {
  py::class_<SubstTemplateTypeParmPackType, Type>(m, "SubstTemplateTypeParmPackType")
    .def("__hash__", [](const SubstTemplateTypeParmPackType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const SubstTemplateTypeParmPackType& a, const SubstTemplateTypeParmPackType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &SubstTemplateTypeParmPackType::Desugar)
    .def_property_readonly("associated_declaration", &SubstTemplateTypeParmPackType::AssociatedDeclaration)
    .def_property_readonly("final", &SubstTemplateTypeParmPackType::Final)
    .def_property_readonly("index", &SubstTemplateTypeParmPackType::Index)
    .def_property_readonly("num_arguments", &SubstTemplateTypeParmPackType::NumArguments)
    .def_property_readonly("replaced_parameter", &SubstTemplateTypeParmPackType::ReplacedParameter)
    .def_property_readonly("is_sugared", &SubstTemplateTypeParmPackType::IsSugared);
}
} // namespace pasta
