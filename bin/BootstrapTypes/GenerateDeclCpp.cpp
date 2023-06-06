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
                             uint32_t class_id, std::ostream &os_py);

// Generate `lib/AST/Decl.cpp`.
void GenerateDeclCpp(std::ostream& py_cmake, std::ostream& py_ast) {
  std::ofstream os(kASTDeclCpp);
  const std::string decl_context{"DeclContext"};
  const auto &derived_from_decl_context =
      gTransitiveDerivedClasses[decl_context];

  os
      << "/*\n"
      << " * Copyright (c) 2022 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#define PASTA_IN_DECL_CPP\n"
      << "#ifndef PASTA_IN_BOOTSTRAP\n"
      << "#pragma clang diagnostic push\n"
      << "#pragma clang diagnostic ignored \"-Wimplicit-int-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wsign-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wshorten-64-to-32\"\n"
      << "#pragma clang diagnostic ignored \"-Wbitfield-enum-conversion\"\n"
      << "#include <clang/AST/Attr.h>\n"
      << "#include <clang/AST/Decl.h>\n"
      << "#include <clang/AST/DeclCXX.h>\n"
      << "#include <clang/AST/DeclFriend.h>\n"
      << "#include <clang/AST/DeclObjC.h>\n"
      << "#include <clang/AST/DeclOpenMP.h>\n"
      << "#include <clang/AST/DeclTemplate.h>\n"
      << "#include <clang/Frontend/CompilerInstance.h>\n"
      << "#include <stdexcept>\n"
      << "#pragma clang diagnostic pop\n\n"
      << "namespace clang {\n"
      << "using OMPDeclarativeDirectiveDecl = OMPDeclarativeDirective<Decl>;\n"
      << "using OMPDeclarativeDirectiveValueDecl = OMPDeclarativeDirective<ValueDecl>;\n"
      << "}  // namespace clang\n\n"
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Stmt.h>\n"
      << "#include <pasta/AST/Type.h>\n"
      << "#include \"AST.h\"\n"
      << "#include \"Builder.h\"\n\n"
      << "#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \\\n"
      << "    std::optional<class derived> derived::From(const class base &that) { \\\n"
      << "      if (auto decl_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.base)) { \\\n"
      << "        return DeclBuilder::Create<class derived>(that.ast, decl_ptr); \\\n"
      << "      } else { \\\n"
      << "        return std::nullopt; \\\n"
      << "      } \\\n"
      << "    }\n\n"
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
      << "      kind = that.kind; \\\n"
      << "      return *this; \\\n"
      << "    } \\\n"
      << "    base &base::operator=(class derived &&that) noexcept { \\\n"
      << "      class derived new_that(std::forward<class derived>(that)); \\\n"
      << "      ast = std::move(new_that.ast); \\\n"
      << "      u.Decl = new_that.u.Decl; \\\n"
      << "      kind = new_that.kind; \\\n"
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
      << "namespace pasta {\n"
      << "namespace {\n"
      << "// Return the PASTA `DeclKind` for a Clang `Decl`.\n"
      << "static DeclKind KindOfDecl(const clang::Decl *decl) {\n"
      << "  switch (decl->getKind()) {\n"
      << "#define PASTA_DECL_CASE(name) \\\n"
      << "    case clang::Decl::name: return DeclKind::k ## name;\n\n"
      << "PASTA_FOR_EACH_DECL_IMPL(PASTA_DECL_CASE, PASTA_IGNORE_ABSTRACT)\n"
      << "#undef PASTA_DECL_CASE\n"
      << "    default: break;\n"
      << "  }\n"
      << "  " PASTA_ASSERT_THROW "\"The unreachable has been reached\");\n"
      << "}\n\n"
      << "static const std::string_view kKindNames[] = {\n"
      << "#define PASTA_DECL_KIND_NAME(name) #name ,\n"
      << "PASTA_FOR_EACH_DECL_IMPL(PASTA_DECL_KIND_NAME, PASTA_IGNORE_ABSTRACT)\n"
      << "#undef PASTA_DECL_KIND_NAME\n"
      << "};\n"
      << "}  // namespace\n\n";

  os  << "DeclVisitor::~DeclVisitor(void) {}\n\n"
      << "void DeclVisitor::Accept(const Decl &decl) {\n"
      << "  switch (decl.Kind()) {\n"
      << "#define PASTA_VISIT_DECL(name) \\\n"
      << "    case DeclKind::k ## name: \\\n"
      << "      Visit ## name ## Decl(reinterpret_cast<const name ## Decl &>(decl)); \\\n"
      << "      break;\n\n"
      << "    PASTA_FOR_EACH_DECL_IMPL(PASTA_VISIT_DECL, PASTA_IGNORE_ABSTRACT)\n"
      << "#undef PASTA_VISIT_DECL\n"
      << "  }\n"
      << "}\n\n";

  for (const auto &name : gTopologicallyOrderedDecls) {
    if (name != "DeclContext") {
      os << "void DeclVisitor::Visit" << name << "(const " << name << " &decl) {\n";
      auto seen = false;
      for (const auto &parent_class : gBaseClasses[name]) {
        if (parent_class != "DeclContext") {
          os << "  Visit" << parent_class << "(decl);\n";
          seen = true;
        }
      }
      if (!seen) {
        os << "  (void) decl;\n";
      }
      os << "}\n\n";
    }
  }

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
      << "std::string_view Decl::KindName(void) const noexcept {\n"
      << "  return kKindNames[static_cast<unsigned>(kind)];\n"
      << "}\n\n"

      // All decls use the same mechanis for token ranges.
      << "::pasta::TokenRange Decl::Tokens(void) const noexcept {\n"
      << "  return ast->DeclTokenRange(u.Decl);\n"
      << "}\n\n"

      // We manually "virtualize" `Decl::getLocation`, which isn't normally
      // virtualized.
      << "::pasta::Token Decl::Token(void) const noexcept {\n"
      << "  clang::SourceLocation loc;\n"
      << "  switch (u.Decl->getKind()) {\n"
      << "#define ABSTRACT_DECL(DECL)\n"
      << "#define DECL(DERIVED, BASE) \\\n"
      << "    case clang::Decl::DERIVED: \\\n"
      << "      loc = (u.DERIVED ## Decl)->getLocation(); \\\n"
      << "      break;\n"
      << "#include <clang/AST/DeclNodes.inc>\n"
      << "  }\n"
      << "  return ast->TokenAt(loc);\n"
      << "}\n\n";


  {
    py_cmake << "    \"" << kPythonBindingsPath << "/DeclContext.cpp\"\n";
    py_ast << "void RegisterDeclContext(py::module_ &m);\n"
           << "  RegisterDeclContext(m);\n";
  
    std::ofstream decl_context_os(std::string(kPythonBindingsPath) + "/DeclContext.cpp");
    decl_context_os << R"(/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterDeclContext(py::module_ &m) {
  py::class_<DeclContext>(m, "DeclContext"))";

    DefineCppMethods(os, decl_context, gClassIDs[decl_context], decl_context_os);

    decl_context_os << ";\n"
          << "}\n"
          << "} // namespace pasta\n";
  }

  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    llvm::StringRef name_ref(name);
    if (name == "DeclContext") {
      continue;
    }


    py_cmake << "    \"" << kPythonBindingsPath << "/" << name << ".cpp\"\n";
    py_ast << "void Register" << name << "(py::module_ &m);\n"
           << "  Register" << name << "(m);\n";

    std::ofstream os_py(std::string(kPythonBindingsPath) + "/" + name + ".cpp");
    os_py << R"(/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void Register)" << name << "(py::module_ &m) {\n"
      << "  py::class_<" << name;

    os
        << name << "::" << name << "(\n"
        << "    std::shared_ptr<ASTImpl> ast_,\n"
        << "    const ::clang::Decl *decl_)";

    // Dispatch to our hand-written constructor that takes the `DeclKind`.
    if (name == "Decl") {
      os << "\n    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}\n\n";

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

      if (derived_from_decl_context.count(name)) {
        os << "PASTA_DEFINE_BASE_OPERATORS(DeclContext, "
           << name << ")\n";
      }

      // These are annoying; these classes don't technically exist, so we need
      // to "find" them by inferring them from their derived classes, which we
      // shimmed in.
      if (name == "OMPDeclarativeDirectiveDecl" ||
          name == "OMPDeclarativeDirectiveValueDecl") {
        for (const auto &base_class : gTransitiveBaseClasses[name]) {
          os << "std::optional<" << name << "> " << name << "::From(const "
             << base_class << " &that) {\n"
             << "  if (false) {\n"
             << "    return std::nullopt;\n";

          for (const auto &derived_class : gDerivedClasses[name]) {
            os << "  } else if (auto p_" << derived_class
               << " = clang::dyn_cast<clang::" << derived_class << ">(that.u.Decl)) {\n"
               << "    return DeclBuilder::Create<" << name << ">(that.ast, p_" << derived_class << ");\n";
          }

          os << "  } else {\n"
             << "    return std::nullopt;\n"
             << "  }\n"
             << "}\n\n";

        }
        for(const auto &base_class : gBaseClasses[name]) {
          if(base_class == "DeclContext") { continue; }
          os_py << ", " << base_class;
        }

      // Normal case.
      } else {
        for (const auto &base_class : gTransitiveBaseClasses[name]) {
          os << "PASTA_DEFINE_BASE_OPERATORS(" << base_class << ", "
             << name << ")\n";
        }
        for(const auto &base_class : gBaseClasses[name]) {
          if(base_class == "DeclContext") { continue; }
          os_py << ", " << base_class;
        }
      }

      for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
        os << "PASTA_DEFINE_DERIVED_OPERATORS("
           << name << ", " << derived_class << ")\n";
      }
    }

    os_py << ">(m, \"" << name << "\")"
          << "\n    .def(\"__hash__\", [](const " << name << "& decl) { return (intptr_t)decl.RawDecl(); })"
          << "\n    .def(\"__eq__\", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })";
    DefineCppMethods(os, name, gClassIDs[name], os_py);

    // We need to manually inject our own `Body` method. Normally there would
    // be `Decl::Body`, but we explicitly remove that. We make is so that
    // `FunctionDecl::Body` only returns something if the request is coming
    // from the function definition itself.
    if (name == "FunctionDecl") {
      os
      << "std::optional<::pasta::Stmt> FunctionDecl::Body(void) const noexcept {\n"
      << "  const clang::FunctionDecl *decl = u.FunctionDecl;\n"
      << "  const clang::FunctionDecl *def = nullptr;\n"
      << "  if (!decl->hasBody(def) || decl != def) {\n"
      << "    return std::nullopt;\n"
      << "  } else if (def->getDefaultedFunctionInfo()) {\n"
      << "    return std::nullopt;\n"
      << "  } else if (auto body = def->getBody()) {\n"
      << "    return StmtBuilder::Create<::pasta::Stmt>(ast, body);\n"
      << "  } else {\n"
      << "    return std::nullopt;\n"
      << "  }\n"
      << "}\n\n";

      os_py << "\n    .def_property_readonly(\"Body\", &" << name << "::Body)";
    }
    os_py << ";\n"
          << "}\n"
          << "} // namespace pasta\n";
  }

  os
      << "}  // namespace pasta\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
