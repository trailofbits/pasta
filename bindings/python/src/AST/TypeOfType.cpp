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

void RegisterTypeOfType(nb::module_ &m) {
  nb::class_<TypeOfType, Type>(m, "TypeOfType")
    .def("__hash__", [](const TypeOfType &type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &TypeOfType::Desugar)
    .def_prop_ro("type_kind", &TypeOfType::TypeKind)
    .def_prop_ro("unmodified_type", &TypeOfType::UnmodifiedType)
    .def_prop_ro("is_sugared", &TypeOfType::IsSugared);
}
} // namespace pasta
