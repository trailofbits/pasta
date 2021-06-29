/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

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

// Adds mappings that translate between clang enumeration types and PASTA
// enumeration types.
void MapEnumRetTypes(void);

// Adds mappings that translate between pointers to clang Decl types and PASTA
// Decl types.
void MapDeclRetTypes(void);

// Generate `include/pasta/AST/Forward.h`.
void GenerateForwardH(void);

// Generate `include/pasta/AST/Decl.h`.
void GenerateDeclH(void);

// Generate `lib/AST/Decl.cpp`.
void GenerateDeclCpp(void);

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

    } else if (class_name.endswith("Type")) {
      gTypeNames.push_back(class_name.str());
    }
  }

  // Build up an adjacency list of parent/child relations.
  for (const auto &[name, base_name] : kExtends) {
    gBaseClasses[name].insert(base_name);
    gDerivedClasses[base_name].insert(name);
  }

  // Topologically order the classes by the parent/child relations.
  for (auto changed = true; changed; ) {
    changed = false;
    for (const auto &name : gDeclNames) {
      if (seen.count(name)) {
        goto skip;
      }

      for (const auto &parent_name : gBaseClasses[name]) {
        if (!seen.count(parent_name)) {
          goto skip;
        }
      }

      gTopologicallyOrderedDecls.push_back(name);
      seen.insert(name);
      changed = true;

    skip:
      continue;
    }
  }

  // Go find the transitive base classes. Rely on the topological order
  // so that we can do it in a single pass.
  for (const auto &base_name : gTopologicallyOrderedDecls) {
    const auto &base_classes = gTransitiveBaseClasses[base_name];

    for (auto &derived_name : gDerivedClasses[base_name]) {
      auto &derived_base_classes = gTransitiveBaseClasses[derived_name];
      derived_base_classes.insert(base_name);
      derived_base_classes.insert(base_classes.begin(), base_classes.end());
    }
  }

  // Go find the transitive derived classes. Rely on the reverse topological
  // order so that we can do it in a single pass.
  for (auto it = gTopologicallyOrderedDecls.rbegin();
       it != gTopologicallyOrderedDecls.rend(); ++it) {
    const auto &derived_name = *it;
    const auto &derived_classes = gTransitiveDerivedClasses[derived_name];

    for (auto &base_name : gBaseClasses[derived_name]) {
      auto &base_derived_classes = gTransitiveDerivedClasses[base_name];
      base_derived_classes.insert(derived_name);
      base_derived_classes.insert(derived_classes.begin(),
                                  derived_classes.end());
    }
  }



  MapEnumRetTypes();
  MapDeclRetTypes();
  GenerateForwardH();
  GenerateDeclH();
  GenerateDeclCpp();

  return EXIT_SUCCESS;
}

