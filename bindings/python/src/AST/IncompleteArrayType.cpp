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

void RegisterIncompleteArrayType(nb::module_ &m) {
  nb::class_<IncompleteArrayType, ArrayType>(m, "IncompleteArrayType")
    .def("__hash__", [](const IncompleteArrayType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &IncompleteArrayType::Desugar)
    .def_prop_ro("is_sugared", &IncompleteArrayType::IsSugared);
}
} // namespace pasta
