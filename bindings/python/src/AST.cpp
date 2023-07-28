/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Printer.h>

#include "bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterAST(nb::module_ &m) {
  nb::class_<AST>(m, "AST")
    .def_static("from", nb::overload_cast<const Token&>(&AST::From))
    .def_static("from", nb::overload_cast<const Decl&>(&AST::From))
    .def_prop_ro("preprocessed_code", &AST::PreprocessedCode)
    .def_prop_ro("tokens", &AST::Tokens)
    .def_prop_ro("macros", &AST::Macros)
    .def_prop_ro("translation_unit", &AST::TranslationUnit)
    .def_prop_ro("main_file", &AST::MainFile)
    .def_prop_ro("parsed_files", &AST::ParsedFiles);

  nb::class_<Token>(m, "Token")
    .def_prop_ro("derived_location", &Token::DerivedLocation)
    .def_prop_ro("derivation_chain", &Token::DerivationChain)
    .def_prop_ro("file_location", &Token::FileLocation)
    .def_prop_ro("macro_location", &Token::MacroLocation)
    .def_prop_ro("associated_macro", &Token::AssociatedMacro)
    .def("is_derived_from_macro", &Token::IsDerivedFromMacro)
    .def_prop_ro("data", &Token::Data)
    .def_prop_ro("index", &Token::Index)
    .def_prop_ro("kind", &Token::Kind)
    .def_prop_ro("role", &Token::Role)
    .def_prop_ro("kind_name", &Token::KindName)
    .def_prop_ro("next_final_expansion_or_file_token", &Token::NextFinalExpansionOrFileToken)
    .def_prop_ro("prev_final_expansion_or_file_token", &Token::PrevFinalExpansionOrFileToken)
    .def("__hash__", [](const Token& token) { return token.Hash(); })
    .def("__eq__", [](const Token& a, const Token& b) { return a == b;});
  
  nb::class_<TokenContext>(m, "TokenContext")
    .def_prop_ro("index", &TokenContext::Index)
    .def_prop_ro("kind_name", &TokenContext::KindName)
    .def_prop_ro("kind", &TokenContext::Kind)
    .def_prop_ro("parent", &TokenContext::Parent)
    .def_prop_ro("aliasee", &TokenContext::Aliasee)
    .def("try_update_to_parent", &TokenContext::TryUpdateToParent)
    .def("try_update_to_aliasee", &TokenContext::TryUpdateToAliasee)
    .def("__hash__", [](const TokenContext& c) { return c.Hash(); })
    .def("__eq__", [](const TokenContext& a, const TokenContext& b) { return a == b;});

  nb::class_<TokenRange>(m, "TokenRange");
  nb::class_<Macro>(m, "Macro");

  nb::class_<CXXBaseSpecifier>(m, "CXXBaseSpecifier");
  nb::class_<TemplateParameterList>(m, "TemplateParameterList");
}
}  // namespace pasta
