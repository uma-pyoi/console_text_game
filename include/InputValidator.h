#ifndef CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H
#define CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H

#include <string>

class InputValidator {
public:
    // reading input
    std::string ReadString();
    int ReadPosIntInRange(int min, int max);
    char ReadStoryModeChar();
    bool ReadYesNo();
    char ReadChar();

    // modifying values
    bool IsNumeric(const std::string& str);
    void TrimTrailingSpacesString(std::string &s);
    void StringToLower(std::string& str);
};


#endif //CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H