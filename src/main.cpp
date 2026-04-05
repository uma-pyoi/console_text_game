#include <iostream>
#include <string>
#include "../include/Item.h"
#include "../include/Food.h"
#include "../include/GameManager.h"
#include "../include/InputValidator.h"
#include "../include/Player.h"


#include <iostream>
#include <fstream>

#include "../include/WordGame.h"
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

int main()
{
     Player player("Kai");
     Inventory inventory;
     GameManager game_manager(player, inventory);
     game_manager.RunStory();

    // WordGame word_game;
    // word_game.Play();

// ++++++++=++++++++=++++++++=++++++++=++++++++=++++++++=++++++++=++++++++=

    // testing json
    // std::ofstream plot_json("plot.json");
    //
    // json j2 = {
    //     {"list", {100, 101, 102}},
    //     {"object", {
    //     {"currency", "USD"},
    //     {"value", 42.99}
    //     }}
    // };
    // j2["new_list"] = {"reading", "writing", "coding"};
    //
    // plot_json << j2;

    // std::ifstream plot_json_2("plot.json");
    // json data = json::parse(plot_json_2);
    //
    // std::vector<std::string> plot_text_arr_0 = data["plot_0"]["text_array"].get<std::vector<std::string>>();
    //
    // // std::cout << data["list"] << '\n';
    // // std::cout << data.dump(4) << '\n';
    // for (int i = 0; i < plot_text_arr_0.size(); i++) {
    //     std::cout << plot_text_arr_0[i];
    // }

    return 0;
}
