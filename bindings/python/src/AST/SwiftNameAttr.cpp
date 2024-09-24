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

void RegisterSwiftNameAttr(nb::module_ &m) {
  nb::class_<SwiftNameAttr, InheritableAttr>(m, "SwiftNameAttr")
    .def("__hash__", [](const SwiftNameAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("name", &SwiftNameAttr::Name)
    .def_prop_ro("name_length", &SwiftNameAttr::NameLength)
    .def_prop_ro("spelling", &SwiftNameAttr::Spelling);
}
} // namespace pasta
