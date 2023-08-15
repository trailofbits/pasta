/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterSubstTemplateTypeParmType(nb::module_ &m) {
  nb::class_<SubstTemplateTypeParmType, Type>(m, "SubstTemplateTypeParmType")
    .def("__hash__", [](const SubstTemplateTypeParmType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &SubstTemplateTypeParmType::Desugar)
    .def_prop_ro("associated_declaration", &SubstTemplateTypeParmType::AssociatedDeclaration)
    .def_prop_ro("index", &SubstTemplateTypeParmType::Index)
    .def_prop_ro("pack_index", &SubstTemplateTypeParmType::PackIndex)
    .def_prop_ro("replaced_parameter", &SubstTemplateTypeParmType::ReplacedParameter)
    .def_prop_ro("replacement_type", &SubstTemplateTypeParmType::ReplacementType)
    .def_prop_ro("is_sugared", &SubstTemplateTypeParmType::IsSugared);
}
} // namespace pasta
