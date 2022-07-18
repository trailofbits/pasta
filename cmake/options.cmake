# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

# --------------------------------------------
# build-time options -------------------------
# --------------------------------------------
option(PASTA_WARNINGS_AS_ERRORS "Build treating warnings as errors" OFF)
option(PASTA_BOOTSTRAP_MACROS "Boostrap the macro definitions" OFF)
option(PASTA_BOOTSTRAP_TYPES "Bootstrap the type definitions from the macros" OFF)
option(PASTA_ENABLE_TESTING "Enable testing" OFF)
cmake_dependent_option(PASTA_ENABLE_INSTALL "Set to true to enable the install target" ON "NOT PASTA_BOOTSTRAP_MACROS;NOT PASTA_BOOTSTRAP_TYPES" OFF)
