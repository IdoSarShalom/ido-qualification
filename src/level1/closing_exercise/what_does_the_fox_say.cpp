#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>

const std::string INPUT_FILE_PATH = "data/fox_input.txt";
const std::string END_PHRASE = "what does the fox say?";
const std::string GOES = "goes";
const std::string FOX_ANIMAL = "fox";

std::vector<std::string> split_recording_into_sounds(const std::string &line) {
    std::stringstream stream(line);
    std::string word;
    std::vector<std::string> words;

    while (stream >> word) {
        words.push_back(word);
    }

    return words;
}

std::pair<std::string, std::string> extract_animal_sound(const std::string &line) {
    std::stringstream stream(line);

    if (std::string animal, goes, sound; stream >> animal >> goes >> sound && goes == GOES) {
        return {animal, sound};
    }

    return {"", ""};
}

void collect_animal_sounds(std::ifstream &input_file, std::map<std::string, std::vector<std::string> > &animal_sounds,
                           std::set<std::string> &known_sounds) {
    std::string line;

    while (std::getline(input_file, line) && line != END_PHRASE) {
        auto [animal, sound] = extract_animal_sound(line);
        animal_sounds[animal].push_back(sound);
        known_sounds.insert(sound);
    }
}

void identify_fox_sounds(const std::vector<std::string> &sounds,
                         const std::set<std::string> &known_sounds,
                         std::vector<std::string> &fox_sounds) {
    for (const std::string &sound: sounds) {
        if (!known_sounds.count(sound)) {
            fox_sounds.push_back(sound);
        }
    }
}

void display_animal_sounds(const std::map<std::string, std::vector<std::string> > &animal_sounds) {
    for (const auto &[animal, sounds]: animal_sounds) {
        std::cout << animal << ":";

        for (const auto &sound: sounds) {
            std::cout << " " << sound;
        }
        std::cout << std::endl;
    }
}

std::string get_recording(std::ifstream &input_file) {
    std::string line;
    std::getline(input_file, line);

    return line;
}

std::map<std::string, std::vector<std::string> > process_animal_sounds(std::ifstream &input_file) {
    const auto recording = get_recording(input_file);
    const auto sounds = split_recording_into_sounds(recording);
    std::map<std::string, std::vector<std::string> > animal_sounds;
    std::set<std::string> known_sounds;
    collect_animal_sounds(input_file, animal_sounds, known_sounds);
    std::vector<std::string> fox_sounds;
    identify_fox_sounds(sounds, known_sounds, fox_sounds);
    animal_sounds[FOX_ANIMAL] = fox_sounds;

    return animal_sounds;
}

void display_fox_sounds(const std::map<std::string, std::vector<std::string> > &animal_sounds) {
    display_animal_sounds(animal_sounds);
}

int main() {
    std::ifstream input_file(INPUT_FILE_PATH);
    const auto animal_sounds = process_animal_sounds(input_file);
    display_fox_sounds(animal_sounds);

    return 0;
}
