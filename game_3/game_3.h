#pragma once

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "dependencies.h"

namespace game_3 {

class PlayerClass {
private:
    int health;

public:
    void addHealth(int amount) {
        this->health += amount;
    }   
    void showHealth() {
        std::cout << this->health << std::endl;
    }   
};

};
