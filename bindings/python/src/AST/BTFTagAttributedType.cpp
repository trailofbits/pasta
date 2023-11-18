/*
 * Copyright (c) 2023 Trail of Bits, Inc.
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

void RegisterBTFTagAttributedType(nb::module_ &m) {
  nb::class_<BTFTagAttributedType, Type>(m, "BTFTagAttributedType")
    .def_prop_ro("desugar", &BTFTagAttributedType::Desugar)
    .def_prop_ro("attribute", &BTFTagAttributedType::Attribute)
    .def_prop_ro("wrapped_type", &BTFTagAttributedType::WrappedType)
    .def_prop_ro("is_sugared", &BTFTagAttributedType::IsSugared);
}
} // namespace pasta
