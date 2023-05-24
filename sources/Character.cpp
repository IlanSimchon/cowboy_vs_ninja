#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Character::Character(string name, Point location) {
    this->name = name;
    this->location = location;
    this->isPlay = false;
}

bool Character::isAlive() {
    return this->hitPoints > 0;
}

double Character::distance(const Character *other) {
    return this->location.distance(other->location);
}

void Character::hit(int hits)  {
    if(hits < 0)
        throw invalid_argument("negative value");
    this->hitPoints -= hits;
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() {
    return this->location;
}

void Character::setLocation(Point newPoint) {
    this->location = newPoint;
}

bool Character::getIsPlay() {
    return this->isPlay;
}

void Character::setIsPlay() {
    this->isPlay = true;
}

int Character::getHitPoints() {
    return this->hitPoints;
}

void Character::setHitPoints(int hits) {
    this->hitPoints = hits;
}

bool Character::compare(Character* char1, Character* char2) {
    return char1->isCowboy() && ! char2->isCowboy();
}

bool Character::compare2(Character *char1, Character *char2) {
    return char1->getHitPoints() > 0 && char1->getHitPoints() < char2->getHitPoints();
}
