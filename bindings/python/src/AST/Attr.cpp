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

void RegisterAttr(py::module_ &m) {
  py::class_<Attr>(m, "Attr")
    .def("__hash__", [](const Attr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("token", &Attr::Token)
    .def_property_readonly("spelling", &Attr::Spelling)
    .def_property_readonly("spelling_list_index", &Attr::SpellingListIndex)
    .def_property_readonly("is_implicit", &Attr::IsImplicit)
    .def_property_readonly("is_inherited", &Attr::IsInherited)
    .def_property_readonly("is_late_parsed", &Attr::IsLateParsed)
    .def_property_readonly("is_pack_expansion", &Attr::IsPackExpansion);
}
} // namespace pasta
