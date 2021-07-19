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

// Generate `lib/AST/Decl.cpp`.
void GenerateDeclCpp(void) {
  std::ofstream os(kASTDeclCpp);
  const std::string decl_context{"DeclContext"};

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#ifndef PASTA_IN_BOOTSTRAP\n"
      << "#include <pasta/AST/Decl.h>\n\n"
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
      << "#pragma clang diagnostic pop\n\n"
      << "#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \\\n"
      << "    base::base(const class derived &that) \\\n"
      << "        : base(that.ast, that.u.Decl) {} \\\n"
      << "    base::base(class derived &&that) noexcept \\\n"
      << "        : base(std::move(that.ast), that.u.Decl) {} \\\n"
      << "    base &base::operator=(const class derived &that) { \\\n"
      << "      if (ast != that.ast) { \\\n"
      << "        ast = that.ast; \\\n"
      << "      } \\\n"
      << "      u.Decl = that.u.Decl; \\\n"
      << "      return *this; \\\n"
      << "    } \\\n"
      << "    base &base::operator=(class derived &&that) noexcept { \\\n"
      << "      if (this != &that) { \\\n"
      << "        ast = std::move(that.ast); \\\n"
      << "        u.Decl = that.u.Decl; \\\n"
      << "      } \\\n"
      << "      return *this; \\\n"
      << "    }\n\n"
      << "#define PASTA_DEFINE_DECLCONTEXT_OPERATORS(base, derived) \\\n"
      << "    base::base(const class derived &that) \\\n"
      << "        : base(that.ast, clang::dyn_cast<clang::derived>(that.u.Decl)) {} \\\n"
      << "    base::base(class derived &&that) noexcept \\\n"
      << "        : base(std::move(that.ast), clang::dyn_cast<clang::derived>(that.u.Decl)) {} \\\n"
      << "    base &base::operator=(const class derived &that) { \\\n"
      << "      if (ast != that.ast) { \\\n"
      << "        ast = that.ast; \\\n"
      << "      } \\\n"
      << "      u.DeclContext = clang::dyn_cast<clang::derived>(that.u.Decl); \\\n"
      << "      return *this; \\\n"
      << "    } \\\n"
      << "    base &base::operator=(class derived &&that) noexcept { \\\n"
      << "      ast = std::move(that.ast); \\\n"
      << "      u.DeclContext = clang::dyn_cast<clang::derived>(that.u.Decl); \\\n"
      << "      return *this; \\\n"
      << "    }\n\n"
      << "#include \"AST.h\"\n\n"
      << "namespace pasta {\n\n"
      << "class DeclBuilder {\n"
      << " public:\n"
      << "  template <typename T, typename D>\n"
      << "  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *decl_) {\n"
      << "    return T(std::move(ast_), decl_);\n"
      << "  }\n"
      << "};\n\n";

  os
      << "Decl::Decl(const class DeclContext &context)\n"
      << "   : Decl(context.ast, clang::dyn_cast<clang::Decl>(context.u.DeclContext)) {}\n"
      << "\n"
      << "Decl::Decl(class DeclContext &&context) noexcept\n"
      << "   : Decl(std::move(context.ast), clang::dyn_cast<clang::Decl>(context.u.DeclContext)) {}\n"
      << "\n"
      << "Decl &Decl::operator=(const class DeclContext &context) {\n"
      << "  if (ast != context.ast) {\n"
      << "    ast = context.ast;\n"
      << "  }\n"
      << "  u.Decl = clang::dyn_cast<clang::Decl>(context.u.DeclContext);\n"
      << "  return *this;\n"
      << "}\n"
      << "\n"
      << "Decl &Decl::operator=(class DeclContext &&context) noexcept {\n"
      << "  if (ast != context.ast) {\n"
      << "    ast = std::move(context.ast);\n"
      << "  }\n"
      << "  u.Decl = clang::dyn_cast<clang::Decl>(context.u.DeclContext);\n"
      << "  return *this;\n"
      << "}\n\n";

  for (const auto &derived_class : gTransitiveDerivedClasses["DeclContext"]) {
    os << "PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, "
       << derived_class << ")\n";
  }

  os
      << "\n"
      << "namespace {\n"
      << "// Return the PASTA `DeclKind` for a Clang `Decl`.\n"
      << "static DeclKind KindOfDecl(const clang::Decl *decl) {\n"
      << "  switch (decl->getKind()) {\n"
      << "#define ABSTRACT_DECL(DECL)\n"
      << "#define DECL(DERIVED, BASE) \\\n"
      << "    case clang::Decl::DERIVED: \\\n"
      << "      return DeclKind::k ## DERIVED;\n"
      << "#include <clang/AST/DeclNodes.inc>\n"
      << "  }\n"
      << "  __builtin_unreachable();\n"
      << "}\n\n"
      << "static const std::string_view kKindNames[] = {\n";

  for (const auto &name_ : gDeclNames) {
    llvm::StringRef name(name_);
    if (name != "Decl" && name != "OMPDeclarativeDirectiveDecl" &&
        name != "OMPDeclarativeDirectiveValueDecl") {
      assert(name.endswith("Decl"));
      name = name.substr(0, name.size() - 4);
      os << "  \"" << name.str() << "\",\n";
    }
  }

  os
      << "};\n"
      << "}  // namespace\n\n"
      << "std::string_view Decl::KindName(void) const {\n"
      << "  return kKindNames[static_cast<unsigned>(kind)];\n"
      << "}\n\n";


  DefineCppMethods(os, decl_context, gClassIDs[decl_context]);

  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    llvm::StringRef name_ref(name);
    if (name == "DeclContext") {
      continue;
    }

    os
        << name << "::" << name << "(\n"
        << "    std::shared_ptr<ASTImpl> ast_,\n"
        << "    const ::clang::Decl *decl_)";

    // Dispatch to our hand-written constructor that takes the `DeclKind`.
    if (name == "Decl") {
      os << "\n    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}\n";

    // Dispatch to the base class constructor(s).
    } else {
      auto sep = "\n    : ";
      const auto &base_classes = gBaseClasses[name];
      auto prefix = base_classes.size() == 1u ? "std::move(" : "";
      auto suffix = base_classes.size() == 1u ? ")" : "";
      for (const auto &parent_class : base_classes) {
        if (parent_class != "DeclContext") {
          os << sep << parent_class << "(" << prefix << "ast_" << suffix
             << ", decl_)";
          sep = ",\n      ";
        }
      }
      os << " {}\n\n";
    }

    // Constructors from derived class -> base class.
    if (name_ref.endswith("Decl")) {
      for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
        os << "PASTA_DEFINE_DERIVED_OPERATORS("
           << name << ", " << derived_class << ")\n";
      }
    }
    DefineCppMethods(os, name, gClassIDs[name]);
  }

  os
      << "}  // namespace pasta\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
