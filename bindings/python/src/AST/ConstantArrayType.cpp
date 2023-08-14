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

void RegisterConstantArrayType(nb::module_ &m) {
  nb::class_<ConstantArrayType, ArrayType>(m, "ConstantArrayType")
    .def("__hash__", [](const ConstantArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &ConstantArrayType::Desugar)
    .def_prop_ro("size", &ConstantArrayType::Size)
    .def_prop_ro("size_expression", &ConstantArrayType::SizeExpression)
    .def_prop_ro("is_sugared", &ConstantArrayType::IsSugared);
}
} // namespace pasta
