cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(GameboyEmulator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

file(GLOB SOURCES "src/*.cpp")

add_executable(GameboyEmulator ${SOURCES})
target_link_libraries(GameboyEmulator ${SDL2_LIBRARIES})

# enable_testing()

# include(FetchContent)

# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        release-1.11.0
# )
# FetchContent_MakeAvailable(googletest)
# add_library(GTest::GTest INTERFACE IMPORTED)
# target_link_libraries(GTest::GTest INTERFACE gtest_main)

# list(FILTER SOURCES EXCLUDE REGEX ".*main\.cpp$")
# list(FILTER SOURCES EXCLUDE REGEX ".*renderer\.cpp$")

# add_executable(EmulatorTest test/test_emulator.cpp ${SOURCES})
# target_link_libraries(EmulatorTest PRIVATE GTest::GTest ${SDL2_LIBRARIES})

# add_test(emulator_gtests EmulatorTest)