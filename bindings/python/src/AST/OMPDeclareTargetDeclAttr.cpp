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

void RegisterOMPDeclareTargetDeclAttr(nb::module_ &m) {
  nb::class_<OMPDeclareTargetDeclAttr, InheritableAttr>(m, "OMPDeclareTargetDeclAttr")
    .def("__hash__", [](const OMPDeclareTargetDeclAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("dev_type", &OMPDeclareTargetDeclAttr::DevType)
    .def_prop_ro("indirect", &OMPDeclareTargetDeclAttr::Indirect)
    .def_prop_ro("indirect_expression", &OMPDeclareTargetDeclAttr::IndirectExpression)
    .def_prop_ro("level", &OMPDeclareTargetDeclAttr::Level)
    .def_prop_ro("map_type", &OMPDeclareTargetDeclAttr::MapType)
    .def_prop_ro("spelling", &OMPDeclareTargetDeclAttr::Spelling);
}
} // namespace pasta
