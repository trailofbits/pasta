/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#ifndef PASTA_IN_BOOTSTRAP
#  error "`PASTA_IN_BOOTSTRAP` must be defined."
#endif

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#include <llvm/ADT/StringRef.h>
#pragma clang diagnostic pop

#include <pasta/Util/Compiler.h>

#include "BootstrapConfig.h"
#include "Globals.h"
#include "Util.h"

// Adds mappings between clang AST pointer types and PASTA wrapper types for
// every category (defined in MapRetTypes.cpp).
void MapAllRetTypes(void);

// Generate `include/pasta/AST/Forward.h` (and the Python `Enums.cpp`).
void GenerateForwardH(std::ostream& os_py);

// Generate `include/pasta/AST/Decl.h`.
void GenerateDeclH(void);

// Generate `lib/AST/Decl.cpp`.
void GenerateDeclCpp(std::ostream& py_cmake, std::ostream &py_ast);

// Generate `include/pasta/AST/Stmt.h`.
void GenerateStmtH(void);

// Generate `lib/AST/Stmt.cpp`.
void GenerateStmtCpp(std::ostream& py_cmake, std::ostream &py_ast);

// Generate `include/pasta/AST/Type.h`.
void GenerateTypeH(void);

// Generate `lib/AST/Type.cpp`.
void GenerateTypeCpp(std::ostream& py_cmake, std::ostream &py_ast);

// Generate `include/pasta/AST/Attr.h`.
void GenerateAttrH(void);

// Generate `lib/AST/Attr.cpp`.
void GenerateAttrCpp(std::ostream& py_cmake, std::ostream &py_ast);

namespace {

struct CategoryDispatch {
  const char *name;
  std::vector<std::string> *names;
  std::vector<std::string> *topo_names;
  void (*generate_h)();
  void (*generate_cpp)(std::ostream &py_cmake, std::ostream &py_ast);
};

// Canonical category order: matches today's prepass order (topo_sort,
// transitive_rels, ret-type mapping). Codegen runs these in a different
// order — see `kCodegenOrder` below.
const CategoryDispatch kCategories[] = {
  {"Decl", &gDeclNames, &gTopologicallyOrderedDecls, &GenerateDeclH, &GenerateDeclCpp},
  {"Stmt", &gStmtNames, &gTopologicallyOrderedStmts, &GenerateStmtH, &GenerateStmtCpp},
  {"Type", &gTypeNames, &gTopologicallyOrderedTypes, &GenerateTypeH, &GenerateTypeCpp},
  {"Attr", &gAttrNames, &gTopologicallyOrderedAttrs, &GenerateAttrH, &GenerateAttrCpp},
};

// Codegen runs Attr first (its emission populates gIterators with attribute-
// related entries that the other generators may consult), then Decl/Stmt/Type.
// Indices into `kCategories`.
const std::size_t kCodegenOrder[] = {3, 0, 1, 2};

}  // namespace

