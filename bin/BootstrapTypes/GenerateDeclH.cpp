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
      << "#define PASTA_DECLARE_DERIVED_OPERATORS(base, derived) \\\n"
      << "      friend class derived; \\\n"
      << "      base(const derived &that_); \\\n"
      << "      base(derived &&that_) noexcept;  \\\n"
      << "      base &operator=(const derived &);  \\\n"
      << "      base &operator=(derived &&) noexcept;\n\n"
      << "#define PASTA_DECLARE_DEFAULT_CONSTRUCTORS(cls) \\\n"
      << "  ~cls(void) = default; \\\n"
      << "  cls(const cls &) = default; \\\n"
      << "  cls(cls &&) noexcept = default; \\\n"
      << "  cls &operator=(const cls &) = default; \\\n"
      << "  cls &operator=(cls &&) noexcept = default;\n\n"
      << "namespace pasta {\n"
      << "class DeclContext {\n"
      << " public:\n"
      << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclContext)\n";

  for (const auto &derived_class : gTransitiveDerivedClasses["DeclContext"]) {
    os << "  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, "
       << derived_class << ")\n";
  }

  os << " private:\n"
     << "  std::shared_ptr<ASTImpl> ast;\n"
     << "  const clang::DeclContext *context;\n\n"
     << "  inline DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *context_)\n"
     << "      : ast(std::move(ast_)),\n"
     << "        context(context_) {}\n"
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
        << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(" << name << ")\n";

    // Constructors from derived class -> base class.
    if (name_ref.endswith("Decl")) {
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
      << "#undef PASTA_DECLARE_DERIVED_OPERATORS\n"
      << "#undef PASTA_DECLARE_DEFAULT_CONSTRUCTORS\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
