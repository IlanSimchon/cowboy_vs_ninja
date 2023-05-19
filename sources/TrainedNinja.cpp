#include "TrainedNinja.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name , location){
    this->setHitPoints(120);
    this->setSpeed(12);
}