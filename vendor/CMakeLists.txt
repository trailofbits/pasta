# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

find_package(Git REQUIRED)

add_subdirectory(llvm-project)

if(PASTA_ENABLE_PY_BINDINGS)
  add_subdirectory(nanobind)
endif()
