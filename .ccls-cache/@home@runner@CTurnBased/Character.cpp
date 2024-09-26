#include "Character.h"

Character::Character(std::string name, Class characterClass, int health, int damage, int speed)
    : name(name), characterClass(characterClass), health(health), damage(damage), speed(speed), energy(3), ultimateCharges(0), actionValue(0), player(0) {}

std::string Character::getName() const {
    return name;
}

Character::Class Character::getCharacterClass() const {
    return characterClass;
}

int Character::getHealth() const {
    return health;
}

int Character::getDamage() const {
    return damage;
}

int Character::getSpeed() const {
    return speed;
}

int Character::getEnergy() const {
    return energy;
}

void Character::setEnergy(int energy) {
    this->energy = energy;
}

int Character::getUltimateCharges() const {
    return ultimateCharges;
}

void Character::setUltimateCharges(int charges) {
    ultimateCharges = charges;
}

void Character::resetTurn() {
    actionValue += 10000 / speed;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::setPlayer(int player) {
    this->player = player;
}

int Character::getPlayer() const {
    return player;
}
