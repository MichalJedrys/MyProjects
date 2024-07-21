cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LibraryManagementSystem)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the path to the SQLite source files
set(SQLITE_SRC_DIR "C:/SQLite/")

# Include directories
include_directories(
    ${SQLITE_SRC_DIR}
    include
)

# SQLite source files
set(SQLITE_SOURCES
    ${SQLITE_SRC_DIR}/sqlite3.c
)

# Add the executable
add_executable(LibraryManagementSystem 
    src/main.cpp
    src/Book.cpp
    src/Menu.cpp
    src/Table.cpp
    ${SQLITE_SOURCES}
)

# Link SQLite3 library
target_link_libraries(LibraryManagementSystem
    ${SQLITE_SRC_DIR}/sqlite3.dll
)

# Specify output directory for the executable
set_target_properties(LibraryManagementSystem  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/debug
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/debug
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/debug
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_SOURCE_DIR}/debug
)