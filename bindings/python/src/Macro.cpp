/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <pasta/AST/Macro.h>

#include "Bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterMacro(nb::module_ &m) {

  nb::enum_<MacroKind>(m, "MacroKind")
    .value("TOKEN", MacroKind::kToken)
    .value("SUBSTITUTION", MacroKind::kSubstitution)
    .value("EXPANSION", MacroKind::kExpansion)
    .value("ARGUMENT", MacroKind::kArgument)
    .value("PARAMETER", MacroKind::kParameter)
    .value("OTHER_DIRECTIVE", MacroKind::kOtherDirective)
    .value("IF_DIRECTIVE", MacroKind::kIfDirective)
    .value("IF_DEFINED_DIRECTIVE", MacroKind::kIfDefinedDirective)
    .value("IF_NOT_DEFINED_DIRECTIVE", MacroKind::kIfNotDefinedDirective)
    .value("ELSE_IF_DIRECTIVE", MacroKind::kElseIfDirective)
    .value("ELSE_IF_DEFINED_DIRECTIVE", MacroKind::kElseIfDefinedDirective)
    .value("ELSE_IF_NOT_DEFINED_DIRECTIVE", MacroKind::kElseIfNotDefinedDirective)
    .value("ELSE_DIRECTIVE", MacroKind::kElseDirective)
    .value("END_IF_DIRECTIVE", MacroKind::kEndIfDirective)
    .value("DEFINE_DIRECTIVE", MacroKind::kDefineDirective)
    .value("UNDEFINE_DIRECTIVE", MacroKind::kUndefineDirective)
    .value("PRAGMA_DIRECTIVE", MacroKind::kPragmaDirective)
    .value("INCLUDE_DIRECTIVE", MacroKind::kIncludeDirective)
    .value("INCLUDE_NEXT_DIRECTIVE", MacroKind::kIncludeNextDirective)
    .value("INCLUDE_MACROS_DIRECTIVE", MacroKind::kIncludeMacrosDirective)
    .value("IMPORT_DIRECTIVE", MacroKind::kImportDirective)
    .value("PARAMETER_SUBSTITUTION", MacroKind::kParameterSubstitution)
    .value("STRINGIFY", MacroKind::kStringify)
    .value("CONCATENATE", MacroKind::kConcatenate)
    .value("VA_OPT", MacroKind::kVAOpt)
    .value("VA_OPT_ARGUMENT", MacroKind::kVAOptArgument);

  nb::class_<MacroRange>(m, "MacroRange")
    .def("__getitem__", &MacroRange::At)
    .def("__bool__", &MacroRange::operator bool)
    .def("__len__", &MacroRange::Size)
    .def("__iter__",
        [](const MacroRange &v) {
          return nb::make_iterator(
              nb::type<MacroRange>(), "MacroIterator", v.begin(), v.end());
        })
    .def_prop_ro("front", &MacroRange::Front)
    .def_prop_ro("back", &MacroRange::Back);

  nb::class_<Macro>(m, "Macro")
    .def("__hash__", [](const Macro &macro) { return reinterpret_cast<intptr_t>(macro.RawMacro()); })
    .def("__eq__", [](const Macro &a, const Macro &b) { return a.RawMacro() == b.RawMacro(); })
    .def("__ne__", [](const Macro &a, const Macro &b) { return a.RawMacro() != b.RawMacro(); })
    .def("__str__", &Token::Data)
    .def_prop_ro("kind", &Macro::Kind)
    .def_prop_ro("parent", &Macro::Parent)
    .def_prop_ro("children", &Macro::Children)
    .def_prop_ro("first_use_token", &Macro::BeginToken)
    .def_prop_ro("last_use_token", &Macro::EndToken);

  nb::class_<MacroToken, Macro>(m, "MacroToken")
    .def("__str__", &MacroToken::Data)
    .def_prop_ro("token_kind", &MacroToken::TokenKind)
    .def_prop_ro("data", &MacroToken::Data)
    .def_prop_ro("file_location", &MacroToken::FileLocation)
    .def_prop_ro("associated_macro", &MacroToken::AssociatedMacro);

  nb::class_<MacroDirective, Macro>(m, "MacroDirective")
    .def_prop_ro("hash_token", &MacroDirective::Hash)
    .def_prop_ro("directive_name_token", &MacroDirective::DirectiveName);

  nb::class_<IncludeLikeMacroDirective, MacroDirective>(m, "IncludeLikeMacroDirective")
    .def_prop_ro("included_file", &IncludeLikeMacroDirective::IncludedFile);

  nb::class_<ConditionalMacroDirective, MacroDirective>(m, "ConditionalMacroDirective");

#define TO_STR_(a) #a
#define TO_STR(a) TO_STR_(a)

