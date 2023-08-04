#pragma once

#include <nanobind/nanobind.h>

#include <nanobind/stl/filesystem.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include "Result.h"

namespace pasta {
namespace detail {
template <typename... Args>
struct overload_cast_const_impl {
  template <typename Return, typename Class>
  constexpr auto operator()(Return (Class::*pmf)(Args...) const, std::false_type = {}) const noexcept
      -> decltype(pmf) {
      return pmf;
  }
};
} // namespace detail

template <typename... Args>
static constexpr detail::overload_cast_const_impl<Args...> overload_cast_const{};

void RegisterArgumentVector(nanobind::module_&);
void RegisterCompileCommand(nanobind::module_&);
void RegisterFileSystem(nanobind::module_&);
void RegisterFileManager(nanobind::module_&);
void RegisterCompileJob(nanobind::module_&);
void RegisterCompiler(nanobind::module_&);
void RegisterAST(nanobind::module_&);
} // namespace pasta
