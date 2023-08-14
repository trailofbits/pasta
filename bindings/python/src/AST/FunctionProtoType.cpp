/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterFunctionProtoType(nb::module_ &m) {
  nb::class_<FunctionProtoType, FunctionType>(m, "FunctionProtoType")
    .def("__hash__", [](const FunctionProtoType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("can_throw", &FunctionProtoType::CanThrow)
    .def_prop_ro("desugar", &FunctionProtoType::Desugar)
    .def_prop_ro("exceptions", &FunctionProtoType::Exceptions)
    .def_prop_ro("ellipsis_token", &FunctionProtoType::EllipsisToken)
    .def_prop_ro("exception_spec_declaration", &FunctionProtoType::ExceptionSpecDeclaration)
    .def_prop_ro("exception_spec_template", &FunctionProtoType::ExceptionSpecTemplate)
    .def_prop_ro("exception_spec_type", &FunctionProtoType::ExceptionSpecType)
    .def_prop_ro("noexcept_expression", &FunctionProtoType::NoexceptExpression)
    .def_prop_ro("num_exceptions", &FunctionProtoType::NumExceptions)
    .def_prop_ro("num_parameters", &FunctionProtoType::NumParameters)
    .def_prop_ro("parameter_types", &FunctionProtoType::ParameterTypes)
    .def_prop_ro("reference_qualifier", &FunctionProtoType::ReferenceQualifier)
    .def_prop_ro("has_dependent_exception_spec", &FunctionProtoType::HasDependentExceptionSpec)
    .def_prop_ro("has_dynamic_exception_spec", &FunctionProtoType::HasDynamicExceptionSpec)
    .def_prop_ro("has_exception_spec", &FunctionProtoType::HasExceptionSpec)
    .def_prop_ro("has_ext_parameter_infos", &FunctionProtoType::HasExtParameterInfos)
    .def_prop_ro("has_instantiation_dependent_exception_spec", &FunctionProtoType::HasInstantiationDependentExceptionSpec)
    .def_prop_ro("has_noexcept_exception_spec", &FunctionProtoType::HasNoexceptExceptionSpec)
    .def_prop_ro("has_trailing_return", &FunctionProtoType::HasTrailingReturn)
    .def_prop_ro("is_nothrow", &FunctionProtoType::IsNothrow)
    .def_prop_ro("is_sugared", &FunctionProtoType::IsSugared)
    .def_prop_ro("is_template_variadic", &FunctionProtoType::IsTemplateVariadic)
    .def_prop_ro("is_variadic", &FunctionProtoType::IsVariadic);
}
} // namespace pasta
