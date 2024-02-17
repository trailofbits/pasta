/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include "Bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterToken(nb::module_ &m) {

  nb::enum_<TokenRole>(m, "TokenRole")
    .value("INVALID", TokenRole::kInvalid)
    .value("BEGIN_OF_FILE_MARKER", TokenRole::kBeginOfFileMarker)
    .value("FILE_TOKEN", TokenRole::kFileToken)
    .value("END_OF_FILE_MARKER", TokenRole::kEndOfFileMarker)
    .value("INITIAL_MACRO_USE_TOKEN", TokenRole::kInitialMacroUseToken)
    .value("INTERMEDIATE_MACRO_EXPANSION_TOKEN", TokenRole::kIntermediateMacroExpansionToken)
    .value("FINAL_MACRO_EXPANSION_TOKEN", TokenRole::kFinalMacroExpansionToken)
    .value("EMPTY_OR_SPECIAL_MACRO_TOKEN", TokenRole::kEmptyOrSpecialMacroToken);

  nb::class_<Token>(m, "Token")
    .def("__bool__", &Token::operator bool)
    .def("__hash__", [](const Token &tok) { return reinterpret_cast<intptr_t>(tok.RawToken()); })
    .def("__eq__", [](const Token &a, const Token &b) { return a.RawToken() == b.RawToken(); })
    .def("__str__", &Token::Data)
    .def_prop_ro("kind", &Token::Kind)
    .def_prop_ro("role", &Token::Role)
    .def_prop_ro("index", &Token::Index)
    .def_prop_ro("data", &Token::Data)
    .def_prop_ro("associated_macro", &Token::AssociatedMacro)
    .def_prop_ro("derived_location", &Token::DerivedLocation)
    .def_prop_ro("file_location", &Token::FileLocation)
    .def_prop_ro("macro_location", &Token::MacroLocation);

  nb::class_<TokenRange>(m, "TokenRange")
    .def("__getitem__", &TokenRange::At)
    .def("__bool__", &TokenRange::operator bool)
    .def("__len__", &TokenRange::Size)
    .def("__contains__", &TokenRange::Contains)
    .def("__iter__",
        [](const TokenRange &v) {
          return nb::make_iterator(
              nb::type<TokenRange>(), "TokenIterator", v.begin(), v.end());
        })
    .def_prop_ro("front", &TokenRange::Front)
    .def_prop_ro("back", &TokenRange::Back);
}

}  // namespace pasta
