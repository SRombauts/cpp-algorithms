# Copyright (c) 2013 Sébastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT)

cmake_minimum_required (VERSION 2.6)
project (CppAlgorithms)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    add_definitions (/D_CRT_SECURE_NO_WARNINGS)
else()
    add_definitions (-std=c++0x)  # -std=c++11
endif()

# add the application executable
add_executable (CppAlgorithms
 src/main.cpp
 src/hash.cpp src/hash.h
 src/random.cpp src/random.h
 src/vector.cpp src/vector.h
)

# add the subdirectory containing the CMakeLists.txt for the gtest library
add_subdirectory (googletest) 
include_directories ("${PROJECT_SOURCE_DIR}/googletest/include")

# add the test executable
add_executable (TestAlgorithms
 src/hash.cpp src/hash.h src/hash_test.cpp
 src/random.cpp src/random.h src/random_test.cpp
 src/vector.cpp src/vector.h src/vector_test.cpp
)
target_link_libraries (TestAlgorithms gtest_main)

# add a "test" target:
enable_testing()

# does the application runs
add_test (ApplicationRuns CppAlgorithms)

# does the tests pass
add_test (TestsPass TestAlgorithms)

