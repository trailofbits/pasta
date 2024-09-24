/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterRecordType(nb::module_ &m) {
  nb::class_<RecordType, TagType>(m, "RecordType")
    .def_prop_ro("desugar", &RecordType::Desugar)
    .def_prop_ro("declaration", &RecordType::Declaration)
    .def_prop_ro("has_const_fields", &RecordType::HasConstFields)
    .def_prop_ro("is_sugared", &RecordType::IsSugared);
}
} // namespace pasta
