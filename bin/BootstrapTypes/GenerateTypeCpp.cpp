/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <fstream>
#include <ostream>
#include <string>

#include "BootstrapConfig.h"
#include "Globals.h"
#include "Util.h"

extern void DefineCppMethods(std::ostream &os, const std::string &class_name,
                             uint32_t class_id);

// Generate `lib/AST/Type.cpp`.
void GenerateTypeCpp(void) {
  std::ofstream os(kASTTypeCpp);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#define PASTA_IN_TYPE_CPP\n"
      << "#ifndef PASTA_IN_BOOTSTRAP\n"
      << "#pragma clang diagnostic push\n"
      << "#pragma clang diagnostic ignored \"-Wimplicit-int-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wsign-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wshorten-64-to-32\"\n"
      << "#include <clang/AST/Decl.h>\n"
      << "#include <clang/AST/DeclCXX.h>\n"
      << "#include <clang/AST/DeclFriend.h>\n"
      << "#include <clang/AST/DeclObjC.h>\n"
      << "#include <clang/AST/DeclOpenMP.h>\n"
      << "#include <clang/AST/DeclTemplate.h>\n"
      << "#include <clang/Frontend/CompilerInstance.h>\n"
      << "#pragma clang diagnostic pop\n\n"
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Type.h>\n"
      << "#include \"AST.h\"\n"
      << "#include \"Builder.h\"\n\n"
      << "#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \\\n"
      << "    std::optional<class derived> derived::From(const class base &that) { \\\n"
      << "      if (auto type_ptr = clang::dyn_cast<clang::derived>(that.u.base)) { \\\n"
      << "        return TypeBuilder::Create<class derived>(that.ast, type_ptr); \\\n"
      << "      } else { \\\n"
      << "        return std::nullopt; \\\n"
      << "      } \\\n"
      << "    }\n\n"
      << "#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \\\n"
      << "    base::base(const class derived &that) \\\n"
      << "        : base(that.ast, that.u.base, that.kind, that.qualifiers) {} \\\n"
      << "    base::base(class derived &&that) noexcept \\\n"
      << "        : base(std::move(that.ast), that.u.base, that.kind, that.qualifiers) {} \\\n"
      << "    base &base::operator=(const class derived &that) { \\\n"
      << "      if (ast != that.ast) { \\\n"
      << "        ast = that.ast; \\\n"
      << "      } \\\n"
      << "      u.Type = that.u.Type; \\\n"
      << "      kind = that.kind; \\\n"
      << "      qualifiers = that.qualifiers; \\\n"
      << "      return *this; \\\n"
      << "    } \\\n"
      << "    base &base::operator=(class derived &&that) noexcept { \\\n"
      << "      if (this != &that) { \\\n"
      << "        ast = std::move(that.ast); \\\n"
      << "        u.Type = that.u.Type; \\\n"
      << "        kind = that.kind; \\\n"
      << "        qualifiers = that.qualifiers; \\\n"
      << "      } \\\n"
      << "      return *this; \\\n"
      << "    }\n\n"
      << "namespace pasta {\n\n";

  os  << "TypeVisitor::~TypeVisitor(void) {}\n\n"
      << "void TypeVisitor::Accept(const Type &type) {\n"
      << "  switch (type.Kind()) {\n"
      << "#define PASTA_VISIT_TYPE(name) \\\n"
      << "    case TypeKind::k ## name: \\\n"
      << "      Visit ## name ## Type(reinterpret_cast<const name ## Type &>(type)); \\\n"
      << "      break;\n\n"
      << "    PASTA_FOR_EACH_TYPE_KIND(PASTA_VISIT_TYPE)\n"
      << "#undef PASTA_VISIT_TYPE\n"
      << "  }\n"
      << "}\n\n";

  for (const auto &name : gTopologicallyOrderedTypes) {
    os << "void TypeVisitor::Visit" << name << "(const " << name << " &type) {\n";
    auto seen = false;
    for (const auto &parent_class : gBaseClasses[name]) {
      os << "  Visit" << parent_class << "(type);\n";
      seen = true;
    }
    if (!seen) {
      os << "  (void) type;\n";
    }
    os << "}\n\n";
  }

//  DefineCppMethods(os, decl_context, gClassIDs[decl_context]);

  const std::string qual_type{"QualType"};

  // Define them all.
  for (const auto &name : gTopologicallyOrderedTypes) {
    llvm::StringRef name_ref(name);

    for (const auto &base_class : gTransitiveBaseClasses[name]) {
      if (name == "TypeWithKeyword") {

        // This type has an overloaded `classof` that prevents `clang::dyn_cast`.
        os << "std::optional<class TypeWithKeyword> TypeWithKeyword::From(const class Type &that) {\n"
           << "  if (auto type_ptr1 = clang::dyn_cast<clang::DependentNameType>(that.u.Type)) {\n"
           << "    return TypeBuilder::Create<class TypeWithKeyword>(that.ast, type_ptr1);\n"
           << "  } else if (auto type_ptr2 = clang::dyn_cast<clang::DependentTemplateSpecializationType>(that.u.Type)) {\n"
           << "    return TypeBuilder::Create<class TypeWithKeyword>(that.ast, type_ptr2);\n"
           << "  } else if (auto type_ptr3 = clang::dyn_cast<clang::ElaboratedType>(that.u.Type)) {\n"
           << "    return TypeBuilder::Create<class TypeWithKeyword>(that.ast, type_ptr3);\n"
           << "  } else {\n"
           << "    return std::nullopt;\n"
           << "  }\n"
           << "}\n\n";

      } else {
        os << "PASTA_DEFINE_BASE_OPERATORS(" << base_class << ", "
           << name << ")\n";
      }
    }
    for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
      os << "PASTA_DEFINE_DERIVED_OPERATORS("
         << name << ", " << derived_class << ")\n";
    }
    DefineCppMethods(os, name, gClassIDs[name]);

    // Put the `QualType` methods after the `Type` ones.
    if (name == "Type") {
      DefineCppMethods(os, qual_type, gClassIDs[qual_type]);
    }
  }

  os
      << "}  // namespace pasta\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
