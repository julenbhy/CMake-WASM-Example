cmake_minimum_required(VERSION 3.10)

# Must be defined previous to project.
set(WASI_SDK_PREFIX "/opt/wasi-sdk")
set(CMAKE_TOOLCHAIN_FILE "${WASI_SDK_PREFIX}/share/cmake/wasi-sdk-pthread.cmake") # Remove "-pthread if not using threads

project(CMake_WASM_Project)

set(SOURCE_FILE "main_threads")

# Only needed if using threads
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,--import-memory,--export-memory,--max-memory=4294901760") # Remove if not using threads


add_executable(${SOURCE_FILE}.wasm src/${SOURCE_FILE}.c)


