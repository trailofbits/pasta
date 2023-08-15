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

void RegisterUnavailableAttr(nb::module_ &m) {
  nb::class_<UnavailableAttr, InheritableAttr>(m, "UnavailableAttr")
    .def("__hash__", [](const UnavailableAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("implicit_reason", &UnavailableAttr::ImplicitReason)
    .def_prop_ro("message", &UnavailableAttr::Message)
    .def_prop_ro("message_length", &UnavailableAttr::MessageLength)
    .def_prop_ro("spelling", &UnavailableAttr::Spelling);
}
} // namespace pasta
