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

void RegisterComplexType(nb::module_ &m) {
  nb::class_<ComplexType, Type>(m, "ComplexType")
    .def("__hash__", [](const ComplexType &type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &ComplexType::Desugar)
    .def_prop_ro("element_type", &ComplexType::ElementType)
    .def_prop_ro("is_sugared", &ComplexType::IsSugared);
}
} // namespace pasta
