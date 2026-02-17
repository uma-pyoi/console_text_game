#include <iostream>
#include <string>

class Player {
private:
    std::string name;
public:
    Player(std::string newName) {
        name = newName;
    }
    std::string getName() {
        return name;
    }
    void printName() {
        std::cout << "Player's name: " << name << '\n';
    }
};



class GameManager {
    Player player;

public:
    std::string getPlayerName

    void printGameStart() {
        std::cout << ""
    }
};


int main() {


    return 0;
}