static void InitClassIDs(void) {
#define PASTA_BEGIN_CLANG_WRAPPER(cls, id) \
    gClassIDs[kClassName_ ## id] = id;

#include "Generated.h"
}

int main(void) {
  InitClassIDs();

  std::unordered_set<std::string> seen;
  seen.insert("DeclContext");

  //gBaseClasses["Decl"].insert("DeclBase");
  //gBaseClasses["DeclContext"].insert("DeclBase");

  // Build the inheritance graph first so that categorization can walk it. The
  // graph is the union of edges emitted into `Generated.h` (kExtends) and the
  // manual edges that wire in synthesized intermediate template classes
  // (kAdditionalExtends).
  for (const auto *edges : {&kExtends, &kAdditionalExtends}) {
    for (const auto &[name, base_name] : *edges) {
      gBaseClasses[name].insert(base_name);
      gDerivedClasses[base_name].insert(name);
    }
  }

  // Categorize each wrappable class by walking its base chain to a known root.
  // Classes that resolve to `None` and aren't in the opt-out set abort the
  // bootstrap rather than silently dropping out of the wrapper API.
  for (auto class_name : kAllClassNames) {
    auto str = class_name.str();
    switch (ResolveCategory(str)) {
      case Category::Decl: gDeclNames.push_back(std::move(str)); break;
      case Category::Stmt: gStmtNames.push_back(std::move(str)); break;
      case Category::Type: gTypeNames.push_back(std::move(str)); break;
      case Category::Attr: gAttrNames.push_back(std::move(str)); break;
      case Category::None:
        if (!kCategorizationOptOut.count(str)) {
          std::cerr << "BootstrapTypes: no category for class '" << str
                    << "'; add an entry to kAdditionalExtends in Globals.cpp "
                       "or kCategorizationOptOut if it should be skipped.\n";
          std::abort();
        }
        break;
    }
  }

  gTypeNames.push_back("TypeWithKeyword");

  auto topo_sort = [&seen](const std::vector<std::string> &names,
                           std::vector<std::string> &ordered_names) {
    for (auto changed = true; changed; ) {
      changed = false;
      for (const auto &name : names) {
        if (seen.count(name)) {
          goto skip;
        }

        for (const auto &parent_name : gBaseClasses[name]) {
          if (!seen.count(parent_name)) {
            goto skip;
          }
        }

        ordered_names.push_back(name);
        seen.insert(name);
        changed = true;

      skip:
        continue;
      }
    }
  };

  // Topologically order the classes by the parent/child relations.
  for (const auto &cat : kCategories) {
    topo_sort(*cat.names, *cat.topo_names);
  }

  auto transitive_rels = [] (const std::vector<std::string> &names) {

    // Go find the transitive base classes. Rely on the topological order
    // so that we can do it in a single pass.
    for (const auto &base_name : names) {
      const auto &base_classes = gTransitiveBaseClasses[base_name];

      for (auto &derived_name : gDerivedClasses[base_name]) {
        auto &derived_base_classes = gTransitiveBaseClasses[derived_name];
        derived_base_classes.insert(base_name);
        derived_base_classes.insert(base_classes.begin(), base_classes.end());
      }
    }

    // Go find the transitive derived classes. Rely on the reverse topological
    // order so that we can do it in a single pass.
    for (auto it = names.rbegin(); it != names.rend(); ++it) {
      const auto &derived_name = *it;
      const auto &derived_classes = gTransitiveDerivedClasses[derived_name];

      for (auto &base_name : gBaseClasses[derived_name]) {
        auto &base_derived_classes = gTransitiveDerivedClasses[base_name];
        base_derived_classes.insert(derived_name);
        base_derived_classes.insert(derived_classes.begin(),
                                    derived_classes.end());
      }
    }
  };

  for (const auto &cat : kCategories) {
    transitive_rels(*cat.topo_names);
  }

  MapAllRetTypes();

  std::string python_bindings_path = kPythonBindingsPath;

  // NOTE(pag): This also maps enum return types.
  std::ofstream enums_os_py(python_bindings_path + "/Enums.cpp");
  GenerateForwardH(enums_os_py);

  // Generate headers first; they fill up `gIterators`. Iteration order
  // matches the historical Attr-first sequence.
  for (auto idx : kCodegenOrder) {
    kCategories[idx].generate_h();
  }

  std::ofstream py_cmake(python_bindings_path + "/CMakeLists.txt");
  std::ofstream py_ast(python_bindings_path + "/AST.cpp");

  py_cmake << R"(#
# Copyright (c) 2023 Trail of Bits, Inc.
#

# This file is auto-generated.

set(PASTA_PYTHON_AST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Enums.cpp"
)";
  py_ast << R"(/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <nanobind/nanobind.h>

namespace pasta {
namespace nb = nanobind;

void RegisterAllAST(nb::module_ &m) {
void RegisterEnums(nb::module_ &m);
  RegisterEnums(m);
)";

  for (auto idx : kCodegenOrder) {
    kCategories[idx].generate_cpp(py_cmake, py_ast);
  }

  py_cmake << "    PARENT_SCOPE)\n";

  py_ast << "}\n"
         << "} // namespace pasta\n";
  return EXIT_SUCCESS;
}

