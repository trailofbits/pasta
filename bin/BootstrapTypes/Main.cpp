/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <cstdlib>
#include <cstring>
#include <iostream>

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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


std::unordered_map<std::string, std::vector<std::string>> gBaseClasses;
std::unordered_map<std::string, std::vector<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;

static void PrintCppDecl(void) {
  std::cout
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#include <memory>\n\n"
      << "namespace clang {\n";

  for (auto name : kDeclNames) {
    std::cout << "class " << name << ";\n";
  }

  std::cout
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
      << "  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, ::clang::Decl *decl_)\n"
      << "      : ast(ast_) {\n"
      << "    u.Decl = decl_;\n"
      << "  }\n"
      << "  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, ::clang::DeclContext *dc_, int)\n"
      << "      : ast(ast_) {\n"
      << "    u.DeclContext = dc_;\n"
      << "  }\n\n"
      << "  std::shared_ptr<ASTImpl> ast;\n"
      << "  union {\n";

  for (auto name : kDeclNames) {
    std::cout << "    ::clang::" << name << " *" << name << ";\n";
  }

  std::cout
      << "  } u;\n"
      << "};\n\n";


  for (auto [name, base_name] : kDeclExtends) {
    gBaseClasses[name].push_back(base_name);
    gDerivedClasses[base_name].push_back(name);
  }

  // Forward declare them all.
  for (auto name : kDeclNames) {
    std::cout << "class " << name << ";\n";
  }

  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    std::cout
        << "class " << name << " :";

    auto sep = " ";
    for (const auto &parent_class : gBaseClasses[name]) {
      std::cout << sep << "public " << parent_class;
      sep = ", ";
    }

    std::cout
        << " {\n"
        << " public:\n"
        << "  ~" << name << "(void) = default;\n"
        << "  " << name << "(const " << name << " &) = default;\n"
        << "  " << name << "(" << name << " &&) noexcept = default;\n"
        << "  " << name << " &operator=(const " << name << " &) = default;\n"
        << "  " << name << " &operator=(" << name << " &&) noexcept = default;\n\n"
        << " private:\n"
        << "  " << name << "(void) = delete;\n\n"
        << "  " << name << "(const DeclBase &) = delete;\n"
        << "  " << name << "(DeclBase &&) noexcept = delete;\n"
        << "  " << name << " &operator=(const DeclBase &) = delete;\n"
        << "  " << name << " &operator=(DeclBase &&) noexcept = delete;\n\n"
        << "  friend class AST;\n"
        << "  friend class ASTImpl;\n"
        << "  friend class DeclBase;\n"
        << "  " << name << "(\n"
        << "      const std::shared_ptr<ASTImpl> &ast_,\n"
        << "      ::clang::" << name << " *decl_);\n";

//    sep = "\n      : ";
//    for (const auto &parent_class : gBaseClasses[name]) {
//      std::cout << sep << parent_class << "(ast_, ";
//      if (name == "DeclContext") {
//        std::cout << "decl_, 0";
//
//      } else if (name == "Decl") {
//
//      } else {
//        std::cout << "reinterpret_cast<::clang::"
//                  << parent_class << " *>(decl_)";
//      }
//      sep = ",\n        ";
//    }

    std::cout
        //<< ") {}\n\n"
        << "};\n\n";
  }

  std::cout
      << "}  // namespace pasta\n";
}

}  // namespace

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Expected one and only one option.";
    return EXIT_FAILURE;
  }

  std::unordered_set<std::string> seen;
  seen.insert("DeclBase");
  gBaseClasses["Decl"].push_back("DeclBase");
  gBaseClasses["DeclContext"].push_back("DeclBase");

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

    skip:
      continue;
    }
  }

  if (!strcmp(argv[1], "--print-cpp-decl")) {
    PrintCppDecl();

  } else {
    std::cerr << "Unrecognized option: " << argv[1];
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

