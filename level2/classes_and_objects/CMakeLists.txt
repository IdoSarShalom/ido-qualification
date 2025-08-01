include_directories(include)

# Create main executable that includes all necessary source files
add_executable(main
        src/main.cpp
        src/geometry_utils.cpp
        src/rectangle.cpp
        src/quad.cpp
)