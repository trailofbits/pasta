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

void RegisterDecayedType(nb::module_ &m) {
  nb::class_<DecayedType, AdjustedType>(m, "DecayedType")
    .def("__hash__", [](const DecayedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("resolved_type", &DecayedType::ResolvedType)
    .def_prop_ro("pointee_type", &DecayedType::PointeeType);
}
} // namespace pasta
