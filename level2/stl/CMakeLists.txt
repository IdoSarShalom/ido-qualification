include_directories(include)

# Create main executable that includes all necessary source files
add_executable(sort_strings
        src/file_utils.cpp
        src/sort_strings.cpp
)

add_executable(count_word_freq
        src/file_utils.cpp
        src/count_word_freq.cpp
)