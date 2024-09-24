/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterSubstTemplateTypeParmType(nb::module_ &m) {
  nb::class_<SubstTemplateTypeParmType, Type>(m, "SubstTemplateTypeParmType")
    .def_prop_ro("desugar", &SubstTemplateTypeParmType::Desugar)
    .def_prop_ro("associated_declaration", &SubstTemplateTypeParmType::AssociatedDeclaration)
    .def_prop_ro("index", &SubstTemplateTypeParmType::Index)
    .def_prop_ro("pack_index", &SubstTemplateTypeParmType::PackIndex)
    .def_prop_ro("replaced_parameter", &SubstTemplateTypeParmType::ReplacedParameter)
    .def_prop_ro("replacement_type", &SubstTemplateTypeParmType::ReplacementType)
    .def_prop_ro("is_sugared", &SubstTemplateTypeParmType::IsSugared);
}
} // namespace pasta
