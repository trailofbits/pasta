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

void RegisterTemplateSpecializationType(py::module_ &m) {
  py::class_<TemplateSpecializationType, Type>(m, "TemplateSpecializationType")
    .def("__hash__", [](const TemplateSpecializationType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TemplateSpecializationType& a, const TemplateSpecializationType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &TemplateSpecializationType::Desugar)
    .def_property_readonly("aliased_type", &TemplateSpecializationType::AliasedType)
    .def_property_readonly("is_current_instantiation", &TemplateSpecializationType::IsCurrentInstantiation)
    .def_property_readonly("is_sugared", &TemplateSpecializationType::IsSugared)
    .def_property_readonly("is_type_alias", &TemplateSpecializationType::IsTypeAlias)
    .def_property_readonly("template_arguments", &TemplateSpecializationType::TemplateArguments);
}
} // namespace pasta
