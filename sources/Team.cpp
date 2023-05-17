#include "Team.hpp"

using namespace ariel;

Team::Team(ariel::Character *leader) {
    this->leader = leader;
}
Team::~Team() {
}

void Team::add(ariel::Character *New) {

}

void Team::attack(Team *enemy) {

}

int Team::stillAlive() {
    return -1;
}

void Team::print() {

}

vector<Character*> Team::getCharacters() {
    return this->Characters;
}

