cmake_minimum_required(VERSION 4.1)
project(cpp_coursework1_P479574)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_coursework1_P479574 src/main.cpp
        src/Item.cpp
        include/Item.h
        src/Food.cpp
        include/Food.h
        src/Weapon.cpp
        include/Weapon.h
        src/Clothing.cpp
        include/Clothing.h
        src/Player.cpp
        include/Player.h
        src/GameManager.cpp
        include/GameManager.h
        src/InputValidator.cpp
        include/InputValidator.h
        src/Inventory.cpp
        include/Inventory.h
        src/Enemy.cpp
        include/Enemy.h
        include/PlotManager.h
        src/Utils.cpp
        include/Utils.h
)
