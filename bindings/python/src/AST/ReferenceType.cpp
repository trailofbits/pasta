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

void RegisterReferenceType(nb::module_ &m) {
  nb::class_<ReferenceType, Type>(m, "ReferenceType")
    .def("__hash__", [](const ReferenceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("pointee_type", &ReferenceType::PointeeType)
    .def_prop_ro("pointee_type_as_written", &ReferenceType::PointeeTypeAsWritten)
    .def_prop_ro("is_inner_reference", &ReferenceType::IsInnerReference)
    .def_prop_ro("is_spelled_as_l_value", &ReferenceType::IsSpelledAsLValue);
}
} // namespace pasta
