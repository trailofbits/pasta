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

void RegisterVectorType(nb::module_ &m) {
  nb::class_<VectorType, Type>(m, "VectorType")
    .def("__hash__", [](const VectorType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &VectorType::Desugar)
    .def_prop_ro("element_type", &VectorType::ElementType)
    .def_prop_ro("num_elements", &VectorType::NumElements)
    .def_prop_ro("vector_kind", &VectorType::VectorKind)
    .def_prop_ro("is_sugared", &VectorType::IsSugared);
}
} // namespace pasta
