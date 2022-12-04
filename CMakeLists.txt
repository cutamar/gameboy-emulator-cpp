cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(GameboyEmulator)

file(GLOB SOURCES "src/*.cpp")

add_executable(GameboyEmulator ${SOURCES})

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

list(FILTER SOURCES EXCLUDE REGEX ".*main\.cpp$")

add_executable(EmulatorTest test/test_emulator.cpp ${SOURCES})

target_link_libraries(EmulatorTest
 PRIVATE
  GTest::GTest)

add_test(emulator_gtests EmulatorTest)