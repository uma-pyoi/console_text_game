#include "../include/InputValidator.h"

#include <filesystem>
#include <iostream>

std::string InputValidator::ReadString() {
    std::string user_string;
    getline(std::cin >> std::ws, user_string);
    return user_string;
}

void InputValidator::TrimTrailingSpacesString(std::string &s) {
    // REFERENCE: https://youtu.be/3ME0l0trRsE?si=U-r89ws4KzKOiyLt
    // Portfolio Courses (2021)
    int end_i = s.length() - 1;
    bool found_non_space_char{false};

    while (end_i >= 0 && !found_non_space_char) {
        if (s[end_i] == ' ' || s[end_i] == '\n' || s[end_i] == '\t') {
            end_i--;
        }
        else {
            found_non_space_char = true;
        }
    }
    s = s.substr(0, end_i + 1);
}
