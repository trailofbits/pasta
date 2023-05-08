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

void RegisterObjCMethodDecl(py::module_ &m) {
  py::class_<ObjCMethodDecl, NamedDecl>(m, "ObjCMethodDecl")
    .def("__hash__", [](const ObjCMethodDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCMethodDecl& a, const ObjCMethodDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def("DefinedInNSObject", &ObjCMethodDecl::DefinedInNSObject)
    .def_property_readonly("FindPropertyDeclaration", &ObjCMethodDecl::FindPropertyDeclaration)
    .def_property_readonly("BeginToken", &ObjCMethodDecl::BeginToken)
    .def_property_readonly("CanonicalDeclaration", &ObjCMethodDecl::CanonicalDeclaration)
    .def_property_readonly("Category", &ObjCMethodDecl::Category)
    .def_property_readonly("ClassInterface", &ObjCMethodDecl::ClassInterface)
    .def_property_readonly("CommandDeclaration", &ObjCMethodDecl::CommandDeclaration)
    .def_property_readonly("DeclaratorEndToken", &ObjCMethodDecl::DeclaratorEndToken)
    .def_property_readonly("EndToken", &ObjCMethodDecl::EndToken)
    .def_property_readonly("ImplementationControl", &ObjCMethodDecl::ImplementationControl)
    .def_property_readonly("MethodFamily", &ObjCMethodDecl::MethodFamily)
    .def_property_readonly("NumSelectorTokens", &ObjCMethodDecl::NumSelectorTokens)
    .def_property_readonly("ObjCDeclQualifier", &ObjCMethodDecl::ObjCDeclQualifier)
    .def_property_readonly("ReturnType", &ObjCMethodDecl::ReturnType)
    .def_property_readonly("ReturnTypeSourceRange", &ObjCMethodDecl::ReturnTypeSourceRange)
    .def_property_readonly("SelectorStartToken", &ObjCMethodDecl::SelectorStartToken)
    .def_property_readonly("SelfDeclaration", &ObjCMethodDecl::SelfDeclaration)
    .def_property_readonly("HasParameterDestroyedInCallee", &ObjCMethodDecl::HasParameterDestroyedInCallee)
    .def_property_readonly("HasRedeclaration", &ObjCMethodDecl::HasRedeclaration)
    .def_property_readonly("HasRelatedResultType", &ObjCMethodDecl::HasRelatedResultType)
    .def_property_readonly("HasSkippedBody", &ObjCMethodDecl::HasSkippedBody)
    .def_property_readonly("IsClassMethod", &ObjCMethodDecl::IsClassMethod)
    .def_property_readonly("IsDefined", &ObjCMethodDecl::IsDefined)
    .def_property_readonly("IsDesignatedInitializerForTheInterface", &ObjCMethodDecl::IsDesignatedInitializerForTheInterface)
    .def_property_readonly("IsDirectMethod", &ObjCMethodDecl::IsDirectMethod)
    .def_property_readonly("IsInstanceMethod", &ObjCMethodDecl::IsInstanceMethod)
    .def_property_readonly("IsOptional", &ObjCMethodDecl::IsOptional)
    .def_property_readonly("IsOverriding", &ObjCMethodDecl::IsOverriding)
    .def_property_readonly("IsPropertyAccessor", &ObjCMethodDecl::IsPropertyAccessor)
    .def_property_readonly("IsRedeclaration", &ObjCMethodDecl::IsRedeclaration)
    .def_property_readonly("IsSynthesizedAccessorStub", &ObjCMethodDecl::IsSynthesizedAccessorStub)
    .def_property_readonly("IsThisDeclarationADefinition", &ObjCMethodDecl::IsThisDeclarationADefinition)
    .def_property_readonly("IsThisDeclarationADesignatedInitializer", &ObjCMethodDecl::IsThisDeclarationADesignatedInitializer)
    .def_property_readonly("IsVariadic", &ObjCMethodDecl::IsVariadic)
    .def_property_readonly("Parameters", &ObjCMethodDecl::Parameters);
}
} // namespace pasta
