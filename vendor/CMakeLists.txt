#
# Copyright (c) 2023, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

find_package(Git REQUIRED)

if(PASTA_ENABLE_INSTALL)
  set(PASTA_VENDOR_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}")
else()
  set(PASTA_VENDOR_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/install")
  execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${PASTA_VENDOR_INSTALL_DIR}")
endif()

add_subdirectory(llvm-project)

if(PASTA_ENABLE_PY_BINDINGS)
  add_subdirectory(nanobind)
endif()
