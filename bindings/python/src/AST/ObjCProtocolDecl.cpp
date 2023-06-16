/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterObjCProtocolDecl(nb::module_ &m) {
  nb::class_<ObjCProtocolDecl, ObjCContainerDecl>(m, "ObjCProtocolDecl")
    .def("__hash__", [](const ObjCProtocolDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &ObjCProtocolDecl::CanonicalDeclaration)
    .def_prop_ro("definition", &ObjCProtocolDecl::Definition)
    .def_prop_ro("obj_c_runtime_name_as_string", &ObjCProtocolDecl::ObjCRuntimeNameAsString)
    .def_prop_ro("has_definition", &ObjCProtocolDecl::HasDefinition)
    .def_prop_ro("is_non_runtime_protocol", &ObjCProtocolDecl::IsNonRuntimeProtocol)
    .def_prop_ro("is_this_declaration_a_definition", &ObjCProtocolDecl::IsThisDeclarationADefinition)
    .def_prop_ro("protocol_tokens", &ObjCProtocolDecl::ProtocolTokens)
    .def_prop_ro("protocols", &ObjCProtocolDecl::Protocols);
}
} // namespace pasta
