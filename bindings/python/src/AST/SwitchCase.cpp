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

void RegisterSwitchCase(py::module_ &m) {
  py::class_<SwitchCase, Stmt>(m, "SwitchCase")
    .def_property_readonly("BeginToken", &SwitchCase::BeginToken)
    .def_property_readonly("ColonToken", &SwitchCase::ColonToken)
    .def_property_readonly("EndToken", &SwitchCase::EndToken)
    .def_property_readonly("KeywordToken", &SwitchCase::KeywordToken)
    .def_property_readonly("NextSwitchCase", &SwitchCase::NextSwitchCase)
    .def_property_readonly("SubStatement", &SwitchCase::SubStatement);
}
} // namespace pasta
