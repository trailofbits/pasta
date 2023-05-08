/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterOMPCaptureKindAttr(py::module_ &m) {
  py::class_<OMPCaptureKindAttr, Attr>(m, "OMPCaptureKindAttr")
    .def("__hash__", [](const OMPCaptureKindAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OMPCaptureKindAttr& a, const OMPCaptureKindAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("capture_kind_value", &OMPCaptureKindAttr::CaptureKindValue)
    .def_property_readonly("spelling", &OMPCaptureKindAttr::Spelling);
}
} // namespace pasta
