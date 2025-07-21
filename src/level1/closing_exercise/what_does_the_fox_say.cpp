#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>

constexpr std::string_view INPUT_FILE_PATH = "data/fox_input.txt";
constexpr std::string_view SENTINEL_PHRASE = "what does the fox say?";

std::vector<std::string> splitLineIntoWords(const std::string &line) {
    std::stringstream stream(line);
    std::string word;
    std::vector<std::string> words;
    while (stream >> word) {
        words.push_back(word);
    }
    return words;
}

std::pair<std::string, std::string> extractAnimalSound(const std::string &line) {
    std::stringstream stream(line);
    std::string goesWord, sound;
    if (std::string animal; stream >> animal >> goesWord >> sound && goesWord == "goes") {
        return {animal, sound};
    }
    return {"", ""};
}

void collectAnimalSounds(std::ifstream &inputFile, std::map<std::string, std::vector<std::string> > &animalSounds,
                         std::set<std::string> &knownSounds) {
    std::string line;
    while (std::getline(inputFile, line) && line != SENTINEL_PHRASE) {
        auto [animal, sound] = extractAnimalSound(line);
        if (!animal.empty()) {
            animalSounds[animal].push_back(sound);
            knownSounds.insert(sound);
        }
    }
}

std::vector<std::string> identifyFoxSounds(const std::vector<std::string> &recording,
                                           const std::set<std::string> &knownSounds) {
    std::vector<std::string> foxSounds;
    for (const std::string &sound: recording) {
        if (!knownSounds.count(sound)) {
            foxSounds.push_back(sound);
        }
    }
    return foxSounds;
}

void displayAnimalSounds(const std::map<std::string, std::vector<std::string> > &animalSounds) {
    for (const auto &[animal, sounds]: animalSounds) {
        std::cout << animal << ":";
        for (const auto &sound: sounds) {
            std::cout << " " << sound;
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> readInitialRecording(std::ifstream &inputFile) {
    std::string line;
    std::getline(inputFile, line);
    return splitLineIntoWords(line);
}

void processAndDisplayFoxSounds(std::ifstream &inputFile) {
    std::vector<std::string> recording = readInitialRecording(inputFile);
    std::map<std::string, std::vector<std::string> > animalSounds;
    std::set<std::string> knownSounds;
    collectAnimalSounds(inputFile, animalSounds, knownSounds);
    std::vector<std::string> foxSounds = identifyFoxSounds(recording, knownSounds);
    animalSounds["fox"] = foxSounds;
    displayAnimalSounds(animalSounds);
}

int main() {
    std::ifstream inputFile(INPUT_FILE_PATH.data());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }
    processAndDisplayFoxSounds(inputFile);
    return 0;
}
