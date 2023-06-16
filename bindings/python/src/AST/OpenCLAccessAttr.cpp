/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterOpenCLAccessAttr(nb::module_ &m) {
  nb::class_<OpenCLAccessAttr, Attr>(m, "OpenCLAccessAttr")
    .def("__hash__", [](const OpenCLAccessAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &OpenCLAccessAttr::SemanticSpelling)
    .def_prop_ro("spelling", &OpenCLAccessAttr::Spelling)
    .def_prop_ro("is_read_only", &OpenCLAccessAttr::IsReadOnly)
    .def_prop_ro("is_read_write", &OpenCLAccessAttr::IsReadWrite)
    .def_prop_ro("is_write_only", &OpenCLAccessAttr::IsWriteOnly);
}
} // namespace pasta
