/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <llvm/ADT/StringRef.h>

#include "BootstrapConfig.h"

namespace {

static const char *kDeclNames[] = {
#define PASTA_BEGIN_CLANG_WRAPPER(name, id) #name ,
#include "Generated/Decl.h"
};

static struct {const char *derived; const char *base; } kDeclExtends[] = {
#define PASTA_PUBLIC_BASE_CLASS(name, id, base_name, base_id) \
    {#name, #base_name},
#include "Generated/Decl.h"
};

static const std::unordered_map<std::string, std::string> kCxxMethodRenames{
    {"SourceRange", "TokenRange"},
    {"Vbases", "VBases"},
    {"vbases", "VirtualBases"},
    {"NumVbases", "NumVBases"},
    {"Ctors", "Constructors"},
    {"ctors", "Constructors"},
    {"Location", "Token"},
};

static std::string CxxName(llvm::StringRef name) {
  if (name.startswith("get")) {
    return CxxName(name.substr(3));

  // Begin/end iterators.
  } else if (name.endswith("_begin") || name.endswith("_end") ||
             name.endswith("_size") || name.endswith("_empty") ||
             name.endswith("_rbegin") || name.endswith("_rend")) {
    return "";

  } else if (name.endswith("Loc")) {
    return name.substr(0, name.size() - 3).str() + "Token";

  } else if (auto name_it = kCxxMethodRenames.find(name.str());
             name_it != kCxxMethodRenames.end()) {
    return name_it->second;

  } else if (name.empty()) {
    return "";

  } else if (std::islower(name.front())) {
    return name.substr(0, 1).upper() + name.substr(1).str();

  } else {
    return name.str();
  }
}

std::unordered_map<std::string, std::vector<std::string>> gBaseClasses;
std::unordered_map<std::string, std::vector<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;

static void DeclareCppMethods(std::ostream &os, const std::string &class_name) {
#define PASTA_CLASS_METHOD_0(cls, id, meth, rt) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        if (!strcmp(#rt, "(bool)")) { \
          os << "  bool " << meth_name << "(void) const;\n"; \
        } else { \
          os << "  // " << meth_name << "\n"; \
        } \
      } \
    }

#define PASTA_CLASS_METHOD_1(cls, id, meth, rt, p0) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_2(cls, id, meth, rt, p0, p1) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_3(cls, id, meth, rt, p0, p1, p2) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_4(cls, id, meth, rt, p0, p1, p2, p3) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_5(cls, id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_6(cls, id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }
#include "Generated/Decl.h"
}

static void DeclareCppClasses(void) {
  std::ofstream os(kASTDeclHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#include <memory>\n\n"
      << "namespace clang {\n";

  for (auto name : kDeclNames) {
    os << "class " << name << ";\n";
  }

  os
      << "}  // namespace clang\n"
      << "namespace pasta {\n"
      << "class AST;\n"
      << "class ASTImpl;\n"
      << "class DeclBase {\n"
      << " public:\n"
      << "  ~DeclBase(void) = default;\n"
      << "  DeclBase(const DeclBase &) = default;\n"
      << "  DeclBase(DeclBase &&) noexcept = default;\n"
      << "  DeclBase &operator=(const DeclBase &) = default;\n"
      << "  DeclBase &operator=(DeclBase &&) noexcept = default;\n\n"
      << " protected:\n"
      << "  DeclBase(void) = delete;\n\n"
      << "  friend class AST;\n"
      << "  friend class ASTImpl;\n\n"
      << "  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, const ::clang::Decl *decl_)\n"
      << "      : ast(ast_) {\n"
      << "    u.Decl = decl_;\n"
      << "  }\n"
      << "  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, const ::clang::DeclContext *dc_, int)\n"
      << "      : ast(ast_) {\n"
      << "    u.DeclContext = dc_;\n"
      << "  }\n\n"
      << "  std::shared_ptr<ASTImpl> ast;\n"
      << "  union {\n";

  for (auto name : kDeclNames) {
    os << "    const ::clang::" << name << " *" << name << ";\n";
  }

  os
      << "  } u;\n"
      << "};\n\n";


  // Forward declare them all.
  for (auto name : kDeclNames) {
    os << "class " << name << ";\n";
  }

  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    os
        << "class " << name << " :";

    auto sep = " ";
    for (const auto &parent_class : gBaseClasses[name]) {
      os << sep << "public " << parent_class;
      sep = ", ";
    }

    os
        << " {\n"
        << " public:\n"
        << "  ~" << name << "(void) = default;\n"
        << "  " << name << "(const " << name << " &) = default;\n"
        << "  " << name << "(" << name << " &&) noexcept = default;\n"
        << "  " << name << " &operator=(const " << name << " &) = default;\n"
        << "  " << name << " &operator=(" << name << " &&) noexcept = default;\n\n";

    DeclareCppMethods(os, name);

    os
        << " private:\n"
        << "  " << name << "(void) = delete;\n\n"
        << "  " << name << "(const DeclBase &) = delete;\n"
        << "  " << name << "(DeclBase &&) noexcept = delete;\n"
        << "  " << name << " &operator=(const DeclBase &) = delete;\n"
        << "  " << name << " &operator=(DeclBase &&) noexcept = delete;\n\n"
        << "  friend class AST;\n"
        << "  friend class ASTImpl;\n"
        << "  friend class DeclBase;\n\n"
        << " protected:\n"
        << "  " << name << "(\n"
        << "      const std::shared_ptr<ASTImpl> &ast_,\n"
        << "      const ::clang::" << name << " *decl_);\n";


    os
        << "};\n\n";
  }

  os
      << "}  // namespace pasta\n";
}

