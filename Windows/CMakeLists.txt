# CMake version check
cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(otlsearch VERSION 1.0 LANGUAGES CXX)

# the name of the target operating system
set(CMAKE_SYSTEM_NAME Windows)

# specify the C++ compiler and standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# which compilers to use for C and C++
set(CMAKE_C_COMPILER "/usr/bin/x86_64-w64-mingw32-gcc-posix")
set(CMAKE_CXX_COMPILER "/usr/bin/x86_64-w64-mingw32-g++-posix")
set(CMAKE_BUILD_TYPE Release)

# set source files list
set(source_files ../src/main.cpp ../src/search.cpp ../src/links.cpp)

# Conan settingns
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${CMAKE_PROJECT_NAME} "${source_files}")

target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS})

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC "../inc"                          
)
