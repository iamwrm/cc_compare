IF(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(NO_OUTPUT_DIRS)
ENDIF()

set(BENCHMARK_FOLDER "${CMAKE_SOURCE_DIR}/benchmark")

find_library(BENCHMARK_LIBRARY 
NAMES benchmark 
PATHS "${BENCHMARK_FOLDER}/build/src" 
REQUIRED
)