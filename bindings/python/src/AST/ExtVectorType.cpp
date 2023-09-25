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

void RegisterExtVectorType(nb::module_ &m) {
  nb::class_<ExtVectorType, VectorType>(m, "ExtVectorType")
    .def("__hash__", [](const ExtVectorType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &ExtVectorType::Desugar)
    .def_prop_ro("is_sugared", &ExtVectorType::IsSugared);
}
} // namespace pasta
