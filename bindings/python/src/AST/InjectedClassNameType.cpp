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

void RegisterInjectedClassNameType(nb::module_ &m) {
  nb::class_<InjectedClassNameType, Type>(m, "InjectedClassNameType")
    .def_prop_ro("desugar", &InjectedClassNameType::Desugar)
    .def_prop_ro("declaration", &InjectedClassNameType::Declaration)
    .def_prop_ro("injected_specialization_type", &InjectedClassNameType::InjectedSpecializationType)
    .def_prop_ro("injected_tst", &InjectedClassNameType::InjectedTST)
    .def_prop_ro("is_sugared", &InjectedClassNameType::IsSugared);
}
} // namespace pasta
