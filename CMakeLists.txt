cmake_minimum_required(VERSION 3.28)
project(ido_qualification)

set(CMAKE_CXX_STANDARD 17)

add_executable(ascii_art src/level1/basics2/ascii_art.cpp)
add_executable(circles src/level1/basics2/circles.cpp)
add_executable(swap_integers src/level1/basics5/swap_integers.cpp)
add_executable(integer_dynamic_allocate src/level1/basics5/integer_dynamic_allocate.cpp)
add_executable(unique_pointer_array src/level1/basics5/unique_pointer_array.cpp)