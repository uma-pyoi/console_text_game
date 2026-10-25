#include <iostream>
#include <string>
#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

int main() {
    Player player("Sakana");
    Inventory inventory;
    GameManager game_manager(player, inventory);
    game_manager.RunStory();

    return 0;
}
