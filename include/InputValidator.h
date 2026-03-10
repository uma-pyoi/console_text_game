#ifndef CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H
#define CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H

#include <string>
#include <iostream>

class InputValidator {
    std::string ReadString() {
        std::string input_string;
        getline(std::cin >> std::ws, input_string);
        return input_string;
    }
};


#endif //CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H