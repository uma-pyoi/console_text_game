#include <iostream>
#include <string>
#include "../include/Item.h"
#include "../include/Food.h"
#include "../include/GameManager.h"
#include "../include/InputValidator.h"
#include "../include/Player.h"

int main()
{
    Player player("Kai");
    GameManager game_manager(player);
    game_manager.RunStory();

    return 0;
}
