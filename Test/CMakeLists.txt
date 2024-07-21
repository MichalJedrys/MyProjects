cmake_minimum_required(VERSION 3.10)
project(MySQLProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the path to the MySQL Connector/C++ library
set(MySQL_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.0")

# Find the MySQL Connector/C++ package
find_package(MySQL REQUIRED)

# Add the executable
add_executable(MySQLProject main.cpp)

# Link the MySQL Connector/C++ libraries
target_include_directories(MySQLProject PRIVATE ${MySQL_INCLUDE_DIR})
target_link_libraries(MySQLProject PRIVATE ${MySQL_LIBRARIES})