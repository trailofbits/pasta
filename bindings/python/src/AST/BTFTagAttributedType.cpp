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

void RegisterBTFTagAttributedType(nb::module_ &m) {
  nb::class_<BTFTagAttributedType, Type>(m, "BTFTagAttributedType")
    .def("__hash__", [](const BTFTagAttributedType &type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &BTFTagAttributedType::Desugar)
    .def_prop_ro("attribute", &BTFTagAttributedType::Attribute)
    .def_prop_ro("wrapped_type", &BTFTagAttributedType::WrappedType)
    .def_prop_ro("is_sugared", &BTFTagAttributedType::IsSugared);
}
} // namespace pasta
