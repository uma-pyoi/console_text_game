#include <iostream>
#include <string>
#include "../include/Item.h"
#include "../include/Food.h"
#include "../include/GameManager.h"
#include "../include/InputValidator.h"
#include "../include/Player.h"


#include <iostream>
#include <fstream>
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

int main()
{
    // Player player("Kai");
    // GameManager game_manager(player);
    // game_manager.RunStory();
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

    std::ifstream plot_json_2("plot.json");
    json data = json::parse(plot_json_2);

    data["list"][0] = data["list"][0].get<int>() + 2;

    std::cout << data["list"] << '\n';
    std::cout << data.dump(4) << '\n';

    return 0;
}
