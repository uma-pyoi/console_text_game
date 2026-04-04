#ifndef CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H
#define CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H

#include <string>

#include "Utils.h"

class InputValidator {
    Utils utils_;
    int prompt_color_ = 90;

public:
    // reading input
    std::string ReadString();
    int ReadPosIntInRange(int min, int max);
    char ReadStoryModeChar();
    bool ReadYesNo();

    // modifying values
    bool IsNumeric(const std::string& str);
    void TrimTrailingSpacesString(std::string &s);
    void StringToLower(std::string& str);

    // outputting prompts
    void OutputStoryModePrompt();
    void OutputNumInRangePrompt(int min, int max);
    void OutputYesNoPrompt();
};


#endif //CPP_COURSEWORK1_P479574_INPUTVALIDATOR_H