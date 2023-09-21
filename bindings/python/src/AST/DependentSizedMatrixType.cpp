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

void RegisterDependentSizedMatrixType(nb::module_ &m) {
  nb::class_<DependentSizedMatrixType, MatrixType>(m, "DependentSizedMatrixType")
    .def("__hash__", [](const DependentSizedMatrixType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("attribute_token", &DependentSizedMatrixType::AttributeToken)
    .def_prop_ro("column_expression", &DependentSizedMatrixType::ColumnExpression)
    .def_prop_ro("row_expression", &DependentSizedMatrixType::RowExpression);
}
} // namespace pasta
