#include <iostream>
#include <string>
#include "../include/Item.h"
#include "../include/Food.h"
#include "../include/InputValidator.h"
#include "../include/Player.h"

int main() {
    InputValidator input_validator;
    std::string myString;
    std::cout << "Enter: ";
    myString = input_validator.ReadString();
    std::cout << "the string is: " << myString << " " << myString.length() << '\n';
    input_validator.TrimTrailingSpacesString(myString);
    std::cout << "now string is: " << myString << "_" << myString.length() << '\n';

    return 0;
}