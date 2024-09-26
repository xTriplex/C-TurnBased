#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void Game::addCharacter(const Character &character) {
    characters.push_back(character);
}

void Game::displayTeam() {
    std::cout << "Team:\n";
    for (const auto &character : characters) {
        std::cout << "Name: " << character.getName() << ", Class: ";
        switch (character.getCharacterClass()) {
            case Character::Class::DPS:
                std::cout << "DPS";
                break;
            case Character::Class::Tank:
                std::cout << "Tank";
                break;
            case Character::Class::Healer:
                std::cout << "Healer";
                break;
            case Character::Class::Support:
                std::cout << "Support";
                break;
        }
        std::cout << ", Health: " << character.getHealth() << ", Damage: " << character.getDamage() << ", Speed: " << character.getSpeed() << std::endl;
    }
}

void Game::sortCharactersByActionValue() {
    for (auto &character : characters) {
        character.resetTurn(); // Reset action value for each character
    }

    // Sort characters by their speed (descending order)
    std::sort(characters.begin(), characters.end(), [](const Character &a, const Character &b) {
        return a.getSpeed() > b.getSpeed();
    });
}

void Game::checkWinCondition() {
    bool p1Alive = false;
    bool p2Alive = false;

    for (const auto &character : characters) {
        if (character.isAlive()) {
            if (character.getPlayer() == 1) {
                p1Alive = true;
            } else {
                p2Alive = true;
            }
        }
    }

    if (!p1Alive) {
        std::cout << "Player 2 wins!\n";
        exit(0); // End the game
    }

    if (!p2Alive) {
        std::cout << "Player 1 wins!\n";
        exit(0); // End the game
    }
}

void Game::simulateCombat() {
    srand(time(0)); // Seed random number generator

    while (true) {
        sortCharactersByActionValue();

        for (auto &character : characters) {
            if (!character.isAlive()) {
                continue;
            }

            if (character.getEnergy() == 0) {
                std::cout << character.getName() << " has no energy and can only use normal attacks or ultimates.\n";
                // Handle normal attacks and ultimates
            } else {
                std::cout << character.getName() << "'s Turn:\n";
                // Handle player actions based on energy and ultimate charges
            }
        }

        checkWinCondition(); // Check win condition after each turn
    }
}
