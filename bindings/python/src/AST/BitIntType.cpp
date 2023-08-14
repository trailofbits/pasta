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

void RegisterBitIntType(nb::module_ &m) {
  nb::class_<BitIntType, Type>(m, "BitIntType")
    .def("__hash__", [](const BitIntType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &BitIntType::Desugar)
    .def_prop_ro("num_bits", &BitIntType::NumBits)
    .def_prop_ro("is_signed", &BitIntType::IsSigned)
    .def_prop_ro("is_sugared", &BitIntType::IsSugared)
    .def_prop_ro("is_unsigned", &BitIntType::IsUnsigned);
}
} // namespace pasta
