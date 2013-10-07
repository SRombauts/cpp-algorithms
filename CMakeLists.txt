# Copyright (c) 2013 Sébastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT)

cmake_minimum_required (VERSION 2.6)
project (CppAlgorithms)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CCPPLINT_ARGS "--output=vs7")
    add_definitions (/D_CRT_SECURE_NO_WARNINGS)
else()
    set(CCPPLINT_ARGS "--output=eclipse")
    add_definitions (-std=c++0x)  # -std=c++11
endif()

# add the application executable
add_executable (CppAlgorithms
 src/main.cpp
 src/algo/hash.cpp src/algo/hash.h
 src/base/random.cpp src/base/random.h
 src/base/utils.h
 src/data/vector.h
)

add_custom_target(cpplint
 ALL
 COMMAND python ${PROJECT_SOURCE_DIR}/cpplint.py ${CCPPLINT_ARGS} ${PROJECT_SOURCE_DIR}/src/*/* 
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

