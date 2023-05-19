#include "Cowboy.hpp"
#include <stdexcept>

using namespace ariel;

Cowboy::Cowboy(string name, Point location) :Character(name , location){
    this->setHitPoints(110);
    this->numOfBullets = 6;
}

bool Cowboy::isCowboy()  {
    return true;
}

void Cowboy::shoot(ariel::Character *enemy) {
    if(enemy == this)
        throw runtime_error("No self harm");
    if(! this->isAlive() || ! enemy->isAlive())
        throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy");
    if(this->hasboolets()){
        enemy->hit(10);
        this->numOfBullets--;
    }
}

bool Cowboy::hasboolets() {
    return this->numOfBullets > 0;
}

void Cowboy::reload() {
    if(! this->isAlive())
        throw runtime_error("Dead cowboy can not reload");
    this->numOfBullets = 6;
}

string Cowboy::print() {
    string s = "type: C , Name: ";
    if(this->isAlive()) {
        s += this->getName() + " , Location: " +
             this->getLocation().Print() + " , hit points: " +
             to_string(this->getHitPoints()) +
             " , num of Bullets: "
             + to_string(this->numOfBullets);
    }
    else {
        s += "(" + this->getName() +") , Location: " + this->getLocation().Print();
    }
    return s;
}