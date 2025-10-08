#include "file_utils.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

namespace {
    std::string trim_whitespace(const std::string &line) {
        const auto first = line.find_first_not_of(" \t\n\r");

        if (std::string::npos == first) {
            return "";
        }
        const auto last = line.find_last_not_of(" \t\n\r");

        return line.substr(first, (last - first + 1));
    }

    bool is_alphanumeric(const std::string &word) {
        return std::all_of(word.begin(), word.end(), ::isalnum);
    }

    bool is_all_digits(const std::string &word) {
        return std::all_of(word.begin(), word.end(), ::isdigit);
    }

    bool is_valid_word(const std::string &word) {
        if (!is_alphanumeric(word)) {
            return false;
        }

        if (is_all_digits(word)) {
            return false;
        }

        return true;
    }

    std::vector<std::string> split_line_into_words(const std::string &line) {
        std::vector<std::string> words;
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            if (is_valid_word(word)) {
                words.push_back(word);
            }
        }

        return words;
    }

    void log_file_open_error(const std::string &file_path) {
        std::cerr << "Error: Unable to open file: " << file_path << std::endl;
    }

    std::vector<std::string> process_file_lines(std::ifstream &file) {
        std::vector<std::string> all_words;
        std::string line;

        while (std::getline(file, line)) {
            std::string trimmed_line = trim_whitespace(line);

            if (!trimmed_line.empty()) {
                std::vector<std::string> line_words = split_line_into_words(trimmed_line);
                all_words.insert(all_words.end(), line_words.begin(), line_words.end());
            }
        }

        return all_words;
    }
}

std::vector<std::string> read_all_words_from_file(const std::string &file_path) {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        log_file_open_error(file_path);
        return {};
    }

    return process_file_lines(file);
}
