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


  nb::class_<Designator>(m, "Designator")
    .def("__hash__", [](const Designator &d) { return reinterpret_cast<intptr_t>(d.RawDesignator()); })
    .def("__eq__", [](const Designator &a, const Designator &b) { return a.RawDesignator() == b.RawDesignator(); })
    .def_prop_ro("is_field_designator", &Designator::IsFieldDesignator)
    .def_prop_ro("is_array_designator", &Designator::IsArrayDesignator)
    .def_prop_ro("is_array_range_designator", &Designator::IsArrayRangeDesignator)
    .def_prop_ro("field", &Designator::Field)
    .def_prop_ro("tokens", &Designator::Tokens)
    .def_prop_ro("dot_token", &Designator::DotToken)
    .def_prop_ro("field_token", &Designator::FieldToken)
    .def_prop_ro("left_bracket_token", &Designator::LeftBracketToken)
    .def_prop_ro("right_bracket_token", &Designator::RightBracketToken)
    .def_prop_ro("ellipsis_token", &Designator::EllipsisToken)
    .def_prop_ro("first_expression_index", &Designator::FirstExpressionIndex);

  nb::class_<CXXBaseSpecifier>(m, "CXXBaseSpecifier")
    .def("__hash__", [](const CXXBaseSpecifier &d) { return reinterpret_cast<intptr_t>(d.RawCXXBaseSpecifier()); })
    .def("__eq__", [](const CXXBaseSpecifier &a, const CXXBaseSpecifier &b) { return a.RawCXXBaseSpecifier() == b.RawCXXBaseSpecifier(); })
    .def_prop_ro("tokens", &CXXBaseSpecifier::Tokens)
    .def_prop_ro("base_type_token", &CXXBaseSpecifier::BaseTypeToken)
    .def_prop_ro("is_virtual", &CXXBaseSpecifier::IsVirtual)
    .def_prop_ro("base_kind", &CXXBaseSpecifier::BaseKind)
    .def_prop_ro("is_pack_expansion", &CXXBaseSpecifier::IsPackExpansion)
    .def_prop_ro("ellipsis_token", &CXXBaseSpecifier::EllipsisToken)
    .def_prop_ro("semantic_access_specifier", &CXXBaseSpecifier::SemanticAccessSpecifier)
    .def_prop_ro("lexical_access_specifier", &CXXBaseSpecifier::LexicalAccessSpecifier)
    .def_prop_ro("base_type", &CXXBaseSpecifier::BaseType);

  nb::class_<TemplateParameterList>(m, "TemplateParameterList")
    .def("__hash__", [](const TemplateParameterList &d) { return reinterpret_cast<intptr_t>(d.RawTemplateParameterList()); })
    .def("__eq__", [](const TemplateParameterList &a, const TemplateParameterList &b) { return a.RawTemplateParameterList() == b.RawTemplateParameterList(); })
    .def_prop_ro("num_parameters", &TemplateParameterList::NumParameters)
    .def_prop_ro("num_required_parameters", &TemplateParameterList::NumRequiredParameters)
    .def_prop_ro("depth", &TemplateParameterList::Depth)
    .def_prop_ro("has_unexpanded_parameter_pack", &TemplateParameterList::HasUnexpandedParameterPack)
    .def_prop_ro("has_parameter_pack", &TemplateParameterList::HasParameterPack)
    .def_prop_ro("requires_clause", &TemplateParameterList::RequiresClause)
    .def_prop_ro("template_keyword_token", &TemplateParameterList::TemplateKeywordToken)
    .def_prop_ro("left_angle_token", &TemplateParameterList::LeftAngleToken)
    .def_prop_ro("right_angle_token", &TemplateParameterList::RightAngleToken)
    .def_prop_ro("tokens", &TemplateParameterList::Tokens)
    .def_prop_ro("parameters", &TemplateParameterList::Parameters);

  nb::class_<TemplateArgument>(m, "TemplateArgument")
    .def("__hash__", [](const TemplateArgument &d) { return reinterpret_cast<intptr_t>(d.RawTemplateArgument()); })
    .def("__eq__", [](const TemplateArgument &a, const TemplateArgument &b) { return a.RawTemplateArgument() == b.RawTemplateArgument(); })
    .def("__bool__", [] (const TemplateArgument &a) { return !a.IsNull(); })
    .def_prop_ro("kind", &TemplateArgument::Kind)
    .def_prop_ro("is_empty", &TemplateArgument::IsNull)
    .def_prop_ro("is_dependent", &TemplateArgument::IsDependent)
    .def_prop_ro("is_instantiation_dependent", &TemplateArgument::IsInstantiationDependent)
    .def_prop_ro("contains_unexpanded_parameter_pack", &TemplateArgument::ContainsUnexpandedParameterPack)
    .def_prop_ro("is_pack_expansion", &TemplateArgument::IsPackExpansion)
    .def_prop_ro("as_declaration", &TemplateArgument::AsDeclaration)
    .def_prop_ro("as_type", &TemplateArgument::AsType)
    .def_prop_ro("parameter_type_for_declaration", &TemplateArgument::ParameterTypeForDeclaration)
    .def_prop_ro("null_pointer_type", &TemplateArgument::NullPointerType);
}

}  // namespace pasta
