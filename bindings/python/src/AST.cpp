#include <pasta/AST/AST.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterAST(py::module_ &m) {
  py::class_<AST>(m, "AST")
    .def_static("from", py::overload_cast<const Token&>(&AST::From))
    .def_static("from", py::overload_cast<const Decl&>(&AST::From))
    .def_property_readonly("preprocessed_code", &AST::PreprocessedCode)
    .def_property_readonly("tokens", &AST::Tokens)
    .def_property_readonly("macros", &AST::Macros)
    .def_property_readonly("translation_unit", &AST::TranslationUnit)
    .def_property_readonly("main_file", &AST::MainFile)
    .def_property_readonly("parsed_files", &AST::ParsedFiles);
}
}  // namespace pasta