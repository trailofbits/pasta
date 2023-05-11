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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterRecordType(py::module_ &m) {
  py::class_<RecordType, TagType>(m, "RecordType")
    .def("__hash__", [](const RecordType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &RecordType::Desugar)
    .def_property_readonly("declaration", &RecordType::Declaration)
    .def_property_readonly("has_const_fields", &RecordType::HasConstFields)
    .def_property_readonly("is_sugared", &RecordType::IsSugared);
}
} // namespace pasta
