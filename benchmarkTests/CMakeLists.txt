cmake_minimum_required(VERSION 3.3)

project(benchmarkTests)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${benchmark_INCLUDE_DIRECTORIES})

target_link_libraries(${PROJECT_NAME}
        benchmark
        )
