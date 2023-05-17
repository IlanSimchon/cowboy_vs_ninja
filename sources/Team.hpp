#ifndef CPP_EX4_TEAM_HPP
#define CPP_EX4_TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinga.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "vector"
namespace ariel{
    class Team{
    private:
        vector<Character*> Characters;
        Character *leader;
    public:
        Team(Character *leader);
        ~Team();
        virtual void add(Character* New);
        virtual void attack(Team  *enemy);
        int stillAlive();
        virtual void print();
        vector<Character*> getCharacters();
    };

}
#endif //CPP_EX4_TEAM_HPP
