cmake_minimum_required(VERSION 3.16)

project(TwinWidthTests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ParserTest parser_test.cpp)

target_link_libraries(ParserTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ParserTest)
