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

// Generate `include/pasta/AST/Type.h`.
void GenerateTypeH(void) {
  std::ofstream os(kASTTypeHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#ifndef PASTA_IN_BOOTSTRAP\n"
      << "#include <variant>\n"
      << "#include <vector>\n"
      << "#include <pasta/Util/Compiler.h>\n"
      << "#include \"Forward.h\"\n\n"
      << "#define PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(base) \\\n"
      << "    friend class AST; \\\n"
      << "    friend class ASTImpl; \\\n"
      << "    friend class TypeBuilder; \\\n"
      << "    friend class TypeVisitor; \\\n"
      << "    base(void) = delete; \\\n"
      << "    explicit base( \\\n"
      << "        std::shared_ptr<ASTImpl> ast_, \\\n"
      << "        const ::clang::Type *type_); \\\n"
      << "    explicit base( \\\n"
      << "        std::shared_ptr<ASTImpl> ast_, \\\n"
      << "        const ::clang::QualType &type_);\n\n";


  os
      << "namespace pasta {\n"
      << "class TypeBuilder;\n\n"
      << "class TypeVisitor {\n"
      << " public:\n"
      << "  virtual ~TypeVisitor(void);\n"
      << "  void Accept(const Type &);\n";
  for (const auto &name : gTopologicallyOrderedTypes) {
    os << "  virtual void Visit" << name << "(const " << name << " &);\n";
  }

  const std::string type{"Type"};
  const std::string qual_type{"QualType"};

  os
      << "};\n\n"
      << "// Wraps a type, including its qualifiers.\n"
      << "class Type {\n"
      << " protected:\n"
      << "  friend class TypeBuilder;\n\n"
      << "  std::shared_ptr<ASTImpl> ast;\n"
      << "  union {\n";
  for (const auto &name : gTopologicallyOrderedTypes) {
    os
        << "    const ::clang::" << name << " *" << name << ";\n";
  }
  os
      << "    void *opaque;\n"
      << "  } u;\n"
      << "  ::pasta::TypeClass type_class;\n"
      << "  uint32_t qualifiers;\n\n"
      << "  inline explicit Type(std::shared_ptr<ASTImpl> ast_,\n"
      << "                       const ::clang::Type *type_,\n"
      << "                       ::pasta::TypeClass type_class_,\n"
      << "                       uint32_t qualifiers_)\n"
      << "      : ast(std::move(ast_)),\n"
      << "        type_class(type_class_),\n"
      << "        qualifiers(qualifiers_) {\n"
      << "    u.Type = type_;\n"
      << "  }\n\n"
      << " public:\n"
      << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Type)\n";

  const auto &derived_from_type =
      gTransitiveDerivedClasses[type];
  for (const auto &derived_class : derived_from_type) {
    os << "  PASTA_DECLARE_DERIVED_OPERATORS(Type, "
       << derived_class << ")\n";
  }

  os
      << "  inline bool operator==(const Type &that) const noexcept {\n"
      << "    return u.opaque == that.u.opaque && qualifiers == that.qualifiers;\n"
      << "  }\n"
      << "  inline bool operator!=(const Type &that) const noexcept {\n"
      << "    return u.opaque != that.u.opaque || qualifiers != that.qualifiers;\n"
      << "  }\n";


  for (const auto &[class_name, method_name_] : gMethodNames) {
    if (class_name == type || class_name == qual_type) {
      const auto meth_name = CxxName(method_name_);
      llvm::StringRef method_name(meth_name);
      if (method_name.endswith("Decl") || method_name.endswith("Unsafe") ||
          method_name.startswith("As")) {
        kCanReturnNullptr.emplace(class_name, meth_name);
      }
    }
  }
  DeclareCppMethods(os, type, gClassIDs[type]);
  os
      << "  inline bool IsQualified(void) const noexcept {\n"
      << "    return qualifiers;\n"
      << "  }\n"
      << "  inline Type UnqualifiedType(void) const noexcept {\n"
      << "    return Type(ast, u.Type, type_class, 0);\n"
      << "  }\n";

  DeclareCppMethods(os, qual_type, gClassIDs[qual_type]);

  os << "};";

  // Define them all.
  for (const auto &name : gTopologicallyOrderedTypes) {
    llvm::StringRef name_ref(name);
    if (name == type || name == qual_type) {
      continue;
    }

    os
        << "\n\nclass " << name;

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
    os
        << " private:\n";
    for (const auto &parent_class : gBaseClasses[name]) {
      os << "  using " << parent_class << "::" << parent_class << ";\n";

      if (parent_class != "Type") {
        os << "  using " << parent_class << "::From;\n";
      }
    }

    os  << " public:\n"
        << "  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(" << name << ")\n";

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

    os
        << " protected:\n"
        << "  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(" << name << ")\n"
        << "};\n";

    // Requiring that all derivations have the same size as the base class
    // will let us do fun sketchy things.
    os << "static_assert(sizeof(Type) == sizeof(" << name << "));";
  }

  os
      << "\n\n}  // namespace pasta\n"
      << "#undef PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR\n"
      << "#endif  // !PASTA_IN_BOOTSTRAP\n";
}
