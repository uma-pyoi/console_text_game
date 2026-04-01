#ifndef CPP_COURSEWORK1_P479574_PLOTMANAGER_H
#define CPP_COURSEWORK1_P479574_PLOTMANAGER_H

#include <string>
#include <vector>

class PlotManager {
    // plot is public as there is no need to keep it private
public:
    std::string plot_0[2] {
        "You wake up in a dark room. "
        "\nA glowing screen shows today's date - May 1st, 3137."
        "\nIt has been 1111 years.",
        "\n\nA woman in a white uniform enters the room. \n\"What is the number?\" she asks."
        "\n1. 1111"
        "\n2. 15"
    };
    std::string plot_01[10] { // 01 means plot 0 branch 1
        "You have angered her! Face the consequences!",
        "The woman slowly and carefully pulls out a knife."
    };
    std::string plot_02[10] {
        "\"What a sweetie!\""
        "\nThe woman smiles kindly."
    };
};


#endif //CPP_COURSEWORK1_P479574_PLOTMANAGER_H