cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(rt)

option(BUILD_MAIN "Build main.cpp" OFF)
option(BUILD_TESTS "Build tests" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sources)

add_library(rest STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/res_h.cpp)

if (BUILD_MAIN)
    add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/sources/res.cpp)
    target_link_libraries(main rest)
    install(TARGETS main RUNTIME DESTINATION bin)
endif()

if (BUILD_TESTS)
    add_subdirectory(third-party/gtest)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
    file(GLOB ACCOUNT_TEST_SOURCES tests/*.cpp)
    add_executable(check ${ACCOUNT_TEST_SOURCES})
    target_link_libraries(check gtest_main gtest gmock rest)
    add_test(NAME check COMMAND check)
endif()
