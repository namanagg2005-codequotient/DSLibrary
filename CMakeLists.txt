cmake_minimum_required(VERSION 3.16)

project(CODEQUOTIENT LANGUAGES CXX)

# ------------------------------------
# C++ Standard
# ------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------
# Google Test
# ------------------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# ------------------------------------
# Main Executable
# ------------------------------------
add_executable(main
    main.cpp
)

target_include_directories(main PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# ------------------------------------
# DynamicArray Tests
# ------------------------------------

file(GLOB DYNAMICARRAY_TESTS
    tests/*.cpp
)

add_executable(DynamicArrayTests
    ${DYNAMICARRAY_TESTS}
)

target_include_directories(DynamicArrayTests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(DynamicArrayTests PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(DynamicArrayTests)