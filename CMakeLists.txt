cmake_minimum_required(VERSION 3.3)

project(exceptions_benchmark)

set(CMAKE_CXX_STANDARD 17)
set(CORE_HOME "${CMAKE_CURRENT_SOURCE_DIR}/../../pspdfkit/PSPDFKit/core")
set(GOOGLE_BENCHMARKS "${CORE_HOME}/Vendor/google-benchmark")

add_subdirectory(${GOOGLE_BENCHMARKS} build-google-benchmark)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${GOOGLE_BENCHMARKS}/include)

target_link_libraries(${PROJECT_NAME}
        benchmark
        )
