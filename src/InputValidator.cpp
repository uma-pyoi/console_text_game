#include "../include/InputValidator.h"

#include <filesystem>
#include <iostream>


void InputValidator::TrimString(std::string &s) {
    int end_i = s.length() - 1;
    bool found_non_space_char{false};

    while (end_i >= 0 || !found_non_space_char) {
        if (s[end_i] == ' ' || s[end_i] == '\n' || s[end_i] == '\t') {
            end_i--;
        }
        else {
            found_non_space_char = true;
        }
    }

    s[end_i + 1] = '\0';
}

// // REFERENCE: https://codemia.io/knowledge-hub/path/how_to_trim_a_stdstring
// // Codemia
// std::string InputValidator::TrimString(std::string &s) {
//     size_t start = s.find_first_not_of(" \t\n\r");
//     size_t end = s.find_last_not_of(" \t\n\r");
//
//     if (start == std::string::npos)
//         s.clear();  // String contains only whitespace
//     else
//         s = s.substr(start, end - start + 1);
// }
