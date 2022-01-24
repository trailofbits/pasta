/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <fstream>
#include <ostream>
#include <string>

#include "BootstrapConfig.h"
#include "Globals.h"
#include "Util.h"

extern void DeclareCppMethods(std::ostream &os, const std::string &class_name,
                              uint32_t class_id);

// Generate `include/pasta/AST/Stmt.h`.
void GenerateStmtH(void) {
  std::ofstream os(kASTStmtHeader);
  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#ifdef PASTA_IN_BOOTSTRAP\n"
      << "#  include \"StmtBootstrap.h\"\n"
      << "#else\n"
      << "#include <variant>\n"
      << "#include <vector>\n"
      << "#include <pasta/Util/Compiler.h>\n"
      << "#include \"Forward.h\"\n\n"
      << "#include \"StmtManual.h\"\n\n"
      << "#define PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(base) \\\n"
      << "    friend class AST; \\\n"
      << "    friend class ASTImpl; \\\n"
      << "    friend class StmtBuilder; \\\n"
      << "    friend class StmtVisitor; \\\n"
      << "    friend class PrintedTokenRange; \\\n"
      << "    base(void) = delete; \\\n"
      << "    explicit base( \\\n"
      << "        std::shared_ptr<ASTImpl> ast_, \\\n"
      << "        const ::clang::Stmt *decl_); \\\n"
      << "   public: \\\n"
      << "    const clang::base *RawStmt(void) const noexcept { \\\n"
      << "      return u.base; \\\n"
      << "    }\n\n"
      << "namespace pasta {\n"
      << "class StmtVisitor {\n"
      << " public:\n"
      << "  virtual ~StmtVisitor(void);\n"
      << "  void Accept(const Stmt &);\n";

  for (const auto &name : gTopologicallyOrderedStmts) {
    os << "  virtual void Visit" << name << "(const " << name << " &);\n";
  }

  os
      << "};\n\n";

  // Define them all.
  for (const auto &name : gTopologicallyOrderedStmts) {
    llvm::StringRef name_ref(name);
    os
        << "class " << name;

    auto sep = " : ";
    for (const auto &parent_class : gBaseClasses[name]) {
      os << sep << "public " << parent_class;
      sep = ", ";
    }

    os
        << " {\n";

    // Make sure all of the `::From` methods inherited from the parent class
    // are private, so that this class "overrides" them with more derived
    // versions.
    if (name_ref != "Stmt") {
      os
          << " private:\n";
      for (const auto &parent_class : gBaseClasses[name]) {
        if (parent_class != "Stmt") {
          os << "  using " << parent_class << "::From;\n";
        }
      }
    }

    os  << " public:\n"
        << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(" << name << ")\n";

    if (name_ref == "Stmt") {
      os << "  friend class TokenContext;\n"
         << "  static std::optional<::pasta::Stmt> From(const TokenContext &);\n";
    }

    // Constructors from derived class -> base class.
    for (const auto &base_class : gTransitiveBaseClasses[name]) {
      os << "  PASTA_DECLARE_BASE_OPERATORS(" << base_class << ", "
         << name << ")\n";
    }

    for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
      os << "  PASTA_DECLARE_DERIVED_OPERATORS(" << name << ", "
         << derived_class << ")\n";
    }

    DeclareCppMethods(os, name, gClassIDs[name]);

    // The top level `Stmt` class has all the content.
    if (name == "Stmt") {
      os
          << "  inline bool operator==(const Stmt &that) const noexcept {\n"
          << "    return u.opaque == that.u.opaque;\n"
          << "  }\n"
          << " protected:\n"
          << "  std::shared_ptr<ASTImpl> ast;\n"
          << "  union {\n";

      for (const auto &name : gStmtNames) {
        os << "    const ::clang::" << name << " *" << name << ";\n";
      }

      os
          << "    const void *opaque;\n"
          << "  } u;\n"
          << "  StmtKind kind;\n\n"
          << "  inline explicit Stmt(std::shared_ptr<ASTImpl> ast_,\n"
          << "                       const ::clang::Stmt *decl_,\n"
          << "                       StmtKind kind_)\n"
          << "      : ast(std::move(ast_)),\n"
          << "        kind(kind_) {\n"
          << "    u.Stmt = decl_;\n"
          << "  }\n\n";
    }

    os
        << " protected:\n"
        << "  PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR(" << name << ")\n"
        << "};\n\n";

    // Requiring that all derivations have the same size as the base class
    // will let us do fun sketchy things.
    if (name != "Stmt") {
      os << "static_assert(sizeof(Stmt) == sizeof(" << name << "));\n\n";
    }
  }

  os
      << "}  // namespace pasta\n"
      << "#undef PASTA_DEFINE_DEFAULT_STMT_CONSTRUCTOR\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
