/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "MacroGenerator.h"

#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclFriend.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/ExprConcepts.h>
#include <clang/AST/ExprObjC.h>
#include <clang/AST/ExprOpenMP.h>
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtCXX.h>
#include <clang/AST/StmtObjC.h>
#include <clang/AST/StmtOpenMP.h>
#include <clang/AST/Type.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include "BootstrapConfig.h"

// Here we can fake some clases for convenience.
namespace clang {

class OMPDeclarativeDirectiveDecl : public OMPDeclarativeDirective<Decl> {

};

class OMPDeclarativeDirectiveValueDecl : public OMPDeclarativeDirective<ValueDecl> {

};

}  // namespace clang
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

static bool IsSigned(clang::QualType qtype) {
  if (auto type = qtype.getTypePtr()) {
    if (auto builtin = clang::dyn_cast<clang::BuiltinType>(type)) {
      return type->isSignedIntegerType();
    }
  }
  return false;
}

}  // namespace

MacroGenerator::MacroGenerator(const clang::ASTContext *ctx)
    : context(ctx) {
  acceptable_class_names.insert("FunctionTemplateSpecializationInfo");
  acceptable_class_names.insert("TemplateArgument");
  acceptable_class_names.insert("TypeSourceInfo");

  // NOTE(pag): We ignore `ExtQualsTypeCommonBase` and `ExtQuals`, in favor
  //            getting the accessors of `ExtQuals` via `QualType`.

  // NOTE(pag): We ignore `SplitQualType` as nothing really returns it

  // Base types.
  acceptable_class_names.insert("QualType");
  acceptable_class_names.insert("TypeWithKeyword");
  acceptable_class_names.insert("Type");
  acceptable_class_names.insert("Decl");
  acceptable_class_names.insert("DeclContext");
  acceptable_class_names.insert("Stmt");
  acceptable_class_names.insert("Expr");
  acceptable_class_names.insert("BaseUsingDecl");
  acceptable_class_names.insert("UsingEnumDecl");

  unacceptable_enum_names.insert("Kind");  // Really, `clang::Decl::Kind`.
  unacceptable_enum_names.insert("OnStack_t");  // There's also `OnStackType`.

  // These are related to `Redeclarable<T>`, and thus have dependent types.
  unacceptable_enum_names.insert("PreviousTag");
  unacceptable_enum_names.insert("LatestTag");
  unacceptable_enum_names.insert("NotUpdatedTag");

#define TYPE(Class, Base) acceptable_class_names.insert(#Class "Type");
#include "clang/AST/TypeNodes.inc"
#undef TYPE

#define DECL(Type, Base) acceptable_class_names.insert(#Type "Decl");
#include "clang/AST/DeclNodes.inc"
#undef DECL

#define STMT(Type, Base) \
    acceptable_class_names.insert(#Base); \
    acceptable_class_names.insert(#Type); \
    acceptable_class_names.insert(#Type "Expr"); \
    acceptable_class_names.insert(#Type "Stmt");
#include "clang/AST/StmtNodes.inc"
#undef DECL
}

MacroGenerator::~MacroGenerator(void) {
  std::error_code ec;
  llvm::raw_fd_ostream os(kClangMacroHeader, ec);
  if (ec) {
    std::cerr << "Error: " << ec.message();
    return;
  }

  auto print_policy = clang::PrintingPolicy(context->getLangOpts());
  print_policy.PrintCanonicalTypes = true;

  // Provide unique, semi-reproducible IDs to each clang declaration class.
  std::hash<std::string> hasher;
  std::unordered_set<size_t> taken_ids;
  std::map<std::string, uint32_t> decl_ids;
  for (const auto &[decl_name, decl] : decl_classes) {
    std::stringstream ss;
    ss << decl_name;
    uint32_t id = 0;
    for (;;) {
      id = static_cast<uint32_t>(hasher(ss.str()) & 0x7FFFFFFFu);
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
  std::map<std::string, clang::EnumDecl *> decl_named_enums;
  std::unordered_set<clang::EnumDecl *> decl_unnamed_enums;

  os << "#include \"DefineDefaultMacros.h\"\n\n";

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
       << ")\n";

    // Get enclosed methods, fields, and enums. This will sort them by name.
    decl_methods.clear();
    decl_fields.clear();
    decl_named_enums.clear();
    decl_unnamed_enums.clear();

    for (const auto enclosed_decl : decl->decls()) {
      if (clang::CXXMethodDecl *method = clang::dyn_cast<clang::CXXMethodDecl>(enclosed_decl)) {
        auto method_name_str = method->getNameAsString();
        llvm::StringRef method_name(method_name_str);

        // Skip over operator overloads, as we don't have any reasonable way to
        // bind them to Python. Also skip over non-public methods, which we
        // probably don't want to expose anyway.
        if (method->isOverloadedOperator() ||
            clang::dyn_cast<clang::CXXConstructorDecl>(method) ||
            clang::dyn_cast<clang::CXXDestructorDecl>(method) ||
            clang::dyn_cast<clang::CXXConversionDecl>(method) ||
            method_name == "hasODRHash" ||
            method->getAccess() != clang::AS_public) {
          continue;
        }

        // Ignore methods that don't return anything; they are propabably
        // mutators.
        auto split_type = method->getReturnType().getSplitDesugaredType();
        if (split_type.Ty && split_type.Ty->isVoidType()) {
          continue;
        }

        // Ignore "setters", as well as factory functions.
        if (!method_name.startswith("set") &&
            !method_name.startswith("remove") &&
            method_name != "Create" &&
            (method->isConst() || method_name == "getODRHash")) {
          decl_methods[method_name.str()].push_back(method);
        }

      } else if (clang::FieldDecl *field = clang::dyn_cast<clang::FieldDecl>(enclosed_decl)) {

        auto field_name = field->getName().str();
        decl_fields.emplace(std::move(field_name), field);

      } else if (clang::EnumDecl *enum_ = clang::dyn_cast<clang::EnumDecl>(enclosed_decl)) {
        if (enum_->getAccess() != clang::AS_public) {
          continue;
        }

        auto enum_name = enum_->getName().str();
        if (!enum_name.empty()) {
          decl_named_enums.emplace(std::move(enum_name),
                                   enum_->getCanonicalDecl());

        } else {
          decl_unnamed_enums.insert(enum_->getCanonicalDecl());
        }
      }
    }

    // Methods.
    os << "  PASTA_BEGIN_METHODS(" << decl_name << ", " << decl_id << ")\n";

    auto method_id = 0u;
    for (const auto &[method_name, methods] : decl_methods) {

      // The simplest case of declaring a method is that it is not overridden.
      if (methods.size() != 1u) {
        os << "    // Skipped overloaded " << method_name << '\n';
      } else {
        const auto method = methods[0];

        // NOTE(pag): Things like `clang::Decl::isDeprecated` and
        //            `clang::Decl::isUnavailable` take in an optional
        //            pointer to a string. We'll ignore/drop that for now,
        //            along with any other default arguments.
        const auto num_args = method->getMinRequiredArguments();

        if (!method->isInstance()) {
          os << "    PASTA_CLASS_METHOD_" << num_args << '(';
        } else if (method->isVirtual() && method->size_overridden_methods()) {
          os << "    PASTA_OVERRIDE_METHOD_" << num_args << '(';
        } else {
          os << "    PASTA_INSTANCE_METHOD_" << num_args << '(';
        }

        os << decl_name << ", " << decl_id << ", " << method_id << ", " << method_name << ", ("
           << method->getReturnType().getAsString(print_policy) << ')';

        for (auto i = 0u; i < num_args; ++i) {
          const auto param = method->getParamDecl(i);
          os << ", (" << param->getType().getAsString(print_policy) << ')';
        }
        os << ")\n";

        ++method_id;
      }
    }

    os << "  PASTA_END_METHODS(" << decl_name << ", " << decl_id << ")\n";

    // NOTE(pag,adrianh): We ignore C++ constructors and destructors because
    //                    our bindings are intended to provide read-only
    //                    access to the underlying data, and so if something
    //                    is inside of a Clang AST, then it should never be
    //                    deleted / deleteable by us.

    // Fields.
    os << "  PASTA_BEGIN_FIELDS(" << decl_name << ", " << decl_id << ")\n";

    for (const auto &[field_name, field] : decl_fields) {
      if (field_name.empty()) {
        continue;
      }

      auto type_name_ = field->getType().getAsString(print_policy);
      llvm::StringRef type_name(type_name_);
      if (type_name.contains("(anonymous")) {
        continue;
      }

      os << "    PASTA" << MacroAccessSpecifier(field) << "INSTANCE_FIELD(";

      os << decl_name << ", " << decl_id << ", " << field_name << ", ("
         << type_name << "))\n";
    }

    os << "  PASTA_END_FIELDS(" << decl_name << ", " << decl_id << ")\n";

    // Enums.
    os << "  PASTA_BEGIN_CLASS_ENUMS(" << decl_name << ", " << decl_id
       << ")\n";


    // Named enums. These are also captured at the namespace level, so we
    // keep these here so that we can do something like
    // `using Blah = ::pasta::Blah` later.
    for (const auto &[enum_name, enum_] : decl_named_enums) {
      if (decl_name == "Decl" && enum_name == "Kind") {
        continue;
      }

      auto enum_def = enum_->getDefinition();
      auto itype = enum_->getIntegerType();
      auto itype_str = itype.getAsString(print_policy);
      if (!itype.isNull() && enum_def) {
        os << "  PASTA_BEGIN_CLASS_NAMED_ENUM(" << decl_name
           << ", " << enum_name << ", ("
           << itype_str << "))\n";

        for (auto elem : enum_def->enumerators()) {
          os << "    PASTA_CLASS_ENUMERATOR(" << elem->getNameAsString()
             << ", (" << itype_str << "), (";
          elem->getInitVal().print(os, IsSigned(itype));
          os << "))\n";
        }

        os << "  PASTA_END_CLASS_NAMED_ENUM(" << decl_name
           << ", " << enum_name << ")\n";
      }
    }

//    // Unnamed enums.
//    for (auto enum_ : decl_unnamed_enums) {
//      auto enum_def = enum_->getDefinition();
//      auto itype = enum_->getIntegerType();
//      if (itype.isNull() || !enum_def) {
//        continue;
//      }
//
//      os << "    PASTA_BEGIN_CLASS_UNNAMED_ENUM(" << decl_name << ", " << decl_id
//         << ", (" << itype.getAsString(print_policy) << "))\n";
//
//      for (auto elem : enum_def->enumerators()) {
//        os << "      PASTA_UNNAMED_ENUMERATOR(" << elem->getNameAsString() << ", ("
//           << itype.getAsString(print_policy) << "), (";
//        elem->getInitVal().print(os, IsSigned(itype));
//        os << "))\n";
//      }
//
//      os << "    PASTA_END_CLASS_UNNAMED_ENUM(" << decl_name
//         << ", " << decl_id << ")\n";
//    }
//

    os << "  PASTA_END_CLASS_ENUMS(" << decl_name << ", " << decl_id << ")\n"
       << "PASTA_END_CLANG_WRAPPER(" << decl_name << ", " << decl_id
       << ")\n\n";
  }

  // Dump out top-level enums.
  for (const auto &[enum_name, enum_] : decl_enums) {
    auto enum_def = enum_->getDefinition();
    auto itype = enum_->getIntegerType();
    if (itype.isNull() || !enum_def) {
      os << "PASTA_DECLARE_NAMED_ENUM(" << enum_name << ", (int))\n\n";
      continue;
    }

    os << "PASTA_BEGIN_NAMED_ENUM(" << enum_name
       << ", (" << itype.getAsString(print_policy) << "))\n";

    for (auto elem : enum_def->enumerators()) {
      os << "  PASTA_NAMED_ENUMERATOR(" << elem->getNameAsString() << ", ("
         << itype.getAsString(print_policy) << "), (";
      elem->getInitVal().print(os, IsSigned(itype));
      os << "))\n";
    }

    os << "PASTA_END_NAMED_ENUM(" << enum_name << ")\n";
  }

  os << "#include \"UndefineDefaultMacros.h\"\n\n";
}

bool MacroGenerator::VisitEnumDecl(clang::EnumDecl *decl) {
  const auto ns_dc = decl->getEnclosingNamespaceContext();
  if (!ns_dc || !ns_dc->isNamespace()) {
    return true;
  }

  // Only record a decl if it's actually the definition. Then we can inspect
  // its enumeration constants.
  auto decl_def = decl->getDefinition();
  if (!decl_def) {
    return true;
  }

  if (decl->getName().empty()) {
    return true;
  }

  const auto ns = clang::NamespaceDecl::castFromDeclContext(ns_dc);

  // Find top-level enums in the `clang` namespace.
  if (ns->getName() == "clang") {

    auto decl_name = decl->getName().str();

    // Avoid crazy things like diagnostic enums.
    if (!unacceptable_enum_names.count(decl_name)) {
      decl_enums.emplace(std::move(decl_name), decl_def);
    }

  // Find top-level enums in the `clang::attr` namespace, and prefix them
  // with `Attribute`.
  } else if (ns->getName() == "attr") {
    if (auto ns_ns_dc = ns->getParent(); ns_ns_dc && ns_ns_dc->isNamespace()) {
      const auto ns_ns = clang::NamespaceDecl::castFromDeclContext(ns_ns_dc);
      if (ns_ns->getName() == "clang") {

        std::string decl_name = "Attribute" + decl->getName().str();
        if (!unacceptable_enum_names.count(decl_name)) {
          decl_enums.emplace(std::move(decl_name), decl_def);
        }
      }
    }
  }

  return true;
}

bool MacroGenerator::VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
  const auto ns_dc = decl->getEnclosingNamespaceContext();
  if (!ns_dc || !ns_dc->isNamespace()) {
    return true;
  }

  const auto ns = clang::NamespaceDecl::castFromDeclContext(ns_dc);
  if (ns->getName() != "clang") {
    return true;
  }

  // Only keep clang `*Decl` class names.
  auto decl_name = decl->getName().str();
  if (!acceptable_class_names.count(decl_name)) {
    return true;
  }

  // Only record a decl if it's actually the definition. Then we can inspect
  // its base classes, methods, etc.
  if (auto decl_def = decl->getDefinition(); decl_def) {
    decl_classes.emplace(std::move(decl_name), decl_def);
  }

  return true;
}

}  // namespace pasta
