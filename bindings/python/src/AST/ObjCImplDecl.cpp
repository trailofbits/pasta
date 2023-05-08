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

void RegisterObjCImplDecl(py::module_ &m) {
  py::class_<ObjCImplDecl, ObjCContainerDecl>(m, "ObjCImplDecl")
    .def("__hash__", [](const ObjCImplDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCImplDecl& a, const ObjCImplDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("class_interface", &ObjCImplDecl::ClassInterface)
    .def_property_readonly("property_implementations", &ObjCImplDecl::PropertyImplementations);
}
} // namespace pasta
