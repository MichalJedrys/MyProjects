include(GoogleTest)
include(CTest)

# Add the executable for the tests
add_executable(unit_tests
    src/UnitTests.cpp
)

# Include directories
target_include_directories(unit_tests PUBLIC
    include
)

# Link libraries
target_link_libraries(unit_tests PUBLIC
    srt_parser_lib
    gtest_main
    gmock_main
)

gtest_discover_tests(unit_tests XML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/test_results/unit_tests)