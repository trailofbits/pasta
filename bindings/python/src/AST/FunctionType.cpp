/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterFunctionType(nb::module_ &m) {
  nb::class_<FunctionType, Type>(m, "FunctionType")
    .def("__hash__", [](const FunctionType &type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("call_conv", &FunctionType::CallConv)
    .def("call_result_type", &FunctionType::CallResultType)
    .def_prop_ro("cmse_ns_call_attribute", &FunctionType::CmseNSCallAttribute)
    .def_prop_ro("has_reg_parm", &FunctionType::HasRegParm)
    .def_prop_ro("no_return_attribute", &FunctionType::NoReturnAttribute)
    .def_prop_ro("reg_parm_type", &FunctionType::RegParmType)
    .def_prop_ro("return_type", &FunctionType::ReturnType)
    .def_prop_ro("is_const", &FunctionType::IsConst)
    .def_prop_ro("is_restrict", &FunctionType::IsRestrict)
    .def_prop_ro("is_volatile", &FunctionType::IsVolatile);
}
} // namespace pasta
