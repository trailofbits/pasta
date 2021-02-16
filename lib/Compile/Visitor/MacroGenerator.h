/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <map>
#include <unordered_set>
#include <sstream>
#include <string>

#include <clang/AST/RecursiveASTVisitor.h>

namespace pasta {
namespace {
static std::string_view MacroAccessSpecifier(const clang::Decl *decl) {
  switch (decl->getAccess()) {
    case clang::AccessSpecifier::AS_private:
      return "_PRIVATE_";
    case clang::AccessSpecifier::AS_protected:
      return "_PROTECTED_";
    default:
      return "_";
  }
}
}  // namespace

class MacroGenerator : public clang::RecursiveASTVisitor<MacroGenerator> {
 public:
  MacroGenerator(void) {
    acceptable_names.insert("Decl");
    acceptable_names.insert("DeclContext");

#define DECL(Type, Base) acceptable_names.insert(#Type "Decl");
#include "clang/AST/DeclNodes.inc"
#undef DECL
  }

  ~MacroGenerator(void) {

    auto &os = llvm::errs();

    // Provide unique, semi-reproducible IDs to each clang declaration class.
    std::hash<std::string> hasher;
    std::unordered_set<size_t> taken_ids;
    std::map<std::string, uint64_t> decl_ids;
    for (const auto &[decl_name, decl] : decl_classes) {
      std::stringstream ss;
      ss << decl_name;
      uint64_t id = 0;
      for (;;) {
        id = hasher(ss.str());
        if (taken_ids.count(id)) {
          ss << id;
        } else {
          taken_ids.insert(id);
          break;
        }
      }
      decl_ids.emplace(decl_name, id);
    }

    // We try to keep as much as possible in sorted order so performing a diff
    // on the auto-generated outputs across multiple Clang versions is easier.
    std::map<std::string, std::vector<clang::CXXMethodDecl *>> decl_methods;
    std::map<std::string, clang::FieldDecl *> decl_fields;

    for (const auto &[decl_name, decl] : decl_classes) {
      const auto decl_id = decl_ids[decl_name];

      os << "PASTA_BEGIN_CLANG_WRAPPER(" << decl_name << ", "
         << decl_id << ")\n";

      os << "  PASTA_BEGIN_BASE_CLASSES(" << decl_name << ", " << decl_id
         << ")\n";

      // We want to be able to mirror the clang class hierarchy directly, so we
      // need to go find the (public) base classes and expose them.
      for (auto base : decl->bases()) {
        auto type = base.getType();
        if (base.getAccessSpecifier() != clang::AS_public || type.isNull()) {
          continue;
        }

        if (auto base_decl = type->getAsCXXRecordDecl(); base_decl) {
          const auto base_decl_name = base_decl->getName().str();
          if (decl_ids.count(base_decl_name)) {
            os << "    PASTA_PUBLIC_BASE_CLASS(" << decl_name << ", " << decl_id
               << ", " << base_decl_name << ", " << decl_ids[base_decl_name]
               << ")\n";
          } else {
            os << "    // Skipped " << base_decl_name << "\n";
          }
        }
      }

      os << "  PASTA_END_BASE_CLASSES(" << decl_name << ", " << decl_id
         << ")\n"
         << "  PASTA_BEGIN_METHODS(" << decl_name << ", " << decl_id
         << ")\n";

      // Get the methods sorted by name, then dump them out.
      decl_methods.clear();
      for (const auto method_decl : decl->methods()) {

        // Skip over operator overloads, as we don't have any reasonable way to
        // bind them to Python. Also skip over non-public methods, which we
        // probably don't want to expose anyway.
        if (method_decl->isOverloadedOperator() ||
            clang::dyn_cast<clang::CXXConstructorDecl>(method_decl) ||
            clang::dyn_cast<clang::CXXDestructorDecl>(method_decl) ||
            clang::dyn_cast<clang::CXXConversionDecl>(method_decl) ||
            method_decl->getAccess() != clang::AS_public) {
          continue;
        }

        if (auto method_decl_def = method_decl->getDefinition(); method_decl_def) {
          auto method_name = method_decl->getName().str();
          decl_methods[method_name].push_back(
              clang::dyn_cast<clang::CXXMethodDecl>(method_decl_def));
        }
      }

      for (const auto &[method_name, methods] : decl_methods) {

        // The simplest cast of declaring a method is that it is not overridden.
        if (methods.size() != 1u) {
          os << "    // Skipped overloaded " << method_name << '\n';
        } else {
          const auto method = methods[0];
          if (method->isCXXClassMember()) {
            os << "    PASTA_PUBLIC_CLASS_METHOD(";
          } else {
            os << "    PASTA_PUBLIC_INSTANCE_METHOD(";
          }

          os << decl_name << ", " << decl_id << ", " << method_name << ");\n";
        }
      }

      os << "  PASTA_END_METHODS(" << decl_name << ", " << decl_id
         << ")\n"
         << "  PASTA_BEGIN_FIELDS(" << decl_name << ", " << decl_id
         << ")\n";

      // NOTE(pag,adrianh): We ignore C++ constructors and destructors because
      //                    our bindings are intended to provide read-only
      //                    access to the underlying data, and so if something
      //                    is inside of a Clang AST, then it should never be
      //                    deleted / deleteable by us.

      // Fields.
      decl_fields.clear();
      for (const auto field : decl->fields()) {
        auto field_name = decl->getName().str();
        decl_fields.emplace(std::move(field_name), field);
      }

      for (const auto &[field_name, field] : decl_fields) {
        os << "    PASTA" << MacroAccessSpecifier(field);
        if (field->isCXXClassMember()) {
          os << "CLASS_FIELD(";
        } else {
          os << "INSTANCE_FIELD(";
        }

        os << decl_name << ", " << decl_id << ", " << field_name << ");\n";
      }

      os << "  PASTA_END_FIELDS(" << decl_name << ", " << decl_id
         << ")\n"
         << "PASTA_END_CLANG_WRAPPER(" << decl_name << ", " << decl_id
         << ");\n\n";
    }
  }

  bool VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
    const auto ns_dc = decl->getEnclosingNamespaceContext();
    if (!ns_dc) {
      return true;
    }
    if (!ns_dc->isNamespace()) {
      return true;
    }

    const auto ns = clang::NamespaceDecl::castFromDeclContext(ns_dc);
    if (ns->getName() != "clang") {
      return true;
    }

    auto decl_name = decl->getName().str();
    if (!acceptable_names.count(decl_name)) {
      return true;
    }

    // Only record a decl if it's actually the definition. Then we can inspect
    // its base classes, methods, etc.
    if (auto decl_def = decl->getDefinition(); decl_def) {
      decl_classes.emplace(std::move(decl_name), decl_def);
    }

    return true;
  }

 private:
  std::unordered_set<std::string> acceptable_names;
  std::map<std::string, clang::CXXRecordDecl *> decl_classes;
};

}  // namespace pasta
