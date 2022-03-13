/*
 * Copyright (c) 2021 Trail of Bits, Inc.
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

#include <llvm/ADT/StringRef.h>

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

// Generate `include/pasta/AST/Forward.h`.
void GenerateForwardH(void);

// Generate `include/pasta/AST/Decl.h`.
void GenerateDeclH(void);

// Generate `lib/AST/Decl.cpp`.
void GenerateDeclCpp(void);

// Generate `include/pasta/AST/Stmt.h`.
void GenerateStmtH(void);

// Generate `lib/AST/Stmt.cpp`.
void GenerateStmtCpp(void);

// Generate `include/pasta/AST/Type.h`.
void GenerateTypeH(void);

// Generate `lib/pasta/AST/Type.cpp`.
void GenerateTypeCpp(void);

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
    if (class_name.endswith("Decl")) {
      gDeclNames.push_back(class_name.str());

    } else if (class_name.endswith("Stmt") ||
               class_name.endswith("Expr") ||
               class_name.endswith("Operator") ||
               class_name.endswith("Directive") ||
               class_name.endswith("Literal") ||
               class_name == "SwitchCase" ||
               class_name == "ExprWithCleanups" ||
               class_name == "OMPCanonicalLoop") {
      gStmtNames.push_back(class_name.str());

    } else if (class_name.endswith("Type") && class_name != "QualType") {
      gTypeNames.push_back(class_name.str());
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
  gDeclNames.push_back("OMPDeclarativeDirectiveDecl");
  gBaseClasses["OMPDeclarativeDirectiveDecl"].insert("Decl");
  gDerivedClasses["Decl"].insert("OMPDeclarativeDirectiveDecl");

  gDeclNames.push_back("OMPDeclarativeDirectiveValueDecl");
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

//  MapEnumRetTypes();
  MapDeclRetTypes();
  MapStmtRetTypes();
  MapTypeRetTypes();

  // NOTE(pag): This also maps enum return types.
  GenerateForwardH();

  // Generate headers first; they fill up `gIterators`.
  GenerateDeclH();
  GenerateStmtH();
  GenerateTypeH();

  GenerateDeclCpp();
  GenerateStmtCpp();
  GenerateTypeCpp();
  return EXIT_SUCCESS;
}

