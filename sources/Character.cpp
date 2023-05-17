#include "Character.hpp"

using namespace ariel;

Character::Character(string name, Point *location) {
    this->name = name;
    this->location = location;
}

bool Character::isAlive() {
    return this->hitPoints > 0;
}

double Character::distance(const Character *other) {
    return this->location->distance(*other->location);
}

void Character::hit(int hits) {
    this->hitPoints -= hits;
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() {
    return *this->location;
}

void Character::setHitPoints(int hits) {
    this->hitPoints = hits;
}

