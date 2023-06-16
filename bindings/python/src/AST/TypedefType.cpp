/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterTypedefType(nb::module_ &m) {
  nb::class_<TypedefType, Type>(m, "TypedefType")
    .def("__hash__", [](const TypedefType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &TypedefType::Desugar)
    .def_prop_ro("declaration", &TypedefType::Declaration)
    .def_prop_ro("is_sugared", &TypedefType::IsSugared)
    .def_prop_ro("type_matches_declaration", &TypedefType::TypeMatchesDeclaration);
}
} // namespace pasta
