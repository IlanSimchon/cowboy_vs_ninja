#include "TrainedNinja.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(string name, Point *location) : Ninja(name , location){
    this->setSpeed(12);
}