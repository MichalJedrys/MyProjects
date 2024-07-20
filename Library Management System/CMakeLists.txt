cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LibraryManagementSystem)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the MySQL Connector/C++ directories
set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.0/include")
set(MYSQL_LIB_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.0/lib64/vs14")

# Include directories
include_directories(
    ${MYSQL_INCLUDE_DIR}
    ${MYSQL_INCLUDE_DIR}/jdbc/
    ${MYSQL_INCLUDE_DIR}/jdbc/cppconn/
    include
)

# Add the executable
add_executable(LibraryManagementSystem 
    src/main.cpp
)

# Link the MySQL libraries
target_link_libraries(LibraryManagementSystem
    "${MYSQL_LIB_DIR}/mysqlcppconn.lib"
    "${MYSQL_LIB_DIR}/mysqlcppconnx.lib"
    "${MYSQL_LIB_DIR}/libcrypto.lib"
    "${MYSQL_LIB_DIR}/libssl.lib"
)