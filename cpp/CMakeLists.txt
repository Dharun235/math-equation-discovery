cmake_minimum_required(VERSION 3.15)
project(MathEquationDiscovery VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Library
add_library(equation_discovery
    src/equation_discovery.cpp
)

target_include_directories(equation_discovery PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Example executable
add_executable(basic_discovery
    examples/basic_discovery.cpp
)

target_link_libraries(basic_discovery PRIVATE equation_discovery)

# Test executable
add_executable(test_equation_discovery
    tests/test_equation_discovery.cpp
)

target_link_libraries(test_equation_discovery PRIVATE equation_discovery)

# Enable testing
enable_testing()
add_test(NAME EquationDiscoveryTests COMMAND test_equation_discovery)

# Installation rules
install(TARGETS equation_discovery
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES src/equation_discovery.h
    DESTINATION include
)

install(TARGETS basic_discovery
    RUNTIME DESTINATION bin
)
