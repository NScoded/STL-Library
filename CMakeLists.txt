cmake_minimum_required(VERSION 3.10)

project(STL_Library VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main executable
add_executable(STL_Library
    main.cpp
)

target_include_directories(STL_Library PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# GoogleTest
enable_testing()

set(GTEST_ROOT $ENV{GTEST_ROOT})

if(NOT EXISTS "${GTEST_ROOT}/CMakeLists.txt")
    message(FATAL_ERROR "GoogleTest not found. Please set GTEST_ROOT correctly.")
endif()

add_subdirectory(${GTEST_ROOT} googletest-build)

# Tests
add_executable(Tests
    tests/main.cpp
    tests/DynamicArray/RemoveTests.cpp
    tests/DynamicArray/InsertTests.cpp
    tests/DynamicArray/PushBackTests.cpp
    tests/DynamicArray/PopBackTests.cpp
    tests/DynamicArray/SizeTests.cpp
    tests/DynamicArray/CapacityTests.cpp
    tests/DynamicArray/ClearTests.cpp
    
    
    tests/LinkedList/InsertHeadTests.cpp
    tests/LinkedList/AssignmentOperatorTests.cpp
    tests/LinkedList/EqualityOperatorTests.cpp
    tests/LinkedList/RemoveTests.cpp
    tests/LinkedList/InsertTests.cpp
    tests/LinkedList/AppendTests.cpp
    tests/LinkedList/PopTests.cpp
    tests/LinkedList/ReverseTests.cpp
    tests/LinkedList/LengthTests.cpp
    tests/LinkedList/ExistsTests.cpp


    tests/HashMap/ConstructorTests.cpp
    tests/HashMap/InsertTests.cpp
    tests/HashMap/RemoveTests.cpp
    tests/HashMap/ExistsTests.cpp
    tests/HashMap/LoadFactorTests.cpp
    tests/HashMap/ClearTests.cpp
    tests/HashMap/RehashTests.cpp
    tests/HashMap/CapacityTests.cpp
    tests/HashMap/SizeTests.cpp
    tests/HashMap/GetTests.cpp
    
)

target_include_directories(Tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Tests PRIVATE
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)