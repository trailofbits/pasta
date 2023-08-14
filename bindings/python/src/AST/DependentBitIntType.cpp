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

void RegisterDependentBitIntType(nb::module_ &m) {
  nb::class_<DependentBitIntType, Type>(m, "DependentBitIntType")
    .def("__hash__", [](const DependentBitIntType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &DependentBitIntType::Desugar)
    .def_prop_ro("num_bits_expression", &DependentBitIntType::NumBitsExpression)
    .def_prop_ro("is_signed", &DependentBitIntType::IsSigned)
    .def_prop_ro("is_sugared", &DependentBitIntType::IsSugared)
    .def_prop_ro("is_unsigned", &DependentBitIntType::IsUnsigned);
}
} // namespace pasta
