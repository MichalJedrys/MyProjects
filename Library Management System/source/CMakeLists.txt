# Add a library to the project using the specified source files
add_library(library_management_system_lib STATIC)


# Specifies sources to use when building a target
target_sources(library_management_system_lib PRIVATE
    src/Book.cpp
    src/Menu.cpp
    src/Table.cpp
    src/SQLiteWrapper.cpp
)

# Include directories
target_include_directories(library_management_system_lib PUBLIC
    include
)

# Link SQLite3 library
target_link_libraries(library_management_system_lib  PUBLIC
    sqlite_lib
)