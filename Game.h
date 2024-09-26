#pragma once

#include "Character.h"
#include <vector>

class Game {
public:
    void addCharacter(const Character &character);
    void displayTeam();
    void sortCharactersByActionValue();
    void simulateCombat();
    void checkWinCondition();

private:
    std::vector<Character> characters;
};
