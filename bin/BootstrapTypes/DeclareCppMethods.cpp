/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <cctype>
#include <ostream>
#include <string>
#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/ADT/StringRef.h>
#pragma clang diagnostic pop

#include "Globals.h"
#include "Util.h"

namespace {

static llvm::StringRef meth_name_ref;
static std::set<std::pair<std::string, std::string>> existing_methods;
static std::unordered_map<std::string, std::string> ret_type;
static std::unordered_map<std::string, llvm::StringRef> get_num_method;
static std::unordered_multimap<std::string, llvm::StringRef> get_nth_method;
static std::unordered_multimap<std::string, llvm::StringRef> get_list_method;

static std::unordered_multimap<std::string, std::tuple<llvm::StringRef, llvm::StringRef>> class_methods0;
static std::unordered_multimap<std::string, std::tuple<llvm::StringRef, llvm::StringRef, llvm::StringRef>> class_methods1;

static void CollectGetNumMethod(const std::string &class_name,
                                llvm::StringRef rt) {
  if (meth_name_ref.startswith("get") && meth_name_ref.contains("Num") &&
      rt == "(unsigned int)") {
    std::tuple<llvm::StringRef, llvm::StringRef> t{meth_name_ref, rt};
    class_methods0.emplace(class_name, std::move(t));

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
    } else {
      std::stringstream ss;
      auto max_i = meth_name_ref.find("Num");
      for (auto i = 3u; i < max_i; ++i) {
        ss << meth_name_ref[i];
      }
      auto len = meth_name_ref.size();
      if (meth_name_ref.endswith("s")) {
        len -= 1;
      }
      for (auto i = max_i + 3; i < len; ++i) {
        ss << meth_name_ref[i];
      }
      get_num_method.emplace(
          ss.str(), meth_name_ref);
    }

  // List form, returns an array of pointers.
  } else if (rt.endswith(" *const *)") &&
             meth_name_ref.startswith("get") &&
             meth_name_ref.endswith("s")) {

    std::tuple<llvm::StringRef, llvm::StringRef> t{meth_name_ref, rt};
    class_methods0.emplace(class_name, std::move(t));

    std::stringstream ss;
    ss << rt.substr(0, rt.size() - 8u).str()  // Chop off `const *)`.
       << ')';  // Re-introduce `)`.

    get_list_method.emplace(
        meth_name_ref.substr(3, meth_name_ref.size() - 4).str(),
        meth_name_ref);
    ret_type.emplace(meth_name_ref.str(), ss.str());
  }
}

static void CollectGetNthMethod(const std::string &class_name,
                                llvm::StringRef p0, llvm::StringRef rt) {
  if (p0 == "(unsigned int)" && meth_name_ref.startswith("get")) {
    std::tuple<llvm::StringRef, llvm::StringRef, llvm::StringRef> t{meth_name_ref, p0, rt};
    class_methods1.emplace(class_name, std::move(t));

    std::stringstream ss;
    ss << meth_name_ref[3u];
    for (auto i = 4u; i < meth_name_ref.size(); ++i) {
      if (std::isupper(meth_name_ref[i])) {
        get_nth_method.emplace(ss.str(), meth_name_ref);
      }
      ss << meth_name_ref[i];
    }
    get_nth_method.emplace(ss.str(), meth_name_ref);
    ret_type.emplace(meth_name_ref.str(), rt.str());
  }
}

static void DeclareCppMethod0(std::ostream &os, const std::string &class_name,
                              const char *meth, const char *rt) {
  meth_name_ref = meth;
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

  if (class_name.find("Decl") != std::string::npos) {
    if (meth_name_ref == "getLocation" || meth_name_ref == "getSourceRange") {
      return;
    }
  }

  CollectGetNumMethod(class_name, rt);
  if (const auto meth_name = CxxName(meth_name_ref);
      !meth_name.empty() && meth_name != "Clone") {

    // NOTE(pag): We leave `Decl::isImplicit` here even though it's excluded
    //            in `DefineCppMethods.cpp` because we imlement our own
    //            `Decl::IsImplicit` in pasta.
    if (class_name == "Decl" &&
        (meth_name_ref == "getKind" || meth_name_ref == "getDeclKindName" ||
         meth_name_ref == "getBody" || meth_name_ref == "getBodyRBrace")) {
      return;
    }

    if (class_name == "Attr" &&
        (meth_name_ref == "getKind" ||
         meth_name_ref == "getAttributeSpellingListIndex")) {
      return;
    }

    auto &new_rt = gRetTypeMap[rt];
    if (new_rt.empty()) {
      os << "  // " << meth_name << ": " << rt << "\n";
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
      os << "  std::optional<" << new_rt << "> " << meth_name << "(void) const;\n";
    } else {
      os << "  " << new_rt << ' ' << meth_name << "(void) const;\n";
    }
  }
}

