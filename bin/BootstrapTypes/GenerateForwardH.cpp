/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <fstream>
#include <ostream>
#include <string>
#include <unordered_set>

#include "BootstrapConfig.h"
#include "Globals.h"
#include "Util.h"

// Declare PASTA versions of every clang enumeration type from our macro file.
extern void DeclareEnums(std::ostream &os, std::ostream &os_py);

// Generate `include/pasta/AST/Forward.h`.
void GenerateForwardH(std::ostream &os_py) {
  std::ofstream os(kASTForwardHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2022, Trail of Bits, Inc.\n"
      << " *\n"
      << " * This source code is licensed in accordance with the terms specified in\n"
      << " * the LICENSE file found in the root directory of this source tree.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n"
      << "#pragma GCC diagnostic push\n"
      << "#pragma GCC diagnostic ignored \"-Wimplicit-int-conversion\"\n"
      << "#pragma GCC diagnostic ignored \"-Wsign-conversion\"\n"
      << "#pragma GCC diagnostic ignored \"-Wshorten-64-to-32\"\n"
      << "#include <llvm/ADT/APSInt.h>\n"
      << "#pragma GCC diagnostic pop\n"
      << "#include <memory>\n"
      << "#include <optional>\n"
      << "#include <string>\n"
      << "#include <string_view>\n\n"
      << "#include \"Token.h\"\n\n"
      << "#define PASTA_IGNORE_ABSTRACT(...)\n\n"
      << "namespace clang {\n";

  for (const auto &name : kAllClassNames) {
    if (name != "OMPDeclarativeDirectiveDecl" &&
        name != "OMPDeclarativeDirectiveValueDecl" &&
        name != "QualifiedType") {
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
      << "#define PASTA_FOR_EACH_DECL_IMPL(m, a) \\\n";

  auto sep = "";
  static constexpr auto kDeclLen = 4u;
  for (const std::string &name_ : gDeclNames) {
    llvm::StringRef name(name_);

    // Abstract ones.
    if (!IsConcreteDecl(name_)) {
      os << sep << "    a(" << name_ << ")";

    } else {
      assert(name.ends_with("Decl"));
      os << sep << "    m(" << name.substr(0, name.size() - kDeclLen).str() << ")";
    }
    sep = " \\\n";
  }

  os
      << "\n\n"
      << "#define PASTA_FOR_EACH_STMT_IMPL(s, d, e, o, l, a) \\\n";

  sep = "";
  for (const std::string &name : gStmtNames) {
    switch (ClassifyStmt(name)) {
      case StmtClassification::kStmt:
        os << sep << "    s(" << name << ")";
        break;
      case StmtClassification::kDirective:
        os << sep << "    d(" << name << ")";
        break;
      case StmtClassification::kExpr:
        os << sep << "    e(" << name << ")";
        break;
      case StmtClassification::kOperator:
        os << sep << "    o(" << name << ")";
        break;
      case StmtClassification::kLiteral:
        os << sep << "    l(" << name << ")";
        break;
      case StmtClassification::kAbstract:
        os << sep << "    a(" << name << ")";
        break;
    }
    sep = " \\\n";
  }

  os
      << "\n\n"
      << "#define PASTA_FOR_EACH_TYPE_IMPL(m, a) \\\n";

  sep = "";
  static constexpr auto kTypeLen = 4u;
  for (const std::string &name_ : gTypeNames) {
    llvm::StringRef name(name_);
    if (!IsConcreteType(name_)) {
      os << sep << "    a(" << name_ << ")";
    } else {
      os << sep << "    m("
         << name.substr(0, name.size() - kTypeLen).str() << ")";
    }
    sep = " \\\n";
  }
  os   
      << "\n\n"
      << "#define PASTA_FOR_EACH_ATTR_IMPL(m, a) \\\n";

  sep = "";
  static constexpr auto kAttrLen = 4u;
  for (const std::string &name_ : gAttrNames) {
    llvm::StringRef name(name_);

    // Abstract ones.
    if (!IsConcreteAttr(name_)) {
      os << sep << "    a(" << name_ << ")";

    } else {
      assert(name.ends_with("Attr"));
      os << sep << "    m(" << name.substr(0, name.size() - kAttrLen).str() << ")";
    }
    sep = " \\\n";
  }

  os
      << "\n\n"
      << "enum class DeclKind : unsigned int {\n"
      << "#define PASTA_DECLARE_DECL_KIND(name) k ## name ,\n"
      << "  PASTA_FOR_EACH_DECL_IMPL(PASTA_DECLARE_DECL_KIND, PASTA_IGNORE_ABSTRACT)\n"
      << "#undef PASTA_DECLARE_DECL_KIND\n"
      << "};\n\n"

      << "enum class AttrKind : unsigned int {\n"
      << "#define PASTA_DECLARE_ATTR_KIND(name) k ## name ,\n"
      << "  PASTA_FOR_EACH_ATTR_IMPL(PASTA_DECLARE_ATTR_KIND, PASTA_IGNORE_ABSTRACT)\n"
      << "#undef PASTA_DECLARE_DECL_KIND\n"
      << "};\n\n";
//      << "enum class TypeKind : unsigned {\n"
//      << "#define PASTA_DECLARE_TYPE_KIND(name) k ## name ,\n"
//      << "  PASTA_FOR_EACH_TYPE_IMPL(PASTA_DECLARE_TYPE_KIND)\n"
//      << "#undef PASTA_DECLARE_TYPE_KIND\n"
//      << "};\n\n";

  // Declare all of the enums.
  os_py << R"(/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <nanobind/nanobind.h>

#include <pasta/AST/Forward.h>

namespace pasta {
namespace nb = nanobind;

void RegisterEnums(nb::module_ &m) {
)";
  DeclareEnums(os, os_py);
  os_py << R"(
}
} // namespace pasta
)";

  os
      << "#define PASTA_FOR_EACH_STMT_KIND(m) \\\n";
  sep = "";
  for (const std::string &stmt_kind : gEnumerators["StmtKind"]) {
    os << sep << "    m(" << stmt_kind << ")";
    sep = " \\\n";
  }

  os
      << "\n\n"
      << "#define PASTA_FOR_EACH_TYPE_KIND(m) \\\n"
      << "    PASTA_FOR_EACH_TYPE_IMPL(m, PASTA_IGNORE_ABSTRACT)\n"
      << "\n"
      << "#define PASTA_FOR_EACH_ATTR_KIND(m) \\\n"
      << "    PASTA_FOR_EACH_ATTR_IMPL(m, PASTA_IGNORE_ABSTRACT)\n"
      << "\n";

  // Forward declare them all.
  for (const auto &name : kAllClassNames) {
    os << "class " << name.str() << ";\n";
  }

  os << "}  // namespace pasta\n";
}
