cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LibraryManagementSystem)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(3rd_party)
add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(output)

# Enable testing
enable_testing()