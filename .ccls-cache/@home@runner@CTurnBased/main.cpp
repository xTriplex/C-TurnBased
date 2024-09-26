#include <iostream>
#include <vector>
#include "Game.h"
#include "Character.h"

int main()
{
    // Initialize available units
    std::vector<Character> availableUnits = {
        Character("DPS", Character::Class::DPS, 3, 2, 110),
        Character("Tank", Character::Class::Tank, 6, 1, 100),
        Character("Healer", Character::Class::Healer, 5, 1, 115),
        Character("Support", Character::Class::Support, 4, 1, 120)
    };

    std::cout << "Welcome to Team Selection!\n";
    std::cout << "Each player will pick 4 units for their team.\n\n";

    std::vector<Character> player1Team;
    std::vector<Character> player2Team;

    // Player 1 selects units
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "\nPlayer 1, pick unit " << i + 1 << " for your team:\n";
        std::cout << "Available Units:\n";
        for (int j = 0; j < availableUnits.size(); ++j)
        {
            std::cout << j + 1 << ". " << availableUnits[j].getName() << std::endl;
        }
        int choice;
        std::cout << "Enter your choice (1-" << availableUnits.size() << "): ";
        std::cin >> choice;
        player1Team.push_back(availableUnits[choice - 1]);
        player1Team.back().setPlayer(1); // Set player number for character
    }

    // Reset available units for Player 2
    availableUnits = {
        Character("DPS", Character::Class::DPS, 3, 2, 110),
        Character("Tank", Character::Class::Tank, 6, 1, 100),
        Character("Healer", Character::Class::Healer, 5, 1, 115),
        Character("Support", Character::Class::Support, 4, 1, 120)
    };

    // Player 2 selects units
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "\nPlayer 2, pick unit " << i + 1 << " for your team:\n";
        std::cout << "Available Units:\n";
        for (int j = 0; j < availableUnits.size(); ++j)
        {
            std::cout << j + 1 << ". " << availableUnits[j].getName() << std::endl;
        }
        int choice;
        std::cout << "Enter your choice (1-" << availableUnits.size() << "): ";
        std::cin >> choice;
        player2Team.push_back(availableUnits[choice - 1]);
        player2Team.back().setPlayer(2); // Set player number for character
    }

    // Display selected teams
    std::cout << "\nPlayer 1's Team:\n";
    for (const auto& character : player1Team)
    {
        std::cout << character.getName() << std::endl;
    }

    std::cout << "\nPlayer 2's Team:\n";
    for (const auto& character : player2Team)
    {
        std::cout << character.getName() << std::endl;
    }

    // Initialize and start the game
    Game game;
    for (const auto& character : player1Team)
    {
        game.addCharacter(character);
    }
    for (const auto& character : player2Team)
    {
        game.addCharacter(character);
    }

    game.simulateCombat();

    return 0;
}
