#ifndef CPP_COURSEWORK1_P479574_PLOTMANAGER_H
#define CPP_COURSEWORK1_P479574_PLOTMANAGER_H

#include <string>
#include <vector>

class PlotManager {
public:
    // plot is public as there is no need to keep it private
    std::vector<std::string> plot_0 {
        "You wake up in a dark room. "
        "\nA glowing screen shows today's date - May 1st, 3137."
        "\nIt has been 1111 years.",
        "\n\nA woman in a white uniform enters the room. \n\"What is the number?\" she asks."
        "\n1. 1111"
        "\n2. 15"
    };
    std::vector<std::string> plot_01 { // 01 means plot 0 branch 1
        "You have angered her! Face the consequences!",
        "\nThe woman slowly and carefully pulls out a knife.\n"
    };
    std::vector<std::string> plot_02 {
        "\"What a sweetie! You sure know the binary system!\""
        "\nThe woman smiles kindly.",
        "\n\nThe nurse hands you a blue hospital gown.",
        "\n\n\"Wait, I was naked this entire time?\" you think."
    };
};


#endif //CPP_COURSEWORK1_P479574_PLOTMANAGER_H