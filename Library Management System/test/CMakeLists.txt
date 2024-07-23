# Add the executable for the tests
add_executable(Test 
    src/BookUnitTests.cpp
)

# Include directories
target_include_directories(Test PUBLIC
    include
)

# Link libraries
target_link_libraries(Test PUBLIC
    sqlite_lib
    library_management_system_lib
    gtest_main
    gmock_main
)