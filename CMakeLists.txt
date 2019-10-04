cmake_minimum_required(VERSION 3.3)

project(exceptionsTesting)

set(CMAKE_BUILD_TYPE debug)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tpl/google-benchmark)
add_subdirectory(benchmarkTests)
add_subdirectory(binarySizeTests)

