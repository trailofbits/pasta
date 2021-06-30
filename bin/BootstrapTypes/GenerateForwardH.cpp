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
      << "using OMPDeclarativeDirectiveDecl = Decl;\n"
      << "using OMPDeclarativeDirectiveValueDecl = ValueDecl;\n"
      << "}  // namespace clang\n"
      << "namespace pasta {\n"
      << "class AST;\n"
      << "class ASTImpl;\n"
      << "class DeclBuilder;\n"
      << "class TypeBuilder;\n\n"
      << "enum class DeclKind : unsigned {\n";

  for (const auto &name_ : gDeclNames) {
    llvm::StringRef name(name_);
    if (name != "Decl") {
      assert(name.endswith("Decl"));
      os << "  k" << name.substr(0, name.size() - 4).str() << ",\n";
    }
  }

  os
      << "};\n\n"
      << "enum class TypeKind : unsigned {\n";

  for (const auto &name_ : gTypeNames) {
    llvm::StringRef name(name_);
    if (name != "Type") {
      os << "  k" << name.substr(0, name.size() - 4).str() << ",\n";
    }
  }

  os
      << "};\n\n";

  // Declare all of the enums.
  DeclareEnums(os);

  // Forward declare them all.
  for (const auto &name : kAllClassNames) {
    os << "class " << name.str() << ";\n";
  }

  os
      << "}  // namespace pasta\n";
}
