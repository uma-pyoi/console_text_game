#ifndef CPP_COURSEWORK1_P479574_WORDGAME_H
#define CPP_COURSEWORK1_P479574_WORDGAME_H
#include <vector>

#include "Utils.h"


class WordGame {
private:
    Utils utils_;

    const int ATTEMPTS_{10};
    std::vector<std::string> words_{"KOI FISH", "WINDOW", "HOSPITAL", "COMPUTER", "BRAIN", "NURSE", "ARM ARCHITECTURE"};

public:
    bool Play();
};


#endif //CPP_COURSEWORK1_P479574_WORDGAME_H
