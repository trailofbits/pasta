/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterLValueReferenceType(nb::module_ &m) {
  nb::class_<LValueReferenceType, ReferenceType>(m, "LValueReferenceType")
    .def("__hash__", [](const LValueReferenceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &LValueReferenceType::Desugar)
    .def_prop_ro("is_sugared", &LValueReferenceType::IsSugared);
}
} // namespace pasta
