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

void RegisterAnnotateAttr(nb::module_ &m) {
  nb::class_<AnnotateAttr, InheritableParamAttr>(m, "AnnotateAttr")
    .def("__hash__", [](const AnnotateAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("annotation", &AnnotateAttr::Annotation)
    .def_prop_ro("annotation_length", &AnnotateAttr::AnnotationLength)
    .def_prop_ro("spelling", &AnnotateAttr::Spelling);
}
} // namespace pasta
