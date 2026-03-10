#ifndef CPP_COURSEWORK1_P479574_GAMEMANAGER_H
#define CPP_COURSEWORK1_P479574_GAMEMANAGER_H

#include "Player.h"
#include "InputValidator.h"
#include "OutputFormatted.h"

class GameManager {
    OutputFormatted output_formatted_;
    InputValidator input_validator_;

    Player player_;
    Inventory inventory_;

public:
    GameManager(Player player);

    // plot is public as there is no need to keep it private
    std::string plot_0[10] {
        "You wake up in a dark room. "
        "\nA glowing screen shows today's date - May 1st, 3137."
        "\nIt has been 1111 years.",
        "A woman in a white uniform enters the room. \n\"What is the number?\" she asks."
    };
    std::string plot_0choice[10] {
        "1. 1111",
        "2. 15"
    };
    std::string plot_01[10] { // 01 means plot 0 branch 1
        "The woman slowly and carefully pulls out a knife."
    };
    std::string plot_02[10] {
        "\"What a sweetie!\""
        "\nThe woman smiles kindly."
    };

    // methods
    void RunStory();
};


#endif //CPP_COURSEWORK1_P479574_GAMEMANAGER_H