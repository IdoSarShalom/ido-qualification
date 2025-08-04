#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

// Define the path to the input file.
// This should be adjusted to the correct path in your project environment.
const std::string INPUT_FILE_PATH = PROJECT_SOURCE_DIR "/level2/data/poem.txt";

// Include the header for the file utility functions.
// This is the correct way to use functions from a library.
#include "file_utils.hpp"


/**
 * @brief Counts the frequency of each word in a vector of strings.
 * @param words The vector of words to process.
 * @return A map where keys are words and values are their frequencies.
 */
std::map<std::string, int> count_word_frequencies(const std::vector<std::string>& words) {
    std::map<std::string, int> frequencies;
    for (const auto& word : words) {
        // If the word is already a key in the map, its count is incremented.
        // If not, it's added to the map with a count of 1.
        frequencies[word]++;
    }
    return frequencies;
}

/**
 * @brief Prints the word frequencies from a map to the console.
 * @param frequencies A map containing the words and their counts.
 */
void print_word_frequencies(const std::map<std::string, int>& frequencies) {
    // A std::map stores its keys in sorted order, so the output will be alphabetical.
    for (const auto& pair : frequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    // Read all words from the specified file using the external utility function.
    // The previous custom file reading functions are no longer needed.
    const auto words = read_all_words_from_file(INPUT_FILE_PATH);

    // Check if the word vector is empty, which would indicate a file reading error.
    if (words.empty()) {
        std::cerr << "No words were read from the file. Exiting." << std::endl;
        return 1; // Return a non-zero status code to indicate an error.
    }

    // Count the frequency of each word.
    auto frequencies = count_word_frequencies(words);

    // Print the results to the console.
    print_word_frequencies(frequencies);

    return 0;
}