/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

namespace {

static const std::string gTypeClassName{"Type"};

static void DefineCppMethod0(std::ostream &os, const std::string &class_name,
                             llvm::StringRef meth_name_ref,
                             llvm::StringRef rt_ref) {

  // `NamedDecl::getName` has an assertion in it where `getNameAsString` does
  // not, and we introduce a method rename for `getNameAstString` to
  // `getName`.
  if (meth_name_ref == "getName") {
    if (class_name == "NamedDecl" ||
        class_name == "ObjCImplementationDecl") {
      return;
    }
  }

  const auto is_qual_type = class_name == "QualType";
  const auto &real_class_name = is_qual_type ? gTypeClassName : class_name;
  const std::string meth_name = CxxName(meth_name_ref);
  if (meth_name.empty()) { \
    os << "// 0: " << real_class_name << "::" << meth_name << "\n";
    return;
  }

  if (class_name == "Decl" &&
      (meth_name_ref == "getKind" || meth_name_ref == "getDeclKindName")) {
    return;
  }

  if (class_name.find("Decl") != std::string::npos) {
    if (meth_name_ref == "getLocation" || meth_name_ref == "getSourceRange") {
      return;
    }
  }

  std::string rt_str = rt_ref.str();
  auto &rt_type = gRetTypeMap[rt_str];
  auto &rt_val = gRetTypeToValMap[rt_str];

  if (rt_type.empty() || rt_val.empty()) {
    os << "// 0: " << real_class_name << "::" << meth_name << "\n";
    return;
  }
  const auto can_ret_null = kCanReturnNullptr.count(
      std::make_pair(class_name, meth_name));
  if (can_ret_null) {
    os << "std::optional<" << rt_type << ">";
  } else {
    os << rt_type;
  }

  os << " " << real_class_name << "::" << meth_name << "(void) const noexcept {\n";

  if (is_qual_type) {
    os << "  auto &ast_ctx = ast->ci->getASTContext();\n"
       << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n"
       << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n";
  } else {
    os << "  auto &self = *const_cast<clang::" << class_name << " *>(u." << class_name << ");\n";
  }
  os << "  auto val = self." << meth_name_ref.str() << "();\n"
     << rt_val;
  if (rt_ref.endswith(" *)")) {
    if (can_ret_null) {
      os << "  return std::nullopt;\n";
    } else {
      os << "  assert(false && \"" << class_name << "::"
         << meth_name << " can return nullptr!\");\n"
         << "  __builtin_unreachable();\n";
    }
  }

  os << "}\n\n";
}


static void DefineCppMethod1(std::ostream &os, const std::string &class_name,
                             llvm::StringRef meth_name_ref,
                             llvm::StringRef rt_ref, llvm::StringRef p0_ref) {
  const auto is_qual_type = class_name == "QualType";
  const auto &real_class_name = is_qual_type ? gTypeClassName : class_name;
  const auto meth_name = CxxName(meth_name_ref); \
  if (meth_name.empty()) {
    os << "// 1: " << real_class_name << "::" << meth_name << "\n";
    return;
  }

  std::string rt_str = rt_ref.str();
  auto &rt_type = gRetTypeMap[rt_str];
  auto &rt_val = gRetTypeToValMap[rt_str];

  if (rt_type.empty() || rt_val.empty()) {
    os << "// 1: " << real_class_name << "::" << meth_name << "\n";
    return;
  }

  if (p0_ref == "(const clang::ASTContext &)" ||
      p0_ref == "(clang::ASTContext &)") {
    const auto can_ret_null = kCanReturnNullptr.count(
        std::make_pair(class_name, meth_name));
    if (can_ret_null) {
      os << "std::optional<" << rt_type << ">";
    } else {
      os << rt_type;
    }
    os << " " << real_class_name << "::" << meth_name << "(void) const noexcept {\n";
    if (is_qual_type) {
      os << "  auto &ast_ctx = ast->ci->getASTContext();\n"
         << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n"
         << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n";
    } else {
      os << "  auto &self = *(u." << class_name << ");\n";
    }
    os << "  auto val = self." << meth_name_ref.str() << "(ast->ci->getASTContext());\n"
       << rt_val;
    if (rt_ref.endswith(" *)")) {
      if (can_ret_null) {
        os << "  return std::nullopt;\n";
      } else {
        os << "  assert(false && \"" << class_name << "::"
           << meth_name << " can return nullptr!\");\n"
           << "  __builtin_unreachable();\n";
      }
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
    os << " " << real_class_name << "::" << meth_name << "(bool b) const noexcept {\n";
    if (is_qual_type) {
      os << "  auto &ast_ctx = ast->ci->getASTContext();\n"
         << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n"
         << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n";
    } else {
      os << "  auto &self = *(u." << class_name << ");\n";
    }
    os << "  auto val = self." << meth_name_ref.str() << "(b);\n"
       << rt_val;
    if (rt_ref.endswith(" *)")) {
      if (can_ret_null) {
        os << "  return std::nullopt;\n";
      } else {
        os << "  assert(false && \"" << class_name << "::"
           << meth_name << " can return nullptr!\");\n"
           << "  __builtin_unreachable();\n";
      }
    }
    os << "}\n\n";

  } else { \
    os << "// 1: " << real_class_name << "::" << meth_name << "\n";
    return;
  }
}

static void DefineIterators(std::ostream &os, const std::string &class_name) {
  for (const IteratorSpec &iterator : gIterators[class_name]) {
    auto &rt_type = gRetTypeMap[iterator.elem_type];
    auto &rt_val = gRetTypeToValMap[iterator.elem_type];
    os << "std::vector<" << rt_type << "> " << class_name << "::"
       << iterator.cxx_method << "(void) const noexcept {\n"
       << "  auto convert_elem = [&] ("
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
      os << "    __builtin_unreachable();\n";
    }

    os << "  };\n"
       << "  std::vector<" << rt_type << "> ret;\n"
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
        std::ostream &os, const std::string &class_name) { \
      DefineCppMethod0(os, class_name, PASTA_STR(meth), PASTA_STR(rt)); \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      DefineCppMethod1(os, class_name, PASTA_STR(meth), PASTA_STR(rt), \
                       PASTA_STR(p0)); \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 2: " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 3: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 4: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 5: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 6: " << class_name << "::" << meth_name << "\n"; \
      } \
    }
#include "Generated.h"

void DefineCppMethods(std::ostream &os, const std::string &class_name,
                      uint32_t class_id) {

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_id == id) { \
      DefineCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#include "Generated.h"

  DefineIterators(os, class_name);
}
