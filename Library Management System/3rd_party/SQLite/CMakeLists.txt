# Add a library to the project using the specified source files
add_library(sqlite_lib)


# Specifies sources to use when building a target
target_sources(sqlite_lib PRIVATE
	src/sqlite3.c
)

# Include directories
target_include_directories(sqlite_lib PUBLIC
    include
)