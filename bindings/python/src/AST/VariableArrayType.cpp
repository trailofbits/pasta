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

void RegisterVariableArrayType(nb::module_ &m) {
  nb::class_<VariableArrayType, ArrayType>(m, "VariableArrayType")
    .def_prop_ro("desugar", &VariableArrayType::Desugar)
    .def_prop_ro("brackets_range", &VariableArrayType::BracketsRange)
    .def_prop_ro("l_bracket_token", &VariableArrayType::LBracketToken)
    .def_prop_ro("r_bracket_token", &VariableArrayType::RBracketToken)
    .def_prop_ro("size_expression", &VariableArrayType::SizeExpression)
    .def_prop_ro("is_sugared", &VariableArrayType::IsSugared);
}
} // namespace pasta
