#include <iostream>
#include <string>

static constexpr auto AUTHOR_NAME = "Ido Sar Shalom";

std::string getAsciiArt(const std::string &author) {
    return "    >> ASCII_ART    <<\n"
           " Author: " + author + "\n"
           " C++ Course Exercise\n"
           "  /_/\n"
           " ( o.o ) \n"
           " >^..^<~ \n"
           " ~~~ ~~~\n";
}

void displayArt() {
    const std::string artToDisplay = getAsciiArt(AUTHOR_NAME);
    std::cout << artToDisplay << std::endl;
}

int main() {
    displayArt();

    return 0;
}
