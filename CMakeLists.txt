cmake_minimum_required(VERSION 3.28)
project(ido_qualification)

set(CMAKE_CXX_STANDARD 17)

# Level 1 executables
add_executable(ascii_art level1/basics2/ascii_art.cpp)
add_executable(circles level1/basics2/circles.cpp)
add_executable(swap_integers level1/basics5/swap_integers.cpp)
add_executable(integer_dynamic_allocate level1/basics5/integer_dynamic_allocate.cpp)
add_executable(unique_pointer_array level1/basics5/unique_pointer_array.cpp)
add_executable(what_does_the_fox_say level1/closing_exercise/what_does_the_fox_say.cpp)

add_definitions(-DPROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

add_subdirectory(level2)