/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

static const std::string gTypeClassName{"Type"};

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      const auto is_qual_type = class_name == "QualType"; \
      const auto &real_class_name = is_qual_type ? gTypeClassName : class_name; \
      const auto meth_name = CxxName(PASTA_STR(meth)); \
      if (meth_name.empty()) { \
        os << "// 0: " << real_class_name << "::" << meth_name << "\n"; \
        return; \
      } \
      auto &rt_type = gRetTypeMap[PASTA_STR(rt)]; \
      auto &rt_val = gRetTypeToValMap[PASTA_STR(rt)]; \
      llvm::StringRef rt_ref(PASTA_STR(rt)); \
      if (rt_type.empty() || rt_val.empty()) { \
        os << "// 0: " << real_class_name << "::" << meth_name << "\n"; \
        return; \
      } \
      const auto can_ret_null = kCanReturnNullptr.count(\
          std::make_pair(class_name, meth_name)); \
      if (can_ret_null) { \
        os << "std::optional<" << rt_type << ">"; \
      } else { \
        os << rt_type; \
      } \
      os << " " << real_class_name << "::" << meth_name << "(void) const {\n"; \
      if (is_qual_type) { \
        os << "  auto &ast_ctx = ast->ci->getASTContext();\n" \
           << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n" \
           << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n"; \
      } else { \
        os << "  auto &self = *(u." << class_name << ");\n"; \
      } \
      os << "  auto val = self." << PASTA_STR(meth) << "();\n" \
         << rt_val; \
      if (rt_ref.endswith(" *)")) { \
        if (can_ret_null) { \
          os << "  return std::nullopt;\n"; \
        } else { \
          os << "  assert(false && \"" << class_name << "::" \
             << meth_name << " can return nullptr!\");\n" \
             << "  __builtin_unreachable();\n"; \
        } \
      } \
      os << "}\n\n"; \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    [[gnu::noinline]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      const auto is_qual_type = class_name == "QualType"; \
      const auto &real_class_name = is_qual_type ? gTypeClassName : class_name; \
      const auto meth_name = CxxName(PASTA_STR(meth)); \
      if (meth_name.empty()) { \
        os << "// 1: " << real_class_name << "::" << meth_name << "\n"; \
        return; \
      } \
      auto &rt_type = gRetTypeMap[PASTA_STR(rt)]; \
      auto &rt_val = gRetTypeToValMap[PASTA_STR(rt)]; \
      llvm::StringRef rt_ref(PASTA_STR(rt)); \
      if (rt_type.empty() || rt_val.empty()) { \
        os << "// 1: " << real_class_name << "::" << meth_name << "\n"; \
        return; \
      } \
      if (strcmp(PASTA_STR(p0), "(const clang::ASTContext &)")) { \
        os << "// 1: " << real_class_name << "::" << meth_name << "\n"; \
        return; \
      } else { \
        const auto can_ret_null = kCanReturnNullptr.count(\
            std::make_pair(class_name, meth_name)); \
        if (can_ret_null) { \
          os << "std::optional<" << rt_type << ">"; \
        } else { \
          os << rt_type; \
        } \
        os << " " << real_class_name << "::" << meth_name << "(void) const {\n"; \
        if (is_qual_type) { \
          os << "  auto &ast_ctx = ast->ci->getASTContext();\n" \
             << "  clang::QualType fast_qtype(u.Type, qualifiers & clang::Qualifiers::FastMask);\n" \
             << "  auto self = ast_ctx.getQualifiedType(fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));\n"; \
        } else { \
          os << "  auto &self = *(u." << class_name << ");\n"; \
        } \
        os << "  auto val = self." << PASTA_STR(meth) << "(ast->ci->getASTContext());\n" \
           << rt_val; \
        if (rt_ref.endswith(" *)")) { \
          if (can_ret_null) { \
            os << "  return std::nullopt;\n"; \
          } else { \
            os << "  assert(false && \"" << class_name << "::" \
               << meth_name << " can return nullptr!\");\n" \
               << "  __builtin_unreachable();\n"; \
          } \
        } \
        os << "}\n\n"; \
      } \
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
}
