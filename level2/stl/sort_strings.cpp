#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

const std::string INPUT_FILE_PATH = PROJECT_SOURCE_DIR "/level2/data/poem.txt";

std::string trim_whitespace(const std::string& line) {
    const auto first = line.find_first_not_of(" \t\n\r");
    const auto last = line.find_last_not_of(" \t\n\r");

    return (first == std::string::npos) ? "" : line.substr(first, last - first + 1);
}

bool check_file_opened(const std::ifstream& file) {
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << INPUT_FILE_PATH << std::endl;
        return false;
    }

    return true;
}

std::vector<std::string> split_line_into_words(const std::string& line) {
    std::vector<std::string> words;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

std::vector<std::string> read_words_from_file(std::ifstream& file) {
    std::vector<std::string> words;
    std::string line;

    while (std::getline(file, line)) {
        std::string trimmed_line = trim_whitespace(line);

        if (!trimmed_line.empty()) {
            std::vector<std::string> line_words = split_line_into_words(trimmed_line);
            words.insert(words.end(), line_words.begin(), line_words.end());
        }
    }

    return words;
}

std::vector<std::string> read_strings_from_file() {
    std::ifstream file(INPUT_FILE_PATH);

    if (!check_file_opened(file)) {
        return {};
    }

    return read_words_from_file(file);
}

void sort_strings(std::vector<std::string>& strings) {
    std::sort(strings.begin(), strings.end());
}

void print_strings(const std::vector<std::string>& strings) {
    for (const auto& string : strings) {
        std::cout << string << std::endl;
    }
}

int main() {
    auto strings = read_strings_from_file();
    sort_strings(strings);
    print_strings(strings);
    return 0;
}
