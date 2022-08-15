# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

cmake_minimum_required(VERSION 3.2)

function(get_compiler_paths)
  cmake_parse_arguments(CC "" "COMPILER;OUT_VAR" "ARGS" ${ARGN})

  if(NOT "x${CMAKE_OSX_SYSROOT}x" STREQUAL "xx")
    set(PREFIX_CC_ARGS -isysroot "${CMAKE_OSX_SYSROOT}")
  endif()
  
  execute_process(
      COMMAND "${CC_COMPILER}" ${PREFIX_CC_ARGS} ${CC_ARGS} -E -v /dev/null
      OUTPUT_FILE "${CC_OUT_VAR}.out"
      ERROR_FILE "${CC_OUT_VAR}.out"
      WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  )
  
  execute_process(
      COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/scripts/convert-to-embeddable-string" "${CC_OUT_VAR}.out"
      OUTPUT_VARIABLE out_data
      WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  )
  
  set("${CC_OUT_VAR}" "${out_data}" PARENT_SCOPE)
endfunction()
