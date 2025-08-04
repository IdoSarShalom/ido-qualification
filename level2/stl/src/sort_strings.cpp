#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "file_utils.hpp"

const std::string INPUT_FILE_PATH = PROJECT_SOURCE_DIR "/level2/data/poem.txt";

void sort_strings(std::vector<std::string>& strings) {
    std::sort(strings.begin(), strings.end());
}

void print_strings(const std::vector<std::string>& strings) {
    for (const auto& str : strings) {
        std::cout << str << std::endl;
    }
}

int main() {
    auto strings = read_all_words_from_file(INPUT_FILE_PATH);

    if (strings.empty()) {
        std::cerr << "File reading failed or file is empty. Exiting." << std::endl;
        return 1;
    }
    sort_strings(strings);
    print_strings(strings);

    return 0;
}