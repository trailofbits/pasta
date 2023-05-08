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

void RegisterFunctionProtoType(py::module_ &m) {
  py::class_<FunctionProtoType, FunctionType>(m, "FunctionProtoType")
    .def("__hash__", [](const FunctionProtoType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const FunctionProtoType& a, const FunctionProtoType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("CanThrow", &FunctionProtoType::CanThrow)
    .def_property_readonly("Desugar", &FunctionProtoType::Desugar)
    .def_property_readonly("Exceptions", &FunctionProtoType::Exceptions)
    .def_property_readonly("EllipsisToken", &FunctionProtoType::EllipsisToken)
    .def_property_readonly("ExceptionSpecDeclaration", &FunctionProtoType::ExceptionSpecDeclaration)
    .def_property_readonly("ExceptionSpecTemplate", &FunctionProtoType::ExceptionSpecTemplate)
    .def_property_readonly("ExceptionSpecType", &FunctionProtoType::ExceptionSpecType)
    .def_property_readonly("NoexceptExpression", &FunctionProtoType::NoexceptExpression)
    .def_property_readonly("NumExceptions", &FunctionProtoType::NumExceptions)
    .def_property_readonly("NumParameters", &FunctionProtoType::NumParameters)
    .def_property_readonly("ParameterTypes", &FunctionProtoType::ParameterTypes)
    .def_property_readonly("ReferenceQualifier", &FunctionProtoType::ReferenceQualifier)
    .def_property_readonly("HasDependentExceptionSpec", &FunctionProtoType::HasDependentExceptionSpec)
    .def_property_readonly("HasDynamicExceptionSpec", &FunctionProtoType::HasDynamicExceptionSpec)
    .def_property_readonly("HasExceptionSpec", &FunctionProtoType::HasExceptionSpec)
    .def_property_readonly("HasExtParameterInfos", &FunctionProtoType::HasExtParameterInfos)
    .def_property_readonly("HasInstantiationDependentExceptionSpec", &FunctionProtoType::HasInstantiationDependentExceptionSpec)
    .def_property_readonly("HasNoexceptExceptionSpec", &FunctionProtoType::HasNoexceptExceptionSpec)
    .def_property_readonly("HasTrailingReturn", &FunctionProtoType::HasTrailingReturn)
    .def_property_readonly("IsNothrow", &FunctionProtoType::IsNothrow)
    .def_property_readonly("IsSugared", &FunctionProtoType::IsSugared)
    .def_property_readonly("IsTemplateVariadic", &FunctionProtoType::IsTemplateVariadic)
    .def_property_readonly("IsVariadic", &FunctionProtoType::IsVariadic);
}
} // namespace pasta
