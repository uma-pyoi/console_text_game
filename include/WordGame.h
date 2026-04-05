#ifndef CPP_COURSEWORK1_P479574_WORDGAME_H
#define CPP_COURSEWORK1_P479574_WORDGAME_H
#include <vector>

#include "Utils.h"


class WordGame {
private:
    Utils utils_;
    InputValidator input_validator_;

    // const int ATTEMPTS_ = 10;
    const int SCORE_POINTS_MULT_ = 10; // multiplier for each word letter
    std::vector<std::string> words_{"ANANAS", "FISH", "WINDOW", "HOSPITAL", "COMPUTER", "BRAIN", "NURSE", "ARCHITECTURE"};

public:
    bool Play();
};


#endif //CPP_COURSEWORK1_P479574_WORDGAME_H
