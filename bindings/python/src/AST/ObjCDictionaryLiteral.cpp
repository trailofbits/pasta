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

void RegisterObjCDictionaryLiteral(nb::module_ &m) {
  nb::class_<ObjCDictionaryLiteral, Expr>(m, "ObjCDictionaryLiteral")
    .def("__hash__", [](const ObjCDictionaryLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCDictionaryLiteral::Children)
    .def_prop_ro("begin_token", &ObjCDictionaryLiteral::BeginToken)
    .def_prop_ro("dictionary_with_objects_method", &ObjCDictionaryLiteral::DictionaryWithObjectsMethod)
    .def_prop_ro("end_token", &ObjCDictionaryLiteral::EndToken)
    .def_prop_ro("num_elements", &ObjCDictionaryLiteral::NumElements)
    .def_prop_ro("tokens", &ObjCDictionaryLiteral::Tokens);
}
} // namespace pasta
