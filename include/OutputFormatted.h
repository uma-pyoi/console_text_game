#ifndef CPP_COURSEWORK1_P479574_OUTPUTFORMATTED_H
#define CPP_COURSEWORK1_P479574_OUTPUTFORMATTED_H

#include "Inventory.h"
#include "Player.h"


class OutputFormatted {
public:
    void OutputGameTitle();
    void OutputGameEnd();
    void OutputStoryModePrompt();
    void OutputPauseScreen(Player player);
    void OutputInventoryMenu(Inventory inventory);
};


#endif //CPP_COURSEWORK1_P479574_OUTPUTFORMATTED_H