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

void RegisterObjCInterfaceType(py::module_ &m) {
  py::class_<ObjCInterfaceType, ObjCObjectType, Type>(m, "ObjCInterfaceType")
    .def("__hash__", [](const ObjCInterfaceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ObjCInterfaceType& a, const ObjCInterfaceType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &ObjCInterfaceType::Desugar)
    .def_property_readonly("Declaration", &ObjCInterfaceType::Declaration)
    .def_property_readonly("IsSugared", &ObjCInterfaceType::IsSugared);
}
} // namespace pasta