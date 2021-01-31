# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

include(cmake/vcpkg_helper.cmake)

cmake_minimum_required(VERSION 3.14.5)
project(pasta LANGUAGES C CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/settings.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/utils.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccache.cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# --------------------------------------------
# build-time options -------------------------
# --------------------------------------------
option(ENABLE_LIBFUZZER "Build libFuzzer fuzz targets" OFF)
option(ENABLE_SANITIZERS "Build with ASAN and UBSAN" OFF)
option(WARNINGS_AS_ERRORS "Build treating warnings as errors" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------
# toolchain-specific warning options ---------
# --------------------------------------------
set(GNULIKE_COMPILER_LIST "Clang" "AppleClang" "GNU")

if(CMAKE_CXX_COMPILER_ID IN_LIST GNULIKE_COMPILER_LIST)
    set(CXX_WARNING_OPTIONS -Wall -pedantic -Wconversion -Wno-unknown-pragmas)
    set(CXX_WARNINGS_AS_ERRORS_OPTION -Werror)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CXX_WARNING_OPTIONS /W4)
    set(CXX_WARNINGS_AS_ERRORS_OPTION /WX)
else()
    set(CXX_WARNING_OPTIONS)
    set(CXX_WARNINGS_AS_ERRORS_OPTION)
    message(WARNING "Unsupported C++ compiler '${CMAKE_CXX_COMPILER_ID}'; build may not work right!")
endif()

# --------------------------------------------
# `cxx_settings` for global build options --------
# --------------------------------------------
add_library(cxx_settings INTERFACE)
target_include_directories(cxx_settings INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}/include"
)

target_compile_options(cxx_settings INTERFACE ${CXX_WARNING_OPTIONS})

if(WARNINGS_AS_ERRORS)
    target_compile_options(cxx_settings INTERFACE ${CXX_WARNINGS_AS_ERRORS_OPTION})
endif()

# --------------------------------------------
# Python dependencies ------------------------
# --------------------------------------------

find_package(PythonInterp 3.7 REQUIRED)
if("x${PYTHON_LIBRARIES}x" STREQUAL "xx")
    execute_process(
        COMMAND "${PYTHON_EXECUTABLE}" -c "import distutils.sysconfig as sysconfig; print(sysconfig.get_config_var('LIBDIR'), end='')"
        OUTPUT_VARIABLE PYTHON_LIBRARY)
    message(STATUS "Found PYTHON_LIBRARY: ${PYTHON_LIBRARY}")
endif()
if("x${PYTHON_INCLUDE_DIRS}x" STREQUAL "xx")
    execute_process(
        COMMAND "${PYTHON_EXECUTABLE}" -c "from distutils.sysconfig import get_python_inc; print(get_python_inc(), end='')"
        OUTPUT_VARIABLE PYTHON_INCLUDE_DIR)
    message(STATUS "Found PYTHON_INCLUDE_DIR: ${PYTHON_INCLUDE_DIR}")
endif()
find_package(PythonLibs 3.7 REQUIRED)

add_library(thirdparty_python INTERFACE)
target_include_directories(thirdparty_python INTERFACE
    ${PYTHON_INCLUDE_DIRS}
)

# --------------------------------------------
# Clang/LLVM dependencies --------------------
# --------------------------------------------

configure_ccache()
find_and_select_clang_compiler()
find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
add_library(thirdparty_llvm INTERFACE)

# These are out-of-order in `LLVM_AVAILABLE_LIBS` and should always be last.
set(LLVM_LIBRARIES ${LLVM_AVAILABLE_LIBS})
list(REMOVE_ITEM LLVM_LIBRARIES LLVMCore LLVMSupport)
list(REMOVE_DUPLICATES LLVM_LIBRARIES)
list(APPEND LLVM_LIBRARIES LLVMCore LLVMSupport)

target_link_libraries(thirdparty_llvm INTERFACE
    ${LLVM_LIBRARIES}
    
    clangSema
    clang
    clangFrontend
    clangDriver
    clangSerialization
    clangParse
    clangAnalysis
    clangEdit
    clangAST
    clangLex
    clangBasic
    clangTooling
    clangIndex
)

target_include_directories(thirdparty_llvm INTERFACE
    ${LLVM_INCLUDE_DIRS}
    ${CLANG_INCLUDE_DIRS}
)

# TODO(pag): Not sure if `Clang_DEFINITIONS` or `CLANG_DEFINITIONS`.
target_compile_definitions(thirdparty_llvm INTERFACE
    ${LLVM_DEFINITIONS}
    ${Clang_DEFINITIONS}
)

# LLVM uses `-lZ3` somewhere, so this is a good way to sneak it in.
find_package(Z3 CONFIG REQUIRED)
add_library(Z3 INTERFACE)
target_link_libraries(Z3 INTERFACE z3::libz3)

# --------------------------------------------
# Configure lib/Compiler/Host.h --------------
# --------------------------------------------

