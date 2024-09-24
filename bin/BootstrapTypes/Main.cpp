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

//// Adds mappings that translate between clang enumeration types and PASTA
//// enumeration types.
//void MapEnumRetTypes(void);

// Adds mappings that translate between pointers to clang Decl types and PASTA
// Decl types.
void MapDeclRetTypes(void);

// Adds mappings that translate between pointers to clang Stmt types and PASTA
// Stmt types.
void MapStmtRetTypes(void);

// Adds mappings that translate between pointers to clang Type types and PASTA
// Type types.
void MapTypeRetTypes(void);

// Adds mappings that translate between pointers to clang Type types and PASTA
// Type types.
void MapAttrRetTypes(void);

// Generate `include/pasta/AST/Forward.h`.
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

// Generate `lib/pasta/AST/Type.cpp`.
void GenerateTypeCpp(std::ostream& py_cmake, std::ostream &py_ast);

// Generate `include/pasta/AST/Attr.h`.
void GenerateAttrH(void);

// Generate `include/pasta/AST/Attr.cpp`.
void GenerateAttrCpp(std::ostream& py_cmake, std::ostream &py_ast);

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

  for (auto class_name : kAllClassNames) {
    if (class_name.ends_with("Decl")) {
      gDeclNames.push_back(class_name.str());

    } else if (class_name.ends_with("Stmt") ||
               class_name.ends_with("Expr") ||
               class_name.ends_with("Operator") ||
               class_name.ends_with("Directive") ||
               class_name.ends_with("Literal") ||
               class_name == "SwitchCase" ||
               class_name == "ExprWithCleanups" ||
               class_name == "OMPCanonicalLoop") {
      gStmtNames.push_back(class_name.str());

    } else if (class_name.ends_with("Type") && class_name != "QualType") {
      gTypeNames.push_back(class_name.str());
    } else if (class_name.ends_with("Attr")) {
      gAttrNames.push_back(class_name.str());
    }
  }

  gTypeNames.push_back("TypeWithKeyword");

  // Build up an adjacency list of parent/child relations.
  for (const auto &[name, base_name] : kExtends) {
    gBaseClasses[name].insert(base_name);
    gDerivedClasses[base_name].insert(name);
  }

  // Fixups. `OMPDeclarativeDirectiveDecl` and `OMPDeclarativeDirectiveValueDecl`
  // are classes defined in `bin/BootstrapMapcros/MacroGenerator.cpp` that
  // extend the intermediate templates, so that we can link everything together.
  gBaseClasses["OMPDeclarativeDirectiveDecl"].insert("Decl");
  gDerivedClasses["Decl"].insert("OMPDeclarativeDirectiveDecl");

  gBaseClasses["OMPDeclarativeDirectiveValueDecl"].insert("ValueDecl");
  gDerivedClasses["ValueDecl"].insert("OMPDeclarativeDirectiveValueDecl");

  gBaseClasses["OMPThreadPrivateDecl"].insert("OMPDeclarativeDirectiveDecl");
  gDerivedClasses["OMPDeclarativeDirectiveDecl"].insert("OMPThreadPrivateDecl");

  gBaseClasses["OMPAllocateDecl"].insert("OMPDeclarativeDirectiveDecl");
  gDerivedClasses["OMPDeclarativeDirectiveDecl"].insert("OMPAllocateDecl");

  gBaseClasses["OMPDeclareMapperDecl"].insert("OMPDeclarativeDirectiveValueDecl");
  gDerivedClasses["OMPDeclarativeDirectiveValueDecl"].insert("OMPDeclareMapperDecl");

  gBaseClasses["OMPRequiresDecl"].insert("OMPDeclarativeDirectiveDecl");
  gDerivedClasses["OMPDeclarativeDirectiveDecl"].insert("OMPRequiresDecl");

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
  topo_sort(gDeclNames, gTopologicallyOrderedDecls);
  topo_sort(gStmtNames, gTopologicallyOrderedStmts);
  topo_sort(gTypeNames, gTopologicallyOrderedTypes);
  topo_sort(gAttrNames, gTopologicallyOrderedAttrs);

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

  transitive_rels(gTopologicallyOrderedDecls);
  transitive_rels(gTopologicallyOrderedStmts);
  transitive_rels(gTopologicallyOrderedTypes);
  transitive_rels(gTopologicallyOrderedAttrs);

//  MapEnumRetTypes();
  MapDeclRetTypes();
  MapStmtRetTypes();
  MapTypeRetTypes();
  MapAttrRetTypes();

  std::string python_bindings_path = kPythonBindingsPath;

  // NOTE(pag): This also maps enum return types.
  std::ofstream enums_os_py(python_bindings_path + "/Enums.cpp");
  GenerateForwardH(enums_os_py);

  // Generate headers first; they fill up `gIterators`.
  GenerateAttrH();
  GenerateDeclH();
  GenerateStmtH();
  GenerateTypeH();

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

  GenerateAttrCpp(py_cmake, py_ast);
  GenerateDeclCpp(py_cmake, py_ast);
  GenerateStmtCpp(py_cmake, py_ast);
  GenerateTypeCpp(py_cmake, py_ast);

  py_cmake << "    PARENT_SCOPE)\n";

  py_ast << "}\n"
         << "} // namespace pasta\n";
  return EXIT_SUCCESS;
}

