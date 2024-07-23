# Add the executable
add_executable(LibraryManagementSystem 
    src/main.cpp
)

# Link libraries
target_link_libraries(LibraryManagementSystem PUBLIC
    library_management_system_lib
    sqlite_lib
)

# Specify output directory for the executable
set_target_properties(LibraryManagementSystem  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/output
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_SOURCE_DIR}/output
)