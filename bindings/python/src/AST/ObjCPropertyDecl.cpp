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

void RegisterObjCPropertyDecl(nb::module_ &m) {
  nb::class_<ObjCPropertyDecl, NamedDecl>(m, "ObjCPropertyDecl")
    .def_prop_ro("at_token", &ObjCPropertyDecl::AtToken)
    .def_prop_ro("getter_method_declaration", &ObjCPropertyDecl::GetterMethodDeclaration)
    .def_prop_ro("getter_name_token", &ObjCPropertyDecl::GetterNameToken)
    .def_prop_ro("l_paren_token", &ObjCPropertyDecl::LParenToken)
    .def_prop_ro("property_implementation", &ObjCPropertyDecl::PropertyImplementation)
    .def_prop_ro("property_instance_variable_declaration", &ObjCPropertyDecl::PropertyInstanceVariableDeclaration)
    .def_prop_ro("query_kind", &ObjCPropertyDecl::QueryKind)
    .def_prop_ro("setter_kind", &ObjCPropertyDecl::SetterKind)
    .def_prop_ro("setter_method_declaration", &ObjCPropertyDecl::SetterMethodDeclaration)
    .def_prop_ro("setter_name_token", &ObjCPropertyDecl::SetterNameToken)
    .def_prop_ro("type", &ObjCPropertyDecl::Type)
    .def_prop_ro("is_atomic", &ObjCPropertyDecl::IsAtomic)
    .def_prop_ro("is_class_property", &ObjCPropertyDecl::IsClassProperty)
    .def_prop_ro("is_direct_property", &ObjCPropertyDecl::IsDirectProperty)
    .def_prop_ro("is_instance_property", &ObjCPropertyDecl::IsInstanceProperty)
    .def_prop_ro("is_optional", &ObjCPropertyDecl::IsOptional)
    .def_prop_ro("is_read_only", &ObjCPropertyDecl::IsReadOnly)
    .def_prop_ro("is_retaining", &ObjCPropertyDecl::IsRetaining);
}
} // namespace pasta
