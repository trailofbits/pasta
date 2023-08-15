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

void RegisterAvailabilityAttr(nb::module_ &m) {
  nb::class_<AvailabilityAttr, InheritableAttr>(m, "AvailabilityAttr")
    .def("__hash__", [](const AvailabilityAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("message", &AvailabilityAttr::Message)
    .def_prop_ro("message_length", &AvailabilityAttr::MessageLength)
    .def_prop_ro("replacement", &AvailabilityAttr::Replacement)
    .def_prop_ro("replacement_length", &AvailabilityAttr::ReplacementLength)
    .def_prop_ro("spelling", &AvailabilityAttr::Spelling)
    .def_prop_ro("strict", &AvailabilityAttr::Strict)
    .def_prop_ro("unavailable", &AvailabilityAttr::Unavailable);
}
} // namespace pasta
