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

void RegisterUnresolvedUsingType(nb::module_ &m) {
  nb::class_<UnresolvedUsingType, Type>(m, "UnresolvedUsingType")
    .def("__hash__", [](const UnresolvedUsingType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &UnresolvedUsingType::Desugar)
    .def_prop_ro("declaration", &UnresolvedUsingType::Declaration)
    .def_prop_ro("is_sugared", &UnresolvedUsingType::IsSugared);
}
} // namespace pasta
