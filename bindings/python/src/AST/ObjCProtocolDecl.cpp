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

void RegisterObjCProtocolDecl(py::module_ &m) {
  py::class_<ObjCProtocolDecl, ObjCContainerDecl>(m, "ObjCProtocolDecl")
    .def("__hash__", [](const ObjCProtocolDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &ObjCProtocolDecl::CanonicalDeclaration)
    .def_property_readonly("definition", &ObjCProtocolDecl::Definition)
    .def_property_readonly("obj_c_runtime_name_as_string", &ObjCProtocolDecl::ObjCRuntimeNameAsString)
    .def_property_readonly("has_definition", &ObjCProtocolDecl::HasDefinition)
    .def_property_readonly("is_non_runtime_protocol", &ObjCProtocolDecl::IsNonRuntimeProtocol)
    .def_property_readonly("is_this_declaration_a_definition", &ObjCProtocolDecl::IsThisDeclarationADefinition)
    .def_property_readonly("protocol_tokens", &ObjCProtocolDecl::ProtocolTokens)
    .def_property_readonly("protocols", &ObjCProtocolDecl::Protocols);
}
} // namespace pasta