static const char *BaseClassName(const std::string &class_name) {
  if (class_name == "DeclContext") {
    return "DeclBase";
  } else {
    return "Decl";
  }
}

static void DefineCppMethods(std::ostream &os, const std::string &class_name) {
#define PASTA_CLASS_METHOD_0(cls, id, meth, rt) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        if (!strcmp(#rt, "(bool)")) { \
          os << "bool " << class_name << "::" << meth_name << "(void) const {\n" \
             << "  return this->" << BaseClassName(class_name) \
             << "::u." << class_name << "->" << #meth << "();\n" \
             << "}\n\n"; \
        } else { \
          os << "  // " << meth_name << "\n"; \
        } \
      } \
    }

#define PASTA_CLASS_METHOD_1(cls, id, meth, rt, p0) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_2(cls, id, meth, rt, p0, p1) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_3(cls, id, meth, rt, p0, p1, p2) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_4(cls, id, meth, rt, p0, p1, p2, p3) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_5(cls, id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_CLASS_METHOD_6(cls, id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_name == #cls) { \
      if (const auto meth_name = CxxName(#meth); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }
#include "Generated/Decl.h"
}

static void DefineCppClasses(void) {
  std::ofstream os(kASTDeclCpp);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
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
      << "#include \"AST.h\"\n\n"
      << "namespace pasta {\n";


  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    os
        << name << "::" << name << "(\n"
        << "    const std::shared_ptr<ASTImpl> &ast_,\n"
        << "    const ::clang::" << name << " *decl_)";

    if (name == "Decl") {
      os << "\n    : DeclBase(ast_, decl_) {}\n";

    } else if (name == "DeclContext") {
      os << "\n    : DeclBase(ast_, decl_, 0) {}\n";

    } else {
      auto sep = "\n    : ";
      for (const auto &parent_class : gBaseClasses[name]) {
        os << sep << parent_class << "(ast_, decl_)";

        sep = ",\n      ";
      }
      os << " {}\n\n";
    }

    DefineCppMethods(os, name);
  }

  os
      << "}  // namespace pasta\n";
}

}  // namespace

int main(void) {

  std::unordered_set<std::string> seen;
  seen.insert("DeclBase");
  gBaseClasses["Decl"].push_back("DeclBase");
  gBaseClasses["DeclContext"].push_back("DeclBase");

  // Build up an adjacency list of parent/child relations.
  for (auto [name, base_name] : kDeclExtends) {
    gBaseClasses[name].push_back(base_name);
    gDerivedClasses[base_name].push_back(name);
  }

  // Topologically order the classes by the parent/child relations.
  for (auto changed = true; changed; ) {
    changed = false;
    for (auto name_ : kDeclNames) {
      const std::string name(name_);
      if (seen.count(name)) {
        goto skip;
      }

      for (const auto &parent_name : gBaseClasses[name]) {
        if (!seen.count(parent_name)) {
          goto skip;
        }
      }

      gTopologicallyOrderedDecls.push_back(name);
      seen.insert(name);
      changed = true;

    skip:
      continue;
    }
  }

  DeclareCppClasses();
  DefineCppClasses();

  return EXIT_SUCCESS;
}

