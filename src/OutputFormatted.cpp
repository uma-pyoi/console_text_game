#include "../include/OutputFormatted.h"
#include <iostream>

void OutputFormatted::OutputGameTitle() {
    std::cout << "**++++--    Sakana    --++++**" << "\n\n";
}

void OutputFormatted::OutputStoryModePrompt() {
    std::cout << "Enter 'n' to continue, 'p' to pause: ";
}
