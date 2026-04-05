#include "../include/WordGame.h"
#include <iostream>

bool WordGame::Play() {
    std::vector<int> guessed_indexes;
    bool is_guessed{false};
    int attempts = ATTEMPTS_;

    int word_index = utils_.GenerateRandomIntInRange(0, words_.size());
    std::string word = words_[0];

    std::cout << "+++++++++++ Word Game! +++++++++++" << "\n\n";

    do {
        for (int i = 0; i < word.size(); i++) {
            char output_char = 0;

            bool char_is_guessed{false};
            for (int guessed_index : guessed_indexes) {
                if (i == guessed_index) {
                    output_char == word[i];
                    char_is_guessed = true;
                }
            }
            if (!char_is_guessed) {
                if (word[i] == ' ') {
                    output_char = ' ';
                }
                else {
                    output_char = '_';
                }
            }

            std::cout << output_char;
        }

        std::cout << "\nGuess a letter from the word!" << '\n';
        char user_char = input_validator_.ReadChar();

        int guessed_index{-1};
        bool is_guess_correct{false};
        for (int i = 0; i < word.size(); i++) {
            if (user_char == word[i]) {
                guessed_index = i;
                is_guess_correct = true;
            }
        }

        if (is_guess_correct) {
            std::cout << "Correct!" << '\n';
            guessed_indexes.push_back(guessed_index);
        }
        else {
            std::cout << "Incorrect!" << '\n';
        }
        attempts--;
        is_guessed = true;
    }
    while (!is_guessed && attempts != 0);
}
