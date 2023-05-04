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

void RegisterRecordType(py::module_ &m) {
  py::class_<RecordType, TagType, Type>(m, "RecordType")
    .def("__hash__", [](const RecordType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const RecordType& a, const RecordType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &RecordType::Desugar)
    .def_property_readonly("Declaration", &RecordType::Declaration)
    .def_property_readonly("HasConstFields", &RecordType::HasConstFields)
    .def_property_readonly("IsSugared", &RecordType::IsSugared);
}
} // namespace pasta
