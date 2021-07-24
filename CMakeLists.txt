# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

cmake_minimum_required(VERSION 3.14.5)

# Takes care of some vcpkg automation so that we can use VCPKG_ROOT
include(cmake/vcpkg_helper.cmake)

project(pasta LANGUAGES C CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/settings.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/utils.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccache.cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# --------------------------------------------
# build-time options -------------------------
# --------------------------------------------
option(PASTA_WARNINGS_AS_ERRORS "Build treating warnings as errors" OFF)
option(PASTA_BOOTSTRAP_MACROS "Boostrap the macro definitions" OFF)
option(PASTA_BOOTSTRAP_TYPES "Bootstrap the type definitions from the macros" OFF)
option(PASTA_PYTHON_BINDINGS "Build Python bindings" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

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

# --------------------------------------------------
# `pasta_cxx_settings` for global build options ----
# --------------------------------------------------
add_library(pasta_cxx_settings INTERFACE)
target_include_directories(pasta_cxx_settings INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}/include"
)

target_compile_options(pasta_cxx_settings INTERFACE ${CXX_WARNING_OPTIONS})

if(PASTA_WARNINGS_AS_ERRORS)
    target_compile_options(pasta_cxx_settings INTERFACE ${CXX_WARNINGS_AS_ERRORS_OPTION})
endif()

if(PASTA_BOOTSTRAP_MACROS OR PASTA_BOOTSTRAP_TYPES)
    target_compile_definitions(pasta_cxx_settings INTERFACE -DPASTA_IN_BOOTSTRAP)
endif()

find_package(Filesystem REQUIRED COMPONENTS Final Experimental)
if(Filesystem_FOUND)
    message(STATUS "Found filesystem: ${CXX_FILESYSTEM_HEADER}")
endif()
target_link_libraries(pasta_cxx_settings INTERFACE std::filesystem)

# --------------------------------------------
# Python dependencies ------------------------
# --------------------------------------------

if(PASTA_PYTHON_BINDINGS)
    find_package(PythonInterp 3.8 REQUIRED)
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
    find_package(PythonLibs 3.8 REQUIRED)
    
    add_library(pasta_thirdparty_python INTERFACE)
    target_include_directories(pasta_thirdparty_python INTERFACE
        ${PYTHON_INCLUDE_DIRS}
    )
endif(PASTA_PYTHON_BINDINGS)

# --------------------------------------------
# Clang/LLVM dependencies --------------------
# --------------------------------------------

find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
add_library(pasta_thirdparty_llvm INTERFACE)

# These are out-of-order in `LLVM_AVAILABLE_LIBS` and should always be last.
set(LLVM_LIBRARIES ${LLVM_AVAILABLE_LIBS})
list(REMOVE_ITEM LLVM_LIBRARIES LLVMCore LLVMSupport)
list(REMOVE_DUPLICATES LLVM_LIBRARIES)
list(APPEND LLVM_LIBRARIES LLVMCore LLVMSupport)

target_link_libraries(pasta_thirdparty_llvm INTERFACE
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

target_include_directories(pasta_thirdparty_llvm INTERFACE
    ${LLVM_INCLUDE_DIRS}
    ${CLANG_INCLUDE_DIRS}
)

# TODO(pag): Not sure if `Clang_DEFINITIONS` or `CLANG_DEFINITIONS`.
target_compile_definitions(pasta_thirdparty_llvm INTERFACE
    ${LLVM_DEFINITIONS}
    ${Clang_DEFINITIONS}
)

# LLVM uses `-lZ3` somewhere, so this is a good way to sneak it in.
# NOTE: Recent versions of cxx-common vcpkg llvm dependencies fix this
if(NOT Z3_FOUND)
    find_package(Z3 CONFIG REQUIRED)
    if (NOT TARGET Z3)
        add_library(Z3 INTERFACE)
    endif()
    target_link_libraries(Z3 INTERFACE z3::libz3)
endif()

# --------------------------------------------
# Configure lib/Compiler/Host.h --------------
# --------------------------------------------

set(PASTA_DUMMY_SOURCE_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.x")
set(PASTA_CC_VERSION_OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.cc.version")
set(PASTA_CXX_VERSION_OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.cxx.version")

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
  if("x${CMAKE_C_SIMULATE_ID}" STREQUAL "xMSVC")
    set(PASTA_C_COMPILER_ID 3)  # clang-cl
  elseif(CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
    set(PASTA_C_COMPILER_ID 2)  # Apple's Clang
  else()
    set(PASTA_C_COMPILER_ID 1)  # LLVM Clang.
  endif()
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
  set(PASTA_C_COMPILER_ID 4)  # cl
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
  set(PASTA_C_COMPILER_ID 5)  # g++
else()
  set(PASTA_C_COMPILER_ID 0)  # Unknown.
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if("x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
    set(PASTA_CXX_COMPILER_ID 3)  # clang-cl
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(PASTA_CXX_COMPILER_ID 2)  # Apple's Clang
  else()
    set(PASTA_CXX_COMPILER_ID 1)  # LLVM Clang.
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(PASTA_CXX_COMPILER_ID 4)  # cl
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(PASTA_CXX_COMPILER_ID 5)  # g++
else()
  set(PASTA_CXX_COMPILER_ID 0)  # Unknown.
endif()

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
    ARGS -x c -std=c18 -isysroot "${CMAKE_CURRENT_BINARY_DIR}/xyz/" -Wno-missing-sysroot
)

get_compiler_paths(
    COMPILER "${CMAKE_CXX_COMPILER}"
    OUT_VAR CSTR_HOST_CXX_VERSION_INFO
    ARGS -x c++ -std=c++17
)
get_compiler_paths(
    COMPILER "${CMAKE_CXX_COMPILER}"
    OUT_VAR CSTR_HOST_CXX_VERSION_INFO_FAKE_SYSROOT
    ARGS -x c++ -std=c++17 -isysroot "${CMAKE_CURRENT_BINARY_DIR}/xyz" -Wno-missing-sysroot
)

configure_file("${HOST_H_IN_FILE}" "${HOST_H_FILE}" @ONLY)

# --------------------------------------------
# Main build targets -------------------------
# --------------------------------------------

add_library(pasta_util STATIC
    "include/pasta/Util/ArgumentVector.h"
    "include/pasta/Util/Compiler.h"
    "include/pasta/Util/FileSystem.h"
    "include/pasta/Util/Init.h"
    "include/pasta/Util/Result.h"
    
    "lib/Util/ArgumentVector.cpp"
    "lib/Util/FileSystem.cpp"
    "lib/Util/Init.cpp"
)

target_link_libraries(pasta_util PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
)

add_library(pasta_compiler STATIC

    "include/pasta/AST/AST.h"
    "include/pasta/AST/Decl.h"
    "include/pasta/AST/DeclBootstrap.h"
    "include/pasta/AST/Forward.h"
    "include/pasta/AST/Token.h"
    "include/pasta/Compile/Command.h"
    "include/pasta/Compile/Compiler.h"
    "include/pasta/Compile/Job.h"

    "lib/AST/AST.cpp"
    "lib/AST/Decl.cpp"
    "lib/AST/DeclBootstrap.cpp"
    "lib/AST/Token.cpp"
    
    "${HOST_H_FILE}"
    "lib/Compile/Command.h"
    "lib/Compile/Compiler.h"
    "lib/Compile/Job.h"
    
    "lib/Compile/Version.h"
    
    "lib/Compile/Command.cpp"
    "lib/Compile/Compiler.cpp"
    "lib/Compile/Create.cpp"
    "lib/Compile/Diagnostic.cpp"
    "lib/Compile/Job.cpp"
    "lib/Compile/Run.cpp"
)

target_include_directories(pasta_compiler PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}/lib/Compile"
)

target_link_libraries(pasta_compiler PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_util
)

if(PASTA_PYTHON_BINDINGS)
    add_library(pasta_python_bindings STATIC
        "include/pasta/Python/Bindings.h"
    
        "lib/Python/Bindings.cpp"
        
        "lib/Python/AST/AST.cpp"
        "lib/Python/AST/SourceLocation.cpp"
        "lib/Python/AST/Token.cpp"
        
        "lib/Python/Compile/Command.cpp"
        "lib/Python/Compile/Compile.h"
        "lib/Python/Compile/Compiler.cpp"
        "lib/Python/Compile/Job.cpp"
        "lib/Python/Pasta.cpp"
    )
    
    target_link_libraries(pasta_python_bindings PRIVATE
        pasta_compiler
        pasta_cxx_settings
        pasta_thirdparty_llvm
        pasta_thirdparty_python
        pasta_util
    )
endif(PASTA_PYTHON_BINDINGS)

# ---------------------------------------------------
# Configure bootstrap header files with source paths.
# ---------------------------------------------------

if(PASTA_BOOTSTRAP_MACROS OR PASTA_BOOTSTRAP_TYPES)
    
    set(PASTA_INCLUDE_SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
    set(PASTA_BINARY_PATH "${CMAKE_CURRENT_BINARY_DIR}")
    set(PASTA_VCPKG_INCLUDE_PATH "${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/include")
    set(PASTA_BIN_BOOTSTRAP_MACROS_MACRO_GENERATOR_CPP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/BootstrapMacros/MacroGenerator.cpp")
    set(PASTA_BIN_BOOTSTRAP_TYPES_GENERATED_H_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/BootstrapTypes/Generated.h")
    set(PASTA_INCLUDE_AST_FORWARD_H_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/pasta/AST/Forward.h")
    set(PASTA_INCLUDE_AST_DECL_H_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/pasta/AST/Decl.h")
    set(PASTA_SRC_AST_DECL_CPP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/AST/Decl.cpp")
    set(PASTA_INCLUDE_AST_TYPE_H_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/pasta/AST/Type.h")
    set(PASTA_SRC_AST_TYPE_CPP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/AST/Type.cpp")
    set(PASTA_INCLUDE_AST_TYPE_H_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/pasta/AST/Stmt.h")
    set(PASTA_SRC_AST_TYPE_CPP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/AST/Stmt.cpp")
    
    set(BOOTSTRAP_CONFIG_H_IN "${CMAKE_CURRENT_SOURCE_DIR}/BootstrapConfig.h.in")
    set(BOOTSTRAP_CONFIG_H "${CMAKE_CURRENT_BINARY_DIR}/BootstrapConfig.h")
    configure_file("${BOOTSTRAP_CONFIG_H_IN}" "${BOOTSTRAP_CONFIG_H}" @ONLY)
    
    # --------------------------------------------
    # Bootstrap build targets --------------------
    # --------------------------------------------
    
    add_library(pasta_bootstrap_config INTERFACE)
    add_dependencies(pasta_bootstrap_config "${BOOTSTRAP_CONFIG_H}")
    target_include_directories(pasta_bootstrap_config INTERFACE
        "${CMAKE_CURRENT_BINARY_DIR}"
    )

endif()


# --------------------------------------------
# Configure setup.py.in and __init__.py.in ---
# --------------------------------------------

if(PASTA_PYTHON_BINDINGS)
    
    set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
    set(SETUP_PY "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
    
    set(INIT_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in")
    set(INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/pasta/__init__.py")
    
    set(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/timestamp")
    
    get_target_tree(DEPENDENT_LIBRARIES pasta_python_bindings)
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
    
    # Determine if we need to link anything to access the C++ filesystem API
    get_property(CXX_FILESYSTEM_LIBS
                 TARGET std::filesystem
                 PROPERTY INTERFACE_LINK_LIBRARIES)
    
    configure_file("${SETUP_PY_IN}" "${SETUP_PY}.gen" @ONLY)
    file(GENERATE OUTPUT "${SETUP_PY}" INPUT "${SETUP_PY}.gen")
    configure_file("${INIT_PY_IN}" "${INIT_PY}" @ONLY)
    
    add_custom_command(
        OUTPUT "${OUTPUT}"
        COMMAND "${PYTHON_EXECUTABLE}" "${SETUP_PY}" build --force
        COMMAND "${CMAKE_COMMAND}" -E touch "${OUTPUT}"
        COMMENT "Building Pasta Python API"
        DEPENDS pasta_python_bindings pasta_compiler
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )
    
    add_custom_target(pasta_build_python_ext ALL DEPENDS "${OUTPUT}")
    
    install(CODE "execute_process(COMMAND \"${PYTHON_EXECUTABLE}\" \"${SETUP_PY}\" install --force)")
endif(PASTA_PYTHON_BINDINGS)

add_subdirectory(bin)

