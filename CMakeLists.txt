# Copyright (c) 2013-2021 Sébastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT)

cmake_minimum_required(VERSION 2.6)
project (CppAlgorithms)

# Print some standard CMake variables
message(STATUS "CMAKE_SYSTEM_NAME/_VERSION      '${CMAKE_SYSTEM_NAME}' '${CMAKE_SYSTEM_VERSION}'")
message(STATUS "CMAKE_CXX_COMPILER_ID/_VERSION  '${CMAKE_CXX_COMPILER_ID}' '${CMAKE_CXX_COMPILER_VERSION}'")
if (NOT MSVC)
    message(STATUS "CMAKE_BUILD_TYPE                '${CMAKE_BUILD_TYPE}'")
endif (NOT MSVC)

# Define useful variables to handle OS/Compiler differences
if (MSVC)
    # Flags for linking with multithread static C++ runtime
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CPPLINT_ARG_OUTPUT      "--output=vs7")
    add_definitions (/D_CRT_SECURE_NO_WARNINGS /D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING)
else (MSVC)
    set(CPPLINT_ARG_OUTPUT      "--output=eclipse")
    add_definitions (-std=c++0x)  # -std=c++11
endif ()
set(CPPLINT_ARG_LINELENGTH "--linelength=120")
set(CPPLINT_ARG_VERBOSE    "--verbose=2")

# add the application executable
add_executable (CppAlgorithms
 src/main.cpp
 src/algo/hash.cpp src/algo/hash.h
 src/base/random.cpp src/base/random.h
 src/base/utils.h
 src/data/vector.h

 .travis.yml
 appveyor.yml
 build.bat
 build.sh
 LICENSE.txt
 README.md
)

# add a cpplint target to the "all" target
add_custom_target(cpplint
 ALL
 COMMAND python ${PROJECT_SOURCE_DIR}/cpplint/cpplint.py ${CPPLINT_ARG_OUTPUT} ${CPPLINT_ARG_LINELENGTH} ${CPPLINT_ARG_VERBOSE} ${PROJECT_SOURCE_DIR}/src/* ${PROJECT_SOURCE_DIR}/src/*/*
)

# add the subdirectory containing the CMakeLists.txt for the gtest library
add_subdirectory (googletest) 
include_directories ("${PROJECT_SOURCE_DIR}/googletest/include")

include_directories ("${PROJECT_SOURCE_DIR}/src")

# add the test executable
add_executable (TestAlgorithms
 src/algo/hash.cpp src/algo/hash.h src/algo/hash_test.cpp
 src/base/random.cpp src/base/random.h src/base/random_test.cpp
 src/base/utils.h
 src/data/vector.h src/data/vector_test.cpp
)
target_link_libraries (TestAlgorithms gtest_main)

# add a "test" target:
enable_testing()

# does the application runs
add_test (ApplicationRuns CppAlgorithms)

# does the tests pass
add_test (TestsPass TestAlgorithms)

