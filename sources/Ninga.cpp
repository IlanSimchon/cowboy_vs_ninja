#include "Ninga.hpp"

using namespace ariel;

Ninja::Ninja(string name, Point *location) : Character(name , location){}

void Ninja::slash(Character *enemy) {
    if(this->distance(enemy) < 1)
        enemy->hit(40);
}

void Ninja::setSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Ninja::move(ariel::Character *enemy) {

}

string Ninja::print() {

}