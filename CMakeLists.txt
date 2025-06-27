cmake_minimum_required(VERSION 3.31)
project(webgpu_example)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_subdirectory(webgpu)
add_executable(webgpu_example main.cpp)
target_link_libraries(webgpu_example PRIVATE webgpu)
target_copy_webgpu_binaries(webgpu_example)

if (EMSCRIPTEN)
    set_target_properties(webgpu_example PROPERTIES SUFFIX ".html")
    target_link_options(webgpu_example PRIVATE -sASYNCIFY)
endif()
