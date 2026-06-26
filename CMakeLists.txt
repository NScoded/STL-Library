cmake_minimum_required(VERSION 3.10)

project(STL_Library VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable
add_executable(STL_Library
    main.cpp
)

# Header search path
target_include_directories(STL_Library PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)