#define PASTA_IGNORE(...)
#define PASTA_MAKE_DIRECTIVE(kind) \
    PASTA_MAKE_DIRECTIVE_BASE(kind, MacroDirective)

#define PASTA_MAKE_INCLUDE_DIRECTIVE(kind) \
    PASTA_MAKE_DIRECTIVE_BASE(kind, IncludeLikeMacroDirective)

#define PASTA_MAKE_COND_DIRECTIVE(kind) \
    PASTA_MAKE_DIRECTIVE_BASE(kind, ConditionalMacroDirective)

#define PASTA_MAKE_DIRECTIVE_BASE(kind, base) \
    nb::class_<kind ## MacroDirective, base>(m, TO_STR(kind ## MacroDirective));

PASTA_FOR_EACH_MACRO_IMPL(PASTA_IGNORE,
                          PASTA_IGNORE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_COND_DIRECTIVE,
                          PASTA_IGNORE,
                          PASTA_MAKE_INCLUDE_DIRECTIVE,
                          PASTA_IGNORE)
#undef PASTA_IGNORE
#undef PASTA_MAKE_DIRECTIVE
#undef PASTA_MAKE_INCLUDE_DIRECTIVE
#undef PASTA_MAKE_DIRECTIVE_BASE

  nb::class_<MacroParameter, Macro>(m, "MacroParameter")
    .def_prop_ro("variadic_dots_token", &MacroParameter::VariadicDots)
    .def_prop_ro("name_token", &MacroParameter::Name)
    .def_prop_ro("index", &MacroParameter::Index);

  nb::class_<DefineMacroDirective, MacroDirective>(m, "DefineMacroDirective")
    .def_prop_ro("name_token", &DefineMacroDirective::Name)
    .def_prop_ro("uses", &DefineMacroDirective::Uses)
    .def_prop_ro("body", &DefineMacroDirective::Body)
    .def_prop_ro("num_explicit_parameters", &DefineMacroDirective::NumExplicitParameters)
    .def_prop_ro("is_variadic", &DefineMacroDirective::IsVariadic)
    .def_prop_ro("is_function_like", &DefineMacroDirective::IsFunctionLike)
    .def_prop_ro("is_builtin", &DefineMacroDirective::IsBuiltin)
    .def_prop_ro("is_command_linw", &DefineMacroDirective::IsCommandLine)
    .def_prop_ro("parameters", &DefineMacroDirective::Parameters);

  nb::class_<MacroArgument, Macro>(m, "MacroArgument")
    .def_prop_ro("is_variadic", &MacroArgument::IsVariadic)
    .def_prop_ro("index", &MacroArgument::Index);

  nb::class_<MacroSubstitution, Macro>(m, "MacroSubstitution")
    .def_prop_ro("replacement_children", &MacroSubstitution::ReplacementChildren)
    .def_prop_ro("first_fully_substituted_token", &MacroSubstitution::FirstFullySubstitutedToken)
    .def_prop_ro("last_fully_substituted_token", &MacroSubstitution::LastFullySubstitutedToken)
    .def_prop_ro("name_or_operator_token", &MacroSubstitution::NameOrOperator);

  nb::class_<MacroParameterSubstitution, MacroSubstitution>(m, "MacroParameterSubstitution")
    .def_prop_ro("parameter", &MacroParameterSubstitution::Parameter)
    .def_prop_ro("parameter_use_token", &MacroParameterSubstitution::ParameterUse);

  nb::class_<MacroExpansion, MacroSubstitution>(m, "MacroExpansion")
    .def_static("containing", &MacroExpansion::Containing)
    .def_prop_ro("intermediate_children", &MacroExpansion::IntermediateChildren)
    .def_prop_ro("definition", &MacroExpansion::Definition)
    .def_prop_ro("arguments", &MacroExpansion::Arguments)
    .def_prop_ro("is_argument_pre_expansion", &MacroExpansion::IsArgumentPreExpansion)
    .def_prop_ro("argument_pre_expansion", &MacroExpansion::ArgumentPreExpansion);

  nb::class_<MacroStringify, MacroSubstitution>(m, "MacroStringify")
    .def_prop_ro("stringified_token", &MacroStringify::StringifiedToken);

  nb::class_<MacroConcatenate, MacroSubstitution>(m, "MacroConcatenate")
    .def_prop_ro("pasted_token", &MacroConcatenate::PastedToken);

  nb::class_<MacroVAOpt, Macro>(m, "MacroVAOpt")
    .def_prop_ro("contents_are_elided", &MacroVAOpt::ContentsAreElided);

  nb::class_<MacroVAOptArgument, Macro>(m, "MacroVAOptArgument");
}

}  // namespace pasta
