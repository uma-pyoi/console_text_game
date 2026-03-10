#include <iostream>
#include <string>
#include "../include/Item.h"
#include "../include/Food.h"
#include "../include/Player.h"
#include "../include/Printer.h"

std::string plot_0[10] {
    "Welcome, my dear. What would your name be?",
    "It's been a long while, my dear",
    "How is it going?"
};


int main() {
    std::cout << "**++++--    Sakana    --++++**" << "\n\n";

    int index_plot{-1};
    bool running{true};

    GetPlayerName();

    // while (running) {
    //     index_plot++;
    //     std::cout << plot_0[index_plot] << '\n';
    //
    //     PrintInputArrow();
    //     std::string player_name;
    // }

    std::cout << plot_0[0] << '\n';
    PrintInputArrow();

    std::string player_name;

    // REFERENCE: https://en.cppreference.com/w/cpp/string/basic_string/getline
    // Cppreference.com (n.d.)
    getline(std::cin, player_name);

    Player player{player_name};
    std::cout << "Ah, " << player.GetName() << ", it's been a long while..." << '\n';

    return 0;
}