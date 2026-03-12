#include "../include/InputValidator.h"
#include <iostream>
#include <string>

std::string InputValidator::ReadString() {
    std::string user_string;
    getline(std::cin >> std::ws, user_string);
    return user_string;
}

// REFERENCE: https://www.tutorialspoint.com/article/how-to-check-if-input-is-numeric-in-cplusplus
// Nishu Kumari (2025)
bool InputValidator::IsNumeric(const std::string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int InputValidator::ReadPosIntInRange(int min, int max) {
    bool is_valid{false};
    int user_num{-1};
    do {
        std::cout << "Enter a number (" << min << "-" << max << "): ";
        std::string user_num_string = this->ReadString();
        this->TrimTrailingSpacesString(user_num_string);
        if (this->IsNumeric(user_num_string)) {
            // REFERENCE: https://en.cppreference.com/w/cpp/string/basic_string/stol
            // Cppreference.com (n.d.)
            user_num = std::stoi(user_num_string);
            if (user_num < min || user_num > max) {
                std::cout << "Invalid! Number must be between " << min << " and " << max << '.' << '\n';
            }
            else {
                is_valid = true;
            }
        }
        else {
            std::cout << "Invalid! Enter a whole positive number." << '\n';
        }
    }
    while (!is_valid);
    return user_num;
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
