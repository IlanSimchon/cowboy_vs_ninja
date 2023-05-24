#include "SmartTeam.hpp"
#include <stdexcept>
#include <algorithm>

using namespace ariel;

SmartTeam::SmartTeam(Character *leader) : Team(leader){}

void SmartTeam::add(Character *New) {
    if(New->getIsPlay())
        throw runtime_error("this Character is plays in other team");

    if(this->getCharacters()->size() == 10)
        throw runtime_error("overflow");

    New->setIsPlay();
    this->setCharacters(New);
    sort(getCharacters()->begin(), getCharacters()->end() , &Character::compare2);

}

void SmartTeam::attack(Team *enemy) {
    Team::attack(enemy);
    sort(getCharacters()->begin(), getCharacters()->end() , &Character::compare2);

}


