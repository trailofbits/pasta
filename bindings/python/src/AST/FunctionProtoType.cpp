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

void RegisterFunctionProtoType(py::module_ &m) {
  py::class_<FunctionProtoType, FunctionType>(m, "FunctionProtoType")
    .def("__hash__", [](const FunctionProtoType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const FunctionProtoType& a, const FunctionProtoType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("can_throw", &FunctionProtoType::CanThrow)
    .def_property_readonly("desugar", &FunctionProtoType::Desugar)
    .def_property_readonly("exceptions", &FunctionProtoType::Exceptions)
    .def_property_readonly("ellipsis_token", &FunctionProtoType::EllipsisToken)
    .def_property_readonly("exception_spec_declaration", &FunctionProtoType::ExceptionSpecDeclaration)
    .def_property_readonly("exception_spec_template", &FunctionProtoType::ExceptionSpecTemplate)
    .def_property_readonly("exception_spec_type", &FunctionProtoType::ExceptionSpecType)
    .def_property_readonly("noexcept_expression", &FunctionProtoType::NoexceptExpression)
    .def_property_readonly("num_exceptions", &FunctionProtoType::NumExceptions)
    .def_property_readonly("num_parameters", &FunctionProtoType::NumParameters)
    .def_property_readonly("parameter_types", &FunctionProtoType::ParameterTypes)
    .def_property_readonly("reference_qualifier", &FunctionProtoType::ReferenceQualifier)
    .def_property_readonly("has_dependent_exception_spec", &FunctionProtoType::HasDependentExceptionSpec)
    .def_property_readonly("has_dynamic_exception_spec", &FunctionProtoType::HasDynamicExceptionSpec)
    .def_property_readonly("has_exception_spec", &FunctionProtoType::HasExceptionSpec)
    .def_property_readonly("has_ext_parameter_infos", &FunctionProtoType::HasExtParameterInfos)
    .def_property_readonly("has_instantiation_dependent_exception_spec", &FunctionProtoType::HasInstantiationDependentExceptionSpec)
    .def_property_readonly("has_noexcept_exception_spec", &FunctionProtoType::HasNoexceptExceptionSpec)
    .def_property_readonly("has_trailing_return", &FunctionProtoType::HasTrailingReturn)
    .def_property_readonly("is_nothrow", &FunctionProtoType::IsNothrow)
    .def_property_readonly("is_sugared", &FunctionProtoType::IsSugared)
    .def_property_readonly("is_template_variadic", &FunctionProtoType::IsTemplateVariadic)
    .def_property_readonly("is_variadic", &FunctionProtoType::IsVariadic);
}
} // namespace pasta
