/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterTemplateTypeParmType(nb::module_ &m) {
  nb::class_<TemplateTypeParmType, Type>(m, "TemplateTypeParmType")
    .def("__hash__", [](const TemplateTypeParmType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &TemplateTypeParmType::Desugar)
    .def_prop_ro("declaration", &TemplateTypeParmType::Declaration)
    .def_prop_ro("depth", &TemplateTypeParmType::Depth)
    .def_prop_ro("index", &TemplateTypeParmType::Index)
    .def_prop_ro("is_parameter_pack", &TemplateTypeParmType::IsParameterPack)
    .def_prop_ro("is_sugared", &TemplateTypeParmType::IsSugared);
}
} // namespace pasta
