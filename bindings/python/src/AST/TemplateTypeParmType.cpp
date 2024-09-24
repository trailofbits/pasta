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

void RegisterTemplateTypeParmType(nb::module_ &m) {
  nb::class_<TemplateTypeParmType, Type>(m, "TemplateTypeParmType")
    .def_prop_ro("desugar", &TemplateTypeParmType::Desugar)
    .def_prop_ro("declaration", &TemplateTypeParmType::Declaration)
    .def_prop_ro("depth", &TemplateTypeParmType::Depth)
    .def_prop_ro("index", &TemplateTypeParmType::Index)
    .def_prop_ro("is_parameter_pack", &TemplateTypeParmType::IsParameterPack)
    .def_prop_ro("is_sugared", &TemplateTypeParmType::IsSugared);
}
} // namespace pasta
