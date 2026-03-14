#ifndef CPP_COURSEWORK1_P479574_OUTPUTFORMATTED_H
#define CPP_COURSEWORK1_P479574_OUTPUTFORMATTED_H
#include "Inventory.h"
#include "Player.h"


class OutputFormatted {
public:
    std::string default_empty_equipment_string{"None"};

    void OutputGameTitle();
    void OutputGameEnd();

    void OutputStoryModePrompt();

    void OutputPauseScreen(Player player);
    void OutputPlayerStats(Player player);

    void OutputInventoryMenu(Inventory inventory);
    void OutputInventory(Inventory inventory);
};


#endif //CPP_COURSEWORK1_P479574_OUTPUTFORMATTED_H