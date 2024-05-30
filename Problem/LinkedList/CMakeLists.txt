# cmake_minimum_required(VERSION 3.10)
# project(LinkedListTests)

# # Set C++ standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Add the main executable
# add_executable(LinkedListTests main.cpp SimpleList.h SimpleList.cpp)

# # Add Google Test
# find_package(GTest CONFIG REQUIRED)
# target_link_libraries(LinkedListTests PRIVATE GTest::gtest GTest::gtest_main)

cmake_minimum_required(VERSION 3.10)
project(LinkedListTests)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the main executable
add_executable(LinkedListTests main.cpp SimpleList.h)

# Link GoogleTest to your test executable
target_link_libraries(LinkedListTests gtest_main)

include(GoogleTest)
gtest_discover_tests(LinkedListTests)
