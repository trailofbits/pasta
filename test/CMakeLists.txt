# Copyright (c) 2021 Trail of Bits, Inc., all rights reserved.

configure_lit_site_cfg(
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
  ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
  MAIN_CONFIG
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.cfg.py
)

set(PASTA_TEST_DEPENDS
  print-tokens
)

add_lit_testsuite(check-pasta "Running the PASTA regression tests"
  ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${PASTA_TEST_DEPENDS}
)

set_target_properties(check-pasta PROPERTIES FOLDER "Tests")

add_lit_testsuites(PASTA ${CMAKE_CURRENT_SOURCE_DIR} DEPENDS ${PASTA_TEST_DEPENDS})