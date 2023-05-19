#include "OldNinja.hpp"

using namespace ariel;

OldNinja::OldNinja(string name, Point location) : Ninja(name , location){
    this->setHitPoints(150);
    this->setSpeed(8);
}