static void DeclareCppMethod1(
    std::ostream &os, const std::string &class_name,
    const char *meth, const char *rt, const char *p0) {
  meth_name_ref = meth;
  CollectGetNthMethod(class_name, p0, rt);
  if (const auto meth_name = CxxName(meth_name_ref);
      !meth_name.empty() && meth_name != "Clone") {
    const auto null_key = std::make_pair(class_name, meth_name);
    const auto can_ret_null = kCanReturnNullptr.count(null_key) ||
                              kConditionalNullptr.count(null_key);
    auto &new_rt = gRetTypeMap[rt];
    if (!new_rt.empty() &&
        (!strcmp(p0, "(const clang::ASTContext &)") ||
         !strcmp(p0, "(clang::ASTContext &)"))) {

      if (can_ret_null) {
        os << "  std::optional<" << new_rt << "> " << meth_name << "(void) const;\n";
      } else {
        os << "  " << new_rt << ' ' << meth_name << "(void) const;\n";
      }
    } else if (!new_rt.empty() && !strcmp(p0, "(bool)")) {
      if (can_ret_null) {
        os << "  std::optional<" << new_rt << "> " << meth_name << "(bool) const;\n";
      } else {
        os << "  " << new_rt << ' ' << meth_name << "(bool) const;\n";
      }
    } else if (!new_rt.empty() &&
        !strcmp(class_name.c_str(), "DesignatedInitExpr") &&
        !strcmp(meth_name.c_str(), "Designator")) {
      os << "  " << new_rt << ' ' << meth_name << "(unsigned int) const;\n";
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
      const std::string &rt = ret_type[getter_method.str()];
      const std::string &new_rt = gRetTypeMap[rt];
      if (new_rt.empty()) {
        os << "  // !!! " << count << " " << counter_method.str() << " "
           << getter_method.str() << " (empty ret type = " << rt << ")\n";
        continue;
      }

      std::string plural_name = getter_method.str() + "s";
      std::string name = CxxName(plural_name);  // `CxxName` will chop off the `get`.
      if (name.empty() || name == "s" || name == "S") {
        os << "  // !!! " << count << " " << counter_method.str()
           << " " << getter_method.str() << " (bad CxxName)\n";
        continue;
      }

      auto meth_key = std::make_pair(class_name, name);
      auto [_, added] = existing_methods.insert(std::move(meth_key));
      if (!added) {
        continue;  // Already defined.
      }

      os << "  std::vector<" << new_rt << "> " << name << "(void) const;\n";

      IteratorSpec spec;
      spec.counter_method = counter_method.str();
      spec.getter_method = getter_method.str();
      spec.cxx_method = std::move(name);
      spec.elem_type = rt;
      gIterators[class_name].emplace_back(std::move(spec));
    }

    for (auto [it, end] = get_list_method.equal_range(count); it != end; ++it) {
      llvm::StringRef list_method = it->second;
      const std::string &rt = ret_type[list_method.str()];
      const std::string &new_rt = gRetTypeMap[rt];
      if (new_rt.empty()) {
        os << "  // !!! " << count << " " << counter_method.str() << " "
           << list_method.str() << " (empty ret type = " << rt << ")\n";
        continue;
      }

      std::string name = CxxName(list_method);  // `CxxName` will chop off the `get`.
      if (name.empty()) {
        os << "  // !!! " << count << " " << counter_method.str()
           << " " << list_method.str() << " (bad CxxName)\n";
        continue;
      }

      auto meth_key = std::make_pair(class_name, name);
      auto [_, added] = existing_methods.insert(std::move(meth_key));
      if (!added) {
        continue;  // Already defined.
      }

      os << "  std::vector<" << new_rt << "> " << name << "(void) const;\n";

      IteratorSpec spec;
      spec.counter_method = counter_method.str();
      spec.list_method = list_method.str();
      spec.cxx_method = std::move(name);
      spec.elem_type = rt;
      gIterators[class_name].emplace_back(std::move(spec));
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
  get_list_method.clear();

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

  // Make iterator identification work across base/derived classes.
  for (const std::string &base_class_name : gBaseClasses[class_name]) {
    assert(base_class_name != class_name);

    std::vector<std::tuple<llvm::StringRef, llvm::StringRef>> methods0;
    std::vector<std::tuple<llvm::StringRef, llvm::StringRef, llvm::StringRef>> methods1;

    for (auto [it, end] = class_methods0.equal_range(base_class_name);
         it != end; ++it) {
      methods0.emplace_back(it->second);
    }

    for (auto [it, end] = class_methods1.equal_range(base_class_name);
         it != end; ++it) {
      methods1.emplace_back(it->second);
    }

    for (auto [name, rt] : methods0) {
      meth_name_ref = name;
      CollectGetNumMethod(class_name, rt);
    }

    for (auto [name, p0, rt] : methods1) {
      meth_name_ref = name;
      CollectGetNthMethod(class_name, p0, rt);
    }
  }

  ProcessIterators(os, class_name);
}
