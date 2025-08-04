#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Include the header for our shared file utility functions.
// This gives us access to read_all_words_from_file.
#include "file_utils.hpp"

// The path to the input file. This remains specific to this program.
const std::string INPUT_FILE_PATH = PROJECT_SOURCE_DIR "/level2/data/poem.txt";

/**
 * @brief Sorts a vector of strings in alphabetical order.
 * @param strings The vector of strings to sort.
 */
void sort_strings(std::vector<std::string>& strings) {
    std::sort(strings.begin(), strings.end());
}

/**
 * @brief Prints each string in a vector to the console on a new line.
 * @param strings The vector of strings to print.
 */
void print_strings(const std::vector<std::string>& strings) {
    for (const auto& str : strings) {
        std::cout << str << std::endl;
    }
}

int main() {
    // Call the single, shared function from our FileUtils module to get all the words.
    auto strings = read_all_words_from_file(INPUT_FILE_PATH);

    // It's good practice to check if the file was read successfully.
    // Our utility function returns an empty vector on failure.
    if (strings.empty()) {
        std::cerr << "File reading failed or file is empty. Exiting." << std::endl;
        return 1; // Exit with an error code
    }

    // The logic specific to this program remains the same.
    sort_strings(strings);
    print_strings(strings);

    return 0;
}
