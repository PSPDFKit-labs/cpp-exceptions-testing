cmake_minimum_required(VERSION 3.3)

project(exceptions_benchmark)

set(CMAKE_BUILD_TYPE debug)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tpl/google-benchmark)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${benchmark_INCLUDE_DIRECTORIES})

target_link_libraries(${PROJECT_NAME}
        benchmark
        )
