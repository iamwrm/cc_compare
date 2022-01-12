cmake_minimum_required(VERSION 3.15)
project(expression_template_benchmark)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "-O3 -march=native ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

include(cmake/support_libs.cmake)

# file(GLOB srcs src/main.cpp)


add_executable(bench
src/bench.cpp
)
target_include_directories(bench
BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
)
target_link_libraries(bench
${BENCHMARK_LIBRARY}
pthread
)


add_executable(main
src/main.cpp
)

target_link_libraries(main
)