#include "../include/InputValidator.h"
#include <iostream>
#include <regex>
#include <string>

std::string InputValidator::ReadString() {
    std::string user_string;
    getline(std::cin >> std::ws, user_string);
    return user_string;
}

// REFERENCE: https://www.tutorialspoint.com/article/how-to-check-if-input-is-numeric-in-cplusplus
// Nishu Kumari (2025)
bool InputValidator::IsNumeric(const std::string &str) {
    bool is_numeric{true};
    for (char ch: str) {
        if (!isdigit(ch)) {
            is_numeric = false;
        }
    }
    return is_numeric;
}

int InputValidator::ReadPosIntInRange(int min, int max) {
    bool is_valid{false};
    int user_num{-1};
    do {
        utils_.OutputNumInRangePrompt(min, max);
        std::string user_num_string = this->ReadString();
        this->TrimTrailingSpacesString(user_num_string);
        if (this->IsNumeric(user_num_string)) {
            // REFERENCE: https://en.cppreference.com/w/cpp/string/basic_string/stol
            // Cppreference.com (n.d.)
            user_num = std::stoi(user_num_string);
            if (user_num < min || user_num > max) {
                std::cout << "Invalid! Number must be between " << min << " and " << max << '.' << '\n';
            } else {
                is_valid = true;
            }
        } else {
            std::cout << "Invalid! Enter a whole positive number." << '\n';
        }
    } while (!is_valid);
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
        } else {
            found_non_space_char = true;
        }
    }
    s = s.substr(0, end_i + 1);
}

// returns char 'n' | 'p'
char InputValidator::ReadStoryModeChar() {
    bool is_valid{false};
    std::string user_string;
    char user_char{'0'}; // 0 here is for initialisation, meaningless
    do {
        utils_.OutputStoryModePrompt();
        user_string = this->ReadString();
        this->TrimTrailingSpacesString(user_string);
        if (user_string.length() == 1) {
            user_char = std::tolower(user_string[0]);
            if (user_char == 'n' || user_char == 'p') {
                is_valid = true;
            } else {
                std::cout << "Invalid! You must enter 'n' or 'p'!" << '\n';
            }
        } else {
            std::cout << "Invalid! You must enter one letter!" << '\n';
        }
    } while (!is_valid);
    return user_char;
}

bool InputValidator::ReadYesNo() {
    bool user_choice{false}; // false here is for initialisation
    bool is_valid{false};
    std::string user_string;
    do {
        utils_.OutputYesNoPrompt();
        user_string = this->ReadString();
        this->TrimTrailingSpacesString(user_string);
        StringToLower(user_string);
        if (user_string == "y" || user_string == "yes") {
            user_choice = true;
            is_valid = true;
        }
        else if (user_string == "n" || user_string == "no") {
            user_choice = false;
            is_valid = true;
        }
        else {
            std::cout << "Invalid! You must enter 'yes' or 'no' !" << '\n';
        }
    }
    while (!is_valid);
    return user_choice;
}


void InputValidator::StringToLower(std::string& str) {
    for (char& i : str) {
        i = std::tolower(i);
    }
}
