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
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterAliasAttr(nb::module_ &m) {
  nb::class_<AliasAttr, Attr>(m, "AliasAttr")
    .def("__hash__", [](const AliasAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("aliasee", &AliasAttr::Aliasee)
    .def_prop_ro("aliasee_length", &AliasAttr::AliaseeLength)
    .def_prop_ro("spelling", &AliasAttr::Spelling);
}
} // namespace pasta
