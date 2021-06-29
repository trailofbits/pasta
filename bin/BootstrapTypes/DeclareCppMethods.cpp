/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
        std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        auto &new_rt = kRetTypeMap[PASTA_STR(rt)]; \
        if (!new_rt.empty()) { \
          if (kCanReturnNullptr.count(std::make_pair(class_name, meth_name))) { \
            os << "  std::optional<" << new_rt << "> " << meth_name << "(void) const;\n"; \
          } else { \
            os << "  " << new_rt << ' ' << meth_name << "(void) const;\n"; \
          } \
        } else { \
          os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
        } \
      } \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    [[gnu::noinline, gnu::optnone]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#include "Generated.h"

[[gnu::optnone]]
void DeclareCppMethods(std::ostream &os, const std::string &class_name,
                       uint32_t class_id) {

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_id == id) { \
      DeclareCppMethod_ ## id ## _ ## meth_id(os, class_name); \
    }

#include "Generated.h"
}
