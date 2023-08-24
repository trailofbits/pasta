/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

namespace {

static const std::string gTypeClassName{"QualifiedType"};
static std::set<std::pair<std::string, std::string>> existing_methods;

static void DefineCppMethod0(std::ostream &os, const std::string &class_name,
                             llvm::StringRef meth_name_ref,
                             llvm::StringRef rt_ref, std::ostream &os_py) {

  if (meth_name_ref.endswith("Unsafe")) {
    return;
  }

  // `NamedDecl::getName` has an assertion in it where `getNameAsString` does
  // not, and we introduce a method rename for `getNameAstString` to
  // `getName`.
  if (meth_name_ref == "getName") {
    if (class_name == "NamedDecl" ||
        class_name == "ObjCImplementationDecl") {
      return;
    }
  }

  const std::string meth_name = CxxName(class_name, meth_name_ref);
  if (meth_name.empty() || meth_name == "Clone") { \
    os << "// 0: " << class_name << "::" << meth_name << "\n";
    return;
  }

  // NOTE(pag): For `isImplicit`, we define our own that walks up the decl
  //            contexts.
  if (class_name == "Decl" &&
      (meth_name_ref == "getKind" || meth_name_ref == "getDeclKindName" ||
       meth_name_ref == "getBody" || meth_name_ref == "getBodyRBrace" ||
       meth_name_ref == "isImplicit")) {
    return;
  }

  if (class_name == "Attr" &&
      (meth_name_ref == "getKind" ||
       meth_name_ref == "getAttributeSpellingListIndex")) {
    return;
  }

  if (class_name == "Type" &&
      (meth_name_ref == "getTypeClass" || meth_name_ref == "getTypeClassName")) {
    return;  // Manually implemented.
  }

  if (class_name.find("Decl") != std::string::npos) {
    if (meth_name_ref == "getLocation" || meth_name_ref == "getSourceRange") {
      return;
    }
  }

  // We have our own, because this looks into the type and can find the "wrong"
  // `...` as a result of type deduplication.
  if (class_name == "FunctionDecl" &&
      (meth_name_ref == "getEllipsisLoc" ||
       meth_name_ref == "getParametersSourceRange" ||
       meth_name_ref == "getReturnTypeSourceRange")) {
    return;
  }

  std::string rt_str = rt_ref.str();
  auto &rt_type = gRetTypeMap[rt_str];
  auto &rt_val = gRetTypeToValMap[rt_str];

  if (rt_type.empty() || rt_val.empty()) {
    os << "// 0: " << class_name << "::" << meth_name << "\n";
    return;
  }

  auto meth_key = std::make_pair(class_name, meth_name);
  auto [_, added] = existing_methods.insert(meth_key);
  if (!added) {
    return;
  }

  const auto null_key = std::make_pair(class_name, meth_name);
  const auto can_ret_null = kCanReturnNullptr.count(null_key) ||
                            kConditionalNullptr.count(null_key);
  if (can_ret_null) {
    os << "std::optional<" << rt_type << ">";
  } else {
    os << rt_type;
  }

  os << " " << class_name << "::" << meth_name << "(void) const {\n";

  const auto is_qual_type = class_name == "QualifiedType";
  if (is_qual_type) {
    os << "  auto &ast_ctx = ast->ci->getASTContext();\n"
       << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n"
       << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n";
  } else {
    os << "  auto &self = *const_cast<clang::" << class_name << " *>(u." << class_name << ");\n";
  }
  auto handled_null_ret = false;
  if (auto it = kConditionalNullptr.find(null_key); it != kConditionalNullptr.end()) {
    os << it->second;
    handled_null_ret = true;
  }
  os << "  decltype(auto) val = self." << meth_name_ref.str() << "();\n";
  if (rt_ref.endswith("QualType)")) {
    if (can_ret_null) {
      os
          << "  if (val.isNull()) {\n"
          << "    return std::nullopt;\n"
          << "  }\n"
          << rt_val;
    } else {
      os
          << "  assert(!val.isNull());\n"
          << rt_val;
    }
  } else if (rt_ref.endswith(" *)")) {
    if (can_ret_null) {
      os
          << "  if (!val) {\n"
          << "    return std::nullopt;\n"
          << "  }\n"
          << rt_val;
    } else {
      os << rt_val
         << "  " PASTA_ASSERT_THROW "\""
         << class_name << "::"
         << meth_name << " can return nullptr!\");\n";
    }
  } else {
    assert(!can_ret_null || handled_null_ret);
    os << rt_val;
    (void) handled_null_ret;
  }

  os << "}\n\n";

  os_py << "\n    .def_prop_ro(\"" << CapitalCaseToSnakeCase(meth_name) << "\", &" << class_name << "::" << meth_name << ")";
}


static void DefineCppMethod1(std::ostream &os, const std::string &class_name,
                             llvm::StringRef meth_name_ref,
                             llvm::StringRef rt_ref, llvm::StringRef p0_ref,
                             std::ostream &os_py) {
  const auto is_qual_type = class_name == "QualifiedType";
  const auto meth_name = CxxName(class_name, meth_name_ref); \
  if (meth_name.empty() || meth_name == "Clone") {
    os << "// 1: " << class_name << "::" << meth_name << "\n";
    return;
  }

  std::string rt_str = rt_ref.str();
  auto &rt_type = gRetTypeMap[rt_str];
  auto &rt_val = gRetTypeToValMap[rt_str];

  if (rt_type.empty() || rt_val.empty()) {
    os << "// 1: " << class_name << "::" << meth_name << "\n";
    return;
  }

  if (p0_ref == "(const clang::ASTContext &)" ||
      p0_ref == "(clang::ASTContext &)") {
    const auto null_key = std::make_pair(class_name, meth_name);
    const auto can_ret_null = kCanReturnNullptr.count(null_key) ||
                              kConditionalNullptr.count(null_key);
    if (can_ret_null) {
      os << "std::optional<" << rt_type << ">";
    } else {
      os << rt_type;
    }
    os << " " << class_name << "::" << meth_name << "(void) const {\n";
    if (is_qual_type) {
      os << "  auto &ast_ctx = ast->ci->getASTContext();\n"
         << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n"
         << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n";
    } else {
      os << "  auto &self = *(u." << class_name << ");\n";
    }
    auto handled_null_ret = false;
    if (auto it = kConditionalNullptr.find(null_key); it != kConditionalNullptr.end()) {
      os << it->second;
      handled_null_ret = true;
    }
    os << "  decltype(auto) val = self." << meth_name_ref.str() << "(ast->ci->getASTContext());\n";
    if (rt_ref.endswith("QualType)")) {
      if (can_ret_null) {
        os
            << "  if (val.isNull()) {\n"
            << "    return std::nullopt;\n"
            << "  }\n"
            << rt_val;
      } else {
        os << "  assert(!val.isNull());\n"
           << rt_val;
      }
    } else if (rt_ref.endswith(" *)")) {
      if (can_ret_null) {
        os
            << "  if (!val) {\n"
            << "    return std::nullopt;\n"
            << "  }\n"
            << rt_val;
      } else {
        os << rt_val
           << "  " PASTA_ASSERT_THROW "\""
           << class_name << "::"
           << meth_name << " can return nullptr!\");\n";
      }
    } else {
      assert(!can_ret_null || handled_null_ret);
      os << rt_val;
      (void) handled_null_ret;
    }
    os << "}\n\n";

  } else if (p0_ref == "(bool)") {
    const auto can_ret_null = kCanReturnNullptr.count(
        std::make_pair(class_name, meth_name));
    if (can_ret_null) {
      os << "std::optional<" << rt_type << ">";
    } else {
      os << rt_type;
    }
    os << " " << class_name << "::" << meth_name << "(bool b) const {\n";
    if (is_qual_type) {
      os << "  auto &ast_ctx = ast->ci->getASTContext();\n"
         << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n"
         << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n";
    } else {
      os << "  auto &self = *(u." << class_name << ");\n";
    }
    os << "  decltype(auto) val = self." << meth_name_ref.str() << "(b);\n";
    if (rt_ref.endswith("QualType)")) {
      if (can_ret_null) {
        os
            << "  if (val.isNull()) {\n"
            << "    return std::nullopt;\n"
            << "  }\n"
            << rt_val;
      } else {
        os << "  assert(!val.isNull());\n"
           << rt_val;
      }
    } else if (rt_ref.endswith(" *)")) {
      if (can_ret_null) {
        os
            << "  if (!val) {\n"
            << "    return std::nullopt;\n"
            << "  }\n"
            << rt_val;
      } else {
        os << rt_val
           << "  " PASTA_ASSERT_THROW "\""
           << class_name << "::"
           << meth_name << " can return nullptr!\");\n";
      }
    } else {
      assert(!can_ret_null);
      os << rt_val;
    }
    os << "}\n\n";

  } else if (!strcmp(class_name.c_str(), "DesignatedInitExpr") &&
      !strcmp(meth_name.c_str(), "Designator")) {
    os << rt_type << " " << class_name << "::" << meth_name << "(unsigned int idx) const {\n"
       << "  auto &self = *const_cast<clang::"<< class_name << " *>(u." << class_name  <<");\n"
       << "  if (idx >= self.designators().size()) {\n"
       << "    return std::nullopt;\n"
       << "  }\n"
       << "  decltype(auto) val = self." << meth_name_ref.str() << "(idx);\n"
       << "  if (!val) {\n"
       << "    return std::nullopt;\n"
       << "  }\n"
       << rt_val
       << "  " PASTA_ASSERT_THROW "\"The unreachable has been reached\");\n"
       << "}\n\n";
  } else { \
    os << "// 1: " << class_name << "::" << meth_name << "\n";
    return;
  }
  os_py << "\n    .def_prop_ro(\"" << CapitalCaseToSnakeCase(meth_name) << "\", &" << class_name << "::" << meth_name << ")";
}

static void DefineIterators(std::ostream &os, const std::string &class_name) {
  for (const IteratorSpec &iterator : gIterators[class_name]) {
    auto &rt_type = gRetTypeMap[iterator.elem_type];
    auto &rt_val = gRetTypeToValMap[iterator.elem_type];
    os << "std::vector<" << rt_type << "> " << class_name << "::"
       << iterator.cxx_method << "(void) const {\n"
       << "  std::vector<" << rt_type << "> ret;\n";

    std::pair<std::string, std::string> null_key(class_name, iterator.cxx_method);
    if (auto null_it = kConditionalNullptr.find(null_key); null_it != kConditionalNullptr.end()) {
      os << null_it->second;
    }

    os << "  auto convert_elem = [&] ("
       << iterator.elem_type.substr(1, iterator.elem_type.size() - 2)
       << " val) {\n";

    std::stringstream ss;
    ss << rt_val;

    auto last_is_rbrace = false;
    for (std::string line; std::getline(ss, line); line.clear()) {
      os << "  " << line << "\n";
      last_is_rbrace = line == "  }";
    }

    if (last_is_rbrace) {
      os << "    " PASTA_ASSERT_THROW "\"The unreachable has been reached\");\n";
    }

    os << "  };\n"
       << "  auto count = u." << class_name << "->"
       << iterator.counter_method << "();\n"
       << "  decltype(count) i = 0;\n"
       << "  for (; i < count; ++i) {\n"
       << "    ret.emplace_back(convert_elem(u." << class_name << "->";

    if (!iterator.getter_method.empty()) {
      os << iterator.getter_method << "(i)));\n";

    } else if (!iterator.list_method.empty()) {
      os << iterator.list_method << "()[i]));\n";

    } else {
      assert(false);
    }

    os << "  }\n"
       << "  return ret;\n"
       << "}\n\n";
  }
}

}  // namespace

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      DefineCppMethod0(os, class_name, PASTA_STR(meth), PASTA_STR(rt), os_py); \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      DefineCppMethod1(os, class_name, PASTA_STR(meth), PASTA_STR(rt), \
                       PASTA_STR(p0), os_py); \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      if (const auto meth_name = CxxName(class_name, PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 2: " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      if (const auto meth_name = CxxName(class_name, PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 3: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      if (const auto meth_name = CxxName(class_name, PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 4: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      if (const auto meth_name = CxxName(class_name, PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 5: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name, std::ostream &os_py) { \
      if (const auto meth_name = CxxName(class_name, PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 6: " << class_name << "::" << meth_name << "\n"; \
      } \
    }
#include "Generated.h"

void DefineCppMethods(std::ostream &os, const std::string &class_name,
                      uint32_t class_id, std::ostream &os_py) {

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name, os_py); \
    }

#include "Generated.h"

  DefineIterators(os, class_name);
}
