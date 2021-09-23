/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <memory>

#include "Forward.h"

namespace clang {
class CXXBaseSpecifier;
}  // namespace clang
namespace pasta {

class ASTImpl;
//
//class CXXBaseSpecifier {
// private:
//  std::shared_ptr<ASTImpl> ast;
//  const clang::CXXBaseSpecifier *spec;
//
// public:
//  ::pasta::TokenRange TokenRange(void) const;
//  Token BaseTypeToken(void) const;
//  bool IsVirtual(void) const;
//  bool isBaseOfClass(void) const;
//  bool IsPackExpansion(void) const;
//  bool InheritConstructors(void) const;
//
//  /// Set that this base class's constructors should be inherited.
//  void setInheritConstructors(bool Inherit = true) {
//    InheritConstructors = Inherit;
//  }
//
//  /// For a pack expansion, determine the location of the ellipsis.
//  SourceLocation getEllipsisLoc() const {
//    return EllipsisLoc;
//  }
//
//  /// Returns the access specifier for this base specifier.
//  ///
//  /// This is the actual base specifier as used for semantic analysis, so
//  /// the result can never be AS_none. To retrieve the access specifier as
//  /// written in the source code, use getAccessSpecifierAsWritten().
//  AccessSpecifier getAccessSpecifier() const {
//    if ((AccessSpecifier)Access == AS_none)
//      return BaseOfClass? AS_private : AS_public;
//    else
//      return (AccessSpecifier)Access;
//  }
//
//  /// Retrieves the access specifier as written in the source code
//  /// (which may mean that no access specifier was explicitly written).
//  ///
//  /// Use getAccessSpecifier() to retrieve the access specifier for use in
//  /// semantic analysis.
//  AccessSpecifier getAccessSpecifierAsWritten() const {
//    return (AccessSpecifier)Access;
//  }
//
//  /// Retrieves the type of the base class.
//  ///
//  /// This type will always be an unqualified class type.
//  QualType getType() const {
//    return BaseTypeInfo->getType().getUnqualifiedType();
//  }
//
//  /// Retrieves the type and source location of the base class.
//  TypeSourceInfo *getTypeSourceInfo() const { return BaseTypeInfo; }
//};

}  // namespace pasta
