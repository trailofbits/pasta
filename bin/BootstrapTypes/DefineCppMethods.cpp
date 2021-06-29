/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

void DefineCppMethods(std::ostream &os, const std::string &class_name) {
#define PASTA_INSTANCE_METHOD_0(cls, id, meth, rt) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        auto &rt_type = kRetTypeMap[PASTA_STR(rt)]; \
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
          os << "  // " << meth_name << "\n"; \
        } \
      } \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth, rt, p0) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth, rt, p0, p1) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth, rt, p0, p1, p2) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth, rt, p0, p1, p2, p3) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }
#include "Generated.h"
}
