#pragma once

#include <string>

class Character {
public:
    enum class Class {
        DPS,
        Tank,
        Healer,
        Support
    };

    Character(std::string name, Class characterClass, int health, int damage, int speed);
    std::string getName() const;
    Class getCharacterClass() const;
    int getHealth() const;
    int getDamage() const;
    int getSpeed() const;
    int getEnergy() const;
    int getUltimateCharges() const;
    int getPlayer() const;
    bool isAlive() const;
    void setEnergy(int energy);
    void setUltimateCharges(int charges);
    void resetTurn();
    void setPlayer(int player);

private:
    std::string name;
    Class characterClass;
    int health;
    int damage;
    int speed;
    int energy;
    int ultimateCharges;
    int actionValue;
    int player;
};
