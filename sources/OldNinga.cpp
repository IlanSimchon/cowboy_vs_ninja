#include "OldNinga.hpp"

using namespace ariel;

OldNinja::OldNinja(string name, Point *location) : Ninja(name , location){
    this->setSpeed(8);
}
