#include "Team.hpp"
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace ariel;
using namespace std;

Team::Team(ariel::Character *leader) {
    if(leader->getIsPlay())
        throw runtime_error("");
    this->leader = leader;
    leader->setIsPlay();
    this->Characters.push_back(leader);
}
Team::~Team() {
    for(Character* character: this->Characters){
        delete character;
    }
}

void Team::add(ariel::Character *New) {
    if(New->getIsPlay())
        throw runtime_error("this Character is plays in other team");

    if(this->Characters.size() == 10)
        throw runtime_error("overflow");

    New->setIsPlay();
    this->Characters.push_back(New);
    sort(Characters.begin(), Characters.end() , &Character::compare);

}

void Team::attack(Team *enemy) {
    if(enemy == nullptr)
        throw invalid_argument("");
    if(enemy->stillAlive() == 0)
        throw runtime_error("Attacking a dead team should throw an exception");
    updateLeader();
    Character* poor = (enemy->getCharacters())->back();
    for (Character* c: *enemy->getCharacters()) {
        if (c->isAlive() && (!poor->isAlive() || c->distance(this->leader) < poor->distance(this->leader)))
            poor = c;
    }

    for (Character *c: this->Characters) {
        if (c->isAlive() && poor->isAlive()) {
            if (Cowboy *c1 = dynamic_cast<Cowboy *>(c)) {
                if (c1->hasboolets())
                    c1->shoot(poor);
                else
                    c1->reload();
            } else if (Ninja *c2 = dynamic_cast<Ninja *>(c)) {
                if (c2->distance(poor) < 1)
                    c2->slash(poor);
                else
                    c2->move(poor);
            }

        }
        if (this->stillAlive() == 0 || enemy->stillAlive() == 0)
            return;
        if (! poor->isAlive()) {
            for (Character *s: *enemy->getCharacters()) {
                if (s->isAlive() && (! poor->isAlive() || s->distance(this->leader) < poor->distance(this->leader)))
                    poor = s;
            }
        }
    }

}

int Team::stillAlive() {
    int alive = 0;
    for (Character* c: this->Characters) {
        if(c->isAlive())
            alive++;
    }
    return alive;
}

void Team::print() {
    for(Character* c : this->Characters){
        cout << c->print() << endl;
    }

}

vector<Character*>* Team::getCharacters() {
    return &this->Characters;
}

void Team::setCharacters(ariel::Character *New) {
    this->Characters.push_back(New);
}

void Team::updateLeader(){
    if(! this->leader->isAlive()){
        Character* soon = this->Characters.back();
        for (Character* c: Characters) {
            if(c->isAlive() && c->distance(this->leader) < soon->distance(this->leader))
                soon = c;
        }
        this->leader = soon;
    }
}

