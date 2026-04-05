#include "../include/WordGame.h"
#include <iostream>

bool WordGame::Play() {
    std::vector<int> guessed_indexes;
    bool is_guessed{false};

    int word_index = utils_.GenerateRandomIntInRange(0, words_.size() - 1);
    std::string word = words_[word_index];
    std::cout << "word: " << word << '\n';
    int attempts = word.size() * 2;

    std::cout << "+++++++++++ Word Game! +++++++++++" << "\n\n";

    do {
        utils_.SetColor(91);
        std::cout << "You have " << attempts << " attempt(s) left." << '\n';
        utils_.ResetColor();
        for (int i = 0; i < word.size(); i++) {
            char output_char = 0;

            bool char_is_guessed{false};
            for (int guessed_index: guessed_indexes) {
                if (i == guessed_index) {
                    output_char = word[i];
                    char_is_guessed = true;
                }
            }
            if (!char_is_guessed) {
                output_char = '_';
            }

            std::cout << output_char << " ";
        }

        std::cout << "\nGuess a letter from the word!" << '\n';
        char user_char = std::toupper(input_validator_.ReadChar());

        std::vector<int> user_guessed_indexes;
        bool is_guess_correct{false};
        for (int i = 0; i < word.size(); i++) {
            if (user_char == word[i]) {
                user_guessed_indexes.push_back(i);
                is_guess_correct = true;
            }
        }

        if (is_guess_correct) {
            // passing only user_guessed_indexes[0] is enough to check if letter was guessed before
            bool guessed_before = std::count(guessed_indexes.begin(), guessed_indexes.end(), user_guessed_indexes[0]);
            if (guessed_before) {
                std::cout << "You already guessed this letter before!" << '\n';
            }
            else {
                std::cout << "Correct!" << '\n';
                for (int guessed_index : user_guessed_indexes) {
                    guessed_indexes.push_back(guessed_index);
                }
                if (guessed_indexes.size() == word.size()) {
                    std::cout << "Congratulations! You guessed the word! The word was:" << '\n';
                    std::cout << word << '\n';
                    int score_rewards = word.size() * SCORE_POINTS_MULT_;
                    utils_.OutputStat("score points", std::to_string(score_rewards));
                    is_guessed = true;
                }
            }
        } else {
            std::cout << "Incorrect!" << '\n';
        }
        attempts--;
        if (attempts == 0) {
            std::cout << "Too bad! No attempts left!" << '\n';
            utils_.OutputGameover();
        }
    } while (!is_guessed && attempts != 0);
}
