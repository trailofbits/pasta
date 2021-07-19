/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        auto &rt_type = gRetTypeMap[PASTA_STR(rt)]; \
        auto &rt_val = gRetTypeToValMap[PASTA_STR(rt)]; \
        llvm::StringRef rt_ref(PASTA_STR(rt)); \
        if (!rt_type.empty() && !rt_val.empty()) { \
          const auto can_ret_null = kCanReturnNullptr.count(\
              std::make_pair(class_name, meth_name)); \
          if (can_ret_null) { \
            os << "std::optional<" << rt_type << ">"; \
          } else { \
            os << rt_type; \
          } \
          os << " " << class_name << "::" << meth_name << "(void) const {\n" \
             << "  auto val = u." << class_name << "->" << PASTA_STR(meth) << "();\n" \
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
        } else { \
          os << "// 0: " << class_name << "::" << meth_name << "\n"; \
        } \
      } \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 1: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 2: " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 3: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 4: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 5: " << class_name << "::" << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    [[gnu::noinline, gnu::optnone]] \
    static void DefineCppMethod_ ## id ## _ ## meth_id( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "// 6: " << class_name << "::" << meth_name << "\n"; \
      } \
    }
#include "Generated.h"

[[gnu::optnone]]
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
