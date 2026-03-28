cmake_minimum_required(VERSION 3.10)
project(XRayBinarySolver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/StarSystem.cpp
    src/XRayAnalyzer.cpp
    src/OrbitalMechanics.cpp
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Compiler options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -O3)
endif()