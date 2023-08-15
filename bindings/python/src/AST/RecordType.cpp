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

void RegisterRecordType(nb::module_ &m) {
  nb::class_<RecordType, TagType>(m, "RecordType")
    .def("__hash__", [](const RecordType &type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &RecordType::Desugar)
    .def_prop_ro("declaration", &RecordType::Declaration)
    .def_prop_ro("has_const_fields", &RecordType::HasConstFields)
    .def_prop_ro("is_sugared", &RecordType::IsSugared);
}
} // namespace pasta
