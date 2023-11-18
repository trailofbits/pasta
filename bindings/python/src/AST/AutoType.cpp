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

void RegisterAutoType(nb::module_ &m) {
  nb::class_<AutoType, DeducedType>(m, "AutoType")
    .def_prop_ro("keyword", &AutoType::Keyword)
    .def_prop_ro("type_constraint_arguments", &AutoType::TypeConstraintArguments)
    .def_prop_ro("type_constraint_concept", &AutoType::TypeConstraintConcept)
    .def_prop_ro("is_constrained", &AutoType::IsConstrained)
    .def_prop_ro("is_decltype_auto", &AutoType::IsDecltypeAuto)
    .def_prop_ro("is_gnu_auto_type", &AutoType::IsGNUAutoType);
}
} // namespace pasta
