/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Printer.h>

#include "Bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterAST(nb::module_ &m) {
  nb::class_<AST>(m, "AST")
    .def_static("containing", nb::overload_cast<const Token &>(&AST::From))
    .def_static("containing", nb::overload_cast<const Decl &>(&AST::From))
    .def_prop_ro("preprocessed_code", &AST::PreprocessedCode)
    .def_prop_ro("tokens", &AST::Tokens)
    .def_prop_ro("macros", &AST::Macros)
    .def_prop_ro("translation_unit", &AST::TranslationUnit)
    .def_prop_ro("main_file", &AST::MainFile)
    .def_prop_ro("parsed_files", &AST::ParsedFiles);
  
  nb::class_<TokenContext>(m, "TokenContext")
    .def_prop_ro("index", &TokenContext::Index)
    .def_prop_ro("kind_name", &TokenContext::KindName)
    .def_prop_ro("kind", &TokenContext::Kind)
    .def_prop_ro("parent", &TokenContext::Parent)
    .def_prop_ro("aliasee", &TokenContext::Aliasee)
    .def("__hash__", [](const TokenContext& c) { return c.Hash(); })
    .def("__eq__", [](const TokenContext& a, const TokenContext& b) { return a == b;});

  nb::class_<CXXBaseSpecifier>(m, "CXXBaseSpecifier");
  nb::class_<TemplateParameterList>(m, "TemplateParameterList");
}
}  // namespace pasta
