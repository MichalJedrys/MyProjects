# Add a library to the project using the specified source files
add_library(vending_machine_lib STATIC)


# Specifies sources to use when building a target
target_sources(vending_machine_lib PRIVATE
    src/Controller.cpp
    src/Display.cpp
    src/Feeder.cpp
    src/VendingMachine.cpp
)

# Include directories
target_include_directories(vending_machine_lib PUBLIC
    include
)