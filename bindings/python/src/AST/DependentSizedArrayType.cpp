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

void RegisterDependentSizedArrayType(nb::module_ &m) {
  nb::class_<DependentSizedArrayType, ArrayType>(m, "DependentSizedArrayType")
    .def("__hash__", [](const DependentSizedArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &DependentSizedArrayType::Desugar)
    .def_prop_ro("brackets_range", &DependentSizedArrayType::BracketsRange)
    .def_prop_ro("l_bracket_token", &DependentSizedArrayType::LBracketToken)
    .def_prop_ro("r_bracket_token", &DependentSizedArrayType::RBracketToken)
    .def_prop_ro("size_expression", &DependentSizedArrayType::SizeExpression)
    .def_prop_ro("is_sugared", &DependentSizedArrayType::IsSugared);
}
} // namespace pasta
