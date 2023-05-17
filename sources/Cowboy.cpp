#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(string name, Point *location) :Character(name , location){
    this->setHitPoints(110);
    this->numOfBullets = 6;
}

void Cowboy::shoot(ariel::Character *enemy) {
    if(enemy->isAlive()){
        enemy->hit(10);
        this->numOfBullets--;
    }
}

bool Cowboy::hashBullets() {
    return this->numOfBullets > 0;
}

void Cowboy::reload() {
    this->numOfBullets = 6;
}

string Cowboy::print() {
    return "aaa";
}