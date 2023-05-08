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

void RegisterObjCProtocolDecl(py::module_ &m) {
  py::class_<ObjCProtocolDecl, ObjCContainerDecl>(m, "ObjCProtocolDecl")
    .def("__hash__", [](const ObjCProtocolDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCProtocolDecl& a, const ObjCProtocolDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &ObjCProtocolDecl::CanonicalDeclaration)
    .def_property_readonly("Definition", &ObjCProtocolDecl::Definition)
    .def_property_readonly("ObjCRuntimeNameAsString", &ObjCProtocolDecl::ObjCRuntimeNameAsString)
    .def_property_readonly("HasDefinition", &ObjCProtocolDecl::HasDefinition)
    .def_property_readonly("IsNonRuntimeProtocol", &ObjCProtocolDecl::IsNonRuntimeProtocol)
    .def_property_readonly("IsThisDeclarationADefinition", &ObjCProtocolDecl::IsThisDeclarationADefinition)
    .def_property_readonly("ProtocolTokens", &ObjCProtocolDecl::ProtocolTokens)
    .def_property_readonly("Protocols", &ObjCProtocolDecl::Protocols);
}
} // namespace pasta
