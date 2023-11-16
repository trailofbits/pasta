# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

include(CMakeDependentOption)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ standard version")

# --------------------------------------------
# build-time options -------------------------
# --------------------------------------------
option(PASTA_WARNINGS_AS_ERRORS "Build treating warnings as errors" OFF)
option(PASTA_BOOTSTRAP_MACROS "Boostrap the macro definitions" OFF)
option(PASTA_BOOTSTRAP_TYPES "Bootstrap the type definitions from the macros" OFF)
option(PASTA_BOOTSTRAP_ENABLE_ASSERTIONS "Generate assertions instead of exceptions when bootstrapping" OFF)
option(PASTA_ENABLE_TESTING "Enable testing" OFF)
cmake_dependent_option(PASTA_ENABLE_INSTALL "Set to true to enable the install target" ON "NOT PASTA_BOOTSTRAP_MACROS;NOT PASTA_BOOTSTRAP_TYPES" OFF)
option(PASTA_ENABLE_PY_BINDINGS "Enable building the Python bindings" ON)
option(PASTA_USE_VENDORED_CLANG "Set to OFF to disable default building of Clang+LLVM as a vendored library." ON)
option(PASTA_USE_VENDORED_NANOBIND "Set to OFF to disable default building of nanobind as a vendored library." ON)
option(PASTA_DISABLE_HOST_COMPILER "Set to ON to disable embedding host compiler information" OFF)