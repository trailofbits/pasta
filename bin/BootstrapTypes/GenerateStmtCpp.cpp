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

// Generate `lib/AST/Stmt.cpp`.
void GenerateStmtCpp(std::ostream& py_cmake, std::ostream& py_ast) {
  std::ofstream os(kASTStmtCpp);

  os
      << "/*\n"
      << " * Copyright (c) 2022 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#define PASTA_IN_STMT_CPP\n"
      << "#ifndef PASTA_IN_BOOTSTRAP\n"
      << "#pragma clang diagnostic push\n"
      << "#pragma clang diagnostic ignored \"-Wimplicit-int-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wsign-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wshorten-64-to-32\"\n"
      << "#pragma clang diagnostic ignored \"-Wbitfield-enum-conversion\"\n"
      << "#include <clang/AST/Stmt.h>\n"
      << "#include <clang/AST/StmtCXX.h>\n"
      << "#include <clang/AST/StmtObjC.h>\n"
      << "#include <clang/AST/StmtOpenMP.h>\n"
      << "#include <clang/AST/Expr.h>\n"
      << "#include <clang/AST/ExprConcepts.h>\n"
      << "#include <clang/AST/ExprCXX.h>\n"
      << "#include <clang/AST/ExprObjC.h>\n"
      << "#include <clang/AST/ExprOpenMP.h>\n"
      << "#include <clang/Frontend/CompilerInstance.h>\n"
      << "#pragma clang diagnostic pop\n\n"
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Stmt.h>\n"
      << "#include <pasta/AST/Type.h>\n"
      << "#include \"AST.h\"\n"
      << "#include \"Builder.h\"\n\n"
      << "#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \\\n"
      << "    std::optional<class derived> derived::From(const class base &that) { \\\n"
      << "      if (auto stmt_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.Stmt)) { \\\n"
      << "        return StmtBuilder::Create<class derived>(that.ast, stmt_ptr); \\\n"
      << "      } else { \\\n"
      << "        return std::nullopt; \\\n"
      << "      } \\\n"
      << "    }\n\n"
      << "#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \\\n"
      << "    base::base(const class derived &that) \\\n"
      << "        : base(that.ast, that.u.Stmt) {} \\\n"
      << "    base::base(class derived &&that) noexcept \\\n"
      << "        : base(std::move(that.ast), that.u.Stmt) {} \\\n"
      << "    base &base::operator=(const class derived &that) { \\\n"
      << "      if (ast != that.ast) { \\\n"
      << "        ast = that.ast; \\\n"
      << "      } \\\n"
      << "      u.Stmt = that.u.Stmt; \\\n"
      << "      kind = that.kind; \\\n"
      << "      return *this; \\\n"
      << "    } \\\n"
      << "    base &base::operator=(class derived &&that) noexcept { \\\n"
      << "      class derived new_that(std::forward<class derived>(that)); \\\n"
      << "      ast = std::move(new_that.ast); \\\n"
      << "      u.Stmt = new_that.u.Stmt; \\\n"
      << "      kind = new_that.kind; \\\n"
      << "      return *this; \\\n"
      << "    }\n\n"
      << "namespace pasta {\n\n";

  os  << "StmtVisitor::~StmtVisitor(void) {}\n\n"
      << "void StmtVisitor::Accept(const Stmt &stmt) {\n"
      << "  switch (stmt.Kind()) {\n"
      << "#define PASTA_VISIT_STMT(name) \\\n"
      << "    case StmtKind::k ## name: \\\n"
      << "      Visit ## name(reinterpret_cast<const name &>(stmt)); \\\n"
      << "      break;\n\n"
      << "    PASTA_FOR_EACH_STMT_IMPL(PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_VISIT_STMT, PASTA_IGNORE_ABSTRACT)\n"
      << "#undef PASTA_VISIT_STMT\n"
      << "  }\n"
      << "}\n\n";

  for (const auto &name : gTopologicallyOrderedStmts) {
    os << "void StmtVisitor::Visit" << name << "(const " << name << " &stmt) {\n";
    auto seen = false;
    for (const auto &parent_class : gBaseClasses[name]) {
      os << "  Visit" << parent_class << "(stmt);\n";
      seen = true;
    }
    if (!seen) {
      os << "  (void) stmt;\n";
    }
    os << "}\n\n";
  }

  // Define them all.
  for (const auto &name : gTopologicallyOrderedStmts) {
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

namespace pasta {
namespace py = pybind11;

void Register)" << name << "(py::module_ &m) {\n"
      << "  py::class_<" << name;

    llvm::StringRef name_ref(name);

    os
        << name << "::" << name << "(\n"
        << "    std::shared_ptr<ASTImpl> ast_,\n"
        << "    const ::clang::Stmt *stmt_)";

    // Dispatch to our hand-written constructor that takes the `StmtKind`.
    if (name == "Stmt") {
      os << "\n    : Stmt(std::move(ast_), stmt_, static_cast<::pasta::StmtKind>(stmt_->getStmtClass())) {}\n\n";

    // Dispatch to the base class constructor(s).
    } else {
      auto sep = "\n    : ";
      const auto &base_classes = gBaseClasses[name];
      auto prefix = base_classes.size() == 1u ? "std::move(" : "";
      auto suffix = base_classes.size() == 1u ? ")" : "";
      for (const auto &parent_class : base_classes) {
        os << sep << parent_class << "(" << prefix << "ast_" << suffix
           << ", stmt_)";
        sep = ",\n      ";
      }
      os << " {}\n\n";
    }

    // Constructors from derived class -> base class.
    for (const auto &base_class : gTransitiveBaseClasses[name]) {
      os << "PASTA_DEFINE_BASE_OPERATORS(" << base_class << ", "
         << name << ")\n";
      os_py << ", " << base_class;
    }
    os_py << ">(m, \"" << name << "\")"
          << "\n    .def(\"__hash__\", [](const " << name << "& stmt) { return (intptr_t)stmt.RawStmt(); })"
          << "\n    .def(\"__eq__\", [](const " << name << "& a, const " << name << "& b) { return a.RawStmt() == b.RawStmt(); })";

    for (const auto &derived_class : gTransitiveDerivedClasses[name]) {
      os << "PASTA_DEFINE_DERIVED_OPERATORS("
         << name << ", " << derived_class << ")\n";
    }
    DefineCppMethods(os, name, gClassIDs[name], os_py);

    os_py << ";\n"
          << "}\n"
          << "} // namespace pasta\n";
  }

  os
      << "}  // namespace pasta\n"
      << "#endif  // PASTA_IN_BOOTSTRAP\n";
}
