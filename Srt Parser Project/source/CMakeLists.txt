# Add a library to the project using the specified source files
add_library(srt_parser_lib STATIC)


# Specifies sources to use when building a target
target_sources(srt_parser_lib PRIVATE
    src/SrtBase.cpp
    src/SrtParserFakeFile.cpp
    src/SrtParserRealFile.cpp
)

# Include directories
target_include_directories(srt_parser_lib PUBLIC
    include
)