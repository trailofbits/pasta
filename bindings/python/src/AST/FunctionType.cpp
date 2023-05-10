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

void RegisterFunctionType(py::module_ &m) {
  py::class_<FunctionType, Type>(m, "FunctionType")
    .def("__hash__", [](const FunctionType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const FunctionType& a, const FunctionType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("call_conv", &FunctionType::CallConv)
    .def("call_result_type", &FunctionType::CallResultType)
    .def_property_readonly("cmse_ns_call_attribute", &FunctionType::CmseNSCallAttribute)
    .def_property_readonly("has_reg_parm", &FunctionType::HasRegParm)
    .def_property_readonly("no_return_attribute", &FunctionType::NoReturnAttribute)
    .def_property_readonly("reg_parm_type", &FunctionType::RegParmType)
    .def_property_readonly("return_type", &FunctionType::ReturnType)
    .def_property_readonly("is_const", &FunctionType::IsConst)
    .def_property_readonly("is_restrict", &FunctionType::IsRestrict)
    .def_property_readonly("is_volatile", &FunctionType::IsVolatile);
}
} // namespace pasta
