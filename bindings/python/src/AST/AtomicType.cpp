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

void RegisterAtomicType(nb::module_ &m) {
  nb::class_<AtomicType, Type>(m, "AtomicType")
    .def("__hash__", [](const AtomicType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &AtomicType::Desugar)
    .def_prop_ro("value_type", &AtomicType::ValueType)
    .def_prop_ro("is_sugared", &AtomicType::IsSugared);
}
} // namespace pasta
