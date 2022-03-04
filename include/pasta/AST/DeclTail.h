/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

namespace std {
template <>
struct hash<::pasta::Decl> {
 public:
  using Hasher = std::hash<const clang::Decl *>;
  static constexpr Hasher kHasher{};

  inline Hasher::result_type operator()(
      const ::pasta::Decl &decl) const noexcept {
    return kHasher(decl.RawDecl());
  }
};
#ifdef PASTA_FOR_EACH_DECL_IMPL
#define PASTA_DEFINE_DECL_HASH(name) \
    template <> \
    struct hash<::pasta::name ## Decl> : public hash<::pasta::Decl> {};

PASTA_FOR_EACH_DECL_IMPL(PASTA_DEFINE_DECL_HASH, PASTA_IGNORE_ABSTRACT)
#undef PASTA_DEFINE_DECL_HASH
#endif

}  // namespace std
