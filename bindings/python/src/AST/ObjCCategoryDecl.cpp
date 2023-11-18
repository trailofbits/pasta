/*
 * Copyright (c) 2023 Trail of Bits, Inc.
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

void RegisterObjCCategoryDecl(nb::module_ &m) {
  nb::class_<ObjCCategoryDecl, ObjCContainerDecl>(m, "ObjCCategoryDecl")
    .def_prop_ro("is_class_extension", &ObjCCategoryDecl::IsClassExtension)
    .def_prop_ro("category_name_token", &ObjCCategoryDecl::CategoryNameToken)
    .def_prop_ro("class_interface", &ObjCCategoryDecl::ClassInterface)
    .def_prop_ro("implementation", &ObjCCategoryDecl::Implementation)
    .def_prop_ro("instance_variable_l_brace_token", &ObjCCategoryDecl::InstanceVariableLBraceToken)
    .def_prop_ro("instance_variable_r_brace_token", &ObjCCategoryDecl::InstanceVariableRBraceToken)
    .def_prop_ro("next_class_category", &ObjCCategoryDecl::NextClassCategory)
    .def_prop_ro("next_class_category_raw", &ObjCCategoryDecl::NextClassCategoryRaw)
    .def_prop_ro("instance_variables", &ObjCCategoryDecl::InstanceVariables)
    .def_prop_ro("protocol_tokens", &ObjCCategoryDecl::ProtocolTokens)
    .def_prop_ro("protocols", &ObjCCategoryDecl::Protocols);
}
} // namespace pasta
