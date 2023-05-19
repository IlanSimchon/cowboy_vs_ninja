#include "Ninga.hpp"
#include <stdexcept>

using namespace ariel;

Ninja::Ninja(string name, Point location) : Character(name , location){}

bool Ninja::isCowboy() {
    return false;
}

void Ninja::slash(Character *enemy) {
    if(enemy == this)
        throw runtime_error("No self harm");
    if (! this->isAlive() || ! enemy->isAlive())
        throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy");

    if (this->distance(enemy) < 1)
        enemy->hit(40);
}

void Ninja::setSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Ninja::move(Character *enemy) {
    this->setLocation(Point::moveTowards(this->getLocation()
            , enemy->getLocation() , this->speed));
}

string Ninja::print() {
    string s = "type: N , Name: ";
    if(this->isAlive()) {
        s += this->getName() + " , Location: " +
             this->getLocation().Print() + " , hit points: " +
             to_string(this->getHitPoints()) +
             " , speed: "
             + to_string(this->speed);
    }
    else {
        s += "(" + this->getName() +") , Location: " + this->getLocation().Print();
    }
    return s;

}