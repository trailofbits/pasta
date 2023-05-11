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

void RegisterObjCTypeParamType(py::module_ &m) {
  py::class_<ObjCTypeParamType, Type>(m, "ObjCTypeParamType")
    .def("__hash__", [](const ObjCTypeParamType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &ObjCTypeParamType::Desugar)
    .def_property_readonly("declaration", &ObjCTypeParamType::Declaration)
    .def_property_readonly("is_sugared", &ObjCTypeParamType::IsSugared);
}
} // namespace pasta
