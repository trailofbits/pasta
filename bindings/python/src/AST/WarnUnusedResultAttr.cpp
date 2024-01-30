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

void RegisterWarnUnusedResultAttr(nb::module_ &m) {
  nb::class_<WarnUnusedResultAttr, InheritableAttr>(m, "WarnUnusedResultAttr")
    .def("__hash__", [](const WarnUnusedResultAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("is_cxx11_no_discard", &WarnUnusedResultAttr::IsCXX11NoDiscard)
    .def_prop_ro("message", &WarnUnusedResultAttr::Message)
    .def_prop_ro("message_length", &WarnUnusedResultAttr::MessageLength)
    .def_prop_ro("semantic_spelling", &WarnUnusedResultAttr::SemanticSpelling)
    .def_prop_ro("spelling", &WarnUnusedResultAttr::Spelling);
}
} // namespace pasta
