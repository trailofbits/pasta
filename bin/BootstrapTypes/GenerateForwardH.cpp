/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <fstream>
#include <ostream>
#include <string>
#include <unordered_set>

#include "BootstrapConfig.h"
#include "Globals.h"
#include "Util.h"

#define DECL_STR1(d) #d
#define DECL_STR2(d) DECL_STR1(d)
#define DECL_STR3(d) DECL_STR2(d)

static const std::unordered_set<std::string> kConcreteDecls{
#define DECL(d, ...) DECL_STR3(d) "Decl",
#define ABSTRACT_DECL(...)
#include <clang/AST/DeclNodes.inc>
};

static const std::unordered_set<std::string> kConcreteStmts{
#define STMT(d, ...) DECL_STR3(d),
#define ABSTRACT_STMT(...)
#include <clang/AST/StmtNodes.inc>
};

static const std::unordered_set<std::string> kConcreteTypes{
#define TYPE(d, base) DECL_STR3(d) "Type",
#define ABSTRACT_TYPE(...)
#include <clang/AST/TypeNodes.inc>
};

static const std::unordered_set<std::string> kConcreteAttrs{
#define ATTR(d, ...) DECL_STR3(d) "Attr",
#include <clang/Basic/AttrList.inc>
};

// Declare PASTA versions of every clang enumeration type from our macro file.
extern void DeclareEnums(std::ostream &os);

// Generate `include/pasta/AST/Forward.h`.
void GenerateForwardH(void) {
  std::ofstream os(kASTForwardHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2022 Trail of Bits, Inc.\n"
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
  for (const auto &name_ : gDeclNames) {
    llvm::StringRef name(name_);

    // Abstract ones.
    if (name == "Decl" ||
        name == "OMPDeclarativeDirectiveDecl" ||
        name == "OMPDeclarativeDirectiveValueDecl" ||
        name == "RedeclarableTemplateDecl" ||
        !kConcreteDecls.count(name_)) {
      os << sep << "    a(" << name_ << ")";

    } else {
      assert(name.endswith("Decl"));
      os << sep << "    m(" << name.substr(0, name.size() - kDeclLen).str() << ")";
    }
    sep = " \\\n";
  }

  os
      << "\n\n"
      << "#define PASTA_FOR_EACH_STMT_IMPL(s, d, e, o, l, a) \\\n";

  sep = "";
  for (const auto &name_ : gStmtNames) {
    llvm::StringRef name(name_);
    if (name == "Stmt" ||
        name == "AbstractConditionalOperator" ||
        name == "AsmStmt" ||
        name == "SwitchCase" ||
        name == "ValueStmt" ||
        name == "Expr" ||
        name == "CoroutineSuspendExpr" ||
        name == "ExplicitCastExpr" ||
        name == "FullExpr" ||
        name == "OverloadExpr" ||
        name == "CastExpr" ||
        name == "CXXNamedCastExpr" ||
        name == "OMPExecutableDirective" ||
        name == "OMPLoopDirective" ||
        name == "OMPLoopBasedDirective" ||
        name == "OMPLoopTransformationDirective" ||
        !kConcreteStmts.count(name_)) {
      os << sep << "    a(" << name.str() << ")";  // Abstract.
    } else if (name.endswith("Stmt") || name == "OMPCanonicalLoop") {
      os << sep << "    s(" << name.str() << ")";
    } else if (name.endswith("Directive")) {
      os << sep << "    d(" << name.str() << ")";
    } else if (name.endswith("Expr") || name == "ExprWithCleanups") {
      os << sep << "    e(" << name.str() << ")";
    } else if (name.endswith("Operator")) {
      os << sep << "    o(" << name.str() << ")";
    } else if (name.endswith("Literal")) {
      os << sep << "    l(" << name.str() << ")";
    } else {
      assert(false);
    }
    sep = " \\\n";
  }

  os
      << "\n\n"
      << "#define PASTA_FOR_EACH_TYPE_IMPL(m, a) \\\n";

  sep = "";
  static constexpr auto kTypeLen = 4u;
  for (const auto &name_ : gTypeNames) {
    llvm::StringRef name(name_);
    if (name == "Type" || name == "TagType" || name == "ReferenceType" ||
        name == "MatrixType" || name == "FunctionType" ||
        name == "DeducedType" || name == "ArrayType" ||
        name == "TypeWithKeyword" || !kConcreteTypes.count(name_)) {
      os << sep << "    a(" << name_ << ")";
    } else {
      os << sep << "    m(" << name.substr(0, name.size() - kTypeLen).str() << ")";
    }
    sep = " \\\n";
  }
  os   
      << sep << "    m(Qualified)"  // Our custom version of `QualType`.
      << "\n\n"
      << "#define PASTA_FOR_EACH_ATTR_IMPL(m, a) \\\n";

  sep = "";
  static constexpr auto kAttrLen = 4u;
  for (const auto &name_ : gAttrNames) {
    llvm::StringRef name(name_);

    // Abstract ones.
    if (name == "Attr" ||
        name == "TypeAttr" ||
        name == "StmtAttr" ||
        name == "DeclOrStmtAttr" ||
        name == "InheritableAttr" ||
        name == "InheritableParamAttr" ||
        name == "ParameterABIAttr" ||
        !kConcreteAttrs.count(name_)) {
      os << sep << "    a(" << name_ << ")";

    } else {
      assert(name.endswith("Attr"));
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
  DeclareEnums(os);

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
