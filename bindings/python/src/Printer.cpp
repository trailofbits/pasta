/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include "Bindings.h"

#include <pasta/AST/Printer.h>

namespace pasta {

namespace nb = nanobind;
void RegisterPrinter(nb::module_ &m) {

  nb::enum_<TokenContextKind>(m, "TokenContextKind")
    .value("STATEMENT", TokenContextKind::kStmt)
    .value("DECLARATION", TokenContextKind::kDecl)
    .value("TYPE", TokenContextKind::kType)
    .value("ATTRIBUTE", TokenContextKind::kAttr)
    .value("CXX_BASE_SPECIFIER", TokenContextKind::kCXXBaseSpecifier)
    .value("DESIGNATOR", TokenContextKind::kDesignator)
    .value("TEMPLATE_PARAMETER_LIST", TokenContextKind::kTemplateParameterList)
    .value("TEMPLATE_ARGUMENT", TokenContextKind::kTemplateArgument)
    .value("TYPE_CONSTRAINT", TokenContextKind::kTypeConstraint)
    .value("STRING", TokenContextKind::kString)
    .value("ALIAS", TokenContextKind::kAlias)
    .value("AST", TokenContextKind::kAST);

  nb::class_<TokenContext>(m, "TokenContext")
    .def("__hash__", [](const TokenContext& c) { return c.Hash(); })
    .def("__eq__", [](const TokenContext& a, const TokenContext& b) { return a == b;})
    .def_prop_ro("index", &TokenContext::Index)
    .def_prop_ro("kind", &TokenContext::Kind)
    .def_prop_ro("parent", &TokenContext::Parent)
    .def_prop_ro("aliasee", &TokenContext::Aliasee)
    .def_prop_ro("as_declaration",
        [] (const TokenContext &context) {
          return Decl::From(context);
        })
    .def_prop_ro("as_statement",
        [] (const TokenContext &context) {
          return Stmt::From(context);
        })
    .def_prop_ro("as_type",
        [] (const TokenContext &context) {
          return Type::From(context);
        })
    .def_prop_ro("as_designator",
        [] (const TokenContext &context) {
          return Designator::From(context);
        })
    .def_prop_ro("as_cxx_base_specifier",
        [] (const TokenContext &context) {
          return CXXBaseSpecifier::From(context);
        })
    .def_prop_ro("as_template_parameter_list",
        [] (const TokenContext &context) {
          return TemplateParameterList::From(context);
        })
    .def_prop_ro("as_template_argument",
        [] (const TokenContext &context) {
          return TemplateArgument::From(context);
        });

  nb::class_<PrintedToken>(m, "PrintedToken")
    .def("__hash__", [](const PrintedToken &tok) { return reinterpret_cast<intptr_t>(tok.RawToken()); })
    .def("__eq__", [](const PrintedToken &a, const PrintedToken &b) { return a.RawToken() == b.RawToken(); })
    .def("__str__", &PrintedToken::Data)
    .def_prop_ro("kind", &PrintedToken::Kind)
    .def_prop_ro("index", &PrintedToken::Index)
    .def_prop_ro("data", &PrintedToken::Data)
    .def_prop_ro("leading_spaces",
        [] (const PrintedToken &tok) {
          return std::string(tok.NumLeadingSpaces(), ' ');
        })
    .def_prop_ro("leading_new_lines",
        [] (const PrintedToken &tok) {
          return std::string(tok.NumLeadingSpaces(), '\n');
        })
    .def_prop_ro("context", &PrintedToken::Context);


  nb::class_<PrintedTokenRange>(m, "PrintedTokenRange")
    .def("__getitem__", &PrintedTokenRange::At)
    .def("__bool__", &PrintedTokenRange::operator bool)
    .def("__len__", &PrintedTokenRange::Size)
    .def("__iter__",
        [] (const PrintedTokenRange &v) {
          return nb::make_iterator(
              nb::type<PrintedTokenRange>(), "PrintedTokenIterator", v.begin(), v.end());
        })
    .def("__add__",
        [] (const PrintedTokenRange &a, const PrintedTokenRange &b) {
          return PrintedTokenRange::Concatenate(a, b);
        })
    .def_static("align",
        [] (PrintedTokenRange &a, PrintedTokenRange &b) {
          if (auto err = PrintedTokenRange::Align(a, b)) {
            throw std::move(err.value());
          }
        })
    .def_static("create",
        [] (const Decl &decl) {
          return PrintedTokenRange::Create(decl);
        })
    .def_static("create",
        [] (const Stmt &stmt) {
          return PrintedTokenRange::Create(stmt);
        })
    .def_static("create",
        [] (const Type &type) {
          return PrintedTokenRange::Create(type);
        })
    .def_prop_ro("front", &TokenRange::Front)
    .def_prop_ro("back", &TokenRange::Back);
}

}  // namespace pasta
