/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterDependentVectorType(nb::module_ &m) {
  nb::class_<DependentVectorType, Type>(m, "DependentVectorType")
    .def_prop_ro("desugar", &DependentVectorType::Desugar)
    .def_prop_ro("attribute_token", &DependentVectorType::AttributeToken)
    .def_prop_ro("element_type", &DependentVectorType::ElementType)
    .def_prop_ro("size_expression", &DependentVectorType::SizeExpression)
    .def_prop_ro("vector_kind", &DependentVectorType::VectorKind)
    .def_prop_ro("is_sugared", &DependentVectorType::IsSugared);
}
} // namespace pasta
