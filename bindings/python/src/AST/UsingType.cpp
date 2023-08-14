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

void RegisterUsingType(nb::module_ &m) {
  nb::class_<UsingType, Type>(m, "UsingType")
    .def("__hash__", [](const UsingType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &UsingType::Desugar)
    .def_prop_ro("found_declaration", &UsingType::FoundDeclaration)
    .def_prop_ro("underlying_type", &UsingType::UnderlyingType)
    .def_prop_ro("is_sugared", &UsingType::IsSugared)
    .def_prop_ro("type_matches_declaration", &UsingType::TypeMatchesDeclaration);
}
} // namespace pasta
