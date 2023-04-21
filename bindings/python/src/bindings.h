#pragma once

#include <pybind11/pybind11.h>

#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>

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

void RegisterArgumentVector(pybind11::module_&);
void RegisterCompileCommand(pybind11::module_&);
void RegisterFileSystem(pybind11::module_&);
void RegisterFileManager(pybind11::module_&);
} // namespace pasta