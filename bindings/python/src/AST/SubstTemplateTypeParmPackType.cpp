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

void RegisterSubstTemplateTypeParmPackType(nb::module_ &m) {
  nb::class_<SubstTemplateTypeParmPackType, Type>(m, "SubstTemplateTypeParmPackType")
    .def("__hash__", [](const SubstTemplateTypeParmPackType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &SubstTemplateTypeParmPackType::Desugar)
    .def_prop_ro("associated_declaration", &SubstTemplateTypeParmPackType::AssociatedDeclaration)
    .def_prop_ro("final", &SubstTemplateTypeParmPackType::Final)
    .def_prop_ro("index", &SubstTemplateTypeParmPackType::Index)
    .def_prop_ro("num_arguments", &SubstTemplateTypeParmPackType::NumArguments)
    .def_prop_ro("replaced_parameter", &SubstTemplateTypeParmPackType::ReplacedParameter)
    .def_prop_ro("is_sugared", &SubstTemplateTypeParmPackType::IsSugared);
}
} // namespace pasta