set(PASTA_DUMMY_SOURCE_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.x")
set(PASTA_CC_VERSION_OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.cc.version")
set(PASTA_CXX_VERSION_OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.cxx.version")

set(HOST_H_IN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/lib/Compile/Host.h.in")
set(HOST_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/lib/Compile/Host.h")

get_compiler_paths(
    COMPILER "${CMAKE_C_COMPILER}"
    OUT_VAR CSTR_HOST_CC_VERSION_INFO
    ARGS -x c -std=c18
)
get_compiler_paths(
    COMPILER "${CMAKE_C_COMPILER}"
    OUT_VAR CSTR_HOST_CC_VERSION_INFO_FAKE_SYSROOT
    ARGS -x c -std=c18 -isysroot "${CMAKE_CURRENT_BINARY_DIR}/xyz" -Wno-missing-sysroot
)

get_compiler_paths(
    COMPILER "${CMAKE_CXX_COMPILER}"
    OUT_VAR CSTR_HOST_CXX_VERSION_INFO
    ARGS -x c++ -std=c++1z
)
get_compiler_paths(
    COMPILER "${CMAKE_CXX_COMPILER}"
    OUT_VAR CSTR_HOST_CXX_VERSION_INFO_FAKE_SYSROOT
    ARGS -x c++ -std=c++1z -isysroot "${CMAKE_CURRENT_BINARY_DIR}/xyz" -Wno-missing-sysroot
)

configure_file("${HOST_H_IN_FILE}" "${HOST_H_FILE}" @ONLY)

# --------------------------------------------
# Main build targets -------------------------
# --------------------------------------------

add_library(util STATIC
  "include/pasta/Util/ArgumentVector.h"
  "include/pasta/Util/Error.h"
  "include/pasta/Util/FileSystem.h"
  "include/pasta/Util/Init.h"
  "include/pasta/Util/JSON.h"
  
  "lib/Util/ArgumentVector.cpp"
  "lib/Util/FileSystem.cpp"
  "lib/Util/Init.cpp"
)

target_link_libraries(util PRIVATE
    cxx_settings
    thirdparty_llvm
)

add_library(compiler STATIC
    "include/pasta/Compile/AST.h"
    "include/pasta/Compile/Command.h"
    "include/pasta/Compile/Compiler.h"
    "include/pasta/Compile/Job.h"
    
    "${HOST_H_FILE}"
    "lib/Compile/AST.h"
    "lib/Compile/Command.h"
    "lib/Compile/Compiler.h"
    "lib/Compile/Job.h"
    
    "lib/Compile/AST.cpp"
    "lib/Compile/Command.cpp"
    "lib/Compile/Compiler.cpp"
    "lib/Compile/Create.cpp"
    "lib/Compile/Diagnostic.cpp"
    "lib/Compile/Job.cpp"
    "lib/Compile/Run.cpp"
)

target_include_directories(compiler PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}/lib/Compile"
)

target_link_libraries(compiler PRIVATE
    cxx_settings
    thirdparty_llvm
    util
)

add_library(python_bindings STATIC
    "include/pasta/Python/Bindings.h"
    
    "lib/Python/Bindings.cpp"
    "lib/Python/Compile/AST.cpp"
    "lib/Python/Compile/Command.cpp"
    "lib/Python/Compile/Compile.h"
    "lib/Python/Compile/Compiler.cpp"
    "lib/Python/Compile/Job.cpp"
    "lib/Python/Pasta.cpp"
)

target_link_libraries(python_bindings PRIVATE
    compiler
    cxx_settings
    thirdparty_llvm
    thirdparty_python
    util
)

add_executable(bootstrap
    "lib/Bootstrap/Visitor.cpp"
    "Bootstrap.cpp"
)

target_link_libraries(bootstrap PRIVATE
    cxx_settings
    thirdparty_llvm
    compiler
)

# --------------------------------------------
# Configure setup.py.in and __init__.py.in ---
# --------------------------------------------

set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY "${CMAKE_CURRENT_BINARY_DIR}/setup.py")

set(INIT_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in")
set(INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/pasta/__init__.py")

set(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/timestamp")

get_target_tree(DEPENDENT_LIBRARIES python_bindings)
get_public_include_folders(INCLUDE_DIRS ${DEPENDENT_LIBRARIES})

# Create a list of generator expressions that will find us the absolute paths
# of all dependent libraries for setup.py to link against.
foreach(lib_target ${DEPENDENT_LIBRARIES})
  if (TARGET ${lib_target})
    get_target_property(target_type "${lib_target}" TYPE)
    if("${target_type}" STREQUAL "STATIC_LIBRARY")
      list(APPEND LIBRARY_PATHS "\$<TARGET_FILE:${lib_target}>")
    elseif("${target_type}" STREQUAL "IMPORTED_LIBRARY")
      get_target_property(target_imported_loc "${target}" IMPORTED_LOCATION)
      if(NOT "${target_imported_loc}" STREQUAL "target_imported_loc-NOTFOUND")
        list(APPEND LIBRARY_PATHS "${target_imported_loc}")
      endif()
    endif()
  endif()
endforeach()

configure_file("${SETUP_PY_IN}" "${SETUP_PY}.gen" @ONLY)
file(GENERATE OUTPUT "${SETUP_PY}" INPUT "${SETUP_PY}.gen")
configure_file("${INIT_PY_IN}" "${INIT_PY}" @ONLY)

add_custom_command(
    OUTPUT "${OUTPUT}"
    COMMAND "${PYTHON_EXECUTABLE}" "${SETUP_PY}" build --force
    COMMAND "${CMAKE_COMMAND}" -E touch "${OUTPUT}"
    COMMENT "Building Pasta Python API"
    DEPENDS python_bindings
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
  
add_custom_target(build_python_ext ALL DEPENDS "${OUTPUT}")

install(CODE "execute_process(COMMAND \"${PYTHON_EXECUTABLE}\" \"${SETUP_PY}\" install)")
