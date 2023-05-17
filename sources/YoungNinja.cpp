#include "YoungNinja.hpp"


using namespace ariel;

YoungNinja::YoungNinja(string name, Point *location) : Ninja(name , location){
    this->setSpeed(14);
}
