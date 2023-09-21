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

void RegisterArrayType(nb::module_ &m) {
  nb::class_<ArrayType, Type>(m, "ArrayType")
    .def("__hash__", [](const ArrayType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("element_type", &ArrayType::ElementType)
    .def_prop_ro("index_type_cvr_qualifiers", &ArrayType::IndexTypeCVRQualifiers)
    .def_prop_ro("size_modifier", &ArrayType::SizeModifier);
}
} // namespace pasta
