/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <fstream>
#include <ostream>
#include <string>

#include "BootstrapConfig.h"
#include "Globals.h"
#include "Util.h"

// Declare PASTA versions of every clang enumeration type from our macro file.
extern void DeclareEnums(std::ostream &os);

// Generate `include/pasta/AST/Forward.h`.
void GenerateForwardH(void) {
  std::ofstream os(kASTForwardHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n"
      << "#include <memory>\n"
      << "#include <optional>\n"
      << "#include <string>\n"
      << "#include <string_view>\n\n"
      << "#include \"Token.h\"\n\n"
      << "namespace clang {\n";

  for (const auto &name : kAllClassNames) {
    if (name != "OMPDeclarativeDirectiveDecl" &&
        name != "OMPDeclarativeDirectiveValueDecl") {
      os << "class " << name.str() << ";\n";
    }
  }

  os
      << "#ifndef PASTA_IN_DECL_CPP\n"
      << "using OMPDeclarativeDirectiveDecl = Decl;\n"
      << "using OMPDeclarativeDirectiveValueDecl = ValueDecl;\n"
      << "#endif  // PASTA_IN_DECL_CPP\n"
      << "}  // namespace clang\n"
      << "namespace pasta {\n"
      << "class AST;\n"
      << "class ASTImpl;\n"
      << "class DeclBuilder;\n"
      << "class TypeBuilder;\n\n"
      << "#define PASTA_FOR_EACH_DECL_IMPL(m) \\\n";

  auto sep = "";
  for (const auto &name_ : gDeclNames) {
    llvm::StringRef name(name_);
    if (name != "Decl" && name != "OMPDeclarativeDirectiveDecl" &&
        name != "OMPDeclarativeDirectiveValueDecl") {
      assert(name.endswith("Decl"));
      os << sep << "    m(" << name.substr(0, name.size() - 4).str() << ")";
      sep = " \\\n";
    }
  }

  os
      << "\n\n"
      << "#define PASTA_FOR_EACH_TYPE_IMPL(m) \\\n";

  sep = "";
  for (const auto &name_ : gTypeNames) {
    llvm::StringRef name(name_);
    if (name != "Type") {
      os << sep << "    m(" << name.substr(0, name.size() - 4).str() << ")";
      sep = " \\\n";
    }
  }

  os
      << "\n\n"
      << "enum class DeclKind : unsigned {\n"
      << "#define PASTA_DECLARE_DECL_KIND(name) k ## name ,\n"
      << "  PASTA_FOR_EACH_DECL_IMPL(PASTA_DECLARE_DECL_KIND)\n"
      << "#undef PASTA_DECLARE_DECL_KIND\n"
      << "};\n\n";
//      << "enum class TypeKind : unsigned {\n"
//      << "#define PASTA_DECLARE_TYPE_KIND(name) k ## name ,\n"
//      << "  PASTA_FOR_EACH_TYPE_IMPL(PASTA_DECLARE_TYPE_KIND)\n"
//      << "#undef PASTA_DECLARE_TYPE_KIND\n"
//      << "};\n\n";

  // Declare all of the enums.
  DeclareEnums(os);

  os
      << "#define PASTA_FOR_EACH_TYPE_CLASS(m) \\\n";
  sep = "";
  for (const std::string &type_class : gEnumerators["TypeClass"]) {
    os << sep << "    m(" << type_class << ")";
    sep = " \\\n";
  }

  os << "\n\n";

  // Forward declare them all.
  for (const auto &name : kAllClassNames) {
    os << "class " << name.str() << ";\n";
  }

  os
      << "class OMPDeclarativeDirectiveDecl;\n"
      << "class OMPDeclarativeDirectiveValueDecl;\n"
      << "}  // namespace pasta\n";
}
