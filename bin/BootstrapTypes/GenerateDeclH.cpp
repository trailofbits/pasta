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

// Generate `include/pasta/AST/Decl.h`.
void GenerateDeclH(void) {
  std::ofstream os(kASTDeclHeader);
  const std::string decl_context{"DeclContext"};
  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#ifdef PASTA_IN_BOOTSTRAP\n"
      << "#  include \"DeclBootstrap.h\"\n"
      << "#else\n"
      << "#include <variant>\n"
      << "#include <vector>\n"
      << "#include <pasta/Util/Compiler.h>\n"
      << "#include \"Forward.h\"\n\n"
      << "#include \"DeclManual.h\"\n\n"
      << "#define PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(base) \\\n"
      << "    friend class AST; \\\n"
      << "    friend class ASTImpl; \\\n"
      << "    friend class DeclBuilder; \\\n"
      << "    friend class DeclVisitor; \\\n"
      << "    friend class PrintedTokenRange; \\\n"
      << "    base(void) = delete; \\\n"
      << "    explicit base( \\\n"
      << "        std::shared_ptr<ASTImpl> ast_, \\\n"
      << "        const ::clang::Decl *decl_); \\\n"
      << "   public: \\\n"
      << "    const clang::base *RawDecl(void) const noexcept { \\\n"
      << "      return u.base; \\\n"
      << "    }\n\n"
      << "namespace pasta {\n"
      << "class DeclVisitor {\n"
      << " public:\n"
      << "  virtual ~DeclVisitor(void);\n"
      << "  void Accept(const Decl &);\n";

  for (const auto &name : gTopologicallyOrderedDecls) {
    if (name != "DeclContext") {
      os << "  virtual void Visit" << name << "(const " << name << " &);\n";
    }
  }

  os
      << "};\n\n"
      << "class DeclContext {\n"
      << " public:\n"
      << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclContext)\n";

  const auto &derived_from_decl_context =
      gTransitiveDerivedClasses["DeclContext"];
  for (const auto &derived_class : derived_from_decl_context) {
    os << "  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, "
       << derived_class << ")\n";
  }

  DeclareCppMethods(os, decl_context, gClassIDs[decl_context]);

  os << " private:\n"
     << "  friend class Decl;\n"
     << "  friend class DeclVisitor;\n"
     << "  friend class UsingDirectiveDecl;\n"
     << "  friend class SourceLocExpr;\n"
     << "  friend class CXXDefaultArgExpr;\n"
     << "  friend class CXXDefaultInitExpr;\n"
     << "  std::shared_ptr<ASTImpl> ast;\n"
     << "  union {\n"
     << "    void *opaque;\n"
     << "    const ::clang::DeclContext *DeclContext;\n"
     << "  } u;\n"
     << "  inline DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *context_)\n"
     << "      : ast(std::move(ast_)) {\n"
     << "    u.DeclContext = context_;\n"
     << "  }\n"
     << "};\n\n";

  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    llvm::StringRef name_ref(name);
    if (name == "DeclContext") {
      continue;
    }

    os
        << "class " << name;

    auto sep = " : ";
    for (const auto &parent_class : gBaseClasses[name]) {
      if (parent_class != "DeclContext") {
        os << sep << "public " << parent_class;
        sep = ", ";
      }
    }

    os
        << " {\n";

    // Make sure all of the `::From` methods inherited from the parent class
    // are private, so that this class "overrides" them with more derived
    // versions.
    if (name_ref.endswith("Decl") && name_ref != "Decl") {
      os
          << " private:\n";
      for (const auto &parent_class : gBaseClasses[name]) {
        if (parent_class != "DeclContext" && parent_class != "Decl") {
          os << "  using " << parent_class << "::From;\n";
        }
      }
    }

    os  << " public:\n"
        << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(" << name << ")\n";

    // Constructors from derived class -> base class.
    if (name_ref.endswith("Decl")) {

      if (derived_from_decl_context.count(name)) {
        os << "  PASTA_DECLARE_BASE_OPERATORS(DeclContext, "
           << name << ")\n";
      }

      for (const auto &base_class : gTransitiveBaseClasses[name]) {
        os << "  PASTA_DECLARE_BASE_OPERATORS(" << base_class << ", "
           << name << ")\n";
      }

      for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
        os << "  PASTA_DECLARE_DERIVED_OPERATORS(" << name << ", "
           << derived_class << ")\n";
      }
    }

//    // Permits down-casting.
//    for (const auto &base_name : gTransitiveBaseClasses[name]) {
//      if (base_name != "DeclContext") {
//        os << "  static std::optional<" << name << "> From(const "
//           << base_name << " &);\n";
//      }
//    }

    DeclareCppMethods(os, name, gClassIDs[name]);

    // The top level `Decl` class has all the content.
    if (name == "Decl") {
      os
          << "  PASTA_DECLARE_DERIVED_OPERATORS(Decl, DeclContext)\n\n"
          << "  inline DeclKind Kind(void) const {\n"
          << "    return kind;\n"
          << "  }\n\n"
          << "  std::string_view KindName(void) const;\n\n"
          << "  inline bool operator==(const Decl &that) const noexcept {\n"
          << "    return u.opaque == that.u.opaque;\n"
          << "  }\n"
          << " protected:\n"
          << "  std::shared_ptr<ASTImpl> ast;\n"
          << "  union {\n";

      for (const auto &name : gDeclNames) {
        os << "    const ::clang::" << name << " *" << name << ";\n";
      }

      os
          << "    const void *opaque;\n"
          << "  } u;\n"
          << "  DeclKind kind;\n\n"
          << "  inline explicit Decl(std::shared_ptr<ASTImpl> ast_,\n"
          << "                       const ::clang::Decl *decl_,\n"
          << "                       DeclKind kind_)\n"
          << "      : ast(std::move(ast_)),\n"
          << "        kind(kind_) {\n"
          << "    u.Decl = decl_;\n"
          << "  }\n\n";
    }

    os
        << " protected:\n"
        << "  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(" << name << ")\n"
        << "};\n\n";

    // Requiring that all derivations have the same size as the base class
    // will let us do fun sketchy things.
    if (name != "Decl" && name_ref.endswith("Decl")) {
      os << "static_assert(sizeof(Decl) == sizeof(" << name << "));\n\n";
    }
  }

  os
      << "}  // namespace pasta\n"
      << "#undef PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
