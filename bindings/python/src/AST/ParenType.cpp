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

void RegisterParenType(nb::module_ &m) {
  nb::class_<ParenType, Type>(m, "ParenType")
    .def("__hash__", [](const ParenType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &ParenType::Desugar)
    .def_prop_ro("inner_type", &ParenType::InnerType)
    .def_prop_ro("is_sugared", &ParenType::IsSugared);
}
} // namespace pasta
