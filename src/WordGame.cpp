#include "../include/WordGame.h"
#include <iostream>

bool WordGame::Play() {
    int word_index = utils_.GenerateRandomIntInRange(0, words_.size());
    std::string word = words_[word_index];

    std::cout << "+++++++++++ Word Game! +++++++++++" << "\n\n";

    for (char c : word) {
        char output_char;
        if (c == ' ') {
            output_char = ' ';
        }
        else {
            output_char = '_';
        }
        std::cout << output_char;
    }

    std::cout << "Now guess a letter";
}
