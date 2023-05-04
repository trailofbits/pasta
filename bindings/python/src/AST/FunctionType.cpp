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

void RegisterFunctionType(py::module_ &m) {
  py::class_<FunctionType, Type>(m, "FunctionType")
    .def_property_readonly("CallConv", &FunctionType::CallConv)
    .def("CallResultType", &FunctionType::CallResultType)
    .def_property_readonly("CmseNSCallAttribute", &FunctionType::CmseNSCallAttribute)
    .def_property_readonly("HasRegParm", &FunctionType::HasRegParm)
    .def_property_readonly("NoReturnAttribute", &FunctionType::NoReturnAttribute)
    .def_property_readonly("RegParmType", &FunctionType::RegParmType)
    .def_property_readonly("ReturnType", &FunctionType::ReturnType)
    .def_property_readonly("IsConst", &FunctionType::IsConst)
    .def_property_readonly("IsRestrict", &FunctionType::IsRestrict)
    .def_property_readonly("IsVolatile", &FunctionType::IsVolatile);
}
} // namespace pasta
