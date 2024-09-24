/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterFunctionType(nb::module_ &m) {
  nb::class_<FunctionType, Type>(m, "FunctionType")
    .def_prop_ro("call_conv", &FunctionType::CallConv)
    .def_prop_ro("call_result_type", &FunctionType::CallResultType)
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
