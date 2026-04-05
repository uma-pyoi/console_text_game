#ifndef CPP_COURSEWORK1_P479574_WORDGAME_H
#define CPP_COURSEWORK1_P479574_WORDGAME_H
#include <vector>

#include "Utils.h"


class WordGame {
private:
    Utils utils_;
    InputValidator input_validator_;

    const int SCORE_POINTS_MULT_ = 10; // multiplier for each word letter
    const int ATTEMPTS_MULT_ = 2; // multiplier for each word letter
    std::vector<std::string> words_{"ANANAS", "FISH", "WINDOW", "HOSPITAL", "COMPUTER", "BRAIN", "NURSE", "ARCHITECTURE"};

public:
    bool Play();

    void OutputAttempts(int attempts);
    void OutputWord(std::string word, std::vector<int> guessed_indexes);
    bool CheckIsGuessCorrect(std::string word, char user_char, std::vector<int>& user_guessed_indexes);
    void GuessIsCorrect(std::vector<int> user_guessed_indexes, std::vector<int>& guessed_indexes,
                              std::string word, bool& word_is_guessed);
};


#endif //CPP_COURSEWORK1_P479574_WORDGAME_H
