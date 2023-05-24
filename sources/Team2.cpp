#include "Team2.hpp"
#include <iostream>
#include <algorithm>

using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::add(Character *New) {
    if(New->getIsPlay())
        throw runtime_error("this Character is plays in other team");

    if(this->getCharacters()->size() == 10)
        throw runtime_error("overflow");

    this->setCharacters(New);
}
