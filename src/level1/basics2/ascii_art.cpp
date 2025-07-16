#include <iostream>
#include <string>

static constexpr auto author_name = "Ido Sar Shalom";

std::string get_ascii_art(const std::string &author) {
    return "    >> ASCII_ART    <<\n"
           " Author: " + author + "\n"
           " C++ Course Exercise\n"
           "  /_/\n"
           " ( o.o ) \n"
           " >^..^<~ \n"
           " ~~~ ~~~\n";
}

void display_art() {
    const std::string art_to_display = get_ascii_art(author_name);
    std::cout << art_to_display << std::endl;
}

int main() {
    display_art();
    return 0;
}
