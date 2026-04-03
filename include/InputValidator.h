#ifndef CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H
#define CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H

#include <string>

#include "Utils.h"

class InputValidator {
    Utils utils_;
public:
    std::string ReadString();
    int ReadPosIntInRange(int min, int max);
    char ReadStoryModeChar();

    bool IsNumeric(const std::string& str);
    void TrimTrailingSpacesString(std::string &s);
};


#endif //CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H