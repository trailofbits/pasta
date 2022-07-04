/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/AttrManual.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Builder.h"

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP

// Returns the attribute syntax type
AttributeSyntax AttributeCommonInfo::Syntax(void) const noexcept {
  return static_cast<AttributeSyntax>(attr->getSyntax());
}

// Returns true if attribute syntax is declspec type
bool AttributeCommonInfo::IsDeclspecAttribute() const noexcept {
  return attr->isDeclspecAttribute();
}

// Returns true if attribute syntax is microsoft type
bool AttributeCommonInfo::IsMicrosoftAttribute() const noexcept {
  return attr->isMicrosoftAttribute();
}

// Returns true if attribute syntax is GNU type
bool AttributeCommonInfo::IsGNUScope() const noexcept {
  return attr->isGNUScope();
}

// Returns true if attribute syntax is alignas type
bool AttributeCommonInfo::IsAlignasAttribute() const noexcept {
  return attr->isAlignasAttribute();
}

// Returns true if attribute syntax is CXX11
bool AttributeCommonInfo::IsCXX11Attribute() const noexcept {
  return attr->isCXX11Attribute();
}

// Returns true if attribute syntax is C2x
bool AttributeCommonInfo::IsC2xAttribute() const noexcept {
  return attr->isC2xAttribute();
}

// Returns true if attribute syntax is keyword
bool AttributeCommonInfo::IsKeywordAttribute() const noexcept {
  return attr->isKeywordAttribute();
}

// Returns trie if attribute syntax is context-sensitive keyword
bool AttributeCommonInfo::IsContextSensitiveKeywordAttribute() const noexcept {
  return attr->isContextSensitiveKeywordAttribute();
}

#endif  // PASTA_IN_BOOTSTRAP

} // namespace pasta
