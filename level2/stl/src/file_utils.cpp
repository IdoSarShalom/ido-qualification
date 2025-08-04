#include "file_utils.hpp"

#include <iostream>
#include <sstream>
#include <vector>

// An anonymous namespace is used to limit the scope of these helper functions
// to this specific file (translation unit). This prevents potential naming
// conflicts with functions in other files.
namespace {
    /**
     * @brief Removes leading and trailing whitespace from a string.
     * @param line The string to trim.
     * @return The trimmed string.
     */
    std::string trim_whitespace(const std::string &line) {
        const auto first = line.find_first_not_of(" \t\n\r");
        if (std::string::npos == first) {
            return ""; // Return an empty string if the line is all whitespace
        }
        const auto last = line.find_last_not_of(" \t\n\r");
        return line.substr(first, (last - first + 1));
    }

    /**
     * @brief Splits a line of text into individual words based on whitespace.
     * @param line The line to split.
     * @return A vector of words.
     */
    std::vector<std::string> split_line_into_words(const std::string &line) {
        std::vector<std::string> words;
        std::istringstream iss(line);
        std::string word;

        // Use the stream extraction operator (>>) to read whitespace-separated words
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
} // end anonymous namespace

/**
 * @brief Reads all words from a file at the given path.
 * This is the implementation for the function declared in FileUtils.hpp.
 */
std::vector<std::string> read_all_words_from_file(const std::string &file_path) {
    // 1. Open the file
    std::ifstream file(file_path);

    // 2. Check if the file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << file_path << std::endl;
        return {}; // Return an empty vector to indicate failure
    }

    std::vector<std::string> all_words;
    std::string line;

    // 3. Loop through each line of the file
    while (std::getline(file, line)) {
        // 4. For each line, trim leading/trailing whitespace
        std::string trimmed_line = trim_whitespace(line);

        // 5. If the line is not empty after trimming, process it
        if (!trimmed_line.empty()) {
            // 6. Split the line into a vector of words
            std::vector<std::string> line_words = split_line_into_words(trimmed_line);

            // 7. Add the words from this line to the main vector
            all_words.insert(all_words.end(), line_words.begin(), line_words.end());
        }
    }

    // 8. Return the complete vector of words
    return all_words;
}
