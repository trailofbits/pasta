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

void RegisterEnableIfAttr(nb::module_ &m) {
  nb::class_<EnableIfAttr, InheritableAttr>(m, "EnableIfAttr")
    .def("__hash__", [](const EnableIfAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("condition", &EnableIfAttr::Condition)
    .def_prop_ro("message", &EnableIfAttr::Message)
    .def_prop_ro("message_length", &EnableIfAttr::MessageLength)
    .def_prop_ro("spelling", &EnableIfAttr::Spelling);
}
} // namespace pasta
