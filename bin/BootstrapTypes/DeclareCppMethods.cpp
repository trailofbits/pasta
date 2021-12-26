/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <cctype>
#include <ostream>
#include <string>
#include <sstream>

#include "Globals.h"
#include "Util.h"

namespace {

static llvm::StringRef meth_name_ref;
static std::set<std::pair<std::string, std::string>> existing_methods;
static std::unordered_map<std::string, llvm::StringRef> ret_type;
static std::unordered_map<std::string, llvm::StringRef> get_num_method;
static std::unordered_multimap<std::string, llvm::StringRef> get_nth_method;

static void CollectGetNumMethod(void) {
  if (meth_name_ref.startswith("getNum")) {
    if (meth_name_ref.endswith("s")) {
      get_num_method.emplace(
          meth_name_ref.substr(6, meth_name_ref.size() - 7).str(),
          meth_name_ref);
    } else {
      get_num_method.emplace(
          meth_name_ref.substr(6, meth_name_ref.size() - 6).str(),
          meth_name_ref);
    }
  }
}

static void CollectGetNthMethod(const char *p0, const char *rt) {
  if (!strcmp(p0, "(unsigned int)") && meth_name_ref.startswith("get")) {
    std::stringstream ss;
    ss << meth_name_ref[3u];
    for (auto i = 4u; i < meth_name_ref.size(); ++i) {
      if (std::isupper(meth_name_ref[i])) {
        get_nth_method.emplace(ss.str(), meth_name_ref);
      }
      ss << meth_name_ref[i];
    }
    get_nth_method.emplace(ss.str(), meth_name_ref);
    ret_type.emplace(meth_name_ref.str(), rt);
  }
}

static void DeclareCppMethod0(std::ostream &os, const std::string &class_name,
                              const char *meth, const char *rt) {
  meth_name_ref = meth;
  CollectGetNumMethod();
  if (const auto meth_name = CxxName(meth_name_ref);
      !meth_name.empty()) {
    auto &new_rt = gRetTypeMap[rt];
    if (!new_rt.empty()) {
      auto meth_key = std::make_pair(class_name, meth_name);
      existing_methods.insert(meth_key);
      if (kCanReturnNullptr.count(meth_key)) {
        os << "  std::optional<" << new_rt << "> " << meth_name << "(void) const;\n";
      } else {
        os << "  " << new_rt << ' ' << meth_name << "(void) const;\n";
      }
    } else {
      os << "  // " << meth_name << ": " << rt << "\n";
    }
  }
}

static void DeclareCppMethod1(
    std::ostream &os, const std::string &class_name,
    const char *meth, const char *rt, const char *p0) {
  meth_name_ref = meth;
  CollectGetNthMethod(p0, rt);
  if (const auto meth_name = CxxName(meth_name_ref);
      !meth_name.empty()) {
    auto &new_rt = gRetTypeMap[rt];
    if (!new_rt.empty() &&
        (!strcmp(p0, "(const clang::ASTContext &)") ||
         !strcmp(p0, "(clang::ASTContext &)"))) {
      if (kCanReturnNullptr.count(std::make_pair(class_name, meth_name))) {
        os << "  std::optional<" << new_rt << "> " << meth_name << "(void) const;\n";
      } else {
        os << "  " << new_rt << ' ' << meth_name << "(void) const;\n";
      }
    } else {
      os << "  // " << meth_name << ": " << rt << "\n";
    }
  }
}

// Try to match up methods that get the count of something, with methods that
// get the Nth thing.
static void ProcessIterators(std::ostream &os, const std::string &class_name) {
  for (const auto &ent : get_num_method) {
    const std::string &count = ent.first;
    llvm::StringRef counter_method = ent.second;
    for (auto [it, end] = get_nth_method.equal_range(count); it != end; ++it) {
      llvm::StringRef getter_method = it->second;
      auto rt = ret_type[getter_method.str()].str();
      auto &new_rt = gRetTypeMap[rt];
      if (new_rt.empty()) {
        os << "  // !!! " << count << " " << counter_method.str() << " "
           << getter_method.str() << " (empty ret type = " << rt << ")\n";
        continue;
      }

      std::string name = CxxName(getter_method) + "s";  // `CxxName` will chop off the `get`.
      if (name == "s") {
        os << "  // !!! " << count << " " << counter_method.str()
           << " " << getter_method.str() << " (bad CxxName)\n";
        continue;
      }

      auto meth_key = std::make_pair(class_name, name);
      if (existing_methods.count(meth_key)) {
        continue;  // Already defined.
      }

      IteratorSpec spec;
      spec.counter_method = counter_method.str();
      spec.getter_method = getter_method.str();
      spec.cxx_method = name;
      spec.elem_type = rt;
      gIterators[class_name].emplace_back(std::move(spec));

      os << "  std::vector<" << new_rt << "> " << name << "(void) const;\n";
    }
  }
}

}  // namespace

#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
        std::ostream &os, const std::string &class_name) { \
      DeclareCppMethod0(os, class_name, PASTA_STR(meth), PASTA_STR(rt)); \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      DeclareCppMethod1(os, class_name, PASTA_STR(meth), PASTA_STR(rt), \
                        PASTA_STR(p0)); \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) \
    [[gnu::noinline]] \
    static void DeclareCppMethod_ ## id ## _ ## meth_id ( \
      std::ostream &os, const std::string &class_name) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); \
          !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(rt) << "\n"; \
      } \
    }

#include "Generated.h"

void DeclareCppMethods(std::ostream &os, const std::string &class_name,
                       uint32_t class_id) {
  ret_type.clear();
  get_num_method.clear();
  get_nth_method.clear();

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

  ProcessIterators(os, class_name);
}
