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

// Generate `include/pasta/AST/Attr.h`.
void GenerateAttrH(void) {
  std::ofstream os(kASTAttrHeader);
  const std::string attr_base_class{"Attr"};

  os
      << "/*\n"
      << " * Copyright (c) 2022 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#ifndef PASTA_IN_BOOTSTRAP\n"
      << "#include <variant>\n"
      << "#include <vector>\n"
      << "#include <pasta/Util/Compiler.h>\n\n"
      << "#include \"AttrManual.h\"\n\n"
      << "#define PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(base) \\\n"
      << "    friend class AST; \\\n"
      << "    friend class ASTImpl; \\\n"
      << "    friend class Decl; \\\n"
      << "    friend class Stmt; \\\n"
      << "    friend class DeclBuilder; \\\n"
      << "    friend class AttrBuilder; \\\n"
      << "    friend class AttrVisitor; \\\n"
      << "    friend class PrintedTokenRange; \\\n"
      << "    base(void) = delete; \\\n"
      << "    explicit base( \\\n"
      << "        std::shared_ptr<ASTImpl> ast_, \\\n"
      << "        const ::clang::Attr *attr_); \\\n"
      << "   public: \\\n"
      << "    inline const clang::base *RawAttr(void) const noexcept { \\\n"
      << "      return u.base; \\\n"
      << "    }\n\n";

  os  << "namespace pasta {\n\n"
      << "class AST;\n"
      << "class ASTImpl;\n"
      << "class AttrBuilder;\n"
      << "class Decl;\n"
      << "class Decl;\n"
      << "class PrintedTokenRange;\n"
      << "class Stmt;\n\n"
      << "class AttrVisitor {\n"
      << " public:\n"
      << "  virtual ~AttrVisitor(void);\n"
      << "  void Accept(const Attr &);\n";
  
  for (const auto &name : gTopologicallyOrderedAttrs) {
    os << "  virtual void Visit" << name << "(const " << name << " &);\n";
  }

  os
      << "};\n\n"
      << "// Wraps an attribute.\n"
      << "class Attr {\n"
      << " public:\n"
      << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Attr)\n";

  const auto &derived_from_attr = gTransitiveDerivedClasses["Attr"];
  for (const auto &derived_class : derived_from_attr) {
    os << "  PASTA_DECLARE_DERIVED_OPERATORS(Attr, "
       << derived_class << ")\n";
  }

  DeclareCppMethods(os, attr_base_class, gClassIDs[attr_base_class]);

  os
     << "  inline ::pasta::AttrKind Kind(void) const noexcept {\n"
     << "    return kind;\n"
     << "  }\n\n"
     << "  std::string_view KindName(void) const noexcept;\n\n"
     << "  ::pasta::TokenRange Tokens(void) const noexcept;\n\n"
     << "  inline bool operator==(const Attr &that) const noexcept {\n"
     << "    return u.opaque == that.u.opaque;\n"
     << "  }\n"
     << "  static std::optional<::pasta::Attr> From(const TokenContext &);\n\n"
     << " protected:\n"
     << "  friend class TokenContext;\n\n"
     << "  std::shared_ptr<ASTImpl> ast;\n"
     << "  union {\n";

     for (const auto &name : gAttrNames) {
       os << "    const ::clang::" << name << " *" << name << ";\n";
     }

  os
     << "    const void *opaque;\n"
     << "  } u;\n"
     << "  AttrKind kind;\n\n"
     << "  inline Attr(std::shared_ptr<ASTImpl> ast_, const clang::Attr *attr_,\n"
     << "              AttrKind kind_)\n"
     << "      : ast(std::move(ast_)),\n"
     << "        kind(kind_) {\n"
     << "    assert(ast.get() != nullptr);\n"
     << "    u.Attr = attr_;\n"
     << "  }\n\n"
     << " protected:\n"
     << "  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(Attr)\n"
     << "};\n\n";

  // Define them all.
  for (const auto &name : gTopologicallyOrderedAttrs) {
    llvm::StringRef name_ref(name);
    if (name == "Attr") {
      continue;
    }

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
    if (name_ref.ends_with("Attr")) {
      os
          << " private:\n";
      for (const auto &parent_class : gBaseClasses[name]) {
        os << "  using " << parent_class << "::From;\n";
      }
    }

    os  << " public:\n"
        << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(" << name << ")\n";

    // Constructors from derived class -> base class.
    if (name_ref.ends_with("Attr")) {
      for (const auto &base_class : gTransitiveBaseClasses[name]) {
        os << "  PASTA_DECLARE_BASE_OPERATORS(" << base_class << ", "
           << name << ")\n";
      }

      for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
        os << "  PASTA_DECLARE_DERIVED_OPERATORS(" << name << ", "
           << derived_class << ")\n";
      }
    }

    DeclareCppMethods(os, name, gClassIDs[name]);

    os
      << " protected:\n"
      << "  PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR(" << name << ")\n"
      << "};\n\n";

    // Requiring that all derivations have the same size as the base class
    // will let us do fun sketchy things.
    if (name != "Attr" && name_ref.ends_with("Attr")) {
      os << "static_assert(sizeof(Attr) == sizeof(" << name << "));\n\n";
    }
  }

  os
    << "}  // namespace pasta\n"
    << "#undef PASTA_DEFINE_DEFAULT_ATTR_CONSTRUCTOR\n"
    << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
