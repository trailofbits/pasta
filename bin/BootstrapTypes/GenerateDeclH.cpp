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

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#ifdef PASTA_IN_BOOTSTRAP\n"
      << "#  include \"DeclBootstrap.h\"\n"
      << "#else\n"
      << "#include \"Forward.h\"\n\n"
      << "namespace pasta {\n"
      << "class DeclContext {\n"
      << " public:\n"
      << "  DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *) {}\n"
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
        << " {\n"
        << " public:\n"
        << "  ~" << name << "(void) = default;\n"
        << "  " << name << "(const " << name << " &) = default;\n"
        << "  " << name << "(" << name << " &&) noexcept = default;\n"
        << "  " << name << " &operator=(const " << name << " &) = default;\n"
        << "  " << name << " &operator=(" << name << " &&) noexcept = default;\n\n";

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
        << " private:\n"
        << "  " << name << "(void) = delete;\n\n"
        << "  friend class DeclBuilder;\n"
        << "  friend class AST;\n"
        << "  friend class ASTImpl;\n\n"
        << " protected:\n"
        << "  explicit " << name << "(\n"
        << "      std::shared_ptr<ASTImpl> ast_,\n"
        << "      const ::clang::Decl *decl_);\n"
        << "};\n\n";

    // Requiring that all derivations have the same size as the base class
    // will let us do fun sketchy things.
    if (name != "Decl" && name_ref.endswith("Decl")) {
      os << "static_assert(sizeof(Decl) == sizeof(" << name << "));\n\n";

    // Require all `Type` derivations to have the same size as `Type`.
    } else if (name != "Type" && name_ref.endswith("Type")) {
      os << "static_assert(sizeof(Type) == sizeof(" << name << "));\n\n";
    }
  }

  os
      << "}  // namespace pasta\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
