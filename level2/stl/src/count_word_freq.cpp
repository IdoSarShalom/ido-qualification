#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "file_utils.hpp"

const std::string INPUT_FILE_PATH = PROJECT_SOURCE_DIR "/level2/data/edge_case.txt";

std::map<std::string, int> count_word_frequencies(const std::vector<std::string>& words) {
    std::map<std::string, int> frequencies;

    for (const auto& word : words) {
        frequencies[word]++;
    }

    return frequencies;
}

void print_word_frequencies(const std::map<std::string, int>& frequencies) {
    for (const auto&[fst, snd] : frequencies) {
        std::cout << fst << ": " << snd << std::endl;
    }
}

int main() {
    const auto words = read_all_words_from_file(INPUT_FILE_PATH);

    if (words.empty()) {
        std::cerr << "No words were read from the file. Exiting." << std::endl;
        return 1;
    }
    const auto frequencies = count_word_frequencies(words);
    print_word_frequencies(frequencies);

    return 0;
}